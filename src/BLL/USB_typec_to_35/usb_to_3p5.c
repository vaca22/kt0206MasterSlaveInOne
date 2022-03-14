#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "usb_headset.h"
#include "usb_headphone.h"
#include "standby_req.h"
#include "suspend.h"
#include "hal_config.h"
#include "bll_config.h"
#include "bll_misc.h"

typedef struct usb_3p5_ftable_stru
{
	void (*Insert)(void);
	void (*Complet)(uint8_t);
	void (*Remove)(uint8_t);
	void (*Start)(uint8_t);
	void (*Stop)(uint8_t);
    void (*Init)(void);
} usb_3p5_ftable_t;

usb_3p5_ftable_t *pusb_3p5_ftabl = NULL;
void EarPhone_Insert_Process(void)
{
	pusb_3p5_ftabl->Insert();
}
extern void patch_EarPhone_Insert_Process(void);

void EarPhone_Complet_Process(uint8_t ucPloeFlag)
{
	pusb_3p5_ftabl->Complet(ucPloeFlag);
}
void new_patch_EarPhone_Complet_Process(uint8_t ucPloeFlag)
{
    if(!ucPloeFlag)//0=4pole
    {
        //audio in init 
        pOtpInRam->PMOD=USB_TYPEC_HEADSET;
    	USB_ConfigHeadSet();
    	USB_SetAppMode(USB_TYPEC_HEADSET);
    }
    else//3pole
    {
        pOtpInRam->PMOD=USB_TYPEC_HEADPHONE;
    	USB_ConfigHeadPhone();
    	USB_SetAppMode(USB_TYPEC_HEADPHONE);
    }
}

void EarPhone_Remove_Process(uint8_t ucPloeFlag)
{
	pusb_3p5_ftabl->Remove(ucPloeFlag);
}
extern void patch_EarPhone_Remove_Process(uint8_t ucPloeFlag);

void TypecTo3p5_Start(uint8_t ucPloeFlag)
{
	pusb_3p5_ftabl->Start(ucPloeFlag);
}
extern void patch_TypecTo3p5_Start(uint8_t ucPloeFlag);

void TypecTo3p5_Stop(uint8_t ucPloeFlag)
{
	pusb_3p5_ftabl->Stop(ucPloeFlag);
}
extern void patch_TypecTo3p5_Stop(uint8_t ucPloeFlag);

void TypecTo3p5_Init(void)
{
    pusb_3p5_ftabl->Init();
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

const usb_3p5_ftable_t new_usb_3p5_patch_ftable =
{
    .Insert     = patch_EarPhone_Insert_Process,
    .Complet    = new_patch_EarPhone_Complet_Process,
    .Remove     = patch_EarPhone_Remove_Process,
    .Start      = patch_TypecTo3p5_Start,
    .Stop       = patch_TypecTo3p5_Stop,
    .Init       = new_patch_TypecTo3p5_Init,
};

void new_usb_3p5_patch_init(void)
{
	pusb_3p5_ftabl = (usb_3p5_ftable_t *)&new_usb_3p5_patch_ftable;
}
