/*
 * earphone_key_wakeup_detect.c
 *
 */

#include "hal_config.h"
#include "bll_config.h"
#include "reg_apb.h"
#include "intc.h"
#include "power_on.h"
#include "power_off.h"
#include "earphone_key_detect.h"
#include "earphone_insert_remove_detect.h"
#include "earphone_key_wakeup_detect.h"
#include "standby_req.h"
#include "usb_intr.h"
#include "usb_com.h"
#include "saradc.h"
#include "usb_app.h"
#include "apple_key_detect.h"
#include "gpio_ctrl.h"
#include "soft_timer.h"
#include "bll_misc.h"
#include "hal_key.h"
#include "chip_config.h"

typedef struct
{
    void (*Earphone_Key_Detect_FuncHandle)(void);
    void (*Earphone_Key_Detect_Isr)(uint32_t uID);
    void (*Micin_Key_Det_Fsm_Init)(void);
} ftable_t;

ftable_t *pEarphoneKeyDetFTtable;

void (*pMidLongKeyFunc)(void)=NULL;

earphone_key_detect_para_t stEarphoneKeyDetectPara;

// earphone_key_thrd_t st_earphone_key_thrd =
// {
//     .thrd0 = 0xE0,                      //play/pause thrd
//     .thrd1 = 0x140,                     //VOLUME UP low threshold
//     .thrd2 = 0x1B0,                     //VOLUME UP high threshold
//     .thrd3 = 0x1E0,                     //VOLUME DOWN low threshold
//     .thrd4 = 0x2A0,                     //VOLUME DOWN high threshold
//     .thrd5 = 0x0F7,                     //MUTE low threshold
//     .thrd6 = 0x130,                     //MUTE high threshold
// };

// //Theoretical Value //Rpullup=2.2kohm
// const earphone_key_thrd_t st_earphone_key_thrd_TypeCTo3p5 =
// {
//     .thrd0 = 0xD0,                      //play/pause thrd
//     .thrd1 = 0x127,                     //VOLUME UP low threshold
//     .thrd2 = 0x187,                     //VOLUME UP high threshold
//     .thrd3 = 0x190,                     //VOLUME DOWN low threshold
//     .thrd4 = 0x2B0,                     //VOLUME DOWN high threshold
//     .thrd5 = 0xD7,                      //MUTE low threshold
//     .thrd6 = 0x120,                     //MUTE high threshold
// };

/* in otp_ctrl */
//Theoretical Value //Rpullup=2.2kohm
// const earphone_key_thrd_t st_earphone_key_thrd_headset =
// {
//  .thrd0 = 0x50,                      //play/pause thrd
//  .thrd1 = 0xBF,                      //VOLUME UP low threshold
//  .thrd2 = 0x120,                     //VOLUME UP high threshold
//  .thrd3 = 0x130,                     //VOLUME DOWN low threshold
//  .thrd4 = 0x250,                     //VOLUME DOWN high threshold
//  .thrd5 = 0x70,                      //MUTE low threshold
//  .thrd6 = 0xB1,                      //MUTE high threshold
// };

uint8_t play_pause_flag;
extern uint8_t u8IsFirstStandBy;
extern uint8_t new_u8IsFirstStandby;

void change_status(void)
{
    g_ucCloseAppleKeyDetFlg = 0;
    softtimer_stop(SOFT_TIMER2);
}

void key_release_detect(void)
{
    uint16_t data;
    uint16_t u16AudioCtl;

    data = Saradc_Convert(4, SARADC_SEL_MIC);
    if (data > st_earphone_key_thrd.thrd4)
    {
        u16AudioCtl = 0;
        USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
        softtimer_stop(SOFT_TIMER2);
        softtimer_stop(SOFT_TIMER3);
        if (g_pstConfig->FuncCfg.SupportAppleEarphone)
        {
            softtimer_start(SOFT_TIMER2, MS_TO_SOFT_TIMER(20), change_status);
        }
    }
}

#if SUPPORT_PREVIOUS_NEXT_FOR_PC

volatile uint8_t vu8MiddleClickFlag = 0;
volatile uint8_t vu8MiddleKeyPress = 0;

void middle_key_release(void)
{
    uint16_t u16AudioCtl = 0;

    softtimer_stop(SOFT_TIMER3);
    u16AudioCtl = 0;
    USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
    if (g_pstConfig->FuncCfg.SupportAppleEarphone)
    {
        softtimer_start(SOFT_TIMER2, MS_TO_SOFT_TIMER(20), change_status);
    }
    vu8MiddleClickFlag = 0;
}

void middle_key_function(void)
{
    uint8_t u8KeyValue = 0;
    uint8_t u8KeyPress = 1;
    uint16_t u16AudioCtl = 0;
    uint16_t u16SaradcData = 0;

    if (1 == vu8MiddleKeyPress) {
        u8KeyPress = 0;
        vu8MiddleKeyPress = 0;
    } else {
        u16SaradcData = Saradc_Convert(4, SARADC_SEL_MIC);
        if (u16SaradcData < st_earphone_key_thrd.thrd0) {
            u8KeyPress = 0;
        }
    }

    u8KeyValue = HAL_KEY_Read(u8KeyPress);

    switch (u8KeyValue) {
    case HAL_KEY_S:
        softtimer_stop(SOFT_TIMER3);
        u16AudioCtl |= BIT3;
        USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
        softtimer_start(SOFT_TIMER3, MS_TO_SOFT_TIMER(30), middle_key_release);
        break;
    case HAL_KEY_D:
        softtimer_stop(SOFT_TIMER3);
        u16AudioCtl |= BIT6;
        USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
        softtimer_start(SOFT_TIMER3, MS_TO_SOFT_TIMER(30), middle_key_release);
        break;
    case HAL_KEY_T:
        softtimer_stop(SOFT_TIMER3);
        u16AudioCtl |= BIT5;
        USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
        softtimer_start(SOFT_TIMER3, MS_TO_SOFT_TIMER(30), middle_key_release);
        break;
    case HAL_KEY_L:
        softtimer_stop(SOFT_TIMER3);
        if(pMidLongKeyFunc==NULL)
        {
            u16AudioCtl |= BIT3;
            USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
            softtimer_start(SOFT_TIMER3, MS_TO_SOFT_TIMER(30), key_release_detect);
        }
        else
        {
            pMidLongKeyFunc();
        }
        vu8MiddleClickFlag = 0;    
        break;
    case HAL_KEY_N:
        break;
    }
}

/*VOLUME UP*/ //BIT0
/*VOLUME DOWN*/ //BIT1
/*MUTE*/ //BIT2
/*PLAY*/ //BIT3
/*PAUSE*/ //BIT4
/*PREVIOUS*/ //BIT5
/*NEXT*/ //BIT6
void Earphone_Key_Detect_FuncHandle(void)
{
    pEarphoneKeyDetFTtable->Earphone_Key_Detect_FuncHandle();
}
void patch_Earphone_Key_Detect_FuncHandle(void)
{
    uint16_t u16AudioCtl;
    uint16_t u16SaradcData;
    u16AudioCtl = 0;

    stUSB_Audio_Attr stAudioOutAttr = {0};
    stUSB_Audio_Attr stAudioInAttr = {0};

    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioInAttr, sizeof(stUSB_Audio_Attr));
    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_OUT, &stAudioOutAttr, sizeof(stUSB_Audio_Attr));

    if (pOtpInRam->PMOD == USB_TYPEC_TO_3P5) {
        if ((1 == stEarphoneDetectPara.EarPhonePoleFlag)                        //3pole
                || (0 == stEarphoneDetectPara.EarPhoneDetectCompletFlag)) {      //jack removed
            return;
        }
    }

    if ((1 == u8IsStandBy) && (2 == new_u8IsFirstStandby)) {
        u8IsStandBy = 0;
        apb_rst_gen_ctrl0_auxadc_rst_setf(1);
        apb_rst_gen_ctrl0_auxadc_rst_setf(0);
        u16SaradcData = Saradc_Convert(4, SARADC_SEL_MIC);
        // if((FALSE == stAudioInAttr.u8Status)&&(FALSE == stAudioOutAttr.u8Status))
        if (FALSE == stAudioOutAttr.u8Status) 
        {
            //resolve key wakeup after first times invalid from standby status.
            USB_ResumeHost();
            u16SaradcData = _SarAdcData;
        }
    } else {
        apb_rst_gen_ctrl0_auxadc_rst_setf(1);
        apb_rst_gen_ctrl0_auxadc_rst_setf(0);
        u16SaradcData = Saradc_Convert(4, SARADC_SEL_MIC);
    }

    if (u16SaradcData < st_earphone_key_thrd.thrd0) {
        // middle key
        vu8MiddleKeyPress = 1;
        if (0 == vu8MiddleClickFlag) {
            vu8MiddleClickFlag = 1;
            softtimer_start(SOFT_TIMER3, MS_TO_SOFT_TIMER(10), middle_key_function);
            g_ucCloseAppleKeyDetFlg = 1;
        }
    } else {
        if ((u16SaradcData > st_earphone_key_thrd.thrd1) && (u16SaradcData <= st_earphone_key_thrd.thrd2)) {
            //VOLUME UP
            u16AudioCtl |= BIT0;
            g_ucButtType = 1;
        } else if ((u16SaradcData > st_earphone_key_thrd.thrd3) && (u16SaradcData <= st_earphone_key_thrd.thrd4)) {
			//VOLUME DOWN
            u16AudioCtl |= BIT1;
            g_ucButtType = 1;
        } else if ((u16SaradcData > st_earphone_key_thrd.thrd5) && (u16SaradcData <= st_earphone_key_thrd.thrd6)) {
            //MUTE
            u16AudioCtl |= BIT2;
        } else {
            u16AudioCtl = 0;
        }

        if (u16AudioCtl) {
#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
            if (1 == UsbSuspendSt) {
                USB_ResumeHost();
                UsbSuspendSt = 0;
            }
#endif
            USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
            softtimer_start(SOFT_TIMER2, MS_TO_SOFT_TIMER(30), key_release_detect);
        }
    }
}

#else
/*VOLUME UP*/ //BIT0
/*VOLUME DOWN*/ //BIT1
/*MUTE*/ //BIT2
/*PLAY*/ //BIT3
/*PAUSE*/ //BIT4
void Earphone_Key_Detect_FuncHandle(void)
{
    pEarphoneKeyDetFTtable->Earphone_Key_Detect_FuncHandle();
}
void patch_Earphone_Key_Detect_FuncHandle(void)
{
    uint16_t u16AudioCtl;
    uint16_t data;
    u16AudioCtl = 0;

    stUSB_Audio_Attr stAudioOutAttr = {0};
    stUSB_Audio_Attr stAudioInAttr = {0};

    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioInAttr, sizeof(stUSB_Audio_Attr));
    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_OUT, &stAudioOutAttr, sizeof(stUSB_Audio_Attr));

    if (pOtpInRam->PMOD == USB_TYPEC_TO_3P5)
    {
        if ((1 == stEarphoneDetectPara.EarPhonePoleFlag)                        //3pole
                || (0 == stEarphoneDetectPara.EarPhoneDetectCompletFlag))       //jack removed
        {
            return;
        }
    }

    if ((1 == u8IsStandBy) && (2 == new_u8IsFirstStandby))
    {
        u8IsStandBy = 0;
        apb_rst_gen_ctrl0_auxadc_rst_setf(1);
        apb_rst_gen_ctrl0_auxadc_rst_setf(0);
        data = Saradc_Convert(4, SARADC_SEL_MIC);
        // if((FALSE == stAudioInAttr.u8Status)&&(FALSE == stAudioOutAttr.u8Status))
        if (FALSE == stAudioOutAttr.u8Status)
        {
            //resolve key wakeup after first times invalid from standby status.
            USB_ResumeHost();
            data = _SarAdcData;
        }
    }
    else
    {
        apb_rst_gen_ctrl0_auxadc_rst_setf(1);
        apb_rst_gen_ctrl0_auxadc_rst_setf(0);
        data = Saradc_Convert(4, SARADC_SEL_MIC);
    }
    if (data < st_earphone_key_thrd.thrd0)          //play/pause
    {
        if (play_pause_flag == 1)
        {
            play_pause_flag = 0;
            u16AudioCtl |= BIT4;
        }
        else
        {
            play_pause_flag = 1;
            u16AudioCtl |= BIT3;
        }

        g_ucCloseAppleKeyDetFlg = 1;
    }
    else if ((data > st_earphone_key_thrd.thrd1) && (data <= st_earphone_key_thrd.thrd2))   //VOLUME UP
    {
        u16AudioCtl |= BIT0;
        g_ucButtType = 1;

    }
    else if ((data > st_earphone_key_thrd.thrd3) && (data <= st_earphone_key_thrd.thrd4))   //VOLUME DOWN
    {
        u16AudioCtl |= BIT1;
        g_ucButtType = 1;
    }
    else if ((data > st_earphone_key_thrd.thrd5) && (data <= st_earphone_key_thrd.thrd6))       //MUTE
    {
        u16AudioCtl |= BIT2;
    }
    else
        u16AudioCtl = 0;

    if (u16AudioCtl)
    {
#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
        if (1 == UsbSuspendSt)
        {
            USB_ResumeHost();
            UsbSuspendSt = 0;
        }
#endif
        USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
        softtimer_start(SOFT_TIMER2, MS_TO_SOFT_TIMER(30), key_release_detect);
    }
}

#endif

void Earphone_Key_Detect_Isr(uint32_t uID)
{
    pEarphoneKeyDetFTtable->Earphone_Key_Detect_Isr(uID);
}
extern void rom_Earphone_Key_Detect_Isr(uint32_t uID);

#ifdef MIC_KEY_SUPPORT
void Micin_Key_Det_Fsm_Init(void)
{
    pEarphoneKeyDetFTtable->Micin_Key_Det_Fsm_Init();
}
void patch_Micin_Key_Det_Fsm_Init(void)
{
    
    play_pause_flag = 1;

    Earphone_KWP_Detect_Uninit();//KWP估计是key wakeup的意思
    key_decoder_init();

    //micbias power on
    apb_spare_reg3_r_spare_reg_3_setf(0xFFFFFFFE);
    timer_delay_length(1, TIM_MS);
    apb_audio_ctrl5_auldo__1p_2v_pd_setf(0);
    apb_power_pd_ctrl0_micbias_pd_setf(0);
    apb_power_pd_ctrl0_micbias_en_setf(1);
    timer_delay_length(5, TIM_MS);

    Earphone_KWP_Detect_Init(pOtpInRam->MicinDebounceSel, pOtpInRam->MicinVoltageThresholdSel);
    Earphone_KWP_Detect_SetCallBack(EARPHONE_KWP_DETECT, (uint32_t)Earphone_Key_Detect_FuncHandle);
    apb_key_ctrl0_micin_det_pd_setf(0);             //power on micin_det
    Earphone_KWP_Detect_Start();
}


void Earphone_Key_Detect_Thrd_Init(product_app_index_t pmod)    //
{
    st_earphone_key_thrd.thrd0 = KEY_THRD0;
    st_earphone_key_thrd.thrd1 = KEY_THRD1;
    st_earphone_key_thrd.thrd2 = KEY_THRD2;
    st_earphone_key_thrd.thrd3 = KEY_THRD3;
    st_earphone_key_thrd.thrd4 = KEY_THRD4;
    st_earphone_key_thrd.thrd5 = KEY_THRD5;
    st_earphone_key_thrd.thrd6 = KEY_THRD6;
}
#endif

extern void rom_Micin_Key_Det_Fsm_Init(void);


const ftable_t patch_Earphone_Key_Detect_fi_table =
{
    .Earphone_Key_Detect_FuncHandle  = patch_Earphone_Key_Detect_FuncHandle,
    .Earphone_Key_Detect_Isr         = rom_Earphone_Key_Detect_Isr,
    #ifdef MIC_KEY_SUPPORT
    .Micin_Key_Det_Fsm_Init          = patch_Micin_Key_Det_Fsm_Init,
    #else
    .Micin_Key_Det_Fsm_Init          = rom_Micin_Key_Det_Fsm_Init,
    #endif
};

void new_earphone_key_detect_patch_init(void)
{
    pEarphoneKeyDetFTtable = (ftable_t *)&patch_Earphone_Key_Detect_fi_table;
}
