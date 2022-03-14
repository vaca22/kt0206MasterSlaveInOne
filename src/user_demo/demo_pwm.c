/*
 * pwm test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

void _user_schedule(void)
{
    // TODO add your own code

}

void _user_init(void)
{
    // TODO add your own code
    api_ret_value_e eRetValue;
#if 0
	eRetValue = api_gpio_func_set(API_GPIO_6, API_GPIO_Func11);
	eRetValue = api_pwm_init(API_PWM_0, 0x1, 0x1);
	eRetValue = api_pwm_start(API_PWM_0);
#else //output fixed pwm wave
	api_gpio_func_set(API_GPIO_6, API_GPIO_Func11);
	api_pwm_duty_ratio(API_PWM_0, 100);// 1 ~ 255
#endif
	// eRetValue = api_gpio_func_set(API_GPIO_7, API_GPIO_Func11);
	// eRetValue = api_pwm_init(API_PWM_1, 0x1, 0x1);
	// eRetValue = api_pwm_start(API_PWM_1);

	// eRetValue = api_gpio_func_set(API_GPIO_8, API_GPIO_Func11);
	// eRetValue = api_pwm_init(API_PWM_2, 0x1, 0x1);
	// eRetValue = api_pwm_start(API_PWM_2);
}
