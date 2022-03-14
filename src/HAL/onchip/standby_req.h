/*
 * standby_req.h
 *
 */

#ifndef _STANDBY_REQ_H_
#define _STANDBY_REQ_H_

typedef void (*standby_req_handle_t)(void);

typedef struct
{
	standby_req_handle_t pStandbyReqHandler;
}standby_req_para_t;

typedef enum
{
	STANDBY_REQ,
	STANDBY_REQ_NUM,
}standby_req_sel_t;

extern uint8_t u8IsStandBy;
extern uint16_t _SarAdcData;

extern void Standby_Req_Init(void);
extern void Standby_Req_SetCallBack(uint8_t Index, uint32_t FuncHandle);
extern void Standby_Req_patch_init(void);
extern void EnterExit_Standby(void);
extern void Standby_Req_UnInit(void);
extern void new_TypeCTo3p5_RmvStandby_WKP_Src_Set(void);

extern void new_Standby_Req_patch_init(void);

#endif
