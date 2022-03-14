/*
 * asrc_muses_fs_ppm.h
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 */

#ifndef ASRC_DAC_FS_PPM_H_
#define ASRC_DAC_FS_PPM_H_
#include "nds32_filtering_math.h"
#include "chip_config.h"
#define   ASRC_RINGBUF_LEN  (384)
#define   ASRC_OBUF_LEN     (16 )
#define   ASRC_OBUF_LEN_patch     (AUDIO_SAMPLE_BLOCK_SIZE )
#define   ASRC_XINBUF_LEN   (26 + ASRC_OBUF_LEN + ASRC_OBUF_LEN/2)
#define   ASRC_XINBUF_LEN_patch   (26 + ASRC_OBUF_LEN_patch + ASRC_OBUF_LEN_patch/2)
extern int32_t  USB_DAC_FS ;
extern int32_t  asrc_xinbuf_len ; // asrc_xinbuf_len <= ASRC_XINBUF_LEN
extern int32_t  dac_ringbuf_rp  ;
extern int32_t  dac_ringbuf_wp  ;

extern int32_t USB_DAC_FS    ;
extern int32_t USB_DAC_FS_D;
extern int32_t USB_DAC_EOF_FLAG;
extern int32_t USB_DAC_PCM_NUM;
extern int32_t USB_DAC_ASRC_ENABLE;

extern int32_t *dac_ringbuf_left;
extern int32_t *dac_ringbuf_right;
extern int32_t USB_DAC_PCM_NUM ;  //PCM sample number in 1ms seconds
extern int32_t DAC_FS_RATIO_Q26 ;  //Fsin/Fsout in Q26 format, 48k/46.875k*2^26
extern int32_t DAC_STEREO_MODE  ;
extern int32_t DAC_REMAIN_NUM_TARGET;
extern int32_t coarse_cnt       ;
extern int32_t coarse_cnt2      ;

extern int32_t usb_audio_out_off_cnt;

extern int32_t coarse_state     ;
//int32_t coarse_nxtstate  = 0;

extern int32_t remain_num_d     ;
extern int32_t remain_num       ;
extern int32_t remain_num_min   ;
extern int32_t remain_num_min0  ;
extern int32_t remain_min_search ;

//int32_t continuous_win   = 8;
extern int32_t coarse_ppm_scale ;
extern int32_t coarse_ppm       ;
extern int32_t coarse_ppm_hold  ;
extern int32_t coarse_locked    ;
extern int32_t fine_ppm         ;
extern int32_t fine_locked      ;
extern int32_t narrow_state     ;
extern int32_t cnt_for_narrow   ;
extern int32_t loopflt_out      ;
extern int32_t dac_Ka           ;
extern int32_t dac_Kb           ;
extern int32_t dpll_err_d1      ;
extern int32_t DAC_MAX_PIDSTEP  ;
extern int32_t DAC_MAX_NARROWCNT;
extern int64_t dac_nco_left ;
extern int64_t dac_nco_right ;
extern int64_t dac_nco_buf_left ;
extern int64_t dac_nco_buf_right;

extern int16_t  stereo_phase_a;
extern int16_t  stereo_phase_b;
extern int16_t  stereo_phase_c;
extern int8_t   left_mag_delta;
extern int8_t   right_mag_delta;

typedef struct {
	int16_t  L_coeff2 ;
	int16_t  L_coeff3 ;
	int16_t  R_coeff2 ;
	int16_t  R_coeff3 ;
}st_THDCoeff;

void estimate_coarse_ppm(void);
void estimate_fine_ppm  (void);

void asrc_dac_top(        //driven by DAC Interrupt , ASRC_OBUF_LEN=8, 8 PCM samples per Interrupt
				//uint8_t *pUSBData, // USB data in Bytes
				int32_t *pUSB_dacbuf_left,
				int32_t *pUSB_dacbuf_right,

				int32_t *pOUT_dacbuf_left,
				int32_t *pOUT_dacbuf_right);

void asrc_Clean_RingBuf();
uint32_t Asrc_Dac_Fs_Ppm_Init(uint32_t uInBaseAddr);
void asrc_dac_patch_init(void);
void estimation_ppm_init(void);
void estimation_ppm_relock_init(void);
extern void new_asrc_dac_patch_init(void);

#endif /* ASRC_MUSES_FS_PPM_H_ */
