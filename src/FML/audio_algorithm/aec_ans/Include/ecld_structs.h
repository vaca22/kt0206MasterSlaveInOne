/*********************************************************************
* ��Ȩ���� (C)
* ϵͳ����: 
* �ļ�����: ecld_structs.h
* ����ժҪ: ��ʷ������װ
* ��ǰ�汾: V2.B0
* ��    ��: 
* �������: 
* �޸ļ�¼: 
* ��    ��			��    ��		�޸��� 		�޸�ժҪ  
**********************************************************************/

#include "../Include/ecld_typedefs.h"
#include "../Include/ecld_const.h"
#include "../Include/ecld_const_table.h"

#ifndef ECLD_STRUCTS_H
#define ECLD_STRUCTS_H

//��������ģ����ʷ����
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
    Word32   dVED_EC_pdd_dtd[ECLD_M_BY_TWO_16K]; //���˵�����غ���
	
	Word32	 EC_dT_vad[2];
	Word32	 EC_dN_FB_mean_vad_tempt[128]; 
	Word32	 EC_dN_FB_mean_vad1[128];       
	Word32	 EC_dS[128]; 
	Word32	 EC_dNoiseRms[128];

	Word16   dCNG_flag_pow[6];
	Word16	 EC_dSpeechFlag[6];   
	Word16   EC_S_sRandNumIndex[2];               //���������
    Word16   EC_S_sRandNumbers[5];                //5�������,���ڲ��������λ,����������
	Word32   EC_m_aNoiseLevel[ECLD_M_BY_TWO_16K]; //������ƽ,����������

	Word16	 EC_dtempt_i;              //����������ѭ��������,ÿ100֡��0,Ȼ�����¼���
	Word16	 EC_dNIS;                 //֡������, ����10000֡�Ժ��ٸ���
	Word16   EC_dpre_emp_mem_Ref;     //Զ�˲ο��źż����˲�����ʷ����
	Word16   EC_dpre_emp_mem_Echo;   //�����źż����˲�����ʷ����
	Word16   EC_dde_emp_mem_Echo;   //ȥ�����˲�����ʷ����

	Word16   EC_NO_SpeechFlag;     //������������,����������������

	Word32   EC_SumPowerAfterNLP;  //���������Դ����Ĳ���������

	char     EC_unused[28];	  //�����ֶ�

} T_ECState_Param;    

/*------------------------------------------------*/


/* ��������ģ����ʷ���� */
typedef struct tag_DMICVQE_State
{
	Word32  adwMidMinPower[WVQE_MAX_PS_LEN];       /* 1024 ��С��ʱ���ڵ���С����ֵ */
	Word32  adwMinPower[WVQE_MAX_PS_LEN];          /* 1024 һ��ʱ���ڵ���С����ֵ */
	Word32  adwSmoothSpectumPower[WVQE_MAX_PS_LEN];/* 1024 ƽ����������� */
	Word32  adwNoise[WVQE_MAX_PS_LEN];             /* 1024 16kԭʼ������320+NB_BANDS*/  
	Word32  awPreFrameInBuf[WVQE_MAX_ADD_LEN_IN_FFT];      /* 192 16kԭʼ������320��32k��320*2*/
	Word32  awPreFrameOutBuf[WVQE_MAX_ADD_LEN_IN_FFT * 2]; /* 192 16kԭʼ������320��32k��320*2*/
	Word32  adwOldSpectrumPower[WVQE_NB_BANDS];            /* 96 */
	Word16  awZeta[WVQE_NB_BANDS];                 /* 48 */
	
	Word32  dwMinCount;               /* ���������ٶȿ��ƣ����� > min_rangʱ ���� */
	Word32  wPreEmpMem;               /* ��Ҫ����Ԥ���ش���,��¼ǰһ֡�����һ������ */
	Word32  wDeEmpMem;                /* ��Ҫ����ȥ���ش���,��¼ǰһ֡�����һ������ */
	Word16  wAdapt;                   /* ��Ҫ���ڼ���betaֵ�Ϳ��������ٶ� */  
	Word16  wPreNormShift;

	char     EC_unused[32];	//�����ֶ�

}T_VQEState_Param;

#endif
