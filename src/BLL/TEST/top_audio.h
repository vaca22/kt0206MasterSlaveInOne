#ifndef _TOP_AUDIO_H_
#define _TOP_AUDIO_H_

extern UINT32 top_audio_init(UINT8 BoundingTXen, UINT32 FifoBaseAddr, AudioHandle audio_in_handler,
			AudioHandle audio_out_handler);
extern void top_audio_in(q31_t *pAdcAddr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum);
extern void top_audio_out(q31_t *pDacAddr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT32 SampleNum);

#endif
