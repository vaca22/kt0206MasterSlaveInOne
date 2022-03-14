#ifndef __KT065X_SEEKFREQ_h__
#define __KT065X_SEEKFREQ_h__

#include "soft_i2c.h"

#define PACKED __attribute__((packed))

//#define UserRandomSeek      // 用户自定义搜台序列

#define 	BpskEn               // 搜台使用Bpsk
#define     KT0656M_I2SEn        // KT0656M通过I2s输出音频

typedef enum
{
	VendorID           			= 0x88,         // 出厂默认ID
	ChangePrivateID 			= 0xe0,			// 改变ID
	ChangeCurrentChannelID  	= 0xe1,         // 换台
	DisConnectID			   	= 0xe2,         // 断开连接
}FunctionID_enum_t;

typedef struct
{
	uint16_t	PrivateID ;          // Bpsk_Data_A, 私人ID
	union{
		struct
		{
			FunctionID_enum_t 	FunctionID  :8;         // Bpsk_Data_B_H
			uint8_t 			FreqIndexID	:8;         // Bpsk_Data_B_L
		}PACKED;
		uint16_t	Bpsk_Data_B;     // Bpsk_Data_B
	}PACKED;
	union{
		struct
		{
			uint16_t 		Volume			:8;         // Bpsk_Data_C
			uint16_t 		FunctionEffect 	:8;         // Bpsk_Data_C
		}PACKED;
		uint16_t	Bpsk_Data_C;        // Bpsk_Data_C
	}PACKED;
	uint16_t	FactoryID;        // Bpsk_Data_D, 出厂ID
}User_Bpsk_t;            // 用户bpsk定义

typedef enum
{
	StartSeek 	= 0,           // 搜台初始状态
	ReadRssi,                  // 1
	ReadSNR,                   // 2
	ReadPilot,                 // 3
	ReadBpskSync,              // 4
	ReadBpskData,              // 5
	VerifyFreq,                // 6
} PACKED KT065x_SeekState_enum_t;


typedef struct
{
	KT065x_SeekState_enum_t 	State;                	    // 用于指示搜台的几个状态
	uint8_t 					Tick5msCnt;           		// 搜台5ms系统节拍
	uint8_t                     ReadTimerCounter;     		// 用于指示在当前SeekState状态下读了多少次(用于计数读Rssi,pilot,BpskData等多少次, 累计到一定次数退出)
	uint8_t                     CurrentChannelRssi;         // 当前台Rssi值

	uint8_t                     CurrentChannelSNR;          // 当前台SNR值(保留，未用)
	uint8_t						ReadRssiFailCnt;     		// 指示当前搜台读取Rssi值小于SeekRssiThresholdLow门限当前次数
	uint8_t						ReadBpskSyncFailCnt;  		// 指示当前搜台读取Bpsk数据失败的当前次数
	uint8_t                     SeekLookBackCnt;            // 用于计数, 收5个台后往回跳之前的台看是否还在，用于断点附近快速恢复

	uint8_t                     CurrentSeekFreqIndex;       // 暂时保存搜台索引号
	uint8_t                     SeekFreqIndex;              // 当前搜台索引号
	uint8_t                     LastSeekFreqOKIndex;        // 上一次搜台OK索引号
	uint8_t  					CurrentVolume;				// 当前音量值关机保存,未用

//	uint8_t                     SaveDataAddrIndex;          // 保存用户数据到Flash索引地址（目前是非关机保存，如果可以正常关机，可以借用用户寄存器实现关机保存）
    uint8_t                     SmoothVol;                  // 为平滑调音量中间值

	uint16_t					PrivateID;                  // 私人ID码（唯一）
	struct
	{
		uint16_t         BpskSync		:1;       // BPSK 同步OK
		uint16_t		 SeekOK			:1;       // 对上台
		uint16_t         LoadDataOK  	:1;       // 开机读取保存用户数据OK
     	uint16_t         SaveData  	    :1;       // 需要保存用户数据标记（目前是非关机保存，KT0323不支持无断声檫除Flash，需要通过其他方式避免）�⣩

     	uint16_t		 ChangePrivateIDDis	:1;   // 开机一定时间内允许改变ID,超时禁止操作
		uint16_t         FastTuneOK		:1;       // 用于标记快速Tune台状态，跳过延时等待
		uint16_t         VolumeSmooth	:1;       // 用于音量渐出标记
		uint16_t         ChannelNum     :1;       // 用于标记当前处于CHA还是CHB

		uint16_t         Err			:3;       // 错误标示
		uint16_t         RFU			:5;       // 保留
	}flag;

	uint32_t 					CurrentChannelFreq;         // 当前台频率关机保存
}KT056x_SeekFreqStatus_t;


typedef struct
{
#ifndef  UserRandomSeek                        // 用户随机搜台
	uint32_t    StartFreq[2];                  // 起始频率
	uint16_t 	SeekFreqStep[2];               // 步进
	uint32_t 	EndFreq[2];                    // 截至频率
#else
	const uint32_t  *UserRandomFreqIndexHead[2];       // 用户自定义随机搜台表
	uint8_t 		UserRandomFreqIndexNum[2];         // 用户自定义随机搜台个数
#endif

	uint16_t 	FactoryID;	     			// 出厂ID码,未用，保留

	uint8_t 	SeekRssiThresholdHigh;	    // 搜台时RSSI高门限（收到台时进入门限）
	uint8_t 	SeekRssiThresholdLow;	    // 搜台时RSSI低门限（当前台消失退出门限）
	uint8_t     ChangeIDRssiThreshold;      // 用户重新对台时需要的RSSI门限,一般要求用户走近接收机才可对台，需要的RSSI门限较大

	uint8_t     ReadRssiMaxCnt;             // 读取RSSI最大次数，如果连续读Rssi值MaxCnt次都小于SeekRssiThresholdHigh门限，则Seek下一个台�̨
	uint8_t     ReadPilotMaxCnt;            // 读Pilot最大次数，如果连续读Polit值MaxCnt次都未检测到导频，则Seek下一个台
    uint8_t     ReadBpskSyncMaxCnt;         // 读Bpsk同步标志最大次数
    uint8_t     ReadBpskDataMaxCnt;         // 读Bpsk数据最大次数

    uint8_t     ReadRssiFailMaxCnt;         // 读取RSSI失败最大次数，如果连续读Rssi值MaxCnt次都小于SeekRssiThresholdLow门限，则Seek下一个台һ��̨
	uint8_t     ReadBpskSyncFailMaxCnt;     // 读Bpsk同步标志失败最大次数
}KT056x_SeekFreqConfig_t;

void SeekFreqDataLoad(KT056x_SeekFreqStatus_t *SeekStatus);         // 初始化结构体
void SeekFreqDataSave(KT056x_SeekFreqStatus_t *SeekStatus);         // 保存
//void KT056x_SeekFreqInit(const SoftI2C_t *I2CDef, KT056x_SeekStatutus);
void KT056x_SeekFreq(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus);
uint8_t CheckBpskData(const SoftI2C_t *I2CDef, KT056x_SeekFreqStatus_t *SeekStatus);

#endif
