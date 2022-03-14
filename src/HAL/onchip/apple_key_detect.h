/*
 *
 */

#ifndef _APPLE_KEY_DETECT_H_
#define _APPLE_KEY_DETECT_H_

#include "com_includes.h"

extern volatile uint8_t g_ucCloseAppleKeyDetFlg; //0->open apple earphone key det, 1->close earphone key det
extern uint8_t g_ucButtType;

extern void key_decoder_init(void);
extern void key_fifo_check(void);
extern uint8_t KEY_decoder(void);
uint8_t Apple_KEY_decoder(void);

#endif 
