/*
 * HeadsetEffect_top.h
 *
 *  Created on: Mar 6, 2020
 *      Author: guoax
 */

#ifndef HEADSETEFFECT_TOP_H_
#define HEADSETEFFECT_TOP_H_
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "ModuleInfo.h"
#include "HardCtrlModule.h"
#include "usb_audio_app.h"
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
	int32_t  *pBuff;
	uint16_t  BuffLenx2;
	uint16_t  wp;
	uint16_t  op; //operate point
	uint16_t  rp;
}UsbOutRingBuff_t;
typedef struct
{
	VolumePara_t     *pVolDryPara;
	VolumeStru_t     *pVolDryStru;

	ReverbPara_t     *pReverbPara;
	ReverbStru_t     *pReverbStru;
	VolumePara_t     *pVolRvbPara;
	VolumeStru_t     *pVolRvbStru;

	EchoPara_t       *pEchoPara;
	EchoStru_t       *pEchoStru;
	VolumePara_t     *pVolEchoPara;
	VolumeStru_t     *pVolEchoStru;

	PitchShiftWsolaPara_t *pPsWsolaPara;
	PitchShiftWsolaStru_t *pPsWsolaStru;

	NoiseGatePara_t  *pNoiseGatePara;
	NoiseGateStru_t  *pNoiseGateStru;

	CompanderPara_t  *pExpanderPara;
	CompanderStru_t  *pExpanderStru;

	LimiterPara_t    *pLimiterPara;
	LimiterStru_t    *pLimiterStru;

	AgcPara_t        *pAgcPara;
	AgcStru_t        *pAgcStru;

	Surround3DPara_t *pSrd3DPara;
	Surround3DStru_t *pSrd3DStru;

	SurroundMovePara_t *pSrdMovePara;
	SurroundMoveStru_t *pSrdMoveStru;
	SideToneStru_t   *pSideToneStru;
	SideTonePara_t   *pSideTonePara;

	MusicDuckingStru_t   *pMusicDuckingStru;
	MusicDuckingPara_t   *pMusicDuckingPara;
	PeakDet3BandStru_t   *pPeakDet3BandStru;
	PeakDet3BandPara_t   *pPeakDet3BandPara;

	UpsampleStru_t   *pUpSampStruL;
	UpsampleStru_t   *pUpSampStruR;
	DownsampleStru_t *pDownSampStru;

	SWI_WrapBuf_t     WrapBuff512p;
	SWI_WrapBuf_t     OutWrapBuff512p;
	UsbOutRingBuff_t  UsbOutRingBuf;
	int32_t          *pTmpBuff512x3;
	void             *pRvbBuff;
	void             *pPitchShiftBuff;
	void             *pEchoBuff;
	void             *pSrdMoveBuff;
	int32_t          *pTmpBuffAddaBlkx4;
	int32_t          *pTmpBuffUsbBlkx6;
	EqStru_t          EqB15Stru;
	EqStru_t          EqB5Stru;
	uint8_t           Prc512pOpen;
	uint8_t           PrcOut512pOpen;
	uint8_t           Cnt512pEft;
	uint8_t           AdcInOpen;
	uint8_t           DacOutOpen;
	uint8_t           UsbInOpen;
	uint8_t           UsbOutOpen;
	uint8_t           AudioInStartFlag;
	uint8_t           AudioOutStartFlag;
}ChipEffect_t;

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern ChipEffect_t *g_st_pHeadsetEft;
extern stUSB_Audio_Dev stUsbAudio;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
uint32_t HeadsetEffect_StruAlc(ChipEffect_t *pHeadsetEft, uint32_t addr);
void HeadsetEffect_AdcStereoin(ChipEffect_t *pHeadsetEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len);
void HeadsetEffect_Adcin (ChipEffect_t *pHeadsetEft, int32_t *pData,  uint32_t Len);
void HeadsetEffect_Usbin (ChipEffect_t *pHeadsetEft, int32_t *pSrc,   int32_t *pDstL, int32_t *pDstR, uint32_t Len);
void HeadsetEffect_Dacout(ChipEffect_t *pHeadsetEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len);
//void HeadsetEffect_Usbout(ChipEffect_t *pHeadsetEft, int32_t *pDataL, int32_t *pDataR, uint32_t Len);
void HeadsetEffect_Usbout(ChipEffect_t *pHeadsetEft, int32_t *pUsbInL, int32_t *pUsbInR, uint32_t LenIn, uint32_t LenOut);
void HeadsetEffect_Usbout_DataRW(ChipEffect_t *pHeadsetEft, int32_t *pUsbOutL, int32_t *pUsbOutR, uint32_t Len);
void HeadsetEffect_AdcIn512P_ISR   (void);
void HeadsetEffect_AdcIn512P(ChipEffect_t *pHeadsetEft);
void HeadsetEffect_DacOut512P_ISR   (void);
void HeadsetEffect_DacOut512P(ChipEffect_t *pHeadsetEft);
void HeadsetEffect_AudioInStart (ChipEffect_t *pHeadsetEft);
void HeadsetEffect_AudioOutStart(ChipEffect_t *pHeadsetEft);
#endif /* HEADSETEFFECT_TOP_H_ */
