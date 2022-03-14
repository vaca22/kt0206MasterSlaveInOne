/*
 * modify usb device and configration description test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

typedef struct _USB_DEVICE_DESC_
{
    uint8_t     bLength;
    uint8_t     bDescriptorType;
    uint16_t bcdUSB;
    uint8_t     bDeviceClass;
    uint8_t     bDeviceSubClass;
    uint8_t     bDeviceProtocol;
    uint8_t     bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t     iManufacturer;
    uint8_t     iProduct;
    uint8_t     iSerialNumber;
    uint8_t     bNumConfigurations;
}USB_DEVICE_DESCRIPTOR;

const USB_DEVICE_DESCRIPTOR g_ucTestDeviceDesc =
{
    0x12,        //       length
    0x01,        // 1.    bDescriptorType
    0x0100,      // 2.-3. Version 2.0 USB spec Word
    0x02,        // 4.    Class
    0x00,        // 5.    bDeviceSubClass
    0x00,        // 6.    bDeviceProtocol
    0x40,        // 7.    bMaxPacketSize0
    0x8888,      // 8.-9.  idVendor
    0xCDC0,      // a.-b.  idProduct
    0x0000,      // c.-d.  bcdDevice
    0x01,        // e.    iManufacturer
    0x02,        // f.    iProduct
    0x03,        // 10.    iSerialNumber
    0x01         // 11.    bNumConfigurations
};

const uint8_t g_ucTestCfgDesc[] =
{
    0x09,    //Length
    0x02,    //DescriptorType : ConfigDescriptor
    0x43,0x00, //TotalLength:0x00be
    0x02,      //NumInterfaces:4
    0x01,    //ConfigurationValue
    0x00,    //Configuration String
    0xa0,    //Attributes:Bus Power
    0x32,     //MaxPower = 0xfa*2ma
    /* 09 byte*/
    //HID INTERFACE(Interface 3, Alternate Setting 0)
    0X09,   //Length of standard interface descriptor
    0x04,                               //Standard Interface Type
    0x00,                               //No of Interface
    0x00,                               //Alternate Setting Selector
    0x01,                               //No of Endpoints
    0x02,                               //Interface Class
    0x02,                       //Interface Sub Class
    0x01,                           //Interface Protocol
    0x00,

    0x05,                               //Standard Endpoint Type
    0x24,                               //Set Int endpoint to 2 for ATAPI mode
    0x00,                               //Endpoint Characteristic
    0x09,                       //Endpoint Max Packet Size
    0x01,

    0x05,                               //Standard Endpoint Type
    0x24,                               //Set Int endpoint to 2 for ATAPI mode
    0x01,                               //Endpoint Characteristic
    0x00,                       //Endpoint Max Packet Size
    0x01,

    0x04,                               //Standard Interface Type
    0x24,                               //No of Interface
    0x02,                               //Alternate Setting Selector
    0x0F,                               //No of Endpoints

    0x05,                               //Standard Endpoint Type
    0x24,                               //Set Int endpoint to 2 for ATAPI mode
    0x06,                               //Endpoint Characteristic
    0x00,                       //Endpoint Max Packet Size
    0x01,
    /* 09 byte*/
    /* Endpoint - HID ENDPOINT 2 OUT Descriptor */
    0x07,   //Length of Standard Endpoint Descriptor
    0x05,                               //Standard Endpoint Type
    0x82,                               //Set Int endpoint to 2 for ATAPI mode
    0x03,                               //Endpoint Characteristic
    0x10,                       //Endpoint Max Packet Size
    0x00,
    0x00,
    /* 07 byte*/
    //HID INTERFACE(Interface 3, Alternate Setting 0)
    0X09,   //Length of standard interface descriptor
    0x04,                               //Standard Interface Type
    0x01,                               //No of Interface
    0x00,                               //Alternate Setting Selector
    0x02,                               //No of Endpoints
    0x0a,                               //Interface Class
    0x00,                       //Interface Sub Class
    0x00,                           //Interface Protocol
    0x04,

    /* Endpoint - HID ENDPOINT 2 OUT Descriptor */
    0x07,   //Length of Standard Endpoint Descriptor
    0x05,                               //Standard Endpoint Type
    0x83,                               //Set Int endpoint to 2 for ATAPI mode
    0x02,                               //Endpoint Characteristic
    0x40,                       //Endpoint Max Packet Size
    0x00,
    0x00,

    /* Endpoint - HID ENDPOINT 2 OUT Descriptor */
    0x07,   //Length of Standard Endpoint Descriptor
    0x05,                               //Standard Endpoint Type
    0x03,                               //Set Int endpoint to 2 for ATAPI mode
    0x02,                               //Endpoint Characteristic
    0x40,                       //Endpoint Max Packet Size
    0x00,
    0x00,
    /* 07 byte*/
};

void _user_schedule(void)
{
    // TODO add your own code

}

void _user_init(void)
{
    // TODO add your own code
    api_usb_config_desc_set((uint8_t *)g_ucTestCfgDesc, sizeof(g_ucTestCfgDesc));
}
