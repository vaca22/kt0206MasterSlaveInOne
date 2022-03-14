#ifndef _BLL_MISC_H_
#define _BLL_MISC_H_

volatile uint8_t ActiveStandbySt; //0-> passive standby, 1-> active standby
extern int16_t ramp_nco;

#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
volatile uint8_t UsbSuspendSt; //0-> usb active status, 1-> usb supend status
volatile uint8_t LowPowerSt; //0-> not low power status, 1-> low power status
#endif

extern void ROM_Schedule(void);
extern void new_ROM_Schedule(void);

void USB_Audio_Config();

void turnOnDac(void);
void turnOnAdc(void);

#endif
