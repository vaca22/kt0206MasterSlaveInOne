/*
 * saradc test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>
#include <stdio.h>


void _user_schedule(void)
{
    // TODO add your own code
	uint16_t u16SaradcValue;
	char ucTmpBuf[16];
    api_timer_delay(100, API_TIM_MS);
	u16SaradcValue = api_saradc_value_get(2, API_SARADC_GPIO1);
	sprintf(ucTmpBuf,"ADC=0x%04X \n", u16SaradcValue);
    api_print_string(ucTmpBuf);
}

void _user_init(void)
{
    // TODO add your own code
    api_gpio_func_set(API_GPIO_3, API_GPIO_Func2);
    api_gpio_func_set(API_GPIO_4, API_GPIO_Func2);
    api_uart_init(115200);

	api_ret_value_e eRetValue = api_gpio_func_set(API_GPIO_1, API_GPIO_Func4);
	if(API_OK == eRetValue)
	{
    	api_print_string("GPIO1 set to adcin ok!\n");
	}
	else
	{
    	api_print_string("GPIO1 set to adcin err!\n");
	}
}
