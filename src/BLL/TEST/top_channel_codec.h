#ifndef _TOP_CHANNEL_CODEC_H_
#define _TOP_CHANNEL_CODEC_H_

extern UINT16 top_channel_encode(UINT8 *pIn, UINT16 InSize, UINT8 *pOut, UINT16 *pOutSize);
extern UINT16 top_channel_decode(UINT8 *pIn, UINT16 InSize, UINT8 *pOut, UINT16 *pOutSize);

#endif
