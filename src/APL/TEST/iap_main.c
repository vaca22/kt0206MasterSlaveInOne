/**
 ****************************************************************************************
 *
 * @file plf_init.c
 *
 * @brief Main loop of the application.
 *
 * @author WeighSong
 *
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "user.h"
#include "suspend.h"
#include "uart_iap.h"
#include "co_mem.h"

/**
 ****************************************************************************************
 * @addtogroup DRIVERS
 * @{
 *
 *
 * ****************************************************************************************
 */
void p_patch_init(void)
{
    power_on_patch_init();
    power_off_patch_init();
    power_ctrl_patch_init();
    qspi_ctrl_patch_init();
    audio_patch_init();
    audio_in_patch_init();
    audio_out_patch_init();
    user_patch_init();
    usb_hid_patch_init();
    usb_ch9_patch_init();
    usb_intr_patch_init();
    usb_audio_patch_init();
    usb_app_patch_init();
    usb_sdk_patch_init();
    usb_dongle_patch_init();
    usb_dongleDSP_patch_init();
    usb_HeadPhone_patch_init();
    usb_HeadSet_patch_init();
    usb_Test_patch_init();
    usb_3p5_patch_init();
    Suspend_patch_init();
    ecld_patch_init();
    asrc_adc_patch_init();
    asrc_codec_patch_init();
    asrc_dac_patch_init();
    drc_patch_init();
    dsp_patch_init();
    eq_patch_init();
    eq_top_patch_init();


    surround_3d_patch_init();
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
    process_usb2dac_patch_init();

    I2sNco_patch_init();
    Standby_Req_patch_init();
    EarphoneIRDet_patch_init();
    Earphone_KWP_Det_patch_init();
}

uint8_t buf[1100] = "ktmicro!";
uint16_t tmp_len;

volatile uint32_t g_ret;

int main(void) 
{
//    void *Addr = (void *)0x40000;
//
//    // p_patch_init();
//    mem_init(Addr, 0x10000);
//    QSPI_Init();
//	intc_init();
//    apb_pad_gpio_func_cfg0_gpio3_func_sel_setf(1);
//    apb_pad_gpio_func_cfg0_gpio4_func_sel_setf(1);
//	g_ret = uart_init();
//    g_ret = IAP_Init();
//    GLOBAL_INT_START();
	
    while(1) 
    {
        // tmp_len = uart_read(buf, 100);
        // uart_write_flush(buf, tmp_len);

        // if(tmp_len)
        // {
        //     uart_write_flush(buf, 8);
        // }

        IAP_MenuService();
    }
}
