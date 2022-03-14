/*
 * timer test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

void timer_test(void)
{
	api_ret_value_e eRetValue = api_gpio_toggle(API_GPIO_3);
}

void _user_schedule(void)
{
    // TODO add your own code
	api_ret_value_e eRetValue = api_timer_delay(20, API_TIM_US);
}

void _user_init(void)
{
    // TODO add your own code
    api_ret_value_e eRetValue;

	eRetValue = api_gpio_func_set(API_GPIO_3, API_GPIO_Func5);
	eRetValue = api_timer_start(API_TIMER_0, 20, API_TIM_MS, (api_timer_handler)timer_test);
}
