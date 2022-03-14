/*
 * standby_req.c
 *
 */

#include "hal_config.h"
#include "reg_apb.h"
#include "standby_req.h"
#include "intc.h"
#include "suspend.h"
#include "power_on.h"
#include "clk.h"
#include "saradc.h"
#include "earphone_insert_remove_detect.h"
#include "timer.h"
#include "bll_config.h"
#include "apple_key_detect.h"
#include "bll_misc.h"
#include "debug.h"

typedef struct
{
	void (*Standby_Req_SetCallBack)(uint8_t Index, uint32_t FuncHandle);
	void (*Standby_Req_Init)(void);
	void (*EnterExit_Standby)(void);
}ftable_t;

ftable_t *pStandbyReqFTable;

extern uint8_t Standby_Itself;
standby_req_para_t stStandby_Req_Para;
uint16_t _SarAdcData;
uint8_t u8IsStandBy;
uint8_t u8IsFirstStandBy;
volatile uint8_t new_u8IsFirstStandby; 
uint8_t no_jack_insert_flag;
extern volatile uint32_t intMaskFlag;
uint8_t standby_enable=0;

//__attribute__((section("stdby_sec"))) 
extern void entry_standby_ins(void);

void EnterExit_Standby(void)
{
    pStandbyReqFTable->EnterExit_Standby();
}


void new_patch_EnterExit_Standby(void)
{
    u8IsStandBy = 1;

	DBG_OUT_FUNC("entry\n");
	if(0 == ActiveStandbySt)
	{
#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
		UsbSuspendSt = 1;
		if(APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG && g_pstConfig->FuncCfg.SupportAppleEarphone)
		{
			if((0 == g_ucButtType) && (1 == jack_insert_complet))
			{
				return;
			}
		}
#endif		
	}
	else
	{
		ActiveStandbySt = 0;
	}

    if(new_u8IsFirstStandby<2)
    {
    	new_u8IsFirstStandby++;
    }

	uint8_t PMOD_tmp = pOtpInRam->PMOD;
	pOtpInRam->PMOD = USB_TYPEC_TO_3P5;
	Sys_Suspend();
	pOtpInRam->PMOD = PMOD_tmp;

	if((1 == Standby_Itself)&&(1 == jack_insert_complet))
	{
		;//由于没有耳机插入而进入standby,但是突然耳机又插入了，所以此时不进入standby
	}
	else
	{
		entry_standby_ins();
	}

    Delay_100Us_600K(1);
    High_Freq_OSC_PowerOn(pOtpInRam->osc_cali_code);
    //osc_cali_code_config(0x2c);
    // Set_Clk_Div_Sel(pOtpInRam->osc_div_sel_2, pOtpInRam->ahb_div_sel_2, pOtpInRam->apb_div_sel_2, pOtpInRam->qspi_div_sel_2);
    Sys_Resume();

    if(((USB_TYPEC_HEADPHONE == pOtpInRam->PMOD)                                                     //USB_TYPEC_HEADPHONE
        || ((USB_TYPEC_TO_3P5 == pOtpInRam->PMOD) && (1 == stEarphoneDetectPara.EarPhonePoleFlag)))  //3 pole
        || ((USB_TYPEC_TO_3P5 == pOtpInRam->PMOD) && !apb_power_pd_ctrl3_jack_insertion_sts_getf())) //no jack inserted
    {
        goto RET;//return;
    }
    else
    {
        apb_rst_gen_ctrl0_auxadc_rst_setf(1);
        apb_rst_gen_ctrl0_auxadc_rst_setf(0);
        _SarAdcData = Saradc_Convert(4, SARADC_SEL_MIC);
    }

RET:
	DBG_OUT_FUNC("exit\n");
}

void Standby_Req_Isr(uint32_t uID)
{
	stStandby_Req_Para.pStandbyReqHandler();
}

void Standby_Req_SetCallBack(uint8_t Index, uint32_t FuncHandle)
{
	DBG_OUT_FUNC("entry\n");
	pStandbyReqFTable->Standby_Req_SetCallBack(Index, FuncHandle);
	DBG_OUT_FUNC("exit\n");
}

extern void Patch_Standby_Req_SetCallBack(uint8_t Index, uint32_t FuncHandle);

void Standby_Req_Init(void)
{
	pStandbyReqFTable->Standby_Req_Init();
}

void new_Patch_Standby_Req_Init(void)
{
	DBG_OUT_FUNC("entry\n");
	new_u8IsFirstStandby = 0;
	apb_clk_gen_clken_clk_cpu_dis_en_setf(1);
	apb_clk_gen_clken_clk_core_dis_en_setf(1);
	if(standby_enable)
	{
		intc_enable_set(INTC_ID_STDBY_REQ, Standby_Req_Isr);
	}
	DBG_OUT_FUNC("exit\n");
}

void Standby_Req_UnInit(void)
{
	DBG_OUT_FUNC("entry\n");
    intc_enable_clr(INTC_ID_STDBY_REQ);
	DBG_OUT_FUNC("exit\n");
}

void new_TypeCTo3p5_RmvStandby_WKP_Src_Set(void)
{
	DBG_OUT_FUNC("entry\n");
	apb_key_ctrl0_hss_mask_setf(0);
	apb_key_ctrl0_micin_int_mask_setf(1);
	apb_key_ctrl0_micin_mask_setf(1);
	apb_pwm_ctrl2_usb_suspendm_mask_setf(1);
	apb_key_ctrl0_gpio_mask_setf(1);
    if(1 == g_pstConfig->FuncCfg.JackSenseSel)
    {
		apb_key_ctrl0_gpio_mask_setf(0); 
    }
    else
    {
		apb_key_ctrl0_gpio_mask_setf(1); 
    }
	DBG_OUT_FUNC("exit\n");
}

const ftable_t new_StandbyReqFuncTableDef =
{
	.Standby_Req_SetCallBack = Patch_Standby_Req_SetCallBack,
	.Standby_Req_Init = new_Patch_Standby_Req_Init,
	.EnterExit_Standby  = new_patch_EnterExit_Standby,
};

void new_Standby_Req_patch_init(void)
{
    pStandbyReqFTable = (ftable_t *)&new_StandbyReqFuncTableDef;
}
