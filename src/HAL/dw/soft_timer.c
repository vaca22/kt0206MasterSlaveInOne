#include "comm.h"
#include "soft_timer.h"
#include "stddef.h"
#include "stdint.h"
#include "timer.h"
#include "gpio_ctrl.h"

typedef struct
{
	volatile uint32_t uFlag;
	volatile uint32_t uDelayTime;
	volatile uint32_t uDelayTimeLoad;
	void (*CallBack)(void);
}soft_timer_t;

soft_timer_t g_stSoftTimer[SOFT_TIMER_NUM];

void softtimer_isr(void)
{
	uint32_t i;
	for(i = 0; i < SOFT_TIMER_NUM; i++)
	{
		if(g_stSoftTimer[i].uFlag)
		{
			g_stSoftTimer[i].uDelayTime--;
			if(0 == g_stSoftTimer[i].uDelayTime)
			{
				g_stSoftTimer[i].uDelayTime = g_stSoftTimer[i].uDelayTimeLoad;
				g_stSoftTimer[i].CallBack();
			}
		}
	}
}

void softtimer_init(void)
{
	uint8_t i;

	for(i = 0; i < SOFT_TIMER_NUM; i++)
	{
		g_stSoftTimer[i].uFlag = 0;
		g_stSoftTimer[i].uDelayTime = 0;
		g_stSoftTimer[i].uDelayTimeLoad = 0;
		g_stSoftTimer[i].CallBack = NULL;
	}

	timer_start_period(TIMER3, 1, softtimer_isr, TIM_MS);
}

void softtimer_uninit(void)
{
	uint32_t i;

	timer_end(TIMER3);
	for(i = 0; i < SOFT_TIMER_NUM; i++)
	{
		g_stSoftTimer[i].uFlag = 0;
		g_stSoftTimer[i].uDelayTime = 0;
		g_stSoftTimer[i].uDelayTimeLoad = 0;
		g_stSoftTimer[i].CallBack = NULL;
	}
}

uint16_t softtimer_start(soft_timer_id_e eID, uint32_t usDelay, void(*CallBack)(void))
{
	if((eID < SOFT_TIMER_NUM) && (usDelay != 0) && (CallBack != NULL))
	{
		g_stSoftTimer[eID].uFlag = 1;
		g_stSoftTimer[eID].uDelayTime = usDelay;
		g_stSoftTimer[eID].uDelayTimeLoad = usDelay;
		g_stSoftTimer[eID].CallBack = CallBack;
		return OK;
	}
	else
	{
		return ERR;
	}
}

uint16_t softtimer_stop(soft_timer_id_e eID)
{
	if(eID < SOFT_TIMER_NUM)
	{
		g_stSoftTimer[eID].uFlag = 0;
		g_stSoftTimer[eID].uDelayTime = 0;
		g_stSoftTimer[eID].uDelayTimeLoad = 0;
		g_stSoftTimer[eID].CallBack = NULL;
		return OK;
	}
	else
	{
		return ERR;
	}
}
