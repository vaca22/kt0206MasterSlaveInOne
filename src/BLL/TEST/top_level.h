#ifndef _TOP_LEVEL_H_
#define _TOP_LEVEL_H_

extern void Audio_out(
	q31_t *pDacAddr,
	q31_t *pI2sOutlAddr,
	q31_t *pI2sOutrAddr,
	UINT16 SampleNum
);

extern void Audio_Encode_Test(q31_t *pAdcAddr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum);

extern void top_level_tx_ic(q31_t *pAdcAddr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum);
extern void top_level_rx_ic_step1(UINT8 *pIn, UINT16 Len);
extern void top_level_rx_ic_step2(q31_t *pDacAddr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT32 SampleNum);

#endif
