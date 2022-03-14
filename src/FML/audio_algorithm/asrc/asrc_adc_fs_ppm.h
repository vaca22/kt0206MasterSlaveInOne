/*
 * asrc_muses_fs_ppm.h
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 */

#ifndef ASRC_ADC_FS_PPM_H_
#define ASRC_ADC_FS_PPM_H_
#include "nds32_filtering_math.h"
#include "chip_config.h"
#define   ASRC_ADC_RINGBUF_LEN  (384)
#define   ASRC_ADC_IBUF_LEN     (16 )
#define   ASRC_ADC_IBUF_LEN_patch     (AUDIO_SAMPLE_BLOCK_SIZE)
#define   ASRC_ADC_OBUF_LEN     (96 )  //PCM sample in 1ms USB frame, max 96 for 96k sample
#define   ASRC_ADC_XINBUF_LEN   (26 + ASRC_ADC_OBUF_LEN + ASRC_ADC_OBUF_LEN/2)
#define   ASRC_ADC_XINBUF_LEN_patch   (26 + ASRC_ADC_OBUF_LEN_patch + ASRC_ADC_OBUF_LEN_patch/2)
#define   ADC_CROSSTALK_BUF_LEN  (128) //normal delay points 47
#define    ADC_CROSSTALK_SEARCH_LEN (32)
//typedef   struct
//{
//	uint8_t DacOnFlag;
//	uint8_t SearchDoneFlag;
//	uint16_t NCOA; //for sine generation
//	uint16_t FCW; //for sine generation
//	int16_t Rp;
//	int16_t Wp;
//	int16_t AccIdx;
//	int16_t MinValIdx;
//	int32_t AccVal;
//	int32_t Cnt;
//	int32_t DacLBuf[ADC_CROSSTALK_BUF_LEN];
//	//int32_t DacRBuf[ADC_CROSSTALK_BUF_LEN];
//	int32_t AccBuf[ADC_CROSSTALK_SEARCH_LEN];
//	int32_t FiltBuf[ASRC_ADC_IBUF_LEN];
//}st_AdcCrossTalk;

//extern st_AdcCrossTalk  AdcCrossTalk;
typedef struct{
	int8_t  Alpha;
	int16_t Cnt  ;
	int32_t Buf;
}st_FAST_DCNOTCH;

void adc_fast_dcnotch(
		st_FAST_DCNOTCH *para,
		int32_t *pSrc,
		int32_t *pDst,
		int16_t Len);


extern int32_t  adc_ringbuf_rp;
extern int32_t  adc_ringbuf_wp;
extern int32_t  asrc_adc_xinbuf_len;
extern int32_t USB_ADC_EOF_FLAG;
extern int32_t USB_ADC_PCM_NUM;
extern int32_t USB_ADC_ASRC_ENABLE;
extern int32_t start_adc_coarse_ppm;
extern int32_t ADC_REMAIN_NUM_TARGET;
extern int32_t ADC_STEREO_MODE;
extern int32_t ADC_LPF_USBFS_SEL_ENABLE;

extern int32_t adc_coarse_cnt       ;
extern int32_t adc_coarse_cnt2      ;

extern int32_t adc_remain_num_d     ;
extern int32_t adc_remain_num_min0  ;
extern int32_t adc_coarse_ppm       ;
extern int32_t adc_fine_ppm         ;
extern int32_t adc_narrow_state     ;
extern int32_t adc_coarse_state     ;
extern int64_t adc_nco         ;
extern int64_t adc_nco_buf     ;
extern int32_t USB_ADC_FS      ;
extern int32_t ADC_FS_RATIO_Q26;

extern int32_t USB_ADC_FS_D ;

extern int32_t ADC_STEREO_MODE  ;
extern int32_t ADC_DOWN_N       ;
extern int32_t adc_decimated_len;
extern int32_t adc_fs_ratio     ;


extern int32_t start_adc_coarse_ppm   ;
extern int32_t start_adc_coarse_ppm_d ;

extern int32_t adc_coarse_state     ;
//int32_t coarse_nxtstate  = 0;

extern int32_t adc_remain_num       ;
extern int32_t adc_remain_num_min   ;
extern int32_t adc_remain_min_search ;

extern int32_t adc_coarse_ppm_scale ;
extern int32_t adc_coarse_ppm_hold  ;
extern int32_t adc_coarse_locked    ;
extern int32_t adc_fine_ppm         ;
extern int32_t adc_fine_locked      ;
extern int32_t adc_narrow_state     ;
extern int32_t adc_Ka   ;
extern int32_t adc_Kb   ;
extern int32_t adc_cnt_for_narrow  ;
extern int32_t ADC_MAX_PIDSTEP     ;

void estimate_adc_coarse_ppm(void);
void estimate_adc_fine_ppm  (void);

//0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
// ADC data ==> USB,
//   ADC Fs,         PCM Sample Num @  1ms USB frame
//   0: 8k           8
//   1: 11.025k      11 or 12
//   2: 12K          12
//   3: 16k          16
//   4: 22.05k       22 or 23
//   5: 24k          24
//   6: 32k          32
//   7: 44.1k        44.1
//   8: 48k          48
//   9: 96k          96
// ASRC_OBUF_LEN=8, 8 PCM samples per Interrupt
//
//    (0)  LPF and decimation in ADC Interrupt
//    (1)  update adc_remain_num in ADC interrupt
//    (2)  do estimate_fs_coarse , estimate_fs_fine in ADC interrupt
//    (3)  do ASRC in USB interrupt

void asrc_adc_writebuf(int32_t *pDATA);   //sfix32_en23, from ADC
void asrc_adc_top(
		int32_t *pOUT_USB,
		int32_t USB_ADC_PCM_NUM);
uint32_t Asrc_Adc_Fs_Ppm_Init(uint32_t uInBaseAddr);
void asrc_adc_Clean_RingBuf();
void asrc_adc_patch_init(void);
void asrc_adc_fs_change_init(void);
void estimation_adc_ppm_init(void);
void estimation_adc_ppm_relock_init(void);
void new_asrc_adc_patch_init(void);
#endif /* ASRC_MUSES_FS_PPM_H_ */
