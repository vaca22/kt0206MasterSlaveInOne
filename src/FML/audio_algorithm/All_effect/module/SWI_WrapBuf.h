#ifndef __SWI_WRAPBUF_H__
#define __SWI_WRAPBUF_H__

#include <nds32_math_types.h>
#include <stdint.h>
#include <stdbool.h>

//use for wrap data between Audio INT(48 block) and SWI INT(512 frame)
//fix q31 data

typedef struct {
	q31_t   * pBuff ;     //
	int16_t   Rp    ;     //
	int16_t   Wp    ;     //
	uint16_t  BlockSize;  //
	uint16_t  FrameSize;  //
	uint16_t  BuffSize;	  //
} SWI_WrapBuf_t;

//clear SWI_WrapBuf, init parameter
//FrameSize	: SWI INT q31 data size, eg. 512
//BlockSize	: Audio INT q31 data size, eg. 32
//return	: buffer end pointer
#if 0
Wrap.BlockSize = 48;
Wrap.FrameSize = 512;

end_addr = SWI_WrapBuf_Init(&Wrap, 0x50000);
#endif
uint32_t SWI_WrapBuf_GetSize(SWI_WrapBuf_t * pWrap);
q31_t  * SWI_WrapBuf_Init   (SWI_WrapBuf_t * pWrap, uint32_t start_addr);

//Get current Audio INT block data pointer
//return : current block pointer
static inline q31_t * SWI_WrapBuf_ReadBlock(SWI_WrapBuf_t * pWrap) {
	return ((pWrap->pBuff) + (pWrap->Wp));
}

//Write Audio INT block into WrapBuf
//return	: true  -> frame is full, ping-pang buffer switch happened
//			  false -> frame is not full
bool SWI_WrapBuf_WriteBlock(SWI_WrapBuf_t * pWrap, const q31_t * pDataIn);

void SWI_WrapBuf_ReadFrame (SWI_WrapBuf_t * pWrap, q31_t *pFrame);
void SWI_WrapBuf_WriteFrame(SWI_WrapBuf_t * pWrap, const q31_t *pFrame);
#endif /* SWI_WRAPBUF_H_ */
