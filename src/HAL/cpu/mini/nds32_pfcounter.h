#ifndef __NDS32_PFCOUNTER_H__
#define __NDS32_PFCOUNTER_H__

/***************************************************************************
 * nds32_pfcounter.h                                                      *
 * Tang Lei adds this file to MP3 project at 2017/1/8                                                                        *
 * Copyright (C) 2012-2015 Andes Technology Corporation                    *
 * All rights reserved.                                                    *
 ***************************************************************************/

#include <stdio.h>
#include "nds32_math_types.h"
#include "compiler.h"

#ifdef PF_COUNTER
#include "nds32_intrinsic.h"

#define startPFM \
    __nds32__mtsr(0, NDS32_SR_PFM_CTL); \
    __nds32__mtsr(0, NDS32_SR_PFMC0); \
    __nds32__mtsr(0, NDS32_SR_PFMC1); \
    __nds32__mtsr(0, NDS32_SR_PFMC2); \
    __nds32__mtsr(0x1000B, NDS32_SR_PFM_CTL)

//OVF2-0 are W1C, so set 0x10008 is ok for checking ov flag later.
#if 0
#define stopPFM \
    __nds32__mtsr(0x10008, NDS32_SR_PFM_CTL); \
    if (__nds32__mfsr(NDS32_SR_PFM_CTL) & (7UL << 6)) \
        printf("\n!!!Error! PFM has OVERFLOWED! PFM_CTL=0x%08X\n\n", (int)__nds32__mfsr(NDS32_SR_PFM_CTL)); \
    __nds32__dsb()
#else
 #define stopPFM \
     __nds32__mtsr(0x10008, NDS32_SR_PFM_CTL); \
     __nds32__dsb()
#endif

#if 0
__attribute__ ((noinline)) static void readResult()
{
    unsigned int msc_cfg = 0;
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
    if (!(msc_cfg & 0x4))
    {
        printf("This CPU config doesn't have pfm to use.\n");
        return;
    }
#ifdef PF_ANALYZE
    printf("Reading Performance Monitor Result\n");
#endif
    unsigned int counter = __nds32__mfsr(NDS32_SR_PFMC0);
    unsigned int counter1 = __nds32__mfsr(NDS32_SR_PFMC1);
    printf("The inst count is %d\n", counter1);
    printf("The cycle count is %d\n", counter);
    printf("The average cycle count is %d\n", (int)(counter / total_samples));
    printf("The function unit size is %d\n", total_samples);
#ifdef PF_ANALYZE
    unsigned int ONEMHZ = 1000000;
    float32_t  mhzbycounter = (float32_t) ONEMHZ / counter * 100.0f;
    printf("The MHZ per cycle count is %5.2f%%\n", mhzbycounter);
#endif
}
#endif

typedef struct
{
    double  inst;
    double  cycle;
} acc_result;

__attribute__ ((noinline)) void ACC_Result(acc_result *result)
{
    unsigned int msc_cfg = 0;
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
    if (!(msc_cfg & 0x4))
    {
        printf("This CPU config doesn't have pfm to use.\n");
        return;
    }
    unsigned int counter = __nds32__mfsr(NDS32_SR_PFMC0);
    unsigned int counter1 = __nds32__mfsr(NDS32_SR_PFMC1);

    result->inst += (double)counter1;
    result->cycle += (double)counter;
}


__attribute__ ((noinline)) void Read_ACC_Result(acc_result *result)
{
#ifdef PF_ANALYZE
    printf("Reading Performance Monitor Result\n");
#endif
    printf("The inst count is %.0lf\n", result->inst);
    printf("The cycle count is %.0lf\n", result->cycle);
#ifdef PF_ANALYZE
    unsigned int ONEMHZ = 1000000;
    float32_t  mhzbycounter = (float32_t) ONEMHZ / (result->cycle) * 100.0f;
    printf("The MHZ per cycle count is %5.2f%%\n", mhzbycounter);
#endif
}

__attribute__ ((noinline)) void Read_Result_Div_By_Size(int Size)
{
    unsigned int msc_cfg = 0;
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
    if (!(msc_cfg & 0x4))
    {
        printf("This CPU config doesn't have pfm to use.\n");
        return;
    }
#ifdef PF_ANALYZE
    printf("Reading Performance Monitor Result\n");
#endif
    unsigned int cycle_counter = __nds32__mfsr(NDS32_SR_PFMC0);
    unsigned int inst_counter = __nds32__mfsr(NDS32_SR_PFMC1);
    printf("The inst count is %d\n", inst_counter / Size);
    printf("The cycle count is %d\n", cycle_counter / Size);
#ifdef PF_ANALYZE
    unsigned int ONEMHZ = 1000000;
    unsigned int ave_cycle = cycle_counter / Size;
    float32_t  mhzbycounter = (float32_t) ONEMHZ / ave_cycle * 100.0f;
    printf("The MHZ per cycle count is %5.2f%%\n", mhzbycounter);
#endif
}

#endif  // PF_COUNTER

static inline uint32_t test_Fread(void *buf, int numByte, uint32_t bSize, FILE *fp)
{


    if (fread(buf, numByte, bSize, fp) != bSize)
    {
        //printf("Error! Can not read file!\n");
        return 0;
    }

#if (defined(NDS32_EB) || defined(__NDS32_EB__))
    uint32_t i;
    char temp;
    char *tt;
    if (numByte == 4)
    {
        q31_t *buf32 = buf;
        for (i = 0; i < bSize; i++)
        {
            tt = (char *)&buf32[i];
            temp = tt[0]; tt[0] = tt[3]; tt[3] = temp;
            temp = tt[1]; tt[1] = tt[2]; tt[2] = temp;
        }
    }
    else if (numByte == 8)
    {
        q63_t *buf64 = buf;
        for (i = 0; i < bSize; i++)
        {
            tt = (char *)&buf64[i];
            temp = tt[0]; tt[0] = tt[7]; tt[7] = temp;
            temp = tt[1]; tt[1] = tt[6]; tt[6] = temp;
            temp = tt[2]; tt[2] = tt[5]; tt[5] = temp;
            temp = tt[3]; tt[3] = tt[4]; tt[4] = temp;
        }
    }
    else if (numByte == 2)
    {
        q15_t *buf16 = buf;
        for (i = 0; i < bSize; i++)
        {
            tt = (char *)&buf16[i];
            temp = tt[0]; tt[0] = tt[1]; tt[1] = temp;
        }
    }
#endif
    return bSize;
}

#endif // __NDS32_PFCOUNTER_H__
