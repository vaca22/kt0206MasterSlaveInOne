#include "usb_hid_desc.h"
#include "hal_config.h"

#define USB_AUDIO_REPORT_SIZE           (67 + 24 + 16)
extern const uint8_t AUDIO_REPORT_DESC[USB_AUDIO_REPORT_SIZE];
usb_hid_desc_t g_stUsbHidDesc;

#if SUPPORT_PREVIOUS_NEXT_FOR_PC

#define new_USB_AUDIO_REPORT_SIZE           (35+35+4)
const uint8_t new_AUDIO_REPORT_DESC[new_USB_AUDIO_REPORT_SIZE] =
{
	 0x05 ,0x0C /* USAGE_PAGE (CONSUMER DEVICE) */
	,0x09 ,0x01 /* USAGE (CONSUMER CONTROL) */
	,0xA1 ,0x01 /* COLLECTION (Application) */
	,0x85 ,0x01 /*REPORT ID(1)*/
	,0x15 ,0x00 /*LOGICAL_MINIMUM (0)*/
	,0x25 ,0x01 /*LOGICAL_MAXIMUM (1)*/
	,0x75 ,0x01 /*REPORT SIZE(1)*/
	,0x95 ,0x02 /*REPORT CONT(2)*/
	,0x09 ,0xE9 /* USAGE(Volume Increment) */
	,0x09 ,0xEA /* USAGE(Volume Decrement) */
	,0x81 ,0x02 /* INPUT (Data,Value,Abs,Bit Field) */
	,0x95 ,0x04 //Report Count (2)
	,0x09 ,0xCD /* USAGE(Play/Pause) */
	,0x09 ,0xCF /* Usage (0x00CF)*/
	,0x09 ,0xB6
	,0x09 ,0xB5
	,0x81 ,0x02 /* INPUT (Data,Value,Abs,Bit Field) */
	,0x95 ,0x02 //Report Count (4)
	,0x81 ,0x01 /* INPUT (Data,Value,Abs,Bit Field) */

	,0x06 ,0x01 ,0xFF //Usage Page (Vendor-defined 0xFF01)
    ,0x85 ,0x4B //Report Id (4B)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)
    ,0x85 ,0x54 //Report Id (54)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)

	,0xC0  		/* END_COLLECTION */
};

#else

#define new_USB_AUDIO_REPORT_SIZE           (35+35)
const uint8_t new_AUDIO_REPORT_DESC[new_USB_AUDIO_REPORT_SIZE] =
{
	 0x05 ,0x0C /* USAGE_PAGE (CONSUMER DEVICE) */
	,0x09 ,0x01 /* USAGE (CONSUMER CONTROL) */
	,0xA1 ,0x01 /* COLLECTION (Application) */
	,0x85 ,0x01 /*REPORT ID(1)*/
	,0x15 ,0x00 /*LOGICAL_MINIMUM (0)*/
	,0x25 ,0x01 /*LOGICAL_MAXIMUM (1)*/
	,0x75 ,0x01 /*REPORT SIZE(1)*/
	,0x95 ,0x02 /*REPORT CONT(2)*/
	,0x09 ,0xE9 /* USAGE(Volume Increment) */
	,0x09 ,0xEA /* USAGE(Volume Decrement) */
	,0x81 ,0x02 /* INPUT (Data,Value,Abs,Bit Field) */
	,0x95 ,0x02 //Report Count (2)
	,0x09 ,0xCD /* USAGE(Play/Pause) */
	,0x09 ,0xCF /* Usage (0x00CF)*/
	,0x81 ,0x02 /* INPUT (Data,Value,Abs,Bit Field) */
	,0x95 ,0x04 //Report Count (4)
	,0x81 ,0x01 /* INPUT (Data,Value,Abs,Bit Field) */

	,0x06 ,0x01 ,0xFF //Usage Page (Vendor-defined 0xFF01)
    ,0x85 ,0x4B //Report Id (4B)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)
    ,0x85 ,0x54 //Report Id (54)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)

	,0xC0  		/* END_COLLECTION */
};
#endif

void USB_HID_Report_Desc_Init(void)
{
	g_stUsbHidDesc.ucAddr = (uint8_t *)new_AUDIO_REPORT_DESC;
	g_stUsbHidDesc.usLen = new_USB_AUDIO_REPORT_SIZE;
}

void USB_HID_Report_Desc_Set(uint8_t* ucAddr, uint16_t usLen)
{
	g_stUsbHidDesc.ucAddr = ucAddr;
	g_stUsbHidDesc.usLen = usLen;
}
