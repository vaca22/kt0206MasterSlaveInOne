/*
 * suspend.c
 *
 */
#include "hal_config.h"
#include "bll_config.h"
#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "suspend.h"
#include "user.h"
#include "earphone_insert_remove_detect.h"


extern void Earphone_Detect_Isr(uint32_t uID);
typedef struct
{
    void (*Suspend_Init)(void);
    void (*Suspend_Uninit)(void);
	void (*Sys_Resume)(void);
	void (*Sys_Suspend)(void);
	void (*TypeC_to_3p5_Resume)(void);
	void (*TypeC_to_3p5_Suspend)(void);
}ftable_t;

ftable_t *pSuspendFTable;
extern uint8_t no_jack_insert_flag;
// extern uint8_t jack_pin_order;
extern void Suspend_Init(void);
// extern void Patch_Suspend_Init(void);
void new_Patch_Suspend_Init(void)
{
	//mask config
    #ifdef JACK_SENSE_FUNC
    if(stEarphoneDetectPara.EarPhoneDetectCompletFlag)    //inserted
    {
        apb_key_ctrl0_hss_mask_setf(1);         //hss: headset switch  CTIA OMTP转化
    }
    else                                                  //removed
    {
        apb_key_ctrl0_hss_mask_setf(0);
        Earphone_KWP_Detect_Uninit();
    }
    #endif
    #ifdef MIC_KEY_SUPPORT
    //micin
    //apb_key_ctrl0_micin_mask_setf(1);
    Earphone_KWP_Detect_Init(pOtpInRam->MicinDebounceSel, pOtpInRam->MicinVoltageThresholdSel);
    #endif
    //suspend
    apb_pwm_ctrl2_usb_suspendm_mask_setf(0);
}

extern void Suspend_Uninit(void);
extern void Patch_Suspend_Uninit(void);

extern void Sys_Resume(void);
extern void Patch_Sys_Resume(void);

extern void Sys_Suspend(void);

#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
void Patch_Sys_Suspend_for_AEVKWP(void)
{
    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            clk_div_cfg_t st_clk = 
            {
                .osc_div_sel = 4, //48MHz
                .ahb_div_sel = 0, //48MHz
                .apb_div_sel = 1, //24MHz
                .qspi_div_sel = 2, //48MHz
                .uart_div_sel = 0,
            };
            new_Set_Clk_Div_Sel(st_clk.osc_div_sel, st_clk.ahb_div_sel, st_clk.apb_div_sel, st_clk.qspi_div_sel, st_clk.uart_div_sel);
            //(void)get_msecond_count();
            //timer_start_period(TIMER0, 333, key_fifo_check, TIM_US);
            break;
        }
        default: 
        {
            break;
        }
    }
}

void Patch_Sys_Resume_for_AEVKWP(void)
{
    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            clk_div_cfg_t st_clk = 
            {
                .osc_div_sel = 2, //128MHz
                .ahb_div_sel = 0, //128MHz
                .apb_div_sel = 1, //64MHz
                .qspi_div_sel = 0, //64MHz
                .uart_div_sel = 1,
            };
            new_Set_Clk_Div_Sel(st_clk.osc_div_sel, st_clk.ahb_div_sel, st_clk.apb_div_sel, st_clk.qspi_div_sel, st_clk.uart_div_sel);
            //(void)get_msecond_count();
            //timer_start_period(TIMER0, 333, key_fifo_check, TIM_US);
            break;
        }
        default: 
        {
            break;
        }
    }
}
#endif

volatile uint32_t intMaskFlag;

extern void Patch_Sys_Suspend(void);


extern void TypeC_to_3p5_Resume(void);
volatile uint8_t g_ucResumeFlag;
void new_Patch_TypeC_to_3p5_Resume(void)
{
    if(stEarphoneDetectPara.EarPhoneDetectCompletFlag)
    {
        if(stEarphoneDetectPara.EarPhonePoleFlag)
        {
            Headphone_PowerOn();
        }
        else
        {
            Headset_PowerOn();
            if(g_pstConfig->FuncCfg.SupportAppleEarphone)
            {
                g_ucResumeFlag = TRUE;
            }
        }
    }
    else
    {
        TYPE_C_To_3P5_PowerOn(pOtpInRam->micbias_output_voltage_sel);
    }
}

extern void TypeC_to_3p5_Suspend(void);
//extern void Patch_TypeC_to_3p5_Suspend(void);
void new_Patch_TypeC_to_3p5_Suspend(void)
{
	// uint32_t cnt;

	AUDIO_IN_Stop(CO_BIT(ADC0),0);
	AUDIO_OUT_Stop(CO_BIT(DAC0)|CO_BIT(DAC1),0);

//	apb_key_ctrl0_micin_int_mask_setf(1);
//	apb_key_ctrl0_micin_mask_setf(1);

	if(1 == stEarphoneDetectPara.EarPhoneDetectCompletFlag)
	{
		if(1 == stEarphoneDetectPara.EarPhonePoleFlag)	//3 pole
		{
			Headphone_PowerOff();
		}
		else
		{
			Headset_PowerOff();
		}
	}
	else
	{
		TYPE_C_To_3P5_PowerOff();
	}

	if(stEarphoneDetectPara.EarPhonePoleFlag)
	{
		apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole
	}
	else
	{
        if(stUsbDev.STATUS.RemoteWake)
        {
            apb_key_ctrl0_micin_mask_setf(0);
        }
        else
        {
            apb_key_ctrl0_micin_mask_setf(1);
        }
    }

	apb_key_ctrl0_hss_mask_setf(0);  										//enable hss wakeup source
	__nds32__nop();
}

const ftable_t new_SuspendFTableDef =
{
    .Suspend_Init   		= new_Patch_Suspend_Init,
    .Suspend_Uninit 		= Patch_Suspend_Uninit,
    .Sys_Resume				= Patch_Sys_Resume,
	.Sys_Suspend			= Patch_Sys_Suspend,
	.TypeC_to_3p5_Resume	= new_Patch_TypeC_to_3p5_Resume,
	.TypeC_to_3p5_Suspend	= new_Patch_TypeC_to_3p5_Suspend,
};

void new_Suspend_patch_init(void)
{
    pSuspendFTable = (ftable_t *)&new_SuspendFTableDef;
}
