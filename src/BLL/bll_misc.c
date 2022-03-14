#include "hal_config.h"
#include "bll_config.h"
#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "suspend.h"
#include "user.h"
#include "earphone_insert_remove_detect.h"
#include "saradc.h"
#include "hss_det.h"
#include "soft_timer.h"
#include "chip_config.h"
#include "audio.h"
#include "asrc_adc_fs_ppm.h"
#include "bll_jack_sense.h"
#include "apple_key_detect.h"
#include "chipEffect_top.h"
#include "chipEftCfg.h"
#include "uswi_asrc.h"

extern void USB_UnConfigHeadSet();
extern void Earphone_Key_Detect_Start(void);
extern void Earphone_Key_Detect_Stop(void);
extern void Standby_Req_UnInit(void);
extern void asrc_adc_Clean_RingBuf(void);
extern void asrc_adc_fs_change_init(void);
extern void i2s_nco_rbuf_reset(void);
extern int8_t u8UsbReadFlag;
extern int8_t u8AdcWriteFlag;
extern int32_t start_adc_coarse_ppm;
extern void EnterExit_Standby(void);
void patch_Wait_DCNotch_Rampdown(void);

extern uint8_t g_ppm_range;
extern uint8_t AUDAC_MUTE_BY_PDDAC_EN;
extern uint8_t u8ADCSampParam, u8DACSampParam;
extern uint32_t u32DACFifoAddr;
extern uint32_t u32ADCFifoAddr;
extern int32_t start_coarse_ppm;
extern uint32_t rampup_step;
extern uint32_t rampdown_step;
//extern int32_t  ramp_signal;
extern volatile uint32_t new_ramp_signal;
extern volatile uint8_t IsRampDown;

extern volatile uint8_t AuOutIntFlg;
extern volatile uint8_t u8DACSampParamSet;
extern volatile uint8_t u8ADCSampParamSet;
extern volatile uint16_t rampcnt;
extern volatile uint8_t AuOutStartFlg;//AUDIO_OUT_Start()函数执行后会置1，AUDIO_OUT_Stop()函数执行后会清0
extern volatile uint8_t AuInStartFlg;
extern volatile uint8_t u8DacNeedStart;
extern volatile uint8_t DacMuteByPdFlg;
extern volatile uint8_t DacRecoverFromPdFlg;
extern volatile uint16_t gusRampUpCnt;
extern volatile uint8_t gucRampUpStart;
extern volatile uint8_t gucValidDataFlag;
extern volatile uint8_t g_u8DongleUsbRdFlag, g_u8DongleAdcWrtFlag, g_u8DongleI2sWrtFlag;
volatile uint8_t usbOutStopDebOk = 0;
volatile uint8_t usbOutStopDebFsm=0;

volatile int8_t g_ucAudioInStopFlag = TRUE;
volatile int8_t g_ucAudioOutStopFlag = TRUE;
// uint32_t jack_det_cnt;
uint8_t no_jack_insert_flag = 0;

volatile uint8_t g_ucResumeFlag = TRUE; //wake up from standby flag
volatile uint8_t ActiveStandbySt = 0; //0-> passive standby, 1-> active standby

int32_t DAC_DC_CALI_L = -10000;
int32_t DAC_DC_CALI_R = -10000;

extern int32_t usb_data[96];

#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
volatile uint8_t UsbSuspendSt = 0; //0-> usb active status, 1-> usb supend status
volatile uint8_t LowPowerSt = 0; //0-> not low power status, 1-> low power status
#endif

void Usb_Out_Sts_Deb(void)
{
    usbOutStopDebOk = 1;
    softtimer_stop(SOFT_TIMER5);
}

void new_ROM_Schedule(void)
{
    #ifdef OSC_CALI_BY_FSM_SRC_USBSOF
	if(0 == AuOutStartFlg)
	{
		if(0 == apb_osc_cali_ctrl0_osc_cali_code_flag_getf())
		{
			__nds32__nop();
			apb_clk_gen_clksel_cali_clk_sel_setf(0);			//0:frame_sync 1:i2s_mclk  2: xtal_clk  3:frame_sync
			apb_osc_cali_ctrl0_osc_cali_adjust_thrd_setf(2);	//0:500ppm  1:1000ppm 2:2000ppm  3:5000ppm
			apb_osc_cali_ctrl0_osc_cali_adjust_intv_setf(3);	//0:100ms  1:1000ppm 2:2000ppm  3:1000ms
			apb_osc_cali_ctrl0_osc_cali_code_flag_setf(1);		//0: osc cali code is provided by cpu; 1:by fsm
		}
	}
	else
	{
		if(1 == apb_osc_cali_ctrl0_osc_cali_code_flag_getf())
		{
			apb_osc_cali_ctrl0_osc_cali_code_flag_setf(0);		//0: osc cali code is provided by cpu; 1:by fsm
		}
	}
    #endif

    #ifdef JACK_SENSE_FUNC
    jacksense_detect_Schedule();
    #endif

    /// reduced power consumption, cannot be replaced
    Delay_Us(100);
#if SIDETONE_ALWAYS_ON_EN
#else
    //audio in process
    stUSB_Audio_Attr stAudioInAttr = {0};

    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_IN, &stAudioInAttr, sizeof(stUSB_Audio_Attr));
    if (((stAudioInAttr.u8Status == FALSE) && (g_ucAudioInStopFlag == FALSE))
            || ((1 == u8ADCSampParamSet) && (1 == AuInStartFlg)))
    {
        #ifdef APPLE_EARPHONE_KEY_SUPPORT
        if((APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG && g_pstConfig->FuncCfg.SupportAppleEarphone && (0 == g_ucButtType)) &&
            ((stAudioInAttr.u8Status == FALSE) && (g_ucAudioInStopFlag == FALSE)))
        {
            __nds32__nop();
            g_ucAudioInStopFlag = TRUE;
        }
        else
        #endif
        {
            AUDIO_IN_Stop(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
            asrc_adc_Clean_RingBuf();
            u8UsbReadFlag = 0;
            u8AdcWriteFlag = 0;
            g_ucAudioInStopFlag = TRUE;

            if (1 == u8ADCSampParamSet)
            {
                AUDIO_IN_Uninit(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
                AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);
                AUDIO_IN_Init(u32ADCFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
                u8ADCSampParamSet = 0;
            }   
        }
    }
    else if (((stAudioInAttr.u8Status == TRUE) && (g_ucAudioInStopFlag == TRUE)) //
    		|| ((g_ucResumeFlag == TRUE) && (g_pstConfig->FuncCfg.SupportAppleEarphone)))
    {
        start_adc_coarse_ppm = 1;
        AUDIO_IN_Stop(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
        asrc_adc_Clean_RingBuf();
        u8UsbReadFlag = 0;
        u8AdcWriteFlag = 0;
        g_ucAudioInStopFlag = TRUE;

        AUDIO_IN_Uninit(BIT0, 0);
        AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);
        AUDIO_IN_Init(u32ADCFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
        u8ADCSampParamSet = 0;
		HeadsetEffect_AudioInStart(g_st_pHeadsetEft);
        AUDIO_IN_Start(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
        g_ucAudioInStopFlag = FALSE;

        g_ucResumeFlag = FALSE;
    }

    //audio out process
    stUSB_Audio_Attr stAudioOutAttr = {0};
    Usb_Get_USB_Attr(0, USB_CALLBACK_AUDIO_OUT, &stAudioOutAttr, sizeof(stUSB_Audio_Attr));
#if (DAC_POWER_BREAK == 1)
    //当stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status=0，即USB停止的时候，并且g_ucAudioOutStopFlag没停时，进行rampdown关dac
    if (((stAudioOutAttr.u8Status == FALSE) && (g_ucAudioOutStopFlag == FALSE))
            || ((1 == u8DACSampParamSet) && (1 == AuOutStartFlg))) //DAC正常工作时AuOutStartFlg=1 g_ucAudioOutStopFlag=0 stAudioOutAttr.u8Status=1
    {
    	switch (usbOutStopDebFsm)
    	{
    		case 0:					  //start debounce
    			usbOutStopDebFsm = 1;
                usbOutStopDebOk = 0;
    			softtimer_start(SOFT_TIMER5, 1000, Usb_Out_Sts_Deb);
    			break;
    		case 1:					  //wait debounce finish, then STOP DAC   //每切换两次歌曲，就进入一下这个状态
    			if(usbOutStopDebOk)
    			{
                    usbOutStopDebOk = 0;
                    if ((pOtpInRam->PMOD != USB_DONGLE) || ((1 == u8DACSampParamSet) && (1 == AuOutStartFlg)))
                    {
                        patch_Wait_DCNotch_Rampdown();
                        AUDIO_OUT_Stop(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                        // asrc_Clean_RingBuf();
                        g_ucAudioOutStopFlag = TRUE;
                        if (1 == u8DACSampParamSet)
                        {
                            AUDIO_OUT_Uninit(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                            AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);
                            AUDIO_OUT_Init(u32DACFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                            u8DACSampParamSet = 0;
                        }
                        IsRampDown = 0;
                        gusRampUpCnt = 0;
                        gucRampUpStart = 0;
                        gucValidDataFlag = 0;
                        #if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
                        Patch_Sys_Suspend_for_AEVKWP();
                        LowPowerSt = 1;
                        #endif 
                    }
    				usbOutStopDebFsm = 0;
    			}
    			break;
    		// default://不会进入此状态，usbOutStopDebFsm要不为1要不为0
            //     usbOutStopDebOk =0;
            //     usbOutStopDebFsm =0;
    		// 	break;
    	}
    }
    //当audioOutStop的时候，stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status=1的时候，打开DAC
    else if ((stAudioOutAttr.u8Status == TRUE) && (g_ucAudioOutStopFlag == TRUE))
    {
        if (pOtpInRam->PMOD != USB_DONGLE)
        {
            #if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
            if(LowPowerSt == 1)
            {
                Patch_Sys_Resume_for_AEVKWP();
				LowPowerSt = 0;
            }
            #endif
            usbOutStopDebFsm = 0;       //
            ramp_nco = 32767;
            start_coarse_ppm = 1;
            g_st_AsrcI2S.start_coarse_ppm = 1;
            new_ramp_signal = 0;
            rampcnt = 0;
			HeadsetEffect_AudioOutStart(g_st_pHeadsetEft);
            AUDIO_OUT_Start(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
            // asrc_Clean_RingBuf();
            g_ucAudioOutStopFlag = FALSE;

        }
    }
    else if ((stAudioOutAttr.u8Status == TRUE) && (g_ucAudioOutStopFlag == FALSE))
    {
        //当usb aduio在interface AltSet设置为0后，usbOutStop进去debounce状态，此时如果interface AltSet又改为不是0，则退出debounce状态
        if((usbOutStopDebFsm == 1)&&(usbOutStopDebOk==0))
        {
        	usbOutStopDebFsm=0;
        }
    }
#else
        //当stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status=0，即USB停止的时候，并且g_ucAudioOutStopFlag没停时， 不关DAC
    if (((stAudioOutAttr.u8Status == FALSE) && (g_ucAudioOutStopFlag == FALSE))
            || ((1 == u8DACSampParamSet) && (1 == AuOutStartFlg))) //DAC正常工作时AuOutStartFlg=1 g_ucAudioOutStopFlag=0 stAudioOutAttr.u8Status=1
    {
        if ((pOtpInRam->PMOD != USB_DONGLE) || ((1 == u8DACSampParamSet) && (1 == AuOutStartFlg)))
        {
            // asrc_Clean_RingBuf();
            g_ucAudioOutStopFlag = TRUE;
            if (1 == u8DACSampParamSet)
            {
                patch_Wait_DCNotch_Rampdown();
                AUDIO_OUT_Stop(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                AUDIO_OUT_Uninit(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);
                AUDIO_OUT_Init(u32DACFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
                u8DACSampParamSet = 0;
                IsRampDown = 0;
                gusRampUpCnt = 0;
                gucRampUpStart = 0;
            }
            gucValidDataFlag = 0;
        }
    }
    //当audioOutStop的时候，stUsbAudio.stAudioAttr[USB_AUDIO_OUT].u8Status=1的时候，打开DAC
    else if ((stAudioOutAttr.u8Status == TRUE) && (g_ucAudioOutStopFlag == TRUE))
    {
        if (pOtpInRam->PMOD != USB_DONGLE)
        {
            start_coarse_ppm = 1;
            g_st_AsrcI2S.start_coarse_ppm = 1;
			HeadsetEffect_AudioOutStart(g_st_pHeadsetEft);
            g_ucAudioOutStopFlag = FALSE;
        }
    }
#endif
    if (u8DacNeedStart)//usb 传了300ms后打开DAC
    {
        AUDIO_OUT_Start(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
        u8DacNeedStart = 0;
    }

    if (1 == AUDAC_MUTE_BY_PDDAC_EN)
    {
        if (1 == DacMuteByPdFlg)
        {
            DacMuteByPdFlg = 0;
            Audio_DAC_normal_PowerOff();
        }
        else if (1 == DacRecoverFromPdFlg)
        {
            DacRecoverFromPdFlg = 0;
            Audio_DAC_PowerOn();
        }
    }
#endif
    #ifdef APPLE_EARPHONE_KEY_SUPPORT
    (void)Apple_KEY_decoder();//苹果按键检测
    #endif
}

#if SIDETONE_ALWAYS_ON_EN
void turnOnDac(void)
{
    ramp_nco = 32767;
    start_coarse_ppm = 1;
    g_st_AsrcI2S.start_coarse_ppm = 1;
    new_ramp_signal = 0;
    rampcnt = 0;
    AUDIO_OUT_Stop(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
    HeadsetEffect_AudioOutStart(g_st_pHeadsetEft);
    AUDIO_OUT_Start(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
    // asrc_Clean_RingBuf();
    g_ucAudioOutStopFlag = FALSE;
}
void turnOnAdc(void)
{
    start_adc_coarse_ppm = 1;
    AUDIO_IN_Stop(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
    asrc_adc_Clean_RingBuf();
    u8UsbReadFlag = 0;
    u8AdcWriteFlag = 0;
    AUDIO_IN_Uninit(BIT0, 0);
    AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);
    AUDIO_IN_Init(u32ADCFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
    u8ADCSampParamSet = 0;
    HeadsetEffect_AudioInStart(g_st_pHeadsetEft);
    AUDIO_IN_Start(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
    g_ucAudioInStopFlag = FALSE;
    g_ucResumeFlag = FALSE;
}
#endif

int16_t ramp_nco;
volatile int32_t cos_ramp_signal;
void patch_Wait_DCNotch_Rampdown(void)
{
    IsRampDown = 1;
    int32_t hold_ramp_signal = new_ramp_signal;
    int64_t temp_aa;

    while (1)
    {
        if (1 == AuOutIntFlg)
        {
            AuOutIntFlg = 0;
            //
            if (ramp_nco > 0)
            {
                if (new_ramp_signal >= rampdown_step)
                {
                    new_ramp_signal -= rampdown_step;
                }
                else
                {
                    new_ramp_signal = 0;
                }
#if(Deleate_Pop_standby == 0)
                ramp_nco = ramp_nco - 200; //40ms @ 160
#else
                ramp_nco = ramp_nco - 48;
#endif
                // cos_ramp_signal = (1- cos(theta))/2
                cos_ramp_signal = 32768;
                cos_ramp_signal -= nds32_cos_q15(ramp_nco);
                cos_ramp_signal >>= 1; //range [32768, 0]

                // temp_aa = cos_ramp_signal/32768*hold_ramp_signal
                temp_aa = cos_ramp_signal * hold_ramp_signal;
                temp_aa >>= 15;
                cos_ramp_signal = (int32_t) temp_aa;
            }
            else
            {
                new_ramp_signal = 0;
                ramp_nco = 32767;
                cos_ramp_signal = 0;
                break;
            }
        }
        if (0 == AuOutStartFlg)
        {
            new_ramp_signal = 0;
            ramp_nco = 32767;
            cos_ramp_signal = 0;
            break;
        }
        timer_delay_length(5, TIM_US);
    }

    new_ramp_signal = 0;
    ramp_nco = 32767;
    cos_ramp_signal = 0;
}

void USB_Audio_Config()
{
    uint32_t uFifoAddr = AUDIO_FIFO_ADDR;
	uint8_t* pUsbBuffer = (uint8_t*)RAM_USB_BUF_BASE_ADDR;

    Audio_bufinit();//
    AUDIO_Sampling_Set(u8ADCSampParam, u8DACSampParam);//设置adc和dacd的采样率为48KHz 0:48K  1:96K
//	dsp_parameter_init();

	g_ucButtType = 0;//按键类型//0->apple earphone key, 1->other earphone key
	memset(usb_data, 0, sizeof(usb_data));

	Usb_Init(pUsbBuffer,0);

    //define audio out
	#if AUDIO_OUT_SEL!=0 
        uint32_t ii;
        uint32_t tempaddr;
        uint32_t audac_fifo_leg;
        AUDIO_CallBack_Set(AUDIO_OUT ,Audio_Out_Speaker); 
        I2s_Para_Tran(&g_stI2sCfgSet_All[AUDIO_IN]);
        u32DACFifoAddr = uFifoAddr;
        tempaddr=uFifoAddr;
        uFifoAddr = AUDIO_OUT_Init(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
        #if SIDETONE_ALWAYS_ON_EN
            AUDIO_OUT_Stop(AUDIO_OUT_CHANNEL_SEL,AUDIO_OUT_I2SSEL);
        #endif
        audac_fifo_leg = uFifoAddr - tempaddr;
        for(ii=tempaddr;ii<(tempaddr+audac_fifo_leg/2);ii+=4)    //calibrate the DC offset
        {
            *(volatile uint32_t *)ii = DAC_DC_CALI_L;//6585;//-15310;//17797;    //pae demo 4#
        }
        for(ii=(tempaddr+audac_fifo_leg/2);ii<uFifoAddr;ii+=4)    //calibrate the DC offset
        {
            *(volatile uint32_t *)ii = DAC_DC_CALI_R;//6585;//-15310;//17797;    //pae demo 4#
        }
        uFifoAddr = Asrc_Dac_Fs_Ppm_Init(uFifoAddr);
        USB_SetCallback(USB_EVENT_AUDIO_OUT, USB_Out_Speaker);
    #endif

    #if AUDIO_IN_SEL!=0 //0:没有音频输入 1:adc输入 2:i2s输入 3:adc输入+i2s输入
        AUDIO_CallBack_Set(AUDIO_IN ,Audio_In_Speaker);
        I2s_Para_Tran(&g_stI2sCfgSet_All[AUDIO_IN]);
        u32ADCFifoAddr = uFifoAddr;
        uFifoAddr = AUDIO_IN_Init(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE, AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
        #if SIDETONE_ALWAYS_ON_EN
            AUDIO_IN_Stop(AUDIO_IN_CHANNEL_SEL,AUDIO_IN_I2SSEL);
        #endif
		#if (AUDIO_IN_STEREO == 1 && AUDIO_IN_SEL == 2)
        uFifoAddr = Pack_Asrc_In_Init(&g_st_AsrcI2SIN, uFifoAddr, 1, g_ppm_range, USB_ADC_FS);
        #else
        uFifoAddr = Asrc_Adc_Fs_Ppm_Init(uFifoAddr);     
        #endif
        USB_SetCallback(USB_EVENT_AUDIO_IN, USB_In_Speaker);   
    #endif
//	ramp_signal      = 0;
	
	asrc_Clean_RingBuf();
	estimation_ppm_init();
	estimation_ppm_relock_init();

    asrc_adc_Clean_RingBuf();
	estimation_adc_ppm_init();
	asrc_adc_fs_change_init();

    // pDSP = &g_pstConfig->DongleAudioReg;
	// dsp_reg_update_all();
//	dsp_buff_init(uFifoAddr,1,AUDIO_SAMPLE_BLOCK_SIZE*4);
    // uFifoAddr = dsp_buff_init_dongle(uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE*4);
    // dsp_effect_private_buff = (q31_t *)uFifoAddr;
    // uFifoAddr = dsp_buff_set_dongle (uFifoAddr, AUDIO_SAMPLE_BLOCK_SIZE*4);

    
    #if AUDIO_OUT_SEL!=0 
        AUDIO_OUT_Stop(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
    #endif
	
    #if AUDIO_IN_SEL!=0 //0:没有音频输入 1:adc输入 2:i2s输入 3:adc输入+i2s输入
        AUDIO_IN_Stop(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
    #endif

	g_st_pHeadsetEft = (ChipEffect_t *)uFifoAddr;
	uFifoAddr += sizeof(ChipEffect_t);
	uFifoAddr = HeadsetEffect_StruAlc(g_st_pHeadsetEft , uFifoAddr);//给音效分配ram
	dsp_EftRam_initial(uFifoAddr, 0x52000 - uFifoAddr);//建立内存池
	ChipEftReg_update_all(g_st_pHeadsetEft, &g_pstConfig->DSPRegAll, &(g_pstConfig->DSPRegAll));

    if((AUDIO_OUT_I2SSEL == 3 || AUDIO_OUT_I2SSEL == 1) ){
            I2S_AUDIO_CallBack_Set(I2S_AUDIO_OUT ,I2S_Audio_Out_Speaker);
            getAsrcComStartAddr(uFifoAddr);
            uFifoAddr = Pack_Asrc_In_Init(&g_st_AsrcI2SIN2Dac, uFifoAddr, 1, g_ppm_range, USB_ADC_FS);
            uFifoAddr = setAsrcComEndAddr(uFifoAddr);
    }

	USB_SetCallback(USB_EVENT_AUDIO_STATUS_CHANGE,USB_InterfaceSetting_adc_dac);
    Earphone_KWP_Detect_SetCallBack(EARPHONE_KWP_DETECT, (uint32_t)Earphone_Key_Detect_FuncHandle);
    #ifdef MIC_KEY_SUPPORT
	//Earphone_KWP_Detect  test initial
	Micin_Key_Det_Fsm_Init();	//hardware mode
	Earphone_Key_Detect_Thrd_Init(0);	//参数没用了
    #else
    Earphone_KWP_Detect_Uninit();
    #endif

    #ifndef JACK_SENSE_FUNC
        // apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf函数没有插入检测的时候一般不需要配置，外部硬件直接连接MICIN引脚
        // apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(1); //0:sleeve as mic input(micin引脚连接到sleeve引脚)  1:ring2 as mic input(micin引脚连接到ring2引脚)
        apb_audio_ctrl1_audio_pga_jack_pin_order_sts_setf(MIC_IN_PIN);		//according to pcb design: default 0:mic=vinn, 1: mic=vinp
    #endif
	stUsbAudio.u8AudioSamSelect = 0;
    Usb_Open(0);
}


void USB_Audio_UnConfig()
{
    Usb_Close(0);
    Usb_DeInit();
    #if AUDIO_IN_SEL!=0 //0:没有音频输入 1:adc输入 2:i2s输入 3:adc输入+i2s输入
        AUDIO_IN_Uninit(AUDIO_IN_CHANNEL_SEL, AUDIO_IN_I2SSEL);
    #endif
    #if AUDIO_OUT_SEL!=0 
        AUDIO_OUT_Uninit(AUDIO_OUT_CHANNEL_SEL, AUDIO_OUT_I2SSEL);
    #endif
}
