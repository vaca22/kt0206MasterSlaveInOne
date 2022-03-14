/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_ch9.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef _UART_IAP_H_
#define _UART_IAP_H_
#include <string.h>
#include "arch.h"
#include "co_math.h"
#include "intc.h"
#include "uart.h"
#include "timer.h"
#include "reg_access.h"
// #include "Usb_intr.h"
// #include "string.h"
// #include "usb_com.h"
// #include "usb_audio_app.h"
// #include "usb_hid_app.h"
// #include "usb_audio_desc.h"
// #include "usb_hid_desc.h"
//#include "usb_mass_desc.h"
// #include "asrc_dac_fs_ppm.h"
// #include "ymodem.h"
#include "qspi_ctrl.h"

#define Space                   (0x20)
#define BackSpace               (0x08)
#define Enter                   (0x0D)

#define IAP_ENTER_DOWNLOAD		(0x80)
#define IAP_BAUDRATE_SET		(0x81)
#define IAP_EXIT_DOWNLOAD		(0x82)
#define IAP_RESET				(0x83)
#define IAP_CFG_INF				(0x84)
#define IAP_READ				(0x85)
#define IAP_READ_CRC			(0x86)
#define IAP_READ_FLASH_ID		(0x87)
#define IAP_WRITE       		(0x88)
#define IAP_FLASH_WRITE  		(0x89)
#define IAP_FLASH_WRITE_CHECK	(0x8A)
#define IAP_FLASH_ERASE_WRITE	(0x8B)
#define IAP_FLASH_ERASE_WRITE_CHECK	    	(0x8C)
#define IAP_FLASH_ERASE	    	(0x8D)

#define PACKET_CMD_INDEX      	(0)
#define PACKET_CMD_LEN       	(1)
#define PACKET_CRC_LEN          (2)

extern void Soft_Reset(void);
extern uint32_t IAP_Init(void);
extern uint8_t IAP_GetChar(uint8_t *pu8Char);

#endif//USB_CDC_H_

