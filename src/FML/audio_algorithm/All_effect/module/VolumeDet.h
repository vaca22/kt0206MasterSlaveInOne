#ifndef __VOLUME_DET_H__
#define __VOLUME_DET_H__

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_includes.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#ifndef NULL
#define NULL ((void*)0)
#endif
/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef struct{
	int32_t  aweight_state[3][4];
	uint32_t det_cnt;
	uint32_t det_peak;
	uint32_t det_win;
	int32_t  dBoutEn16;
	uint8_t  det_en;
	uint8_t  aweight_en;
}VolumeDetStru_t;

typedef struct{
	int32_t  Fs_Hz;
	uint32_t PeakWinT_ms;
	int32_t *pDetOutEn16_dB;
	uint8_t  det_en;
	uint8_t  aweight_en;
}VolumeDetPara_t;
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void VolumeDetNew(VolumeDetPara_t *pPara, VolumeDetStru_t *pInst);
void VolumeDet(VolumeDetStru_t *pInst, q31_t *src, q31_t *pTmpLen, uint32_t Len);

#endif
