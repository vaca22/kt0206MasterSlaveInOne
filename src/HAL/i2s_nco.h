/*
 * i2s_nco.h
 *
 *  Created on: Jun 27, 2018
 *      Author: wangshengli
 */

#ifndef I2S_NCO_H_
#define I2S_NCO_H_
#include "comm.h"

typedef enum
{
	TIM_WIN_400MS=0,
	TIM_WIN_600MS=1,
	TIM_WIN_800MS=2,
	TIM_WIN_1000MS=3,
}i2s_nco_adj_tim_win_t;

typedef enum
{
	NCO_DISABLE=0,
	NCO_ENABLE=1,
}i2s_nco_en_t;

typedef enum
{
	FCW_SMP_CLR=0,
	FCW_SMP_SET=1,
}i2s_nco_fcw_smp_t;

extern int32_t i2s_nco_delta_fcw;
extern uint32_t sclk_lrclk_rate;

//void I2S_NCO_Init(uint16_t i2sfcwdelta,uint32_t i2s_smp_rate);
extern void I2S_NCO_Init(uint32_t i2s_smp_rate);
extern void I2S_NCO_fcw_delta_Set(int16_t i2sfcwdelta);
extern void I2sNco_patch_init(void);
extern void new_I2sNco_patch_init(void);


#endif /* I2S_NCO_H_ */
