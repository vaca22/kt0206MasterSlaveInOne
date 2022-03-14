#ifndef _TOP_SOURCE_CODEC_H_
#define _TOP_SOURCE_CODEC_H_

extern UINT32 top_source_codec_init(UINT32 BufBaseAddr, UINT8 TXen, UINT8 SoucrceCodecMode);
extern UINT16 top_source_encode(void *pIn, UINT16 InSize,void *pOut, UINT16 *pOutSize);
extern UINT16 top_source_decode(void *pIn, UINT16 InSize,void *pOut, UINT16 *pOutSize);

#endif
