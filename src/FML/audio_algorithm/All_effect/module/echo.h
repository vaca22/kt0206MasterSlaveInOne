/*
 * echo.h
 *
 *  Created on: Jul 20, 2019
 *      Author: guoax
 */

#ifndef ECHO_H_
#define ECHO_H_

#include "effect_config.h"
#include "nds32_includes.h"


#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct{
	float    LoopRatio_dB;
	uint32_t Fs_Hz;
	uint16_t Dly_Ms;
	uint16_t DlyMax_Ms;
	uint16_t En;
}EchoPara_t;

typedef struct{
	float    LoopRatioDB_old;
	uint16_t LoopRatioFI;
	uint16_t DlySamp;
	uint16_t DlySampMax;
	uint16_t DlySampOld;
	uint16_t DlySampMaxOld;
	uint16_t En;

	int32_t  LoopRatioBuff;
	int32_t  SrcRampBuf0;
	uint16_t SmthIndex;
	uint16_t rp;
	uint16_t wp;
	uint16_t rp_old;
	int16_t *pBuff;

}EchoStru_t;

#if(EFFECT_ECHO_EN)
void Echo_New (EchoPara_t *pPara, EchoStru_t *pInst);
uint32_t Echo_MaxBuff(EchoPara_t *pPara, EchoStru_t *pInst);
uint32_t Echo_Init(EchoStru_t *pInst, void *pBuff);
void Echo_Wet(int32_t *pData, EchoStru_t *pInst, uint16_t Len);
#endif

#endif /* ECHO_H_ */
