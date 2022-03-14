#ifndef _USERTIMER_H_
#define _USERTIMER_H_
#include <stdint.h>
#include "timer.h"
#include "debug.h"

typedef enum
{
    timerNeedStrat,
    timerStarting,
    timerStop,
}timerStatusEnum;

typedef enum
{
    timerOnce,
    timerPeriod,
}timerTypeEnum;

typedef struct _timerSetStruct
{
    uint32_t startTimer;
    uint32_t stopTimer;
    uint32_t timerNeedCounter;
    timerStatusEnum timerStatus;
    timerTypeEnum timerType;
    void (*pFunc)(void);
    struct _timerSetStruct* pNextTimerSet;
}timerSetStruct;

void userTimerInit();//在用户初始化函数的地方调用
void addUserTimerEvent(void (*pEvent)(void) ,uint32_t delayTime,timerTypeEnum timerType);//delayTime单位是ms
void removeUserTimerEvent(void (*pEvent)(void));//移除某个函数的定时器
void UserTimerProcess(void);//在主循环里面调用
void refreshMin(void);//userTimer.c内部使用的函数

#endif
