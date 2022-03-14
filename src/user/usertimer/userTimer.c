#include "userTimer.h"
#define USER_TIMER_MAX_USE 10 //为了资源考虑，最多10个事件同时使用这个定时器
// timerSetStruct* userTimerSetStart=NULL; 
// timerSetStruct* userTimerSetStop=NULL; 
// timerSetStruct* userTimerSetCurrent=NULL; 
static timerSetStruct userTimerSet[USER_TIMER_MAX_USE];
static uint32_t minStopTimer=0xffffffff;
static uint8_t minTimerIndex=USER_TIMER_MAX_USE;
void userTimerInit(void)
{
	timer_tick_init();
    uint8_t i=0;
    for(i=0;i<USER_TIMER_MAX_USE;i++)
    {
        (userTimerSet+i)->pFunc=NULL;
        (userTimerSet+i)->timerStatus=timerStop;
    }
}

void addUserTimerEvent(void (*pEvent)(void) ,uint32_t delayTime,timerTypeEnum timerType)
{
    uint8_t i=0;
    for(i=0;i<USER_TIMER_MAX_USE;i++)
    {
        if((userTimerSet+i)->pFunc==NULL)
        {
            (userTimerSet+i)->pFunc=pEvent;
            (userTimerSet+i)->timerNeedCounter=delayTime;
            (userTimerSet+i)->timerType=timerType;
            (userTimerSet+i)->startTimer=timer_tick_ms_get();
            (userTimerSet+i)->stopTimer=(userTimerSet+i)->startTimer+delayTime;
            if(minStopTimer>(userTimerSet+i)->stopTimer)
            {
                minStopTimer=(userTimerSet+i)->stopTimer;
                minTimerIndex=i;
            }
            break;
        }
    }
    if(i>=10)
    {
        DBG_OUT_INFO("addUserTimerEvent fail\n ");
    }
}

void removeUserTimerEvent(void (*pEvent)(void))
{
    uint8_t i=0;
    for(i=0;i<USER_TIMER_MAX_USE;i++)
    {
        if((userTimerSet+i)->pFunc==pEvent)
        {
            (userTimerSet+i)->pFunc=NULL;
            if(minStopTimer==(userTimerSet+i)->stopTimer)
            {
                refreshMin();
            }
            break;
        }
    }
    if(i>=10)
    {
        DBG_OUT_INFO("removeUserTimerEvent fail\n ");
    }
}

void UserTimerProcess(void)
{
    if(timer_tick_ms_get()>=minStopTimer)
    {
        (userTimerSet+minTimerIndex)->pFunc();
        if((userTimerSet+minTimerIndex)->timerType==timerOnce)
        {
            (userTimerSet+minTimerIndex)->pFunc=NULL;
        }
        else
        {
            (userTimerSet+minTimerIndex)->stopTimer += (userTimerSet+minTimerIndex)->timerNeedCounter;
        }
        refreshMin();
    }
}

void refreshMin(void)
{
    uint8_t j=0;
    minStopTimer=0xffffffff;
    minTimerIndex=USER_TIMER_MAX_USE;
    for(j=0;j<USER_TIMER_MAX_USE;j++)
    {
        if((userTimerSet+j)->pFunc!=NULL)
        {
            if(minStopTimer>(userTimerSet+j)->stopTimer)
            {
                minStopTimer=(userTimerSet+j)->stopTimer;
                minTimerIndex=j;
            }
        }
    }
}
