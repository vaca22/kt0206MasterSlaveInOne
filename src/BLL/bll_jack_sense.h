#ifndef _BLL_JACK_SENSE_H_
#define _BLL_JACK_SENSE_H_

#include "com_includes.h"

typedef struct usb_3p5_ftable_stru
{
	void (*Insert)(void);
	void (*Complet)(uint8_t);
	void (*Remove)(uint8_t);
	void (*Start)(uint8_t);
	void (*Stop)(uint8_t);
    void (*Init)(void);
} usb_3p5_ftable_t;

extern void EarPhone_Complet_Process(uint8_t ucPloeFlag);
extern void TypecTo3p5_Init(void);
extern void usb_3p5_patch_init(void);
void new_usb_3p5_patch_init(void);
void jacksense_detect_Schedule(void);
#endif
