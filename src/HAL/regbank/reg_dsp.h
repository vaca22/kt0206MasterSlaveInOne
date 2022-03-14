#ifndef REG_DSP_H_
#define REG_DSP_H_

#include "comm.h"
//TODO - add dsp register definition
//typedef unsigned int               uint32_t;


/*-----------------------DRC-------------------*/
typedef struct
{
    uint32_t drc_en : 1;
    uint32_t drc_2band : 1;
    uint32_t drc_softlimit : 1;
    uint32_t RFU0 : 5;
    uint32_t drc_vlimitF : 8;
    uint32_t drc_attackF : 4;
    uint32_t drc_releaseF : 4;
    uint32_t drc_hpf_cutoff : 8;
}st_DSP_DRC_CTRL0;

typedef struct
{
    uint32_t drc_vlimitL : 8;
    uint32_t drc_attackL : 4;
    uint32_t drc_releaseL : 4;
    uint32_t drc_vlimitH : 8;
    uint32_t drc_attackH : 4;
    uint32_t drc_releaseH : 4;
}st_DSP_DRC_CTRL1;


#endif /* REG_DSP_H_ */
