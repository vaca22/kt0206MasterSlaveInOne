/*
 * audio_process_usb2dac.h
 *
 *  Created on: Jun 30, 2017
 *      Author: guoax
 */

#ifndef AUDIO_PROCESS_USB2DAC_H_
#define AUDIO_PROCESS_USB2DAC_H_

void new_patch_audio_dac_rail_ctrl(
    q31_t *pToDacL,
    q31_t *pToDacR,
    q31_t *tempbuff,
    uint32_t len);
void new_process_usb2dac_patch_init(void);

#endif /* AUDIO_EFFECT_H_ */
