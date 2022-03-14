/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        :
********************************************************************************/
#include "hal_config.h"
#include "bll_config.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "usb_audio_sdk.h"
#include "usb_headset.h"
#include "Co_rbuf.h"
#include "Asrc_dac_fs_ppm.h"
#include "Asrc_adc_fs_ppm.h"
#include "earphone_key_detect.h"
#include "earphone_key_wakeup_detect.h"
#include "saradc.h"

extern uint32_t u32ADCFifoAddr;
extern uint32_t u32DACFifoAddr;
extern int32_t usb_data[96];
extern void estimation_adc_ppm_init();
typedef struct usb_HeadSet_ftable_stru
{
	void (*ConfigHeadSet)(void);
	void (*UnConfigHeadSet)(void);
	void (*HeadSetGPIO)(uint8_t);
} usb_HeadSet_ftable_t;
usb_HeadSet_ftable_t *pusb_HeadSet_ftabl = NULL;
extern int32_t  ramp_signal;

extern int32_t DAC_DC_CALI_L;
extern int32_t DAC_DC_CALI_R;

void USB_ConfigHeadSet()
{
	pusb_HeadSet_ftabl->ConfigHeadSet();
}
void new_patch_USB_ConfigHeadSet()
{
	uint32_t uFifoAddr = AUDIO_FIFO_ADDR;
	uint8_t* pUsbBuffer = (uint8_t*)RAM_USB_BUF_BASE_ADDR;
	uint32_t ii;
	uint32_t tempaddr;
	uint32_t audac_fifo_leg;

	AUDIO_Sampling_Set(0,0);//设置adc和dacd的采样率为48KHz 0:48K  1:96K

	g_ucButtType = 0;
	memset(usb_data, 0, sizeof(usb_data));

	Usb_Init(pUsbBuffer,0);
	AUDIO_CallBack_Set(AUDIO_IN ,Audio_In_Speaker);
	AUDIO_CallBack_Set(AUDIO_OUT ,Audio_Out_Speaker);
	u32DACFifoAddr = uFifoAddr;

	tempaddr=uFifoAddr;
	uFifoAddr = AUDIO_OUT_Init(uFifoAddr, 16, CO_BIT(DAC0)| CO_BIT(DAC1), 0);
	audac_fifo_leg = uFifoAddr - tempaddr;
    for(ii=tempaddr;ii<(tempaddr+audac_fifo_leg/2);ii+=4)    //calibrate the DC offset
    {
    	*(volatile uint32_t *)ii = DAC_DC_CALI_L;//6585;//-15310;//17797;    //pae demo 4#
    }
    for(ii=(tempaddr+audac_fifo_leg/2);ii<uFifoAddr;ii+=4)    //calibrate the DC offset
    {
    	*(volatile uint32_t *)ii = DAC_DC_CALI_R;//6585;//-15310;//17797;    //pae demo 4#
    }

	u32ADCFifoAddr = uFifoAddr;
	uFifoAddr = AUDIO_IN_Init(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, CO_BIT(ADC0), 0);
	uFifoAddr = Asrc_Adc_Fs_Ppm_Init(uFifoAddr);
	uFifoAddr = Asrc_Dac_Fs_Ppm_Init(uFifoAddr);

	USB_SetCallback(USB_EVENT_AUDIO_IN, USB_In_Speaker);
	USB_SetCallback(USB_EVENT_AUDIO_OUT, USB_Out_Speaker);

	ramp_signal      = 0;

	asrc_adc_Clean_RingBuf();
	asrc_Clean_RingBuf();
	estimation_ppm_init();
	estimation_ppm_relock_init();

	estimation_adc_ppm_init();
	asrc_adc_fs_change_init();

	AUDIO_OUT_Stop(CO_BIT(DAC0)| CO_BIT(DAC1), 0);
	AUDIO_IN_Stop(CO_BIT(ADC0), 0);


	USB_SetCallback(USB_EVENT_AUDIO_STATUS_CHANGE,USB_InterfaceSetting_adc_dac);

	//Earphone_KWP_Detect  test initial
	Micin_Key_Det_Fsm_Init();	//hardware mode
	Earphone_Key_Detect_Thrd_Init(pOtpInRam->PMOD);	//for KT0201/0202 board

	if(USB_TYPEC_HEADSET == pOtpInRam->PMOD)
	{
		apb_audio_ctrl1_audio_pga_jack_pin_order_sts_setf(1);		//according to pcb design: default 0:mic=vinn, 1: mic=vinp
	}


	stUsbAudio.u8AudioSamSelect = 0;
    Usb_Open(0);
}
void USB_UnConfigHeadSet()
{
	pusb_HeadSet_ftabl->UnConfigHeadSet();
}
extern void patch_USB_UnConfigHeadSet();

void USB_HeadSet_GPIO_Handle(uint8_t ucGpioBits)
{
	pusb_HeadSet_ftabl->HeadSetGPIO(ucGpioBits);
}
extern void patch_USB_HeadSet_GPIO_Handle(uint8_t ucGpioBits);


const usb_HeadSet_ftable_t new_usb_HeadSet_patch_ftable =
{
    .ConfigHeadSet          = new_patch_USB_ConfigHeadSet,
    .UnConfigHeadSet          = patch_USB_UnConfigHeadSet,
    .HeadSetGPIO          = patch_USB_HeadSet_GPIO_Handle,
};

void new_usb_HeadSet_patch_init(void)
{
	pusb_HeadSet_ftabl = (usb_HeadSet_ftable_t *)&new_usb_HeadSet_patch_ftable;
}
