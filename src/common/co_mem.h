#ifndef __CO_MEM_H__
#define __CO_MEM_H__

#include "comm.h"
#include <stdlib.h>

extern volatile uint32_t g_uEndOfStackAddr;

int MEM_Cmp_Word(const void *buf1, const void *buf2, unsigned int cnt);
int MEM_Cpy_Word(unsigned int *des, const unsigned int *src, unsigned int cnt);
int MEM_Cpy_Byte_Word(unsigned char *des, uint32_t *src, unsigned int cnt);



typedef struct
{
	void *pBaseAddr;
	uint32_t PoolLen;
	void *pStartAddr;
	void *pEndAddr;
}mem_pool_t;

#define MEM_DEBUG
#ifdef MEM_DEBUG
	#define MEM_DBG_INDEX 16
	#define MEM_DBG_NAME_LEN 16

	typedef struct
	{
		char Name[MEM_DBG_INDEX][MEM_DBG_NAME_LEN];
		void *pStartAddr[MEM_DBG_INDEX];
		uint32_t Len[MEM_DBG_INDEX];
		uint8_t index;
	}mem_debug_t;
#else
#endif

void mem_init(void *mem_pool, uint32_t len);

//align: x byte aligned
void * mem_malloc(const char *pName, uint32_t size, uint8_t align);

extern void stack_fill(void);
extern uint32_t stack_high_water_mark_get(void);


#endif
