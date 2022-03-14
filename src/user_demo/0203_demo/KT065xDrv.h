
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#ifndef __KT065XDrv_h__
#define __KT065XDrv_h__

#include <stdint.h>
#include "soft_i2c.h"

#define KT0656M
//#define KT0655M

//#define XTAL_DUAL
#define XTAL_24M_ONLY
//#define XTAL_24P576M_ONLY

#ifdef	 XTAL_DUAL
	//#define OLD_SEL_XTAL_MODE 			  //KT0616M
	#define NEW_SEL_XTAL_MODE 				  //KT0656M
#endif

//#define AUTO_SEARCH_FREQ	 //


#ifdef  XTAL_24P576M_ONLY
    #define XTAL_SEL1  1 //0:24MHz xtal 1:24.576MHz xtal
    #define XTAL_SEL2  0 //0:24MHz xtal 1:24.576MHz xtal
#else
    #define XTAL_SEL1  0 //0:24MHz xtal 1:24.576MHz xtal
    #define XTAL_SEL2  1 //0:24MHz xtal 1:24.576MHz xtal
#endif

#define XTAL_24M_FREQ     0
#define XTAL_24P576M_FREQ 1

#define HLSI_INV          0 //0: (HLSI); 1: inv(HLSI)

#define DCDC_EN           1 //DCDC

#define AUTOMUTE_EN //undefine to disable automute
//#define SQUEAL_EN //undefine to disable squeal
#define I2S_EN


#define KT065x_MUTE              1
#define KT065x_UNMUTE            0

#define FAST_RSSI_MUTE_EN       1     //1:enable 0:disable
#define FAST_RSSI_PD_MUTE_EN    1     //1:enable 0:disable
#define SUPER_RSSI_MUTE_EN      1     //1:enable 0:disable

#define AUTOMUTE_SNR_LOWTH	   0x78
#define AUTOMUTE_SNR_HIGHTH	   0x80


//I2C
#define KTWirelessMicRx_addressAM 0x72//0x7A
#define KTWirelessMicRx_addressAS 0x7a//0x72

#define KTWirelessMicRx_addressBM 0x62//0x6A
#define KTWirelessMicRx_addressBS 0x6a

#define INIT_FAIL_TH        3

//
#define    BAND_TOP_CHA            754850//727550//754850//662500
#define    BAND_BOTTOM_CHA         740150//710450//740150
#define    BAND_TOP_CHB            800000//743750//769850
#define    BAND_BOTTOM_CHB         650000//728150//755150
#define    BAND_STEP               50

//
#define    BATTERY_MAX             0x7FF
#define    BATTERY_HIGHTH          0x500
#define    BATTERY_MIDDLETH        0x4C0
#define    BATTERY_LOWTH           0x4A0

#ifdef KT0655M
	#define LINEIN_AGC_DIS	 0 			//
	#define LINEIN_LOCAL_VOL_CTRL 30
	#define COMPEN_GAIN	   2  			//
	#define PGA_GAIN_SEL 3 				//
	#define	SLNC_MUTE_TIME	0x13		//
	#define SLNC_MUTE_DIS  1			//
	#define	SLNC_MUTE_LOW_LEVEL	0x04
	#define SLNC_MUTE_HIGH_LEVEL 0x06
	
	#define ALC_DIS	1					//
	#define ALC_VMAX  0x7f				//
    #define ALC_SOFTKNEE  1				//
#endif

//REG0x0200
#define ADJUST_GAIN			  1		   //0:75KHz 1:50KHz 2:37.5KHz 3:25KHz 4:20KHz 5:120KHz 6:100KHz

//REG0x0241
#define BPSK_NEW_MODE         1//0//1        //1:new mode  0:old mode
#define AUXDATA_EN            1        //

#define CARRY_NUM_TH          4        // 3'b000:10 3'b001:12  3'b010:14 3'b011:16 3'b100:18 3'b101:20  3'b110:22 3'b111:24
#define AUX_CARRY_NUM         3        //3'b000 32 3'b001 28	3'b010 24  3'b011 22 3'b100 20 3'b101 18  3'b110 16	 3'b111 12

#define COMP_TC				  1        // 压扩时间常数
#define EXPAND_MESH     0    // 与发射CPRS_1XLPF_BP相匹配

//REG0x026F
#define SQUEAL_ELIM_EN        1    //0: disable;    1: ensable		bit5
#define SQEUAL_DET_EN         3	   //
#define FNOTCH_NOTRESP_TH     1    //0: 1/4;    1: 1/2
#define N_OCTAVE              3//0    //0: 1/5;    1: 1/10;    2: 1/20;    3:1/80

//REG0x0270
#define FFT_R_TH            15    //8// 0: 0;        15: 30
#define FRAME_NUM_TH        0    //4    //

//REG0x0271
#define    PMAX_HITH          14  //8
#define    PMAX_LOWTH         12  //6
#define    AFC_RNG		  	  2//3	   //2'b00: +/-20kHz;2'b01: +/-40kHz;2'b10: +/-60kHz;2'b11: +/-90kHz;

//REG0x0272
#define    FDIFF_HITH         7//15
#define    FDIFF_LOWTH        1//7

#define ECHO_STRU         1    //0:
#define ECHO_GAIN_DOWN    0    //0: -13dB; 1: -10dB; 2: -7dB;
#define ECHO_GAIN_UP      7    //0: 0dB; 1: 1.9dB; 2: 3.5dB; 3: 5.5dB; 4: 7dB; 5: 9.4dB; 6: 10.9dB; 7: 13.1dB;
#define ECHO_RATIO        10   //0~25: 0~25/32
#define ECHO_DELAY        23   //0~23:    22ms~197ms ECHO

#define EXCITER_TUNE    2    //0: 600Hz; 1: 1KHz; 2: 2KHz; 3: 3.8KHz;
#define EXCITER_DRIVE   0    //0: 0dB; 1: 3.5dB; 2: 6dB; 3: 9dB; 4: 12dB; 5: 15dB
#define EXCITER_ODD     1    //0~6:
#define EXCITER_EVEN    1    //0~6:


typedef enum
{
	Dis		= 0,
	En		= 1,
}KT065xM_FunctionState_t;


typedef struct
{
	uint16_t Bpsk_Data_A;       // High bit Low bit Exchange
	uint16_t Bpsk_Data_B;		// High bit Low bit Exchange
	uint16_t Bpsk_Data_C;		// High bit Low bit Exchange
	uint16_t Bpsk_Data_D;		// High bit Low bit Exchange
}KT065xM_BpskData_t;

typedef enum
{
	EQ_25Hz     =   0,
	EQ_40Hz     =   1,
	EQ_63Hz     =   2,
	EQ_100Hz    =   3,
	EQ_160Hz    =   4,
	EQ_250Hz    =   5,
	EQ_400Hz    =   6,
	EQ_630Hz    =   7,
	EQ_1KHz     =   8,
	EQ_1K6Hz    =   9,
	EQ_2K5Hz    =  10,
	EQ_4KHz     =  11,
	EQ_6K3Hz    =  12,
	EQ_10KHz    =  13,
	EQ_16KHz    =  14,
}KT065xM_EQFreq_t;

typedef enum
{
    EQ_Neg12dB    =  0,
    EQ_Neg11dB    =  1,
    EQ_Neg10dB    =  2,
    EQ_Neg9dB     =  3,
    EQ_Neg8dB     =  4,
    EQ_Neg7dB     =  5,
    EQ_Neg6dB     =  6,
    EQ_Neg5dB     =  7,
    EQ_Neg4dB     =  8,
    EQ_Neg3dB     =  9,
    EQ_Neg2dB     = 10,
    EQ_Neg1dB     = 11,
    EQ_Pos0dB     = 12,
    EQ_Pos1dB     = 13,
    EQ_Pos2dB     = 14,
    EQ_Pos3dB     = 15,
    EQ_Pos4dB     = 16,
    EQ_Pos5dB     = 17,
    EQ_Pos6dB     = 18,
    EQ_Pos7dB     = 19,
    EQ_Pos8dB     = 20,
    EQ_Pos9dB     = 21,
    EQ_Pos10dB    = 22,
    EQ_Pos11dB    = 23,
    EQ_Pos12dB    = 24,
}KT065xM_EQGain_t;


#define PRESET_VOL       31 //0: mute; 31: maximum volume

#define  PKGSYNC         1
#define  NON_PKGSYNC     0

#define  PilotFlag       1     //

typedef enum
{
	KT_I2S_LRCLK48K			= 0,
	KT_I2S_LRCLK96K			= 1,
	KT_I2S_LRCLK192K		= 2,
}KT065xM_I2SLRCLK_t;

typedef enum
{
	KT_I2S_MCLK12P288M		= 0,
	KT_I2S_MCLK24P576M		= 1,
}KT065xM_I2SMCLK_t;

typedef enum
{
	KT_I2S_SLAVE			= 0,
	KT_I2S_MASTER			= 1,
}KT065xM_I2SMasterSlave_t;

typedef enum
{
	KT_I2S_MONO				= 0,
	KT_I2S_STRREO			= 1,
}KT065xM_I2SSteroMono_t;

typedef enum
{
	KT_I2S_RIGHT			= 0,
	KT_I2S_LEFT				= 1,
}KT065xM_I2SLeftRight_t;

typedef enum
{
	KT_I2S_NOMODE			= 0,
	KT_I2S_I2SMODE			= 1,
	KT_I2S_LEFTMODE			= 2,
	KT_I2S_RIGHTMODE 		= 3,
}KT065xM_I2SMode_t;

typedef enum
{
	KT_I2S_LENGHT16BIT			= 0,
	KT_I2S_LENGHT20BIT			= 1,
	KT_I2S_LENGHT24BIT			= 2,
	KT_I2S_LENGHT8BIT			= 3,
}KT065xM_I2SDataLength_t;

typedef struct
{
	KT065xM_I2SLRCLK_t 			LRCLK;
	KT065xM_I2SMCLK_t  			MCLK;
	KT065xM_I2SMasterSlave_t 	MasterOrSlave;  //1:master 0:slave
	KT065xM_I2SSteroMono_t 		SteroOrMono;    //1:stereo 0:Mono
	KT065xM_I2SLeftRight_t 		LeftOrRight;	//1:left 0:right
	KT065xM_I2SMode_t 			Mode;     		//0:
	KT065xM_I2SDataLength_t   	DataLength;		//0:16 1:20 2:24 3:8
}KT065xM_I2SConfig_t;


//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------
void KT_Bus_Write(const SoftI2C_t *I2CDef, uint16_t RegAddr, uint8_t Byte_Data);
uint8_t KT_Bus_Read(const SoftI2C_t *I2CDef, uint16_t RegAddr);

uint8_t KT_WirelessMicRx_PreInit(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_Init(const SoftI2C_t *I2CDef);
void KT_WirelessMicRx_Tune(const SoftI2C_t *I2CDef, uint32_t Freq); //in kHz
uint8_t KT_WirelessMicRx_Volume(const SoftI2C_t *I2CDef, uint8_t cVolume);
uint8_t KT_WirelessMicRx_GetVolume(const SoftI2C_t *I2CDef);
void KT_WirelessMicRx_SW_Echo(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cEcho_En);
void KT_WirelessMicRx_SetEcho(const SoftI2C_t *I2CDef, uint8_t cEcho_Ratio, uint8_t cEcho_Delay);
void KT_WirelessMicRx_SW_Exciter(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cExciter_En);
void KT_WirelessMicRx_SetExciter(const SoftI2C_t *I2CDef, uint8_t cExciter_Odd, uint8_t cExciter_Even);
void KT_WirelessMicRx_SW_Equalizer(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cEqualizer_En);
void KT_WirelessMicRx_SetEqualizer(const SoftI2C_t *I2CDef, KT065xM_EQFreq_t cEqualizer_Frq, KT065xM_EQGain_t cEqualizer_Gain);
void KT_WirelessMicRx_SW_Diversity(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t diversity_En);
uint8_t KT_WirelessMicRx_GetAF(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_GetRSSI(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_GetFastRSSI(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_Automute(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_CheckAUXCH(const SoftI2C_t *I2CDef);
void KT_WirelessMicRx_GetAUXCH(const SoftI2C_t *I2CDef, KT065xM_BpskData_t *BpskData);
uint8_t KT_WirelessMicRx_CheckPilot(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_GetSNR(const SoftI2C_t *I2CDef);
void KT_WirelessMicRx_SelectMS(const SoftI2C_t *I2CDef);
void KT_WirelessMicRx_SAIInit(const SoftI2C_t *I2CDef, const KT065xM_I2SConfig_t *i2sConfig);
void KT_WirelessMicRx_FastTune(const SoftI2C_t *I2CDef, uint32_t Freq);
void KT_WirelessMicRx_Patch(const SoftI2C_t *I2CDef);

uint8_t KT_WirelessMicRx_GetPilotStatus(const SoftI2C_t *I2CDef);
uint8_t KT_WirelessMicRx_GetBpskSyncStatus(const SoftI2C_t *I2CDef);

void  KT_WirelessMicRx_SetMaxRfGain(const SoftI2C_t *I2CDef, uint8_t sel); //

void KT_WirelessMicRx_DoFastTune(const SoftI2C_t *I2CDef, uint32_t Freq);
uint8_t KT_WirelessMicRx_CheckFastTuneOK(const SoftI2C_t *I2CDef);

uint8_t KT_WirelessMicRx_deltemp(const SoftI2C_t *I2CDef);
//void AutoSeekFreq(BOOL chan_num);               //

/********* KT0656M Old patch *******/
void rfIntCtl(const SoftI2C_t *I2CDef);
void pilotMuteRefresh(const SoftI2C_t *I2CDef);
void snrMuteRefresh(const SoftI2C_t *I2CDef);

#endif
