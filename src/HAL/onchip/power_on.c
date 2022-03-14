/*
 * power_on.c
 *
 *  Created on: May 8, 2018
 *      Author: chenbowen
 */

#include "power_on.h"
#include "earphone_key_detect.h"
#include "saradc.h"
#include "timer.h"
#include "bll_config.h"
#include "chip_config.h"
#include "debug.h"


typedef struct ftable_stru
{
	void (*Xtal_PowerOn)(void);
	void (*SarADC_PowerOn)(void);
	void (*ADC_RC_Cali_PowerOn)(void);
	void (*DAC_Current_Cali_PowerOn)(void);
	void (*Charge_pump_PowerOn)(void);
	void (*Audio_ADC_PowerOn)(void);
	void (*Audio_DAC_PowerOn)(void);
	void (*Itrim_Monitor)(void);
	void (*Dongle_PowerOn)(void);
	void (*Headset_PowerOn)(void);
	void (*Headphone_PowerOn)(void);
	void (*TYPE_C_To_3P5_PowerOn)(uint8_t ucMicbiasSel);
}ftable_t;

ftable_t *power_on_ftable;

const uint8_t ucAudacItrimCode[16] = {0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0,
									  0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
const uint8_t ucAudacLownItrimCode[16] = {0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0,
									 	   0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};

//for OTP, @CP cap=4.7uF, 0:1.5M, 1:3.1M, 2:375k, 3:750k, 4:25k, 5:50k, 6:100k, 7:185kHz
uint8_t ucHighRailCpClk = 7;	

//for OTP, @CP cap=4.7uF, 0:1.5M, 1:3.1M, 2:375k, 3:750k, 4:25k, 5:50k, 6:100k, 7:185kHz
uint8_t ucLowRailCpClk = 2;	
/*************************************************************************************************/
/*																								 */
/* 									Different module Power on 									 */
/*																								 */
/*************************************************************************************************/
void osc_cali_code_config(uint8_t ucOscCaliCode)
{
	// load Code of NVM into osc_cali_code_reg
	apb_osc_cali_ctrl1_osc_cali_code_reg_setf(ucOscCaliCode);
}

extern void High_Freq_OSC_PowerOn(uint8_t ucOscCaliCode);

void Xtal_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Xtal_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Xtal_PowerOn(void);

void SarADC_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->SarADC_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

// extern void rom_SarADC_PowerOn(void);
extern void Saradc_Init(void);


void ADC_RC_Cali_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->ADC_RC_Cali_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_ADC_RC_Cali_PowerOn(void);



extern uint8_t Saradc_Pdata_Out_Get(uint8_t ucAvgNum);

extern void Audac_Lown_Itrim_Code_Set(uint8_t ucValue);

extern uint8_t Audac_Lown_Itrim_Code_Get(void);

void pga_init(void)
{
	DBG_OUT_FUNC("entry\n");
	apb_audio_ctrl0_audac_r_anagain_setf(g_pstConfig->PerfCfg.PgaDACR);
	apb_audio_ctrl0_audac_l_anagain_setf(g_pstConfig->PerfCfg.PgaDACL);
	apb_power_pd_ctrl1_audio_pga_cfgregs_gain_setf(g_pstConfig->PerfCfg.PgaADC);
	DBG_OUT_FUNC("exit\n");
}

void DAC_Current_Cali_PowerOn(void)
{
	power_on_ftable->DAC_Current_Cali_PowerOn();
}

//extern void rom_DAC_Current_Cali_PowerOn(void);
void patch_DAC_Current_Cali_PowerOn(void)
{
	uint8_t ucLevel1 = 0;
	uint8_t ucLevel2 = 0;
//	uint8_t ucSaradcPdataOut0p5;
	uint8_t ucSaradcPdataOut0p55;
	uint16_t ParaA = 0x6AAB;
	uint16_t ParaB = 0x0000;
	uint32_t uTmpValue;

	DBG_OUT_FUNC("entry\n");
	ParaA = pOtpInRam->saradc_a;
	ParaB = (pOtpInRam->saradc_b) << 5;

	// /* set lower thread */
	// apb_audio_ctrl2_saradc_pdata_out__0p_45_setf(g_saradc_pdata_out_0p45);
	// /* set higher thread */
	// apb_audio_ctrl2_saradc_pdata_out__0p_55_setf(g_saradc_pdata_out_0p55);
	/* set num from otp */
	apb_audio_ctrl0_saradc_pdata_avg_num_setf(pOtpInRam->saradc_pdata_avg_num);
	/* set flag to 0 select software to cali */
	apb_audio_ctrl0_audac_itrim_flag_setf(0);
	/* audac_itrim calibration flow */
	apb_aux_adc_ctrl0_saradc_sel_reg_setf(0x9);
	apb_audio_ctrl0_audac_itrim_en_setf(0x1);
	uTmpValue = apb_spare_reg0_get();
	uTmpValue &= 0xFF7FFFFF;
	apb_spare_reg0_set(uTmpValue);
	apb_audio_ctrl0_audac_itrim_setf(ucAudacItrimCode[ucLevel1]);
//	ucSaradcPdataOut0p5 = (uint16_t)((ParaA * 0.5) + ParaB) >> 7;
	ucSaradcPdataOut0p55 = (uint16_t)((ParaA * 0.55) + ParaB) >> 7;
	apb_spare_reg2_set(g_pstConfig->PerfCfg.THDCfg);
	while(1)
	{
		timer_delay_length(10, TIM_US);
		uTmpValue = Saradc_Pdata_Out_Get(pOtpInRam->saradc_pdata_avg_num);
		// uTmpValue = Saradc_Convert(pOtpInRam->saradc_pdata_avg_num, SARADC_SEL_AUDAC_ITRIM_VOUT);
		// uTmpValue >>= 2;
//		if(uTmpValue >= ucSaradcPdataOut0p5)
		if(uTmpValue >= ucSaradcPdataOut0p55)
		{
			if(apb_audio_ctrl0_audac_itrim_getf() != ucAudacItrimCode[0])
			{
				ucLevel1--;
				apb_audio_ctrl0_audac_itrim_setf(ucAudacItrimCode[ucLevel1]);
			}
			break;
		}
		else if(apb_audio_ctrl0_audac_itrim_getf() == ucAudacItrimCode[15])
		{
			break;
		}
		else
		{
			ucLevel1++;
			apb_audio_ctrl0_audac_itrim_setf(ucAudacItrimCode[ucLevel1]);
		}
	}

	/* audac_lown_itrim calibration flow */
	apb_aux_adc_ctrl0_saradc_sel_reg_setf(0x9);
	apb_audio_ctrl0_audac_itrim_en_setf(0x1);
	uTmpValue = apb_spare_reg0_get();
	uTmpValue |= 0x1<<23;
	apb_spare_reg0_set(uTmpValue);
	Audac_Lown_Itrim_Code_Set(ucAudacLownItrimCode[ucLevel2]);
//	ucSaradcPdataOut0p5 = (uint16_t)((ParaA * 0.5) + ParaB) >> 7;
	ucSaradcPdataOut0p55 = (uint16_t)((ParaA * 0.55) + ParaB) >> 7;

	while(1)
	{
		timer_delay_length(10, TIM_US);
		uTmpValue = Saradc_Pdata_Out_Get(pOtpInRam->saradc_pdata_avg_num);
		// uTmpValue = Saradc_Convert(pOtpInRam->saradc_pdata_avg_num, SARADC_SEL_AUDAC_ITRIM_VOUT);
		// uTmpValue >>= 2;
//		if(uTmpValue >= ucSaradcPdataOut0p5)
		if(uTmpValue >= ucSaradcPdataOut0p55)
		{
			if(Audac_Lown_Itrim_Code_Get() != ucAudacLownItrimCode[0])
			{
				ucLevel2--;
				Audac_Lown_Itrim_Code_Set(ucAudacLownItrimCode[ucLevel2]);
			}
			break;
		}
		else if(Audac_Lown_Itrim_Code_Get() == ucAudacLownItrimCode[15])
		{
			break;
		}
		else
		{
			ucLevel2++;
			Audac_Lown_Itrim_Code_Set(ucAudacLownItrimCode[ucLevel2]);
		}
	}
	DBG_OUT_FUNC("exit\n");
}


void Charge_pump_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Charge_pump_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Charge_pump_PowerOn(void);

void Audio_ADC_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Audio_ADC_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Audio_ADC_PowerOn(void);

void patch_Audio_ADC_PowerOn(void)
{
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFE);
	Delay_Ms(1);

	apb_audio_ctrl5_auldo__1p_2v_pd_setf(0);
	apb_audio_pd_rst_audac_bias_pd_setf(0);
#if MICBIAS_POWER_ON_EN
	apb_power_pd_ctrl0_micbias_pd_setf(0);
	apb_power_pd_ctrl0_micbias_en_setf(1);
#else
	apb_power_pd_ctrl0_micbias_pd_setf(1);
	apb_power_pd_ctrl0_micbias_en_setf(0);
#endif
	Delay_Ms(1);

	/*Audio ADC RC cali*/
	ADC_RC_Cali_PowerOn();

	/*Audio DAC Current cali*/
	DAC_Current_Cali_PowerOn();

	apb_power_pd_ctrl1_audio_pga_pd_setf(0);
	apb_audio_pd_rst_auadc__1_pd_setf(0);
	apb_audio_pd_rst_auadc_vcm_pd_setf(0);
	Delay_Us(10);
	apb_audio_pd_rst_auadc_vcmo_rst_setf(0);
	Delay_Us(10);
	apb_audio_pd_rst_auadc_rst_setf(0);
}

void Audio_DAC_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Audio_DAC_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

//extern void rom_Audio_DAC_PowerOn(void);
void patch_Audio_DAC_PowerOn(void)
{
	uint32_t uTmpValue;
	// timer_delay_length(10, TIM_MS);		//for POP sound canceling
	/* Audio_vref_pd(spare_reg3<0>)=1->0 */
	uTmpValue = apb_spare_reg3_get();
	uTmpValue &= 0xFFFFFFFE;

	DBG_OUT_FUNC("entry\n");
	apb_spare_reg3_set(uTmpValue);
	/* Delay 1ms for vref1p8v stable */
	timer_delay_length(1, TIM_MS);
	/* Audac_bias_pd=1->0 */
	apb_audio_pd_rst_audac_bias_pd_setf(0);
	/* Auldo_1p2v_pd=1->0 */
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(0);
	/* Delay 1ms for audio LDO output stable */
	timer_delay_length(1, TIM_MS);
	timer_delay_length(25, TIM_MS);		//for POP sound canceling
	/* Audio DAC Current cali */
	DAC_Current_Cali_PowerOn();
	/* Audac_l_pd=1->0 */
	apb_audio_pd_rst_audac_l_pd_setf(0);
	/* Audac_r_pd=1->0 */
	apb_audio_pd_rst_audac_r_pd_setf(0);

	/* Charge pump power up sequence */
	Charge_pump_PowerOn();
	// timer_delay_length(100, TIM_US);
	/* Audac_l_aui2v_pd=1->0 */
	apb_audio_pd_rst_audac_l_aui_2v_pd_setf(0);
	/* Audac_r_aui2v_pd=1->0 */
	apb_audio_pd_rst_audac_r_aui_2v_pd_setf(0);
	/* Delay 100us for DAC output vcm stable */

	/* cg_driver_s1(spare_reg0<21>)=0->1 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue |= 0x1<<21;
	apb_spare_reg0_set(uTmpValue);

//	/*cgldo = 1.98V */
//	uTmpValue = apb_spare_reg0_get();
//	uTmpValue |= 0x03<<28;
//	apb_spare_reg0_set(uTmpValue);

	/* cg_pdl=1->0 */
	apb_power_pd_ctrl1_cg_pdl_setf(0);
	/* cg_pdr=1->0 */
	apb_power_pd_ctrl1_cg_pdr_setf(0);
	/* Delay 500us for classg driver stable */
	timer_delay_length(500, TIM_US);
	/* cg_driver_s3(spare_reg0<19:16>)from 0 to 11, step 1, interval 500us */
	uint8_t ucStep;
	for(ucStep=0; ucStep<12; ucStep++)
	{
		uTmpValue = apb_spare_reg0_get();
		uTmpValue &= 0xFFF0FFFF;
		uTmpValue |= ucStep<<16;
		apb_spare_reg0_set(uTmpValue);
		timer_delay_length(500, TIM_US);
	}
	/* Delay 500us for s3 stable */
	timer_delay_length(500, TIM_US);
	/* cg_driver_s2(spare_reg0<20>)=0->1 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue |= 0x1<<20;
	apb_spare_reg0_set(uTmpValue);
	/* Delay 200us for classg driver stable */
	timer_delay_length(200, TIM_US);
	/* cg_driver_s1(spare_reg0<21>)=1->0 */
	uTmpValue = apb_spare_reg0_get();
	uTmpValue &= 0xFFDFFFFF;
	apb_spare_reg0_set(uTmpValue);
	DBG_OUT_FUNC("exit\n");
}

void Itrim_Monitor(void)
{
	power_on_ftable->Itrim_Monitor();
}

//extern void rom_Itrim_Monitor(void);
void patch_Itrim_Monitor(void)
{
	int i;
	uint8_t ucLevel1 = 0, ucLevel2 = 0;
	uint8_t ucSaradcPdataOut0p45;
	uint8_t ucSaradcPdataOut0p55;
	uint16_t ParaA = 0x6AAB;
	uint16_t ParaB = 0x0000;
	uint32_t uTmpValue;

	//DBG_OUT_FUNC("\n");
	ParaA = pOtpInRam->saradc_a;
	ParaB = (pOtpInRam->saradc_b) << 5;

	if((pOtpInRam->itrim_monitor_en) && (g_stStartFlag.OutStartFlag == 1))
	{
		if(((apb_spare_reg0_get()>>22) & 0x1) == 0x0)
		{
			uTmpValue = apb_spare_reg0_get();
			uTmpValue &= 0xFF7FFFFF;
			apb_spare_reg0_set(uTmpValue);
			apb_aux_adc_ctrl0_saradc_sel_reg_setf(0x9);
			apb_audio_ctrl0_audac_itrim_en_setf(0x1);
			ucSaradcPdataOut0p45 = (uint16_t)((ParaA * 0.45) + ParaB) >> 7;
			ucSaradcPdataOut0p55 = (uint16_t)((ParaA * 0.55) + ParaB) >> 7;

			uTmpValue = apb_audio_ctrl0_audac_itrim_getf();
			for(i=0; i<16; i++)
			{
				if(uTmpValue == ucAudacItrimCode[i])
				{
					ucLevel1 = i;
					break;
				}
			}

			while(1)
			{
				timer_delay_length(10, TIM_US);
				uTmpValue = Saradc_Pdata_Out_Get(pOtpInRam->saradc_pdata_avg_num);
				// uTmpValue = Saradc_Convert(pOtpInRam->saradc_pdata_avg_num, SARADC_SEL_AUDAC_ITRIM_VOUT);
				// uTmpValue >>= 2;
				if(uTmpValue >= ucSaradcPdataOut0p55)
				{
					if(apb_audio_ctrl0_audac_itrim_getf() == ucAudacItrimCode[0])
					{
						break;
					}
					else
					{
						apb_audio_ctrl0_audac_itrim_setf(ucAudacItrimCode[--ucLevel1]);
					}
				}
				else if(uTmpValue <= ucSaradcPdataOut0p45)
				{
					if(apb_audio_ctrl0_audac_itrim_getf() == ucAudacItrimCode[15])
					{
						break;
					}
					else
					{
						apb_audio_ctrl0_audac_itrim_setf(ucAudacItrimCode[++ucLevel1]);
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			uTmpValue = apb_spare_reg0_get();
			uTmpValue |= 0x1<<23;
			apb_spare_reg0_set(uTmpValue);
			apb_aux_adc_ctrl0_saradc_sel_reg_setf(0x9);
			apb_audio_ctrl0_audac_itrim_en_setf(0x1);
			ucSaradcPdataOut0p45 = (uint16_t)((ParaA * 0.45) + ParaB) >> 7;
			ucSaradcPdataOut0p55 = (uint16_t)((ParaA * 0.55) + ParaB) >> 7;

			uTmpValue = Audac_Lown_Itrim_Code_Get();
			for(i=0; i<16; i++)
			{
				if(uTmpValue == ucAudacLownItrimCode[i])
				{
					ucLevel2 = i;
					break;
				}
			}

			while(1)
			{
				timer_delay_length(10, TIM_US);
				uTmpValue = Saradc_Pdata_Out_Get(pOtpInRam->saradc_pdata_avg_num);
				// uTmpValue = Saradc_Convert(pOtpInRam->saradc_pdata_avg_num, SARADC_SEL_AUDAC_ITRIM_VOUT);
				// uTmpValue >>= 2;
				if(uTmpValue >= ucSaradcPdataOut0p55)
				{
					if(Audac_Lown_Itrim_Code_Get() == ucAudacLownItrimCode[0])
					{
						break;
					}
					else
					{
						Audac_Lown_Itrim_Code_Set(ucAudacLownItrimCode[--ucLevel2]);
					}
				}
				else if(uTmpValue <= ucSaradcPdataOut0p45)
				{
					if(Audac_Lown_Itrim_Code_Get() == ucAudacLownItrimCode[15])
					{
						break;
					}
					else
					{
						Audac_Lown_Itrim_Code_Set(ucAudacLownItrimCode[++ucLevel2]);
					}
				}
				else
				{
					break;
				}
			}
		}
	}
}

/*************************************************************************************************/
/*																								 */
/* 									Different mode Power on 									 */
/*																								 */
/*************************************************************************************************/
void Dongle_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Dongle_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Dongle_PowerOn(void);

void Headset_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Headset_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Headset_PowerOn(void);

void Headphone_PowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->Headphone_PowerOn();
	DBG_OUT_FUNC("exit\n");
}

extern void rom_Headphone_PowerOn(void);

void TYPE_C_To_3P5_PowerOn(uint8_t ucMicbiasSel)
{
	DBG_OUT_FUNC("entry\n");
	power_on_ftable->TYPE_C_To_3P5_PowerOn(ucMicbiasSel);
	DBG_OUT_FUNC("exit\n");
}

extern void rom_TYPE_C_To_3P5_PowerOn(uint8_t ucMicbiasSel);

void chipPowerOn(void)
{
	DBG_OUT_FUNC("entry\n");
    // High Freq OSC
	// High_Freq_OSC_PowerOn(stPowerOnPara);
	// Standby Digital LDO Calibration pd
	apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(0);
	// Xtal
	Xtal_PowerOn();

	// SarADC
	SarADC_PowerOn();

    #ifdef JACK_SENSE_FUNC
    apb_audio_pd_rst_audio_det_pd_setf(1);
	apb_key_ctrl0_micin_det_pd_setf(0);

	apb_pwm_ctrl2_usb_suspendm_mask_setf(0);
	apb_key_ctrl0_micin_int_mask_setf(0);
	apb_key_ctrl0_micin_mask_setf(0);

	// setup micbias to target value
	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(pOtpInRam->micbias_output_voltage_sel);
    #else 
        #ifdef MIC_KEY_SUPPORT
        // setup micbias to target value
        apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(pOtpInRam->micbias_output_voltage_sel);
        //micbias power on
        apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFE);
        apb_audio_ctrl5_auldo__1p_2v_pd_setf(0);
        apb_power_pd_ctrl0_micbias_pd_setf(0);
        apb_power_pd_ctrl0_micbias_en_setf(1);

        apb_pwm_ctrl2_usb_suspendm_mask_setf(0);
        apb_key_ctrl0_hss_mask_setf(0);

        apb_key_ctrl0_micin_int_mask_setf(0);
        apb_key_ctrl0_micin_mask_setf(0);
        #else
        apb_key_ctrl0_micin_det_pd_setf(1);
        apb_pwm_ctrl2_usb_suspendm_mask_setf(0);
        apb_key_ctrl0_micin_int_mask_setf(1);
        apb_key_ctrl0_micin_mask_setf(1);
        #endif
    #endif
	DBG_OUT_FUNC("exit\n");
}

const ftable_t patch_power_on_fi_table =
{
	.Xtal_PowerOn 				= rom_Xtal_PowerOn,
	.SarADC_PowerOn 			= Saradc_Init,
	.ADC_RC_Cali_PowerOn 		= rom_ADC_RC_Cali_PowerOn,
	.DAC_Current_Cali_PowerOn 	= patch_DAC_Current_Cali_PowerOn,
	.Charge_pump_PowerOn 		= rom_Charge_pump_PowerOn,
	.Audio_ADC_PowerOn 			= patch_Audio_ADC_PowerOn,
	.Audio_DAC_PowerOn 			= patch_Audio_DAC_PowerOn,
	.Itrim_Monitor 				= patch_Itrim_Monitor,
	.Dongle_PowerOn 			= rom_Dongle_PowerOn,
	.Headset_PowerOn 			= rom_Headset_PowerOn,
	.Headphone_PowerOn 			= rom_Headphone_PowerOn,
	.TYPE_C_To_3P5_PowerOn 		= rom_TYPE_C_To_3P5_PowerOn,
};

void new_power_on_patch_init(void)
{
	power_on_ftable = (ftable_t *)&patch_power_on_fi_table;
}
