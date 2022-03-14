/*
 * GPIO test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

void _user_schedule(void)
{
    // TODO add your own code
	(void)api_gpio_toggle(API_GPIO_3);
    api_timer_delay(100, API_TIM_MS);
}

void _user_init(void)
{
    // TODO add your own code
    api_ret_value_e eRetValue;

	eRetValue = api_gpio_func_set(API_GPIO_3, API_GPIO_Func5);
	eRetValue = api_gpio_func_set(API_GPIO_3, API_GPIO_Func6);
}
