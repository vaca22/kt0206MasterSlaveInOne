/*
 * power_off.h
 *
 *  Created on: May 8, 2018
 *      Author: chenbowen
 */

#ifndef POWER_OFF_H_
#define POWER_OFF_H_

#include "reg_apb.h"
#include "audio.h"
#include "power_on.h"

extern void Charge_pump_PowerOff(void);
extern void Audio_DAC_normal_PowerOff(void);
extern void Audio_DAC_fast_PowerOff(void);
extern void Audio_DAC_fast_PowerOff_ISR(void);
extern void Audio_ADC_PowerOff(void);
extern void SarADC_PowerOff(void);
extern void XTAL_PowerOff(void);
extern void High_Freq_OSC_PowerOff(void);

extern void Dongle_PowerOff(void);
extern void Headset_PowerOff(void);
extern void Headphone_PowerOff(void);
extern void TYPE_C_To_3P5_PowerOff(void);

extern void power_off_patch_init(void);
void new_power_off_patch_init(void);
void PD_Det_Volt_Thre_Set(uint8_t threshold);

#endif /* POWER_OFF_H_ */
