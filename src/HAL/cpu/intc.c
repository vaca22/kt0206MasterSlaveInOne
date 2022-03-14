/**
 ****************************************************************************************
 *
 * @file intc.c
 *
 * @brief Definition of the Interrupt Controller (INTCTRL) API.
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup INTC
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "ll.h"
#include "compiler.h"
#include <stdint.h>
#include <string.h>
#include "co_math.h"         // math library definition
#include "chip_config.h"
#include "intc.h"

/*
 * DEFINES
 ****************************************************************************************
 */
typedef struct intc_env_stru {
    intc_handler *handler[INTC_ID_NUM];
} intc_env_t;

typedef struct ftable_stru {
    void (*en_set)(intc_id_t id, intc_handler *handler);
    void (*en_clr)(intc_id_t id);
    void (*state_clr)(void);
    void (*isr)(uint32_t id);
} ftable_t;

/*
 * GLOBAL VARIABLE DECLARATION
 ****************************************************************************************
 */
intc_env_t intc_env;
ftable_t *intc_ftable;

/*
 * INTERNAL FUNCTIONS DEFINITIONS
 ****************************************************************************************
 */


/*
 * INTERFACE FUNCTION INSTANCE DEFINITIONS
 ****************************************************************************************
 */
void intc_if_enable_set(intc_id_t id, intc_handler *handler);

void intc_if_enable_clr(intc_id_t id);

void intc_if_isr(uint32_t id);

/*
 * EXPORTED FUNCTIONS DEFINITIONS
 ****************************************************************************************
 */
void intc_enable_set(intc_id_t id, intc_handler *handler)
{
    if (intc_ftable->en_set != NULL) {
        intc_ftable->en_set(id, handler);
    }
}

void intc_enable_clr(intc_id_t id)
{
    if (intc_ftable->en_clr != NULL) {
        intc_ftable->en_clr(id);
    }
}

void intc_stat_clear(void)
{
    if (intc_ftable->state_clr != NULL) {
        intc_ftable->state_clr();
    }
}

void HW_ISR(uint32_t id)
{
    if (intc_ftable->isr != NULL) {
        intc_ftable->isr(id);
    }
}

const ftable_t intc_fi_table = {
    .en_set = intc_if_enable_set,
    .en_clr = intc_if_enable_clr,
    .state_clr = NULL,
    .isr = intc_if_isr,
} ;


void new_intc_init(void)
{
    memset(&intc_env, 0, sizeof(intc_env_t));

    intc_ftable = (ftable_t *)&intc_fi_table;

    /* Check IVIC numbers (IVB.NIVIC) */
    if ((__nds32__mfsr(NDS32_SR_IVB) & 0x0E) != 0) {
        /* set priority */
        __nds32__mtsr(

            (0x1 << (INTC_ID_I2C               * 2)) |   //HW0
            (0x3 << (INTC_ID_UART              * 2)) |   //HW1
            (0x3 << (INTC_ID_WDT               * 2)) |   //HW2
            (0x3 << (INTC_ID_TIMER0            * 2)) |   //HW3
            (0x3 << (INTC_ID_TIMER1            * 2)) |   //HW4
            (0x3 << (INTC_ID_TIMER2            * 2)) |   //HW5
            (0x3 << (INTC_ID_TIMER3            * 2)) |   //HW6
#ifdef	KT0203
            (0x1 << (INTC_ID_USB_CTRL          * 2)) |   //HW7
            (0x1 << (INTC_ID_IO_BUF_IN         * 2)) |   //HW8
			(0x3 << (INTC_ID_IO_BUF_OUT        * 2)) |   //HW9 沒用
            (0x0 << (INTC_ID_IO_BUF            * 2)) |   //HW10
            (0x2 << (INTC_ID_SWI               * 2)) |   //HW15
#else
	#if (AUDIO_SAMPLE_BLOCK_SIZE == 16)
//            (0x2 << (INTC_ID_USB_CTRL          * 2)) |   //HW7
//            (0x1 << (INTC_ID_IO_BUF_IN         * 2)) |   //HW8
//            (0x0 << (INTC_ID_IO_BUF            * 2)) |   //HW10
//            (0x3 << (INTC_ID_SWI               * 2)) |   //HW15
            //DAC FS < = 48k
			(0x1 << (INTC_ID_USB_CTRL          * 2)) |   //HW7
			(0x0 << (INTC_ID_IO_BUF_IN         * 2)) |   //HW8
			(0x3 << (INTC_ID_IO_BUF_OUT        * 2)) |   //HW9 沒用
			(0x0 << (INTC_ID_IO_BUF            * 2)) |   //HW10
			(0x2 << (INTC_ID_SWI               * 2)) |   //HW15
	#else
			(0x0 << (INTC_ID_USB_CTRL          * 2)) |   //HW7 USB
            (0x1 << (INTC_ID_IO_BUF_IN         * 2)) |   //HW8 ADC
            (0x1 << (INTC_ID_IO_BUF            * 2)) |   //HW10 DAC
            (0x1 << (INTC_ID_IO_BUF_OUT        * 2)) |   //HW9 I2S OUT SLAVE
            (0x2 << (INTC_ID_SWI               * 2)) |   //HW15
    #endif
#endif

            
            (0x3 << (INTC_ID_HEADSET_SWITCH    * 2)) |   //HW11
            (0x3 << (INTC_ID_AUX_ADC           * 2)) |   //HW12
            (0x3 << (INTC_ID_PAD_IO            * 2)) |   //HW13
            (0x3 << (INTC_ID_D10_PM            * 2)) |   //HW14
            0, NDS32_SR_INT_PRI);

        __nds32__mtsr(
            (0x3 << (INTC_ID_FM_INTR0          * 2 - 32)) |   //HW16
            (0x3 << (INTC_ID_FM_INTR1          * 2 - 32)) |   //HW17
            (0x3 << (INTC_ID_MIC_IN            * 2 - 32)) |   //HW18
            (0x3 << (INTC_ID_GPIO_KEY          * 2 - 32)) |   //HW19
            (0x3 << (INTC_ID_TDM0              * 2 - 32)) |   //HW20
            (0x3 << (INTC_ID_TDM1              * 2 - 32)) |   //HW21
            (0x3 << (INTC_ID_STDBY_REQ         * 2 - 32)) |   //HW22
            (0x0 << (INTC_ID_PWDN_DET          * 2 - 32)) |   //HW23
            0, NDS32_SR_INT_PRI2);

        /* Mask all interrupt */
        __nds32__mtsr(0, NDS32_SR_INT_MASK2);

        /* Interrupt pending register, write 1 to clear */
        __nds32__mtsr(0xFFFFFFFF, NDS32_SR_INT_PEND2);
    }
}

/// @} INTC
