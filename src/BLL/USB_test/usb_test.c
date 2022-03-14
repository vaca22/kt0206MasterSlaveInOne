/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#include "usb_audio_sdk.h"
#include "Co_rbuf.h"
#include "Asrc_dac_fs_ppm.h"
#include "Asrc_adc_fs_ppm.h"
#include "swi.h"
#include "hal_config.h"

typedef struct usb_Test_ftable_stru
{
	void (*ConfigTest)(void);
} usb_Test_ftable_t;

usb_Test_ftable_t *pusb_Test_ftabl = NULL;
void USB_ConfigTest()
{
	pusb_Test_ftabl->ConfigTest();
}
void new_patch_USB_ConfigTest()
{
	/* set clk for otp write */
	//clk div sel otp 12M
//	Set_Clk_Div_Sel(OTP_Default_Value.osc_div_sel_1, OTP_Default_Value.ahb_div_sel_1,
//			OTP_Default_Value.apb_div_sel_1, OTP_Default_Value.qspi_div_sel_1);
//
//	//open OTP clock
//	apb_clk_gen_clken_clk_otp_en_setf(1);
//	timer_delay_length(10, TIM_MS);
////	/*for high OSC Cali test*/
//	apb_pad_gpio_func_cfg0_gpio1_func_sel_setf(1);
//	apb_pad_gpio_func_cfg0_gpio2_func_sel_setf(1);
//	apb_pad_gpio_func_cfg1_gpio9_func_sel_setf(1);
//	apb_pad_gpio_func_cfg1_gpio10_func_sel_setf(1);
////	apb_pad_i2s_func_cfg0_i2s_mclk_func_sel_setf(3);		//configure the MCLK to digital input


//
//	while(1)
//	{
//		DEBUG_GPIO5_SET();
//		timer_delay_length(1, TIM_MS);
//	}
//


	/*for I2S in DAC out test*/
	uint32_t uFifoAddr = AUDIO_FIFO_ADDR;
	uint8_t* pUsbBuffer = (uint8_t*)RAM_USB_BUF_BASE_ADDR;

	SarADC_PowerOn();
	Audio_bufinit();
	AUDIO_Sampling_Set(0,0);
	dsp_buff_init(uFifoAddr,0,16);
	dsp_parameter_init();
	Usb_Init(pUsbBuffer,0);
    AUDIO_CallBack_Set(AUDIO_IN , Audio_In_Test_Write);
    AUDIO_CallBack_Set(AUDIO_OUT  ,Audio_Out_Test_Read);
    uFifoAddr =  USB_Buf_Init(uFifoAddr);
    I2s_Para_Tran(&g_stI2sCfgSet_All[0]);
    uFifoAddr = AUDIO_IN_Init(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R), MASTER0);
	uFifoAddr = AUDIO_OUT_Init(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, CO_BIT(DAC0)| CO_BIT(DAC1), 0);

    AUDIO_IN_Start(CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R),MASTER0);
    AUDIO_OUT_Start(CO_BIT(DAC0)|CO_BIT(DAC1), 0);
    AUDIO_OUT_Test_Config();

//	/*for ADC in I2S out test*/
//	uint32_t uFifoAddr = AUDIO_FIFO_ADDR;
//	uint8_t* pUsbBuffer = (uint8_t*)RAM_USB_BUF_BASE_ADDR;
//	SarADC_PowerOn();
//	Audio_bufinit();
//	AUDIO_Sampling_Set(0,0);
//	dsp_buff_init(uFifoAddr,0,16);
//	dsp_parameter_init();
//	Usb_Init(pUsbBuffer,0);
//    AUDIO_CallBack_Set(AUDIO_IN , Audio_In_Test_Write);
//    AUDIO_CallBack_Set(AUDIO_OUT, Audio_Out_Test_Read);
//    uFifoAddr =  USB_Buf_Init(uFifoAddr);
//    I2s_Para_Tran(&g_stI2sCfgSet_All[4]);
//    uFifoAddr = AUDIO_OUT_Init(uFifoAddr, 16, CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R), MASTER0);
//    uFifoAddr = AUDIO_IN_Init(uFifoAddr, 16, CO_BIT(ADC0), 0);
//    AUDIO_OUT_Start(CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R), MASTER0);
//    AUDIO_IN_Start(CO_BIT(ADC0), 0);

}

const usb_Test_ftable_t new_usb_Test_patch_ftable =
{
    .ConfigTest          = new_patch_USB_ConfigTest,
};

void new_usb_Test_patch_init(void)
{
	pusb_Test_ftabl = (usb_Test_ftable_t *)&new_usb_Test_patch_ftable;
}
