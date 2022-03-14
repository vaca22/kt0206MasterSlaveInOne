/*
 * dac_cali_main.c
 *
 *  Created on: Jan 31, 2019
 *      Author: chenbowen
 */

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "user.h"

USB_OTP gstOTP;
uint8_t *gp_public_buf = NULL;
void p_patch_init(void)
{
    power_on_patch_init();
    power_off_patch_init();
    power_ctrl_patch_init();
    audio_patch_init();
    audio_in_patch_init();
    audio_out_patch_init();
    user_patch_init();
    usb_hid_patch_init();
    usb_ch9_patch_init();
    usb_intr_patch_init();
    usb_audio_patch_init();
    usb_app_patch_init();
    usb_sdk_patch_init();
    usb_dongle_patch_init();
    usb_dongleDSP_patch_init();
    usb_HeadPhone_patch_init();
    usb_HeadSet_patch_init();
    usb_Test_patch_init();
    usb_3p5_patch_init();
    Suspend_patch_init();
    ecld_patch_init();
    asrc_adc_patch_init();
    asrc_codec_patch_init();
    asrc_dac_patch_init();
    drc_patch_init();
    dsp_patch_init();
    eq_patch_init();
    eq_top_patch_init();

    saradc_patch_init();
    earphone_key_detect_patch_init();

    surround_3d_patch_init();
    volume_patch_init();
    nco_patch_init();
    nco_write_patch_init();
    process_adc2usb_patch_init();
#if 0
    process_i2s_patch_init();
    reverb_patch_init();
    echo_patch_init();
    freq_shift_patch_init();
    howling_detect_patch_init();
#endif
    process_usb2dac_patch_init();

    I2sNco_patch_init();
    Standby_Req_patch_init();
    EarphoneIRDet_patch_init();
    Earphone_KWP_Det_patch_init();
}

void Audio_Decode0(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, uint16_t usSampleNum, uint16_t usSignal)
{
	static float Fs = 46875;
	static float LFsig = 1000;

	static float ldelta_phase_f;
	static int ldelta_phase = 0;
	static int lphase = 0;
	static int first_flag = 1;
	int lsample;
	UINT16 i;

	if(first_flag)
	{
		ldelta_phase_f = LFsig/Fs *65536;//32768;
		ldelta_phase = (int)ldelta_phase_f;
		first_flag = 0;
	}

	for(i = 0; i < usSampleNum; i++)
	{
		if(lphase > 65535)//32767
		{
			lphase = lphase - 65536;//32768;
		}
		lsample = nds32_sin_q15(lphase);

		lphase = lphase + ldelta_phase;

		// lsample = sin_data[i & 0x0F];

		if(CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))){
			pDac0Addr[i] = lsample<<6;
		}
		if(CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))){
			pDac1Addr[i] = lsample<<6;
		}
		if((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R))))
		{
			pI2sOutlAddr[i] = lsample<<6;
			pI2sOutrAddr[i] = lsample<<6;
		}
	}
}

int main(void) 
{
	p_patch_init();
	
    // Initialize the Interrupt Controller
    intc_init();
    
    // power on
    Headset_PowerOn();

    GLOBAL_INT_START();

//    Audio_DAC_PowerOn();
    DEBUG_GPIO5_SET();

    AUDIO_CallBack_Set(AUDIO_OUT ,Audio_Decode0);
    AUDIO_OUT_Init(AUDIO_FIFO_ADDR, 16, CO_BIT(DAC0)| CO_BIT(DAC1), 0);
    AUDIO_OUT_Start(CO_BIT(DAC0)|CO_BIT(DAC1),0);

    Delay_Us(500);

    AUDIO_OUT_Stop(CO_BIT(DAC0)| CO_BIT(DAC1), 0);

    DEBUG_GPIO5_CLR();

    g_stStartFlag.OutStartFlag = 1;

    while(1) 
    {
        //TODO - add Event FSM loop
        //TEST
        Itrim_Monitor();
    }
}
