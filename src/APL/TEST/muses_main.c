#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"

typedef struct{
	void (*h_patch_init)(void);
    void (*h_init)(void);
    void (*h_schedule)(void);
} main_ftable_t;

main_ftable_t *main_ftable;

void patch_init(void)
{
    main_ftable->h_patch_init();
}

void p_patch_init(void){
    // audio_effect_qianhai_patch_init();
    // drc_fun_patch_init();
    // dsp_patch_init();
    // echo_fun_patch_init();
    // eq_cal_coeff_top_patch_init();
    // eq_top_patch_init();
    // freqshift_patch_init();
    // HowlingDetect_patch_init();
    // noise_gate_patch_init();
    // reverb_patch_init();
    // volume_patch_init();
    // BCH_127_K_patch_init();
    // BCH_255_K_patch_init();
    // BCH_31_K_patch_init();
    // BCH_63_K_patch_init();
    // g711_plc_patch_init();
    // parallel_crc_patch_init();
    // co_mem_patch_init();
    // aptx_patch_init();
    // asrc_patch_init();
    // modes_patch_init();
    // celt_encoder_patch_init();
    // celt_decoder_patch_init();
    // sbc_patch_init();
    // plf_patch_init();
    // flash_patch_init();
    // otp_ctrl_patch_init();
    // power_ctrl_patch_init();
    // qspi_ctrl_patch_init();
    // swi_patch_init();
    // syscntl_patch_init();
    // audio_patch_init();
    // audio_in_patch_init();
    // audio_out_patch_init();
    // dw_i2c_patch_init();
    // dw_timer_patch_init();
    // dw_uart_patch_init();
    // i2c_patch_init();
    // rf_patch_init();
    // RX_DQPSK_patch_init();
    // RX_GFSK_patch_init();
    // TX_DQPSK_patch_init();
    // TX_GFSK_patch_init();
    // work_flow_patch_init();
    // cache_patch_init();
    // top_asrc_patch_init();
    // top_audio_patch_init();
    // top_audio_effect_patch_init();
    // top_channel_codec_patch_init();
    // top_level_patch_init();
    // top_rf_patch_init();
    // top_source_codec_patch_init();
}

void init(void)
{
    main_ftable->h_init();
}

extern void __c_init();

//power_on_para_t g_stPowerOnPara_1 =
//{
//    .osc_div_sel = 4,
//};

void p_init(void)
{
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
    intc_init();
    GLOBAL_INT_START();

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


            break;
        }        
        case USB_TYPEC_HEADPHONE:
        {


            break;
        }
        case USB_DONGLE:
        {


            break;
        }
        case USB_DONGLE_DSP:
        {


            break;
        }
        default: //USB_TEST
        {

            break;
        }
    }

    Suspend_Init();
    Standby_Req_SetCallBack(STANDBY_REQ, Suspend_EnterExit_Process);
}

void schedule(void)
{
    main_ftable->h_schedule();
}

void p_schedule(void)
{
    //TODO - add Event FSM loop
    //TEST

    // if(g_SysData.TopPlcEn)
    // {
	   // top_level_rx_ic_step12();
    // }

    // if(g_I2CWriteCnt != g_I2CWriteCnt_old) {
    //     dsp_register_to_parameter();    //dsp register update
    //     g_I2CWriteCnt_old = g_I2CWriteCnt;
    // }
    
    //uart_puts("This is Rom. Hello world!\n");

    // //register updata
    // void dsp_reg_updata(void)
    // {

    // }
    // ke_event_callback_set(KE_EVENT_DSP_REG_UPDATA, tlpool_handler);
    // ke_event_set(KE_EVENT_DSP_REG_UPDATA);
    // ke_event_clear(KE_EVENT_DSP_REG_UPDATA);
    // ke_event_schedule();
    
    // PowerDown_Process();
    //StandBy_Process(g_SysData.TopAudioStrength);
	__nds32__nop();
}

// Patch functions table
volatile main_ftable_t patch_ftable;

// Patch functions table
const main_ftable_t patch_default_value_ftable = 
{
    .h_patch_init = p_patch_init,
    .h_init       = p_init,
    .h_schedule   = p_schedule,
};

int main(void)
{
    main_ftable = (main_ftable_t *)&patch_ftable;

    if((RUN_MODE_IS_PATCH == SW_CFG0->PrgRunMode) || (RUN_MODE_IS_PATCH2RAM == SW_CFG0->PrgRunMode))
    {
        UINT32 Tmp;

        Tmp = INW(FLASH_PATCH_TABLE_ADDR);
        (void)MEM_Cpy_Word((unsigned int *)&patch_ftable, (unsigned int *)Tmp, sizeof(main_ftable_t)>>2);
    }
    else
    {
        UINT32 Tmp;

        Tmp = (UINT32)&patch_default_value_ftable;
        memcpy((unsigned int *)&patch_ftable, (unsigned int *)Tmp, sizeof(main_ftable_t));
    }


    /* patch able code start */

    patch_init();

    init();

    while(1)
    {
        //schedule();
        DEBUG_GPIO6_SET();
        Delay_Ms(5);
        DEBUG_GPIO6_CLR();
        Delay_Ms(5);
    }
}


