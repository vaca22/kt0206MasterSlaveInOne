/**
 ****************************************************************************************
 *
 * @file plf_init.c
 *
 * @brief Main loop of the application.
 *
 * @author WeighSong
 *
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "user.h"
#include "suspend.h"
#include "usb_cdc.h"
/**
 ****************************************************************************************
 * @addtogroup DRIVERS
 * @{
 *
 *
 * ****************************************************************************************
 */

void tim_test_handle(void)
{
	DEBUG_GPIO1_CLR();
}

int main(void) 
{
    intc_init();
	timer_init();
    GLOBAL_INT_START();

    while(1) {
    	/*timer delay test*/
    	// DEBUG_GPIO1_SET();
    	// timer_delay(5);
    	// DEBUG_GPIO1_CLR();
    	// timer_delay(10);

    	/*tickcount test*/
//    	LOG_INFO("schedule");
//    	tim_delay(500);

    	/*timer test*/
   	DEBUG_GPIO1_SET();
   	timer_start(TIMER2, 5, tim_test_handle, TIM_US);
    timer_delay(5);
   	DEBUG_GPIO1_SET();
   	timer_start(TIMER3, 5, tim_test_handle, TIM_US);
    timer_delay(10);



//    	tim_delay(500);
    }
}
