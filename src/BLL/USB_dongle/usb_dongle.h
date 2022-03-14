/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_DONGLE_H_
#define USB_DONGLE_H_

#include"nds32_math_types.h"
#include"comm.h"
#include "usb_com.h"
#include "usb_ch9.h"
#include "usb_hid_app.h"
#include "usb_app.h"
#include "audio_process_adc2usb.h"
#include "audio_process_usb2dac.h"
#include "dsp.h"
#include "audio_in.h"
#include "audio_out.h"

void USB_ConfigDongle(void);
void USB_UnConfigDongle(void);
void usb_dongle_patch_init(void);
void new_usb_dongle_patch_init(void);
#endif//USB_HEADPHONE_H_

