/*
 * volume.h
 *
 *  Created on: Jul 16, 2019
 *      Author: guoax
 */

#ifndef _VOLUMESMTH_H_
#define _VOLUMESMTH_H_
typedef enum VolumeType_enum{
	VolDB  = 0,
	VolPCT = 1,	
}VolumeType_t;

typedef struct {
	float        VolFL;
	uint8_t      step;
	VolumeType_t dBorPct;
}VolumePara_t;

typedef struct {
    int32_t  VolQ32;
    int32_t  VolSmth;
    int16_t  step;
    uint8_t  SmthOpen;
}VolumeStru_t;

void VolumeNew   (VolumePara_t *pPara, VolumeStru_t *pInst);
void VolumeMono  (q31_t *pData, VolumeStru_t *pInst, uint32_t Len);
void VolumeStereo(q31_t *pData0, q31_t *pData1, VolumeStru_t *pInst, uint32_t Len);
void AudioInv    (q31_t *pData, uint32_t inv, int32_t Len);
void AudioMute   (q31_t *pData, uint32_t mute, int32_t Len);
#endif /* VOLUME_H_ */
