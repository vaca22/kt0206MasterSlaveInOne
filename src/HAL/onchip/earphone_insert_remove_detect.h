/*
 * earphone_insert_remove_detect.h
 *
 */

#ifndef _EARPHONE_INSERT_REMOVE_DETECT_H_
#define _EARPHONE_INSERT_REMOVE_DETECT_H_

typedef void (*earphone_detect_insert_handle_t)(void);
typedef void (*earphone_detect_handle_t)(uint8_t ucPoleType);

typedef struct
{
	earphone_detect_insert_handle_t pEarphoneInsertHandler;
	earphone_detect_handle_t pEarphoneCompletHandler;
	earphone_detect_handle_t pEarphoneRemoveHandler;
	uint8_t EarPhoneDetectCompletFlag; //detect complet flag
	uint8_t EarPhonePoleFlag; //0:4pole  1:3pole
}earphone_detect_para_t;

typedef struct
{
	uint8_t u8GpioValue_old;
	uint8_t u8GpioValue_new;
	uint8_t u8GpioValue0Cnt;
	uint8_t u8GpioValue1Cnt;
}earphone_insert_remove_by_gpio_t;

typedef enum
{
	EARPHONE_DETECT_INSERT,
	EARPHONE_DETECT_COMPLET,
	EARPHONE_DETECT_REMOVE,
	EARPHONE_DETECT_NUM,
}earphone_detect_sel_t;


extern volatile uint8_t jack_insert_complet;
extern earphone_detect_para_t stEarphoneDetectPara;
extern volatile uint8_t jack_ins_bygpio_proc;
extern volatile uint8_t g_u8DebTimeSet;

extern void Earphone_Detect_Init(void);
extern void Earphone_Detect_SetCallBack(uint8_t Index, uint32_t FuncHandle);
extern void EarphoneIRDet_patch_init(void);
extern void Jack_InsRmvDet_ByGpio_Init(void);

extern void new_EarphoneIRDet_patch_init(void);

#endif 
