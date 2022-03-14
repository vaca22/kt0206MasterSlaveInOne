/**********************************************************************************************
* 版权所有                                              *
* 系统名称：宽带拓展回声抵消及VQE 模块〈V1.0〉                                                *
* 文件名称：ecld_alg.h                                                                        *
* 文件标识：                                                                                  *
* 内容摘要：头文件，包含全局的宏定义，结构体类型，主函数接口声明。              *
* 其它说明：                                                                                  *
* 当前版本：2.B0                                                                              *
* 原始作者：                                                     *
* 完成日期： 2016年9月                                                                     *
* 修改记录：                                                                                  *
***********************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef      __AEC_ALG_H__
#define      __AEC_ALG_H__

#include "comm.h"
#include "ecld_structs.h"
//采样率宏定义
#define  AEC_SAMPLINGRATE_8K       0    //support 8k sampling-rate
#define  AEC_SAMPLINGRATE_16K      1    //support 16k sampling-rate

//回声尾长（滤波器长度）定义
#define  AEC_IAEC_TAIL64ms        16   /* Maximum echo delay path of 64 ms  */
#define  AEC_IAEC_TAIL128ms       32   /* Maximum echo delay path of 128 ms */
#define  AEC_IAEC_TAIL256ms       64   /* Maximum echo delay path of 128 ms */

//#define  ECLD_GLOBST_LEN  	      0x0000C09C //1路算法所需的内存空间
//#define ANS_MODE       1
//#define AEC_MODE       1
//#define ECLD_GLOBST_LEN  (AEC_MODE==0) ? 0x00007530 : 0x0000C09C

#define ECLD_NR_GLOBST_LEN      0x00001540
#define ECLD_AEC_GLOBST_LEN     0x0000AB5C

#ifdef   WIN32                   
#define  ECLD_dllexport   __declspec( dllexport )
#endif
	
#ifndef NULL
#define NULL 0
#endif

//#define CHANNEL 1
//#define   VERSION	       200  // ECLD库版本号

//算法参数结构体封装
typedef struct
{
	void   *pChannelStAddr;             /* 历史数据保存空间 */
    int    wChnSize;	                /* 表示历史数据的长度，初始化时校验用，不通过返回-2 */
    short  wParamSize;   		        /* 存放本结构体的长度，初始化时校验用，不通过返回-2 */	
    short  wAEC_span;                   /* 回声尾长选择，支持3种参数 */
	char   cSamplingRate;               /* 采样率 ，两种采样率选择*/			
	char   cNR_Opt;						/* 噪声抑制开关, 1为开， 0 为关 */	
	char   cAEC_Opt;					/* 回声抵消开关, 1为开， 0 为关 */
}T_ECLD_Param;


//extern char	wHistBuff[CHANNEL][ECLD_GLOBST_LEN];
extern T_ECLD_Param	ECLD_VQE_Param;
extern short   Echo_Len;
extern char    SamplingRate;
extern char    NR_Opt;
extern char    AEC_Opt;

extern T_ECState_Param        *pECstate_Param ; //sizeof(T_ECState_Param)=0xab5c= 43868
extern T_VQEState_Param       *pVQEstate_Param; //sizeof(T_VQEState_Param)=0x1540= 5440



extern UINT32 g_WVQE_MainProcess_;
extern UINT32 g_WVQE_MainProcess_buff_size ;
extern UINT32 g_EC_Proc_buff ;
extern UINT32 g_EC_Proc_buff_size;

extern INT32 dwNoiseSuppress; //噪声抑制比参数，该参数可调，-12表示噪声压制12个DB，建议范围-15到-10
/* 接口函数原型 */
#ifdef WIN32
extern ECLD_dllexport short ECLD_Init( T_ECLD_Param   *io_pParam );



extern ECLD_dllexport short ECLD_Proc( short 		*i_pwRefPCMIn,   	/*(i)  参考信号          */
				                       short 		*i_pwEchoPCMIn,	    /*(i)  需回声抵消的信号  */							
				                       short  	    i_s16InSize,	 	/*(i)  输入缓冲区长度    */					       						                           
									   short 		*o_ps16DstData,
				                       short 		*o_ps16OutSize, 	/*(o)  输出缓冲区长度    */
									   T_ECLD_Param    *io_pParam       /*(i/o)  EC参数结构体地址 */					                            
				                     );

extern ECLD_dllexport short ECLD_GetVer(void);

#else

extern short ECLD_Init( T_ECLD_Param   *io_pParam ,void* wHistBuff,char SamplingRate,short Echo_Len,char NR_Opt,char AEC_Opt);


extern short ECLD_Proc( short 		*i_pwRefPCMIn,   	/*(i)  参考信号          */
				        short 		*i_pwEchoPCMIn,	    /*(i)  需回声抵消的信号  */							
				        short  	    i_s16InSize,	 	/*(i)  输入缓冲区长度    */					       						            
					    short 		*o_ps16DstData,
						T_ECLD_Param    *io_pParam, 	    /*(i/o)  EC参数结构体地址 */
						void          * TempBuff
				      );

extern short ECLD_GetVer(void);


#endif

#endif

#ifdef __cplusplus
}
#endif
