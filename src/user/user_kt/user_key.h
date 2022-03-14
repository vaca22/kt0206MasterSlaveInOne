/* How to use:
1. Config hardware and key struct.
2. Call userKeyInit() to initialization the hardware and keyFunctionPointer.
3. Poll the keyboardScan() at 50ms period.
4. Realize your function in keyFunctionPointer.*/
#ifndef _USER_KEY_H_
#define _USER_KEY_H_

//#define USER_KEY_SUPPORT //define to support key function
#ifdef USER_KEY_SUPPORT

/* Includes ------------------------------------------------------------------*/
#include "user.h"
#include "nds32_utils_math.h"
#include "saradc.h"
#include "gpio_ctrl.h"

/* define --------------------------------------------------------------------*/
/*----hardware config*/
// #define KT0206_Game_EVB			1
// #define CUSTOMER_BOARD			2
// #define HARDWARE_BOARD_SEL		CUSTOMER_BOARD

/*----gpio or adc key selection macro*/
#define KEY_TYPE_GPIO	1
#define KEY_TYPE_ADC	2

/*----hardware selection*/
#if (HARDWARE_BOARD_SEL == KT0206_Game_EVB)
	#define KEY_TYPE			KEY_TYPE_ADC
	#define KEY_NUMBER 			2
	#define SARADC_CVT_KEY		Saradc_Convert(2, SARADC_SEL_GPIO5)
	#define KEY_INIT 			GPIO_FuncSet(GPIO5, GPIO_AuxADC)
#elif (HARDWARE_BOARD_SEL == CUSTOMER_BOARD)
	#define KEY_TYPE			KEY_TYPE_GPIO
	#define KEY_NUMBER 			2
	#define KEY1_PORT 			GPIO7
	#define KEY2_PORT 			GPIO8
	#define KEY_PRESSING(port) 	((GPIO_InputGet(port) == 0) ? TRUE : FALSE) // low level valid
	#define KEY_INIT 			do{GPIO_FuncSet(KEY1_PORT, GPIO_PullUpInput); GPIO_FuncSet(KEY2_PORT, GPIO_PullUpInput);}while(0)
#endif 

/*----double and triple click support, 1:support, 0:not support*/
#define KEY_DOUBLE_TRIPLE_CLICK_EN		0	

/*----key scan parameter macro*/
#define KEY_SCAN_TIME 			(50U)
#define SHORT_PRES_TIME_MIN		(50U) //short press min time threshold
#define SHORT_PRES_TIME_MAX 	(350U) //short press max time threshold
#define LONG_PRES_TIME_MIN		(400U) //long press min time threshold
#define LONG_PRES_TIME_MAX 		(8000U) //long press max time threshold

#if KEY_DOUBLE_TRIPLE_CLICK_EN
	//#define PRES1_OVER_TIME		LONG_PRES_TIME_MAX //key press over time
	#define REL1_OVER_TIME		SHORT_PRES_TIME_MAX //key release over time
	#define PRES2_OVER_TIME		(500U)  //key press over time
	#define REL2_OVER_TIME		REL1_OVER_TIME  //key release over time
	#define PRES3_OVER_TIME		PRES2_OVER_TIME //key press over time
	//#define REL3_OVER_TIME		REL1_OVER_TIME  //key release over time
#endif

/* typedef -------------------------------------------------------------------*/
/*key state*/
typedef enum keyState_e{
	KEY_STAT_INIT, 	//init state(must be release state)
	KEY_STAT_PRES1,	//first press
	KEY_STAT_REL1, 	//first release
	KEY_STAT_PRES2,	//second press
	KEY_STAT_REL2, 	//second release
	KEY_STAT_PRES3,	//third press
	KEY_STAT_REL3,	//third release
	KEY_STAT_EXCEPT,//exception state
} keyState_e;

/*key event or result*/
typedef enum keyEvent_e{
	KEY_NO_ACTION,		//no key pressed or key pressed but no need to deal with
	KEY_S_PRES,			//short or single press
	KEY_S_REL,			//short or single release
	KEY_D_CLICK,		//double click
	KEY_T_CLICK,		//triple click
	KEY_L_PRES,			//long press 
	KEY_L_PRESSING,		//long press keep
	KEY_L_REL,			//long press release
}keyEvent_e;

typedef struct keyInfo_s{
	const uint8_t 	keyIndex;
#if (KEY_TYPE == KEY_TYPE_ADC)
	const uint16_t 	lowVoltage;
	const uint16_t 	highVoltage;
#elif (KEY_TYPE == KEY_TYPE_GPIO)
	uint8_t 	keyGpioPort;
#endif
	uint16_t 	keyStateTime;
	keyState_e 	keyState;
	keyEvent_e 	keyEvent;
}keyInfo_s;

/* variables -----------------------------------------------------------------*/
extern keyInfo_s keyArray[];

/* function prototypes -------------------------------------------------------*/
void userKeyInit(void* pKeyFunc);
void userKeyScan(void);
#endif /* USER_KEY_SUPPORT */
#endif /* _USER_KEY_H_ */
