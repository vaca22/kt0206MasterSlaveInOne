#ifndef __HOWLING_DETECT_H__
#define __HOWLING_DETECT_H__

#include "eq_cal_coeff.h"
#include "nds32_math_types.h"
#include "nds32_filtering_math.h"
#include "effect_config.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
#define N_NOTCH               (32)
#define N_MAX_FFT             (20)

typedef struct
{
	uint32_t CntGlobal;
	 int32_t delay0;
	 int32_t delay1;
	uint32_t ZCindex[32];
	uint32_t PKindex[32];
	uint32_t ZCcnt;
	uint32_t PKcnt;
	uint32_t cnt0;

	 int32_t PeakLong;
	 int32_t PeakTemp;
	uint32_t PeakLongCnt;

	uint64_t PeakLong2Sum;
	uint64_t PeakSum;
	uint64_t Peak2Sum;
	uint64_t ZCindex2Sum;
	uint64_t PKindex2Sum;
	uint32_t ZCindexSum;
	uint32_t PKindexSum;
	uint32_t ZCNindexSum;
	uint32_t ZCindexVar;
	uint32_t PKindexVar;
	uint32_t PeakLongVar;
	uint32_t PeakShortVar;
	uint32_t SimiHowlCnt;

	uint32_t PKLongWinSamp;
	uint32_t ZCindexVarTh;
	uint32_t PKindexVarTh;
	uint32_t PeakLongVarTh;
	uint32_t PeakShortVarTh;
	uint32_t Fs_Hz;
	uint32_t Fhowl_Hz;
	uint8_t  HowlState;
}HowlDetStru_t;

typedef struct
{
	uint8_t  PKLongWinT_S;
	uint8_t  ZCindexVarTh;
	uint8_t  PKindexVarTh;
	uint8_t  PeakLongVarTh;
	uint8_t  PeakShortVarTh;
	uint32_t Fs_Hz;
	uint32_t Fhowl_Hz;
	uint8_t  HowlState;
}HowlDetPara_t;

typedef struct
{
	 int64_t gBuffEn62;
	 int32_t gUseEn31;
	 int32_t gSetEn31;
	uint32_t HowlCnt;
	uint32_t cnt;
	uint32_t AtCnt;
	uint32_t FailCnt;
	uint32_t AtWin;

    int32_t  gAtEn31;
    int32_t  gRtEn31;
	int32_t  UpStep0En30;
	int32_t  UpStep1En30;
	int32_t  DownStepEn30;
	int32_t  gMinEn31;
	int32_t  gUp0ThEn31;
	uint32_t UpWin;
	uint8_t  NoHowlPctEn8;
	uint8_t  AfterNotchN;
}HowlGainStru_t;

typedef struct
{
	float      NoHowl_Pct;
	uint16_t   gAT_Ms;
	uint16_t   gRT_Ms;
	uint8_t    UpStep0_dB;
	uint8_t    UpStep1_dB;
	uint8_t    DownStep_dB;
	uint8_t    gMin_dB;
	uint8_t    gUp0Th_dB;
	uint8_t    UpWinT_Ms;
	uint8_t    AfterNotchN;

	uint32_t   gUseEn31;
}HowlGainPara_t;


typedef struct
{
	uint16_t notchF[N_NOTCH];
	 uint8_t notchEn[N_NOTCH];
	 uint8_t notchD[N_NOTCH];
	uint32_t notchCnt[N_NOTCH];
	uint32_t notchDownCnt[N_NOTCH];
	 int32_t notchCoeff[N_NOTCH][5];
	 int32_t notchState[N_NOTCH][4];
	uint16_t Fhowl[N_MAX_FFT];
	uint8_t  DetState[N_MAX_FFT];
	uint8_t  NotchUpdate;

	uint32_t NotchLife_2048p;
	uint32_t NotchUpTime_2048p;
	uint16_t NotchHold_2048p;
	uint8_t  NotchDeep_dB;
	uint8_t  NotchInit_dB;
	uint8_t  NotchUp_dB;
	uint8_t  NotchDown_dB;
	uint8_t  NotchTotalNum;
	uint8_t  NotchWantStudy;

	uint8_t  DetNth;
	uint16_t DetFth_Hz;
	uint16_t NotchDf_Hz;
	uint8_t  NotchQ;

	uint32_t NotchOpenFlag;
	uint32_t NotchOldFlag;
	uint32_t NotchFixFlag;
	uint8_t  NotchCurStudy;
	uint8_t  StudyUpdate;

} HowlNotchStru_t;
	
typedef struct
{
	uint16_t NotchLife_S;
	uint16_t NotchUpTime_S;
	uint16_t NotchHold_Ms;
	uint8_t  NotchDeep_dB;
	uint8_t  NotchInit_dB;
	uint8_t  NotchUp_dB;
	uint8_t  NotchDown_dB;
	uint8_t  NotchTotalNum;
	uint8_t  NotchWantStudy;

	uint8_t  DetNth;
	uint16_t DetFth_Hz;
	uint16_t NotchDf_Hz;
	uint8_t  NotchQ;

	uint32_t NotchOpenFlag;
	uint32_t NotchOldFlag;
	uint32_t NotchFixFlag;
	uint8_t  NotchCurStudy;
	uint8_t  StudyUpdate;
} HowlNotchPara_t;

typedef struct
{
	HowlDetStru_t   DetState;
	HowlNotchStru_t NotchState;
	HowlGainStru_t  GainState;
	uint8_t         DetEn;
	uint8_t         NotchUpdateEn;
	uint8_t         NotchEn;
	uint8_t         GainCtrlEn;
	uint8_t         ClearEn;
	uint8_t         En;
}HowlStru_t;

typedef struct
{
	HowlDetPara_t   DetPara;
	HowlNotchPara_t NotchPara;
	HowlGainPara_t  GainPara;
	uint8_t         DetEn;
	uint8_t         NotchUpdateEn;
	uint8_t         NotchEn;
	uint8_t         GainCtrlEn;
	uint8_t         ClearEn;
	uint8_t         En;
}HowlPara_t;

#if(EFFECT_HOWLSUPRESS_EN)
void HowlSupressTop    (q31_t *pData, HowlStru_t *pInst, q31_t *pTmpLenx1, uint32_t Len);
void HowlSupressNew    (              HowlStru_t *pInst, HowlPara_t *pPara);
void HowlDetParaNew    (              HowlStru_t *pInst, HowlPara_t *pPara);
void HowlNotchParaNew  (              HowlStru_t *pInst, HowlPara_t *pPara);
void HowlGainParaNew   (              HowlStru_t *pInst, HowlPara_t *pPara);
void HowlSupressParaOut(              HowlStru_t *pStru, HowlPara_t *pPara);

void HowlDetect        (const q31_t *pSrc, HowlStru_t *pInst, q31_t *pTmpLenx1, uint32_t Len);
void HowlDetect_GetPara(const q31_t *pSrc, HowlStru_t *pInst, q31_t *pTmpLenx1, uint32_t Len);
void HowlDetect_Judge  (             HowlStru_t *pInst                                );

void HowlNotchUpdate     (             HowlStru_t *pInst                                         );
void HowlNotchUpdate_Down(             HowlStru_t *pInst, uint8_t NotchIdx, uint8_t *NotchUpState);
void HowlNotchUpdate_Open(             HowlStru_t *pInst, uint8_t NotchIdx, uint8_t *NotchUpState);
void HowlNotchUpdate_Up  (             HowlStru_t *pInst                                         );
void HowlNotch           (q31_t *pData, HowlStru_t *pInst, uint32_t Len                           );

void HowlGainCtrl        (q31_t *pData, HowlStru_t *pInst, uint32_t Len);
void HowlGainCtrl_gUse   (q31_t *pData, HowlStru_t *pInst, uint32_t Len);

static inline uint32_t my_bclr(uint32_t datain, uint32_t idx){
	return datain & (~((uint32_t)1 << idx));
}

static inline uint32_t my_bset(uint32_t datain, uint32_t idx){
	return datain | ((uint32_t)1 << idx);
}

static inline uint32_t my_btst(uint32_t datain, uint32_t idx){
	return (datain & ((uint32_t)1 << idx)) ? 1 : 0;
}
//-----------------------------------------------------
//Patch
//-----------------------------------------------------
#define HOWLINGDETECT_PATCH                                                                     \
const uint32_t * g_howling_notch_life_tab;                                                      \
const int32_t * agzc_gain_q31;                                                                  \
const int32_t * agzc_gainup_tab;                                                                \
const int32_t * agzc_gaindown_tab;                                                              \
void (*HowlingSupress_top)(q31_t *pSrc,q31_t *pDst,q31_t *TempBuff6k,uint32_t blocksize);       \
uint32_t (*agzc_notch_update)(uint32_t agzc_state);                                             \
uint32_t (*agzc_detect)(q31_t *pSrc,uint32_t blocksize);                                        \
void (*agzc_gain_ctrl)(q31_t *pSrc,uint32_t agzc_state,uint32_t blocksize);                    \
void (*adaptnotch_rst)(void);

#define HOWLINGDETECT_PATCH_INIT                                                                \
.g_howling_notch_life_tab  = g_howling_notch_life_tab,                                          \
.agzc_gain_q31             = agzc_gain_q31,                                                     \
.agzc_gainup_tab           = agzc_gainup_tab,                                                   \
.agzc_gaindown_tab         = agzc_gaindown_tab,                                                 \
.HowlingSupress_top        = HowlingSupress_top,                                                \
.agzc_notch_update         = agzc_notch_update,                                                 \
.agzc_detect               = agzc_detect,                                                       \
.agzc_gain_ctrl            = agzc_gain_ctrl,	                                                \
.adaptnotch_rst            = adaptnotch_rst,


#define HOWLINGDETECT_PATCH_NUM 9

#endif

#endif
