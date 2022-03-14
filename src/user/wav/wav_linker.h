#ifndef __WAV_LINKER_H__
#define __WAV_LINKER_H__

#include "user.h"

#define WAV_8k16b_IN_48k16b_DATA_MULT   (6U)
#define WAV_16k16b_IN_48k16b_DATA_MULT  (3U)
#define WAV_DATA_MULT  WAV_8k16b_IN_48k16b_DATA_MULT //the multiple of different samlpe data

//#define WAV_ENGLISH

#if (WAV_DATA_MULT == WAV_8k16b_IN_48k16b_DATA_MULT)
	#ifdef WAV_ENGLISH		
		#define WAV_0 /8k16bit/en_io_Original.wav
		#define WAV_1 /8k16bit/en_in_KTV.wav
		#define WAV_2 /8k16bit/en_in_FemaleTone.wav
		#define WAV_3 /8k16bit/en_in_MaleTone.wav
		#define WAV_4 /8k16bit/en_in_BabyTone.wav
		#define WAV_5 /8k16bit/en_in_MonsterTone.wav
		#define WAV_11 /8k16bit/en_out_Stereo.wav
		#define WAV_12 /8k16bit/en_out_MegaBass.wav
		#define WAV_13 /8k16bit/en_out_Surrund.wav
		#define WAV_15 /8k16bit/en_out_PUBG.wav
		#define WAV_16 /8k16bit/en_out_GameMode.wav
	#else
		#define WAV_0 /8k16bit/in_YuanSheng.wav
		#define WAV_1 /8k16bit/in_KTV.wav
		#if EFT_PITCHSHIFT_M2F_EN
			#define WAV_2 /8k16bit/in_NanBianNv.wav
		#else
			#define WAV_2
		#endif
		#if EFT_PITCHSHIFT_F2M_EN
			#define WAV_3 /8k16bit/in_NvBianNan.wav
		#else
			#define WAV_3
		#endif
		#define WAV_4 /8k16bit/in_WaWaYin.wav
		#define WAV_5 /8k16bit/in_MoShouYin.wav
		//#define WAV_6 /8k16bit/in_KGeMoShi.wav
		#define WAV_11 /8k16bit/out_LiTiSheng.wav
		#define WAV_12 /8k16bit/out_ZhongDiYin.wav
		#define WAV_13 /8k16bit/out_HuanRaoSheng.wav
		//#define WAV_14 /8k16bit/out_3DManBu.wav
		#if EFFECT_CHIJI_EN
			#define WAV_15 /8k16bit/out_ChiJiMoShi.wav
		#else
			#define WAV_15
		#endif
		#if EFFECT_WANGZHE_EN
			#define WAV_16 /8k16bit/out_WangZheRongYao.wav
		#else
			#define WAV_16
		#endif
	#endif
#elif (WAV_DATA_MULT == WAV_16k16b_IN_48k16b_DATA_MULT)
	#define WAV_0 /16k16bit/in_YuanSheng.wav
	#define WAV_1 /16k16bit/in_KTV.wav
	#define WAV_2 /16k16bit/in_NanBianNv.wav
	#define WAV_3 /16k16bit/in_NvBianNan.wav
	#define WAV_4 /16k16bit/in_WaWaYin.wav
	#define WAV_5 /16k16bit/in_MoShouYin.wav
	//#define WAV_6 /16k16bit/in_KGeMoShi.wav
	#define WAV_11 /16k16bit/33DingDing.wav
	#define WAV_12 /16k16bit/33DingDing.wav
	#define WAV_13 /16k16bit/33DingDing.wav
	//#define WAV_14 /16k16bit/33DingDing.wav
	#define WAV_15 /16k16bit/33DingDing.wav
	#define WAV_16 /16k16bit/33DingDing.wav
#endif
//#define WAV_7
//#define WAV_8
//#define WAV_9
//#define WAV_10
//#define WAV_11
//#define WAV_12
//#define WAV_13
//#define WAV_14
//#define WAV_15
//#define WAV_16
//#define WAV_17
//#define WAV_18
//#define WAV_19
//#define WAV_20
//#define WAV_21
//#define WAV_22
//#define WAV_23
//#define WAV_24
//#define WAV_25
//#define WAV_26
//#define WAV_27
//#define WAV_28
//#define WAV_29
//#define WAV_30
//#define WAV_31
//#define WAV_32
//#define WAV_33
//#define WAV_34
//#define WAV_35
//#define WAV_36
//#define WAV_37
//#define WAV_38
//#define WAV_39
//#define WAV_40
//#define WAV_41
//#define WAV_42
//#define WAV_43
//#define WAV_44
//#define WAV_45
//#define WAV_46
//#define WAV_47
//#define WAV_48
//#define WAV_49
//#define WAV_50
//#define WAV_51
//#define WAV_52
//#define WAV_53
//#define WAV_54
//#define WAV_55
//#define WAV_56
//#define WAV_57
//#define WAV_58
//#define WAV_59
//#define WAV_60
//#define WAV_61
//#define WAV_62
//#define WAV_63

#if (defined(WAV_0 ) || defined(WAV_1 ) || defined(WAV_2 ) || defined(WAV_3 ) ||	\
	defined(WAV_4 ) || defined(WAV_5 ) || defined(WAV_6 ) || defined(WAV_7 ) ||	\
	defined(WAV_8 ) || defined(WAV_9 ) || defined(WAV_10) || defined(WAV_11) ||	\
	defined(WAV_12) || defined(WAV_13) || defined(WAV_14) || defined(WAV_15) ||	\
	defined(WAV_16) || defined(WAV_17) || defined(WAV_18) || defined(WAV_19) ||	\
	defined(WAV_20) || defined(WAV_21) || defined(WAV_22) || defined(WAV_23) ||	\
	defined(WAV_24) || defined(WAV_25) || defined(WAV_26) || defined(WAV_27) ||	\
	defined(WAV_28) || defined(WAV_29) || defined(WAV_30) || defined(WAV_31) || \
	defined(WAV_32) || defined(WAV_33) || defined(WAV_34) || defined(WAV_35) ||	\
	defined(WAV_36) || defined(WAV_37) || defined(WAV_38) || defined(WAV_39) ||	\
	defined(WAV_40) || defined(WAV_41) || defined(WAV_42) || defined(WAV_43) ||	\
	defined(WAV_44) || defined(WAV_45) || defined(WAV_46) || defined(WAV_47) ||	\
	defined(WAV_48) || defined(WAV_49) || defined(WAV_50) || defined(WAV_51) || \
	defined(WAV_52) || defined(WAV_53) || defined(WAV_54) || defined(WAV_55) ||	\
	defined(WAV_56) || defined(WAV_57) || defined(WAV_58) || defined(WAV_59) ||	\
	defined(WAV_60) || defined(WAV_61) || defined(WAV_62) || defined(WAV_63))

#define HAVE_WAV
#define WAV_LINKER_PATH ../src/user/wav
#endif

#ifndef __ASSEMBLER__
#include "stdint.h"
extern uint8_t WAV_start0 , WAV_size0;
extern uint8_t WAV_start1 , WAV_size1;
extern uint8_t WAV_start2 , WAV_size2;
extern uint8_t WAV_start3 , WAV_size3;
extern uint8_t WAV_start4 , WAV_size4;
extern uint8_t WAV_start5 , WAV_size5;
extern uint8_t WAV_start6 , WAV_size6;
extern uint8_t WAV_start7 , WAV_size7;
extern uint8_t WAV_start8 , WAV_size8;
extern uint8_t WAV_start9 , WAV_size9;
extern uint8_t WAV_start10, WAV_size10;
extern uint8_t WAV_start11, WAV_size11;
extern uint8_t WAV_start12, WAV_size12;
extern uint8_t WAV_start13, WAV_size13;
extern uint8_t WAV_start14, WAV_size14;
extern uint8_t WAV_start15, WAV_size15;
extern uint8_t WAV_start16, WAV_size16;
extern uint8_t WAV_start17, WAV_size17;
extern uint8_t WAV_start18, WAV_size18;
extern uint8_t WAV_start19, WAV_size19;
extern uint8_t WAV_start20, WAV_size20;
extern uint8_t WAV_start21, WAV_size21;
extern uint8_t WAV_start22, WAV_size22;
extern uint8_t WAV_start23, WAV_size23;
extern uint8_t WAV_start24, WAV_size24;
extern uint8_t WAV_start25, WAV_size25;
extern uint8_t WAV_start26, WAV_size26;
extern uint8_t WAV_start27, WAV_size27;
extern uint8_t WAV_start28, WAV_size28;
extern uint8_t WAV_start29, WAV_size29;
extern uint8_t WAV_start30, WAV_size30;
extern uint8_t WAV_start31, WAV_size31;
extern uint8_t WAV_start32, WAV_size32;
extern uint8_t WAV_start33, WAV_size33;
extern uint8_t WAV_start34, WAV_size34;
extern uint8_t WAV_start35, WAV_size35;
extern uint8_t WAV_start36, WAV_size36;
extern uint8_t WAV_start37, WAV_size37;
extern uint8_t WAV_start38, WAV_size38;
extern uint8_t WAV_start39, WAV_size39;
extern uint8_t WAV_start40, WAV_size40;
extern uint8_t WAV_start41, WAV_size41;
extern uint8_t WAV_start42, WAV_size42;
extern uint8_t WAV_start43, WAV_size43;
extern uint8_t WAV_start44, WAV_size44;
extern uint8_t WAV_start45, WAV_size45;
extern uint8_t WAV_start46, WAV_size46;
extern uint8_t WAV_start47, WAV_size47;
extern uint8_t WAV_start48, WAV_size48;
extern uint8_t WAV_start49, WAV_size49;
extern uint8_t WAV_start50, WAV_size50;
extern uint8_t WAV_start51, WAV_size51;
extern uint8_t WAV_start52, WAV_size52;
extern uint8_t WAV_start53, WAV_size53;
extern uint8_t WAV_start54, WAV_size54;
extern uint8_t WAV_start55, WAV_size55;
extern uint8_t WAV_start56, WAV_size56;
extern uint8_t WAV_start57, WAV_size57;
extern uint8_t WAV_start58, WAV_size58;
extern uint8_t WAV_start59, WAV_size59;
extern uint8_t WAV_start60, WAV_size60;
extern uint8_t WAV_start61, WAV_size61;
extern uint8_t WAV_start62, WAV_size62;
extern uint8_t WAV_start63, WAV_size63;
#endif

#define MACRO_EXPAND(x) #x
#define MACRO_TOSTRING(x) MACRO_EXPAND(x)

#endif /* WAV_LINKER_H_ */
