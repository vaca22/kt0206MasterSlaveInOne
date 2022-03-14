/**
 ****************************************************************************************
 *
 * @file timer.h
 *
 * @brief TIMER Driver.
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 ****************************************************************************************
 */

#ifndef _TIMER_H_
#define _TIMER_H_

/**
 ****************************************************************************************
 * @defgroup TIMER
 * @ingroup DRIVERS
 *
 * @brief Timer driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>      // standard integer definition
#include "intc.h"
#include "reg_apb.h"

//#define TIMER_NUM	8

/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

///Modes
enum {
    TIM_MODE_FREERUN,
    TIM_MODE_USER_CNT,
    TIM_MODE_NUM
};

///State
enum {
    TIM_DIS,
    TIM_EN,
};

/*
 * STRUCT DEFINITIONS
 ****************************************************************************************
 */
typedef enum tim_id_enum {
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIM_ID_NUM
} tim_id_t;

///State
typedef enum tim_unit {
    TIM_MS,
    TIM_US,
}tim_unit_t;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

typedef void (*timer_handler)(void);

/**
 ****************************************************************************************
 * @brief Initialize the timer1 as a count-down counter at 13MHz
 *
 ****************************************************************************************
 */

extern void timer_init(void);
extern void timer_tick_init(void);
extern void timer_delay(uint16_t usMs);
extern void timer_start(tim_id_t eId, uint16_t usMs, timer_handler handler, tim_unit_t eUnit);
extern void timer_start_period(tim_id_t eId, uint16_t usMs, timer_handler handler, tim_unit_t eUnit);
extern void timer_end(tim_id_t eId);

/**
 ****************************************************************************************
 * @brief Waits for the passed number of microseconds.
 *
 * @param us  Number of the us to wait for. Maximum supported value is 1000us
 *
 ****************************************************************************************
 */
extern uint32_t timer_tick_ms_get(void);
extern void timer_delay_length(uint16_t usNum, tim_unit_t eUnit);
extern uint32_t get_msecond_count(void);


/// @} TIMER

#endif /* _TIMER_H_ */
