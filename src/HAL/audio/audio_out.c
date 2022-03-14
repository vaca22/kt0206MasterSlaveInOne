#include "audio_out.h"
#include "clk.h"
#include "timer.h"
#include "reg_timer.h"
#include "bll_config.h"
#include "chip_config.h"
#include "gpio_ctrl.h"
#include "chip_config.h"
#include "debug.h"
	extern uint8_t AUDIO_IN_I2SSEL;
	extern uint8_t AUDIO_OUT_I2SSEL;

typedef struct ftable_stru
{
	uint32_t (*AUDIO_OUT_Init)(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode);
	void 	 (*AUDIO_OUT_Uninit)(uint16_t usSignal, uint8_t ucMode);
	void 	 (*AUDIO_OUT_Start)(uint16_t usSignal, uint8_t ucMode);
	void 	 (*AUDIO_OUT_Stop)(uint16_t usSignal, uint8_t ucMode);
	void 	 (*AUDIO_OUT_Isr)(void);
}ftable_t;

ftable_t *audio_out_ftable;

extern volatile uint8_t AuOutStartFlg;//在rom的aduio_out.c里面定义的
volatile int32_t g_32HalDacDcOffsetL = 0;
volatile int32_t g_32HalDacDcOffsetR = 0;
extern volatile uint8_t u8DACSampParamSet;
/*************************************************************************************************/
/*																								 */
/*										DAC and i2s part 										 */
/*																								 */
/*************************************************************************************************/
/*
    uFifoBaseAddr	 : start address of Fifo
    usSample_num     : number of sampling
	usSignal		 : select DAC or I2S_Out
    ucMode			 : mode select:
    				   MASTER0
    				   SLAVE0
    				   MASTER1
    				   SLAVE1
*/
uint32_t AUDIO_OUT_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode)
{
	return audio_out_ftable->AUDIO_OUT_Init(uFifoBaseAddr, usSample_num, usSignal, ucMode);
}

//extern uint32_t rom_AUDIO_OUT_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode);

uint32_t new_patch_AUDIO_OUT_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode)
{
	uint32_t uFifoAddr = uFifoBaseAddr;
    uint16_t usSampleNum = usSample_num;
    g_stIoBufSys.Fifo_Out_Sample_Num = usSampleNum;
    g_stIoBufSys.IoBufOutFlag = 0;//鍙橀噺浠ｈ〃杈撳嚭閫氶亾寮�簡鍝簺锛孌AC0,DAC1鍙奍2S_OUT_L锛孖2S_OUT_R绛�
    g_stStartFlag.OutStartFlag = 0;//audio杈撳嚭start鍚庣疆1锛宻top鍚庢竻0
    AuOutStartFlg = 0;//璺焔_stStartFlag.OutStartFlag鍙橀噺闅鹃亾涓嶆槸涓�嚧鐨勫悧锛�

    g_stIoBufSys_I2S.Fifo_Out_Sample_Num = usSampleNum;
    g_stIoBufSys_I2S.IoBufOutFlag = 0;

    intc_enable_set(INTC_ID_IO_BUF, (intc_handler *)AUDIO_OUT_Isr);
    intc_enable_set(INTC_ID_IO_BUF_OUT, (intc_handler *)I2S_AUDIO_OUT_Isr);

	/* I2S_OUT part */
    if((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R))))
    {
    	/* reset two interfaces */
		apb_rst_gen_ctrl0_i_2s_rst_setf(0);

		/* I2S OUT L */
		// FIFO_THRE_X_REG_SET(FIFO_THRE_8, I2S_OUT_L, usSampleNum*2);
		FIFO_CONTROL_X_REG_SET_I2S(FIFO_CONTROL_8, I2S_OUT_L, usSampleNum, uFifoAddr);
		FIFO_CONTROL_X_REG_GET_I2S(FIFO_CONTROL_8, I2S_OUT_L);
//		FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_8, I2S_OUT_L);

		/* I2S OUT R */
//		if(CO_BIT(DAC0) != (usSignal & CO_BIT(DAC0)))//涓嶅紑dac鐨勬椂鍊欒缃甶2s鐨�
//		{
//			FIFO_THRE_X_REG_SET(FIFO_THRE_9, I2S_OUT_R, usSampleNum*2);
//		}
		FIFO_CONTROL_X_REG_SET_I2S(FIFO_CONTROL_9, I2S_OUT_R, usSampleNum, uFifoAddr);
		FIFO_CONTROL_X_REG_GET_I2S(FIFO_CONTROL_9, I2S_OUT_R);
//		FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_9, I2S_OUT_R);

		/* INT trigger by I2S R*/
		lm_fifo_config_out_sel_setf(9);
		/* select interface 0 */
		if((MASTER0 == ucMode) || (SLAVE0 == ucMode))
		{
		    apb_audio_0_cfg_audio_0_i_2s_tdm_en_setf(1);

		    /* select Master or Slave */
		    if(MASTER0 == ucMode)
		    {
		        apb_audio_0_cfg_audio_0_mas_slv_en_setf(1);
		    }
		    else
		    {
		        apb_audio_0_cfg_audio_0_mas_slv_en_setf(0);
		    }
		    apb_audio_0_cfg_audio_0_trans_recv_en_setf(1);

		    /* set format */
		    I2s_Cfg_Set(ucMode);
		}

		/* select interface 1 */
		if((MASTER1 == ucMode) || (SLAVE1 == ucMode))
		{
		    apb_audio_1_cfg_audio_1_i_2s_tdm_en_setf(1);

		    /* select Master or Slave */
		    if(MASTER1 == ucMode)
		    {
		        apb_audio_1_cfg_audio_1_mas_slv_en_setf(1);
		    }
		    else
		    {
		        apb_audio_1_cfg_audio_1_mas_slv_en_setf(0);
		    }
		    apb_audio_1_cfg_audio_1_trans_recv_en_setf(1);

		    /* set format */
		    I2s_Cfg_Set(ucMode);
		}

		g_stIoBufSys_I2S.IoBufOutFlag |= (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R));

		lm_fifo_config_2_out_thre_setf(usSampleNum - 1);
		lm_fifo_config_2_out_thre_en_setf(1);

    }

    /* DAC part */
    if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))))
    {
		apb_audio_ctrl0_audac_l_anagain_setf(g_pstConfig->PerfCfg.PgaDACL);    //L DAC analog gain:0x0E=1.5dB	0x0D=0dB
		apb_audio_ctrl0_audac_r_anagain_setf(g_pstConfig->PerfCfg.PgaDACR);    //R DAC analog gain: 0x0E=1.5dB	0x0D=0dB
		// apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(1);    //set charge pump vdd voltage as high rail
		// apb_power_pd_ctrl1_cg_cp_freq_sel_setf(2);     //set charge pump clk = 375kHz
		// apb_power_pd_ctrl1_cg_ldo_output_ctrl_setf(1); //1:1.75V 0:1.71V
		apb_dac_filt_config_left_dc_set_setf(1);       //SDM DC input level for left DAC:  2'b00 1/53, 2'b01 0
		apb_dac_filt_config_right_dc_set_setf(1);      //SDM DC input level for right DAC: 2'b00 1/53, 2'b01 0
    	apb_audio_ctrl1_audac_dir_isel_setf(1);

    	apb_rst_gen_ctrl0_sdm_mix_rst_setf(1);

	    /* DAC0 */
	    if(CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0)))
	    {
	    	apb_rst_gen_ctrl0_sdm_left_rst_setf(1);

	        FIFO_THRE_X_REG_SET(FIFO_THRE_6, DAC0, usSampleNum);
	        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_6, DAC0, usSampleNum, uFifoAddr);
	        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_6, DAC0);
//	        FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_6, DAC0);

	        g_stIoBufSys.IoBufOutFlag |= CO_BIT(DAC0);
	    }

		/* DAC1 */
	    if(CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1)))
	    {
	    	apb_rst_gen_ctrl0_sdm_right_rst_setf(1);

	        FIFO_THRE_X_REG_SET(FIFO_THRE_7, DAC1, usSampleNum);
	        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_7, DAC1, usSampleNum, uFifoAddr);
	        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_7, DAC1);
//	        FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_7, DAC1);

	        g_stIoBufSys.IoBufOutFlag |= CO_BIT(DAC1);
	    }
	    if(0==u8DACSampParamSet)
	    {
	    	Audio_DAC_normal_PowerOff();
	    }
	    else
	    {
	    	;
	    }
    	/* on FIFO-6 ~ FIFO-10 AE interrput */
        lm_fifo_config_fifo_int_en_2_setf(0x02);

    }

//    if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) ||
//       (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))) ||
//       ((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))))
//    {
//    	/* on FIFO-6 ~ FIFO-10 AE interrput */
//        lm_fifo_config_fifo_int_en_2_setf(0x02);
//    }

    timer_delay_length(255, TIM_US);

	return uFifoAddr;
}

uint32_t patch_AUDIO_OUT_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode)
{
	uint32_t uFifoAddr = uFifoBaseAddr;
    uint16_t usSampleNum = usSample_num;
    g_stIoBufSys.Fifo_Out_Sample_Num = usSampleNum;
    g_stIoBufSys.IoBufOutFlag = 0;//变量代表输出通道开了哪些，DAC0,DAC1及I2S_OUT_L，I2S_OUT_R等
    g_stStartFlag.OutStartFlag = 0;//audio输出start后置1，stop后清0
    AuOutStartFlg = 0;//跟g_stStartFlag.OutStartFlag变量难道不是一致的吗？

    intc_enable_set(INTC_ID_IO_BUF, (intc_handler *)AUDIO_OUT_Isr);

	/* I2S_OUT part */
    if((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R))))
    {
    	/* reset two interfaces */
		apb_rst_gen_ctrl0_i_2s_rst_setf(0);

		/* I2S OUT L */
		// FIFO_THRE_X_REG_SET(FIFO_THRE_8, I2S_OUT_L, usSampleNum*2);
		FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_8, I2S_OUT_L, usSampleNum*2, uFifoAddr);
		FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_8, I2S_OUT_L);
		FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_8, I2S_OUT_L);

		/* I2S OUT R */
		// if(CO_BIT(DAC0) != (usSignal & CO_BIT(DAC0)))//不开dac的时候设置i2s的
		{
			FIFO_THRE_X_REG_SET(FIFO_THRE_9, I2S_OUT_R, usSampleNum);
		}
		FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_9, I2S_OUT_R, usSampleNum*2, uFifoAddr);
		FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_9, I2S_OUT_R);
		FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_9, I2S_OUT_R);

		/* select interface 0 */
		if((MASTER0 == ucMode) || (SLAVE0 == ucMode))
		{
		    apb_audio_0_cfg_audio_0_i_2s_tdm_en_setf(1);

		    /* select Master or Slave */
		    if(MASTER0 == ucMode)
		    {
		        apb_audio_0_cfg_audio_0_mas_slv_en_setf(1);
		    }
		    else
		    {
		        apb_audio_0_cfg_audio_0_mas_slv_en_setf(0);
		    }
		    apb_audio_0_cfg_audio_0_trans_recv_en_setf(1);

		    /* set format */
		    I2s_Cfg_Set(ucMode);
		}

		/* select interface 1 */
		if((MASTER1 == ucMode) || (SLAVE1 == ucMode))
		{
		    apb_audio_1_cfg_audio_1_i_2s_tdm_en_setf(1);

		    /* select Master or Slave */
		    if(MASTER1 == ucMode)
		    {
		        apb_audio_1_cfg_audio_1_mas_slv_en_setf(1);
		    }
		    else
		    {
		        apb_audio_1_cfg_audio_1_mas_slv_en_setf(0);
		    }
		    apb_audio_1_cfg_audio_1_trans_recv_en_setf(1);

		    /* set format */
		    I2s_Cfg_Set(ucMode);
		}

		g_stIoBufSys.IoBufOutFlag |= (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R));
    }

    /* DAC part */
    if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))))
    {
		apb_audio_ctrl0_audac_l_anagain_setf(g_pstConfig->PerfCfg.PgaDACL);    //L DAC analog gain:0x0E=1.5dB	0x0D=0dB
		apb_audio_ctrl0_audac_r_anagain_setf(g_pstConfig->PerfCfg.PgaDACR);    //R DAC analog gain: 0x0E=1.5dB	0x0D=0dB
		// apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(1);    //set charge pump vdd voltage as high rail
		// apb_power_pd_ctrl1_cg_cp_freq_sel_setf(2);     //set charge pump clk = 375kHz
		// apb_power_pd_ctrl1_cg_ldo_output_ctrl_setf(1); //1:1.75V 0:1.71V
		apb_dac_filt_config_left_dc_set_setf(1);       //SDM DC input level for left DAC:  2'b00 1/53, 2'b01 0
		apb_dac_filt_config_right_dc_set_setf(1);      //SDM DC input level for right DAC: 2'b00 1/53, 2'b01 0
    	apb_audio_ctrl1_audac_dir_isel_setf(1);

    	apb_rst_gen_ctrl0_sdm_mix_rst_setf(1);

	    /* DAC0 */
	    if(CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0)))
	    {
	    	apb_rst_gen_ctrl0_sdm_left_rst_setf(1);

	        FIFO_THRE_X_REG_SET(FIFO_THRE_6, DAC0, usSampleNum);
	        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_6, DAC0, usSampleNum*2, uFifoAddr);
	        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_6, DAC0);
	        FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_6, DAC0);

	        g_stIoBufSys.IoBufOutFlag |= CO_BIT(DAC0);
	    }

		/* DAC1 */
	    if(CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1)))
	    {
	    	apb_rst_gen_ctrl0_sdm_right_rst_setf(1);

	        // FIFO_THRE_X_REG_SET(FIFO_THRE_7, DAC1, usSampleNum*2);
	        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_7, DAC1, usSampleNum*2, uFifoAddr);
	        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_7, DAC1);
	        FIFO_WRITE_DATA_AND_WR(FIFO_POINTER_7, DAC1);

	        g_stIoBufSys.IoBufOutFlag |= CO_BIT(DAC1);
	    }
	    if(0==u8DACSampParamSet)
	    {
	    	Audio_DAC_normal_PowerOff();
	    }
	    else
	    {
	    	;
	    }

    }

    if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) ||
       (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))) ||
       ((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))))
    {
    	/* on FIFO-6 ~ FIFO-10 AE interrput */
        lm_fifo_config_fifo_int_en_2_setf(0x02);
    }

    timer_delay_length(255, TIM_US);

	return uFifoAddr;
}


void AUDIO_OUT_Uninit(uint16_t usSignal, uint8_t ucMode)
{
	USER_DBG_OUT("==== AUDIO_OUT_Uninit...\n");	//yuan++
	audio_out_ftable->AUDIO_OUT_Uninit(usSignal, ucMode);
}

extern void rom_AUDIO_OUT_Uninit(uint16_t usSignal, uint8_t ucMode);

void AUDIO_OUT_Start(uint16_t usSignal, uint8_t ucMode)
{
	USER_DBG_OUT("==== AUDIO_OUT_Start...\n");	//yuan++
	audio_out_ftable->AUDIO_OUT_Start(usSignal, ucMode);
}

static uint8_t dacFirstStart=1;
//extern void rom_AUDIO_OUT_Start(uint16_t usSignal, uint8_t ucMode);
void patch_AUDIO_OUT_Start(uint16_t usSignal, uint8_t ucMode)
{
	if(0 == AuOutStartFlg)
	{
		dacFirstStart=1;
		if((CO_BIT(DAC0) == (usSignal & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (usSignal & CO_BIT(DAC1))))
		{
#if(Deleate_Pop_standby == 0)
			Audio_DAC_PowerOn();
#endif
		    uint32_t temp = apb_clk_gen_clken_get();
		    temp &= 0xFFCFFFFF;
		    temp |= (0x3 << 20);
		    apb_clk_gen_clken_set(temp);
		    timer_delay_length(1, TIM_MS);
		    apb_dac_filt_config_left_sync_bit_setf(1);
		    apb_dac_filt_config_right_sync_bit_setf(1);
		    apb_rst_gen_ctrl0_sdm_left_rst_setf(0);
		    apb_rst_gen_ctrl0_sdm_right_rst_setf(0);

			apb_clk_gen_clken_clk_dac_en_setf(1);
			apb_rst_gen_ctrl0_sdm_mix_rst_setf(0);

			lm_fifo_status_get(6);
	        lm_fifo_status_get(7);
	        lm_fifo_control_fifo_int_en_setf(6, 1);
	        lm_fifo_control_fifo_int_en_setf(7, 1);

		    lm_fifo_control_fifo_en_setf(6, 1);
		    lm_fifo_control_fifo_en_setf(7, 1);
#if(Deleate_Pop_standby)
		    Audio_DAC_PowerOn();
#endif
		}

	    if((CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)) == (usSignal & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R))))
		{
			lm_fifo_control_fifo_en_setf(8, 1);
		    lm_fifo_control_fifo_en_setf(9, 1);

		    if((MASTER0 == ucMode) || (SLAVE0 == ucMode))
		    {
		        if(MASTER0 == ucMode)
		        {
		            apb_clk_gen_clken_i_2sm_0_en_setf(1);
		        }
		        else
		        {
		            apb_clk_gen_clken_i_2ss_0_en_setf(1);
		        }

		        apb_audio_0_cfg_audio_0_en_setf(1);
		    }

		    if((MASTER1 == ucMode) || (SLAVE1 == ucMode))
		    {
		        if(MASTER1 == ucMode)
		        {
		            apb_clk_gen_clken_i_2sm_1_en_setf(1);
		        }
		        else
		        {
		            apb_clk_gen_clken_i_2ss_1_en_setf(1);
		        }

		        apb_audio_1_cfg_audio_1_en_setf(1);
		    }
		}
		g_stStartFlag.OutStartFlag = 1;
		AuOutStartFlg = 1;
	}
}

void AUDIO_OUT_Stop(uint16_t usSignal, uint8_t ucMode)
{
	audio_out_ftable->AUDIO_OUT_Stop(usSignal, ucMode);
}

extern void rom_AUDIO_OUT_Stop(uint16_t usSignal, uint8_t ucMode);


volatile uint16_t g_usIoBufOutFlag;
volatile uint16_t gusRampUpCnt = 0;
volatile uint8_t gucRampUpStart = 0;
extern volatile int32_t cos_ramp_signal;
extern volatile uint32_t new_ramp_signal;
extern volatile uint8_t gucValidDataFlag;
uint16_t g_usIoBufOutFlag_i2s;

void AUDIO_OUT_Isr(void)
{
	audio_out_ftable->AUDIO_OUT_Isr();
}

//extern void rom_AUDIO_OUT_Isr(void);

void new_patch_AUDIO_OUT_Isr(void)
{
    // GPIO_FuncSet(GPIO9,GPIO_DigOutput1);//璁剧疆GPIO杈撳嚭浣�
	const uint16_t sampleNumbersBytes= AUDIO_SAMPLE_BLOCK_SIZE<<2;//涓�釜閲囨牱鐐规槸4bytes 16*4=64
	const uint16_t remainderNumbersBytes=g_stIoBufSys.Fifo_Len[DAC0]-sampleNumbersBytes;
	if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC0))
    {
		if(lm_fifo_status_data_num_getf(6) <= remainderNumbersBytes)
        {
            g_usIoBufOutFlag |= CO_BIT(DAC0);
        }
    }

    if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC1))
    {
		if(lm_fifo_status_data_num_getf(7) <= remainderNumbersBytes)
        {
            g_usIoBufOutFlag |= CO_BIT(DAC1);
        }
    }

	if(g_stIoBufSys.IoBufOutFlag == g_usIoBufOutFlag)
	{
        uint16_t usDac0Wr;
        uint16_t usDac1Wr;
        uint16_t usI2SOUT0Wr=0;
        uint16_t usI2SOUT1Wr=0;

        usDac0Wr = lm_fifo_pointer_wr_ptr_getf(6);

        usDac1Wr = lm_fifo_pointer_wr_ptr_getf(7);

        g_stIoBufSys.audio_out_handler(			//璋冪敤鐨勬槸 Audio_Out_Speaker 鍑芥暟
                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC0] + usDac0Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC1] + usDac1Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_OUT_L] + usI2SOUT0Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_OUT_R] + usI2SOUT1Wr),
                   g_stIoBufSys.Fifo_Out_Sample_Num,
                   g_usIoBufOutFlag);

        switch(pOtpInRam->PMOD)
        {
            case USB_TYPEC_TO_3P5:
            case USB_TYPEC_HEADSET:
            case USB_TYPEC_HEADPHONE:
            {
				 /* ramp up start */
				if((CO_BIT(DAC0) == (g_usIoBufOutFlag & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (g_usIoBufOutFlag & CO_BIT(DAC1))))
				{
					int cnt;
					uint16_t usSampleNum = g_stIoBufSys.Fifo_Out_Sample_Num;
					int32_t *pAddr0 = (int32_t *)(g_stIoBufSys.Fifo_Base[DAC0] + usDac0Wr);
					int32_t *pAddr1 = (int32_t *)(g_stIoBufSys.Fifo_Base[DAC1] + usDac1Wr);

					if(gucValidDataFlag)
					{
						gucRampUpStart = 1;
					}
					else
					{
						gucRampUpStart = 0;
						gusRampUpCnt   = 0;
						nds32_set_q31(g_32HalDacDcOffsetL, pAddr0, usSampleNum);
						nds32_set_q31(g_32HalDacDcOffsetR, pAddr1, usSampleNum);
					}

					if(gucRampUpStart)
					{
						if(gusRampUpCnt < 25)
						{
							for(cnt=0; cnt<usSampleNum; cnt++)
							{
								pAddr0[cnt] = (pAddr0[cnt] - g_32HalDacDcOffsetL) / (usSampleNum * 25) * (cnt + usSampleNum * gusRampUpCnt) + g_32HalDacDcOffsetL;
								pAddr1[cnt] = (pAddr1[cnt] - g_32HalDacDcOffsetR) / (usSampleNum * 25) * (cnt + usSampleNum * gusRampUpCnt) + g_32HalDacDcOffsetR;
							}
							gusRampUpCnt++;
						}
					}
				}/* ramp up end */
				break;
            }
        	default:
        		break;
        }


        //output
        if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC0))
        {
			usDac0Wr += sampleNumbersBytes;
			if(usDac0Wr >= (g_stIoBufSys.Fifo_Len[DAC0]))
			{
				usDac0Wr = 0;
			}
            lm_fifo_pointer_wr_ptr_setf(6, usDac0Wr);
        }

        if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC1))
        {
			usDac1Wr += sampleNumbersBytes;
			if(usDac1Wr >= (g_stIoBufSys.Fifo_Len[DAC1]))
			{
				usDac1Wr = 0;
			}
            lm_fifo_pointer_wr_ptr_setf(7, usDac1Wr);
        }
	    g_usIoBufOutFlag = 0;
	}
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 6 * 4);
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 7 * 4);
    // GPIO_FuncSet(GPIO9,GPIO_DigOutput0);//璁剧疆GPIO杈撳嚭浣�
}
void I2S_AUDIO_OUT_Isr(void)
{
	//GPIO_FuncSet(GPIO9,GPIO_DigOutput1);
	const uint16_t sampleNumbersBytes= AUDIO_SAMPLE_BLOCK_SIZE<<2;//涓�釜閲囨牱鐐规槸4bytes 16*4=64
	const uint16_t remainderNumbersBytes=g_stIoBufSys_I2S.Fifo_Len_Half[I2S_OUT_L];
	    if(g_stIoBufSys_I2S.IoBufOutFlag & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))
	    {
			if(lm_fifo_status_data_num_getf(8) <= remainderNumbersBytes)
	        {
	            __nds32__nop();
	        }

	        if(lm_fifo_status_data_num_getf(9) <= remainderNumbersBytes)
	        {
	        	g_usIoBufOutFlag_i2s |= CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R);
	        }
	    }
		if(g_stIoBufSys_I2S.IoBufOutFlag == g_usIoBufOutFlag_i2s)
		{
	        uint16_t usDac0Wr=0;
	        uint16_t usDac1Wr=0;
	        uint16_t usI2SOUT0Wr;
	        uint16_t usI2SOUT1Wr;

	        usI2SOUT0Wr = lm_fifo_pointer_wr_ptr_getf(8);

	        usI2SOUT1Wr = lm_fifo_pointer_wr_ptr_getf(9);

	        g_stIoBufSys_I2S.audio_out_handler(			//璋冪敤鐨勬槸 Audio_Out_Speaker 鍑芥暟
	                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC0] + usDac0Wr),
	                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC1] + usDac1Wr),
	                   (q31_t *)(g_stIoBufSys_I2S.Fifo_Base[I2S_OUT_L] + usI2SOUT0Wr),
	                   (q31_t *)(g_stIoBufSys_I2S.Fifo_Base[I2S_OUT_R] + usI2SOUT1Wr),
	                   g_stIoBufSys_I2S.Fifo_Out_Sample_Num,
	                   g_usIoBufOutFlag_i2s);
	        //output
	        if(g_stIoBufSys_I2S.IoBufOutFlag & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))
	        {
	            usI2SOUT0Wr += sampleNumbersBytes;
	            if(usI2SOUT0Wr >= (g_stIoBufSys_I2S.Fifo_Len[I2S_OUT_L]))
	            {
	                usI2SOUT0Wr = 0;
	            }
	            lm_fifo_pointer_wr_ptr_setf(8, usI2SOUT0Wr);

	            usI2SOUT1Wr += sampleNumbersBytes;
	            if(usI2SOUT1Wr >= (g_stIoBufSys_I2S.Fifo_Len[I2S_OUT_R]))
	            {
	                usI2SOUT1Wr = 0;
	            }
	            lm_fifo_pointer_wr_ptr_setf(9, usI2SOUT1Wr);
	        }
		    g_usIoBufOutFlag_i2s = 0;
		}
		//GPIO_FuncSet(GPIO9,GPIO_DigOutput0);
		REG_PL_RD(LM_FIFO_STATUS_ADDR + 8 * 4);
		REG_PL_RD(LM_FIFO_STATUS_ADDR + 9 * 4);
}

void patch_AUDIO_OUT_Isr(void)
{
    // GPIO_FuncSet(GPIO9,GPIO_DigOutput1);//设置GPIO输出低
	const uint16_t sampleNumbersBytes= AUDIO_SAMPLE_BLOCK_SIZE<<2;//一个采样点是4bytes 16*4=64
	const uint16_t remainderNumbersBytes=g_stIoBufSys.Fifo_Len[DAC0]-sampleNumbersBytes;
	if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC0))
    {
		if(lm_fifo_status_data_num_getf(6) <= remainderNumbersBytes)
        {
            g_usIoBufOutFlag |= CO_BIT(DAC0);
        }
    }

    if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC1))
    {
		if(lm_fifo_status_data_num_getf(7) <= remainderNumbersBytes)
        {
            g_usIoBufOutFlag |= CO_BIT(DAC1);
        }
    }

    if(g_stIoBufSys.IoBufOutFlag & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))
    {
		if(lm_fifo_status_data_num_getf(8) <= remainderNumbersBytes)
        {
            __nds32__nop();
        }

        if(lm_fifo_status_data_num_getf(9) <= remainderNumbersBytes)
        {
            g_usIoBufOutFlag |= CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R);
        }
    }

	if(g_stIoBufSys.IoBufOutFlag == g_usIoBufOutFlag)
	{
        uint16_t usDac0Wr;
        uint16_t usDac1Wr;
        uint16_t usI2SOUT0Wr;
        uint16_t usI2SOUT1Wr;

		if(dacFirstStart==1)
		{
			dacFirstStart=0;
			uint16_t temp1=lm_fifo_status_data_num_getf(6);
			uint16_t temp2=lm_fifo_status_data_num_getf(8);
			if((temp1<sampleNumbersBytes)||(temp1>remainderNumbersBytes))
			{
				usDac0Wr = lm_fifo_pointer_wr_ptr_getf(6);
				usDac0Wr += (sampleNumbersBytes<<1);
				if(usDac0Wr >= (g_stIoBufSys.Fifo_Len[DAC0]))
				{
					usDac0Wr -= (g_stIoBufSys.Fifo_Len[DAC0]);
				}
				lm_fifo_pointer_wr_ptr_setf(6, usDac0Wr);
				lm_fifo_pointer_wr_ptr_setf(7, usDac0Wr);
			}
			if((temp2<sampleNumbersBytes)||(temp2>remainderNumbersBytes))
			{
				usI2SOUT0Wr = lm_fifo_pointer_wr_ptr_getf(8);
				usI2SOUT0Wr += (sampleNumbersBytes<<1);
				if(usI2SOUT0Wr >= (g_stIoBufSys.Fifo_Len[I2S_OUT_L]))
				{
					usI2SOUT0Wr -= (g_stIoBufSys.Fifo_Len[I2S_OUT_L]);
				}
				lm_fifo_pointer_wr_ptr_setf(8, usI2SOUT0Wr);
				lm_fifo_pointer_wr_ptr_setf(9, usI2SOUT0Wr);
			}
		}

        usDac0Wr = lm_fifo_pointer_wr_ptr_getf(6);

        usDac1Wr = lm_fifo_pointer_wr_ptr_getf(7);

        usI2SOUT0Wr = lm_fifo_pointer_wr_ptr_getf(8);

        usI2SOUT1Wr = lm_fifo_pointer_wr_ptr_getf(9);

        g_stIoBufSys.audio_out_handler(			//调用的是 Audio_Out_Speaker 函数
                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC0] + usDac0Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[DAC1] + usDac1Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_OUT_L] + usI2SOUT0Wr),
                   (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_OUT_R] + usI2SOUT1Wr),
                   g_stIoBufSys.Fifo_Out_Sample_Num,
                   g_usIoBufOutFlag);

        switch(pOtpInRam->PMOD)
        {
            case USB_TYPEC_TO_3P5:
            case USB_TYPEC_HEADSET:
            case USB_TYPEC_HEADPHONE:
            {
				 /* ramp up start */
				if((CO_BIT(DAC0) == (g_usIoBufOutFlag & CO_BIT(DAC0))) || (CO_BIT(DAC1) == (g_usIoBufOutFlag & CO_BIT(DAC1))))
				{
					int cnt;
					uint16_t usSampleNum = g_stIoBufSys.Fifo_Out_Sample_Num;
					int32_t *pAddr0 = (int32_t *)(g_stIoBufSys.Fifo_Base[DAC0] + usDac0Wr);
					int32_t *pAddr1 = (int32_t *)(g_stIoBufSys.Fifo_Base[DAC1] + usDac1Wr);

					if(gucValidDataFlag)
					{
						gucRampUpStart = 1;
					}
					else
					{
						gucRampUpStart = 0;
						gusRampUpCnt   = 0;
						nds32_set_q31(g_32HalDacDcOffsetL, pAddr0, usSampleNum);
						nds32_set_q31(g_32HalDacDcOffsetR, pAddr1, usSampleNum);
					}

					if(gucRampUpStart)
					{
						if(gusRampUpCnt < 25)
						{
							for(cnt=0; cnt<usSampleNum; cnt++)
							{
								pAddr0[cnt] = (pAddr0[cnt] - g_32HalDacDcOffsetL) / (usSampleNum * 25) * (cnt + usSampleNum * gusRampUpCnt) + g_32HalDacDcOffsetL;
								pAddr1[cnt] = (pAddr1[cnt] - g_32HalDacDcOffsetR) / (usSampleNum * 25) * (cnt + usSampleNum * gusRampUpCnt) + g_32HalDacDcOffsetR;
							}
							gusRampUpCnt++;
						}
					}
				}/* ramp up end */
				break;
            }
        	default:
        		break;
        }


        //output
        if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC0))
        {
			usDac0Wr += sampleNumbersBytes;
			if(usDac0Wr >= (g_stIoBufSys.Fifo_Len[DAC0]))
			{
				usDac0Wr = 0;
			}
            lm_fifo_pointer_wr_ptr_setf(6, usDac0Wr);
        }

        if(g_stIoBufSys.IoBufOutFlag & CO_BIT(DAC1))
        {
			usDac1Wr += sampleNumbersBytes;
			if(usDac1Wr >= (g_stIoBufSys.Fifo_Len[DAC1]))
			{
				usDac1Wr = 0;
			}
            lm_fifo_pointer_wr_ptr_setf(7, usDac1Wr);
        }

        if(g_stIoBufSys.IoBufOutFlag & (CO_BIT(I2S_OUT_L)|CO_BIT(I2S_OUT_R)))
        {
            usI2SOUT0Wr += sampleNumbersBytes;
            if(usI2SOUT0Wr >= (g_stIoBufSys.Fifo_Len[I2S_OUT_L]))
            {
                usI2SOUT0Wr = 0;
            }
            lm_fifo_pointer_wr_ptr_setf(8, usI2SOUT0Wr);

            usI2SOUT1Wr += sampleNumbersBytes;
            if(usI2SOUT1Wr >= (g_stIoBufSys.Fifo_Len[I2S_OUT_R]))
            {
                usI2SOUT1Wr = 0;
            }
            lm_fifo_pointer_wr_ptr_setf(9, usI2SOUT1Wr);
        }
	    g_usIoBufOutFlag = 0;
	}
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 8 * 4);
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 9 * 4);
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 6 * 4);
	REG_PL_RD(LM_FIFO_STATUS_ADDR + 7 * 4);
    // GPIO_FuncSet(GPIO9,GPIO_DigOutput0);//设置GPIO输出低
}


const ftable_t patch_audio_out_fi_tableOut3 =
{
	.AUDIO_OUT_Init	  = new_patch_AUDIO_OUT_Init,
	.AUDIO_OUT_Uninit = rom_AUDIO_OUT_Uninit,
	.AUDIO_OUT_Start  = patch_AUDIO_OUT_Start,
	.AUDIO_OUT_Stop   = rom_AUDIO_OUT_Stop,
	.AUDIO_OUT_Isr	  = new_patch_AUDIO_OUT_Isr,
};

const ftable_t patch_audio_out_fi_table =
{
	.AUDIO_OUT_Init	  = patch_AUDIO_OUT_Init,
	.AUDIO_OUT_Uninit = rom_AUDIO_OUT_Uninit,
	.AUDIO_OUT_Start  = patch_AUDIO_OUT_Start,
	.AUDIO_OUT_Stop   = rom_AUDIO_OUT_Stop,
	.AUDIO_OUT_Isr	  = patch_AUDIO_OUT_Isr,
};

void new_audio_out_patch_init(void)
{
	if (AUDIO_OUT_I2SSEL == 3){
		audio_out_ftable = (ftable_t *)&patch_audio_out_fi_tableOut3;
	}else{
		audio_out_ftable = (ftable_t *)&patch_audio_out_fi_table;
	}

}
