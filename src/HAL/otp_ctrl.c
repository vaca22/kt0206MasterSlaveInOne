#include "otp_ctrl.h"
#include "comm.h"
#include "co_math.h"
#include "co_mem.h"
#include "power_on.h"
#include "asrc_dac_fs_ppm.h"
#include "hss_det.h"
#include "earphone_key_detect.h"
#include "power_on.h"
#include "usb_audio_app.h"
#include "chip_config.h"

extern int32_t DAC_DC_CALI_L;
extern int32_t DAC_DC_CALI_R;
extern uint8_t AUDAC_MUTE_BY_PDDAC_EN;
extern uint8_t AUDAC_POWEROFF_CNT_WIN;
extern uint8_t AUDAC_MUTE_DET_WIN;
extern uint32_t AUDAC_MUTE_DET_THRD;
extern uint8_t ASRC_ADC_PFORMANCE;
extern uint8_t ASRC_DAC_PFORMANCE;
extern uint8_t ASRC_DAC_PFORMANCE_96K;
extern uint8_t g_ppm_range;
extern int32_t DAC_STEREO_MODE;

extern uint32_t ramp_dcoffset;  //for OTP
extern uint32_t rampup_step;        //for OTP
extern uint32_t rampdown_step;      //for OTP

const st_OTPRegBank_t OTP_Default_Value_InFlash  __attribute__ ((section (".OTPDFT_SECTOR"))) =
{
    // uint8_t bonding_en_0;
    .chip_cfg_st = 1,
    .clk_cfg_st = 1,
    .detect_cfg_st = 0,
    .key_cfg_st = 0,
    .sys_cfg_st = 1,
    .dc_offset_st = 1,
    .saradc_cfg_st = 0,
    .dac_gain_st = 0,

    // uint8_t bonding_en_1,
    .pga_gain_st = 0,
    .itrim_cfg_st = 0,
    .usb_cfg_st = 1,
    .ana_dft_st = 0,
    .asrc_cfg_0_st = 1,
    .asrc_cfg_1_st = 0,
    .stereo_phase_st = 0,
    .mag_delta_st = 0,

    // uint8_t bonding_en_2;
    .micin_key_thrh_st = 0,
    .cg_cp_freq_sel_st = 0,
    .audac_mute_cfg_st = 0,
    .dac_stereo_cfg_st = 0,
    .dsp_cfg_st = 0,

    .bonding_en_3 = 0,
    .bonding_en_4 = 0,
    .bonding_en_5 = 0,
    .bonding_en_6 = 0,
    .bonding_en_7 = 0,
    .bonding_en_8 = 0,
    .bonding_en_9 = 0,
    .bonding_en_10 = 0,
    .bonding_en_11 = 0,
    .bonding_en_12 = 0,
    .bonding_en_13 = 0,
    .bonding_en_14 = 0,

    // uint8_t bonding_en_15,
    .thd_coeff_st = 1,
    .ic_number_st = 0,
    .chip_ver_st = 1,
    .chip_id_st = 0,
    .osc_cali_code_st = 1,
    .usb_volume_st = 1,
	.ramp_st = 1,

    // uint8_t chip_cfg_0,
    .POWER_SEL = 0,
    .FLASH_EN = 1,
    .CACHE_EN = 1,
    .PMOD = 0, //0->headset, 1->headphone, 2->usbto3.5, 3->dongle, 4->dongle+dsp, 5->test,

    // uint8_t clk_cfg_0,
    // uint8_t clk_cfg_1,
    // uint8_t clk_cfg_2,
    // uint8_t clk_cfg_3,


    .osc_div_sel_1 = 5,  //= 384/16 = 24MHz
    .ahb_div_sel_1 = 0,  //= core_clk = 24MHz
    .apb_div_sel_1 = 1,  //= core_clk/2 = 12MHz
    .qspi_div_sel_1 = 2, //= core_clk = 24MHz
    .RFU1 = 0,

    //---------------------------------------------------------------------------
    //      core_clk       ahb_clk,            apb_clk ,         qspi_clk
    //---------------------------------------------------------------------------
    //      96M,              96M,              48M                96M
    //      osc_div_sel=3    ahb_div_sel=0,   apb_div_sel=1,    qspi_div_sel=2
    //----------------------------------------------------------------------------
    //      128M,             128M,             64M                64M
    //      osc_div_sel=2    ahb_div_sel=0,   apb_div_sel=1,    qspi_div_sel=0
    //----------------------------------------------------------------------------
    //      154M,             154M,             77M                77M
    //      osc_div_sel=8    ahb_div_sel=0,   apb_div_sel=1,    qspi_div_sel=0
    //----------------------------------------------------------------------------
    //      192M,              192M,             96M                96M
    //      osc_div_sel=1    ahb_div_sel=0,   apb_div_sel=1,    qspi_div_sel=0
    //----------------------------------------------------------------------------
    // .osc_div_sel_2 = 8,  //= 384/3 = 154MHz
    // .ahb_div_sel_2 = 0,  //= core_clk = 154MHz
    // .apb_div_sel_2 = 1,  //= core_clk/2 = 77MHz
    // .qspi_div_sel_2 = 0, //= core_clk/2 = 77MHz

//    .osc_div_sel_2 = 2,  //= 384/3 = 128MHz
//    .ahb_div_sel_2 = 0,  //= core_clk = 128MHz
//    .apb_div_sel_2 = 1,  //= core_clk/2 = 64MHz
//    .qspi_div_sel_2 = 0, //= core_clk/2 = 64MHz

   .osc_div_sel_2 = 1,  //= 384/3 = 192MHz
   .ahb_div_sel_2 = 0,  //= core_clk = 192MHz
   .apb_div_sel_2 = 1,  //= core_clk/2 = 96MHz
   .qspi_div_sel_2 = 0, //= core_clk/2 = 96MHz

    .RFU2 = 0,

    .detect_cfg_0 = 0,
    // .key_val_0 = 0x50,      //play/pause thrd
    // .key_val_1 = 0xBF,      //VOLUME UP low threshold
    // .key_val_2 = 0x120,     //VOLUME UP high threshold
    // .key_val_3 = 0x130,     //VOLUME DOWN low threshold
    // .key_val_4 = 0x250,     //VOLUME DOWN high threshold
    // .key_val_5 = 0x70,      //MUTE low threshold
    // .key_val_6 = 0xB1,      //MUTE high threshold
    .key_long_press_time = 0,

    .MicinDebounceSel = 3,
    .MicinVoltageThresholdSel = 0,
    .GpioKeyDebounceSel = 3,
    .RFU4 = 0,
    .micbias_output_voltage_sel = 0,
    .RFU3 = 0,

    // uint8_t sys_cfg_0,
    // uint8_t sys_cfg_1,
#if(Deleate_Pop_standby == 0)
    .dc_offset_l = 0,
    .dc_offset_r = 0,
#else
    .dc_offset_l = -10000,
	.dc_offset_r = -8500,
#endif
    .saradc_a = 0x6AAB,
    .saradc_b = 0x00,
    .dac_gain = 0,
    .pga_gain = 0,
    .itrim_monitor_en = 1,
    .saradc_pdata_avg_num = 0,

    // .UsbCodeState = 0xB6,
    // .UsbManufact = "UsbManufact",
    // .UsbProduct = {
    // 	 0x22,	   // length
    //    	 0x03, 	   // descriptor type = string
    //      'K' , 0x00,
    //    	 'T' , 0x00,
    //    	 'M' , 0x00,
    //    	 'I' , 0x00,
    //    	 'C' , 0x00,
    // 	 'R' , 0x00,
    //    	 '-' , 0x00,
    //      'D' , 0x00,
    //      'e' , 0x00,
    //      'v' , 0x00,
    //      'i' , 0x00,
    //    	 'c' , 0x00,
    //      'e' , 0x00,
    //      '-' , 0x00,
    //      '0' , 0x00,
    //      '1' , 0x00},

    // .UsbSerial = {
    //      0x22,     // length
    //      0x03,     // descriptor type = string
    //      '2' , 0x00,
    //      '1' , 0x00,
    //      '4' , 0x00,
    //      'b' , 0x00,
    //      '2' , 0x00,
    //      '0' , 0x00,
    //      '6' , 0x00,
    //      '0' , 0x00,
    //      '0' , 0x00,
    //      '0' , 0x00,
    //      '0' , 0x00,
    //      '0' , 0x00,
    //      '0' , 0x00,
    //      '1' , 0x00,
    //      '0' , 0x00,
    //      '1' , 0x00},

    // .UsbStringID = "kt123",
    // .UsbVendorID = 0x31B3,//0x165b,//
    // .UsbProductID = 0x0011,//0x2430,//
    // .ucUsbMaxPower = 0,

    // .out_frequency_en = 0x3FF,
    // .in_frequency_en = 0x1FF,
    .audio_ctrl0 = 0,
    .audio_ctrl1 = 0,
    .audio_ctrl2 = 0,
    .audio_ctrl3 = 0,
    .audio_ctrl5 = 0,
    .audio_ctrl6 = 0,
    .audio_pd_rst = 0,
    .osc_ctrl = 0,
    .ref_ctrl = 0,
    .saradc_ctrl = 0,
    .xtal_ctrl = 0,
    .clk_gen_clksel = 0,
    .clk_gen_clken = 0,
    .rst_gen_ctrl0 = 0,
    .rst_gen_ctrl1 = 0,
    .i2s_status0 = 0,
    .i2s_status1 = 0,
    .i2s_status2 = 0,
    .i2s_status3 = 0,
    .i2s_ctrl1 = 0,
    .i2s_ctrl2 = 0,
    .pad_i2s_sw_ctrl2 = 0,
    .pad_gpio_func_cfg = 0,
    .pad_spi_func_cfg = 0,
    .pad_i2s_func_cfg = 0,
    .spare_reg0 = 0,
    .spare_reg1 = 0,
    .spare_reg2 = 0,
    .spare_reg3 = 0,

    // uint8_t asrc_cfg_0;
    .asrc_ppm_range = 3,

    // uint8_t asrc_cfg_1;
    .asrc_dac_performance = 0,
    .asrc_dac_performance_96k = 0,
    .asrc_adc_performance = 0,

    .stereo_phase_a = 0,
    .stereo_phase_b = 0,
    .stereo_phase_c = 0,
    .left_mag_delta = 0,
    .right_mag_delta = 0,
    .micin_key_thrh = 0,
    .cg_cp_freq_sel_h_rail = 0,
    .cg_cp_freq_sel_l_rail = 0,
    .audac_mute_by_pddac_en = 0,
    .audac_poweroff_cnt_win = 0,
    .audac_mute_det_win = 0,
    .audac_mute_det_thrd = 0,
    .dac_stereo_mode = 0,

    .dsp_eq_band0 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band1 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band2 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band3 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band4 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band5 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band6 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band7 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band8 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band9 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band10 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band11 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band12 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band13 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_eq_band14 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_wnf0 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_wnf1 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_wnf2 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_wnf3 = { .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0 },
    .dsp_wnf4 = {  .en = 0, .freq = 0, .type = 0, .qv = 0, .dBgain = 0},
    .dsp_drc_0 = 0,
    .dsp_drc_1 = 0,
    .dsp_drc_2 = 0,
    .dsp_drc_3 = 0,
    .dsp_drc_4 = 0,
    .dsp_drc_5 = 0,
    .dsp_drc_6 = 0,
    .dsp_drc_7 = 0,
    .dsp_railctrl_0 = 0xA9,
    .dsp_railctrl_1 = 0x80,
    .dsp_sidetone = 0x67,
    .dsp_volume_0 = 0x67,
    .dsp_volume_1 = 0x67,
    .dsp_ans = 0x00,
    .dsp_surround_3d = 0x10,

    .thd_r_coeff3 = 128,
    .thd_r_coeff2 = 128,
    .thd_l_coeff3 = 128,
    .thd_l_coeff2 = 128,
#ifdef KT0203
    .ic_number = "0203B04",
#else
    .ic_number = "0201B04",
#endif
    .ramp_dcoffset = 79138/2,
    .rampup_step = 100,
    .rampdown_step = 400,
    .volume_min = 0xCE00,//0xCC00,
    .volume_max = 0x0000,//0xFE00,
    .volume_res = 0x0080,
    .osc_cali_code = 0x2D, //Each chip may be different, please set a correct code
    .chip_id = 0,
    .hardware_ver = 0x4B020242,
    .firmware_ver = 0x4B020242,
};

void patch_OTP_Read_All(void)
{
    uint32_t *pOTP = (uint32_t *)OTPC_BASE;
    uint8_t *pTmp = (uint8_t *)RAM_OTP_REG_BASE_ADDR;
    uint32_t i;

    for(i = 0; i < 16; i++)
    {
        ((volatile uint8_t *)pOtpInRam)[i] = (uint8_t)pOTP[i];
    }

    if(pOtpInRam->chip_cfg_st)
    {
       ((volatile uint8_t *)pOtpInRam)[16] = (uint8_t)pOTP[16];
    }

    if(pOtpInRam->clk_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[17], &pOTP[17] , 4);
    }

    if(pOtpInRam->detect_cfg_st)
    {
        ((volatile uint8_t *)pOtpInRam)[31] = (uint8_t)pOTP[31];
    }

    if(pOtpInRam->key_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[32], &pOTP[32] , 15);
    }

    if(pOtpInRam->sys_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[47], &pOTP[47] , 2);
    }

    if(pOtpInRam->dc_offset_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[64], &pOTP[64] , 8);
    }

    if(pOtpInRam->saradc_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[72], &pOTP[72] , 3);
    }

    if(pOtpInRam->dac_gain_st)
    {
        ((volatile uint8_t *)pOtpInRam)[75] = (uint8_t)pOTP[75];
    }

    if(pOtpInRam->pga_gain_st)
    {
        ((volatile uint8_t *)pOtpInRam)[76] = (uint8_t)pOTP[76];
    }

    if(pOtpInRam->itrim_cfg_st)
    {
        ((volatile uint8_t *)pOtpInRam)[77] = (uint8_t)pOTP[77];
    }

    // if(pOtpInRam->usb_cfg_st)
    // {
    //     ((volatile uint8_t *)pOtpInRam)[97] = (uint8_t)pOTP[97];

    //     if(pOtpInRam->UsbCodeState & CO_BIT(0))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[98], &pOTP[98] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(1))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[158], &pOTP[158] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(2))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[218], &pOTP[218] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(3))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[278], &pOTP[278] , 10);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(4))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[288], &pOTP[288] , 2);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(5))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[290], &pOTP[290] , 2);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(6))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[292], &pOTP[292] , 1);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(7))
    //     {
    //         MEM_Cpy_Byte_Word(&pTmp[294], &pOTP[294] , 4);
    //     }
    // }

    if(pOtpInRam->ana_dft_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[320], &pOTP[320] , 116);
    }

    if(pOtpInRam->asrc_cfg_0_st)
    {
        ((volatile uint8_t *)pOtpInRam)[436] = (uint8_t)pOTP[436];
    }

    if(pOtpInRam->asrc_cfg_1_st)
    {
        ((volatile uint8_t *)pOtpInRam)[437] = (uint8_t)pOTP[437];
    }

    if(pOtpInRam->stereo_phase_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[442], &pOTP[442] , 6);
    }

    if(pOtpInRam->mag_delta_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[448], &pOTP[448] , 2);
    }

    if(pOtpInRam->micin_key_thrh_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[450], &pOTP[450] , 2);
    }

    if(pOtpInRam->cg_cp_freq_sel_st)
    {
        ((volatile uint8_t *)pOtpInRam)[452] = (uint8_t)pOTP[452];
    }

    if(pOtpInRam->audac_mute_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[453], &pOTP[453] , 7);
    }

    if(pOtpInRam->dac_stereo_cfg_st)
    {
        ((volatile uint8_t *)pOtpInRam)[460] = (uint8_t)pOTP[460];
    }

    if(pOtpInRam->dsp_cfg_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[576], &pOTP[576] , 135);
    }

    if(pOtpInRam->thd_coeff_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[980], &pOTP[980] , 4);
    }

    if(pOtpInRam->ic_number_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[984], &pOTP[984] , 8);
    }

    if(pOtpInRam->ramp_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[992], &pOTP[992] , 12);
    }

    if(pOtpInRam->usb_volume_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[1004], &pOTP[1004] , 6);
    }

    if(pOtpInRam->osc_cali_code_st)
    {
        ((volatile uint8_t *)pOtpInRam)[1011] = (uint8_t)pOTP[1011];
    }

    if(pOtpInRam->chip_id_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[1012], &pOTP[1012] , 4);
    }

    if(pOtpInRam->chip_ver_st)
    {
        MEM_Cpy_Byte_Word(&pTmp[1016], &pOTP[1016] , 8);
    }

    new_OTP_Update2Variable();
}

void new_OTP_Update2Variable(void)
{
    if(pOtpInRam->clk_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[17], &pOTP[17] , 4);
    }

    if(pOtpInRam->detect_cfg_st)
    {
        //((volatile uint8_t *)pOtpInRam)[31] = (uint8_t)pOTP[31];
    }

    if(pOtpInRam->key_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[32], &pOTP[32] , 15);
        // st_earphone_key_thrd.thrd0 = pOtpInRam->key_val_0;
        // st_earphone_key_thrd.thrd1 = pOtpInRam->key_val_1;
        // st_earphone_key_thrd.thrd2 = pOtpInRam->key_val_2;
        // st_earphone_key_thrd.thrd3 = pOtpInRam->key_val_3;
        // st_earphone_key_thrd.thrd4 = pOtpInRam->key_val_4;
        // st_earphone_key_thrd.thrd5 = pOtpInRam->key_val_5;
        // st_earphone_key_thrd.thrd6 = pOtpInRam->key_val_6;
    }

    if(pOtpInRam->sys_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[47], &pOTP[47] , 2);
    }

    if(pOtpInRam->dc_offset_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[64], &pOTP[64] , 8);
        DAC_DC_CALI_L = pOtpInRam->dc_offset_l;
        DAC_DC_CALI_R = pOtpInRam->dc_offset_r;
    }

    if(pOtpInRam->saradc_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[72], &pOTP[72] , 3);
    }

    if(pOtpInRam->dac_gain_st)
    {
        //((volatile uint8_t *)pOtpInRam)[75] = (uint8_t)pOTP[75];
        apb_audio_ctrl0_audac_l_anagain_setf((pOtpInRam->dac_gain) & 0x0F);
        apb_audio_ctrl0_audac_r_anagain_setf((pOtpInRam->dac_gain >> 4) & 0x0F);
    }

    if(pOtpInRam->pga_gain_st)
    {
        //((volatile uint8_t *)pOtpInRam)[76] = (uint8_t)pOTP[76];
        apb_power_pd_ctrl1_audio_pga_cfgregs_gain_setf(pOtpInRam->pga_gain);
    }

    if(pOtpInRam->itrim_cfg_st)
    {
        //((volatile uint8_t *)pOtpInRam)[77] = (uint8_t)pOTP[77];
    }

    // if(pOtpInRam->usb_cfg_st)
    // {
    //     //((volatile uint8_t *)pOtpInRam)[97] = (uint8_t)pOTP[97];

    //     if(pOtpInRam->UsbCodeState & CO_BIT(0))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[98], &pOTP[98] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(1))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[158], &pOTP[158] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(2))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[218], &pOTP[218] , 60);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(3))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[278], &pOTP[278] , 10);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(4))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[288], &pOTP[288] , 2);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(5))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[290], &pOTP[290] , 2);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(6))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[292], &pOTP[292] , 1);
    //     }

    //     if(pOtpInRam->UsbCodeState & CO_BIT(7))
    //     {
    //         //MEM_Cpy_Byte_Word(&pTmp[294], &pOTP[294] , 4);
    //     }
    // }

    if(pOtpInRam->ana_dft_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[320], &pOTP[320] , 116);
        apb_audio_ctrl0_set(pOtpInRam->audio_ctrl0);
        apb_audio_ctrl1_set(pOtpInRam->audio_ctrl1);
        apb_audio_ctrl2_set(pOtpInRam->audio_ctrl2);
        apb_audio_ctrl3_set(pOtpInRam->audio_ctrl3);
        apb_audio_ctrl5_set(pOtpInRam->audio_ctrl5);
        apb_audio_ctrl6_set(pOtpInRam->audio_ctrl6);
        apb_audio_pd_rst_set(pOtpInRam->audio_pd_rst);

        apb_osc_ctrl_set(pOtpInRam->osc_ctrl);
        apb_ref_ctrl_set(pOtpInRam->ref_ctrl);
        apb_saradc_ctrl_set(pOtpInRam->saradc_ctrl);
        apb_xtal_ctrl_set(pOtpInRam->xtal_ctrl);

        apb_clk_gen_clksel_set(pOtpInRam->clk_gen_clksel);
        apb_clk_gen_clken_set(pOtpInRam->clk_gen_clken);
        apb_rst_gen_ctrl0_set(pOtpInRam->rst_gen_ctrl0);
        apb_rst_gen_ctrl1_set(pOtpInRam->rst_gen_ctrl1);

        apb_i2s_status0_set(pOtpInRam->i2s_status0);
        apb_i2s_status1_set(pOtpInRam->i2s_status1);
        apb_i2s_status2_set(pOtpInRam->i2s_status2);
        apb_i2s_status3_set(pOtpInRam->i2s_status3);
        apb_i2s_ctrl1_set(pOtpInRam->i2s_ctrl1);
        apb_i2s_ctrl2_set(pOtpInRam->i2s_ctrl2);

        apb_pad_i2s_sw_ctrl2_set(pOtpInRam->pad_i2s_sw_ctrl2);
        apb_pad_gpio_func_cfg0_set(pOtpInRam->pad_gpio_func_cfg);
        apb_pad_spi_func_cfg_set(pOtpInRam->pad_spi_func_cfg);
        apb_pad_i2s_func_cfg0_set(pOtpInRam->pad_i2s_func_cfg);

        apb_spare_reg0_set(pOtpInRam->spare_reg0);
        apb_spare_reg1_set(pOtpInRam->spare_reg1);
        apb_spare_reg2_set(pOtpInRam->spare_reg2);
        apb_spare_reg3_set(pOtpInRam->spare_reg3);
    }

    if(pOtpInRam->asrc_cfg_0_st)
    {
        //((volatile uint8_t *)pOtpInRam)[436] = (uint8_t)pOTP[436];
        g_ppm_range = pOtpInRam->asrc_ppm_range;
    }

    if(pOtpInRam->asrc_cfg_1_st)
    {
        //((volatile uint8_t *)pOtpInRam)[437] = (uint8_t)pOTP[437];
        ASRC_DAC_PFORMANCE = pOtpInRam->asrc_dac_performance;
        ASRC_DAC_PFORMANCE_96K = pOtpInRam->asrc_dac_performance_96k;
        ASRC_ADC_PFORMANCE = pOtpInRam->asrc_adc_performance;
    }

    if(pOtpInRam->stereo_phase_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[442], &pOTP[442] , 6);
        stereo_phase_a = pOtpInRam->stereo_phase_a;
        stereo_phase_b = pOtpInRam->stereo_phase_b;
        stereo_phase_c = pOtpInRam->stereo_phase_c;
    }

    if(pOtpInRam->mag_delta_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[448], &pOTP[448] , 2);
        left_mag_delta = pOtpInRam->left_mag_delta;
        right_mag_delta = pOtpInRam->right_mag_delta;
    }

    if(pOtpInRam->micin_key_thrh_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[450], &pOTP[450] , 2);
        micin_key_thrh = pOtpInRam->micin_key_thrh;
    }

    if(pOtpInRam->cg_cp_freq_sel_st)
    {
        //((volatile uint8_t *)pOtpInRam)[452] = (uint8_t)pOTP[452];
        ucHighRailCpClk = pOtpInRam->cg_cp_freq_sel_h_rail;
        ucLowRailCpClk = pOtpInRam->cg_cp_freq_sel_l_rail;
    }

    if(pOtpInRam->audac_mute_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[453], &pOTP[453] , 7);
        AUDAC_MUTE_BY_PDDAC_EN = pOtpInRam->audac_mute_by_pddac_en;
        AUDAC_POWEROFF_CNT_WIN = pOtpInRam->audac_poweroff_cnt_win;
        AUDAC_MUTE_DET_WIN = pOtpInRam->audac_mute_det_win;
        AUDAC_MUTE_DET_THRD = pOtpInRam->audac_mute_det_thrd;
    }

    if(pOtpInRam->dac_stereo_cfg_st)
    {
        //((volatile uint8_t *)pOtpInRam)[460] = (uint8_t)pOTP[460];
        DAC_STEREO_MODE = pOtpInRam->dac_stereo_mode;
    }

    if(pOtpInRam->dsp_cfg_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[576], &pOTP[576] , 135);
    }

    if(pOtpInRam->thd_coeff_st)
    {
        // MEM_Cpy_Byte_Word(&pTmp[980], &pOTP[980] , 4);
    }

    if(pOtpInRam->ic_number_st)
    {
        // MEM_Cpy_Byte_Word(&pTmp[988], &pOTP[988] , 4);
    }

    if(pOtpInRam->ramp_st)
    {
        ramp_dcoffset = pOtpInRam->ramp_dcoffset;
        rampup_step = pOtpInRam->rampup_step;
        rampdown_step = pOtpInRam->rampdown_step;
    }

    if(pOtpInRam->usb_volume_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[1004], &pOTP[1004] , 6);
        g_usVolumeMin = pOtpInRam->volume_min;
        g_usVolumeMax = pOtpInRam->volume_max;
        g_usVolumeRes = pOtpInRam->volume_res;
    }

    if(pOtpInRam->osc_cali_code_st)
    {
        //((volatile uint8_t *)pOtpInRam)[1011] = (uint8_t)pOTP[1011];
        osc_cali_code_config(pOtpInRam->osc_cali_code);
    }

    if(pOtpInRam->chip_id_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[1012], &pOTP[1012] , 4);
    }

    if(pOtpInRam->chip_ver_st)
    {
        //MEM_Cpy_Byte_Word(&pTmp[1016], &pOTP[1016] , 8);
    }
}
