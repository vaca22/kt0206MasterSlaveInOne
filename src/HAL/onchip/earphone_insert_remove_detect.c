/*
 * earphone_insert_remove_detect.c
 *
 */

#include "reg_apb.h"
#include "intc.h"
#include "audio_in.h"
#include "audio_out.h"
#include "earphone_insert_remove_detect.h"
#include "usb_app.h"
#include "gpio_ctrl.h"
#include "soft_timer.h"
#include "hal_config.h"
#include "debug.h"

typedef struct
{
	void (*h_Earphone_Insert_Branch_Isr)(void);
	void (*h_Earphone_Complet_Branch_Isr)(void);
	void (*h_Earphone_Remove_Branch_Isr)(void);
	void (*h_Earphone_Detect_Isr)(uint32_t uID);
	void (*h_Earphone_Detect_SetCallBack)(uint8_t Index, uint32_t FuncHandle);
	void (*h_Earphone_Detect_Init)(void);
}ftable_t;

#ifdef JACK_SENSE_FUNC

extern uint8_t no_jack_insert_flag;

volatile uint8_t jack_insert_complet = 0;
volatile uint8_t jack_ins_bygpio_sts=0;
volatile uint8_t jack_ins_bygpio_proc = 0;
volatile uint8_t g_u8DebTimeSet = 0;

ftable_t *pEarphoneIRFTable;

earphone_detect_para_t stEarphoneDetectPara;
earphone_insert_remove_by_gpio_t stEarphoneInsRmvByGpio;

void new_Patch_Earphone_Insert_Branch_Isr(void)
{
	jack_insert_complet = 1;

	apb_power_pd_ctrl3_e_jack_insertion_clr_setf(1); 
	apb_power_pd_ctrl3_e_jack_insertion_clr_setf(0);
}

extern void Patch_Earphone_Complet_Branch_Isr(void);
// void Patch_Earphone_Complet_Branch_Isr(void)
// {
// 	apb_power_pd_ctrl3_e_jack_det_compl_clr_setf(1);
// 	apb_power_pd_ctrl3_e_jack_det_compl_clr_setf(0);
// }

void new_Patch_Earphone_Remove_Branch_Isr(void)
{
	apb_power_pd_ctrl3_e_jack_removal_clr_setf(1);
	apb_power_pd_ctrl3_e_jack_removal_clr_setf(0);

	jack_insert_complet = 0;

	stEarphoneDetectPara.EarPhonePoleFlag = 0;
	stEarphoneDetectPara.EarPhoneDetectCompletFlag = 0;
	//power down micbias
	apb_power_pd_ctrl0_micbias_pd_setf(1);			/* temp */
	apb_power_pd_ctrl0_micbias_en_setf(0);			/* temp */
}

extern void Patch_Earphone_Insert_Branch_Isr(void);
extern void Earphone_Detect_Isr(uint32_t uID);
extern void Patch_Earphone_Detect_Isr(uint32_t uID);
extern void Patch_Earphone_Detect_SetCallBack(uint8_t Index, uint32_t FuncHandle);

void new_Patch_Earphone_Detect_Init(void)
{
	DBG_OUT_FUNC("entry\n");
	//reset hss fsm
	apb_clk_gen_clken_clk_hss_ctrl_en_setf(0);
	apb_rst_gen_ctrl0_hss_ctrl_rst_setf(1);
	timer_delay_length(10, TIM_US);
	apb_rst_gen_ctrl0_hss_ctrl_rst_setf(0);
	timer_delay_length(10, TIM_US);

	//debounce config

	//IRQ MASK config
	stEarphoneDetectPara.EarPhonePoleFlag = 0;
	stEarphoneDetectPara.EarPhoneDetectCompletFlag = 0;

	/*Enable jacksns detect but disable hss fsm work*/

	intc_enable_set(INTC_ID_HEADSET_SWITCH, Earphone_Detect_Isr);
	//hp_det_en
	apb_power_pd_ctrl3_hp_det_en_setf(0);
	//jack_type_en
	apb_power_pd_ctrl3_jack_type_en_setf(0);
	//hss fsm work
	apb_power_pd_ctrl2_hss_ctrl_flag_setf(0); //1: hardware ; 0: software
	apb_spare_reg3_set(0); //spare_reg3 bit0 = 0
	apb_clk_gen_clken_clk_hss_ctrl_en_setf(1);
}

void Jack_Insert_Branch_ByGpio_Isr(void)
{
	jack_insert_complet = 1;
#if EarphoneInsert_GPIOlevel
	/*gpio key polarity config:set as low level trigger*/
	apb_key_ctrl0_gpio_key_pol_setf(0);
#else
	/*gpio key polarity config:set as high level trigger*/
	apb_key_ctrl0_gpio_key_pol_setf(1);
#endif
	jack_ins_bygpio_sts = 1;
}

void Jack_Remove_Branch_ByGpio_Isr(void)
{
	jack_insert_complet = 0;
	stEarphoneDetectPara.EarPhonePoleFlag = 0;
	stEarphoneDetectPara.EarPhoneDetectCompletFlag = 0;
#if EarphoneInsert_GPIOlevel
	/*gpio key polarity config: set as high level trigger*/
	apb_key_ctrl0_gpio_key_pol_setf(1);
#else
	/*gpio key polarity config: set as low level trigger*/
	apb_key_ctrl0_gpio_key_pol_setf(0);
#endif
	jack_ins_bygpio_sts = 0;
}

void Jack_InsRmvDet_ByGpio_Handle(void)
{
	stEarphoneInsRmvByGpio.u8GpioValue_new = GPIO_InputGet(GPIO3);

	if(stEarphoneInsRmvByGpio.u8GpioValue_old == stEarphoneInsRmvByGpio.u8GpioValue_new){
		if(1 == stEarphoneInsRmvByGpio.u8GpioValue_new){
			stEarphoneInsRmvByGpio.u8GpioValue1Cnt++;
		}else{
			stEarphoneInsRmvByGpio.u8GpioValue0Cnt++;
		}
	}else{
		if(1 == stEarphoneInsRmvByGpio.u8GpioValue_new){
			stEarphoneInsRmvByGpio.u8GpioValue0Cnt = 0;
		}else{
			stEarphoneInsRmvByGpio.u8GpioValue1Cnt = 0;
		}
	}

	stEarphoneInsRmvByGpio.u8GpioValue_old = stEarphoneInsRmvByGpio.u8GpioValue_new;

	if(g_u8DebTimeSet == stEarphoneInsRmvByGpio.u8GpioValue1Cnt){
		jack_ins_bygpio_proc = 0;
		stEarphoneInsRmvByGpio.u8GpioValue1Cnt = 0;
		softtimer_stop(SOFT_TIMER1);
#if EarphoneInsert_GPIOlevel
		Jack_Insert_Branch_ByGpio_Isr();
#endif
	}else if(g_u8DebTimeSet == stEarphoneInsRmvByGpio.u8GpioValue0Cnt){
		jack_ins_bygpio_proc = 0;
		stEarphoneInsRmvByGpio.u8GpioValue0Cnt = 0;
		softtimer_stop(SOFT_TIMER1);
#if EarphoneInsert_GPIOlevel == 0
		Jack_Insert_Branch_ByGpio_Isr();
#endif
	}
}

void Jack_InsRmvDet_ByGpio_Isr()
{
	apb_key_ctrl0_gpio_key_int_clr_setf(1);
	apb_key_ctrl0_gpio_key_int_clr_setf(0);

	if(0 == jack_ins_bygpio_sts)
	{
		jack_ins_bygpio_proc = 1;
		stEarphoneInsRmvByGpio.u8GpioValue_old = GPIO_InputGet(GPIO3);
		/*-- start timer to detect earphone insert status --*/
		softtimer_start(SOFT_TIMER1, MS_TO_SOFT_TIMER(50), Jack_InsRmvDet_ByGpio_Handle);
	}
	else
	{
		jack_ins_bygpio_proc = 0;
		Jack_Remove_Branch_ByGpio_Isr();
	}
}

void Jack_InsRmvDet_ByGpio_Init(void)
{
	//insert removal status init
	stEarphoneDetectPara.EarPhonePoleFlag = 0;
	stEarphoneDetectPara.EarPhoneDetectCompletFlag = 0;
	stEarphoneInsRmvByGpio.u8GpioValue_old = 0;
	stEarphoneInsRmvByGpio.u8GpioValue_new = 0;
	stEarphoneInsRmvByGpio.u8GpioValue0Cnt = 0;
	stEarphoneInsRmvByGpio.u8GpioValue1Cnt = 0;
	jack_ins_bygpio_proc = 0;
	g_u8DebTimeSet = 5;

	apb_key_ctrl0_gpio_key_det_rst_setf(0);
#if EarphoneInsert_GPIOlevel == 0
	/*GPIO3 Function Set*/
	GPIO_FuncSet(GPIO3, GPIO_DigInput);

	/*gpio key polarity config*/
	apb_key_ctrl0_gpio_key_pol_setf(0);		//0: low level, 1: high level
#else
	/*GPIO3 Function Set*/
	GPIO_FuncSet(GPIO3, GPIO_DigInput);

	/*gpio key polarity config*/
	apb_key_ctrl0_gpio_key_pol_setf(1);		//0: low level, 1: high level
#endif
	/*debounce config*/
	apb_key_ctrl0_gpio_key_deb_setf(pOtpInRam->GpioKeyDebounceSel);		//0: 10ms  1:20ms 2:40ms  3:80ms

	/*gpio key int mask set, use gpio3 key interrupt*/
	apb_key_ctrl0_gpio_key_int_mask_setf((uint8_t)~BIT2);

	/*Enable GPIO input interrupt*/
	intc_enable_set(INTC_ID_GPIO_KEY, Jack_InsRmvDet_ByGpio_Isr);
	
	/*gpio clk gpio key det enable*/
	apb_key_ctrl0_clk_gpio_key_det_en_setf(1);
}

const ftable_t patch_EarPhoneIRFuncTableDef = 
{
	.h_Earphone_Insert_Branch_Isr  = new_Patch_Earphone_Insert_Branch_Isr,
	.h_Earphone_Complet_Branch_Isr = Patch_Earphone_Complet_Branch_Isr,
	.h_Earphone_Remove_Branch_Isr  = new_Patch_Earphone_Remove_Branch_Isr,
	.h_Earphone_Detect_Isr 		   = Patch_Earphone_Detect_Isr,
	.h_Earphone_Detect_SetCallBack = Patch_Earphone_Detect_SetCallBack,
	.h_Earphone_Detect_Init        = new_Patch_Earphone_Detect_Init,
};

void new_EarphoneIRDet_patch_init(void)
{
    pEarphoneIRFTable = (ftable_t *)&patch_EarPhoneIRFuncTableDef;
}

#endif
