/*
 * asrc_muses_fs_ppm.c
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 *
 * V0.2  LIZHEN  2018-07-05  (1) change the adjust period to 100ms
 * V0.3  LIZHEN  2018-07-05  (1) change to original ppm logic, and start ADC and USB in the controller
 * V0.4  lizhen 2018-12-04  (1) change buffer to (384*2), add usb off cnt, usb_read_firstxx_packet, scale all target by 2
 *                          (2) add usb_audio_in_off_cnt_thrsh =4 or 7
 *                          (3) delete asrc filter performance 0/1,
 *                          (4) change memset() back to for(...), memset() is too slow
 */
//2018-12-14   (1) clear buffer in the coarse_ppm, reduce peak CPU usage
//             (2) do asrc freq ratio cali  after usb_read_firstxx_packet_thrsh/2,
//2018-12-18   (1) change to support [-5%, 5%] high osc freq error
//             (2) add  USB_ADC_EOF_FLAG = 1 in adc_asrc_top , after the adc_ringbuf_rp updated in ASRC
//2019-01-24   (1) add adc_relock_init() function
#include "com_includes.h"
#include "asrc_adc_fs_ppm.h"
#include "asrc_codec_filter.h"
#include "nds32_filtering_math.h"

int32_t *g_pAdcRingBufLeft = NULL;
int32_t *g_pAdcXinBufLeft = NULL;
int32_t ASRC_ADC_RINGBUF_LEN_patch;
int16_t usb_read_firstxx_packet;
int16_t usb_read_firstxx_packet_thrsh;
int16_t usb_audio_in_off_cnt;
int16_t usb_audio_in_off_cnt_thrsh;
int16_t adc_dpll_bw_sel;
int32_t ADC_MAX_PPM;
int32_t adc_coarse_ppm_abs;
int16_t adc_loop_out_scale;
extern int32_t coarse_locked;
extern int32_t narrow_state;
extern int32_t coarse_ppm_abs;
extern int32_t dpll_bw_sel;
extern int32_t fine_ppm;
extern int32_t coarse_ppm_scale;
//performance level, SNDR and CPU cost tradeoff option
// 0:pfzero 10M , 1:pflow 20M, 2:pfmid 30M,3: pfhigh 40M for 48k stereo audio
// 0 or 1, pflow,  2: pfmid, 3:pfhigh for 96k stereo audio
uint8_t ASRC_ADC_PFORMANCE = 2; //0,2,3 performance
int32_t ADC_LPF_USBFS_SEL_ENABLE=1;
int32_t ADC_REMAIN_NUM_TARGET = 270;
int32_t  asrc_adc_xinbuf_len = ASRC_ADC_XINBUF_LEN; // asrc_adc_xinbuf_len <= ASRC_ADC_XINBUF_LEN

int32_t  adc_ringbuf_rp  = 0;
int32_t  adc_ringbuf_wp =  (ASRC_ADC_RINGBUF_LEN/2);

int32_t USB_ADC_FS   = 8;         //0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
int32_t USB_ADC_FS_D = -1; //sample rate delay
int32_t USB_ADC_EOF_FLAG     = 0;
int32_t USB_ADC_PCM_NUM = 48;  //PCM sample number in 1ms seconds
int32_t USB_ADC_ASRC_ENABLE = 1;
int32_t ADC_FS_RATIO_Q26  = 65536000;  //Fsin/Fsout in Q26 format, 46.875k/48k*2^26
int32_t ADC_STEREO_MODE  = 0;
int32_t ADC_DOWN_N       = 1;
int32_t adc_decimated_len = ASRC_ADC_IBUF_LEN;
int32_t adc_fs_ratio     = 65536000;
int32_t adc_coarse_cnt      = 0 ;
int32_t adc_coarse_cnt2     = 0 ;

int32_t start_adc_coarse_ppm   = 0;
int32_t start_adc_coarse_ppm_d = 0;

int32_t adc_coarse_state     = 0;
//int32_t coarse_nxtstate  = 0;

int32_t adc_remain_num_d     = 0;
int32_t adc_remain_num       = 0;
int32_t adc_remain_num_min   = 0;
int32_t adc_remain_num_min0  = 0;
int32_t adc_remain_min_search = 888;

//int32_t adc_continuous_win   = 8;
int32_t adc_coarse_ppm_scale = 2333;
int32_t adc_coarse_ppm       = 0;
int32_t adc_coarse_ppm_hold  = 0;
int32_t adc_coarse_locked    = 0;
int32_t adc_fine_ppm         = 0;
int32_t adc_narrow_state     = 0;
int32_t adc_Ka  = 21020 ;
int32_t adc_Kb  = 20040 ;
int32_t adc_cnt_for_narrow  = 0;
int32_t adc_dpll_err_d1     = 0;
int32_t ADC_MAX_PIDSTEP     = 20*1000;
int32_t ADC_MAX_NARROWCNT   = 300;
int64_t adc_nco     = 0;
int64_t adc_nco_buf = 0;

extern int32_t *g_pAdcRingBufLeft;
extern int32_t *g_pAdcXinBufLeft;
extern int32_t ASRC_ADC_RINGBUF_LEN_patch;
int16_t usb_read_firstxx_packet;
int16_t usb_read_firstxx_packet_thrsh;
int16_t usb_audio_in_off_cnt;
int16_t usb_audio_in_off_cnt_thrsh;

int16_t adc_dpll_bw_sel;
int32_t ADC_MAX_PPM;
int32_t adc_coarse_ppm_abs;
int16_t adc_loop_out_scale;
extern uint8_t g_ppm_range;

st_FAST_DCNOTCH FAST_DCNOTCH = {
		.Alpha = 1,
		.Cnt = 0,
		.Buf = 0,
};

typedef struct
{
    uint32_t (*Asrc_Adc_Fs_Ppm_Init)(uint32_t uInBaseAddr);
    void (*estimation_adc_ppm_init)(void);
    void (*asrc_adc_fs_change_init)(void);
    void (*estimate_adc_coarse_ppm)(void);
    void (*estimate_adc_fine_ppm)(void);
    void (*asrc_adc_writebuf)(int32_t *pDATA);
    void (*asrc_adc_top)(int32_t *pOUT_USB, int32_t USB_ADC_PCM_NUM);
    void (*asrc_adc_Clean_RingBuf)(void);
} asrc_adc_ftable_t;

asrc_adc_ftable_t *pasrc_adc_ftabl = NULL;

//void  Pilot_Filt_Init()
//{
//	PilotFiltCoeffBand0[0] =
//}

uint32_t Asrc_Adc_Fs_Ppm_Init(uint32_t uInBaseAddr)
{
    return pasrc_adc_ftabl->Asrc_Adc_Fs_Ppm_Init(uInBaseAddr);
}
extern uint32_t Patch_Asrc_Adc_Fs_Ppm_Init(uint32_t uInBaseAddr);
//uint32_t Patch_Asrc_Adc_Fs_Ppm_Init(uint32_t uInBaseAddr)
//{
//	USB_ADC_FS_D =  -1;
//	start_adc_coarse_ppm = 0;
//
//	ASRC_ADC_RINGBUF_LEN_patch = (384*3);
//
//    uInBaseAddr = ((uInBaseAddr + 3) & 0xFFFFFFFC); //int32_t aligN
//    g_pAdcRingBufLeft= (int32_t *)(uInBaseAddr);
//    uInBaseAddr += ASRC_ADC_RINGBUF_LEN_patch * sizeof(int32_t);
//    g_pAdcXinBufLeft = (int32_t *)(uInBaseAddr);
//    uInBaseAddr += (96+96/2+26)* sizeof(int32_t);  //allocate max buffer for 96k
//
//    return uInBaseAddr;
//}

void estimation_adc_ppm_init(void)
{
    pasrc_adc_ftabl->estimation_adc_ppm_init();
}

int adc_packet_num;
//extern void Patch_estimation_adc_ppm_init(void);
void new_Patch_estimation_adc_ppm_init(void)
{

	ASRC_ADC_PFORMANCE = 2; //0,2,3 performance
	ADC_LPF_USBFS_SEL_ENABLE = 0;

	//ADC_REMAIN_NUM_TARGET  = 280;
	usb_read_firstxx_packet = 0;
	usb_read_firstxx_packet_thrsh = 8; //8ms
	usb_audio_in_off_cnt = 0;
	usb_audio_in_off_cnt_thrsh = 7;

	adc_loop_out_scale = 1;
	ADC_MAX_PPM = ((g_ppm_range * 10000) << 10); //ppm in Q10

	adc_ringbuf_wp = ASRC_ADC_RINGBUF_LEN_patch/2;
	adc_ringbuf_rp = 0;
    adc_packet_num = 0;
}
extern void estimation_adc_ppm_relock_init(void);
//void estimation_adc_ppm_relock_init(void)
//{
//	    adc_coarse_locked    = 0;
//		adc_coarse_cnt      = 0 ;
//		adc_coarse_cnt2     = 0 ;
//
//		adc_remain_num_d     = 0;
//		adc_remain_num_min0 = 0;
//		adc_coarse_ppm       = 0;
//		adc_fine_ppm         = 0;
//		adc_narrow_state     = 0;
//		adc_coarse_state     = 0;
//		adc_nco     = 0;
//		adc_nco_buf = 0;
//}

void asrc_adc_fs_change_init(void)  //re-initialize the state;
{
    pasrc_adc_ftabl->asrc_adc_fs_change_init();
}
//extern void Patch_asrc_adc_fs_change_init(void)  ;

void new_Patch_asrc_adc_fs_change_init(void)  //re-initialize the state;
{
  	 asrc_adc_lpf_init(USB_ADC_FS);  //for decimation LPF

	   switch(USB_ADC_FS)
	   {
	      case 0:   // usb audio out freq
	            {
	            	 ADC_FS_RATIO_Q26 =  98304000;
	            	 adc_coarse_ppm_scale  = 1953;
	            	 ADC_DOWN_N = 4;
	            	 adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>2;
	            	 asrc_adc_xinbuf_len = (12+12/2);
	            	 ADC_REMAIN_NUM_TARGET = 138*2 ;
	            	 usb_audio_in_off_cnt_thrsh =4;
	            	 adc_loop_out_scale = 4;
	            }break; //8k
	      case 1:
	            {
	            	ADC_FS_RATIO_Q26 =  71331701 ;
	            	adc_coarse_ppm_scale  = 1417;
	            	ADC_DOWN_N = 4;
	            	adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>2;
	            	asrc_adc_xinbuf_len = (12+12/2);
	            	ADC_REMAIN_NUM_TARGET = 143*2 ;
	            	usb_audio_in_off_cnt_thrsh =4;
	            	 adc_loop_out_scale = 4;
	            }break; //11.025k
	      case 2:
	 	        {
	 	        	ADC_FS_RATIO_Q26 =  65536000 ;
	 	        	adc_coarse_ppm_scale  = 1302;
	 	        	ADC_DOWN_N = 4;
	 	        	adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>2;
	 	        	asrc_adc_xinbuf_len = (12+12/2);
	 	        	ADC_REMAIN_NUM_TARGET = 144*2 ;
	 	        	usb_audio_in_off_cnt_thrsh =4;
	 	        	adc_loop_out_scale = 4;
	 	        }break; //12k
	      case 3:
	           {
	        	   ADC_FS_RATIO_Q26 =  98304000 ;
	        	   adc_coarse_ppm_scale = 977;
	        	   ADC_DOWN_N = 2;
	        	   adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>1;
	        	   asrc_adc_xinbuf_len = (24+24/2);
	        	   ADC_REMAIN_NUM_TARGET = 150*2 ;
	        	   usb_audio_in_off_cnt_thrsh =4;
	        	   adc_loop_out_scale = 2;

	           }break; //16k
	      case 4:
	          {
	        	  ADC_FS_RATIO_Q26 =  71331701 ;
	        	  adc_coarse_ppm_scale = 709;
	        	  ADC_DOWN_N = 2;
	        	  adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>1;
	        	  asrc_adc_xinbuf_len = (24+24/2);
	        	  ADC_REMAIN_NUM_TARGET = 159*2 ;
	        	  usb_audio_in_off_cnt_thrsh =4;
	        	  adc_loop_out_scale = 2;
	          }break; //22.05k
	      case 5:
	         {
	        	 ADC_FS_RATIO_Q26 =  65536000;
	        	 adc_coarse_ppm_scale = 651;
	        	 ADC_DOWN_N = 2;
	        	 adc_decimated_len = ASRC_ADC_IBUF_LEN_patch>>1;
	        	 asrc_adc_xinbuf_len = (24+24/2);
	        	 ADC_REMAIN_NUM_TARGET = 162*2 ;
	        	 usb_audio_in_off_cnt_thrsh = 4;
	        	   adc_loop_out_scale = 2;
	         }break; //24k

	      case 6:
	         {
	        	 ADC_FS_RATIO_Q26 =  98304000;
	        	 adc_coarse_ppm_scale = 488;
	        	 ADC_DOWN_N = 1;
	        	 adc_decimated_len = ASRC_ADC_IBUF_LEN_patch;
	        	 asrc_adc_xinbuf_len = (48+48);
	        	 ADC_REMAIN_NUM_TARGET = 174*2;
	        	 usb_audio_in_off_cnt_thrsh = 4;
	        	 adc_loop_out_scale = 1;

	         }break; //32k
	      case 7:
	         {
	        	 ADC_FS_RATIO_Q26 =   73043661;   //(48/44.1)*2^26
	        	 adc_coarse_ppm_scale = 354;
	        	 ADC_DOWN_N = 1;
	        	 adc_decimated_len = ASRC_ADC_IBUF_LEN_patch;
	        	 asrc_adc_xinbuf_len = (48+48/2);
//	        	 ADC_REMAIN_NUM_TARGET = 192*2;
	        	 ADC_REMAIN_NUM_TARGET = ASRC_ADC_RINGBUF_LEN_patch/2;
	        	 usb_audio_in_off_cnt_thrsh =4;
	        	 adc_loop_out_scale = 1;
	         }break; //44.1k
	      case 8:
	         {
	        	 ADC_FS_RATIO_Q26 =  67108864;
	        	 adc_coarse_ppm_scale = 325;
	        	 ADC_DOWN_N = 1;
	        	 adc_decimated_len = ASRC_ADC_IBUF_LEN_patch;
	        	 asrc_adc_xinbuf_len = (48+48/2);
//	        	 ADC_REMAIN_NUM_TARGET = 198*2 ;
	        	 ADC_REMAIN_NUM_TARGET = ASRC_ADC_RINGBUF_LEN_patch/2;
	        	 usb_audio_in_off_cnt_thrsh =4;
	        	 adc_loop_out_scale = 1;
	         }break; //48k
	      default:
	         {
	        	 ADC_FS_RATIO_Q26 =  67108864;
	        	 adc_coarse_ppm_scale = 162;
	        	 ADC_DOWN_N = 1;
	        	 adc_decimated_len  = ASRC_ADC_IBUF_LEN_patch;
	        	 asrc_adc_xinbuf_len = (96+96/2);
	        	 ADC_REMAIN_NUM_TARGET = ASRC_ADC_RINGBUF_LEN_patch/2+96;
	        	 usb_audio_in_off_cnt_thrsh =7;
	        	 adc_loop_out_scale = 1;
	         }break; //96k
	   }// end switch

	   adc_ringbuf_wp = ADC_REMAIN_NUM_TARGET;
	   adc_ringbuf_rp = 0;
	  // asrc_adc_Clean_RingBuf();

      if     (ASRC_ADC_PFORMANCE == 0)
          	  asrc_adc_xinbuf_len += 5;

      else if(ASRC_ADC_PFORMANCE == 1)
           	  asrc_adc_xinbuf_len += 13;

      else if(ASRC_ADC_PFORMANCE == 2)
           	  asrc_adc_xinbuf_len += 19;
      else
          	  asrc_adc_xinbuf_len += 26;
}

//int32_t adc_flag_change;
int32_t adc_remain_delta0;
int32_t adc_coarse_unlock;
int32_t  ADC_LOCAL_MIN_WINDOW = 18;

void estimate_adc_coarse_ppm(void)  //re-initialize the state;
{
    pasrc_adc_ftabl->estimate_adc_coarse_ppm();
}
extern void Patch_estimate_adc_coarse_ppm(void);

void new_Patch_estimate_adc_coarse_ppm(void)
{
//(0) update adc_ppm_scale in asrc_adc_fs_change_init();
	if(start_adc_coarse_ppm || (USB_ADC_FS != USB_ADC_FS_D) )
	{
		start_adc_coarse_ppm = 0;
		USB_ADC_FS_D = USB_ADC_FS;
		estimation_adc_ppm_init();
		asrc_adc_fs_change_init();
//		estimation_adc_ppm_relock_init();
		if(USB_ADC_FS <=8)
		{
			apb_adc_filt_config_0_cic1_en_2_setf(0);
			apb_adc_filt_config_0_sync_bit_setf(1);
		}
		else
		{
			apb_adc_filt_config_0_cic1_en_2_setf(1);
			apb_adc_filt_config_0_sync_bit_setf(1);
		}

	}

  	// adc_remain_num_d = adc_remain_num;  //update remain_num_d
    adc_coarse_unlock = (adc_remain_num<=48) || (adc_remain_num >= ASRC_ADC_RINGBUF_LEN_patch-48);

    //(1) search locak min value

   if(1)   //search local min value
   {
	   if(adc_coarse_cnt2 < ADC_LOCAL_MIN_WINDOW)
	   {
		   adc_coarse_cnt2 += 1;
		   if(adc_remain_min_search > adc_remain_num)
			   adc_remain_min_search = adc_remain_num;
	   }
	   else
	   {
		   adc_coarse_cnt2 = 0;
		   adc_remain_num_min = adc_remain_min_search;
		   adc_remain_min_search = 8888;
	   }
   }

   int16_t ii;
 //(2) FSM
    switch(adc_coarse_state)
    {
       case 0:
        {
	    	 for(ii=0;ii<ASRC_ADC_RINGBUF_LEN_patch/2;ii++)
     	      {
	    		 g_pAdcRingBufLeft[ii] = 0;
     	      }

        	adc_coarse_cnt = 0;
        	adc_coarse_locked = 0;
//        	adc_coarse_state = 4;
        	adc_coarse_state += 1;


        }break;

       case 1:         //record the remain_num_min0 in step0
       {
	      for(ii=ASRC_ADC_RINGBUF_LEN_patch/2;ii<ASRC_ADC_RINGBUF_LEN_patch;ii++)
   	       {
	    		 g_pAdcRingBufLeft[ii] = 0;
   	       }

	      adc_remain_num_min0 = adc_remain_num;
//	      adc_coarse_state += 1;
	      adc_coarse_state = 4;

       }break;

       case 2:
       {
    	  adc_remain_delta0 = adc_remain_num - adc_remain_num_min0;
    	  adc_coarse_ppm = 0;

    	  {
    	   //wait until remain_num changed delta >= 64 or about 0.1 seconds (for small ppm )
    	    if(adc_remain_delta0 >= 64 || adc_remain_delta0 <= -64 || adc_coarse_cnt >= 100)
    	    {
    		   adc_coarse_state += 1;
    		   if(adc_coarse_cnt != 0)     //
    		   {
    			   adc_coarse_ppm = (int32_t) (((int64_t)adc_coarse_ppm_scale*1048576)/adc_coarse_cnt); // coarse ppm in 32Q10 format
    			   adc_coarse_ppm = (adc_coarse_ppm * adc_remain_delta0)>>4; //
    			   adc_coarse_locked = 0;
    		   }
    	    }
    	    else
    	    {
    	         adc_coarse_cnt +=1;
    	    }
    	  }

       }break;

       case 3:
       {
     	   adc_coarse_state += 1;
     	   if(adc_coarse_ppm > ADC_MAX_PPM )
     	     	adc_coarse_ppm = (ADC_MAX_PPM);
     	  else if(adc_coarse_ppm < -ADC_MAX_PPM)
     	        adc_coarse_ppm = -(ADC_MAX_PPM);


       }break;

       case 4:    // unlock detection
       {
    	   adc_coarse_ppm = 0;
    	   adc_coarse_locked = 1;
    	   if(adc_coarse_unlock  )
    	   {
    	  // DEBUG_GPIO4_SET();
   		      adc_coarse_state = 0;
   		      adc_coarse_locked = 0;
   		      start_adc_coarse_ppm  = 1;
   		      estimation_adc_ppm_relock_init();

   	   	  //DEBUG_GPIO4_CLR();
    	   }

       }break;
    }//end switch
 }

int32_t adc_loopflt_out = 0 ;
int32_t adc_narrow_upflag, adc_narrow_lowflag;
int32_t adc_delta_target, adc_delta_target_min;
int32_t adc_loop_cnt;
void estimate_adc_fine_ppm(void)
{
    pasrc_adc_ftabl->estimate_adc_fine_ppm();
}
//extern void Patch_estimate_adc_fine_ppm(void);

void new_Patch_estimate_adc_fine_ppm(void)
{

    int32_t adc_dpll_err,  adc_delta_u;

    if(adc_narrow_state <1)
         { adc_Ka = 40160;  adc_Kb = 40000;    ADC_MAX_PIDSTEP = 1000<<10; }

    else if(adc_narrow_state<2)

         { adc_Ka = 8080;   adc_Kb = 8000;   ADC_MAX_PIDSTEP = 50<<10;}
    else
         { adc_Ka = 8080;   adc_Kb = 8000;   ADC_MAX_PIDSTEP = 20<<10;}


     if( (!adc_coarse_locked) )
     {
    	 adc_narrow_state    = 0;
    	 adc_cnt_for_narrow  = 0;
    	 adc_loopflt_out     = 0;
    	 adc_fine_ppm        = adc_coarse_ppm;
    	 adc_coarse_ppm_hold = adc_coarse_ppm;
    	 adc_dpll_err_d1     = 0;
    	 adc_loop_cnt        = 0;
     }
     else
     {
    	 if(adc_cnt_for_narrow < 3000)
    	 {
    		   adc_narrow_state = 0;
    		   adc_cnt_for_narrow += 1;
    	 }
    	 else if(adc_cnt_for_narrow < 6000)
    	 {
    		   adc_narrow_state = 1;
    		   adc_cnt_for_narrow += 1;
    	 }
		 else
		 {
			   adc_narrow_state = 2;
		 }

          if(adc_narrow_state>0)
    	       adc_dpll_err = adc_remain_num_min - ADC_REMAIN_NUM_TARGET;
          else
        	   adc_dpll_err = adc_remain_num - ADC_REMAIN_NUM_TARGET;

    	   adc_delta_u   = adc_Ka*adc_dpll_err - adc_Kb * adc_dpll_err_d1;     //PI control

    	   if(adc_delta_u > ADC_MAX_PIDSTEP)
    		   adc_loopflt_out = adc_loopflt_out + ADC_MAX_PIDSTEP;

    	   else if(adc_delta_u < - ADC_MAX_PIDSTEP)
    		   adc_loopflt_out = adc_loopflt_out - ADC_MAX_PIDSTEP;

    	   else
    		   adc_loopflt_out = adc_loopflt_out + adc_delta_u;


     	   if( adc_loopflt_out > (ADC_MAX_PPM)  )  // ppm in Q10,
        	      adc_loopflt_out = (ADC_MAX_PPM);
           else if(adc_loopflt_out < (-ADC_MAX_PPM) )
        	  	  adc_loopflt_out =  (-ADC_MAX_PPM);

     	  adc_fine_ppm = (adc_coarse_ppm_hold + adc_loopflt_out*adc_loop_out_scale); //fine ppm in Q10

//
//         if(adc_narrow_state<2)
//        	 adc_fine_ppm = (adc_coarse_ppm_hold + adc_loopflt_out*adc_loop_out_scale); //fine ppm in Q10
//         else
//         {
//        	 if(adc_loop_cnt<6000)  //3000*0.3ms = 1s
//        		 adc_loop_cnt++;
//        	 else
//        	 {
//        		 adc_loop_cnt = 0;
//
//            	 if( adc_dpll_err > 128)
//            	 {
//            		 adc_fine_ppm -= 50<<10;
//            	 }
//            	 else if(adc_dpll_err < -128)
//            	 {
//            		 adc_fine_ppm += 50<<10;
//            	 }
//            	 else
//            	 {
//            		 ;
//            	 }
//
//        	 }
//
//         }


    	 adc_dpll_err_d1 = adc_dpll_err;
        }

}


void asrc_adc_writebuf(int32_t *pDATA)
{
    pasrc_adc_ftabl->asrc_adc_writebuf(pDATA);
}

int adc_packet_num;
// int usb_audio_in_off_cnt = 0;
 //driven by ADC Interrupt , ASRC_ADC_IBUF_LEN = 16, 16 PCM samples per Interrupt
void new_Patch_asrc_adc_writebuf(int32_t *pDATA)               //sfix32_en23, from ADC
{

//	 DEBUG_GPIO5_SET();
    int16_t  ii;
    //=======================================================
	//Alpha:  5/   6/  7/  8/  9/  10/  11/  12/
	//BW   228/ 115/ 56/ 28/ 14/   7/   3/  1.5/Hz
    //=======================================================
    if(0 == FAST_DCNOTCH.Cnt) // wait the 'non-zero' data
    {
    	for(ii=0;ii<ASRC_ADC_IBUF_LEN_patch;ii++)
    	{
    		if(__nds32__abs(pDATA[ii]) > (5<<13) )   //5mV in 24bits
    		{
    			FAST_DCNOTCH.Cnt = 1;
    			break;
    		}
    	}
    }
    else
    {
    	if(FAST_DCNOTCH.Cnt < 16*2)
    	{
    		FAST_DCNOTCH.Alpha = 1;
    		FAST_DCNOTCH.Cnt++;
    	}
    	else if(FAST_DCNOTCH.Cnt < 16*10)  //160*0.3 = 48ms  for analog DC set
		{
			FAST_DCNOTCH.Alpha = (FAST_DCNOTCH.Cnt>>4); //1~9
			FAST_DCNOTCH.Cnt++;
		}
    }

	int8_t Alpha = FAST_DCNOTCH.Alpha;
	int32_t sum0; // 32Q23 ==> 32Q29
	int32_t Buf = FAST_DCNOTCH.Buf;
	int32_t temp_int32;

	for(ii=0;ii<ASRC_ADC_IBUF_LEN_patch;ii++)
	{
		temp_int32 = pDATA[ii]<<6; //32Q29
		sum0 = ((temp_int32 - Buf) >> Alpha) + Buf;
		Buf = sum0;
		pDATA[ii] = (temp_int32 - sum0)>>6;
	}
	FAST_DCNOTCH.Buf = Buf;


  if( usb_read_firstxx_packet >  usb_read_firstxx_packet_thrsh/8) //
  {
	   // apb_adc_filt_config_0_dcnotcg_bw_setf(2) ;//0->228Hz, 2->57Hz,
	   // apb_adc_filt_config_0_sync_bit_setf(1);

    //(0) do fs initialize when fs changed, decimation LPF init, ppm_scale init...

    //(1) do LPF for decimation

     asrc_adc_lpf(pDATA,       //sfix32_en23
    		     pDATA ,       //sfix32_en23, output
    		     USB_ADC_FS,   // USB ADC FS sample freq
    		     ASRC_ADC_IBUF_LEN_patch
    		     );


    //(2) decimation and write ADC data to ringbuf,  and sync with USB start input
       if(1) //USB_ADC_START_COUNT >= USB_ADC_START_COUNT_THRSH-1)
       {
            // adc_packet_num += 1;
            //
            if (USB_ADC_FS == 7 || USB_ADC_FS == 8)
            {

                for (ii = 0; ii < adc_decimated_len; ii++) //write to ringbuf
                {
                    adc_ringbuf_wp += 1;
                    if (adc_ringbuf_wp >  ASRC_ADC_RINGBUF_LEN_patch - 1 ) //wrap round the writer pointer
                        adc_ringbuf_wp = 0;

                    g_pAdcRingBufLeft[adc_ringbuf_wp] = pDATA[ii];
                }

            }
            else
            {

                for (ii = 0; ii < adc_decimated_len; ii++) //write to ringbuf
                {
                    adc_ringbuf_wp += 1;
                    if (adc_ringbuf_wp >  ASRC_ADC_RINGBUF_LEN_patch - 1 ) //wrap round the writer pointer
                        adc_ringbuf_wp = 0;

                    g_pAdcRingBufLeft[adc_ringbuf_wp] = pDATA[ii * ADC_DOWN_N];
                }

            }


            // for (ii = 0; ii < adc_decimated_len; ii++) //write to ringbuf
            // {
            //     adc_ringbuf_wp += 1;
            //     if (adc_ringbuf_wp >  ASRC_ADC_RINGBUF_LEN_patch - 1 ) //wrap round the writer pointer
            //         adc_ringbuf_wp = 0;

            //     g_pAdcRingBufLeft[adc_ringbuf_wp] = pDATA[ii * ADC_DOWN_N];
            // }
        }
    }

   // USB_DAC_EOF_FLAG == 0 continuous 7 times, hold the ADC input ringbuffer
    if( USB_ADC_EOF_FLAG )
    {
     	usb_audio_in_off_cnt = 0;

     	if(usb_read_firstxx_packet<888)
     		usb_read_firstxx_packet++;

        if(USB_ADC_FS <=8)
        	  usb_audio_in_off_cnt_thrsh = 5;
        else
              usb_audio_in_off_cnt_thrsh = 8;
        USB_ADC_EOF_FLAG = 0;
    }
    else
    {
      	if(usb_audio_in_off_cnt < usb_audio_in_off_cnt_thrsh+3) //avoid overflow
     		usb_audio_in_off_cnt ++ ;
    }


    // when no USB reading buff last for >7 ADC interrupt
    if(usb_audio_in_off_cnt >  usb_audio_in_off_cnt_thrsh)
    {
	   usb_read_firstxx_packet = 0;
	   start_adc_coarse_ppm = 1;
	   FAST_DCNOTCH.Cnt = 0; //
    }

    //(3) caculate remain_num && update ppm when USB_ADC_EOF_FLAG set to 1 && firstxx_packet >
//    if(USB_ADC_EOF_FLAG && (usb_read_firstxx_packet >  usb_read_firstxx_packet_thrsh/8) ) //after read xx frame data
    if( (usb_read_firstxx_packet >  usb_read_firstxx_packet_thrsh/8) ) //after read xx frame data
    {
//    	USB_ADC_EOF_FLAG = 0;

    	//DEBUG_GPIO4_SET();

    	  //(3_0) caculate remain_num when USB_EOF_FLAG
    	  if(adc_ringbuf_wp < adc_ringbuf_rp)
    	   {
    	 	   	 adc_remain_num = ASRC_ADC_RINGBUF_LEN_patch + adc_ringbuf_wp - adc_ringbuf_rp;
    	   }
    	 else
    	  {
    	 		 adc_remain_num = adc_ringbuf_wp - adc_ringbuf_rp;
    	  }


#ifdef DATA_RECORD
    	  if(rr_idx<6000)
    	     adc_remain_num_array[rr_idx++] = adc_remain_num;
    	  else
    		  __nds32__nop();

#endif

    	      estimate_adc_coarse_ppm(); //search the local remain_num min
    	      estimate_adc_fine_ppm ();  //get adc_fine_ppm
              adc_fs_ratio = ADC_FS_RATIO_Q26 + (adc_fine_ppm>>4); // ppm in Q10

             // DEBUG_GPIO4_CLR();
       }

//    DEBUG_GPIO5_CLR();
}

void asrc_adc_top(int32_t *pOUT_USB, int32_t USB_ADC_PCM_NUM)
{
    pasrc_adc_ftabl->asrc_adc_top(pOUT_USB, USB_ADC_PCM_NUM);
}
int adc_remain_temp =0;
int  usb_packet_num;
int32_t g_usb_adc_pcm_num;

extern void Patch_asrc_adc_top(int32_t *pOUT_USB, int32_t USB_ADC_PCM_NUM);

//driven by USB Interrupt
//void new_Patch_asrc_adc_top(int32_t *pOUT_USB, int32_t USB_ADC_PCM_NUM)
//{
//
//   // DEBUG_GPIO6_SET();
//
//    int32_t ADC_STEREO_MODE = 0;   //mono ADC
//
//    //(0) read from ringbuf and do ASRC, all situation:
//    // [fs<=48] or [fs =96], [performance level 0/1/2/3]
//  int16_t ii;
//  int64_t nco_temp_p;
//  int32_t temp_p2;
//  g_usb_adc_pcm_num = USB_ADC_PCM_NUM;
//  usb_read_firstxx_packet_thrsh = 8;
//  if(USB_ADC_ASRC_ENABLE && (usb_read_firstxx_packet > usb_read_firstxx_packet_thrsh/8))  //set USB_ADC_ASRC_ENABLE in audio_out.c, adc_start, adc_stop
//  {
//     if(USB_ADC_FS <= 8 ) // Fs <= 48k
//     {
//	    asrc_codec48k_readbuf(
//	    		   g_pAdcRingBufLeft  , //data format 32Q23, 24bits Audio
//	    		   g_pAdcRingBufLeft  , //data format 32Q23, 24bits Audio
//	      		   g_pAdcXinBufLeft    , //data format 32Q19 for asrc filter
//	       		   g_pAdcXinBufLeft    , //data format 32Q19 for asrc filter
//	       		   ASRC_ADC_RINGBUF_LEN_patch   ,
//	      		   asrc_adc_xinbuf_len    , //xin buffer length, according to asrc performance level
//	       		   &adc_nco_buf           ,
//	       		   &nco_temp_p           ,
//	       		   &adc_ringbuf_rp        ,
//	       		   &temp_p2                ,
//	       		    ADC_STEREO_MODE       );
//
//
//	 if(ASRC_ADC_PFORMANCE == 0)
//	  {
//		   asrc_codec_pfzero(
//					g_pAdcXinBufLeft     ,  // ringbuffer, data format 32Q19 !!!
//					pOUT_USB                ,  // outbuffer,  data format 32Q23
//					USB_ADC_PCM_NUM         ,
//					&adc_nco                ,
//					&adc_nco_buf            ,
//					adc_fs_ratio            ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//	   }
//	 else if(ASRC_ADC_PFORMANCE <= 2)  //1,2
//      {
//       	   asrc_codec_pfmid(
//        		    g_pAdcXinBufLeft     ,  // ringbuffer, data format 32Q19 !!!
//    	            pOUT_USB                ,  // outbuffer,  data format 32Q23
//    	            USB_ADC_PCM_NUM         ,
//                    &adc_nco                ,
//                    &adc_nco_buf            ,
//                    adc_fs_ratio            ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//       }
//
//     else
//       {
//       	  asrc_codec_pfhigh(
//        		    g_pAdcXinBufLeft     ,  // ringbuffer, data format 32Q19 !!!
//    	            pOUT_USB                ,  // outbuffer,  data format 32Q23
//    	            USB_ADC_PCM_NUM         ,
//                    &adc_nco                ,
//                    &adc_nco_buf            ,
//                     adc_fs_ratio           ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//       }
//
//  }
//  else    // Fs == 96k
//  {
//	  int32_t bitcut_en ;
//	  bitcut_en =  (ASRC_ADC_PFORMANCE <= 2); //0,1:pflow, 2:pfmid, 3:pfhigh
//
//	  asrc_codec96k_readbuf(
//	     		g_pAdcRingBufLeft  , //32Q23, 24bits audio
//	     		g_pAdcRingBufLeft  , //32Q23, 24bits audio
//	    		g_pAdcXinBufLeft    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
//	     		g_pAdcXinBufLeft   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
//	     		ASRC_ADC_RINGBUF_LEN_patch   ,
//	    		asrc_adc_xinbuf_len    , //xinbuffer length
//	     		&adc_nco_buf           ,
//	     		&nco_temp_p                ,
//	     		&adc_ringbuf_rp        ,
//	       	    &temp_p2                ,
//	     		bitcut_en              ,  // bitcut = 0 :high performance, 1: mid or low performance
//	     		ADC_STEREO_MODE        );
//
//
//	  if(ASRC_ADC_PFORMANCE <= 2) //2:pflow
//	  {
//		  asrc_codec96k_pfmid(
//		            g_pAdcXinBufLeft  ,  //  data format 32Q20 !!!
//		             pOUT_USB            ,  //  data format 32Q23, 24bits Audio
//		             USB_ADC_PCM_NUM     ,
//	                 &adc_nco            ,
//	                 &adc_nco_buf        ,
//	                  adc_fs_ratio       );//in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//		 }
//	  else                               //3:pfhigh
//		 {
//		  asrc_codec96k_pfhigh(             // high performance
//		            g_pAdcXinBufLeft  ,  //  data format 32Q23 !!!
//		             pOUT_USB            ,  //  data format 32Q23, 24bits Audio
//		             USB_ADC_PCM_NUM     ,
//	                 &adc_nco            ,
//	                 &adc_nco_buf        ,
//	                  adc_fs_ratio       );//in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//		  }
//    }
//
//    uint32_t ii;
//    for(ii=0;ii<USB_ADC_PCM_NUM;ii++)
//    {
//	    pOUT_USB[ii] = __nds32__clips(pOUT_USB[ii],23);
//    }
//
//    usb_packet_num += 1;
//  }
//
//  if( usb_read_firstxx_packet < usb_read_firstxx_packet_thrsh/8)  // when the firstxx usb packet
//  {
//	   for(ii=0;ii<USB_ADC_PCM_NUM;ii++)
//	    {
//		    pOUT_USB[ii] = 0;
//	    }
//
//   }
//
//  USB_ADC_EOF_FLAG = 1; // after the adc_ringbuf_rp updated in ASRC
// // DEBUG_GPIO6_CLR();
//}

void asrc_adc_Clean_RingBuf(void)
{
   pasrc_adc_ftabl->asrc_adc_Clean_RingBuf();
}
extern void Patch_asrc_adc_Clean_RingBuf(void);
//void Patch_asrc_adc_Clean_RingBuf(void)
//{
//	int32_t ii;
//	   adc_ringbuf_wp = ADC_REMAIN_NUM_TARGET;
//	   adc_ringbuf_rp = 0;
//	   adc_nco = 0;
//	   adc_nco_buf = 0;
//
//	   adc_packet_num = 0;
//	   usb_packet_num = 0;
//	 //  USB_ADC_START_FLAG = 0;
//	   for(ii=0;ii<ASRC_ADC_RINGBUF_LEN;ii++)
//	   {
//		   g_pAdcRingBufLeft[ii] = 0;
//	   }
//}

const asrc_adc_ftable_t new_asrc_adc_patch_ftable =
{
    .Asrc_Adc_Fs_Ppm_Init = Patch_Asrc_Adc_Fs_Ppm_Init,
    .estimation_adc_ppm_init = new_Patch_estimation_adc_ppm_init,
    .asrc_adc_fs_change_init = new_Patch_asrc_adc_fs_change_init,
    .estimate_adc_coarse_ppm = new_Patch_estimate_adc_coarse_ppm,
    .estimate_adc_fine_ppm = new_Patch_estimate_adc_fine_ppm,
    .asrc_adc_writebuf = new_Patch_asrc_adc_writebuf,
    .asrc_adc_top = Patch_asrc_adc_top,
   .asrc_adc_Clean_RingBuf = Patch_asrc_adc_Clean_RingBuf,
};

void new_asrc_adc_patch_init(void)
{
	pasrc_adc_ftabl = (asrc_adc_ftable_t *)&new_asrc_adc_patch_ftable;
}


