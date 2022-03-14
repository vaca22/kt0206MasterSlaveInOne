#ifndef QSPI_CTRL_H_
#define QSPI_CTRL_H_

#include <stdint.h>
#include <stddef.h>
#include "reg_qspi.h"
#include "clk.h"
#include "co_endian.h"

/*
 * MACRO DEFINITIONS
 **************************************************************************************************
 */
#define ONE_SET             64          // process 64 bytes one time
#define PAGE_SIZE           0x100       // 256 bytes one page
#define SECTOR_SIZE         0x1000      // one sector 4096 bytes
#define FLASH_ADDR_START    0x80000     // flash start address
//#define QSPI_NEW

/*
 * STRUCTURE DEFINES
 **************************************************************************************************
 */
typedef enum {
	eflash_WriteEnable             = 0x06,
	eflash_WriteDisable	           = 0x04,
	eflash_SRWriteEnable           = 0x50,
	eflash_ReadStatus1             = 0x05,
	eflash_ReadStatus2             = 0x35,
	eflash_ReadStatus3             = 0x15,
	eflash_WriteStatus1            = 0x01,
	eflash_WriteStatus2            = 0x31,
	eflash_WriteStatus3            = 0x11,
	eflash_ReadData                = 0x03,
    eflash_FastRead                = 0x0B,
    eflash_DualIoFastRead	 	   = 0xBB,
    eflash_QuadIoWordFastRead	   = 0xE7,
	eflash_PageProgram             = 0x02,
	eflash_QuadPageProgram         = 0x32,
	eflash_SectorErase             = 0x20,
	eflash_BlockErase_32K          = 0x52,
	eflash_BlockErase_64K          = 0xD8,
	eflash_ChipErase               = 0x60,
	eflash_EnableReset             = 0x66,
	eflash_Reset                   = 0x99,
	eflash_Suspend                 = 0x75,
	eflash_Resume                  = 0x7A,
	eflash_ManuID                  = 0x90,
	eflash_DualManuID              = 0x92,
	eflash_QuadManuID              = 0x94,
	eflash_ReadID                  = 0x9F,
	eflash_HighPerformMode         = 0xA3,
}en_eflash_cmd_t;

typedef enum
{
	QSPI_RecvDis = 0,
	QSPI_RecvEn  = 1,
}QspiRecv_t;

typedef enum
{
	QSPI_1Byte = 0,
	QSPI_2Byte = 1,
	QSPI_3Byte = 2,
	QSPI_4Byte = 3,
}QspiByteSize_t;

typedef enum
{
	Xip_SingLine 	= 0,
	Reg_SingLine 	= 0,
	Xip_DualLine 	= 1,
	Reg_DualLine 	= 1,
	Xip_QuadLine 	= 2,
	Reg_QuadLine 	= 3,
}QspiLineMode_t;

typedef enum 
{
	QSPI_TxHiAlert	= BIT0,
	QSPI_TxLoAlert	= BIT1,
	QSPI_TxFull		= BIT2,
	QSPI_TxEmpty	= BIT3,
	QSPI_TxFinish	= BIT4,
	QSPI_RxHiAlert	= BIT16,
	QSPI_RxLoAlert	= BIT17,
	QSPI_RxFull		= BIT18,
	QSPI_RxEmpty	= BIT19,
	QSPI_RxFinish	= BIT20,
}QspiWaitFifoStatus_t;

#ifdef QSPI_NEW
typedef enum FlashCapacity_enum {
	Flash_05		= 0,
	Flash_10		= 1,
	Flash_20		= 2,
	Flash_40		= 3,
	Flash_80		= 4,
	Flash_16		= 5,
	Flash_32		= 6,
	Flash_None		= 7,
}flashCapacity_t;
#endif

/* QSPI read func */
extern void FlashRead(uint32_t uAddr, uint32_t *uBuf, uint32_t uDataSize, QspiLineMode_t qspiLineMode);
extern uint32_t FlashReadId(void);
/* QSPI verify func */
extern void FlashVerifyEnSet(uint8_t ucFlashVerifyEn);
extern uint16_t FlashVerify(uint32_t uAddr, uint8_t *uBuf, uint32_t uDataSize, uint8_t uConst);
/* QSPI erase func */
extern uint16_t FlashSectorErase(uint32_t uAddr);
extern uint16_t FlashErase(uint32_t uAddr, uint32_t uDataSize);
/* QSPI program func */
extern uint16_t FlashProgramPage(uint32_t uAddr, uint32_t *uBuf);
extern uint16_t FlashProgramSmall(uint32_t uAddr, uint32_t *uBuf, uint32_t uDataSize);

#ifdef QSPI_NEW
extern uint16_t FlashProgram(uint32_t uAddr, uint32_t *uBuf, uint32_t uDataSize);
/* QSPI init func */
extern void QSPI_LineModeIdentity(void);
extern void QSPI_XipLineModeSet(QspiLineMode_t qspiLineMode);
#endif

extern void QSPI_Init(void);

extern uint16_t Flash_Write(uint32_t uAddr, uint32_t *uBuf, uint32_t uDataSize);
//-------------------------------------------------------------------------------------------------------------

void QSPI_NoCacheRead_Config(void);

//Must ensure ((flash_word_addr & 0x3) == 0)
static inline void FlashReadWords(uint32_t * pDes, uint32_t flash_word_addr, size_t word_len) {
	uint32_t * pSrc = (uint32_t *)(0x80000 + flash_word_addr);
	while(word_len--) {
		*pDes++ = *pSrc++;
	}
}

//use 2GB map to 0GB, jump cache , direct access flash
static inline void FlashReadWords_NoCache(uint32_t * pDes, uint32_t flash_word_addr, size_t word_len) {
	uint32_t * pSrc = (uint32_t *)(0x80080000 + flash_word_addr);
	while(word_len--) {
		*pDes++ = *pSrc++;
	}
}

static inline uint32_t FlashReadWord(uint32_t flash_word_addr) {
	uint32_t * pSrc = (uint32_t *)(0x80000 + flash_word_addr);
	return (*pSrc);
}

static inline uint32_t FlashReadWord_NoCache(uint32_t flash_word_addr) {
	uint32_t * pSrc = (uint32_t *)(0x80080000 + flash_word_addr);
	return (*pSrc);
}

void QSPI_XIP_QuadSel_En(void);            // QSPI Quad Line

#endif

