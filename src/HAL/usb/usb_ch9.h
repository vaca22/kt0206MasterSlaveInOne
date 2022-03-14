/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_ch9.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_CH9_H_
#define USB_CH9_H_
#include "arch.h"
#include "co_math.h"
#include "intc.h"
#include "uart.h"
#include "timer.h"
#include "reg_access.h"
#include "Usb_intr.h"
#include "string.h"
#include "usb_com.h"
#include "usb_cdc.h"
#include "usb_audio_app.h"
#include "usb_hid_app.h"
#include "usb_audio_desc.h"
#include "usb_hid_desc.h"
// #include "usb_mass_desc.h"
#include "asrc_dac_fs_ppm.h"

#ifndef DEBUG_MODE_BYPASS_ALGORITHM_BUFFER
//#define DEBUG_MODE_BYPASS_ALGORITHM_BUFFER 
#endif

#define	USB_AUDIO
//#define USB_HID
//#define USB_MASS

#define 	HID_REPORT_WITEMLENGTH 	    (16)
#define 	CONFIG_DESC_SIZE 	        (2)
#define     SWAP(x)   ((((x)&0xFF)<<8)|(((x)>>8)&0xFF))
#define     MSB(x)    (uint8_t)(((x) >> 8) & 0xFF)
#define     LSB(x)    (uint8_t)((x) & 0xFF)

#define 	AUDIO_FIFO		0x00048000
//#define 	USB_BUFF		0X00050000
extern uint8_t * _pu8UsbBuffer;
extern uint8_t * _pu8OutPutbuffer;
#define 	USB_BUFF                          _pu8UsbBuffer
#define 	USB_BUFF_AUDIO_IN                (_pu8UsbBuffer+0x600)
#define 	USB_OUTPUT_BUFF                   _pu8OutPutbuffer
#define 	USB_INPUT_BUFF                   (_pu8UsbBuffer + 0x540)
#define 	EP0_CMD_BUF(x) 			(*(uint8_t *)(USB_BUFF +x))
#define 	EP1_DATA_BUF(x) 			(*(uint8_t *)(USB_BUFF +x))
#define 	EP2_DATA_BUF(x) 			(*(uint8_t *)(USB_BUFF +x))
#define 	EP3_DATA_BUF(x) 			(*(uint8_t *)(USB_BUFF +x))
#define 	EP1_DATA32_BUF_L(x) 			(*(uint8_t *)(USB_BUFF +x))
#define 	EP1_DATA32_BUF_R(x) 			(*(uint8_t *)(USB_BUFF +2048 +x))
#define	EP0_CMD			0
#define	EP0_RX			1
#define	EP0_TX			2
#define	EP0_IDEL		3
#define M_Ep0Index()		 rSIE_INDEX = 0x00
#define M_Ep1Index()		 rSIE_INDEX = 0x01
#define M_Ep2Index()		 rSIE_INDEX = 0x02
#define M_Ep3Index()		 rSIE_INDEX = 0x03
#define M_Ep4Index()		 rSIE_INDEX = 0x04

#define M_SetEpIndex(EpNum)	 rSIE_INDEX = EpNum
#define M_ResetDataTog()	 rSIE_INCSR |= B_CLRDATATOG_EP1IN; rSIE_OUTCSR |= B_CLRDATATOG_EP1OUT
#define M_Ep1IntEn()	 	 rSIE_INTRINE |= B_INT_EP1; rSIE_INTROUTE |= B_INT_EP1
#define M_Ep2IntEn()	 	 rSIE_INTRINE |= B_INT_EP2; rSIE_INTROUTE |= B_INT_EP2
#define M_Ep3IntEn()	 	 rSIE_INTRINE |= B_INT_EP3; rSIE_INTROUTE |= B_INT_EP3
#define M_Ep4IntEn()	 	 rSIE_INTRINE |= B_INT_EP4; rSIE_INTROUTE |= B_INT_EP4
#define M_SetTest_J()		 rSIE_TESTMODE = B_TEST_J
#define M_SetTest_K()	 	 rSIE_TESTMODE = B_TEST_K
#define M_SetTestSE0()	 	 rSIE_TESTMODE = B_TEST_SE0_NAK
#define M_SetTestPKT()	 	 rSIE_TESTMODE = B_TEST_PACKET

#define MAX_SIZE							0xc0
#define USB_DEVICE_DESC_TYPE                0x01
#define USB_CONFIG_DESC_TYPE   		        0x02
#define USB_STRING_DESC_TYPE                0x03
#define USB_INTERFACE_DESC_TYPE             0x04
#define USB_ENDPOINT_DESC_TYPE              0x05
#define USB_QUALIFIER_DESC_TYPE				0x06
#define	USB_OTHERSPEED_DESC_TYPE			0x07
#define USB_POWER_DESC_TYPE                 0x08

#define USB_REQUEST_GET_STATUS              0x00
#define USB_REQUEST_CLEAR_FEATURE           0x01
#define USB_REQUEST_SET_FEATURE             0x03
#define USB_REQUEST_SET_ADDRESS             0x05
#define USB_REQUEST_GET_DESCRIPTOR          0x06
#define USB_REQUEST_SET_DESCRIPTOR          0x07
#define USB_REQUEST_GET_CONFIGURATION       0x08
#define USB_REQUEST_SET_CONFIGURATION       0x09
#define USB_REQUEST_GET_INTERFACE           0x0A
#define USB_REQUEST_SET_INTERFACE           0x0B
#define USB_REQUEST_SYNC_FRAME              0x0C
#define USB_REQUEST_GET_MAXLUN				0xFE
#define USB_REQUEST_BOUL_RESET				0xFF

//HID
#define USB_HID_DESC_TYPE					0x21
#define USB_HID_REPORT_TYPE					0x22

#define USB_CLASS_GET_IDEL					0x02
#define USB_HID_SET_IDEL					0x0a

#define USB_CLASS_GET_PROTOCOL				0x03
#define USB_CLASS_SET_PROTOCOL				0x0b

#define USB_CLASS_GET_REPORT				0x01
#define USB_CLASS_SET_REPORT				0x09
#define USB_HID_CLASS_REPORT				0x02

#define USB_AUDIO_GET_CUR                   0x81
#define USB_AUDIO_GET_MIN                   0x82
#define USB_AUDIO_GET_MAX                   0x83
#define USB_AUDIO_GET_RES                   0x84
#define USB_AUDIO_GET_MEN                  	0x85

#define USB_AUDIO_SET_CUR                   0x01
#define USB_AUDIO_SET_MIN                   0x02
#define USB_AUDIO_SET_MAX                   0x03
#define USB_AUDIO_SET_RES                   0x04
#define USB_AUDIO_SET_MEN                  	0x05

#define USB_HID_GET_REPORT					0x01
#define USB_HID_GET_IDLE					0x02	
#define USB_HID_GET_PROTOCOL				0x03

#define USB_HID_SET_REPORT					0x09
#define USB_HID_SET_IDLE					0x0A
#define USB_HID_SET_PROTOCOL				0x0B

#define USB_CDC_SET_LINE_CODING				0x20
#define USB_CDC_GET_LINE_CODING				0x21
#define USB_CDC_SET_CONCTROL_LINE_STATE		0x22
#define USB_CDC_SEND_BREAK					0x23

#define USB_REQUEST_GET_MAXLUN				0xFE
#define USB_REQUEST_BOUL_RESET				0xFF




#define	DEV_DEFAULT		0
#define DEV_ADDRESS		1
#define	DEV_CONFIG		2

#define     _USB_EP0_	0
#define     _USB_EP1_	1
#define     _USB_EP2_	2
#define     _USB_EP3_	3

#define TEST_MODE		2
#define ENDP_HALT		0
#define REMOTE_WAK		1

#define	TEST_J			1
#define	TEST_K			2
#define	TEST_PKT		4
#define TEST_SE0_NAK	3


#define M_Ep0TxReady()		  	rSIE_INCSR |= B_INPKTRDY_EP0
#define M_Ep0RxReady()		  	rSIE_INCSR |= B_SERVICEDOUTPKTRDY_EP0

#define M_Ep0DataEnd()			rSIE_INCSR |= B_DATAEND_EP0;
#define M_Ep0TxDoneCheck()		while ((rSIE_INCSR & B_INPKTRDY_EP0) != 0)
#define M_EpxCmdModeTxDoneCheck()	while ((rSIE_INCSR & B_INPKTRDY_EP1) != 0)
#define M_EpxRxDoneCheck()			while ((rSIE_OUTCSR & B_OUTPKTRDY) == 0)
#define M_EpxTxCmdModeReady() rSIE_INCSR  |= B_INPKTRDY_EP1
#define M_EpxRxCmdModeReady() rSIE_OUTCSR &= (~B_OUTPKTRDY)

typedef struct
{
    UINT32 u32UsbConfigFlag;
}st_USB_Contrtl_t;


typedef struct _USB_REQUEST
{
	uint8_t	bmRequestType;
	uint8_t	bRequest;
	uint16_t	wValue;
	uint16_t	wIndex;
	uint16_t	wLength;
}USB_REQUEST;

typedef struct _USB_DEVICE_DESC_
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint16_t bcdUSB;
    uint8_t 	bDeviceClass;
    uint8_t 	bDeviceSubClass;
    uint8_t 	bDeviceProtocol;
    uint8_t 	bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t 	iManufacturer;
    uint8_t 	iProduct;
    uint8_t 	iSerialNumber;
    uint8_t 	bNumConfigurations;
}USB_DEVICE_DESCRIPTOR;

typedef struct __STRING_DESC_
{
    uint8_t    bLength;
    uint8_t    bDescriptorType;
    char    bString[253];

}STRING_DESC,*PSTRING_DESC;

typedef struct _INQUIRY_
{
 	uint8_t 	Peripheral_Device_Type;
 	uint8_t 	RMB;
 	uint8_t 	ISO_ECMA_ANSI;
 	uint8_t 	Response_Data_Format;
 	uint8_t 	Additional_length;
 	uint8_t  reserved[3];
 	uint8_t 	Vendor_Information[8];
 	uint8_t 	Product_Identification[16];
 	uint8_t 	Product_Revision[4];
}INQUIRY;

typedef struct _USB_ENDPOINT_DESCRIPTOR
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bEndpointAddress;
    uint8_t 	bmAttributes;
    uint16_t 	wMaxPacketSize;
    uint8_t 	bInterval;
} USB_ENDPOINT_DESCRIPTOR;


typedef struct _USB_CONFIGURATION_DESCRIPTOR
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint16_t 	wTotalLength;
    uint8_t 	bNumInterfaces;
    uint8_t 	bConfigurationValue;
    uint8_t 	iConfiguration;
    uint8_t 	bmAttributes;
    uint8_t 	MaxPower;
} USB_CONFIGURATION_DESCRIPTOR;

typedef struct _USB_INTERFACE_DESCRIPTOR
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bInterfaceNumber;
    uint8_t 	bAlternateSetting;
    uint8_t 	bNumEndpoints;
    uint8_t 	bInterfaceClass;
    uint8_t 	bInterfaceSubClass;
    uint8_t 	bInterfaceProtocol;
    uint8_t 	iInterface;
} USB_INTERFACE_DESCRIPTOR;

typedef struct _USB_STRING_MANUFACT //Ipgoal
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bString[26];
} USB_STRING_MANUFACT;

typedef struct _USB_STRING_PRODUCT //Solid State Disk
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bString[48];
} USB_STRING_PRODUCT;

typedef struct _USB_STRING_SERIAL//0000
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bString[60];
} USB_STRING_SERIAL;

typedef struct _USB_STRING_ID
{
    uint8_t	 bLength;
    uint8_t	 bDescriptorType;
    uint8_t	 bString[2];
} USB_STRING_ID;

typedef struct _USB_POWER_DESCRIPTOR
{
    uint8_t 	bLength;
    uint8_t 	bDescriptorType;
    uint8_t 	bCapabilitiesFlags;
    uint16_t EventNotification;
    uint16_t D1LatencyTime;
    uint16_t D2LatencyTime;
    uint16_t D3LatencyTime;
    uint8_t 	PowerUnit;
    uint16_t D0PowerConsumption;
    uint16_t D1PowerConsumption;
    uint16_t D2PowerConsumption;
} USB_POWER_DESCRIPTOR;

typedef struct _USB_DEVICE_QUALIFIER
{
	uint8_t	bLength;			//length of HS Device Descriptor
	uint8_t	bQualifier; 		//HS Device Qualifier Type
	uint16_t	wVersion;			// USB 2.0 version
	uint8_t	bDeviceClass;		//Device class
	uint8_t	bDeviceSubClasss;	//Device SubClass
	uint8_t	bProtocol;			//Device Protocol Code
	uint8_t	MaxPktSize;			//Maximum Packet SIze for other speed
	uint8_t	bOther_Config;		//Number of Other speed configurations
	uint8_t	Reserved;			//Reserved
}USB_DEVICE_QUALIFIER;


typedef struct _USB_COMMON_DESCRIPTOR
{
    uint8_t bLength;
    uint8_t bDescriptorType;
} USB_COMMON_DESCRIPTOR;


typedef struct _USB_HID_DESCRIPTOR
{
	uint8_t    bLength;
	uint8_t	bDescriptorType;
	uint16_t	bcdHID;
	uint8_t	bCountryCode;
	uint8_t	bNumDescriptors;
	uint8_t	bReportType;
	uint16_t	wItemLength;
}USB_HID_DESCRIPTOR;


typedef struct _USB_INTASSO_DESCRIPTOR
{
    uint8_t  bLength;
    uint8_t  bDescriptorType;
    uint8_t  bFirstInterface;
    uint8_t  bInterfaceCount;
    uint8_t  bFunctionClass;
    uint8_t  bFunctionSubClass;
    uint8_t  bFunctionProtocol;
    uint8_t  iFunction	;
}USB_INTASSO_DESCRIPTOR;


//*******************************************************************
//
//
//
//*******************************************************************
typedef union  _USB_DEVICE_STATUS_
{
	struct DEVICE_STATUS_BITS
	{
		uint8_t	CfgVal 		:1;
		uint8_t	DevState	:2;//default ,addressed ,configed
		uint8_t	AltSet	 	:2;
		uint8_t  InterfaceNum    :2;
		uint8_t	EP0Status		:2;
		uint8_t	RemoteWake	:1;

		uint8_t  Rev0      		:1;
		uint8_t	EP1EdpHaltIN	:1;
		uint8_t	EP1EdpHaltOUT	:1;
		uint8_t	EP1HaltReason	:1;//0 ��USB TESET SET    1��EPX STALL SET
		uint8_t  EP1Status		:3;//rev_cmd.rev_data,send_csw

		uint8_t	EP2EdpHaltIN	:1;
		uint8_t	EP2EdpHaltOUT	:1;
		uint8_t	EP2HaltReason	:1;//0 ��USB TESET SET    1��EPX STALL SET
		uint8_t  EP2Status		:3;//rev_cmd.rev_data,send_csw

		uint8_t	EP3EdpHaltIN	:1;
		uint8_t	EP3EdpHaltOUT	:1;
		uint8_t	EP3HaltReason	:1;//0 ��USB TESET SET    1��EPX STALL SET
		uint8_t  EP3Status		:3;//rev_cmd.rev_data,send_csw

		uint8_t  USBAddrUpate	:1;

		//app define
		uint8_t  ValidCbw		:1;
		uint8_t  ValidCsw		:1;
		uint8_t  CbwResult       :1;
		uint8_t  MSCError		:1;

		uint8_t	CbwDevStatus	:2;//Di,Do,Dn
		uint8_t	CbwHostStatus	:2;//Hi,Ho,HnD

		uint8_t  RxEnd1		:1;
		uint8_t  TxEnd1		:1;
        uint8_t  RxEnd2      :1;
		uint8_t  TxEnd2		:1;
		uint8_t  ReportStatus		:1;
        uint8_t  REV             :7;   
	}STATUS;

	uint32_t	dwValue;
}USB_DEVICE_STATUS;

typedef struct
{
    uint8_t* ucAddr;
    uint16_t usLen;
    uint8_t ucFlag; //0->use internal descript, 1->use external descript
} usb_config_desc_t;

typedef struct
{
    uint8_t* ucAddr;
    uint16_t usLen;
    uint8_t ucFlag; //0->use internal descript, 1->use external descript
} usb_device_desc_t;

extern USB_DEVICE_STATUS	stUsbDev;
void Set_USBBuffer(uint8_t * pu8UsbBuffer,uint16_t u16UsbBufferSize);

void Delay(uint16_t cont);
void USB_BusSuspend(void);
void USB_BusResume(void);
void USB_BusReset(void);
void USB_EP0Service(void);
void CHP9_SetupService(void);
void Hal_EP0SendStall(void);
void CHP9_GetStatus(void);
void CHP9_ClearFeature(void);
void CHP9_SetFeature(void);
void CHP9_SetAddress(void);
void CHP9_GetDesc(void);
void CHP9_SetDesc(void);
void CHP9_GetConfig(void);
void CHP9_SetConfig(void);
void CHP9_GetInterface(void);
void CHP9_SetInterface(void);
void CHAP_SendDevDesc(void);
void Set_Request();
void Set_HWConfig(uint32_t u32UsbConfigFlag);
void Set_OutPutBuffer(uint8_t* pu8OutPutbuffer,uint16_t u16OutPutBufferSize);

void Hal_EpxSetMaxSize(void);
void Hal_EP0NoData(void);
void Vendor_DownLoad(uint8_t u8VendorMoad);
void Hal_USB_SetOTP(USB_OTP stOTP);
void Hal_USB_SetAppMode(product_app_index_t eUsbMode);
void usb_ch9_patch_init(void);

void USB_Config_Desc_Set(uint8_t* ucAddr, uint16_t usLen);

void new_usb_ch9_patch_init(void);

extern USB_REQUEST stUsbSetup;

#endif//USB_CH9_H_

