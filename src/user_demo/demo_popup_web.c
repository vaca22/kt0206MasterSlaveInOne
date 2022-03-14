/*
 * pop-up web test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

/*
typedef struct {
    uint8_t u8CtrlKeyFlag;
    uint8_t u8ReservedBytes;
    uint8_t u8KeyValue[6];
}USB_KeyBoard_Report_t;
*/
const uint8_t ucTestWebStr[] = {
    0x08, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, //win + r
    0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, //capslock
    0x00, 0x00, 0x1A, 0x00, 0x1A, 0x00, 0x1A, 0x00, //www
    0x00, 0x00, 0x37, 0x0E, 0x17, 0x10, 0x0C, 0x06, //.ktmic
    0x00, 0x00, 0x15, 0x12, 0x37, 0x06, 0x12, 0x10, //ro.com
    0x00, 0x00, 0x37, 0x06, 0x11, 0x00, 0x00, 0x00, //.cn
    0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, //enter
    0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, //capslock
};
uint16_t g_usCounter = 0;
uint16_t g_usSendFlag = 1;

void _user_schedule(void)
{
    // TODO add your own code
    if(g_usSendFlag)
    {
        api_timer_delay(100, API_TIM_MS);
        g_usCounter++;
        if(g_usCounter == 25)
        {
            api_keyboard_continue_send((uint8_t*)ucTestWebStr, sizeof(ucTestWebStr));
            g_usSendFlag = 0;
        }
    }
}

void _user_init(void)
{
    // TODO add your own code
    api_keyboard_support_cfg(1);
}
