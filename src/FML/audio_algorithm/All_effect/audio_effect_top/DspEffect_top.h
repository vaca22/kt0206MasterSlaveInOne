#ifndef __DSPEFFECT_TOP_H__
#define __DSPEFFECT_TOP_H__

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

	UpsampleStru_t   *pUpSampStru;
	DownsampleStru_t *pDownSampStru;
	SWI_WrapBuf_t     WrapBuff512p;
	int32_t          *pTmpBuff512x2;
	int32_t          *pTmpBuff32x4;
	int32_t          *pEchoBuff;
	int32_t          *pFreqShiftBuff;
	int32_t          *pRvbBuff;
	int32_t          *pPitchShiftBuff;
	EqStru_t          EqB15MonoStru;
	uint8_t           Prc512pOpen;
}DspEffect_t;
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
uint32_t DspEffectStru_Alc(DspEffect_t *pDspEft, uint32_t addr);
void     DspI2Ssalve_SWI_ISR(DspEffect_t *pDspEft, uint32_t id);
void     DspEffectPath(DspEffect_t *pDspEft, int32_t *pData, uint32_t Len);
void     DspEffect512P(DspEffect_t *pDspEft);

#endif /* DSPEFFECT_TOP_H_ */
