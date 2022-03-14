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
#include "user_key.h"
#include "usb_bulk.h"

/* define --------------------------------------------------------------------*/
#define RELEASE_INFO "KT0206 Stereo"

/* typedef -------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
extern uint8_t g_usb_bus_state;
extern uint8_t standby_enable;

/* function prototypes -------------------------------------------------------*/
void sideToneEn(uint8_t en);

#if SIDETONE_ALWAYS_ON_EN
	extern void turnOnDac(void);
	extern void turnOnAdc(void);
#endif

/* functions -----------------------------------------------------------------*/
#define APPLE_IAP_USB_BULK_TEST_EN 	1
#if APPLE_IAP_USB_BULK_TEST_EN
uint8_t g_intBulkInNum = 0;
uint8_t g_intBulkOutNum = 0;
uint8_t appleFirstBulkInBuf[6] = {0xFF, 0x55, 0x02, 0x00, 0xEE, 0x10};
uint8_t rcvBuf[256] = {0};
#endif
void displayTime(void)
{
	USER_DBG_OUT("time: %ld ms\n", timer_tick_ms_get());
#if APPLE_IAP_USB_BULK_TEST_EN
	USER_DBG_OUT("g_intBulkInNum: %d , g_intBulkOutNum: %d \n", g_intBulkInNum, g_intBulkOutNum);
	USER_DBG_OUT("wr=%d, rd=%d\n", g_stBulkOut.wr, g_stBulkOut.rd);

	uint8_t dataLen = bulk_out_buf_data_num_get(g_stBulkOut.wr, g_stBulkOut.rd, g_stBulkOut.buf_size);
	USER_DBG_OUT("bulk rcv %d data\n", dataLen);
	if(dataLen > 0)
	{
		USB_BULK_Receive(rcvBuf, dataLen);
		uint8_t i = 0;
		USER_DBG_OUT("bulk rcv data: ");
		for(;i < dataLen; i++){
			USER_DBG_OUT("0x%02X ", *(rcvBuf+i));
		}
		USER_DBG_OUT("\n");
	}
#endif
}
/*
first send data is "0xFF, 0x55, 0x02, 0x00, 0xEE, 0x10", you should print:
----
time: XXXXms
g_intBulkInNum: 2, g_intBulkOutNum: 1
wr=6, rd=0
bulk rcv 6 data
bulk rcv data: 0xFF 0x55 0x02 0x00 0xEE 0x10
----
verify OK!
*/

/********************************************
 * GPIO1,GPIO2挂了滑动变阻器，用来调节音量
 * GPIO3,GPIO4为UART功能
 * GPIO5 挂了6个按键
 * GPIO6 挂了一个LED，低电平亮
 * GPIO7,GPIO8为仿真器接口
 * GPIO9，GPIO10 分别挂了一个LED，低电平亮
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
}

//用户所有的初始化函数都放在这里面来做
void _user_delay_init(void)
{
}

void _user_schedule(void)
{
	UserTimerProcess();
	#if APPLE_IAP_USB_BULK_TEST_EN
	if(g_ucUsbEnumFinish)
	{
		static uint8_t flag = 1;
		if(flag)
		{
			flag = 0;
			USB_BULK_Transmit(appleFirstBulkInBuf, sizeof(appleFirstBulkInBuf));
		}
	}
	#endif
}

void _user_init(void)
{
	GPIOInit();
	uartInit(115200);//串口初始化
	USER_DBG_OUT("\n\n\n KTMicro USB Audio!");
	USER_DBG_OUT("\n Compile @ %s %s ----> Release : %s\n\n", __DATE__, __TIME__, RELEASE_INFO);
	userTimerInit();//1ms tick定时器初始化,使用的是内部的timer0
	addUserTimerEvent(displayTime, 5000, timerPeriod);//设置5s打印一次时间
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
	addUserTimerEvent(userKeyScan, KEY_SCAN_TIME, timerPeriod);//
#endif
	//g_pstConfig->DSPRegAll.bs.MusicDkCfg0.En = 1;//music dodge
#if APPLE_IAP_USB_BULK_TEST_EN
	USB_BULK_Init(NULL);
#endif
}

