/*
 * KT0203_Drv.h
 *
 *  Created on: Jul 9, 2019
 *      Author: lisy
 */

#ifndef __KT0203_DRV_H__
#define __KT0203_DRV_H__

#include "reg.dsp.h"
#include "api.h"

#define PACKED __attribute__((packed))

typedef union {
	uint8_t		uint8[4];
	int8_t		int8[4];
	uint16_t	uint16[2];
	int16_t		int16[2];
	uint32_t 	uint32;
	int32_t		int32;
}split32_t;



//-----����
typedef union DSP_Reverb_Para_union {
	uint32_t	all32[3];
	struct {
		uint32_t    RFU0         	: 2;
		uint32_t	Spread          : 6;	//扩散

		uint32_t	RoomSize        : 8;	//空间大小

		uint32_t	Time         	: 8;	//延时

		uint32_t	Damping         : 5;	//阻尼
		uint32_t    RFU1            : 3;


		uint32_t	DryLevel	    : 7;	//干声比例, Reverb/Echo共用
		uint32_t	RFU2			: 1;

		uint32_t    ReverbLevel     : 7;	//湿音比例
		uint32_t    RFU3			: 1;

		uint32_t	EarlyLevel      : 8;	//前期反射

		uint32_t	TailLevel       : 8;	//后期反射


		uint32_t	LPF_BW			: 5;	//低通带宽
		uint32_t	RFU4			: 2;
		uint32_t    LPF_En          : 1;	//低通使能

		uint32_t	HPF_BW		    : 5;	//高通带宽
		uint32_t	RFU5			: 2;
		uint32_t    HPF_En          : 1;	//高通使能

		uint32_t    PreDelay        : 6;	//预延时(混响/Echo共用)
		uint32_t	RFU6			: 10;
	};
}DSP_Reverb_Para_t;

//----啸叫抑制
typedef struct DSP_HowlingCtrl_Para_struct {
	union {
		uint8_t para0;
		struct {
			uint8_t supress_en		: 1;	//总开关
			uint8_t detect_en		: 1;	//检测开关
			uint8_t notch_en		: 1;	//陷波器开关
			uint8_t avc_en			: 1;	//压音量开关
			uint8_t RFU0			: 1;
			uint8_t study_save		: 1;	//学习保存
			uint8_t RFU1			: 2;
		} PACKED;
	} PACKED;
	uint8_t eeprom_save_cycle;	//save_time = (1 + save_cycle) * 500ms
}DSP_HowlingCtrl_Para_t;

typedef union DSP_Howling_Detect_Para_union {
	struct {

		uint32_t det_diff_varTH				: 4; //howling det th -
		uint32_t det_peak_varTH				: 4; //howling det th -
		uint32_t det_peak_winT				: 6; //
		uint32_t det_fornotch_nth			: 4; //howling det time ctrl for notch
		uint32_t det_fornotch_fth			: 4; //howling det th for notch -
		uint32_t RFU0	: 10;
	};
	uint32_t	all32;
}DSP_Howling_Detect_Para_t;

typedef union DSP_HowlingNotch_Para_union {
	uint32_t	all32[2];
	uint16_t	all16[4];
	struct {
		uint8_t Hold 		: 3;	//�����ͬХ�е�������, ��Ҫ�ȴ�һ��ʱ���ٴ�����
		uint8_t Life 		: 5;	//�ݲ����������
		uint8_t DownStep 	: 4;	//Х�е��ٴ����ٺ�, �ݲ������ӵ����(x+1)dB
		uint8_t UpStep		: 4;	//�ݲ����������, ÿ����up_time, ��С�����(x+1)dB
		uint8_t UpTime;				//�ݲ�����������, ���µ�����
		uint8_t InitialGain	: 4;	//�ݲ���������ʼ���(-xxdB)
		uint8_t MaxDeep		: 4;	//�ݲ���������(-xxdB)

		uint8_t df;					//�����ݲ���֮����СƵ���ֵ(x+1)Hz
		uint8_t q;					//�ݲ���qֵ

		uint8_t nFixed		: 6;	//�̶��ݲ����ĸ���(ע��Ҫ < n_total)
		uint8_t RFU0		: 2;
		uint8_t nTotal		: 6;	//�������ݲ����ܸ���
		uint8_t RFU1		: 2;
	};
}DSP_HowlingNotch_Para_t;

typedef union DSP_Howling_Avc_Para_union {
	struct {
		uint32_t after_notchN		: 5;	//gain down en time
		uint32_t gain_set			: 5;	//gain set
		uint32_t short_winT			: 6;	//howling det time ctrl for gain up/down
		uint32_t releaseTim			: 4;	//release time
		uint32_t save_volume_en		: 1;
		uint32_t short_win_shift	: 3;
		uint32_t step_down			: 4;
		uint32_t step_up			: 4;
	};
	uint32_t	all32;
}DSP_Howling_Avc_Para_t;


//-----EQ

typedef enum DSP_EQ_Band_enum {
	EQ_PTMIC_Band0,
	EQ_PTMIC_Band1,
	EQ_PTMIC_Band2,
	EQ_PTMIC_Band3,
	EQ_PTMIC_Band4,
	EQ_PTMIC_Band5,
	EQ_PTMIC_Band6,
	EQ_PTMIC_Band7,
	EQ_PTMIC_Band8,
	EQ_PTMIC_Band9,
	EQ_PTMIC_Band10,
	EQ_PTMIC_Band11,
	EQ_PTMIC_Band12,
	EQ_PTMIC_Band13,
	EQ_PTMIC_Band14,
	EQ_Band_Max,
}DSP_EQ_Band_t;

typedef enum DSP_EQType_enum {
	EQ_PeakNotch	= 0,
	EQ_LowPass		= 1,
	EQ_HighPass		= 2,
	EQ_LowShelf		= 3,
	EQ_HighShelf	= 4,
}DSP_EQType_t;

typedef union DSP_EQ_Para_enum {
	uint64_t	all64;
	uint32_t	all32[2];
	struct {
		uint16_t 		Qval;			//Q值/0.001
		uint16_t 		F0;				//1Hz
		uint16_t 		Gain;			//增益 0.1dB
		DSP_EQType_t 	Type	: 3;	//类型
		uint8_t  		RFU0	: 5;
		uint8_t  		Enable	: 1;	//开关
		DSP_EQ_Band_t  	Band	: 7;	//Band节点
	};
}DSP_EQ_Para_t;

typedef union DSP_Echo_Para_union {
	struct {
		uint32_t	RFU0		: 1;
		uint32_t	MaxDelay	: 7;	//最大延时

		uint32_t	Delay		: 7;	//延时  Delay <= MaxDelay
		uint32_t	RFU1		: 1;

		uint32_t	LoopRatio   : 7;	//深度
		uint32_t	RFU2        : 1;

		uint32_t	WetRatio    : 7;	//比例
		uint32_t	RFU3		: 1;
	};
	uint32_t		all32;
	uint8_t			all8[4];
}DSP_Echo_Para_t;



//-----混响
void DSP_Reverb_Set(const DSP_Reverb_Para_t * pPara) ;
void DSP_Reverb_Ctrl(FunctionState_t en);

//设置混响湿音比例
void DSP_Reverb_Level(uint8_t u7level);



//啸叫抑制
void DSP_Howling_Ctrl(const DSP_HowlingCtrl_Para_t * pPara);

//啸叫抑制关闭请求
void DSP_Howling_ClearReq(void);

//啸叫检测
void DSP_Howling_Detect(const DSP_Howling_Detect_Para_t * pPara);

//啸叫压音量
void DSP_Howling_Avc(const DSP_Howling_Avc_Para_t * pPara);

//啸叫陷波器配置
void DSP_Howling_Notch(const DSP_HowlingNotch_Para_t * pPara);


//获取陷波器状态, 32-bit 1bit
uint32_t DSP_Howling_NotchGet(void);

//获取固定陷波器
uint32_t DSP_Howling_NotchFixedGet(void);


//EQ设置
void DSP_EQ_Set(const DSP_EQ_Para_t * pPara);

//EQ开关
void DSP_EQ_Ctrl(DSP_EQ_Band_t BandX, FunctionState_t en);

//Echo设置
void DSP_Echo_Set(const DSP_Echo_Para_t * pPara);

//Echo开关
void DSP_Echo_Ctrl(FunctionState_t en);


#endif /* KT0203_DRV_H_ */
