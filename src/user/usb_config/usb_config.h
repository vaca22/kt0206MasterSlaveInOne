#ifndef _USB_CONFIG_H_
#define _USB_CONFIG_H_

#include "usb_com.h"
#include "bll_config.h"
#include "usb_ch9.h"
#include "user.h"


extern const USB_DEVICE_DESCRIPTOR g_userDeviceDesc;
void setUsbUserConfig(USB_OTP *pstOTP);


#endif
