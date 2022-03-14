/*
 * mixer.c
 *
 *  Created on: July 11, 2017
 *      Author: lizhen
 *  lizhen 2017/07/25 (1) add noise gate mute logic for I2S
 *                    (2) change ramp logic
 */


#include "nds32_utils_math.h"
#include "volume.h"
#include "reg_dsp.h"
#include "hal_includes.h"

uint8_t g_mute_bit = 0;

uint8_t dsp_usb2dac_vol_l   = 103;
uint8_t dsp_usb2dac_vol_r   = 103;

uint8_t dsp_i2so_vol_l   = 103;
uint8_t dsp_i2so_vol_r   = 103;
int64_t g_dsp_i2so_vol_l_buff = 0;
int64_t g_dsp_i2so_vol_r_buff = 0;

int64_t g_dsp_prevol_i2sL_buff_l = 0;
int64_t g_dsp_prevol_i2sR_buff_r = 0;

int64_t g_adc2dac_vol_buff   = 0;
int64_t g_usb2dac_vol_buff_l = 0;
int64_t g_usb2dac_vol_buff_r = 0;

uint16_t g_dsp_gain_dacl = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_dacr = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_adc  = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_i2sil  = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_i2sir  = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_i2sol  = (1<<DSP_GAIN_SHIFT);
uint16_t g_dsp_gain_i2sor  = (1<<DSP_GAIN_SHIFT);
void Dsp24bitVolume_Sat(
		int32_t *pIN_Data,
		int32_t *pOUT_Data,
		uint16_t vol,
		uint16_t Len)
{
    uint16_t ii;
    int32_t *pIn, *pOut;

    register int64_t  temp64_0;
    for (ii = 0; ii < Len; ii += 4)
    {
        pIn  = pIN_Data + ii;
        pOut = pOUT_Data + ii;

        temp64_0 = (int64_t)pIn[0] * vol;
        temp64_0 = temp64_0 >> DSP_GAIN_SHIFT;
        pOut[0] = __nds32__clips((int32_t) temp64_0, 23);

        temp64_0 = (int64_t)pIn[1] * vol;
        temp64_0 = temp64_0 >> DSP_GAIN_SHIFT;
        pOut[1] = __nds32__clips((int32_t) temp64_0, 23);


        temp64_0 = (int64_t)pIn[2] * vol;
        temp64_0 = temp64_0 >> DSP_GAIN_SHIFT;
        pOut[2] = __nds32__clips((int32_t) temp64_0, 23);


        temp64_0 = (int64_t)pIn[3] * vol;
        temp64_0 = temp64_0 >> DSP_GAIN_SHIFT;
        pOut[3] = __nds32__clips((int32_t) temp64_0, 23);
    }

} //end function

void Dsp24bitVolumeSmoothStereo(
    int32_t * pIN_DataL,  //LSB 24bits,
    int32_t * pIN_DataR,  //LSB 24bits,
    int32_t * pOUT_DataL, //LSB 24bits,
    int32_t * pOUT_DataR, //LSB 24bits,
    uint16_t  vol,
    int64_t * SmoothBuff,
    uint16_t Len)
{
    uint16_t ii;
    uint16_t vol_smooth;
    register int64_t  temp64_0;

    int32_t *pInL, *pOutL;
    int32_t *pInR, *pOutR;

    if ((stUsbAudio.u8Mute & BIT_SPK) || (g_mute_bit & BIT_SPK)) {
        for (ii = 0; ii < Len; ii += 4)
        {
            //-----------------------------for vol smooth-----------------------------//
            *SmoothBuff = (vol) + ((*SmoothBuff * 1023) >> 10);
            vol_smooth = (uint16_t)(*SmoothBuff >> 10);
            //-----------------------------for vol smooth-----------------------------//
            pOutL[0] = 0;
            pOutL[1] = 0;
            pOutL[2] = 0;
            pOutL[3] = 0;

            pOutR[0] = 0;
            pOutR[1] = 0;
            pOutR[2] = 0;
            pOutR[3] = 0;
        }
    } else {
        for (ii = 0; ii < Len; ii += 4)
        {
            //-----------------------------for vol smooth-----------------------------//
            *SmoothBuff = (vol) + ((*SmoothBuff * 1023) >> 10);
            vol_smooth = (uint16_t)(*SmoothBuff >> 10);
            //-----------------------------for vol smooth-----------------------------//
            pInL  = pIN_DataL + ii;
            pOutL = pOUT_DataL + ii;

            temp64_0 = pInL[0];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutL[0] = (int32_t) temp64_0;


            temp64_0 = pInL[1];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutL[1] = (int32_t) temp64_0;


            temp64_0 = pInL[2];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutL[2] = (int32_t) temp64_0;


            temp64_0 = pInL[3];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutL[3] = (int32_t) temp64_0;


            pInR  = pIN_DataR + ii;
            pOutR = pOUT_DataR + ii;

            temp64_0 = pInR[0];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutR[0] = (int32_t) temp64_0;


            temp64_0 = pInR[1];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutR[1] = (int32_t) temp64_0;


            temp64_0 = pInR[2];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutR[2] = (int32_t) temp64_0;


            temp64_0 = pInR[3];
            temp64_0 = temp64_0 * vol_smooth;
            temp64_0 = temp64_0 >> 13;
            pOutR[3] = (int32_t) temp64_0;
        }
    }
} //end function
