#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <stdint.h>
#include "co_math.h"
#include "reg_apb.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef void(*AudioHandle)(q31_t *pAddr1, q31_t *pAddr2, q31_t *pAddr3, q31_t *pAddr4, uint16_t usSampleNum, uint16_t usSignal);

typedef enum
{
	ADC0,
	ADC1,
	TDM_IN_0,
	TDM_IN_1,
	I2S_IN_L,
	I2S_IN_R,
	DAC0,
	DAC1,
	I2S_OUT_L,
	I2S_OUT_R,
	TDM_OUT_0,
	TDM_OUT_1,
	AUDIO_PATH_NUM,
}audio_path_t;

enum
{
	MASTER0,
	SLAVE0,
	MASTER1,
	SLAVE1,
};

enum
{
	AUDIO_IN,
	AUDIO_OUT,
	I2S_AUDIO_IN,
	I2S_AUDIO_OUT,
};



typedef struct
{
	AudioHandle audio_in_handler;
	AudioHandle audio_out_handler;
	uint32_t Fifo_Base[AUDIO_PATH_NUM];
	uint16_t Fifo_Len[AUDIO_PATH_NUM]; //1 byte unite
	uint16_t Fifo_Len_Half[AUDIO_PATH_NUM]; //2 byte unite
	uint16_t Fifo_Len_16[AUDIO_PATH_NUM]; //16 byte unite
	uint16_t Fifo_Len_16_Half[AUDIO_PATH_NUM]; //32 byte unite
	uint16_t Fifo_In_Sample_Num; //sample point number
	uint16_t Fifo_Out_Sample_Num; //sample point number
	uint16_t IoBufInFlag;
	uint16_t IoBufOutFlag;
}io_buf_sys_papa_t;

typedef struct
{
	uint8_t Disable;
	un_FIFO_CONTROL_x Fifo_Control;
}io_buf_papa_t;

typedef struct
{
	uint8_t InStartFlag;
	uint8_t	OutStartFlag;
}in_out_start_flag_t;

typedef struct
{
	uint8_t sclk_lrclk_rate;
	uint8_t data_size;
	uint8_t data_mode;
}i2s_config_set_t;

#define FIFO_LEN_CALC(sample_num, data_size) ((((sample_num) * 4) << (data_size)) >> 4)

#define FIFO_CONTROL_X_REG_SET(fifo_reg, path_x, sample_num, io_buf_addr) \
	fifo_reg = (g_stIoBufCfg[path_x] .Fifo_Control.overall) | \
	(FIFO_LEN_CALC((sample_num), (g_stIoBufCfg[path_x] .Fifo_Control.bs.DATA_SIZE)) << 16) | \
    (((io_buf_addr) >> 4) & 0xFFFF)

#define FIFO_CONTROL_X_REG_SET_I2S(fifo_reg, path_x, sample_num, io_buf_addr) \
	fifo_reg = (g_stIoBufCfg_i2s[path_x] .Fifo_Control.overall) | \
	(FIFO_LEN_CALC((sample_num), (g_stIoBufCfg[path_x] .Fifo_Control.bs.DATA_SIZE)) << 16) | \
    (((io_buf_addr) >> 4) & 0xFFFF)

#define FIFO_CONTROL_X_REG_GET_I2S(fifo_reg, path_x) \
    { un_##fifo_reg _TmpReg; _TmpReg.overall = fifo_reg; \
	g_stIoBufSys_I2S.Fifo_Len[path_x] = _TmpReg.bs.FIFO_LEN << 4; \
	g_stIoBufSys_I2S.Fifo_Len_Half[path_x] = _TmpReg.bs.FIFO_LEN << 3; \
	g_stIoBufSys_I2S.Fifo_Len_16[path_x] = _TmpReg.bs.FIFO_LEN; \
	g_stIoBufSys_I2S.Fifo_Len_16_Half[path_x] = _TmpReg.bs.FIFO_LEN >> 1; \
	g_stIoBufSys_I2S.Fifo_Base[path_x] = _TmpReg.bs.START_ADDR << 4; \
	uFifoAddr += _TmpReg.bs.FIFO_LEN << 4; \
	}

#define FIFO_CONTROL_X_REG_GET(fifo_reg, path_x) \
    { un_##fifo_reg _TmpReg; _TmpReg.overall = fifo_reg; \
	g_stIoBufSys.Fifo_Len[path_x] = _TmpReg.bs.FIFO_LEN << 4; \
	g_stIoBufSys.Fifo_Len_Half[path_x] = _TmpReg.bs.FIFO_LEN << 3; \
	g_stIoBufSys.Fifo_Len_16[path_x] = _TmpReg.bs.FIFO_LEN; \
	g_stIoBufSys.Fifo_Len_16_Half[path_x] = _TmpReg.bs.FIFO_LEN >> 1; \
	g_stIoBufSys.Fifo_Base[path_x] = _TmpReg.bs.START_ADDR << 4; \
	uFifoAddr += _TmpReg.bs.FIFO_LEN << 4; \
	}

#define FIFO_AF_THRE_CALC(sample_num, data_size) (((sample_num) * 2) << (data_size))
#define FIFO_AE_THRE_CALC(sample_num, data_size) ((((sample_num) - 1) * 2) << (data_size))
#define FIFO_THRE_X_REG_SET(fifo_reg, path_x, sample_num) \
	fifo_reg = (FIFO_AF_THRE_CALC((sample_num), (g_stIoBufCfg[path_x] .Fifo_Control.bs.DATA_SIZE)) << 16) | \
	(FIFO_AE_THRE_CALC((sample_num), (g_stIoBufCfg[path_x] .Fifo_Control.bs.DATA_SIZE)))

#define FIFO_WRITE_DATA_AND_WR(fifo_reg, path_x) \
	{ \
        { \
        	un_##fifo_reg _TmpReg; _TmpReg.overall = fifo_reg; \
			_TmpReg.bs.WR_PTR = g_stIoBufSys.Fifo_Len_Half[path_x]; \
			fifo_reg = _TmpReg.overall; \
		} \
	}

extern io_buf_sys_papa_t g_stIoBufSys;
extern io_buf_sys_papa_t g_stIoBufSys_I2S;
extern const io_buf_papa_t g_stIoBufCfg[];
extern const io_buf_papa_t g_stIoBufCfg_i2s[];
extern in_out_start_flag_t g_stStartFlag;
extern i2s_config_set_t g_stI2sCfgSet;
extern i2s_config_set_t g_stI2sCfgSet_All[];

extern void AUDIO_CallBack_Set(uint8_t Index, AudioHandle audio_handler);
extern void AUDIO_Sampling_Set(uint8_t AdcSampling, uint8_t DacSampling);
extern void I2s_Para_Tran(i2s_config_set_t *stI2sCfgSet);
extern void I2s_Cfg_Set(uint8_t ucMode);
void I2S_AUDIO_CallBack_Set(uint8_t Index, AudioHandle audio_handler);
extern void audio_patch_init(void);

#ifdef  __cplusplus
}
#endif

#endif

