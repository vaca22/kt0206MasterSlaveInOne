/*
 * Effect.h
 *
 *  Created on: Nov 7, 2019
 *      Author: lisy
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include "KT0203_Drv.h"

extern const DSP_Echo_Para_t UserEchoConfig[];            // Echo配置
extern const DSP_Reverb_Para_t  UserReverbConfig[];       // 混响配置
extern const DSP_EQ_Para_t UserEQPara[][7];               // EQ配置

//啸叫抑制
extern const DSP_Howling_Detect_Para_t		UserHowlingDetectConfig[];
extern const DSP_Howling_Avc_Para_t 		UserHowlingAvcConfig[];
extern const DSP_HowlingNotch_Para_t		UserHowlingNotchConfig[];
extern const DSP_HowlingCtrl_Para_t 		UserHowlingCtrlEn;  // ��
extern const DSP_HowlingCtrl_Para_t 		UserHowlingCtrlDis; // ��


#endif /* EFFECT_H_ */
