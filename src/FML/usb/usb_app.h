#ifndef _USB_APP_H_
#define _USB_APP_H_
#include "usb_com.h"
#include "usb_audio_app.h"
#include "usb_hid_app.h"
#include "usb_ch9.h"
#include "ke_config.h"
#include "usb_audio_sdk.h"

typedef enum
{
	USB_CALLBACK_AUDIO_IN,
	USB_CALLBACK_AUDIO_OUT,
	USB_CALLBACK_HID_OUT,
	USB_CALLBACK_PATH_NUM,
}USB_CALLBACK_PATH;
USB_RETURN Usb_Init(uint8_t* pu8UsbBuffer,uint16_t u16UsbBufferSize);
USB_RETURN Usb_Open(uint8_t u8UsbDevIndex );
USB_RETURN Usb_Close(uint8_t u8UsbDevIndex);
USB_RETURN Usb_DeInit();
USB_RETURN Usb_Set_HWConfing(uint8_t u8UsbDevIndex, UINT32 u32UsbConfigFlag);
USB_RETURN Usb_Get_USB_Attr(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex,void* param,uint8_t u8Len);
USB_RETURN Usb_Get_USB_Buff(uint8_t u8UsbDevIndex, USB_CALLBACK_PATH eIndex ,void* param,uint8_t u8ParamNum,uint8_t u8Len);
USB_RETURN USB_SetOTP(USB_OTP stOTP);
USB_RETURN USB_SendHidReport(uint8_t u8UsbDevIndex, eReportId  u8HidNum  ,void* param,uint8_t u8Len);
uint16_t USB_KeyBoardContinueSend(uint8_t* ucBuf, uint16_t usLen);
USB_RETURN USB_SetAppMode(product_app_index_t eUsbMode);
USB_RETURN USB_SetVendorMode(uint8_t u8VendorMode);
void new_usb_app_patch_init(void);
extern void USB_PowerOn_Init(uint8_t mode);

#endif /* _USB_APP_H_ */
