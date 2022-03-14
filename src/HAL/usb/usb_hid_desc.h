/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_hid_desc.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_HID_DESC_H_
#define USB_HID_DESC_H_

#include <stdint.h>

#define USB_KEYBOARD_REPORT_SIZE     65

typedef struct
{
	uint8_t* ucAddr;
	uint16_t usLen;
} usb_hid_desc_t;

extern usb_hid_desc_t g_stUsbHidDesc;

extern void USB_HID_Report_Desc_Init(void);
extern void USB_HID_Report_Desc_Set(uint8_t* ucAddr, uint16_t usLen);


#endif//USB_HID_DESC_H_

