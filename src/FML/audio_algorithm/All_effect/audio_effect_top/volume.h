/*
 * reverb.h
 *
 *  Created on: May 25, 2017
 *      Author: lizhen
 */

#ifndef VOLUME_H_
#define VOLUME_H_

#include "reg_dsp.h"

#define BIT_MIC		BIT0
#define BIT_SPK		BIT1
#define BIT_ST		BIT2 //sidetone

#define DSP_GAIN_SHIFT (11)

extern uint8_t g_mute_bit;

extern const uint16_t volume_table[128];
extern uint8_t dsp_prevol_i2sL ;
extern uint8_t dsp_prevol_i2sR ;
extern uint8_t dsp_usb_postvol ;//音频上传到usb的音量，是否可以删除这个音量，释放一点cpu
extern uint8_t dsp_adc2usb_vol;//host设置的mic音量
extern uint8_t dsp_adc2dac_vol;
extern uint8_t dsp_usb2dac_vol;//没有用？？
extern uint8_t dsp_usb2dac_vol_l;//host上面调节的喇叭右声道单独的音量
extern uint8_t dsp_usb2dac_vol_r;//host上面调节的喇叭右声道单独的音量
extern uint8_t dsp_usb2aec_vol;
extern uint8_t dsp_dac_postvol;//host上面调节的喇叭音量

extern uint8_t dsp_i2so_vol_l;
extern uint8_t dsp_i2so_vol_r;
extern int64_t g_dsp_i2so_vol_l_buff;
extern int64_t g_dsp_i2so_vol_r_buff;

extern int64_t g_usb_postvol_buff;
extern int64_t g_adc2usb_vol_buff;
extern int64_t g_usb2dac_vol_buff;
extern int64_t g_usb2dac_vol_buff_l;
extern int64_t g_usb2dac_vol_buff_r;
extern int64_t g_dac_postvol_buff;
extern int64_t g_dsp_prevol_i2sL_buff_l;
extern int64_t g_dsp_prevol_i2sR_buff_r;
extern int64_t g_adc2dac_vol_buff;

extern uint16_t g_dsp_gain_dacl;
extern uint16_t g_dsp_gain_dacr;
extern uint16_t g_dsp_gain_adc;
extern uint16_t g_dsp_gain_i2sil;
extern uint16_t g_dsp_gain_i2sir;
extern uint16_t g_dsp_gain_i2sol;
extern uint16_t g_dsp_gain_i2sor;
void Dsp24bitVolumeSmooth(
		int32_t * pIN_Data,  //LSB 24bits,
		int32_t * pOUT_Data, //LSB 24bits,
		uint16_t  vol,
		int64_t * SmoothBuff,
		uint16_t Len);

void Dsp16bitVolume(
		int16_t *pIN_Data,  //LSB 16bits,
		int32_t *pOUT_Data, //LSB 24bits,
		uint16_t vol,
		uint16_t Len);
void Dsp24bitVolume(
		int32_t *pIN_Data,  //LSB 24bits,
		int32_t *pOUT_Data, //LSB 24bits,
		uint16_t vol,
		uint16_t Len);

void DspPostVolume(
		int32_t *pIN_Data,  //LSB 24bits,
		int32_t *pOUT_Data, //LSB 24bits,
		uint16_t Len);
void volume_patch_init(void);


void Dsp24bitVolume_Sat(
		int32_t *pIN_Data,
		int32_t *pOUT_Data,
		uint16_t vol,
		uint16_t Len);

void Dsp24bitVolumeSmoothStereo(
    int32_t * pIN_DataL,  //LSB 24bits,
    int32_t * pIN_DataR,  //LSB 24bits,
    int32_t * pOUT_DataL, //LSB 24bits,
    int32_t * pOUT_DataR, //LSB 24bits,
    uint16_t  vol,
    int64_t * SmoothBuff,
    uint16_t Len);

#endif /* REVERB_H_ */
