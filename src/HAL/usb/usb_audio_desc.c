/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_desc.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        :
********************************************************************************/
#include "usb_ch9.h"
/*USB Terminal Type
input terminal type:	0x0201:Microphone
output terminal type:	0x0301:Speaker,		0x0302:Headphones
bi-dir terminal type:	0x0402:Headset		*/
#ifndef USB_TERMINAL_TYPE
	#define USB_TERMINAL_TYPE_Speaker	255	
	#define USB_TERMINAL_TYPE 	USB_TERMINAL_TYPE_Speaker
#endif

#if (USB_TERMINAL_TYPE == USB_TERMINAL_TYPE_Headset)
	#define TERM_IN_H	0x04
	#define TERM_IN_L	0x02
	#define TERM_OUT_H	0x04
	#define TERM_OUT_L	0x02
#elif (USB_TERMINAL_TYPE == USB_TERMINAL_TYPE_Headphne)
	#define TERM_IN_H	0x02
	#define TERM_IN_L	0x01
	#define TERM_OUT_H	0x03
	#define TERM_OUT_L	0x02
#elif (USB_TERMINAL_TYPE == USB_TERMINAL_TYPE_Speaker)
	#define TERM_IN_H	0x02
	#define TERM_IN_L	0x01
	#define TERM_OUT_H	0x03
	#define TERM_OUT_L	0x01
#endif
//*******************************************************************
//
//				描述符
//
//*******************************************************************
extern stUSB_Audio_Dev stUsbAudio;

/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */

const uint8_t AUDIO_HEADSET_CONFIG_DESC[9];
// const uint8_t new_AUDIO_HEADSET_CONFIG_DESC[] =
// {
// 	0x09,		// bLength
// 	0x02,		// bDescriptorType : ConfigDescriptor
// ///	0xff,0x01,	// wTotalLength:0x00be
// 	0x04,		// bNumInterfaces:4
// 	0x01,		// bConfigurationValue
// 	0x00,		// iConfiguration
// 	0xA0,		// bmAttributes:Bus Power
// 	0xfa		// bMaxPower = 0xfa*2ma
// 	/* 09 byte*/
// };

const uint8_t new_AUDIO_CTRL_HEADSET_DESC[] =
{
//standard interface AC descriptor(Interface 0, Alternate Setting 0):

	0x09,    //Length
	0x04,     //DescriptorType:Inerface
	0x00,     //InterfaceNum:0
	0x00,       //AlternateSetting:0
	0x00,       //NumEndpoint:0
	0x01,       //InterfaceClass:audio
	0x01,       //InterfaceSubClass:audio ctl
	0x00,       //InterfaceProtocol
	0x00,      //Interface String
	/* 09 byte*/

//class-specific AC interface descriptor,audio interface(0x24),audio control header(0x01),

	0x0a,    //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x01,     //DescriptorSubType:audio control header
	0x00, 0x01, //bcdADC:audio Device Class v1.00
	0x5b, 0x00, //TotalLength:0x005c
	0x02,      //InCollection:2 AudioStreaming interface
	0x02,      //InterfaceNr(2) - AS #1 id AudioStreaming interface 2 belongs to this AudioControl interface
	0x01,     //InterfaceNr(1) - AS #2 id AudioStreaming interface 1 belongs to this AudioControl interface
	/* 10 byte*/

//USB HEADSET IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x01,
	0x0c,    //Length
	0x24,    //DescriptorType:audio interface descriptor
	0x02,     //DescriptorSubType:Input Terminal
	0x01,     //TerminalID:0x01
	TERM_IN_L, TERM_IN_H, //TerminalType:Microphone
	0x00,      //AssocTerminal
	0x01,      //NrChannels:1 channel
	0x00, 0x00, //ChannelConfig:mono
	0x00,       //ChannelName String
	0x00,       //Terminal String
	/* 12 byte*/

	//Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x02,
#if(USB_IN_CHANNEL == 2)
	0x0a,    //Length
#else
	0x09,    //Length
#endif
	0x24,      //DescriptorType:audio interface descriptor
	0x06,      //DescriptorSubType:Audio Feature Unit
	0x02,       //UnitID:0x02
	0x01,      //SourceID:1 #HEADSET IT
	0x01,      //ControlSize:1 byte
	0x03,     //Controls(0):Mute
	0x00,      //Controls(1):Volume
#if(USB_IN_CHANNEL == 2)
	0x00,      //Controls(2):Volume
#endif
	0x00,       //Feature String
	/* 09/10 byte*/

	//Audio Select Unit Descriptor:audio interface descriptor,select_unit(0x05),terminal id 0x03,
	0x07,		//Length
	0x24,		//escriptorType:audio interface descriptor
	0x05,		//DescriptorSubType:Audio Feature Unit
	0x03,		//UnitID:0x03
	0x01,		//Number of input pins.
	0x02,		//baSourceID,From Handset In Feature Unit
	0x00,		//iSelector
	/* 07 byte*/


//USB Streaming OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x04,
	0x09,    //Length
	0x24,       //DescriptorType:audio interface descriptor
	0x03,      //DescriptorSubTYpe:Output Terminal
	0x04,      //TerminalID:0x04
	0x01, 0x01, //TerminalType:USB Streaming
	0x00,       //AssocTerminal:ID 0
	0x03,      //SourceID:3 #Select UNIT
	0x00,       //Terminal String
	/* 09 byte*/

#if (EFFECT_POST_SIDETONE_EN && USB_AUDIO_FEATURE_UNIT_ST_EN)
	//Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x09,
#if(USB_IN_CHANNEL == 2)
	0x0a,    //Length
#else
	0x09,    //Length
#endif
	0x24,      //DescriptorType:audio interface descriptor
	0x06,      //DescriptorSubType:Audio Feature Unit
	0x09,       //UnitID
	0x01,      //SourceID:1 #HEADSET IT
	0x01,      //ControlSize:1 byte
	0x03,     //Controls(0):Mute
	0x00,      //Controls(1):Volume
#if(USB_IN_CHANNEL == 2)
	0x00,      //Controls(2):Volume
#endif
	0x00,       //Feature String
	/* 09/10 byte*/
#endif
//USB USB Streaming IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x05,
	0x0c,       //Length
	0x24,       //DescriptorType:audio interface descriptor
	0x02,       //DescriptorSubType:Input Terminal
	0x05,       //TerminalID:0x05
	0x01, 0x01, //TerminalType:USB Streaming
	0x00,       //AssocTerminal
	0x02,       //NrChannels:2 channel
	0x03, 0x00, //ChannelConfig:Left Front,Right Front,
	0x00,       //ChannelName String
	0x00,       //Terminal String
	/* 12 byte*/

//Audio MIXer Unit Descriptor:audio interface descriptor,MIXer_unit(0x04),terminal id 0x06,
	0x0d,		//Length
	0x24,		//DescriptorType:audio interface descriptor
	0x04,		//DescriptorSubType:Input Terminal
	0x06,		//TerminalID:0x06
	0x02,		//Number of Input Pins of this Unit
	0x05,		//baSourceID1: 0x05(IT)
#if (EFFECT_POST_SIDETONE_EN && USB_AUDIO_FEATURE_UNIT_ST_EN)
	0x09,		//baSourceID2: 0x09(Feature Unit)
#else
	0x05,		//baSourceID2: 0x05(IT)
#endif
	0x02,		//Number of Output Pins of this Unit
	0x03, 0x00,	//wChannelConfig:Left Front,Right Front
	0x00,		//iChannelNames
	0x00,		//bmControls
	0x00,		//iMixer
	/* 13 byte*/

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
	/* 10 byte*/

//USB HEADSET OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x08,

	0x09,      //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x03,      //DescriptorSubTYpe:Output Terminal
	0x08,      //TerminalID:0x08
	TERM_OUT_L, TERM_OUT_H, //TerminalType:Speaker
	0x00,       //AssocTerminal:
	0x07,      //SourceID:6 #Feature UNIT
	0x00      //Terminal String
	/* 09 byte*/
};

const uint8_t new_AUDIO_CTRL_DONGLE_DESC[] =
{
	//standard interface AC descriptor(Interface 0, Alternate Setting 0):

	0x09,    //Length
	0x04,     //DescriptorType:Inerface
	0x00,     //InterfaceNum:0
	0x00,       //AlternateSetting:0
	0x00,       //NumEndpoint:0
	0x01,       //InterfaceClass:audio
	0x01,       //InterfaceSubClass:audio ctl
	0x00,       //InterfaceProtocol
	0x00,      //Interface String
	/* 09 byte*/

	//class-specific AC interface descriptor,audio interface(0x24),audio control header(0x01),

	0x09,    //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x01,     //DescriptorSubType:audio control header
	0x00, 0x01, //bcdADC:audio Device Class v1.00
	0x27, 0x00, //TotalLength:0x005c
	0x01,      //InCollection:2 AudioStreaming interface
	0x01,      //InterfaceNr(2) - AS #1 id AudioStreaming interface 2 belongs to this AudioControl interface
	/* 09 byte*/


	//USB HEADSET IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x01,
	0x0c,    //Length
	0x24,    //DescriptorType:audio interface descriptor
	0x02,     //DescriptorSubType:Input Terminal
	0x01,     //TerminalID:0x01
	0x01, 0x02,//TerminalType:Microphone
	0x00,      //AssocTerminal
	0x01,      //NrChannels:1 channel
	0x00, 0x00, //ChannelConfig:mono
	0x00,       //ChannelName String
	0x00,       //Terminal String
	/* 12 byte*/


	//Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x02,
#if(USB_IN_CHANNEL == 2)
	0x0a,    //Length
#else
	0x09,    //Length
#endif
	0x24,      //DescriptorType:audio interface descriptor
	0x06,      //DescriptorSubType:Audio Feature Unit
	0x02,       //UnitID:0x02
	0x01,      //SourceID:1 #HEADSET IT
	0x01,      //ControlSize:1 byte
	0x01,     //Controls(0):Mute
	0x02,      //Controls(1):Volume
#if(USB_IN_CHANNEL == 2)
	0x02,      //Controls(2):Volume
#endif
	0x00,       //Feature String
	/* 09/10 byte*/

	//Audio Select Unit Descriptor:audio interface descriptor,select_unit(0x05),terminal id 0x03,
	// 0x07,		//Length
	// 0x24,		//escriptorType:audio interface descriptor
	// 0x05,		//DescriptorSubType:Select UNIT
	// 0x03,		//UnitID:0x03
	// 0x01,		//Number of input pins.
	// 0x02,		//baSourceID,From Handset In Feature Unit
	// 0x00,		//iSelector
	/* 07 byte*/


	//USB Streaming OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x04,
	0x09,    //Length
	0x24,       //DescriptorType:audio interface descriptor
	0x03,      //DescriptorSubTYpe:Output Terminal
	0x04,      //TerminalID:0x04
	0x01, 0x01, //TerminalType:USB Streaming
	0x00,       //AssocTerminal:ID 0
	// 0x03,      //SourceID:3 #Select UNIT
	0x02,      //SourceID:2 #Audio Feature Unit
	0x00,       //Terminal String
	/* 09 byte*/
};

const uint8_t new_AUDIO_CTRL_HEADPHONE_DESC[] =
{
//standard interface AC descriptor(Interface 0, Alternate Setting 0):

	0x09,    //Length
	0x04,     //DescriptorType:Inerface
	0x00,     //InterfaceNum:0
	0x00,       //AlternateSetting:0
	0x00,       //NumEndpoint:0
	0x01,       //InterfaceClass:audio
	0x01,       //InterfaceSubClass:audio ctl
	0x00,       //InterfaceProtocol
	0x00,      //Interface String
	/* 09 byte*/

//class-specific AC interface descriptor,audio interface(0x24),audio control header(0x01),

	0x09,    //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x01,     //DescriptorSubType:audio control header
	0x00, 0x01, //bcdADC:audio Device Class v1.00
	0x28, 0x00, //TotalLength:0x005c
	0x01,      //InCollection:2 AudioStreaming interface
	0x02,      //InterfaceNr(2) - AS #1 id AudioStreaming interface 2 belongs to this AudioControl interface
	/* 10 byte*/


//USB USB Streaming IT:audio interface descriptor,audio control input terminal(0x02),terminal id 0x05,
	0x0c,       //Length
	0x24,       //DescriptorType:audio interface descriptor
	0x02,       //DescriptorSubType:Input Terminal
	0x05,       //TerminalID:0x05
	0x01, 0x01, //TerminalType:USB Streaming
	0x00,       //AssocTerminal
	0x02,       //NrChannels:2 channel
	0x03, 0x00, //ChannelConfig:Left Front,Right Front,
	0x00,       //ChannelName String
	0x00,       //Terminal String
	/* 12 byte*/


//Audio Feature Unit Descriptor:audio interface descriptor,feature_unit(0x06),terminal id 0x07,

	0x0a,    //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x06,       //DescriptorSubType:Audio Feature Unit
	0x07,       //UnitID:0x07
	0x05,      //SourceID:6 #USB Streaming IT
	0x01,      //ControlSize:1 byte
	0x01,      //Controls:Mute,
	0x02,       //Controls(0):Volume
	0x02,      //Controls(1):Volume
	0x00,       //Feature String
	/* 10 byte*/

//USB HEADSET OT:audio interface descriptor,audio control output terminal(0x03),terminal id 0x08,

	0x09,      //Length
	0x24,      //DescriptorType:audio interface descriptor
	0x03,      //DescriptorSubTYpe:Output Terminal
	0x08,      //TerminalID:0x08
	0x02, 0x03, //TerminalType:Headphones
	0x00,       //AssocTerminal:
	0x07,      //SourceID:6 #Feature UNIT
	0x00      //Terminal String
	/* 09 byte*/
};

// const uint8_t AUDIO_MICROPHONE_INTERFACE_DESC_1[33];// = new_AUDIO_MICROPHONE_INTERFACE_DESC + new_AUDIO_MICROPHONE_INTERFACE_DESC_1
const uint8_t new_AUDIO_MICROPHONE_INTERFACE_DESC[] =
{
	//-------------------Microphone AS Endpoint:0---------------------//
	//standard interface AS descriptor(Interface 1, Alternate Setting 0):
	0x09,		//Length
	0x04,		//DescriptorType:Interface
	0x01,		//InterfaceNum:1
	0x00,		//AlternateSettig:0
	0x00,		//NumEndpoint:0
	0x01,		//InterfaceClass:audio
	0x02,		//InterfaceSubClass:audio streaming
	0x00,		//InterfaceProtocol
	0x00,		//Interface String
	/* 09 byte*/
};

const uint8_t new_AUDIO_MICROPHONE_INTERFACE_DESC_1[] =
{
	//-------------------Microphone AS Endpoint:1---------------------//
	//standard interface AS descriptor(Interface 1, Alternate Setting 1):
	0x09,		//Length
	0x04,		//DescriptorType:Interface
	0x01,		//InterfaceNum:1
	0x01,		//AlternateSetting:1
	0x01,		//NumEndpoint:1
	0x01,		//InterfaceClass:audio
	0x02,		//InterfaceSubClass:audio streaming
	0x00,		//InterfaceProtocol
	0x00,		//Interface String
	/* 09 byte*/

	//Audio Streaming Interface Descriptor:AS_GENERAL(0x01),
	0x07,		//Length
	0x24,		//DescriptorType:audio interface descriptor
	0x01,		//DescriptorSubType:AS_GENERAL
	0x04,		//TerminalLink:#4USB USB Streaming OT
	0x01,		//Delay:1
	0x01,0x00,	//FormatTag:PCM
	/* 07 byte*/

	//Type 1 Format type descriptor:FORMAT_TYPE(0x02),FORMAT_TYPE_I(0x01),
	//physical channels 0x01,two byte per audio subframe(0x02),16bit,
	0x08,		//Length
	0x24,		//DescriptorType:audio interface descriptor
	0x02,		//DescriptorSubType:Format_type
	0x01,		//FormatType:Format type 1
	0x01,		//NumberOfChanne:1
	0x02,		//SubframeSize:2byte
	0x10,		//BitsResolution:16bit
	0x00,		//SampleFreqType:One sampling frequency.
};

const uint8_t AUDIO_MICROPHONE_INTERFACE_DESC_2[16];
//  =
// {
//  //Endpoint 1 - Standard Descriptor:Input Endpoint1
//  0x09,     //Length
//  0x05,      //DescriptorType:endpoint descriptor
//  0x81,       //EndpointAddress:Input endpoint 1
//  0x05,       //Attributes:0x05,Isochronous,Synchronization Type(Asynchronous).........
//  0x80,0x01,  //MaxPacketSize:0x0084=........
//  0x01,      //Interval
//  0x00,
//  0x00,
//  /* 07byte*/

//  //Endpoint - Audio Streaming Descriptor:
//  //Audio Endpoint descriptor,General,
//  0x07,    //Length
//  0x25,      //DescriptorType:audio endpoint descriptor
//  0x01,      //DescriptorSubType:audio endpiont general
//  0x01,       //Attributes:0x00........
//  0x00,      //LockDelayUnits
//  0x00,0x00,  //LockDelay
//  /* 07 byte*/
// };

// const uint8_t AUDIO_SPEAK_INTERFACE_DESC_1[33];

const uint8_t new_AUDIO_SPEAK_INTERFACE_DESC_1[] = 
{
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
};

const uint8_t new_AUDIO_SPEAK_INTERFACE_DESC_2[] =
{
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
  0x08,     //Length
  0x24,       //DescriptorType:audio interface descriptor
  0x02,      //DescriptorSubType:Format_type
  0x01,       //FormatType:Format type 1
  0x02,       //NumberOfChanne:2
  0x02,       //SubframeSize:2byte
  0x10,      //BitsResolution:16bit
  0x00 ,      //SampleFreqType:One sampling frequency.
};

// const uint8_t AUDIO_SPEAK_INTERFACE_DESC_2[40];
//  =
// {
//   //Endpoint 1 - Standard Descriptor:Output Endpoint1
//   //Isochronous,Synchronization Type(Asynchronous),MaxPacketSize 0x0084,
//   0x09,      //Length
//   0x05,       //DescriptorType:endpoint descriptor
//   0x01,       //EndpointAddress:Output endpoint 1
//   0x05,      //Attributes:0x05,Isochronous,Synchronization Type(Asynchronous).........
//   0x80,0x01,  //MaxPacketSize:0x0084=.....
//   0x01,      //Interval
//   0x00,
//   0x00,
//   /* 07 byte*/

//   //Endpoint - Audio Streaming Descriptor:
//   //Audio Endpoint descriptor,General,
//   0x07,       //Length
//   0x25,       //DescriptorType:audio endpoint descriptor
//   0x01,       //DescriptorSubType:audio endpiont general
//   0x01,      //Attributes:0x00.............
//   0x00,       //LockDelayUnits
//   0x00,0x00,  //LockDelay
//   /* 07 byte*/

//  //standard interface AS descriptor(Interface 2, Alternate Setting 2):
//  //bNumEndpoints = 0x01,bInterFaceClass = 0x01(audio),bInterfaceSubClass = 0x02(audio stream),
//  0x09,      //Length
//  0x04,      //DescriptorType:Interface
//  0x02,       //InterfaceNum:2
//  0x02,       //AlternateSetting:1
//  0x01,       //NumEndpoint:1
//  0x01,      //InterfaceClass:audio
//  0x02,       //InterfaceSubClass:audio streaming
//  0x00,       //InterfaceProtocol
//  0x00,      //Interface String
// /* 09 byte*/

//  //Audio Streaming Interface Descriptor:AS_GENERAL(0x01),
//  //TerminalLink 0x04,PCM(0x0001)
//  0x07,      //Length
//  0x24,       //DescriptorType:audio interface descriptor
//  0x01,       //DescriptorSubType:AS_GENERAL
//  0x05,      //TerminalLink:#5 USB Streaming IT
//  0x01,      //Delay:1
//  0x01,0x00,  //FormatTag:PCM
//  /* 07 byte*/

//  //Type 1 Format type descriptor:FORMAT_TYPE(0x02),FORMAT_TYPE_I(0x01),
//  //physical channels 0x02,two byte per audio subframe(0x02),16bit,
//  //32K(0x007d00)
//  0x08,     //Length
//  0x24,       //DescriptorType:audio interface descriptor
//  0x02,      //DescriptorSubType:Format_type
//  0x01,       //FormatType:Format type 1
//  0x02,       //NumberOfChanne:2
//  0x03,       //SubframeSize:2byte
//  0x18,      //BitsResolution:16bit
//  0x00 ,      //SampleFreqType:One sampling frequency.
// };

const uint8_t AUDIO_SPEAK_INTERFACE_DESC_3[16];
//  =
// {
//  //Endpoint 1 - Standard Descriptor:Output Endpoint1
//  //Isochronous,Synchronization Type(Asynchronous),MaxPacketSize 0x0084,
//  0x09,      //Length
//  0x05,       //DescriptorType:endpoint descriptor
//  0x01,       //EndpointAddress:Output endpoint 1
//  0x05,      //Attributes:0x05,Isochronous,Synchronization Type(Asynchronous).........
//  0x40,0x02,  //MaxPacketSize:0x0084=.....
//  0x01,      //Interval
//  0x00,
//  0x00,
//  /* 07 byte*/

//  //Endpoint - Audio Streaming Descriptor:
//  //Audio Endpoint descriptor,General,
//  0x07,       //Length
//  0x25,       //DescriptorType:audio endpoint descriptor
//  0x01,       //DescriptorSubType:audio endpiont general
//  0x01,      //Attributes:0x00.............
//  0x00,       //LockDelayUnits
//  0x00,0x00  //LockDelay
//  /* 07 byte*/
// };

const uint8_t new_HID_INTERFACE_DESC[] =
{
	//HID INTERFACE(Interface 3, Alternate Setting 0)
	0X09,		//Length of standard interface descriptor
	0x04,		//Standard Interface Type
	0x03,		//No of Interface
	0x00,		//Alternate Setting Selector
	0x02,		//No of Endpoints
	0x03,		//Interface Class
	0x00,		//Interface Sub Class
	0x00,		//Interface Protocol
	0x00,
	/* 09 byte*/

	/* HID - Standard Descriptor */
	0x09,		// bLength: HID Descriptor size
	0x21,		// bDescriptorType: HID
	0x10,
	0x01,		// bcdHID: HID Class Spec release number
	0x21,		// bCountryCode: Hardware target country
	0x01,		// bNumDescriptors: Number of HID class descriptors to follow
	0x22,		// bDescriptorType
	70,		// wItemLength: Total length of Report descriptor
	0x00,
	/* 09 byte*/

	/* Endpoint - HID ENDPOINT 2 IN Descriptor */
	0x07,		//Length of Standard Endpoint Descriptor
	0x05,		//Standard Endpoint Type
	0x82,		//Set Int endpoint to 2 for ATAPI mode
	0x03,		//Endpoint Characteristic
	0x40,		//Endpoint Max Packet Size
	0x00,
	0x10,
	/* 07 byte*/

	/* Endpoint - HID ENDPOINT 2 OUT Descriptor */
	0x07,		//Length of Standard Endpoint Descriptor
	0x05,		//Standard Endpoint Type
	0x02,		//Set Int endpoint to 2 for ATAPI mode
	0x03,		//Endpoint Characteristic
	0x40,		//Endpoint Max Packet Size
	0x00,
	0x10
	/* 07 byte*/
};

USB_CONFIG_DES_SIZE new_patch_Get_ConfigDesSize(void)
{
	USB_CONFIG_DES_SIZE stConfigDesSize;

	stConfigDesSize.u8HeadLength = AUDIO_HEADSET_CONFIG_DESC[0];
	if ((stUsbAudio.eUsbMode == USB_DONGLE_DSP)
	        || (stUsbAudio.eUsbMode == USB_DONGLE))
	{
		stConfigDesSize.u8ACLength = sizeof(new_AUDIO_CTRL_DONGLE_DESC);
	}
	else if (stUsbAudio.eUsbMode == USB_TYPEC_HEADPHONE)
	{
		stConfigDesSize.u8ACLength = sizeof(new_AUDIO_CTRL_HEADPHONE_DESC);
	}
	else if (stUsbAudio.eUsbMode == USB_TYPEC_HEADSET)
	{
		stConfigDesSize.u8ACLength = sizeof(new_AUDIO_CTRL_HEADSET_DESC);
	}

	stConfigDesSize.u8MicroPhoneLength = sizeof(new_AUDIO_MICROPHONE_INTERFACE_DESC);
	stConfigDesSize.u8MicroPhoneLength_1 = sizeof(new_AUDIO_MICROPHONE_INTERFACE_DESC_1);
	stConfigDesSize.u8MicroPhoneLength_2 = sizeof(AUDIO_MICROPHONE_INTERFACE_DESC_2);

	// stConfigDesSize.u8SpeakLength = sizeof(AUDIO_SPEAK_INTERFACE_DESC);
	stConfigDesSize.u8SpeakLength_1 = sizeof(new_AUDIO_SPEAK_INTERFACE_DESC_1);
	stConfigDesSize.u8SpeakLength_2 = sizeof(new_AUDIO_SPEAK_INTERFACE_DESC_2);
	stConfigDesSize.u8SpeakLength_3 = sizeof(AUDIO_SPEAK_INTERFACE_DESC_3);
	stConfigDesSize.u8HIDLength = sizeof(new_HID_INTERFACE_DESC);
	return stConfigDesSize;
}
