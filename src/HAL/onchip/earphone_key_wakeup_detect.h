/*
 * earphone_key_wakeup_detect.h
 *
 */

#ifndef _EARPHONE_KEY_WAKEUP_DETECT_H_
#define _EARPHONE_KEY_WAKEUP_DETECT_H_

typedef void (*earphone_kwp_detect_handle_t)(void);

typedef struct
{
	earphone_kwp_detect_handle_t pEarphoneKwpDetectHandler;
}earphone_kwp_detect_para_t;

typedef enum
{
	EARPHONE_KWP_DETECT,
	EARPHONE_KWP_DETECT_NUM,
}earphone_kwp_detect_sel_t;

extern void Earphone_KWP_Detect_SetCallBack(uint8_t Index, uint32_t FuncHandle);
extern void Earphone_KWP_Detect_Init(uint8_t ucDebounceSel, uint8_t ucVoltageThresholdSel);
extern void Earphone_KWP_Detect_Uninit(void);
extern void Earphone_KWP_Detect_Start(void);
extern void Earphone_KWP_Detect_Stop(void);
extern void Earphone_KWP_Det_patch_init(void);

#endif 
