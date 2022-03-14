/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_hid_app.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_HID_APP_H_
#define USB_HID_APP_H_
#include "usb_com.h"

#define SET 		1
#define NOT_SET 	0

typedef struct {
    uint8_t u8CtrlKeyFlag;
    uint8_t u8ReservedBytes;
    uint8_t u8KeyValue[6];
}st_USB_KeyBoard_Report_t;

void HID_SetReport(void);
void HID_SetIdle(void);
void HID_SetProtocol(void);
void HID_GetIdle(void);
void HID_GetProtocol(void);
void HID_GetReport(void);
void HID_Out(void);
void ID_K_HID_In(uint8_t *pucBuf, uint8_t ucLen);
void ID_T_HID_In(uint8_t *pucBuf, uint8_t ucLen);
void KeyBoard_HID_In(st_USB_KeyBoard_Report_t stKeyBoard);
void Audio_HID_In(uint8_t u8AudioCtl);
void usb_hid_patch_init(void);
void  USB_HIDSend(void);
void USB_HIDBuffInit(void);
void new_usb_hid_patch_init(void);
#endif//USB_HID_APP_H_

