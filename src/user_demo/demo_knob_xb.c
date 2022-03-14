/**
 * microphone knob, speaker knob and mic key mute demo.
 * 
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include "uart.h"
#include "userTimer.h"
#include "gpio_ctrl.h"
#include "wav.h"
#include "saradc.h"
#include "volume.h"
#include "bll_config.h"
#include "chipEftCfg.h"
#include "reg_eft.h"
#include "user_key.h"

/* define --------------------------------------------------------------------*/
/*
LED1: light on when mute mic， else light off.
*/
#define LED1_PORT 	GPIO6
#define LED1_OFF 	GPIO_FuncSet(LED1_PORT, GPIO_DigOutput1)
#define LED1_ON 	GPIO_FuncSet(LED1_PORT, GPIO_DigOutput0)
#define LED1_TOGGLE 	do{	static uint8_t flag = 0;\
							flag ? LED1_ON : LED1_OFF;\
							flag = !flag;}while(0)
#define LED_INIT  	do{LED1_ON;}while(0)

/* typedef -------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
extern uint8_t standby_enable;
extern volatile uint8_t AuInStartFlg;//USB MIC 1:enable/0:disable

/* function prototypes -------------------------------------------------------*/

/* functions -----------------------------------------------------------------*/
#if 1//def USER_KEY_SUPPORT
//to do your key funciton
#define KEY_DBG_OUT(...) 	//printf(__VA_ARGS__)
void keyFunction(keyInfo_s *pKeyInfo)
{
	USER_DBG_OUT("key%d: %d\n", pKeyInfo->keyIndex, pKeyInfo->keyEvent);
	if(pKeyInfo->keyIndex == 1)
	{
		switch (pKeyInfo->keyEvent)
		{
			case KEY_S_PRES:
				KEY_DBG_OUT("KEY_S_PRES\n");
				if(g_mute_bit & BIT_MIC)//update g_mute_bit and led
				{
					g_mute_bit &= ~BIT_MIC; //unmute
					LED1_OFF;
				}else{
					g_mute_bit |= BIT_MIC;
					LED1_ON;
				}	
			break;
			// case KEY_S_REL:			KEY_DBG_OUT("KEY_S_REL\n");			break;
			// case KEY_L_PRES:			KEY_DBG_OUT("KEY_L_PRES\n");		break;
			// case KEY_L_PRESSING:		KEY_DBG_OUT("KEY_L_PRESSING\n");	break;
			// case KEY_L_REL:			KEY_DBG_OUT("KEY_L_REL\n");			break;
			default:break;
		}
	}
	// else if(pKeyInfo->keyIndex == 2){
	// }
}
#endif

#if 1/*******************************knob************************************/
/* define --------------------------------------------------------------------*/
#define ADC_SCAN_TIME 			(50U)
#define MIC_VOL_KNOB_VAL		Saradc_Convert(2, SARADC_SEL_GPIO1)
#define SPK_VOL_KNOB_VAL		Saradc_Convert(2, SARADC_SEL_GPIO2)
#define MIC_VOL_KNOB_INIT		GPIO_FuncSet(GPIO1, GPIO_AuxADC)
#define SPK_VOL_KNOB_INIT		GPIO_FuncSet(GPIO2, GPIO_AuxADC)

//get max volume of the config
#define ADC_GAIN_DIGIT_dB		((int8_t)6)	//-40dB ~ +24dB, must corresponding to ADC_GAIN_DIGIT_SEL
#define DAC_GAIN_DIGIT_dB		((int8_t)0)	//-40dB ~ +24dB, must corresponding to DACL_GAIN_DIGIT_SEL and DACL_GAIN_DIGIT_SEL

//get max volume of the config, index of 80 coressponding to 0dB
#define ADC_VOL_MAX_IDX 	(uint8_t)(80 + (ADC_GAIN_DIGIT_dB * 2)) 
#define DAC_VOL_MAX_IDX 	(uint8_t)(80 + (DAC_GAIN_DIGIT_dB * 2))

/* typedef -------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
//[log10(i) / log(63)],i = [0~63]
const float logCoefTab[64]={\
 0.000, 0.000, 0.167, 0.265, 0.335, 0.388, 0.432, 0.470, 0.502, 0.530, 0.556, 0.579, 0.600, 0.619, 0.637, 0.654, 0.669, 0.684, 0.698, 0.711,\
 0.723, 0.735, 0.746, 0.757, 0.767, 0.777, 0.786, 0.795, 0.804, 0.813, 0.821, 0.829, 0.837, 0.844, 0.851, 0.858, 0.865, 0.872, 0.878, 0.884,\
 0.890, 0.896, 0.902, 0.908, 0.913, 0.919, 0.924, 0.929, 0.934, 0.939, 0.944, 0.949, 0.954, 0.958, 0.963, 0.967, 0.972, 0.976, 0.980, 0.984,\
 0.988, 0.992, 0.996, 1.000};//*/

/* function prototypes -------------------------------------------------------*/
void auxAdcKnobInit(void);
void micVolKnobScan(void);
void spkVolKnobScan(void);

/* functions -----------------------------------------------------------------*/
void auxAdcKnobInit(void)
{
	MIC_VOL_KNOB_INIT;
	SPK_VOL_KNOB_INIT;
	standby_enable = 0;
}

/**
  * @brief  update ADC digital gain according to sarADC sample value
  * @param  void: void
  * @note   
  * @retval None
  */
void micVolKnobScan(void)
{

	int16_t adcVal = MIC_VOL_KNOB_VAL; // 0 ~ 1023
	static int16_t adcValPrev = 512; //assign a large enough number,avoid invalid at power on when knob in min position. 
	
	if (abs(adcVal - adcValPrev) > 16)
	{
		adcValPrev = adcVal;
		// uint8_t volIndex = (uint8_t)((ADC_VOL_MAX_IDX * adcVal) >> 10);//volMax*[0~1023]/1024  
		uint8_t volIndex = (uint8_t)(ADC_VOL_MAX_IDX * logCoefTab[adcVal >> 4]);	//>>4 for sarADC is 10bit.
		if(volIndex < 2) //force mute
		{
			volIndex = 0;
		}
		g_pstConfig->DSPRegAll.bs.ADCDigGain.ADCGain = volume_table[volIndex];// 0.5dB step
		ChipEftReg_update(g_st_pHeadsetEft,&(g_pstConfig->DSPRegAll),DSPREG_IDX(ADCDigGain), AUDIO_SAMPLE_BLOCK_SIZE);
	}
}

/**
  * @brief  update DAC digital gain according to sarADC sample value
  * @param  void: void
  * @note   
  * @retval None
  */
void spkVolKnobScan(void)
{
	int16_t adcVal = SPK_VOL_KNOB_VAL; // 0 ~ 1023
	static int16_t adcValPrev = 512; //assign a large enough number,avoid invalid at power on when knob in min position. 
	
	if (abs(adcVal - adcValPrev) > 16)
	{
		adcValPrev = adcVal;
		// uint8_t volIndex = (uint8_t)((DAC_VOL_MAX_IDX * adcVal) >> 10);
		uint8_t volIndex = (uint8_t)(DAC_VOL_MAX_IDX * (adcVal >> 4) / 63);	//>>4 for sarADC is 10bit.
		if(volIndex < 2)  //force mute
		{
			volIndex = 0;
		}
		g_pstConfig->DSPRegAll.bs.DACDigGain.DACLGain = volume_table[volIndex];
		g_pstConfig->DSPRegAll.bs.DACDigGain.DACRGain = g_pstConfig->DSPRegAll.bs.DACDigGain.DACLGain;
		ChipEftReg_update(g_st_pHeadsetEft,&(g_pstConfig->DSPRegAll),DSPREG_IDX(DACDigGain), AUDIO_SAMPLE_BLOCK_SIZE);
	}
}
#endif/*******************************knob************************************/

//轮询用户操作的任务，并做响应
void userActionPollTask(void)
{
	userKeyScan();
	micVolKnobScan();
	dacVolKnobScan();
}

void displayTime(void)
{
	USER_DBG_OUT("time: %ld ms\n", timer_tick_ms_get());
}

/********************************************
 * GPIO1,GPIO2挂了滑动变阻器，用来调节音量
 * GPIO3,GPIO4为UART功能
*******************************************/
void GPIOInit(void)
{
	uint8_t i;
	for(i=0;i<7;i++)
	{
		pad_sw_bak.all32[i]=0x11111111;
	}
	GPIO_FuncSet(GPIO3,GPIO_Func1);//uart rx
	GPIO_FuncSet(GPIO4,GPIO_Func1);//uart tx
	
	LED_INIT;
}

//用户部分初始化函数放在这里面
void _user_delay_init(void)
{
	
}

void _user_schedule(void)
{
	UserTimerProcess();
}

void _user_init(void)
{
	GPIOInit();
	uartInit(115200);//串口初始化
	USER_DBG_OUT("\n\n\n KTMicro USB Audio!");
	userTimerInit();//1ms tick定时器初始化,使用的是内部的timer0
	addUserTimerEvent(displayTime, 5000, timerPeriod);//设置5s打印一次时间
	addUserTimerEvent(_user_delay_init, 2000, timerOnce);//
#if 1//def USER_KEY_SUPPORT
	userKeyInit(keyFunction); //regist key function
	auxAdcKnobInit();
	// addUserTimerEvent(userKeyScan, KEY_SCAN_TIME, timerPeriod);//
#endif
	addUserTimerEvent(userActionPollTask, 50, timerPeriod);// set poll time 50ms
}

