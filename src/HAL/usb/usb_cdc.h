/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_ch9.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_CDC_H_
#define USB_CDC_H_
#include <string.h>
#include "arch.h"
#include "co_math.h"
#include "intc.h"
#include "uart.h"
#include "timer.h"
#include "reg_access.h"
#include "Usb_intr.h"
#include "string.h"
#include "usb_com.h"
#include "usb_audio_app.h"
#include "usb_hid_app.h"
#include "usb_audio_desc.h"
#include "usb_hid_desc.h"
//#include "usb_mass_desc.h"
#include "asrc_dac_fs_ppm.h"
#include "ymodem.h"
#include "qspi_ctrl.h"

#define Space                   (0x20)
#define BackSpace               (0x08)
#define Enter                   (0x0D)

typedef enum
{
    USB_CDC_HS,
    USB_CDC_MENU,
    USB_CDC_DOWNLOAD_RESET,
    USB_CDC_DOWNLOAD,
    USB_CDC_NUM
}eUSB_CDC_Menu;

typedef enum
{
    RETURN_CDC_FAIL,
    RETURN_CDC_OK,
    RETURN_CDC_INPUT_ERR,
    RETURN_CDC_NO_USE,
    RETURN_CDC_NOT_SUPPORT,
    RETURN_CDC_CONFIG_ERR,
    RETURN_CDC_TIME_OUT,
}USB_CDC_RETURN;
typedef enum
{
    USB_CDC_READCHAR,
    USB_CDC_READWORD,
    USB_CDC_READ_NUM
}eUSB_CDC_ReadMode;
typedef enum
{
    USB_DOWNLOAD_HS,
    USB_DOWNLOAD_DATA,
    USB_DOWNLOAD_END,
    USB_DOWNLOAD_NUM,
}eUSB_DownLoad_Status;
typedef enum
{
    USB_CDC_SENDDATA,
    USB_CDC_SENDSTR,
    USB_CDC_SENDD_NUM
}eUSB_CDC_SendMode;

void USB_CDCInit(void);
void CDC_SetConctrolLine(void);
void CDC_GetLineCoding(void);
void CDC_SetLineCoding(void);
void USB_MenuService(void);
uint8_t USB_CDCGetChar(uint8_t *pu8Char);
void CDC_SendChar(uint8_t u8Word);
uint8_t USB_DownLoadFlashWrite(uint32_t *pu32FlashAddr, uint32_t *pu32DataAddr ,uint32_t u32len );
uint8_t USB_DownLoadFlashWriteRBuf(uint32_t *pu32FlashAddr, uint32_t *pu32DataAddr ,uint32_t u32len);
uint8_t USB_DownLoadFlashReadRBuf(uint32_t *pu32FlashAddr );
void USB_CDCService(void);
void USB_CDCWrite(void);
#endif//USB_CDC_H_

