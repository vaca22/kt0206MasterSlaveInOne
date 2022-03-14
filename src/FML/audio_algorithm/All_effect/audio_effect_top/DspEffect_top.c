/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "DspEffect_top.h"
#include "swi.h"
#include "reg_eft.h"
#include "gpio_ctrl.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/*
 * LOCAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */


/*
 * EXPORTED FUNCTION DEFINITIONS
 ****************************************************************************************
 */
uint32_t DspEffectStru_Alc(DspEffect_t *pDspEft, uint32_t addr)
{
	uint32_t TmpAddr = addr;

	/* EQ */
	EqInit(&pDspEft->EqB15MonoStru, EQ_MONO, 15);
	uint32_t ii;
	for(ii=0;ii<15;ii++)
	{
		pDspEft->EqB15MonoStru.pPara[ii] = (EqCoeffPara_t *)TmpAddr;
		TmpAddr += sizeof(EqCoeffPara_t);
		pDspEft->EqB15MonoStru.pStru[ii] = (EqFiltStru_t  *)TmpAddr;
		TmpAddr += pDspEft->EqB15MonoStru.StruSize;
	}
    /* Echo */
	pDspEft->pEchoPara = (EchoPara_t *)TmpAddr;
	TmpAddr += sizeof(EchoPara_t);

	pDspEft->pEchoStru = (EchoStru_t *)TmpAddr;
	TmpAddr += sizeof(EchoStru_t);

	pDspEft->pVolEchoPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDspEft->pVolEchoStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Reverb */
	pDspEft->pReverbPara = (ReverbPara_t *)TmpAddr;
	TmpAddr += sizeof(ReverbPara_t);

	pDspEft->pReverbStru = (ReverbStru_t *)TmpAddr;
	TmpAddr += sizeof(ReverbStru_t);

	pDspEft->pVolRvbPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDspEft->pVolRvbStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Dry Volume */
	pDspEft->pVolDryPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDspEft->pVolDryStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Freqshift & Howl */
	pDspEft->pFreqShiftPara = (FreqShiftPara_t *)TmpAddr;
	TmpAddr += sizeof(FreqShiftPara_t);

	pDspEft->pFreqShiftStru = (FreqShiftStru_t *)TmpAddr;
	TmpAddr += sizeof(FreqShiftStru_t);

	pDspEft->pHowlPara = (HowlPara_t *)TmpAddr;
	TmpAddr += sizeof(HowlPara_t);

	pDspEft->pHowlStru = (HowlStru_t *)TmpAddr;
	TmpAddr += sizeof(HowlStru_t);

	/* Noise Gate */
	pDspEft->pNoiseGatePara = (NoiseGatePara_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGatePara_t);

	pDspEft->pNoiseGateStru = (NoiseGateStru_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGateStru_t);

	/* Pitch Shift */
	pDspEft->pPsWsolaPara = (PitchShiftWsolaPara_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaPara_t);

	pDspEft->pPsWsolaStru = (PitchShiftWsolaStru_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaStru_t);

	/* other */
	pDspEft->pDownSampStru = (DownsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(DownsampleStru_t);

	pDspEft->pUpSampStru = (UpsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(UpsampleStru_t);

//	if(NULL == pDSPAll)
//	{
//		pDSPAll = (un_DSPRegAll_t *)TmpAddr;
//		TmpAddr += sizeof(un_DSPRegAll_t);
//	}
	pDspEft->WrapBuff512p.BlockSize = 32;
	pDspEft->WrapBuff512p.FrameSize = 512;
	pDspEft->WrapBuff512p.pBuffFrame = (q31_t *)TmpAddr;
	TmpAddr += (pDspEft->WrapBuff512p.FrameSize*2) << 2;

	if(addr == (uint32_t)NULL)
	{
		nds32_set_q31(0, (q31_t *)(pDspEft), sizeof(DspEffect_t)>>2);
		return TmpAddr;
	}

	q31_t *TmpQ31 = SWI_WrapBuf_Init(&pDspEft->WrapBuff512p);
	TmpAddr = (uint32_t)TmpQ31;
	nds32_set_q31(0, (q31_t *)addr, (TmpAddr-addr)>>2);


	pDspEft->pVolDryPara->step  = 8;
	pDspEft->pVolEchoPara->step = 8;
	pDspEft->pVolRvbPara->step  = 8;
	pDspEft->pTmpBuff32x4  = (int32_t *)0x000542bc;
//	pDspEft->pTmpBuff512x2 = (int32_t *)0x000552e8;
	return TmpAddr;
}

void DspEffectPath(DspEffect_t *pDspEft, int32_t *pData, uint32_t Len)
{
	int32_t *pTmpBuff  = pDspEft->pTmpBuff32x4;
	int32_t *pMidBuff  = pTmpBuff;
	int32_t *pTmpLenx3 = pTmpBuff + Len;
	int32_t *pWrapRead;

	if(pDspEft == NULL)
	{
		return;
	}
	NoiseGate(pData, pDspEft->pNoiseGateStru, Len);
	if(pDspEft->Prc512pOpen)
	{
		pWrapRead = SWI_WrapBuf_ReadBlock(&pDspEft->WrapBuff512p);
	}
	else
	{
		pWrapRead = pData;
	}
	//first read
	nds32_dup_q31(pWrapRead, pMidBuff, Len);
	//then write
	bool trigger0 = SWI_WrapBuf_WriteBlock(&pDspEft->WrapBuff512p, pData);
	if(trigger0 == true) {
		Gen_SWI();
	}

	FreqShiftTop  (pMidBuff,  pDspEft->pFreqShiftStru, pTmpLenx3, Len);
	HowlSupressTop(pMidBuff,  pDspEft->pHowlStru,      pTmpLenx3, Len);
	EqMono        (pMidBuff, &pDspEft->EqB15MonoStru,             Len);

	int32_t *pDown2x  = pTmpLenx3;
	int32_t *pEcho    = pTmpLenx3  + (Len>>1);
	int32_t *pReverb0 = pTmpLenx3  + Len;
	int32_t *pReverb1 = pTmpLenx3  + Len + (Len>>1);
	uint32_t OutLen = 0;
	nds32_dup_q31(pMidBuff, pData, Len);

	DownSample(pMidBuff, pDown2x, pDspEft->pDownSampStru, 3, Len, &OutLen);
	nds32_dup_q31(pDown2x,  pEcho, OutLen);
	Echo_Wet(pEcho, pDspEft->pEchoStru, OutLen);
	Reverb_wet(pDspEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
	nds32_add_q31(pReverb0, pReverb1, pReverb0, OutLen);
	VolumeMono(pEcho,    pDspEft->pVolEchoStru, OutLen);
	VolumeMono(pReverb0, pDspEft->pVolRvbStru,  OutLen);
	nds32_add_q31(pEcho, pReverb0, pEcho, OutLen);
	UpSample     (pEcho, pReverb0, pDspEft->pDownSampStru, pDspEft->pUpSampStru, 3, OutLen, Len);
	VolumeMono(pData, pDspEft->pVolDryStru, Len);
	nds32_add_q31(pReverb0, pData, pData, Len);
//	nds32_set_q31(0, pData, Len);
}

void DspEffect512P(DspEffect_t *pDspEft)
{
	int32_t *pTmp = SWI_WrapBuf_GetFrame(&pDspEft->WrapBuff512p);
	PitchShiftWsola(pDspEft->pPsWsolaStru, pTmp, pDspEft->pTmpBuff512x2, 512);
}

void DspI2Ssalve_SWI_ISR(DspEffect_t *pDspEft, uint32_t id)
{
	DspEffect512P(pDspEft);
	Clear_SWI();
}
