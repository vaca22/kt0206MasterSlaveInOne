#ifndef __TX_AUDIO_H__
#define __TX_AUDIO_H__

#include "audio.h"
#include "intc.h"
#include "power_on.h"
#include "power_off.h"

#ifdef  __cplusplus
extern "C" {
#endif

extern uint32_t AUDIO_IN_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal,	uint8_t ucMode);
extern void AUDIO_IN_Uninit(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_IN_Start(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_IN_Stop(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_IN_Isr(void);

extern void audio_in_patch_init(void);
extern void new_audio_in_patch_init(void);

#ifdef  __cplusplus
}
#endif

#endif