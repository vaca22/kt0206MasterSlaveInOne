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
} USB_DEVICE_DESCRIPTOR;

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
    //Configuration descriptor
    0x09,       //Length
    0x02,       //DescriptorType : ConfigDescriptor
    0x43, 0x00, //TotalLength:0x00be
    0x02,       //NumInterfaces:4
    0x01,       //ConfigurationValue
    0x00,       //Configuration String
    0xA0,       //Attributes:Bus Power
    0xFA,       //MaxPower = 0xfa*2ma
    /* 09 byte*/

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x00, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x00, //bNumEndpoints
    0x01, //bInterfaceClass
    0x01, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x03, //iInterface

    //Audio Descriptor
    0x0A, //bLength
    0x24, //bDescriptorType
    0x01, //bDescriptorSubtype
    0x00, //bcdADC
    0x01, 
    0x6E, //wTotalLength
    0x00, 
    0x02, //bInCollection
    0x01, //baInterfaceNr(1)
    0x02, //baInterfaceNr(2)

    //Audio Descriptor
    0x0C, //bLength
    0x24, //bDescriptorType
    0x02, //bDescriptorSubtype = INPUT_TERMINAL
    0x01, //bTerminalID
    0x01, //wTerminalType = USB streaming
    0x01, 
    0x00, //bAssocTerminal
    0x08, //bNrChannels
    0x3F,
    0x00, //wChannelConfig
    0x00, //iChannelNames
    0x00, //iTerminal

    //Audio Descriptor
    0x0C, //bLength
    0x24, //bDescriptorType
    0x02, //bDescriptorSubtype = INPUT_TERMINAL
    0x05, //bTerminalID
    0x01, //wTerminalType = Microphone
    0x02, 
    0x00, //bAssocTerminal
    0x02, //bNrChannels
    0x03,
    0x00, //wChannelConfig
    0x00, //iChannelNames
    0x00, //iTerminal

    //Audio Descriptor
    0x09, //bLength
    0x24, //bDescriptorType
    0x03, //bDescriptorSubtype = OUTPUT_TERMINAL
    0x07, //bTerminalID
    0x01, //wTerminalType = Speaker
    0x03, 
    0x00, //bAssocTerminal
    0x0D, //bSourceID
    0x00, //iTerminal

    //Audio Descriptor
    0x09, //bLength
    0x24, //bDescriptorType
    0x03, //bDescriptorSubtype = OUTPUT_TERMINAL
    0x0B, //bTerminalID
    0x01, //wTerminalType = USB streaming
    0x01, 
    0x00, //bAssocTerminal
    0x11, //bSourceID
    0x00, //iTerminal

    //Audio Descriptor
    0x10, //bLength
    0x24, //bDescriptorType = CS_INTERFACE
    0x06, //bDescriptorSubtype = FEATURE_UNIT
    0x0D, //bUnitID
    0x12, //bSourceID
    0x01, //bControlSize
    0x01, //bmaControls(0)
    0x00, //bmaControls(1)
    0x00, //bmaControls(2)
    0x00, //bmaControls(3)
    0x00, //bmaControls(4)
    0x00, //bmaControls(5)
    0x00, //bmaControls(6)
    0x00, //bmaControls(7)
    0x00, //bmaControls(8)
    0x00, //iFeature

    //Audio Descriptor
    0x0A, //bLength
    0x24, //bDescriptorType = CS_INTERFACE
    0x06, //bDescriptorSubtype = FEATURE_UNIT
    0x10, //bUnitID
    0x05, //bSourceID
    0x01, //bControlSize
    0x01, //bmaControls(0)
    0x00, //bmaControls(1)
    0x00, //bmaControls(2)
    0x00, //iFeature

    //Audio Descriptor
    0x0A, //bLength
    0x24, //bDescriptorType = CS_INTERFACE
    0x06, //bDescriptorSubtype = FEATURE_UNIT
    0x11, //bUnitID
    0x05, //bSourceID
    0x01, //bControlSize
    0x01, //bmaControls(0)
    0x00, //bmaControls(1)
    0x00, //bmaControls(2)
    0x00, //iFeature

    //Audio Descriptor
    0x16, //bLength
    0x24, //bDescriptorType = CS_INTERFACE
    0x04, //bDescriptorSubtype = MIXER_UNIT
    0x12, //bUnitID
    0x02, //bNrInPins
    0x01, //bSourceID
    0x10, //bSourceID
    0x08, //bNrChannels
    0x3F, //wChannelConfig(0)
    0x06, //wChannelConfig(1)
    0x00, //iChannelNames
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //bmControls
    0x00, //iMixer

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x01, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x00, //bNumEndpoints
    0x01, //bInterfaceClass
    0x02, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x04, //iInterface

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x01, //bInterfaceNumber
    0x01, //bAlternateSetting
    0x02, //bNumEndpoints
    0x01, //bInterfaceClass
    0x02, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x00, //iInterface

    //Audio Descriptor
    0x07, //bLength
    0x24, //bDescriptorType
    0x01, //bDescriptorSubtype
    0x01, //bTerminalLink
    0x01, //bDelay
    0x01,
    0x00, //wFormatTag

    //Audio Descriptor
    0x0E, //bLength
    0x24, //bDescriptorType
    0x02, //bDescriptorSubtype
    0x01, //bFormatType
    0x08, //bNrChannels
    0x02, //bSubframeSize
    0x10, //bBitResolution
    0x02, //bSamFreqType
    0x44, //tSamFreq(1)
    0xAC,
    0x00,
    0x80, //tSamFreq(2)
    0xBB,
    0x00,

    //Endpoint descriptor
    0x09, //bLength
    0x05, //bDescriptorType
    0x05, //bEndpointAddress
    0x05, //bmAttributes
    0x20, //wMaxPacketSize
    0x03,
    0x04, //bInterval
    0x00, //bRefresh
    0x85, //bSynchAddress

    //Audio Descriptor
    0x07, //bLength
    0x25, //bDescriptorType
    0x01, //bDescriptorSubtype
    0x01, //bmAttributes
    0x00, //bLockDelayUnits
    0x00, //wLockDelay
    0x00,

    //Endpoint descriptor
    0x09, //bLength
    0x05, //bDescriptorType
    0x85, //bEndpointAddress
    0x01, //bmAttributes
    0x03, //wMaxPacketSize
    0x00,
    0x04, //bInterval
    0x05, //bRefresh
    0x00, //bSynchAddress

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x02, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x00, //bNumEndpoints
    0x01, //bInterfaceClass
    0x02, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x06, //iInterface

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x02, //bInterfaceNumber
    0x01, //bAlternateSetting
    0x01, //bNumEndpoints
    0x01, //bInterfaceClass
    0x02, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x00, //iInterface

    //Audio Descriptor
    0x07, //bLength
    0x24, //bDescriptorType
    0x01, //bDescriptorSubtype
    0x0B, //bTerminalLink
    0x01, //bDelay
    0x01, //wFormatTag
    0x00, 

    //Audio Descriptor
    0x0E, //bLength
    0x24, //bDescriptorType
    0x02, //bDescriptorSubtype
    0x01, //bFormatType
    0x02, //bNrChannels
    0x02, //bSubframeSize
    0x10, //bBitResolution
    0x02, //bSamFreqType
    0x44, //tSamFreq(1)
    0xAC,
    0x00,
    0x80, //tSamFreq(2)
    0xBB,
    0x00,

    //Endpoint descriptor
    0x09, //bLength
    0x05, //bDescriptorType
    0x88, //bEndpointAddress
    0x05, //bmAttributes
    0xC8, //wMaxPacketSize
    0x00,
    0x04, //bInterval
    0x00, //bRefresh
    0x00, //bSynchAddress

    //Audio Descriptor
    0x07, //bLength
    0x25, //bDescriptorType
    0x01, //bDescriptorSubtype
    0x01, //bmAttributes
    0x00, //bLockDelayUnits
    0x00, //wLockDelay
    0x00,

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x03, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x01, //bNumEndpoints
    0x03, //bInterfaceClass
    0x00, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x00, //iInterface

    //HID descriptor
    0x09, //bLength
    0x21, //bDescriptorType
    0x00, //bcdHID
    0x01,
    0x00, //bCountryCode
    0x01, //bNumDescriptors
    0x22, //bDescriptorType[0]
    0x18, //wDescriptorLength[0]
    0x00,

    //Endpoint descriptor
    0x07, //bLength
    0x05, //bDescriptorType
    0x84, //bEndpointAddress
    0x03, //bmAttributes
    0x10, //wMaxPacketSize
    0x00, 
    0x04, //bInterval
};

const uint8_t g_ucTestCfgDesc2[] =
{
    //Configuration descriptor
    0x09,       //Length
    0x02,       //DescriptorType : ConfigDescriptor
    0x20,       //TotalLength
    0x01,       
    0x04,       //NumInterfaces
    0x01,       //ConfigurationValue
    0x00,       //Configuration String
    0xA0,       //Attributes:Bus Power
    0xFA,       //MaxPower = 0xfa*2ma

    //Interface descriptor
    0x09, //bLength
    0x04, //bDescriptorType
    0x00, //bInterfaceNumber
    0x00, //bAlternateSetting
    0x00, //bNumEndpoints
    0x01, //bInterfaceClass
    0x01, //bInterfaceSubClass
    0x00, //bInterfaceProtocol
    0x00, //iInterface

 //class-specific AC interface descriptor,audio interface(0x24),audio control header(0x01), 
 0x0a,    //Length
 0x24,      //DescriptorType:audio interface descriptor                                                     
 0x01,     //DescriptorSubType:audio control header                                                        
 0x00,0x01,  //bcdADC:audio Device Class v1.00                                                               
 0x5c,0x00,  //TotalLength:0x005c                                                                            
 0x02,      //InCollection:2 AudioStreaming interface
 0x02,      //InterfaceNr(2) - AS #1 id AudioStreaming interface 2 belongs to this AudioControl interface   
 0x01,     //InterfaceNr(1) - AS #2 id AudioStreaming interface 1 belongs to this AudioControl interface

 //USB HEADSET IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x01,
 0x0c,    //Length
 0x24,    //DescriptorType:audio interface descriptor
 0x02,     //DescriptorSubType:Input Terminal
 0x01,     //TerminalID:0x01
 0x01,0x02,  //TerminalType:USB HEADSET
 0x00,      //AssocTerminal
 0x01,      //NrChannels:1 channel
 0x04,0x00,  //ChannelConfig:mono
 0x00,       //ChannelName String
 0x00,       //Terminal String

 //Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x02,
 0x09,    //Length
 0x24,      //DescriptorType:audio interface descriptor
 0x06,      //DescriptorSubType:Audio Feature Unit
 0x02,       //UnitID:0x02
 0x01,      //SourceID:1 #HEADSET IT
 0x01,      //ControlSize:1 byte
 0x01,     //Controls:Mute
 0x02,      //Controls(0):Volume
 0x00,       //Feature String

  //Audio Select Unit Descriptor:audio interface descriptor,select_unit(0x05),terminal id 0x03,
 0x07,      //Length
 0x24,      //escriptorType:audio interface descriptor
 0x05,      //DescriptorSubType:Audio Feature Unit
 0x03,      //UnitID:0x03
 0x01,      //Number of input pins.
 0x02,      //baSourceID,From Handset In Feature Unit
 0x00,      //iSelector

 //USB Streaming OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x04,
 0x09,    //Length
 0x24,       //DescriptorType:audio interface descriptor
 0x03,      //DescriptorSubTYpe:Output Terminal
 0x04,      //TerminalID:0x04
 0x01,0x01,  //TerminalType:USB Streaming
 0x00,       //AssocTerminal:ID 0
 0x03,      //SourceID:3 #Select UNIT
 0x00,       //Terminal String           

 //USB USB Streaming IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x05,
 0x0c,       //Length                                    
 0x24,       //DescriptorType:audio interface descriptor 
 0x02,       //DescriptorSubType:Input Terminal          
 0x05,       //TerminalID:0x05                           
 0x01,0x01,  //TerminalType:USB Streaming               
 0x00,       //AssocTerminal                             
 0x02,       //NrChannels:2 channel                              
 0x03,0x00,  //ChannelConfig:Left Front,Right Front,     
 0x00,       //ChannelName String                        
 0x00,       //Terminal String                          

 //Audio MIXer Unit Descriptor:audio interface descriptor,MIXer_unit(0x04),terminal id 0x06, 
 0x0d,      //Length  
 0x24,      //DescriptorType:audio interface descriptor 
 0x04,      //DescriptorSubType:Input Terminal 
 0x06,      //TerminalID:0x06
 0x02,      //Number of Input Pins of this Unit
 0x05,      //baSourceID:0x05
 0x02,      //baSourceID:0x02
 0x02,      //Number of Output Pins of this Unit
 0x03,0x00, //wChannelConfig:Left Front,Right Front
 0x00,      //iChannelNames
 0x00,      //bmControls
 0x00,      //iMixer

 //Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x07, 
 0x0a,    //Length                                   
 0x24,      //DescriptorType:audio interface descriptor
 0x06,       //DescriptorSubType:Audio Feature Unit     
 0x07,       //UnitID:0x07                             
 0x06,      //SourceID:6 #USB Streaming IT                
 0x01,      //ControlSize:1 byte                       
 0x01,      //Controls:Mute,                     
 0x02,       //Controls(0):Volume                             
 0x02,      //Controls(1):Volume                             
 0x00,       //Feature String              

 //USB HEADSET OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x08,
 0x09,      //Length                                    
 0x24,      //DescriptorType:audio interface descriptor 
 0x03,      //DescriptorSubTYpe:Output Terminal         
 0x08,      //TerminalID:0x08                           
 0x02,0x04,  //TerminalType:Speaker                
 0x00,       //AssocTerminal:                       
 0x07,      //SourceID:6 #Feature UNIT                    
 0x00      //Terminal String

 //-------------------Microphone  interface---------------------//
 //standard interface AS descriptor(Interface 1, Alternate Setting 0):                
 0x09,    //Length                           
 0x04,       //DescriptorType:Interface         
 0x01,      //InterfaceNum:1                   
 0x00,      //AlternateSetting:0               
 0x00,       //NumEndpoint:0                    
 0x01,      //InterfaceClass:audio             
 0x02,      //InterfaceSubClass:audio streaming
 0x00,       //InterfaceProtocol                
 0x00,       //Interface String            

 //standard interface AS descriptor(Interface 1, Alternate Setting 1):                         
 0x09,    //Length                           
 0x04,      //DescriptorType:Interface         
 0x01,      //InterfaceNum:1                   
 0x01,      //AlternateSetting:1               
 0x01,       //NumEndpoint:1
 0x01,      //InterfaceClass:audio             
 0x02,       //InterfaceSubClass:audio streaming
 0x00,      //InterfaceProtocol                
 0x00,       //Interface String        

 //Audio Streaming Interface Descriptor:AS_GENERAL(0x01),
 0x07,    //Length                                      
 0x24,       //DescriptorType:audio interface descriptor   
 0x01,      //DescriptorSubType:AS_GENERAL                
 0x04,       //TerminalLink:#4USB USB Streaming OT           
 0x01,       //Delay:1                                     
 0x01,0x00,  //FormatTag:PCM        

 //Type 1 Format type descriptor:FORMAT_TYPE(0x02),FORMAT_TYPE_I(0x01),
 //physical channels 0x01,two byte per audio subframe(0x02),16bit,
 0x0B,      //Length                            
 0x24,      //DescriptorType:audio interface descriptor
 0x02,      //DescriptorSubType:Format_type            
 0x01,       //FormatType:Format type 1                 
 0x01,      //NumberOfChanne:1
 0x02,       //SubframeSize:2byte
 0x10,      //BitsResolution:16bit
 0x01,       //SampleFreqType:One sampling frequency.
 0x80,
 0xBB,
 0x00,

 //Endpoint 1 - Standard Descriptor:Input Endpoint1
 0x09,     //Length
 0x05,      //DescriptorType:endpoint descriptor
 0x81,       //EndpointAddress:Input endpoint 1
 0x05,       //Attributes:0x05,Isochronous,Synchronization Type(Asynchronous).........
 0x80,0x01,  //MaxPacketSize:0x0084=........
 0x01,      //Interval
 0x00,
 0x00,
 /* 07byte*/

 //Endpoint - Audio Streaming Descriptor:
 //Audio Endpoint descriptor,General,
 0x07,    //Length
 0x25,      //DescriptorType:audio endpoint descriptor
 0x01,      //DescriptorSubType:audio endpiont general
 0x01,       //Attributes:0x00........
 0x00,      //LockDelayUnits
 0x00,0x00,  //LockDelay
 /* 07 byte*/

 //-------------------Speaker  interface---------------------//
 //standard interface AS descriptor(Interface 2, Alternate Setting 0):
 //bNumEndpoints = 0x00,bInterFaceClass = 0x01(audio),bInterfaceSubClass = 0x02(audio stream), 
 0x09,      //Length                           
 0x04,      //DescriptorType:Interface         
 0x02,       //InterfaceNum:2                   
 0x00,       //AlternateSetting:0               
 0x00,      //NumEndpoint:0                    
 0x01,       //InterfaceClass:audio             
 0x02,      //InterfaceSubClass:audio streaming
 0x00,      //InterfaceProtocol                
 0x00,       //Interface String                
/* 09 byte*/

 //standard interface AS descriptor(Interface 2, Alternate Setting 1):                        
  //bNumEndpoints = 0x01,bInterFaceClass = 0x01(audio),bInterfaceSubClass = 0x02(audio stream),
  0x09,      //Length
  0x04,      //DescriptorType:Interface
  0x02,       //InterfaceNum:2
  0x01,       //AlternateSetting:1
  0x01,       //NumEndpoint:1
  0x01,      //InterfaceClass:audio
  0x02,       //InterfaceSubClass:audio streaming
  0x00,       //InterfaceProtocol
  0x00,      //Interface String
 /* 09 byte*/

  //Audio Streaming Interface Descriptor:AS_GENERAL(0x01),
  //TerminalLink 0x04,PCM(0x0001)
  0x07,      //Length
  0x24,       //DescriptorType:audio interface descriptor
  0x01,       //DescriptorSubType:AS_GENERAL
  0x05,      //TerminalLink:#5 USB Streaming IT
  0x01,      //Delay:1
  0x01,0x00,  //FormatTag:PCM
  /* 07 byte*/

  //Type 1 Format type descriptor:FORMAT_TYPE(0x02),FORMAT_TYPE_I(0x01),
  //physical channels 0x02,two byte per audio subframe(0x02),16bit,
  //32K(0x007d00)
  0x0B,     //Length
  0x24,       //DescriptorType:audio interface descriptor
  0x02,      //DescriptorSubType:Format_type
  0x01,       //FormatType:Format type 1
  0x02,       //NumberOfChanne:2
  0x02,       //SubframeSize:2byte
  0x10,      //BitsResolution:16bit
  0x00 ,      //SampleFreqType:One sampling frequency.
  0x80, 
  0xBB,
  0x00,





{
  //Endpoint 1 - Standard Descriptor:Output Endpoint1
  //Isochronous,Synchronization Type(Asynchronous),MaxPacketSize 0x0084,
  0x09,      //Length
  0x05,       //DescriptorType:endpoint descriptor
  0x01,       //EndpointAddress:Output endpoint 1
  0x05,      //Attributes:0x05,Isochronous,Synchronization Type(Asynchronous).........
  0x80,0x01,  //MaxPacketSize:0x0084=.....
  0x01,      //Interval
  0x00,
  0x00,
  /* 07 byte*/

  //Endpoint - Audio Streaming Descriptor:
  //Audio Endpoint descriptor,General,
  0x07,       //Length
  0x25,       //DescriptorType:audio endpoint descriptor
  0x01,       //DescriptorSubType:audio endpiont general
  0x01,      //Attributes:0x00.............
  0x00,       //LockDelayUnits
  0x00,0x00,  //LockDelay
  /* 07 byte*/

 //standard interface AS descriptor(Interface 2, Alternate Setting 2):
 //bNumEndpoints = 0x01,bInterFaceClass = 0x01(audio),bInterfaceSubClass = 0x02(audio stream),
 0x09,      //Length                           
 0x04,      //DescriptorType:Interface         
 0x02,       //InterfaceNum:2                   
 0x02,       //AlternateSetting:1
 0x01,       //NumEndpoint:1                    
 0x01,      //InterfaceClass:audio             
 0x02,       //InterfaceSubClass:audio streaming
 0x00,       //InterfaceProtocol                
 0x00,      //Interface String                
/* 09 byte*/

 //Audio Streaming Interface Descriptor:AS_GENERAL(0x01),
 //TerminalLink 0x04,PCM(0x0001)
 0x07,      //Length                                   
 0x24,       //DescriptorType:audio interface descriptor
 0x01,       //DescriptorSubType:AS_GENERAL             
 0x05,      //TerminalLink:#5 USB Streaming IT     
 0x01,      //Delay:1                                  
 0x01,0x00,  //FormatTag:PCM     
 /* 07 byte*/

 //Type 1 Format type descriptor:FORMAT_TYPE(0x02),FORMAT_TYPE_I(0x01),
 //physical channels 0x02,two byte per audio subframe(0x02),16bit,
 //32K(0x007d00)
 0x08,     //Length
 0x24,       //DescriptorType:audio interface descriptor
 0x02,      //DescriptorSubType:Format_type            
 0x01,       //FormatType:Format type 1                 
 0x02,       //NumberOfChanne:2                         
 0x03,       //SubframeSize:2byte
 0x18,      //BitsResolution:16bit
 0x00 ,      //SampleFreqType:One sampling frequency.
}


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
