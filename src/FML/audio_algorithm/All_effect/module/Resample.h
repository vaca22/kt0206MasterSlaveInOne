/*
 * Resample.h
 *
 *  Created on: Jul 11, 2019
 *      Author: guoax
 */

#ifndef RESAMPLE_H_
#define RESAMPLE_H_
#include "nds32_includes.h"

typedef struct {
	int32_t    DownFiltState[12];
	uint32_t   down_start;
	uint32_t   down_start_d;
}DownsampleStru_t;

typedef struct {
	int32_t    UpFiltState[12];
	int32_t    Up_buff;
} UpsampleStru_t;

void DownSample(q31_t *pSrc, q31_t *pDst, DownsampleStru_t *pInst, uint32_t Nx, uint32_t Len,   uint32_t *OutLen);
void UpSample  (q31_t *pSrc, q31_t *pDst, DownsampleStru_t *pDownInst, UpsampleStru_t *pUpInst, uint32_t Nx, uint32_t InLen, uint32_t  OutLen);
#endif /* RESAMPLE_H_ */
