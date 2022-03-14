/*
 * AudioDRC.h
 *
 *  Created on: Sep 19, 2019
 *      Author: guoax
 */

#ifndef AUDIODRC_H_
#define AUDIODRC_H_
#include "nds32_includes.h"
#include "effect_config.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
#define DRC_ATRT_MIN  (0.1f)
#define DRC_ATRT_MAX  (60000.0f)

typedef struct{
	int32_t 		LpfBuff      ;
	int32_t         DownSampBuff ;
	int32_t         Buff         ;
	int64_t         gBuff        ;

	int32_t 		alpha        ;
	int32_t         ratio        ;
	int32_t         point        ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;
	uint8_t         soft         ;
	uint8_t         en           ;
}CompanderStru_t;


typedef struct{
	float           ratio        ;
	float           point_dB     ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           ave_Ms       ;
	uint16_t        Fnotch[5]    ;
	uint16_t        Qv           ;
	uint16_t        fs_Hz        ;
	uint8_t         Nnotch       ;
	uint8_t         en           ;
}DeEsserPara_t;

typedef struct{
	int32_t 		LpfBuff      ;
	int32_t         DownSampBuff ;
	int32_t         Buff         ;
	int64_t         gBuff        ;

	int32_t 		alpha        ;
	int32_t         ratio        ;
	int32_t         point        ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;
	int32_t         sinwQ[5]     ;
	int32_t         cosw[5]      ;
    int32_t         NotchState[20];
    uint8_t         Nnotch       ;
	uint8_t         en           ;
}DeEsserStru_t;

typedef struct{
	float           ratio        ;
	float           point_dB     ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           ave_Ms       ;
	uint16_t        fs_Hz        ;
	uint8_t         compand      ;
	uint8_t         soft         ;
	uint8_t         en           ;
}CompanderPara_t;

typedef struct{
	int32_t 		PeakBuff     ;
	int32_t 		PeakBuff1    ;
	int32_t         Buff         ;
	int64_t         gBuff        ;
	int32_t         Vlow         ;
	int32_t         Vhigh        ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;

	int32_t         PkAttack     ;
	int32_t         PkRelease    ;

    int32_t         gSet         ;
    int32_t         gGate        ;

    uint32_t        Nsignal      ;
    uint32_t        Nnoise       ;


	uint32_t        cnt          ;
	uint8_t         state        ;
	uint8_t         reachGate    ;
	uint8_t         en           ;

}NoiseGateStru_t;

typedef struct{
	float           THlow_dB     ;
	float           THhigh_dB    ;
	float           signalT_Ms   ;
	float           noiseT_Ms    ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           PkAT_Ms      ;
	float           PkRT_Ms      ;
	float           GateVol_dB   ;
	uint16_t        fs_Hz        ;
	uint8_t         en           ;
	uint8_t         reachGate    ;
}NoiseGatePara_t;


typedef struct{
	int32_t 		PeakBuff     ;
	int32_t         PeakBuff1    ;
	int32_t         Buff         ;
	int64_t         gBuff        ;

	int32_t         Vpoint       ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;

	int32_t         PkAttack     ;
	int32_t         PkRelease    ;

	uint8_t         en           ;
	uint8_t         soft         ;

}LimiterStru_t;

typedef struct{
	float           point_dB     ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           PkAT_Ms      ;
	float           PkRT_Ms      ;
	uint16_t        fs_Hz        ;
	uint8_t         soft         ;
	uint8_t         en           ;
}LimiterPara_t;

typedef struct{
	int32_t 		LpfBuff      ;
	int32_t         DownSampBuff ;
	int32_t         Buff         ;
	int64_t         gBuff        ;
	uint32_t        HoldCnt      ;

	int32_t 		alpha        ;
	int32_t         ratio        ;
	int32_t         point        ;
	int32_t         maxg         ;

	int32_t         gAttack      ;
	int32_t         gRelease     ;
	uint32_t        HoldSmp      ;
	uint8_t         en           ;
}AgcStru_t;

typedef struct{
	float           ratio        ;
	float           point_dB     ;
	float           gMax_dB      ;
	float           gAT_Ms       ;
	float           gRT_Ms       ;
	float           ave_Ms       ;
	float           hold_Ms      ;
	uint16_t        fs_Hz        ;
	uint8_t         en           ;
}AgcPara_t;

void NoiseGateNew   (NoiseGateStru_t *pStru, NoiseGatePara_t *pPara);
void NoiseGate      (int32_t *pData,  NoiseGateStru_t *pInst, uint16_t Len);
void NoiseGateStereo(int32_t *pDataL, int32_t *pDataR, NoiseGateStru_t *pInst, uint16_t Len);

void CompanderNew (CompanderStru_t *pStru, CompanderPara_t *pPara);
void CompressLarge(int32_t *pData, CompanderStru_t *pInst, uint16_t Len);
void ExpandSmall  (int32_t *pData, CompanderStru_t *pInst, uint16_t Len);

void DeEsserNew(DeEsserStru_t *pStru, DeEsserPara_t *pPara);
void DeEsser(int32_t *pData, DeEsserStru_t *pInst, uint16_t Len);
void NotchFilterUpdate(DeEsserStru_t *pInst, int32_t *pCoeff);

void Limiter      (int32_t *pData,  LimiterStru_t *pInst, uint16_t Len);
void LimiterStereo(int32_t *pDataL, int32_t *pDataR, LimiterStru_t *pInst, uint16_t Len);
void LimiterNew   (LimiterStru_t *pStru, LimiterPara_t *pPara);

void AgcNew(AgcStru_t *pStru, AgcPara_t *pPara);
void Agc   (int32_t *pData, AgcStru_t *pInst, uint16_t Len);


#endif /* AUDIODRC_H_ */
