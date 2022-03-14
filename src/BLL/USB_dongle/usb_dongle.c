/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#include "hal_includes.h"
#include "fml_includes.h"
#include "usb_audio_sdk.h"
#include "Co_rbuf.h"
#include "Asrc_dac_fs_ppm.h"
#include "Asrc_adc_fs_ppm.h"
#include "i2s_nco_writebuf.h"
#include "hal_config.h"
#include "audioeffect_top.h"
#include "bll_config.h"
extern uint32_t u32ADCFifoAddr;
extern uint32_t u32DACFifoAddr;
extern uint8_t dsp_i2s_in_en;
extern int32_t usb_data[96];
extern void estimation_adc_ppm_init();

st_i2s_nco_param i2s_nco_param;
st_i2s_nco_param1 i2s_nco_param1;
typedef struct usb_dongle_ftable_stru
{
	void (*ConfigDongle)(void);
    void (*UnConfigDongle)(void);
} usb_dongle_ftable_t;

usb_dongle_ftable_t *pusb_dongle_ftabl = NULL;
void USB_ConfigDongle()
{
	pusb_dongle_ftabl->ConfigDongle();
}
void new_patch_USB_ConfigDongle()
{
	uint32_t uFifoAddr = AUDIO_FIFO_ADDR;
	uint8_t* pUsbBuffer = (uint8_t*)RAM_USB_BUF_BASE_ADDR;

	Audio_bufinit();
	dsp_parameter_init();

	Usb_Init(pUsbBuffer,0);

	AUDIO_CallBack_Set(AUDIO_IN ,Audio_In_Dongle_Write);

	switch(g_pstConfig->FuncCfg.DongleAudioInSel){
		case DONGLE_ADC_IN:{
			apb_audio_ctrl1_audio_pga_jack_pin_order_sts_setf(1);		//according to pcb design: default 0:mic=vinn, 1: mic=vinp
			AUDIO_Sampling_Set(0,0);
			u32ADCFifoAddr = uFifoAddr;
			uFifoAddr = AUDIO_IN_Init(AUDIO_FIFO_ADDR, AUDIO_SAMPLE_BLOCK_SIZE,  CO_BIT(ADC0), 0);
			uFifoAddr = Asrc_Adc_Fs_Ppm_Init(uFifoAddr);
			USB_SetCallback(USB_EVENT_AUDIO_IN, USB_In_Dongle_Read);
			asrc_adc_Clean_RingBuf();
			estimation_adc_ppm_init();
			asrc_adc_fs_change_init();
			AUDIO_IN_Stop(CO_BIT(ADC0), 0);
			break;
		}
		case DONGLE_I2S_MASTER_IN:{
			i2s_nco_param.sclk_lrclk_rate		  = 64;
			i2s_nco_param.i2s_nco_ringbuf_len	  = 900;//384;
			i2s_nco_param.i2s_nco_high_thrsh	  = 650;//i2s_nco_param.i2s_nco_ringbuf_len*3/5;//
			i2s_nco_param.i2s_nco_low_thrsh		  = 350;//i2s_nco_param.i2s_nco_ringbuf_len*2/5;
			i2s_nco_param.fcw_delta_step_ppm	  = 35;	//
			i2s_nco_param.i2s_nco_mdfy_period	  = 100;	//
			i2s_nco_param1.i2s_nco_average_cnt    = 5;
			i2s_nco_param1.i2s_nco_sable_period   = 500;
			i2s_nco_param1.i2s_nco_error_num      = 2;
			i2s_nco_param1.i2s_nco_high_delta_fcw = 10000;
			i2s_nco_param1.i2s_nco_low_delta_fcw  = -10000;
			i2s_nco_param_init(i2s_nco_param);

			I2s_Para_Tran(&g_stI2sCfgSet_All[0]);
			uFifoAddr = AUDIO_IN_Init(AUDIO_FIFO_ADDR, AUDIO_SAMPLE_BLOCK_SIZE,  CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
			uFifoAddr = I2s_Nco_Buf_Init(uFifoAddr);
			AUDIO_IN_Stop(CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
			i2s_nco_rbuf_reset();
			//I2S_NCO_Init(48000);	//default data rate
			USB_SetCallback(USB_EVENT_AUDIO_IN, USB_In_Dongle_Read);
			USB_SetCallback(USB_EVENT_AUDIO_STATUS_CHANGE,USB_InterfaceSetting_I2S);
			uFifoAddr = USB_Buf_Init(uFifoAddr);
			dsp_i2s_in_en = 1;
			break;
		}
		case DONGLE_I2S_SLAVE_IN:{
			memset(usb_data, 0, sizeof(usb_data));
			I2s_Para_Tran(&g_stI2sCfgSet_All[0]);
			uFifoAddr = AUDIO_IN_Init(AUDIO_FIFO_ADDR, AUDIO_SAMPLE_BLOCK_SIZE,  CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), SLAVE0);
			dsp_i2s_in_en = 1;
			uFifoAddr = Asrc_Adc_Fs_Ppm_Init(uFifoAddr);
			USB_SetCallback(USB_EVENT_AUDIO_IN, USB_In_Dongle_Read);
			asrc_adc_Clean_RingBuf();
			estimation_adc_ppm_init();
			asrc_adc_fs_change_init();
			AUDIO_IN_Stop(CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), SLAVE0);
			break;
		}
	}

    pDSP = &g_pstConfig->DongleAudioReg;
	if(isFlashValid)
	{
		;
	}
	else
	{
		dsp_reg_init();
	}
	dsp_reg_update_all();

    uFifoAddr = dsp_buff_init_dongle(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE);
    dsp_effect_private_buff = (q31_t *)uFifoAddr;
    uFifoAddr = dsp_buff_set_dongle (uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE);
    Usb_Open(0);
}
void USB_UnConfigDongle()
{
	pusb_dongle_ftabl->UnConfigDongle();
}
void new_patch_USB_UnConfigDongle()
{
	switch(g_pstConfig->FuncCfg.DongleAudioInSel){
		case DONGLE_ADC_IN:{
			AUDIO_IN_Uninit(CO_BIT(ADC0), 0);
			break;
		}
		case DONGLE_I2S_MASTER_IN:{
			AUDIO_IN_Uninit(CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), MASTER0);
			break;
		}
		case DONGLE_I2S_SLAVE_IN:{
			AUDIO_IN_Uninit(CO_BIT(I2S_IN_L)| CO_BIT(I2S_IN_R), SLAVE0);
			break;
		}
	}
    Usb_Close(0);
    Usb_DeInit();
}
const usb_dongle_ftable_t new_usb_dongle_patch_ftable =
{
    .ConfigDongle          = new_patch_USB_ConfigDongle,
    .UnConfigDongle        = new_patch_USB_UnConfigDongle,
};

void new_usb_dongle_patch_init(void)
{
	pusb_dongle_ftabl = (usb_dongle_ftable_t *)&new_usb_dongle_patch_ftable;
}
