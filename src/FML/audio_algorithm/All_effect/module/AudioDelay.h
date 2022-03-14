/*
 * AudioDelay.h
 *
 *  Created on: Jul 18, 2019
 *      Author: guoax
 */

#ifndef AUDIODELAY_H_
#define AUDIODELAY_H_
#include "nds32_includes.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct{
	uint32_t Fs_Hz;
	float    DlyMax_Ms;
	float    DlyL_Ms;
	float    DlyR_Ms;
	uint8_t  En;
}AudioDelayPara_t;

typedef struct{
	int32_t  SrcRampBuf0;
	uint16_t SmthIndex;
	uint16_t DlySampMax;
	uint16_t DlySampL;
	uint16_t DlySampLOld;
	uint16_t rpL;
	uint16_t rpL_old;
	uint16_t DlySampR;
	uint16_t DlySampROld;
	uint16_t rpR;
	uint16_t rpR_old;
	uint16_t wp;
	uint16_t En;
	int16_t *pBuff;
}AudioDelayStru_t;

void     AudioDelay_New    (AudioDelayPara_t *pPara, AudioDelayStru_t *pInst);
uint32_t AudioDelay_MaxBuff(AudioDelayPara_t *pPara, AudioDelayStru_t *pInst);
uint32_t AudioDelay_Init(AudioDelayStru_t *pInst, void *pBuff);
void AudioDelayMono(int32_t *pData, AudioDelayStru_t *pInst, uint32_t Len);
void AudioDelayStereo(int32_t *pDataI, int32_t *pDataL, int32_t *pDataR, AudioDelayStru_t *pInst, uint32_t Len);
#endif /* AUDIODELAY_H_ */
