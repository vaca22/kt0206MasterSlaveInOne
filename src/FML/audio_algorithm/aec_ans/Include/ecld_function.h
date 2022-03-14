/*********************************************************************
* 版权所有 (C)
* 系统名称: 
* 文件名称: ecld_functions.h
* 内容摘要: 函数声明
* 当前版本: V2.B0
* 作    者: 
* 设计日期: 
* 修改记录: 
* 日    期			版    本		修改人 		修改摘要  
**********************************************************************/

#ifndef ECLD_FUNCTION_H
#define ECLD_FUNCTION_H

#include "../Include/ecld_alg.h"
#include "../Include/ecld_structs.h"
#include "../Include/ecld_typedefs.h"

#define EXTRACT16(x)      ((Word16)(x))
#define EXTEND32(x)       ((Word32)(x))
#define MULT16_16(a,b)    (Word32)(((Word16)(a)) * ((Word16)(b)))   
#define MIN16(a, b)       ((a) < (b) ? (a)  : (b))  
#define MAX16(a, b)       ((a) > (b) ? (a)  : (b))   
#define MIN32(a, b)       ((a) < (b) ? (a)  : (b))  
#define MAX32(a, b)       ((a) > (b) ? (a)  : (b))  
#define SQR16_Q15(x)      (ECLD_mult((x), (x)))
void ecld_patch_init(void);
/*************************  AEC Function  **************************/
void ECLD_r_fft(
				  Word16 * farray_ptr,
                  Word16 VED_SIZE,
                  Word16 VED_SIZE_BY_TWO,
                  Word16 VED_NUM_STAGE,
                  const Word16 *VED_CONST_PHS_TABLE,
				  const Word16 *VED_CONST_II_TABLE,
				  Word16 isign
				  );

void ECLD_c_fft (
				  Word16 * farray_ptr,
                  Word16 VED_SIZE,
                  Word16 VED_SIZE_BY_TWO,
                  Word16 VED_NUM_STAGE,
                  const Word16 *VED_CONST_PHS_TABLE,
				  const Word16 *VED_CONST_II_TABLE,
				  Word16 isign
				  );


Word16  ECLD_Subband_process(
					         Word16 *ifftx, 
							 Word16 *VED_EC_h_main, 
							 Word16 *VED_EC_u,
							 Word32 *VED_EC_upower,
					         Word32 *VED_EC_sed,
							 Word32 *VED_EC_syy,							 
							 Word32 *NLP_gain,
					         Word16 *CNG_flag_pow,
							 Word16 *SpeechFlag,
							 Word16 vad_ref,
					         Word16 vad_mic, 
							 Word16 i_wEC_L, 
							 Word16 s16SampleRate, 
							 Word16 *io_NIS,
							 Word16 NLP_tmp,
							 Word32 *pSumPowerAfterNLP,
							 Word32 *Tbuffer
					         );

VOID ECLD_VAD_Estimate (
						 Word32 	*pY,
						 Word16     *NIS,
						 Word16     *tempt_i,
						 Word32 	*pS,
						 Word32 	*N_FB_mean_vad_tempt,
						 Word32 	*N_FB_mean_vad1,
						 Word16 	*SpeechFlag,						 
						 Word32 	*T_vad,
						 Word32 	*vad_tr,
						 Word16 	*Hangover1,
						 Word32     *NoiseRms,
						 Word32     *ps32FullEnergy,
						 Word16     s16ECLD_M_BY_TWO,
						 Word32     *Tbuffer
						 );	
VOID ECLD_vad_Process(
				Word16 *ifftx, 
				Word16 *CNG_flag_pow,
				Word16 *NIS,
				Word16 *tempt_i,
				Word32 *pS,
				Word32 *N_FB_mean_vad_tempt,
		        Word32 *N_FB_mean_vad1,
				Word16 *SpeechFlag,
				Word32 *T_vad,
				Word32 *NoiseRms,
				Word16 *pvad_ref,
				Word16 *pvad_mic,
				Word32 *pNoiseLevel,
				Word16 *NO_SpeechFlag,
				Word16 s16SampleRate,
				Word16 *Tbuffer
				);

void  ECLD_ana_Process_8K(
					  Word16   *i_pSrcData_Echo, 
					  Word16   *i_pDstData, 
					  Word16   *io_Ref_buffer,
					  Word16   *io_Echo_buffer, 
					  Word16   *o_ifftx,
					  Word16   *Tbuffer
					  );

void  ECLD_ana_Process_16K(
					  Word16   *i_pSrcData_Echo, 
					  Word16   *i_pDstData, 
					  Word16   *io_Ref_buffer,
					  Word16   *io_Echo_buffer, 
					  Word16   *o_ifftx,
					  Word16   *Tbuffer
					  );

void  ECLD_syn_Process_8K(
					  Word16 *o_pSrcData_Echo,
					  Word16 *i_ifftx,
					  Word16 *io_Ex_buffer					  
					  );

void  ECLD_syn_Process_16K(
					  Word16 *o_pSrcData_Echo,
					  Word16 *i_ifftx,
					  Word16 *io_Ex_buffer					  
					  );

short ECLD_block_norm(
				      Word16	*data, 
				      Word16	size, 
				      Word16	headroom
				     );

void ECLD_block_denorm(
					   Word16    *data, 
					   Word16  	size, 
					   Word16	scnt
					 );

VOID ECLD_ECProc_PreFilter(Word16 *ifftx, 
						   Word16 *VED_EC_h,
						   Word16 *VED_EC_u,
						   Word32 *VED_EC_upower_dtd,
					       Word32 *VED_EC_ped0,
					       Word32 *VED_EC_pyy,
					       Word32 *VED_EC_ped2, 
						   Word32 *VED_EC_ped1,
					       Word32 *VED_EC_pdd, 						      
					       Word16 *CNG_flag_pow,
					       Word16 *SpeechFlag,
					       Word16 vad_ref, 
					       Word16 vad_mic, 
					       Word16 i_wEC_L, 
					       Word16 s16SampleRate, 
					       Word16 *io_NIS, 
						   Word16 *pNlpMax,
						   Word32 *Tbuffer
						   );

VOID ECLD_dtd_syn(
			Word16 *pSrcData_Echo,
			Word16 *Ex_buffer,
			Word16 *ifftx,
			Word16 *VED_EC_h_main,
			Word16 *VED_EC_h, 
			Word16 *VED_EC_u,
			Word32 *VED_EC_upower,
			Word32 *VED_EC_upower_dtd,
			Word32 *VED_EC_sed,
			Word32 *VED_EC_syy, 

			Word32 *VED_EC_ped2_dtd, 
			Word32 *VED_EC_ped1_dtd,
			Word32 *VED_EC_pdd_dtd,
			Word32 *VED_EC_ped0_dtd, 
			Word32 *VED_EC_pyy_dtd,

			Word16 *CNG_flag_pow,
			Word16 *NIS,
			Word16 *tempt_i,
			Word32 *pS,
			Word32 *N_FB_mean_vad_tempt,
		    Word32 *N_FB_mean_vad1,
			Word16 *SpeechFlag,
			Word32 *T_vad,
			Word32 *NoiseRms,
			Word16 *sRandNumIndex,
			Word16 *sRandNumbers,
			Word16 vad_ref, 
			Word16 vad_mic,
			Word16 i_wEC_L,
			Word32 *pNoiseLevel,
            Word16 s16SampleRate,
			Word32 *pSumPowerAfterNLP,
			Word16 *Tbuffer
			);
Word16 AEC_DelayEstimate(Word16* i_pFilterCoeff,
                         Word16 s16ECLD_M,
						 Word16 i_wEC_L
						 );
	
VOID ECLD_rand_number(Word16 *sEcscratch,
					 Word16 *sRandNumIndex,
					 Word16 *sRandNumbers,
					 Word16 s16ECLD_ABLOCK
					 );	

short EC_Init( 
			  T_ECState_Param   * pECstate_Param
			  );
Word16 EC_Init_new(T_ECState_Param *pECstate_Param);

void EC_Proc( 
			    Word16 		*i_pwRefPCMIn,	//(i)  参考信号           
				Word16 		*i_pwEchoPCMIn,	//(i)  需回声抵消的信号   							
				Word16  	    i_wInSize,	 	//(i)  输入缓冲区长度     	
				Word16 		*o_pwEchoPCMOut,//(o)  回声抵消后的信号   		    
				T_ECLD_Param     *io_pParam, 	    //(i/o)  EC参数结构体地址
				short 		*TempBuffer
				);	

/*********************************   VQE Function ************************************/
Word16 VQE_Init(T_VQEState_Param  *pVQEstate_Param);

Word16 WVQE_Block_Norm(Word32 *pwData, Word16 wSize, Word16 wHeadRoom);

VOID WVQE_Block_Denorm(Word32 * pwData, Word16 wSize, Word16 wScnt);


VOID WVQE_NR_Proc(Word16 *pwInputPnt,
				  Word16 *pwOutputPnt, 
				  T_ECLD_Param *pParam,
                  T_VQEState_Param  * pVQEstate_Param,
                  Word16 *TempBuff
				  );

VOID WVQE_MainProcess(Word16 *i_pSourceData, 
					  T_VQEState_Param* ptGlobalState,
					  Word32 dwFrameLen,
					  Word16 wPsLen,
					  Word16 wAddLenInFFT,
					  Word16 wSamplingRate,				 
					  Word8  cNR_Opt,
					  Word16 *o_pDestData,
					  Word16 *TempBuff);

Word16 WVQE_DIV32_16_Q8   (Word32 dwVar1, Word32 dwVar2);

Word16 WVQE_DIV32_16_Q15  (Word32 dwVar1, Word32 dwVar2);

Word32 WVQE_L_div32       (Word32 dwVar1, Word32 dwVar2);

Word16 WVQE_Sqrt          (Word32 dwVar);

Word32 WVQE_Exp           (Word16 dwVar);

Word32 WVQE_Qcurve        (Word16 wVar);

Word32 WVQE_Hypergeom_Gain(Word32 dwTheta);

VOID WVQE_Spectrum_PSD(Word16 *pwFreqForm,
					   const Word16 *pwFilterLeft, 
					   const Word16 *pwFilterRight, 
					   const Word32 *pdwBankLeft, 					   
					   const Word32 *pdwBankRight, 				       
					   Word16 *pwBarkForm, 					   
					   Word16 wLen);

VOID WVQE_Analysis(Word32 *i_pwOriginalData, 
				   Word32 *pdwSpectrumPower,
				   Word32 *pdwBarkSpectrumPower, 
				   Word32 *pwFrame,
				   Word32 *pwFreqForm,
				   Word32  aTmpFrame[512],				   
				   const Word16 *pwFFTCoef,
				   const Word16 *pwFFTCoefRearrange,
				   const Word16 *pwWinTable,
				   const Word32 *pdwBankLeft, 
				   const Word16 *pwFilterLeft, 
				   const Word32 *pdwBankRight, 
				   const Word16 *pwFilterRight, 
				   Word32  dwFrameLen,
				   Word16  wPsLen,
				   Word16  wAddLen,
				   Word16  wSamplingRate,
				   T_VQEState_Param *ptGlobalState,
				   Word16 *TempBuffer);

VOID WVQE_Noise_Vad(T_VQEState_Param *ptStateVar,
					Word16 wPsLen, 
					Word32 *pdwSpectrumPower,
					BYTE   *pbUpdateNoiseFlag);

VOID WVQE_Spectrum_Bank(Word32 *pdwFreqForm, 
						Word32 *pdwBarkForm,						
						const Word32 *pdwBankLeft, 					
						const Word32 *pdwBankRight,
						const Word16 *pwFilterLeft, 
						const Word16 *pwFilterRight, 
						Word16 wLen
						);

VOID WVQE_PostAndPriorSNR(Word16 *pwPostSNR, 
						  Word16 *pwPriorSNR,
						  Word32 *pwOldSpectrumPower,						  
						  Word32 *pdwBarkSpectrumPower, 
						  Word32 *pdwBarkNoise,
                          Word16 s16Adapt 
						  );

VOID WVQE_Gain_Proc(T_VQEState_Param *ptStateVar, 
					Word16 *pwPostSNR,
					Word16 *pwPriorSNR,
					Word32 *pdwBarkNoise,
					Word32 *pdwBarkSpectrumPower, 
					const Word32 *pdwBankLeft, 
					const Word16 *pwFilterLeft, 
					const Word32 *pdwBankRight, 
					const Word16 *pwFilterRight, 
					Word8 cNR_Opt, 
					Word16 wPsLen,
					Word16 *pwFinalGain);

VOID WVQE_IFFT(Word32 *i_pwFreqDomain, 
			   Word16 wFFTSize, 
			   Word16 wSizeByTwo,
			   Word16 wStageNum,
			   const Word16 *s16pFFTCoefTab, 
			   const Word16 *s16PFFTCoefTabRearrange,
			   Word32 *o_pwTimeDomain);

VOID WVQE_FFT(Word32 *i_pwTimeDomain, 
			  Word16 wFFTSize, 
			  Word16 wSizeByTwo,
			  Word16 wStageNum, 
			  const Word16 *s16pFFTCoefTab, 
			  const Word16 *s16PFFTCoefTabRearrange,
			  Word32 *o_pwFreqDomain);
/* 噪声门处理 */
VOID Noise_Gate_Proc(Word16 *i_input, Word16 s16SubFrameLen, T_VQEState_Param *pVQEState);

/* AGC处理部分 */
void  VED_AGC_Process(
					  T_VQEState_Param *ptGlobalState, 
					  Word16 *i_pSourceData, 
					  const Word32 *GainTable,
					  Word16  wSamplingRate,
					  Word16 *o_pOutPutData
					  );
											
#endif
