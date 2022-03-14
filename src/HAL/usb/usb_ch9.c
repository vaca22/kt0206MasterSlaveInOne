/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_ch9.c
* Author             : wanggang
* Email              : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        :
********************************************************************************/
#include "usb_ch9.h"
#include "usb_app.h"
#include "usb_cdc.h"
#include "hal_config.h"
#include "bll_config.h"
#include "chip_config.h"
#include "usb_config.h"
#include "uswi_asrc.h"

#ifndef USB_SMP_16b
    #define USB_SMP_16b				0x2 //0x0010, 16bit
    #define USB_SMP_24b				0x4	//0x0100, 24bit
    #define USB_SMP_16b_24b			0x6	//0x0110, 16bit + 24bit
    #ifndef USB_IN_SAMPLE_DEPTH
        #define USB_IN_SAMPLE_DEPTH 	USB_SMP_16b// usb in audio sample depth
    #endif
    #ifndef USB_OUT_SAMPLE_DEPTH
        #define USB_OUT_SAMPLE_DEPTH 	USB_SMP_16b_24b// usb out audio sample depth
    #endif
#endif
volatile uint8_t u8UsbInSpeakerSts = FALSE;
extern USB_REQUEST stUsbSetup;
extern USB_DEVICE_STATUS    stUsbDev;
extern uint8_t _USB_ADDR_REG_;
extern int32_t start_adc_coarse_ppm;
extern int16_t gwSecCnt;
extern UINT32 _u32UsbConfigFlag;
extern uint8_t * _pu8UsbBuffer;
extern uint16_t _16UsbBufferSize;
extern uint8_t _u8SendNum;
extern USB_CONFIG_DES_SIZE stConfigDesSize;
extern uint16_t   _wDescLen;
extern uint8_t   _wReportLen;
extern stUSB_Audio_Dev stUsbAudio;
extern uint8_t  cTEST_PACKET[];
extern const uint8_t new_HID_INTERFACE_DESC[];

//#define _Set_ConfigFlag(eUsbConfigType)         (_u32UsbConfigFlag|=(1<<(eUsbConfigType)))
#define _Get_ConfigFlag(eUsbConfigType)       ((1<<(eUsbConfigType))&_u32UsbConfigFlag)

extern const uint8_t  KEYBOARD_REPORT_DESC[];
extern const uint8_t  HID_REPORT_DESC[];
extern const uint8_t  HID_CONFIG_DESC[];
extern const uint8_t  HID_INTERFACE_DESC[];

//tern const uint8_t AUDIO_MH_CONFIG_DESC[MIC_HEADPHONE_LEN];
extern const uint8_t new_AUDIO_CTRL_DONGLE_DESC[];
extern const uint8_t new_AUDIO_CTRL_HEADPHONE_DESC[];
extern const uint8_t new_AUDIO_CTRL_HEADSET_DESC[];
extern const uint8_t AUDIO_HEADSET_CONFIG_DESC[];
extern const uint8_t AUDIO_SPEAK_INTERFACE_DESC[];
extern const uint8_t new_AUDIO_SPEAK_INTERFACE_DESC_1[];
extern const uint8_t new_AUDIO_SPEAK_INTERFACE_DESC_2[];
extern const uint8_t AUDIO_SPEAK_INTERFACE_DESC_3[];
extern const uint8_t new_AUDIO_MICROPHONE_INTERFACE_DESC[];
extern const uint8_t new_AUDIO_MICROPHONE_INTERFACE_DESC_1[];
extern const uint8_t AUDIO_MICROPHONE_INTERFACE_DESC_2[];
// extern const uint8_t VENDOR_INTERFACE_DESC[];

typedef struct usb_ch9_ftable_stru
{
    void (*ConfigDesc)   (void);
    void (*HIDReportDesc)(void);
    void (*DeviceDesc)   (void);
    uint8_t (*StringDesc)   (void);
    void (*SendDevDesc)  (void);
    void (*Delay)        (uint16_t);
    void (*BusSuspend)   (void);
    void (*BusResume)    (void);
    void (*BusReset)     (void);
    void (*EP0Service)   (void);
    void (*SetupService) (void);
    void (*EP0SendStall) (void);
    void (*GetStatus)    (void);
    void (*ClearFeature) (void);
    void (*SetFeature)   (void);
    void (*SetAddress)    (void);
    void (*GetDesc)     (void);
    void (*SetDesc) (void);
    void (*GetConfig) (void);
    void (*SetConfig)    (void);
    void (*GetInterface) (void);
    void (*InterfaceSetting)   (uint8_t , uint8_t );
    void (*SetInterface)    (void);
    void (*SetRequest)     (void);
    void (*EpxSetMaxSize) (void);
    void (*EP0NoData) (void);
    void (*HWConfig)    (uint32_t);
    void (*SetBuffer)    (uint8_t* , uint16_t);
    void (*DownLoad)   (uint8_t);
    void (*SetOTP)    (USB_OTP);
    void (*SetAppMode)     (product_app_index_t);
} usb_ch9_ftable_t;

extern const USB_DEVICE_DESCRIPTOR  cDEVICE_VENDOR_DESC;
usb_ch9_ftable_t *pusb_ch9_ftabl;
extern const uint8_t CDC_INTERFACE_DESC[];
extern const USB_DEVICE_DESCRIPTOR  cDEVICE_DESC;
extern const uint8_t  cLANG_STR[];
extern const uint8_t     cMANUFACT_STR[];
extern const uint8_t     cSERIAL_STR[];


void new_patch_CHP9_SetupService(void)
{
    if ((stUsbAudio.eRequestType == USB_REQUEST_GENRE)
            && (stUsbAudio.eRequestFlowType == USB_REQUEST_HOST_TO_DEVICE))
    {
        switch (stUsbSetup.bRequest)
        {
        case USB_AUDIO_SET_CUR:

        case USB_AUDIO_SET_MIN:

        case USB_AUDIO_SET_MAX:

        case USB_AUDIO_SET_RES:

        case USB_HID_SET_REPORT:

        case USB_HID_SET_IDLE:

        case USB_HID_SET_PROTOCOL:  Set_Request();  break;

        case USB_REQUEST_BOUL_RESET: /*MASS_BulkOnlyReset();*/break;

        case USB_CDC_SET_LINE_CODING:       Set_Request(); break;

        case USB_CDC_SET_CONCTROL_LINE_STATE:  Set_Request(); break;

        default: Hal_EP0SendStall(); break;
        }
    }
    else if ((stUsbAudio.eRequestType == USB_REQUEST_GENRE)
             && (stUsbAudio.eRequestFlowType == USB_REQUEST_DEVICE_TO_HOST))
    {
        switch (stUsbSetup.bRequest)
        {
        case USB_AUDIO_GET_CUR:

        case USB_AUDIO_GET_MIN:

        case USB_AUDIO_GET_MAX:

        case USB_AUDIO_GET_RES:     Audio_GetRequest(); break;

        case USB_HID_GET_REPORT:    HID_GetReport();    break;

        case USB_HID_GET_IDLE:      HID_GetIdle();      break;

        case USB_HID_GET_PROTOCOL:  HID_GetProtocol();  break;

        case USB_REQUEST_GET_MAXLUN:/* MASS_GetMaxLun();*/ break;

        case USB_CDC_GET_LINE_CODING: CDC_GetLineCoding();  break;

        default: Hal_EP0SendStall(); break;

        }
    }
    else if (stUsbAudio.eRequestType == USB_REQUEST_STANDARD)
    {
        switch (stUsbSetup.bRequest) {
        case USB_REQUEST_GET_STATUS:
            CHP9_GetStatus(); //////////
            break;

        case USB_REQUEST_CLEAR_FEATURE:
            CHP9_ClearFeature();////////
            break;

        case USB_REQUEST_SET_FEATURE:
            CHP9_SetFeature();/////////
            break;

        case USB_REQUEST_SET_ADDRESS:
            CHP9_SetAddress();//////////
            break;

        case USB_REQUEST_GET_DESCRIPTOR:
            CHP9_GetDesc(); //////////
            break;

        case USB_REQUEST_SET_DESCRIPTOR:
            CHP9_SetDesc();///////////
            break;

        case USB_REQUEST_GET_CONFIGURATION:
            CHP9_GetConfig();//////////
            break;

        case USB_REQUEST_SET_CONFIGURATION:
            CHP9_SetConfig();/////////////
            break;

        case USB_REQUEST_GET_INTERFACE:
            CHP9_GetInterface();///////////////
            break;

        case USB_REQUEST_SET_INTERFACE:
            CHP9_SetInterface();/////////////////
            break;

        default:
            Hal_EP0SendStall();
            break;
        }
    }
    else
    {
        Hal_EP0SendStall();
    }
}

extern void _Set_USB_Device_Desc();

#define USB_HID_INTERFACE_LEN 0x09
#define USB_HID_DESC_LEN 0x09

void new_Set_USB_HIDDesc_Desc()
{
    _wReportLen = USB_HID_DESC_LEN;
    memcpy((uint8_t *)USB_BUFF, (uint8_t *)&new_HID_INTERFACE_DESC[USB_HID_INTERFACE_LEN], USB_HID_DESC_LEN);
    if (_wDescLen > _wReportLen)
    {
        _wDescLen = _wReportLen;
    }
    _wDescLen = _wReportLen;
}


// extern void patch_Set_USB_Device_Desc();
void new_patch_Set_USB_Device_Desc(void)
{
    if (_wDescLen > 0x12)
    {
        _wDescLen = 0x12;
    }
    if (stUsbAudio.ubDownLoad == TRUE)
    {
        memcpy((uint8_t *)USB_BUFF, (uint8_t *)&cDEVICE_VENDOR_DESC, _wDescLen);
    }
    else
    {
        memcpy((uint8_t *)USB_BUFF, (uint8_t *)(&g_userDeviceDesc), _wDescLen);
        *((uint16_t *)(USB_BUFF+10))=g_pstConfig->USBReg.UsbProductID;

    }
    stConfigDesSize = Get_ConfigDesSize();
}


extern void _Set_USB_HIDReport_Desc();
// extern void patch_Set_USB_HIDReport_Desc();
void new_patch_Set_USB_HIDReport_Desc()
{
    _wReportLen = g_stUsbHidDesc.usLen;
    memcpy((uint8_t *)USB_BUFF, g_stUsbHidDesc.ucAddr, g_stUsbHidDesc.usLen);

    if (g_pstConfig->FuncCfg.SupportUsbKeyboard) //((stUsbAudio.eUsbMode == USB_DONGLE)||(stUsbAudio.eUsbMode == USB_DONGLE_DSP))
    {
        _wReportLen += USB_KEYBOARD_REPORT_SIZE;
        memcpy((uint8_t *)USB_BUFF + g_stUsbHidDesc.usLen, (uint8_t *)KEYBOARD_REPORT_DESC, USB_KEYBOARD_REPORT_SIZE);
    }

    if (_wDescLen > _wReportLen)
    {
        _wDescLen = _wReportLen;
    }
    _wDescLen = _wReportLen;
}
//AUIDO_SAMPLE_FREQ , the asme array in rom
const uint8_t AUIDO_SAMPLE_FREQ[] =
{
    0x40, 0x1f, 0x00, //8K
    0x11, 0x2b, 0x00, //11.025K
    0xe0, 0x2e, 0x00, //12K
    0x80, 0x3e, 0x00, //16K
    0x09, 0x56, 0x00,  //22.025K
    0xc0, 0x5d, 0x00, //24K
    0x00, 0x7d, 0x00, //32K
    0x44, 0xac, 0x00, //44.1K
    0x80, 0xbb, 0x00, //48K
    0x00, 0x77, 0x01, //96K
};

const uint8_t new_AUIDO_SAMPLE_FREQ[] =
{
    0x40, 0x1f, 0x00, //8K
    0x11, 0x2b, 0x00, //11.025K
    0xe0, 0x2e, 0x00, //12K
    0x80, 0x3e, 0x00, //16K
    0x09, 0x56, 0x00,  //22.025K
    0xc0, 0x5d, 0x00, //24K
    0x00, 0x7d, 0x00, //32K
    0x44, 0xac, 0x00, //44.1K
    0x80, 0xbb, 0x00, //48K
    0x00, 0x77, 0x01, //96K
    0x00, 0xee, 0x02, //192K
};

const uint32_t AUDIO_MAXPACKSIZE[] = {
    8,11,12,16,22,24,32,44,48,96,192
};

extern void _Set_USB_Config_Desc();
// extern void patch_Set_USB_Config_Desc();

usb_config_desc_t g_stUsbConfigDesc = {0, 0, 0};

void USB_Config_Desc_Set(uint8_t* ucAddr, uint16_t usLen)
{
    g_stUsbConfigDesc.ucAddr = ucAddr;
    g_stUsbConfigDesc.usLen = usLen;
    g_stUsbConfigDesc.ucFlag = TRUE;
}

void new_patch_Set_USB_Config_Desc()
{
    uint8_t ucFreqNum;
    uint16_t usDescLen = 0;
    uint16_t i = 0;
    uint16_t k = 0;
    uint8_t  u8InterfaceNum = 2;
    uint16_t u16tmp;
    uint16_t MaxSampleFreq = 48;

    if (stUsbAudio.ubDownLoad == FALSE)
    {
        if (g_stUsbConfigDesc.ucFlag)
        {
            for (i = 0; i < g_stUsbConfigDesc.usLen; i++)
            {
                EP0_CMD_BUF(i) = g_stUsbConfigDesc.ucAddr[i];
            }
            usDescLen += g_stUsbConfigDesc.usLen;
        }
        else
        {
            for (i = 0; i < stConfigDesSize.u8HeadLength; i++)
            {
                EP0_CMD_BUF(i) = AUDIO_HEADSET_CONFIG_DESC[i];
                if (stUsbAudio.stUsbOTP.u8MaxPower != 0)
                {
                    EP0_CMD_BUF(8) = stUsbAudio.stUsbOTP.u8MaxPower;
                }
            }
            usDescLen += stConfigDesSize.u8HeadLength;

            if ((stUsbAudio.eUsbMode == USB_DONGLE_DSP)
                    || (stUsbAudio.eUsbMode == USB_DONGLE))
            {
                for (i = 0; i < stConfigDesSize.u8ACLength; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_CTRL_DONGLE_DESC[i];
                }
                EP0_CMD_BUF(usDescLen + 14) = stConfigDesSize.u8ACLength - 9;//TotalLength(9 + 5 = 14)
                if(USB_IN_CHANNEL == 2)
                {
                    EP0_CMD_BUF(usDescLen + 25) = 0x02;//2 channel(9 + 9 + 7 = 25)
                    EP0_CMD_BUF(usDescLen + 26) = 0x03;//stereo (9 + 9 + 8 = 26)
                }
            }
            else if (stUsbAudio.eUsbMode == USB_TYPEC_HEADPHONE)
            {
                for (i = 0; i < stConfigDesSize.u8ACLength; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_CTRL_HEADPHONE_DESC[i];
                }
            }
            else if (stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)
            {
                for (i = 0; i < stConfigDesSize.u8ACLength; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_CTRL_HEADSET_DESC[i];
                }
                EP0_CMD_BUF(usDescLen + 14) = stConfigDesSize.u8ACLength - 9;//TotalLength(9 + 5 = 14)
                if(USB_IN_CHANNEL == 2)
                {
                    EP0_CMD_BUF(usDescLen + 26) = 0x02;//2 channel (9 + 10 + 7 = 26)
                    EP0_CMD_BUF(usDescLen + 27) = 0x03;//stereo (9 + 10 + 8 = 27)
                }
            }

            usDescLen += stConfigDesSize.u8ACLength;
            if ((stUsbAudio.eUsbMode == USB_TYPEC_HEADSET ) ||
                    (stUsbAudio.eUsbMode == USB_DONGLE ) ||
                    (stUsbAudio.eUsbMode == USB_DONGLE_DSP ) ||
                    (stUsbAudio.eUsbMode == USB_TYPEC_TO_3P5 ))
            {
                // for (i=0; i<stConfigDesSize.u8MicroPhoneLength; i++)
                // {
                //  EP0_CMD_BUF(usDescLen+i) = AUDIO_MICROPHONE_INTERFACE_DESC[i];
                // }
                //    if(stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)
                //    {
                //     EP0_CMD_BUF(usDescLen+29) = 1;
                //    }
                //    else if((stUsbAudio.eUsbMode == USB_DONGLE)
                //     ||(stUsbAudio.eUsbMode == USB_DONGLE_DSP))
                //    {
                //     EP0_CMD_BUF(usDescLen+29) = 2;
                //    }
                // usDescLen += stConfigDesSize.u8MicroPhoneLength;
                // u8InterfaceNum++;

                ucFreqNum = 0;
                u16tmp = g_pstConfig->USBReg.InFreqEnCtrl;
                while (u16tmp)
                {
                    if (u16tmp & 0x0001)
                    {
                        ucFreqNum++;
                    }
                    u16tmp >>= 1;
                }

                for (i = 0; i < stConfigDesSize.u8MicroPhoneLength; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_MICROPHONE_INTERFACE_DESC[i];
                }
                usDescLen += stConfigDesSize.u8MicroPhoneLength;

#if (USB_IN_SAMPLE_DEPTH & USB_SMP_16b) 
                for (i = 0; i < stConfigDesSize.u8MicroPhoneLength_1; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_MICROPHONE_INTERFACE_DESC_1[i];
                }
                /*AlternateSetting----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 3) = 0x01; //AlternateSetting:1
                /*MIC channel nums----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 4) = USB_IN_CHANNEL; 
                /*sample depth--------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 5) = 0x02; //2byte 
                EP0_CMD_BUF(usDescLen + 9 + 7 + 6) = 0x10; //16bit
                /*config sample rate----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 0) = 8 + ucFreqNum * 3;  //length
                EP0_CMD_BUF(usDescLen + 9 + 7 + 7) = ucFreqNum; // nums of sample rate
                usDescLen += stConfigDesSize.u8MicroPhoneLength_1;
                u16tmp = g_pstConfig->USBReg.InFreqEnCtrl;
                for (i = 0, k = 0; k < sizeof(new_AUIDO_SAMPLE_FREQ); ){
                    if (u16tmp & 0x0001){
                        EP0_CMD_BUF(usDescLen + i) = new_AUIDO_SAMPLE_FREQ[k];
                        EP0_CMD_BUF(usDescLen + i + 1) = new_AUIDO_SAMPLE_FREQ[k + 1];
                        EP0_CMD_BUF(usDescLen + i + 2) = new_AUIDO_SAMPLE_FREQ[k + 2];
                        i += 3;
                        MaxSampleFreq = AUDIO_MAXPACKSIZE[k/3];
                    }
                    k += 3;
                    u16tmp >>= 1;
                }
                usDescLen += ucFreqNum * 3;

                for (i = 0 ; i < stConfigDesSize.u8MicroPhoneLength_2; i++){
                    EP0_CMD_BUF(usDescLen + i) = AUDIO_MICROPHONE_INTERFACE_DESC_2[i];
                }
                /*max package size----------------------------------------------*/
                {
                    uint16_t usMaxPktSize = MaxSampleFreq * 2 * USB_IN_CHANNEL;
                    EP0_CMD_BUF(usDescLen + 4) = LSB(usMaxPktSize);
                    EP0_CMD_BUF(usDescLen + 5) = MSB(usMaxPktSize);
                }
                usDescLen += stConfigDesSize.u8MicroPhoneLength_2;
#endif
                
#if (USB_IN_SAMPLE_DEPTH & USB_SMP_24b) 
                for (i = 0; i < stConfigDesSize.u8MicroPhoneLength_1; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_MICROPHONE_INTERFACE_DESC_1[i];
                }
                /*AlternateSetting----------------------------------------------*/
                #if (USB_IN_SAMPLE_DEPTH == USB_SMP_24b) 
                    EP0_CMD_BUF(usDescLen + 3) = 0x01; //AlternateSetting:1
                #else
                    EP0_CMD_BUF(usDescLen + 3) = 0x02; //AlternateSetting:2
                #endif
                /*MIC channel nums----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 4) = USB_IN_CHANNEL; 
                /*sample depth--------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 5) = 0x03; //3byte 
                EP0_CMD_BUF(usDescLen + 9 + 7 + 6) = 0x18; //24bit
                /*config sample rate----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 0) = 8 + ucFreqNum * 3;  //length
                EP0_CMD_BUF(usDescLen + 9 + 7 + 7) = ucFreqNum; // nums of sample rate
                usDescLen += stConfigDesSize.u8MicroPhoneLength_1;
                u16tmp = g_pstConfig->USBReg.InFreqEnCtrl;
                for (i = 0, k = 0; k < sizeof(new_AUIDO_SAMPLE_FREQ); ){
                    if (u16tmp & 0x0001){
                        EP0_CMD_BUF(usDescLen + i) = new_AUIDO_SAMPLE_FREQ[k];
                        EP0_CMD_BUF(usDescLen + i + 1) = new_AUIDO_SAMPLE_FREQ[k + 1];
                        EP0_CMD_BUF(usDescLen + i + 2) = new_AUIDO_SAMPLE_FREQ[k + 2];
                        i += 3;
                        MaxSampleFreq = AUDIO_MAXPACKSIZE[k/3];
                    }
                    k += 3;
                    u16tmp >>= 1;
                }
                usDescLen += ucFreqNum * 3;

                for (i = 0 ; i < stConfigDesSize.u8MicroPhoneLength_2; i++){
                    EP0_CMD_BUF(usDescLen + i) = AUDIO_MICROPHONE_INTERFACE_DESC_2[i];
                }
                /*max package size----------------------------------------------*/
                {
                    uint16_t usMaxPktSize = MaxSampleFreq * 3 * USB_IN_CHANNEL;
                    EP0_CMD_BUF(usDescLen + 4) = LSB(usMaxPktSize);
                    EP0_CMD_BUF(usDescLen + 5) = MSB(usMaxPktSize);
                }
                usDescLen += stConfigDesSize.u8MicroPhoneLength_2;
#endif
                u8InterfaceNum++;
            }
            if ((stUsbAudio.eUsbMode == USB_TYPEC_HEADPHONE ) ||
                    (stUsbAudio.eUsbMode == USB_TYPEC_HEADSET ) ||
                    (stUsbAudio.eUsbMode == USB_TYPEC_TO_3P5 ))
            {
                // memcpy((USB_BUFF +usDescLen),AUDIO_SPEAK_INTERFACE_DESC,stConfigDesSize.u8SpeakLength);
                // usDescLen += stConfigDesSize.u8SpeakLength;
                // u8InterfaceNum++;

                ucFreqNum = 0;
                u16tmp = g_pstConfig->USBReg.OutFreqEnCtrl;
                while (u16tmp)
                {
                    if (u16tmp & 0x0001)
                    {
                        ucFreqNum++;
                    }
                    u16tmp >>= 1;
                }

                for (i = 0; i < stConfigDesSize.u8SpeakLength_1; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_SPEAK_INTERFACE_DESC_1[i];
                }
                usDescLen += stConfigDesSize.u8SpeakLength_1;

#if (USB_OUT_SAMPLE_DEPTH & USB_SMP_16b)
                for (i = 0; i < stConfigDesSize.u8SpeakLength_2; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_SPEAK_INTERFACE_DESC_2[i];
                }
                /*AlternateSetting----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 3) = 0x01; //AlternateSetting:1
                /*sample depth--------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 5) = 0x02; //2byte 
                EP0_CMD_BUF(usDescLen + 9 + 7 + 6) = 0x10; //16bit
                /*config sample rate----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 0) = 8 + ucFreqNum * 3;  //length
                EP0_CMD_BUF(usDescLen + 9 + 7 + 7) = ucFreqNum; // nums of sample rate
                usDescLen += stConfigDesSize.u8SpeakLength_2;
                u16tmp = g_pstConfig->USBReg.OutFreqEnCtrl;
                for (i = 0, k = 0; k < sizeof(AUIDO_SAMPLE_FREQ); ){
                    if (u16tmp & 0x0001){
                        EP0_CMD_BUF(usDescLen + i) = AUIDO_SAMPLE_FREQ[k];
                        EP0_CMD_BUF(usDescLen + i + 1) = AUIDO_SAMPLE_FREQ[k + 1];
                        EP0_CMD_BUF(usDescLen + i + 2) = AUIDO_SAMPLE_FREQ[k + 2];
                        i += 3;
                        MaxSampleFreq = AUDIO_MAXPACKSIZE[k/3];
                    }
                    k += 3;
                    u16tmp >>= 1;
                }
                usDescLen += ucFreqNum * 3;

                for (i = 0 ; i < stConfigDesSize.u8SpeakLength_3; i++){
                    EP0_CMD_BUF(usDescLen + i) = AUDIO_SPEAK_INTERFACE_DESC_3[i];
                }
                /*bmAttributes -------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 3) = 0x09; //Adaptive, Isochronous
                /*max package size----------------------------------------------*/
                {
                    uint16_t usMaxPktSize = MaxSampleFreq * 2 * 2;//16bit, 2ch
                    EP0_CMD_BUF(usDescLen + 4) = LSB(usMaxPktSize);
                    EP0_CMD_BUF(usDescLen + 5) = MSB(usMaxPktSize);
                }
                usDescLen += stConfigDesSize.u8SpeakLength_3;
#endif
                
#if (USB_OUT_SAMPLE_DEPTH & USB_SMP_24b) 
                for (i = 0; i < stConfigDesSize.u8SpeakLength_2; i++)
                {
                    EP0_CMD_BUF(usDescLen + i) = new_AUDIO_SPEAK_INTERFACE_DESC_2[i];
                }
                /*AlternateSetting----------------------------------------------*/
                #if (USB_OUT_SAMPLE_DEPTH == USB_SMP_24b) 
                    EP0_CMD_BUF(usDescLen + 3) = 0x01; //AlternateSetting:1
                #else
                    EP0_CMD_BUF(usDescLen + 3) = 0x02; //AlternateSetting:2
                #endif
                /*sample depth--------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 5) = 0x03; //2byte 
                EP0_CMD_BUF(usDescLen + 9 + 7 + 6) = 0x18; //16bit
                /*config sample rate----------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 9 + 7 + 0) = 8 + ucFreqNum * 3;  //length
                EP0_CMD_BUF(usDescLen + 9 + 7 + 7) = ucFreqNum; // nums of sample rate
                usDescLen += stConfigDesSize.u8SpeakLength_2;
                u16tmp = g_pstConfig->USBReg.OutFreqEnCtrl;
                for (i = 0, k = 0; k < sizeof(AUIDO_SAMPLE_FREQ); ){
                    if (u16tmp & 0x0001){
                        EP0_CMD_BUF(usDescLen + i) = AUIDO_SAMPLE_FREQ[k];
                        EP0_CMD_BUF(usDescLen + i + 1) = AUIDO_SAMPLE_FREQ[k + 1];
                        EP0_CMD_BUF(usDescLen + i + 2) = AUIDO_SAMPLE_FREQ[k + 2];
                        i += 3;
                        MaxSampleFreq = AUDIO_MAXPACKSIZE[k/3];
                    }
                    k += 3;
                    u16tmp >>= 1;
                }
                usDescLen += ucFreqNum * 3;

                for (i = 0 ; i < stConfigDesSize.u8SpeakLength_3; i++){
                    EP0_CMD_BUF(usDescLen + i) = AUDIO_SPEAK_INTERFACE_DESC_3[i];
                }
                /*bmAttributes -------------------------------------------------*/
                EP0_CMD_BUF(usDescLen + 3) = 0x09; //Adaptive, Isochronous
                /*max package size----------------------------------------------*/
                {
                    uint16_t usMaxPktSize = MaxSampleFreq * 3 * 2;//24bit, 2ch
                    EP0_CMD_BUF(usDescLen + 4) = LSB(usMaxPktSize);
                    EP0_CMD_BUF(usDescLen + 5) = MSB(usMaxPktSize);
                }
                usDescLen += stConfigDesSize.u8SpeakLength_3;
#endif
                u8InterfaceNum++;
            }

            for (i = 0; i < stConfigDesSize.u8HIDLength; i++)
            {
                EP0_CMD_BUF(usDescLen + i) = new_HID_INTERFACE_DESC[i];
            }
            if (g_pstConfig->FuncCfg.SupportUsbKeyboard) //((stUsbAudio.eUsbMode == USB_DONGLE)||(stUsbAudio.eUsbMode == USB_DONGLE_DSP))
            {
                EP0_CMD_BUF(usDescLen + HID_REPORT_WITEMLENGTH) = g_stUsbHidDesc.usLen + USB_KEYBOARD_REPORT_SIZE;
            }
            else
            {
                EP0_CMD_BUF(usDescLen + HID_REPORT_WITEMLENGTH) = g_stUsbHidDesc.usLen;
            }

            usDescLen += stConfigDesSize.u8HIDLength;

#ifdef APPLE_LIGHTING_USB_SUPPORT
            /*usb bulk interface*/
            extern const uint8_t USB_BULK_IF_EP_DESC[];
            extern uint8_t g_ucUsbBulkDescLength;
            for (i = 0; i < g_ucUsbBulkDescLength; i++)
            {
                EP0_CMD_BUF(usDescLen + i) = USB_BULK_IF_EP_DESC[i];
            }
            usDescLen += g_ucUsbBulkDescLength;
            u8InterfaceNum++;
#endif
            /*

                    for (i=0; i<stConfigDesSize.u8CDCLength; i++)
                    {
                        EP0_CMD_BUF(usDescLen+i) = CDC_INTERFACE_DESC[i];
                        u8InterfaceNum = u8InterfaceNum +2;
                    }
                    usDescLen += stConfigDesSize.u8CDCLength;*/
            EP0_CMD_BUF(2) = usDescLen & 0xff;
            EP0_CMD_BUF(3) = (usDescLen & 0xff00) >> 8;
            EP0_CMD_BUF(4) = u8InterfaceNum;
        }
    }
    else
    {
        usDescLen = CDC_INTERFACE_DESC[2];
        for (i = 0; i < CDC_INTERFACE_DESC[2]; i++)
        {
            EP0_CMD_BUF(i) = CDC_INTERFACE_DESC[i];
        }

    }
    if (_wDescLen > usDescLen)
    {
        _wDescLen = usDescLen;
    }
    _u8SendNum = 0;
#ifdef APPLE_LIGHTING_USB_SUPPORT
    extern volatile uint8_t g_ucUsbEnumFinish;
    g_ucUsbEnumFinish = 1;
#endif
}

uint8_t _Set_USB_String_Desc()
{
    return pusb_ch9_ftabl->StringDesc();
}

uint8_t new_patch_Set_USB_String_Desc()
{
    switch (LSB(stUsbSetup.wValue))
    {
    case 0x00:
    {
        if (_wDescLen > 4) _wDescLen = 4;
        memcpy((uint8_t *)USB_BUFF, (uint8_t *)cLANG_STR, _wDescLen);
    }
    break;
    case 0x01:
    {
        uint8_t* pstManufact = USB_BUFF;
        if (stUsbAudio.stUsbOTP.stManufact.bLength != 0)
        {
            *pstManufact = stUsbAudio.stUsbOTP.stManufact.bLength;
            *(pstManufact+1) = stUsbAudio.stUsbOTP.stManufact.bDescriptorType;
            if (_wDescLen > *pstManufact) _wDescLen = *pstManufact;
            memcpy(pstManufact+2, stUsbAudio.stUsbOTP.stManufact.pString, _wDescLen - 2);
        }
    }
    break;
    case 0x02:
    {
        uint8_t* pstProduct = USB_BUFF;
        if (stUsbAudio.stUsbOTP.stProduct.bLength != 0)
        {
            *pstProduct = stUsbAudio.stUsbOTP.stProduct.bLength;
            *(pstProduct+1) = stUsbAudio.stUsbOTP.stProduct.bDescriptorType;
            if (_wDescLen > *pstProduct) _wDescLen = *pstProduct;
            memcpy(pstProduct+2, stUsbAudio.stUsbOTP.stProduct.pString, _wDescLen - 2);
        }
    }
    break;
    case 0x03:
    {
        uint8_t* pstSerial = USB_BUFF;
        if (stUsbAudio.stUsbOTP.stSerial.bLength != 0)
        {
            *pstSerial = stUsbAudio.stUsbOTP.stSerial.bLength;
            *(pstSerial+1)= stUsbAudio.stUsbOTP.stSerial.bDescriptorType;
            if (_wDescLen > *pstSerial) _wDescLen = *pstSerial;
            memcpy(pstSerial+2, stUsbAudio.stUsbOTP.stSerial.pString, _wDescLen - 2);
        }
    }
#ifdef APPLE_LIGHTING_USB_SUPPORT
    case 0x04:
    {
        uint8_t* pstSerial = USB_BUFF;
        extern USB_STRING g_stAppleIAP;
        if (g_stAppleIAP.bLength != 0)
        {
            *pstSerial = g_stAppleIAP.bLength;
            *(pstSerial+1)= g_stAppleIAP.bDescriptorType;
            if (_wDescLen > *pstSerial) _wDescLen = *pstSerial;
            memcpy(pstSerial+2, g_stAppleIAP.pString, _wDescLen - 2);
        }
    }
#endif
    break;
    default :
    {
        Hal_EP0SendStall();
        return TRUE;
    }
    }
    return FALSE;
}

extern void CHAP_Send_DevDesc(void);
extern void patch_CHAP_Send_DevDesc(void);
extern void patch_Delay(uint16_t cont);
extern void patch_USB_BusSuspend(void);
extern void patch_USB_BusResume(void);
extern void patch_USB_BusReset(void);
void new_patch_USB_BusReset(void)
{
    rSIE_INTRUSBE   = B_INT_RESET | B_INT_SUSPEND;//enable int

    M_Ep1Index();
    rSIE_INTRINE    = B_INT_EP0 | B_INT_EP1 | B_INT_EP2 | B_INT_EP3;
    rSIE_INTROUTE   = B_INT_EP1 | B_INT_EP2 | B_INT_EP3;;
    rSIE_INCSR      = B_CLRDATATOG_EP1IN | B_FLUSHFIFO_EP1IN;
    rSIE_OUTCSR     = B_CLRDATATOG_EP1OUT | B_FLUSHFIFO_EP1OUT;
    rSIE_OUTCSRH    = B_Iso_EPOut;//EP1 OUTÎªÍ¬²½´«Êä
    M_Ep2Index();
    rSIE_INCSR      = B_CLRDATATOG_EP1IN | B_FLUSHFIFO_EP1IN;
    rSIE_OUTCSR     = B_CLRDATATOG_EP1OUT | B_FLUSHFIFO_EP1OUT;
    M_Ep3Index();
    rSIE_INCSR      = B_CLRDATATOG_EP1IN | B_FLUSHFIFO_EP1IN;
    rSIE_OUTCSR     = B_CLRDATATOG_EP1OUT | B_FLUSHFIFO_EP1OUT;
    M_Ep0Index();

    stUsbDev.dwValue = 0;
    stUsbDev.STATUS.RemoteWake = 1;

#if 0
    stUsbDev.STATUS.EP3Status = REV_CMD;
    gwSecCnt = 0x00;
#endif
}

extern void patch_USB_EP0Service(void);
extern void patch_Hal_EP0SendStall(void);
extern void patch_CHP9_GetStatus(void);


extern void patch_CHP9_ClearFeature(void);



extern void patch_CHP9_ClearFeature(void);
extern void patch_CHP9_SetFeature(void);


extern void patch_CHP9_SetAddress(void);
//*******************************************************************
//
//
//
//*******************************************************************
void CHP9_GetDesc(void)
{
    return pusb_ch9_ftabl->GetDesc();
}
// extern void patch_CHP9_GetDesc(void);
extern uint8_t standby_enable;
void new_patch_CHP9_GetDesc(void)
{
    uint8_t    bError = FALSE;
//LOG_INFO("CHP9_GetDesc s");
    _wDescLen = stUsbSetup.wLength;
 // LSB(stUsbSetup.wLength)|(MSB(stUsbSetup.wLength)&0xff00); 
 
    M_Ep0RxReady();

    switch(MSB(stUsbSetup.wValue))
    {
        case USB_DEVICE_DESC_TYPE:
        {LOG_INFO("1 s");
            _Set_USB_Device_Desc();
        }
        break;

        case USB_CONFIG_DESC_TYPE:
        {LOG_INFO("2 s");
            _Set_USB_Config_Desc();
        }
        break;

        case USB_STRING_DESC_TYPE://
        {LOG_INFO("3 s");
            bError = _Set_USB_String_Desc();
        }
        break;

        case USB_QUALIFIER_DESC_TYPE:
        {LOG_INFO("4 s");
            Hal_EP0SendStall();
            bError = TRUE;
        }
        break;

        case USB_OTHERSPEED_DESC_TYPE:
        {LOG_INFO("5 s");
            Hal_EP0SendStall();
            bError = TRUE;
        }
        break;
        case USB_HID_DESC_TYPE:
        {
            new_Set_USB_HIDDesc_Desc();
        }
        break;
        case USB_HID_REPORT_TYPE:
        {LOG_INFO("6 s");
            _Set_USB_HIDReport_Desc();
        }
        break;
        default:
        {LOG_INFO("7 s");
            Hal_EP0SendStall();
            bError = TRUE;
        }
        break;

    }
        stUsbDev.STATUS.EP0Status = EP0_TX;
        USB_EP0_LOG("[CHP9_GetDesc]EP0 TX");
        if(bError == FALSE)
        {
            CHAP_Send_DevDesc();
        }
    if(standby_enable)
    {
        USB_SuspendmEn();
    }
}

extern void patch_CHP9_SetDesc(void);
extern void patch_CHP9_GetConfig(void);
extern void patch_CHP9_SetConfig(void);
extern void patch_CHP9_GetInterface(void);
// extern void patch_CHP9_InterfaceSetting(uint8_t u8InterfaceNum ,uint8_t u8AltSet);
void new_patch_CHP9_InterfaceSetting(uint8_t u8InterfaceNum , uint8_t u8AltSet)
{
    // AUDIO_OUT_IO_BUF_Stop(0x3);
    switch (u8InterfaceNum)
    {
        case 0:
        {

        }
        break;
        case 1:
        {
            switch (u8AltSet)
            {
            case 0:
            {
                u8UsbInSpeakerSts = FALSE;
                if (g_pstConfig->FuncCfg.SupportAppleEarphone)
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status = TRUE;
                }
                else
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status = FALSE;
                    //clear usb buf
                    M_Ep1Index();
                    rSIE_INCSR = (B_FLUSHFIFO_EP1IN | B_CLRDATATOG_EP1IN);
                }
            }
            break;
            case 1:
#if (USB_IN_SAMPLE_DEPTH != USB_SMP_24b) 
            {
                if (stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8PackSize != 2)
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8BufChange |= BIT1;
                }
                u8UsbInSpeakerSts = TRUE;                   //
                stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status = TRUE;
                if ((stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)||(stUsbAudio.eUsbMode == USB_DONGLE))
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8ChannelNum = USB_IN_CHANNEL;
                }
                stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8PackSize = 2;
                Audio_Task();
            }
            break;
            case 2:
#endif
            {
                if (stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8PackSize != 3)
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8BufChange |= BIT1;
                }
                u8UsbInSpeakerSts = TRUE;                   //
                stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status = TRUE;
                if ((stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)||(stUsbAudio.eUsbMode == USB_DONGLE))
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8ChannelNum = USB_IN_CHANNEL;
                }
                stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8PackSize = 3;
                Audio_Task();
            }
            break;
            }
        }
        break;
        case 2:
        {
            switch (u8AltSet)
            {
            case 0:
            {
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status = FALSE;
            }
            break;
            case 1:
#if (USB_OUT_SAMPLE_DEPTH != USB_SMP_24b) 
            {
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status = TRUE;
                if (stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8PackSize != 2)
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8BufChange |= BIT1;
                }
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8ChannelNum = 2;
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8PackSize = 2;
            }
            break;
            case 2:
#endif
            {
                if (stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8PackSize != 3)
                {
                    stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8BufChange |= BIT1;
                }
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status = TRUE;
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8ChannelNum = 2;
                stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8PackSize = 3;
            }
            break;
            }

            swiPackAsrc(stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status);
        }
        break;
        case 3:
        {
            switch (u8AltSet)
            {
            case 0:
            {

            }
            break;
            case 1:
            {

            }
            break;
            }
        }
        break;
    }
}


extern void patch_CHP9_SetInterface(void);
extern void patch_Set_Request();
extern void patch_Hal_EpxSetMaxSize(void);
extern void patch_Hal_EP0NoData(void);
extern void patch_Set_HWConfig(uint32_t u32UsbConfigFlag);
extern void patch_Set_USBBuffer(uint8_t* pu8UsbBuffer, uint16_t u16UsbBufferSize);
extern void patch_Vendor_DownLoad(uint8_t u8VendorMoad);
extern void patch_Hal_USB_SetOTP(USB_OTP stOTP);
extern void patch_Hal_USB_SetAppMode(product_app_index_t eUsbMode);

const usb_ch9_ftable_t new_usb_ch9_patch_ftable =
{
    .ConfigDesc         = new_patch_Set_USB_Config_Desc,
    .HIDReportDesc      = new_patch_Set_USB_HIDReport_Desc,
    .DeviceDesc         = new_patch_Set_USB_Device_Desc,
    .StringDesc         = new_patch_Set_USB_String_Desc,
    .SendDevDesc        = patch_CHAP_Send_DevDesc,
    .Delay              = patch_Delay,
    .BusSuspend         = patch_USB_BusSuspend,
    .BusResume          = patch_USB_BusResume,
    .BusReset           = new_patch_USB_BusReset,
    .EP0Service         = patch_USB_EP0Service,
    .SetupService       = new_patch_CHP9_SetupService,
    .EP0SendStall       = patch_Hal_EP0SendStall,
    .GetStatus          = patch_CHP9_GetStatus,
    .ClearFeature       = patch_CHP9_ClearFeature,
    .SetFeature         = patch_CHP9_SetFeature,
    .SetAddress         = patch_CHP9_SetAddress,
    .GetDesc            = new_patch_CHP9_GetDesc,
    .SetDesc            = patch_CHP9_SetDesc,
    .GetConfig          = patch_CHP9_GetConfig,
    .SetConfig          = patch_CHP9_SetConfig,
    .GetInterface       = patch_CHP9_GetInterface,
    .InterfaceSetting   = new_patch_CHP9_InterfaceSetting,
    .SetInterface       = patch_CHP9_SetInterface,
    .SetRequest         = patch_Set_Request,
    .EpxSetMaxSize      = patch_Hal_EpxSetMaxSize,
    .EP0NoData          = patch_Hal_EP0NoData,
    .HWConfig           = patch_Set_HWConfig,
    .SetBuffer          = patch_Set_USBBuffer,
    .DownLoad           = patch_Vendor_DownLoad,
    .SetOTP             = patch_Hal_USB_SetOTP,
    .SetAppMode         = patch_Hal_USB_SetAppMode,
};

void new_usb_ch9_patch_init(void)
{
    pusb_ch9_ftabl = (usb_ch9_ftable_t *)&new_usb_ch9_patch_ftable;
}
