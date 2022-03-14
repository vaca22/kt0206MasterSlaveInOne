#ifndef __REG_RAM_H__
#define __REG_RAM_H__

#include "comm.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*================================寄存器内容定义================================*/
typedef struct
{
    
    UINT32 FlashOtpDefValKeyOk : 1;
    UINT32 FlashStudyDataKeyOk : 1;
    UINT32 FlashSwVerOk : 1;
    UINT32 FlashTypeKeyOk : 1;
    UINT32 FlashRegApbKeyOk : 1;
    UINT32 FlashDataKeyOk : 1;
    UINT32 PrgRunMode : 3;
    UINT32 FlashGetSysStatusKeyOk : 1;
    UINT32 FlashCInitKeyOk : 1;
    UINT32 FlashClkDivSelKeyOk : 1;
    UINT32 FlashOtpReadAllKeyOk : 1;
    UINT32 FlashOtpUninitKeyOk : 1;

    UINT32 POWER_ON_FINISH : 1;

    UINT32 RFU0 : 1;
    UINT32 RFU2 : 24;

	UINT32 IoBufInFlag0 : 8;
	UINT32 IoBufInFlag1 : 8;
    UINT32 IoBufInFlag2 : 8;
    UINT32 I2cWrCnt : 8;
}st_SW_CFG0;

typedef struct
{
    UINT32 VersionPart3 : 8;
    UINT32 VersionPart2 : 8;
    UINT32 VersionPart1 : 8;
    UINT32 TargetNumber : 8;
}st_SW_IC_VER;

/*================================封装类型定义================================*/
typedef union
{
	st_SW_IC_VER bs;
	UINT32 overall;
}un_SW_IC_VER;


/*================================寄存器定义================================*/
#define SW_CFG0  	        ((volatile st_SW_CFG0 *)(RAM_SOFT_REG_BASE_ADDR + 0x00))
// #define SW_CFG1  	        ((volatile un_SW_CFG1 *)(RAM_SOFT_REG_BASE_ADDR + 0x04))
// #define SW_CFG2  	        ((volatile un_SW_CFG2 *)(RAM_SOFT_REG_BASE_ADDR + 0x08))
// #define SW_CFG3             ((volatile un_SW_CFG2 *)(RAM_SOFT_REG_BASE_ADDR + 0x0C))
#define SW_USB_DOWNLOAD     (*((volatile UINT32 *)(RAM_SOFT_REG_BASE_ADDR + 0x10)))
#define SW_IC_HW_VER    	((volatile un_SW_IC_VER *)(RAM_SOFT_REG_BASE_ADDR + 0x14))
#define SW_IC_FW_VER    	((volatile un_SW_IC_VER *)(RAM_SOFT_REG_BASE_ADDR + 0x18))
#define SW_IC_SW_VER    	((volatile un_SW_IC_VER *)(RAM_SOFT_REG_BASE_ADDR + 0x1C))





#ifdef  __cplusplus
}
#endif

#endif

