#ifndef _USWI_ASRC_H_
#define _USWI_ASRC_H_

#include "stdint.h"
#include "asrc_adc_fs_ppm_pack.h"

extern uint8_t swiI2SIn2DACFlag;
extern int32_t g_I2SIn2DacBuf[96];
extern AsrcIn_t g_st_AsrcI2SIN2Dac;

void swiPackAsrc(uint8_t UsbOutStatus);

void getAsrcComStartAddr(uint32_t addr);
uint32_t setAsrcComEndAddr(uint32_t addr);


#endif
