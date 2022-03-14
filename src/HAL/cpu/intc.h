/**
 ****************************************************************************************
 *
 * @file intc.h
 *
 * @brief Declaration of the Interrupt Controller API.
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 ****************************************************************************************
 */

#ifndef _INTC_H_
#define _INTC_H_

/**
 ****************************************************************************************
 * @addtogroup INTC INTC
 * @ingroup DRIVERS
 *
 * @brief Declaration of the Interrupt Controller API.
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "arch.h"
#include "compiler.h"

/*
 * DEFINES
 ****************************************************************************************
 */

/** @name Mapping of the peripherals interrupts in the interrupt controller.
 * @{
 */
typedef enum intc_id_enum {
    INTC_ID_I2C,                            /* 0 */
	INTC_ID_UART,                           /* 1 */
    INTC_ID_WDT,                            /* 2 */
    INTC_ID_TIMER0,                         /* 3 */
    INTC_ID_TIMER1,                         /* 4 */
    INTC_ID_TIMER2,                         /* 5 */
    INTC_ID_TIMER3,                         /* 6 */
    INTC_ID_USB_CTRL,                       /* 7 */
    INTC_ID_IO_BUF_IN,                      /* 8 */ //audio_in isr
    INTC_ID_IO_BUF_OUT,                     /* 9 */
    INTC_ID_IO_BUF,                         /* 10 */ //audio_out isr
    INTC_ID_HEADSET_SWITCH,                 /* 11 */
    INTC_ID_AUX_ADC,                        /* 12 */
    INTC_ID_PAD_IO,                         /* 13 */
    INTC_ID_D10_PM,                         /* 14 */
    INTC_ID_SWI,                            /* 15 */
    INTC_ID_FM_INTR0,                       /* 16 */
    INTC_ID_FM_INTR1,                       /* 17 */
    INTC_ID_MIC_IN,                         /* 18 */
    INTC_ID_GPIO_KEY,                       /* 19 */
    INTC_ID_TDM0,                           /* 20 */
    INTC_ID_TDM1,                           /* 21 */
    INTC_ID_STDBY_REQ,                      /* 22 */
    INTC_ID_PWDN_DET,                       /* 23 */

    // INTC_ID_BT_ESCO_PORT0,                  /* 23 */
    // INTC_ID_BT_ESCO_PORT1,                  /* 24 */
    // INTC_ID_RFU_3,                          /* 25 */
    // INTC_ID_BT_SLEEP,                       /* 26 */
    // INTC_ID_BT_RCV,                         /* 27 */
    // INTC_ID_BT_SLOT,                        /* 28 */
    // INTC_ID_AUDIO_PATH_PRBS,                /* 29 */
    // INTC_ID_AUDIO_PATH_PCM,                 /* 30 */
    // INTC_ID_AUDIO_PATH_APB2DPV,             /* 31 */

    // INTC_ID_TZ_START,
    // INTC_ID_TZ_VOL_INC = INTC_ID_TZ_START,  /* 32 */
    // INTC_ID_TZ_VOL_DEC,                     /* 33 */
    // INTC_ID_TZ_ON_OFF_NEGE,                 /* 34 */
    // INTC_ID_TZ_ON_OFF_POS,                  /* 35 */
    // INTC_ID_TZ_USB_ON,                      /* 36 */
    // INTC_ID_TZ_CHARGER_DONE,                /* 37 */
    // INTC_ID_TZ_RF_PLL_DONE,                 /* 38 */
    // INTC_ID_TZ_ADC_DET,                     /* 39 */
    // INTC_ID_TZ_RF_PLL_UNLOCK,               /* 40 */
    // INTC_ID_TZ_BB_PLL_UNLOCK,               /* 41 */
    // INTC_ID_RFU_4,                          /* 42 */
    // INTC_ID_RFU_5,                          /* 43 */
    // INTC_ID_RFU_6,                          /* 44 */
    // INTC_ID_RFU_7,                          /* 45 */
    // INTC_ID_RFU_8,                          /* 46 */
    // INTC_ID_RFU_9,                          /* 47 */
    // INTC_ID_TZ_SAR_ADC0_DONE,               /* 48 */
    // INTC_ID_TZ_SAR_ADC1_DONE,               /* 49 */
    // INTC_ID_TZ_SAR_ADC2_DONE,               /* 50 */
    // INTC_ID_TZ_SAR_ADC3_DONE,               /* 51 */
    // INTC_ID_TZ_SAR_ADC4_DONE,               /* 52 */
    // INTC_ID_TZ_SAR_ADC5_DONE,               /* 53 */
    // INTC_ID_TZ_SAR_ADC6_DONE,               /* 54 */
    // INTC_ID_TZ_SAR_ADC7_DONE,               /* 55 */
    // INTC_ID_TZ_SAR_ADC8_DONE,               /* 56 */
    // INTC_ID_TZ_SAR_ADC9_DONE,               /* 57 */
    // INTC_ID_TZ_SAR_ADC10_DONE,              /* 58 */
    // INTC_ID_TZ_SAR_ADC11_DONE,              /* 59 */
    // INTC_ID_TZ_SAR_ADC12_DONE,              /* 60 */
    // INTC_ID_TZ_SAR_ADC13_DONE,              /* 61 */
    // INTC_ID_TZ_SAR_ADC14_DONE,              /* 62 */
    // INTC_ID_TZ_SAR_ADC15_DONE,              /* 63 */

    INTC_ID_NUM
} intc_id_t;


/// @} INTC mapping

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

typedef void (intc_handler)(uint32_t id);

/**
 ****************************************************************************************
 * @brief Initialize and configure the reference interrupt controller.
 *
 * This function configures the interrupt controller according to the system needs.
 *
 ****************************************************************************************
 */
void intc_init(void);

void intc_enable_set(intc_id_t id, intc_handler *handler);
void intc_enable_clr(intc_id_t id);

/**
 ****************************************************************************************
 * @brief Clear status of interrupts.
 *
 * This function clear interrupt status.
 *
 ****************************************************************************************
 */
void intc_stat_clear(void);

void new_intc_init(void);

/// @} INTC

#endif // _INTC_H_
