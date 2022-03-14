#include "hal_includes.h"
#include "fml_includes.h"
//#include "usb_headset.h"
//#include "usb_headphone.h"
#include "standby_req.h"
#include "suspend.h"
#include "hal_config.h"
#include "bll_config.h"
#include "bll_misc.h"
#include "chip_config.h"
#include "bll_jack_sense.h"
#include "debug.h"

extern uint8_t Standby_Itself;

extern volatile uint8_t AuOutStartFlg;
extern volatile uint8_t AuInStartFlg;
extern volatile uint8_t IsRampDown;

#ifdef JACK_SENSE_FUNC

static usb_3p5_ftable_t  new_usb_3p5_ftabl;

extern usb_3p5_ftable_t *pusb_3p5_ftabl;
extern const usb_3p5_ftable_t usb_3p5_patch_ftable;
extern void USB_UnConfigHeadSet();

void new_patch_EarPhone_Complet_Process(uint8_t ucPloeFlag)
{
    if(!ucPloeFlag)//0=4pole
    {
        //audio in init 
        pOtpInRam->PMOD=USB_TYPEC_HEADSET;
    }
    else//3pole
    {
        pOtpInRam->PMOD=USB_TYPEC_HEADPHONE;
    }
    USB_Audio_Config();
}

void new_patch_TypecTo3p5_Init(void)
{
    uint32_t jack_det_cnt=0;

    while(1)
    {
        jack_det_cnt++;
        timer_delay_length(1, TIM_MS);

		if(jack_insert_complet)
		{
			return;
		}
        #if JACK_SENSE_CFG==0
        if(jack_det_cnt > ((apb_power_pd_ctrl3_jack_ins_deb_getf()+1)*50 + 50))
        #else
        if(jack_det_cnt > (((1 << apb_key_ctrl0_gpio_key_deb_getf()) + 2) * 10 + g_u8DebTimeSet * 50)) //0: 10ms  1:20ms 2:40ms  3:80ms 
        #endif
        {
            jack_det_cnt = 0;
            apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole to avoid micbias pop noise
            Standby_Req_UnInit();
            Suspend_Init();
            Standby_Req_Init();
            Standby_Req_SetCallBack(STANDBY_REQ, (uint32_t)EnterExit_Standby);

            new_TypeCTo3p5_RmvStandby_WKP_Src_Set();
            
            USB_UnConfigHeadSet();
            ActiveStandbySt = 1;
            EnterExit_Standby();
            break;
        }
    }
}

extern void patch_Wait_DCNotch_Rampdown(void);
void jacksense_detect_Schedule(void)
{
    //3.5 process
    if ((1 == jack_insert_complet) && (!stEarphoneDetectPara.EarPhoneDetectCompletFlag))
    {
        // jack_det_cnt = 0;
        USB_UnConfigHeadSet();              //unconfig all

        HSS_Detect_Fun();

        Standby_Req_UnInit();
        Suspend_Init();
        Standby_Req_Init();
        Standby_Req_SetCallBack(STANDBY_REQ, (uint32_t)EnterExit_Standby);
        Standby_Itself = 0;
        DBG_OUT_INFO("PMOD: %d (0:HeadSet, 1:phone, 2:to3p5, 4:dongle)\n", pOtpInRam->PMOD);
#if SIDETONE_ALWAYS_ON_EN
        turnOnDac();
        turnOnAdc();
#endif
    }
    else if (0 == jack_insert_complet)
    {
        if(1 == jack_ins_bygpio_proc){      /// judge whether earphone detect is processing
            __nds32__nop();
        }else{
            Standby_Itself = 1;

            g_ucButtType = 0;

            //3 pole or 4 pole
            stEarphoneDetectPara.EarPhonePoleFlag = 0;
            stEarphoneDetectPara.EarPhoneDetectCompletFlag = 0;

            /* process ramp down while enter standby activity */
            if (1 == AuOutStartFlg)
            {
                patch_Wait_DCNotch_Rampdown();
                AUDIO_OUT_Stop(CO_BIT(DAC0) | CO_BIT(DAC1), 0);
                asrc_Clean_RingBuf();
                IsRampDown = 0;
            }
            if (1 == AuInStartFlg)
            {
                AUDIO_IN_Stop(CO_BIT(ADC0),0);
            }

            apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(1);//set as 3 pole to avoid micbias pop noise
            if (1 == u8IsStandBy)           //valid when jack removal detected by HSS hardware mode
            {
                USB_ResumeHost();
                timer_delay_length(2, TIM_MS);
            }

            new_TypeCTo3p5_RmvStandby_WKP_Src_Set();
            USB_UnConfigHeadSet();
            ActiveStandbySt = 1;
            EnterExit_Standby();
        }
    }
}
#endif

void new_usb_3p5_patch_init(void)
{
    #ifdef JACK_SENSE_FUNC
    new_usb_3p5_ftabl.Insert=usb_3p5_patch_ftable.Insert;
    new_usb_3p5_ftabl.Remove=usb_3p5_patch_ftable.Remove;
    new_usb_3p5_ftabl.Start=usb_3p5_patch_ftable.Start;
    new_usb_3p5_ftabl.Stop=usb_3p5_patch_ftable.Stop;
    new_usb_3p5_ftabl.Complet=new_patch_EarPhone_Complet_Process;
    new_usb_3p5_ftabl.Init=new_patch_TypecTo3p5_Init;
	pusb_3p5_ftabl=&new_usb_3p5_ftabl;
    #endif
}
