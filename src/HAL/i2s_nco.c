/*
 * i2s_nco.c
 *
 *  Created on: Jun 27, 2018
 *      Author: wangshengli
 */
#include "i2s_nco.h"
#include "i2s_nco_writebuf.h"
#include "audio.h"
#include "reg_apb.h"
#include "audio_in.h"
#include "hal_config.h"
#include "chip_config.h"


extern void i2s_nco_rbuf_reset(void);

typedef struct
{
	void (*I2S_NCO_Init)(uint32_t i2s_smp_rate);
	void (*I2S_NCO_fcw_delta_Set)(int16_t i2sfcwdelta);
}ftable_t;

ftable_t *pI2sNcoFTable;

int32_t i2s_nco_delta_fcw=0;
uint32_t sclk_lrclk_rate=64;
uint32_t adjust_state;
extern uint32_t USB_I2SNCO_EOF_FLAG;
extern uint8_t USB_IN_START;
extern st_i2s_nco_param i2s_nco_param;
extern uint8_t I2SNCO_INIT_FLAG;
extern uint32_t usb_dongle_int_cnt;

/*
    i2sfcwdelta   	: i2s fcw delta
    ncoadjtimwin    : nco adj tim win
	i2s_fcw			: select ADC or I2S_In
	i2s_smp_rate	: Audio sample rate (Hz)
*/
uint32_t smp_rate_record,smp_rate_record2;

void I2S_NCO_Init(uint32_t i2s_smp_rate)
{
	pI2sNcoFTable->I2S_NCO_Init(i2s_smp_rate);
}

void new_Patch_I2S_NCO_Init(uint32_t i2s_smp_rate)	//uint8_t ncoadjtimwin, uint32_t i2s_fcw)
{
	uint32_t i2s_fcw;

	AUDIO_IN_Stop( CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
	AUDIO_IN_Uninit(CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
	AUDIO_IN_Init(AUDIO_FIFO_ADDR, AUDIO_SAMPLE_BLOCK_SIZE,  CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
	AUDIO_IN_Start( CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);

//	smp_rate_record = i2s_smp_rate;
//	if(smp_rate_record2 == smp_rate_record)
//	{
//		return;
//	}
//	else
//	{
//		smp_rate_record2 = smp_rate_record;

//		i2s_fcw = (uint64_t)i2s_smp_rate*sclk_lrclk_rate*16384/46875;//i2s_smp_rate*sclk_lrclk_rate/192000000*2^26;
		i2s_fcw = (uint64_t)i2s_smp_rate*sclk_lrclk_rate*16384/48000;//i2s_smp_rate*sclk_lrclk_rate/192000000*2^26;
		apb_i2s_ctrl2_nco_en_setf(NCO_DISABLE);
	//	apb_i2s_ctrl1_nco_adj_tim_win_setf(TIM_WIN_600MS);
		apb_i2s_ctrl2_i_2s_fcw_setf(i2s_fcw);
		apb_i2s_ctrl2_nco_en_setf(NCO_ENABLE);

		apb_i2s_ctrl2_fcw_smp_setf(FCW_SMP_CLR);
		apb_i2s_ctrl1_i_2s_fcw_delta_setf(0);
		apb_i2s_ctrl2_fcw_smp_setf(FCW_SMP_SET);	//sync


//		adjust_state = 0;
//		USB_I2SNCO_EOF_FLAG = 0;
//		USB_IN_START = 0;
//	}

	adjust_state = 0;
	USB_I2SNCO_EOF_FLAG = 0;
	USB_IN_START = 0;
	I2SNCO_INIT_FLAG = 1;
//	usb_dongle_int_cnt = 0;
	i2s_nco_rbuf_reset();
}

void I2S_NCO_fcw_delta_Set(int16_t i2sfcwdelta)
{
	pI2sNcoFTable->I2S_NCO_fcw_delta_Set(i2sfcwdelta);
}

extern void Patch_I2S_NCO_fcw_delta_Set(int16_t i2sfcwdelta);

const ftable_t new_I2sNcoFuncTableDef =
{
    .I2S_NCO_Init = new_Patch_I2S_NCO_Init,
    .I2S_NCO_fcw_delta_Set = Patch_I2S_NCO_fcw_delta_Set,
};

void new_I2sNco_patch_init(void)
{
    pI2sNcoFTable = (ftable_t *)&new_I2sNcoFuncTableDef;
}
