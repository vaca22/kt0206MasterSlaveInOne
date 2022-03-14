/*
 * asrc_muses.c
 *
 *  Created on: Mar 15, 2018
 *      Author: lizhen
 */
#include "asrc_codec_filter.h"
#include "nds32_filtering_math.h"
#include "com_includes.h"
extern int32_t ADC_LPF_USBFS_SEL_ENABLE;
//firpoly for PFZERO,  in 32Q17, max value <32767, so int16
typedef struct asrc_codec_ftable_stru
{
    void (*asrc_adc_lpf_init) (int32_t);
    void (*asrc_adc_lpf) (int32_t *, int32_t *, int32_t , int16_t);
    void (*asrc_codec48k_readbuf) (int32_t *, int32_t *, int32_t *, int32_t *, int32_t  , int32_t  , int64_t *, int64_t *, int32_t *, int32_t *, int32_t );
    void (*asrc_codec_pfzero) (int32_t *, int32_t * , int32_t  , int64_t *, int64_t *, int32_t);
    void (*asrc_codec_pflow) (int32_t *, int32_t *, int32_t, int64_t *, int64_t * , int32_t);
    void (*asrc_codec_pfmid) (int32_t *, int32_t *, int32_t , int64_t *, int64_t *, int32_t);
    void (*asrc_codec_pfhigh) (int32_t *, int32_t *, int32_t, int64_t *, int64_t *, int32_t);
    void (*asrc_codec96k_readbuf) ( int32_t *,
                                    int32_t *,
                                    int32_t *,
                                    int32_t *,
                                    int32_t  ,
                                    int32_t  ,
                                    int64_t *,
                                    int64_t *,
                                    int32_t *,
                                    int32_t *,
                                    int32_t  ,
                                    int32_t );
    void (*asrc_codec96k_pflow) (int32_t *, int32_t *, int32_t, int64_t *, int64_t *, int32_t);
    void (*asrc_codec96k_pfmid) (int32_t *, int32_t *, int32_t, int64_t *, int64_t *, int32_t);
    void (*asrc_codec96k_pfhigh) (int32_t *, int32_t *, int32_t, int64_t *, int64_t *, int32_t);
} asrc_codec_ftable_t;

asrc_codec_ftable_t *pasrc_codec_ftabl = NULL;
extern const int16_t fir_poly_pfzero[32][4];

//fir poly phase    coefficients in 32Q23
extern const int32_t  fir_poly_pfmid[32][18];

//fir poly  coefficient in 32Q22 for high performance
extern const int32_t  fir_poly_pfhigh[32][25];

//fir poly coefficient  in 32Q17 for 96k low performance
extern const int32_t fir_poly_96k_pflow[32][5];

// fir poly coefficient in 32Q20 for 96k mid performance
extern const int32_t fir_poly_96k_pfmid[32][7];

//fir poly  coefficient in 32Q22 for 96k high performance
extern const int32_t fir_poly_96k_pfhigh[32][9];

//----------------- 10th LPF for decimation -------------------------------------------//
// coeff in 32Q28, [b0,b1,b2,-a1,-a2], shiftpositive=3
extern q31_t adc_lpf0_coeff[5];
extern q31_t adc_lpf1_coeff[5];
extern q31_t adc_lpf2_coeff[5];
extern q31_t adc_lpf3_coeff[5];
extern q31_t adc_lpf4_coeff[5];

extern q31_t adc_lpf0_state[4];
extern q31_t adc_lpf1_state[4];
extern q31_t adc_lpf2_state[4];
extern q31_t adc_lpf3_state[4];
extern q31_t adc_lpf4_state[4];

extern nds32_bq_df1_q31_t   adc_lpf0_inst;
extern nds32_bq_df1_q31_t   adc_lpf1_inst;
extern nds32_bq_df1_q31_t   adc_lpf2_inst;
extern nds32_bq_df1_q31_t   adc_lpf3_inst;
extern nds32_bq_df1_q31_t   adc_lpf4_inst;

//coeff in 32Q28, [b0,b1,b2,-a1,-a2], shiftpositive=3
extern const int32_t ADC_LPF_COEFF_ARRAY[35][5];

void asrc_adc_lpf_init(int32_t adc_lpf_usbfs_sel)
{
    pasrc_codec_ftabl->asrc_adc_lpf_init(adc_lpf_usbfs_sel);
}

extern void Patch_asrc_adc_lpf_init(int32_t adc_lpf_usbfs_sel);

void asrc_adc_lpf(
    int32_t *pSrc, //sfix32_en23
    int32_t *pDst, //sfix32_en23
    int32_t  adc_lpf_usbfs_sel, // USB FS sample freq
    int16_t  Len
)
{
    pasrc_codec_ftabl->asrc_adc_lpf(pSrc, pDst, adc_lpf_usbfs_sel, Len);
}

extern void Patch_asrc_adc_lpf(
    int32_t *pSrc, //sfix32_en23
    int32_t *pDst, //sfix32_en23
    int32_t  adc_lpf_usbfs_sel, // USB FS sample freq
    int16_t  Len);

void asrc_codec48k_readbuf(
    int32_t *p_ringbuf_left   , //data format 32Q23, 24bits Audio
    int32_t *p_ringbuf_right  , //data format 32Q23, 24bits Audio
    int32_t *p_xinbuf_left    , //data format 32Q19 for asrc filter
    int32_t *p_xinbuf_right   , //data format 32Q19 for asrc filter
    int32_t  asrc_ringbuf_len ,
    int32_t  asrc_xinbuf_len  , //xin buffer length
    int64_t *p_nco_buf_left   ,
    int64_t *p_nco_buf_right  ,
    int32_t *p_ringbuf_left_rp,
    int32_t *p_ringbuf_right_rp,
    int32_t  stereo_mode     )
{
    pasrc_codec_ftabl->asrc_codec48k_readbuf(
        p_ringbuf_left   , //data format 32Q23, 24bits Audio
        p_ringbuf_right  , //data format 32Q23, 24bits Audio
        p_xinbuf_left    , //data format 32Q19 for asrc filter
        p_xinbuf_right   , //data format 32Q19 for asrc filter
        asrc_ringbuf_len ,
        asrc_xinbuf_len  , //xin buffer length
        p_nco_buf_left   ,
        p_nco_buf_right  ,
        p_ringbuf_left_rp,
        p_ringbuf_right_rp,
        stereo_mode
    );
}

//-----------------------------------------------------------------
// copy from ringbuf to xinbuf, and manage the ringbuf read pointer
// for DAC stereo, fs <= 48k sample rate
//----------------------------------------------------------------
void new_Patch_asrc_codec48k_readbuf(
    int32_t *p_ringbuf_left   , //data format 32Q23, 24bits Audio
    int32_t *p_ringbuf_right  , //data format 32Q23, 24bits Audio
    int32_t *p_xinbuf_left    , //data format 32Q19 for asrc filter
    int32_t *p_xinbuf_right   , //data format 32Q19 for asrc filter
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

    nco_buf_left    = *p_nco_buf_left;
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

    int32_t temp_rp = ringbuf_left_rp;
    if (ringbuf_left_rp + asrc_xinbuf_len < asrc_ringbuf_len)
    {
        for (ii = 0; ii < asrc_xinbuf_len; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++] >> 4); //
        }
    }
    else
    {
        jj = asrc_ringbuf_len - ringbuf_left_rp;
        for (ii = 0; ii < jj; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++] >> 4); //
        }
        temp_rp = 0;
        for ( ; ii < asrc_xinbuf_len; ii++)
        {
            p_xinbuf_left[ii] = (p_ringbuf_left[temp_rp++] >> 4); //
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

        temp_rp = ringbuf_right_rp;
        if (ringbuf_right_rp + asrc_xinbuf_len < asrc_ringbuf_len)
        {
            for (ii = 0; ii < asrc_xinbuf_len; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++] >> 4); //
            }
        }
        else
        {
            jj = asrc_ringbuf_len - ringbuf_right_rp;
            for (ii = 0; ii < jj; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++] >> 4); //
            }
            temp_rp = 0;
            for ( ; ii < asrc_xinbuf_len; ii++)
            {
                p_xinbuf_right[ii] = (p_ringbuf_right[temp_rp++] >> 4); //
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

void asrc_codec_pfzero(
    int32_t *p_xinbuf_left   ,  // ringbuffer, data format 32Q19 !!!
    //int32_t *p_xinbuf_right  ,  // ringbuffer, data format 32Q19 !!!
    int32_t *p_obuf_left     ,  // outbuffer,  data format 32Q23
    //int32_t *p_obuf_right    ,  // outbuffer,  data format 32Q23
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec_pfzero(p_xinbuf_left, p_obuf_left, asrc_outbuf_len, p_nco, p_nco_buf, fs_ratio);
}

extern void Patch_asrc_codec_pfzero(
    int32_t *p_xinbuf_left   ,  // ringbuffer, data format 32Q19 !!!
    //int32_t *p_xinbuf_right  ,  // ringbuffer, data format 32Q19 !!!
    int32_t *p_obuf_left     ,  // outbuffer,  data format 32Q23
    //int32_t *p_obuf_right    ,  // outbuffer,  data format 32Q23
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

void asrc_codec_pfmid(
    int32_t *p_xinbuf_left   ,  //  data format 32Q19
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec_pfmid(
        p_xinbuf_left   ,
        p_obuf_left     ,
        asrc_outbuf_len ,
        p_nco           ,
        p_nco_buf       ,
        fs_ratio
    );
}

extern void Patch_asrc_codec_pfmid(
    int32_t *p_xinbuf_left   ,  //  data format 32Q19
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

void asrc_codec_pfhigh(
    int32_t *p_xinbuf_left   ,  //  data format 32Q19
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec_pfhigh(
        p_xinbuf_left   ,
        p_obuf_left     ,
        asrc_outbuf_len ,
        p_nco           ,
        p_nco_buf       ,
        fs_ratio       );
}

extern void Patch_asrc_codec_pfhigh(
    int32_t *p_xinbuf_left   ,  //  data format 32Q19
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

void asrc_codec96k_readbuf(
    int32_t *p_ringbuf_left   , //32Q23, 24bits audio
    int32_t *p_ringbuf_right  , //32Q23, 24bits audio
    int32_t *p_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    int32_t *p_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    int32_t  asrc_ringbuf_len ,
    int32_t  asrc_xinbuf_len  , //xinbuffer length
    int64_t *p_nco_buf_left   ,
    int64_t *p_nco_buf_right  ,
    int32_t *p_ringbuf_left_rp,
    int32_t *p_ringbuf_right_rp,
    int32_t  bitcut_en        , // 0 :high performance, 1: mid or low performance
    int32_t  stereo_mode      )
{
    pasrc_codec_ftabl->asrc_codec96k_readbuf(
        p_ringbuf_left   , //32Q23, 24bits audio
        p_ringbuf_right  , //32Q23, 24bits audio
        p_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
        p_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
        asrc_ringbuf_len ,
        asrc_xinbuf_len  , //xinbuffer length
        p_nco_buf_left   ,
        p_nco_buf_right  ,
        p_ringbuf_left_rp,
        p_ringbuf_right_rp,
        bitcut_en        , // 0 :high performance, 1: mid or low performance
        stereo_mode      );
}


//-----------------------------------------------------------------
// copy from ringbuf to xinbuf, and manage the ringbuf read pointer
// for 96k stereo DAC
//-------------------------------------------------------------------
extern void  Patch_asrc_codec96k_readbuf(
    int32_t *p_ringbuf_left   , //32Q23, 24bits audio
    int32_t *p_ringbuf_right  , //32Q23, 24bits audio
    int32_t *p_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    int32_t *p_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
    int32_t  asrc_ringbuf_len ,
    int32_t  asrc_xinbuf_len  , //xinbuffer length
    int64_t *p_nco_buf_left   ,
    int64_t *p_nco_buf_right  ,
    int32_t *p_ringbuf_left_rp,
    int32_t *p_ringbuf_right_rp,
    int32_t  bitcut_en        , // 0 :high performance, 1: mid or low performance
    int32_t  stereo_mode      );

void asrc_codec96k_pflow(
    int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec96k_pflow(
        p_xinbuf_left   ,
        p_obuf_left     ,
        asrc_outbuf_len ,
        p_nco           ,
        p_nco_buf       ,
        fs_ratio        );
}

extern void Patch_asrc_codec96k_pflow(
    int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

void asrc_codec96k_pfmid(
    int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec96k_pfmid(
        p_xinbuf_left   ,
        p_obuf_left     ,
        asrc_outbuf_len ,
        p_nco           ,
        p_nco_buf       ,
        fs_ratio        );
}

extern void Patch_asrc_codec96k_pfmid(
    int32_t *p_xinbuf_left   ,  //  data format 32Q20 !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

void asrc_codec96k_pfhigh(          // high performance
    int32_t *p_xinbuf_left   ,  //  data format 32Q23, !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
{
    pasrc_codec_ftabl->asrc_codec96k_pfhigh(
        p_xinbuf_left   ,
        p_obuf_left     ,
        asrc_outbuf_len ,
        p_nco           ,
        p_nco_buf       ,
        fs_ratio        );
}

extern void Patch_asrc_codec96k_pfhigh(          // high performance
    int32_t *p_xinbuf_left   ,  //  data format 32Q23, !!!
    int32_t *p_obuf_left     ,  //  data format 32Q23, 24bits Audio
    int32_t  asrc_outbuf_len ,
    int64_t *p_nco           ,
    int64_t *p_nco_buf       ,
    int32_t  fs_ratio        ) ;

const asrc_codec_ftable_t new_asrc_codec_patch_ftable =
{
    .asrc_adc_lpf_init     = Patch_asrc_adc_lpf_init,
    .asrc_adc_lpf          = Patch_asrc_adc_lpf,
    .asrc_codec48k_readbuf = new_Patch_asrc_codec48k_readbuf,
    .asrc_codec_pfzero     = Patch_asrc_codec_pfzero,
    //  .asrc_codec_pflow  = Patch_asrc_codec_pflow,
    .asrc_codec_pfmid      = Patch_asrc_codec_pfmid,
    .asrc_codec_pfhigh     = Patch_asrc_codec_pfhigh,
    .asrc_codec96k_readbuf = Patch_asrc_codec96k_readbuf,
    .asrc_codec96k_pflow   = Patch_asrc_codec96k_pflow,
    .asrc_codec96k_pfmid   = Patch_asrc_codec96k_pfmid,
    .asrc_codec96k_pfhigh  = Patch_asrc_codec96k_pfhigh,
};

void new_asrc_codec_patch_init(void)
{
    pasrc_codec_ftabl = (asrc_codec_ftable_t *)&new_asrc_codec_patch_ftable;
}
