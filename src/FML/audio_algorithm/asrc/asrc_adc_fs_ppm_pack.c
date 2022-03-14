

#include "com_includes.h"
#include "asrc_adc_fs_ppm_pack.h"
#include "asrc_codec_filter.h"
#include "nds32_filtering_math.h"
#include "gpio_ctrl.h"

#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
AsrcIn_t g_st_AsrcI2SIN = {
	.En = 1,
};

uint32_t Pack_Asrc_In_Init(AsrcIn_t *pAsrcStru, uint32_t uInBaseAddr, uint32_t stereo_mode, uint32_t MaxPpm, int32_t usb_in_fs)
{
	if(pAsrcStru->En == 0 || pAsrcStru == NULL)
	{
		return uInBaseAddr;
	}
	pAsrcStru->ADC_STEREO_MODE = stereo_mode;
	pAsrcStru->USB_ADC_FS_D =  -1;
	pAsrcStru->start_adc_coarse_ppm = 0;

	pAsrcStru->RingBufLen   = 384*6;
	pAsrcStru->XinBufLenMax = 96 + 96/2 + 26;
	pAsrcStru->AdcInLen = ASRC_ADC_IBUF_LEN_patch;

    uInBaseAddr = ((uInBaseAddr + 3) & 0xFFFFFFFC); //int32_t aligN
    pAsrcStru->pRingBufLeft = (int32_t *)(uInBaseAddr);
   	uInBaseAddr += pAsrcStru->RingBufLen   * sizeof(int32_t);
   	pAsrcStru->pXinBufLeft  = (int32_t *)(uInBaseAddr);
   	uInBaseAddr += pAsrcStru->XinBufLenMax * sizeof(int32_t);  //allocate max buffer for 96k

   	if(pAsrcStru->ADC_STEREO_MODE == 1)
   	{
   		pAsrcStru->pRingBufRight = (int32_t *)(uInBaseAddr);
	   	uInBaseAddr += pAsrcStru->RingBufLen   * sizeof(int32_t);
	   	pAsrcStru->pXinBufRight  = (int32_t *)(uInBaseAddr);
	   	uInBaseAddr += pAsrcStru->XinBufLenMax * sizeof(int32_t);  //allocate max buffer for 96k
   	}
   	pAsrcStru->ADC_MAX_PPM = ((MaxPpm * 10000) << 10); //ppm in Q10
   	pAsrcStru->usb_read_firstxx_packet_thrsh = 8;
   	pAsrcStru->ADC_LOCAL_MIN_WINDOW = 18;
   	pAsrcStru->ASRC_ADC_PFORMANCE = 2; //0,2,3 performance

	Pack_Asrc_In_Relock(pAsrcStru);
	Pack_Asrc_In_FsSwitch(pAsrcStru, usb_in_fs);
   	return uInBaseAddr;
}

void Pack_Asrc_In_Relock(AsrcIn_t *pAsrcStru)
{
	if(pAsrcStru->En == 0 || pAsrcStru == NULL)
	{
		return;
	}
	//coarse ppm
	pAsrcStru->adc_coarse_state   = 0;
	pAsrcStru->adc_coarse_locked  = 0;
	pAsrcStru->adc_remain_num0    = 0;
	pAsrcStru->adc_coarse_ppm     = 0;
	pAsrcStru->adc_coarse_cnt     = 0;

    //fine ppm
	pAsrcStru->adc_cnt_for_narrow   = 0;
	pAsrcStru->adc_dpll_err_d1      = 0;
	pAsrcStru->adc_fine_ppm         = 0;
	pAsrcStru->adc_narrow_state     = 0;
	pAsrcStru->adc_loopflt_out      = 0;
}

void Pack_Asrc_In_FsSwitch(AsrcIn_t *pAsrcStru, uint32_t usb_in_fs)  //re-initialize the state;
{
	// asrc_adc_lpf_init(usb_in_fs);  //for decimation LPF
	uint32_t fs_sel = usb_in_fs;
	if(fs_sel > 6)
  	{
  		fs_sel = 6;
  	}
  	pAsrcStru->pDecFiltCoeff = (int32_t *)&ADC_LPF_COEFF_ARRAY[fs_sel*5+0][0];
  	nds32_set_q31(0, pAsrcStru->DecFiltStateLeft,  4*5);
  	nds32_set_q31(0, pAsrcStru->DecFiltStateRight, 4*5);

	if(usb_in_fs <=8)
	{
		apb_adc_filt_config_0_cic1_en_2_setf(0);
		apb_adc_filt_config_0_sync_bit_setf(1);
	}
	else
	{
		apb_adc_filt_config_0_cic1_en_2_setf(1);
		apb_adc_filt_config_0_sync_bit_setf(1);
	}
	switch(usb_in_fs)
	{
		case 0:   // usb audio out freq
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  98304000;
			pAsrcStru->adc_coarse_ppm_scale  = 1953;
			pAsrcStru->ADC_DOWN_N = 4;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>2;
			pAsrcStru->XinBufLen = (12+12/2);
			pAsrcStru->REMAIN_NUM_TARGET = 138*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 4;
		}break; //8k
		case 1:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  71331701 ;
			pAsrcStru->adc_coarse_ppm_scale  = 1417;
			pAsrcStru->ADC_DOWN_N = 4;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>2;
			pAsrcStru->XinBufLen = (12+12/2);
			pAsrcStru->REMAIN_NUM_TARGET = 143*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 4;
		}break; //11.025k
		case 2:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  65536000 ;
			pAsrcStru->adc_coarse_ppm_scale  = 1302;
			pAsrcStru->ADC_DOWN_N = 4;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>2;
			pAsrcStru->XinBufLen = (12+12/2);
			pAsrcStru->REMAIN_NUM_TARGET = 144*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 4;
		}break; //12k
		case 3:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  98304000 ;
			pAsrcStru->adc_coarse_ppm_scale = 977;
			pAsrcStru->ADC_DOWN_N = 2;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>1;
			pAsrcStru->XinBufLen = (24+24/2);
			pAsrcStru->REMAIN_NUM_TARGET = 150*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 2;
		}break; //16k
		case 4:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  71331701 ;
			pAsrcStru->adc_coarse_ppm_scale = 709;
			pAsrcStru->ADC_DOWN_N = 2;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>1;
			pAsrcStru->XinBufLen = (24+24/2);
			pAsrcStru->REMAIN_NUM_TARGET = 159*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 2;
		}break; //22.05k
		case 5:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  65536000;
			pAsrcStru->adc_coarse_ppm_scale = 651;
			pAsrcStru->ADC_DOWN_N = 2;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen>>1;
			pAsrcStru->XinBufLen = (24+24/2);
			pAsrcStru->REMAIN_NUM_TARGET = 162*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 2;
		}break; //24k
		case 6:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  98304000;
			pAsrcStru->adc_coarse_ppm_scale = 488;
			pAsrcStru->ADC_DOWN_N = 1;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen;
			pAsrcStru->XinBufLen = (48+48);
			pAsrcStru->REMAIN_NUM_TARGET = 174*2;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 1;
		}break; //32k
		case 7:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =   73043661;   //(48/44.1)*2^26
			pAsrcStru->adc_coarse_ppm_scale = 354;
			pAsrcStru->ADC_DOWN_N = 1;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen;
			pAsrcStru->XinBufLen = (48+48/2);
			pAsrcStru->REMAIN_NUM_TARGET = 192*2;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 1;
		}break; //44.1k
		case 8:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  67108864;
			pAsrcStru->adc_coarse_ppm_scale = 325;
			pAsrcStru->ADC_DOWN_N = 1;
			pAsrcStru->adc_decimated_len = pAsrcStru->AdcInLen;
			pAsrcStru->XinBufLen = (48+48/2);
			pAsrcStru->REMAIN_NUM_TARGET = 198*2 ;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 48/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 1;
		}break; //48k
		default:
		{
			pAsrcStru->ADC_FS_RATIO_Q26 =  67108864;
			pAsrcStru->adc_coarse_ppm_scale = 162;
			pAsrcStru->ADC_DOWN_N = 1;
			pAsrcStru->adc_decimated_len  = pAsrcStru->AdcInLen;
			pAsrcStru->XinBufLen = (96+96/2);
			pAsrcStru->REMAIN_NUM_TARGET = pAsrcStru->AdcInLen/2+96;
			pAsrcStru->usb_audio_in_off_cnt_thrsh = 96/pAsrcStru->AdcInLen + 2;
			pAsrcStru->adc_loop_out_scale = 1;
		}break; //96k
	}// end switch
	pAsrcStru->REMAIN_NUM_TARGET = pAsrcStru->RingBufLen/2;
	uint32_t detaLen[4] = {5, 13, 19, 26};
	pAsrcStru->XinBufLen              += detaLen[pAsrcStru->ASRC_ADC_PFORMANCE];
	// pAsrcStru->usb_read_firstxx_packet = 0;
	pAsrcStru->RingBufRightWp          = pAsrcStru->REMAIN_NUM_TARGET;
	pAsrcStru->RingBufRightRp          = 0;
	pAsrcStru->RingBufLeftWp           = pAsrcStru->REMAIN_NUM_TARGET;
	pAsrcStru->RingBufLeftRp           = 0;
	
	pAsrcStru->left_nco     		= 0;
	pAsrcStru->left_nco_buf			= 0;
	pAsrcStru->right_nco     		= 0;
	pAsrcStru->right_nco_buf		= 0;

	pAsrcStru->remain_min_search_cnt   = 0;
	pAsrcStru->adc_remain_num_min      = pAsrcStru->REMAIN_NUM_TARGET;
	pAsrcStru->adc_remain_min_search   = 8888;
}

void Pack_Asrc_In_CoarsePpm(AsrcIn_t *pAsrcStru, uint32_t USB_IN_FS)
{
	//(0) update adc_ppm_scale in asrc_adc_fs_change_init();
	if(pAsrcStru->start_adc_coarse_ppm)
	{

		pAsrcStru->start_adc_coarse_ppm = 0;
		pAsrcStru->restart_asrc_in = 0;
		pAsrcStru->USB_ADC_FS_D = USB_IN_FS;
		Pack_Asrc_In_FsSwitch(pAsrcStru, USB_IN_FS);
		Pack_Asrc_In_Relock(pAsrcStru);
	}
	else if(pAsrcStru->restart_asrc_in || (USB_IN_FS != pAsrcStru->USB_ADC_FS_D) )
	{
		pAsrcStru->restart_asrc_in = 0;
		pAsrcStru->USB_ADC_FS_D = USB_IN_FS;
		Pack_Asrc_In_FsSwitch(pAsrcStru, USB_IN_FS);
	}
	//(2) FSM
	switch(pAsrcStru->adc_coarse_state)
	{
		case 0:
		{
			nds32_set_q31(0, pAsrcStru->pRingBufLeft, pAsrcStru->RingBufLen);

			if(pAsrcStru->ADC_STEREO_MODE)
			{
				nds32_set_q31(0, pAsrcStru->pRingBufLeft, pAsrcStru->RingBufLen);
			}
	       	pAsrcStru->adc_coarse_cnt = 0;
	       	pAsrcStru->adc_coarse_ppm = 0;
	       	pAsrcStru->adc_coarse_locked = 0;
	       	pAsrcStru->adc_remain_num0 = pAsrcStru->adc_remain_num;//record the remain_num_min0 in step0
	       	// pAsrcStru->adc_coarse_state += 1;
	       	pAsrcStru->adc_coarse_state += 2; //coarse偏差太大， 不做coarse

		}break;

		case 1:
		{
			int32_t adc_remain_delta0 = pAsrcStru->adc_remain_num - pAsrcStru->adc_remain_num0;
			pAsrcStru->adc_coarse_ppm = 0;

			//wait until remain_num changed delta >= 64 or about 0.1 seconds (for small ppm )
			if(adc_remain_delta0 >= 64 || adc_remain_delta0 <= -64 || pAsrcStru->adc_coarse_cnt >= 100)
			{
				pAsrcStru->adc_coarse_state ++;
				if(pAsrcStru->adc_coarse_cnt != 0)     //
				{
					pAsrcStru->adc_coarse_ppm = (int32_t) (((int64_t)pAsrcStru->adc_coarse_ppm_scale*1048576)/pAsrcStru->adc_coarse_cnt); // coarse ppm in 32Q10 format
					pAsrcStru->adc_coarse_ppm = (pAsrcStru->adc_coarse_ppm * adc_remain_delta0)>>4; //
					pAsrcStru->adc_coarse_locked = 0;
					if(pAsrcStru->adc_coarse_ppm > pAsrcStru->ADC_MAX_PPM)
					{
						pAsrcStru->adc_coarse_ppm = pAsrcStru->ADC_MAX_PPM;
					}
					else if(pAsrcStru->adc_coarse_ppm < -pAsrcStru->ADC_MAX_PPM)
					{
						pAsrcStru->adc_coarse_ppm = -pAsrcStru->ADC_MAX_PPM;
					}
				}
			}
			else
			{
				pAsrcStru->adc_coarse_cnt ++;
			}
		}break;
		case 2:    // unlock detection
		{
			pAsrcStru->adc_coarse_locked = 1;
			uint8_t adc_coarse_unlock = (pAsrcStru->adc_remain_num < 48) || (pAsrcStru->adc_remain_num > pAsrcStru->RingBufLen-48);
			if(adc_coarse_unlock)
			{
				pAsrcStru->adc_coarse_state = 0;
				pAsrcStru->adc_coarse_locked = 0;
				pAsrcStru->start_adc_coarse_ppm  = 1;
			}
		}break;
	}//end switch
}

void Pack_Asrc_In_FinePpm(AsrcIn_t *pAsrcStru)
{
	//(1) search locak min value
	if(pAsrcStru->remain_min_search_cnt < pAsrcStru->ADC_LOCAL_MIN_WINDOW)
	{
		pAsrcStru->remain_min_search_cnt ++;
		if(pAsrcStru->adc_remain_min_search > pAsrcStru->adc_remain_num)
		{
			pAsrcStru->adc_remain_min_search = pAsrcStru->adc_remain_num;
		}
	}
	else
	{
		pAsrcStru->remain_min_search_cnt = 0;
		pAsrcStru->adc_remain_num_min = pAsrcStru->adc_remain_min_search;
		pAsrcStru->adc_remain_min_search = 8888;
	}
	 
    int32_t adc_dpll_err,  adc_delta_u;
    int32_t adc_Ka ;
	int32_t adc_Kb ;
	int32_t ADC_MAX_PIDSTEP;
	if(pAsrcStru->adc_narrow_state <1)
	{ 
		adc_Ka = 40160;  
		adc_Kb = 40000;    
		ADC_MAX_PIDSTEP = 1000<<10; 
	}
	else if(pAsrcStru->adc_narrow_state<2)
	{
		adc_Ka = 8080;//40160/8;
		adc_Kb = 8000;//40000/8;
		ADC_MAX_PIDSTEP = 500<<10;
	}
	else
	{
		adc_Ka = 8080;  
		adc_Kb = 8000;   
		ADC_MAX_PIDSTEP = 20<<10;
	}


	if( (!pAsrcStru->adc_coarse_locked) )
	{
		pAsrcStru->adc_narrow_state    = 0;
		pAsrcStru->adc_cnt_for_narrow  = 0;
		pAsrcStru->adc_loopflt_out     = 0;
		pAsrcStru->adc_fine_ppm        = pAsrcStru->adc_coarse_ppm;
		pAsrcStru->adc_coarse_ppm_hold = pAsrcStru->adc_coarse_ppm;
		pAsrcStru->adc_dpll_err_d1     = 0;
		// pAsrcStru->adc_loop_cnt        = 0;
	}
	else
	{
		if(pAsrcStru->adc_cnt_for_narrow < 3000)
		{
			pAsrcStru->adc_narrow_state = 0;
			pAsrcStru->adc_cnt_for_narrow += 1;
		}
		else if(pAsrcStru->adc_cnt_for_narrow < 6000)
		{
			pAsrcStru->adc_narrow_state = 1;
			pAsrcStru->adc_cnt_for_narrow += 1;
		}
		else
		{
			pAsrcStru->adc_narrow_state = 2;
		}

		if(pAsrcStru->adc_narrow_state>0)
		{
		   adc_dpll_err = pAsrcStru->adc_remain_num_min - pAsrcStru->REMAIN_NUM_TARGET;
		}
		else
		{
		   adc_dpll_err = pAsrcStru->adc_remain_num - pAsrcStru->REMAIN_NUM_TARGET;
		}

		adc_delta_u   = adc_Ka*adc_dpll_err - adc_Kb * pAsrcStru->adc_dpll_err_d1;     //PI control

		if(adc_delta_u > ADC_MAX_PIDSTEP)
		{
			pAsrcStru->adc_loopflt_out += ADC_MAX_PIDSTEP;
		}
		else if(adc_delta_u < - ADC_MAX_PIDSTEP)
		{
			pAsrcStru->adc_loopflt_out -= ADC_MAX_PIDSTEP;
		}
		else
		{
			pAsrcStru->adc_loopflt_out += adc_delta_u;
		}

		if( pAsrcStru->adc_loopflt_out > pAsrcStru->ADC_MAX_PPM  )  // ppm in Q10,
		{
			pAsrcStru->adc_loopflt_out = pAsrcStru->ADC_MAX_PPM;
		}
		else if(pAsrcStru->adc_loopflt_out < -pAsrcStru->ADC_MAX_PPM )
		{
			pAsrcStru->adc_loopflt_out =  -pAsrcStru->ADC_MAX_PPM;
		}

		pAsrcStru->adc_fine_ppm = pAsrcStru->adc_coarse_ppm_hold + (pAsrcStru->adc_loopflt_out*pAsrcStru->adc_loop_out_scale); //fine ppm in Q10
		pAsrcStru->adc_dpll_err_d1 = adc_dpll_err;
	}
}

void Pack_asrc_In_Writebuf(AsrcIn_t *pAsrcStru, int32_t *pDataL, int32_t *pDataR, uint32_t USB_IN_FS)               //sfix32_en23, from ADC
{

	if(pAsrcStru->En == 0 || pAsrcStru == NULL)
	{
		return;
	}
    int16_t  ii;

	// USB_DAC_EOF_FLAG == 0 continuous 7 times, hold the ADC input ringbuffer
    if( pAsrcStru->USB_ADC_EOF_FLAG )
    {
     	pAsrcStru->usb_audio_in_off_cnt = 0;
     	if(pAsrcStru->usb_read_firstxx_packet<888)
     	{
     		pAsrcStru->usb_read_firstxx_packet++;
     	}

        pAsrcStru->USB_ADC_EOF_FLAG = 0;
    }
    else
    {
      	if(pAsrcStru->usb_audio_in_off_cnt < pAsrcStru->usb_audio_in_off_cnt_thrsh + 3) //
      	{
     		pAsrcStru->usb_audio_in_off_cnt ++ ;

      	}
    }
	// when no USB reading buff last for >7 ADC interrupt
	if(pAsrcStru->usb_audio_in_off_cnt >=  pAsrcStru->usb_audio_in_off_cnt_thrsh)
	{
		pAsrcStru->usb_read_firstxx_packet = 0;
		// pAsrcStru->restart_asrc_in = 1;
		pAsrcStru->start_adc_coarse_ppm  = 1; //重新锁定ppm, 防止频繁开关usb in导致unlock。

	}
  	if(pAsrcStru->usb_read_firstxx_packet >  pAsrcStru->usb_read_firstxx_packet_thrsh/8) //
  	{
	    //(0) do fs initialize when fs changed, decimation LPF init, ppm_scale init...
	    //(1) do LPF for decimation
	    nds32_bq_df1_q31_t inst = {
	    	.nstage = 5,
            .state  = pAsrcStru->DecFiltStateLeft,
            .coeff  = pAsrcStru->pDecFiltCoeff,
			.shift  = 3,
	    };
		if(pAsrcStru->USB_ADC_FS_D <= 6)           //when f < 44.1khz, add lpf 
		{
			nds32_bq_df1_q31(&inst, pDataL, pDataL, pAsrcStru->AdcInLen);
			if(pAsrcStru->ADC_STEREO_MODE)
			{
				inst.state = pAsrcStru->DecFiltStateRight;
				nds32_bq_df1_q31(&inst, pDataR, pDataR, pAsrcStru->AdcInLen);
			}
		}

    	//(2) decimation and write ADC data to ringbuf,  and sync with USB start input
    	int32_t *pRingBufLeftTmp    = pAsrcStru->pRingBufLeft;
    	int32_t *pRingBufRightTmp   = pAsrcStru->pRingBufRight;
    	uint32_t RingBufLeftWpTmp   = pAsrcStru->RingBufLeftWp;
		uint32_t RingBufRightWpTmp  = pAsrcStru->RingBufRightWp;

		uint8_t  DownN = pAsrcStru->ADC_DOWN_N;

		//Left channel
		for(ii=0; ii<pAsrcStru->adc_decimated_len; ii++)
		{
			pRingBufLeftTmp[RingBufLeftWpTmp++] = pDataL[ii* DownN];
			if(RingBufLeftWpTmp >= pAsrcStru->RingBufLen)
			{
				RingBufLeftWpTmp = 0;
			}
		}
		//Right channel
		if(pAsrcStru->ADC_STEREO_MODE)
		{
			for(ii=0; ii<pAsrcStru->adc_decimated_len; ii++)
			{
				pRingBufRightTmp[RingBufRightWpTmp++] = pDataR[ii* DownN];
				if(RingBufRightWpTmp >= pAsrcStru->RingBufLen)
				{
					RingBufRightWpTmp = 0;
				}
			}
		}
		pAsrcStru->RingBufLeftWp  = RingBufLeftWpTmp;
		pAsrcStru->RingBufRightWp = RingBufRightWpTmp;

		//(3) caculate remain_num && update ppm
		if(pAsrcStru->RingBufLeftWp < pAsrcStru->RingBufLeftRp)
		{
			pAsrcStru->adc_remain_num = pAsrcStru->RingBufLen + pAsrcStru->RingBufLeftWp - pAsrcStru->RingBufLeftRp;
		}
		else
		{
			pAsrcStru->adc_remain_num = pAsrcStru->RingBufLeftWp - pAsrcStru->RingBufLeftRp;
		}		
		Pack_Asrc_In_CoarsePpm(pAsrcStru, USB_IN_FS); //search the local remain_num min
		Pack_Asrc_In_FinePpm (pAsrcStru);  //get adc_fine_ppm
		pAsrcStru->adc_fs_ratio = pAsrcStru->ADC_FS_RATIO_Q26 + (pAsrcStru->adc_fine_ppm>>4); // ppm in Q10
	}
	else
	{
		nds32_set_q31(0, pAsrcStru->pRingBufLeft, pAsrcStru->RingBufLen);
		if(pAsrcStru->ADC_STEREO_MODE)
		{
			nds32_set_q31(0, pAsrcStru->pRingBufRight, pAsrcStru->RingBufLen);
		}
	}
}

void Pack_asrc_In_Top(AsrcIn_t *pAsrcStru, int32_t *pDataL, int32_t *pDataR, int32_t USB_IN_PCM_NUM)
{

	if(pAsrcStru->En == 0 || pAsrcStru == NULL)
	{
		return;
	}
	//(0) read from ringbuf and do ASRC, all situation:
	// [fs<=48] or [fs =96], [performance level 0/1/2/3]
	pAsrcStru->USB_ADC_PCM_NUM  = USB_IN_PCM_NUM;
	pAsrcStru->USB_ADC_EOF_FLAG = 1; // after the adc_ringbuf_rp updated in ASRC
	if(pAsrcStru->usb_read_firstxx_packet > (pAsrcStru->usb_read_firstxx_packet_thrsh/8))  //set USB_ADC_ASRC_ENABLE in audio_out.c, adc_start, adc_stop
	{
		if(pAsrcStru->USB_ADC_FS_D <= 8 ) // Fs <= 48k
		{
			asrc_codec48k_readbuf(
				pAsrcStru->pRingBufLeft     , //data format 32Q23, 24bits Audio
				pAsrcStru->pRingBufRight    , //data format 32Q23, 24bits Audio
				pAsrcStru->pXinBufLeft      , //data format 32Q19 for asrc filter
				pAsrcStru->pXinBufRight     , //data format 32Q19 for asrc filter
				pAsrcStru->RingBufLen       ,
				pAsrcStru->XinBufLen        , //xin buffer length, according to asrc performance level
				&pAsrcStru->left_nco_buf    ,
				&pAsrcStru->right_nco_buf   ,
				&pAsrcStru->RingBufLeftRp   ,
				&pAsrcStru->RingBufRightRp  ,
				pAsrcStru->ADC_STEREO_MODE );
			if(pAsrcStru->ASRC_ADC_PFORMANCE == 0)
			{
				asrc_codec_pfzero(
					pAsrcStru->pXinBufLeft      , //data format 32Q19 for asrc filter
					pDataL                      , // outbuffer,  data format 32Q23
					USB_IN_PCM_NUM              ,
					&pAsrcStru->left_nco        ,
					&pAsrcStru->left_nco_buf    ,
					pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
			else if(pAsrcStru->ASRC_ADC_PFORMANCE <= 2)  //1,2
			{
				asrc_codec_pfmid(
					pAsrcStru->pXinBufLeft      , //data format 32Q19 for asrc filter
					pDataL                      , // outbuffer,  data format 32Q23
					USB_IN_PCM_NUM              ,
					&pAsrcStru->left_nco        ,
					&pAsrcStru->left_nco_buf    ,
					pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}

			else
			{
				asrc_codec_pfhigh(
					pAsrcStru->pXinBufLeft      , //data format 32Q19 for asrc filter
					pDataL                      , // outbuffer,  data format 32Q23
					USB_IN_PCM_NUM              ,
					&pAsrcStru->left_nco        ,
					&pAsrcStru->left_nco_buf    ,
					pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
			if(pAsrcStru->ADC_STEREO_MODE)
			{
				if(pAsrcStru->ASRC_ADC_PFORMANCE == 0)
				{
					asrc_codec_pfzero(
						pAsrcStru->pXinBufRight     , //data format 32Q19 for asrc filter
						pDataR                      , // outbuffer,  data format 32Q23
						USB_IN_PCM_NUM              ,
						&pAsrcStru->right_nco       ,
						&pAsrcStru->right_nco_buf   ,
						pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
				}
				else if(pAsrcStru->ASRC_ADC_PFORMANCE <= 2)  //1,2
				{
					asrc_codec_pfmid(
						pAsrcStru->pXinBufRight     , //data format 32Q19 for asrc filter
						pDataR                      , // outbuffer,  data format 32Q23
						USB_IN_PCM_NUM              ,
						&pAsrcStru->right_nco       ,
						&pAsrcStru->right_nco_buf   ,
						pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
				}

				else
				{
					asrc_codec_pfhigh(
						pAsrcStru->pXinBufRight     , //data format 32Q19 for asrc filter
						pDataR                      , // outbuffer,  data format 32Q23
						USB_IN_PCM_NUM              ,
						&pAsrcStru->right_nco       ,
						&pAsrcStru->right_nco_buf   ,
						pAsrcStru->adc_fs_ratio     ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
				}
			}
		}
		else    // Fs == 96k
		{
			int32_t bitcut_en =  (pAsrcStru->ASRC_ADC_PFORMANCE <= 2); //0,1:pflow, 2:pfmid, 3:pfhigh
			asrc_codec96k_readbuf(
				pAsrcStru->pRingBufLeft   , //32Q23, 24bits audio
				pAsrcStru->pRingBufRight  , //32Q23, 24bits audio
				pAsrcStru->pXinBufLeft    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
				pAsrcStru->pXinBufRight   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
				pAsrcStru->RingBufLen     ,
				pAsrcStru->XinBufLen      , //xinbuffer length
				&pAsrcStru->left_nco_buf  ,
				&pAsrcStru->right_nco_buf ,
				&pAsrcStru->RingBufLeftRp ,
				&pAsrcStru->RingBufRightRp,
				bitcut_en                 ,  // bitcut = 0 :high performance, 1: mid or low performance
				pAsrcStru->ADC_STEREO_MODE);
			if(pAsrcStru->ASRC_ADC_PFORMANCE <= 2) //2:pflow
			{
				asrc_codec96k_pfmid(
					pAsrcStru->pRingBufLeft   ,  //  data format 32Q20 !!!
					pDataL                    ,  //  data format 32Q23, 24bits Audio
					USB_IN_PCM_NUM            ,
					&pAsrcStru->left_nco      ,
					&pAsrcStru->left_nco_buf  ,
					pAsrcStru->adc_fs_ratio   ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
			else                               //3:pfhigh
			{
				asrc_codec96k_pfhigh(             // high performance
					pAsrcStru->pRingBufLeft   ,  //  data format 32Q20 !!!
					pDataL                    ,  //  data format 32Q23, 24bits Audio
					USB_IN_PCM_NUM            ,
					&pAsrcStru->left_nco      ,
					&pAsrcStru->left_nco_buf  ,
					pAsrcStru->adc_fs_ratio   ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
			if(pAsrcStru->ADC_STEREO_MODE)
			{
				if(pAsrcStru->ASRC_ADC_PFORMANCE <= 2) //2:pflow
				{
					asrc_codec96k_pfmid(
						pAsrcStru->pRingBufRight  ,  //  data format 32Q20 !!!
						pDataR                    ,  //  data format 32Q23, 24bits Audio
						USB_IN_PCM_NUM            ,
						&pAsrcStru->right_nco     ,
						&pAsrcStru->right_nco_buf ,
						pAsrcStru->adc_fs_ratio   ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
				}
				else                               //3:pfhigh
				{
					asrc_codec96k_pfhigh(             // high performance
						pAsrcStru->pRingBufRight  ,  //  data format 32Q20 !!!
						pDataR                    ,  //  data format 32Q23, 24bits Audio
						USB_IN_PCM_NUM            ,
						&pAsrcStru->right_nco     ,
						&pAsrcStru->right_nco_buf ,
						pAsrcStru->adc_fs_ratio   ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
				}
			}
		}
		uint32_t ii;
		for(ii=0;ii<USB_IN_PCM_NUM;ii++)
		{
			pDataL[ii] = __nds32__clips(pDataL[ii],23);
		}
		if(pAsrcStru->ADC_STEREO_MODE)
		{
			for(ii=0;ii<USB_IN_PCM_NUM;ii++)
			{
				pDataR[ii] = __nds32__clips(pDataR[ii],23);
			}
		}

	}
	else
	{
		nds32_set_q31(0, pDataL, USB_IN_PCM_NUM);
		if(pAsrcStru->ADC_STEREO_MODE)
		{
			nds32_set_q31(0, pDataR, USB_IN_PCM_NUM);
		}
	}
}

#endif /* (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2) */
