


/*-----------------------------------user.h-------------------------------------*/
	#define EFFECT_POST_SIDETONE_EN     1//sidetone

	#if EFFECT_POST_SIDETONE_EN
		#define SIDETONE_ALWAYS_ON_EN		1
		#define SIDETONE_AUTO_CTRL_EN		0 //0:常开 1:当主机播放时关闭sidetone，否则开启
		#define SIDETONE_DEF_STAT			(0U) //1:on,0:off , default sidetone state when power up
	#else
		#define SIDETONE_ALWAYS_ON_EN		0
		#define SIDETONE_AUTO_CTRL_EN		0
		#define SIDETONE_DEF_STAT			(0U) //always no sidetone
	#endif

/*-----------------------------------user.c-------------------------------------*/

#include "usb_app.h"


#define LED1_ON 	GPIO_FuncSet(GPIO9, GPIO_DigOutput0)
#define LED2_ON 	GPIO_FuncSet(GPIO10, GPIO_DigOutput0)
#define LED1_OFF 	GPIO_FuncSet(GPIO9, GPIO_DigOutput1)
#define LED2_OFF 	GPIO_FuncSet(GPIO10, GPIO_DigOutput1)

// extern volatile uint8_t u8UsbInSpeakerSts;

void usbAudioStreamState()
{
    // if(u8UsbInSpeakerSts)//if apple key support(only for KT0200), use "u8UsbInSpeakerSts"
	if(stUsbAudio.stAudioAttr[USB_AUDIO_IN].u8Status) 
	{
		LED1_ON;
	}
	else
	{
		LED1_OFF;
	}
	
	if(stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status)
	{
		LED2_ON;
	}
	else
	{
		LED2_OFF;
	}
}
