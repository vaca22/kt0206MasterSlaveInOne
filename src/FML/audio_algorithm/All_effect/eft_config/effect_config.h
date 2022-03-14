#ifndef EFFECT_CONFIG_H_
#define EFFECT_CONFIG_H_

#include "chip_config.h"
    //定义芯片有可能开启的一些音效，在使用过程中一定不会开启的音效定义0，就不把代码编译进去
    //此处不是音效的使能，是决定音效代码是否编译进去

    #if defined(KT0200) || defined(KT0201)
        #define EFFECT_ECHO_EN              0
        #define EFFECT_PITCHSHIFT_EN        0
        #define EFFECT_REVERB_EN            0
        #define EFFECT_SURROUND3D_EN        0
        // #define EFFECT_NOISEGATE_EN         0
        // #define EFFECT_COMPANDER_EN         0
        #define EFFECT_HOWLSUPRESS_EN       0
        // #define EFFECT_AGC_EN               0
        #define EFFECT_DEESSER_EN           0
        // #define EFFECT_EQ_EN                1
        #define EFFECT_POST_SIDETONE_EN     0//加在后面的sidetone
    #endif
#endif
