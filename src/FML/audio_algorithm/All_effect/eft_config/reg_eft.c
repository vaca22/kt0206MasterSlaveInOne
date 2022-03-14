
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "reg_eft.h"
#include "DspEffect_top.h"
#include "eft_malloc.h"

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
// const un_DSPRegAll_t g_const_DspReg       =
// {
// 	.bs = {
// 		.ADCDigGain                         = {
// 		    .ADCGain                        = 2048,
// 		},
// 		.I2SIDigGain                        = {
// 		    .I2SILGain                      = 2048,
// 		    .I2SIRGain                      = 2048,
// 		},
// 		.DACDigGain                         = {
// 		    .DACLGain                       = 2048,
// 		    .DACRGain                       = 2048,
// 		},
// 		.DACDigGain                         = {
// 		    .DACLGain                       = 2048,
// 		    .DACRGain                       = 2048,
// 		},
// 		.I2SODigGain                        = {
// 		    .I2SOLGain                      = 2048,
// 		    .I2SORGain                      = 2048,
// 		},
// 		.InVolCfg                           = {
// 			.ADCVol	                        = 103,
// 			.I2SILVol	                    = 103,
// 			.I2SIRVol	                    = 103,
// 			.USBInVol                       = 103,
// 		},
// 		.OutVolCfg                           = {
// 			.DACLVol	                    = 103,
// 			.DACRVol	                    = 103,
// 			.I2SOLVol	                    = 103,
// 			.I2SORVol	                    = 103,
// 		},
//         .EftVolCfg                          = {
//             .dryvol                         = 100,
//         },
//         .SideToneCfg                        = {
//         	.En                             = 0,
//         	.MixInVol                       = 0,
//         	.MixOutVol                      = 0,
//         },
//         .MusicDkCfg0                        = {
//             .THlow_dB                       = (uint8_t)((int8_t) -40),
//             .THhigh_dB                      = (uint8_t)((int8_t) -38),
//             .DuckVol_dB                     = (uint8_t)((int8_t) -20),
//             .ave_Ms                         = 100,
//             .En                             = 0,
//         },
//         .MusicDkCfg1                        = {
//             .gAT_Ms                         = 200,
//             .gRT_Ms                         = 400,
//         },
//         .MusicDkCfg2                        = {
//             .sigT_Ms                        = 10,
//             .noiseT_Ms                      = 1000,
//         },
//         .HowlSprsCtrl0                      = { 0 },
//         .HowlDetCtrl0                       = {
//             .PKLongWinT_s                   = 10,
//             .ZCindexVarTh                   = 4,
//             .PKindexVarTh                   = 4,

//             .PKLongVarTh                    = 20,
//             .PKShortVarTh                   = 20,
//         },
//         .HowlNotchCtrl0                     = {
//             .TotalNum                       = 31,
//             .WantStdy                       = 8,
//             .NotchQ                         = 30,

//             .NotchDf                        = 100,
//             .DetNth                         = 4,
//             .DetFth                         = 3,
//         },
//         .HowlNotchCtrl1                     = {
//             .Life_s                         = 60 * 3,
//             .UpTime_s                       = 10,
//             .Hold_40Ms                      = 3,

//             .DownStep_dB                    = 2,
//             .UpStep_dB                      = 1,
//             .Init_dB                        = 3,
//             .Deep_dB                        = 12,
//         },

//         .HowlGainCtrl0                      = {
//             .gAT_Ms                         = 50,
//             .gRT_Ms                         = 200,
//         },

//         .HowlGainCtrl1                      = {
//             .UpWinT_Ms                      = 1000 * 10,

//             .NoHowlPct_0p01                 = 10,
//             .AfterNotchN                    = 4,
//         },

//         .HowlGainCtrl2                      = {
//             .UpStep0_dB                     = 4,
//             .UpStep1_dB                     = 1,
//             .DownStep_dB                    = 2,
//             .gMin_dB                        = 32,
//             .gUp0Th_dB                      = 12,
//         },
//         .FreqShiftCtrl                      = {
//             .BW                             = BW500Hz,
//             .dF                             = (uint8_t)((int8_t)(-5)),
//             .En                             = 0,
//         },
//         .EchoCfg0                           = {
//             .Delay_2MS                      = 100,
//             .MaxDelay_2MS                   = 250,
//             .LoopRatio                      = (uint8_t)((int8_t)(-12)),
//             .En                             = 0,
//         },
//         .EchoCfg1                           = {
//             .WetLevel                       = 100,
//             .CloseReq                       = 0,
//         },
//         .ReverbCfg0                         = {
//             .RoomSize                       = 70,
//             .RevTime                        = 25,

//             .Spread                         = 100,
//             .Damping                        = 50,
//             .En                             = 0,
//         },
//         .ReverbCfg1                         = {
//             .TailLevel                      = 80,
//             .EarlyLevel                     = 100,

//             .LpfBw                          = 80,
//             .LpfEn                          = 1,
//             .HpfBw                          = 10,
//             .HpfEn                          = 1,
//         },
//         .ReverbCfg2                         = {
//             .WetLevel                       = 100,
//             .SpreadMax                      = 16,
//             .RoomSizeMax                    = 70,
//             .CloseReq                       = 0,
//         },
//         .PitchShiftCfg                      = {
//         	.ratio                          = 70,
//         	.En                             = 0,
//         },
//         .NoiseGateCfg0                      = {
//             .THlow_dB                       = (uint8_t)((int8_t) -40),
//             .THhigh_dB                      = (uint8_t)((int8_t) -38),
//             .GateVol_dB                     = (uint8_t)((int8_t) -30),
//             .ave_Ms                         = 60,
//             .En                             = 0,
//         },
//         .NoiseGateCfg1                      = {
//             .gAT_Ms                         = 10,
//             .gRT_Ms                         = 20,
//         },
//         .NoiseGateCfg2                      = {
//             .sigT_Ms                        = 10,
//             .noiseT_Ms                      = 500,
//         },
//         .LimiterCfg0                        = {
//             .point_dB                       = (uint8_t)((int8_t) -3),
//             .soft                           = 0,
//             .En                             = 0,
//         },
//         .LimiterCfg1                        = {
//             .gAT_Ms                         = 10,
//             .gRT_Ms                         = 300,
//         },
//         .LimiterCfg2                        = {
//             .PkAT_Ms                        = 10,
//             .PkRT_Ms                        = 100,
//         },
//         .EQB15Cfg                              = {
//             [0]     = { .F0_0p1Hz = 250,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [1]     = { .F0_0p1Hz = 400,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [2]     = { .F0_0p1Hz = 630,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [3]     = { .F0_0p1Hz = 1000,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [4]     = { .F0_0p1Hz = 1600,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [5]     = { .F0_0p1Hz = 2500,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [6]     = { .F0_0p1Hz = 4000,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [7]     = { .F0_0p1Hz = 6300,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [8]     = { .F0_0p1Hz = 10000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [9]     = { .F0_0p1Hz = 16000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [10]    = { .F0_0p1Hz = 25000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [11]    = { .F0_0p1Hz = 40000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [12]    = { .F0_0p1Hz = 63000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [13]    = { .F0_0p1Hz = 100000, .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//             [14]    = { .F0_0p1Hz = 160000, .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) -60), .EQ_EN = 0},
//         },
//         .HowlSprsStdyCtrl                   = { 0 },
//         .HowlSprsStdyData                   = {{ 0 }},

//     },
// };
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
void dsp_EftRam_initial(uint32_t MEMaddr, uint32_t MEMsize)
{
	MEM_Init((void *)MEMaddr, MEMsize);
}

void dsp_EftReg_initial(const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst)
{
    nds32_dup_q31((q31_t *)pSrc, (q31_t *)pDst, sizeof(un_DSPRegAll_t) / 4);
}

