/*
 * earphone_key_wakeup_detect.h
 *
 */

#ifndef _EARPHONE_KEY_DETECT_H_
#define _EARPHONE_KEY_DETECT_H_

#include "com_includes.h"

typedef void (*earphone_key_detect_handle_t)(void);

typedef struct
{
	earphone_key_detect_handle_t pEarphoneKeyDetectHandler;
}earphone_key_detect_para_t;

typedef enum
{
	EARPHONE_KEY_DETECT,
	EARPHONE_KEY_DETECT_NUM,
}earphone_key_detect_sel_t;

typedef struct{
	uint16_t thrd0;
	uint16_t thrd1;
	uint16_t thrd2;
	uint16_t thrd3;
	uint16_t thrd4;
	uint16_t thrd5;
	uint16_t thrd6;
}earphone_key_thrd_t;

extern earphone_key_thrd_t st_earphone_key_thrd;
extern void Earphone_Key_Detect_FuncHandle(void);
extern void Earphone_Key_Detect_Isr(uint32_t uID);
extern void Micin_Key_Det_Fsm_Init(void);
extern void earphone_key_detect_patch_init(void);
extern void new_earphone_key_detect_patch_init(void);
extern void Earphone_Key_Detect_Thrd_Init(product_app_index_t pmod);

#endif 
