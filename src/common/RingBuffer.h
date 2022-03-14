#pragma once

#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef struct {
	uint16_t 		WriteCount;
	uint16_t 		ReadCount;
	void 		  * BufferPointer;
	uint16_t		BufferSize;
}RingBuffer_t;

static inline void RingBuffer_Init(RingBuffer_t * pBuf) {
	register uint16_t len = pBuf->BufferSize;
	pBuf->WriteCount += len;
	pBuf->ReadCount += len;
}

static inline int16_t RingBuffer_GetDatalen(RingBuffer_t * pBuf) {
	return (int16_t)(pBuf->WriteCount - pBuf->ReadCount);
}

static inline int16_t RingBuffer_GetFreelen(RingBuffer_t * pBuf) {
	int16_t len = (int16_t)(pBuf->WriteCount - pBuf->ReadCount);
	if(len >= 0) {
		len = pBuf->BufferSize - len;
	}
	return len;
}

static inline void RingBuffer_ReadCountMove(RingBuffer_t * pBuf, int16_t size) {
	pBuf->ReadCount += size;
}

static inline void RingBuffer_WriteCountMove(RingBuffer_t * pBuf, int16_t size) {
	pBuf->WriteCount += size;
}

int16_t RingBuffer_Write(RingBuffer_t * pBuf, const void * pData, int16_t size);
int16_t RingBuffer_Read(RingBuffer_t * pBuf, void * pData, int16_t size);

