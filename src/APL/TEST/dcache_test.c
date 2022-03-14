/*
 * dcache_test.c
 *
 *  Created on: 2019-8-28
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

extern main_ftable_t *main_ftable;

extern void User_Init(void);
extern void User_Schedule(void);

extern void patch_patch_init(void);
extern void patch_plf_schedule(void);
extern void patch_plf_init(void);
extern void p_plf_uninit(void);

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

#define BIT(x)  (1UL << (x))
typedef enum pfm_type_enum
{
    PFM_TYPE_HIT_RATE_D,
    PFM_TYPE_HIT_RATE_I,
    PFM_TYPE_MAX,
} PFM_type_e;
PFM_type_e _ePFMtpye = PFM_TYPE_MAX;
uint32_t g_uMissRate;

typedef enum return_enum
{
    OK_RETURN,
    FAIL_RETURN,
    RETURN_INTPUT_INVALID,
    RETURN_MAX,
} return_e;

return_e PFM_start(PFM_type_e ePFMtpye)
{
    unsigned int counter0 = 0, counter1 = 0, counter2 = 0;
    unsigned int ctrl = 0, msc_cfg = 0;
//    unsigned int sdz_ctl = 0;
    return_e eRet = OK_RETURN;
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);

//    sdz_ctl = __nds32__mfsr(NDS32_SR_SDZ_CTL);
//    sdz_ctl &= 0xFFFFF1F8;
//    sdz_ctl |= 0x1;
//    sdz_ctl |= (0x3 << 9);
//    __nds32__mtsr_dsb(sdz_ctl, NDS32_SR_SDZ_CTL);

    //check performance monitoring mechanism(counters) exists or not
    if (!(msc_cfg & 0x4))
    {
        return FAIL_RETURN;
    }

    //Counter0
    __nds32__mtsr_dsb(counter0, NDS32_SR_PFMC0);

    //Counter1
    __nds32__mtsr_dsb(counter1, NDS32_SR_PFMC1);

    //Counter2
    __nds32__mtsr_dsb(counter2, NDS32_SR_PFMC2);

    /* Enable performance counter0 , counter1, counter2 */
    ctrl |= BIT(0)| BIT(1)| BIT(2);
    /* Calculate Cycles for counter0 */
    ctrl |= (0UL << 15);
    switch(ePFMtpye)
    {
        case PFM_TYPE_HIT_RATE_I:
            /* Calculate ICache access for counter1 */
            ctrl |= (17 << 16);
            /* Calculate ICache miss  for counter2 */
            ctrl |= (17 << 22);
            break;
        case PFM_TYPE_HIT_RATE_D:
            /* Calculate DCache access for counter1 */
            ctrl |= (20 << 16);
            /* Calculate DCache miss for counter2 */
            ctrl |= (21 << 22);
            break;
        default:
            eRet = RETURN_INTPUT_INVALID;
            break;
    }
    _ePFMtpye = ePFMtpye;
    __nds32__mtsr(ctrl, NDS32_SR_PFM_CTL);
    return eRet;
}

return_e PFM_stop()
{
    unsigned int pfm_ctl, msc_cfg = 0;
    return_e eRet = OK_RETURN;
    char uart_str[80]={0};

    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);

    //check performance monitoring mechanism(counters) exists or not
    if (!(msc_cfg & 0x4))
    {
        return FAIL_RETURN;
    }

//    pfm_ctl = __nds32__mfsr(NDS32_SR_PFM_CTL);
//    //Disable all counters
//    pfm_ctl = pfm_ctl & 0xFFFFFFF8;//pfm_ctl = Write4Byte(pfm_ctl,BIT(0)| BIT(1)| BIT(2),FALSE)
//    __nds32__mtsr(pfm_ctl, NDS32_SR_PFM_CTL);

    volatile uint64_t counter0 = __nds32__mfsr(NDS32_SR_PFMC0);
    volatile uint64_t counter1 = __nds32__mfsr(NDS32_SR_PFMC1);
    volatile uint64_t counter2 = __nds32__mfsr(NDS32_SR_PFMC2);

    (void )counter0;
    (void )counter1;
    (void )counter2;

    switch(_ePFMtpye)
    {
        case PFM_TYPE_HIT_RATE_I:
            //Read cycles count for counter0
        //	sprintf(uart_str,"The cycles for counter0 is = %d \n", counter0);

            //Read cycles count for counter0
      //  	sprintf(uart_str,"The hit rate for I-cache is = %d \n", (counter1*10000)/(counter1+counter2));
            g_uMissRate = (counter2 * 10000)/(counter1);
            // sprintf(uart_str,"%d %d The miss rate for I-cache is = %d \n", (int)counter2, (int)counter1, (int)g_uMissRate);
            sprintf(uart_str,"%u %u %u The miss rate for I-cache is = %u \n", (unsigned int)counter0, (unsigned int)counter1, (unsigned int)counter2, (unsigned int)g_uMissRate);

            //Read ICache access count for counter1
        //	sprintf(uart_str,"The I-Cache access count for counter1 is = %d \n", counter1);

            //Read DCache access count for counter2
        //	sprintf(uart_str,"The I-Cache miss count for counter2 is = %d \n", counter2);
            uart_write_flush((uint8_t *)uart_str, strlen(uart_str));
            break;
        case PFM_TYPE_HIT_RATE_D:
            //Read cycles count for counter0
     //   	sprintf(uart_str,"The cycles for counter0 is = %d \n", counter0);

            //Read cycles count for counter0
     //   	sprintf(uart_str,"The hit rate for D-cache is = %d \n", (counter1*10000)/(counter1+counter2));
            g_uMissRate = (counter2 * 10000)/(counter1);
            sprintf(uart_str,"%u %u %u The miss rate for D-cache is = %u \n", (unsigned int)counter0, (unsigned int)counter1, (unsigned int)counter2, (unsigned int)g_uMissRate);
            //Read ICache access count for counter1
     //   	sprintf(uart_str,"The D-Cache access count for counter1 is = %d \n", counter1);

            //Read DCache access count for counter2
        //	sprintf(uart_str,"The D-Cache miss count for counter2 is = %d \n", counter2);

            uart_write_flush((uint8_t *)uart_str, strlen(uart_str));
            break;
        default:
            eRet = RETURN_INTPUT_INVALID;
            break;
    }
    return eRet;
}

void patch_patch_init(void)
{
    new_power_on_patch_init();
    new_power_off_patch_init();
    power_ctrl_patch_init();
    audio_patch_init();
    new_audio_in_patch_init();
    new_audio_out_patch_init();
    // user_patch_init();
    new_usb_hid_patch_init();
    new_usb_ch9_patch_init();
    usb_intr_patch_init();
    new_usb_audio_patch_init();
    new_usb_app_patch_init();
    new_usb_sdk_patch_init();
    new_usb_dongle_patch_init();
    usb_HeadPhone_patch_init();
    new_usb_HeadSet_patch_init();
    new_usb_Test_patch_init();
    new_usb_3p5_patch_init();
    new_Suspend_patch_init();
    ecld_patch_init();
    new_asrc_adc_patch_init(); //new
    new_asrc_codec_patch_init();
    new_asrc_dac_patch_init();
    drc_patch_init();
    new_dsp_patch_init();
    eq_patch_init();
    eq_top_patch_init();
    new_hss_det_patch_init();

    new_saradc_patch_init();
    new_earphone_key_detect_patch_init();

    new_surround_3d_patch_init();
    volume_patch_init();
    nco_patch_init();
    nco_write_patch_init();
    process_adc2usb_patch_init();
#if 0
    process_i2s_patch_init();
    reverb_patch_init();
    echo_patch_init();
    freq_shift_patch_init();
    howling_detect_patch_init();
#endif
    new_process_usb2dac_patch_init();

    new_I2sNco_patch_init();
    new_Standby_Req_patch_init();
    new_EarphoneIRDet_patch_init();
    Earphone_KWP_Det_patch_init();

    pAFI = (api_ftable_t *)0x97000;
    if(pAFI->MagicKey != stApiFunctionTableDft.MagicKey)
    {
        pAFI = (api_ftable_t *)&stApiFunctionTableDft;
    }

    pAFI->User_C_Init();
}

// extern void QSPI_Continue_Enable(void);

USB_OTP gstOTP;

void patch_plf_init(void)
{
    USB_OTP stOTP;
    memset(&stOTP, 0, sizeof(USB_OTP));

    if(pOtpInRam->CACHE_EN)
    {
        cache_on();
    }

    PFM_start(PFM_TYPE_HIT_RATE_D);
     QSPI_NoCacheRead_Config();
    //DC DC enable, off ldo
    if(pOtpInRam->POWER_SEL)
    {
        apb_dig_stdby_ctrl_dig_ldo_flag_setf(0);            //set as software mode
        apb_power_pd_ctrl0_dig_ref_pd_setf(1);
        apb_power_pd_ctrl0_dig_ldoh_pd_setf(1);
        apb_power_pd_ctrl0_dig_ldol_pd_setf(1);
        apb_dig_stdby_ctrl_dig_stdby_pd_setf(1);
    }

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

    // set fast power off intc
//    PD_Det_Volt_Thre_Set(0x06);
    intc_enable_set(INTC_ID_PWDN_DET, (intc_handler *)Audio_DAC_fast_PowerOff_ISR);

    GLOBAL_INT_START();
    softtimer_init();

    USB_HID_Report_Desc_Init();
    pAFI->User_Init();

    //power on
    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            TYPE_C_To_3P5_PowerOn(pOtpInRam->micbias_output_voltage_sel);
            break;
        }
        case USB_TYPEC_HEADSET:
        {
            Headset_PowerOn();
            break;
        }
        case USB_TYPEC_HEADPHONE:
        {
            Headphone_PowerOn();
            break;
        }
        case USB_DONGLE:
        {
            Dongle_PowerOn();
            break;
        }
        default: //USB_TEST
        {
            break;
        }
    }
    if(g_pstConfig->USBReg.UsbCodeState<=0xff)
    {
		if ((g_pstConfig->USBReg.UsbCodeState & BIT0) != 0)
		{
			stOTP.stManufact.pString = (uint8_t*)&g_pstConfig->USBReg.UsbManufact[2];
			stOTP.stManufact.bLength = g_pstConfig->USBReg.UsbManufact[0];
			stOTP.stManufact.bDescriptorType = g_pstConfig->USBReg.UsbManufact[1];
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT1) != 0)
		{
			stOTP.stProduct.pString =  (uint8_t*)&g_pstConfig->USBReg.UsbProduct[2];
			stOTP.stProduct.bLength = g_pstConfig->USBReg.UsbProduct[0];
			stOTP.stProduct.bDescriptorType = g_pstConfig->USBReg.UsbProduct[1];
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT2) != 0)
		{
			stOTP.stSerial.pString =  (uint8_t*)&g_pstConfig->USBReg.UsbSerial[2];
			stOTP.stSerial.bLength = g_pstConfig->USBReg.UsbSerial[0];
			stOTP.stSerial.bDescriptorType = g_pstConfig->USBReg.UsbSerial[1];
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT3) != 0)
		{
			stOTP.stStringID.pString =  (uint8_t*)&g_pstConfig->USBReg.UsbStringID[2];
			stOTP.stStringID.bLength = g_pstConfig->USBReg.UsbStringID[0];
			stOTP.stStringID.bDescriptorType = g_pstConfig->USBReg.UsbStringID[1];
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT4) != 0)
		{
			stOTP.u16VendorID =  g_pstConfig->USBReg.UsbVendorID;
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT5) != 0)
		{
			stOTP.u16ProductID =  g_pstConfig->USBReg.UsbProductID;
		}
		if ((g_pstConfig->USBReg.UsbCodeState & BIT6) != 0)
		{
			stOTP.u8MaxPower =  g_pstConfig->USBReg.ucUsbMaxPower;
		}
    }

    USB_PowerOn_Init(pOtpInRam->PMOD);

    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            Earphone_Detect_SetCallBack(EARPHONE_DETECT_COMPLET, (uint32_t)EarPhone_Complet_Process);
            Earphone_Detect_Init();
            if(1 == g_pstConfig->FuncCfg.JackSenseSel)
            {
                Jack_InsRmvDet_ByGpio_Init();       //use gpio3 as jack insert remove detection source .
            }
            TypecTo3p5_Init();
            break;
        }
        case USB_TYPEC_HEADSET:
        {
            USB_ConfigHeadSet();
            USB_SetAppMode(pOtpInRam->PMOD);
            break;
        }
        case USB_TYPEC_HEADPHONE:
        {
            USB_ConfigHeadPhone();
            USB_SetAppMode(pOtpInRam->PMOD);
            break;
        }
        case USB_DONGLE:
        {
            USB_ConfigDongle();
            USB_SetAppMode(pOtpInRam->PMOD);
            break;
        }
        default: //USB_TEST
        {
            USB_ConfigTest();
            USB_SetAppMode(pOtpInRam->PMOD);
            break;
        }
    }
    pga_init();
    USB_SetOTP(stOTP);
    gstOTP = stOTP;

    PwrBrk_enable(10);

#ifdef HIGH_FREQ_OSC_TRIM_TEST
    //mclk as refclk for high freq OSC trim
    apb_clk_gen_clksel_cali_clk_sel_setf(2);
    apb_osc_cali_ctrl0_osc_cali_code_flag_setf(1);
#endif

    if ((pOtpInRam->PMOD != USB_TYPEC_TO_3P5) && (pOtpInRam->PMOD != USB_DONGLE) && (pOtpInRam->PMOD != USB_TEST))
    {
        Standby_Req_UnInit();
        Suspend_Init();
        Standby_Req_Init();
        Standby_Req_SetCallBack(STANDBY_REQ, (uint32_t)EnterExit_Standby);
    }

    // apb_pad_gpio_func_cfg0_gpio3_func_sel_setf(1);
    // apb_pad_gpio_func_cfg0_gpio4_func_sel_setf(1);

    // if(g_pstConfig->FuncCfg.SupportUartCommunication)
    {
        new_uart_init(115200);
    }
    Show_Web_init();
}

uint16_t i = 0;
void patch_plf_schedule(void)
{
    ke_event_schedule();
    pAFI->User_Schedule();
    uart_schedule();
    Show_Web_schedule();
    new_ROM_Schedule();
    Itrim_Monitor();

    i++;
    if(i == 1000){
    	PFM_stop();
    	i = 0;
//    	__nds32__nop();
//    	PFM_start(PFM_TYPE_HIT_RATE_D);
//    	i = 0;
    }
//    printf("muses_v2_patch_1\n");
//    printf("muses_v2_patch_6\n");
}

