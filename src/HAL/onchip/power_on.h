/*
 * power_on.h
 *
 *  Created on: May 8, 2018
 *      Author: chenbowen
 */

#ifndef POWER_ON_H_
#define POWER_ON_H_

#include "com_includes.h"
#include "reg_apb.h"
#include "earphone_key_detect.h"
#include "audio.h"

extern uint8_t ucHighRailCpClk;
extern uint8_t ucLowRailCpClk;
extern void pga_init(void);
extern void osc_cali_code_config(uint8_t ucOscCaliCode);
extern void High_Freq_OSC_PowerOn(uint8_t ucOscCaliCode);
extern void Xtal_PowerOn(void);
extern void SarADC_PowerOn(void);
extern void ADC_RC_Cali_PowerOn(void);
extern void DAC_Current_Cali_PowerOn(void);
extern void Audio_ADC_PowerOn(void);
extern void Audio_DAC_PowerOn(void);
extern void Itrim_Monitor(void);

extern void Dongle_PowerOn(void);
extern void Headset_PowerOn(void);
extern void Headphone_PowerOn(void);
extern void TYPE_C_To_3P5_PowerOn(uint8_t ucMicbiasSel);

extern void power_on_patch_init(void);
extern void new_power_on_patch_init(void);

void chipPowerOn(void);

#endif /* POWER_ON_H_ */
