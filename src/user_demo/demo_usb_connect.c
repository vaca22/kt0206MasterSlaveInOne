/*
 * usb connect disconnect test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

uint16_t g_usCounter = 0;
uint16_t g_usTestFlag = 0;

void _user_schedule(void)
{
    // TODO add your own code
    if(g_usTestFlag == 0)
    {
        api_timer_delay(100, API_TIM_MS);
        g_usCounter++;
        if(g_usCounter == 100)
        {
            api_disconnect_usb();
            g_usTestFlag = 1;
            g_usCounter = 0;
        }
    }

    if(g_usTestFlag == 1)
    {
        api_timer_delay(100, API_TIM_MS);
        g_usCounter++;
        if(g_usCounter == 100)
        {
            api_connect_usb();
            g_usTestFlag = 2;
            g_usCounter = 0;
        }
    }
}

void _user_init(void)
{
    // TODO add your own code

}
