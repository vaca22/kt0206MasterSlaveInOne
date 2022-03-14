#include "hal_config.h"
#include "bll_config.h"
#include "timer.h"
#include "audio_in.h"
#include "chip_config.h"
#include "gpio_ctrl.h"


typedef struct ftable_stru
{
    uint32_t (*AUDIO_IN_Init)(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode);
    void     (*AUDIO_IN_Uninit)(uint16_t usSignal, uint8_t ucMode);
    void     (*AUDIO_IN_Start)(uint16_t usSignal, uint8_t ucMode);
    void     (*AUDIO_IN_Stop)(uint16_t usSignal, uint8_t ucMode);
    void     (*AUDIO_IN_Isr)(void);
} ftable_t;

ftable_t *audio_in_ftable;
volatile uint8_t AuInStartFlg = 0;
/*************************************************************************************************/
/*                                                                                               */
/*                                      ADC and i2s part                                         */
/*                                                                                               */
/*************************************************************************************************/
/*
    uFifoBaseAddr   : start address of Fifo
    usSample_num    : number of sampling
    usSignal        : select ADC or I2S_In
    ucMode          : mode select
*/
uint32_t AUDIO_IN_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode)
{
    return audio_in_ftable->AUDIO_IN_Init(uFifoBaseAddr, usSample_num, usSignal, ucMode);
}
uint32_t patch_AUDIO_IN_Init(uint32_t uFifoBaseAddr, uint16_t usSample_num, uint16_t usSignal, uint8_t ucMode)
{
    uint32_t uFifoAddr = uFifoBaseAddr;
    uint16_t usSampleNum = usSample_num;
    g_stIoBufSys.Fifo_In_Sample_Num = usSampleNum;
    g_stIoBufSys.IoBufInFlag = 0;
    g_stStartFlag.InStartFlag = 0;
    AuInStartFlg = 0;

    /* I2S_In part */
    if ((CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R))))
    {
        apb_rst_gen_ctrl0_i_2s_rst_setf(0);

        /* I2S IN L */
        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_4, I2S_IN_L, usSampleNum*2, uFifoAddr);
        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_4, I2S_IN_L);

        /* I2S IN R */
        FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_5, I2S_IN_R, usSampleNum*2, uFifoAddr);
        FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_5, I2S_IN_R);

        /* I2S IN L */
        lm_fifo_config_in_sel_setf(4);

        /* select interface 0 */
        if ((MASTER0 == ucMode) || (SLAVE0 == ucMode))
        {
            apb_audio_0_cfg_audio_0_i_2s_tdm_en_setf(1);

            /* select Master or Slave */
            if (MASTER0 == ucMode)
            {
                apb_audio_0_cfg_audio_0_mas_slv_en_setf(1);
            }
            else
            {
                apb_audio_0_cfg_audio_0_mas_slv_en_setf(0);
            }
            apb_audio_0_cfg_audio_0_trans_recv_en_setf(0);

            /* set format */
            I2s_Cfg_Set(ucMode);
        }

        /* select interface 1 */
        if ((MASTER1 == ucMode) || (SLAVE1 == ucMode))
        {
            apb_audio_1_cfg_audio_1_i_2s_tdm_en_setf(1);

            /* select Master or Slave */
            if (MASTER1 == ucMode)
            {
                apb_audio_1_cfg_audio_1_mas_slv_en_setf(1);
            }
            else
            {
                apb_audio_1_cfg_audio_1_mas_slv_en_setf(0);
            }
            apb_audio_1_cfg_audio_1_trans_recv_en_setf(0);

            /* set format */
            I2s_Cfg_Set(ucMode);
        }

        g_stIoBufSys.IoBufInFlag |= (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R));
    }

    /* ADC part */
    if ((CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0))))
    {
        apb_rst_gen_ctrl0_adc_rst_setf(0);

        if (CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0)))
        {
            FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_0, ADC0, usSampleNum*2, uFifoAddr);
            FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_0, ADC0);

            if (g_pstConfig->FuncCfg.SupportAppleEarphone) /* support apple earphone*/
            {
                FIFO_CONTROL_X_REG_SET(FIFO_CONTROL_1, ADC0, usSampleNum * 32, uFifoAddr);
                FIFO_CONTROL_X_REG_GET(FIFO_CONTROL_1, ADC1);
            }

            /* ADC0 */
            lm_fifo_config_in_sel_setf(0);

            apb_adc_filt_config_0_dcnotcg_bw_setf(2) ;//0->228Hz, 2->57Hz,3->28Hz, 4->14
            apb_adc_filt_config_0_sync_bit_setf(1);
            apb_audio_ctrl1_audio_pga_vcm_ctrl_setf(0);

            g_stIoBufSys.IoBufInFlag |= CO_BIT(ADC0);
        }

        Audio_ADC_PowerOff();
    }

    if ((CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0))) ||
            ((CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)))))
    {
        lm_fifo_config_2_in_thre_setf(usSampleNum - 1);
        lm_fifo_config_2_in_thre_en_setf(1);
    }

    intc_enable_set(INTC_ID_IO_BUF_IN, (intc_handler *)AUDIO_IN_Isr);

    return uFifoAddr;
}

void AUDIO_IN_Uninit(uint16_t usSignal, uint8_t ucMode)
{
    audio_in_ftable->AUDIO_IN_Uninit(usSignal, ucMode);
}
void patch_AUDIO_IN_Uninit(uint16_t usSignal, uint8_t ucMode)
{
    lm_fifo_config_2_in_thre_setf(0);
    lm_fifo_config_2_in_thre_en_setf(0);
    Delay_Us(100);

    if ((CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0))))
    {
        apb_clk_gen_clken_clk_adc_dnsp_1_en_setf(0);
        apb_clk_gen_clken_clk_adc_en_setf(0);

        apb_adc_filt_config_0_sync_bit_setf(0);

        /* turn off fifo */
        lm_fifo_control_set(0, 0);
        lm_fifo_status_get(0);
        if (g_pstConfig->FuncCfg.SupportAppleEarphone)
        {
            lm_fifo_control_fifo_en_setf(1, 0);
            lm_fifo_status_get(1);
        }

        apb_rst_gen_ctrl0_adc_rst_setf(1);

        /* turn off analog */
        Audio_ADC_PowerOff();
    }

    if ((CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R))))
    {
        lm_fifo_pointer_rd_ptr_setf(4, 0);
        lm_fifo_control_set(4, 0);

        lm_fifo_pointer_rd_ptr_setf(5, 0);
        lm_fifo_control_set(5, 0);

        if ((MASTER0 == ucMode) || (SLAVE0 == ucMode))
        {
            apb_audio_0_cfg_audio_0_en_setf(0);

            apb_rst_gen_ctrl0_i_2s_rst_setf(1);

            if (MASTER0 == ucMode)
            {
                apb_clk_gen_clken_i_2sm_0_en_setf(0);
            }
            else
            {
                apb_clk_gen_clken_i_2ss_0_en_setf(0);
            }
        }

        if ((MASTER1 == ucMode) || (SLAVE1 == ucMode))
        {
            apb_audio_1_cfg_audio_1_en_setf(0);

            apb_rst_gen_ctrl0_i_2s_rst_setf(2);

            if (MASTER1 == ucMode)
            {
                apb_clk_gen_clken_i_2sm_1_en_setf(0);
            }
            else
            {
                apb_clk_gen_clken_i_2ss_1_en_setf(0);
            }
        }

        lm_fifo_status_get(4);
        lm_fifo_status_get(5);
    }

    intc_enable_clr(INTC_ID_IO_BUF_IN);
}

void AUDIO_IN_Start(uint16_t usSignal, uint8_t ucMode)
{
    audio_in_ftable->AUDIO_IN_Start(usSignal, ucMode);
}
void patch_AUDIO_IN_Start(uint16_t usSignal, uint8_t ucMode)
{
    if (0 == AuInStartFlg)
    {
        if ((CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0))))
        {
            /* turn on analog */
            Audio_ADC_PowerOn();

            /* turn on fifo */
            lm_fifo_control_fifo_en_setf(0, 1);
            if (g_pstConfig->FuncCfg.SupportAppleEarphone)
            {
                lm_fifo_control_fifo_en_setf(1, 1);
            }

            apb_clk_gen_clken_clk_adc_dnsp_1_en_setf(1);
            apb_clk_gen_clken_clk_adc_en_setf(1);
            apb_adc_filt_config_0_dcnotch_en_setf(0);// Do Not use hardware DCNotch,
            apb_adc_filt_config_0_sync_bit_setf(1);
        }
        if ((CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R))))
        {
            apb_rst_gen_ctrl0_i_2s_rst_setf(0);

            lm_fifo_status_get(4);
            lm_fifo_status_get(5);

            lm_fifo_control_fifo_en_setf(4, 1);
            lm_fifo_control_fifo_en_setf(5, 1);

            if ((MASTER0 == ucMode) || (SLAVE0 == ucMode))
            {
                if (MASTER0 == ucMode)
                {
                    apb_clk_gen_clken_i_2sm_0_en_setf(1);
                }
                else
                {
                    apb_clk_gen_clken_i_2ss_0_en_setf(1);
                }

                apb_audio_0_cfg_audio_0_en_setf(1);
            }

            if ((MASTER1 == ucMode) || (SLAVE1 == ucMode))
            {
                if (MASTER1 == ucMode)
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
        #if(AUDIO_IN_SEL==3)
        lm_fifo_config_2_in_thre_setf(g_stIoBufSys.Fifo_In_Sample_Num/2 - 1);
        #else
        lm_fifo_config_2_in_thre_setf(g_stIoBufSys.Fifo_In_Sample_Num - 1);
        #endif

        g_stStartFlag.InStartFlag = 1;
        AuInStartFlg = 1;
    }
}


void AUDIO_IN_Stop(uint16_t usSignal, uint8_t ucMode)
{
    audio_in_ftable->AUDIO_IN_Stop(usSignal, ucMode);
}
void patch_AUDIO_IN_Stop(uint16_t usSignal, uint8_t ucMode)
{
    if (1 == AuInStartFlg)
    {
        lm_fifo_config_2_in_thre_setf(0);

        timer_delay_length(100, TIM_US);

        if ((CO_BIT(ADC0) == (usSignal & CO_BIT(ADC0))))
        {
            apb_clk_gen_clken_clk_adc_dnsp_1_en_setf(0);
            apb_clk_gen_clken_clk_adc_en_setf(0);

            apb_adc_filt_config_0_sync_bit_setf(0);

            /* turn off fifo */
            lm_fifo_control_fifo_en_setf(0, 0);
            lm_fifo_status_get(0);
            if (g_pstConfig->FuncCfg.SupportAppleEarphone)
            {
                lm_fifo_control_fifo_en_setf(1, 0);
                lm_fifo_status_get(0);
            }

            /* turn off analog */
            Audio_ADC_PowerOff();
        }

        if ((CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)) == (usSignal & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R))))
        {
            lm_fifo_pointer_rd_ptr_setf(4, 0);
            lm_fifo_control_fifo_en_setf(4, 0);

            lm_fifo_pointer_rd_ptr_setf(5, 0);
            lm_fifo_control_fifo_en_setf(5, 0);

            if ((MASTER0 == ucMode) || (SLAVE0 == ucMode))
            {
                apb_audio_0_cfg_audio_0_en_setf(0);

                apb_rst_gen_ctrl0_i_2s_rst_setf(1);

                if (MASTER0 == ucMode)
                {
                    apb_clk_gen_clken_i_2sm_0_en_setf(0);
                }
                else
                {
                    apb_clk_gen_clken_i_2ss_0_en_setf(0);
                }
            }

            if ((MASTER1 == ucMode) || (SLAVE1 == ucMode))
            {
                apb_audio_1_cfg_audio_1_en_setf(0);

                apb_rst_gen_ctrl0_i_2s_rst_setf(2);

                if (MASTER1 == ucMode)
                {
                    apb_clk_gen_clken_i_2sm_1_en_setf(0);
                }
                else
                {
                    apb_clk_gen_clken_i_2ss_1_en_setf(0);
                }
            }

            lm_fifo_status_get(4);
            lm_fifo_status_get(5);
        }

        g_stStartFlag.InStartFlag = 0;
        AuInStartFlg = 0;
    }
}

volatile uint16_t g_usIoBufInFlag;
void AUDIO_IN_Isr(void)
{
    audio_in_ftable->AUDIO_IN_Isr();
}

void patch_AUDIO_IN_Isr(void)
{
	// GPIO_FuncSet(GPIO10,GPIO_DigOutput1);//设置GPIO输出高
    const uint16_t sampleNumbersBytes= AUDIO_SAMPLE_BLOCK_SIZE<<2;//一个采样点是4bytes 16*4=64
    if (g_stIoBufSys.IoBufInFlag & CO_BIT(ADC0))
    {
        if (lm_fifo_status_data_num_getf(0) >= sampleNumbersBytes)
        {
            g_usIoBufInFlag |= CO_BIT(ADC0);
        }
    }

    if (g_stIoBufSys.IoBufInFlag & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)))
    {
        if (lm_fifo_status_data_num_getf(4) >= sampleNumbersBytes)
        {
            g_usIoBufInFlag |= CO_BIT(I2S_IN_L);
        }

        if (lm_fifo_status_data_num_getf(5) >= sampleNumbersBytes)
        {
            g_usIoBufInFlag |= CO_BIT(I2S_IN_R);
        }
    }
    if (g_stIoBufSys.IoBufInFlag == g_usIoBufInFlag) //i2s和adc都打开的话，两个都来中断才处理
    {
        uint16_t usAdc0Rd;
        uint16_t usAdc1Rd;
        uint16_t usI2SIN0Rd;
        uint16_t usI2SIN1Rd;


        usAdc0Rd = lm_fifo_pointer_rd_ptr_getf(0);

        usAdc1Rd = lm_fifo_pointer_rd_ptr_getf(1);

        usI2SIN0Rd = lm_fifo_pointer_rd_ptr_getf(4);

        usI2SIN1Rd = lm_fifo_pointer_rd_ptr_getf(5);
        if (g_stIoBufSys.audio_in_handler != NULL) {//new_patch_Audio_In_Speaker
            g_stIoBufSys.audio_in_handler(
                (q31_t *)(g_stIoBufSys.Fifo_Base[ADC0] + usAdc0Rd),
                (q31_t *)(g_stIoBufSys.Fifo_Base[ADC1] + usAdc1Rd),
                (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_IN_L] + usI2SIN0Rd),
                (q31_t *)(g_stIoBufSys.Fifo_Base[I2S_IN_R] + usI2SIN1Rd),
                g_stIoBufSys.Fifo_In_Sample_Num,
                g_usIoBufInFlag);
        }

        /* input */
        if (g_stIoBufSys.IoBufInFlag & CO_BIT(ADC0))
        {
            usAdc0Rd += sampleNumbersBytes;
            if (usAdc0Rd >= (g_stIoBufSys.Fifo_Len[ADC0]))
            {
                usAdc0Rd -= g_stIoBufSys.Fifo_Len[ADC0];
            }
            lm_fifo_pointer_rd_ptr_setf(0, usAdc0Rd);
        }

        if (g_stIoBufSys.IoBufInFlag & (CO_BIT(I2S_IN_L) | CO_BIT(I2S_IN_R)))
        {
            usI2SIN0Rd += sampleNumbersBytes;
            if (usI2SIN0Rd >= (g_stIoBufSys.Fifo_Len[I2S_IN_L]))
            {
                usI2SIN0Rd -= g_stIoBufSys.Fifo_Len[I2S_IN_L];
            }
            lm_fifo_pointer_rd_ptr_setf(4, usI2SIN0Rd);

            usI2SIN1Rd += sampleNumbersBytes;
            if (usI2SIN1Rd >= (g_stIoBufSys.Fifo_Len[I2S_IN_R]))
            {
                usI2SIN1Rd -= g_stIoBufSys.Fifo_Len[I2S_IN_R];
            }
            lm_fifo_pointer_rd_ptr_setf(5, usI2SIN1Rd);
        }
        g_usIoBufInFlag = 0;
    }
	// GPIO_FuncSet(GPIO10,GPIO_DigOutput0);//设置GPIO输出低
}

const ftable_t patch_audio_in_fi_table =
{
    .AUDIO_IN_Init   = patch_AUDIO_IN_Init,
    .AUDIO_IN_Uninit = patch_AUDIO_IN_Uninit,
    .AUDIO_IN_Start  = patch_AUDIO_IN_Start,
    .AUDIO_IN_Stop   = patch_AUDIO_IN_Stop,
    .AUDIO_IN_Isr    = patch_AUDIO_IN_Isr,
};

void new_audio_in_patch_init(void)
{
    audio_in_ftable = (ftable_t *)&patch_audio_in_fi_table;
}
