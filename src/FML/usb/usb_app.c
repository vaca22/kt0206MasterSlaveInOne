//******************KT Micro ******************************************************/
// File Name          : usb_app.c
// Author             : bing.cui
// Version            : V1.0.0
// Date               : 04/24/2018
// Description        :
// lizhen 2018/12/19  拢篓1拢漏 add tempSampNum pre logic for 44.1k ...
//********************************************************************************/
#include <stdio.h>
#include "usb_app.h"
#include "ke_event.h"
#include "audio.h"
#include "audio_out.h"
#include "Co_rbuf.h"
#include "swi.h"
#include "usb_audio_app.h"
#include "usb_hid_app.h"
#include "earphone_insert_remove_detect.h"
#include "hal_config.h"
#include "bll_config.h"
#include "reg_misc.h"
#include "chip_config.h"
#include "volume.h"

#include "chipEffect_top.h"
#include "effect_config.h"
#include "asrc_adc_fs_ppm_pack.h"
#include "debug.h"
#include "uswi_asrc.h"


//*******************************************************************************
//                               .                        global variable
//*******************************************************************************/
st_USB_Contrtl_t _stUSBCtrtl[USB_DEV_NUM_MAX];
uint8_t _u8UsbDevFlag = 0;
//BOOL _bUsbInit = FALSE;
uint8_t _u8VendorMode = 0;
extern stUSB_Audio_Dev stUsbAudio;

extern int32_t USB_ADC_FS;
extern int32_t USB_ADC_FS_D;
extern uint8_t _u8InCount;
extern int32_t usb_data[96];

//*******************************************************************************
//                                                          define
//*******************************************************************************/
#define _Set_ConfigFlag(eUsbConfigType,u8UsbDevIndex)		   (_stUSBCtrtl[u8UsbDevIndex].u32UsbConfigFlag|=(1<<(eUsbConfigType)))
#define _Get_ConfigFlag(eUsbConfigType,u8UsbDevIndex)		   ((1<<(eUsbConfigType))&_stUSBCtrtl[u8UsbDevIndex].u32UsbConfigFlag)
#define _Usb_Opean_UsbDevId(u8UsbDevIndex)		                 (_u8UsbDevFlag = (1<<(u8UsbDevIndex))|_u8UsbDevFlag)
#define _Usb_Close_UsbDevId(u8UsbDevIndex)		                 (_u8UsbDevFlag = ((~(1<<(u8UsbDevIndex)))&_u8UsbDevFlag))
#define _Usb_Get_UsbDevId(u8UsbDevIndex)		                        ((1<<(u8UsbDevIndex))&_u8UsbDevFlag)
/*
#define _Usb_Check_Init() 	                                                                  \
{                                                                                                       \
    if( FALSE == _bUsbInit )                                                               \
    {                                                                                                   \
        LOG_ERROR("[USB]Please init first.");                                          \
        return RETURN_NO_INIT;                                                           \
    }                                                                                                   \
}

#define _Usb_Check_Index(u8UsbDevIndex)                                                             \
{                                                                                                                                       \
    if( USB_DEV_NUM_MAX <= (u8UsbDevIndex) )                                                                \
    {                                                                                                                                   \
        LOG_ERROR("[USB]Without this device number.[%d]",u8UsbDevIndex);                          \
        return RETURN_INPUT_ERR;                                                                                       \
    }                                                                                                                                   \
}*/
typedef struct usb_app_ftable_stru
{
	USB_RETURN (*Init)(uint8_t* ,uint16_t);
	void (*USB_PowerOn_Init)(uint8_t mode);
	void (*SWIEnable)   (void);
	USB_RETURN (*Open)  (uint8_t);
	USB_RETURN (*Close)  (uint8_t);
	USB_RETURN (*DeInit)   (void);
    USB_RETURN (*GetUSBAttr)    (uint8_t , USB_CALLBACK_PATH ,void* ,uint8_t );
    USB_RETURN (*GetUSBBuff)    (uint8_t , USB_CALLBACK_PATH ,void* ,uint8_t ,uint8_t);
    USB_RETURN (*SendHidReport)   (uint8_t , eReportId ,void* ,uint8_t);
    USB_RETURN (*SetOTP)   (USB_OTP);
    USB_RETURN (*SetAppMode) (product_app_index_t);
    USB_RETURN (*SetVendorMode) (uint8_t);

} usb_app_ftable_t;
usb_app_ftable_t *pusb_app_ftabl = NULL;

/*******************************************************************************
/                                                               API
*******************************************************************************
* Function Name  :Usb_Init
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
USB_RETURN Usb_Init(uint8_t* pu8UsbBuffer,uint16_t u16UsbBufferSize)
{
	return pusb_app_ftabl->Init(pu8UsbBuffer,u16UsbBufferSize);
}

extern USB_OTP gstOTP;
//extern USB_RETURN patch_Usb_Init(uint8_t* pu8UsbBuffer,uint16_t u16UsbBufferSize);
USB_RETURN new_patch_Usb_Init(uint8_t* pu8UsbBuffer,uint16_t u16UsbBufferSize)
{
	DBG_OUT_FUNC("entry\n");
	// uint8_t *pubDownLoad = (uint8_t *)0x41430;
	// uint32_t bkDownLoad;

	apb_pwm_ctrl2_usb_phy_pd_setf(0);	//USB PHY power on
	timer_delay_length(1, TIM_MS);

	// bkDownLoad = *pubDownLoad;
	// bkDownLoad = SW_USB_DOWNLOAD;
    memset((void *)RAM_USB_FIFO_BASE_ADDR,0, 1024*9+64);
    // Init_SIE();//这连接USB,让主机开始识别
    Set_USBBuffer(pu8UsbBuffer,  u16UsbBufferSize);
    memset(_stUSBCtrtl,0,sizeof(st_USB_Contrtl_t)*USB_DEV_NUM_MAX);
    memset(&stUsbAudio, 0, sizeof(stUSB_Audio_Dev));
	// 下面设置USB_SetAppMode(pOtpInRam->PMOD);是因为前面会把stUsbAudio.eUsbMode给清成0，故先要在前面初始化0后再调用
	#ifndef JACK_SENSE_FUNC
		#if(AUDIO_IN_SEL==0)
			USB_SetAppMode(USB_TYPEC_HEADPHONE);//stUsbAudio.eUsbMode = pOtpInRam->PMOD;
		#else
			#if(AUDIO_OUT_SEL==0)
			USB_SetAppMode(USB_DONGLE);
			#else
			USB_SetAppMode(USB_TYPEC_HEADSET);
			#endif
		#endif
	#else
		#if(AUDIO_IN_SEL==0)
			USB_SetAppMode(USB_TYPEC_HEADPHONE);//stUsbAudio.eUsbMode = pOtpInRam->PMOD;
		#else
			USB_SetAppMode(pOtpInRam->PMOD);//stUsbAudio.eUsbMode = pOtpInRam->PMOD;
		#endif
	#endif
    USB_SetOTP(gstOTP);
	Init_SIE();//这连接USB,让主机开始识别
    FIFO_CONFIG_5 = 0x40000u;

  //  Vendor_DownLoad(_u8VendorMode);
    // if(1)//*pubDownLoad == 0x78)
    // *pubDownLoad = bkDownLoad;
    // if(*pubDownLoad == 0x78)
    if(0x12345678 == SW_USB_DOWNLOAD)
    {
    	stUsbAudio.ubDownLoad = TRUE;
    	USB_CDCInit();
    }

    USB_HIDBuffInit();
	DBG_OUT_FUNC("exit\n");
    return RETURN_OK;
}


extern uint8_t _u8InCount;
extern int32_t USB_ADC_FS;

extern void asrc_adc_top(
		int32_t *pOUT_USB,
		int32_t USB_ADC_PCM_NUM);

void USB_PowerOn_Init(uint8_t mode)
{
	pusb_app_ftabl->USB_PowerOn_Init(mode);
}
//extern void patch_USB_PowerOn_Init(uint8_t mode);
void new_patch_USB_PowerOn_Init(uint8_t mode)
{
	DBG_OUT_FUNC("entry\n");
	apb_pwm_ctrl2_usb_phy_pd_setf(1);	//USB PHY power off
	timer_delay_length(1, TIM_MS);
	apb_pwm_ctrl2_usb_phy_pd_setf(0);	//USB PHY power on
	timer_delay_length(5, TIM_MS);

	apb_rst_gen_ctrl0_soft_usb_xclk_rst_setf(1);
	apb_rst_gen_ctrl0_soft_usb_phy_rst_setf(1);
	apb_rst_gen_ctrl1_soft_usb_rst_setf(1);
	timer_delay_length(1, TIM_MS);
	apb_rst_gen_ctrl0_soft_usb_xclk_rst_setf(0);
	apb_rst_gen_ctrl0_soft_usb_phy_rst_setf(0);
	apb_rst_gen_ctrl1_soft_usb_rst_setf(0);
	// timer_delay_length(2000, TIM_MS);
	DBG_OUT_FUNC("exit\n");
}





/*******************************************************************************
* Function Name  :Usb_Opean
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
extern uint8_t SWI_UsbIn_flag;
extern uint8_t SWI_UsbOut_flag;
#ifndef USB2DSP_SMP_RATE_DIFF
void new_NEW_SWI_ISR(uint32_t id)
{
	if ((USB_DONGLE != pOtpInRam->PMOD) ||
	   ((USB_DONGLE == pOtpInRam->PMOD)&&(DONGLE_ADC_IN == g_pstConfig->FuncCfg.DongleAudioInSel)) ||
	   ((USB_DONGLE == pOtpInRam->PMOD)&&(DONGLE_I2S_SLAVE_IN == g_pstConfig->FuncCfg.DongleAudioInSel)))
	{
		uint8_t  tempSamNum = 48;
		if(SWI_UsbIn_flag)
		{
			#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
			Pack_asrc_In_Top(&g_st_AsrcI2SIN, usb_data, usb_data+48, tempSamNum);
			uint16_t vol = volume_table[dsp_usb_postvol];
			Dsp24bitVolumeSmoothStereo(usb_data, usb_data+48, usb_data, usb_data+48 ,vol, &g_usb_postvol_buff, tempSamNum);
			#else
			asrc_adc_top(usb_data,tempSamNum);
			if(tempSamNum <= 48)
			{
				HeadsetEffect_Usbin(g_st_pHeadsetEft, usb_data, usb_data, usb_data+48, tempSamNum);
				// if(SWI_UsbOut_flag)
				{
					HeadsetEffect_Usbout(g_st_pHeadsetEft, usb_data, usb_data+48, tempSamNum, USB_DAC_PCM_NUM);
				}
				uint16_t vol = volume_table[dsp_usb_postvol];
				Dsp24bitVolumeSmoothStereo(usb_data, usb_data+48, usb_data, usb_data+48 ,vol, &g_usb_postvol_buff, tempSamNum);
			}
			#endif
			SWI_UsbIn_flag = 0;
		}
		if(SWI_UsbOut_flag)
		{
			HeadsetEffect_Usbout(g_st_pHeadsetEft, usb_data, usb_data+48, 0, USB_DAC_PCM_NUM);
			SWI_UsbOut_flag = 0;
		}

		if (swiI2SIn2DACFlag)
		{
			Pack_asrc_In_Top(&g_st_AsrcI2SIN2Dac, &g_I2SIn2DacBuf[0], &g_I2SIn2DacBuf[48], tempSamNum);
			swiI2SIn2DACFlag = 0;

			if(SWI_UsbIn_flag) {
				#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
				Pack_asrc_In_Top(&g_st_AsrcI2SIN, usb_data, usb_data+48, tempSamNum);
				uint16_t vol = volume_table[dsp_usb_postvol];
				Dsp24bitVolumeSmoothStereo(usb_data, usb_data+48, usb_data, usb_data+48 ,vol, &g_usb_postvol_buff, tempSamNum);
				#else
				asrc_adc_top(usb_data,tempSamNum);
				if(tempSamNum <= 48)
				{
					HeadsetEffect_Usbin(g_st_pHeadsetEft, usb_data, usb_data, usb_data+48, tempSamNum);
					// if(SWI_UsbOut_flag)
					{
						HeadsetEffect_Usbout(g_st_pHeadsetEft, usb_data, usb_data+48, tempSamNum, USB_DAC_PCM_NUM);
					}
					uint16_t vol = volume_table[dsp_usb_postvol];
					Dsp24bitVolumeSmoothStereo(usb_data, usb_data+48, usb_data, usb_data+48 ,vol, &g_usb_postvol_buff, tempSamNum);
				}
				#endif
				SWI_UsbIn_flag = 0;
			}
		}

	}

    Clear_SWI();
}
#else
uint8_t sampleMultiple = 1;
void new_NEW_SWI_ISR(uint32_t id)
{
	if ((USB_DONGLE != pOtpInRam->PMOD) ||
	   ((USB_DONGLE == pOtpInRam->PMOD)&&(DONGLE_ADC_IN == g_pstConfig->FuncCfg.DongleAudioInSel)) ||
	   ((USB_DONGLE == pOtpInRam->PMOD)&&(DONGLE_I2S_SLAVE_IN == g_pstConfig->FuncCfg.DongleAudioInSel)))
	{
		uint8_t tempSamNum = 48;
		switch(USB_ADC_FS)
		{
			case 7:  //44.1k
			{
				tempSamNum =  44;
				sampleMultiple = stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8SamPointNum / tempSamNum;
				if( _u8InCount == 10-1 )
					tempSamNum = 45;

			}break;
			case 8:  //48k
			{
			   tempSamNum =  48;
			   sampleMultiple = stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8SamPointNum / tempSamNum;
			}break;
			default: break;
		}

		 if(SWI_UsbIn_flag)
		 {
			asrc_adc_top(usb_data,tempSamNum);
			// uint16_t vol = volume_table[dsp_usb_postvol];
			// Dsp24bitVolumeSmooth(usb_data, usb_data, vol, &g_usb_postvol_buff, tempSamNum*N);
		 }
		 else
		 {
			if(SWI_UsbOut_flag)
			{
				HeadsetEffect_Usbout(g_st_pHeadsetEft, usb_data, usb_data, 0, USB_DAC_PCM_NUM);
			}
		 }

	}
    SWI_UsbIn_flag = 0;
    SWI_UsbOut_flag = 0;
    Clear_SWI();
}
#endif


void SWI_Enable()
{
	pusb_app_ftabl->SWIEnable();
}
void new_patch_SWI_Enable()
{
    intc_enable_set(INTC_ID_SWI,new_NEW_SWI_ISR);
    return ;
}

extern uint8_t _u8UsbDevFlag;
#define _Usb_Opean_UsbDevId(u8UsbDevIndex)		                 (_u8UsbDevFlag = (1<<(u8UsbDevIndex))|_u8UsbDevFlag)
inline void Gen_SWI(void);


USB_RETURN Usb_Open(uint8_t u8UsbDevIndex)
{
	return pusb_app_ftabl->Open(u8UsbDevIndex);
}
extern USB_RETURN patch_Usb_Open(uint8_t u8UsbDevIndex);

/*******************************************************************************
* Function Name  :Usb_Close
* Description    :
* Input          :
* Output         :
* Return         :
*
******************************************************************************/
USB_RETURN Usb_Close(uint8_t u8UsbDevIndex)
{
	return pusb_app_ftabl->Close(u8UsbDevIndex);
}
extern USB_RETURN patch_Usb_Close(uint8_t u8UsbDevIndex);


/*******************************************************************************
* Function Name  :
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
USB_RETURN Usb_DeInit()
{
	return pusb_app_ftabl->DeInit();
}
extern USB_RETURN patch_Usb_DeInit();

USB_RETURN Usb_Get_USB_Attr(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex,void* param,uint8_t u8Len)
{
	return pusb_app_ftabl->GetUSBAttr(u8UsbDevIndex, eIndex, param, u8Len);
}
extern USB_RETURN patch_Usb_Get_USB_Attr(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex,void* param,uint8_t u8Len);

USB_RETURN Usb_Get_USB_Buff(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex ,void* param,uint8_t u8ParamNum,uint8_t u8Len)
{
	return pusb_app_ftabl->GetUSBBuff(u8UsbDevIndex,eIndex ,param, u8ParamNum, u8Len);
}
extern USB_RETURN patch_Usb_Get_USB_Buff(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex ,void* param,uint8_t u8ParamNum,uint8_t u8Len);

USB_RETURN USB_SendHidReport(uint8_t u8UsbDevIndex, eReportId  u8HidNum  ,void* param,uint8_t u8Len)
{
	return pusb_app_ftabl->SendHidReport(u8UsbDevIndex, u8HidNum , param, u8Len);
}
extern USB_RETURN patch_USB_SendHidReport(uint8_t u8UsbDevIndex, eReportId  u8HidNum  ,void* param,uint8_t u8Len);

uint16_t USB_KeyBoardContinueSend(uint8_t* ucBuf, uint16_t usLen)
{
    uint16_t i;
    const uint8_t ucNoEvent[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    st_USB_KeyBoard_Report_t stTest;

    if(usLen % sizeof(st_USB_KeyBoard_Report_t))
    {
        return ERR;
    }

    usLen /= sizeof(st_USB_KeyBoard_Report_t);

    for(i = 0; i < usLen; i++)
    {
        memcpy(&stTest, &ucBuf[i * sizeof(st_USB_KeyBoard_Report_t)], sizeof(st_USB_KeyBoard_Report_t));
        USB_SendHidReport(0, REPORT_KEYBOARD_ID, &stTest, sizeof(st_USB_KeyBoard_Report_t));
        memcpy(&stTest, &ucNoEvent, sizeof(st_USB_KeyBoard_Report_t));
        USB_SendHidReport(0, REPORT_KEYBOARD_ID, &stTest, sizeof(st_USB_KeyBoard_Report_t)); // clear
        timer_delay_length(11, TIM_MS);
    }
    USB_SendHidReport(0, REPORT_KEYBOARD_ID, &stTest, sizeof(st_USB_KeyBoard_Report_t)); // clear
    return OK;
}

USB_RETURN USB_SetOTP(USB_OTP stOTP)
{
	return pusb_app_ftabl->SetOTP(stOTP);
}
extern USB_RETURN patch_USB_SetOTP(USB_OTP stOTP);

USB_RETURN USB_SetAppMode(product_app_index_t eUsbMode)
{
	return pusb_app_ftabl->SetAppMode(eUsbMode);
}
extern USB_RETURN patch_USB_SetAppMode(product_app_index_t eUsbMode);

USB_RETURN USB_SetVendorMode(uint8_t u8VendorMode)
{
	return pusb_app_ftabl->SetVendorMode(u8VendorMode);
}
extern USB_RETURN patch_USB_SetVendorMode(uint8_t u8VendorMode);

const usb_app_ftable_t new_usb_app_patch_ftable =
{
    .Init				= new_patch_Usb_Init,
    .USB_PowerOn_Init	= new_patch_USB_PowerOn_Init,
    .SWIEnable			= new_patch_SWI_Enable,
    .Open				= patch_Usb_Open,
    .Close				= patch_Usb_Close,
    .DeInit				= patch_Usb_DeInit,
    .GetUSBAttr			= patch_Usb_Get_USB_Attr,
    .GetUSBBuff			= patch_Usb_Get_USB_Buff,
    .SendHidReport		= patch_USB_SendHidReport,
    .SetOTP				= patch_USB_SetOTP,
    .SetAppMode			= patch_USB_SetAppMode,
    .SetVendorMode		= patch_USB_SetVendorMode,
};
void new_usb_app_patch_init(void)
{
	pusb_app_ftabl = (usb_app_ftable_t *)&new_usb_app_patch_ftable;
}
