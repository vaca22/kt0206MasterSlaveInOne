#ifndef _USB_COM_H_
#define _USB_COM_H_

#include "stdint.h"

#define     USB_DEV_NUM_MAX		        (1)
#ifdef DEBUG_EP0
#define USB_EP0_LOG(str)   LOG_INFO(str)
#else
#define USB_EP0_LOG(str)
#endif
typedef	void(*Interface_Callback)(uint8_t u8InterfaceNum,uint8_t u8SettingNum);
typedef	void(*USB_Callback)(void);
typedef enum
{
    USB_REQUEST_HOST_TO_DEVICE,
    USB_REQUEST_DEVICE_TO_HOST,
    USB_REQUEST_FLOW_NUM,
}eUSB_RequestFlow_Type;

typedef enum
{
    USB_REQUEST_STANDARD,
    USB_REQUEST_GENRE,
    USB_REQUEST_MANUFACTURER,
    USB_REQUEST_RESERVE,
    USB_REQUEST_TYPE_NUM,
}eUSB_Request_Type;

typedef enum
{
    USB_REQUEST_DEVICE,
    USB_REQUEST_INTERFACE,
    USB_REQUEST_ENDPOINT,
    USB_REQUEST_OTHER,
    USB_REQUEST_ACCEPTER_NUM,
}eUSB_RequestAccepter;

typedef enum
{
    USB_CONFIG_HEADPHONE,
    USB_CONFIG_KEYBOARD,
    USB_CONFIG_MASS,
    USB_CONFIG_MAX,
}eUsbConfigType;

typedef enum
{
    RETURN_FAIL,
    RETURN_OK,
    RETURN_INPUT_ERR,
    RETURN_NO_INIT,
    RETURN_NOT_SUPPORT,
    RETURN_CONFIG_ERR,
    RETURN_TIME_OUT,  
}USB_RETURN;
typedef enum
{
    AUDIO_TYPE_HIGHT_3BYTE,
    AUDIO_TYPE_LOW_3BYTE,
}AUDIO_TYPE;
typedef enum
{
    REPORT_AUDIO_ID = 1,
    REPORT_KEYBOARD_ID = 2,
    REPORT_K_ID = 0x4B,
    REPORT_T_ID = 0x54,
    REPORT_ID_MAX = REPORT_T_ID,
}eReportId;

typedef struct _USB_STRING //Ipgoal
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t* 	pString;
} USB_STRING;

typedef struct _USB_OTP //Ipgoal
{
	USB_STRING 	stManufact;
	USB_STRING 	stProduct;
	USB_STRING 	stSerial;
	USB_STRING 	stStringID;
    uint16_t    u16VendorID;				// 8.-9.  idVendor
    uint16_t    u16ProductID;  				// a.-b.  idProduct
    uint8_t 	u8MaxPower;
} USB_OTP;
#endif /* _USB_COM_H_ */
