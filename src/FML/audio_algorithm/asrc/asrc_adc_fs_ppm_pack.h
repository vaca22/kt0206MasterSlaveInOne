/*
 * asrc_adc_fs_ppm_pack.h
 *
 *  Created on: Aug 27, 2020
 *      Author: guoaixiang
 */

#ifndef ASRC_ADC_FS_PPM_PACK_H_
#define ASRC_ADC_FS_PPM_PACK_H_
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_includes.h"
#include "chip_config.h"
#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define   ASRC_ADC_IBUF_LEN_patch     (AUDIO_SAMPLE_BLOCK_SIZE)
#define   ASRC_ADC_OBUF_LEN     (96 )  //PCM sample in 1ms USB frame, max 96 for 96k sample
#define   ASRC_ADC_XINBUF_LEN_patch   (26 + ASRC_ADC_OBUF_LEN_patch + ASRC_ADC_OBUF_LEN_patch/2)

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
	int32_t *pRingBufLeft;
	int32_t *pRingBufRight;
	uint32_t RingBufLen;
	int32_t  RingBufLeftRp;
	int32_t  RingBufLeftWp;
	int32_t  RingBufRightRp;
	int32_t  RingBufRightWp;

	int32_t *pXinBufLeft;
	int32_t *pXinBufRight;
	uint32_t XinBufLenMax;
	uint32_t XinBufLen;

	uint32_t AdcInLen;

	uint8_t En;
	// uint8_t ppm_range;
	uint8_t ADC_STEREO_MODE;
	uint8_t ADC_DOWN_N;
	uint8_t adc_decimated_len; 
	// uint8_t USB_ADC_FS;   //0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
	uint8_t USB_ADC_FS_D; //sample rate delay
	uint8_t USB_ADC_EOF_FLAG;
	uint8_t USB_ADC_PCM_NUM ;  //PCM sample number in 1ms seconds
	//performance level, SNDR and CPU cost tradeoff option
	// 0:pfzero 10M , 1:pflow 20M, 2:pfmid 30M,3: pfhigh 40M for 48k stereo audio
	// 0 or 1, pflow,  2: pfmid, 3:pfhigh for 96k stereo audio
	uint8_t ASRC_ADC_PFORMANCE; //0,2,3 performance
	// uint8_t ADC_LPF_USBFS_SEL_ENABLE;
	int32_t *pDecFiltCoeff;
	int32_t DecFiltStateLeft[4*5];
	int32_t DecFiltStateRight[4*5];

    //usb read data monitor
	int16_t usb_read_firstxx_packet;
	int16_t usb_read_firstxx_packet_thrsh;
	int16_t usb_audio_in_off_cnt;
	int16_t usb_audio_in_off_cnt_thrsh;


	int32_t ADC_FS_RATIO_Q26;  //Fsin/Fsout in Q26 format, 46.875k/48k*2^26
	int32_t adc_fs_ratio ;

	int32_t ADC_MAX_PPM;
	int32_t REMAIN_NUM_TARGET;
	int32_t adc_remain_num ;


    //coarse ppm
    uint8_t restart_asrc_in;
	uint8_t start_adc_coarse_ppm;
	uint8_t adc_coarse_state;
	uint8_t adc_coarse_locked ;
	int32_t adc_remain_num0 ;
	int32_t adc_coarse_ppm_scale ;
	int32_t adc_coarse_ppm ;
	int32_t adc_coarse_cnt ;

    //fine ppm
    int32_t adc_coarse_ppm_hold ;
	int32_t remain_min_search_cnt;
	int32_t adc_remain_min_search;
	int32_t adc_remain_num_min ;
	int32_t ADC_LOCAL_MIN_WINDOW;
	int32_t adc_fine_ppm ;
	int32_t adc_narrow_state;
	int32_t adc_cnt_for_narrow ;
	int32_t adc_dpll_err_d1;
	int32_t adc_loopflt_out ;
	int16_t adc_loop_out_scale;



	int64_t left_nco ;
	int64_t left_nco_buf;
	int64_t right_nco ;
	int64_t right_nco_buf;

}AsrcIn_t;

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern const int32_t ADC_LPF_COEFF_ARRAY[35][5];
extern AsrcIn_t g_st_AsrcI2SIN;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */

uint32_t Pack_Asrc_In_Init(AsrcIn_t *pAsrcStru, uint32_t uInBaseAddr, uint32_t stereo_mode, uint32_t MaxPpm, int32_t usb_in_fs);
void 	 Pack_asrc_In_Writebuf(AsrcIn_t *pAsrcStru, int32_t *pDataL, int32_t *pDataR, uint32_t USB_IN_FS);
void 	 Pack_asrc_In_Top(AsrcIn_t *pAsrcStru, int32_t *pDataL, int32_t *pDataR, int32_t USB_IN_PCM_NUM);

void 	 Pack_Asrc_In_Relock(AsrcIn_t *pAsrcStru);
void 	 Pack_Asrc_In_FsSwitch(AsrcIn_t *pAsrcStru, uint32_t usb_in_fs);
void 	 Pack_Asrc_In_CoarsePpm(AsrcIn_t *pAsrcStru, uint32_t USB_IN_FS);
void 	 Pack_Asrc_In_FinePpm(AsrcIn_t *pAsrcStru);

#endif /* (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2) */
#endif /* ASRC_ADC_FS_PPM_PACK_H_ */
