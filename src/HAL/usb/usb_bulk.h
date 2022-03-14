#ifndef USB_BULK_H_
#define USB_BULK_H_

#include <stdint.h>
#include "usb_com.h"

#define USB_BULK_RING_BUFF_VALID

#define M_Ep0Index()         rSIE_INDEX = 0x00
#define M_Ep1Index()         rSIE_INDEX = 0x01
#define M_Ep2Index()         rSIE_INDEX = 0x02
#define M_Ep3Index()         rSIE_INDEX = 0x03
#define M_EpxIndex(x)         rSIE_INDEX = x

#define BULK_IN_EP    _USB_EP3_
#define BULK_OUT_EP    _USB_EP3_

#define M_EpxInPktRdyGet   (rSIE_INCSR & B_INPKTRDY_EP1)

#define NOP __nds32__nop

typedef void(BulkCallback)(uint8_t *buf, uint16_t len);

typedef struct  {
    volatile uint8_t *pAddr;
    volatile uint32_t Len;
    volatile uint16_t PreLen; //previous length
    volatile uint8_t Status; //0-> free, 1-> progress/busy
} bulk_in_t;


#ifdef APPLE_LIGHTING_USB_SUPPORT
extern const uint8_t g_UsbStringIAP[];
extern USB_STRING g_stAppleIAP;
extern bulk_in_t g_stBulkIn;

extern uint8_t g_ucUsbBulkDescLength;
extern volatile uint8_t g_ucUsbEnumFinish;


extern void USB_BULK_InService(void);
extern void USB_BULK_OutService(void);
extern void USB_BULK_Init(BulkCallback *CbFunc);
extern void USB_BULK_Uninit(void);
extern uint8_t USB_BULK_Status(void);
extern uint16_t USB_BULK_Transmit(uint8_t *pBuf, uint16_t buf_size);
#endif /* APPLE_LIGHTING_USB_SUPPORT */



#ifdef USB_BULK_RING_BUFF_VALID
#define USB_BULK_OUT_BUF_SIZE      256 //should be power of 2.

typedef struct  {
	volatile uint16_t rd; //read position  
    volatile uint16_t wr; //write position
    volatile uint8_t *buf; //ring buff pointer
    volatile uint16_t buf_size; //size of buff, shoud be power of 2.
    volatile uint8_t overflow; // 1--overflow, 0--not overflow
} bulk_out_t;

extern bulk_out_t g_stBulkOut;

uint16_t bulk_out_buf_data_num_get(uint16_t wr, uint16_t rd, uint16_t buf_size);
uint16_t USB_BULK_Receive(uint8_t *buf, uint16_t size);
#endif

#endif