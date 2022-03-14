/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#include "usb_ch9.h"
#include "Co_rbuf.h"
#include "Asrc_dac_fs_ppm.h"
#include "Asrc_adc_fs_ppm.h"
#include "audio_process_usb2dac.h"
#include "audio_process_adc2usb.h"
#include "i2s_nco_writebuf.h"
#include "i2s_nco.h"
#include "asrc_codec_filter_fast.h"
#include "hal_config.h"
#include "bll_config.h"
#include "volume.h"
#include "chip_config.h"
#include "debug.h"

#define VOL_IDX_VAL_MAX		 103 // the index value of 0dB in volume table is 103

volatile uint8_t u8DACSampParamSet=0;
volatile uint8_t u8ADCSampParamSet=0;
volatile uint16_t g_usVolumeMin;
volatile uint16_t g_usVolumeMax;
volatile uint16_t g_usVolumeRes;
uint8_t Mute;
uint8_t Volume_H;
uint8_t Volume_L;
uint16_t Volume_CUR;
uint8_t _u8USBOutFifoSize = MAX_SIZE;
int32_t USB_DAC_PCM_NUM = 48;  //PCM sample number in 1ms seconds
extern int32_t USB_DAC_FS;
extern int32_t USB_ADC_FS;  
extern uint8_t dsp_adc2usb_vol;
co_rbuf_t *pRBufAudioL;
co_rbuf_t *pRBufAudioR;
uint8_t _u8InCount = 0;
extern stUSB_Audio_Dev stUsbAudio;
uint8_t u8ADCSampParam, u8DACSampParam;
extern uint8_t dsp_dac_postvol;
// q31_t u32Unit[96] ={0};

extern int32_t start_coarse_ppm;
extern uint8_t ASRC_DAC_PFORMANCE;
extern uint8_t ASRC_DAC_PFORMANCE_96K;

extern uint8_t PLAY_END_CONT;	//yuan++

typedef struct usb_audio_ftable_stru
{
	void (*GetPacket)   (uint8_t* , uint8_t* ,eUSB_Audio_Path);
	void (*AudioTask)(void);
    void (*SetCallback)   (eUSB_Event ,USB_Callback );
    void (*OutAudio)   (void);
 	uint8_t (*InAudioPre)  (void);
    void (*InAudioSend)  (void);
    void (*GeFeatureMute)   (uint8_t);
    void (*GetFeatureVolume)    (uint8_t);
    void (*GetVolume)     (uint8_t ,uint8_t ,uint8_t );
    void (*SetFeatureVolume)   (uint8_t);
    void (*SetVolume) (uint8_t);
    void (*SetFeatureMute) (uint8_t);
    void (*GetRequest)    (void);
    void (*AudioSet) (void);
    void (*AudioGet)   (void);
    void (*GetFeature)    (uint8_t);
    void (*SetFeature)     (uint8_t);
    void (*bufinit) (void);
    void (*GetMIXer) (uint8_t);
    void (*GetEndPoint)    (void);
    void (*SetEndPoint) (void);
    USB_CONFIG_DES_SIZE (*ConfigDesSize) (void);
} usb_audio_ftable_t;

usb_audio_ftable_t *pusb_audio_ftabl = NULL;
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetPacket_Type(uint8_t *pu8ChannelNum, uint8_t * pu8PackSize ,eUSB_Audio_Path eAudioPath)
{
	return pusb_audio_ftabl->GetPacket(pu8ChannelNum,pu8PackSize ,eAudioPath);
}
extern void patch_Audio_GetPacket_Type(uint8_t *pu8ChannelNum, uint8_t * pu8PackSize ,eUSB_Audio_Path eAudioPath);

void Audio_Task(void)
{
	return pusb_audio_ftabl->AudioTask();
}
extern void patch_Audio_Task(void);

void USB_SetCallback(eUSB_Event ePath,USB_Callback AudioFun)
{
	return pusb_audio_ftabl->SetCallback(ePath,AudioFun);
}
extern void patch_USB_SetCallback(eUSB_Event ePath,USB_Callback AudioFun);
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_Out_Audio(void) //USB 1ms interrupt
{
	return pusb_audio_ftabl->OutAudio();
}
void new_patch_USB_Out_Audio(void) //USB 1ms interrupt
{
    uint16_t i,u16PktSize =0;
    uint8_t u8ChannelNum = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8ChannelNum;
    uint8_t u8PackSize =stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8PackSize;
    int32_t u32Unit =0;
	int32_t* pUsbAddrL =0;
	int32_t* pUsbAddrR= 0;

	u16PktSize = rSIE_OCOUNT;

	//for 96k, 2channel, 24bits,  u16PktSize = 96*2*3Bytes = 576
    USB_DAC_PCM_NUM = u16PktSize/(u8ChannelNum*u8PackSize);  //16bits or 24bits

    stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8SamPointNum = USB_DAC_PCM_NUM;

    if(stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8BufChange != 0)// to do : if u8ChannelNum/u8PackSize/USB_DAC_PCM_NUM change
    {
		if(2 == u8PackSize)   //16bit
		{
			pUsbAddrL =(int32_t *)((uint16_t *)USB_BUFF+USB_DAC_PCM_NUM*u8ChannelNum*u8PackSize);
			pUsbAddrR =(int32_t *)((uint16_t *)USB_BUFF+USB_DAC_PCM_NUM*u8ChannelNum*u8PackSize)+USB_DAC_PCM_NUM;
		}
		else if(3 == u8PackSize)   //24bit
		{
			pUsbAddrL =(int32_t *)(USB_BUFF+USB_DAC_PCM_NUM*u8ChannelNum*u8PackSize);
			pUsbAddrR =((int32_t *)(USB_BUFF+USB_DAC_PCM_NUM*u8ChannelNum*u8PackSize))+USB_DAC_PCM_NUM;
		}
		if(USB_DAC_PCM_NUM <96)
		{
			pUsbAddrL = pUsbAddrL + 2;
			pUsbAddrR = pUsbAddrR + 4;
		}
		stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8BufChange =0;
		stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left = pUsbAddrL;
		stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right = pUsbAddrR;
    }
    else
    {
        pUsbAddrL = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left;
        pUsbAddrR= stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right;
        PLAY_END_CONT = 0;	//yuan++
    }

    uint16_t *pu16Ep1TxBuf = (uint16_t *)EP1_TX_BUF;
	if (2 == u8PackSize) {
        for (i = 0; i < USB_DAC_PCM_NUM; i++)
        {
        	u32Unit = pu16Ep1TxBuf[i*u8ChannelNum];
        	pUsbAddrL[i] = (u32Unit << 16) >> 8;
        	if(2 == u8ChannelNum){
        		u32Unit = pu16Ep1TxBuf[i*u8ChannelNum+1]; 
        		pUsbAddrR[i] = (u32Unit << 16) >> 8;
        	}
        }
    } else if (3 == u8PackSize) {
        for (i = 0; i < USB_DAC_PCM_NUM; i++)
        {
        	u32Unit = pu16Ep1TxBuf[3*i*u8ChannelNum/2];
        	u32Unit = __nds32__insb(u32Unit, pu16Ep1TxBuf[3*i*u8ChannelNum/2 + 1] & 0xFF, 2);
        	pUsbAddrL[i] = (u32Unit << 8) >> 8;
        	if(2 == u8ChannelNum){
        		u32Unit = (pu16Ep1TxBuf[3*i*u8ChannelNum/2 + 1] >> 8) & 0xFF;
        		u32Unit |= pu16Ep1TxBuf[3*i*u8ChannelNum/2 + 2] << 8;
        		pUsbAddrR[i] = (u32Unit << 8) >> 8;
        	}
        }
    } else {
        ;
    }
	
	// do mag compensation
	// if( (ASRC_DAC_PFORMANCE == 0) && (USB_DAC_FS<=8) )
	if((ASRC_DAC_PFORMANCE == 0) || (ASRC_DAC_PFORMANCE_96K == 0))
	{
	  	pffast_two_dac_mag(
	  			pUsbAddrL,
	  			pUsbAddrR,
	  			pUsbAddrL,
	  			pUsbAddrR,
	  			USB_DAC_FS,
	  			2,
	  			USB_DAC_PCM_NUM);
	}
}



/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
extern uint8_t patch_USB_In_Audio_Pre(void);

extern void patch_USB_In_Audio_Send(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetFeatureMute(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->GeFeatureMute(u8TerminalID);
}
extern void patch_Audio_GetFeatureMute(uint8_t u8TerminalID);

void new_patch_Audio_GetFeatureMute(uint8_t u8TerminalID)
{
	uint8_t u8Mute = 0;
	if(USB_UNIT_2 == u8TerminalID)
	{
		u8Mute = (((stUsbAudio.u8Mute) & BIT0) != FALSE);
	}
	else if(USB_UNIT_7 == u8TerminalID)
	{
		u8Mute = (((stUsbAudio.u8Mute) & BIT1) != FALSE);
	}
	else if(USB_UNIT_9 == u8TerminalID)
	{
		u8Mute = (((stUsbAudio.u8Mute) & BIT2) != FALSE);
	}
	rSIE_FIFOEP0 = u8Mute;
}
/*******************************************************************************
* Function Name  : 
* Description    :
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetFeatureVolume(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->GetFeatureVolume(u8TerminalID);
}
extern  void patch_Audio_GetFeatureVolume(uint8_t u8TerminalID);
// {
// 	switch(stUsbSetup.bRequest)
// 	{
// 		case USB_AUDIO_GET_CUR:
// 		{
// 			Audio_GetVolume(Volume_L,Volume_H,u8TerminalID);
// 			break;
// 		}
// 		case USB_AUDIO_GET_MIN:
// 		{
// 			rSIE_FIFOEP0 = LSB(g_usVolumeMin);
// 			rSIE_FIFOEP0 = MSB(g_usVolumeMin);
// 			break;
// 		}
// 		case USB_AUDIO_GET_MAX:
// 		{
// 			rSIE_FIFOEP0 = LSB(g_usVolumeMax);
// 			rSIE_FIFOEP0 = MSB(g_usVolumeMax);
// 			break;
// 		}
// 		case USB_AUDIO_GET_RES:
// 		{
// 			rSIE_FIFOEP0 = LSB(g_usVolumeRes);
// 			rSIE_FIFOEP0 = MSB(g_usVolumeRes);
// 			break;
// 		}
// 	}
// }
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetVolume(uint8_t volum_l,uint8_t volum_h,uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->GetVolume(volum_l, volum_h, u8TerminalID);
}
//extern void patch_Audio_GetVolume(uint8_t volum_l,uint8_t volum_h,uint8_t u8TerminalID);
void new_patch_Audio_GetVolume(uint8_t volum_l,uint8_t volum_h,uint8_t u8TerminalID)
{
 	uint16_t u16Volume = 0;
	uint8_t volIndex = 0;
	float volMax = (int16_t)g_usVolumeMax - (int16_t)g_usVolumeMin;

	switch (u8TerminalID)
	{
	case USB_UNIT_2:
#ifdef USB_IN_VOL_INIT_SET_SUPPORT
		{
			static uint8_t usbInVolInitFlag = 0;
			if (usbInVolInitFlag == 0){
				usbInVolInitFlag = 1;
				dsp_adc2usb_vol = USB_IN_VOL_INIT_CLASS;
			}
		}
#endif
		volIndex = dsp_adc2usb_vol;
		break;
	case USB_UNIT_7:						//Audio DAC feature unit
#ifdef USB_OUT_VOL_INIT_SET_SUPPORT
		{
			static uint8_t usbOutVolInitFlag = 0;
			if (usbOutVolInitFlag == 0){
				usbOutVolInitFlag = 1;
				dsp_usb2dac_vol_l = USB_OUT_VOL_INIT_CLASS;
				dsp_usb2dac_vol_r = dsp_usb2dac_vol_l;
				dsp_i2so_vol_l = dsp_usb2dac_vol_l;
				dsp_i2so_vol_r = dsp_usb2dac_vol_l;
			}
		}
#endif
		if (0x01 == LSB(stUsbSetup.wValue)) //left channel
		{
			volIndex = dsp_usb2dac_vol_l;
		#if ((AUDIO_OUT_SEL == 2) || (AUDIO_OUT_SEL == 3))
			volIndex = dsp_i2so_vol_l;
		#endif
		}
		else if (0x02 == LSB(stUsbSetup.wValue)) //right channel
		{
			volIndex = dsp_usb2dac_vol_r;
		#if ((AUDIO_OUT_SEL == 2) || (AUDIO_OUT_SEL == 3))
			volIndex = dsp_i2so_vol_r;
		#endif
		}
		break;
	case USB_UNIT_6:
		volIndex = dsp_dac_postvol;
		break;
	case USB_UNIT_9:
		volIndex = dsp_adc2dac_vol;
	default:
		break;
	}
	u16Volume = (uint16_t)((int16_t)(((float)volIndex / VOL_IDX_VAL_MAX) * volMax) + (int16_t)g_usVolumeMin);
	rSIE_FIFOEP0 = u16Volume & 0xff;
	rSIE_FIFOEP0 = (u16Volume >> 8) & 0xff;
	//DBG_OUT_SYS("get %d 0x%04X ~ %d\n", u8TerminalID, u16Volume, volIndex);
}

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_SetFeatureVolume(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->SetFeatureVolume(u8TerminalID);
}
extern void patch_Audio_SetFeatureVolume(uint8_t u8TerminalID);
// {
// 	switch(stUsbSetup.bRequest)
// 	{
// 		case USB_AUDIO_SET_CUR:		Audio_SetVolume(u8TerminalID);	break;
// 	}
// }
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_SetVolume(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->SetVolume(u8TerminalID);
}
//extern void patch_Audio_SetVolume(uint8_t u8TerminalID);
void new_patch_Audio_SetVolume(uint8_t u8TerminalID)
{
	uint16_t u16Volume = 0;
	u16Volume = rSIE_FIFOEP0;
	u16Volume |= (rSIE_FIFOEP0 << 8) & 0xff00;

	float volSet = (int16_t)u16Volume - (int16_t)g_usVolumeMin;
	float volMax = (int16_t)g_usVolumeMax - (int16_t)g_usVolumeMin;
	uint8_t volIndex = (uint8_t)((volSet/volMax) * VOL_IDX_VAL_MAX);
	switch (u8TerminalID)
	{
	case USB_UNIT_2:
		dsp_adc2usb_vol = volIndex;
		break;
	case USB_UNIT_7:						//Audio DAC feature unit
		if (0x01 == LSB(stUsbSetup.wValue)) //left channel
		{
			dsp_usb2dac_vol_l = volIndex;
			dsp_i2so_vol_l = volIndex;
		}
		else if (0x02 == LSB(stUsbSetup.wValue)) //right channel
		{
			dsp_usb2dac_vol_r = volIndex;
			dsp_i2so_vol_r = volIndex;
		}
		break;
	case USB_UNIT_6:
		dsp_dac_postvol = volIndex;
		break;
	case USB_UNIT_9:
		dsp_adc2dac_vol = volIndex;
		break;
	default:
		break;
	}
	//DBG_OUT_SYS("set %d 0x%04X ~ %d\n", u8TerminalID, u16Volume, volIndex);
}

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_SetFeatureMute(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->SetFeatureMute(u8TerminalID);
}
extern void patch_Audio_SetFeatureMute(uint8_t u8TerminalID);

void new_patch_Audio_SetFeatureMute(uint8_t u8TerminalID)
{
	uint8_t u8BitPos = 0;
	uint8_t u8Mute;
	u8Mute = rSIE_FIFOEP0;

	switch (u8TerminalID)
	{
	case USB_UNIT_2:
		u8BitPos = BIT0;
		break;
	case USB_UNIT_7:
		u8BitPos = BIT1;
		break;
	case USB_UNIT_9:
		u8BitPos = BIT2;
		break;
	default:
		break;
	}
	stUsbAudio.u8Mute = ((u8Mute == TRUE) ? (stUsbAudio.u8Mute | u8BitPos) : (stUsbAudio.u8Mute & ~u8BitPos));
}
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetRequest()
{
	return pusb_audio_ftabl->GetRequest();
}
extern void patch_Audio_GetRequest();

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_Set(void)
{
	return pusb_audio_ftabl->AudioSet();
}
extern void patch_Audio_Set(void);

void new_patch_Audio_Set(void)
{
	if(stUsbAudio.eRequestAccepter == USB_REQUEST_ENDPOINT)
	{
		Audio_SetEndPoint();
	}
	else
	{
		switch(MSB(stUsbSetup.wIndex))
		{
			case	0x02:	Audio_SetFeature(MSB(stUsbSetup.wIndex));	break;
			case	0x07:	Audio_SetFeature(MSB(stUsbSetup.wIndex));	break;
			case	0x06:	Audio_SetVolume(MSB(stUsbSetup.wIndex));	break;
			case	0x09:	Audio_SetFeature(MSB(stUsbSetup.wIndex));	break;
		}
	}
	// patch_Audio_Set();
}
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_Get(void)
{
	return pusb_audio_ftabl->AudioGet();
}
extern void patch_Audio_Get(void);

void new_patch_Audio_Get(void)
{
	if(stUsbAudio.eRequestAccepter == USB_REQUEST_ENDPOINT)
	{
		Audio_GetEndPoint();
	}
	else
	{
		switch(MSB(stUsbSetup.wIndex))
		{		
			case	0x02:   Audio_GetFeature(MSB(stUsbSetup.wIndex));	break;
			case	0x07:	Audio_GetFeature(MSB(stUsbSetup.wIndex));	break;
			case 	0x06:	Audio_GetMIXer(MSB(stUsbSetup.wIndex));		break;
			case	0x09:	Audio_GetFeature(MSB(stUsbSetup.wIndex));	break;
		}
	}
	// patch_Audio_Get();
}
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetFeature(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->GetFeature(u8TerminalID);
}
extern void patch_Audio_GetFeature(uint8_t u8TerminalID);
// {
// 	switch(MSB(stUsbSetup.wValue))
// 		{
// 			case 0x01:Audio_GetFeatureMute(u8TerminalID);break;
// 			case 0x02:Audio_GetFeatureVolume(u8TerminalID);break;
// 		}
// }
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_SetFeature(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->SetFeature(u8TerminalID);
}
extern void patch_Audio_SetFeature(uint8_t u8TerminalID);
// {
// 	switch(MSB(stUsbSetup.wValue))
// 	{
// 		case 0x01:Audio_SetFeatureMute(u8TerminalID);break;
// 		case 0x02:Audio_SetFeatureVolume(u8TerminalID);break;
// 	}
// }

void Audio_bufinit()
{
	return pusb_audio_ftabl->bufinit();
}
extern void patch_Audio_bufinit();

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Audio_GetMIXer(uint8_t u8TerminalID)
{
	return pusb_audio_ftabl->GetMIXer(u8TerminalID);
}
extern void patch_Audio_GetMIXer(uint8_t u8TerminalID);
/*******************************************************************************
* Function Name  :
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
void Audio_GetEndPoint()
{
	return pusb_audio_ftabl->GetEndPoint();
}
extern void patch_Audio_GetEndPoint();

/*******************************************************************************
* Function Name  :
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
uint32_t u32ADCFifoAddr = 0;
uint32_t u32DACFifoAddr = 0;
void Audio_SetEndPoint()
{
	return pusb_audio_ftabl->SetEndPoint();
}
void new_patch_Audio_SetEndPoint()
{ 
    int i = 0;
    int32_t u32SamFreq =0;

    uint8_t u8AudioSamSelect = 0;
    uint8_t u8AsrcMode= 0;

    for(i = 0; i <3; i++)
    {
        u32SamFreq |=  rSIE_FIFOEP0<<(i*8);
    }
    
    switch(u32SamFreq/1000)
    {
        case 8:
        {
            u8AsrcMode =0;
            break;
        }
        case 11:
        {
            u8AsrcMode =1;
            break;
        }
        case 12:
        {
            u8AsrcMode =2;
            break;
        }
        case 16:
        {
            u8AsrcMode =3;
            break;
        }
        case 22:
        {
            u8AsrcMode =4;
            break;
        }
        case 24:
        {
            u8AsrcMode =5;
            break;
        }
        case 32:
        {
            u8AsrcMode =6;
            break;
        }
        case 44:
        {
            u8AsrcMode =7;
            break;
        }
        case 48:
        {
            u8AsrcMode =8;
            break;
        }
		#ifndef USB2DSP_SMP_RATE_DIFF
        case 96:
        {
            u8AsrcMode =9;
            break;
        }
		#endif
        default:
		{
            u8AsrcMode =8;
            break;
        }
    } 
    if(stUsbSetup.wIndex ==0x01)
    {
        if(9 == u8AsrcMode)
        {
             u8AudioSamSelect|= BIT0;
        }
        if(u32SamFreq != stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u32SamFreq)
        {
        	stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8BufChange |= BIT0;
        	stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u32SamFreq = u32SamFreq;
        }
        stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8SamPointNum= u32SamFreq/1000;
        USB_DAC_FS = u8AsrcMode;
    }
    else if (stUsbSetup.wIndex == 0x81)
    {
        if(9 == u8AsrcMode)
        {
             u8AudioSamSelect|= BIT1;
        }
        if(u32SamFreq != stUsbAudio.stAudioAttr[USB_AUDIO_IN].u32SamFreq)
        {
        	stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8BufChange |= BIT0;
        	stUsbAudio.stAudioAttr[USB_AUDIO_IN].u32SamFreq = u32SamFreq;
        }
        stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8SamPointNum= u32SamFreq/1000;
        USB_ADC_FS = u8AsrcMode;


        // if (stUsbAudio.eUsbMode == USB_DONGLE)
        // {
        //     if(usb_audio_fs != u32SamFreq)
        //     {
        //     	usb_audio_fs = u32SamFreq;
        //     	i2s_nco_delta_fcw = 0;
        //     }

		// 	// switch(g_pstConfig->FuncCfg.DongleAudioInSel){
		// 	// 	case DONGLE_ADC_IN:
		// 	// 		break;
		// 	// 	case DONGLE_I2S_MASTER_IN:
		// 	// 		I2S_NCO_Init(u32SamFreq);		//I2S NCO test
		// 	// 		break;
		// 	// 	case DONGLE_I2S_SLAVE_IN:
		// 	// 		break;
		// 	// }
        // }
    }

    if(stUsbAudio.u8AudioSamSelect != u8AudioSamSelect)
    {
        if(stUsbSetup.wIndex ==0x01)
        {
            // if((stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)
            // 	||(stUsbAudio.eUsbMode == USB_TYPEC_HEADPHONE))
			#if((AUDIO_OUT_SEL==1)||(AUDIO_OUT_SEL==3))
            {
            	u8DACSampParamSet = 1;
            	u8ADCSampParam = ((u8AudioSamSelect>>1)&0x1);
				u8DACSampParam = u8AudioSamSelect&0x1;
            }
			#endif
        }
        else if (stUsbSetup.wIndex == 0x81)
        {
            // if((stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)||(stUsbAudio.eUsbMode == USB_DONGLE))
			#if((AUDIO_IN_SEL==1)||(AUDIO_IN_SEL==3))
            {
				u8ADCSampParamSet = 1;
				u8ADCSampParam = ((u8AudioSamSelect>>1)&0x1);
				u8DACSampParam = u8AudioSamSelect&0x1;
            }
			#endif
            // else
            // {
			// 	if(stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status == TRUE)
			// 	{
			// 		switch(g_pstConfig->FuncCfg.DongleAudioInSel){
			// 			case DONGLE_ADC_IN:
			// 				AUDIO_IN_Start(CO_BIT(ADC0), 0);
			// 				break;
			// 			case DONGLE_I2S_MASTER_IN:
			// 				AUDIO_IN_Start((CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)), MASTER0);
			// 				break;
			// 			case DONGLE_I2S_SLAVE_IN:
			// 				AUDIO_IN_Start((CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)), SLAVE0);
			// 				break;
			// 		}
			// 	}
            // }
        }
    	stUsbAudio.u8AudioSamSelect = u8AudioSamSelect;
    }
}

USB_CONFIG_DES_SIZE Get_ConfigDesSize(void)
{
	return pusb_audio_ftabl->ConfigDesSize();
}
const usb_audio_ftable_t new_usb_audio_patch_ftable =
{
    .GetPacket				= patch_Audio_GetPacket_Type,
    .AudioTask				= patch_Audio_Task,
    .SetCallback			= patch_USB_SetCallback,
    .OutAudio				= new_patch_USB_Out_Audio,
    .InAudioPre				= patch_USB_In_Audio_Pre,
    .InAudioSend			= patch_USB_In_Audio_Send,
    .GeFeatureMute			= new_patch_Audio_GetFeatureMute,
    .GetFeatureVolume		= patch_Audio_GetFeatureVolume,
    .GetVolume				= new_patch_Audio_GetVolume,
    .SetFeatureVolume		= patch_Audio_SetFeatureVolume,
    .SetVolume				= new_patch_Audio_SetVolume,
    .SetFeatureMute			= new_patch_Audio_SetFeatureMute,
    .GetRequest				= patch_Audio_GetRequest,
    .AudioSet				= new_patch_Audio_Set,
    .AudioGet				= new_patch_Audio_Get,
    .GetFeature				= patch_Audio_GetFeature,
    .SetFeature				= patch_Audio_SetFeature,
    .bufinit				= patch_Audio_bufinit,
    .GetMIXer				= patch_Audio_GetMIXer,
    .GetEndPoint			= patch_Audio_GetEndPoint,
    .SetEndPoint			= new_patch_Audio_SetEndPoint,
    .ConfigDesSize			= new_patch_Get_ConfigDesSize,
};

void new_usb_audio_patch_init(void)
{
	pusb_audio_ftabl = (usb_audio_ftable_t *)&new_usb_audio_patch_ftable;
}
