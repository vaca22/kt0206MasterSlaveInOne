  /*
 * KT0206
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
//#include <stdint.h>
#include "uart.h"
#include "userTimer.h"
#include "gpio_ctrl.h"
#include "wav.h"
#include "saradc.h"
#include "volume.h"
#include "bll_config.h"
#include "chipEftCfg.h"
#include "reg_eft.h"
#include "asrc_adc_fs_ppm_pack.h"
#include "version.h"
#include "user_key.h"

uint8_t PLAY_END_CONT = 10;		//yuan++
uint8_t Kt1607TxRx_Mode = 0;	//0=RXMode, 1=TxMode

/* define --------------------------------------------------------------------*/
#define RELEASE_INFO 	SDK_VERSION

// gpio init ---------------------------------------------
#define LED1_ON 	GPIO_FuncSet(GPIO6, GPIO_DigOutput0)
#define LED2_ON 	GPIO_FuncSet(GPIO9, GPIO_DigOutput0)
#define LED3_ON 	GPIO_FuncSet(GPIO10, GPIO_DigOutput0)
#define LED7_ON 	GPIO_FuncSet(GPIO7, GPIO_DigOutput0)
#define LED8_ON 	GPIO_FuncSet(GPIO8, GPIO_DigOutput0)
#define LED1_OFF 	GPIO_FuncSet(GPIO6, GPIO_DigOutput1)
#define LED2_OFF 	GPIO_FuncSet(GPIO9, GPIO_DigOutput1)
#define LED3_OFF 	GPIO_FuncSet(GPIO10, GPIO_DigOutput1)
#define LED7_OFF 	GPIO_FuncSet(GPIO7, GPIO_DigOutput1)
#define LED8_OFF 	GPIO_FuncSet(GPIO8, GPIO_DigOutput1)
uint8_t AUDIO_IN_I2SSEL=0;//I2S_A, 只能设置为0或1 0:MASTER0 1:SLAVE0 	2:MASTER1	3:SLAVE1	0->1	//yuan++
uint8_t AUDIO_OUT_I2SSEL=2;//I2S_B, 只能设置为2或3 0:MASTER0 1:SLAVE0 2:MASTER1	3:SLAVE1
/* typedef -------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
extern uint8_t g_usb_bus_state;
extern uint8_t standby_enable;
#ifdef USB_IN_I2S_VOLUME_CTRL_BY_USER
	extern uint8_t dsp_adc2usb_vol;
#endif
#ifdef USB_OUT_I2S_VOLUME_CTRL_BY_USER
	extern uint8_t dsp_i2so_vol_l;
	extern uint8_t dsp_i2so_vol_r;
#endif

/* function prototypes -------------------------------------------------------*/
void sideToneEn(uint8_t en);

#if SIDETONE_ALWAYS_ON_EN
	extern void turnOnDac(void);
	extern void turnOnAdc(void);
#endif

/* functions -----------------------------------------------------------------*/
#ifdef USER_KEY_SUPPORT
//to do your key funciton
#define KEY_DBG_OUT(...) 	//printf(__VA_ARGS__)
void keyFunction(keyInfo_s *pKeyInfo)
{
	USER_DBG_OUT("key%d: %d\n", pKeyInfo->keyIndex, pKeyInfo->keyEvent);
	if(pKeyInfo->keyIndex == 1){
		switch (pKeyInfo->keyEvent){
		case KEY_S_PRES:			KEY_DBG_OUT("KEY_S_PRES\n");		break;
		case KEY_S_REL:				KEY_DBG_OUT("KEY_S_REL\n");			break;
		case KEY_L_PRES:			KEY_DBG_OUT("KEY_L_PRES\n");		break;
		case KEY_L_PRESSING:		KEY_DBG_OUT("KEY_L_PRESSING\n");	break;
		case KEY_L_REL:				KEY_DBG_OUT("KEY_L_REL\n");			break;
		default:break;
		}
	}else if(pKeyInfo->keyIndex == 2){
	}
}
#endif


#ifdef I2S_IN_DATA_PROCESS_USER
/*
pI2sInlAddr, pI2sInrAddr: i2s left and right data(24bit format 0xFFXXXXXX).
Len: usually 48
*/
void i2sInDataProcessUser(int32_t *pI2sInlAddr, int32_t *pI2sInrAddr, uint32_t Len)
{
	//int16_t i2sData16bit = (int16_t)(((*pI2sInlAddr)>>8) & 0xFFFF);
}
#endif

//SideTone switch
void sideToneEn(uint8_t en)
{
#if EFFECT_POST_SIDETONE_EN 
	if(g_pstConfig->DSPRegAll.bs.SideToneCfg.En != en)
	{
		g_pstConfig->DSPRegAll.bs.SideToneCfg.En = en;
		ChipEftReg_update(g_st_pHeadsetEft,&(g_pstConfig->DSPRegAll),DSPREG_IDX(SideToneCfg),AUDIO_SAMPLE_BLOCK_SIZE);
	}
#endif
}

//mic eq config
void inEffectEqCfg(void)
{
#if EFFECT_EQ_EN
	uint8_t i = 0;
	/*---------------------------------EQ config----------------------------------*/
	uint8_t eqNum = 2;
	const st_DSP_EQ_CONFIG EQB5Cfg[] = {
		[0]     = {.EQ_Type = 2,  .F0_0p1Hz = 750,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t)  -30), .EQ_EN = 1},
		[1]     = {.EQ_Type = 2,  .F0_0p1Hz = 750,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t)  -30), .EQ_EN = 1},
		// [2]     = {.EQ_Type = 2,  .F0_0p1Hz = 10000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t)  -30), .EQ_EN = 1},
		// [3]     = {.EQ_Type = 2,  .F0_0p1Hz = 80000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t)  -30), .EQ_EN = 1},
		// [4]     = {.EQ_Type = 2,  .F0_0p1Hz = 160000, .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t)  -30), .EQ_EN = 1},
	};
	for(i = 0; i < eqNum; i++){
		g_pstConfig->DSPRegAll.bs.EQB5Cfg[i].EQ_EN 	= EQB5Cfg[i].EQ_EN;
		g_pstConfig->DSPRegAll.bs.EQB5Cfg[i].EQ_Type 	= EQB5Cfg[i].EQ_Type;	
		g_pstConfig->DSPRegAll.bs.EQB5Cfg[i].Qv 		= EQB5Cfg[i].Qv;	
		g_pstConfig->DSPRegAll.bs.EQB5Cfg[i].F0_0p1Hz 	= EQB5Cfg[i].F0_0p1Hz;
		g_pstConfig->DSPRegAll.bs.EQB5Cfg[i].Gain_0p1dB= EQB5Cfg[i].Gain_0p1dB;
		ChipEftReg_update(g_st_pHeadsetEft,&(g_pstConfig->DSPRegAll),DSPREG_IDX(EQB5Cfg[i]),AUDIO_SAMPLE_BLOCK_SIZE);
	}
#endif
}

void displayTime(void)
{
	USER_DBG_OUT("time: %ld ms\n", timer_tick_ms_get());
	//**** Kt1607 TxRx 切換 ****************
	if(PLAY_END_CONT < 10){	//yuan++
		PLAY_END_CONT++;
		if(Kt1607TxRx_Mode == 0){
			Kt1607TxRx_Mode = 1;
			GPIO_FuncSet(GPIO6, GPIO_DigOutput1);	//Kt1607 for TxMode
			USER_DBG_OUT("KT1607 Setup TxMode...\n");
		}
	}else{
		if(Kt1607TxRx_Mode == 1){
			Kt1607TxRx_Mode = 0;
			GPIO_FuncSet(GPIO6, GPIO_DigOutput0);	//Kt1607 for RxMode
			USER_DBG_OUT("KT1607 Setup RxMode...\n");
		}
	}
}

/********************************************
 * GPIO1,GPIO2 挂了滑动变阻器，用来调节音量
 * GPIO3,GPIO4 为UART功能
 * GPIO5 挂了6个按键
 * GPIO6，GPIO9，GPIO10 分别挂了一个LED，低电平亮
 * GPIO7,GPIO8 分别挂了一个LED，低电平亮, 可为仿真器接口
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

	LED1_ON;	// for KT1607 ON=RxMode	OFF=TxMode
	LED2_OFF;
	LED3_OFF;
	LED7_OFF;
	LED8_OFF;
}

//**** 用户所有的初始化函数都放在这里面来做
void _user_delay_init(void)
{
	sideToneEn(SIDETONE_DEF_STAT);
	inEffectEqCfg();
#if SIDETONE_ALWAYS_ON_EN
	g_mute_bit &= ~BIT_SPK; //unmute dac
#endif
	if(g_usb_bus_state & B_INT_RESET) // must run in _user_delay_init()
	{
		g_usb_bus_state &= ~B_INT_RESET;
		USER_DBG_OUT("usb reset! connecting to a usb host.\n");
	}
}
//***********************************************
void _user_schedule(void)
{
	UserTimerProcess();
}
//***********************************************
void _user_init(void)
{
	GPIOInit();
	uartInit(115200);//串口初始化
	USER_DBG_OUT("\n\n\n KTMicro USB Audio!");
	USER_DBG_OUT("\n Compile @ %s %s ----> Release : %s\n\n", __DATE__, __TIME__, RELEASE_INFO);
	userTimerInit();//1ms tick定时器初始化,使用的是内部的timer0
	addUserTimerEvent(displayTime, 1000, timerPeriod);//设置1s打印一次时间	//yuan++
	standby_enable = 1;
#if SIDETONE_ALWAYS_ON_EN
	g_mute_bit |= BIT_SPK; //mute dac
	addUserTimerEvent(turnOnAdc, 1000, timerOnce);//
	addUserTimerEvent(turnOnDac, 1000, timerOnce);//
	standby_enable = 0;
#endif
	addUserTimerEvent(_user_delay_init, 2000, timerOnce);//
#ifdef USER_KEY_SUPPORT
	userKeyInit(keyFunction);
	// addUserTimerEvent(userKeyScan, KEY_SCAN_TIME, timerPeriod);//
#endif
	//g_pstConfig->DSPRegAll.bs.MusicDkCfg0.En = 1;//music dodge
}

