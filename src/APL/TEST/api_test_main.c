/*
 * api_test_main.c
 *
 *  Created on: Sep 29, 2019
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
#include "api.h"

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

uint8_t tempBuf1[256] = {0};
uint8_t tempBuf2[256] = {0};
uint8_t hello[8] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};

void patch_plf_init(void)
{
    if(pOtpInRam->CACHE_EN)
    {
        cache_on();
    }
//    QSPI_NoCacheRead_Config();

//    mem_init((void *)&__bss1_end, 0x1200);
//    g_uEndOfStackAddr += 0x1200;
//    uart_uninit();
//    uart_buf_init(0x100, 0x100);
//    gp_public_buf = (uint8_t *)mem_malloc("public_buf", 0x1000, 1);
//    stack_fill();

//    ke_init();
//    new_intc_init();
//    timer_init();
//    ChipCfg_Init(); //todo

//    GLOBAL_INT_START();
//    softtimer_init();

    GLOBAL_INT_STOP();

//    api_flash_sector_erase(0x40000, 0x1000);

//    api_flash_param_save(0x20000, hello, sizeof(hello));
//    api_flash_param_save(0x20100, hello, sizeof(hello));

    api_flash_param_read(0x10000, tempBuf1, sizeof(tempBuf1));
    api_flash_param_read(0x10000, tempBuf2, sizeof(tempBuf2));

    __nds32__nop();
}


void patch_plf_schedule(void)
{
	while(1);
    ke_event_schedule();
    pAFI->User_Schedule();
    uart_schedule();
    Show_Web_schedule();
    new_ROM_Schedule();
    Itrim_Monitor();
}



