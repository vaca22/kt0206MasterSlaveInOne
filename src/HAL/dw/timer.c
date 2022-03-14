
#include "timer.h"        // timer definition
#include "reg_timer.h"    // register timer
#include "clk.h"

typedef struct tim_env_stru {
    timer_handler handler[TIM_ID_NUM];
    uint32_t uCur_ms;
} tim_env_t;

#define TIM_ID_TICK_CNT     INTC_ID_TIMER0
#define TIM_ID_DELAY        TIMER1
/// Delay between 2 values of timer
#define TIM_DELAY_NOW()      ((uint32_t)TIMER_CURR_VAL_MASK - timer_curr_val_getf(TIM_ID_DELAY))

/*
 * GLOBAL VARIABLE DECLARATION
 ****************************************************************************************
 */
extern tim_env_t g_stTim_env;
extern uint32_t g_uLoadcount;    //load count value

uint32_t get_msecond_count(void)
{
    g_uLoadcount = Get_APB_Clk() / 1000;
    return g_uLoadcount;
}

void timer_isr_period(uint32_t uId)
{
    uint32_t tim_id;

    if((uId > INTC_ID_TIMER3) || (uId < INTC_ID_TIMER0)) 
    {
        return;
    }
    tim_id = uId - INTC_ID_TIMER0;
    timer_eoi_get(tim_id);
    if(g_stTim_env.handler[tim_id])
    {
        g_stTim_env.handler[tim_id]();
    }
}


void timer_start_period(tim_id_t eId, uint16_t usMs, timer_handler handler, tim_unit_t eUnit)
{
    /* init timer
     * Disable the timer to avoid potential ysnchronization problems
     */
    timer_control_pack(eId,					    /*timer id */
                       TIM_DIS,                 /* 02 int_mask */
                       TIM_MODE_USER_CNT,       /* 01     mode */
                       TIM_DIS);                /* 00   enable */

    /* Load timer counter value */
    if(TIM_US == eUnit)
    {
    	timer_load_cnt_setf(eId, usMs * (g_uLoadcount/1000));
    }
    else if(TIM_MS == eUnit)
    {
    	timer_load_cnt_setf(eId, usMs * g_uLoadcount);
    }

    g_stTim_env.handler[eId] = handler;

    /* Enable timer */
    timer_enable_setf(eId, TIM_EN);

    /*register interrupt handle*/
    intc_enable_set(INTC_ID_TIMER0 + eId, timer_isr_period);
}

void timer_delay_length(uint16_t usNum, tim_unit_t eUnit)
{
    uint32_t uDelay = 0;

    (void)get_msecond_count();
    switch(eUnit)
    {
        case TIM_US:
            uDelay = usNum * g_uLoadcount / 1000;
            break;
        case TIM_MS:
            uDelay = usNum * g_uLoadcount;
            break;
    }

    timer_control_pack(TIMER1,
                       TIM_EN,                 /* 02 int_mask */
                       TIM_MODE_FREERUN,        /* 01     mode */
                       TIM_DIS);                /* 00   enable */


    /* Load timer counter value */
    timer_load_cnt_setf(TIMER1, TIMER_CURR_VAL_MASK);

    /* Enable timer */
    timer_enable_setf(TIMER1, TIM_EN);

    while (TIM_DELAY_NOW() < uDelay);

    timer_enable_setf(TIMER1, TIM_DIS);
}

/// @} TIMER
