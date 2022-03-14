#include "earphone_key_detect.h"
#include "saradc.h"
#include "timer.h"
#include "debug.h"

typedef struct
{
    void (*Saradc_Init)(void);
    void (*Saradc_Uninit)(void);
    uint16_t (*Saradc_Convert)(uint16_t usAvgNum, SARADC_PATH_un ePathNum);
    uint16_t (*Saradc_Convert_Pack)(uint16_t usAvgNum, SARADC_PATH_un ePathNum);
}ftable_t;

ftable_t *saradc_ftable;

void Saradc_Init(void)
{
    saradc_ftable->Saradc_Init();
}
void patch_Saradc_Init(void)
{
	//DBG_OUT_FUNC("entry\n");//这个函数会不断循环
    apb_saradc_ctrl_saradc_ldo_pd_setf(0);
    apb_saradc_ctrl_saradc_pd_setf(0);
    timer_delay_length(1, TIM_MS);
    apb_saradc_ctrl_saradc_dig_rst_n_setf(1);
    apb_clk_gen_clken_clk_auxadc_en_setf(1);
    apb_aux_adc_ctrl0_auxadc_fsm_mode_setf(0);
    apb_aux_adc_ctrl0_saradc_start_reg_setf(0);
    // timer_delay_length(20, TIM_US);
}

void Saradc_Uninit(void)
{
    saradc_ftable->Saradc_Uninit();
}
extern void rom_Saradc_Uninit(void);

uint16_t Saradc_Convert(uint16_t usAvgNum, SARADC_PATH_un ePathNum)
{
    return saradc_ftable->Saradc_Convert(usAvgNum, ePathNum);
}
uint16_t patch_Saradc_Convert(uint16_t usAvgNum, SARADC_PATH_un ePathNum)
{
    uint16_t i;
    uint32_t uSum = 0;
    uint16_t timerCnt=0;
    uint16_t value;
    uint16_t maxValue=0;
    uint16_t minValue=0x3ff;
    // apb_clk_gen_clken_clk_auxadc_en_setf(1);

    // apb_aux_adc_ctrl0_saradc_sel_reg_setf(ePathNum);
    // timer_delay_length(1, TIM_US);
    for (i = 0; i < usAvgNum; i++)
    {
        apb_aux_adc_ctrl0_saradc_sel_reg_setf(ePathNum);
        timer_delay_length(1, TIM_US);
		apb_aux_adc_ctrl0_saradc_start_reg_setf(0);
        apb_aux_adc_ctrl0_saradc_start_reg_setf(1);
        timer_delay_length(5, TIM_US);
        timerCnt = 0;
        while (!apb_saradc_ctrl_saradc_pdata_done_getf())
        {
            timer_delay_length(1, TIM_US);
            timerCnt++;
            if((apb_saradc_ctrl_saradc_pd_getf())
                ||(timerCnt>1500))
            {
                return 0x3FF;
            }
        }
        apb_aux_adc_ctrl0_saradc_start_reg_setf(0);
        value=apb_saradc_ctrl_saradc_pdata_out_getf();
        if(value>maxValue)maxValue=value;
        if(value<minValue)minValue=value;
        uSum += value;
    }
    if(usAvgNum>2)
    {
        uSum-=maxValue;
        uSum-=minValue;
        usAvgNum-=2;
    }

    uSum /= usAvgNum;
    return uSum;
}

uint16_t Saradc_Convert_Pack(uint16_t usAvgNum, SARADC_PATH_un ePathNum)
{
    return saradc_ftable->Saradc_Convert_Pack(usAvgNum, ePathNum);
}
extern uint16_t rom_Saradc_Convert_Pack(uint16_t usAvgNum, SARADC_PATH_un ePathNum);

const ftable_t new_saradc_fi_table = 
{
    .Saradc_Init         = patch_Saradc_Init,
    .Saradc_Uninit       = rom_Saradc_Uninit,
    .Saradc_Convert      = patch_Saradc_Convert,
    .Saradc_Convert_Pack = rom_Saradc_Convert_Pack,
};

void new_saradc_patch_init(void)
{
    saradc_ftable = (ftable_t *)&new_saradc_fi_table;
}
