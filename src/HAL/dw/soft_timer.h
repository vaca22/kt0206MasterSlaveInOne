#ifndef __SOFT_TIMER_H__
#define __SOFT_TIMER_H__


typedef enum
{
    SOFT_TIMER0,
    SOFT_TIMER1, //Jack_InsRmvDet_ByGpio
    SOFT_TIMER2, //key_release_detect
    SOFT_TIMER3,
    SOFT_TIMER4,
    SOFT_TIMER5,  //prevent the DAC turning on and off too frequently
    SOFT_TIMER_NUM
}soft_timer_id_e;

#define MS_TO_SOFT_TIMER(x) ((x) * 1)

extern void softtimer_init(void);
extern void softtimer_uninit(void);
extern uint16_t softtimer_start(soft_timer_id_e eID, uint32_t usDelay, void(*CallBack)(void));
extern uint16_t softtimer_stop(soft_timer_id_e eID);


#endif 
