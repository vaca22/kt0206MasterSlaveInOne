/*
 * audio_test_final.c
 *
 *  Created on: May 31, 2018
 *      Author: chenbowen
 */

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "user.h"

co_rbuf_t stRBufAudio[8];
volatile q7_t Encode_Buf[8][256];
// const q31_t sin_data[] = {
// 	0  ,     12540   ,    23170   ,    30274  ,     32768  ,     30274  ,     23170  ,     12540  ,
// 	0  ,    -12540   ,   -23170   ,   -30274  ,    -32768  ,    -30274  ,    -23170  ,    -12540
// };

void Audio_Encode0(q31_t *pAdc0Addr, q31_t *pAdc1Addr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, uint16_t usSampleNum, uint16_t usSignal)
{
	if(CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0)))
	{
		uint16_t i;
		for(i = 0; i < usSampleNum; i++)
		{
			Encode_Buf[0][i] = pAdc0Addr[i];
		}
	}

	if((CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R))))
	{
		uint16_t i;
		for(i = 0; i < usSampleNum; i++)
		{
			Encode_Buf[1][i] = pI2sInlAddr[i];
			Encode_Buf[2][i] = pI2sInrAddr[i];
		}
	}
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

void Audio_Encode1(q31_t *pAdc0Addr, q31_t *pAdc1Addr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, uint16_t usSampleNum, uint16_t usSignal)
{
	if(CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0)))
	{
		uint32_t uLen0 = co_rbuf_free_blocks_get(&stRBufAudio[0]);
		if(uLen0 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[0], pAdc0Addr, usSampleNum);
		}

		uint32_t uLen1 = co_rbuf_free_blocks_get(&stRBufAudio[1]);
		if(uLen1 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[1], pAdc0Addr, usSampleNum);
		}

		uint32_t uLen2 = co_rbuf_free_blocks_get(&stRBufAudio[2]);
		if(uLen2 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[2], pAdc0Addr, usSampleNum);
		}

		uint32_t uLen3 = co_rbuf_free_blocks_get(&stRBufAudio[3]);
		if(uLen3 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[3], pAdc0Addr, usSampleNum);
		}
	}

	if((CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R))))
	{

		uint32_t uLen0 = co_rbuf_free_blocks_get(&stRBufAudio[0]);
		if(uLen0 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[0], pI2sInlAddr, usSampleNum);
		}

		uint32_t uLen1 = co_rbuf_free_blocks_get(&stRBufAudio[1]);
		if(uLen1 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[1], pI2sInrAddr, usSampleNum);
		}

		uint32_t uLen2 = co_rbuf_free_blocks_get(&stRBufAudio[2]);
		if(uLen2 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[2], pI2sInlAddr, usSampleNum);
		}

		uint32_t uLen3 = co_rbuf_free_blocks_get(&stRBufAudio[3]);
		if(uLen3 > usSampleNum)
		{
			co_rbuf_write(&stRBufAudio[3], pI2sInrAddr, usSampleNum);
		}
	}
}

void Audio_Decode1(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, uint16_t usSampleNum, uint16_t usSignal)
{
	uint16_t i;

	if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))))
	{
		if(CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0)))
		{
			uint32_t uLen0 = co_rbuf_written_blocks_get(&stRBufAudio[0]);
			for(i=0; i<usSampleNum; i++)
			{
				pDac0Addr[i] = 0;
			}

			if(uLen0 > usSampleNum)
			{
				co_rbuf_read(&stRBufAudio[0], pDac0Addr, usSampleNum);
			}
		}
		if(CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1)))
		{
			uint32_t uLen1 = co_rbuf_written_blocks_get(&stRBufAudio[1]);
			for(i=0; i<usSampleNum; i++)
			{
				pDac1Addr[i] = 0;
			}

			if(uLen1 > usSampleNum)
			{
				co_rbuf_read(&stRBufAudio[1], pDac1Addr, usSampleNum);
			}
		}
	}

	if((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R))))
	{
		uint32_t uLen2 = co_rbuf_written_blocks_get(&stRBufAudio[2]);
		for(i=0; i<usSampleNum; i++)
		{
			pI2sOutlAddr[i] = 0;
		}

		if(uLen2 >= usSampleNum)
	    {
	        co_rbuf_read(&stRBufAudio[2], pI2sOutlAddr, usSampleNum);
	    }

	    uint32_t uLen3 = co_rbuf_written_blocks_get(&stRBufAudio[3]);
	    for(i=0; i<usSampleNum; i++)
		{
			pI2sOutrAddr[i] = 0;
		}

		if(uLen3 >= usSampleNum)
	    {
	    	co_rbuf_read(&stRBufAudio[3], pI2sOutrAddr, usSampleNum);
	    }
	}
}

//void Tdm_Encode0(uint32_t *pAddr, uint16_t usSampleNum, uint8_t ucTrackNum)
//{
//	uint16_t i, j;
//
//	for(i=0; i<usSampleNum; i++)
//	{
//		for(j=0; j<g_ucTrackNum; j++)
//		{
//			Encode_Buf[j][i] = ((uint32_t *)(pAddr[j]))[i];
//		}
//	}
//}

//void Tdm_Decode0(uint32_t *pAddr, uint16_t usSampleNum, uint8_t ucTrackNum)
//{
//	static float Fs = 46875;
//	static float LFsig = 2000;
//
//	static float ldelta_phase_f;
//	static int ldelta_phase = 0;
//	static int lphase = 0;
//	static int first_flag = 1;
//	int lsample;
//	int16_t i, j;
//
//	if(first_flag)
//	{
//		ldelta_phase_f = LFsig/Fs *65536;//32768;
//		ldelta_phase = (int)ldelta_phase_f;
//		first_flag = 0;
//	}
//
//	for(i = 0; i < usSampleNum; i++)
//	{
//		if(lphase > 65535)//32767)
//		{
//			lphase = lphase - 65536;//32768;
//		}
//		lsample = nds32_sin_q15(lphase);
//
//		lphase = lphase + ldelta_phase;
//
//		// lsample = sin_data[i & 0x0F];
//
//		for(j=0; j<ucTrackNum; j++)
//		{
//			((uint32_t *)(pAddr[j]))[i] = lsample<<13;
//		}
//	}
//}

//void Tdm_Encode1(uint32_t *pAddr, uint16_t usSampleNum, uint8_t ucTrackNum)
//{
//	uint8_t i;
//	uint32_t uLen[ucTrackNum];
//	for(i = 0; i < ucTrackNum; i++)
//	{
//		uLen[i] = co_rbuf_free_blocks_get(&stRBufAudio[i]);
//		if(uLen[i] > usSampleNum)
//		{
//			co_rbuf_write(&stRBufAudio[i], (uint32_t *)(pAddr[i]), usSampleNum);
//		}
//	}
//}

//void Tdm_Decode1(uint32_t *pAddr, uint16_t usSampleNum, uint8_t ucTrackNum)
//{
//    uint8_t i, j;
//    uint32_t uLen[ucTrackNum];
//    for(i = 0; i < ucTrackNum; i++)
//    {
//    	uLen[i] = co_rbuf_written_blocks_get(&stRBufAudio[i]);
//    	for(j=0; j<usSampleNum; j++)
//    	{
//    		((uint32_t *)(pAddr[i]))[j] = 0;
//    	}
//    	if(uLen[i] >= usSampleNum)
//    	{
//    		co_rbuf_read(&stRBufAudio[i], (uint32_t *)(pAddr[i]), usSampleNum);
//    	}
//    }
//}

void p_patch_init(void)
{
    power_on_patch_init();
    power_off_patch_init();
    power_ctrl_patch_init();
    qspi_ctrl_patch_init();
    audio_patch_init();
    audio_in_patch_init();
    audio_out_patch_init();
    user_patch_init();
    usb_intr_patch_init();
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
//    echo_patch_init();
    eq_patch_init();
    eq_top_patch_init();
//    freq_shift_patch_init();
//    howling_detect_patch_init();
//    reverb_patch_init();
    surround_3d_patch_init();
    volume_patch_init();
    nco_patch_init();
    nco_write_patch_init();
    process_adc2usb_patch_init();
//    process_i2s_patch_init();
    process_usb2dac_patch_init();

    I2sNco_patch_init();
    Standby_Req_patch_init();
    EarphoneIRDet_patch_init();
    Earphone_KWP_Det_patch_init();
}

// #define ADC_TEST
#define DAC_TEST
// #define I2S_IN_TEST
// #define I2S_OUT_TEST
// #define TDM_IN_TEST
// #define TDM_OUT_TEST

uint16_t ucAudioBuf[8][256];

int main(void) 
{
    uint8_t i;
    uint16_t usSampleNum;
    uint32_t uFifoAddr = AUDIO_FIFO_ADDR;

	p_patch_init();
	
    // Initialize the Interrupt Controller
    intc_init();
    
    // power on
    Headset_PowerOn();

    // ring buffer initial
    for(i = 0; i < 4; i++)
    {
    	rbuf_init(&stRBufAudio[i], ucAudioBuf[i], sizeof(ucAudioBuf[i]), 4);
    }
    
    AUDIO_Sampling_Set(0, 0);

#ifdef ADC_TEST
    usSampleNum = 16;
    AUDIO_CallBack_Set(AUDIO_IN, Audio_Encode1);
    uFifoAddr = AUDIO_IN_Init(uFifoAddr, usSampleNum, CO_BIT(ADC0), 0);
    AUDIO_IN_Start(CO_BIT(ADC0), 0);
#endif

#ifdef DAC_TEST
    usSampleNum = 16;
    AUDIO_CallBack_Set(AUDIO_OUT, Audio_Decode0);
	uFifoAddr = AUDIO_OUT_Init(uFifoAddr, usSampleNum, (CO_BIT(DAC0)|CO_BIT(DAC1)), 0);
	AUDIO_OUT_Start((CO_BIT(DAC0)|CO_BIT(DAC1)), 0);
#endif

#ifdef I2S_IN_TEST
    usSampleNum = 16;
    I2s_Para_Tran(&g_stI2sCfgSet_All[0]);
    AUDIO_CallBack_Set(AUDIO_IN, Audio_Encode1);
    uFifoAddr = AUDIO_IN_Init(uFifoAddr, usSampleNum, (CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)), MASTER0);
    AUDIO_IN_Start((CO_BIT(I2S_IN_L)|CO_BIT(I2S_IN_R)), MASTER0);
#endif

#ifdef I2S_OUT_TEST
    usSampleNum = 16;
    I2s_Para_Tran(&g_stI2sCfgSet_All[0]);
    AUDIO_CallBack_Set(AUDIO_OUT, Audio_Decode1);
	uFifoAddr = AUDIO_OUT_Init(uFifoAddr, usSampleNum, (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)), MASTER1);
	AUDIO_OUT_Start((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)), MASTER1);
#endif

#ifdef TDM_IN_TEST
	usSampleNum = 16;
	TDM_Para_Tran(&g_stTdmCfgSet_All[0], &g_stTdmCtrlSet_All[AUDIO_IN]);
	TDM_CallBack_Set(AUDIO_IN, Tdm_Encode1);
	uFifoAddr = TDM_IN_Init(uFifoAddr, usSampleNum, CO_BIT(MASTER0));
#endif

#ifdef TDM_OUT_TEST
	usSampleNum = 16;
	TDM_Para_Tran(&g_stTdmCfgSet_All[0], &g_stTdmCtrlSet_All[AUDIO_OUT]);
    TDM_CallBack_Set(AUDIO_OUT, Tdm_Decode1);
	uFifoAddr = TDM_OUT_Init(uFifoAddr, usSampleNum, CO_BIT(MASTER1));
#endif

    GLOBAL_INT_START();

    while(1) 
    {
        //TODO - add Event FSM loop
        //TEST
    }
}
