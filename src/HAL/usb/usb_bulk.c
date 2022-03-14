#include "usb_ch9.h"
#include "usb_bulk.h"
#include "debug.h"

#ifdef APPLE_LIGHTING_USB_SUPPORT

const uint8_t USB_BULK_IF_EP_DESC[]={
	    /* Interface Descriptor */
    0x09,          /* bLength */
    0x04,          /* bDescriptorType */
    0x04,          /* bInterfaceNumber */
    0x00,          /* bAlternateSetting */
    0x02,          /* bNumEndpoints */
    0xFF,          /* bInterfaceClass */
    0xF0,          /* bInterfaceSubClass*/
    0x00,          /* bInterfaceProtocol */
    0x04,//0x08,//0x05,          /* iInterface */
    
    /* Endpoint Descriptor */
    0x07,          /* bLength */
    0x05,          /* bDescriptorType */
    0x83,		   /* bEndpointAddress */
    0x02,          /* bmAttributes */
    0x40,0x00,     /* wMaxPacketSize note */
    0x01,//0x0A,          /* bInterval*/
    
    /* Endpoint Descriptor */
    0x07,          /* bLength */
    0x05,          /* bDescriptorType */
    0x03,          /* bEndpointAddress */
    0x02,          /* bmAttributes */
    0x40,0x00,     /* wMaxPacketSize note */
    0x01,//0x0A,          /* bInterval*/
};

const uint8_t g_UsbStringIAP[] = "iAP Interface";
USB_STRING 	g_stAppleIAP;
uint8_t g_ucUsbBulkDescLength = sizeof(USB_BULK_IF_EP_DESC);
volatile uint8_t g_ucUsbEnumFinish = 0;
BulkCallback *pFunCB_USB_BulkOut = NULL;

bulk_in_t g_stBulkIn = {
    .pAddr = NULL,
    .Len = 0,
    .PreLen = 0,
    .Status = 0,
};

#ifdef USB_BULK_RING_BUFF_VALID
uint8_t usb_bulk_out_buf[USB_BULK_OUT_BUF_SIZE];// = {0};
bulk_out_t g_stBulkOut = {
    .rd = 0,
    .wr =0,
    .buf = usb_bulk_out_buf,
    .buf_size = USB_BULK_OUT_BUF_SIZE,
    .overflow = 0,
};

void push_recv_data(void *pDataRcvd, uint16_t len);
#endif
void HAL_USB_Transmit(uint8_t ucEpNum, uint8_t *pucBuf, uint16_t usSize);
uint16_t HAL_USB_Receive(uint8_t ucEpNum, uint8_t *pucBuf, uint16_t usSize);

void USB_BULK_Init(BulkCallback *CbFunc)
{
    pFunCB_USB_BulkOut = CbFunc;
    g_ucUsbEnumFinish = 0;
}

void USB_BULK_Uninit(void)
{
    pFunCB_USB_BulkOut = NULL;
    g_ucUsbEnumFinish = 0;
}

uint8_t USB_BULK_Status(void)
{
    return g_stBulkIn.Status;
}

void USB_BULK_InService(void)
{
    uint16_t usLen = 0;

    if (g_stBulkIn.Status) {
        if (g_stBulkIn.Len > 0) {
            if (g_stBulkIn.Len > 64) {
                usLen = 64;
            } else {
                usLen = g_stBulkIn.Len;
            }

            HAL_USB_Transmit(BULK_IN_EP, (uint8_t *)g_stBulkIn.pAddr, usLen);
            g_stBulkIn.PreLen = usLen;
            g_stBulkIn.pAddr += usLen;
            g_stBulkIn.Len -= usLen;
        } else {
            if (g_stBulkIn.PreLen == 64) {
                HAL_USB_Transmit(BULK_IN_EP, (uint8_t *)g_stBulkIn.pAddr, 0);
                g_stBulkIn.PreLen = 0;
            } else {
                g_stBulkIn.PreLen = 0;
                g_stBulkIn.Status = 0;
            }
        }
    }
}

void USB_BULK_OutService(void)
{
    uint16_t u16PktSize = 0;
    uint8_t ucBuf[64] = {0};
    u16PktSize = HAL_USB_Receive(BULK_OUT_EP, ucBuf, 64);
#ifdef USB_BULK_RING_BUFF_VALID
    push_recv_data(ucBuf, u16PktSize);
#endif
    if (pFunCB_USB_BulkOut) {
        pFunCB_USB_BulkOut(ucBuf, u16PktSize);
    }
}

#ifdef USB_BULK_RING_BUFF_VALID
/**
 * @brief caculate remain data len of ring buff.
 * @param wr: write position
 * @param rd: read position
 * @param buf_size: the buf total size
 * @return: remain data len of buff
 * @note 
 * --If wr position > rd position，the the data remain in buf = wr-rd,
 * else wr position is overflow,so the the data remain in buf  = wr + buf_size - rd.
 * --The paramater wr and rd is passed by value, not by reference
**/
uint16_t bulk_out_buf_data_num_get(uint16_t wr, uint16_t rd, uint16_t buf_size)
{
    wr = (wr >= rd) ? (wr - rd) :  (wr + buf_size - rd);
    return wr;
}

/**
 * @brief push recieved data to rx buff.
 * @param pDataRcvd: the recieved data to be pushed.
 * @param len: len of data.
 * @note 
 * --The function should be a call back function and palced in revieve ISR.
 * --If buf_size = 0x100, When wrNum + 0x100 == rdNum or wrNum == rdNum +0x100, indicate that the buff is full.
**/
void push_recv_data(void *pDataRcvd, uint16_t len)
{
    uint16_t bufRemainLen = bulk_out_buf_data_num_get(g_stBulkOut.wr, g_stBulkOut.rd, g_stBulkOut.buf_size);
	if((g_stBulkOut.buf_size - bufRemainLen) >= len)// buff size is enough
	{
		memcpy((uint8_t*)(g_stBulkOut.buf + (g_stBulkOut.wr & (g_stBulkOut.buf_size - 1))), pDataRcvd, len);
		g_stBulkOut.wr += len;
	}
	else// buff overflow
	{
        uint8_t* pBuf = pDataRcvd;
		g_stBulkOut.overflow = 1;
		while((g_stBulkOut.rd + g_stBulkOut.buf_size) != g_stBulkOut.wr)// write data until buff full
		{
			g_stBulkOut.buf[g_stBulkOut.wr++ & (g_stBulkOut.buf_size - 1)] = *(pBuf++);
		}
	}
}

/**
 * @brief read data from rx buff.
 * @param buf: user memory of read data
 * @return Amount of data actually read
 * @note 
 * --The index of (rd & (buf_size-1)) make it always within buf address.
**/
uint16_t USB_BULK_Receive(uint8_t *buf, uint16_t size)
{
    uint16_t i;

    for(i = 0; i < size; i++)
    {
        if(g_stBulkOut.rd != g_stBulkOut.wr)// if have data
        {
            buf[i] = g_stBulkOut.buf[g_stBulkOut.rd++ & (g_stBulkOut.buf_size - 1)];
        }
        else
        {
            goto RET;
        }
    }

RET:
    return i;
} 
#endif /* USB_BULK_RING_BUFF_VALID */

uint16_t USB_BULK_Transmit(uint8_t *pBuf, uint16_t buf_size)
{
    uint16_t usLen1;
    uint16_t usLen2;

    if ((NULL == pBuf) || (0 == buf_size) || (g_ucUsbEnumFinish == 0)) {
        return 0;
    }

    while ((1 == g_stBulkIn.Status) || (M_EpxInPktRdyGet)) {
        NOP();
    }

    if (buf_size > 64) {
        usLen1 = 64;
        usLen2 = buf_size - 64;
    } else {
        usLen1 = buf_size;
        usLen2 = 0;
    }

    if (usLen2 > 0) {
        g_stBulkIn.pAddr = &pBuf[usLen1];
        g_stBulkIn.Len = usLen2;
    } else {
        g_stBulkIn.pAddr = NULL;
        g_stBulkIn.Len = 0;
    }

    g_stBulkIn.Status = 1;
    g_stBulkIn.PreLen = usLen1;
    HAL_USB_Transmit(BULK_IN_EP, pBuf, usLen1);
    // return buf_size;
    return usLen2;// return remain size
}

/*
HAL
*/
void HAL_USB_Transmit(uint8_t ucEpNum, uint8_t *pucBuf, uint16_t usSize)
{
    uint16_t i;
    M_EpxIndex(ucEpNum);
    M_EpxCmdModeTxDoneCheck();

    if (1 == ucEpNum) {
        for (i = 0; i < usSize; i++) {
            rSIE_FIFOEP1 = pucBuf[i];
        }
    } else if (2 == ucEpNum) {
        for (i = 0; i < usSize; i++) {
            rSIE_FIFOEP2 = pucBuf[i];
        }
    } else if (3 == ucEpNum) {
        for (i = 0; i < usSize; i++) {
            rSIE_FIFOEP3 = pucBuf[i];
        }
    }

    M_EpxTxCmdModeReady();
}

/*
HAL
*/
uint16_t HAL_USB_Receive(uint8_t ucEpNum, uint8_t *pucBuf, uint16_t usSize)
{
    uint16_t i = 0;
    uint16_t u16PktSize = 0;
    uint8_t Finish;
    M_EpxIndex(ucEpNum);
    M_EpxRxDoneCheck();
    u16PktSize = rSIE_OCOUNT;

    if (u16PktSize > usSize) {
        u16PktSize = usSize;
        Finish = 0;
    } else {
        Finish = 1;
    }

    if (1 == ucEpNum) {
        for (i = 0; i < u16PktSize; i++) {
            pucBuf[i] = rSIE_FIFOEP1;
        }
    } else if (2 == ucEpNum) {
        for (i = 0; i < u16PktSize; i++) {
            pucBuf[i] = rSIE_FIFOEP2;
        }
    } else if (3 == ucEpNum) {
        for (i = 0; i < u16PktSize; i++) {
            pucBuf[i] = rSIE_FIFOEP3;
        }
    }

    if (Finish) {
        M_EpxRxCmdModeReady();
    }

    return u16PktSize;
}

#endif
