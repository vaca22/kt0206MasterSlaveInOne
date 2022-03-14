#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "suspend.h"
#include "user.h"
#include "earphone_insert_remove_detect.h"
#include "saradc.h"
#include "debug.h"

#ifndef JACK_PIN_ORDER_DEF
	#define JACK_PIN_ORDER_3POLE	0
	#define JACK_PIN_ORDER_CITA		1
	#define JACK_PIN_ORDER_OMTP		2
	#define JACK_PIN_ORDER_DEF		JACK_PIN_ORDER_CITA
#endif
typedef struct
{
	void (*HSS_Detect_Fun)(void);
}ftable_t;

ftable_t *hss_det_ftable;

extern void Charge_pump_PowerOn(void);

uint8_t jack_pin_order;
int16_t micin_key_thrh = 400;

void HSS_Detect_Fun(void)
{
	hss_det_ftable->HSS_Detect_Fun();
}

// void rom_HSS_Detect_Fun(void);
void patch_HSS_Detect_Fun(void)
{
#ifdef INSERT_DET_DELAY_TIMms
	if(timer_tick_ms_get() > 3000) //avoid power on too slow
	{
		timer_delay_length(INSERT_DET_DELAY_TIMms, TIM_MS);//delay xms to detect headset type
	}
#endif
	GLOBAL_INT_STOP();

	//insert charge pump power on
	Charge_pump_PowerOn();

	//micbias power on
	//setup micbias to target value
	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(7);
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFE);
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(0);
	apb_power_pd_ctrl0_micbias_pd_setf(0);
	apb_power_pd_ctrl0_micbias_en_setf(1);
	//E_jack_det_compl_clr
	apb_power_pd_ctrl3_e_jack_det_compl_clr_setf(1);
	apb_power_pd_ctrl3_e_jack_det_compl_clr_setf(0);

	apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(0);//default: 0 4pole
	apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(0);
#ifdef JACK_PIN_ORDER_FIXED
	#if (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_CITA)
			apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(0);  //sleeve as mic input
			jack_pin_order = 1;
			stEarphoneDetectPara.EarPhonePoleFlag = 0;
	#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_OMTP)
			apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1); //ring2 as mic input
			jack_pin_order = 2;
			stEarphoneDetectPara.EarPhonePoleFlag = 0;
	#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_3POLE)
			apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole
			stEarphoneDetectPara.EarPhonePoleFlag = 1;
	#endif
#else
	int16_t data1,data1a;
	int16_t data2,data2a;
	
	timer_delay_length(5, TIM_MS);
	data1 = Saradc_Convert(4, SARADC_SEL_MIC);
	timer_delay_length(5, TIM_MS);
	data1a = Saradc_Convert(4, SARADC_SEL_MIC);
	data1 = (data1+data1a) >> 1;///2;

	apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1);
	timer_delay_length(5, TIM_MS);
	data2 = Saradc_Convert(4, SARADC_SEL_MIC);
	timer_delay_length(5, TIM_MS);
	data2a = Saradc_Convert(4, SARADC_SEL_MIC);
	data2 = (data2+data2a) >> 1; ///2;

	if((data1+data2) < micin_key_thrh)  // use absolute value
	{
		apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole
		stEarphoneDetectPara.EarPhonePoleFlag = 1;
	}
	else if((__nds32__abs(data1-data2)<0x70) && data1 > 0x170 && data2 > 0x170)
	{
#if (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_CITA)
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(0);  //sleeve as mic input
		jack_pin_order = 1;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_OMTP)
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1); //ring2 as mic input
		jack_pin_order = 2;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_3POLE)
		apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole
		stEarphoneDetectPara.EarPhonePoleFlag = 1;
#endif
	}
	else if(data1 > data2)
	{
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(0);  //sleeve as mic input
		jack_pin_order = 1;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
	}
	else if(data1 < data2)   // OMTP compare relative value
	{
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1); //ring2 as mic input
		jack_pin_order = 2;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
	}
	else 				//default
	{
#if (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_CITA)
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(0);  //sleeve as mic input
		jack_pin_order = 1;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_OMTP)
		apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1); //ring2 as mic input
		jack_pin_order = 2;
		stEarphoneDetectPara.EarPhonePoleFlag = 0;
#elif (JACK_PIN_ORDER_DEF == JACK_PIN_ORDER_3POLE)
		apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole
		stEarphoneDetectPara.EarPhonePoleFlag = 1;
#endif
	}
#endif /*JACK_PIN_ORDER_FIXED*/
	//software headset switch detect disable
	apb_power_pd_ctrl0_micbias_en_setf(1);
	apb_power_pd_ctrl0_micbias_pd_setf(0);
	apb_audio_ctrl5_auldo__1p_2v_pd_setf(1);
	apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFE);
	apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(pOtpInRam->micbias_output_voltage_sel);

	GLOBAL_INT_START();
	DBG_OUT_INFO("data1 = %d, data1a = %d\n",data1 ,data1a);
	DBG_OUT_INFO("data2 = %d, data2a = %d\n",data2 ,data2a);
	DBG_OUT_INFO("jack_pin_order = %d (1:CITA,2:OMTP)\n", jack_pin_order);
	DBG_OUT_INFO("EarPhonePoleFlag = %d (0:4pole,1:3pole)\n", stEarphoneDetectPara.EarPhonePoleFlag);
	stEarphoneDetectPara.pEarphoneCompletHandler(stEarphoneDetectPara.EarPhonePoleFlag);
	stEarphoneDetectPara.EarPhoneDetectCompletFlag = 1;
}

const ftable_t new_hss_det_fi_table = 
{
	.HSS_Detect_Fun = patch_HSS_Detect_Fun,
};

void new_hss_det_patch_init(void)
{
	hss_det_ftable = (ftable_t *)&new_hss_det_fi_table;
}
