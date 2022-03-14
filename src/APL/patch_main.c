/*
 * patch_main.c
 *
 *  Created on: Jul 10, 2018
 *      Author: chenbowen
 */

#include "hal_config.h"
#include "bll_config.h"
#include "patch_main.h"
#include <stdio.h>
#include "patch.h"
#include "flash_info.h"
#include "qspi_ctrl.h"
#include "soft_timer.h"
#include "fml_includes.h"
#include "usb_config.h"
#include "bll_jack_sense.h"
#include "eq_top.h"

extern main_ftable_t *main_ftable;

extern void User_Init(void);
extern void User_Schedule(void);

extern void patch_patch_init(void);
extern void patch_plf_schedule(void);
extern void patch_plf_init(void);
extern void p_plf_uninit(void);
void new_process_adc2usb_patch_init(void);
const main_ftable_t main_patch_ftable =
{
    .h_patch_init      = patch_patch_init,
    .h_plf_schedule    = patch_plf_schedule,
    .h_plf_init        = patch_plf_init,
    .h_plf_uninit      = p_plf_uninit,
};

extern uint16_t g_uart_rx_buf_size;
extern uint16_t g_uart_tx_buf_size;
extern uint32_t __data2_start;
extern uint8_t __bss1_end;
extern uint8_t *gp_public_buf;

extern void usb_dongle_patch_init(void);
extern void usb_HeadSet_patch_init(void);
extern void usb_HeadPhone_patch_init(void);
extern void drc_patch_init(void);
extern void volume_patch_init(void);
extern void HAL_CLK_OHPQ_Div_Set(uint8_t osc_div_sel, uint8_t ahb_div_sel, uint8_t apb_div_sel, uint8_t qspi_div_sel);

void patch_other_init(void)
{
    // flash app c init
    patch_cinit();
    //clk div sel otp 12M
    HAL_CLK_OHPQ_Div_Set(OTP_Default_Value.osc_div_sel_1, OTP_Default_Value.ahb_div_sel_1,
                    OTP_Default_Value.apb_div_sel_1, OTP_Default_Value.qspi_div_sel_1);

    OTP_Init();
    patch_Get_Sys_Status();
    patch_OTP_Read_All();
    OTP_Uninit();

    //clk div sel cpu up
    HAL_CLK_OHPQ_Div_Set(pOtpInRam->osc_div_sel_2, pOtpInRam->ahb_div_sel_2,
                    pOtpInRam->apb_div_sel_2, pOtpInRam->qspi_div_sel_2);

    Delay_Us(1);//为了解决加了boot后一些奇怪的问题
}


void patch_patch_init(void)
{
	GPIO_FuncSet(GPIO2, GPIO_PullUpInput);
		if(GPIO_InputGet(GPIO2)!=0){
			 AUDIO_IN_I2SSEL=1;//I2S_A, 只能设置为0或1 0:MASTER0 1:SLAVE0 	2:MASTER1	3:SLAVE1	0->1	//yuan++
			 AUDIO_OUT_I2SSEL=3;//I2S_B, 只能设置为2或3 0:MASTER0 1:SLAVE0 2:MASTER1	3:SLAVE1
		}else{
			 AUDIO_IN_I2SSEL=0;//I2S_A, 只能设置为0或1 0:MASTER0 1:SLAVE0 	2:MASTER1	3:SLAVE1	0->1	//yuan++
			 AUDIO_OUT_I2SSEL=2;//I2S_B, 只能设置为2或3 0:MASTER0 1:SLAVE0 2:MASTER1	3:SLAVE1
		}
    new_power_on_patch_init();
    new_power_off_patch_init();
    power_ctrl_patch_init();
    audio_patch_init();
    new_audio_in_patch_init();
    new_audio_out_patch_init();
    // user_patch_init();
    new_usb_hid_patch_init();
    new_usb_ch9_patch_init();
    new_usb_intr_patch_init(); //
    new_usb_audio_patch_init();
    new_usb_app_patch_init();
    new_usb_sdk_patch_init();
    usb_dongle_patch_init();
    usb_HeadPhone_patch_init();
    usb_HeadSet_patch_init();
//    new_usb_Test_patch_init();
    // usb_3p5_patch_init();
    new_usb_3p5_patch_init();
    new_Suspend_patch_init();
    ecld_patch_init();
    new_asrc_adc_patch_init(); //new
    new_asrc_codec_patch_init();
    new_asrc_dac_patch_init();
    drc_patch_init();
//    new_dsp_patch_init();
//    eq_patch_init();
//    eq_top_patch_init();
    new_hss_det_patch_init();

    new_saradc_patch_init();
    new_earphone_key_detect_patch_init();

//    new_surround_3d_patch_init();
    volume_patch_init();
    nco_patch_init();
    nco_write_patch_init();
//    process_adc2usb_patch_init();
#if 0
    process_i2s_patch_init();
    reverb_patch_init();
    echo_patch_init();
    freq_shift_patch_init();
    howling_detect_patch_init();
#endif
    new_process_usb2dac_patch_init();
    new_process_adc2usb_patch_init();
    new_I2sNco_patch_init();
    new_Standby_Req_patch_init();
    #ifdef JACK_SENSE_FUNC
    new_EarphoneIRDet_patch_init();
    #endif
    Earphone_KWP_Det_patch_init();

    pAFI = (api_ftable_t *)&stApiFunctionTableDft;
    pAFI->User_C_Init();
}

// extern void QSPI_Continue_Enable(void);

USB_OTP gstOTP;

void patch_plf_init(void)
{
    if(pOtpInRam->CACHE_EN)
    {
        cache_on();
    }
    QSPI_NoCacheRead_Config();

    //DC DC enable, off ldo
    #ifdef EXTERNAL_DVDD1P2V
    // if(pOtpInRam->POWER_SEL)
    {
        apb_dig_stdby_ctrl_dig_ldo_flag_setf(0);            //set as software mode
        apb_power_pd_ctrl0_dig_ref_pd_setf(1);
        apb_power_pd_ctrl0_dig_ldoh_pd_setf(1);
        apb_power_pd_ctrl0_dig_ldol_pd_setf(1);
        apb_dig_stdby_ctrl_dig_stdby_pd_setf(1);
    }
    #endif

    mem_init((void *)&__bss1_end, 0x1200);
    g_uEndOfStackAddr += 0x1200;
    uart_uninit();
    uart_buf_init(0x100, 0x100);
    gp_public_buf = (uint8_t *)mem_malloc("public_buf", 0x1000, 1);
    stack_fill();

    ke_init();
    new_intc_init();
    timer_init();
    ChipCfg_Init(); //todo
#if EQ10band_down_MicNoise
    eq10band_all_coeff_init();
#endif

    // set fast power off intc
    #ifndef VDD_VOLTAGE_3P3V
    //    PD_Det_Volt_Thre_Set(0x06);
    intc_enable_set(INTC_ID_PWDN_DET, (intc_handler *)Audio_DAC_fast_PowerOff_ISR);
    #endif
	QSPI_XIP_QuadSel_En();       // QSPI EQ = Quad Mode

    GLOBAL_INT_START();
    softtimer_init();

    USB_HID_Report_Desc_Init();
    pAFI->User_Init();

    //power on
    chipPowerOn();
    setUsbUserConfig(&gstOTP);//设置用户配置的usb相关的描述字符串，及PIVD、VID等
    USB_PowerOn_Init(0);

	#ifdef JACK_SENSE_FUNC
        Earphone_Detect_SetCallBack(EARPHONE_DETECT_COMPLET, (uint32_t)EarPhone_Complet_Process);
        Earphone_Detect_Init();
        if(1 == g_pstConfig->FuncCfg.JackSenseSel)
        {
            Jack_InsRmvDet_ByGpio_Init();       //use gpio3 as jack insert remove detection source .
        }
        TypecTo3p5_Init();//waiting for 耳机插入
    #else
        USB_Audio_Config();
    #endif
    pga_init();
    // USB_SetOTP(gstOTP);//设置usb的一些字符串描述符及PID VID等
    PwrBrk_enable(10);

    #ifdef HIGH_FREQ_OSC_TRIM_TEST
        //mclk as refclk for high freq OSC trim
        apb_clk_gen_clksel_cali_clk_sel_setf(2);
        apb_osc_cali_ctrl0_osc_cali_code_flag_setf(1);
    #endif
    // 1、原来USB_DONGLE模式下不进入待机，现在也会
    // 2、有插拔检测功能的暂时不初始化standby功能，否则可能没完成初次的插拔检测就已经进待机了
    #ifndef JACK_SENSE_FUNC 
    {
        Standby_Req_UnInit();
        Suspend_Init();//Suspend_Init的时候会打开mic的中断，导致mic按键还会触发中断，因没有调用中断回调函数，死机
        Standby_Req_Init();
        Standby_Req_SetCallBack(STANDBY_REQ, (uint32_t)EnterExit_Standby);
    }
    #endif
}


void patch_plf_schedule(void)
{
    ke_event_schedule();
    pAFI->User_Schedule();
    new_ROM_Schedule();
    Itrim_Monitor();
    MsgSchedule();
}

int main_flash(void)
{
    cache_on();

    patch_other_init();

    patch_patch_init();

    patch_plf_init();

    while (1) {
        patch_plf_schedule();
    }
}
