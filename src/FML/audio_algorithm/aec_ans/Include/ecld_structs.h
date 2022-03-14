/*********************************************************************
* 版权所有 (C)
* 系统名称: 
* 文件名称: ecld_structs.h
* 内容摘要: 历史变量封装
* 当前版本: V2.B0
* 作    者: 
* 设计日期: 
* 修改记录: 
* 日    期			版    本		修改人 		修改摘要  
**********************************************************************/

#include "../Include/ecld_typedefs.h"
#include "../Include/ecld_const.h"
#include "../Include/ecld_const_table.h"

#ifndef ECLD_STRUCTS_H
#define ECLD_STRUCTS_H

//回声消除模块历史变量
typedef struct 
{
	Word16   dVED_EC_u[ECLD_M_16K*ECLD_L_256MS];
	Word16   dVED_EC_h[ECLD_M_16K*ECLD_L_256MS];
	Word16	 dVED_EC_h_main[ECLD_M_16K*ECLD_L_256MS];   
	
	Word16   dRef_buffer[ECLD_Ana_len*ECLD_M_16K];
	Word16   dEcho_buffer[ECLD_Ana_len*ECLD_M_16K];
	Word16   dEx_buffer[ECLD_Ana_len*ECLD_M_16K];

	Word32   dVED_EC_upower[ECLD_M_BY_TWO_16K];
	Word32   dVED_EC_upower_dtd[ECLD_M_BY_TWO_16K];
	Word32   dVED_EC_sed[ECLD_M_BY_TWO_16K];
	Word32   dVED_EC_syy[ECLD_M_BY_TWO_16K];

	Word32   dVED_EC_ped0_dtd[ECLD_M_BY_TWO_16K];					   
	Word32   dVED_EC_pyy_dtd[ECLD_M_BY_TWO_16K];
    Word32   dVED_EC_ped1_dtd[ECLD_M_BY_TWO_16K];					   
	Word32   dVED_EC_ped2_dtd[ECLD_M_BY_TWO_16K];
    Word32   dVED_EC_pdd_dtd[ECLD_M_BY_TWO_16K]; //近端的自相关函数
	
	Word32	 EC_dT_vad[2];
	Word32	 EC_dN_FB_mean_vad_tempt[128]; 
	Word32	 EC_dN_FB_mean_vad1[128];       
	Word32	 EC_dS[128]; 
	Word32	 EC_dNoiseRms[128];

	Word16   dCNG_flag_pow[6];
	Word16	 EC_dSpeechFlag[6];   
	Word16   EC_S_sRandNumIndex[2];               //随机数索引
    Word16   EC_S_sRandNumbers[5];                //5个随机数,用于产生随机相位,舒适噪声用
	Word32   EC_m_aNoiseLevel[ECLD_M_BY_TWO_16K]; //噪声电平,舒适噪声用

	Word16	 EC_dtempt_i;              //跟踪语音的循环计数器,每100帧清0,然后重新计数
	Word16	 EC_dNIS;                 //帧计数器, 大于10000帧以后不再更新
	Word16   EC_dpre_emp_mem_Ref;     //远端参考信号加重滤波器历史数据
	Word16   EC_dpre_emp_mem_Echo;   //回声信号加重滤波器历史数据
	Word16   EC_dde_emp_mem_Echo;   //去加重滤波器历史数据

	Word16   EC_NO_SpeechFlag;     //无语音计数器,用于舒适噪声跟踪

	Word32   EC_SumPowerAfterNLP;  //经过非线性处理后的残余能量和

	char     EC_unused[28];	  //保留字段

} T_ECState_Param;    

/*------------------------------------------------*/


/* 噪声抑制模块历史变量 */
typedef struct tag_DMICVQE_State
{
	Word32  adwMidMinPower[WVQE_MAX_PS_LEN];       /* 1024 更小段时间内的最小能量值 */
	Word32  adwMinPower[WVQE_MAX_PS_LEN];          /* 1024 一段时间内的最小能量值 */
	Word32  adwSmoothSpectumPower[WVQE_MAX_PS_LEN];/* 1024 平滑后的谱能量 */
	Word32  adwNoise[WVQE_MAX_PS_LEN];             /* 1024 16k原始定义是320+NB_BANDS*/  
	Word32  awPreFrameInBuf[WVQE_MAX_ADD_LEN_IN_FFT];      /* 192 16k原始定义是320，32k是320*2*/
	Word32  awPreFrameOutBuf[WVQE_MAX_ADD_LEN_IN_FFT * 2]; /* 192 16k原始定义是320，32k是320*2*/
	Word32  adwOldSpectrumPower[WVQE_NB_BANDS];            /* 96 */
	Word16  awZeta[WVQE_NB_BANDS];                 /* 48 */
	
	Word32  dwMinCount;               /* 用于收敛速度控制，当其 > min_rang时 清零 */
	Word32  wPreEmpMem;               /* 主要用于预加重处理,记录前一帧的最后一个数据 */
	Word32  wDeEmpMem;                /* 主要用于去加重处理,记录前一帧的最后一个数据 */
	Word16  wAdapt;                   /* 主要用于计算beta值和控制收敛速度 */  
	Word16  wPreNormShift;

	char     EC_unused[32];	//保留字段

}T_VQEState_Param;

#endif
