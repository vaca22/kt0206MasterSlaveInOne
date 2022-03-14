/*
 * HowlFreqShift.h
 *
 *  Created on: Oct 16, 2019
 *      Author: guoax
 */

#ifndef HOWLFREQSHIFT_H_
#define HOWLFREQSHIFT_H_
#include "nds32_includes.h"
#include "effect_config.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
typedef enum FreqShiftBw_enum{
	BW200Hz  = 0,
	BW250Hz  = 1,
	BW300Hz  = 2,
	BW350Hz  = 3,
	BW400Hz  = 4,
	BW450Hz  = 5,
	BW500Hz  = 6,
	BWFULL   = 7,
}FreqShiftBw_t;

#define FREQSHIFT_FIR_LEN               132

typedef struct {
	q31_t sin_buff;
	q31_t cos_buff;
	q31_t sin_norm;
	q31_t cos_theta;
}SinCosGenStru_t;

typedef struct {
	SinCosGenStru_t SinCos[2];
	q31_t          *pHiltFilt_odd;
	q31_t          *pHiltFilt_even;
	q31_t           FirOutBuff;
	int32_t         CrsovrFilt[2][8];
	int32_t        *pHpfDelay;
	int32_t        *pBuff;
	int32_t        *pHiltFiltCoeff;
	int32_t        *pCrsovrFiltCoeff;
	int32_t         dF;
	uint32_t        BuffSize;
	uint32_t        FirLen;
	FreqShiftBw_t   Bw;
	uint8_t         dfUpdata;
	uint8_t         En;
}FreqShiftStru_t;

typedef struct {
	int32_t         dF;
	FreqShiftBw_t   Bw;
	uint8_t         En;
}FreqShiftPara_t;

#if(EFFECT_HOWLSUPRESS_EN)
void FreqShiftNew(FreqShiftStru_t *pStru, FreqShiftPara_t *pPara, uint32_t Len);
uint32_t FreqShift_MaxBuff(FreqShiftStru_t *pStru, uint32_t Len);
uint32_t FreqShiftInit(FreqShiftStru_t *pStru, void *pBuff, uint32_t Len);

void FreqShiftTop (q31_t *pData, FreqShiftStru_t *pStru, int32_t *pTmpLenx3, uint32_t Len);
void FreqShift    (q31_t *pData, FreqShiftStru_t *pStru, int32_t *pTmpLenx3, uint32_t Len);
void ImagDelay    (q31_t *pStateEven, q31_t *pStateOdd, q31_t *pSrc, q31_t *pDst, uint16_t Delay, uint32_t Len);
void PhaseRotate  (q31_t *pReal, q31_t *pImag, q31_t *pDst, FreqShiftStru_t *pStru, uint32_t Len);
#endif

#endif /* FREQSHIFT_H_ */


