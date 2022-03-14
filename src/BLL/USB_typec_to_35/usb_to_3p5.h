#ifndef _USB_TO_3P5_H_
#define _USB_TO_3P5_H_

extern void EarPhone_Insert_Process(void);
extern void EarPhone_Complet_Process(uint8_t ucPloeFlag);
extern void EarPhone_Remove_Process(uint8_t ucPloeFlag);
extern void TypecTo3p5_Start(uint8_t ucPloeFlag);
extern void TypecTo3p5_Stop(uint8_t ucPloeFlag);
extern void TypecTo3p5_Init(void);
void usb_3p5_patch_init(void);
void new_usb_3p5_patch_init(void);
#endif
