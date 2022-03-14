/*
 ============================================================================
 Name        : test_fir_q31.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sin1k_32k_q31.h"
#include "nds32_filtering_math.h"
#include "nds32_basic_math.h"
#include "nds32_transform_math.h"
//#include "init/init.h"
#include "nds32_pfcounter.h"
#include "aptx.h"
#include "frame.h"
#include "plf.h"

#define size 4096*1

#ifdef  ENABLE_CACHE
extern void cache_invalidate_d();
extern void cache_invalidate_i();
extern void cache_on();
extern void cache_off();
#endif

uint32_t blockSize = BLOCK_SIZE;

uint8_t tempU8[APTX_CODE_BLOCK_SIZE] = {0};


uint8_t tmpU8[APTX_CODE_BLOCK_SIZE *(size/BLOCK_SIZE)] = {0};

uint32_t id_debug = 0;
int main(void) {

#ifdef	ENABLE_CACHE
	#define NDS32_ISIZE         (0x07 << 6)
	#define NDS32_DSIZE         (0x07 << 6)

	unsigned int dcm_cfg,icm_cfg,cache_ctl;

	dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);
	icm_cfg = __nds32__mfsr(NDS32_SR_ICM_CFG);

    /* Check if cache available */
	if((icm_cfg & NDS32_ISIZE) || (dcm_cfg & NDS32_DSIZE)) {
		if(!(__nds32__mfsr(NDS32_SR_CACHE_CTL) & 0x3)) { //cache is off
			cache_invalidate_d();		//invaldiate D$
			cache_invalidate_i(); 		//invalidate ID
			cache_on();					// enable I$ and D$
		}
	}
#endif



	int cout=0;

	int frmSize = blockSize;
	int frmNum;
    q31_t *src;
    q31_t output[size]= {0};
    //q31_t *output;



    frmNum = size/frmSize;
    src = sin1k;
    if( (ERROR == aptx_init(pAptxContCode)) || (ERROR == aptx_init(pAptxContDeCode)))
    {
    	return 0;
    }


    while(cout < frmNum)
    {
    	aptx_encode_frame(pAptxContCode, tempU8, src);

//    	nds32_dup_q7((q7_t*)tempU8,(q7_t*)(tmpU8+APTX_CODE_BLOCK_SIZE*cout),APTX_CODE_BLOCK_SIZE);

    	aptx_decode_frame(pAptxContDeCode, tempU8, output + cout*blockSize);

        src = src + frmSize;
        cout++;
    }

	return EXIT_SUCCESS;
}
