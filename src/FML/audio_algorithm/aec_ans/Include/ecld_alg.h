/**********************************************************************************************
* ��Ȩ����                                              *
* ϵͳ���ƣ������չ����������VQE ģ�顴V1.0��                                                *
* �ļ����ƣ�ecld_alg.h                                                                        *
* �ļ���ʶ��                                                                                  *
* ����ժҪ��ͷ�ļ�������ȫ�ֵĺ궨�壬�ṹ�����ͣ��������ӿ�������              *
* ����˵����                                                                                  *
* ��ǰ�汾��2.B0                                                                              *
* ԭʼ���ߣ�                                                     *
* ������ڣ� 2016��9��                                                                     *
* �޸ļ�¼��                                                                                  *
***********************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef      __AEC_ALG_H__
#define      __AEC_ALG_H__

#include "comm.h"
#include "ecld_structs.h"
//�����ʺ궨��
#define  AEC_SAMPLINGRATE_8K       0    //support 8k sampling-rate
#define  AEC_SAMPLINGRATE_16K      1    //support 16k sampling-rate

//����β�����˲������ȣ�����
#define  AEC_IAEC_TAIL64ms        16   /* Maximum echo delay path of 64 ms  */
#define  AEC_IAEC_TAIL128ms       32   /* Maximum echo delay path of 128 ms */
#define  AEC_IAEC_TAIL256ms       64   /* Maximum echo delay path of 128 ms */

//#define  ECLD_GLOBST_LEN  	      0x0000C09C //1·�㷨������ڴ�ռ�
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
//#define   VERSION	       200  // ECLD��汾��

//�㷨�����ṹ���װ
typedef struct
{
	void   *pChannelStAddr;             /* ��ʷ���ݱ���ռ� */
    int    wChnSize;	                /* ��ʾ��ʷ���ݵĳ��ȣ���ʼ��ʱУ���ã���ͨ������-2 */
    short  wParamSize;   		        /* ��ű��ṹ��ĳ��ȣ���ʼ��ʱУ���ã���ͨ������-2 */	
    short  wAEC_span;                   /* ����β��ѡ��֧��3�ֲ��� */
	char   cSamplingRate;               /* ������ �����ֲ�����ѡ��*/			
	char   cNR_Opt;						/* �������ƿ���, 1Ϊ���� 0 Ϊ�� */	
	char   cAEC_Opt;					/* ������������, 1Ϊ���� 0 Ϊ�� */
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

extern INT32 dwNoiseSuppress; //�������ƱȲ������ò����ɵ���-12��ʾ����ѹ��12��DB�����鷶Χ-15��-10
/* �ӿں���ԭ�� */
#ifdef WIN32
extern ECLD_dllexport short ECLD_Init( T_ECLD_Param   *io_pParam );



extern ECLD_dllexport short ECLD_Proc( short 		*i_pwRefPCMIn,   	/*(i)  �ο��ź�          */
				                       short 		*i_pwEchoPCMIn,	    /*(i)  ������������ź�  */							
				                       short  	    i_s16InSize,	 	/*(i)  ���뻺��������    */					       						                           
									   short 		*o_ps16DstData,
				                       short 		*o_ps16OutSize, 	/*(o)  �������������    */
									   T_ECLD_Param    *io_pParam       /*(i/o)  EC�����ṹ���ַ */					                            
				                     );

extern ECLD_dllexport short ECLD_GetVer(void);

#else

extern short ECLD_Init( T_ECLD_Param   *io_pParam ,void* wHistBuff,char SamplingRate,short Echo_Len,char NR_Opt,char AEC_Opt);


extern short ECLD_Proc( short 		*i_pwRefPCMIn,   	/*(i)  �ο��ź�          */
				        short 		*i_pwEchoPCMIn,	    /*(i)  ������������ź�  */							
				        short  	    i_s16InSize,	 	/*(i)  ���뻺��������    */					       						            
					    short 		*o_ps16DstData,
						T_ECLD_Param    *io_pParam, 	    /*(i/o)  EC�����ṹ���ַ */
						void          * TempBuff
				      );

extern short ECLD_GetVer(void);


#endif

#endif

#ifdef __cplusplus
}
#endif
