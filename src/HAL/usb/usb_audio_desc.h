/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_desc.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_AUDIO_DESC_H_
#define USB_AUDIO_DESC_H_

//#define MIC_HEADPHONE
// #define HEADPHONE

// #define   MIC_HEADPHONE_LEN	0xd7
// #define   HEADPHONE_LEN	0xea
typedef struct 
{
    uint8_t  u8HeadLength;
    uint8_t  u8ACLength;
    uint8_t  u8MicroPhoneLength;
    uint8_t  u8MicroPhoneLength_1;
    uint8_t  u8MicroPhoneLength_2;
    uint8_t  u8SpeakLength;
    uint8_t  u8SpeakLength_1;
    uint8_t  u8SpeakLength_2;
    uint8_t  u8SpeakLength_3;
    uint8_t  u8HIDLength;
}USB_CONFIG_DES_SIZE;
USB_CONFIG_DES_SIZE Get_ConfigDesSize(void );
USB_CONFIG_DES_SIZE new_patch_Get_ConfigDesSize(void);
#endif//USB_AUDIO_DESC_H_
