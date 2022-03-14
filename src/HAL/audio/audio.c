#include "audio.h"

typedef struct ftable_stru
{
	void (*AUDIO_CallBack_Set)(uint8_t Index, AudioHandle audio_handler);
	void (*AUDIO_Sampling_Set)(uint8_t AdcSampling, uint8_t DacSampling);
	void (*I2s_Para_Tran)(i2s_config_set_t *stI2sCfgSet);
	void (*I2s_Cfg_Set)(uint8_t ucMode);
}ftable_t;

extern ftable_t *audio_ftable;

extern io_buf_sys_papa_t g_stIoBufSys;
io_buf_sys_papa_t g_stIoBufSys_I2S;

const io_buf_papa_t g_stIoBufCfg_i2s[] =
{
	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //ADC0
	{0}, //ADC1
	{0}, //TDM0_IN
	{0}, //TDM1_IN
	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_IN_L
	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_IN_R

	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //DAC0
	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //DAC1

	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_OUT_L
	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 1, .FIFO_ENABLE = 0}}}, //I2S_OUT_R
	{0}, //TDM0_OUT
	{0}, //TDM1_OUT
};
extern const io_buf_papa_t g_stIoBufCfg[];// =
//{
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //ADC0
//	{0}, //ADC1
//	{0}, //TDM0_IN
//	{0}, //TDM1_IN
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_IN_L
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 1, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_IN_R
//
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 1, .FIFO_ENABLE = 0}}}, //DAC0
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 1, .FIFO_ENABLE = 0}}}, //DAC1
//
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 0, .FIFO_ENABLE = 0}}}, //I2S_OUT_L
//	{ .Disable = 1, {{ .START_ADDR = 0, .FIFO_LEN = 0, .DATA_SIZE = 1, .DATA_ADJUST = 0, .FIFO_INT_ENABLE = 1, .FIFO_ENABLE = 0}}}, //I2S_OUT_R
//	{0}, //TDM0_OUT
//	{0}, //TDM1_OUT
//};

extern in_out_start_flag_t g_stStartFlag;

void I2S_AUDIO_CallBack_Set(uint8_t Index, AudioHandle audio_handler)
{
    if(I2S_AUDIO_IN == Index)
    {
    	g_stIoBufSys_I2S.audio_in_handler = audio_handler;
    }
    if(I2S_AUDIO_OUT == Index)
    {
    	g_stIoBufSys_I2S.audio_out_handler = audio_handler;
    }
}




