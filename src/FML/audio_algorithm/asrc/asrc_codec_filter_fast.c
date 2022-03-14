/*
* asrc_codec_filter_fast.c
*
* (1) New ASRC filter with mag compensation,
*      CPU 10M @ 44.1/48k single channel
*      CPU 14M @ 96k single channel
*  Created on: May 10, 2019 *
*
*      Author: lizhen
*/
#include "asrc_codec_filter_fast.h"
#include "nds32_filtering_math.h"
#include "stdint.h"
//fir coefficients in 32Q23 for 44.1/48k fast filter
int32_t (*fir_poly_pffast)[11];
// int32_t  fir_poly_pffast[32][11]
// #if 1
// = {
//      {    63, 2911,-7141,-108867,-71943,317200,306480,-79980,-105121,-5716, 2733,    },
//      {    41, 3090,-8686,-112504,-63419,327427,295302,-87522,-101286,-4405, 2556,    },
//      {    55, 3267,-10351,-116016,-54418,337129,283700,-94561,-97381,-3205, 2381,    },
//      {    70, 3441,-12141,-119381,-44952,346276,271709,-101095,-93421,-2113, 2211,   },
//      {    89, 3610,-14058,-122581,-35036,354838,259367,-107119,-89424,-1124, 2045,   },
//      {   111, 3771,-16103,-125595,-24685,362788,246712,-112634,-85406, -234, 1884,   },
//      {   137, 3923,-18277,-128404,-13917,370099,233782,-117641,-81382,  562, 1730,   },
//      {   167, 4063,-20583,-130987,-2753,376750,220614,-122142,-77367, 1269, 1582,    },
//      {   200, 4187,-23019,-133325, 8786,382717,207249,-126142,-73375, 1891, 1441,    },
//      {   239, 4295,-25586,-135396,20677,387982,193726,-129646,-69418, 2432, 1308,    },
//      {   282, 4381,-28282,-137180,32893,392527,180083,-132664,-65509, 2899, 1182,    },
//      {   331, 4444,-31107,-138659,45409,396338,166360,-135203,-61659, 3294, 1064,    },
//      {   386, 4478,-34058,-139813,58196,399401,152595,-137274,-57878, 3625,  954,    },
//      {   446, 4482,-37131,-140623,71224,401708,138826,-138889,-54176, 3894,  851,    },
//      {   513, 4451,-40323,-141070,84461,403250,125092,-140062,-50562, 4106,  755,    },
//      {   587, 4381,-43629,-141136,97874,404022,111429,-140806,-47044, 4267,  668,    },
//      {   668, 4267,-47044,-140806,111429,404022,97874,-141136,-43629, 4381,  587,    },
//      {   755, 4106,-50562,-140062,125092,403250,84461,-141070,-40323, 4451,  513,    },
//      {   851, 3894,-54176,-138889,138826,401708,71224,-140623,-37131, 4482,  446,    },
//      {   954, 3625,-57878,-137274,152595,399401,58196,-139813,-34058, 4478,  386,    },
//      {  1064, 3294,-61659,-135203,166360,396338,45409,-138659,-31107, 4444,  331,    },
//      {  1182, 2899,-65509,-132664,180083,392527,32893,-137180,-28282, 4381,  282,    },
//      {  1308, 2432,-69418,-129646,193726,387982,20677,-135396,-25586, 4295,  239,    },
//      {  1441, 1891,-73375,-126142,207249,382717, 8786,-133325,-23019, 4187,  200,    },
//      {  1582, 1269,-77367,-122142,220614,376750,-2753,-130987,-20583, 4063,  167,    },
//      {  1730,  562,-81382,-117641,233782,370099,-13917,-128404,-18277, 3923,  137,   },
//      {  1884, -234,-85406,-112634,246712,362788,-24685,-125595,-16103, 3771,  111,   },
//      {  2045,-1124,-89424,-107119,259367,354838,-35036,-122581,-14058, 3610,   89,   },
//      {  2211,-2113,-93421,-101095,271709,346276,-44952,-119381,-12141, 3441,   70,   },
//      {  2381,-3205,-97381,-94561,283700,337129,-54418,-116016,-10351, 3267,   55,    },
//      {  2556,-4405,-101286,-87522,295302,327427,-63419,-112504,-8686, 3090,   41,    },
//      {  2733,-5716,-105121,-79980,306480,317200,-71943,-108867,-7141, 2911,   63,    },
//      };
// #endif
//fir coefficient  in 32Q23 for 96k fast filter
int32_t (*fir_poly_96k_pffast)[5];
// int32_t fir_poly_96k_pffast[32][5]
// #if 1
// = {
//      {    57,17131,116341,113122,15497,  },
//      {    55,18880,119435,109792,13975,  },
//      {    81,20746,122391,106364,12562,  },
//      {   114,22732,125196,102852,11254,  },
//      {   157,24837,127837,99271,10047,   },
//      {   210,27064,130304,95634, 8938,   },
//      {   276,29413,132583,91956, 7922,   },
//      {   357,31882,134667,88249, 6994,   },
//      {   455,34471,136543,84528, 6150,   },
//      {   572,37178,138205,80805, 5385,   },
//      {   711,40000,139645,77093, 4694,   },
//      {   876,42933,140855,73404, 4073,   },
//      {  1069,45974,141830,69749, 3517,   },
//      {  1293,49117,142565,66141, 3022,   },
//      {  1553,52358,143057,62588, 2582,   },
//      {  1852,55688,143304,59100, 2193,   },
//      {  2193,59100,143304,55688, 1852,   },
//      {  2582,62588,143057,52358, 1553,   },
//      {  3022,66141,142565,49117, 1293,   },
//      {  3517,69749,141830,45974, 1069,   },
//      {  4073,73404,140855,42933,  876,   },
//      {  4694,77093,139645,40000,  711,   },
//      {  5385,80805,138205,37178,  572,   },
//      {  6150,84528,136543,34471,  455,   },
//      {  6994,88249,134667,31882,  357,   },
//      {  7922,91956,132583,29413,  276,   },
//      {  8938,95634,130304,27064,  210,   },
//      { 10047,99271,127837,24837,  157,   },
//      { 11254,102852,125196,22732,  114,  },
//      { 12562,106364,122391,20746,   81,  },
//      { 13975,109792,119435,18880,   55,  },
//      { 15497,113122,116341,17131,   57,  }, };
// #endif

//--------------- Equalizer for PFLOW-----------------------------------------
//TODO, add coeff //0->8, 1->11.025, 2->12, 3->16, 4->22.05, 5->24, 6->32, 7->44.1, 8->48, 9->96k
int32_t (*DAC_MAG_COEFF_ARRAY)[5];
// q31_t DAC_MAG_COEFF_ARRAY[5][5]
// #if 1
// = {
//         {133170884,   -30323202,    30338612,    30323202,   104925960}, //mag1 for 48k/32k/24k/16k/12k/8k
//         {402354770,   423410250,    68232679,  -423410250,  -202151993}, //mag0 for 44.1k/22.05k/11.025k
//         {122472762,   -16762415,    29643787,    16762415,   116318907},//mag0 for 44.1k/22.05k/11.025k
//         {494469914,   468018092,    -7190830,  -468018092,  -218843628}, //mag1 for 44.1k/22.05k/11.025k
//         {323788280,   -14150237,    36637165,    14150237,   -91989989},//mag0 for 96k, mag1 not used
//      };
// #endif
extern q31_t dac_mag0_coeff[5];
extern q31_t dac_mag1_coeff[5];

extern q31_t dac0_mag0_state[4];
extern q31_t dac1_mag0_state[4];
extern q31_t dac2_mag0_state[4];
extern q31_t dac3_mag0_state[4];
extern q31_t dac4_mag0_state[4];
extern q31_t dac5_mag0_state[4];
extern q31_t dac6_mag0_state[4];

extern q31_t dac0_mag1_state[4];
extern q31_t dac1_mag1_state[4];
extern q31_t dac2_mag1_state[4];
extern q31_t dac3_mag1_state[4];
extern q31_t dac4_mag1_state[4];
extern q31_t dac5_mag1_state[4];
extern q31_t dac6_mag1_state[4];

extern nds32_bq_df1_q31_t   dac0_mag0_inst;
extern nds32_bq_df1_q31_t   dac1_mag0_inst;
extern nds32_bq_df1_q31_t   dac2_mag0_inst;
extern nds32_bq_df1_q31_t   dac3_mag0_inst;
extern nds32_bq_df1_q31_t   dac4_mag0_inst;
extern nds32_bq_df1_q31_t   dac5_mag0_inst;
extern nds32_bq_df1_q31_t   dac6_mag0_inst;

extern nds32_bq_df1_q31_t   dac0_mag1_inst;
extern nds32_bq_df1_q31_t   dac1_mag1_inst;
extern nds32_bq_df1_q31_t   dac2_mag1_inst;
extern nds32_bq_df1_q31_t   dac3_mag1_inst;
extern nds32_bq_df1_q31_t   dac4_mag1_inst;
extern nds32_bq_df1_q31_t   dac5_mag1_inst;
extern nds32_bq_df1_q31_t   dac6_mag1_inst;
extern uint8_t asrc_return_flag;
//-----------------------------------------------------------------
// copy from ringbuf to xinbuf, and manage the ringbuf read pointer
// for DAC stereo, fs <= 48k sample rate
//----------------------------------------------------------------
void new_asrc_codec_readbuf_fast(
    int32_t *p_ringbuf_left   , //data format 32Q23, 24bits Audio
    int32_t *p_ringbuf_right  , //data format 32Q23, 24bits Audio
    int32_t *p_xinbuf_left    , //data format 32Q23 for pffast
    int32_t *p_xinbuf_right   , //data format 32Q23 for pffast
    int32_t  asrc_ringbuf_len ,
    int32_t  asrc_xinbuf_len  , //xin buffer length
    int64_t *p_nco_buf_left   ,
    int64_t *p_nco_buf_right  ,
    int32_t *p_ringbuf_left_rp,
    int32_t *p_ringbuf_right_rp,
    int32_t  stereo_mode     )
{

    int64_t   int64_temp0;
    int32_t   ii, jj;
    int32_t   xin_idx_left, xin_idx_right;

    int64_t   nco_buf_left, nco_buf_right;
    int32_t   ringbuf_left_rp, ringbuf_right_rp;

    nco_buf_left     = *p_nco_buf_left;
    ringbuf_left_rp  = *p_ringbuf_left_rp;


    //=========================================================
    // get xin, xin_new from the ringbuffer
    // 26 + OBUF_LEN*1.5

    xin_idx_left =  (nco_buf_left) >> (5 + 21); //the new data start

    //update nco_buff, wrap around
    int64_temp0 = xin_idx_left;
    nco_buf_left = nco_buf_left - (int64_temp0 << (5 + 21));

    ringbuf_left_rp  += xin_idx_left;

    if (ringbuf_left_rp >= asrc_ringbuf_len)  //ASRC_OBUF_LEN < ASRC_RINGBUF_LEN/2
    {
        ringbuf_left_rp -= asrc_ringbuf_len; //mod(ASRC_RINGBUF_LEN)
    }
    if(ringbuf_left_rp <0)
    {
    	 ringbuf_left_rp += asrc_ringbuf_len;
    }

    int32_t temp_rp = ringbuf_left_rp;
    if (ringbuf_left_rp + asrc_xinbuf_len < asrc_ringbuf_len)
    {
        for (ii = 0; ii < asrc_xinbuf_len; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++]);   //
        }
    }
    else
    {
        jj = asrc_ringbuf_len - ringbuf_left_rp;
        for (ii = 0; ii < jj; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++]);   //
        }
        temp_rp = 0;
        for ( ; ii < asrc_xinbuf_len; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++]);   //
        }
    }

    if (stereo_mode)
    {

        nco_buf_right    = *p_nco_buf_right;
        ringbuf_right_rp = *p_ringbuf_right_rp;
        xin_idx_right =  (nco_buf_right) >> (5 + 21); //the new data start

        int64_temp0 = xin_idx_right;
        nco_buf_right = nco_buf_right - (int64_temp0 << (5 + 21));

        ringbuf_right_rp += xin_idx_right;

        if (ringbuf_right_rp >= asrc_ringbuf_len)  //ASRC_OBUF_LEN < ASRC_RINGBUF_LEN/2
        {
            ringbuf_right_rp -= asrc_ringbuf_len; //mod(ASRC_RINGBUF_LEN)
        }
        if(ringbuf_right_rp < 0)
        {
        	ringbuf_right_rp += asrc_ringbuf_len;
        }

        temp_rp = ringbuf_right_rp;
        if (ringbuf_right_rp + asrc_xinbuf_len < asrc_ringbuf_len)
        {
            for (ii = 0; ii < asrc_xinbuf_len; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++]);   //
            }
        }
        else
        {
            jj = asrc_ringbuf_len - ringbuf_right_rp;
            for (ii = 0; ii < jj; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++]);   //
            }
            temp_rp = 0;
            for ( ; ii < asrc_xinbuf_len; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++]);   //
            }
        }
    }

    *p_nco_buf_left      = nco_buf_left ;
    *p_ringbuf_left_rp   = ringbuf_left_rp   ;

    if (stereo_mode)
    {
        *p_nco_buf_right     = nco_buf_right   ;
        *p_ringbuf_right_rp  = ringbuf_right_rp   ;
    }
    else
    {
        *p_nco_buf_right     = nco_buf_left    ;
        *p_ringbuf_right_rp  = ringbuf_left_rp    ;
    }
}





void new_asrc_codec96k_pffast(
    int32_t *p_xinbuf_left   ,  //  data format 32Q23
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

{
    int32_t  Mu;  //32Q21
    int32_t  xin_idx;
    int32_t  polyphase_idx;
    int64_t  int64_temp0;
    //int32_t  int32_temp0;
    int32_t  base1_left, base2_left;
    int32_t *xin_buf_new_L;
    int32_t *p_fir_poly;
    int32_t  ii;

    int64_t nco, nco_buf; //temp variables

    nco     = *p_nco;
    nco_buf = *p_nco_buf;

	for (ii = 0; ii < asrc_outbuf_len; ii++)
	{
		nco = nco_buf + fs_ratio;              //[[3]]
		nco_buf = nco;
		xin_idx = (nco >> (5 + 21));               //[[1]]
		polyphase_idx = (nco >> 21) - (xin_idx << 5); //index from zeros //[[3]]
		Mu = (int32_t) (nco - ((nco >> 21) << 21));

		//extend the loop
		xin_buf_new_L = &p_xinbuf_left[xin_idx];//
		p_fir_poly = (int32_t*)&fir_poly_96k_pffast[polyphase_idx][0];

		int64_temp0 = __nds32__smar64(0, xin_buf_new_L[4], p_fir_poly[0]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[3], p_fir_poly[1]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[2], p_fir_poly[2]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[1], p_fir_poly[3]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[0], p_fir_poly[4]);
		base1_left = (int32_t)(int64_temp0 >> (23 - 6)); // coeff in Q23

		//xin_buf_new_L = &p_xinbuf_left[xin_idx];
		//xin_buf_new_R = &p_xinbuf_right[xin_idx];
		p_fir_poly = (int32_t *)&fir_poly_96k_pffast[polyphase_idx + 1][0];
		if (polyphase_idx >= 31)
		{
			xin_buf_new_L = &p_xinbuf_left[xin_idx + 1];
			p_fir_poly = (int32_t *)&fir_poly_96k_pffast[0][0];
		}
		int64_temp0 = __nds32__smar64(0, xin_buf_new_L[4], p_fir_poly[0]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[3], p_fir_poly[1]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[2], p_fir_poly[2]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[1], p_fir_poly[3]);
		int64_temp0 = __nds32__smar64(int64_temp0, xin_buf_new_L[0], p_fir_poly[4]);
		base2_left = (int32_t)(int64_temp0 >> (23 - 6)); // coeff in Q23

		int64_temp0 = (int64_t)base1_left * ((1 << 21) - Mu) + (int64_t)base2_left * Mu; //int32 * 32Q16
		p_obuf_left[ii] = (int32_t) (int64_temp0 >> (21 + 6 - 5 - 0)); //from 32Q23 to 32Q23

	}
    *p_nco     =   nco;
    *p_nco_buf =   nco_buf;
}

void new_asrc_filter_nco_nop(
	int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{

    int32_t  ii;
    int64_t nco, nco_buf; //temp variables

    nco     = *p_nco;
    nco_buf = *p_nco_buf;

	for (ii = 0; ii < asrc_outbuf_len; ii++)
	{
		nco     = nco_buf + fs_ratio;              //[[3]]
		nco_buf = nco;
	}

	*p_nco     =   nco;
	*p_nco_buf =   nco_buf;

}
