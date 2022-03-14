/*
 * patch.c
 *
 *  Created on: Jul 12, 2018
 *      Author: chenbowen
 */

#include "patch.h"
#include "hss_det.h"
#include "user.h"
#include "bll_config.h"
#include "patch_main.h"
#include "bll_jack_sense.h"

extern int32_t DAC_DC_CALI_L;
extern int32_t DAC_DC_CALI_R;
extern uint8_t g_ppm_range;
extern uint8_t AUDAC_MUTE_BY_PDDAC_EN;
extern uint8_t AUDAC_POWEROFF_CNT_WIN;
extern uint8_t AUDAC_MUTE_DET_WIN;
extern uint32_t AUDAC_MUTE_DET_THRD;
extern uint8_t ASRC_ADC_PFORMANCE;
extern uint8_t ASRC_DAC_PFORMANCE;
extern uint8_t ASRC_DAC_PFORMANCE_96K;

#define MacroExpand(x) #x
#define MacroToString(x) MacroExpand(x)

__attribute__((unused))
static void Null_Func(void)
{
    __nds32__nop();
}

const api_ftable_t stApiFunctionTableDft =
{
    .User_C_Init = Null_Func,
    .User_Init = _user_init,
    .User_Schedule = _user_schedule,
    .MagicKey = 0x88891955,
};



api_ftable_t *pAFI = NULL; //pApiFunctionInterface

// extern void OTP_End_Read(void);
// extern main_ftable_t patch_ftable;
// extern USB_OTP gstOTP;
// extern uint8_t *gp_public_buf;
// extern void User_Init(void);
// extern uint8_t __bss1_end;
// void usb_download_plf_init(void)
// {
//     USB_OTP stOTP;
//     pOtpInRam->PMOD=USB_TYPEC_HEADSET;

//     memset(&stOTP, 0, sizeof(USB_OTP));

//     if(pOtpInRam->CACHE_EN)
//     {
//         cache_on();
//     }

//     // //DC DC enable, off ldo
//     // if(pOtpInRam->POWER_SEL)
//     // {
//     //     apb_dig_stdby_ctrl_dig_ldo_flag_setf(0);            //set as software mode
//     //     apb_power_pd_ctrl0_dig_ref_pd_setf(1);
//     //     apb_power_pd_ctrl0_dig_ldoh_pd_setf(1);
//     //     apb_power_pd_ctrl0_dig_ldol_pd_setf(1);
//     //     apb_dig_stdby_ctrl_dig_stdby_pd_setf(1);
//     // }

//     ke_init();
//     intc_init();
//     timer_init();

//     GLOBAL_INT_START();

//     //power on
//     switch(pOtpInRam->PMOD)
//     {
//         case USB_TYPEC_TO_3P5:
//         {
//             TYPE_C_To_3P5_PowerOn(pOtpInRam->micbias_output_voltage_sel);
//             break;
//         }
//         case USB_TYPEC_HEADSET:
//         {
//             Headset_PowerOn();
//             break;
//         }
//         case USB_TYPEC_HEADPHONE:
//         {
//             Headphone_PowerOn();
//             break;
//         }
//         case USB_DONGLE:
//         {
//             Dongle_PowerOn();
//             break;
//         }
//         case USB_DONGLE_DSP:
//         {
//             Dongle_PowerOn();
//             break;
//         }
//         default: //USB_TEST
//         {

//             break;
//         }
//     }

//     USB_PowerOn_Init(pOtpInRam->PMOD);

//     switch(pOtpInRam->PMOD)
//     {
//         case USB_TYPEC_TO_3P5:
//         {
// //            Earphone_Detect_SetCallBack(EARPHONE_DETECT_INSERT, (uint32_t)EarPhone_Insert_Process);
//             Earphone_Detect_SetCallBack(EARPHONE_DETECT_COMPLET, (uint32_t)EarPhone_Complet_Process);
// //            Earphone_Detect_SetCallBack(EARPHONE_DETECT_REMOVE, (uint32_t)EarPhone_Remove_Process);
//             Earphone_Detect_Init();
//             TypecTo3p5_Init();
//             break;
//         }
//         case USB_TYPEC_HEADSET:
//         {
//             USB_Audio_Config();
//             USB_SetAppMode(pOtpInRam->PMOD);
//             break;
//         }
//         case USB_TYPEC_HEADPHONE:
//         {
//             USB_Audio_Config();
//             USB_SetAppMode(pOtpInRam->PMOD);
//             break;
//         }
//         case USB_DONGLE:
//         {
//             USB_Audio_Config();
//             USB_SetAppMode(pOtpInRam->PMOD);
//             break;
//         }
//         case USB_DONGLE_DSP:
//         {
//             USB_Audio_Config();
//             USB_SetAppMode(pOtpInRam->PMOD);
//             break;
//         }
// //        default: //USB_TEST
// //        {
// //            USB_ConfigTest();
// //            USB_SetAppMode(pOtpInRam->PMOD);
// //            break;
// //        }
//     }

//     USB_SetOTP(stOTP);
//     gstOTP = stOTP;

//     User_Init();

//     PFT_mode(10);

//     if (pOtpInRam->PMOD != USB_TYPEC_TO_3P5)
//     {
//         Standby_Req_UnInit();
//         Suspend_Init();
//         Standby_Req_Init();
//         Standby_Req_SetCallBack(STANDBY_REQ, (uint32_t)EnterExit_Standby);
//     }

//     gp_public_buf = (uint8_t *)0x52000; //size = 0x1000, for modify PID VID back DATA
// }

void patch_Get_Sys_Status(void)
{
    st_OTHER_KEY *pTmp = (st_OTHER_KEY *)(0x84000);
    if(SW_CFG0->FlashOtpDefValKeyOk)
    {
    	unsigned int *pDes = (unsigned int *)RAM_OTP_REG_BASE_ADDR;
    	unsigned int *pSrc = (unsigned int *)pTmp->OtpDefaultValueAddr;
        (void)MEM_Cpy_Word(&pDes[0], &pSrc[0], 256);

        new_OTP_Update2Variable();
    }

    // if(0x12345678 == SW_USB_DOWNLOAD)
    // {
    //     patch_ftable.h_plf_init = usb_download_plf_init;
    // }
    return;
}

void patch___null_function(void)
{
    ;
}

void patch_cinit(void)
{
    //patch data bss init
    extern q31_t __data2_lma_start, __data2_lma_end, __data2_start;
    size_t size = &__data2_lma_end - &__data2_lma_start;
    nds32_dup_q31(&__data2_lma_start, &__data2_start, size);

    extern q31_t __bss2_start, __bss2_end;
    size = &__bss2_end - &__bss2_start;
    nds32_set_q31(0, &__bss2_start, size);
}

