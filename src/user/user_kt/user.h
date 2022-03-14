 /*******************************************
 * user.h
 *
 ******************************************/
#ifndef _USER_H_
 #define _USER_H_
//	#define __FW_VERSION_USER__ "0123456789ABCDEF" //16 characters lenght ref
	#define __FW_VERSION_USER__ "0206Stereo220111" //firmware version of user, No more than 16 characters
	//chip config *******************************************
    #define KT0206    //do not modifiy

	// hardware config **************************************
	#define KT0206_Game_EVB			1
	#define CUSTOMER_BOARD			2
	#define HARDWARE_BOARD_SEL		KT0206_Game_EVB

	#define VDD_VOLTAGE_3P3V    //定义芯片供电为3.3V供电  芯片默认供电电压是5V,如果供电电压是3.3V，则需要定义此宏，5V供电的时候注销此宏 yuan++
//	#define  EXTERNAL_DVDD1P2V  //如果是外部供电的话，打开此宏定义，否则注销

	#define MIC_IN_PIN        	1	// 0:mic=vinn, 1: mic=vinp
	#define AUDIO_IN_STEREO   	1	// 0:mono asrc input 1:stereo asrc input
	#if AUDIO_IN_STEREO 			// if stereo in enable, must set AUDIO_IN_SEL to 2
		#define AUDIO_IN_SEL	2
	#else
		#define AUDIO_IN_SEL	1	// 0:没有音频输入 1:adc输入 2:i2s输入 3:adc输入+i2s输入
		#if ((AUDIO_IN_SEL == 2) || (AUDIO_IN_SEL == 3))
			// #define USB_IN_I2S_LEFT	//usb in get I2S left channel if defined, else get left+right
		#endif
	#endif
	#define AUDIO_OUT_SEL     3//0:没有音频输出 1:dac输出 2:i2s输出 3:dac输出+i2s输出					1->3	//yuan++




	//---- jack sense config ----------------------------------------------------
//	#define JACK_SENSE_FUNC     //define使能插入检测,undef不使能插入检测
	#ifdef JACK_SENSE_FUNC
		#define JACK_SENSE_CFG      0       //0->jack sense hardware, 1->GPIO key hardware
		#if JACK_SENSE_CFG
			#define EarphoneInsert_GPIOlevel	1  //0->inser earphone,gpio3==0,1->inser earphone,gpio3==1;
		#endif  
	#endif

	#if defined(KT0201) || defined(KT0203) || defined(HQ_01)
		#undef JACK_SENSE_FUNC
	#endif

	//---- jack pin order config ------------------------------
	#define JACK_PIN_ORDER_3POLE	0
	#define JACK_PIN_ORDER_CITA		1	//
	#define JACK_PIN_ORDER_OMTP		2	//
	#define JACK_PIN_ORDER_DEF		JACK_PIN_ORDER_CITA

	//#define JACK_PIN_ORDER_FIXED		//if defined, the jack pin order fixed to JACK_PIN_ORDER_DEF
	
	//---- mic bias config -----------------------------------------------------
//	#define MICBIAS_POWER_ON_EN		1 //(1:enable  0:disable) micbias power

	//----- mic key config ----------------------------------------
//	#define MIC_KEY_SUPPORT //是否支持耳麦上带的按键
	#if defined(KT0203) || (MICBIAS_POWER_ON_EN == 0)
		#undef MIC_KEY_SUPPORT //KT0203不支持耳麦上带的按键
	#endif
	#if (defined(MIC_KEY_SUPPORT) && defined(KT0200))
		#define APPLE_EARPHONE_KEY_SUPPORT//定义此宏代表支持苹果耳机的按键，不定义不支持
	#endif

	//---- effect config ----------------------------------------
	#if defined(KT0203) || defined(KT0206) || defined(HQ_01)
			#define EFFECT_ECHO_EN              0
			#define EFFECT_PITCHSHIFT_EN        0
			#define EFFECT_REVERB_EN            0
			#define EFFECT_SURROUND3D_EN        0
			#define EFFECT_SURROUNDMOVE_EN      0
			#define EFFECT_NOISEGATE_EN         0
			#define EFFECT_COMPANDER_EN         0
			#define EFFECT_HOWLSUPRESS_EN       0
			#define EFFECT_AGC_EN               0
			#define EFFECT_DEESSER_EN           0
			#define EFFECT_EQ_EN                0
			#define EFFECT_POST_SIDETONE_EN     1//sidetone,需要监听打开这个宏即可//yuan++
			#define WAV_EN  					0//打开播放wav文件的代码
	#endif
	
	#define Deleate_Pop_standby			1	//deleate pop kt0206 emits when kt0206 enters or exits stanby mode.
	// #define I2S_IN_DATA_PROCESS_USER	//define the macro if want to get i2s data, else do not define

	/*sidetone-----------------------------------------------------------------------*/
	#if EFFECT_POST_SIDETONE_EN
		#define SIDETONE_ALWAYS_ON_EN		1
		#define SIDETONE_AUTO_CTRL_EN		0 //0:常开 1:当主机播放时关闭sidetone，否则开启
		#define SIDETONE_DEF_STAT			(1U) //1:on,0:off , default sidetone state when power up
	#else
		#define SIDETONE_ALWAYS_ON_EN		0
		#define SIDETONE_AUTO_CTRL_EN		0
		#define SIDETONE_DEF_STAT			(0U) //always no sidetone
	#endif
	
	/*usb volume----------------------------------------------------(-50~0dB),0~103*/
	#define VOL_CLASS_0			0	//min
	#define VOL_CLASS_50		82
	#define VOL_CLASS_60		87
	#define VOL_CLASS_70		92
	#define VOL_CLASS_80		96
	#define VOL_CLASS_90		99
	#define VOL_CLASS_100		103 //max(default)
	/* usb init volume for all host os */
	#define USB_IN_VOL_INIT_IDX				VOL_CLASS_100
	#define USB_OUT_VOL_INIT_IDX			VOL_CLASS_100

	/* usb init volume for windows */
	// #define USB_IN_VOL_INIT_SET_SUPPORT	//define to support usb in init volume
	// #define USB_OUT_VOL_INIT_SET_SUPPORT	//define to support usb out init volume
	// #define USB_IN_VOL_INIT_CLASS		VOL_CLASS_60
	// #define USB_OUT_VOL_INIT_CLASS		VOL_CLASS_60

	/*compander-------------------------------------------------------------------*/
	#define EFFECT_COMPANDER_DEF_STAT  	0//1: enable when start up, 0:disable when start up, the EFFECT_COMPANDER_EN is only compile in.
	#define EXPANDOR_CFG_POINT_0P5dB	((uint8_t)((int8_t)-56))//(unit:0.5dB)

	/*Noise Gate-------------------------------------------------------------------*/
	#define EFFECT_NOISEGATE_DEF_STAT  	0//1: enable when start up, 0:disable when start up, the EFFECT_NOISEGATE_EN is only compile in.
	#define EFFECT_NOISEGATE_DET_TIME	(500U)//noise gate detect time, 500ms default

	// ---- DIGIT_GAIN -----------------------------------------
	#define DIGIT_GAIN_neg12dB	(0x00000202U)
	#define DIGIT_GAIN_neg9dB	(0x000002D6U)
	#define DIGIT_GAIN_neg6dB	(0x00000402U)
	#define DIGIT_GAIN_neg3dB	(0x000005A9U)
	#define DIGIT_GAIN_0dB		(0x00000800U)//default
	#define DIGIT_GAIN_1dB		(0x000008F9U)
	#define DIGIT_GAIN_1p5dB	(0x00000982U)
	#define DIGIT_GAIN_2dB		(0x00000A12U)
	#define DIGIT_GAIN_3dB		(0x00000B4CU)
	#define DIGIT_GAIN_4p5dB	(0x00000D6EU)
	#define DIGIT_GAIN_6dB		(0x00000FF6U)
	#define DIGIT_GAIN_9dB		(0x0000168CU)
	#define DIGIT_GAIN_12dB 	(0x00001FD9U)
	#define DIGIT_GAIN_18dB 	(0x00003F8BU)
	#define DIGIT_GAIN_24dB 	(0x00007ECAU)

	//ADC Analog Gain: 0: 0dB, 1: -6dB, 2: 8dB, 3: 14dB, 4: 20dB(def), 5: 26dB, 6: 32dB, 7: 44dB
	#define ADC_GAIN_ANALOG_0dB 	(0U)
	#define ADC_GAIN_ANALOG_20dB 	(4U) //default
	#define ADC_GAIN_ANALOG_26dB 	(5U) 
	
	//DAC Analog Gain:	0: mute  , 1: -18dB,  2: -16.5dB,  3: -15dB,  4: -13.5dB,  5: -12dB,  6: -10.5dB,      7: -9dB
	//					8: -7.5dB, 9: -6dB , 10: -4.5dB , 11: -3dB , 12: -1.5dB , 13: 0dB  , 14: 1.5dB(def),  15: 3dB 
	#define DAC_GAIN_ANALOG_1p5dB 	(14U) // default


	//---- adc gain -------------------------------------
	#define ADC_GAIN_ANALOG_SEL 	ADC_GAIN_ANALOG_20dB
	#define ADC_GAIN_DIGIT_SEL		DIGIT_GAIN_6dB

	//---- dac left gain ----------------------------------
	#define DACL_GAIN_ANALOG_SEL 	DAC_GAIN_ANALOG_1p5dB
	#define DACL_GAIN_DIGIT_SEL		DIGIT_GAIN_0dB

	//---- dac right gain -----------------------------------
	#define DACR_GAIN_ANALOG_SEL 	DACL_GAIN_ANALOG_SEL
	#define DACR_GAIN_DIGIT_SEL		DACL_GAIN_DIGIT_SEL
	
	//---- USB Terminal -------------------------------------
	#define USB_TERMINAL_TYPE_Headset	1	//
	#define USB_TERMINAL_TYPE_Headphne	2	//
	#define USB_TERMINAL_TYPE_Speaker	3	//
	#define USB_TERMINAL_TYPE 	USB_TERMINAL_TYPE_Speaker

	// USB Desciption ---------------------------------------
	//#define USB_VENDORID 	0x31B2
    #define USB_MANUFACT    "KTMicro"
#if (AUDIO_IN_STEREO == 0)
    #define USB_PRODUCTID   0x0011
    #define USB_PRODUCT     "KT_USB_AUDIO"
    #define USB_SERIAL      "214b206000000178"
#else
    #define USB_PRODUCTID   0x0012
    #define USB_PRODUCT     "Stereo_Audio_InOut"
    #define USB_SERIAL      "Kt_StereoInOut"
#endif
    #define USB_MAXPOWER     45 //可配置1-250，250代表最大可取电流为250*2=500mA

    //IN/OUT Frequency	bit : 9     8     7       6     5     4         3     2     1         0
    //					int:| 96k | 48k | 44.1k | 32k | 24k | 20.025k | 16k | 12k | 11.025k | 8k |
    #define USB_IN_FREQ_SUPPORT     0x100 // usb输入可以配置的频率  <=192K  (exp:0x389 --> 96k,48k,44.1k,16k,8K)
    #define USB_OUT_FREQ_SUPPORT    0x100 // usb输出可以配置的频率  <= 96k

//	#define USB2DSP_SMP_RATE_DIFF	//define to support sample rate above 96KHz in USBin, but 44.1KHz/48KHz in DSP
	#ifdef USB2DSP_SMP_RATE_DIFF //  the sample rate supported as follow:
    /*	           IN Frequency         bit :   7      6     5       4       3     2       1      0
    *							 Low Byte:  | 44.1k |  x  |  x  |    x    |  x  |  x  |    x    | x  |
    *							High Byte:  |   x   |  x  |  x  |    x    |  x  | 192k|   96k   | 48k|*/
	#endif

    #define USB_SMP_16b				0x2 //0x0010, 16bit
    #define USB_SMP_24b				0x4	//0x0100, 24bit
    #define USB_SMP_16b_24b			0x6	//0x0110, 16bit + 24bit
    #define USB_IN_SAMPLE_DEPTH 	USB_SMP_16b_24b// usb in audio sample depth
    #define USB_OUT_SAMPLE_DEPTH 	USB_SMP_16b_24b// usb out audio sample depth

	// #define USB_AUDIO_FEATURE_UNIT_ST_EN	1 //Feature unit for sidetone control in windows(1:enable, 0:disable)
	// #define APPLE_LIGHTING_USB_SUPPORT

    #ifndef __ASSEMBLER__
        extern void _user_schedule(void);
        extern void _user_init(void);
    #endif
#endif 
