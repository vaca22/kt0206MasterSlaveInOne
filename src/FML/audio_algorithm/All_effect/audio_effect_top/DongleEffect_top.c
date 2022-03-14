/*
 * DongleEffect_top.c
 *
 *  Created on: Mar 6, 2020
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "DongleEffect_top.h"
#include "reg_eft.h"
#include "swi.h"
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
DongleEffect_t *g_st_pDongleEft = NULL;
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

uint32_t DongleEffectStru_Alc_MonoIn  (DongleEffect_t *pDongleEft, uint32_t addr)
{
	uint32_t TmpAddr = addr;
	if(NULL == pDongleEft)
	{
		return 0;
	}
	nds32_set_q31(0, (q31_t *)(pDongleEft), sizeof(DongleEffect_t)>>2);
	/* EQ */
	EqInit(&pDongleEft->EqB15Stru, EQ_MONO, 15);
	uint32_t ii;
	for(ii=0;ii<15;ii++)
	{
		pDongleEft->EqB15Stru.pPara[ii] = (EqCoeffPara_t *)TmpAddr;
		TmpAddr += sizeof(EqCoeffPara_t);
		pDongleEft->EqB15Stru.pStru[ii] = (EqFiltStru_t  *)TmpAddr;
		TmpAddr += pDongleEft->EqB15Stru.StruSize;
	}
    /* Echo */
	pDongleEft->pEchoPara = (EchoPara_t *)TmpAddr;
	TmpAddr += sizeof(EchoPara_t);

	pDongleEft->pEchoStru = (EchoStru_t *)TmpAddr;
	TmpAddr += sizeof(EchoStru_t);

	pDongleEft->pVolEchoPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDongleEft->pVolEchoStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Reverb */
	pDongleEft->pReverbPara = (ReverbPara_t *)TmpAddr;
	TmpAddr += sizeof(ReverbPara_t);

	pDongleEft->pReverbStru = (ReverbStru_t *)TmpAddr;
	TmpAddr += sizeof(ReverbStru_t);

	pDongleEft->pVolRvbPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDongleEft->pVolRvbStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Dry Volume */
	pDongleEft->pVolDryPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pDongleEft->pVolDryStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	/* Freqshift & Howl */
	pDongleEft->pFreqShiftPara = (FreqShiftPara_t *)TmpAddr;
	TmpAddr += sizeof(FreqShiftPara_t);

	pDongleEft->pFreqShiftStru = (FreqShiftStru_t *)TmpAddr;
	TmpAddr += sizeof(FreqShiftStru_t);

	pDongleEft->pHowlPara = (HowlPara_t *)TmpAddr;
	TmpAddr += sizeof(HowlPara_t);

	pDongleEft->pHowlStru = (HowlStru_t *)TmpAddr;
	TmpAddr += sizeof(HowlStru_t);

	/* Noise Gate */
	pDongleEft->pNoiseGatePara = (NoiseGatePara_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGatePara_t);

	pDongleEft->pNoiseGateStru = (NoiseGateStru_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGateStru_t);

	/* Pitch Shift */
	pDongleEft->pPsWsolaPara = (PitchShiftWsolaPara_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaPara_t);

	pDongleEft->pPsWsolaStru = (PitchShiftWsolaStru_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaStru_t);

	/* other */
	pDongleEft->pDownSampStru = (DownsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(DownsampleStru_t);

	pDongleEft->pUpSampStruL = (UpsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(UpsampleStru_t);

	pDongleEft->pUpSampStruR = (UpsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(UpsampleStru_t);

//	if(NULL == pDSPAll)
//	{
//		pDSPAll = (un_DSPRegAll_t *)TmpAddr;
//		TmpAddr += sizeof(un_DSPRegAll_t);
//	}
	pDongleEft->WrapBuff512p.BlockSize = 32;
	pDongleEft->WrapBuff512p.FrameSize = 512;
	pDongleEft->WrapBuff512p.pBuffFrame = (q31_t *)TmpAddr;
	TmpAddr += (pDongleEft->WrapBuff512p.FrameSize*2) << 2;

	if(addr == (uint32_t)NULL)
	{
		nds32_set_q31(0, (q31_t *)(pDongleEft), sizeof(DongleEffect_t)>>2);
		return TmpAddr;
	}

	q31_t *TmpQ31 = SWI_WrapBuf_Init(&pDongleEft->WrapBuff512p);
	TmpAddr = (uint32_t)TmpQ31;
	nds32_set_q31(0, (q31_t *)addr, (TmpAddr-addr)>>2);


	pDongleEft->pVolDryPara->step  = 8;
	pDongleEft->pVolEchoPara->step = 8;
	pDongleEft->pVolRvbPara->step  = 8;
	pDongleEft->pTmpBuffBlkx4  = (int32_t *)0x000552e8;
//	pDongleEft->pTmpBuff512x2 = (int32_t *)0x000552e8;
	return TmpAddr;
}

uint32_t DongleEffectStru_Alc_StereoIn(DongleEffect_t *pDongleEft, uint32_t addr)
{
	uint32_t TmpAddr = addr;

	if(NULL == pDongleEft)
	{
		return 0;
	}
	nds32_set_q31(0, (q31_t *)(pDongleEft), sizeof(DongleEffect_t)>>2);
	EqInit(&pDongleEft->EqB15Stru, EQ_STEREO, 15);
	uint32_t ii;
	for(ii=0;ii<15;ii++)
	{
		pDongleEft->EqB15Stru.pPara[ii] = (EqCoeffPara_t *)TmpAddr;
		TmpAddr += sizeof(EqCoeffPara_t);
		pDongleEft->EqB15Stru.pStru[ii] = (EqFiltStru_t  *)TmpAddr;
		TmpAddr += pDongleEft->EqB15Stru.StruSize;
	}

	/*SRS 3D */
	pDongleEft->pSrd3DPara = (Surround3DPara_t *)TmpAddr;
	TmpAddr += sizeof(Surround3DPara_t);

	pDongleEft->pSrd3DStru = (Surround3DStru_t *)TmpAddr;
	TmpAddr += sizeof(Surround3DStru_t);

//	pDSPAll = (un_DSPRegAll_t *)TmpAddr;
//	TmpAddr += sizeof(un_DSPRegAll_t);

	if(addr == (uint32_t)NULL)
	{
		nds32_set_q31(0, (q31_t *)(pDongleEft), sizeof(DongleEffect_t)>>2);
		return TmpAddr;
	}
	nds32_set_q31(0, (q31_t *)addr, (TmpAddr-addr)>>2);
	pDongleEft->pTmpBuffBlkx4  = (int32_t *)0x000542bc; //0x000552e8(0x4e0) 0x000542bc(0x2ac)
	return TmpAddr;
}

void DongleEffectPath_StereoIn(DongleEffect_t *pDongleEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len)
{
	if(NULL == pDongleEft)
	{
		return;
	}
	EqStereo        (pDataL, pDataR, &pDongleEft->EqB15Stru,             Len);
	Surround3D      (pDataL, pDataR, pDongleEft->pSrd3DStru,             Len);

}

void DongleEffectPath_MonoIn  (DongleEffect_t *pDongleEft, int32_t *pSrc, int32_t *pDstL, int32_t *pDstR, uint32_t Len)
{
	int32_t *pTmpBuff  = pDongleEft->pTmpBuffBlkx4;
	int32_t *pMidBuff  = pTmpBuff;
	int32_t *pTmpLenx3 = pTmpBuff + Len;
	int32_t *pWrapRead;

	if(NULL == pDongleEft)
	{
		return;
	}
	NoiseGate(pSrc, pDongleEft->pNoiseGateStru, Len);
	if(pDongleEft->Prc512pOpen)
	{
		pWrapRead = SWI_WrapBuf_ReadBlock(&pDongleEft->WrapBuff512p);
	}
	else
	{
		pWrapRead = pSrc;
	}
	//first read
	nds32_dup_q31(pWrapRead, pMidBuff, Len);
	//then write
	bool trigger0 = SWI_WrapBuf_WriteBlock(&pDongleEft->WrapBuff512p, pSrc);
	if(trigger0 == true) {
		Gen_SWI();
	}

	FreqShiftTop  (pMidBuff,  pDongleEft->pFreqShiftStru, pTmpLenx3, Len);
	HowlSupressTop(pMidBuff,  pDongleEft->pHowlStru,      pTmpLenx3, Len);
	EqMono        (pMidBuff, &pDongleEft->EqB15Stru,             Len);

	int32_t *pDown2x  = pTmpLenx3;
	int32_t *pEcho    = pTmpLenx3  + (Len>>1);
	int32_t *pReverb0 = pTmpLenx3  + Len;
	int32_t *pReverb1 = pTmpLenx3  + Len + (Len>>1);
	uint32_t OutLen = 0;
	nds32_dup_q31(pMidBuff, pSrc, Len);

	DownSample(pSrc, pDown2x, pDongleEft->pDownSampStru, 3, Len, &OutLen);
	nds32_dup_q31(pDown2x,  pEcho, OutLen);
	Echo_Wet(pEcho, pDongleEft->pEchoStru, OutLen);
	Reverb_wet(pDongleEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
	VolumeMono(pEcho,    pDongleEft->pVolEchoStru, OutLen);
	VolumeStereo(pReverb0, pReverb1, pDongleEft->pVolRvbStru, OutLen);
	nds32_add_q31(pEcho, pReverb0, pReverb0, OutLen);
	nds32_add_q31(pEcho, pReverb1, pReverb1, OutLen);
	UpSample     (pReverb0, pDstL, pDongleEft->pDownSampStru, pDongleEft->pUpSampStruL, 3, OutLen, Len);
	UpSample     (pReverb1, pDstR, pDongleEft->pDownSampStru, pDongleEft->pUpSampStruR, 3, OutLen, Len);

	VolumeMono(pMidBuff, pDongleEft->pVolDryStru, Len);
	nds32_add_q31(pMidBuff, pDstL, pDstL, Len);
	nds32_add_q31(pMidBuff, pDstR, pDstR, Len);
}

void DongleEffect512P_SWI_ISR   (uint32_t id)
{
	DongleEffect512P(g_st_pDongleEft);
	Clear_SWI();
}

void DongleEffect512P(DongleEffect_t *pDongleEft)
{
	if(NULL == pDongleEft)
	{
		return;
	}
	int32_t *pTmp = SWI_WrapBuf_GetFrame(&pDongleEft->WrapBuff512p);
	PitchShiftWsola(pDongleEft->pPsWsolaStru, pTmp, pDongleEft->pTmpBuff512x2, 512);
}
