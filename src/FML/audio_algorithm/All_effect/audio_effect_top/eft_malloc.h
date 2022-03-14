#ifndef __EFT_MALLOC_H__
#define __EFT_MALLOC_H__

#include "comm.h"
#include <stdlib.h>

void MEM_Init(void *pMemPool, UINT16 Len);
void *MEM_Malloc(uint16_t size);
void *MEM_Realloc(void *pOld, UINT16 size);
void MEM_Free(void *pMem);
int MEM_Cmp_Word(const void *buf1, const void *buf2, unsigned int cnt);
int MEM_Cpy_Word(unsigned int *des, const unsigned int *src, unsigned int cnt);

#endif
