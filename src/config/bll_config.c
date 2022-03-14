#include "stdlib.h"
#include "string.h"
#include "hal_config.h"
#include "bll_config.h"
#include "config.h"
#include "patch.h"
#include "usb_config.h"
#include "HowlFreqShift.h"
#include "version.h"


uint8_t isFlashValid = 0;
//vender configration infomation
volatile const config_t g_stVendorConfig __attribute__ ((section(".FLASH_CFG_SECTION"))) =
{
	.FramFlag = 0x12345678,

	.SoftCheck = 0x03,

	.Version = {
		.FirmVer = __FW_VERSION_USER__,
		.mData = __DATE__,
	    .mTime = __TIME__,
	    .VerServer = SERVERVERSION,
	},

	.SaveDataAddr = 0xbd000,

	.DSPRegAll =
	{
		.bs =
		{
			.ADCDigGain                         = {
				.ADCGain                        = ADC_GAIN_DIGIT_SEL,//2048,
			},
			.I2SIDigGain                        = {
				.I2SILGain                      = 2048,
				.I2SIRGain                      = 2048,
			},
			.DACDigGain                         = {
				.DACLGain                       = DACL_GAIN_DIGIT_SEL,//2048,
				.DACRGain                       = DACR_GAIN_DIGIT_SEL,//2048,
			},
			.I2SODigGain                        = {
				.I2SOLGain                      = 2048,
				.I2SORGain                      = 2048,
			},
			.InVolCfg                           = {
				.ADCVol	                        = USB_IN_VOL_INIT_IDX,//103,
				.I2SILVol	                    = 103,
				.I2SIRVol	                    = 103,
				.USBInVol                       = 103,
			},
			.OutVolCfg                           = {
				.DACLVol	                    = USB_OUT_VOL_INIT_IDX,//103,
				.DACRVol	                    = USB_OUT_VOL_INIT_IDX,//103,
				.I2SOLVol	                    = USB_OUT_VOL_INIT_IDX,//103,
				.I2SORVol	                    = USB_OUT_VOL_INIT_IDX,//103,
			},
			.EftVolCfg                          = {
				.dryvol                         = 100,
			},
			.SideToneCfg                        = {
				.En                             = 1,
				.MixInVol                       = 0,
				.MixOutVol                      = 0,
			},
			.PeakDetCfg                         = {
				.En                             = 0,
			},
			.MusicDkCfg0                        = {
				.THlow_dB                       = (uint8_t)((int8_t) - 40),
				.THhigh_dB                      = (uint8_t)((int8_t) - 38),
				.DuckVol_dB                     = (uint8_t)((int8_t) - 10),
				.ave_Ms                         = 20,
				.En                             = 0,
			},
			.MusicDkCfg1                        = {
				.gAT_Ms                         = 200,
				.gRT_Ms                         = 400,
			},
			.MusicDkCfg2                        = {
				.sigT_Ms                        = 1,
				.noiseT_Ms                      = 1000,
			},
			.HowlSprsCtrl0                      = { 0 },
			.HowlDetCtrl0                       = {
				.PKLongWinT_s                   = 10,
				.ZCindexVarTh                   = 4,
				.PKindexVarTh                   = 4,

				.PKLongVarTh                    = 20,
				.PKShortVarTh                   = 20,
			},
			.HowlNotchCtrl0                     = {
				.TotalNum                       = 31,
				.WantStdy                       = 8,
				.NotchQ                         = 30,

				.NotchDf                        = 100,
				.DetNth                         = 4,
				.DetFth                         = 3,
			},
			.HowlNotchCtrl1                     = {
				.Life_s                         = 60 * 3,
				.UpTime_s                       = 10,
				.Hold_40Ms                      = 3,

				.DownStep_dB                    = 2,
				.UpStep_dB                      = 1,
				.Init_dB                        = 3,
				.Deep_dB                        = 12,
			},

			.HowlGainCtrl0                      = {
				.gAT_Ms                         = 50,
				.gRT_Ms                         = 200,
			},

			.HowlGainCtrl1                      = {
				.UpWinT_Ms                      = 1000 * 10,

				.NoHowlPct_0p01                 = 10,
				.AfterNotchN                    = 4,
			},

			.HowlGainCtrl2                      = {
				.UpStep0_dB                     = 4,
				.UpStep1_dB                     = 1,
				.DownStep_dB                    = 2,
				.gMin_dB                        = 32,
				.gUp0Th_dB                      = 12,
			},
			.FreqShiftCtrl                      = {
				.BW                             = BW500Hz,
				.dF                             = (uint8_t)((int8_t)(-5)),
				.En                             = 0,
			},
			.EchoCfg0                           = {
				.Delay_2MS                      = 100,
				.MaxDelay_2MS                   = 250,
				.LoopRatio                      = (uint8_t)((int8_t)(-12)),
				.En                             = 0,
			},
			.EchoCfg1                           = {
				.WetLevel                       = 100,
				.CloseReq                       = 0,
			},
			.ReverbCfg0                         = {
				.RoomSize                       = 70,
				.RevTime                        = 25,

				.Spread                         = 100,
				.Damping                        = 50,
				.En                             = 0,
			},
			.ReverbCfg1                         = {
				.TailLevel                      = 128,//80,
				.EarlyLevel                     = 90,//100,

				.LpfBw                          = 80,
				.LpfEn                          = 1,
				.HpfBw                          = 10,
				.HpfEn                          = 1,
			},
			.ReverbCfg2                         = {
				.WetLevel                       = 30,//100,
				.SpreadMax                      = 16,
				.RoomSizeMax                    = 70,
				.CloseReq                       = 0,
			},
			.PitchShiftCfg                      = {
				.ratio                          = 70,
				.En                             = 0,
			},
			.SrdCfg0                            = {
				.CenterGain_0p5dB               = 0,
				.LRGain_0p5dB                   = 0,
				.LSRSGain_0p5dB                 = 0,
				.En                             = 0,
			},
			.SrdMoveCfg0                        = {
				.SrdMovePara={
					.En=0,
				},
			},
			.NoiseGateCfg0                      = {
				.THlow_dB                       = (uint8_t)((int8_t) - 40),
				.THhigh_dB                      = (uint8_t)((int8_t) - 38),
				.GateVol_dB                     = (uint8_t)((int8_t) - 30),
				.ave_Ms                         = 20,
				.En                             = EFFECT_NOISEGATE_DEF_STAT,//0,
			},
			.NoiseGateCfg1                      = {
				.gAT_Ms                         = 10,
				.gRT_Ms                         = 20,
			},
			.NoiseGateCfg2                      = {
				.sigT_Ms                        = 1,
				.noiseT_Ms                      = EFFECT_NOISEGATE_DET_TIME,//500,
			},
			.LimiterCfg0                        = {
				.point_dB                       = (uint8_t)((int8_t) - 3),
				.soft                           = 0,
				.En                             = 0,
			},
			.LimiterCfg1                        = {
				.gAT_Ms                         = 0,
				.gRT_Ms                         = 100,
			},
			.LimiterCfg2                        = {
				.PkAT_Ms                        = 0,
				.PkRT_Ms                        = 40,
			},
			.AgcCfg0                            = {
				.ratio                          = 35,
				.point_dB                       = (uint8_t)((int8_t) - 20),
				.gMax_dB                        = 20,
				.En                             = 0,
			},
			.AgcCfg1                            = {
				.gAT_Ms                         = 100,
				.gRT_Ms                         = 800,
			},
			.AgcCfg2                            = {
				.ave_Ms                         = 20,
				.hold_Ms                        = 1000,
			},
			.ExpandorCfg0                       = {
				.point_dB                       = EXPANDOR_CFG_POINT_0P5dB,//(uint8_t)((int8_t) - 40),
				.ratio                          = 50,

				.ave_Ms                         = 20,
				.compand                        = 1,
				.soft                           = 0,
				.En                             = EFFECT_COMPANDER_DEF_STAT,//0,
			},
			.ExpandorCfg1                       = {
				.gAT_Ms                         = 10,
				.gRT_Ms                         = 30,
			},
			.EQB15Cfg                              = {
				[0]     = { .F0_0p1Hz = 250,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[1]     = { .F0_0p1Hz = 400,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[2]     = { .F0_0p1Hz = 630,    .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[3]     = { .F0_0p1Hz = 1000,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[4]     = { .F0_0p1Hz = 1600,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[5]     = { .F0_0p1Hz = 2500,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[6]     = { .F0_0p1Hz = 4000,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[7]     = { .F0_0p1Hz = 6300,   .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[8]     = { .F0_0p1Hz = 10000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[9]     = { .F0_0p1Hz = 16000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[10]    = { .F0_0p1Hz = 25000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[11]    = { .F0_0p1Hz = 40000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[12]    = { .F0_0p1Hz = 63000,  .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[13]    = { .F0_0p1Hz = 100000, .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
				[14]    = { .F0_0p1Hz = 160000, .Qv = 707,  .Gain_0p1dB = (uint16_t)((int16_t) - 60), .EQ_EN = 0},
			},
			.HowlSprsStdyCtrl                   = { 0 },
			.HowlSprsStdyData                   = {{ 0 }},
		},
	},


	.USBReg = {
		.UsbCodeState = 0xf7,
		.UsbManufact = USB_MANUFACT,
		.UsbProduct = USB_PRODUCT,
		.UsbSerial = USB_SERIAL,
		.UsbStringID = {0x04, 0x03, 0x09, 0x04},
		.UsbProductID = USB_PRODUCTID,
		.ucUsbMaxPower = USB_MAXPOWER,
		.OutFreqEnCtrl = USB_OUT_FREQ_SUPPORT,
		.InFreqEnCtrl = USB_IN_FREQ_SUPPORT,
	},


	.FuncCfg = {
#ifdef APPLE_EARPHONE_KEY_SUPPORT
		.SupportAppleEarphone = 1,
#else
		.SupportAppleEarphone = 0,
#endif
		.SupportUsbKeyboard = SUPPORT_USB_KEYBOARD_CFG,
#ifdef JACK_SENSE_FUNC
		.JackSenseSel = JACK_SENSE_CFG,
#endif
		// .AudioPathSel = ,
		.DongleAudioInSel = DONGLE_AUDIO_IN_SEL,
		.DongleAudioInCfg = DONGLE_AUDIO_IN_CFG,
		.DongleUsbInCfg = DONGLE_USB_IN_CFG,
		.DongleUsbInChannel = DONGLE_USB_IN_CHANNEL,
	},
	.PerfCfg = {
		//0: 0dB, 1: -6dB, 2: 8dB, 3: 14dB, 4: 20dB, 5: 26dB, 6: 32dB, 7: 44dB
		.PgaADC = ADC_GAIN_ANALOG_SEL,//4, //affect apple earphone function, please don't easily adjusted.

		//0: mute,   1: -18dB, 2: -16.5dB,  3: -15dB,  4: -13.5dB,  5: -12dB, 6: -10.5dB, 7: -9dB
		//8: -7.5dB, 9: -6dB, 10: -4.5dB,  11: -3dB,  12: -1.5dB,  13: 0dB,  14: 1.5dB,  15: 3dB
		.PgaDACR = DACR_GAIN_ANALOG_SEL,//0X0E,
		.PgaDACL = DACL_GAIN_ANALOG_SEL,//0X0E,
		.THDCfg = 0x78787878,
	},
	.Crc16 = 0x87654321,

};


config_t* g_pstRoConfig = (config_t*)&g_stVendorConfig; //chip config read only infomation struct point
config_t* g_pstConfig = (config_t*)RAM_DSP_REG_BASE_ADDR; //chip config infomation struct point

//void ChipCfg_Set(config_t* pstConfig)
//{
//    g_pstRoConfig = pstConfig;
//}

void ChipCfg_Init(void)
{
	if (INW(g_stVendorConfig.SaveDataAddr) == g_stVendorConfig.FramFlag)
	{
		memcpy(g_pstConfig, (void*)g_stVendorConfig.SaveDataAddr, sizeof(config_t));
	}
	else
	{
		memcpy(g_pstConfig, g_pstRoConfig, sizeof(config_t));
	}
	g_pstConfig->FLASHMODE= *((uint32_t *)(0xbfffc));
}

