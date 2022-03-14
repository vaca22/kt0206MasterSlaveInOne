#include "usb_config.h"

#ifndef USB_VENDORID
#define USB_VENDORID 0x31B2
#endif

const USB_DEVICE_DESCRIPTOR g_userDeviceDesc =
{
    0x12,               //          length
    0x01,               // 1.       bDescriptorType
    0x0110,             // 2.-3.    Version 2.0 USB spec Word
    0x00,               // 4.       Class
    0x00,               // 5.       bDeviceSubClass
    0x00,               // 6.       bDeviceProtocol
    0x40,               // 7.       bMaxPacketSize0
    USB_VENDORID,       // 8.-9.    idVendor
    USB_PRODUCTID,      // a.-b.    idProduct
    0x0100,             // c.-d.    bcdDevice
    0x01,               // e.       iManufacturer
    0x02,               // f.       iProduct
    0x03,               // 10.      iSerialNumber
    0x01                // 11.      bNumConfigurations
};


uint8_t tempUsbManufact[60];
uint8_t tempUsbProduct[60];
uint8_t tempUsbSerial[60];
#ifdef APPLE_LIGHTING_USB_SUPPORT
uint8_t tempUsbIAP[40];
#endif
void setUsbUserConfig(USB_OTP *pstOTP)
{
    int index=0;
    while(g_pstConfig->USBReg.UsbManufact[index++]!=0);
    index-=2;
    pstOTP->stManufact.bLength = ((index+1)<<1)+2;
    pstOTP->stManufact.bDescriptorType = 0x03;
    pstOTP->stManufact.pString = tempUsbManufact;
    for(;index>=0;index--)
    {
        tempUsbManufact[(index<<1)+1]=0;
        tempUsbManufact[index<<1]=g_pstConfig->USBReg.UsbManufact[index];
    }

    index=0;
    while(g_pstConfig->USBReg.UsbProduct[index++]!=0);
    index-=2;
    pstOTP->stProduct.bLength = ((index+1)<<1)+2;
    pstOTP->stProduct.bDescriptorType = 0x03;
    pstOTP->stProduct.pString = tempUsbProduct;
    for(;index>=0;index--)
    {
        tempUsbProduct[(index<<1)+1]=0;
        tempUsbProduct[index<<1]=g_pstConfig->USBReg.UsbProduct[index];
    } 

    index=0;
    while(g_pstConfig->USBReg.UsbSerial[index++]!=0);
    index-=2;
    pstOTP->stSerial.bLength = ((index+1)<<1)+2;
    pstOTP->stSerial.bDescriptorType = 0x03;
    pstOTP->stSerial.pString = tempUsbSerial;
    for(;index>=0;index--)
    {
        tempUsbSerial[(index<<1)+1]=0;
        tempUsbSerial[index<<1]=g_pstConfig->USBReg.UsbSerial[index];
    }

#ifdef APPLE_LIGHTING_USB_SUPPORT
    extern const uint8_t g_UsbStringIAP[];
    extern USB_STRING g_stAppleIAP;
    index=0;
    while(g_UsbStringIAP[index++]!=0);
    index-=2;
    g_stAppleIAP.bLength = ((index+1)<<1)+2;
    g_stAppleIAP.bDescriptorType = 0x03;
    g_stAppleIAP.pString = tempUsbIAP;
    for(;index>=0;index--)
    {
        tempUsbIAP[(index<<1)+1]=0;
        tempUsbIAP[index<<1]=g_UsbStringIAP[index];
    }
#endif
    // pstOTP->u16VendorID =  g_pstConfig->USBReg.UsbVendorID;
    // pstOTP->u16ProductID =  g_pstConfig->USBReg.UsbProductID;
    pstOTP->u8MaxPower =  g_pstConfig->USBReg.ucUsbMaxPower;
}
