/*
 * ModuleInfo.h
 *
 *  Created on: Jul 12, 2019
 *      Author: guoax
 */

#ifndef MODULEINFO_H_
#define MODULEINFO_H_

#include "reverb.h"
#include "Resample.h"
#include "mymath.h"
#include "VolumeSmth.h"
#include "AudioDelay.h"
#include "eq_top.h"
#include "echo.h"
#include "eq_cal_coeff.h"
#include "HowlingDetect.h"
//#include "sgolayfilt.h"
#include "AudioDRC.h"
#include "HowlFreqShift.h"
#include "MusicDucking.h"
//#include "FreqReps_SetNotch.h"
#include "PitchShiftWsola.h"
#include "SWI_WrapBuf.h"
#include "Surround3D.h"
#include "SurroundMove.h"
//#include "VirtualSurround.h"
//======================================Volume Start=============================================//
/*
 * VolumeNew   : external Parameter to Internal Structure
 * typedef enum VolumeType_enum{
		VolDB  = 0,
		VolPCT = 1,	
	}VolumeType_t;

	typedef struct {
		float        VolFL;
		VolumeType_t dBorPct;
	}VolumePara_t;

 * @param[in]  : *pPara     - points to an instance of the external structure
 * @param[out] : *pInst     - points to an instance of the internal structure
 * @return     : none
 */
void VolumeNew(VolumePara_t *pPara, VolumeStru_t *pInst);

/*
 * VolumeMono      : mono audio Volume adjust
 *
 * @param[in&out]  : *pData     - points to input block data & output block data
 * @param[in&out]  : *pInst     - points to an instance of the internal structure
 * @param[in]      :  Len       - number of the block.
 * @return         : none
 */
void VolumeMono(q31_t *pData, VolumeStru_t *pInst, uint32_t Len);

/*
 * VolumeStereo    : stereo audio Volume adjust
 *
 * @param[in&out]  : *pData     - points to input block data & output block data
 * @param[in&out]  : *pInst     - points to an instance of the internal structure
 * @param[in]      :  Len       - number of the block.
 * @return         : none
 */
void VolumeStereo(q31_t *pData0, q31_t *pData1, VolumeStru_t *pInst, uint32_t Len);

/*
 * AudioInv        : audio phase inverse
 *
 * @param[in&out]  : *pData     - points to input block data & output block data
 * @param[in]      :  inv       - inverse audio flag.
 * @param[in]      :  Len       - number of the block.
 * @return         : none
 */
void AudioInv(q31_t *pData, uint32_t inv, int32_t Len);

/*
 * AudioMute       : audio mute
 *
 * @param[in&out]  : *pData     - points to input block data & output block data
 * @param[in]      :  mute      - mute audio flag.
 * @param[in]      :  Len       - number of the block.
 * @return         : none
 */
void AudioMute(q31_t *pData, uint32_t mute, int32_t Len);
//=======================================Volume End==============================================//


//====================================Resample Start=============================================//
/*
 * DownSample      : down dample 2x or 3x,  bw = 7kHz@3x, bw = 10kHz@2x 
 *
 * @param[in]      : *pSrc      - points to input block data
 * @param[out]     : *pDst      - points to output block data
 * @param[in&out]  : *pInst     - points to an instance of the internal structure
 * @param[in]      :  Nx        - 2 or 3.
 * @param[in]      :  Len       - number of the input block, must be even.
 * @param[in]      : *OutLen    - point of  the output block number.
 * @return         : none
 */
void DownSample(q31_t *pSrc, q31_t *pDst, DownsampleStru_t *pInst, 
	            uint32_t Nx, uint32_t Len,   uint32_t *OutLen);

/*
 * UpSample        : Up dample 2x or 3x
 *
 * @param[in]      : *pSrc      - points to input block data
 * @param[out]     : *pDst      - points to output block data
 * @param[in&out]  : *pDownInst - points to an instance of the down sample internal structure
 * @param[in&out]  : *pUpInst   - points to an instance of the up sample internal structure
 * @param[in]      :  Nx        - 2 or 3.
 * @param[in]      :  InLen     - number of the input block.
 * @param[in]      :  OutLen    - number of the output block.
 * @return         : none
 */
void UpSample  (q31_t *pSrc, q31_t *pDst, DownsampleStru_t *pDownInst, UpsampleStru_t *pUpInst, 
	            uint32_t Nx, uint32_t InLen, uint32_t  OutLen);
//=====================================Resample End==============================================//

//=======================================DRC Start===============================================//

/*
 *  NoiseGateNew: external Parameter to Internal Structure
	typedef struct{
		float           THlow_dB     ;
		float           THhigh_dB    ;
		float           signalT_Ms   ;
		float           noiseT_Ms    ;
		float           gAT_Ms       ;
		float           gRT_Ms       ;
		float           ave_Ms       ;
		float           GateVol_dB   ;
		uint16_t        fs_Hz        ;
		uint8_t         en           ;
		uint8_t         reachGate    ;
	}NoiseGatePara_t;
 *
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pStru  - points to an instance of the internal structure
 * @return     : none
 */
void NoiseGateNew(NoiseGateStru_t *pStru, NoiseGatePara_t *pPara);

/*
 * NoiseGate       : noise gate
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - data number of the block.
 * @return         : none
 */
void NoiseGate   (int32_t *pData, NoiseGateStru_t *pInst, uint16_t Len);

/*
 *  CompanderNew: external Parameter to Internal Structure
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
 *
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pStru  - points to an instance of the internal structure
 * @return     : none
 */
void CompanderNew (CompanderStru_t *pStru, CompanderPara_t *pPara);

/*
 * CompressLarge   : large signal compress
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void CompressLarge(int32_t *pData, CompanderStru_t *pInst, uint16_t Len);

/*
 * ExpandSmall     : small signal expand
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void ExpandSmall  (int32_t *pData, CompanderStru_t *pInst, uint16_t Len);

/*
 *  LimiterNew: external Parameter to Internal Structure
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

 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pStru  - points to an instance of the internal structure
 * @return     : none
 */
void LimiterNew(LimiterStru_t *pStru, LimiterPara_t *pPara);

/*
 * ExpandSmall     : small signal expand
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void Limiter   (int32_t *pData, LimiterStru_t *pInst, uint16_t Len);

/*
 *  AgcNew: external Parameter to Internal Structure
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

 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pStru  - points to an instance of the internal structure
 * @return     : none
 */
void AgcNew(AgcStru_t *pStru, AgcPara_t *pPara);

/*
 * Agc     : Agc
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void Agc  (int32_t *pData, AgcStru_t *pInst, uint16_t Len);

//========================================DRC End================================================//

//========================================EQ Start===============================================//

/*
 *  EqInit     : EQ initialize
	typedef enum EqChannel_enum {
		EQ_MONO       = 0,
		EQ_STEREO     = 1,
	}EqChannel_t;
 * @param[in]  : channel - channel number
 * @param[in]  : BandNum - Band number, limit to 15
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void EqInit  (EqStru_t *pInst, EqChannel_t channel, uint8_t BandNum);

/*
 *  EqNew      : external Parameter to Internal Structure
	typedef struct {
		EqFilt_t         *pStru[15];
		EqCoeffPara_t    *pPara[15];
		int32_t           CoeffBak[6];
		int32_t          *pCoeffBak;
		uint32_t          NAll;
		uint32_t          NChan;
		uint32_t          StruSize;
	}EqStru_t;
 * @param[in]  : *pInst  - points to an instance of the internal structure
                  allocate pStru[bandx] (NumBytes = StruSize) 
                  allocate pPara[bandx] (NumBytes = sizeof(EqCoeffPara_t))
 * @param[in]  : bandx   - Band index
 * @return     : none
 */
void EqNew   (EqStru_t *pInst, uint8_t bandx);

/*
 * EqMono          : Mono audio EQ
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void EqMono  (int32_t *pData, EqStru_t *pInst, uint16_t Len);

/*
 * EqStereo        : Stereo audio EQ
 *
 * @param[in&out]  : *pData0 - points to L input block data
 * @param[in&out]  : *pData1 - points to R input block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void EqStereo(int32_t *pData0, int32_t *pData1, EqStru_t *pInst, uint16_t Len);
//========================================EQ End=================================================//

//=====================================Howling Start=============================================//
/*
 *  HowlSupressNew      : external Parameter to Internal Structure
	typedef struct
	{
		HowlDetPara_t   DetPara;
		HowlNotchPara_t NotchPara;
		HowlGainPara_t  GainPara;
		uint8_t         DetEn;
		uint8_t         NotchUpdateEn;
		uint8_t         NotchEn;
		uint8_t         GainCtrlEn;
		uint8_t         ClearEn;
		uint8_t         En;
	}HowlPara_t;
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void HowlSupressNew    (              HowlStru_t *pInst, HowlPara_t *pPara);

/*
 *  HowlDetParaNew      : external Parameter to Internal Structure
	typedef struct
	{
		uint8_t  PKLongWinT_S;
		uint8_t  ZCindexVarTh;
		uint8_t  PKindexVarTh;
		uint8_t  PeakLongVarTh;
		uint8_t  PeakShortVarTh;
		uint32_t Fs_Hz;
		uint32_t Fhowl_Hz;
		uint8_t  HowlState;
	}HowlDetPara_t;
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void HowlDetParaNew    (              HowlStru_t *pInst, HowlPara_t *pPara);
/*
 *  HowlNotchParaNew      : external Parameter to Internal Structure
	typedef struct
	{
		uint16_t NotchLife_S;
		uint16_t NotchUpTime_S;
		uint16_t NotchHold_Ms;
		uint8_t  NotchDeep_dB;
		uint8_t  NotchInit_dB;
		uint8_t  NotchUp_dB;
		uint8_t  NotchDown_dB;
		uint8_t  NotchTotalNum;
		uint8_t  NotchWantStudy;

		uint8_t  DetNth;
		uint16_t DetFth_Hz;
		uint16_t NotchDf_Hz;
		uint8_t  NotchQ;

		uint32_t NotchOpenFlag;
		uint32_t NotchOldFlag;
		uint32_t NotchFixFlag;
		uint8_t  NotchCurStudy;
		uint8_t  StudyUpdate;
	} HowlNotchPara_t;
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void HowlNotchParaNew  (              HowlStru_t *pInst, HowlPara_t *pPara);
/*
 *  HowlGainParaNew      : external Parameter to Internal Structure
	typedef struct
	{
		float      NoHowl_Pct;
		uint16_t   gAT_Ms;
		uint16_t   gRT_Ms;
		uint8_t    UpStep0_dB;
		uint8_t    UpStep1_dB;
		uint8_t    DownStep_dB;
		uint8_t    gMin_dB;
		uint8_t    gUp0Th_dB;
		uint8_t    UpWinT_Ms;
		uint8_t    AfterNotchN;

		uint32_t   gUseEn31;
	}HowlGainPara_t;
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void HowlGainParaNew   (              HowlStru_t *pInst, HowlPara_t *pPara);

/*
 * HowlSupressTop  : Howling detect & notch & gain adjust
 *
 * @param[in&out]  : *pData  - points to L input & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void HowlSupressTop    (q31_t *pData, HowlStru_t *pInst, q31_t *pTmpLenx1, uint32_t Len);

/*
 * FreqShiftNew: external Parameter to Internal Structure
	typedef enum FreqShiftBw_enum{
		BW200Hz  = 0,
		BW250Hz  = 1,
		BW300Hz  = 2,
		BW350Hz  = 3,
		BW400Hz  = 4,
		BW450Hz  = 5,
		BW500Hz  = 6,
		BWFULL   = 7,
	}FreqShiftBw_t;
	typedef struct {
		int32_t         dF;
		FreqShiftBw_t   Bw;
		uint8_t         En;
	}FreqShiftPara_t;
 *
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pStru  - points to an instance of the internal structure
 * @param[in]  :  Len    - data number of the block
 * @return     : none
 */
void FreqShiftNew(FreqShiftStru_t *pStru, FreqShiftPara_t *pPara, uint32_t Len);

/*
 * FreqShift_MaxBuff: compute buff size
 *
 * @param[in]  : *pStru  - points to an instance of the internal structure
 * @param[in]  : Len     - data number of the block.
 * @return     : need to malloc buff size for freqshift data 
 */
uint32_t FreqShift_MaxBuff(FreqShiftStru_t *pStru, uint32_t Len);

/*
 * FreqShiftInit  : FreqShift initialize, call after FreqShiftNew
 *
 * @param[in]     : *pBuff  - points to FreqShift buffer start addr
 * @param[out]    : *pStru  - points to an instance of the internal structure
 * @param[in]     :  Len    - data number of the block
 * @return        :  delay buffer end addr
 */
uint32_t FreqShiftInit(FreqShiftStru_t *pStru, void *pBuff, uint32_t Len);

/*
 * FreqShiftTop    : Freq shift
 *
 * @param[in&out]  : *pData     - points to L input & output block data
 * @param[in&out]  : *pStru     - points to an instance of the internal structure
 * @param[in]      : *pTmpLenx3 - temp data buff addr, size = Len*3*4 byte
 * @param[in]      :  Len       - data number of the block.
 * @return         : none
 */
void FreqShiftTop (q31_t *pData, FreqShiftStru_t *pStru, int32_t *pTmpLenx3, uint32_t Len);
//=====================================Howling End===============================================//

//=====================================AudioDelay Start==========================================//
/*
 * AudioDelay_New: external Parameter to Internal Structure
   typedef struct{
		uint32_t Fs_Hz;
		float    DlyMax_Ms;
		float    DlyL_Ms;
		float    DlyR_Ms;
		uint8_t  En;
   }AudioDelayPara_t;
 *
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : none
 */
void AudioDelay_New (AudioDelayPara_t *pPara, AudioDelayStru_t *pInst);

/*
 * AudioDelay_MaxBuff: compute max buff size according to DlyMax_Ms
 *
 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     : need to malloc buff size for delay data 
 */
uint32_t AudioDelay_MaxBuff(AudioDelayPara_t *pPara, AudioDelayStru_t *pInst);

/*
 * AudioDelay_Init: Audio Delay initialize, call after AudioDelay_New
 *
 * @param[in]     : *pBuff  - points to delay buffer start addr
 * @param[out]    : *pInst  - points to an instance of the internal structure
 * @return        : delay buffer end addr
 */
uint32_t AudioDelay_Init(AudioDelayStru_t *pInst, void *pBuff);
/*
 * AudioDelayMono: Audio Delay mono
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void AudioDelayMono(int32_t *pData, AudioDelayStru_t *pInst, uint32_t Len);

/*
 * AudioDelayStereo: Audio L & R with different delay
 *
 * @param[in]      : *pData  - points to input block data
 * @param[out]     : *pDataL - points to input block data & output block data
 * @param[out]     : *pDataR - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void AudioDelayStereo(int32_t *pDataI, int32_t *pDataL, int32_t *pDataR,
		              AudioDelayStru_t *pInst, uint32_t Len);
//=====================================AudioDelay End============================================//

//======================================Echo Start===============================================//
/*
 * Echo_New   : external Parameter to Internal Structure
	typedef struct{
		float    LoopRatio_dB;
		uint32_t Fs_Hz;
		uint16_t Dly_Ms;
		uint16_t DlyMax_Ms;
		uint16_t En;
	}EchoPara_t;

 * @param[in]  : *pPara  - points to an instance of the external structure
 * @param[out] : *pInst  - points to an instance of the internal structure
 * @return     :  none
 */
void Echo_New(EchoPara_t *pPara, EchoStru_t *pInst);

/*
 * Echo_MaxBuff   : compute max buff size according to DlyMax_Ms
 *
 * @param[in]     : *pBuff  - points to delay buffer start addr
 * @param[out]    : *pInst  - points to an instance of the internal structure
 * @return        : need to malloc buff size for echo data
 */
uint32_t Echo_MaxBuff(EchoPara_t *pPara, EchoStru_t *pInst);

/*
 * Echo_Init      : Echo initialize, call after Echo_new
 *
 * @param[in]     : *pBuff  - points to delay buffer start addr
 * @param[out]    : *pInst  - points to an instance of the internal structure
 * @return        : echo buffer end addr
 */
uint32_t Echo_Init(EchoStru_t *pInst, void *pBuff);

/*
 * Echo_Wet        : Echo wet generate, without dry audio & wet ratio adjust
 *
 * @param[in&out]  : *pData  - points to input block data & output block data
 * @param[in&out]  : *pInst  - points to an instance of the internal structure
 * @param[in]      :  Len    - number of the block.
 * @return         : none
 */
void Echo_Wet(int32_t *pData, EchoStru_t *pInst, uint16_t Len);
//=====================================Echo End==================================================//

//===================================Reverb Start================================================//
/*
 * Reverb_new   : external Parameter to Internal Structure
	typedef struct {
		float roomsize;
		float revtime;
		float spread;
		float TailLevel;
		float EarlyLevel;
		float LpfBw;
		float HpfBw;
		float Damping;
		float RoomMax;
		float SprdMax;
		uint32_t Fs_Hz;
		uint8_t LpfEn;
		uint8_t HpfEn;
		uint8_t HpfOld;
		uint8_t En;
	}ReverbPara_t;

 * @param[in]  : *pPara     - points to an instance of the external structure
 * @param[out] : *pInst     - points to an instance of the internal structure
 * @return     : none
 */
void Reverb_new(ReverbStru_t *pInst, ReverbPara_t *pPara);

/*
 * Reverb_MaxBuff : compute max buff size according to RoomMax & SprdMax 
 *
 * @param[in]  : *pPara     - points to an instance of the external structure
 * @param[out] : *pInst     - points to an instance of the internal structure
 * @return        : need to malloc buff size for reverb data
 */
uint32_t Reverb_MaxBuff(ReverbStru_t *pInst, ReverbPara_t *pPara);

/*
 * Reverb_init    : Reverb initialize, call after Reverb_new
 *
 * @param[in]     : *pBuff     - points to delay buffer start addr
 * @param[out]    : *pInst     - points to an instance of the internal structure
 * @return        : Reverb buffer end addr
 */
uint32_t Reverb_init(ReverbStru_t *pInst, void *pBuff);

/*
 * Reverb_wet      : Revert wet generate, without dry audio & wet ratio adjust
 *
 * @param[in]      : *pSrc      - points to input block data
 * @param[out]     : *yleft     - points to output block data
 * @param[out]     : *yright    - points to output block data
 * @param[in&out]  : *pInst     - points to an instance of the internal structure
 * @param[in]      :  Len       - number of the block.
 * @return         : none
 */
void Reverb_wet(ReverbStru_t *pInst, int32_t *pSrc, int32_t *yleft, int32_t *yright,
				int32_t Len);
//======================================Reverb End===============================================//

#endif /* MODULEINFO_H_ */
