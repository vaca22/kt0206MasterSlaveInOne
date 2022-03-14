/**
 **************************************************************************************************
 *
 * @file qspi_ctrl.c
 *
 * @brief process qspi cmd
 *
 * @author chenbowen
 *
 * Copyright (C), 2017 - 2018,  KT Micro,Inc.
 *
 *
 **************************************************************************************************
 */

/*
 * INCLUDE FILES
 **************************************************************************************************
 */
#include "qspi_ctrl.h"
#include "gpio_ctrl.h"
#include "fml_includes.h"


typedef union {
	struct {
		uint32_t	D		: 1;
		uint32_t	NTC0	: 2;
		uint32_t	NTC1	: 2;
		uint32_t	NTC2	: 2;
		uint32_t	NTC3	: 2;
		uint32_t	TBALCK	: 1;
		uint32_t	MPZIU	: 1;
		uint32_t	NTM0	: 2;
		uint32_t	NTM1	: 2;
		uint32_t	NTM2	: 2;
		uint32_t	NTM3	: 2;
		uint32_t	DREE	: 1;
		uint32_t	RFU0	: 3;
		uint32_t	UNA		: 1;
		uint32_t	RFU1	: 8;
	};
	uint32_t		all32;
}D10_MMU_CTL_t;

#define READ_D10(regname) {											\
	D10_##regname##_t regname = {									\
		.all32 = __nds32__mfsr(NDS32_SR_##regname),					\
	};

#define WRITE_D10(regname)											\
	__nds32__mtsr(regname.all32, NDS32_SR_##regname);				\
}

void QSPI_NoCacheRead_Config(void) {
	READ_D10(MMU_CTL)
	MMU_CTL.UNA = 1;	//open unaligned access allow
	MMU_CTL.NTC2 = 0;	//2GB access 0GB no cache
	MMU_CTL.NTM2 = 0;	//map 2GB to 0GB
	WRITE_D10(MMU_CTL)
}

// void Wait_Tx_Finish(void)
// {
//     while(1)
//     {
//         if(1 == qspi_fifo_status_tx_finish_getf())
//         {
//             break;
//         }
//     }
// }

// void Wait_Rx_Finish(void)
// {
//     while(1)
//     {
//         if(1 == qspi_fifo_status_rx_finish_getf())
//         {
//             break;
//         }
//     }
// }

/*************************************************************************************************/
/*                                                                                               */
/*                                          QSPI Init                                            */
/*                                                                                               */
/*************************************************************************************************/
// void QSPI_Init(void)
// {
// 	/* open QSPI_CLK */
//     apb_clk_gen_clken_clk_qspi_en_setf(1);

// 	/* config pop time */
//     // qspi_eflash_ctrl_pack(1, uQSPI_Clk / 200);
//     Delay_Ms_600K(1);
//     qspi_eflash_ctrl_pack(1, 1); 

/*
 * LOCAL FUNCTION DEFINITIONS
 **************************************************************************************************
 */

/*
 * EXPORTED FUNCTION DEFINITIONS
 **************************************************************************************************
 */
extern uint16_t FlashProgramPage(uint32_t uAddr, uint32_t *uBuf);

uint8_t g_u8TmpBuf[256];
uint16_t Flash_Write(uint32_t uAddr, uint32_t *uBuf, uint32_t uDataSize)
{
    uint8_t *pu8Buf = (uint8_t *)uBuf;
    uint16_t u16RetValue = OK, u16PageAlign, u16PageRestLen, i;
    uint32_t u32ProcAddr = uAddr;

    u16PageAlign = uAddr % PAGE_SIZE;
    u16PageRestLen = PAGE_SIZE - u16PageAlign;
    /* if uAddr is not 256 bytes align */
    if(u16PageAlign != 0){
        u32ProcAddr -= u16PageAlign;
        /* if data uDataSize of uBuf is less than and equal to page rest length */
        if(uDataSize < u16PageRestLen){
            for(i=u16PageAlign; i<(u16PageAlign+uDataSize); i++){
                g_u8TmpBuf[i] = pu8Buf[i-u16PageAlign];
            }
            u16RetValue = FlashProgramPage(u32ProcAddr, (uint32_t *)g_u8TmpBuf);
            uDataSize = 0;
        }else{
            for(i=u16PageAlign; i<PAGE_SIZE; i++){
                g_u8TmpBuf[i] = pu8Buf[i-u16PageAlign];
            }
            u16RetValue = FlashProgramPage(u32ProcAddr, (uint32_t *)g_u8TmpBuf);
            u32ProcAddr += PAGE_SIZE;
            pu8Buf += u16PageRestLen;
            uDataSize -= u16PageRestLen;
        }/* if(uDataSize < u16PageRestLen) */
    }else{
        memset(g_u8TmpBuf, 0xFF, sizeof(g_u8TmpBuf));
    }/* if(u16PageAlign != 0) */

    if(ERR == u16RetValue){
        return u16RetValue;
    }

    while(uDataSize){
        memset(g_u8TmpBuf, 0xFF, sizeof(g_u8TmpBuf));
        u16PageRestLen = (uDataSize >= PAGE_SIZE) ? PAGE_SIZE : uDataSize;
        for(i=0; i<u16PageRestLen; i++){
            g_u8TmpBuf[i] = pu8Buf[i];
        }
        u16RetValue = FlashProgramPage(u32ProcAddr, (uint32_t *)g_u8TmpBuf);
        u32ProcAddr += u16PageRestLen;
        pu8Buf += u16PageRestLen;
        uDataSize -= u16PageRestLen;
        if(ERR == u16RetValue){
            return u16RetValue;
        }
    }/* while(uDataSize) */

    return u16RetValue;
}
