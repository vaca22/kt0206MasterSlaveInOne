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
#include "celt_angle_q31.h"
#include "nds32_utils_math.h"
//#include "nds32_basic_math.h"
#include "nds32_transform_math.h"
//#include "init.h"
#include "nds32_pfcounter.h"
#include "celt.h"
#include "opus_celt121.h"

#include "celt_signal_in.h"
#define size 8000

#ifdef  ENABLE_CACHE
extern void cache_invalidate_d();
extern void cache_invalidate_i();
extern void cache_on();
extern void cache_off();
#endif

int16_t        sig_out[size]={0};
extern int16_t sig_1499Hz[];
int32_t        current_samples;


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
    q31_t *src;
    q31_t *dst;
    q31_t output[size];

    src = angle;
    dst = output;

	OpusCustomMode *celt_mode=NULL;
	OpusCustomEncoder *celt_enc;
	OpusCustomDecoder *celt_dec;

    unsigned char data[MAX_PACKET];

    int16_t *in, *out;
	int err;
    int len;
	in  = &sig_1499Hz[0];

	out = &sig_out[0];
	celt_mode = opus_custom_mode_create(48000, celt_frame_size, NULL);
	celt_enc = opus_custom_encoder_create(celt_mode, 1, &err);
  	celt_dec = opus_custom_decoder_create(celt_mode, 1, &err);

  	opus_custom_encoder_ctl(celt_enc, OPUS_SET_COMPLEXITY(celt_complexity));
  	opus_custom_decoder_ctl(celt_dec, OPUS_SET_COMPLEXITY(celt_complexity));


    memset(output,0,sizeof(q31_t)*size);

//    acc_result pfmResult = {0, 0};  //Added by Tang Lei at 2017/1/8
//    startPFM;

    while(cout < 66)
        {
        	//*dst = nds32_cos_q31(*src);
         	//src++;
        	//dst++;
       	cout++;

    	len = opus_custom_encode(celt_enc, in, celt_frame_size, data, celt_bytes_per_packet);
    	err = opus_custom_decode(celt_dec, data, celt_bytes_per_packet, out, celt_frame_size);

  		 in += celt_frame_size;
  		 out+= celt_frame_size;
  		 current_samples += celt_frame_size;
        }


//    stopPFM;   						//Added by Tang Lei at 2017/1/8
//    ACC_Result(&pfmResult);			//Added by Tang Lei at 2017/1/8
//    Read_ACC_Result(&pfmResult);	//Added by Tang Lei at 2017/1/8
	return EXIT_SUCCESS;
}
