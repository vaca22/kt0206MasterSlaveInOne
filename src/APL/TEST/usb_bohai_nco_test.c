/**
 ****************************************************************************************
 *
 * @file plf_init.c
 *
 * @brief Main loop of the application.
 *
 * @author WeighSong
 *
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "usb_app.h"
#include "ke_event.h"
#include "KT0656M_drv.h"
#include "i2c.h"
//#include "dw_i2c.h"
/*
	   uint8_t UsbManufact[60];
	   uint8_t UsbProduct[60];
	   uint8_t UsbSerial[60];
	   uint8_t UsbStringID[10];
*/
void plf_sleep_check(void)
{
}

void plf_schedule(void)
{
    ke_event_schedule();
}


void p_init(void)
{
    USB_OTP stOTP;

    memset(&stOTP, 0, sizeof(USB_OTP));

    if(pOtpInRam->CACHE_EN)
    {
        cache_on();
    }

    //DC DC enable, off ldo
    if(pOtpInRam->POWER_SEL)
    {
        apb_power_pd_ctrl0_dig_ldoh_bypass_setf(1);
        apb_power_pd_ctrl0_dig_ldoh_pd_setf(1);
        apb_power_pd_ctrl0_dig_ldol_pd_setf(1);
        apb_dig_stdby_ctrl_dig_stdby_pd_setf(1);
    }

    //power on
    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            TYPE_C_To_3P5_PowerOn(pOtpInRam->micbias_output_voltage_sel);
            break;
        }
        case USB_TYPEC_HEADSET:
        {
            Headset_PowerOn();
            break;
        }
        case USB_TYPEC_HEADPHONE:
        {
            Headphone_PowerOn();
            break;
        }
        case USB_DONGLE:
        {
            Dongle_PowerOn();
            break;
        }
        case USB_DONGLE_DSP:
        {
            Dongle_PowerOn();
            break;
        }
        default: //USB_TEST
        {

            break;
        }
    }

    // Initialize the Interrupt Controller
 //   intc_init();
    USB_SetOTP(stOTP);
    USB_SetAppMode(pOtpInRam->PMOD);
    // Sys_Init();
    switch(pOtpInRam->PMOD)
    {
        case USB_TYPEC_TO_3P5:
        {
            Earphone_Detect_SetCallBack(EARPHONE_DETECT_INSERT, (uint32_t)EarPhone_Insert_Process);
            Earphone_Detect_SetCallBack(EARPHONE_DETECT_COMPLET, (uint32_t)EarPhone_Complet_Process);
            Earphone_Detect_SetCallBack(EARPHONE_DETECT_REMOVE, (uint32_t)EarPhone_Remove_Process);
            Earphone_Detect_Init();
            break;
        }
        case USB_TYPEC_HEADSET:
        {

        	USB_ConfigHeadSet();
            break;
        }
        case USB_TYPEC_HEADPHONE:
        {

        	USB_ConfigHeadPhone();
            break;
        }
        case USB_DONGLE:
        {

        	//USB_ConfigDongle();
            break;
        }
        case USB_DONGLE_DSP:
        {

        	//USB_ConfigDongle();
            break;
        }
        default: //USB_TEST
        {
        	USB_ConfigTest();
            break;
        }
    }

    if((pOtpInRam->UsbCodeState&BIT0) != 0)
    {
	   stOTP.stManufact.pString = (uint8_t*)pOtpInRam->UsbManufact;
	   stOTP.stManufact.bLength = 60;
	   stOTP.stManufact.bDescriptorType = 0x03;
    }
    if((pOtpInRam->UsbCodeState&BIT1) != 0)
    {
 	   stOTP.stProduct.pString =  (uint8_t*)pOtpInRam->UsbProduct;
 	   stOTP.stProduct.bLength = 60;
 	   stOTP.stProduct.bDescriptorType = 0x03;
    }
    if((pOtpInRam->UsbCodeState&BIT2) != 0)
    {
 	   stOTP.stSerial.pString =  (uint8_t*)pOtpInRam->UsbSerial;
 	   stOTP.stSerial.bLength = 60;
 	   stOTP.stSerial.bDescriptorType = 0x03;
    }
    if((pOtpInRam->UsbCodeState&BIT3) != 0)
    {
 	   stOTP.stStringID.pString =  (uint8_t*)pOtpInRam->UsbStringID;
 	   stOTP.stStringID.bLength = 10;
 	   stOTP.stStringID.bDescriptorType = 0x03;
    }
    if((pOtpInRam->UsbCodeState&BIT4) != 0)
    {
        stOTP.u16VendorID =  pOtpInRam->UsbVendorID;
    }
    if((pOtpInRam->UsbCodeState&BIT5) != 0)
    {
    	stOTP.u16ProductID =  pOtpInRam->UsbProductID;
    }
    if((pOtpInRam->UsbCodeState&BIT6) != 0)
    {
    	stOTP.u8MaxPower =  pOtpInRam->ucUsbMaxPower;
    }
 //   GLOBAL_INT_START();
    USB_ConfigDongle();
}

//#define NCO_FCW_TEST
//#define NCO_FCW_DELTA_TEST
#define USB_DONGLE_KEY_TEST

int main(void) {

	ke_init();
	intc_init();
	//g_I2C_SlaveInit_para.Addr |= ((OTP_inRAM.bs.I2C_SlaveAddr)&0x3)<<2;


	tim_init();


    GLOBAL_INT_START();
    //apb_pad_gpio_func_cfg0_gpio5_func_sel_setf(3);
//    if(1 == apb_pad_input_status_pad_gpio5_in_getf())
//    {
//    	//USB_SetVendorMode(1);
//    }
    p_init();
    KT0656M_init();
    while(1) {
		#ifdef NCO_FCW_TEST
			Delay_Ms(1000);
			I2S_NCO_Init(48000);
			Delay_Ms(1000);
			I2S_NCO_Init(64000);
		#endif

		#ifdef NCO_FCW_DELTA_TEST
			Delay_Ms(1000);
			I2S_NCO_Init(48000);
			Delay_Ms(1000);
			I2S_NCO_Init(64000);
		#endif

		KT0656M_KeyDetect();
    	plf_schedule();//auto test
    }
}

