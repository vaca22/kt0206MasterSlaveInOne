/*
 * user global variable init test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

uint8_t g_UserFlag = 0x88;

void _user_schedule(void)
{
	// TODO add your own code
    api_timer_delay(100, API_TIM_MS);
    if(g_UserFlag == 0x88)
    {
        api_print_string("variable initialized!\n");
    }
    else
    {
        api_print_string("variable uninitialized!\n");
    }
}

void _user_init(void)
{
	// TODO add your own code
    api_gpio_func_set(API_GPIO_3, API_GPIO_Func2);
    api_gpio_func_set(API_GPIO_4, API_GPIO_Func2);
    api_uart_init(115200);
}
