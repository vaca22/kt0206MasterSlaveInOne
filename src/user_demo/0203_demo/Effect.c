/*
 * Effect.c
 *
 *  Created on: Nov 7, 2019
 *      Author: lisy
 */

#include "Effect.h"
#include "KT0203_Drv.h"

const DSP_Echo_Para_t UserEchoConfig[3] =
{
	{
		.MaxDelay   = 30,          // Delay<=MaxDelay
		.Delay		= 18,	//延时
		.LoopRatio  = 110,	//深度
		.WetRatio   = 103,	//比例
	},
	{
		.MaxDelay   = 30,
		.Delay		= 20, 	//延时
		.LoopRatio  = 110,	//深度
		.WetRatio   = 103,	//比例
	},
	{
		.MaxDelay   = 30,
		.Delay		= 22, 	//延时
		.LoopRatio  = 110,	//深度
		.WetRatio   = 103,	//比例
	},
};

const DSP_Reverb_Para_t  UserReverbConfig[3] =
{
	{
		.Spread     = 63,  	//扩散
		.RoomSize   = 180,  //空间大小
		.Time       = 50,  	//时间
		.Damping    = 11,  	//阻尼
		.DryLevel	= 103,  //干音比例
		.ReverbLevel= 80,  	//湿音比例
		.EarlyLevel = 50,  	//前期反射
		.TailLevel  = 70,  	//后期反射
		.LPF_BW		= 31,  	//低通带宽
		.LPF_En     = 1,  	//低通开关
		.HPF_BW		= 16,  	//高通带宽
		.HPF_En     = 1,  	//高通开关
		.PreDelay   = 0,  	//预延时  (与Echo共用)
	},
	{
		.Spread     = 63,  	//扩散
		.RoomSize   = 200,  //空间大小
		.Time       = 80,  	//时间
		.Damping    = 11,  	//阻尼
		.DryLevel	= 103,  //干音比例
		.ReverbLevel= 80,  	//湿音比例
		.EarlyLevel = 60,  	//前期反射
		.TailLevel  = 85,  	//后期反射
		.LPF_BW		= 31,  	//低通带宽
		.LPF_En     = 1,  	//低通开关
		.HPF_BW		= 16,  	//高通带宽
		.HPF_En     = 1,  	//高通开关
		.PreDelay   = 10,  	//预延时  (与Echo共用)
	},
	{
		.Spread     = 63,  	//扩散
		.RoomSize   = 254,  //空间大小
		.Time       = 108,  //时间
		.Damping    = 11,  	//阻尼
		.DryLevel	= 103,  //干音比例
		.ReverbLevel= 80,  	//湿音比例
		.EarlyLevel = 72,  	//前期反射
		.TailLevel  = 128,  //后期反射
		.LPF_BW		= 31,  	//低通带宽
		.LPF_En     = 1,  	//低通开关
		.HPF_BW		= 16,  	//高通带宽
		.HPF_En     = 1,  	//高通开关
		.PreDelay   = 20,  	//预延时  (与Echo共用)
	},
};


const DSP_EQ_Para_t UserEQPara[5][7] =
{
		// Q值 0.001，        //频率1Hz           // 增益0.1db     // 类型
	{	{.Qval = 1200, .F0 = 31,   .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band0},     // UserEQGroup[0][]
		{.Qval = 1200, .F0 = 62,   .Gain = 7*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band1},
		{.Qval = 1200, .F0 = 125,  .Gain = 3*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band2},
		{.Qval = 1200, .F0 = 250,  .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band3},
		{.Qval = 1200, .F0 = 500,  .Gain = 8*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band4},
		{.Qval = 1200, .F0 = 1000, .Gain = 9*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band5},
		{.Qval = 1200, .F0 = 2000, .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band6},
		//
	},

		// Q值 0.001，        //频率1Hz           // 增益0.1db     // 类型
	{	{.Qval = 1200, .F0 = 31,   .Gain = 7*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band0},    // UserEQGroup[1][]
		{.Qval = 1200, .F0 = 62,   .Gain = 9*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band1},
		{.Qval = 1200, .F0 = 125,  .Gain = 4*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band2},
		{.Qval = 1200, .F0 = 250,  .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band3},
		{.Qval = 1200, .F0 = 500,  .Gain = -2*10,.Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band4},
		{.Qval = 1200, .F0 = 1000, .Gain = 1*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band5},
		{.Qval = 1200, .F0 = 2000, .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band6},
		//
	},
		// Q值 0.001，        //频率1Hz           // 增益0.1db     // 类型
	{	{.Qval = 1200, .F0 = 31,   .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band0},    // UserEQGroup[2][]
		{.Qval = 1200, .F0 = 62,   .Gain = 7*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band1},
		{.Qval = 1200, .F0 = 125,  .Gain = 3*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band2},
		{.Qval = 1200, .F0 = 250,  .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band3},
		{.Qval = 1200, .F0 = 500,  .Gain = 8*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band4},
		{.Qval = 1200, .F0 = 1000, .Gain = 9*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band5},
		{.Qval = 1200, .F0 = 2000, .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band6},
		//
	},
		// Q值 0.001，        //频率1Hz           // 增益0.1db     // 类型
	{	{.Qval = 1200, .F0 = 31,   .Gain = 0*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band0},    // UserEQGroup[3][]
		{.Qval = 1200, .F0 = 62,   .Gain = 0*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band1},
		{.Qval = 1200, .F0 = 125,  .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band2},
		{.Qval = 1200, .F0 = 250,  .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band3},
		{.Qval = 1200, .F0 = 500,  .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band4},
		{.Qval = 1200, .F0 = 1000, .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band5},
		{.Qval = 1200, .F0 = 2000, .Gain = 2*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band6},
		//
	},
		// Q值 0.001，        //频率1Hz           // 增益0.1db     // 类型
	{	{.Qval = 1200, .F0 = 31,   .Gain = 3*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band0},    // UserEQGroup[4][]
		{.Qval = 1200, .F0 = 62,   .Gain = 6*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band1},
		{.Qval = 1200, .F0 = 125,  .Gain = 5*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band2},
		{.Qval = 1200, .F0 = 250,  .Gain = 0*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band3},
		{.Qval = 1200, .F0 = 500,  .Gain = 0*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band4},
		{.Qval = 1200, .F0 = 1000, .Gain = 4*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band5},
		{.Qval = 1200, .F0 = 2000, .Gain = 4*10, .Type	= EQ_PeakNotch, .Enable	= 1, .Band	= EQ_PTMIC_Band6},
		//
	},
};


const DSP_Howling_Detect_Para_t		UserHowlingDetectConfig[3] =            // ����3������Х��ģʽ
{
	{
		.det_diff_varTH				= 12, //howling det th -
		.det_peak_varTH				= 12, //howling det th -
		.det_peak_winT				= 3, //                                  检测条件w, 值越大越严格
		.det_fornotch_nth			= 2, //howling det time ctrl for notch   检测条件v, 值越小越严格
		.det_fornotch_fth			= 12, //howling det th for notch -       检测条件d, 值越小越严格
	},
	{
		.det_diff_varTH				= 10, //howling det th -
		.det_peak_varTH				= 10, //howling det th -
		.det_peak_winT				= 4, //                                  检测条件w, 值越大越严格
		.det_fornotch_nth			= 3, //howling det time ctrl for notch   检测条件v, 值越小越严格
		.det_fornotch_fth			= 10, //howling det th for notch -       检测条件d, 值越小越严格
	},
	{
		.det_diff_varTH				= 13, //howling det th -
		.det_peak_varTH				= 14, //howling det th -
		.det_peak_winT				= 2, //                                  检测条件w, 值越大越严格
		.det_fornotch_nth			= 4, //howling det time ctrl for notch   检测条件v, 值越小越严格
		.det_fornotch_fth			= 14, //howling det th for notch -       检测条件d, 值越小越严格
	},
};

const DSP_Howling_Avc_Para_t 	UserHowlingAvcConfig[3] =				// 啸叫压低音量配置
{
	{
		.after_notchN		= 4,	//gain down en time		       第N路陷波器后开始压低音量
		.gain_set			= 3,	//gain set         0:-6dB,1:-8dB,2:-10dB...
		.short_winT			= 2,	//howling det time ctrl for gain up/down  检测周期
		.releaseTim			= 3,	//release time     释放时间
		.save_volume_en		= 1,
		.short_win_shift	= 5,    // 压低音量阈值0~7
		.step_down			= 2,    // 压低音量步进
		.step_up			= 0,	// 释放音量步进
	},
	{
		.after_notchN		= 5,	//gain down en time		       第N路陷波器后开始压低音量
		.gain_set			= 3,	//gain set         0:-6dB,1:-8dB,2:-10dB...
		.short_winT			= 2,	//howling det time ctrl for gain up/down  检测周期
		.releaseTim			= 3,	//release time     释放时间
		.save_volume_en		= 1,
		.short_win_shift	= 5,    // 压低音量阈值0~7
		.step_down			= 2,    // 压低音量步进
		.step_up			= 0,    // 释放音量步进
	},
	{
		.after_notchN		= 3,	//gain down en time		       第N路陷波器后开始压低音量
		.gain_set			= 4,	//gain set         0:-6dB,1:-8dB,2:-10dB...
		.short_winT			= 1,	//howling det time ctrl for gain up/down  检测周期
		.releaseTim			= 3,	//release time     释放时间
		.save_volume_en		= 1,
		.short_win_shift	= 6,    // 压低音量阈值0~7
		.step_down			= 2,    // 压低音量步进
		.step_up			= 0,    // 释放音量步进
	},
};

const DSP_HowlingNotch_Para_t		UserHowlingNotchConfig[3] =			// 陷波器配置
{
	{
		.Hold 		= 1,  //如果相同啸叫点持续出现, 需要等待一定时间再次抑制
		.Life 		= 5,  //陷波器生成周期
		.DownStep 	= 2,  //啸叫点再次来临后, 陷波器增加的深度(x+1)dB
		.UpStep		= 0,  //陷波器生存期满, 每经过up_time, 减小的深度(x+1)dB
		.UpTime 	= 0,  //陷波器生存期满后, 更新的周期
		.InitialGain= 1,  //陷波器开启初始深度(-xxdB)
		.MaxDeep	= 2,  //陷波器最大深度(-xxdB)

		.df 		= 65, //两个陷波器之间最小频点差值(x+1)Hz
		.q  		= 20, //陷波器q值

		.nFixed		= 3,  //固定陷波器的个数(注意要 < n_total)
		.nTotal		= 6,  //开启的陷波器总个数
	},
	{
		.Hold 		= 1,  //如果相同啸叫点持续出现, 需要等待一定时间再次抑制
		.Life 		= 5,  //陷波器生成周期
		.DownStep 	= 2,  //啸叫点再次来临后, 陷波器增加的深度(x+1)dB
		.UpStep		= 0,  //陷波器生存期满, 每经过up_time, 减小的深度(x+1)dB
		.UpTime 	= 0,  //陷波器生存期满后, 更新的周期
		.InitialGain= 1,  //陷波器开启初始深度(-xxdB)
		.MaxDeep	= 2,  //陷波器最大深度(-xxdB)

		.df 		= 90, //两个陷波器之间最小频点差值(x+1)Hz
		.q  		= 20, //陷波器q值

		.nFixed		= 3,  //固定陷波器的个数(注意要 < n_total)
		.nTotal		= 6,  //开启的陷波器总个数
	},
	{
		.Hold 		= 1,  //如果相同啸叫点持续出现, 需要等待一定时间再次抑制
		.Life 		= 5,  //陷波器生成周期
		.DownStep 	= 2,  //啸叫点再次来临后, 陷波器增加的深度(x+1)dB
		.UpStep		= 0,  //陷波器生存期满, 每经过up_time, 减小的深度(x+1)dB
		.UpTime 	= 0,  //陷波器生存期满后, 更新的周期
		.InitialGain= 1,  //陷波器开启初始深度(-xxdB)
		.MaxDeep	= 2,  //陷波器最大深度(-xxdB)

		.df 		= 50, //两个陷波器之间最小频点差值(x+1)Hz
		.q  		= 20, //陷波器q值

		.nFixed		= 5,  //固定陷波器的个数(注意要 < n_total)
		.nTotal		= 8,  //开启的陷波器总个数
	},
};


const DSP_HowlingCtrl_Para_t 	UserHowlingCtrlEn =
{
	.supress_en		= 1,  //功能总开关
	.detect_en		= 1,  //啸叫检测开关
	.notch_en		= 1,  //陷波器开关
	.avc_en			= 1,  //自动音量控制开关
};

const DSP_HowlingCtrl_Para_t 	UserHowlingCtrlDis =
{
	.supress_en		= 0,  //功能总开关
	.detect_en		= 1,  //啸叫检测开关
	.notch_en		= 1,  //陷波器开关
	.avc_en			= 1,  //自动音量控制开关
};

