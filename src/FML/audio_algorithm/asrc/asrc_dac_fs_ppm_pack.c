/*
 * asrc_dac_fs_ppm.c
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 */

#include "asrc_dac_fs_ppm_pack.h"
#include "asrc_codec_filter_fast.h"
#include "reg_apb.h"
//#include "gpio_ctrl.h"

AsrcOut_t g_st_AsrcI2S = {
		.En = 1,
};

uint32_t Pack_Asrc_Out_Init(AsrcOut_t *pAsrcStru, uint32_t uInBaseAddr, uint32_t MaxPpm,  uint32_t STEREO_MODE)
{
	if(pAsrcStru->En == 0)
	{
		return uInBaseAddr;
	}
	pAsrcStru->USB_DAC_FS_D = -1;
	pAsrcStru->start_coarse_ppm = 1;
	pAsrcStru->DAC_STEREO_MODE = STEREO_MODE;
//	Audio_DAC_PowerOff_CNT = 0; ??????

	pAsrcStru->ringbuf_len = 512*2;
	pAsrcStru->xinbuf_len_max = ASRC_XINBUF_LEN_patch;
    uInBaseAddr = ((uInBaseAddr + 3) & 0xFFFFFFFC); //int32_t align

    pAsrcStru->ringbuf_left = (int32_t *)(uInBaseAddr);
    uInBaseAddr += pAsrcStru->ringbuf_len * sizeof(int32_t);

    pAsrcStru->ringbuf_right = (int32_t *)(uInBaseAddr);
    uInBaseAddr += pAsrcStru->ringbuf_len * sizeof(int32_t);

    pAsrcStru->xinbuf_left = (int32_t *)(uInBaseAddr);
    uInBaseAddr += pAsrcStru->xinbuf_len_max * sizeof(int32_t);

    pAsrcStru->xinbuf_right = (int32_t *)(uInBaseAddr);
    uInBaseAddr += pAsrcStru->xinbuf_len_max * sizeof(int32_t);


//    pAsrcStru->ASRC_DAC_PFORMANCE = 0;
//    pAsrcStru->ASRC_DAC_PFORMANCE_96K = 0;
    pAsrcStru->ppm_range = MaxPpm;
    pAsrcStru->DAC_MAX_PPM  = ((pAsrcStru->ppm_range * 10000) << 10); //max ppm in Q10
    pAsrcStru->usb_write_firstxx_packet_thrsh = 12; //

    /*for 44.1k to 46.875 compen @ 20kHz */
    //272741622   451088578   230867461  -451088578  -235173627 //2dB
    //271656136   450273979   231043504  -450273979  -234264184 //1.5dB
//    pAsrcStru->compen_coeff[0] =  271656136;
//    pAsrcStru->compen_coeff[1] =  450273979;
//    pAsrcStru->compen_coeff[2] =  231043504;
//    pAsrcStru->compen_coeff[3] = -450273979;
//    pAsrcStru->compen_coeff[4] = -234264184;


    fir_poly_pffast = (int32_t (*)[])new_fir_poly_pffast;
    fir_poly_96k_pffast = (int32_t (*)[])new_fir_poly_96k_pffast;
    DAC_MAG_COEFF_ARRAY = (int32_t (*)[])new_DAC_MAG_COEFF_ARRAY;

    return uInBaseAddr;
}

void Pack_Asrc_EstimationPPM_init(AsrcOut_t *pAsrcStru, uint32_t USB_OUT_FS)
{
    int16_t ii;
    for (ii = 0; ii < 4; ii++)
    {
    	pAsrcStru->compen_left_state[ii] = 0;
    	pAsrcStru->compen_right_state[ii] = 0;
    }


//  pAsrcStru->dac_interrupt_cnt = 0;
    pAsrcStru->nco_left      = 0;
    pAsrcStru->nco_right     = 0;
    pAsrcStru->nco_buf_left  = 0;
    pAsrcStru->nco_buf_right = 0;
    pAsrcStru->usb_write_firstxx_packet       = 0;

    pAsrcStru->xinbuf_len = 12 + ASRC_OBUF_LEN_patch + (ASRC_OBUF_LEN_patch >> 1);

    //when 48kHz mode, Muses DAC FS = 12M/256 = 46.875K
    //when 96kHz mode, Muses DAC FS = 12M/128 = 93.75k
    //round(Fsin/Fsout*2^26)
#if (ASRC_OBUF_LEN_patch == 16)
    if (USB_OUT_FS <= 8)
    	pAsrcStru->usb_audio_out_off_cnt_thrsh = 6;
    else
    	pAsrcStru->usb_audio_out_off_cnt_thrsh = 12;
#else
    if (USB_OUT_FS <= 8)
    	pAsrcStru->usb_audio_out_off_cnt_thrsh = 3;
    else
    	pAsrcStru->usb_audio_out_off_cnt_thrsh = 6;

#endif
    //when 48kHz mode, Muses DAC FS = 12M/256 = 46.875K
    //when 96kHz mode, Muses DAC FS = 12M/128 = 93.75k
    //round(Fsin/Fsout*2^26)
    switch (USB_OUT_FS)
    {
    case 0:   // usb audio out freq
    {
    	pAsrcStru->DAC_FS_RATIO_Q26      = 11184811;
//    	pAsrcStru->coarse_ppm_scale      = 1313;
    	pAsrcStru->dac_loop_out_scale    = 12;
    	pAsrcStru->REMAIN_NUM_TARGET = 138 * 2;
    } break; //8k
    case 1:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26      = 15414067;
//    	pAsrcStru->coarse_ppm_scale      = 955;
    	pAsrcStru->dac_loop_out_scale    = 10;
    	pAsrcStru->REMAIN_NUM_TARGET = 143 * 2;
    } break; //11.025k
    case 2:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26      = 16777216;
//    	pAsrcStru->coarse_ppm_scale      = 876;
    	pAsrcStru->dac_loop_out_scale    = 8;
    	pAsrcStru->REMAIN_NUM_TARGET = 144 * 2;
    } break; //12k
    case 3:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26      = 22369621;
//    	pAsrcStru->coarse_ppm_scale      = 657;
    	pAsrcStru->dac_loop_out_scale    = 6;
    	pAsrcStru->REMAIN_NUM_TARGET = 150 * 2;
    } break; //16k
    case 4:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  30828134;
//    	pAsrcStru->coarse_ppm_scale = 478;
    	pAsrcStru->dac_loop_out_scale = 6;
    	pAsrcStru->REMAIN_NUM_TARGET = 159 * 2;
    } break; //22.05k
    case 5:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  33554432;
//    	pAsrcStru->coarse_ppm_scale = 438;
    	pAsrcStru->dac_loop_out_scale = 4;
    	pAsrcStru->REMAIN_NUM_TARGET = 162 * 2;
    } break; //24k
    case 6:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  44739243;
//    	pAsrcStru->coarse_ppm_scale = 328;
    	pAsrcStru->dac_loop_out_scale = 4;
    	pAsrcStru->REMAIN_NUM_TARGET = 174 * 2;
    } break; //32k
    case 7:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  61656269;
//    	pAsrcStru->coarse_ppm_scale = 238;
    	pAsrcStru->dac_loop_out_scale = 3;
    	pAsrcStru->REMAIN_NUM_TARGET = pAsrcStru->ringbuf_len / 2;
    } break; //44.1k
    case 8:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  67108864;
//    	pAsrcStru->coarse_ppm_scale = 219;
    	pAsrcStru->dac_loop_out_scale = 2;
    	pAsrcStru->REMAIN_NUM_TARGET = pAsrcStru->ringbuf_len / 2;
    } break; //48k
    default:
    {
    	pAsrcStru->DAC_FS_RATIO_Q26 =  67108864;
//    	pAsrcStru->coarse_ppm_scale = 128;
    	pAsrcStru->dac_loop_out_scale = 2;
    	pAsrcStru->REMAIN_NUM_TARGET = pAsrcStru->ringbuf_len / 2 + 96;
    } break; //96k
    }
    pAsrcStru->ringbuf_left_wp   =  pAsrcStru->REMAIN_NUM_TARGET;
    pAsrcStru->ringbuf_right_wp  =  pAsrcStru->REMAIN_NUM_TARGET;
    pAsrcStru->ringbuf_left_rp   = 0;
    pAsrcStru->ringbuf_right_rp  = 0;

    pffast_dac_mag_init(USB_OUT_FS);
}

void Pack_Asrc_CoarseStart_FsSwitch(AsrcOut_t *pAsrcStru, uint32_t USB_OUT_FS)
{
	if( pAsrcStru->start_coarse_ppm  || (pAsrcStru->USB_DAC_FS_D != USB_OUT_FS) )
	{
//		DEBUG_GPIO4_SET();
		pAsrcStru->start_coarse_ppm = 0;
		pAsrcStru->USB_DAC_FS_D = USB_OUT_FS;
		Pack_Asrc_EstimationPPM_init  (pAsrcStru, USB_OUT_FS);
		pAsrcStru->coarse_state = 0;
		if(USB_OUT_FS<=8)
		{
			apb_dac_filt_config_left_dac_fs96k_setf(0);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
		else
		{
			apb_dac_filt_config_left_dac_fs96k_setf(1);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
//		DEBUG_GPIO4_CLR();
	}
}

void Pack_Asrc_EstimatePPM_coarse(AsrcOut_t *pAsrcStru)
{
    //ringbuf underflow or overflow detection and reset
	pAsrcStru->coarse_unlock = ( pAsrcStru->remain_num <= ASRC_OBUF_LEN_patch+1) || (pAsrcStru->remain_num >= pAsrcStru->ringbuf_len -1 - 96);
    int16_t ii;
    // FSM
    switch(pAsrcStru->coarse_state)
    {
       case 0:
       {
           // clear the buffer
    	   for(ii=0;ii<pAsrcStru->ringbuf_len;ii++)
	       {
        		pAsrcStru->ringbuf_left[ii] = 0;
        		pAsrcStru->ringbuf_right[ii] = 0;
	       }
//    	   pAsrcStru->coarse_cnt    = 0 ;
    	   pAsrcStru->coarse_locked = 0;
    	   pAsrcStru->coarse_state  = 1;
    	   pAsrcStru->coarse_ppm    = 0;
       }break;
       case 1:    // unlock detection
       {
    	   pAsrcStru->coarse_locked = 1;
    	   if(pAsrcStru->coarse_unlock)
    	   {
    		   pAsrcStru->coarse_locked      = 0;
    		   pAsrcStru->start_coarse_ppm   = 1;
    	   }
       }break;
    }//end switch
 }


void Pack_Asrc_EstimatePPM_fine(AsrcOut_t *pAsrcStru)
{
    int32_t dpll_err, delta_u;
    int8_t ii;
    //coarse_locked = 1;
#if (ASRC_OBUF_LEN_patch == 16)
    if (pAsrcStru->narrow_state < 1)
    {
    	pAsrcStru->dac_Ka = 40160;
        pAsrcStru->dac_Kb = 40000;
        pAsrcStru->DAC_MAX_PIDSTEP = 2000 << 10;
    }
    else if (pAsrcStru->narrow_state < 2)
    {
    	pAsrcStru->dac_Ka = 8080;
    	pAsrcStru->dac_Kb = 8000;
    	pAsrcStru->DAC_MAX_PIDSTEP = 2000 << 10;
    }
    else
    {
    	pAsrcStru->dac_Ka = 602;
    	pAsrcStru->dac_Kb = 600;
    	pAsrcStru->DAC_MAX_PIDSTEP = 2000 << 10;
    }
#else
	if (pAsrcStru->narrow_state < 1)
	{
		pAsrcStru->dac_Ka = 40160;
		pAsrcStru->dac_Kb = 40000;
//		pAsrcStru->DAC_MAX_PIDSTEP = 1000 << 10;
	}
	else if (pAsrcStru->narrow_state < 2)
	{
		pAsrcStru->dac_Ka = 40160/8;
		pAsrcStru->dac_Kb = 40000/8;
//		pAsrcStru->DAC_MAX_PIDSTEP = 200 << 10;  /*DAC_MAX_PIDSTEP not used !!!*/
	}
#endif
    if ( (!pAsrcStru->coarse_locked) )
    {
    	pAsrcStru->narrow_state    = 0;
    	pAsrcStru->cnt_for_narrow  = 0;
    	pAsrcStru->loopflt_out     = 0;
    	pAsrcStru->fine_ppm        = pAsrcStru->coarse_ppm;
    	pAsrcStru->coarse_ppm_hold = pAsrcStru->coarse_ppm;
    	pAsrcStru->dpll_err_d1     = 0;
		for(ii=0;ii<ERR_AVG_LEN;ii++)
		{
			pAsrcStru->dpll_err_array2[ii] = 0;
			pAsrcStru->dpll_err_array[ii]  = 0;
		}
    }
    else
    {
        if (pAsrcStru->cnt_for_narrow < 2000)
        {
        	pAsrcStru->narrow_state = 0;
        	pAsrcStru->cnt_for_narrow += 1;
        }
        else if (pAsrcStru->cnt_for_narrow < 3000) //DAC_MAX_NARROWCNT
        {
        	pAsrcStru->narrow_state = 1;
        	pAsrcStru->cnt_for_narrow += 1;
        }
        else
        {
        	pAsrcStru->narrow_state = 2;
        }

		for(ii=ERR_AVG_LEN-1;ii>0;ii--)
		{
			pAsrcStru->dpll_err_array[ii] = pAsrcStru->dpll_err_array[ii-1];
		}

		pAsrcStru->dpll_err_array[0]  = pAsrcStru->remain_num - pAsrcStru->REMAIN_NUM_TARGET;
//		if(__nds32__abs(pAsrcStru->dpll_err_array[0]) > 32)
//		{
//			__nds32__nop();
//		}

		if (pAsrcStru->narrow_state < 2) //moving average
		{
			dpll_err = 0;
			for(ii=0;ii<ERR_AVG_LEN;ii++)
			{
				dpll_err += pAsrcStru->dpll_err_array[ii];
			}
		}
		else  //median filter
		{
			//========================================================================
				for(ii=0;ii<ERR_AVG_LEN;ii++)
				{
					pAsrcStru->dpll_err_array2[ii] = pAsrcStru->dpll_err_array[ii];
				}
				//=============== sort ==============
				int8_t jj;
				int16_t temp;
				for(ii=1;ii<ERR_AVG_LEN;ii++)
				{
					temp = pAsrcStru->dpll_err_array2[ii];
					jj = ii-1;
					while(jj>=0 && pAsrcStru->dpll_err_array2[jj]>temp)
					{
						pAsrcStru->dpll_err_array2[jj+1] = pAsrcStru->dpll_err_array2[jj];
						jj--;
					}
					pAsrcStru->dpll_err_array2[jj+1] = temp;
				}
				dpll_err = pAsrcStru->dpll_err_array2[ERR_AVG_LEN>>1];	//return the median value
		}

		// delta_u   = (para->dac_Ka*dpll_err_avg - para->dac_Kb * para->dpll_err_avg_d1)>>3;
        delta_u   = (pAsrcStru->dac_Ka * dpll_err - pAsrcStru->dac_Kb * pAsrcStru->dpll_err_d1);   //PI control
        pAsrcStru->dpll_err_d1 = dpll_err;


        pAsrcStru->loopflt_out = ((pAsrcStru->loopflt_out<<ERR_SHIFT)+delta_u)>>ERR_SHIFT;


        if ( pAsrcStru->loopflt_out > pAsrcStru->DAC_MAX_PPM   ) // ppm in Q10,
        {
        	pAsrcStru->loopflt_out = pAsrcStru->DAC_MAX_PPM ;
        }
        else if (pAsrcStru->loopflt_out < -pAsrcStru->DAC_MAX_PPM  )
        {
        	pAsrcStru->loopflt_out = -pAsrcStru->DAC_MAX_PPM ;
        }

        pAsrcStru->fine_ppm = (pAsrcStru->coarse_ppm_hold + pAsrcStru->loopflt_out * pAsrcStru->dac_loop_out_scale); //fine ppm in Q10
       // fine_ppm = 0;
    }
}

void Pack_Asrc_write_ringbuf(
		AsrcOut_t *pAsrcStru,
	    int32_t   *pUSB_dacbuf_left,
	    int32_t   *pUSB_dacbuf_right,
	    uint32_t   Len)
{
	if(pAsrcStru->En == 0)
	{
		return;
	}
	int16_t temp_num, ii;

	if (pAsrcStru->usb_write_firstxx_packet < 32767)
	{
		pAsrcStru->usb_write_firstxx_packet += 1;
	}
	int16_t writeSpace = (pAsrcStru->ringbuf_left_rp + pAsrcStru->ringbuf_len - pAsrcStru->ringbuf_left_wp - 8); //left headroom 8

	if (writeSpace >=  pAsrcStru->ringbuf_len ) {
		writeSpace -= pAsrcStru->ringbuf_len;
	}

	int16_t writeNum = Len;

	if (writeNum > writeSpace) {
//	    DEBUG_GPIO4_SET();
		writeNum = writeSpace;  //ring buffer full !!!
	}

	if ( pAsrcStru->usb_write_firstxx_packet > pAsrcStru->usb_write_firstxx_packet_thrsh)
	{
        //left
		register int32_t Lwp = pAsrcStru->ringbuf_left_wp;
		register int32_t Rwp = pAsrcStru->ringbuf_right_wp;
		if ( Lwp + writeNum < pAsrcStru->ringbuf_len - 1 )
		{
			for (ii = 0; ii < writeNum; ii++) //write to ringbuf
			{
				pAsrcStru->ringbuf_left [++Lwp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
				pAsrcStru->ringbuf_right[++Rwp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}
		}
		else
		{
			temp_num = pAsrcStru->ringbuf_len - 1 - Lwp;
			for (ii = 0; ii < temp_num; ii++) //write to ringbuf
			{
				pAsrcStru->ringbuf_left [++Lwp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
				pAsrcStru->ringbuf_right[++Rwp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}

			Lwp = -1;
			Rwp = -1;
			for (; ii < (writeNum); ii++) //write to ringbuf
			{
				pAsrcStru->ringbuf_left [++Lwp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
				pAsrcStru->ringbuf_right[++Rwp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}
		}
		pAsrcStru->ringbuf_left_wp  = Lwp;
		pAsrcStru->ringbuf_right_wp = Rwp;
	}
	pAsrcStru->USB_DAC_EOF_FLAG = 1;
//	DEBUG_GPIO4_CLR();
}

void Pack_Asrc_padding_ringbuf(
		AsrcOut_t *pAsrcStru,
	    int32_t dataLeft,
	    int32_t dataRight,
	    int16_t writeNum)
{

	int16_t temp_num, ii;

	register int32_t Lwp = pAsrcStru->ringbuf_left_wp;
	register int32_t Rwp = pAsrcStru->ringbuf_right_wp;
	if ( Lwp + writeNum < pAsrcStru->ringbuf_len - 1 )
	{
		for (ii = 0; ii < writeNum; ii++) //write to ringbuf
		{
			pAsrcStru->ringbuf_left  [++Lwp]       = dataLeft;  //USB data format 24bits ?
			pAsrcStru->ringbuf_right [++Rwp]       = dataRight;  //USB data format 24bits ?
		}
	}
	else
	{
		temp_num = pAsrcStru->ringbuf_len - 1 - Lwp;
		for (ii = 0; ii < temp_num; ii++) //write to ringbuf
		{
			pAsrcStru->ringbuf_left  [++Lwp]        = dataLeft;  //USB data format 24bits ?
			pAsrcStru->ringbuf_right [++Rwp]       = dataRight;  //USB data format 24bits ?
		}
		Lwp = -1;
		Rwp = -1;
		for (; ii < (writeNum); ii++) //write to ringbuf
		{
			pAsrcStru->ringbuf_left  [++Lwp]        = dataLeft;  //USB data format 24bits ?
			pAsrcStru->ringbuf_right [++Rwp]       = dataRight;  //USB data format 24bits ?
		}
	}
	pAsrcStru->ringbuf_left_wp  = Lwp;
	pAsrcStru->ringbuf_right_wp = Rwp;
}

void Pack_Asrc_dac_top(        //driven by DAC Interrupt ,
	AsrcOut_t *pAsrcStru,
    int32_t   *pOUT_dacbuf_left,
    int32_t   *pOUT_dacbuf_right,
    int32_t    USB_OUT_FS)
{
	if(pAsrcStru->En == 0)
	{
		return;
	}
    int32_t  ii = 0;

    //(0.0) USB & DAC ON/OFF judge
    // when   USB_DAC_EOF_FLAG == 0 continuous 10 times, output to DAC '0'
    if (pAsrcStru-> USB_DAC_EOF_FLAG )
    {
    	pAsrcStru->USB_DAC_EOF_FLAG = 0;
    	pAsrcStru->usb_audio_out_off_cnt = 0;
//        if (pAsrcStru->dac_interrupt_cnt < 8)
//        {
//        	pAsrcStru->dac_interrupt_cnt++;
//        }
    }
    else  // detect continuous DAC interrupt
    {
        if (pAsrcStru->usb_audio_out_off_cnt < 66) //avoid overflow
        {
        	pAsrcStru->usb_audio_out_off_cnt ++ ;
        }
    }
    /* Coarse Start & Fs Switch Monitor*/
    Pack_Asrc_CoarseStart_FsSwitch(pAsrcStru, USB_OUT_FS);

    if (pAsrcStru->usb_write_firstxx_packet > pAsrcStru->usb_write_firstxx_packet_thrsh) //after receive firstxx_packets from USB host
    {
        //(0) copy USB data to ringbuffer (move to USB Interrupt callback)
        // asrc_write_ringbuf(pUSB_dacbuf_left,pUSB_dacbuf_right);

        //(1) caculate remain_num
        if (pAsrcStru->ringbuf_left_wp < pAsrcStru->ringbuf_left_rp)
        {
        	pAsrcStru->remain_num = pAsrcStru->ringbuf_len  + pAsrcStru->ringbuf_left_wp - pAsrcStru->ringbuf_left_rp;
        }
        else
        {
        	pAsrcStru->remain_num = pAsrcStru->ringbuf_left_wp - pAsrcStru->ringbuf_left_rp;
        }

        //(2) estimate coarse_ppm , estimate_fine_ppm and update dac_fs_ratio
        Pack_Asrc_EstimatePPM_coarse(pAsrcStru); //get coarse_ppm

        Pack_Asrc_EstimatePPM_fine(pAsrcStru);  //get fine_ppm

        //(3) update clock_ratio
        pAsrcStru->dac_fs_ratio = pAsrcStru->DAC_FS_RATIO_Q26 + (pAsrcStru->fine_ppm >> 4); //fine_ppm inQ10

        if(pAsrcStru->usb_audio_out_off_cnt > pAsrcStru->usb_audio_out_off_cnt_thrsh)
        {
        	/*USB interrupt stop*/
    		pAsrcStru->usb_write_firstxx_packet = 0;
    //    	pAsrcStru->dac_interrupt_cnt = 0;

    		pAsrcStru->ringbuf_left_rp  = pAsrcStru->ringbuf_left_wp  - pAsrcStru->REMAIN_NUM_TARGET;
    		pAsrcStru->ringbuf_right_rp = pAsrcStru->ringbuf_right_wp - pAsrcStru->REMAIN_NUM_TARGET;

    		while(pAsrcStru->ringbuf_left_rp <0)
    		{
    			pAsrcStru->ringbuf_left_rp += pAsrcStru->ringbuf_len;
    		}

    		while(pAsrcStru->ringbuf_right_rp <0)
    		{
    			pAsrcStru->ringbuf_right_rp += pAsrcStru->ringbuf_len;
    		}

            for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
            {
                pOUT_dacbuf_right[ii] = 0;
                pOUT_dacbuf_left[ii]  = 0;
            }
        }
        else
        {
        	/*ASRC filter*/
        	if( pAsrcStru->remain_num <  pAsrcStru->xinbuf_len )
        	{
        		/*ring buffer empty!!!*/
        		int16_t delta_num = (pAsrcStru->xinbuf_len  - pAsrcStru->remain_num);
        		int32_t dataLeft  = pAsrcStru->ringbuf_left[pAsrcStru->ringbuf_left_wp];
        		int32_t dataRight = pAsrcStru->ringbuf_right[pAsrcStru->ringbuf_right_wp];
    //    		int32_t dataLeft  = (1<<23)-10;
    //    		int32_t dataRight = (1<<23)-10;
    //    		DEBUG_GPIO4_SET();
        		Pack_Asrc_padding_ringbuf(pAsrcStru, dataLeft, dataRight, delta_num);
        	}

        	AsrcFilterHandle AsrcFilterHandler = (USB_OUT_FS <= 8 ) ? asrc_codec48k_pffast : new_asrc_codec96k_pffast;
			new_asrc_codec_readbuf_fast(
					pAsrcStru->ringbuf_left   , //data format 32Q23, 24bits Audio
					pAsrcStru->ringbuf_right  , //data format 32Q23, 24bits Audio
					pAsrcStru->xinbuf_left    , //data format 32Q19 for asrc filter
					pAsrcStru->xinbuf_right   , //data format 32Q19 for asrc filter
					pAsrcStru->ringbuf_len    ,
					pAsrcStru->xinbuf_len     , //xin buffer length, according to asrc performance level
				   &pAsrcStru->nco_buf_left   ,
				   &pAsrcStru->nco_buf_right  ,
				   &pAsrcStru->ringbuf_left_rp,
				   &pAsrcStru->ringbuf_right_rp  ,
					pAsrcStru->DAC_STEREO_MODE
			);
			AsrcFilterHandler(
					pAsrcStru->xinbuf_left    ,  // ringbuffer, data format 32Q19 !!!
					pOUT_dacbuf_left          ,  // outbuffer,  data format 32Q23
					ASRC_OBUF_LEN_patch       ,
				   &pAsrcStru->nco_left       ,
				   &pAsrcStru->nco_buf_left   ,
					pAsrcStru->dac_fs_ratio   ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

			if (pAsrcStru->DAC_STEREO_MODE > 0)
			{
				AsrcFilterHandler(
						pAsrcStru->xinbuf_right      ,  // ringbuffer, data format 32Q19 !!!
						pOUT_dacbuf_right            ,  // outbuffer,  data format 32Q23
						ASRC_OBUF_LEN_patch          ,
					   &pAsrcStru->nco_right         ,
					   &pAsrcStru->nco_buf_right     ,
					   pAsrcStru->dac_fs_ratio          ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
        }
    }
    else
    {
        for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
        {
            pOUT_dacbuf_right[ii] = 0;
            pOUT_dacbuf_left[ii]  = 0;
        }
    }
}


