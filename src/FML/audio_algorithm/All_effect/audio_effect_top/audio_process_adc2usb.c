/*
 * audio_effect.c
 *
 *  Created on: Jun 30, 2017
 *      Author: guoax
 */

#include "audio_process_adc2usb.h"
#include "nds32_includes.h"

typedef struct process_adc2usb_ftable_stru
{
	void (*AudioProcessAdc)   (	q31_t *,q31_t *,uint32_t);
	void (*AudioProcessAdc10ms)   (void);
	void (*DspbuffRstAdc)   (uint32_t );
	void (*AdcI2sMux)   (q31_t *,q31_t *,q31_t *,q31_t *,uint32_t);
} process_adc2usb_ftable_t;
extern process_adc2usb_ftable_t *pprocess_adc2usb_ftabl;
void new_patch_adc_i2s_mux (q31_t *pAdcAudioIn, q31_t *pI2sAudioInL, q31_t *pI2sAudioInR, q31_t *pAudioOut, uint32_t len)
{
	nds32_dup_q31(pAdcAudioIn, pAudioOut, len);
	return;
}
void new_patch_audio_process_adc (q31_t *pAudioIn, q31_t *pAudioOut, uint32_t len)
{
	nds32_dup_q31(pAudioIn, pAudioOut, len);
	return;
}
void new_patch_audio_process_adc_10ms (void)
{
	return;
}
void new_patch_dsp_buff_rst_adc(uint32_t blocksize)
{
	return;
}
const process_adc2usb_ftable_t new_process_adc2usb_patch_ftable =
{
    .AudioProcessAdc          = new_patch_audio_process_adc,
    .AudioProcessAdc10ms      = new_patch_audio_process_adc_10ms,
    .DspbuffRstAdc            = new_patch_dsp_buff_rst_adc,
    .AdcI2sMux                = new_patch_adc_i2s_mux,
};

void new_process_adc2usb_patch_init(void)
{
	pprocess_adc2usb_ftabl = (process_adc2usb_ftable_t *)&new_process_adc2usb_patch_ftable;
}
