/*
 * MusicDucking.h
 *
 *  Created on: Dec 10, 2019
 *      Author: guoax
 */
#ifndef MUSICDUCKING_H_
#define MUSICDUCKING_H_

#include "nds32_includes.h"
typedef struct{
	int32_t 		LpfBuff      ;
	int32_t         Buff         ;
	int64_t         gBuff        ;
	int32_t 		alpha        ;
	int32_t         Vlow         ;
	int32_t         Vhigh        ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;

    int32_t         gSet         ;
    int32_t         gDucking     ;

    uint32_t        Nsignal      ;
    uint32_t        Nnoise       ;

	uint32_t        cnt          ;
	uint8_t         state        ;
	uint8_t         en           ;
}MusicDuckingStru_t;

typedef struct{
	float           THlow_dB     ;
	float           THhigh_dB    ;
	float           signalT_Ms   ;
	float           noiseT_Ms    ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           ave_Ms       ;
	float           DuckingVol_dB;
	uint16_t        fs_Hz        ;
	uint8_t         en           ;
}MusicDuckingPara_t;
void MusicDuckingNew(MusicDuckingStru_t *pStru, MusicDuckingPara_t *pPara);
void MusicDuckingCtrl(const int32_t *pData, MusicDuckingStru_t *pInst, int32_t *pOut, uint16_t Len);
void MusicDucking(int32_t *pDataL, int32_t *pDataR, int32_t *pDuckingVol, MusicDuckingStru_t *pInst, uint16_t Len);

#endif /* MUSICDUCKING_H_ */
