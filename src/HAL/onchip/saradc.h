#ifndef _SARADC_H_
#define _SARADC_H_

typedef enum
{
    SARADC_SEL_MIC,
    SARADC_SEL_GPIO1,
    SARADC_SEL_GPIO2,
    SARADC_SEL_GPIO3,
    SARADC_SEL_GPIO4,
    SARADC_SEL_GPIO5,
    SARADC_SEL_GPIO6,
    SARADC_SEL_GPIO7,
    SARADC_SEL_GPIO8,
    SARADC_SEL_AUDAC_ITRIM_VOUT,
} SARADC_PATH_un;

extern void Saradc_Init(void);
extern void Saradc_Uninit(void);
extern uint16_t Saradc_Convert(uint16_t usAvgNum, SARADC_PATH_un ePathNum);
extern uint16_t Saradc_Convert_Pack(uint16_t usAvgNum, SARADC_PATH_un ePathNum);
extern void saradc_patch_init(void);
extern void new_saradc_patch_init(void);

#endif
