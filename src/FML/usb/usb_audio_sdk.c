/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        :
* lizhen 2018/12/19  (1) move the "USB_ADC_EOF_FLAG = 1" to soft interrupt;
********************************************************************************/
#include "hal_includes.h"
#include "hal_config.h"
#include "bll_config.h"
#include "usb_audio_sdk.h"
#include "Co_rbuf.h"
#include "Asrc_dac_fs_ppm.h"
#include "Asrc_adc_fs_ppm.h"

#include "i2s_nco_readbuf.h"	//
#include "i2s_nco_writebuf.h"
#include "fml_includes.h"
#include "i2s_nco.h"
#include "co_rbuf.h"
#include "asrc_adc_fs_ppm.h"
#include "volume.h"
#include "chip_config.h"
#include "swi.h"
#include "DongleEffect_top.h"
#include "chipEffect_top.h"
#include "effect_config.h"
#include "asrc_adc_fs_ppm_pack.h"
#include "uswi_asrc.h"
//int32_t new_usb_data_mute[96] = {0};//usb录音关闭的时候，把0送往usb,可能还得放回函数里每次都初始化
uint8_t SWI_UsbIn_flag = 0;
uint8_t SWI_UsbOut_flag = 0;
uint8_t asrc_return_flag = 0;
uint8_t gucValidDataFlag = 0;
uint8_t usb_in_aud_flag = 0; //usb in interrupt indecate, must cleared by user if used
uint8_t usb_out_aud_flag = 0; //usb out interrupt indecate, must cleared by user if used

#ifdef I2S_IN_DATA_PROCESS_USER
extern void i2sInDataProcessUser(int32_t *pI2sInlAddr, int32_t *pI2sInrAddr, uint32_t Len); //the i2s data used by user
#endif

void new_patch_USB_In_Speaker(void)
{
	stUSB_Audio_Attr stAudioAttrIn = {0};
	int32_t* pUsbBuffIn[2];
	u8UsbReadFlag = 1;
	usb_in_aud_flag = 1;
	if((u8UsbReadFlag != 1)||(u8AdcWriteFlag != 1))
	{
		return ;
	}
	Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_IN,&stAudioAttrIn,sizeof(stUSB_Audio_Attr));
	Usb_Get_USB_Buff(0,USB_CALLBACK_AUDIO_IN,&pUsbBuffIn,USB_IN_CHANNEL,sizeof(int32_t*));

	int16_t ii;
	int16_t SamPointNum = stAudioAttrIn.u8SamPointNum;
#ifdef USB2DSP_SMP_RATE_DIFF
	extern uint8_t sampleMultiple;
	if(sampleMultiple == 2)
	{
		uint8_t jj = 0;
		for(ii = 0; ii < SamPointNum; ii += sampleMultiple)
		{
			*(pUsbBuffIn[0]+ii) = usb_data[jj];
			*(pUsbBuffIn[0]+ii+1) = usb_data[jj];
			jj++;
		}
		#if (USB_IN_CHANNEL == 2)
		memcpy(pUsbBuffIn[1],pUsbBuffIn[0],SamPointNum);
		#endif
	}
	else if(sampleMultiple == 4)
	{
		uint8_t jj = 0;
		for(ii = 0; ii < SamPointNum; ii += sampleMultiple)
		{
			*(pUsbBuffIn[0]+ii) = usb_data[jj];
			*(pUsbBuffIn[0]+ii+1) = usb_data[jj];
			*(pUsbBuffIn[0]+ii+2) = usb_data[jj];
			*(pUsbBuffIn[0]+ii+3) = usb_data[jj];
			jj++;
		}
		#if (USB_IN_CHANNEL == 2)
		memcpy(pUsbBuffIn[1],pUsbBuffIn[0],SamPointNum);
		#endif
	}
	else 
#endif
	{
		for(ii = 0; ii < SamPointNum; ii++)
		{
			*(pUsbBuffIn[0]+ii) = usb_data[ii];
			#if (USB_IN_CHANNEL == 2)
			*(pUsbBuffIn[1]+ii) = usb_data[ii+SamPointNum];
			#endif
		}
	}
	//USB_ADC_EOF_FLAG = 1; // after the adc_ringbuf_rp updated in ASRC
	SWI_UsbIn_flag = 1;
	Gen_SWI();
}

void new_patch_USB_Out_Speaker(void) //USB 1ms interrupt
{
	uint16_t cnt = 0;
	int32_t* pUsbAddr[2] ={0};
	stUSB_Audio_Attr stAudioAttr = {0};
	stUSB_Audio_Attr stAudioAttrIn = {0};
	Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttr,sizeof(stUSB_Audio_Attr));
	Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_IN,&stAudioAttrIn,sizeof(stUSB_Audio_Attr));
	Usb_Get_USB_Buff(0,USB_CALLBACK_AUDIO_OUT,pUsbAddr,2,sizeof(int32_t*));

	for (cnt = 0; cnt < USB_DAC_PCM_NUM; cnt++)
	{
		if (__nds32__abs(pUsbAddr[0][cnt]) > 2 || __nds32__abs(pUsbAddr[1][cnt]) > 2)
		{
			usb_out_aud_flag = 1;
			break;
		}
	}
#if (AUDIO_SAMPLE_BLOCK_SIZE == 48)
	/*write usb data to UsbOut ringbuffer && read processed data from UsbOut ringbuffer*/
	HeadsetEffect_Usbout_DataRW(g_st_pHeadsetEft, pUsbAddr[0], pUsbAddr[1], USB_DAC_PCM_NUM);
if((AUDIO_OUT_I2SSEL == 3 || AUDIO_OUT_I2SSEL == 1) ){
	if (stAudioAttr.u8Status == TRUE) {
		Pack_Asrc_write_ringbuf(&g_st_AsrcI2S, pUsbAddr[0], pUsbAddr[1], USB_DAC_PCM_NUM);
	}	
}
	asrc_write_ringbuf(pUsbAddr[0],pUsbAddr[1]);
#endif
    USB_DAC_EOF_FLAG =1;
    if(0 == AuOutStartFlg)
    {
    	if(u32USBOutIsrCnt < 300)
    	{
    		u32USBOutIsrCnt++;
    	}
    	else
    	{
    		u32USBOutIsrCnt = 0;
    		u8DacNeedStart = 1;
    	}
    }
    SWI_UsbOut_flag = 1;
	if(stAudioAttrIn.u8Status == 0) /*when USB IN int stop GenSwi*/
	{
		Gen_SWI();
	}
}
/*******************************************************************************
* Function Name  :
* Description    :
* Input          :
* Output         :
* Return         :
*
*******************************************************************************/
// const  int32_t  g_const_test1k_fs48k[48] =    {0,     273733,     542782,     802545,    1048575,    1276665,    1482910,    1663782,    1816186,    1937515,    2025693,    2079210,    2097152,    2079210,    2025693,    1937515,    1816186,    1663782,    1482910,    1276665,    1048576,     802545,     542782,     273733,          0,    -273734,    -542783,    -802546,   -1048576,   -1276666,   -1482911,   -1663783,   -1816187,   -1937516,   -2025694,   -2079211,   -2097152,   -2079211,   -2025694,   -1937516,   -1816187,   -1663783,   -1482911,   -1276666,   -1048577,    -802546,    -542783,    -273734};
// const  int32_t  g_const_test2k_fs48k[48] =    {0,     542782,    1048575,    1482910,    1816186,    2025693,    2097152,    2025693,    1816186,    1482910,    1048576,     542782,          0,    -542783,   -1048576,   -1482911,   -1816187,   -2025694,   -2097152,   -2025694,   -1816187,   -1482911,   -1048577,    -542783,          0,     542782,    1048575,    1482910,    1816186,    2025693,    2097152,    2025693,    1816186,    1482910,    1048575,     542782,          0,    -542783,   -1048576,   -1482911,   -1816187,   -2025694,   -2097152,   -2025694,   -1816187,   -1482911,   -1048577,    -542783};

int32_t I2SIN_DataL_old = 0;          // previous Data

void new_patch_Audio_In_Speaker(q31_t *pAdc0Addr, q31_t *pAdc1Addr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT16 Signal)
{
	stUSB_Audio_Attr stAudioAttrOut = {0};
	Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttrOut,sizeof(stUSB_Audio_Attr));

	u8AdcWriteFlag = 1;
	
	int32_t temp = pI2sInlAddr[SampleNum-1];
	uint32_t ii;
	for(ii=SampleNum-1;ii>0;ii--)
	{
		pI2sInlAddr[ii]=pI2sInlAddr[ii-1];
	}
	pI2sInlAddr[0] = I2SIN_DataL_old;    // load old data
	I2SIN_DataL_old = temp;              // save old data

	#ifdef APPLE_EARPHONE_KEY_SUPPORT
	key_fifo_check();
	#endif

	#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)

		if((stUsbAudio.u8Mute & BIT_MIC) || (g_mute_bit & BIT_MIC))
		{
			int32_t usb_data_mute[96]={0};
			Pack_asrc_In_Writebuf(&g_st_AsrcI2SIN, usb_data_mute, usb_data_mute+48, USB_ADC_FS);
			if (stAudioAttrOut.u8Status == FALSE) {
				Pack_asrc_In_Writebuf(&g_st_AsrcI2SIN2Dac, pI2sInlAddr, pI2sInrAddr, USB_ADC_FS);
			}	
		}
		else
		{
		#ifdef I2S_IN_DATA_PROCESS_USER
			i2sInDataProcessUser(pI2sInlAddr, pI2sInrAddr, SampleNum);
		#endif
		#ifdef USB_IN_I2S_VOLUME_CTRL_BY_USER
			HeadsetEffect_AdcStereoin(g_st_pHeadsetEft, pI2sInlAddr, pI2sInrAddr, SampleNum);
		#else
			// nds32_dup_q31((int32_t *)g_const_test1k_fs48k, pI2sInlAddr, SampleNum);
			// nds32_dup_q31((int32_t *)g_const_test2k_fs48k, pI2sInrAddr, SampleNum);
			Dsp24bitVolume_Sat(pI2sInlAddr, pI2sInlAddr, g_dsp_gain_i2sil, SampleNum);
			Dsp24bitVolume_Sat(pI2sInrAddr, pI2sInrAddr, g_dsp_gain_i2sir, SampleNum);

			HeadsetEffect_AdcStereoin(g_st_pHeadsetEft, pI2sInlAddr, pI2sInrAddr, SampleNum);
			uint16_t vol = volume_table[dsp_adc2usb_vol];
			int64_t  vol_buff_tmp = g_adc2usb_vol_buff;
			Dsp24bitVolumeSmooth(pI2sInlAddr, pI2sInlAddr, vol, &vol_buff_tmp,       SampleNum);
			Dsp24bitVolumeSmooth(pI2sInrAddr, pI2sInrAddr, vol, &g_adc2usb_vol_buff, SampleNum);
		#endif
			Pack_asrc_In_Writebuf(&g_st_AsrcI2SIN, pI2sInlAddr, pI2sInrAddr, USB_ADC_FS);//
			if (stAudioAttrOut.u8Status == FALSE) {
				Pack_asrc_In_Writebuf(&g_st_AsrcI2SIN2Dac, pI2sInlAddr, pI2sInrAddr, USB_ADC_FS);
			}
		}
	#else
	int32_t *pDataMux;
	#if SIDETONE_ALWAYS_ON_EN
	#else
		if ((u8UsbReadFlag != 1) || (u8AdcWriteFlag != 1))
		{
			return ;
		}
	#endif
	/* digital gain*/
	#if (AUDIO_IN_SEL==1)
		Dsp24bitVolume_Sat(pAdc0Addr, pAdc0Addr, g_dsp_gain_adc, SampleNum);
		pDataMux = pAdc0Addr;
	#else
	#ifdef I2S_IN_DATA_PROCESS_USER
		i2sInDataProcessUser(pI2sInlAddr, pI2sInrAddr, SampleNum);
	#endif
		#if(AUDIO_IN_SEL==2)
		Dsp24bitVolume_Sat(pI2sInlAddr, pI2sInlAddr, g_dsp_gain_i2sil, SampleNum);
		Dsp24bitVolume_Sat(pI2sInrAddr, pI2sInrAddr, g_dsp_gain_i2sir, SampleNum);
		#ifndef USB_IN_I2S_LEFT
			nds32_add_q31(pI2sInlAddr,pI2sInrAddr,pI2sInlAddr,SampleNum);
		#endif
		pDataMux = pI2sInlAddr;
		#else//(AUDIO_IN_SEL==3)
		Dsp24bitVolume_Sat(pI2sInlAddr, pI2sInlAddr, g_dsp_gain_i2sil, SampleNum);
		Dsp24bitVolume_Sat(pI2sInrAddr, pI2sInrAddr, g_dsp_gain_i2sir, SampleNum);
		#ifndef USB_IN_I2S_LEFT
			nds32_add_q31(pI2sInlAddr,pI2sInrAddr,pI2sInlAddr,SampleNum);
		#endif
		Dsp24bitVolume_Sat(pAdc0Addr, pAdc0Addr, g_dsp_gain_adc, SampleNum);
		nds32_add_q31(pAdc0Addr,pI2sInlAddr,pAdc0Addr,SampleNum);
		pDataMux = pAdc0Addr;
		#endif
	#endif

#if EQ10band_down_MicNoise
	/*10bandEQ*/
	eq10band_mono_top(pDataMux,pDataMux,SampleNum);
#endif

	/* Effect */
	HeadsetEffect_Adcin(g_st_pHeadsetEft, pDataMux, SampleNum);

#ifndef USB_IN_I2S_VOLUME_CTRL_BY_USER
	/* volume ctrl*/
	uint16_t vol = volume_table[dsp_adc2usb_vol];
	Dsp24bitVolumeSmooth(pDataMux,pDataMux,vol, &g_adc2usb_vol_buff, SampleNum);
#endif

	if((stUsbAudio.u8Mute & BIT_MIC) || (g_mute_bit & BIT_MIC))
	{
		int32_t usb_data_mute[96]={0};
		asrc_adc_writebuf(usb_data_mute);
	}
	else
	{
		asrc_adc_writebuf(pDataMux);//把usb_data_in的数据写到 g_pAdcRingBufLeft 里面
	}
	#endif /* (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2) */
}

#if SIDETONE_ALWAYS_ON_EN
void new_patch_Audio_Out_Speaker(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal)
{
	#if((AUDIO_OUT_SEL==1)||(AUDIO_OUT_SEL==3))
	// static int64_t vol_buff_l=0;
	// static int64_t vol_buff_r=0;
	// uint32_t cnt;
	AuOutIntFlg = 1;
	dac_l_peak_dat = 0;
	// register int32_t TempInt32;
	// /*Fs<48000 ????*/
	// int32_t *pUsbDataL = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left;
	// int32_t *pUsbDataR = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right;
	asrc_return_flag = 0;
	#endif
	asrc_dac_top(
	     stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left ,
	     stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right ,  //not used when AUDIO_SAMPLE_BLOCK_SIZE == 48
	     usb_data_left, usb_data_right); // clear USB_EOF_FLAG in this function
	if(1 == asrc_return_flag)
	{
		if  (AUDIO_OUT_I2SSEL == 0 || AUDIO_OUT_I2SSEL == 2){
			nds32_dup_q31(usb_data_left,pI2sOutlAddr,SampleNum);
			nds32_dup_q31(usb_data_right,pI2sOutrAddr,SampleNum);
		}
		return;
	}

	#if((AUDIO_OUT_SEL==1)||(AUDIO_OUT_SEL==3))
	/* judge data valid */
	// gucValidDataFlag = 0;
	// for (cnt = 0; cnt < SampleNum; cnt++)
	// {
	// 	if (__nds32__abs(usb_data_left[cnt]) > 2 || __nds32__abs(usb_data_right[cnt]) > 2)
	// 	{
			gucValidDataFlag = 1;
	// 		break;
	// 	}
	// }
	#endif
#else /* SIDETONE_ALWAYS_ON_EN */
void new_patch_Audio_Out_Speaker(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal)
{
	#if((AUDIO_OUT_SEL==1)||(AUDIO_OUT_SEL==3))
	// static int64_t vol_buff_l=0;
	// static int64_t vol_buff_r=0;
	uint32_t cnt;
	AuOutIntFlg = 1;
	dac_l_peak_dat = 0;
	register int32_t TempInt32;
	/*Fs<48000 ????*/
	int32_t *pUsbDataL = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left;
	int32_t *pUsbDataR = stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right;
	for (cnt = 0; cnt < SampleNum; cnt++)
	{
		TempInt32 = __nds32__abs(pUsbDataL[cnt]) > __nds32__abs(pUsbDataR[cnt]) ? __nds32__abs(pUsbDataL[cnt]) : __nds32__abs(pUsbDataR[cnt]);
		if(TempInt32 > dac_l_peak_dat)
		{
			dac_l_peak_dat = TempInt32;
		}
	}
	if ((dac_l_peak_dat < AUDAC_MUTE_DET_THRD) && (dac_l_mute_det_cnt < 0x7FFFFFF0) )
	{
		dac_l_mute_det_cnt++;
	}

	uint32_t CntTh = AUDAC_MUTE_DET_WIN * DAC_FS_TABLE[USB_DAC_FS_D] / (1000* SampleNum);
	if (1 == AUDAC_MUTE_BY_PDDAC_EN)
	{
		if (0 == dac_l_peak_dat)	//when continuous N*50ms player "pause", output all '0', power off DAC
		{
			if ( Audio_DAC_PowerOff_CNT < ( CntTh * AUDAC_POWEROFF_CNT_WIN) ) // continuous 100*50ms= 5000ms
			{
				Audio_DAC_PowerOff_CNT++;
			}
			else if (0 == Audio_DAC_PowerOff_Status) //
			{
				DacMuteByPdFlg = 1;					//Audio_DAC_normal_PowerOff(); move to bll_misc.c
				Audio_DAC_PowerOff_Status = 1;
			}
			else;
		}
	}

	if (	((dac_l_mute_det_cnt > CntTh) && (dac_l_peak_dat < AUDAC_MUTE_DET_THRD))	//mute
	        || ((1 == dac_mute_flag) && (dac_l_peak_dat < (AUDAC_MUTE_DET_THRD * 4)))) // high thresh for hyst
	{
		dac_l_mute_det_cnt = 0;
		dac_l_peak_dat = 0;
		if (IsRampDown)
		{
			g_32HalDacDcOffsetL = DAC_DC_CALI_L + cos_ramp_signal;
			g_32HalDacDcOffsetR = DAC_DC_CALI_R + cos_ramp_signal;
		}
		else
		{
			g_32HalDacDcOffsetL = DAC_DC_CALI_L + new_ramp_signal;
			g_32HalDacDcOffsetR = DAC_DC_CALI_R + new_ramp_signal;
		}
		for (cnt = 0; cnt < SampleNum; cnt++)
		{
			pDac0Addr[cnt] = g_32HalDacDcOffsetL;
			pDac1Addr[cnt] = g_32HalDacDcOffsetR;
		}
		/*if DAC mute, then set classG vdd as low rail*/
		if(1 == apb_power_pd_ctrl1_cg_vdd_rail_sel_getf())
		{
			apb_power_pd_ctrl1_cg_cp_freq_sel_setf(ucLowRailCpClk);
			apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(0);
		}
		dac_mute_flag = 1;
		asrc_return_flag = 1;
		//return;  // must place return in asrc_dac_fs_ppm.c  and after asrc_dac_top() !!!
	}
	else if (dac_l_peak_dat > AUDAC_MUTE_DET_THRD)		//recover from mute
	{
		dac_l_mute_det_cnt = 0;
		dac_mute_flag = 0;
		asrc_return_flag = 0;
		if (1 == AUDAC_MUTE_BY_PDDAC_EN)
		{
			if (Audio_DAC_PowerOff_Status == 1)
			{
				DacRecoverFromPdFlg = 1;				//Audio_DAC_PowerOn(); move to bll_misc.c
				Audio_DAC_PowerOff_Status = 0;
				Audio_DAC_PowerOff_CNT = 0;
			}
		}
		if ((new_ramp_signal < ramp_dcoffset) && (!IsRampDown)) // 1/212 in 32Q23
		{
			if ((new_ramp_signal < (rampup_step * 2)) && (rampcnt < 20))
			{
				rampcnt++;
				new_ramp_signal = 0;
			}
			else
			{
				new_ramp_signal += rampup_step;
			}
		}
	}
	else
	{
		asrc_return_flag = 0;
	}
	#endif
	#if (AUDIO_SAMPLE_BLOCK_SIZE == 16)

	if(USB_DAC_EOF_FLAG)
	{
		HeadsetEffect_Usbout_DataRW(g_st_pHeadsetEft,
				stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left ,
				stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right ,
				USB_DAC_PCM_NUM);
	}

	#endif
	asrc_dac_top(
	     stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Left ,
	     stUsbAudio.stAudioAttr[USB_AUDIO_OUT].pUsb_Data_Right ,  //not used when AUDIO_SAMPLE_BLOCK_SIZE == 48
	     usb_data_left, usb_data_right); // clear USB_EOF_FLAG in this function
	if(1 == asrc_return_flag)
	{
		if (AUDIO_OUT_I2SSEL == 0 || AUDIO_OUT_I2SSEL == 2){
			nds32_dup_q31(usb_data_left,pI2sOutlAddr,SampleNum);
			nds32_dup_q31(usb_data_right,pI2sOutrAddr,SampleNum);
	}
		return;
	}

	#if((AUDIO_OUT_SEL==1)||(AUDIO_OUT_SEL==3))
	/* judge data valid */
	gucValidDataFlag = 0;
	for (cnt = 0; cnt < SampleNum; cnt++)
	{
		if (__nds32__abs(usb_data_left[cnt]) > 2 || __nds32__abs(usb_data_right[cnt]) > 2)
		{
			gucValidDataFlag = 1;
			break;
		}
	}
	#endif
#endif  /* SIDETONE_ALWAYS_ON_EN */
	if(AUDIO_OUT_I2SSEL == 0 || AUDIO_OUT_I2SSEL == 2){
		nds32_dup_q31(usb_data_left, pI2sOutlAddr,SampleNum);
		nds32_dup_q31(usb_data_right,pI2sOutrAddr,SampleNum);
		#ifndef USB_OUT_I2S_VOLUME_CTRL_BY_USER
			uint16_t vol  = volume_table[dsp_i2so_vol_l];
			uint16_t vol1 = volume_table[dsp_i2so_vol_r];
			Dsp24bitVolumeSmooth(pI2sOutlAddr, pI2sOutlAddr, vol,  &g_dsp_i2so_vol_l_buff, SampleNum);
			Dsp24bitVolumeSmooth(pI2sOutrAddr, pI2sOutrAddr, vol1, &g_dsp_i2so_vol_r_buff, SampleNum);
		#endif
		if((stUsbAudio.u8Mute & BIT_SPK) || (g_mute_bit & BIT_SPK)){
			Dsp24bitVolume_Sat(pI2sOutlAddr,  pI2sOutlAddr, 0, SampleNum);
			Dsp24bitVolume_Sat(pI2sOutrAddr,  pI2sOutrAddr, 0, SampleNum);
		}else{
			Dsp24bitVolume_Sat(pI2sOutlAddr,  pI2sOutlAddr, g_dsp_gain_i2sol, SampleNum);
			Dsp24bitVolume_Sat(pI2sOutrAddr,  pI2sOutrAddr, g_dsp_gain_i2sor, SampleNum);
		}
		}
	#if ((AUDIO_OUT_SEL==1) || (AUDIO_OUT_SEL==3))
	/* Effect */
	HeadsetEffect_Dacout( g_st_pHeadsetEft, usb_data_left, usb_data_right, SampleNum);
	/*volume control move to headsetEffect Dacout*/
	// uint16_t vol  = volume_table[dsp_usb2dac_vol_l];
	// uint16_t vol1 = volume_table[dsp_usb2dac_vol_r];
	// Dsp24bitVolumeSmooth(usb_data_left, pDac0Addr, vol,  &g_usb2dac_vol_buff_l, SampleNum);
	// Dsp24bitVolumeSmooth(usb_data_right,pDac1Addr,vol1, &g_usb2dac_vol_buff_r, SampleNum);

	// if (!((stUsbAudio.u8Mute)&BIT1)) {
	// 	Dsp24bitVolumeSmooth(pDac0Addr,  pDac0Addr, g_dsp_gain_dacl<<2, &vol_buff_l,SampleNum);
	// 	Dsp24bitVolumeSmooth(pDac1Addr,  pDac1Addr, g_dsp_gain_dacr<<2, &vol_buff_r,SampleNum);
	// }

	if (IsRampDown) {
		g_32HalDacDcOffsetL = DAC_DC_CALI_L + cos_ramp_signal;
		g_32HalDacDcOffsetR = DAC_DC_CALI_R + cos_ramp_signal;
	} else {
		g_32HalDacDcOffsetL = DAC_DC_CALI_L + new_ramp_signal;
		g_32HalDacDcOffsetR = DAC_DC_CALI_R + new_ramp_signal;
	}
	// for (cnt = 0; cnt < SampleNum; cnt++) //calibrate the DC offset
	// {
	// 	pDac0Addr[cnt] += g_32HalDacDcOffsetL;
	// 	pDac1Addr[cnt] += g_32HalDacDcOffsetR;
	// }
	nds32_offset_q31(usb_data_left,g_32HalDacDcOffsetL,pDac0Addr,SampleNum);
	nds32_offset_q31(usb_data_right,g_32HalDacDcOffsetR,pDac1Addr,SampleNum);

	#endif
}


void I2S_Audio_Out_Speaker(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal)
{
	stUSB_Audio_Attr stAudioAttrOut = {0};
	Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttrOut,sizeof(stUSB_Audio_Attr));
	if (stAudioAttrOut.u8Status == FALSE) return;

	Pack_Asrc_dac_top(&g_st_AsrcI2S, pI2sOutlAddr, pI2sOutrAddr, USB_DAC_FS);
#ifndef USB_OUT_I2S_VOLUME_CTRL_BY_USER
	uint16_t vol  = volume_table[dsp_i2so_vol_l];
	uint16_t vol1 = volume_table[dsp_i2so_vol_r];
	Dsp24bitVolumeSmooth(pI2sOutlAddr, pI2sOutlAddr,vol,  &g_dsp_i2so_vol_l_buff, SampleNum);
	Dsp24bitVolumeSmooth(pI2sOutrAddr, pI2sOutrAddr,vol1, &g_dsp_i2so_vol_r_buff, SampleNum);
#endif

	if((stUsbAudio.u8Mute & BIT_SPK) || (g_mute_bit & BIT_SPK))
	{
		Dsp24bitVolume_Sat(pI2sOutlAddr,  pI2sOutlAddr, 0, SampleNum);
		Dsp24bitVolume_Sat(pI2sOutrAddr,  pI2sOutrAddr, 0, SampleNum);
	}
	else
	{
		Dsp24bitVolume_Sat(pI2sOutlAddr,  pI2sOutlAddr, g_dsp_gain_i2sol, SampleNum);
		Dsp24bitVolume_Sat(pI2sOutrAddr,  pI2sOutrAddr, g_dsp_gain_i2sor, SampleNum);
	}
	return;
};



// void Audio_In_Dongle_Write(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal)
// {
// 	pusb_sdk_ftabl->InDongleWrite(pDac0Addr, pDac1Addr, pI2sOutlAddr, pI2sOutrAddr, SampleNum, Signal);
// }

// __pack_func__ void new_patch_Audio_In_Dongle_Write(q31_t *pAdc0Addr, q31_t *pAdc1Addr , q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT16 Signal)
// {
// 	q31_t pTmp[AUDIO_SAMPLE_BLOCK_SIZE] = {0};
// 	int32_t usb_data_mute[AUDIO_SAMPLE_BLOCK_SIZE*2] = {0};


// 	switch (g_pstConfig->FuncCfg.DongleAudioInSel) {
// 	case DONGLE_ADC_IN: {
// 		g_u8DongleAdcWrtFlag = 1;
// 		if ((g_u8DongleUsbRdFlag != 1) || (g_u8DongleAdcWrtFlag != 1))
// 		{
// 			return ;
// 		}
// 		pI2sInlAddr = pTmp;
// 		pI2sInrAddr = pTmp;

// 		Dsp24bitVolume_Sat(pAdc0Addr, pAdc0Addr, g_dsp_gain_adc, SampleNum);

// //		adc_i2s_mux_dongle(pAdc0Addr, pI2sInlAddr, pI2sInrAddr, new_usb_data_in, new_usb_data_in + SampleNum, SampleNum);
// //		DongleEffectPath_MonoIn( g_st_pDongleEft, pAdc0Addr, usb_data_in, usb_data_in + SampleNum, SampleNum);

// 		if ((stUsbAudio.u8Mute)&BIT0) //mute
// 		{
// 			asrc_adc_writebuf(usb_data_mute);
// 		}
// 		else
// 		{
// 			asrc_adc_writebuf(usb_data_in);
// 		}
// 		break;
// 	}
// 	case DONGLE_I2S_MASTER_IN: {
// 		uint32_t ii = 0;
// 		pAdc0Addr = pTmp;
// 		int32_t *pOut0 = usb_data_in;
// 		int32_t *pOut1 = usb_data_in + SampleNum;
// 		i2s_nco_writebuf(pOut0, pOut1, SampleNum);		//nco test
// 		Dsp24bitVolume_Sat(pI2sInlAddr, pI2sInlAddr, g_dsp_gain_i2sil, SampleNum);
// 		Dsp24bitVolume_Sat(pI2sInrAddr, pI2sInrAddr, g_dsp_gain_i2sir, SampleNum);

// //		adc_i2s_mux_dongle(pAdc0Addr, pI2sInlAddr, pI2sInrAddr, pOut0, pOut1, SampleNum);
// 		uint16_t vol = volume_table[dsp_usb_postvol];
// //		Dsp24bitVolume(pOut0, pOut0, vol, SampleNum);
// //		Dsp24bitVolume(pOut1, pOut1, vol, SampleNum);
// 		if(g_pstConfig->FuncCfg.DongleAudioInCfg)
// 		{
// //			DongleEffectPath_StereoIn( g_st_pDongleEft, pI2sInlAddr, pI2sInrAddr, SampleNum);
// 			Dsp24bitVolume(pI2sInlAddr, pOut0, vol, SampleNum);
// 			Dsp24bitVolume(pI2sInrAddr, pOut1, vol, SampleNum);
// 		}
// 		else
// 		{
// 			nds32_add_q31(pI2sInlAddr, pI2sInrAddr, pI2sInlAddr, SampleNum);
// //			DongleEffectPath_MonoIn( g_st_pDongleEft, pI2sInlAddr, pOut0, pOut1, SampleNum);
// 			Dsp24bitVolume(pOut0, pOut0, vol, SampleNum);
// 			Dsp24bitVolume(pOut1, pOut1, vol, SampleNum);
// 		}
// 		for (ii = 0; ii < SampleNum; ii++)
// 		{
// 			pOut0[ii] = __nds32__clips(pOut0[ii], 23);
// 			pOut1[ii] = __nds32__clips(pOut1[ii], 23);
// 		}
// //		i2s_nco_writebuf(pOut0, pOut1, SampleNum);		//nco test
// 		break;
// 	}
// 	case DONGLE_I2S_SLAVE_IN: {
// 		g_u8DongleI2sWrtFlag = 1;
// 		if ((g_u8DongleUsbRdFlag != 1) || (g_u8DongleI2sWrtFlag != 1))
// 		{
// 			return ;
// 		}
// 		Dsp24bitVolume_Sat(pI2sInlAddr, pI2sInlAddr, g_dsp_gain_i2sil, SampleNum);
// 		Dsp24bitVolume_Sat(pI2sInrAddr, pI2sInrAddr, g_dsp_gain_i2sir, SampleNum);

// 		int32_t *pOut0 = usb_data_in;
// 		int32_t *pOut1 = usb_data_in + SampleNum;

// //		adc_i2s_mux_dongle(pAdc0Addr, pI2sInlAddr, pI2sInrAddr, usb_data_in, usb_data_in + SampleNum, SampleNum);
// 		uint16_t vol = volume_table[dsp_usb_postvol];
// 		nds32_add_q31(pI2sInlAddr, pI2sInrAddr, pI2sInlAddr, SampleNum);
// //		DongleEffectPath_MonoIn( g_st_pDongleEft, pI2sInlAddr, pOut0, pOut1, SampleNum);
// 		Dsp24bitVolume(pOut0, pOut0, vol, SampleNum);
// 		Dsp24bitVolume(pOut1, pOut1, vol, SampleNum);

// 		if ((stUsbAudio.u8Mute)&BIT0) //mute
// 		{
// 			asrc_adc_writebuf(usb_data_mute);
// 		}
// 		else
// 		{
// 			asrc_adc_writebuf(usb_data_in);
// 		}
// 		break;
// 	}
// 	}
// }

// void USB_In_Dongle_Read(void)
// {
// 	pusb_sdk_ftabl->InDongleRead();
// }

// __pack_func__ void new_patch_USB_In_Dongle_Read(void)
// {
// 	stUSB_Audio_Attr stAudioAttrOut = {0};
// 	stUSB_Audio_Attr stAudioAttr = {0};
// 	int32_t* pUsbAddr[2] = {0};
// 	int32_t usbTmpBuff[192] = {0};
// 	int32_t tmpValue;
// 	int16_t ii;

// 	switch (g_pstConfig->FuncCfg.DongleAudioInSel) {
// 	case DONGLE_ADC_IN: {
// 		// Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttrOut,sizeof(stUSB_Audio_Attr));
// 		Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioAttr, sizeof(stUSB_Audio_Attr));
// 		Usb_Get_USB_Buff(0, USB_CALLBACK_AUDIO_IN, pUsbAddr, g_pstConfig->FuncCfg.DongleUsbInChannel, sizeof(int32_t*));
// 		//loop back need (stAudioAttr.u8SamPointNum =stAudioAttrOut.u8SamPointNum)

// 		if ((USB_ADC_FS != 1) && (USB_ADC_FS != 4) && (USB_ADC_FS != 7) ) //Don't support  11.025k/22.05k/44.1k
// 		{
// 			if (stAudioAttrOut.u32SamFreq == stAudioAttr.u32SamFreq)
// 			{
// 				stAudioAttr.u8SamPointNum = stAudioAttrOut.u8SamPointNum;
// 			}
// 		}

// 		g_u8SamPointNum = stAudioAttr.u8SamPointNum;
// 		//asrc_adc_top(usb_data,stAudioAttr.u8SamPointNum);  // the function to main while()

// 		g_u8DongleUsbRdFlag = 1;
// 		if ((g_u8DongleUsbRdFlag != 1) || (g_u8DongleAdcWrtFlag != 1))
// 		{
// 			for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++)
// 			{
// 				pUsbAddr[0][ii] = 0;
// 				if (2 == g_pstConfig->FuncCfg.DongleUsbInChannel) {
// 					pUsbAddr[1][ii] = 0;
// 				}
// 			}
// 			return ;
// 		}
// 		else
// 		{
// 			for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++)
// 			{
// 				pUsbAddr[0][ii] = usb_data[ii];
// 				if (2 == g_pstConfig->FuncCfg.DongleUsbInChannel) {
// 					pUsbAddr[1][ii] = usb_data[ii];
// 				}
// 			}
// 		}

// 		//USB_ADC_EOF_FLAG = 1; // after the adc_ringbuf_rp updated in ASRC
// 		Gen_SWI();
// 		break;
// 	}
// 	case DONGLE_I2S_MASTER_IN: {
// 		Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioAttr, sizeof(stUSB_Audio_Attr));
// 		Usb_Get_USB_Buff(0, USB_CALLBACK_AUDIO_IN, pUsbAddr, g_pstConfig->FuncCfg.DongleUsbInChannel, sizeof(int32_t*));

// 		i2s_nco_readbuf(pUsbAddr[0], usbTmpBuff, stAudioAttr.u8SamPointNum);		//nco test
// 		if (1 == g_pstConfig->FuncCfg.DongleUsbInChannel) {
// 			for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++) {
// 				pUsbAddr[0][ii] += usbTmpBuff[ii];
// 				pUsbAddr[0][ii] >>= 1;
// 			}
// 		} else {
// 			if (1 == g_pstConfig->FuncCfg.DongleUsbInCfg) {
// 				for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++) {
// 					tmpValue = (pUsbAddr[0][ii] + usbTmpBuff[ii]) >> 1;
// 					pUsbAddr[0][ii] = tmpValue;
// 					pUsbAddr[1][ii] = tmpValue;
// 				}
// 			} else {
// 				for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++) {
// 					pUsbAddr[1][ii] = usbTmpBuff[ii];
// 				}
// 			}
// 		}
// 		usb_dongle_int_cnt++;	//
// 		break;
// 	}
// 	case DONGLE_I2S_SLAVE_IN: {
// 		// Usb_Get_USB_Attr(0,USB_CALLBACK_AUDIO_OUT,&stAudioAttrOut,sizeof(stUSB_Audio_Attr));
// 		Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioAttr, sizeof(stUSB_Audio_Attr));
// 		Usb_Get_USB_Buff(0, USB_CALLBACK_AUDIO_IN, pUsbAddr, g_pstConfig->FuncCfg.DongleUsbInChannel, sizeof(int32_t*));
// 		//loop back need (stAudioAttr.u8SamPointNum =stAudioAttrOut.u8SamPointNum)

// 		if ((USB_ADC_FS != 1) && (USB_ADC_FS != 4) && (USB_ADC_FS != 7) ) //Don't support  11.025k/22.05k/44.1k
// 		{
// 			if (stAudioAttrOut.u32SamFreq == stAudioAttr.u32SamFreq)
// 			{
// 				stAudioAttr.u8SamPointNum = stAudioAttrOut.u8SamPointNum;
// 			}
// 		}

// 		g_u8SamPointNum = stAudioAttr.u8SamPointNum;
// 		//asrc_adc_top(usb_data,stAudioAttr.u8SamPointNum);  // the function to main while()

// 		g_u8DongleUsbRdFlag = 1;
// 		if ((g_u8DongleUsbRdFlag != 1) || (g_u8DongleI2sWrtFlag != 1))
// 		{
// 			for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++)
// 			{
// 				pUsbAddr[0][ii] = 0;
// 				if (2 == g_pstConfig->FuncCfg.DongleUsbInChannel) {
// 					pUsbAddr[1][ii] = 0;
// 				}
// 			}
// 			return ;
// 		}
// 		else
// 		{
// 			for (ii = 0; ii < stAudioAttr.u8SamPointNum; ii++)
// 			{
// 				pUsbAddr[0][ii] = usb_data[ii];
// 				if (2 == g_pstConfig->FuncCfg.DongleUsbInChannel) {
// 					pUsbAddr[1][ii] = usb_data[ii];
// 				}
// 			}
// 		}

// 		//USB_ADC_EOF_FLAG = 1; // after the adc_ringbuf_rp updated in ASRC
// 		Gen_SWI();
// 		break;
// 	}
// 	}
// }


extern void patch_USB_InterfaceSetting_adc_dac(void);
extern void patch_USB_InterfaceSetting_I2S(void);
extern uint32_t patch_USB_Buf_Init(uint32_t uInBaseAddr);

const usb_sdk_ftable_t new_usb_sdk_patch_ftable =
{
	.AudioOutSpeaker 	= new_patch_Audio_Out_Speaker,
	.USBOutSpeaker      = new_patch_USB_Out_Speaker,
	.AudioInSpeaker     = new_patch_Audio_In_Speaker,
	.USBInSpeaker       = new_patch_USB_In_Speaker,
	.OutTestRead        = NULL,
	.InTestWrite        = NULL,
	.InDongleWrite      = NULL,
	.InDongleRead       = NULL,
	// .OutTestRead        = patch_Audio_Out_Test_Read,
	// .InTestWrite        = patch_Audio_In_Test_Write,
	// .InDongleWrite      = new_patch_Audio_In_Dongle_Write,
	// .InDongleRead       = new_patch_USB_In_Dongle_Read,
	.InterfaceAdcDac 	= patch_USB_InterfaceSetting_adc_dac,
	.InterfaceI2S       = patch_USB_InterfaceSetting_I2S,
	.BufInit          	= patch_USB_Buf_Init,
};

void new_usb_sdk_patch_init(void)
{
	pusb_sdk_ftabl = (usb_sdk_ftable_t *)&new_usb_sdk_patch_ftable;
}
