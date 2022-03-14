/*********************************************************************
* 版权所有 (C)
* 系统名称: 
* 文件名称: 
* 内容摘要: 常量定义
* 当前版本: V2.B0
* 作    者:
* 设计日期: 
* 修改记录: 
* 日    期			版    本		修改人 		修改摘要 
**********************************************************************/

#ifndef ECLD_CONST_H
#define ECLD_CONST_H


//#define VED_EC_MIN(a,b)	((a)>(b)?(b):(a))
//#define	VED_EC_MAX(a,b)    ((a)<(b)?(b):(a))

#define		ECLD_L_256MS        48 //48
#define		ECLD_L_128MS        24 //48
#define		ECLD_L_64MS         12 //24
#define     ECLD_LENGTH_EXP     4  //5
#define		ECLD_r              253741824//16384

#define		ECLD_NLP_min        3  //1
#define		ECLD_NLP_max        10

#define		ECLD_GRD            2767

#define		ECLD_SIZE		    128 //32
#define		ECLD_SIZE_BY_TWO    64  //16
#define		ECLD_NUM_STAGE	    6   //4
#define		ECLD_Ana_len_M      192 //256
#define		ECLD_Syn_len_M      192 //320
#define		ECLD_Dec			40  //20  //抽取倍数
#define		ECLD_M	    	    64  //32
#define		ECLD_M_BY_TWO	    32  //16

#define		ECLD_Ana_len         3   //8

#define		FRAMELENGTH         135

#define		ECLD_ABLOCK          32//31  //15
#define		ECLD_CNG_neg         -100 //-100
      
#define		ECLD_DTD_speed_ful   0x2c00
//#define		DTD_level            5000

#define     ECLD_PRE_EMP_FAC     -0//-26214	/* -0.8 scaled as 0,15 */
#define     ECLD_DE_EMP_FAC      0//26214	

#define		ECLD_M_16K	    	 128  
#define     ECLD_M_BY_TWO_16K    64
#define		ECLD_Ana_len_M_16K   384 
#define		ECLD_Syn_len_M_16K   384 
#define     ECLD_FRAME_LEN_16K	 160
#define		ECLD_ABLOCK_16K      64
#define     ECLD_SIZE_16K        256
#define     ECLD_SIZE_BY_TWO_16K 128
#define     ECLD_NUM_STAGE_16K   7
#define     ECLD_Dec_16K         80

#define     ECLD_SUBBAND_NUMBER  2
  

/*------------------------------------------------*/

/* 噪声抑制处理部分 */
#define WVQE_PRE_EMP_FAC              -866019132	/* -0.8 scaled as 0,15 */
#define WVQE_DE_EMP_FAC                866019132
#define WVQE_SNR_SHIFT                 8
#define WVQE_EXPIN_SHIFT               11
#define WVQE_NOISE_SHIFT               7
#define WVQE_MAX_PS_LEN                256
#define WVQE_MAX_ADD_LEN_IN_FFT        96
#define WVQE_NB_BANDS                  24  /* 频域子带数 */
#define WVQE_BASIC_FRAME_LEN           80   
#define WVQE_BASIC_PS_LEN              64
#define WVQE_FFT_HEADROOM              6
#define WVQE_IFFT_HEADROOM             8
#define WVQE_NR_FRAME_COUNT            1

#define NOISE_GATE_FRAME_COUNT         500

#define	VED_NR_SIZE			          (128)

#endif

