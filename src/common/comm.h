#ifndef __COMM_H__
#define __COMM_H__


#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>
#include <nds32_intrinsic.h>
#include <nds32_utils_math.h>

#include "co_assert.h"
	
#include "reg_apb.h"
#include "reg_rf.h"
#include "reg_lm.h"
#include "reg_otp.h"
#include "config.h"
#include "otp_ctrl.h"
//#include "interrupt.h"


typedef signed char                INT8;
typedef signed short int           INT16;
typedef signed int                 INT32;
typedef unsigned char              UINT8;
typedef unsigned short int         UINT16;
typedef unsigned int               UINT32;
//typedef bit                 BOOL;
typedef void *              HANDLE;
typedef void voidfunc(void);	//use voidfunc * pfunc to define void function pointer

#define     __I     volatile const       /*!< defines 'read only' permissions                 */
#define     __O     volatile             /*!< defines 'write only' permissions                */
#define     __IO    volatile             /*!< defines 'read / write' permissions              */


#define TRUE                0x1
#define FALSE               0x0

#define PTCH

#define __pack_func__ __attribute__((used,section(".pack_func")))

#ifndef MIN
   #define MIN(x,y) ((x)<(y)?(x):(y))
#endif

#ifndef MAX
   #define MAX(x,y) ((x)>(y)?(x):(y))
#endif

#define ABS(x) (((x) > 0) ? (x) : -(x))

#define BIT0 (0x01ul)
#define BIT1 (0x02ul)
#define BIT2 (0x04ul)
#define BIT3 (0x08ul)
#define BIT4 (0x10ul)
#define BIT5 (0x20ul)
#define BIT6 (0x40ul)
#define BIT7 (0x80ul)

#define BIT8  (0x0100ul)
#define BIT9  (0x0200ul)
#define BIT10 (0x0400ul)
#define BIT11 (0x0800ul)
#define BIT12 (0x1000ul)
#define BIT13 (0x2000ul)
#define BIT14 (0x4000ul)
#define BIT15 (0x8000ul)

#define BIT16 (0x010000ul)
#define BIT17 (0x020000ul)
#define BIT18 (0x040000ul)
#define BIT19 (0x080000ul)
#define BIT20 (0x100000ul)
#define BIT21 (0x200000ul)
#define BIT22 (0x400000ul)
#define BIT23 (0x800000ul)

#define BIT24 (0x01000000ul)
#define BIT25 (0x02000000ul)
#define BIT26 (0x04000000ul)
#define BIT27 (0x08000000ul)
#define BIT28 (0x10000000ul)
#define BIT29 (0x20000000ul)
#define BIT30 (0x40000000ul)
#define BIT31 (0x80000000ul)
#define  Data_Init(VaNum,size,ByteNum,... )               \
{                         \
	int i = 0,j =0 ;           \
	va_list ArgPtr;       \
	va_start(ArgPtr, n);           \
	if(ByteNum == 4)             \
	{                           \
		uint32_t * pUnit =0;		\
		for(i=0 ; i<VaNum;i++)    \
		{                     \
			pUnit = va_arg(ArgPtr,uint32_t*); \
			for(j=0 ; j<size;i++)    \
			{\
				*pUnit = 0; \
				pUnit++; \
			}\
		} \
	}                      \
	else if(ByteNum == 2)           \
	{              \
		uint16_t * pUnit =0;		\
		for(i=0 ; i<VaNum;i++)    \
		{                     \
			pUnit = va_arg(ArgPtr,uint16_t*); \
			for(j=0 ; j<size;i++)    \
			{\
				*pUnit = 0; \
				pUnit++; \
			}\
		} \
	}       \
	else if(ByteNum == 1)           \
	{              \
		uint8_t * pUnit =0;		\
		for(i=0 ; i<VaNum;i++)    \
		{                     \
			pUnit = va_arg(ArgPtr,uint8_t*); \
			for(j=0 ; j<size;i++)    \
			{\
				*pUnit = 0; \
				pUnit++; \
			}\
		} \
	}       \
}

typedef union {
	uint8_t		uint8[4];
	int8_t		int8[4];
	uint16_t	uint16[2];
	int16_t		int16[2];
	uint32_t 	uint32;
	int32_t		int32;
}un_split32_t;

typedef union {
	uint16_t	uint16;
	int16_t		int16;
	uint8_t		uint8[2];
	int8_t		int8[2];
}un_split16_t;

#define INW(reg)        ( *((volatile UINT32 *)(reg)))
#define OUTW(reg, data) ((*((volatile UINT32 *)(reg)))=(UINT32)(data))

enum {
    OK                  = 0x178e,              /*处理正确*/
    ERR                 = 0x000f,              /*一般错误*/
    TIMER_PARAM_ERR     = 0x0203,
    TIMER_BUSY_ERR      = 0x0230,


        /*--------------------i2c return  code-------------------------------*/
    I2C_PARA_ERR        = 0x03a6,
    I2C_NOT_SET_UP      = 0x03a9,
    I2C_MALLOC_EER      = 0x03c0,
    I2C_WRITE_EER       = 0x03cf,
    I2C_READ_EER        = 0x03f3,
    I2C_STATUS_ERR      = 0x03fc,
};

//#define ASSERT_ERR(x)

#define SET_REG_BITS(Reg, CtrlBits)  (Reg = Reg | CtrlBits)

#define CLR_REG_BITS(Reg,CtrlBits)  (Reg = Reg & (~CtrlBits))

extern void Delay_Us(uint16_t Nus);
extern void Delay_Ms(uint16_t Nms);
extern void Delay_Ms_24M(uint16_t Nms);
extern void Delay_Ms_600K(uint16_t Nms);
extern void Delay_100Us_600K(uint16_t Nus);

#ifdef  __cplusplus
}
#endif

#endif

