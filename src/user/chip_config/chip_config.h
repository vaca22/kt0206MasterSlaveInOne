#ifndef _CHIP_CONFIG_H_
#define _CHIP_CONFIG_H_

    #include "user.h"//在用户.h文件里面定义芯片的型号

    #ifndef DAC_POWER_BREAK     //开关dac的操作
        #define DAC_POWER_BREAK  1
    #endif

    #ifndef Deleate_Pop_standby //去掉dac打开pop noises的操作
        #define	Deleate_Pop_standby			0//deleate pop kt0206 emits when kt0206 enters or exits stanby mode.
    #endif

    #ifndef EQ10band_down_MicNoise //10段专门去adc高频噪底的操作  可能将来改了KT0206的封装后，外部分开供电，这段代码就能去掉
	    #define EQ10band_down_MicNoise		0//decrease noise of MIC.
    #endif


    #if defined(KT0200) || defined(KT0201)
        #if ((AUDIO_IN_SEL >=2)||(AUDIO_OUT_SEL >=2))
            #error "KT0200/KT0201 can not support i2s in"
        #endif
    #endif

    #ifndef JACK_SENSE_FUNC
        #define KEY_THRD0  0x50     //play/pause thrd
        #define KEY_THRD1  0xBF     //VOLUME UP low threshold
        #define KEY_THRD2  0x120     //VOLUME UP high threshold
        #define KEY_THRD3  0x130     //VOLUME DOWN low threshold
        #define KEY_THRD4  0x250     //VOLUME DOWN high threshold
        #define KEY_THRD5  0x70      //MUTE low threshold
        #define KEY_THRD6  0xB1      //MUTE high threshold        
    #else
        #define KEY_THRD0  0xD0     //play/pause thrd
        #define KEY_THRD1  0x127     //VOLUME UP low threshold
        #define KEY_THRD2  0x187     //VOLUME UP high threshold
        #define KEY_THRD3  0x190     //VOLUME DOWN low threshold
        #define KEY_THRD4  0x2b0     //VOLUME DOWN high threshold
        #define KEY_THRD5  0xd7     //MUTE low threshold
        #define KEY_THRD6  0x120     //MUTE high threshold
    #endif

    #if AUDIO_IN_SEL== 0
        #define AUDIO_IN_CHANNEL_SEL 0
        #define USB_IN_CHANNEL 1//上传音频的通道数，就是电脑上显示的麦克风输入的通道数
    #endif
    #if AUDIO_IN_SEL== 1
        #define AUDIO_IN_CHANNEL_SEL 1
        #define USB_IN_CHANNEL 1
    #endif
    #if AUDIO_IN_SEL== 2
        #define AUDIO_IN_CHANNEL_SEL 0x30
        #define USB_IN_CHANNEL 2
        #ifdef AUDIO_IN_STEREO
            #if (AUDIO_IN_STEREO == 0)
                #undef USB_IN_CHANNEL
                #define USB_IN_CHANNEL 1
            #endif
        #endif
    #endif
    #if AUDIO_IN_SEL== 3
        #define AUDIO_IN_CHANNEL_SEL 0x31
        #define USB_IN_CHANNEL 2
        #ifdef AUDIO_IN_STEREO
            #if (AUDIO_IN_STEREO == 0)
                #undef USB_IN_CHANNEL
                #define USB_IN_CHANNEL 1
            #endif
        #endif
    #endif

    #if AUDIO_OUT_SEL== 0
        #define AUDIO_OUT_CHANNEL_SEL 0x00
    #endif
    #if AUDIO_OUT_SEL== 1
        #define AUDIO_OUT_CHANNEL_SEL 0xc0
    #endif
    #if AUDIO_OUT_SEL== 2
        #define AUDIO_OUT_CHANNEL_SEL 0x300
    #endif
    #if AUDIO_OUT_SEL== 3
        #define AUDIO_OUT_CHANNEL_SEL 0x3c0
    #endif

    #if defined(KT0203) || defined(KT0206) || defined(HQ_01)
        #define  AUDIO_SAMPLE_BLOCK_SIZE	    48
    #else
        #define  AUDIO_SAMPLE_BLOCK_SIZE	    16
    #endif
    #define THD_COMPENSATE_EN               0
    #define CROSS_TALK_COMPENSATE_EN        0
    

#endif

