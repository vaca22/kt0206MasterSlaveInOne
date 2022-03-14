/* Includes ------------------------------------------------------------------*/
#include "user_key.h"

#ifdef USER_KEY_SUPPORT
/* define --------------------------------------------------------------------*/
/* typedef -------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
//key struct
keyInfo_s keyArray[] = {
#if (HARDWARE_BOARD_SEL == KT0206_Game_EVB)
	{.keyIndex = 1, .lowVoltage = 60,  .highVoltage = 130, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}, //93 10k 1k
	{.keyIndex = 2, .lowVoltage = 180, .highVoltage = 270, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}, //236 10k 3k
	// {.keyIndex = 3, .lowVoltage = 300, .highVoltage = 400, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}, //346 10k 5.1k
	// {.keyIndex = 4, .lowVoltage = 450, .highVoltage = 550, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}, //512 10k 10k
	// {.keyIndex = 5, .lowVoltage = 570, .highVoltage = 640, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}, //614 10k 15k
	// {.keyIndex = 6, .lowVoltage = 645, .highVoltage = 750, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION}  //682 10k 20k
#elif (HARDWARE_BOARD_SEL == CUSTOMER_BOARD)
	{.keyIndex = 1, .keyGpioPort = KEY1_PORT, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION},
	{.keyIndex = 2, .keyGpioPort = KEY2_PORT, .keyStateTime = 0, .keyState = KEY_STAT_INIT, .keyEvent = KEY_NO_ACTION},
#endif
};

static void (*pKeyFunction)(keyInfo_s *pKeyInfo_s);
/* function prototypes -------------------------------------------------------*/
/* functions -----------------------------------------------------------------*/
void userKeyInit(void* pKeyFunc)
{
	KEY_INIT;
	pKeyFunction = pKeyFunc;
}

//scan the all key and get the key event
/**********************************************************************
====single/long PRES： INIT---PRES1---REL1---INIT	
@PRES1 get SINGLE_PRES, LONG_PRES, LONG_PRES_KEEP 	@REL1 get SINGLE_REL
====double PRES: INIT---PRES1---REL1---PRES2---REL2---INIT						@REL2 get double click
====triple PRES：INIT---PRES1---REL1---PRES2---REL2---PRES3---REL3---INIT		@REL3 get triple click
************************************************************************/
#define KEY_DBG_INFO(...)	//printf(__VA_ARGS__)
void userKeyScan(void)
{
	uint8_t i;

	for(i=0; i < KEY_NUMBER; i++)
	{
#if (KEY_TYPE == KEY_TYPE_ADC)
		uint16_t code = SARADC_CVT_KEY;
		uint8_t keyPressing = ((code >= keyArray[i].lowVoltage) && (code <= keyArray[i].highVoltage));
#elif (KEY_TYPE == KEY_TYPE_GPIO)
		uint8_t keyPressing = KEY_PRESSING(keyArray[i].keyGpioPort);
#endif

		switch (keyArray[i].keyState)
		{
		case KEY_STAT_INIT:
			keyArray[i].keyEvent = KEY_NO_ACTION;
			if(keyPressing){
				KEY_DBG_INFO("key %d detection start >>>>>>>>\n", (i + 1));
				keyArray[i].keyState = KEY_STAT_PRES1;
				keyArray[i].keyStateTime = 0;
			}
			break;
		case KEY_STAT_PRES1:
			if(keyPressing){
				keyArray[i].keyStateTime += KEY_SCAN_TIME;
				//单击按下开始，切换按键结果，结果仅本次扫描有效
				if(keyArray[i].keyStateTime == KEY_SCAN_TIME){//assignment KEY_S_PRES only once
						KEY_DBG_INFO("short press down detected!\n");
						keyArray[i].keyEvent = KEY_S_PRES;
				}
				//当按下超过一定时间，赋值长按事件，下次扫描切换到长按循环事件
				else if(keyArray[i].keyStateTime >= LONG_PRES_TIME_MIN){ 
					if((keyArray[i].keyEvent == KEY_L_PRES) || (keyArray[i].keyEvent == KEY_L_PRESSING)){
						KEY_DBG_INFO("long press continue!\n");
						keyArray[i].keyEvent = KEY_L_PRESSING;
					}else{
						KEY_DBG_INFO("long press down detected!\n");
						keyArray[i].keyEvent = KEY_L_PRES;	//assignment KEY_L_PRES only once
					}
				}else{
					keyArray[i].keyEvent = KEY_NO_ACTION;
				}
			}else{//key release
				KEY_DBG_INFO("KEY PRESS1\t time = %d ms\n", keyArray[i].keyStateTime);
#if (KEY_DOUBLE_TRIPLE_CLICK_EN == 0)
				//释放后获取按下时间，这里可确认单击按键释放事件
				if((keyArray[i].keyStateTime >= SHORT_PRES_TIME_MIN)&&(keyArray[i].keyStateTime < SHORT_PRES_TIME_MAX)){
					KEY_DBG_INFO("short press release detected!\n");
					keyArray[i].keyEvent = KEY_S_REL;
				}else if(keyArray[i].keyStateTime >= LONG_PRES_TIME_MIN){ 
					KEY_DBG_INFO("long press release detected!\n");
					keyArray[i].keyEvent = KEY_L_REL;
				}else{
					keyArray[i].keyEvent = KEY_NO_ACTION;//avoid keyEvent = KEY_S_PRES.
				}
				KEY_DBG_INFO(">>>>>>>> key %d detection complete!\n", (i + 1));
				keyArray[i].keyState = KEY_STAT_INIT;	
				keyArray[i].keyStateTime = 0;	
			}
			break;
#else
				if(keyArray[i].keyStateTime >= LONG_PRES_TIME_MIN){ 
					KEY_DBG_INFO("long press release detected!\n");
					keyArray[i].keyEvent = KEY_L_REL;
					keyArray[i].keyState = KEY_STAT_INIT;	
					KEY_DBG_INFO(">>>>>>>> key %d detection complete!\n", (i + 1));
				}else{
					keyArray[i].keyEvent = KEY_NO_ACTION;//avoid keyEvent = KEY_S_PRES.
					keyArray[i].keyState = KEY_STAT_REL1; 
				}
				keyArray[i].keyStateTime = 0;		
			}
			break;
		case KEY_STAT_REL1:
			if(keyPressing){	//press, change state
				KEY_DBG_INFO("KEY RELEASE1\t time = %d ms\n", keyArray[i].keyStateTime);
				keyArray[i].keyState = KEY_STAT_PRES2;	
				keyArray[i].keyStateTime = 0;
			}else{//key release
				keyArray[i].keyStateTime += KEY_SCAN_TIME;
				//当释放时间超时，则确认单击事件(要支持双击，需要检测释放时间，超时才可确认，因此支持双击、三击的情况下单击响应会慢一点)
				if(keyArray[i].keyStateTime > REL1_OVER_TIME){
					KEY_DBG_INFO("single click detected!\n");
					keyArray[i].keyEvent = KEY_S_REL;
					keyArray[i].keyState = KEY_STAT_INIT;	
					keyArray[i].keyStateTime = 0;
					KEY_DBG_INFO(">>>>>>>> key %d detection complete!\n", (i + 1));
				}
			}
			break;
		case KEY_STAT_PRES2:
			if(keyPressing){
				keyArray[i].keyStateTime += KEY_SCAN_TIME;
				//限制连击时按下时间
				if(keyArray[i].keyStateTime > PRES2_OVER_TIME){
					KEY_DBG_INFO("EXCEPTION: The second press down over time!\n");
					keyArray[i].keyState = KEY_STAT_EXCEPT;	
					keyArray[i].keyStateTime = 0;
				}
			}else{//key release
				KEY_DBG_INFO("KEY PRESS2\t time = %d ms\n", keyArray[i].keyStateTime);
				keyArray[i].keyState = KEY_STAT_REL2;
				keyArray[i].keyStateTime = 0;
			}
			break;
		case KEY_STAT_REL2:
			if(keyPressing){  //press, change state
				KEY_DBG_INFO("KEY RELEASE2\t time = %d ms\n", keyArray[i].keyStateTime);
				keyArray[i].keyState = KEY_STAT_PRES3;	
				keyArray[i].keyStateTime = 0;
			}else{//key release
				keyArray[i].keyStateTime += KEY_SCAN_TIME;

				//当释放时间超时，则确认双击事件
				if(keyArray[i].keyStateTime > REL2_OVER_TIME){
					KEY_DBG_INFO("double click detected!\n");
					keyArray[i].keyEvent = KEY_D_CLICK;
					keyArray[i].keyState = KEY_STAT_INIT;	
					keyArray[i].keyStateTime = 0;
					KEY_DBG_INFO(">>>>>>>> key %d detection complete!\n", (i + 1));
				}
			}
			break;
		case KEY_STAT_PRES3:
			if(keyPressing){
				keyArray[i].keyStateTime += KEY_SCAN_TIME;
				//限制连击时按下时间
				if(keyArray[i].keyStateTime > PRES3_OVER_TIME){
					KEY_DBG_INFO("EXCEPTION: The third press down over time!\n");
					keyArray[i].keyState = KEY_STAT_EXCEPT;	
					keyArray[i].keyStateTime = 0;
				}
			}else{//key release
				KEY_DBG_INFO("KEY PRESS3\t time = %d ms\n", keyArray[i].keyStateTime);
				keyArray[i].keyState = KEY_STAT_REL3;	
				keyArray[i].keyStateTime = 0;
			}
			break;
		case KEY_STAT_REL3:
			//当释放时，则确认三击事件
			KEY_DBG_INFO("triple click detected!\n");
			keyArray[i].keyEvent = KEY_T_CLICK;
			keyArray[i].keyState = KEY_STAT_INIT;	
			keyArray[i].keyStateTime = 0;
			KEY_DBG_INFO(">>>>>>>> key %d detection complete!\n", (i + 1));
			break;
		case KEY_STAT_EXCEPT:
			keyArray[i].keyEvent = KEY_NO_ACTION;

			if(keyPressing){
				KEY_DBG_INFO("waiting for key%d released!\n", (i + 1));//wait release
			}else{//key release
				keyArray[i].keyState = KEY_STAT_INIT;	
				keyArray[i].keyStateTime = 0;
				KEY_DBG_INFO(">>>>>>>> key%d exception process complete!\n", (i + 1));
			}
			break;
#endif
		default:
			break;
		}
		if(keyArray[i].keyEvent != KEY_NO_ACTION)
		{
			pKeyFunction(&keyArray[i]);
		}
	}
}

#if 0 //move the function to user.c
//to do your key funciton
void keyFunction(keyInfo_s *pKeyInfo)
#define KEY_DBG_OUT(...) 	//printf(__VA_ARGS__)
void keyFunction(keyInfo_s *pKeyInfo)
{
	KEY_DBG_OUT("key%d: %d\n", pKeyInfo->keyIndex, pKeyInfo->keyEvent);
	if(pKeyInfo->keyIndex == 1){
		switch (pKeyInfo->keyEvent){
		case KEY_S_PRES:			KEY_DBG_OUT("KEY_S_PRES\n");		break;
		case KEY_S_REL:				KEY_DBG_OUT("KEY_S_REL\n");			break;
		case KEY_D_CLICK:			KEY_DBG_OUT("KEY_D_CLICK\n");		break;
		case KEY_T_CLICK:			KEY_DBG_OUT("KEY_T_CLICK\n");		break;
		case KEY_L_PRES:			KEY_DBG_OUT("KEY_L_PRES\n");		break;
		case KEY_L_PRESSING:		KEY_DBG_OUT("KEY_L_PRESSING\n");	break;
		case KEY_L_REL:				KEY_DBG_OUT("KEY_L_REL\n");			break;
		default:break;
		}
	}else if(pKeyInfo->keyIndex == 2){
	}
}
//userKeyInit(keyFunction);
#endif

#endif /* USER_KEY_SUPPORT */
