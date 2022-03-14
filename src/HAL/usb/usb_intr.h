/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_intr.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/

#ifndef USB_INTR_H_
#define USB_INTR_H_




//*******************************************************************
//
//	SIE regs
//
//*******************************************************************
#define _REG_SIE_BASE_          0xC0000000

#define rSIE_FADDR   (*(volatile uint8_t*)(_REG_SIE_BASE_+0x00))
#define rSIE_POWER   (*(volatile uint8_t*)(_REG_SIE_BASE_+0x01))
//USB模式、状态控制寄存器。
    #define B_ENABLESUSPENDM    	0X01	//suspend 使能
    #define B_SUSPENDMODE	        0X02	//suspend 指示(标志)。
    #define B_RESUME           		0X04	//USB Resume操作信号。
    #define B_RESET             	0X08	//USB总线复位指示。
    #define B_HSMODE          		0X10	//USB工作在高速模式状态标志。RO
    #define B_HSENAB				0X20	//USB高速模式使能。
    #define B_SOFTCONN          	0X40	//USB接口使能。
	#define B_SOFTCONN_NEW			0X41	//enable USB interface and suspendm

    /*
        bit4:   1:High speed mode   0:Full speed mode
        bit5:   1:High speed enable 0:disable
    */
#define rSIE_INTRIN  (*(volatile uint8_t*)(_REG_SIE_BASE_+0x02))// 为In Endpoint的中断状态寄存器。
    /*
        bit0:   ep0_setup intr
        bit1:   ep1_in intr
    */
#define rSIE_INTROUT (*(volatile uint8_t*)(_REG_SIE_BASE_+0x04))
    /*为Out Endpoint的中断状态寄存器。
        bit0:   reserved
        bit1:   ep1_out intr
        bit2:   ep2_out intr
    */
#define rSIE_INTRINE  (*(volatile uint8_t*)(_REG_SIE_BASE_+0x06))//该寄存器使能 In端点中断，每一位对应SIE_IntrIn的中断。
#define rSIE_INTROUTE (*(volatile uint8_t*)(_REG_SIE_BASE_+0x08))//该寄存器使能 Out端点中断，每一位对应SIE_IntrOut的中断。该寄存器使能Out端点中断，每一位对应SIE_IntrOut的中断。
    #define B_INT_EP0       0x01     //ONLY IN SIE_INTRINE
    #define B_INT_EP1       0x02
    #define B_INT_EP2       0x04
	#define B_INT_EP3       0x08

#define rSIE_INTRUSB  (*(volatile uint8_t*)(_REG_SIE_BASE_+0x0A))
#define rSIE_INTRUSBE (*(volatile uint8_t*)(_REG_SIE_BASE_+0x0B))
    #define B_INT_SUSPEND       0x01
    #define B_INT_RESUME        0x02
    #define B_INT_RESET     0x04
	#define B_INT_SOF     0x08

#define rSIE_FRAMENUM_L	(*(volatile uint8_t*)(_REG_SIE_BASE_+0x0C))
#define rSIE_FRAMENUM_H	(*(volatile uint8_t*)(_REG_SIE_BASE_+0x0D))

#define rSIE_INDEX    (*(volatile uint8_t*)(_REG_SIE_BASE_+0x0E))
#define rSIE_TESTMODE (*(volatile uint8_t*)(_REG_SIE_BASE_+0x0F))
    #define B_TEST_SE0_NAK  0x01
    #define B_TEST_J            0x02
    #define B_TEST_K            0x04
    #define B_TEST_PACKET       0x08

#define rSIE_INMAX    (*(volatile uint16_t*)(_REG_SIE_BASE_+0x10))
#define rSIE_INMAXH   (*(volatile uint8_t*)(_REG_SIE_BASE_+0x11))
#define rSIE_INCSR    (*(volatile uint8_t*)(_REG_SIE_BASE_+0x12))
#define rSIE_INCSRH   (*(volatile uint8_t*)(_REG_SIE_BASE_+0x13))
//ep0
    #define B_OUTPKTRDY     	0x01   	     //and ep1 Out
    #define B_INPKTRDY_EP0  	0x02
    #define B_SENTSTALL_EP0 	0x04
    #define B_DATAEND_EP0       0x08
    #define B_SETUPEND_EP0      0x10
    #define B_SENDSTALL_EP0     0x20
    #define B_SERVICEDOUTPKTRDY_EP0		0x40
    #define B_SERVICEDSETUPEND_EP0  	0x80
//ep1 In
    #define B_INPKTRDY_EP1  0x01
    #define B_FLUSHFIFO_EP1IN   0x08
    #define B_SENDSTALL_EP1IN   0x10
    #define B_SENTSTALL_EP1IN   0x20
    #define B_CLRDATATOG_EP1IN  0x40
//high byte
    #define B_DMAENAB_EP1IN     0x10//[4]
    #define B_AUTOSET_EP1IN     0x80//[7]
	#define B_Iso_EPIn     		0x40//[6]

#define rSIE_OUTMAX   (*(volatile uint16_t*)(_REG_SIE_BASE_+0x14))
#define rSIE_OUTMAXH  (*(volatile uint8_t*)(_REG_SIE_BASE_+0x15))
#define rSIE_OUTCSR   (*(volatile uint8_t*)(_REG_SIE_BASE_+0x16))
#define rSIE_OUTCSRH  (*(volatile uint8_t*)(_REG_SIE_BASE_+0x17))
//ep1 Out
    #define B_FLUSHFIFO_EP1OUT  0x10
    #define B_SENDSTALL_EP1OUT  0x20
    #define B_SENTSTALL_EP1OUT  0x40
    #define B_CLRDATATOG_EP1OUT 0x80
//high byte
    #define B_DMAMODE_EP1OUT    0x08
    #define B_DISNYET_EP1OUT        0x10
    #define B_DMAENAB_EP1OUT    0x20
    #define B_AUTOCLEAR_EP1OUT  0x80
	#define B_Iso_EPOut			0x40

#define rSIE_OCOUNT  (*(volatile uint16_t*)(_REG_SIE_BASE_+0x18))
#define rSIE_FIFOEP0 (*(volatile uint8_t*)(_REG_SIE_BASE_+0x20))
#define rSIE_FIFOEP1 (*(volatile uint8_t*)(_REG_SIE_BASE_+0x24))
#define rSIE_FIFOEP2 (*(volatile uint8_t*)(_REG_SIE_BASE_+0x28))
#define rSIE_FIFOEP3 (*(volatile uint8_t*)(_REG_SIE_BASE_+0x2C))

#define EP1_TX_BUF (RAM_USB_FIFO_BASE_ADDR + 0x440)


void Init_SIE(void);
void Hal_ConectUsb(void);
void Hal_DisConectUsb(void);
void Usb_INTR();
void DeInit_SIE(void);
void USB_EP1ServiceIN(void);
void USB_EP1ServiceOUT(void);
void USB_EP2ServiceIN(void);
void USB_EP2ServiceOUT(void);
void USB_EP3Service(void);
void usb_intr_patch_init(void);
extern void USB_ResumeHost(void);
extern void USB_SuspendmEn(void);

extern void new_usb_intr_patch_init(void);


#endif//USB_INTR_H_

