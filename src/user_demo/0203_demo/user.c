
/*
 * user.c
 *
 */

#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>
#include <stdio.h>

#include "KT065xDrv.h"
#include "KT065x_SeekFreq.h"
#include "soft_i2c.h"
#include "user_flash.h"
#include "KT_usb_keyboard.h"
#include "Effect.h"

#define   UART_DEBUG_REG	// 串口上位机调试寄存器

#define   SeekChannel       // 搜台
#define   BPSKEffect        // BPSK数据调音效       //
#define   SAVE_FLASH        // 保存数据到Flash
//#define 	TestKey         // 定义调试按键                     开机按住进入测试模式,自定义按键调试功能等等

#define KT0656M_CHIPEN_A	API_GPIO_9            //
#define KT0656M_CHIPEN_B	API_GPIO_10

#define SeekCHALEDPin	    API_GPIO_5            //  通道A搜台指示灯GPIO3，同时也是串口接收,因为将UART打开当做串口调试用了，所以这个GPIO不可用了！
#define SeekCHBLEDPin		API_GPIO_6            //  通道B搜台指示灯GPIO5
//#define TestPin		    	API_GPIO_3            //  测试按键GPIO6

typedef struct
{
	uint8_t		SysTick;
	uint8_t		KeyVal;
    uint16_t 	UserCount;

	struct
	{
		uint16_t Task_5msOK		:1;
		uint16_t Task_100msOK	:1;
		uint16_t Task_500msOK	:1;
		uint16_t UserCountOK	:1;

		uint16_t RxOK			:1;
		uint16_t HIDReceiveOK   :1;         // 收到HID命令，保留

		uint16_t RFU			:10;        // 保留位
	}flag;

	uint8_t		Rxbuf[20];
}st_SysTickStruct;

const SoftI2C_t I2CDef_KT065xM_CHA =
{
		.SCL_Pin		= API_GPIO_2,
		.SDA_Pin		= API_GPIO_1,
		.DeviceAddr = KTWirelessMicRx_addressAM,
		.AddrLen	= SoftI2C_2Byte,
		.DataLen	= SoftI2C_1Byte,
		.Speed		= SoftI2C_200K,
};

const SoftI2C_t I2CDef_KT065xM_CHB =
{
		.SCL_Pin		= API_GPIO_2,
		.SDA_Pin		= API_GPIO_1,
		.DeviceAddr = KTWirelessMicRx_addressBM,
		.AddrLen	= SoftI2C_2Byte,
		.DataLen	= SoftI2C_1Byte,
		.Speed		= SoftI2C_200K,
};



const uint8_t u8BufTest[256] = {
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A,

        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
        0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x5A, 0x11,
};

st_SysTickStruct 	SysTickStruct = {0};
uint16_t SeekTimerCnt_CHA;
uint16_t SeekTimerCnt_CHB;
uint8_t SaveDataAddrIndex = 0;
uint8_t TestMode = 1;
uint8_t HIDReceiveBuf[8] = {0};

uint8_t rxbuf[256] = {0};

extern KT056x_SeekFreqStatus_t  SeekFreqStruct_CHA;
extern KT056x_SeekFreqStatus_t  SeekFreqStruct_CHB;
extern const KT065xM_I2SConfig_t 	I2SConfig_CHA;
extern const KT065xM_I2SConfig_t 	I2SConfig_CHB;
extern KT065xM_BpskData_t KT065x_BpskData;

void UserTask_5ms (void);
void UserTask_100ms (void);
void UserTask_500ms (void);
void Key_Task(void);
void Rx_Response(void);

void Timer0_ISR (void)
{
	SysTickStruct.SysTick++;

	// KT0656M计数器节拍
	SeekFreqStruct_CHA.Tick5msCnt++;
	SeekFreqStruct_CHB.Tick5msCnt++;

	SysTickStruct.flag.Task_5msOK = 1;
	if(SysTickStruct.SysTick>=100)
	{
		SysTickStruct.SysTick = 0;
		SysTickStruct.flag.Task_500msOK = 1;
	}
	if(SysTickStruct.SysTick%20 == 0)
	{
		SysTickStruct.flag.Task_100msOK = 1;
	}
    if(SysTickStruct.UserCount>0)
    {
    	SysTickStruct.UserCount--;
    	if(SysTickStruct.UserCount == 0)
    	{
    		SysTickStruct.flag.UserCountOK = 1;
    	}
    }
#ifdef 	TestKey
    static uint8_t Key_ValOld = 1, KeyCnt = 0;
    uint8_t Key_Val;
    Key_Val = api_gpio_input_get(TestPin);
    if((Key_Val==API_GPIO_INPUT1)&&(Key_ValOld==API_GPIO_INPUT0))
    {
    	if(KeyCnt>=150)
    	{
    		SysTickStruct.KeyVal = 100+1;          // long
    	}
    	else
    	{
    		SysTickStruct.KeyVal = 1;              // short
    	}
    	KeyCnt = 0;
    }
    if(Key_Val==API_GPIO_INPUT0)
    {
    	if(KeyCnt<255)
    		KeyCnt++;
    }
    Key_ValOld = Key_Val;
#endif
}

// HID接收中断处理函数
void User_HID_ReceiveCallback(uint8_t *buf) // HID中断函数，禁止写延时!!!,内部串口打印不可用!!! 使用HID前需要先注册该函数！
{
	HIDReceiveBuf[0] = buf[0];              // buf数据共4个字节, for UART Print
	HIDReceiveBuf[1] = buf[1];
	HIDReceiveBuf[2] = buf[2];
	HIDReceiveBuf[3] = buf[3];

 /*         发送给主机格式  byte:   0    1     2   3     4   5    6    7    8    9    10
 *  Send Data To USB Host:  |0x4b|0x00|0x00|0x00|0x00|0xb1| xx | dd | dd | dd | dd |          xx:RFU(hex), dd:data(hex)
 */
	User_HID_Send(buf, 4);                 // 可选，  HID返回给主机 , 且User_HID_Send只能在User_HID_ReceiveCallback()回调函数中使用
	;                                      // 用户可自行定义返回给主机数据 ,只有dd数据(Byte7~10)是用户可以自定义的

	SysTickStruct.flag.HIDReceiveOK = 1;
}

void _user_schedule(void)
{
	// TODO add your own code
	if(SysTickStruct.flag.Task_5msOK)
	{
#ifdef	SeekChannel
#ifdef TestKey
	    if(TestMode==API_GPIO_INPUT1)         // 正常模式
#endif
	    {
		    UserTask_5ms();
	    }
#endif
		SysTickStruct.flag.Task_5msOK = 0;
	}
	if(SysTickStruct.flag.Task_100msOK)
	{
#ifdef	SeekChannel
#ifdef TestKey
	    if(TestMode==API_GPIO_INPUT1)         // 正常模式
#endif
		{
			UserTask_100ms();
		}
#endif
		SysTickStruct.flag.Task_100msOK = 0;
	}
	if(SysTickStruct.flag.Task_500msOK)
	{
		UserTask_500ms();
		SysTickStruct.flag.Task_500msOK = 0;
	}
	if(SysTickStruct.flag.UserCountOK)
	{
		// 用户开机更改手柄ID超时,使能禁止
		SeekFreqStruct_CHA.flag.ChangePrivateIDDis = 1;
		SeekFreqStruct_CHB.flag.ChangePrivateIDDis = 1;
		SysTickStruct.flag.UserCountOK = 0;
	}
    if(SysTickStruct.KeyVal)          // 按键按下
    {
#ifdef 	TestKey
    	Key_Task();
#endif
    	SysTickStruct.KeyVal = 0;
    }

}

void _user_init(void)
{
//	un_SaveSeekFreqStruct *p;
//	api_coreclk_set(API_CORECLK_192M);
//	Delay_Ms(20);
	// TODO add your own code

	Set_User_HID_Receive_Handler(User_HID_ReceiveCallback);        // 注册HID中断接收函数，使用HID前需要先注册

	api_keyboard_support_cfg(Enable);

//	api_keyboard_support_cfg(Enable);

	api_timer_start(API_TIMER_0, 5, API_TIM_MS, Timer0_ISR);

	api_gpio_func_set(SeekCHALEDPin, API_GPIO_Output1); //
	api_gpio_func_set(SeekCHBLEDPin, API_GPIO_Output1);

#ifdef 	TestKey
	api_gpio_func_set(TestPin, API_GPIO_PullUpInput);
#else
	//api_gpio_func_set(TestPin, API_GPIO_Output1);
#endif


#ifdef 	dbg    // 串口打印
//	api_uart_init(460800.0/1.024);         // 修正波特率系数误差
	api_uart_init(115200);         // 460800*192/128
	DBG("UART INIT OK\n");
#endif

//	i2c_init(&KT0656M_I2C_Def);   硬件I2C有bug
	SoftI2C_Init(&I2CDef_KT065xM_CHA);

	// KT0656M CHIPEN
	api_gpio_func_set(KT0656M_CHIPEN_A, API_GPIO_Output0);
	api_gpio_func_set(KT0656M_CHIPEN_B, API_GPIO_Output0);
	Delay_Ms(10);
	api_gpio_func_set(KT0656M_CHIPEN_A, API_GPIO_Output1);
	api_gpio_func_set(KT0656M_CHIPEN_B, API_GPIO_Output1);

	Delay_Ms(100);

	while(!KT_WirelessMicRx_PreInit(&I2CDef_KT065xM_CHA));
	while(!KT_WirelessMicRx_Init(&I2CDef_KT065xM_CHA));

	KT_WirelessMicRx_deltemp(&I2CDef_KT065xM_CHA);
	KT_WirelessMicRx_Tune(&I2CDef_KT065xM_CHA, 645250);

	while(!KT_WirelessMicRx_PreInit(&I2CDef_KT065xM_CHB));
	while(!KT_WirelessMicRx_Init(&I2CDef_KT065xM_CHB));

	KT_WirelessMicRx_deltemp(&I2CDef_KT065xM_CHB);
	KT_WirelessMicRx_Tune(&I2CDef_KT065xM_CHB, 665250);

	DBG("KT0656M INIT OK\n");

	SeekFreqStruct_CHA.CurrentVolume = 31;  // 保存音量
	SeekFreqStruct_CHB.CurrentVolume = 31;  // 保存音量

#ifdef 	TestKey
	TestMode = api_gpio_input_get(TestPin);  // 开机按下测试按键进入测试模式

    if(TestMode==API_GPIO_INPUT0)  // 测试模式
    {
		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHA, 31);     // 关音量
		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHB, 31);

#ifdef	KT0656M_I2SEn

		Delay_Ms(200);
		KT_WirelessMicRx_SAIInit(&I2CDef_KT065xM_CHA, &I2SConfig_CHA);
		KT_WirelessMicRx_SAIInit(&I2CDef_KT065xM_CHB, &I2SConfig_CHB);
#endif
    }
    else            // 正常模式
    {
		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHA, 0);     // 关音量
		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHB, 0);
    }
#else

	KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHA, 0);     // 关音量
	KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHB, 0);
#endif

	SysTickStruct.UserCount = 20;//30*200;         // 用户开机更改手柄ID预置时间30*200*5ms
	SeekTimerCnt_CHA = 0; // 搜台计时清零
	SeekTimerCnt_CHB = 0;

	//------------ DSP 开机音效 -----------
//	DSP_Echo_Set(&UserEchoConfig0);
//	DSP_Reverb_Set(&UserReverbConfig2);

//	DSP_Howling_Detect(&UserHowlingDetectConfig0);
//	DSP_Howling_Avc(&UserHowlingAvcConfig0);
//	DSP_Howling_Notch(&UserHowlingNotchConfig0);
//	DSP_Howling_Ctrl(&UserHowlingCtrlDis);

	; // 此处添加读取并檫除Flash操作, 暂不启用
#ifdef	SAVE_FLASH
	Delay_Ms(10);
	if(ReadDataFromFlash())
	{
		SeekFreqStruct_CHA.CurrentVolume       = FlashData.SeekData_A.CurrentVolume;
		SeekFreqStruct_CHA.LastSeekFreqOKIndex = FlashData.SeekData_A.LastSeekFreqOKIndex;
		SeekFreqStruct_CHA.PrivateID           = FlashData.SeekData_A.PrivateID;

		SeekFreqStruct_CHB.CurrentVolume       = FlashData.SeekData_B.CurrentVolume;
		SeekFreqStruct_CHB.LastSeekFreqOKIndex = FlashData.SeekData_B.LastSeekFreqOKIndex;
		SeekFreqStruct_CHB.PrivateID           = FlashData.SeekData_B.PrivateID;

		SeekFreqStruct_CHA.flag.LoadDataOK = 1;     // 从Flash读取用户数据OK
		SeekFreqStruct_CHB.flag.LoadDataOK = 1;

		DBG("CHA.CurrentVolume = %d\n", SeekFreqStruct_CHA.CurrentVolume);
		DBG("CHA.LastSeekFreqOKIndex = %d\n", SeekFreqStruct_CHA.LastSeekFreqOKIndex);
		DBG("CHA.PrivateID = 0x%04x\n", SeekFreqStruct_CHA.PrivateID);

		DBG("CHB.CurrentVolume = %d\n", SeekFreqStruct_CHB.CurrentVolume);
		DBG("CHB.LastSeekFreqOKIndex = %d\n", SeekFreqStruct_CHB.LastSeekFreqOKIndex);
		DBG("CHB.PrivateID = 0x%04x\n", SeekFreqStruct_CHB.PrivateID);
		DBG("Read Flash OK\n");

		// erase
		GLOBAL_INT_STOP();
		api_flash_sector_erase(0x24000, 0x4000);   // 擦除16k空间大小
		GLOBAL_INT_START();

		DBG("Erase Flash OK\n");

		SaveDataToFlash(&FlashData);         // Save Update
	}
	else
	{
		DBG("No Data in Flash!\n");
		// erase
		GLOBAL_INT_STOP();
		api_flash_sector_erase(0x24000, 0x4000);	// 擦除16k空间大小
		GLOBAL_INT_START();

		DBG("Erase Flash OK\n");
	}

#endif
}


void UserTask_5ms (void)
{
	KT056x_SeekFreq(&I2CDef_KT065xM_CHA, &SeekFreqStruct_CHA);     // CH A
	KT056x_SeekFreq(&I2CDef_KT065xM_CHB, &SeekFreqStruct_CHB);     // CH B

	uint8_t len;
	len = api_uart_read(SysTickStruct.Rxbuf, 20);           // 串口接收到数据 ,循环查询方式获得

	if((len>0)&&(len<19))    // 接收到数据
	{
#ifdef	UART_DEBUG_REG
		if(len==8)
		{
			Uart_Debug_Reg_Response(SysTickStruct.Rxbuf, 8);     // 上位机调试寄存器接口
		}
		else
#endif
		{
			DBG("Uart Get %d Data:", len);
			SysTickStruct.Rxbuf[len] = '\0';   // 最后一位补\0,方便打印
			Rx_Response();     // 串口收到数据
		}
	}

    /************** 用于计时搜台时间 ************/
    if(!SeekFreqStruct_CHA.flag.SeekOK)
    {
    	SeekTimerCnt_CHA++;
    }
    if(!SeekFreqStruct_CHB.flag.SeekOK)
    {
    	SeekTimerCnt_CHB++;
    }

    if(SeekFreqStruct_CHA.flag.VolumeSmooth)            // 音量平滑
    {
    	if(SeekFreqStruct_CHA.SmoothVol<SeekFreqStruct_CHA.CurrentVolume)
    	{
    	    KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHA, SeekFreqStruct_CHA.SmoothVol++);        //
    	}
    	else
    	{
    		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHA, SeekFreqStruct_CHA.CurrentVolume);
    		SeekFreqStruct_CHA.flag.VolumeSmooth = 0;
    	}
    }
    if(SeekFreqStruct_CHB.flag.VolumeSmooth)            // 音量平滑
    {
    	if(SeekFreqStruct_CHB.SmoothVol<SeekFreqStruct_CHB.CurrentVolume)
    	{
    	    KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHB, SeekFreqStruct_CHB.SmoothVol++);        //
    	}
    	else
    	{
    		KT_WirelessMicRx_Volume(&I2CDef_KT065xM_CHB, SeekFreqStruct_CHB.CurrentVolume);
    		SeekFreqStruct_CHB.flag.VolumeSmooth = 0;
    	}
    }
}

void UserTask_100ms (void)
{
	if(SysTickStruct.flag.HIDReceiveOK)
	{
		DBG("HID=0x%02x %02x %02x %02x\n", HIDReceiveBuf[0], HIDReceiveBuf[1], HIDReceiveBuf[2], HIDReceiveBuf[3]);
		SysTickStruct.flag.HIDReceiveOK = 0;
	}

	static uint8_t SeekStatusold_A = 1, SeekStatusold_B = 1;
	if((SeekStatusold_A==1)&&(SeekFreqStruct_CHA.flag.SeekOK==0))
	{
		DBG("--------ChannelA Start Seek!--------\n");
		SeekTimerCnt_CHA = 0;    // 搜台计时计数器清零
	}
	else if((SeekStatusold_A==0)&&(SeekFreqStruct_CHA.flag.SeekOK==1))
	{
	  DBG("-----------ChannelA Seek OK!----------\n");
	  DBG("Seek ChannelA:Count=%d\tTim=%6.2fs!\t",SeekFreqStruct_CHA.SeekFreqIndex,(float)SeekTimerCnt_CHA*0.005);
	}
	if((SeekStatusold_B==1)&&(SeekFreqStruct_CHB.flag.SeekOK==0))
	{
	  DBG("--------ChannelB Start Seek!--------\n");
	  SeekTimerCnt_CHB = 0;    // 搜台计时计数器清零
	}
	else if((SeekStatusold_B==0)&&(SeekFreqStruct_CHB.flag.SeekOK==1))
	{
	  DBG("-----------ChannelB Seek OK!----------\n");
	  DBG("Seek ChannelB:Count=%d\tTim=%6.2fs!\t",SeekFreqStruct_CHB.SeekFreqIndex,(float)SeekTimerCnt_CHB*0.005);
	}
	SeekStatusold_A = SeekFreqStruct_CHA.flag.SeekOK;
	SeekStatusold_B = SeekFreqStruct_CHB.flag.SeekOK;

    if(SeekFreqStruct_CHA.flag.SaveData)
    {
        ;// 此处添加保存到Flash操作
#ifdef	SAVE_FLASH
		FlashData.SeekData_A.CurrentVolume          = SeekFreqStruct_CHA.CurrentVolume;
		FlashData.SeekData_A.LastSeekFreqOKIndex    = SeekFreqStruct_CHA.LastSeekFreqOKIndex;
		FlashData.SeekData_A.PrivateID              = SeekFreqStruct_CHA.PrivateID;
		if(SaveDataToFlash(&FlashData))
		{
			DBG("Save Data A Success\n");
		}
		else
		{
			DBG("Save Data A fail\n");
		}
#endif
    	SeekFreqStruct_CHA.flag.SaveData = 0;
    }
    if(SeekFreqStruct_CHB.flag.SaveData)
    {
    	;// 此处添加保存到Flash操作
#ifdef	SAVE_FLASH
		FlashData.SeekData_B.CurrentVolume          = SeekFreqStruct_CHB.CurrentVolume;
		FlashData.SeekData_B.LastSeekFreqOKIndex    = SeekFreqStruct_CHB.LastSeekFreqOKIndex;
		FlashData.SeekData_B.PrivateID              = SeekFreqStruct_CHB.PrivateID;
		if(SaveDataToFlash(&FlashData))
		{
			DBG("Save Data B Success\n");
		}
		else
		{
			DBG("Save Data B fail\n");
		}
#endif
    	SeekFreqStruct_CHB.flag.SaveData = 0;
    }

#ifdef	BPSKEffect
    static uint8_t FunctionEffect_CHAold = 0,FunctionEffect_CHBold = 0;
    User_Bpsk_t *BpskData = (User_Bpsk_t *)&KT065x_BpskData;

    if(SeekFreqStruct_CHA.flag.SeekOK)              //
    {
		KT_WirelessMicRx_GetAUXCH(&I2CDef_KT065xM_CHA, &KT065x_BpskData);
		if(FunctionEffect_CHAold != BpskData->FunctionEffect)         // 状态改变
		{
			switch(BpskData->FunctionEffect)
			{
			case 0xE0:
				{
					DSP_Echo_Set(&UserEchoConfig[0]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo0 Enable!\n");
				}break;        // 混响1
			case 0xE1:
				{
					DSP_Echo_Set(&UserEchoConfig[1]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo1 Enable!\n");
				}break;        // 混响2
			case 0xE2:
				{
					DSP_Echo_Set(&UserEchoConfig[2]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo2 Enable!\n");
				}break;        // 混响3
			default:
				{
					DSP_Echo_Ctrl(Disable);
					DBG("Echo Disable!\n");
				}break;
			}
		}
		FunctionEffect_CHAold = BpskData->FunctionEffect;     // 保存状态
    }

    if((SeekFreqStruct_CHB.flag.SeekOK)&&(SeekFreqStruct_CHA.flag.SeekOK==0))
    {
    	KT_WirelessMicRx_GetAUXCH(&I2CDef_KT065xM_CHB, &KT065x_BpskData);
		if(FunctionEffect_CHBold != BpskData->FunctionEffect)         // 状态改变
		{
			switch(BpskData->FunctionEffect)
			{
			case 0xE0:
				{
					DSP_Echo_Set(&UserEchoConfig[0]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo0 Enable!\n");
				}break;        // 混响1
			case 0xE1:
				{
					DSP_Echo_Set(&UserEchoConfig[1]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo1 Enable!\n");
				}break;        // 混响2
			case 0xE2:
				{
					DSP_Echo_Set(&UserEchoConfig[2]);
					DSP_Echo_Ctrl(Enable);
					DBG("Echo2 Enable!\n");
				}break;        // 混响3
			default:
				{
					DSP_Echo_Ctrl(Disable);
					DBG("Echo Disable!\n");
				}break;
			}
		}
		FunctionEffect_CHBold = BpskData->FunctionEffect;     // 保存状态
    }
#endif

}

void UserTask_500ms (void)
{
//	DBG("CHA State = %d\t", SeekFreqStruct_CHA.State);
//	DBG("CHA Freq = %ld\t", SeekFreqStruct_CHA.CurrentChannelFreq);
//	DBG("CHA flag = 0x%04x\n", SeekFreqStruct_CHA.flag);
//
//
//	DBG("CHB State = %d\t", SeekFreqStruct_CHB.State);
//	DBG("CHB Freq = %ld\t", SeekFreqStruct_CHB.CurrentChannelFreq);
//	DBG("CHB flag = 0x%04x\n", SeekFreqStruct_CHB.flag);

	/************  Seek LED TASK  **********/
	if(!SeekFreqStruct_CHA.flag.SeekOK)
	{
		api_gpio_toggle(SeekCHALEDPin);
	}
	else
	{
		api_gpio_func_set(SeekCHALEDPin, API_GPIO_Output1); //
	}
	if(!SeekFreqStruct_CHB.flag.SeekOK)
	{
		api_gpio_toggle(SeekCHBLEDPin);
	}
	else
	{
		api_gpio_func_set(SeekCHBLEDPin, API_GPIO_Output1);
	}
}


void Key_Task(void)
{
	if(SysTickStruct.KeyVal==1)          // 按键短按下
	{
		;
		DBG("Key = 1!\n");
	}
	else if(SysTickStruct.KeyVal==101)  // 按键长按下
	{
		;
		DBG("Key = 101!\n");
	}
}

void Rx_Response(void)       //串口接收到数据
{

#ifdef 	dbg    // 串口打印
	;    // 以下代码均为测试代码  for test
	if((SysTickStruct.Rxbuf[0]=='s')&&(SysTickStruct.Rxbuf[1]=='a')&&(SysTickStruct.Rxbuf[2]=='v')&&(SysTickStruct.Rxbuf[3]=='e'))  // save
	{
		FlashData.RFU0++;
		FlashData.SeekData_A.PrivateID++;
		SaveDataToFlash(&FlashData);
	}
	else if((SysTickStruct.Rxbuf[0]=='e')&&(SysTickStruct.Rxbuf[1]=='r')&&(SysTickStruct.Rxbuf[2]=='a')&&(SysTickStruct.Rxbuf[3]=='s'))  // Erase
	{
		GLOBAL_INT_STOP();
		api_flash_sector_erase(0x24000, 0x4000);	// 擦除16k空间大小
		GLOBAL_INT_START();
	}
	else if((SysTickStruct.Rxbuf[0]=='r')&&(SysTickStruct.Rxbuf[1]=='e')&&(SysTickStruct.Rxbuf[2]=='a')&&(SysTickStruct.Rxbuf[3]=='d'))  // read
	{
		ReadDataFromFlash();
	}
	else if((SysTickStruct.Rxbuf[0]=='p')&&(SysTickStruct.Rxbuf[1]=='o')&&(SysTickStruct.Rxbuf[2]=='p')&&(SysTickStruct.Rxbuf[3]=='w'))  // pop www.
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[3], 8);        // 'backspace'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[21], 8);       // 'win'+'r'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[22], 8);       // 'w'+'w'+'w'+'.'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[23], 8);       // 'k'+'t'+'m'+'i'+'c'+'r'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[24], 8);       // 'o'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[25], 8);       // '.'+'c'+'o'+'m'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[26], 8);       // '.'+'c'+'n'
		api_keyboard_continue_send((uint8_t *)DemoWebStr[1], 8);        // 'Enter'
	}
	else if((SysTickStruct.Rxbuf[0]=='f')&&(SysTickStruct.Rxbuf[1]=='5'))//f5
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[10], 8);        // 'f5'
	}
	else if((SysTickStruct.Rxbuf[0]=='e')&&(SysTickStruct.Rxbuf[1]=='s')&&(SysTickStruct.Rxbuf[2]=='c'))  // esc
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[2], 8);        // 'esc'
	}
	else if((SysTickStruct.Rxbuf[0]=='n')&&(SysTickStruct.Rxbuf[1]=='e')&&(SysTickStruct.Rxbuf[2]=='x')&&(SysTickStruct.Rxbuf[3]=='t'))  // -->
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[14], 8);        // '-->'
	}
	else if((SysTickStruct.Rxbuf[0]=='p')&&(SysTickStruct.Rxbuf[1]=='r')&&(SysTickStruct.Rxbuf[2]=='e')&&(SysTickStruct.Rxbuf[3]=='v'))  // <--
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[13], 8);        // '<--'
	}
	else if((SysTickStruct.Rxbuf[0]=='t')&&(SysTickStruct.Rxbuf[1]=='a')&&(SysTickStruct.Rxbuf[2]=='b'))  // Alt+Tab
	{
		api_keyboard_continue_send((uint8_t *)DemoWebStr[29], 8);        // Alt+Tab
	}

#endif
	DBG("%s\n",SysTickStruct.Rxbuf);
}


