/*
 * HeadsetEffect_top.c
 *
 *  Created on: Mar 6, 2020
 *      Author: guoax
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "chipEffect_top.h"
#include "reg_eft.h"
#include "timer.h"
#include "volume.h"
#include "wav.h"
#include "uswi_asrc.h"
#include "usb_app.h"
#include "swi.h"
#include "gpio_ctrl.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define THREE_BAND_PEAK_DET_EN	0	//detect low/medium/high freq and do some LED effect

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */
#if EFFECT_POST_SIDETONE_EN
	#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
		int32_t g_Adc2DacL[48]={0};
		int32_t g_Adc2DacR[48]={0};
	#else
		int32_t g_Adc2Dac[48]={0};
	#endif
#endif
#if ((EFFECT_PITCHSHIFT_EN == 1) || (EFFECT_ECHO_EN == 1) || (EFFECT_REVERB_EN == 1) || (THREE_BAND_PEAK_DET_EN == 1))
	int32_t g_Buff4k[512*2];
#endif
ChipEffect_t *g_st_pHeadsetEft = NULL;
uint8_t usb2dacMute=0;
extern wavStruc_t wavInfo;
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

uint32_t HeadsetEffect_StruAlc(ChipEffect_t *pHeadsetEft, uint32_t addr)
{
	uint32_t TmpAddr = addr;

	if(NULL == pHeadsetEft)
	{
		return 0;
	}
	nds32_set_q31(0, (q31_t *)(pHeadsetEft), sizeof(ChipEffect_t)>>2);
	#if(EFFECT_EQ_EN)
	uint32_t ii;
	EqInit(&pHeadsetEft->EqB15Stru, EQ_STEREO, 15);
	for(ii=0;ii<15;ii++)
	{
		pHeadsetEft->EqB15Stru.pPara[ii] = (EqCoeffPara_t *)TmpAddr;
		TmpAddr += sizeof(EqCoeffPara_t);
		pHeadsetEft->EqB15Stru.pStru[ii] = (EqFiltStru_t  *)TmpAddr;
		TmpAddr += pHeadsetEft->EqB15Stru.StruSize;
	}

	#if (AUDIO_IN_STEREO == 1)
	EqInit(&pHeadsetEft->EqB5Stru, EQ_STEREO, 5);
	#else
	EqInit(&pHeadsetEft->EqB5Stru, EQ_MONO, 5);
	#endif
	for(ii=0;ii<5;ii++)
	{
		pHeadsetEft->EqB5Stru.pPara[ii] = (EqCoeffPara_t *)TmpAddr;
		TmpAddr += sizeof(EqCoeffPara_t);
		pHeadsetEft->EqB5Stru.pStru[ii] = (EqFiltStru_t  *)TmpAddr;
		TmpAddr += pHeadsetEft->EqB5Stru.StruSize;
	}
	#endif
	pHeadsetEft->pVolDryPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pHeadsetEft->pVolDryStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);

	#if EFFECT_REVERB_EN
	/* Reverb */
	pHeadsetEft->pReverbPara = (ReverbPara_t *)TmpAddr;
	TmpAddr += sizeof(ReverbPara_t);

	pHeadsetEft->pReverbStru = (ReverbStru_t *)TmpAddr;
	TmpAddr += sizeof(ReverbStru_t);

	pHeadsetEft->pVolRvbPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pHeadsetEft->pVolRvbStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);
	#endif

	#if EFFECT_ECHO_EN
	/* Echo */
	pHeadsetEft->pEchoPara = (EchoPara_t *)TmpAddr;
	TmpAddr += sizeof(EchoPara_t);

	pHeadsetEft->pEchoStru = (EchoStru_t *)TmpAddr;
	TmpAddr += sizeof(ReverbStru_t);

	pHeadsetEft->pVolEchoPara = (VolumePara_t *)TmpAddr;
	TmpAddr += sizeof(VolumePara_t);

	pHeadsetEft->pVolEchoStru = (VolumeStru_t *)TmpAddr;
	TmpAddr += sizeof(VolumeStru_t);
	#endif

	#if EFFECT_PITCHSHIFT_EN
	/* Pitch Shift */
	pHeadsetEft->pPsWsolaPara = (PitchShiftWsolaPara_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaPara_t);

	pHeadsetEft->pPsWsolaStru = (PitchShiftWsolaStru_t *)TmpAddr;
	TmpAddr += sizeof(PitchShiftWsolaStru_t);
	#endif

	#if EFFECT_NOISEGATE_EN
	/* Noise Gate */
	pHeadsetEft->pNoiseGatePara = (NoiseGatePara_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGatePara_t);

	pHeadsetEft->pNoiseGateStru = (NoiseGateStru_t *)TmpAddr;
	TmpAddr += sizeof(NoiseGateStru_t);
	#endif

	/* Expander */
	pHeadsetEft->pExpanderPara = (CompanderPara_t *)TmpAddr;
	TmpAddr += sizeof(CompanderPara_t);

	pHeadsetEft->pExpanderStru = (CompanderStru_t *)TmpAddr;
	TmpAddr += sizeof(CompanderStru_t);

	#if EFFECT_LIMITER_EN
	/*Limiter */
	pHeadsetEft->pLimiterPara = (LimiterPara_t *)TmpAddr;
	TmpAddr += sizeof(LimiterPara_t);

	pHeadsetEft->pLimiterStru = (LimiterStru_t *)TmpAddr;
	TmpAddr += sizeof(LimiterStru_t);
	#endif

	#if EFFECT_AGC_EN
	/*Agc */
	pHeadsetEft->pAgcPara = (AgcPara_t *)TmpAddr;
	TmpAddr += sizeof(AgcPara_t);

	pHeadsetEft->pAgcStru = (AgcStru_t *)TmpAddr;
	TmpAddr += sizeof(AgcStru_t);
	#endif

	#if EFFECT_SURROUND3D_EN
	/*SRS 3D */
	pHeadsetEft->pSrd3DPara = (Surround3DPara_t *)TmpAddr;
	TmpAddr += sizeof(Surround3DPara_t);

	pHeadsetEft->pSrd3DStru = (Surround3DStru_t *)TmpAddr;
	TmpAddr += sizeof(Surround3DStru_t);

	pHeadsetEft->pSrdMovePara = (SurroundMovePara_t *)TmpAddr;
	TmpAddr += sizeof(SurroundMovePara_t);
	pHeadsetEft->pSrdMoveStru = (SurroundMoveStru_t *)TmpAddr;
	TmpAddr += sizeof(SurroundMoveStru_t);
	#endif
	
	/*Side Tone */
	pHeadsetEft->pSideTonePara = (SideTonePara_t *)TmpAddr;
	TmpAddr += sizeof(SideTonePara_t);

	pHeadsetEft->pSideToneStru = (SideToneStru_t *)TmpAddr;
	TmpAddr += sizeof(SideToneStru_t);

	/*Music Ducking */
	pHeadsetEft->pMusicDuckingPara = (MusicDuckingPara_t *)TmpAddr;
	TmpAddr += sizeof(MusicDuckingPara_t);

	pHeadsetEft->pMusicDuckingStru = (MusicDuckingStru_t *)TmpAddr;
	TmpAddr += sizeof(MusicDuckingStru_t);

	pHeadsetEft->pPeakDet3BandPara = (PeakDet3BandPara_t *)TmpAddr;
	TmpAddr += sizeof(PeakDet3BandPara_t);
	pHeadsetEft->pPeakDet3BandStru = (PeakDet3BandStru_t *)TmpAddr;
	TmpAddr += sizeof(PeakDet3BandStru_t);
	/* other */
	pHeadsetEft->pDownSampStru = (DownsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(DownsampleStru_t);

	pHeadsetEft->pUpSampStruL = (UpsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(UpsampleStru_t);

	pHeadsetEft->pUpSampStruR = (UpsampleStru_t *)TmpAddr;
	TmpAddr += sizeof(UpsampleStru_t);

	// pHeadsetEft->pTmpBuffAddaBlkx4   = (int32_t *)TmpAddr;
	// TmpAddr += AUDIO_SAMPLE_BLOCK_SIZE*4*4;

	pHeadsetEft->WrapBuff512p.BlockSize = AUDIO_SAMPLE_BLOCK_SIZE;
	pHeadsetEft->WrapBuff512p.FrameSize = 512;
	uint32_t size  = SWI_WrapBuf_GetSize(&pHeadsetEft->WrapBuff512p);
	uint32_t pSwiBuff = TmpAddr;
	TmpAddr += size;

	pHeadsetEft->UsbOutRingBuf.BuffLenx2 = 96*5*2;
	pHeadsetEft->UsbOutRingBuf.pBuff     = (int32_t *)TmpAddr;
	size = (pHeadsetEft->UsbOutRingBuf.BuffLenx2)<<2;
	TmpAddr += size;

	if(addr == (uint32_t)NULL)
	{
		nds32_set_q31(0, (q31_t *)(pHeadsetEft), sizeof(ChipEffect_t)>>2);
		return TmpAddr;
	}
	nds32_set_q31(0, (q31_t *)addr, (TmpAddr-addr)>>2);
	SWI_WrapBuf_Init(&pHeadsetEft->WrapBuff512p, pSwiBuff);
//	pHeadsetEft->pSideToneBuff      = (int32_t *)0x000542bc;
	pHeadsetEft->pTmpBuffAddaBlkx4  = (int32_t *)0x00054264;
	pHeadsetEft->pTmpBuffUsbBlkx6   = (int32_t *)0x000552e8; //0x000552e8(0x4e0) 0x000542bc(0x2ac)
	pHeadsetEft->pVolRvbPara->step  = 8;
	pHeadsetEft->pVolEchoPara->step = 8;
	pHeadsetEft->pVolDryPara->step  = 8;
	pHeadsetEft->AdcInOpen  = 1;
	pHeadsetEft->DacOutOpen = 1;
	pHeadsetEft->UsbInOpen  = 0;
#if SIDETONE_ALWAYS_ON_EN
	pHeadsetEft->UsbOutOpen = 0;
#else
	pHeadsetEft->UsbOutOpen = 1;
#endif
	return TmpAddr;
}

void HeadsetEffect_AdcStereoin(ChipEffect_t *pHeadsetEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len)
{	
#if(EFFECT_EQ_EN)
	EqStereo(pDataL, pDataR, &pHeadsetEft->EqB5Stru, Len);
#endif

#if (EFFECT_POST_SIDETONE_EN == 1 && AUDIO_IN_STEREO == 1)
	nds32_dup_q31(pDataL, g_Adc2DacL, Len);
	nds32_dup_q31(pDataR, g_Adc2DacR, Len);
#endif
}
void HeadsetEffect_Adcin(ChipEffect_t *pHeadsetEft, int32_t *pData, uint32_t Len)
{
	int32_t *pMidBuff = pHeadsetEft->pTmpBuffAddaBlkx4;
	int32_t *pWrapRead;
	if(NULL == pHeadsetEft || 0 == pHeadsetEft->AdcInOpen)
	{
		return;
	}
	#if(EFFECT_COMPANDER_EN)
	ExpandSmall(pData, pHeadsetEft->pExpanderStru,  Len);
	#endif
	#if(EFFECT_NOISEGATE_EN)
	NoiseGate  (pData, pHeadsetEft->pNoiseGateStru, Len);
	#endif
	#if(EFFECT_AGC_EN)
	Agc        (pData, pHeadsetEft->pAgcStru,       Len);
	#endif
	if(pHeadsetEft->Prc512pOpen)
	{
		pWrapRead = SWI_WrapBuf_ReadBlock(&pHeadsetEft->WrapBuff512p);
		if(0 == pHeadsetEft->pPsWsolaStru->En)
		{
			nds32_dup_q31(pData,     pMidBuff, Len);
#if SIDETONE_ALWAYS_ON_EN
			if(0==pHeadsetEft->UsbInOpen)
#endif
			{
				VolumeMono   (pMidBuff,  pHeadsetEft->pVolDryStru, Len);
				nds32_add_q31(pWrapRead, pMidBuff, pMidBuff, Len);
			}
		}
		else
		{
			nds32_dup_q31(pWrapRead, pMidBuff, Len);
		}
	}
	else
	{
		nds32_dup_q31(pData, pMidBuff, Len);
	}
	//first read

	//then write
	bool trigger0 = SWI_WrapBuf_WriteBlock(&pHeadsetEft->WrapBuff512p, pData);	
	if(trigger0 == true) {
		timer_start(TIMER2, 5, HeadsetEffect_AdcIn512P_ISR, TIM_US);
	}
	#if(EFFECT_EQ_EN)
	EqMono     (pMidBuff, &pHeadsetEft->EqB5Stru,      Len);
	#endif
	nds32_dup_q31(pMidBuff, pData, Len);	
#if (EFFECT_POST_SIDETONE_EN == 1 && AUDIO_IN_STEREO == 0)
	nds32_dup_q31(pMidBuff, g_Adc2Dac, Len);
#endif
}

void HeadsetEffect_Usbin(ChipEffect_t *pHeadsetEft, int32_t *pSrc, int32_t *pDstL, int32_t *pDstR, uint32_t Len)
{
	int32_t *pDryData = pHeadsetEft->pTmpBuffUsbBlkx6;
	uint32_t Nx = 1;

	if(NULL==pHeadsetEft || 0 == pHeadsetEft->UsbInOpen || (0 == EFFECT_ECHO_EN && 0 == EFFECT_REVERB_EN))
	{
		nds32_dup_q31(pSrc, pDstL, Len);
		nds32_dup_q31(pSrc, pDstR, Len);
		return;
	}

	if(Len > 32) //44.1k; 48k
	{
		Nx = 3;
	}
	else if(Len > 16) // 32k
	{
		Nx = 2;
	}
	nds32_dup_q31(pSrc, pDryData, Len);
	if(Nx > 1)
	{

		#if((EFFECT_ECHO_EN==1)&&(EFFECT_REVERB_EN==0))
		int32_t *pDown2x  = pDryData + Len;
		uint32_t OutLen   = Len;
		int32_t *pEcho    = pDown2x;
		DownSample   (pSrc,    pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
		Echo_Wet     (pEcho,   pHeadsetEft->pEchoStru,    OutLen);
		VolumeMono   (pEcho,   pHeadsetEft->pVolEchoStru, OutLen);
		UpSample     (pEcho,   pDstL, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
		nds32_dup_q31(pDstL,   pDstR, Len);
		#elif((EFFECT_REVERB_EN==1)&&(EFFECT_ECHO_EN==0))
		int32_t *pDown2x  = pDryData + Len;
		uint32_t OutLen   = Len;
		int32_t *pReverb0 = pDryData + Len + (Len>>1);
		int32_t *pReverb1 = pDryData + Len + Len;
		DownSample   (pSrc, pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
		Reverb_wet   (pHeadsetEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
		VolumeStereo (pReverb0, pReverb1, pHeadsetEft->pVolRvbStru, OutLen);
		UpSample  (pReverb0, pDstL, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
		UpSample  (pReverb1, pDstR, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruR, Nx, OutLen, Len);
		#elif((EFFECT_REVERB_EN==1)&&(EFFECT_ECHO_EN==1))
		int32_t *pDown2x  = pDryData + Len;
		uint32_t OutLen   = Len;
		int32_t *pReverb0 = pDryData + Len + (Len>>1);
		int32_t *pReverb1 = pDryData + Len + Len;
		DownSample   (pSrc, pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
		Reverb_wet   (pHeadsetEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
		VolumeStereo (pReverb0, pReverb1, pHeadsetEft->pVolRvbStru, OutLen);
		Echo_Wet     (pDown2x,   pHeadsetEft->pEchoStru,    OutLen);
		VolumeMono   (pDown2x,   pHeadsetEft->pVolEchoStru, OutLen);
		nds32_add_q31(pDown2x,pReverb0,pReverb0,OutLen);
		nds32_add_q31(pDown2x,pReverb1,pReverb1,OutLen);
		UpSample     (pReverb0, pDstL, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
		UpSample     (pReverb1, pDstR, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruR, Nx, OutLen, Len);
		#endif
	}
	else
	{
		#if((EFFECT_ECHO_EN==1)&&(EFFECT_REVERB_EN==0))
		int32_t *pEcho = pSrc;
		Echo_Wet     (pEcho,   pHeadsetEft->pEchoStru,    Len);
		VolumeMono   (pEcho,   pHeadsetEft->pVolEchoStru, Len);
		nds32_dup_q31(pEcho,   pDstL, Len);
		nds32_dup_q31(pEcho,   pDstR, Len);
		#elif((EFFECT_ECHO_EN==0)&&(EFFECT_REVERB_EN==1))
		Reverb_wet   (pHeadsetEft->pReverbStru, pSrc, pDstL, pDstR, Len);
		VolumeStereo (pDstL, pDstR, pHeadsetEft->pVolRvbStru, Len);
		#elif((EFFECT_ECHO_EN==1)&&(EFFECT_REVERB_EN==1))
		Reverb_wet   (pHeadsetEft->pReverbStru, pSrc, pDstL, pDstR, Len);
		VolumeStereo (pDstL, pDstR, pHeadsetEft->pVolRvbStru, Len);
		Echo_Wet     (pSrc,   pHeadsetEft->pEchoStru,    Len);
		VolumeMono   (pSrc,   pHeadsetEft->pVolEchoStru, Len);
		nds32_add_q31(pSrc, pDstL,  pDstL, Len);
		nds32_add_q31(pSrc, pDstR,  pDstR, Len);
		#endif
	}
	VolumeMono   (pDryData,     pHeadsetEft->pVolDryStru, Len);
	nds32_add_q31(pDryData, pDstL, pDstL, Len);
	nds32_add_q31(pDryData, pDstR, pDstR, Len);
	return;
}

// #if ((SIDETONE_ALWAYS_ON_EN == 1) && (SIDETONE_AUTO_CTRL_EN == 1))
uint32_t UsbDataInValidCounter=0;
// #endif
void HeadsetEffect_Dacout(ChipEffect_t *pHeadsetEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len)
{
	#if (EFFECT_POST_SIDETONE_EN && (AUDIO_IN_SEL == 2 || AUDIO_IN_SEL == 3))
		stUSB_Audio_Attr stAudioAttrOut = {0};
		Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttrOut,sizeof(stUSB_Audio_Attr));
		if (stAudioAttrOut.u8Status == FALSE)
		{
			nds32_dup_q31(&g_I2SIn2DacBuf[0],  g_Adc2DacL, Len);
			nds32_dup_q31(&g_I2SIn2DacBuf[48], g_Adc2DacR, Len);
			swiI2SIn2DACFlag = 1;
			Gen_SWI();
		}
	#endif

	if(NULL == pHeadsetEft)
	{
		return;
	}
	int32_t *pTmpBuff = pHeadsetEft->pTmpBuffAddaBlkx4 + Len;
	#if(EFFECT_SURROUND3D_EN)
	Surround3D   (pDataL, pDataR, pHeadsetEft->pSrd3DStru, Len);
	#endif
	#if(EFFECT_EQ_EN)
	EqStereo     (pDataL, pDataR, &pHeadsetEft->EqB15Stru,  Len);
	#endif
#if(EFFECT_SURROUNDMOVE_EN)
	SurroundMove (pHeadsetEft->pSrdMoveStru, pDataL, pDataR, pTmpBuff, Len);
#endif

#if EFFECT_POST_SIDETONE_EN
	if((0 == pHeadsetEft->UsbOutOpen) && (0 == pHeadsetEft->UsbInOpen) \
	&& ((g_mute_bit & BIT_MIC) == 0)\
	&& ((g_mute_bit & BIT_ST) == 0)\
	&& ((stUsbAudio.u8Mute & BIT_MIC) == 0)\
	&& ((stUsbAudio.u8Mute & BIT_ST) == 0))
	{
	// #if SIDETONE_AUTO_CTRL_EN
		uint8_t cnt;
		for (cnt = 0; cnt < 48; cnt++)
		{
			if (__nds32__abs(pDataL[cnt]) > 0x700 || __nds32__abs(pDataR[cnt]) > 0x700)
			{
				UsbDataInValidCounter = 0;
				break;
			}
		}
		UsbDataInValidCounter++;
		if (UsbDataInValidCounter > 600) //3=1ms  600=200ms
		{
			GPIO_FuncSet( GPIO5, GPIO_DigOutput0 );
			#if SIDETONE_AUTO_CTRL_EN
			#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
			memset(g_Adc2DacL, 0, 48 << 2);
			memset(g_Adc2DacR, 0, 48 << 2);
			#else
			memset(g_Adc2Dac, 0, 48 << 2);
			#endif
			#endif
		}
		else{
			GPIO_FuncSet( GPIO5, GPIO_DigOutput1 );
		}
	// #endif
		uint16_t vol_st  = volume_table[dsp_adc2dac_vol];
		#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
		int64_t vol_buff_st = g_adc2dac_vol_buff;
		Dsp24bitVolumeSmooth(g_Adc2DacL, g_Adc2DacL, vol_st,  &vol_buff_st, Len);
		Dsp24bitVolumeSmooth(g_Adc2DacR, g_Adc2DacR, vol_st,  &g_adc2dac_vol_buff, Len);
		SideToneAdd(pHeadsetEft->pSideToneStru,pHeadsetEft->pMusicDuckingStru,
					g_Adc2DacL,					g_Adc2DacR,
					pDataL,						pDataR,
					pTmpBuff,					Len,Len);
		#else
		Dsp24bitVolumeSmooth(g_Adc2Dac, g_Adc2Dac, vol_st,  &g_adc2dac_vol_buff, Len);
		SideToneAdd(pHeadsetEft->pSideToneStru,pHeadsetEft->pMusicDuckingStru,
					g_Adc2Dac,					g_Adc2Dac,
					pDataL,						pDataR,
					pTmpBuff,					Len,Len);
		#endif
	}
#endif
	// LimiterStereo(pDataL, pDataR, pHeadsetEft->pLimiterStru, Len);
	uint16_t vol  = volume_table[dsp_usb2dac_vol_l];
	uint16_t vol1 = volume_table[dsp_usb2dac_vol_r];
#if WAV_EN
	wavPlayer(pDataL, pDataR, Len, &vol, &vol1);
	//if(wavInfo.playFlag == 1){}
#endif
	Dsp24bitVolumeSmooth(pDataL, pDataL, vol,  &g_usb2dac_vol_buff_l, Len);
	Dsp24bitVolumeSmooth(pDataR, pDataR, vol1, &g_usb2dac_vol_buff_r, Len);
	static int64_t vol_buff_l=0;
	static int64_t vol_buff_r=0;
	if((stUsbAudio.u8Mute & BIT_SPK) || (g_mute_bit & BIT_SPK))
	{
		Dsp24bitVolumeSmooth(pDataL,  pDataL, 0, &vol_buff_l,Len);
		Dsp24bitVolumeSmooth(pDataR,  pDataR, 0, &vol_buff_r,Len);
	}
	else
	{
		Dsp24bitVolumeSmooth(pDataL,  pDataL, g_dsp_gain_dacl<<2, &vol_buff_l,Len);
		Dsp24bitVolumeSmooth(pDataR,  pDataR, g_dsp_gain_dacr<<2, &vol_buff_r,Len);
	}
	
	if(pHeadsetEft->PrcOut512pOpen)
	{
		nds32_add_q31(pDataL, pDataR, pTmpBuff,Len);
		bool trigger0 = SWI_WrapBuf_WriteBlock(&pHeadsetEft->OutWrapBuff512p, pTmpBuff);
		if(trigger0 == true) {
			timer_start(TIMER2, 5, HeadsetEffect_DacOut512P_ISR, TIM_US);
		}
	}
	new_patch_audio_dac_rail_ctrl(pDataL, pDataR, pTmpBuff, Len);
}

void HeadsetEffect_Usbout(ChipEffect_t *pHeadsetEft, int32_t *pUsbInL, int32_t *pUsbInR, uint32_t LenIn, uint32_t LenOut)
{

	uint32_t  ii;
	int32_t  *pTmpBuff = pHeadsetEft->pTmpBuffUsbBlkx6;
	uint16_t  BuffLen = pHeadsetEft->UsbOutRingBuf.BuffLenx2 >> 1;
	int32_t  *pBuffL = pHeadsetEft->UsbOutRingBuf.pBuff;
	int32_t  *pBuffR = pBuffL + BuffLen;
	if(NULL == pHeadsetEft || 0 == pHeadsetEft->UsbOutOpen)
	{
		return;
	}
// #if (AUDIO_SAMPLE_BLOCK_SIZE == 16)
#if(1)
	uint16_t  LenRound = LenOut;
	uint16_t  rp = pHeadsetEft->UsbOutRingBuf.rp;
	uint16_t  wp = pHeadsetEft->UsbOutRingBuf.wp;
	uint16_t  op = pHeadsetEft->UsbOutRingBuf.op;
	uint32_t  RstResForRd = LenRound*2;  //
	uint32_t  ResForOp;
	uint32_t  ResForRd;
	uint8_t order=0;//order==1的时候，需要改变op的地址
	if(pHeadsetEft->AudioInStartFlag || pHeadsetEft->AudioOutStartFlag)
	{
		op = rp + RstResForRd;
		if(op >= BuffLen)
		{
			op -= BuffLen;
		}
		pHeadsetEft->UsbOutRingBuf.op = op;
		pHeadsetEft->AudioInStartFlag = 0;
		pHeadsetEft->AudioOutStartFlag = 0;
	}
	else{
		ResForOp = (wp >= op) ? (wp - op) : (BuffLen + wp - op);
		ResForRd = (op >= rp) ? (op - rp) : (BuffLen + op - rp);
		if(((wp>=rp)&&(rp>=op))||((rp>=op)&&(op>=wp))||((op>=wp)&&(wp>=rp)))
		{
			order=1;
		}
		if((ResForOp < LenOut) || (ResForRd < LenOut) || (order==1))
		{
			op = rp + RstResForRd;
			if(op >= BuffLen)
			{
				op -= BuffLen;
			}
			pHeadsetEft->UsbOutRingBuf.op = op;
		}
	}
#else
	uint16_t  rp = pHeadsetEft->UsbOutRingBuf.rp;
	uint16_t  op = rp;
#endif
	int32_t *pUsbOutL = pTmpBuff;
	int32_t *pUsbOutR = pTmpBuff+LenOut;

	uint16_t optmp = op;
    //read usb out data from ringbuff for operate
	for(ii=0; ii<LenOut; ii++)
	{
		pUsbOutL[ii]  = pBuffL[optmp];
		pUsbOutR[ii]  = pBuffR[optmp++];
		if(optmp >= BuffLen)
		{
			optmp = 0;
		}
	}
	//operate usb out data
// #if(EFFECT_POST_SIDETONE_EN)
// 	int32_t *pTmpLenOutx3 = pUsbOutR + LenOut;
// 	SideToneAdd(pHeadsetEft->pSideToneStru,  pHeadsetEft->pMusicDuckingStru,
// 				                   pUsbInL,                         pUsbInR,
// 				    	          pUsbOutL,                        pUsbOutR,
// 						      pTmpLenOutx3,                          LenOut,    LenIn);
// #endif
	//write operated data back to ringbuff
	for(ii=0; ii<LenOut; ii++)
	{
		pBuffL[op]   = pUsbOutL[ii];
		pBuffR[op++] = pUsbOutR[ii];
		if(op >= BuffLen)
		{
			op = 0;
		}
	}
	pHeadsetEft->UsbOutRingBuf.op = op;
}

void HeadsetEffect_AdcIn512P_ISR   (void)
{
	HeadsetEffect_AdcIn512P(g_st_pHeadsetEft);
}

void HeadsetEffect_AdcIn512P(ChipEffect_t *pHeadsetEft)
{
	if(NULL == pHeadsetEft)
	{
		return;
	}
#if ((EFFECT_PITCHSHIFT_EN == 1) || (EFFECT_ECHO_EN == 1) || (EFFECT_REVERB_EN == 1))
//	int32_t *pTmp = pHeadsetEft->pTmpBuff512x3;
//	int32_t *pTmpBuff512x2 = pTmp + 512;
	int32_t TmpData[512];
	int32_t *pTmp = TmpData;
	int32_t *pTmpBuff512x2 = g_Buff4k;
	SWI_WrapBuf_ReadFrame (&pHeadsetEft->WrapBuff512p, pTmp);
	#if(EFFECT_PITCHSHIFT_EN)
	PitchShiftWsola(pHeadsetEft->pPsWsolaStru, pTmp, pTmpBuff512x2, 512);
	#endif
#if SIDETONE_ALWAYS_ON_EN
	if(0==pHeadsetEft->UsbInOpen)
#endif
	{
	#if(EFFECT_ECHO_EN == 1 && EFFECT_REVERB_EN == 0)
	uint32_t Nx = 3;
	int32_t *pDryData = pTmp;
	int32_t *pTmp0    = pTmpBuff512x2;
	int32_t *pDown2x  = pTmpBuff512x2 + 512;
	uint32_t Len      = 512;
	uint32_t OutLen   = Len;
	nds32_dup_q31(pDryData, pTmp0, 512);
	DownSample   (pTmp0,    pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
	Echo_Wet     (pDown2x,   pHeadsetEft->pEchoStru,    OutLen);
	VolumeMono   (pDown2x,   pHeadsetEft->pVolEchoStru, OutLen);
	UpSample     (pDown2x,   pTmp0, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
	if(1 == pHeadsetEft->pPsWsolaStru->En)
	{
		VolumeMono   (pDryData,  pHeadsetEft->pVolDryStru, Len);
		nds32_add_q31(pDryData,  pTmp0,  pTmp,  Len);
	}
	else
	{
		nds32_dup_q31(pTmp0, pTmp, Len);
	}
	#elif(EFFECT_REVERB_EN == 1 && EFFECT_ECHO_EN == 0)
	uint32_t Nx = 3;
	int32_t *pDryData = pTmp;
	int32_t *pTmp0    = pTmpBuff512x2;
	int32_t *pDown2x  = pTmpBuff512x2 + 512;
	int32_t *pReverb0 = pTmp0;
	int32_t *pReverb1 = pTmp0 + (512>>1);
	uint32_t Len      = 512;
	uint32_t OutLen   = Len;
	nds32_dup_q31(pDryData, pTmp0, 512);
	DownSample   (pTmp0,    pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
	Reverb_wet   (pHeadsetEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
	VolumeMono   (pReverb0,  pHeadsetEft->pVolRvbStru,  OutLen);
	UpSample     (pReverb0,  pDown2x, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
	if(1 == pHeadsetEft->pPsWsolaStru->En)
	{
		VolumeMono   (pDryData,  pHeadsetEft->pVolDryStru, Len);
		nds32_add_q31(pDryData,  pDown2x,  pTmp,  Len);
	}
	else
	{
		nds32_dup_q31(pDown2x,   pTmp, Len);
	}
	#elif(EFFECT_REVERB_EN == 1 && EFFECT_ECHO_EN == 1)
	uint32_t Nx = 3;
	int32_t *pDryData = pTmp;
	int32_t *pTmp0    = pTmpBuff512x2;
	int32_t *pDown2x  = pTmpBuff512x2 + 512;
	int32_t *pReverb0 = pTmp0;
	int32_t *pReverb1 = pTmp0 + (512>>1);
	uint32_t Len      = 512;
	uint32_t OutLen   = Len;
	nds32_dup_q31(pDryData, pTmp0, 512);
	DownSample   (pTmp0,    pDown2x, pHeadsetEft->pDownSampStru, Nx, Len, &OutLen);
	Reverb_wet   (pHeadsetEft->pReverbStru, pDown2x, pReverb0, pReverb1, OutLen);
	VolumeMono   (pReverb0,  pHeadsetEft->pVolRvbStru,  OutLen);
	Echo_Wet     (pDown2x,   pHeadsetEft->pEchoStru,    OutLen);
	VolumeMono   (pDown2x,   pHeadsetEft->pVolEchoStru, OutLen);
	nds32_add_q31(pDown2x,   pReverb0, pDown2x, OutLen);
	UpSample     (pDown2x,   pTmp0, pHeadsetEft->pDownSampStru, pHeadsetEft->pUpSampStruL, Nx, OutLen, Len);
	if(1 == pHeadsetEft->pPsWsolaStru->En)
	{
		VolumeMono   (pDryData,  pHeadsetEft->pVolDryStru, Len);
		nds32_add_q31(pDryData,  pTmp0,  pTmp,  Len);
	}
	else
	{
		nds32_dup_q31(pTmp0, pTmp, Len);
	}
	#endif
	}
	SWI_WrapBuf_WriteFrame(&pHeadsetEft->WrapBuff512p, (const int32_t *)pTmp);
#endif /* ((EFFECT_PITCHSHIFT_EN == 1) || (EFFECT_ECHO_EN == 1) || (EFFECT_REVERB_EN == 1)) */
}

void HeadsetEffect_DacOut512P_ISR (void)
{
	HeadsetEffect_DacOut512P(g_st_pHeadsetEft);
}
void HeadsetEffect_DacOut512P(ChipEffect_t *pHeadsetEft)
{
#if SIDETONE_ALWAYS_ON_EN
	if(NULL == pHeadsetEft)
#else
	if(NULL == pHeadsetEft || NULL == pHeadsetEft->pTmpBuff512x3)
#endif
	{
		return;
	}
#if THREE_BAND_PEAK_DET_EN
	int32_t TmpData[512];
//	int32_t *pTmp = pHeadsetEft->pTmpBuff512x3;
//	int32_t *pTmpBuff512x2 = pTmp + 512;
	int32_t *pTmp = TmpData;
	int32_t *pTmpBuff512x2 = g_Buff4k;
	SWI_WrapBuf_ReadFrame (&pHeadsetEft->OutWrapBuff512p, pTmp);
	PeakDet3Band(pHeadsetEft->pPeakDet3BandStru, pTmp, NULL, pTmpBuff512x2, 512);
#endif
}
void HeadsetEffect_Usbout_DataRW(ChipEffect_t *pHeadsetEft, int32_t *pUsbOutL, int32_t *pUsbOutR, uint32_t Len)
{
	uint32_t ii;
	uint16_t  BuffLen = pHeadsetEft->UsbOutRingBuf.BuffLenx2 >> 1;
	uint16_t  rp = pHeadsetEft->UsbOutRingBuf.rp;
	uint16_t  wp = pHeadsetEft->UsbOutRingBuf.wp;
	uint16_t  LenRound = Len;
	if(Len == 11 || Len == 22 || Len == 44)
	{
		LenRound = Len + 1;
	}
// #if (AUDIO_SAMPLE_BLOCK_SIZE == 48)
#if(1)
	uint16_t  RstResLen = LenRound*4;
#else
	uint16_t  RstResLen = LenRound;
#endif
	uint32_t  ResLen;

	int32_t  *pBuffL = pHeadsetEft->UsbOutRingBuf.pBuff;
	int32_t  *pBuffR = pBuffL + BuffLen;
	if(0 == pHeadsetEft->UsbOutOpen || NULL == pBuffL)
	{
		return;
	}
	ResLen = (wp >= rp) ? (wp - rp) : (BuffLen + wp - rp);
	if(ResLen != RstResLen)
	{
		wp = rp + RstResLen;
		if(wp >= BuffLen)
		{
			wp=0;
		}
	}
	for(ii=0; ii<Len; ii++)
	{
		if(usb2dacMute==1)//用户需要有时候只听mic的声音，把usb传下来的声音去掉
		{
			pBuffL[wp  ] = 0;
			pBuffR[wp++] = 0;
		}
		else
		{
			pBuffL[wp  ] = pUsbOutL[ii];
			pBuffR[wp++] = pUsbOutR[ii];
		}
		pUsbOutL[ii] = pBuffL[rp  ];
		pUsbOutR[ii] = pBuffR[rp++];
		if(rp >= BuffLen)
		{
			rp = 0;
		}
		if(wp >= BuffLen)
		{
			wp = 0;
		}
	}
	pHeadsetEft->UsbOutRingBuf.rp = rp;
	pHeadsetEft->UsbOutRingBuf.wp = wp;
}


void HeadsetEffect_AudioInStart(ChipEffect_t *pHeadsetEft)
{
	pHeadsetEft->AudioInStartFlag = 1;
}

void HeadsetEffect_AudioOutStart(ChipEffect_t *pHeadsetEft)
{
	pHeadsetEft->AudioOutStartFlag = 1;
}
