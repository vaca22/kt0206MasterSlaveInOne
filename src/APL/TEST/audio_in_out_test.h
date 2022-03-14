
#ifndef __AUDIO_IN_OUT_TEST_H__
#define __AUDIO_IN_OUT_TEST_H__

extern void Audio_Encode_Test(q31_t *pAdcAddr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT8 Signal);
extern void Audio_Decode(q31_t *pDaclAddr, q31_t *pDacrAddr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT8 Signal);

#ifdef  __cplusplus
}
#endif

#endif


