#ifndef __REG_EFT_H__
#define __REG_EFT_H__

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>
#include "comm.h"
#include "SurroundMove.h"

/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#ifndef NULL
#define NULL ((void *)0)
#endif

#define DSPREG_IDX(mem) (((uint32_t)(&(((st_DSPRegAll_t *)0)->mem)))>>2)
/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef struct {
    UINT32 ADCGain                          : 16;
    UINT32 RFU                              : 16;
} st_DSP_DIGGAIN_CONFIG0;

typedef struct {
    UINT32 I2SILGain                        : 16;
    UINT32 I2SIRGain                        : 16;
} st_DSP_DIGGAIN_CONFIG1;

typedef struct {
    UINT32 DACLGain                         : 16;
    UINT32 DACRGain                         : 16;
} st_DSP_DIGGAIN_CONFIG2;
typedef struct {
    UINT32 I2SOLGain                        : 16;
    UINT32 I2SORGain                        : 16;
} st_DSP_DIGGAIN_CONFIG3;

typedef struct {
    UINT32 ADCVol                           : 7;
    UINT32 RFU0                             : 1;
    UINT32 I2SILVol                         : 7;
    UINT32 RFU1                             : 1;
    UINT32 I2SIRVol                         : 7;
    UINT32 RFU2                             : 1;
    UINT32 USBInVol                         : 7;
    UINT32 RFU3                             : 1;
} st_DSP_VOLUME_CONFIG0;

typedef struct {
    UINT32 DACLVol                          : 7;
    UINT32 RFU0                             : 1;
    UINT32 DACRVol                          : 7;
    UINT32 RFU1                             : 1;
    UINT32 I2SOLVol                         : 7;
    UINT32 RFU2                             : 1;
    UINT32 I2SORVol                         : 7;
    UINT32 RFU3                             : 1;
} st_DSP_VOLUME_CONFIG1;

typedef struct {
    UINT32 dryvol                           : 8;
    UINT32 RFU                              : 24;
} st_DSP_EFTVOLUME_CONFIG;

typedef struct {
    UINT32 MixInVol                         : 8;
    UINT32 MixOutVol                        : 8;
    UINT32 RFU                              : 15;
    UINT32 En                               : 1;
} st_DSP_SIDETONE_CONFIG;

/*------------------Music Ducking----------------*/
typedef struct {

    UINT32 THlow_dB                         : 8;
    UINT32 THhigh_dB                        : 8;

    UINT32 DuckVol_dB                       : 8;
    UINT32 ave_Ms                           : 7;
    UINT32 En                               : 1;
} st_DSP_MUSICDUCKING_CONFIG0;

typedef struct {
    UINT32 gAT_Ms                           : 16;
    UINT32 gRT_Ms                           : 16;
} st_DSP_MUSICDUCKING_CONFIG1;

typedef struct {
    UINT32 sigT_Ms                          : 16;
    UINT32 noiseT_Ms                        : 16;
} st_DSP_MUSICDUCKING_CONFIG2;

/*--------------------REVERB-------------------*/
typedef struct {
    UINT32 RoomSize                         : 8;
    UINT32 RevTime                          : 8;

    UINT32 Spread                           : 8;
    UINT32 Damping                          : 7;
    UINT32 En                               : 1;
} st_DSP_REVERB_CONFIG0;

typedef struct {
    UINT32 TailLevel                        : 8;
    UINT32 EarlyLevel                       : 8;

    UINT32 LpfBw                            : 7;
    UINT32 LpfEn                            : 1;
    UINT32 HpfBw                            : 7;
    UINT32 HpfEn                            : 1;
} st_DSP_REVERB_CONFIG1;

typedef struct {
    UINT32 WetLevel                         : 8;
    UINT32 RFU                              : 8;

    UINT32 SpreadMax                        : 8;
    UINT32 RoomSizeMax                      : 7;
    UINT32 CloseReq                         : 1;
} st_DSP_REVERB_CONFIG2;

/*---------------------ECHO--------------------*/
typedef struct {
    UINT32 Delay_2MS                        : 8;
    UINT32 MaxDelay_2MS                         : 8;

    UINT32 LoopRatio                        : 8;
    UINT32 RFU0                             : 7;
    UINT32 En                               : 1;
} st_DSP_ECHO_CONFIG0;

typedef struct {
    UINT32 WetLevel                         : 8;
    UINT32 RFU                              : 8;

    UINT32 RFU0                             : 15;
    UINT32 CloseReq                         : 1;
} st_DSP_ECHO_CONFIG1;
/*-----------------Howling notch---------------*/
typedef struct {
    UINT32 En                               : 1;
    UINT32 DetEn                            : 1;
    UINT32 NotchUpdateEn                    : 1;
    UINT32 NotchEn                          : 1;

    UINT32 GainCtrlEn                       : 1;
    UINT32 ClearEn                          : 1;
    UINT32 RFU0                             : 2;

    UINT32 RFU1                             : 24;
} st_DSP_HOWLSUPRESS_CONFIG0;

typedef struct {
    UINT32 PKLongWinT_s                     : 8;
    UINT32 ZCindexVarTh                     : 4;
    UINT32 PKindexVarTh                     : 4;

    UINT32 PKLongVarTh                      : 8;
    UINT32 PKShortVarTh                     : 8;
} st_DSP_HOWLDET_CONFIG0;

typedef struct {
    UINT32 Fhowl_Hz                         : 16;

    UINT32 RFU                              : 15;
    UINT32 HowlState                        : 1;
} st_DSP_HOWLDET_OUT;

typedef struct {
    UINT32 TotalNum                         : 5;
    UINT32 WantStdy                         : 4;
    UINT32 NotchQ                           : 7;

    UINT32 NotchDf                          : 8;
    UINT32 DetNth                           : 4;
    UINT32 DetFth                           : 4;
} st_DSP_HOWLNOTCH_CONFIG0;

typedef struct {
    UINT32 Life_s                           : 9;
    UINT32 UpTime_s                         : 5;
    UINT32 Hold_40Ms                        : 2;

    UINT32 DownStep_dB                      : 3;
    UINT32 UpStep_dB                        : 3;
    UINT32 Init_dB                          : 5;
    UINT32 Deep_dB                          : 5;
} st_DSP_HOWLNOTCH_CONFIG1;

typedef struct {
    UINT32 CurStdy                          : 8;

    UINT32 RFU                              : 23;
    UINT32 StdyUpdate                       : 1;
} st_DSP_HOWLNOTCH_OUT0;

typedef struct {
    UINT32 OldFlag                          : 32;
} st_DSP_HOWLNOTCH_OUT1;

typedef struct {
    UINT32 FixFlag                          : 32;
} st_DSP_HOWLNOTCH_OUT2;

typedef struct {
    UINT32 OpenFlag                         : 32;
} st_DSP_HOWLNOTCH_OUT3;

typedef struct {
    UINT32 gAT_Ms                           : 16;
    UINT32 gRT_Ms                           : 16;
} st_DSP_HOWLGAIN_CONFIG0;

typedef struct {
    UINT32 UpWinT_Ms                        : 16;

    UINT32 NoHowlPct_0p01                   : 8;
    UINT32 AfterNotchN                      : 5;
    UINT32 RFU                              : 3;
} st_DSP_HOWLGAIN_CONFIG1;
typedef struct {
    UINT32 UpStep0_dB                       : 4;
    UINT32 UpStep1_dB                       : 4;
    UINT32 DownStep_dB                      : 4;
    UINT32 RFU                              : 4;

    UINT32 gMin_dB                          : 8;
    UINT32 gUp0Th_dB                        : 8;
} st_DSP_HOWLGAIN_CONFIG2;

typedef struct {
    UINT32 gUseEn31                         : 32;
} st_DSP_HOWLGAIN_OUT;

typedef struct {
    UINT32 StudyN                           : 6;
    UINT32 SaveFlash                        : 1;
    UINT32 RFU0                             : 9;
    UINT32 Q                                : 16;
} st_DSP_HOWLSTUDY_CONFIG;

typedef struct {
    UINT32 howling_notch_f                  : 16;
    UINT32 howling_notch_d                  : 16;

} st_DSP_HOWLSTUDY_DATA;
/*------------------FREQSHIFT-----------------*/
typedef struct {
    UINT32 En                               : 1;
    UINT32 BW                               : 3;
    UINT32 dF                               : 8;
    UINT32 RFU0                             : 20;
} st_DSP_FREQSHIFT_CONFIG0;

/*------------------NOISE GATE----------------*/
typedef struct {

    UINT32 THlow_dB                         : 8;
    UINT32 THhigh_dB                        : 8;

    UINT32 GateVol_dB                       : 8;
    UINT32 ave_Ms                           : 7;
    UINT32 En                               : 1;
} st_DSP_NOISEGATE_CONFIG0;

typedef struct {
    UINT32 gAT_Ms                           : 16;
    UINT32 gRT_Ms                           : 16;
} st_DSP_NOISEGATE_CONFIG1;

typedef struct {
    UINT32 sigT_Ms                          : 16;
    UINT32 noiseT_Ms                        : 16;
} st_DSP_NOISEGATE_CONFIG2;

typedef struct {
    UINT32 mute_out                         : 1;
    UINT32 mute_out_delay                   : 1;
    UINT32 RFU0                             : 30;
} st_DSP_NOISEGATE_OUT_READ0;


/*----------------------Limiter---------------*/
typedef struct {
    UINT32 point_dB                         : 8;
    UINT32 RFU0                             : 22;
    UINT32 soft                             : 1;
    UINT32 En                               : 1;
} st_DSP_LIMITER_CONFIG0;

typedef struct {
    UINT32 gAT_Ms                           : 16;
    UINT32 gRT_Ms                           : 16;
} st_DSP_LIMITER_CONFIG1;

typedef struct {
    UINT32 PkAT_Ms                          : 16;
    UINT32 PkRT_Ms                          : 16;
} st_DSP_LIMITER_CONFIG2;
/*----------------------Compandor---------------*/
typedef struct {
    uint32_t point_dB                         : 8;
    uint32_t ratio                            : 8;

    uint32_t ave_Ms                           : 13;
    uint32_t compand                          : 1;
    uint32_t soft                             : 1;
    uint32_t En                               : 1;
} st_DSP_COMPANDOR_CONFIG0;
typedef struct {
    uint32_t gAT_Ms                           : 16;
    uint32_t gRT_Ms                           : 16;
} st_DSP_COMPANDOR_CONFIG1;


/*----------------------Agc---------------*/
typedef struct
{
	uint32_t ratio                         :  8;
	uint32_t point_dB                      :  8;
	uint32_t gMax_dB                       :  8;
	uint32_t RFU                           :  7;
	uint32_t En                            :  1;
}st_DSP_AGC_CONFIG0;
typedef struct
{
	uint32_t gAT_Ms                        : 16;
	uint32_t gRT_Ms                        : 16;
}st_DSP_AGC_CONFIG1;

typedef struct
{
	uint32_t ave_Ms                        : 16;
	uint32_t hold_Ms                       : 16;
}
st_DSP_AGC_CONFIG2;
/*----------------------Equalizer---------------*/
typedef struct {
    UINT32 Qv                               : 16;
    UINT32 Gain_0p1dB                       : 16;

    UINT32 F0_0p1Hz                         : 20;
    UINT32 RFU                              : 8;
    UINT32 EQ_Type                          : 3;
    UINT32 EQ_EN                            : 1;
} st_DSP_EQ_CONFIG;

/*----------------------PitchShift---------------*/
typedef struct {
    UINT32 ratio                            : 15;
    UINT32 En                               : 1;
    UINT32 RFU                              : 16;
} st_DSP_PITCHSHIFT_CONFIG;


/*----------------------Surround3D---------------*/
typedef struct {
    UINT32 CenterGain_0p5dB                 : 8;
    UINT32 LRGain_0p5dB                     : 8;
    UINT32 LSRSGain_0p5dB                   : 8;
    UINT32 RFU                              : 7;
    UINT32 En                               : 1;
} st_DSP_SURROUND3D_CONFIG;

typedef struct {
	SurroundMovePara_t  SrdMovePara;
} st_DSP_SURROUNDMOVE_CONFIG;
typedef struct {
    UINT32 RFU                              : 31;
    UINT32 En                               : 1;
} st_DSP_PEAKDET_CONFIG;
typedef struct {
	//----size: 0x10
	st_DSP_DIGGAIN_CONFIG0                  ADCDigGain;                  //0x00
	st_DSP_DIGGAIN_CONFIG1                  I2SIDigGain;                 //0x01
	st_DSP_DIGGAIN_CONFIG2                  DACDigGain;                  //0x02
	st_DSP_DIGGAIN_CONFIG3                  I2SODigGain;                 //0x03
	st_DSP_VOLUME_CONFIG0                   InVolCfg;                    //0x04
	st_DSP_VOLUME_CONFIG1                   OutVolCfg;                   //0x05
	st_DSP_EFTVOLUME_CONFIG                 EftVolCfg;                   //0x06
	st_DSP_SIDETONE_CONFIG                  SideToneCfg;                 //0x07
	st_DSP_MUSICDUCKING_CONFIG0             MusicDkCfg0;				 //0x08
	st_DSP_MUSICDUCKING_CONFIG1             MusicDkCfg1;				//0x09
	st_DSP_MUSICDUCKING_CONFIG2             MusicDkCfg2;				//0x0A
	st_DSP_PEAKDET_CONFIG                   PeakDetCfg;
	uint32_t                                RFU0[4];                    //0x0B ~ 0x0F

	//----size: 0x30
	st_DSP_FREQSHIFT_CONFIG0                FreqShiftCtrl;               //0x00
	st_DSP_HOWLSUPRESS_CONFIG0              HowlSprsCtrl0;               //0x01
	st_DSP_HOWLDET_CONFIG0                  HowlDetCtrl0;                //0x02
	st_DSP_HOWLDET_OUT                      HowlDetOut;                  //0x03
	st_DSP_HOWLNOTCH_CONFIG0                HowlNotchCtrl0;              //0x04
	st_DSP_HOWLNOTCH_CONFIG1                HowlNotchCtrl1;              //0x05
	st_DSP_HOWLNOTCH_OUT0                   HowlNotchOut0;               //0x06
	st_DSP_HOWLNOTCH_OUT1                   HowlNotchOut1;               //0x07
	st_DSP_HOWLNOTCH_OUT2                   HowlNotchOut2;               //0x08
	st_DSP_HOWLNOTCH_OUT3                   HowlNotchOut3;               //0x09
	st_DSP_HOWLGAIN_CONFIG0                 HowlGainCtrl0;               //0x0A
	st_DSP_HOWLGAIN_CONFIG1                 HowlGainCtrl1;               //0x0B
	st_DSP_HOWLGAIN_CONFIG2                 HowlGainCtrl2;               //0x0C
	st_DSP_HOWLGAIN_OUT                     HowlGainOut;                 //0x0D
	st_DSP_HOWLSTUDY_CONFIG                 HowlSprsStdyCtrl;            //0x0E
	st_DSP_HOWLSTUDY_DATA                   HowlSprsStdyData[32];        //0x0F ~ 0x2E
	uint32_t                                RFU1[1];                     //0x2F

	//----size: 0x20
	st_DSP_ECHO_CONFIG0                     EchoCfg0;                    //0x00
	st_DSP_ECHO_CONFIG1                     EchoCfg1;                    //0x01
	st_DSP_REVERB_CONFIG0                   ReverbCfg0;                  //0x02
	st_DSP_REVERB_CONFIG1                   ReverbCfg1;                  //0x03
	st_DSP_REVERB_CONFIG2                   ReverbCfg2;                  //0x04
	st_DSP_PITCHSHIFT_CONFIG                PitchShiftCfg;               //0x05
	st_DSP_SURROUND3D_CONFIG                SrdCfg0;                     //0x06
	st_DSP_SURROUNDMOVE_CONFIG              SrdMoveCfg0;                 //0x07 ~ 0x12
	uint32_t                                RFU2[13];                    //0x13 ~ 0x1F

	//----size: 0x10
	st_DSP_NOISEGATE_CONFIG0                NoiseGateCfg0;               //0x00
	st_DSP_NOISEGATE_CONFIG1                NoiseGateCfg1;               //0x01
	st_DSP_NOISEGATE_CONFIG2                NoiseGateCfg2;               //0x02
	st_DSP_NOISEGATE_OUT_READ0              NoiseGateOut;                //0x03
	st_DSP_LIMITER_CONFIG0                  LimiterCfg0;                 //0x04
	st_DSP_LIMITER_CONFIG1                  LimiterCfg1;                 //0x05
	st_DSP_LIMITER_CONFIG2                  LimiterCfg2;                 //0x06
	st_DSP_COMPANDOR_CONFIG0                ExpandorCfg0;                //0x07
	st_DSP_COMPANDOR_CONFIG1                ExpandorCfg1;                //0x08
	st_DSP_AGC_CONFIG0                      AgcCfg0;                     //0x09
	st_DSP_AGC_CONFIG1                      AgcCfg1;                     //0x0A
	st_DSP_AGC_CONFIG2                      AgcCfg2;                     //0x0B
	uint32_t                                RFU4[4];                     //0x0C ~ 0x0F

	//----size: 0x30
	st_DSP_EQ_CONFIG                        EQB15Cfg[15];                //0x00 ~ 0x1D
	st_DSP_EQ_CONFIG                        EQB5Cfg[5];                  //0x1E ~ 0x27
	uint32_t                                RFU5[8];                     //0x28 ~ 0x2F


}st_DSPRegAll_t;
#pragma pack(4)
typedef union {
	st_DSPRegAll_t  bs;
	uint32_t 	all32[sizeof(st_DSPRegAll_t) >> 2];
	uint8_t		all8[sizeof(st_DSPRegAll_t)];
}un_DSPRegAll_t;
#pragma pack()

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern const un_DSPRegAll_t g_const_DspReg;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void dsp_EftRam_initial(uint32_t MEMaddr, uint32_t MEMsize);
void dsp_EftReg_initial(const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst);

#endif

