/*
 * HardCtrlModule.h
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

#ifndef HARDCTRLMODULE_H_
#define HARDCTRLMODULE_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_math_types.h"
#include "nds32_includes.h"
#include "VolumeSmth.h"
#include "MusicDucking.h"
#include "VolumeDet.h"
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
	int64_t   Lpf0State[8];
	int64_t   Hpf0State[8];
	int32_t   Lpf1State[8];
	int32_t   Hpf1State[8];
	VolumeDetStru_t st_PeakDet[3];
	uint8_t   En;
}PeakDet3BandStru_t;
typedef struct
{
	uint8_t       En;
	VolumeDetPara_t st_PeakDetPara[3];
}PeakDet3BandPara_t;
typedef struct
{
	uint8_t   En;
	VolumeStru_t  UsbInVol;
	VolumeStru_t  UsbOutVol;
}SideToneStru_t;

typedef struct
{
	uint8_t       En;
	VolumePara_t  UsbInVolPara;
	VolumePara_t  UsbOutVolPara;
}SideTonePara_t;
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern int32_t USB_DAC_FS;
extern uint8_t ucHighRailCpClk;
extern uint8_t ucLowRailCpClk;
extern q31_t g_DacStereoL_PeakState;
extern q31_t g_DacStereoR_PeakState;
extern q31_t g_DacStereo_PeakAttack;
extern q31_t g_DacStereo_PeakRelease;
extern q31_t g_classg_rail_switch_volt_low;//sfix24_en23
extern q31_t g_classg_rail_switch_volt_high;//sfix24_en23
extern uint32_t g_classg_rail_high_hold;
extern uint32_t g_classg_rail_cnt;
extern uint8_t g_classg_rail_ctrl;
extern uint8_t g_classg_rail_ctrl_old;
extern uint8_t g_classg_rail_ctrl_en;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void peak_det(
  q31_t *pSrc,
  q31_t *pDst,
  q31_t *PeakState,
  q31_t DrcPeakAttack,
  q31_t DrcPeakRelease,
  uint32_t blocksize
);

void new_patch_audio_dac_rail_ctrl(
    q31_t *pToDacL,
    q31_t *pToDacR,
    q31_t *tempbuff,
    uint32_t len);
void SideToneAdd(SideToneStru_t  *pStru,         MusicDuckingStru_t *pMDStru,
		          const int32_t  *pUsbInL,            const int32_t *pUsbInR,
		                int32_t  *pUsbOutL,                 int32_t *pUsbOutR,
		                int32_t  *pTmpLenOutx3,            uint32_t  LenOut,  uint32_t LenIn);

void SideToneNew(SideToneStru_t *pStru, SideTonePara_t *pPara);

void PeakDet3Band(PeakDet3BandStru_t *pStru, int32_t *pDataL, int32_t *pDataR, int32_t *pTmpLenx2, int32_t Len);
void PeakDet3BandNew(PeakDet3BandPara_t *pPara, PeakDet3BandStru_t *pInst);
#endif /* HARDCTRLMODULE_H_ */
