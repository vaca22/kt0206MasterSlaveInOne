/*
 * asrc_muses_fs_ppm.h
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 */

#ifndef ASRC_DAC_FS_PPM_PACK_H_
#define ASRC_DAC_FS_PPM_PACK_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_includes.h"
#include "chip_config.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define   ASRC_RINGBUF_LEN  (384)
#define   ASRC_OBUF_LEN     (16 )
#define   ASRC_OBUF_LEN_patch     (AUDIO_SAMPLE_BLOCK_SIZE )
#define   ASRC_XINBUF_LEN   (26 + ASRC_OBUF_LEN + ASRC_OBUF_LEN/2)
#define   ASRC_XINBUF_LEN_patch   (26 + ASRC_OBUF_LEN_patch + ASRC_OBUF_LEN_patch/2)
#define   ERR_AVG_LEN  (16)
#define   ERR_SHIFT    (4)
/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

typedef void(*AsrcFilterHandle)(
	    int32_t *p_xinbuf_left   ,  //  data format 32Q23
	    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
	    int32_t  asrc_outbuf_len ,
	    int64_t *p_nco           ,
	    int64_t *p_nco_buf       ,
	    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

typedef struct
{
	int32_t *ringbuf_left;
	int32_t *ringbuf_right;
	int32_t *xinbuf_left;
	int32_t *xinbuf_right;

	int32_t  ringbuf_len;
	int32_t  ringbuf_right_rp ;
	int32_t  ringbuf_right_wp ;
	int32_t  ringbuf_left_rp;
	int32_t  ringbuf_left_wp;

	int32_t  xinbuf_len_max;
	int32_t  xinbuf_len; // asrc_xinbuf_len <= ASRC_XINBUF_LEN
	int64_t  nco_left;
	int64_t  nco_right;
	int64_t  nco_buf_left;
	int64_t  nco_buf_right;

	q31_t    compen_coeff[5]  ;  //  coeff for mag compensation , 32x32 EQ
	q31_t    compen_left_state[4];  //state for left mag compensation
	q31_t    compen_right_state[4];  //state for left mag compensation

	int32_t  usb_audio_out_off_cnt;
	int16_t  usb_audio_out_off_cnt_thrsh;
	int16_t  usb_write_firstxx_packet;
//	int16_t  usb_write_packet_num;
	int16_t  usb_write_firstxx_packet_thrsh;
//	uint8_t  dac_interrupt_cnt;
	//---------------------------------------------------------------------------------------------
	/*performance level, SNDR and CPU cost tradeoff option
	  0:pfzero 10M , 1:pflow 20M, 2:pfmid 30M,3: pfhigh 40M for 48k stereo audio
	  0 or 1, pflow,  2: pfmid, 3:pfhigh for 96k stereo audio */
//	uint8_t ASRC_DAC_PFORMANCE; /*only support 0,2,3*/
//	uint8_t ASRC_DAC_PFORMANCE_96K; /*only support 2,3*/
	uint8_t ppm_range;
	uint8_t En;

	int32_t USB_DAC_FS;         //0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
	int32_t USB_DAC_FS_D; //sample rate delay
	int32_t USB_DAC_EOF_FLAG;
//	int32_t USB_DAC_ASRC_ENABLE;


	int32_t DAC_FS_RATIO_Q26;  //Fsin/Fsout in Q26 format, 48k/46.875k*2^26
	int32_t DAC_STEREO_MODE;
	int32_t REMAIN_NUM_TARGET;




//	int32_t remain_num_d     ;
	int32_t remain_num       ;
	int32_t remain_num_min   ;
//	int32_t remain_num_min0  ;
//	int32_t remain_min_search;
//	int32_t remain_delta0;

	int32_t start_coarse_ppm   ;
//	int32_t start_coarse_ppm_d ;
//	int32_t coarse_cnt ;
//	int32_t coarse_cnt2 ;
	int32_t coarse_state     ;
//	int32_t coarse_ppm_scale ;
	int32_t coarse_ppm       ;
	int32_t coarse_ppm_hold  ;
	int32_t coarse_locked    ;
	int32_t coarse_unlock;
//	int32_t coarse_ppm_abs;

	int32_t fine_ppm         ;
//	int32_t fine_locked      ;
	int32_t narrow_state     ;
	int32_t cnt_for_narrow   ;
	int32_t loopflt_out      ;
	int32_t dac_Ka           ;
	int32_t dac_Kb           ;
	int32_t dpll_err_d1      ;
//	int32_t DAC_MAX_PIDSTEP  ;
//	int32_t DAC_MAX_NARROWCNT;
	int32_t DAC_MAX_PPM ;
	int32_t dac_fs_ratio;
	int16_t dac_loop_out_scale;
//	int32_t dpll_bw_sel;

	int16_t dpll_err_array[ERR_AVG_LEN];
	int16_t dpll_err_array2[ERR_AVG_LEN];
}AsrcOut_t;

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern AsrcOut_t g_st_AsrcI2S;
extern int32_t (*fir_poly_pffast)[11];
extern int32_t (*fir_poly_96k_pffast)[5];
extern int32_t (*DAC_MAG_COEFF_ARRAY)[5];
extern const int32_t new_fir_poly_pffast[32][11];
extern const int32_t new_fir_poly_96k_pffast[32][5];
extern const int32_t new_DAC_MAG_COEFF_ARRAY[5][5];

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
uint32_t Pack_Asrc_Out_Init     (AsrcOut_t *pAsrcStru, uint32_t uInBaseAddr,      uint32_t MaxPpm,            uint32_t STEREO_MODE );
void     Pack_Asrc_write_ringbuf(AsrcOut_t *pAsrcStru, int32_t *pUSB_dacbuf_left, int32_t *pUSB_dacbuf_right, uint32_t   Len);
void     Pack_Asrc_dac_top      (AsrcOut_t *pAsrcStru, int32_t *pOUT_dacbuf_left, int32_t *pOUT_dacbuf_right, int32_t    USB_OUT_FS);
#endif /* ASRC_MUSES_FS_PPM_H_ */
