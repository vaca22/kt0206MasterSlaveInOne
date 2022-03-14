#ifndef _OTP_CTRL_H_
#define _OTP_CTRL_H_

#include "comm.h"
#include "config.h"
#include "reg_otp.h"

typedef struct
{
	uint16_t en: 1;
	uint16_t freq: 15;
	uint16_t type: 3;
	uint16_t qv: 13;
	uint8_t dBgain;
	uint8_t dsp_spare_0;
}st_dsp_wnf_x;

//notice: define as word align
typedef struct
{
	// uint8_t bonding_en_0;
	uint8_t chip_cfg_st: 1;
	uint8_t clk_cfg_st: 1;
	uint8_t detect_cfg_st: 1;
	uint8_t key_cfg_st: 1;
	uint8_t sys_cfg_st: 1;
	uint8_t dc_offset_st: 1;
	uint8_t saradc_cfg_st: 1;
	uint8_t dac_gain_st: 1;

	// uint8_t bonding_en_1;
	uint8_t pga_gain_st: 1;
	uint8_t itrim_cfg_st: 1;
	uint8_t usb_cfg_st: 1;
	uint8_t ana_dft_st: 1;
	uint8_t asrc_cfg_0_st: 1;
	uint8_t asrc_cfg_1_st: 1;
	uint8_t stereo_phase_st: 1;
	uint8_t mag_delta_st: 1;

	// uint8_t bonding_en_2;
	uint8_t micin_key_thrh_st: 1;
	uint8_t cg_cp_freq_sel_st: 1;
	uint8_t audac_mute_cfg_st: 1;
	uint8_t dac_stereo_cfg_st: 1;
	uint8_t dsp_cfg_st: 1;
	uint8_t bonding_en_2_rfu: 3;

	uint8_t bonding_en_3;
	uint8_t bonding_en_4;
	uint8_t bonding_en_5;
	uint8_t bonding_en_6;
	uint8_t bonding_en_7;
	uint8_t bonding_en_8;
	uint8_t bonding_en_9;
	uint8_t bonding_en_10;
	uint8_t bonding_en_11;
	uint8_t bonding_en_12;
	uint8_t bonding_en_13;
	uint8_t bonding_en_14;

	// uint8_t bonding_en_15;
	uint8_t bonding_en_15_rfu: 1;
	uint8_t thd_coeff_st: 1;
	uint8_t ic_number_st: 1;
	uint8_t ramp_st: 1;
	uint8_t usb_volume_st: 1;
	uint8_t osc_cali_code_st: 1;
	uint8_t chip_id_st: 1;
	uint8_t chip_ver_st: 1;

	// uint8_t chip_cfg_0;
	uint8_t PMOD: 5;
	uint8_t CACHE_EN: 1;
	uint8_t FLASH_EN: 1;
	uint8_t POWER_SEL: 1;

	// uint8_t clk_cfg_0;
	// uint8_t clk_cfg_1;
	// uint8_t clk_cfg_2;
	// uint8_t clk_cfg_3;
	uint8_t apb_div_sel_1: 2;
	uint8_t ahb_div_sel_1: 2;
	uint8_t osc_div_sel_1: 4;
	uint8_t RFU1: 6;
	uint8_t qspi_div_sel_1: 2;

	uint8_t apb_div_sel_2: 2;
	uint8_t ahb_div_sel_2: 2;
	uint8_t osc_div_sel_2: 4;
	uint8_t RFU2: 6;
	uint8_t qspi_div_sel_2: 2;

	uint8_t spare_0[10];
	uint8_t detect_cfg_0;
	uint16_t key_val_0;
	uint16_t key_val_1;
	uint16_t key_val_2;
	uint16_t key_val_3;
	uint16_t key_val_4;
	uint16_t key_val_5;
	uint16_t key_val_6;
	uint8_t key_long_press_time;

	// uint8_t sys_cfg_0;
	// uint8_t sys_cfg_1;
	uint8_t RFU4: 1;
	uint8_t GpioKeyDebounceSel: 2;
	uint8_t MicinVoltageThresholdSel: 3;
	uint8_t MicinDebounceSel: 2;
	uint8_t RFU3: 5;
	uint8_t micbias_output_voltage_sel: 3;
	uint8_t spare_1[15];

	int32_t dc_offset_l;
	int32_t dc_offset_r;
	uint16_t saradc_a;
	uint8_t saradc_b;

	uint8_t dac_gain;
	uint8_t pga_gain;
	uint8_t itrim_monitor_en: 1;
	uint8_t itrim_ctrl_rfu: 3;
	uint8_t saradc_pdata_avg_num: 4;
	uint8_t spare_2[19];

	uint8_t UsbCodeState;
	uint8_t UsbManufact[60];
	uint8_t UsbProduct[60];
	uint8_t UsbSerial[60];
	uint8_t UsbStringID[10];
	uint16_t UsbVendorID;
	uint16_t UsbProductID;
	uint8_t ucUsbMaxPower;
	uint8_t spare_3[1];

	uint16_t out_frequency_en;
	uint16_t in_frequency_en;
	uint8_t spare_4[22];

	uint32_t audio_ctrl0;
	uint32_t audio_ctrl1;
	uint32_t audio_ctrl2;
	uint32_t audio_ctrl3;
	uint32_t audio_ctrl5;
	uint32_t audio_ctrl6;
	uint32_t audio_pd_rst;
	uint32_t osc_ctrl;
	uint32_t ref_ctrl;
	uint32_t saradc_ctrl;
	uint32_t xtal_ctrl;
	uint32_t clk_gen_clksel;
	uint32_t clk_gen_clken;
	uint32_t rst_gen_ctrl0;
	uint32_t rst_gen_ctrl1;
	uint32_t i2s_status0;
	uint32_t i2s_status1;
	uint32_t i2s_status2;
	uint32_t i2s_status3;
	uint32_t i2s_ctrl1;
	uint32_t i2s_ctrl2;
	uint32_t pad_i2s_sw_ctrl2;
	uint32_t pad_gpio_func_cfg;
	uint32_t pad_spi_func_cfg;
	uint32_t pad_i2s_func_cfg;
	uint32_t spare_reg0;
	uint32_t spare_reg1;
	uint32_t spare_reg2;
	uint32_t spare_reg3;

	// uint8_t asrc_cfg_0;
	uint8_t asrc_ppm_range: 3;
	uint8_t asrc_ppm_RFU0: 5;

	// uint8_t asrc_cfg_1;
	uint8_t asrc_dac_performance: 2;
	uint8_t asrc_dac_performance_96k: 2;
	uint8_t asrc_adc_performance: 2;
	uint8_t asrc_performance_RFU0: 2;
	
	uint8_t spare_45[4];
	uint16_t stereo_phase_a;
	uint16_t stereo_phase_b;
	uint16_t stereo_phase_c;
	uint8_t	left_mag_delta;
	uint8_t	right_mag_delta;
	uint16_t micin_key_thrh;
	uint8_t cg_cp_freq_sel_h_rail: 3;
	uint8_t cg_cp_freq_sel_rfu1: 1;
	uint8_t cg_cp_freq_sel_l_rail: 3;
	uint8_t cg_cp_freq_sel_rfu2: 1;
	uint8_t audac_mute_by_pddac_en;
	uint8_t audac_poweroff_cnt_win;
	uint8_t audac_mute_det_win;
	uint32_t audac_mute_det_thrd;
	uint8_t dac_stereo_mode;
	uint8_t spare_5[115];

	st_dsp_wnf_x dsp_eq_band0;
	st_dsp_wnf_x dsp_eq_band1;
	st_dsp_wnf_x dsp_eq_band2;
	st_dsp_wnf_x dsp_eq_band3;
	st_dsp_wnf_x dsp_eq_band4;
	st_dsp_wnf_x dsp_eq_band5;
	st_dsp_wnf_x dsp_eq_band6;
	st_dsp_wnf_x dsp_eq_band7;
	st_dsp_wnf_x dsp_eq_band8;
	st_dsp_wnf_x dsp_eq_band9;
	st_dsp_wnf_x dsp_eq_band10;
	st_dsp_wnf_x dsp_eq_band11;
	st_dsp_wnf_x dsp_eq_band12;
	st_dsp_wnf_x dsp_eq_band13;
	st_dsp_wnf_x dsp_eq_band14;
	st_dsp_wnf_x dsp_wnf0;
	st_dsp_wnf_x dsp_wnf1;
	st_dsp_wnf_x dsp_wnf2;
	st_dsp_wnf_x dsp_wnf3;
	st_dsp_wnf_x dsp_wnf4;
	uint8_t dsp_drc_0;
	uint8_t dsp_drc_1;
	uint8_t dsp_drc_2;
	uint8_t dsp_drc_3;
	uint8_t dsp_drc_4;
	uint8_t dsp_drc_5;
	uint8_t dsp_drc_6;
	uint8_t dsp_drc_7;
	uint8_t dsp_railctrl_0;
	uint8_t dsp_railctrl_1;
	uint8_t dsp_sidetone;
	uint8_t dsp_volume_0;
	uint8_t dsp_volume_1;
	uint8_t dsp_ans;
	uint8_t dsp_surround_3d;
	uint8_t spare_6[269];
	uint8_t thd_r_coeff3;
	uint8_t thd_r_coeff2;
	uint8_t thd_l_coeff3;
	uint8_t thd_l_coeff2;
	uint8_t ic_number[8];
	uint32_t ramp_dcoffset;
	uint32_t rampup_step;
	uint32_t rampdown_step;
	uint16_t volume_min;
	uint16_t volume_max;
	uint16_t volume_res;
	uint8_t spare_7;
	uint8_t osc_cali_code;
	uint32_t chip_id;
	uint32_t hardware_ver;
	uint32_t firmware_ver;
}st_OTPRegBank_t;

#define OTP_READ_PART_POST	(16)

typedef enum
{
	USB_TYPEC_HEADSET,
	USB_TYPEC_HEADPHONE,
	USB_TYPEC_TO_3P5,
	USB_DONGLE,
	USB_DONGLE_DSP,
	USB_TEST,
	PRODUCT_APP_NUM,
}product_app_index_t;

extern const st_OTPRegBank_t OTP_Default_Value;
extern volatile st_OTPRegBank_t *pOtpInRam;
extern const st_OTPRegBank_t OTP_Default_Value_InFlash;

extern void OTP_Init(void);
extern void OTP_Read_Part(void);
extern void OTP_Read_All(void);
extern void OTP_Uninit(void);
extern void OTP_Update2Variable(void);

extern void patch_OTP_Read_All(void);
extern void new_OTP_Update2Variable(void);

#endif /* OTPC_H_ */
