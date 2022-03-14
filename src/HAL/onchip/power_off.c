/*
 * power_off.c
 *
 *  Created on: May 8, 2018
 *      Author: chenbowen
 */
#include "hal_config.h"
#include "power_off.h"
#include "com_includes.h"
#include "power_on.h"
#include "intc.h"
#include "timer.h"
#include "chip_config.h"

typedef struct ftable_stru
{
	void (*Charge_pump_PowerOff)(void);
	void (*Audio_DAC_normal_PowerOff)(void);
	void (*Audio_DAC_fast_PowerOff)(void);
	void (*Audio_DAC_fast_PowerOff_ISR)(void);
	void (*Audio_ADC_PowerOff)(void);
	void (*SarADC_PowerOff)(void);
	void (*XTAL_PowerOff)(void);
	void (*High_Freq_OSC_PowerOff)(void);
	void (*Dongle_PowerOff)(void);
	void (*Headset_PowerOff)(void);
	void (*Headphone_PowerOff)(void);
	void (*TYPE_C_To_3P5_PowerOff)(void);
}ftable_t;

ftable_t *power_off_ftable;

/*************************************************************************************************/
/*																								 */
/* 									Different module Power down 								 */
/*																								 */
/*************************************************************************************************/
void Charge_pump_PowerOff(void)
{
	power_off_ftable->Charge_pump_PowerOff();
}

extern void rom_Charge_pump_PowerOff(void);

void Audio_DAC_normal_PowerOff(void)
{
	power_off_ftable->Audio_DAC_normal_PowerOff();
}

//extern void rom_Audio_DAC_normal_PowerOff(void);
void patch_Audio_DAC_normal_PowerOff(void)
{
	uint32_t uTmpValue;
	/* cg_vdd_rail_sel=1 */
	apb_power_pd_ctrl1_cg_cp_freq_sel_setf(ucHighRailCpClk);
	apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(1);
	/* Delay 200us for cp high rail stable */
	timer_delay_length(200, TIM_US);
	/* cg_driver_s1(spare_reg0<21>)=0->1 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue |= 0x1<<21;
	apb_spare_reg0_set(uTmpValue);
	/* Delay 200us for classg driver stable */
	timer_delay_length(200, TIM_US);
	/* cg_driver_s2(spare_reg0<20>)=1->0 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue &= 0xFFEFFFFF;
	apb_spare_reg0_set(uTmpValue);
	/* Delay 800us for classg driver stable */
	timer_delay_length(800, TIM_US);
	/* cg_driver_s3(spare_reg0<19:16>)from 11 to 0, step 1, interval 500us */
	int8_t step;
	for(step=11; step>=0; step--)
	{
		uTmpValue = apb_spare_reg0_get();
		uTmpValue &= 0xFFF0FFFF;
		uTmpValue |= step<<16;
		apb_spare_reg0_set(uTmpValue);
		timer_delay_length(500, TIM_US);
	}
	/* Delay 100us for classg driver stable */
	timer_delay_length(100, TIM_US);
	/* cg_pdl=1 */
	apb_power_pd_ctrl1_cg_pdl_setf(1);
	/* cg_pdr=1 */
	apb_power_pd_ctrl1_cg_pdr_setf(1);
	/* cg_driver_s1(spare_reg0<21>)=1->0 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue &= 0xFFDFFFFF;
	apb_spare_reg0_set(uTmpValue);
	/* Charge pump power down sequence */
	Charge_pump_PowerOff();
	/* DAC blocks is power down */
	apb_audio_pd_rst_audac_l_pd_setf(1);
	apb_audio_pd_rst_audac_r_pd_setf(1);
	apb_audio_pd_rst_audac_l_aui_2v_pd_setf(1);
	apb_audio_pd_rst_audac_r_aui_2v_pd_setf(1);
	/* If audio in and audio out both power down, do this action */
	if((0 == g_stStartFlag.OutStartFlag) && (0 == g_stStartFlag.InStartFlag))
	{
		apb_audio_pd_rst_audac_bias_pd_setf(1);
		apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
		// uTmpValue = apb_spare_reg3_get();
		// uTmpValue |= 0x1;
		// apb_spare_reg3_set(uTmpValue);
	}
}

void Audio_DAC_fast_PowerOff(void)
{
	power_off_ftable->Audio_DAC_fast_PowerOff();
}

extern void rom_Audio_DAC_fast_PowerOff(void);

void Audio_DAC_fast_PowerOff_ISR(void)
{
	power_off_ftable->Audio_DAC_fast_PowerOff_ISR();
}

extern void rom_Audio_DAC_fast_PowerOff_ISR(void);

void Audio_ADC_PowerOff(void)
{
	power_off_ftable->Audio_ADC_PowerOff();
}

// extern void rom_Audio_ADC_PowerOff(void);
void patch_Audio_ADC_PowerOff(void)
{
	// uint32_t uTmpValue;
	// apb_power_pd_ctrl0_micbias_pd_setf(1);			/* temp */
	// apb_power_pd_ctrl0_micbias_en_setf(0);			/* temp */
	apb_power_pd_ctrl1_audio_pga_pd_setf(1);
	apb_audio_pd_rst_auadc__1_pd_setf(1);
	apb_audio_pd_rst_auadc_vcm_pd_setf(1);
	apb_audio_pd_rst_auadc_vcmo_rst_setf(1);
	apb_audio_pd_rst_auadc_rst_setf(1);
	/* If audio in and audio out both power down, do this action */
	if((0 == g_stStartFlag.OutStartFlag) && (0 == g_stStartFlag.InStartFlag))
	{
		apb_audio_pd_rst_audac_bias_pd_setf(1);
		apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
		// uTmpValue = apb_spare_reg3_get();
		// uTmpValue |= 0x1;
		// apb_spare_reg3_set(uTmpValue);
	}
}

void SarADC_PowerOff(void)
{
	power_off_ftable->SarADC_PowerOff();
}

// extern void rom_SarADC_PowerOff(void);
extern void Saradc_Uninit(void);


void XTAL_PowerOff(void)
{
	power_off_ftable->XTAL_PowerOff();
}

extern void rom_XTAL_PowerOff(void);

void High_Freq_OSC_PowerOff(void)
{
	power_off_ftable->High_Freq_OSC_PowerOff();
}

extern void rom_High_Freq_OSC_PowerOff(void);

/*************************************************************************************************/
/*																								 */
/* 									Different mode Power down 									 */
/*																								 */
/*************************************************************************************************/
void Dongle_PowerOff(void)
{
	power_off_ftable->Dongle_PowerOff();
}

//extern void patch_Dongle_PowerOff(void);
void patch_Dongle_PowerOff(void)
{
	// Standby Digital LDO Calibration
	#ifndef EXTERNAL_DVDD1P2V
    // if(0 == pOtpInRam->POWER_SEL)
    {
		// Standby Digital LDO Calibration. Assure fsm controll
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(1);
    	timer_delay_length(2,TIM_US);
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(0);

		apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(1);
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(1);
		while(!apb_dig_stdby_ctrl_dig_stdby_cali_done_fsm_getf());
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(0);
    }
	#endif

    uint8_t stdbyCaliCode;
    stdbyCaliCode = apb_dig_stdby_ctrl_dig_stdby_cali_code_fsm_getf();
    if(stdbyCaliCode>2)
    {
    	stdbyCaliCode--;
    	stdbyCaliCode--;
    }
    apb_dig_stdby_ctrl_dig_stdby_pd_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_code_setf(stdbyCaliCode);

	// SarADC
	SarADC_PowerOff();

	// XTAL
	XTAL_PowerOff();

	// Digital Part
	apb_osc_cali_ctrl0_low_power_setf(1);
#ifndef FPGA_DEBUG
	while(1)
	{
		if (0 == apb_osc_cali_ctrl0_osc_high_sw_getf())
		{
			break;
		}
	}
#endif
	// High Freq OSC
	High_Freq_OSC_PowerOff();

	// Digital Part
	// Execute standby instruction, and make system enter into standby mode.

	// Digital LDO
	// Digital_LDO_PowerOff();

	// Standby Dig LDO
	// Power on standby Digital LDO
}


void Headset_PowerOff(void)
{
	power_off_ftable->Headset_PowerOff();
}

//extern void rom_Headset_PowerOff(void);
void patch_Headset_PowerOff(void)
{
	// Standby Digital LDO Calibration
	#ifndef EXTERNAL_DVDD1P2V
    // if(0 == pOtpInRam->POWER_SEL)
    {
		// Standby Digital LDO Calibration. Assure fsm controll
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(1);
    	timer_delay_length(2,TIM_US);
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(0);

		apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(1);
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(1);
		while(!apb_dig_stdby_ctrl_dig_stdby_cali_done_fsm_getf());
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(0);
    }
	#endif

    uint8_t stdbyCaliCode;
    stdbyCaliCode = apb_dig_stdby_ctrl_dig_stdby_cali_code_fsm_getf();
    if(stdbyCaliCode>2)
    {
    	stdbyCaliCode--;
    	stdbyCaliCode--;
    }
    apb_dig_stdby_ctrl_dig_stdby_pd_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_code_setf(stdbyCaliCode);

	// Audio DAC
	Audio_DAC_normal_PowerOff();

	// Audio ADC
	Audio_ADC_PowerOff();

	// Audio ADC and DAC
	apb_audio_pd_rst_audac_bias_pd_setf(1);
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFF);

	// SarADC
	SarADC_PowerOff();

	// XTAL
	XTAL_PowerOff();

	// MicBias
	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(8);

	// Micin Detection
	apb_key_ctrl0_micin_det_pd_setf(0);

	// Audio Detection
	apb_audio_pd_rst_audio_det_pd_setf(0);

	// Digital Part
	apb_osc_cali_ctrl0_low_power_setf(1);
	Delay_100Us_600K(1);
#ifndef FPGA_DEBUG
	while(1)
	{
		if (0 == apb_osc_cali_ctrl0_osc_high_sw_getf())
		{
			break;
		}
	}
#endif

	// High Freq OSC
	High_Freq_OSC_PowerOff();
}

void Headphone_PowerOff(void)
{
	power_off_ftable->Headphone_PowerOff();
}

//extern void rom_Headphone_PowerOff(void);
void patch_Headphone_PowerOff(void)
{
	apb_pwm_ctrl2_usb_suspendm_mask_setf(0);
	apb_key_ctrl0_hss_mask_setf(0);

	apb_key_ctrl0_micin_int_mask_setf(1);
	apb_key_ctrl0_micin_mask_setf(1);
	apb_power_pd_ctrl0_micbias_pd_setf(1);
	apb_power_pd_ctrl0_micbias_en_setf(0);

	#ifndef EXTERNAL_DVDD1P2V
    // if(0 == pOtpInRam->POWER_SEL)
    {
		// Standby Digital LDO Calibration. Assure fsm controll
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(1);
    	timer_delay_length(2,TIM_US);
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(0);

		apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(1);
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(1);
		while(!apb_dig_stdby_ctrl_dig_stdby_cali_done_fsm_getf());
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(0);
    }
	#endif
    uint8_t stdbyCaliCode;
    stdbyCaliCode = apb_dig_stdby_ctrl_dig_stdby_cali_code_fsm_getf();
    if(stdbyCaliCode>2)
    {
    	stdbyCaliCode--;
    	stdbyCaliCode--;
    }
    apb_dig_stdby_ctrl_dig_stdby_pd_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_code_setf(stdbyCaliCode);

	// Audio DAC
	Audio_DAC_normal_PowerOff();

	// Audio ADC and DAC
	apb_audio_pd_rst_audac_bias_pd_setf(1);
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFF);

	// SarADC
	SarADC_PowerOff();

	// XTAL
	XTAL_PowerOff();

	// Micin Detection
	apb_key_ctrl0_micin_det_pd_setf(1);

	// Audio Detection
	apb_audio_pd_rst_audio_det_pd_setf(1);

	// Digital Part
	apb_osc_cali_ctrl0_low_power_setf(1);
#ifndef FPGA_DEBUG
	while(1)
	{
		if (0 == apb_osc_cali_ctrl0_osc_high_sw_getf())
		{
			break;
		}
	}
#endif

	// High Freq OSC
	High_Freq_OSC_PowerOff();

	// Digital Part
	// Execute standby instruction, and make system enter into standby mode.

	// Digital LDO
	// Digital_LDO_PowerOff();

	// Standby Dig LDO
	// Power on standby Digital LDO
}

void TYPE_C_To_3P5_PowerOff(void)
{
	power_off_ftable->TYPE_C_To_3P5_PowerOff();
}

//extern void rom_TYPE_C_To_3P5_PowerOff(void);
void patch_TYPE_C_To_3P5_PowerOff(void)
{
    #ifndef EXTERNAL_DVDD1P2V
	// if(0 == pOtpInRam->POWER_SEL)
    {
		// Standby Digital LDO Calibration. Assure fsm controll
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(1);
    	timer_delay_length(2,TIM_US);
    	apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(0);

		apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(1);
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(1);
		while(!apb_dig_stdby_ctrl_dig_stdby_cali_done_fsm_getf());
		apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(0);
    }
	#endif
    uint8_t stdbyCaliCode;
    stdbyCaliCode = apb_dig_stdby_ctrl_dig_stdby_cali_code_fsm_getf();
    if(stdbyCaliCode>2)
    {
    	stdbyCaliCode--;
    	stdbyCaliCode--;
    }
    apb_dig_stdby_ctrl_dig_stdby_pd_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(0);
    apb_dig_stdby_ctrl_dig_stdby_cali_code_setf(stdbyCaliCode);

	// Audio DAC
	Audio_DAC_normal_PowerOff();

	// Audio ADC
	Audio_ADC_PowerOff();

	// Audio ADC and DAC
	apb_audio_pd_rst_audac_bias_pd_setf(1);
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFF);

	// SarADC
	SarADC_PowerOff();

	// XTAL
	XTAL_PowerOff();

//	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(0);
	apb_key_ctrl0_micin_det_pd_setf(1);
	apb_audio_pd_rst_audio_det_pd_setf(1);

	// MicBias
//	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(8);
	apb_power_pd_ctrl0_micbias_pd_setf(1);			/* temp */
	apb_power_pd_ctrl0_micbias_en_setf(0);			/* temp */

	// Micin Detection
	apb_key_ctrl0_micin_det_pd_setf(0);

	// Audio Detection
	apb_audio_pd_rst_audio_det_pd_setf(0);

	// Digital Part
	apb_osc_cali_ctrl0_low_power_setf(1);
//	Delay_100Us_600K(1);

#ifndef FPGA_DEBUG
	while(1)
	{
		if (0 == apb_osc_cali_ctrl0_osc_high_sw_getf())
		{
			break;
		}
	}
#endif

	apb_osc_cali_ctrl0_osc_high_en_setf(0);
	// High Freq OSC
	High_Freq_OSC_PowerOff();
}


const ftable_t new_power_off_fi_table =
{
	.Charge_pump_PowerOff 		 = rom_Charge_pump_PowerOff,
	.Audio_DAC_normal_PowerOff   = patch_Audio_DAC_normal_PowerOff,
	.Audio_DAC_fast_PowerOff 	 = rom_Audio_DAC_fast_PowerOff,
	.Audio_DAC_fast_PowerOff_ISR = rom_Audio_DAC_fast_PowerOff_ISR,
	.Audio_ADC_PowerOff 		 = patch_Audio_ADC_PowerOff,
	.SarADC_PowerOff 			 = Saradc_Uninit,
	.XTAL_PowerOff 				 = rom_XTAL_PowerOff,
	.High_Freq_OSC_PowerOff 	 = rom_High_Freq_OSC_PowerOff,
	.Dongle_PowerOff 			 = patch_Dongle_PowerOff,
	.Headset_PowerOff 			 = patch_Headset_PowerOff,
	.Headphone_PowerOff 		 = patch_Headphone_PowerOff,
	.TYPE_C_To_3P5_PowerOff 	 = patch_TYPE_C_To_3P5_PowerOff,
};

void new_power_off_patch_init(void)
{
	power_off_ftable = (ftable_t *)&new_power_off_fi_table;
}
