/*
 * asrc_codec_filter_fast.h
 *
 *  Created on: May 10, 2019
 *      Author: lizhen
 */

#ifndef ASRC_CODEC_FILTER_FAST_H_
#define ASRC_CODEC_FILTER_FAST_H_
#include "nds32_utils_math.h"

void pffast_dac_mag_init(int32_t  usb_dac_fs); // USB FS sample freq
void pffast_seven_dac_mag(
int32_t *pSrc0, //sfix32_en23
int32_t *pSrc1, //sfix32_en23
int32_t *pSrc2, //sfix32_en23
int32_t *pSrc3, //sfix32_en23
int32_t *pSrc4, //sfix32_en23
int32_t *pSrc5, //sfix32_en23
int32_t *pSrc6, //sfix32_en23
int32_t *pDst0, //sfix32_en23
int32_t *pDst1, //sfix32_en23
int32_t *pDst2, //sfix32_en23
int32_t *pDst3, //sfix32_en23
int32_t *pDst4, //sfix32_en23
int32_t *pDst5, //sfix32_en23
int32_t *pDst6, //sfix32_en23
int32_t  usb_dac_fs, // USB FS sample freq
int32_t  num_of_dac, //1~7
int16_t  Len);

void pffast_two_dac_mag(
int32_t *pSrc0, //sfix32_en23
int32_t *pSrc1, //sfix32_en23
int32_t *pDst0, //sfix32_en23
int32_t *pDst1, //sfix32_en23
int32_t  usb_dac_fs, // USB FS sample freq
int32_t  num_of_dac, //1~7
int16_t  Len);

void new_asrc_codec_readbuf_fast(
	int32_t *p_ringbuf_left   , //data format 32Q23, 24bits Audio
	int32_t *p_ringbuf_right  , //data format 32Q23, 24bits Audio
	int32_t *p_xinbuf_left    , //data format 32Q23 for pffast
	int32_t *p_xinbuf_right   , //data format 32Q23 for pffast
	int32_t  asrc_ringbuf_len ,
	int32_t  asrc_xinbuf_len  , //xin buffer length
	int64_t *p_nco_buf_left   ,
	int64_t *p_nco_buf_right  ,
	int32_t *p_ringbuf_left_rp,
	int32_t *p_ringbuf_right_rp,
	int32_t  stereo_mode     );


void asrc_codec48k_pffast(
int32_t *p_xinbuf_left   ,  //  data format 32Q23
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)


void new_asrc_codec96k_pffast(
int32_t *p_xinbuf_left   ,  //  data format 32Q23
int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
int32_t  asrc_outbuf_len ,
int64_t *p_nco           ,
int64_t *p_nco_buf       ,
int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)



void new_asrc_filter_nco_nop(
	int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        );
#endif /* ASRC_CODEC_FILTER_FAST_H_ */
