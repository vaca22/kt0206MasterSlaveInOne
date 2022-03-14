/*
 * pitchshift.h
 *
 *  Created on: Dec 17, 2019
 *      Author: guoax
 */

#ifndef PITCHSHIFTWSOLA_H_
#define PITCHSHIFTWSOLA_H_
#include "nds32_includes.h"
#include "effect_config.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct {
	float ratio;
	uint8_t      En;
}PitchShiftWsolaPara_t;
typedef struct {
	int32_t		*pBuff;
	uint32_t     BuffSize;
	int32_t      Ytmp[2];
	int32_t     *pOlp;
	int32_t 	*pRingBuff;
	uint16_t     rd;
	uint16_t     wr;
	uint16_t     RingBuffLen;
	uint16_t     OlpLen;
	uint16_t     YLen;
	uint16_t     InpTn;
	uint16_t     ShiftMax;
	uint16_t 	 RaitoEn9;
	uint8_t      En;
}PitchShiftWsolaStru_t;

#if(EFFECT_PITCHSHIFT_EN)
uint16_t FindOptMatch(PitchShiftWsolaStru_t *pStru, int32_t *pTmp400);
void OlpAddSynthesis (PitchShiftWsolaStru_t *pStru, int32_t *pYout, uint32_t IdxMatch, uint32_t len);
void InpForPitchShift(PitchShiftWsolaStru_t *pStru, int32_t *pIn,   int32_t *pOut,  uint32_t outlen);

void PitchShiftWsola_New(PitchShiftWsolaStru_t *pStru, PitchShiftWsolaPara_t *pPara);
uint32_t PitchShiftWsola_MaxBuff(PitchShiftWsolaStru_t *pStru, uint32_t Len);
uint32_t PitchShiftWsola_Init(PitchShiftWsolaStru_t *pStru, void *pBuff, uint32_t len);
void PitchShiftWsola(PitchShiftWsolaStru_t *pStru, int32_t *pData, int32_t *pTmpLenx2Add400, uint16_t len);
#endif
#endif /* PITCHSHIFT_H_ */
