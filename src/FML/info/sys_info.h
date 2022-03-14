#ifndef __SYS_INFO_H__
#define __SYS_INFO_H__

#include <stdint.h>

enum
{
    RUN_MODE_IS_ROM,
    RUN_MODE_IS_PATCH,
    RUN_MODE_IS_PATCH2RAM,
    RUN_MODE_IS_FLASH,
    RUN_MODE_IS_FLASH2RAM,
    RUN_MODE_IS_OTHER
};

enum
{
    OTP_INIT_ADDR_INDEX,
    OTP_READ_PART_ADDR_INDEX,
    QSPI_INIT_ADDR_INDEX,
    SET_SYS_DFT_STS_ADDR_INDEX,
    GET_SYS_STS_ADDR_INDEX,
    C_INIT_INDEX,
    CLK_DIV_SEL_ADDR_INDEX,
    OTP_READ_ALL_ADDR_INDEX,
    OTP_UNINIT_ADDR_INDEX,
    F2RAM_PRG_ADDR_INDEX,
    FLASH_MAIN_ADDR_INDEX,
    IVB_ADDR_INDEX,
    PATCH_TAB_ADDR_INDEX,
    ADDR_INDEX_NUM_INDEX
};

typedef struct
{
	union {
		struct {
		    uint8_t RegApbKey[16];
		    uint8_t DataKey[16];
		};
		struct {
		    uint8_t MusesMark[16];
		    uint8_t ChipTypeMark[8];
		    uint8_t SizeMark[4];
		    uint32_t BinSize;
		};
	};

    uint8_t ToRamKey[16];
    uint8_t PrgKey[16];
    uint8_t PatchKey[16];
    
    uint8_t GetSysStatusKey[16];
    uint8_t CInitKey[16];
    uint8_t ClkDivSelKey[16];
    uint8_t OtpReadAllKey[16];
    uint8_t OtpUninitKey[16];

    uint8_t Rfu1[16];
    uint32_t Rfu2[1];
    uint32_t OtpDefaultValueKey;
    uint32_t OtpDefaultValueAddr;
    uint32_t AddrKey[ADDR_INDEX_NUM_INDEX];
    uint8_t TypeKey[16];
    uint8_t FlashSignal[16];
}st_OTHER_KEY;

typedef struct
{
    uint8_t RegDspKey[16];
	uint8_t StudyDataKey[16];
	st_OTHER_KEY OtherKey; 
}st_ALL_KEY;

#define FLASH_SECTION_IS_REGAPB     BIT0
#define FLASH_SECTION_IS_PATCH      BIT1
#define FLASH_SECTION_IS_PRG        BIT2
#define FLASH_SECTION_IS_DATA       BIT3
#define FLASH_SECTION_IS_TYPE       BIT4
#define FLASH_SECTION_IS_REGDSP     BIT5
#define FLASH_SECTION_IS_STUDY_DATA BIT6

#define FLASH_MEMORY_BASE           (0x80000)

#define FLASH_OTHER_INFO_BASE       (0x80000)

#define FLASH_GET_SYS_STS_ADDR      (0x800CC)
#define FLASH_C_INIT_ADDR           (0x800D0)
#define FLASH_CLK_DIV_SEL_ADDR      (0x800D4)
#define FLASH_OTP_READ_ALL_ADDR     (0x800D8)
#define FLASH_OTP_UNINIT_ADDR       (0x800DC)

#define FLASH_TO_RAM_PRG_ADDR       (0x800E0)
#define FLASH_MAIN_FUNC_ADDR        (0x800E4)
#define FLASH_IVB_ADDR              (0x800E8)
#define FLASH_PATCH_TABLE_ADDR      (0x800EC)

extern void Get_Sys_Status(void);
extern void Set_Sys_Default_Inf(void);

#endif

