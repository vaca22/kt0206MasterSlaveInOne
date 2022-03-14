/*
 * i2s_nco_writebuf.h
 *
 *  Created on: Jun 27, 2018
 *      Author: lizhen
 */

#ifndef I2S_NCO_WRITEBUF_H_
#define I2S_NCO_WRITEBUF_H_

#include "comm.h"

extern uint32_t USB_I2SNCO_EOF_FLAG;

extern uint32_t i2s_nco_ringbuf_len;
extern uint32_t i2s_nco_high_thrsh;		//I2S_NCO_HIGH_THRSH;
extern uint32_t i2s_nco_low_thrsh;		//I2S_NCO_HIGH_THRSH;
extern uint32_t fcw_delta_step_ppm;
extern uint32_t i2s_nco_mdfy_period;	//driven by USB


extern int32_t *g_pI2sNcoRingBufLeft;
extern int32_t *g_pI2sNcoRingBufRight;

extern uint32_t usb_audio_fs;		//usb audio sample frequency
extern uint32_t i2s_nco_ringbuf_rp;
extern uint32_t i2s_nco_ringbuf_wp;
extern uint32_t i2s_nco_remain_num;
extern uint32_t usb_dongle_int_cnt;

typedef struct{
	uint32_t sclk_lrclk_rate;		//sclk:lrclk = 64 or 128
	uint32_t i2s_nco_ringbuf_len;	//e.g. 384
	uint32_t i2s_nco_high_thrsh;	//e.g. i2s_nco_ringbuf_len*3/5
	uint32_t i2s_nco_low_thrsh;		//e.g. i2s_nco_ringbuf_len*2/5
	uint32_t fcw_delta_step_ppm;	//e.g. 20ppm
	uint32_t i2s_nco_mdfy_period;	//>400, e.g. 500
}st_i2s_nco_param;

typedef struct{
	uint8_t i2s_nco_average_cnt;
	uint32_t i2s_nco_sable_period;
	uint32_t i2s_nco_error_num;
	int32_t i2s_nco_high_delta_fcw;
	int32_t i2s_nco_low_delta_fcw;
}st_i2s_nco_param1;

//void i2s_nco_writebuf(int32_t *pDataLeft,int32_t *pDataRight);
extern void i2s_nco_writebuf(int32_t *pDataLeft,int32_t *pDataRight, uint8_t sampnum);
extern uint32_t I2s_Nco_Buf_Init(uint32_t uInBaseAddr);
extern void i2s_nco_param_init(st_i2s_nco_param param);
extern void i2s_nco_rbuf_reset(void);
extern void nco_write_patch_init(void);
#endif /* I2S_NCO_WRITEBUF_H_ */
