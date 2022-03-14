/*
 * eq_cal_coeff_top.h
 *
 *  Created on: May 11, 2017
 *      Author: lizhen
 */

#ifndef __EQ_CAL_COEFF_H_NEW__
#define __EQ_CAL_COEFF_H_NEW__

#include <stdint.h>
#include "effect_config.h"
#define EQ_COEFF_SHIFT_SHELF  (7)
#define EQ_COEFF_SHIFT_OTHER  (3)

#define EQ_COEFF_F0_RES       (10)
#define EQ_COEFF_QV_RES       (1000)
#define EQ_COEFF_DBG_RES      (10)

typedef enum EqType_enum {
	PEAK_NOTCH       = 0,
	LPF              = 1,
	HPF              = 2,
	LSF              = 3,
	HSF              = 4,
}EqTypeEnum_t;
typedef struct{
	int32_t  f0;   //0.1Hz
	int32_t  Qv;   //0.0001
	int32_t  dBG;  //0.1dB
	int32_t  Fs;   //Hz
	uint8_t  Type; 
	uint8_t  en;
	uint16_t RFU;
}EqCoeffPara_t;
#if(EFFECT_EQ_EN)
void EqCalCoeff      (EqCoeffPara_t *pInst, int32_t *pCoeff);
void EqShelfCoeff    (EqCoeffPara_t *pInst, int32_t *pCoeff);
void EqLpfHpfCoeff   (EqCoeffPara_t *pInst, int32_t *pCoeff);
void EqPeakNotchCoeff(EqCoeffPara_t *pInst, int32_t *pCoeff);

//---------------------------------------------------
//Patch
//---------------------------------------------------
#define EQ_CAL_COEFF_PATCH                                \
void (*eq_peak_notch_coeff)(                              \
	int32_t f0,                                           \
	int32_t Qv,                                           \
	int32_t dbgain,                                       \
	int32_t Fs,                                           \
	int32_t *pCoeff                                       \
);                                                        \
void (*eq_lpf_hpf_coeff)(                                 \
	int32_t f0,                                           \
	int32_t Qv,                                           \
	int32_t Fs,                                           \
	int8_t type_lpf,                                      \
	int32_t *pCoeff                                       \
);                                                        \
void (*eq_shelv_coeff)(                                   \
	int32_t f0,                                           \
	int32_t Qv,                                           \
	int16_t dbgain,                                       \
	int32_t Fs,                                           \
	int8_t type_lowfreq,                                  \
	int32_t *pCoeff                                       \
);                                                        \
void (*eq_cal_coeff)(                                     \
	int32_t f0,                                           \
	int32_t Qv,                                           \
	int16_t dbgain,                                       \
	int32_t Fs,                                           \
	int8_t eq_type,                                       \
	int32_t *pCoeff                                       \
);


#define EQ_CAL_COEFF_PATCH_INIT                           \
.eq_peak_notch_coeff = eq_peak_notch_coeff,               \
.eq_lpf_hpf_coeff    = eq_lpf_hpf_coeff,                  \
.eq_shelv_coeff      = eq_shelv_coeff,                    \
.eq_cal_coeff        = eq_cal_coeff,

#define EQ_CAL_COEFF_PATCH_NUM 4
#endif
#endif /* EQ_CAL_COEFF_TOP_H_ */
