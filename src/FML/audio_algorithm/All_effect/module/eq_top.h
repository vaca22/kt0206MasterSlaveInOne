/*
 * eq_top.h
 *
 *  Created on: Jun 14, 2017
 *      Author: lizhen
 */

#ifndef __EQ_TOP_H__
#define __EQ_TOP_H__
#ifndef NULL
#define NULL ((void *)0)
#endif
#include "nds32_includes.h"
#include "eq_cal_coeff.h"

#if EQ10band_down_MicNoise
extern uint8_t   dsp_fs48k_en;
extern int32_t  eq_fs;  //Fs in Hz for all band, 46875=24MHz/512, 48000= 24.576MHz/512
#endif

#define  EQ_64BIT_FREQ     (500*10)
typedef enum EqChannel_enum {
	EQ_MONO       = 0,
	EQ_STEREO     = 1,
}EqChannel_t;

typedef union {
	struct{
		uint32_t		shift	: 8;
		uint32_t		NeedBit	: 8;
		uint32_t		Type	: 4;
		uint32_t		RFU  	: 12;
	};
	uint32_t 				overall;	
}EqCoeffSideInfo_t;

typedef struct {
	int64_t  *pState;
	int32_t  *pCoeff;
	int32_t   Coeff[6]; //Coeff[5] save for CoeffSideInfo
	uint8_t   ThisEn;
	uint8_t   PreType;
	uint8_t   CurBit;
}EqFiltStru_t;

typedef struct {
	EqFiltStru_t     *pStru[15];
	EqCoeffPara_t    *pPara[15];
	int32_t           CoeffBak[6];
	int32_t          *pCoeffBak;
	uint8_t           NAll;
	uint8_t           NChan;
	uint8_t           StruSize;
}EqStru_t;

#define EQ_FILT_SIZE   (sizeof(EqFiltStru_t  ))
#define EQ_PARA_SIZE   (sizeof(EqCoeffPara_t ))

#if EQ10band_down_MicNoise
void eq10band_all_coeff_init(void);
void eq10band_mono_top(q31_t *pAudioIn,q31_t *pAudioOut,uint32_t len);
#endif
#if(EFFECT_EQ_EN)
const uint32_t g_eq_stru_size[2];
void EqUpdate(EqStru_t *pInst, uint8_t bandx);
void EqInit  (EqStru_t *pInst, EqChannel_t channel, uint8_t BandNum);
void EqMono  (int32_t *pData, EqStru_t *pInst, uint16_t Len);
void EqStereo(int32_t *pData0, int32_t *pData1, EqStru_t *pInst, uint16_t Len);
//-------------------------------------------------
//Patch
//-------------------------------------------------
#define EQ_TOP_PATCH                                 \
void (*EQ_Update)(                                   \
	uint8_t eq_idx,	                                 \
	uint8_t BandX,                                   \
	DSP_EQ_Ctrl_t * pEQCtrl                          \
);                                                   \
void (*eq_echo)(                                     \
	int32_t *pSrc,                                   \
	int32_t *pDst,                                   \
	uint16_t Len                                     \
);                                                   \
void (*eq_mic01)(                                    \
	int32_t *pSrc,                                   \
	int32_t *pDst,                                   \
	uint16_t Len                                     \
);                                                   \
void (*eq_mic23)(                                    \
	int32_t *pSrc,                                   \
	int32_t *pDst,                                   \
	uint16_t Len                                     \
);                                                   \
void (*eq_ptmic)(                                    \
	int32_t *pSrc,                                   \
	int32_t *pDst,                                   \
	uint16_t Len                                     \
);                                                   \
void (*eq_music)(                                    \
	int32_t *pSrc0,                                  \
	int32_t *pSrc1,                                  \
	int32_t *pDst0,                                  \
	int32_t *pDst1,                                  \
	uint16_t Len                                     \
);                                                   \
void (*eq_reverb)(                                   \
	int32_t *pSrc0,                                  \
	int32_t *pSrc1,                                  \
	int32_t *pDst0,                                  \
	int32_t *pDst1,                                  \
	uint16_t Len                                     \
);

#define EQ_TOP_PATCH_INIT                            \
.EQ_Update   = EQ_Update,                            \
.eq_echo     = eq_echo,                              \
.eq_mic01    = eq_mic01,                             \
.eq_mic23    = eq_mic23,                             \
.eq_ptmic    = eq_ptmic,                             \
.eq_music    = eq_music,                             \
.eq_reverb   = eq_reverb,

#define EQ_TOP_PATCH_NUM 7
#endif
#endif /* EQ_TOP_H_ */
