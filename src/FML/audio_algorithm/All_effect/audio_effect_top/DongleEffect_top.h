/*
 * DongleEffect_top.h
 *
 *  Created on: Mar 6, 2020
 *      Author: guoax
 */

#ifndef DONGLEEFFECT_TOP_H_
#define DONGLEEFFECT_TOP_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>
#include <nds32_intrinsic.h>
#include "nds32_math_types.h"
#include "comm.h"
#include "ModuleInfo.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef struct
{
	EchoPara_t       *pEchoPara;
	EchoStru_t       *pEchoStru;
	VolumePara_t     *pVolEchoPara;
	VolumeStru_t     *pVolEchoStru;

	ReverbPara_t     *pReverbPara;
	ReverbStru_t     *pReverbStru;
	VolumePara_t     *pVolRvbPara;
	VolumeStru_t     *pVolRvbStru;

	VolumePara_t     *pVolDryPara;
	VolumeStru_t     *pVolDryStru;

	FreqShiftPara_t  *pFreqShiftPara;
	FreqShiftStru_t  *pFreqShiftStru;
	HowlPara_t       *pHowlPara;
	HowlStru_t       *pHowlStru;

	NoiseGatePara_t  *pNoiseGatePara;
	NoiseGateStru_t  *pNoiseGateStru;

	PitchShiftWsolaPara_t *pPsWsolaPara;
	PitchShiftWsolaStru_t *pPsWsolaStru;

	Surround3DPara_t *pSrd3DPara;
	Surround3DStru_t *pSrd3DStru;

	UpsampleStru_t   *pUpSampStruL;
	UpsampleStru_t   *pUpSampStruR;
	DownsampleStru_t *pDownSampStru;
	SWI_WrapBuf_t     WrapBuff512p;
	int32_t          *pTmpBuff512x2;
	int32_t          *pTmpBuffBlkx4;
	int32_t          *pEchoBuff;
	int32_t          *pFreqShiftBuff;
	int32_t          *pRvbBuff;
	int32_t          *pPitchShiftBuff;
	EqStru_t          EqB15Stru;
	uint8_t           Prc512pOpen;
}DongleEffect_t;

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern DongleEffect_t *g_st_pDongleEft;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
uint32_t DongleEffectStru_Alc_MonoIn  (DongleEffect_t *pDongleEft, uint32_t addr);
uint32_t DongleEffectStru_Alc_StereoIn(DongleEffect_t *pDongleEft, uint32_t addr);
void     DongleEffectPath_MonoIn      (DongleEffect_t *pDongleEft, int32_t *pSrc, int32_t *pDstL, int32_t *pDstR, uint32_t Len);
void     DongleEffectPath_StereoIn    (DongleEffect_t *pDongleEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len);
void     DongleEffect512P(DongleEffect_t *pDongleEft);

#endif /* DONGLEEFFECT_TOP_H_ */
