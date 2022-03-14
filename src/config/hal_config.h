#ifndef _HAL_CONFIG_H_
#define _HAL_CONFIG_H_

/*                         audio_in
                              |
            ________(DONGLE_AUDIO_IN_SEL)________
            |                 |                 |
           ADC              I2S_M             I2S_S
            |                 |_________________|
            |                           |
            |                 (DONGLE_AUDIO_IN_CFG)
            |             0_____________|_______________1
            |              |       |         |         |
            |             left   right     left      right
            |              |_______|         |         |
            |                  |             |         |
        (Algorithm)       (Algorithm)   (Algorithm)(Algorithm)
        ____|____          ____|____         |         |
        |       |          |       |         |         |
      left    right      left    right     left      right
        |       |          |       |         |         |
       LRB     RRB        LRB     RRB       LRB       RRB
________________________________________________________________________

                        LRB         RRB
                         |___________|
                               |
                      (DONGLE_USB_IN_CFG)
            0__________________|__________________1
    ________|________                     ________|________
    |               |                     |               |
TempL=LRB       TempR=RRB      TempL=(LRB+RRB)>>1    TempR=(LRB+RRB)>>1
________________________________________________________________________

                    TempL           TempR
                      |_______________|
                              |
                   (DONGLE_USB_IN_CHANNEL)
                1_____________|_____________2
            ____|____                   ____|____
            |       |                   |       |
        ch1=TempL   x             ch1=TempL   ch2=TempR
            |_______|___________________|_______|
                              |
                            usb_in
*/

#include <stdint.h>

#define SUPPORT       1
#define NORSUPPORT    0
#define ENABLE        1
#define DISABLE       0

//#define FUN_UART_EN
//#define FUN_I2C_SLAVE_EN
#define SUPPORT_PREVIOUS_NEXT_FOR_PC		1//0  //0->not support, 1->support
#define APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG   0  //0->nonsupport, 1->support
#define SUPPORT_USB_KEYBOARD_CFG            0  //0->nonsupport, 1->support  //find  pDSP->isSupportKeyboard
// #define JACK_SENSE_CFG                   0  //0->jack sense hardware, 1->GPIO key hardware
// #if JACK_SENSE_CFG
// #define EarphoneInsert_GPIOlevel			1  //0->inser earphone,gpio3==0,1->inser earphone,gpio3==1;
// #endif

#define DONGLE_AUDIO_IN_SEL                     1  //0-> DONGLE_ADC_IN   1->DONGLE_I2S_MASTER_IN   2->DONGLE_I2S_SLAVE_IN
#define DONGLE_AUDIO_IN_CFG                     0  //0->left + right 1->left | right
#define DONGLE_USB_IN_CFG                       1  //0->left | right  1->left + right
#define DONGLE_USB_IN_CHANNEL                   2  //1->1 channel, 2->2 channel

#define THD_COMPENSATE_DBG_CFG                  0  //0->THD compensate debug disable, 1->THD compensate debug enable

//#define OSC_CALI_BY_FSM_SRC_USBSOF				1

typedef enum{
    DONGLE_ADC_IN,
    DONGLE_I2S_MASTER_IN,
    DONGLE_I2S_SLAVE_IN,
}dongle_in_sel_e;


#if SUPPORT_USB_KEYBOARD_CFG > 1
    #error SUPPORT_USB_KEYBOARD_CFG config > 1
#endif

#if DONGLE_USB_IN_CHANNEL > 2
    #error DONGLE_USB_IN_CHANNEL config > 2
#endif

#if JACK_SENSE_CFG > 1
    #error JACK_SENSE_CFG config > 1
#endif

extern void SupportUsbKeyboard_Set(uint8_t u8cValue);
extern void UsbMicCfg_Set(uint8_t ucUsbMicChannel, uint8_t ucUsbMicAudioInSel, uint8_t ucUsbMicI2sCfg);

extern uint8_t AUDIO_IN_I2SSEL;
extern uint8_t AUDIO_OUT_I2SSEL;
#endif /* MUSES_H_ */
