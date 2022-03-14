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
    
}

void _user_init(void)
{
    // TODO add your own code
	api_usbmic_set(API_USBMIC_1_CHANNEL, API_USBMIC_ADC_IN, API_USBMIC_L_R_IN);
}
