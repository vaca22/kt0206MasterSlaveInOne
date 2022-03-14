#ifndef __RX_AUDIO_H__
#define __RX_AUDIO_H__

#include "audio.h"
#include "intc.h"
#include "power_on.h"
#include "power_off.h"

#ifdef  __cplusplus
extern "C" {
#endif

extern volatile int32_t g_32HalDacDcOffsetL;
extern volatile int32_t g_32HalDacDcOffsetR;

extern uint32_t AUDIO_OUT_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSiganl, uint8_t ucMode);
extern void AUDIO_OUT_Uninit(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_OUT_Start(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_OUT_Stop(uint16_t usSignal, uint8_t ucMode);
extern void AUDIO_OUT_Isr(void);
extern void AUDIO_OUT_Test_Config(void);

void I2S_AUDIO_OUT_Isr(void);

extern void audio_out_patch_init(void);
extern void new_audio_out_patch_init(void);

#ifdef  __cplusplus
}
#endif

#endif

