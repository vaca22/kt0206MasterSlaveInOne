#include "comm.h"
#include "sys_info.h"
#include "patch_main.h"
#include "patch.h"
#include "otp_ctrl.h"
#include "flash_info.h"
#include "hal_config.h"

extern void OTP_Init(void);
extern void OTP_Read_Part(void);
extern void QSPI_Init(void);
extern void Get_Sys_Status(void);
extern void Set_Sys_Default_Inf(void);
extern int main(void);
extern void Set_Clk_Div_Sel(uint8_t osc_div_sel, uint8_t ahb_div_sel, uint8_t apb_div_sel, uint8_t qspi_div_sel);
extern void OTP_Read_All(void);
extern void OTP_Uninit(void);
extern int32_t nds32_rfft_q15(q15_t *src, uint32_t m);
extern void __null_function(void);

// const uint8_t EMPTY[16] __attribute__((section(".EMPTY_SECTOR"))) = "muses_flash";
//const UINT8 g_RegDspKey[16] __attribute__ ((section (".FLASH_REG_DSP_KEY_SECTION"))); // = "KTRegDspKey";
//const UINT8 g_StudyDataKey[16] __attribute__ ((section (".FLASH_STUDY_DATA_KEY_SECTION")));// = "KTStudyDataKey";
//
//const UINT32 g_FlashDataContent[64] __attribute__ ((section (".FLASH_DATA_CONTENT_SECTION"))) =
//{
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa,
//    0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa, 0x55aa55aa
//};


// const st_OTHER_KEY g_OtherKeyInFlash __attribute__ ((section (".FLASH_OTHER_KEY_SECTION"))) =
// {
// 	.TypeKey =
// 	{
// 		0x01,'V', '1', '0', 'm', 'u', 's', 'e',
// 		's', 'R', 'O', 'M', 0x04, 0x10, 0x00, 0x00
// 	}
// };

extern const main_ftable_t main_patch_ftable;

extern uint32_t __data2_lma_end;

const st_OTHER_KEY g_OtherKeyInFlash __attribute__ ((section (".FLASH_OTHER_KEY_SECTION"))) =
{
    // .RegApbKey = "KTRegApbKey",
    // .DataKey = "KTDataKey",

	.MusesMark	= "KT_msv2b_flash_1",
#ifdef KT0203
    .ChipTypeMark = "0203B04",
#else
	.ChipTypeMark = "020xB04",
#endif
	.SizeMark = "Size",
	.BinSize = (uint32_t)(&__data2_lma_end) - 0x80000,

	// .ToRamKey = "KTFlash2RamKey",
    // .PrgKey = "KTPrgKey",
    .PatchKey = "KTPatchKey",

    .GetSysStatusKey = "KTGetSysStatus",
    .CInitKey = "KTCInitKey",
    // .ClkDivSelKey = "KTClkDivSelKey",
    .OtpReadAllKey = "KTOtpReadAll",
    // .OtpUninitKey = "KTOtpUninitKey",

    .AddrKey = 
    {
        (uint32_t)OTP_Init,
        (uint32_t)OTP_Read_Part,
        (uint32_t)QSPI_Init,
        (uint32_t)Set_Sys_Default_Inf,

        0,//(uint32_t)patch_Get_Sys_Status,
        0,//(uint32_t)patch_cinit,//patch___null_function,
        0,//(uint32_t)patch_Set_Clk_Div_Sel,
        0,//(uint32_t)patch_OTP_Read_All,
        0,//(uint32_t)patch_OTP_Uninit,

        0,
        (uint32_t)main_flash,
        0,
        0//(uint32_t)&main_patch_ftable
    },
    .Rfu2 = 
    {
        // (uint32_t)nds32_rfft_q15,
    },
    .OtpDefaultValueKey = 0x12345678,
    .OtpDefaultValueAddr = (uint32_t)&OTP_Default_Value_InFlash,
    .TypeKey = 
    {
        'K', 0x02, 0x02, 'B', 'K', 0x02, 0x02, 'B',
		'F', 'L', 'S', 'H', 0x04, 0x10, 0x00, 0x00
    },
    .FlashSignal =
	{
		'K', 'T', '-', 'M', 'i', 'c', 'r', 'o',
		0x04, 0x10
	}
};
