/*
 * Surround3D.h
 *
 *  Created on: Dec 10, 2019
 *      Author: guoax
 */

#ifndef SURROUND3D_H_
#define SURROUND3D_H_
#include "effect_config.h"
#include "nds32_includes.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
#define SS2 ( 21652)  //0x5494;
#define KK2 (-24595)  //0x9FED;
#define SS1 (  2332)  //0x091C;
#define KK1 ( 32685)  //0x7FAD;
#define CC0 (  6179)  //0x1823;
#define CC1 (-21632)  //0xAB80;
#define CC2 (-32768)  //0x8000;

typedef struct{
	int32_t    SrdFiltU0;
	int32_t    SrdFiltU1;
	int16_t    CenterGain;
	int16_t    SrdGain;
	int16_t    FrontGain;
	uint8_t    En;
}Surround3DStru_t;

typedef struct{
	float      CenterGain_dB;
	float      SrdGain_dB;
	float      FrontGain_dB;
	uint8_t    En;
}Surround3DPara_t;

#if(EFFECT_SURROUND3D_EN)
void  Surround3DNew(Surround3DPara_t *pPara, Surround3DStru_t *pStru);
void  Surround3D(int32_t *pDataL, int32_t *pDataR, Surround3DStru_t *pStru, uint16_t Len);
#endif
#endif /* SURROUND3D_H_ */
