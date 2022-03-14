#ifndef _TOP_AUDIO_EFFECT_H_
#define _TOP_AUDIO_EFFECT_H_

extern UINT16 top_audio_in_effect(q31_t *pIn, UINT16 InSize, q31_t *pOut, UINT16 *pOutSize);
extern UINT16 top_audio_out_effect(q31_t *pIn, UINT16 InSize, q31_t *pOut, UINT16 *pOutSize);

#endif
