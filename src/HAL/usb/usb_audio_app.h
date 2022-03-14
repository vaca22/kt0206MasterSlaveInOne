/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_AUDIO_APP_H_
#define USB_AUDIO_APP_H_

#include"nds32_math_types.h"
#include"comm.h"
#include "usb_com.h"
#include "usb_ch9.h"
#include "usb_hid_app.h"
#include "audio_in.h"
#include "audio_out.h"

#define IN_SEZE		32
/////////////////////////////////HID DEFINE//////////////////////////////
#define Set_Control(x)	 CONTROL = x
#define VOLUM_UP	0x01
#define VOLUM_DOWN	0x02
#define MUTE		0x04
#define PLAY		0x08
#define PAUSE		0x10
///////////////////////////////////////////////////////////////////////


typedef enum
{
    USB_EVENT_AUDIO_IN,
    USB_EVENT_AUDIO_OUT,
    USB_EVENT_HID_OUT,
    USB_EVENT_AUDIO_STATUS_CHANGE,
    USB_EVENT_BUS_SUSPEND,
    USB_EVENT_NUM,
}eUSB_Event;
typedef enum
{
    USB_AUDIO_IN,
    USB_AUDIO_OUT,
    USB_MODE_NUM,
}eUSB_Audio_Path;
typedef enum
{
    USB_UNIT_1 = 1,
    USB_UNIT_2,
    USB_UNIT_3,
    USB_UNIT_4,
    USB_UNIT_5,
    USB_UNIT_6,
    USB_UNIT_7,
    USB_UNIT_8,
    USB_UNIT_9,//Feature unit for sidetone control in windows
    USB_UNIT_NUM = USB_UNIT_9,
}eUSB_FeatureUnit;

typedef struct 
{
    uint8_t 	 u8Length;
    uint8_t      u8IsSamFreqChange;
    uint8_t	     u8BufChange;     //bit0 sam freq ,bit1 packet size ,bit2 channel
    uint32_t      u32SamFreq;
    uint8_t        u8SamPointNum;
    int32_t*      pUsb_Data_Left;
    int32_t*      pUsb_Data_Right;
    uint8_t        bMaxPacketSize0;
    uint8_t        u8ChannelNum;
    uint8_t        u8PackSize;
    uint8_t        u8Status;
    USB_Callback pUsbFun;
}stUSB_Audio_Attr;

typedef struct
{
    uint8_t 	              bLength;
    uint8_t                   u8AudioSamSelect;
    stUSB_Audio_Attr 	      stAudioAttr[USB_MODE_NUM];
    st_USB_KeyBoard_Report_t  stKeyBoard;
    uint8_t 	              u8LastAudioCtl;
    uint8_t 	              u8AudioCtl;
    uint8_t 	              u8LedStatus;
    uint8_t 	              eRequest;
    uint8_t                   u8InterfaceNum;
    uint8_t                   u8AltSet;
    eUSB_RequestFlow_Type     eRequestFlowType;
    eUSB_Request_Type         eRequestType;
    eUSB_RequestAccepter      eRequestAccepter;
    uint8_t 	              u8Mute;
    uint16_t                  u16Volume[3];
    uint8_t 	              ubDownLoad : 1;
    uint8_t 	              ubMic : 1;
    USB_OTP                   stUsbOTP;
    product_app_index_t       eUsbMode;
    USB_Callback              USBCallBackFun;
    USB_Callback              USBHidOutFun;
    USB_Callback              USBStatusFun;
}stUSB_Audio_Dev;
extern stUSB_Audio_Dev stUsbAudio;
void Audio_Task(void);

uint8_t USB_In_Audio_Pre(void);
void USB_In_Audio_Send(void);
void Audio_Task(void);
void USB_Out_Audio(void);

void Audio_HID(void);
void Audio_GetFeatureMute(uint8_t u8TerminalID);
void Audio_SetFeatureMute(uint8_t u8TerminalID);

void Audio_GetFeatureVolume(uint8_t u8TerminalID);
void Audio_GetVolume(uint8_t volum_l,uint8_t volum_h,uint8_t u8TerminalID);

void Audio_SetFeatureVolume(uint8_t u8TerminalID);
void Audio_SetVolume(uint8_t u8TerminalID);

void Audio_GetRequest();
void Audio_GetFeature(uint8_t u8TerminalID);
void Audio_SetFeature(uint8_t u8TerminalID);

void Audio_GetMIXer(uint8_t u8TerminalI);
void Audio_GetEndPoint();
void Audio_SetEndPoint();
void Audio_bufinit();
void Audio_Set(void);
void Audio_Get(void);
void USB_SetCallback(eUSB_Event ePath,USB_Callback AudioFun);
void usb_audio_patch_init(void);

void new_usb_audio_patch_init(void);

extern uint8_t Mute;
extern uint8_t Volume_H;
extern uint8_t Volume_L;
extern uint16_t Volume_CUR;
volatile uint16_t g_usVolumeMin;
volatile uint16_t g_usVolumeMax;
volatile uint16_t g_usVolumeRes;


#endif//USB_AUDIO_APP_H_

