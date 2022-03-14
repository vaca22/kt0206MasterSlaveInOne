/*
 * uart test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

uint8_t g_ucTestData = 0;
void _user_schedule(void)
{
	// TODO add your own code
    api_timer_delay(100, API_TIM_MS);
    if(g_ucTestData == 0)
    {
    	api_print_string("hello word!\n");
    }
    else if(g_ucTestData == 'a')
    {
    	api_print_string("a!\n");
    }
    else if(g_ucTestData == 'b')
    {
    	api_print_string("b!\n");
    }
    else
    {
    	api_print_string("c!\n");
    }

    if(api_uart_in_waiting() > 0)
    {
    	api_uart_read(&g_ucTestData, 1);
    }
}

void _user_init(void)
{
	// TODO add your own code
    api_gpio_func_set(API_GPIO_3, API_GPIO_Func2);
    api_gpio_func_set(API_GPIO_4, API_GPIO_Func2);
    api_uart_init(115200);
}
