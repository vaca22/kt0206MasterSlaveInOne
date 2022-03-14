/*
 * asrc_muses.h
 *
 *  Created on: Mar 15, 2018
 *      Author: lizhen
 */
#ifndef ASRC_CODEC_FLT_H_
#define ASRC_CODEC_FLT_H_

#include "nds32_utils_math.h"


void asrc_codec48k_readbuf(
  		int32_t *p_ringbuf_left   , //data format 32Q23, 24bits Audio
  		int32_t *p_ringbuf_right  , //data format 32Q23, 24bits Audio
 		int32_t *p_xinbuf_left    , //data format 32Q19 for asrc filter
  		int32_t *p_xinbuf_right   , //data format 32Q19 for asrc filter
  		int32_t  asrc_ringbuf_len ,
 		int32_t  asrc_xinbuf_len  , //xin buffer length
  		int64_t *p_nco_buf_left   ,
  		int64_t *p_nco_buf_right  ,
  		int32_t *p_ringbuf_left_rp,
  		int32_t *p_ringbuf_right_rp,
  		int32_t  stereo_mode     );


void asrc_codec_pfzero(
int32_t *p_xinbuf_left   ,  // ringbuffer, data format 32Q19 !!!
//int32_t *p_xinbuf_right  ,  // ringbuffer, data format 32Q19 !!!
int32_t *p_obuf_left     ,  // outbuffer,  data format 32Q23
//int32_t *p_obuf_right    ,  // outbuffer,  data format 32Q23
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)



void asrc_codec_pflow(
int32_t *p_xinbuf_left   ,  //  data format 32Q19
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_codec_pfmid(
int32_t *p_xinbuf_left   ,  //  data format 32Q19
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_codec_pfhigh(
int32_t *p_xinbuf_left   ,  //  data format 32Q19
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_codec96k_readbuf(
    		int32_t *p_ringbuf_left   , //32Q23, 24bits audio
    		int32_t *p_ringbuf_right  , //32Q23, 24bits audio
   		    int32_t *p_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    		int32_t *p_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    		int32_t  asrc_ringbuf_len ,
   		    int32_t  asrc_xinbuf_len  , //xinbuffer length
    		int64_t *p_nco_buf_left   ,
    		int64_t *p_nco_buf_right  ,
       		int32_t *p_ringbuf_left_rp,
       		int32_t *p_ringbuf_right_rp,
    		int32_t  bitcut_en        , // 0 :high performance, 1: mid or low performance
    		int32_t  stereo_mode      );


void asrc_codec96k_pflow(
int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_codec96k_pfmid(
		int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
		int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
		int32_t  asrc_outbuf_len ,
		int64_t *p_nco           ,
		int64_t *p_nco_buf       ,
		int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_codec96k_pfhigh(          // high performance
int32_t *p_xinbuf_left   ,  //  data format 32Q23, !!!
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void asrc_adc_lpf(
		int32_t *pSrc,              //sfix32_en23
		int32_t *pDst,              //sfix32_en23
		int32_t  adc_lpf_usbfs_sel, // USB FS sample freq
		int16_t  Len
		);

void asrc_adc_lpf_init(int32_t adc_lfp_usbfs_el);
/*
void asrc_dac_pfzero(
int32_t *p_xinbuf_left   ,  // ringbuffer, data format 32Q19 !!!
int32_t *p_xinbuf_right  ,  // ringbuffer, data format 32Q19 !!!
int32_t *p_obuf_left     ,  // outbuffer,  data format 32Q23
int32_t *p_obuf_right    ,  // outbuffer,  data format 32Q23
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio     )   ;//in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
*/

void asrc_codec_patch_init(void);
void new_asrc_codec_patch_init(void);
#endif /* ASRC_QIANHAI_H_ */
