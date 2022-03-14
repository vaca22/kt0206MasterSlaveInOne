#ifndef REG_LM_H_
#define REG_LM_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "comm.h"
#include "config.h"

//FIFO_INT_STATUS
typedef struct {
	//Byte0
    uint32_t ADC0_INT				: 1;
    uint32_t RFU0					: 1;
    uint32_t TDM_IN_0				: 1;
    uint32_t TDM_IN_1				: 1;
    uint32_t I2S_IN_L_INT			: 1;
    uint32_t I2S_IN_R_INT			: 1;
    uint32_t DAC0_INT				: 1;
    uint32_t DAC1_INT				: 1;
    //Byte1~3
    uint32_t I2S_OUT_L_INT			: 1;
    uint32_t I2S_OUT_R_INT			: 1;
    uint32_t TDM_OUT_0				: 1;
    uint32_t TDM_OUT_1				: 1;
    uint32_t IN_THRE_INT			: 1;
    uint32_t OUT_THRE_INT			: 1;
    uint32_t RFU1					: 18;
}st_FIFO_INT_STATUS;
typedef union {
	st_FIFO_INT_STATUS				bs;
	uint32_t						overall;
}un_FIFO_INT_STATUS;


//FIFO_CONFIG
typedef struct {
	//Byte0
    uint32_t IN_SEL					: 4;
    uint32_t OUT_SEL				: 4;
    //Byte1
    uint32_t FIFO_INT_EN_1			: 7;
    uint32_t RFU0					: 1;
    //Byte2
    uint32_t FIFO_INT_EN_2			: 7;
    uint32_t RFU1					: 1;
    //Byte3
    uint32_t PERF_CNT_EN			: 1;
    uint32_t RFU2					: 4;
    uint32_t RAM_2_ILM				: 1;
    uint32_t RAM_3_ILM				: 1;
    uint32_t RFU3					: 1;
}st_FIFO_CONFIG;
typedef union {
	st_FIFO_CONFIG					bs;
	uint32_t						overall;
}un_FIFO_CONFIG;


//FIFO_CONTROL_x
typedef struct {
	//Byte0~1
    uint32_t START_ADDR				: 16;
    //Byte2~3
    uint32_t FIFO_LEN				: 12;
    uint32_t DATA_SIZE				: 1;
    uint32_t DATA_ADJUST			: 1;
    uint32_t FIFO_INT_ENABLE		: 1;
    uint32_t FIFO_ENABLE			: 1;
}st_FIFO_CONTROL_x;
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_x;

//FIFO_CONTROL_0
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_0;
//FIFO_CONTROL_1
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_1;
//FIFO_CONTROL_4
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_4;
//FIFO_CONTROL_5
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_5;
//FIFO_CONTROL_6
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_6;
//FIFO_CONTROL_7
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_7;
//FIFO_CONTROL_8
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_8;
//FIFO_CONTROL_9
typedef union{
	st_FIFO_CONTROL_x				bs;
	uint32_t						overall;
}un_FIFO_CONTROL_9;


//FIFO_POINTER_x
typedef struct {
	//Byte0~1
    uint32_t WR_PTR					: 16;
    //Byte2~3
    uint32_t RD_PTR					: 16;
}st_FIFO_POINTER_x;
typedef union{
	st_FIFO_POINTER_x 				bs;
	uint32_t 						overall;
}un_FIFO_POINTER_x;

//FIFO_POINTER_0
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_0;
//FIFO_POINTER_1
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_1;
//FIFO_POINTER_2
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_2;
//FIFO_POINTER_3
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_3;
//FIFO_POINTER_4
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_4;
//FIFO_POINTER_5
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_5;
//FIFO_POINTER_6
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_6;
//FIFO_POINTER_7
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_7;
//FIFO_POINTER_8
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_8;
//FIFO_POINTER_9
typedef union{
	st_FIFO_POINTER_x				bs;
	uint32_t						overall;
}un_FIFO_POINTER_9;


//FIFO_STATUS_x
typedef struct {
	//Byte0~1
    uint32_t DATA_NUM				: 16;
    //Byte2~3
    uint32_t FIFO_EMPTY				: 1;
    uint32_t FIFO_AE				: 1;
    uint32_t FIFO_HF				: 1;
    uint32_t FIFO_AF				: 1;
    uint32_t FIFO_FULL				: 1;
    uint32_t FIFO_UNDERFLOW			: 1;
    uint32_t FIFO_OVERFLOW			: 1;
    uint32_t RFU0					: 9;
}st_FIFO_STATUS_x;
typedef union{
	st_FIFO_STATUS_x 				bs;
	uint32_t 						overall;
}un_FIFO_STATUS_x;

//FIFO_STATUS_0
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_0;
//FIFO_STATUS_1
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_1;
//FIFO_STATUS_2
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_2;
//FIFO_STATUS_3
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_3;
//FIFO_STATUS_4
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_4;
//FIFO_STATUS_5
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_5;
//FIFO_STATUS_6
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_6;
//FIFO_STATUS_7
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_7;
//FIFO_STATUS_8
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_8;
//FIFO_STATUS_9
typedef union{
	st_FIFO_STATUS_x				bs;
	uint32_t						overall;
}un_FIFO_STATUS_9;


//FIFO_THRE
typedef struct {
	//Byte0~1
    uint32_t AE_THRE				: 16;
    //Byte2~3
    uint32_t AF_THRE				: 16;
}st_FIFO_THRE_x;
typedef union{
	st_FIFO_THRE_x 					bs;
	uint32_t 						overall;
}un_FIFO_THRE_x;

//FIFO_THRE_0
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_0;
//FIFO_THRE_4
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_4;
//FIFO_THRE_5
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_5;
//FIFO_THRE_6
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_6;
//FIFO_THRE_7
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_7;
//FIFO_THRE_8
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_8;
//FIFO_THRE_9
typedef union{
	st_FIFO_THRE_x					bs;
	uint32_t						overall;
}un_FIFO_THRE_9;


//FIFO_CONFIG2
typedef struct {
	//Byte0~1
    uint32_t IN_THRE				: 15;
    uint32_t IN_THRE_EN				: 1;
    //Byte2~3
    uint32_t OUT_THRE				: 15;
    uint32_t OUT_THRE_EN			: 1;
}st_FIFO_CONFIG_2;
typedef union{
	st_FIFO_CONFIG_2				bs;
	uint32_t						overall;
}un_FIFO_CONFIG_2;


//FIFO_CONFIG_3
typedef struct {
	//Byte0
	uint32_t RAM_0_MARGIN 				: 2;
	uint32_t RAM_0_PWR_LV 				: 1;
	uint32_t RFU0		 				: 1;
	uint32_t RAM_1_MARGIN 				: 2;
	uint32_t RAM_1_PWR_LV 				: 1;
	uint32_t RAM_1_PWR_GSLEEP 			: 1;

	//Byte1
	uint32_t RAM_2_MARGIN 				: 2;
	uint32_t RAM_2_PWR_LV 				: 1;
	uint32_t RAM_2_PWR_GSLEPP 			: 1;
	uint32_t RAM_3_MARGIN 				: 2;
	uint32_t RAM_3_PWR_LV 				: 1;
	uint32_t RAM_3_PWR_GSLEEP 			: 1;

	//Byte2~3
	uint32_t ICACHE_MARGIN 				: 2;
	uint32_t DCACHE_MARGIN 				: 2;
	uint32_t RFU1 						: 8;
	uint32_t ROM_0_MARGIN 				: 1;
	uint32_t ROM_1_MARGIN 				: 1;
	uint32_t RFU2 						: 1;
	uint32_t DLM_MODEM_SAME_CLK			: 1;
}st_FIFO_CONFIG_3;
typedef union {
	st_FIFO_CONFIG_3					bs;
	uint32_t							overall;
}un_FIFO_CONFIG_3;


//CPU_CYCLE_CNT
typedef struct {
    uint32_t CPU_CYCLE_CNT				: 32;
}st_CPU_CYCLE_CNT;
typedef union{
	st_CPU_CYCLE_CNT					bs;
	uint32_t							overall;
}un_CPU_CYCLE_CNT;


//TDM_CONTROL_0
typedef struct{
	//Byte0~1
	uint32_t TDM_FIFO_LEN 				: 12;
	uint32_t RFU0 						: 4;

	//Byte2
	uint32_t TDM_FIFO_SEL 				: 4;
	uint32_t RFU1 						: 1;
	uint32_t TDM_DATA_SIZE 				: 1;
	uint32_t TDM_DATA_ADJUST 			: 2;

	//Byte3
	uint32_t RFU2 						: 5;
	uint32_t TDM_IO_SEL 				: 1;
	uint32_t TDM_INT_EN 				: 1;
	uint32_t TDM_PORT_EN 				: 1;
}st_TDM_CONTROL_0;
typedef union{
	st_TDM_CONTROL_0 					bs;
	uint32_t 							overall;
}un_TDM_CONTROL_0;


//TDM_CHANNEL_0
typedef struct{
	//Byte0
	uint32_t TDM_CHANNEL_EN 			: 8;

	//Byte1
	uint32_t RFU0 						: 8;

	//Byte2~3
	uint32_t TDM_CNT_THRE 				: 12;
	uint32_t TDM_CNT_SEL 				: 4;
}st_TDM_CHANNEL_0;
typedef union{
	st_TDM_CHANNEL_0 					bs;
	uint32_t 							overall;
}un_TDM_CHANNLE_0;


//TDM_FIFO_ADDR_0
typedef struct{
	//Byte0~1
	uint32_t TDM_START_ADDR 			: 16;

	//Byte2
	uint32_t RFU0 						: 8;

	//Byte3
	uint32_t TDM_FIFO_SEL 				: 4;
	uint32_t RFU1 						: 4;
}st_TDM_FIFO_ADDR_0;
typedef union{
	st_TDM_FIFO_ADDR_0 					bs;
	uint32_t 							overall;
}un_TDM_FIFO_ADDR_0;


//TDM_OUT_POINTER_0
typedef struct{
	//Byte0
	uint32_t WR_PTR 				: 16;
	//Byte1
	uint32_t RD_PTR 				: 16;
}st_TDM_OUT_POINTER_0;
typedef union{
	st_TDM_OUT_POINTER_0 			bs;
	uint32_t 						overall;
}un_TDM_OUT_POINTER_0;


//TDM_OUT_POINTER_1
typedef struct{
	//Byte0
	uint32_t WR_PTR					: 16;
	//Byte1
	uint32_t RD_PTR 				: 16;
}st_TDM_OUT_POINTER_1;
typedef union{
	st_TDM_OUT_POINTER_1 			bs;
	uint32_t 						overall;
}un_TDM_OUT_POINTER_1;


//FIFO_CONFIG_4
typedef struct {
	//Byte0~3
	uint32_t RFU0						: 32;
}st_FIFO_CONFIG_4;
typedef union {
	st_FIFO_CONFIG_4					bs;
	uint32_t							overall;
}un_FIFO_CONFIG_4;


//FIFO_CONFIG_5
typedef struct {
	//Byte0~3
	uint32_t RFU0		 				: 28;
	uint32_t MODEM_RAM_SEL				: 2;
	uint32_t RFU1						: 2;
}st_FIFO_CONFIG_5;
typedef union {
	st_FIFO_CONFIG_5						bs;
	uint32_t							overall;
}un_FIFO_CONFIG_5;


//LM_VERSION
typedef struct{
	//Byte0
	uint32_t IP_MINOR_VERSION 			: 8;

	//Byte1
	uint32_t IP_MAJOR_VERSION 			: 8;

	//Byte2
	uint32_t CHIP_ID 					: 8;

	//Byte3
	uint32_t RFU0 						: 8;
}st_LM_VERSION;
typedef union{
	st_LM_VERSION 						bs;
	uint32_t 							overall;
}un_LM_VERSION;


#define FIFO_INT_STATUS			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x00)))
#define FIFO_CONFIG				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x04)))
#define FIFO_CONTROL_0			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x08)))
#define FIFO_CONTROL_1			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x0C)))
//0x10~0x14 RFU
#define FIFO_CONTROL_4			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x18)))
#define FIFO_CONTROL_5			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x1C)))
#define FIFO_CONTROL_6			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x20)))
#define FIFO_CONTROL_7			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x24)))
#define FIFO_CONTROL_8			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x28)))
#define FIFO_CONTROL_9			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x2C)))
#define FIFO_POINTER_0			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x30)))
#define FIFO_POINTER_1			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x34)))
#define FIFO_POINTER_2			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x38)))
#define FIFO_POINTER_3			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x3C)))
#define FIFO_POINTER_4			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x40)))
#define FIFO_POINTER_5			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x44)))
#define FIFO_POINTER_6			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x48)))
#define FIFO_POINTER_7			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x4C)))
#define FIFO_POINTER_8			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x50)))
#define FIFO_POINTER_9			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x54)))
#define FIFO_STATUS_0			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x58)))
#define FIFO_STATUS_1			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x5C)))
#define FIFO_STATUS_2			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x60)))
#define FIFO_STATUS_3			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x64)))
#define FIFO_STATUS_4			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x68)))
#define FIFO_STATUS_5			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x6C)))
#define FIFO_STATUS_6			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x70)))
#define FIFO_STATUS_7			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x74)))
#define FIFO_STATUS_8			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x78)))
#define FIFO_STATUS_9			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x7C)))
#define FIFO_THRE_0				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x80)))
#define FIFO_THRE_1				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x84)))
#define FIFO_THRE_2				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x88)))
#define FIFO_THRE_3				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x8C)))
#define FIFO_THRE_4				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x90)))
#define FIFO_THRE_5				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x94)))
#define FIFO_THRE_6				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x98)))
#define FIFO_THRE_7				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0x9C)))
#define FIFO_THRE_8				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xA0)))
#define FIFO_THRE_9				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xA4)))
#define FIFO_CONFIG_2			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xA8)))
#define FIFO_CONFIG_3			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xAC)))
#define CPU_CYCLE_CNT			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xB0)))
#define TDM_CONTROL_0 			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xB4)))
#define TDM_CHANNEL_0 			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xB8)))
#define TDM_FIFO_ADDR_0			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xBC)))
#define TDM_OUT_POINTER_0 		(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xC0)))
#define TDM_OUT_STATUS_0 		(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xC4)))
#define TDM_CONTROL_1 			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xC8)))
#define TDM_CHANNEL_1 			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xCC)))
#define TDM_FIFO_ADDR_1 		(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xD0)))
#define TDM_OUT_POINTER_1 		(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xD4)))
#define TDM_OUT_STATUS_1 		(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xD8)))
//0xDC RFU
#define FIFO_CONFIG_4			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xE0)))
#define FIFO_CONFIG_5			(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xE4)))
//0xE8~0xEC RFU
#define LM_VERSION 				(*((volatile uint32_t *)(LM_REG_BASE_ADDR + 0xF0)))
//0xF4~0xFF RFU


#ifdef  __cplusplus
}
#endif


#endif /* REG_LM_H_ */

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#ifndef _REG_LM_H_
#define _REG_LM_H_

#include <stdint.h>
#include "_reg_lm.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_LM_COUNT 61

#define REG_LM_DECODING_MASK 0x000000FF

/**
 * @brief FIFO_INT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     13         OUT_THRE_INT   0
 *     12          IN_THRE_INT   0
 *     11            TDM_OUT_1   0
 *     10            TDM_OUT_0   0
 *     09        I2S_OUT_R_INT   0
 *     08        I2S_OUT_L_INT   0
 *     07             DAC1_INT   0
 *     06             DAC0_INT   0
 *     05         I2S_IN_R_INT   0
 *     04         I2S_IN_L_INT   0
 *     03             TDM_IN_1   0
 *     02             TDM_IN_0   0
 *     00             ADC0_INT   0
 * </pre>
 */
#define LM_FIFO_INT_STATUS_ADDR   0x0005FF00
#define LM_FIFO_INT_STATUS_OFFSET 0x00000000
#define LM_FIFO_INT_STATUS_INDEX  0x00000000
#define LM_FIFO_INT_STATUS_RESET  0x00000000

__INLINE uint32_t lm_fifo_int_status_get(void)
{
    return REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
}

// field definitions
#define LM_FIFO_INT_STATUS_OUT_THRE_INT_BIT     ((uint32_t)0x00002000)
#define LM_FIFO_INT_STATUS_OUT_THRE_INT_POS     13
#define LM_FIFO_INT_STATUS_IN_THRE_INT_BIT      ((uint32_t)0x00001000)
#define LM_FIFO_INT_STATUS_IN_THRE_INT_POS      12
#define LM_FIFO_INT_STATUS_TDM_OUT_1_BIT        ((uint32_t)0x00000800)
#define LM_FIFO_INT_STATUS_TDM_OUT_1_POS        11
#define LM_FIFO_INT_STATUS_TDM_OUT_0_BIT        ((uint32_t)0x00000400)
#define LM_FIFO_INT_STATUS_TDM_OUT_0_POS        10
#define LM_FIFO_INT_STATUS_I2S_OUT_R_INT_BIT    ((uint32_t)0x00000200)
#define LM_FIFO_INT_STATUS_I2S_OUT_R_INT_POS    9
#define LM_FIFO_INT_STATUS_I2S_OUT_L_INT_BIT    ((uint32_t)0x00000100)
#define LM_FIFO_INT_STATUS_I2S_OUT_L_INT_POS    8
#define LM_FIFO_INT_STATUS_DAC1_INT_BIT         ((uint32_t)0x00000080)
#define LM_FIFO_INT_STATUS_DAC1_INT_POS         7
#define LM_FIFO_INT_STATUS_DAC0_INT_BIT         ((uint32_t)0x00000040)
#define LM_FIFO_INT_STATUS_DAC0_INT_POS         6
#define LM_FIFO_INT_STATUS_I2S_IN_R_INT_BIT     ((uint32_t)0x00000020)
#define LM_FIFO_INT_STATUS_I2S_IN_R_INT_POS     5
#define LM_FIFO_INT_STATUS_I2S_IN_L_INT_BIT     ((uint32_t)0x00000010)
#define LM_FIFO_INT_STATUS_I2S_IN_L_INT_POS     4
#define LM_FIFO_INT_STATUS_TDM_IN_1_BIT         ((uint32_t)0x00000008)
#define LM_FIFO_INT_STATUS_TDM_IN_1_POS         3
#define LM_FIFO_INT_STATUS_TDM_IN_0_BIT         ((uint32_t)0x00000004)
#define LM_FIFO_INT_STATUS_TDM_IN_0_POS         2
#define LM_FIFO_INT_STATUS_ADC0_INT_BIT         ((uint32_t)0x00000001)
#define LM_FIFO_INT_STATUS_ADC0_INT_POS         0

#define LM_FIFO_INT_STATUS_OUT_THRE_INT_RST     0x0
#define LM_FIFO_INT_STATUS_IN_THRE_INT_RST      0x0
#define LM_FIFO_INT_STATUS_TDM_OUT_1_RST        0x0
#define LM_FIFO_INT_STATUS_TDM_OUT_0_RST        0x0
#define LM_FIFO_INT_STATUS_I2S_OUT_R_INT_RST    0x0
#define LM_FIFO_INT_STATUS_I2S_OUT_L_INT_RST    0x0
#define LM_FIFO_INT_STATUS_DAC1_INT_RST         0x0
#define LM_FIFO_INT_STATUS_DAC0_INT_RST         0x0
#define LM_FIFO_INT_STATUS_I2S_IN_R_INT_RST     0x0
#define LM_FIFO_INT_STATUS_I2S_IN_L_INT_RST     0x0
#define LM_FIFO_INT_STATUS_TDM_IN_1_RST         0x0
#define LM_FIFO_INT_STATUS_TDM_IN_0_RST         0x0
#define LM_FIFO_INT_STATUS_ADC0_INT_RST         0x0

__INLINE void lm_fifo_int_status_unpack(uint8_t* outthreint, uint8_t* inthreint, uint8_t* tdmout1, uint8_t* tdmout0, uint8_t* i2soutrint, uint8_t* i2soutlint, uint8_t* dac1int, uint8_t* dac0int, uint8_t* i2sinrint, uint8_t* i2sinlint, uint8_t* tdmin1, uint8_t* tdmin0, uint8_t* adc0int)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    *outthreint = (localVal & ((uint32_t)0x00002000)) >> 13;
    *inthreint = (localVal & ((uint32_t)0x00001000)) >> 12;
    *tdmout1 = (localVal & ((uint32_t)0x00000800)) >> 11;
    *tdmout0 = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2soutrint = (localVal & ((uint32_t)0x00000200)) >> 9;
    *i2soutlint = (localVal & ((uint32_t)0x00000100)) >> 8;
    *dac1int = (localVal & ((uint32_t)0x00000080)) >> 7;
    *dac0int = (localVal & ((uint32_t)0x00000040)) >> 6;
    *i2sinrint = (localVal & ((uint32_t)0x00000020)) >> 5;
    *i2sinlint = (localVal & ((uint32_t)0x00000010)) >> 4;
    *tdmin1 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *tdmin0 = (localVal & ((uint32_t)0x00000004)) >> 2;
    *adc0int = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t lm_fifo_int_status_out_thre_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE uint8_t lm_fifo_int_status_in_thre_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE uint8_t lm_fifo_int_status_tdm_out_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t lm_fifo_int_status_tdm_out_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t lm_fifo_int_status_i2s_out_r_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t lm_fifo_int_status_i2s_out_l_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t lm_fifo_int_status_dac1_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t lm_fifo_int_status_dac0_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t lm_fifo_int_status_i2s_in_r_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t lm_fifo_int_status_i2s_in_l_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t lm_fifo_int_status_tdm_in_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t lm_fifo_int_status_tdm_in_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t lm_fifo_int_status_adc0_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_INT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief FIFO_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     30            RAM_3_ILM   0
 *     29            RAM_2_ILM   0
 *     24          PERF_CNT_EN   0
 *  22:16        FIFO_INT_EN_2   0x0
 *  14:08        FIFO_INT_EN_1   0x0
 *  07:04              OUT_SEL   0x0
 *  03:00               IN_SEL   0x0
 * </pre>
 */
#define LM_FIFO_CONFIG_ADDR   0x0005FF04
#define LM_FIFO_CONFIG_OFFSET 0x00000004
#define LM_FIFO_CONFIG_INDEX  0x00000001
#define LM_FIFO_CONFIG_RESET  0x00000000

__INLINE uint32_t lm_fifo_config_get(void)
{
    return REG_PL_RD(LM_FIFO_CONFIG_ADDR);
}

__INLINE void lm_fifo_config_set(uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, value);
}

// field definitions
#define LM_FIFO_CONFIG_RAM_3_ILM_BIT        ((uint32_t)0x40000000)
#define LM_FIFO_CONFIG_RAM_3_ILM_POS        30
#define LM_FIFO_CONFIG_RAM_2_ILM_BIT        ((uint32_t)0x20000000)
#define LM_FIFO_CONFIG_RAM_2_ILM_POS        29
#define LM_FIFO_CONFIG_PERF_CNT_EN_BIT      ((uint32_t)0x01000000)
#define LM_FIFO_CONFIG_PERF_CNT_EN_POS      24
#define LM_FIFO_CONFIG_FIFO_INT_EN_2_MASK   ((uint32_t)0x007F0000)
#define LM_FIFO_CONFIG_FIFO_INT_EN_2_LSB    16
#define LM_FIFO_CONFIG_FIFO_INT_EN_2_WIDTH  ((uint32_t)0x00000007)
#define LM_FIFO_CONFIG_FIFO_INT_EN_1_MASK   ((uint32_t)0x00007F00)
#define LM_FIFO_CONFIG_FIFO_INT_EN_1_LSB    8
#define LM_FIFO_CONFIG_FIFO_INT_EN_1_WIDTH  ((uint32_t)0x00000007)
#define LM_FIFO_CONFIG_OUT_SEL_MASK         ((uint32_t)0x000000F0)
#define LM_FIFO_CONFIG_OUT_SEL_LSB          4
#define LM_FIFO_CONFIG_OUT_SEL_WIDTH        ((uint32_t)0x00000004)
#define LM_FIFO_CONFIG_IN_SEL_MASK          ((uint32_t)0x0000000F)
#define LM_FIFO_CONFIG_IN_SEL_LSB           0
#define LM_FIFO_CONFIG_IN_SEL_WIDTH         ((uint32_t)0x00000004)

#define LM_FIFO_CONFIG_RAM_3_ILM_RST        0x0
#define LM_FIFO_CONFIG_RAM_2_ILM_RST        0x0
#define LM_FIFO_CONFIG_PERF_CNT_EN_RST      0x0
#define LM_FIFO_CONFIG_FIFO_INT_EN_2_RST    0x0
#define LM_FIFO_CONFIG_FIFO_INT_EN_1_RST    0x0
#define LM_FIFO_CONFIG_OUT_SEL_RST          0x0
#define LM_FIFO_CONFIG_IN_SEL_RST           0x0

__INLINE void lm_fifo_config_pack(uint8_t ram3ilm, uint8_t ram2ilm, uint8_t perfcnten, uint8_t fifointen2, uint8_t fifointen1, uint8_t outsel, uint8_t insel)
{
    ASSERT_ERR((((uint32_t)ram3ilm << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)ram2ilm << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)perfcnten << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)fifointen2 << 16) & ~((uint32_t)0x007F0000)) == 0);
    ASSERT_ERR((((uint32_t)fifointen1 << 8) & ~((uint32_t)0x00007F00)) == 0);
    ASSERT_ERR((((uint32_t)outsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)insel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR,  ((uint32_t)ram3ilm << 30) | ((uint32_t)ram2ilm << 29) | ((uint32_t)perfcnten << 24) | ((uint32_t)fifointen2 << 16) | ((uint32_t)fifointen1 << 8) | ((uint32_t)outsel << 4) | ((uint32_t)insel << 0));
}

__INLINE void lm_fifo_config_unpack(uint8_t* ram3ilm, uint8_t* ram2ilm, uint8_t* perfcnten, uint8_t* fifointen2, uint8_t* fifointen1, uint8_t* outsel, uint8_t* insel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    *ram3ilm = (localVal & ((uint32_t)0x40000000)) >> 30;
    *ram2ilm = (localVal & ((uint32_t)0x20000000)) >> 29;
    *perfcnten = (localVal & ((uint32_t)0x01000000)) >> 24;
    *fifointen2 = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *fifointen1 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *outsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *insel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t lm_fifo_config_ram_3_ilm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void lm_fifo_config_ram_3_ilm_setf(uint8_t ram3ilm)
{
    ASSERT_ERR((((uint32_t)ram3ilm << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)ram3ilm << 30));
}

__INLINE uint8_t lm_fifo_config_ram_2_ilm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void lm_fifo_config_ram_2_ilm_setf(uint8_t ram2ilm)
{
    ASSERT_ERR((((uint32_t)ram2ilm << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)ram2ilm << 29));
}

__INLINE uint8_t lm_fifo_config_perf_cnt_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void lm_fifo_config_perf_cnt_en_setf(uint8_t perfcnten)
{
    ASSERT_ERR((((uint32_t)perfcnten << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)perfcnten << 24));
}

__INLINE uint8_t lm_fifo_config_fifo_int_en_2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

__INLINE void lm_fifo_config_fifo_int_en_2_setf(uint8_t fifointen2)
{
    ASSERT_ERR((((uint32_t)fifointen2 << 16) & ~((uint32_t)0x007F0000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)fifointen2 << 16));
}

__INLINE uint8_t lm_fifo_config_fifo_int_en_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

__INLINE void lm_fifo_config_fifo_int_en_1_setf(uint8_t fifointen1)
{
    ASSERT_ERR((((uint32_t)fifointen1 << 8) & ~((uint32_t)0x00007F00)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)fifointen1 << 8));
}

__INLINE uint8_t lm_fifo_config_out_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void lm_fifo_config_out_sel_setf(uint8_t outsel)
{
    ASSERT_ERR((((uint32_t)outsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)outsel << 4));
}

__INLINE uint8_t lm_fifo_config_in_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void lm_fifo_config_in_sel_setf(uint8_t insel)
{
    ASSERT_ERR((((uint32_t)insel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)insel << 0));
}

/**
 * @brief FIFO_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31              FIFO_EN   0
 *     30          FIFO_INT_EN   0
 *     29          DATA_ADJUST   0
 *     28            DATA_SIZE   0
 *  27:16             FIFO_LEN   0x0
 *  15:00           START_ADDR   0x0
 * </pre>
 */
#define LM_FIFO_CONTROL_ADDR   0x0005FF08
#define LM_FIFO_CONTROL_OFFSET 0x00000008
#define LM_FIFO_CONTROL_INDEX  0x00000002
#define LM_FIFO_CONTROL_RESET  0x00000000
#define LM_FIFO_CONTROL_COUNT  10

__INLINE uint32_t lm_fifo_control_get(int reg_idx)
{
    return REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
}

__INLINE void lm_fifo_control_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, value);
}

// field definitions
#define LM_FIFO_CONTROL_FIFO_EN_BIT        ((uint32_t)0x80000000)
#define LM_FIFO_CONTROL_FIFO_EN_POS        31
#define LM_FIFO_CONTROL_FIFO_INT_EN_BIT    ((uint32_t)0x40000000)
#define LM_FIFO_CONTROL_FIFO_INT_EN_POS    30
#define LM_FIFO_CONTROL_DATA_ADJUST_BIT    ((uint32_t)0x20000000)
#define LM_FIFO_CONTROL_DATA_ADJUST_POS    29
#define LM_FIFO_CONTROL_DATA_SIZE_BIT      ((uint32_t)0x10000000)
#define LM_FIFO_CONTROL_DATA_SIZE_POS      28
#define LM_FIFO_CONTROL_FIFO_LEN_MASK      ((uint32_t)0x0FFF0000)
#define LM_FIFO_CONTROL_FIFO_LEN_LSB       16
#define LM_FIFO_CONTROL_FIFO_LEN_WIDTH     ((uint32_t)0x0000000C)
#define LM_FIFO_CONTROL_START_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define LM_FIFO_CONTROL_START_ADDR_LSB     0
#define LM_FIFO_CONTROL_START_ADDR_WIDTH   ((uint32_t)0x00000010)

#define LM_FIFO_CONTROL_FIFO_EN_RST        0x0
#define LM_FIFO_CONTROL_FIFO_INT_EN_RST    0x0
#define LM_FIFO_CONTROL_DATA_ADJUST_RST    0x0
#define LM_FIFO_CONTROL_DATA_SIZE_RST      0x0
#define LM_FIFO_CONTROL_FIFO_LEN_RST       0x0
#define LM_FIFO_CONTROL_START_ADDR_RST     0x0

__INLINE void lm_fifo_control_pack(int reg_idx, uint8_t fifoen, uint8_t fifointen, uint8_t dataadjust, uint8_t datasize, uint16_t fifolen, uint16_t startaddr)
{
    ASSERT_ERR((((uint32_t)fifoen << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)fifointen << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)dataadjust << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)datasize << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)fifolen << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)startaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4,  ((uint32_t)fifoen << 31) | ((uint32_t)fifointen << 30) | ((uint32_t)dataadjust << 29) | ((uint32_t)datasize << 28) | ((uint32_t)fifolen << 16) | ((uint32_t)startaddr << 0));
}

__INLINE void lm_fifo_control_unpack(int reg_idx, uint8_t* fifoen, uint8_t* fifointen, uint8_t* dataadjust, uint8_t* datasize, uint16_t* fifolen, uint16_t* startaddr)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    *fifoen = (localVal & ((uint32_t)0x80000000)) >> 31;
    *fifointen = (localVal & ((uint32_t)0x40000000)) >> 30;
    *dataadjust = (localVal & ((uint32_t)0x20000000)) >> 29;
    *datasize = (localVal & ((uint32_t)0x10000000)) >> 28;
    *fifolen = (localVal & ((uint32_t)0x0FFF0000)) >> 16;
    *startaddr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t lm_fifo_control_fifo_en_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void lm_fifo_control_fifo_en_setf(int reg_idx, uint8_t fifoen)
{
    ASSERT_ERR((((uint32_t)fifoen << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x80000000)) | ((uint32_t)fifoen << 31));
}

__INLINE uint8_t lm_fifo_control_fifo_int_en_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void lm_fifo_control_fifo_int_en_setf(int reg_idx, uint8_t fifointen)
{
    ASSERT_ERR((((uint32_t)fifointen << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x40000000)) | ((uint32_t)fifointen << 30));
}

__INLINE uint8_t lm_fifo_control_data_adjust_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void lm_fifo_control_data_adjust_setf(int reg_idx, uint8_t dataadjust)
{
    ASSERT_ERR((((uint32_t)dataadjust << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x20000000)) | ((uint32_t)dataadjust << 29));
}

__INLINE uint8_t lm_fifo_control_data_size_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void lm_fifo_control_data_size_setf(int reg_idx, uint8_t datasize)
{
    ASSERT_ERR((((uint32_t)datasize << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x10000000)) | ((uint32_t)datasize << 28));
}

__INLINE uint16_t lm_fifo_control_fifo_len_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}

__INLINE void lm_fifo_control_fifo_len_setf(int reg_idx, uint16_t fifolen)
{
    ASSERT_ERR((((uint32_t)fifolen << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)fifolen << 16));
}

__INLINE uint16_t lm_fifo_control_start_addr_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_fifo_control_start_addr_setf(int reg_idx, uint16_t startaddr)
{
    ASSERT_ERR((((uint32_t)startaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_CONTROL_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_CONTROL_ADDR + reg_idx * 4) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)startaddr << 0));
}

/**
 * @brief FIFO_POINTER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16               RD_PTR   0x0
 *  15:00               WR_PTR   0x0
 * </pre>
 */
#define LM_FIFO_POINTER_ADDR   0x0005FF30
#define LM_FIFO_POINTER_OFFSET 0x00000030
#define LM_FIFO_POINTER_INDEX  0x0000000C
#define LM_FIFO_POINTER_RESET  0x00000000
#define LM_FIFO_POINTER_COUNT  10

__INLINE uint32_t lm_fifo_pointer_get(int reg_idx)
{
    return REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4);
}

__INLINE void lm_fifo_pointer_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(LM_FIFO_POINTER_ADDR + reg_idx * 4, value);
}

// field definitions
#define LM_FIFO_POINTER_RD_PTR_MASK   ((uint32_t)0xFFFF0000)
#define LM_FIFO_POINTER_RD_PTR_LSB    16
#define LM_FIFO_POINTER_RD_PTR_WIDTH  ((uint32_t)0x00000010)
#define LM_FIFO_POINTER_WR_PTR_MASK   ((uint32_t)0x0000FFFF)
#define LM_FIFO_POINTER_WR_PTR_LSB    0
#define LM_FIFO_POINTER_WR_PTR_WIDTH  ((uint32_t)0x00000010)

#define LM_FIFO_POINTER_RD_PTR_RST    0x0
#define LM_FIFO_POINTER_WR_PTR_RST    0x0

__INLINE void lm_fifo_pointer_pack(int reg_idx, uint16_t rdptr, uint16_t wrptr)
{
    ASSERT_ERR((((uint32_t)rdptr << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)wrptr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_POINTER_ADDR + reg_idx * 4,  ((uint32_t)rdptr << 16) | ((uint32_t)wrptr << 0));
}

__INLINE void lm_fifo_pointer_unpack(int reg_idx, uint16_t* rdptr, uint16_t* wrptr)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4);
    *rdptr = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *wrptr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint16_t lm_fifo_pointer_rd_ptr_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE void lm_fifo_pointer_rd_ptr_setf(int reg_idx, uint16_t rdptr)
{
    ASSERT_ERR((((uint32_t)rdptr << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(LM_FIFO_POINTER_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rdptr << 16));
}

__INLINE uint16_t lm_fifo_pointer_wr_ptr_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_fifo_pointer_wr_ptr_setf(int reg_idx, uint16_t wrptr)
{
    ASSERT_ERR((((uint32_t)wrptr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_POINTER_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_POINTER_ADDR + reg_idx * 4) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)wrptr << 0));
}

/**
 * @brief FIFO_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     22        FIFO_OVERFLOW   0
 *     21       FIFO_UNDERFLOW   0
 *     20            FIFO_FULL   0
 *     19              FIFO_AF   0
 *     18              FIFO_HF   0
 *     17              FIFO_AE   0
 *     16           FIFO_EMPTY   0
 *  15:00             DATA_NUM   0x0
 * </pre>
 */
#define LM_FIFO_STATUS_ADDR   0x0005FF58
#define LM_FIFO_STATUS_OFFSET 0x00000058
#define LM_FIFO_STATUS_INDEX  0x00000016
#define LM_FIFO_STATUS_RESET  0x00000000
#define LM_FIFO_STATUS_COUNT  10

__INLINE uint32_t lm_fifo_status_get(int reg_idx)
{
    return REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
}

__INLINE void lm_fifo_status_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(LM_FIFO_STATUS_ADDR + reg_idx * 4, value);
}

// field definitions
#define LM_FIFO_STATUS_FIFO_OVERFLOW_BIT     ((uint32_t)0x00400000)
#define LM_FIFO_STATUS_FIFO_OVERFLOW_POS     22
#define LM_FIFO_STATUS_FIFO_UNDERFLOW_BIT    ((uint32_t)0x00200000)
#define LM_FIFO_STATUS_FIFO_UNDERFLOW_POS    21
#define LM_FIFO_STATUS_FIFO_FULL_BIT         ((uint32_t)0x00100000)
#define LM_FIFO_STATUS_FIFO_FULL_POS         20
#define LM_FIFO_STATUS_FIFO_AF_BIT           ((uint32_t)0x00080000)
#define LM_FIFO_STATUS_FIFO_AF_POS           19
#define LM_FIFO_STATUS_FIFO_HF_BIT           ((uint32_t)0x00040000)
#define LM_FIFO_STATUS_FIFO_HF_POS           18
#define LM_FIFO_STATUS_FIFO_AE_BIT           ((uint32_t)0x00020000)
#define LM_FIFO_STATUS_FIFO_AE_POS           17
#define LM_FIFO_STATUS_FIFO_EMPTY_BIT        ((uint32_t)0x00010000)
#define LM_FIFO_STATUS_FIFO_EMPTY_POS        16
#define LM_FIFO_STATUS_DATA_NUM_MASK         ((uint32_t)0x0000FFFF)
#define LM_FIFO_STATUS_DATA_NUM_LSB          0
#define LM_FIFO_STATUS_DATA_NUM_WIDTH        ((uint32_t)0x00000010)

#define LM_FIFO_STATUS_FIFO_OVERFLOW_RST     0x0
#define LM_FIFO_STATUS_FIFO_UNDERFLOW_RST    0x0
#define LM_FIFO_STATUS_FIFO_FULL_RST         0x0
#define LM_FIFO_STATUS_FIFO_AF_RST           0x0
#define LM_FIFO_STATUS_FIFO_HF_RST           0x0
#define LM_FIFO_STATUS_FIFO_AE_RST           0x0
#define LM_FIFO_STATUS_FIFO_EMPTY_RST        0x0
#define LM_FIFO_STATUS_DATA_NUM_RST          0x0

__INLINE void lm_fifo_status_unpack(int reg_idx, uint8_t* fifooverflow, uint8_t* fifounderflow, uint8_t* fifofull, uint8_t* fifoaf, uint8_t* fifohf, uint8_t* fifoae, uint8_t* fifoempty, uint16_t* datanum)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    *fifooverflow = (localVal & ((uint32_t)0x00400000)) >> 22;
    *fifounderflow = (localVal & ((uint32_t)0x00200000)) >> 21;
    *fifofull = (localVal & ((uint32_t)0x00100000)) >> 20;
    *fifoaf = (localVal & ((uint32_t)0x00080000)) >> 19;
    *fifohf = (localVal & ((uint32_t)0x00040000)) >> 18;
    *fifoae = (localVal & ((uint32_t)0x00020000)) >> 17;
    *fifoempty = (localVal & ((uint32_t)0x00010000)) >> 16;
    *datanum = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t lm_fifo_status_fifo_overflow_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t lm_fifo_status_fifo_underflow_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE uint8_t lm_fifo_status_fifo_full_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE uint8_t lm_fifo_status_fifo_af_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE uint8_t lm_fifo_status_fifo_hf_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t lm_fifo_status_fifo_ae_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE uint8_t lm_fifo_status_fifo_empty_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE uint16_t lm_fifo_status_data_num_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_STATUS_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief FIFO_THRE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16              AF_THRE   0x0
 *  15:00              AE_THRE   0x0
 * </pre>
 */
#define LM_FIFO_THRE_ADDR   0x0005FF80
#define LM_FIFO_THRE_OFFSET 0x00000080
#define LM_FIFO_THRE_INDEX  0x00000020
#define LM_FIFO_THRE_RESET  0x00000000
#define LM_FIFO_THRE_COUNT  10

__INLINE uint32_t lm_fifo_thre_get(int reg_idx)
{
    return REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4);
}

__INLINE void lm_fifo_thre_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(LM_FIFO_THRE_ADDR + reg_idx * 4, value);
}

// field definitions
#define LM_FIFO_THRE_AF_THRE_MASK   ((uint32_t)0xFFFF0000)
#define LM_FIFO_THRE_AF_THRE_LSB    16
#define LM_FIFO_THRE_AF_THRE_WIDTH  ((uint32_t)0x00000010)
#define LM_FIFO_THRE_AE_THRE_MASK   ((uint32_t)0x0000FFFF)
#define LM_FIFO_THRE_AE_THRE_LSB    0
#define LM_FIFO_THRE_AE_THRE_WIDTH  ((uint32_t)0x00000010)

#define LM_FIFO_THRE_AF_THRE_RST    0x0
#define LM_FIFO_THRE_AE_THRE_RST    0x0

__INLINE void lm_fifo_thre_pack(int reg_idx, uint16_t afthre, uint16_t aethre)
{
    ASSERT_ERR((((uint32_t)afthre << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)aethre << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_THRE_ADDR + reg_idx * 4,  ((uint32_t)afthre << 16) | ((uint32_t)aethre << 0));
}

__INLINE void lm_fifo_thre_unpack(int reg_idx, uint16_t* afthre, uint16_t* aethre)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4);
    *afthre = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *aethre = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint16_t lm_fifo_thre_af_thre_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE void lm_fifo_thre_af_thre_setf(int reg_idx, uint16_t afthre)
{
    ASSERT_ERR((((uint32_t)afthre << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(LM_FIFO_THRE_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)afthre << 16));
}

__INLINE uint16_t lm_fifo_thre_ae_thre_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 9);

    localVal = REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_fifo_thre_ae_thre_setf(int reg_idx, uint16_t aethre)
{
    ASSERT_ERR((((uint32_t)aethre << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_FIFO_THRE_ADDR + reg_idx * 4, (REG_PL_RD(LM_FIFO_THRE_ADDR + reg_idx * 4) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)aethre << 0));
}

/**
 * @brief FIFO_CONFIG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31          OUT_THRE_EN   0
 *  30:16             OUT_THRE   0x0
 *     15           IN_THRE_EN   0
 *  14:00              IN_THRE   0x0
 * </pre>
 */
#define LM_FIFO_CONFIG_2_ADDR   0x0005FFA8
#define LM_FIFO_CONFIG_2_OFFSET 0x000000A8
#define LM_FIFO_CONFIG_2_INDEX  0x0000002A
#define LM_FIFO_CONFIG_2_RESET  0x00000000

__INLINE uint32_t lm_fifo_config_2_get(void)
{
    return REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
}

__INLINE void lm_fifo_config_2_set(uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR, value);
}

// field definitions
#define LM_FIFO_CONFIG_2_OUT_THRE_EN_BIT    ((uint32_t)0x80000000)
#define LM_FIFO_CONFIG_2_OUT_THRE_EN_POS    31
#define LM_FIFO_CONFIG_2_OUT_THRE_MASK      ((uint32_t)0x7FFF0000)
#define LM_FIFO_CONFIG_2_OUT_THRE_LSB       16
#define LM_FIFO_CONFIG_2_OUT_THRE_WIDTH     ((uint32_t)0x0000000F)
#define LM_FIFO_CONFIG_2_IN_THRE_EN_BIT     ((uint32_t)0x00008000)
#define LM_FIFO_CONFIG_2_IN_THRE_EN_POS     15
#define LM_FIFO_CONFIG_2_IN_THRE_MASK       ((uint32_t)0x00007FFF)
#define LM_FIFO_CONFIG_2_IN_THRE_LSB        0
#define LM_FIFO_CONFIG_2_IN_THRE_WIDTH      ((uint32_t)0x0000000F)

#define LM_FIFO_CONFIG_2_OUT_THRE_EN_RST    0x0
#define LM_FIFO_CONFIG_2_OUT_THRE_RST       0x0
#define LM_FIFO_CONFIG_2_IN_THRE_EN_RST     0x0
#define LM_FIFO_CONFIG_2_IN_THRE_RST        0x0

__INLINE void lm_fifo_config_2_pack(uint8_t outthreen, uint16_t outthre, uint8_t inthreen, uint16_t inthre)
{
    ASSERT_ERR((((uint32_t)outthreen << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)outthre << 16) & ~((uint32_t)0x7FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)inthreen << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)inthre << 0) & ~((uint32_t)0x00007FFF)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR,  ((uint32_t)outthreen << 31) | ((uint32_t)outthre << 16) | ((uint32_t)inthreen << 15) | ((uint32_t)inthre << 0));
}

__INLINE void lm_fifo_config_2_unpack(uint8_t* outthreen, uint16_t* outthre, uint8_t* inthreen, uint16_t* inthre)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
    *outthreen = (localVal & ((uint32_t)0x80000000)) >> 31;
    *outthre = (localVal & ((uint32_t)0x7FFF0000)) >> 16;
    *inthreen = (localVal & ((uint32_t)0x00008000)) >> 15;
    *inthre = (localVal & ((uint32_t)0x00007FFF)) >> 0;
}

__INLINE uint8_t lm_fifo_config_2_out_thre_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void lm_fifo_config_2_out_thre_en_setf(uint8_t outthreen)
{
    ASSERT_ERR((((uint32_t)outthreen << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_2_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)outthreen << 31));
}

__INLINE uint16_t lm_fifo_config_2_out_thre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
    return ((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}

__INLINE void lm_fifo_config_2_out_thre_setf(uint16_t outthre)
{
    ASSERT_ERR((((uint32_t)outthre << 16) & ~((uint32_t)0x7FFF0000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_2_ADDR) & ~((uint32_t)0x7FFF0000)) | ((uint32_t)outthre << 16));
}

__INLINE uint8_t lm_fifo_config_2_in_thre_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void lm_fifo_config_2_in_thre_en_setf(uint8_t inthreen)
{
    ASSERT_ERR((((uint32_t)inthreen << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)inthreen << 15));
}

__INLINE uint16_t lm_fifo_config_2_in_thre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_2_ADDR);
    return ((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

__INLINE void lm_fifo_config_2_in_thre_setf(uint16_t inthre)
{
    ASSERT_ERR((((uint32_t)inthre << 0) & ~((uint32_t)0x00007FFF)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_2_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_2_ADDR) & ~((uint32_t)0x00007FFF)) | ((uint32_t)inthre << 0));
}

/**
 * @brief FIFO_CONFIG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31   DLM_MODEM_SAME_CLK   1
 *     29         ROM_1_MARGIN   0
 *     28         ROM_0_MARGIN   0
 *  19:18        DCACHE_MARGIN   0x2
 *  17:16        ICACHE_MARGIN   0x2
 *     15     RAM_3_PWR_GSLEEP   0
 *     14         RAM_3_PWR_LV   0
 *  13:12         RAM_3_MARGIN   0x2
 *     11     RAM_2_PWR_GSLEEP   0
 *     10         RAM_2_PWR_LV   0
 *  09:08         RAM_2_MARGIN   0x2
 *     07     RAM_1_PWR_GSLEEP   0
 *     06         RAM_1_PWR_LV   0
 *  05:04         RAM_1_MARGIN   0x2
 *     02         RAM_0_PWR_LV   0
 *  01:00         RAM_0_MARGIN   0x2
 * </pre>
 */
#define LM_FIFO_CONFIG_3_ADDR   0x0005FFAC
#define LM_FIFO_CONFIG_3_OFFSET 0x000000AC
#define LM_FIFO_CONFIG_3_INDEX  0x0000002B
#define LM_FIFO_CONFIG_3_RESET  0x800A2222

__INLINE uint32_t lm_fifo_config_3_get(void)
{
    return REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
}

__INLINE void lm_fifo_config_3_set(uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, value);
}

// field definitions
#define LM_FIFO_CONFIG_3_DLM_MODEM_SAME_CLK_BIT    ((uint32_t)0x80000000)
#define LM_FIFO_CONFIG_3_DLM_MODEM_SAME_CLK_POS    31
#define LM_FIFO_CONFIG_3_ROM_1_MARGIN_BIT          ((uint32_t)0x20000000)
#define LM_FIFO_CONFIG_3_ROM_1_MARGIN_POS          29
#define LM_FIFO_CONFIG_3_ROM_0_MARGIN_BIT          ((uint32_t)0x10000000)
#define LM_FIFO_CONFIG_3_ROM_0_MARGIN_POS          28
#define LM_FIFO_CONFIG_3_DCACHE_MARGIN_MASK        ((uint32_t)0x000C0000)
#define LM_FIFO_CONFIG_3_DCACHE_MARGIN_LSB         18
#define LM_FIFO_CONFIG_3_DCACHE_MARGIN_WIDTH       ((uint32_t)0x00000002)
#define LM_FIFO_CONFIG_3_ICACHE_MARGIN_MASK        ((uint32_t)0x00030000)
#define LM_FIFO_CONFIG_3_ICACHE_MARGIN_LSB         16
#define LM_FIFO_CONFIG_3_ICACHE_MARGIN_WIDTH       ((uint32_t)0x00000002)
#define LM_FIFO_CONFIG_3_RAM_3_PWR_GSLEEP_BIT      ((uint32_t)0x00008000)
#define LM_FIFO_CONFIG_3_RAM_3_PWR_GSLEEP_POS      15
#define LM_FIFO_CONFIG_3_RAM_3_PWR_LV_BIT          ((uint32_t)0x00004000)
#define LM_FIFO_CONFIG_3_RAM_3_PWR_LV_POS          14
#define LM_FIFO_CONFIG_3_RAM_3_MARGIN_MASK         ((uint32_t)0x00003000)
#define LM_FIFO_CONFIG_3_RAM_3_MARGIN_LSB          12
#define LM_FIFO_CONFIG_3_RAM_3_MARGIN_WIDTH        ((uint32_t)0x00000002)
#define LM_FIFO_CONFIG_3_RAM_2_PWR_GSLEEP_BIT      ((uint32_t)0x00000800)
#define LM_FIFO_CONFIG_3_RAM_2_PWR_GSLEEP_POS      11
#define LM_FIFO_CONFIG_3_RAM_2_PWR_LV_BIT          ((uint32_t)0x00000400)
#define LM_FIFO_CONFIG_3_RAM_2_PWR_LV_POS          10
#define LM_FIFO_CONFIG_3_RAM_2_MARGIN_MASK         ((uint32_t)0x00000300)
#define LM_FIFO_CONFIG_3_RAM_2_MARGIN_LSB          8
#define LM_FIFO_CONFIG_3_RAM_2_MARGIN_WIDTH        ((uint32_t)0x00000002)
#define LM_FIFO_CONFIG_3_RAM_1_PWR_GSLEEP_BIT      ((uint32_t)0x00000080)
#define LM_FIFO_CONFIG_3_RAM_1_PWR_GSLEEP_POS      7
#define LM_FIFO_CONFIG_3_RAM_1_PWR_LV_BIT          ((uint32_t)0x00000040)
#define LM_FIFO_CONFIG_3_RAM_1_PWR_LV_POS          6
#define LM_FIFO_CONFIG_3_RAM_1_MARGIN_MASK         ((uint32_t)0x00000030)
#define LM_FIFO_CONFIG_3_RAM_1_MARGIN_LSB          4
#define LM_FIFO_CONFIG_3_RAM_1_MARGIN_WIDTH        ((uint32_t)0x00000002)
#define LM_FIFO_CONFIG_3_RAM_0_PWR_LV_BIT          ((uint32_t)0x00000004)
#define LM_FIFO_CONFIG_3_RAM_0_PWR_LV_POS          2
#define LM_FIFO_CONFIG_3_RAM_0_MARGIN_MASK         ((uint32_t)0x00000003)
#define LM_FIFO_CONFIG_3_RAM_0_MARGIN_LSB          0
#define LM_FIFO_CONFIG_3_RAM_0_MARGIN_WIDTH        ((uint32_t)0x00000002)

#define LM_FIFO_CONFIG_3_DLM_MODEM_SAME_CLK_RST    0x1
#define LM_FIFO_CONFIG_3_ROM_1_MARGIN_RST          0x0
#define LM_FIFO_CONFIG_3_ROM_0_MARGIN_RST          0x0
#define LM_FIFO_CONFIG_3_DCACHE_MARGIN_RST         0x2
#define LM_FIFO_CONFIG_3_ICACHE_MARGIN_RST         0x2
#define LM_FIFO_CONFIG_3_RAM_3_PWR_GSLEEP_RST      0x0
#define LM_FIFO_CONFIG_3_RAM_3_PWR_LV_RST          0x0
#define LM_FIFO_CONFIG_3_RAM_3_MARGIN_RST          0x2
#define LM_FIFO_CONFIG_3_RAM_2_PWR_GSLEEP_RST      0x0
#define LM_FIFO_CONFIG_3_RAM_2_PWR_LV_RST          0x0
#define LM_FIFO_CONFIG_3_RAM_2_MARGIN_RST          0x2
#define LM_FIFO_CONFIG_3_RAM_1_PWR_GSLEEP_RST      0x0
#define LM_FIFO_CONFIG_3_RAM_1_PWR_LV_RST          0x0
#define LM_FIFO_CONFIG_3_RAM_1_MARGIN_RST          0x2
#define LM_FIFO_CONFIG_3_RAM_0_PWR_LV_RST          0x0
#define LM_FIFO_CONFIG_3_RAM_0_MARGIN_RST          0x2

__INLINE void lm_fifo_config_3_pack(uint8_t dlmmodemsameclk, uint8_t rom1margin, uint8_t rom0margin, uint8_t dcachemargin, uint8_t icachemargin, uint8_t ram3pwrgsleep, uint8_t ram3pwrlv, uint8_t ram3margin, uint8_t ram2pwrgsleep, uint8_t ram2pwrlv, uint8_t ram2margin, uint8_t ram1pwrgsleep, uint8_t ram1pwrlv, uint8_t ram1margin, uint8_t ram0pwrlv, uint8_t ram0margin)
{
    ASSERT_ERR((((uint32_t)dlmmodemsameclk << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)rom1margin << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)rom0margin << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)dcachemargin << 18) & ~((uint32_t)0x000C0000)) == 0);
    ASSERT_ERR((((uint32_t)icachemargin << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)ram3pwrgsleep << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)ram3pwrlv << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)ram3margin << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)ram2pwrgsleep << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)ram2pwrlv << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)ram2margin << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)ram1pwrgsleep << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)ram1pwrlv << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)ram1margin << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)ram0pwrlv << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)ram0margin << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR,  ((uint32_t)dlmmodemsameclk << 31) | ((uint32_t)rom1margin << 29) | ((uint32_t)rom0margin << 28) | ((uint32_t)dcachemargin << 18) | ((uint32_t)icachemargin << 16) | ((uint32_t)ram3pwrgsleep << 15) | ((uint32_t)ram3pwrlv << 14) | ((uint32_t)ram3margin << 12) | ((uint32_t)ram2pwrgsleep << 11) | ((uint32_t)ram2pwrlv << 10) | ((uint32_t)ram2margin << 8) | ((uint32_t)ram1pwrgsleep << 7) | ((uint32_t)ram1pwrlv << 6) | ((uint32_t)ram1margin << 4) | ((uint32_t)ram0pwrlv << 2) | ((uint32_t)ram0margin << 0));
}

__INLINE void lm_fifo_config_3_unpack(uint8_t* dlmmodemsameclk, uint8_t* rom1margin, uint8_t* rom0margin, uint8_t* dcachemargin, uint8_t* icachemargin, uint8_t* ram3pwrgsleep, uint8_t* ram3pwrlv, uint8_t* ram3margin, uint8_t* ram2pwrgsleep, uint8_t* ram2pwrlv, uint8_t* ram2margin, uint8_t* ram1pwrgsleep, uint8_t* ram1pwrlv, uint8_t* ram1margin, uint8_t* ram0pwrlv, uint8_t* ram0margin)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    *dlmmodemsameclk = (localVal & ((uint32_t)0x80000000)) >> 31;
    *rom1margin = (localVal & ((uint32_t)0x20000000)) >> 29;
    *rom0margin = (localVal & ((uint32_t)0x10000000)) >> 28;
    *dcachemargin = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *icachemargin = (localVal & ((uint32_t)0x00030000)) >> 16;
    *ram3pwrgsleep = (localVal & ((uint32_t)0x00008000)) >> 15;
    *ram3pwrlv = (localVal & ((uint32_t)0x00004000)) >> 14;
    *ram3margin = (localVal & ((uint32_t)0x00003000)) >> 12;
    *ram2pwrgsleep = (localVal & ((uint32_t)0x00000800)) >> 11;
    *ram2pwrlv = (localVal & ((uint32_t)0x00000400)) >> 10;
    *ram2margin = (localVal & ((uint32_t)0x00000300)) >> 8;
    *ram1pwrgsleep = (localVal & ((uint32_t)0x00000080)) >> 7;
    *ram1pwrlv = (localVal & ((uint32_t)0x00000040)) >> 6;
    *ram1margin = (localVal & ((uint32_t)0x00000030)) >> 4;
    *ram0pwrlv = (localVal & ((uint32_t)0x00000004)) >> 2;
    *ram0margin = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t lm_fifo_config_3_dlm_modem_same_clk_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void lm_fifo_config_3_dlm_modem_same_clk_setf(uint8_t dlmmodemsameclk)
{
    ASSERT_ERR((((uint32_t)dlmmodemsameclk << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)dlmmodemsameclk << 31));
}

__INLINE uint8_t lm_fifo_config_3_rom_1_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void lm_fifo_config_3_rom_1_margin_setf(uint8_t rom1margin)
{
    ASSERT_ERR((((uint32_t)rom1margin << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)rom1margin << 29));
}

__INLINE uint8_t lm_fifo_config_3_rom_0_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void lm_fifo_config_3_rom_0_margin_setf(uint8_t rom0margin)
{
    ASSERT_ERR((((uint32_t)rom0margin << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)rom0margin << 28));
}

__INLINE uint8_t lm_fifo_config_3_dcache_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void lm_fifo_config_3_dcache_margin_setf(uint8_t dcachemargin)
{
    ASSERT_ERR((((uint32_t)dcachemargin << 18) & ~((uint32_t)0x000C0000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)dcachemargin << 18));
}

__INLINE uint8_t lm_fifo_config_3_icache_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void lm_fifo_config_3_icache_margin_setf(uint8_t icachemargin)
{
    ASSERT_ERR((((uint32_t)icachemargin << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)icachemargin << 16));
}

__INLINE uint8_t lm_fifo_config_3_ram_3_pwr_gsleep_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void lm_fifo_config_3_ram_3_pwr_gsleep_setf(uint8_t ram3pwrgsleep)
{
    ASSERT_ERR((((uint32_t)ram3pwrgsleep << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)ram3pwrgsleep << 15));
}

__INLINE uint8_t lm_fifo_config_3_ram_3_pwr_lv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void lm_fifo_config_3_ram_3_pwr_lv_setf(uint8_t ram3pwrlv)
{
    ASSERT_ERR((((uint32_t)ram3pwrlv << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)ram3pwrlv << 14));
}

__INLINE uint8_t lm_fifo_config_3_ram_3_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void lm_fifo_config_3_ram_3_margin_setf(uint8_t ram3margin)
{
    ASSERT_ERR((((uint32_t)ram3margin << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)ram3margin << 12));
}

__INLINE uint8_t lm_fifo_config_3_ram_2_pwr_gsleep_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void lm_fifo_config_3_ram_2_pwr_gsleep_setf(uint8_t ram2pwrgsleep)
{
    ASSERT_ERR((((uint32_t)ram2pwrgsleep << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)ram2pwrgsleep << 11));
}

__INLINE uint8_t lm_fifo_config_3_ram_2_pwr_lv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void lm_fifo_config_3_ram_2_pwr_lv_setf(uint8_t ram2pwrlv)
{
    ASSERT_ERR((((uint32_t)ram2pwrlv << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)ram2pwrlv << 10));
}

__INLINE uint8_t lm_fifo_config_3_ram_2_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void lm_fifo_config_3_ram_2_margin_setf(uint8_t ram2margin)
{
    ASSERT_ERR((((uint32_t)ram2margin << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)ram2margin << 8));
}

__INLINE uint8_t lm_fifo_config_3_ram_1_pwr_gsleep_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void lm_fifo_config_3_ram_1_pwr_gsleep_setf(uint8_t ram1pwrgsleep)
{
    ASSERT_ERR((((uint32_t)ram1pwrgsleep << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)ram1pwrgsleep << 7));
}

__INLINE uint8_t lm_fifo_config_3_ram_1_pwr_lv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void lm_fifo_config_3_ram_1_pwr_lv_setf(uint8_t ram1pwrlv)
{
    ASSERT_ERR((((uint32_t)ram1pwrlv << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)ram1pwrlv << 6));
}

__INLINE uint8_t lm_fifo_config_3_ram_1_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void lm_fifo_config_3_ram_1_margin_setf(uint8_t ram1margin)
{
    ASSERT_ERR((((uint32_t)ram1margin << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)ram1margin << 4));
}

__INLINE uint8_t lm_fifo_config_3_ram_0_pwr_lv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void lm_fifo_config_3_ram_0_pwr_lv_setf(uint8_t ram0pwrlv)
{
    ASSERT_ERR((((uint32_t)ram0pwrlv << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ram0pwrlv << 2));
}

__INLINE uint8_t lm_fifo_config_3_ram_0_margin_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_3_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void lm_fifo_config_3_ram_0_margin_setf(uint8_t ram0margin)
{
    ASSERT_ERR((((uint32_t)ram0margin << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_3_ADDR, (REG_PL_RD(LM_FIFO_CONFIG_3_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)ram0margin << 0));
}

/**
 * @brief CPU_CYCLE_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00        CPU_CYCLE_CNT   0x0
 * </pre>
 */
#define LM_CPU_CYCLE_CNT_ADDR   0x0005FFB0
#define LM_CPU_CYCLE_CNT_OFFSET 0x000000B0
#define LM_CPU_CYCLE_CNT_INDEX  0x0000002C
#define LM_CPU_CYCLE_CNT_RESET  0x00000000

__INLINE uint32_t lm_cpu_cycle_cnt_get(void)
{
    return REG_PL_RD(LM_CPU_CYCLE_CNT_ADDR);
}

// field definitions
#define LM_CPU_CYCLE_CNT_CPU_CYCLE_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define LM_CPU_CYCLE_CNT_CPU_CYCLE_CNT_LSB    0
#define LM_CPU_CYCLE_CNT_CPU_CYCLE_CNT_WIDTH  ((uint32_t)0x00000020)

#define LM_CPU_CYCLE_CNT_CPU_CYCLE_CNT_RST    0x0

__INLINE uint32_t lm_cpu_cycle_cnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_CPU_CYCLE_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief TDM_CONTROL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31          TDM_PORT_EN   0
 *     30           TDM_INT_EN   0
 *     29           TDM_IO_SEL   0
 *  23:22      TDM_DATA_ADJUST   0x0
 *     21        TDM_DATA_SIZE   0
 *  19:16         TDM_FIFO_SEL   0x0
 *  11:00         TDM_FIFO_LEN   0x0
 * </pre>
 */
#define LM_TDM_CONTROL_0_ADDR   0x0005FFB4
#define LM_TDM_CONTROL_0_OFFSET 0x000000B4
#define LM_TDM_CONTROL_0_INDEX  0x0000002D
#define LM_TDM_CONTROL_0_RESET  0x00000000

__INLINE uint32_t lm_tdm_control_0_get(void)
{
    return REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
}

__INLINE void lm_tdm_control_0_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, value);
}

// field definitions
#define LM_TDM_CONTROL_0_TDM_PORT_EN_BIT        ((uint32_t)0x80000000)
#define LM_TDM_CONTROL_0_TDM_PORT_EN_POS        31
#define LM_TDM_CONTROL_0_TDM_INT_EN_BIT         ((uint32_t)0x40000000)
#define LM_TDM_CONTROL_0_TDM_INT_EN_POS         30
#define LM_TDM_CONTROL_0_TDM_IO_SEL_BIT         ((uint32_t)0x20000000)
#define LM_TDM_CONTROL_0_TDM_IO_SEL_POS         29
#define LM_TDM_CONTROL_0_TDM_DATA_ADJUST_MASK   ((uint32_t)0x00C00000)
#define LM_TDM_CONTROL_0_TDM_DATA_ADJUST_LSB    22
#define LM_TDM_CONTROL_0_TDM_DATA_ADJUST_WIDTH  ((uint32_t)0x00000002)
#define LM_TDM_CONTROL_0_TDM_DATA_SIZE_BIT      ((uint32_t)0x00200000)
#define LM_TDM_CONTROL_0_TDM_DATA_SIZE_POS      21
#define LM_TDM_CONTROL_0_TDM_FIFO_SEL_MASK      ((uint32_t)0x000F0000)
#define LM_TDM_CONTROL_0_TDM_FIFO_SEL_LSB       16
#define LM_TDM_CONTROL_0_TDM_FIFO_SEL_WIDTH     ((uint32_t)0x00000004)
#define LM_TDM_CONTROL_0_TDM_FIFO_LEN_MASK      ((uint32_t)0x00000FFF)
#define LM_TDM_CONTROL_0_TDM_FIFO_LEN_LSB       0
#define LM_TDM_CONTROL_0_TDM_FIFO_LEN_WIDTH     ((uint32_t)0x0000000C)

#define LM_TDM_CONTROL_0_TDM_PORT_EN_RST        0x0
#define LM_TDM_CONTROL_0_TDM_INT_EN_RST         0x0
#define LM_TDM_CONTROL_0_TDM_IO_SEL_RST         0x0
#define LM_TDM_CONTROL_0_TDM_DATA_ADJUST_RST    0x0
#define LM_TDM_CONTROL_0_TDM_DATA_SIZE_RST      0x0
#define LM_TDM_CONTROL_0_TDM_FIFO_SEL_RST       0x0
#define LM_TDM_CONTROL_0_TDM_FIFO_LEN_RST       0x0

__INLINE void lm_tdm_control_0_pack(uint8_t tdmporten, uint8_t tdminten, uint8_t tdmiosel, uint8_t tdmdataadjust, uint8_t tdmdatasize, uint8_t tdmfifosel, uint16_t tdmfifolen)
{
    ASSERT_ERR((((uint32_t)tdmporten << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)tdminten << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmiosel << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmdataadjust << 22) & ~((uint32_t)0x00C00000)) == 0);
    ASSERT_ERR((((uint32_t)tdmdatasize << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)tdmfifosel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)tdmfifolen << 0) & ~((uint32_t)0x00000FFF)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR,  ((uint32_t)tdmporten << 31) | ((uint32_t)tdminten << 30) | ((uint32_t)tdmiosel << 29) | ((uint32_t)tdmdataadjust << 22) | ((uint32_t)tdmdatasize << 21) | ((uint32_t)tdmfifosel << 16) | ((uint32_t)tdmfifolen << 0));
}

__INLINE void lm_tdm_control_0_unpack(uint8_t* tdmporten, uint8_t* tdminten, uint8_t* tdmiosel, uint8_t* tdmdataadjust, uint8_t* tdmdatasize, uint8_t* tdmfifosel, uint16_t* tdmfifolen)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    *tdmporten = (localVal & ((uint32_t)0x80000000)) >> 31;
    *tdminten = (localVal & ((uint32_t)0x40000000)) >> 30;
    *tdmiosel = (localVal & ((uint32_t)0x20000000)) >> 29;
    *tdmdataadjust = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *tdmdatasize = (localVal & ((uint32_t)0x00200000)) >> 21;
    *tdmfifosel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *tdmfifolen = (localVal & ((uint32_t)0x00000FFF)) >> 0;
}

__INLINE uint8_t lm_tdm_control_0_tdm_port_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void lm_tdm_control_0_tdm_port_en_setf(uint8_t tdmporten)
{
    ASSERT_ERR((((uint32_t)tdmporten << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)tdmporten << 31));
}

__INLINE uint8_t lm_tdm_control_0_tdm_int_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void lm_tdm_control_0_tdm_int_en_setf(uint8_t tdminten)
{
    ASSERT_ERR((((uint32_t)tdminten << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)tdminten << 30));
}

__INLINE uint8_t lm_tdm_control_0_tdm_io_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void lm_tdm_control_0_tdm_io_sel_setf(uint8_t tdmiosel)
{
    ASSERT_ERR((((uint32_t)tdmiosel << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)tdmiosel << 29));
}

__INLINE uint8_t lm_tdm_control_0_tdm_data_adjust_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void lm_tdm_control_0_tdm_data_adjust_setf(uint8_t tdmdataadjust)
{
    ASSERT_ERR((((uint32_t)tdmdataadjust << 22) & ~((uint32_t)0x00C00000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)tdmdataadjust << 22));
}

__INLINE uint8_t lm_tdm_control_0_tdm_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void lm_tdm_control_0_tdm_data_size_setf(uint8_t tdmdatasize)
{
    ASSERT_ERR((((uint32_t)tdmdatasize << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)tdmdatasize << 21));
}

__INLINE uint8_t lm_tdm_control_0_tdm_fifo_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void lm_tdm_control_0_tdm_fifo_sel_setf(uint8_t tdmfifosel)
{
    ASSERT_ERR((((uint32_t)tdmfifosel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)tdmfifosel << 16));
}

__INLINE uint16_t lm_tdm_control_0_tdm_fifo_len_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_0_ADDR);
    return ((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

__INLINE void lm_tdm_control_0_tdm_fifo_len_setf(uint16_t tdmfifolen)
{
    ASSERT_ERR((((uint32_t)tdmfifolen << 0) & ~((uint32_t)0x00000FFF)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_0_ADDR, (REG_PL_RD(LM_TDM_CONTROL_0_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)tdmfifolen << 0));
}

/**
 * @brief TDM_CHANNEL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:28          TDM_CNT_SEL   0x0
 *  27:16         TDM_CNT_THRE   0x0
 *  07:00       TDM_CHANNEL_EN   0x0
 * </pre>
 */
#define LM_TDM_CHANNEL_0_ADDR   0x0005FFB8
#define LM_TDM_CHANNEL_0_OFFSET 0x000000B8
#define LM_TDM_CHANNEL_0_INDEX  0x0000002E
#define LM_TDM_CHANNEL_0_RESET  0x00000000

__INLINE uint32_t lm_tdm_channel_0_get(void)
{
    return REG_PL_RD(LM_TDM_CHANNEL_0_ADDR);
}

__INLINE void lm_tdm_channel_0_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_CHANNEL_0_ADDR, value);
}

// field definitions
#define LM_TDM_CHANNEL_0_TDM_CNT_SEL_MASK      ((uint32_t)0xF0000000)
#define LM_TDM_CHANNEL_0_TDM_CNT_SEL_LSB       28
#define LM_TDM_CHANNEL_0_TDM_CNT_SEL_WIDTH     ((uint32_t)0x00000004)
#define LM_TDM_CHANNEL_0_TDM_CNT_THRE_MASK     ((uint32_t)0x0FFF0000)
#define LM_TDM_CHANNEL_0_TDM_CNT_THRE_LSB      16
#define LM_TDM_CHANNEL_0_TDM_CNT_THRE_WIDTH    ((uint32_t)0x0000000C)
#define LM_TDM_CHANNEL_0_TDM_CHANNEL_EN_MASK   ((uint32_t)0x000000FF)
#define LM_TDM_CHANNEL_0_TDM_CHANNEL_EN_LSB    0
#define LM_TDM_CHANNEL_0_TDM_CHANNEL_EN_WIDTH  ((uint32_t)0x00000008)

#define LM_TDM_CHANNEL_0_TDM_CNT_SEL_RST       0x0
#define LM_TDM_CHANNEL_0_TDM_CNT_THRE_RST      0x0
#define LM_TDM_CHANNEL_0_TDM_CHANNEL_EN_RST    0x0

__INLINE void lm_tdm_channel_0_pack(uint8_t tdmcntsel, uint16_t tdmcntthre, uint8_t tdmchannelen)
{
    ASSERT_ERR((((uint32_t)tdmcntsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmcntthre << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)tdmchannelen << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_0_ADDR,  ((uint32_t)tdmcntsel << 28) | ((uint32_t)tdmcntthre << 16) | ((uint32_t)tdmchannelen << 0));
}

__INLINE void lm_tdm_channel_0_unpack(uint8_t* tdmcntsel, uint16_t* tdmcntthre, uint8_t* tdmchannelen)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_0_ADDR);
    *tdmcntsel = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *tdmcntthre = (localVal & ((uint32_t)0x0FFF0000)) >> 16;
    *tdmchannelen = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t lm_tdm_channel_0_tdm_cnt_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_0_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}

__INLINE void lm_tdm_channel_0_tdm_cnt_sel_setf(uint8_t tdmcntsel)
{
    ASSERT_ERR((((uint32_t)tdmcntsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_0_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_0_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)tdmcntsel << 28));
}

__INLINE uint16_t lm_tdm_channel_0_tdm_cnt_thre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_0_ADDR);
    return ((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}

__INLINE void lm_tdm_channel_0_tdm_cnt_thre_setf(uint16_t tdmcntthre)
{
    ASSERT_ERR((((uint32_t)tdmcntthre << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_0_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_0_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)tdmcntthre << 16));
}

__INLINE uint8_t lm_tdm_channel_0_tdm_channel_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void lm_tdm_channel_0_tdm_channel_en_setf(uint8_t tdmchannelen)
{
    ASSERT_ERR((((uint32_t)tdmchannelen << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_0_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tdmchannelen << 0));
}

/**
 * @brief TDM_FIFO_ADDR_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  27:24         TDM_FIFO_SEL   0x0
 *  15:00       TDM_START_ADDR   0x0
 * </pre>
 */
#define LM_TDM_FIFO_ADDR_0_ADDR   0x0005FFBC
#define LM_TDM_FIFO_ADDR_0_OFFSET 0x000000BC
#define LM_TDM_FIFO_ADDR_0_INDEX  0x0000002F
#define LM_TDM_FIFO_ADDR_0_RESET  0x00000000

__INLINE uint32_t lm_tdm_fifo_addr_0_get(void)
{
    return REG_PL_RD(LM_TDM_FIFO_ADDR_0_ADDR);
}

__INLINE void lm_tdm_fifo_addr_0_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_FIFO_ADDR_0_ADDR, value);
}

// field definitions
#define LM_TDM_FIFO_ADDR_0_TDM_FIFO_SEL_MASK     ((uint32_t)0x0F000000)
#define LM_TDM_FIFO_ADDR_0_TDM_FIFO_SEL_LSB      24
#define LM_TDM_FIFO_ADDR_0_TDM_FIFO_SEL_WIDTH    ((uint32_t)0x00000004)
#define LM_TDM_FIFO_ADDR_0_TDM_START_ADDR_MASK   ((uint32_t)0x0000FFFF)
#define LM_TDM_FIFO_ADDR_0_TDM_START_ADDR_LSB    0
#define LM_TDM_FIFO_ADDR_0_TDM_START_ADDR_WIDTH  ((uint32_t)0x00000010)

#define LM_TDM_FIFO_ADDR_0_TDM_FIFO_SEL_RST      0x0
#define LM_TDM_FIFO_ADDR_0_TDM_START_ADDR_RST    0x0

__INLINE void lm_tdm_fifo_addr_0_unpack(uint8_t* tdmfifosel, uint16_t* tdmstartaddr)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_0_ADDR);
    *tdmfifosel = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *tdmstartaddr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t lm_tdm_fifo_addr_0_tdm_fifo_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_0_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

__INLINE uint16_t lm_tdm_fifo_addr_0_tdm_start_addr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_0_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_tdm_fifo_addr_0_tdm_start_addr_setf(uint16_t tdmstartaddr)
{
    ASSERT_ERR((((uint32_t)tdmstartaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_TDM_FIFO_ADDR_0_ADDR, (uint32_t)tdmstartaddr << 0);
}

/**
 * @brief TDM_OUT_POINTER_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16               RD_PTR   0x0
 *  15:00               WR_PTR   0x0
 * </pre>
 */
#define LM_TDM_OUT_POINTER_0_ADDR   0x0005FFC0
#define LM_TDM_OUT_POINTER_0_OFFSET 0x000000C0
#define LM_TDM_OUT_POINTER_0_INDEX  0x00000030
#define LM_TDM_OUT_POINTER_0_RESET  0x00000000

__INLINE uint32_t lm_tdm_out_pointer_0_get(void)
{
    return REG_PL_RD(LM_TDM_OUT_POINTER_0_ADDR);
}

__INLINE void lm_tdm_out_pointer_0_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_OUT_POINTER_0_ADDR, value);
}

// field definitions
#define LM_TDM_OUT_POINTER_0_RD_PTR_MASK   ((uint32_t)0xFFFF0000)
#define LM_TDM_OUT_POINTER_0_RD_PTR_LSB    16
#define LM_TDM_OUT_POINTER_0_RD_PTR_WIDTH  ((uint32_t)0x00000010)
#define LM_TDM_OUT_POINTER_0_WR_PTR_MASK   ((uint32_t)0x0000FFFF)
#define LM_TDM_OUT_POINTER_0_WR_PTR_LSB    0
#define LM_TDM_OUT_POINTER_0_WR_PTR_WIDTH  ((uint32_t)0x00000010)

#define LM_TDM_OUT_POINTER_0_RD_PTR_RST    0x0
#define LM_TDM_OUT_POINTER_0_WR_PTR_RST    0x0

__INLINE void lm_tdm_out_pointer_0_unpack(uint16_t* rdptr, uint16_t* wrptr)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_0_ADDR);
    *rdptr = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *wrptr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint16_t lm_tdm_out_pointer_0_rd_ptr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_0_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE uint16_t lm_tdm_out_pointer_0_wr_ptr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_0_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_tdm_out_pointer_0_wr_ptr_setf(uint16_t wrptr)
{
    ASSERT_ERR((((uint32_t)wrptr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_TDM_OUT_POINTER_0_ADDR, (uint32_t)wrptr << 0);
}

/**
 * @brief TDM_OUT_STATUS_0 register definition
 */
#define LM_TDM_OUT_STATUS_0_ADDR   0x0005FFC4
#define LM_TDM_OUT_STATUS_0_OFFSET 0x000000C4
#define LM_TDM_OUT_STATUS_0_INDEX  0x00000031
#define LM_TDM_OUT_STATUS_0_RESET  0x00000000

__INLINE uint32_t lm_tdm_out_status_0_get(void)
{
    return REG_PL_RD(LM_TDM_OUT_STATUS_0_ADDR);
}

__INLINE void lm_tdm_out_status_0_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_OUT_STATUS_0_ADDR, value);
}

/**
 * @brief TDM_CONTROL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31          TDM_PORT_EN   0
 *     30           TDM_INT_EN   0
 *     29           TDM_IO_SEL   0
 *  23:22      TDM_DATA_ADJUST   0x0
 *     21        TDM_DATA_SIZE   0
 *  19:16         TDM_FIFO_SEL   0x0
 *  11:00         TDM_FIFO_LEN   0x0
 * </pre>
 */
#define LM_TDM_CONTROL_1_ADDR   0x0005FFC8
#define LM_TDM_CONTROL_1_OFFSET 0x000000C8
#define LM_TDM_CONTROL_1_INDEX  0x00000032
#define LM_TDM_CONTROL_1_RESET  0x00000000

__INLINE uint32_t lm_tdm_control_1_get(void)
{
    return REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
}

__INLINE void lm_tdm_control_1_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, value);
}

// field definitions
#define LM_TDM_CONTROL_1_TDM_PORT_EN_BIT        ((uint32_t)0x80000000)
#define LM_TDM_CONTROL_1_TDM_PORT_EN_POS        31
#define LM_TDM_CONTROL_1_TDM_INT_EN_BIT         ((uint32_t)0x40000000)
#define LM_TDM_CONTROL_1_TDM_INT_EN_POS         30
#define LM_TDM_CONTROL_1_TDM_IO_SEL_BIT         ((uint32_t)0x20000000)
#define LM_TDM_CONTROL_1_TDM_IO_SEL_POS         29
#define LM_TDM_CONTROL_1_TDM_DATA_ADJUST_MASK   ((uint32_t)0x00C00000)
#define LM_TDM_CONTROL_1_TDM_DATA_ADJUST_LSB    22
#define LM_TDM_CONTROL_1_TDM_DATA_ADJUST_WIDTH  ((uint32_t)0x00000002)
#define LM_TDM_CONTROL_1_TDM_DATA_SIZE_BIT      ((uint32_t)0x00200000)
#define LM_TDM_CONTROL_1_TDM_DATA_SIZE_POS      21
#define LM_TDM_CONTROL_1_TDM_FIFO_SEL_MASK      ((uint32_t)0x000F0000)
#define LM_TDM_CONTROL_1_TDM_FIFO_SEL_LSB       16
#define LM_TDM_CONTROL_1_TDM_FIFO_SEL_WIDTH     ((uint32_t)0x00000004)
#define LM_TDM_CONTROL_1_TDM_FIFO_LEN_MASK      ((uint32_t)0x00000FFF)
#define LM_TDM_CONTROL_1_TDM_FIFO_LEN_LSB       0
#define LM_TDM_CONTROL_1_TDM_FIFO_LEN_WIDTH     ((uint32_t)0x0000000C)

#define LM_TDM_CONTROL_1_TDM_PORT_EN_RST        0x0
#define LM_TDM_CONTROL_1_TDM_INT_EN_RST         0x0
#define LM_TDM_CONTROL_1_TDM_IO_SEL_RST         0x0
#define LM_TDM_CONTROL_1_TDM_DATA_ADJUST_RST    0x0
#define LM_TDM_CONTROL_1_TDM_DATA_SIZE_RST      0x0
#define LM_TDM_CONTROL_1_TDM_FIFO_SEL_RST       0x0
#define LM_TDM_CONTROL_1_TDM_FIFO_LEN_RST       0x0

__INLINE void lm_tdm_control_1_pack(uint8_t tdmporten, uint8_t tdminten, uint8_t tdmiosel, uint8_t tdmdataadjust, uint8_t tdmdatasize, uint8_t tdmfifosel, uint16_t tdmfifolen)
{
    ASSERT_ERR((((uint32_t)tdmporten << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)tdminten << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmiosel << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmdataadjust << 22) & ~((uint32_t)0x00C00000)) == 0);
    ASSERT_ERR((((uint32_t)tdmdatasize << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)tdmfifosel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)tdmfifolen << 0) & ~((uint32_t)0x00000FFF)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR,  ((uint32_t)tdmporten << 31) | ((uint32_t)tdminten << 30) | ((uint32_t)tdmiosel << 29) | ((uint32_t)tdmdataadjust << 22) | ((uint32_t)tdmdatasize << 21) | ((uint32_t)tdmfifosel << 16) | ((uint32_t)tdmfifolen << 0));
}

__INLINE void lm_tdm_control_1_unpack(uint8_t* tdmporten, uint8_t* tdminten, uint8_t* tdmiosel, uint8_t* tdmdataadjust, uint8_t* tdmdatasize, uint8_t* tdmfifosel, uint16_t* tdmfifolen)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    *tdmporten = (localVal & ((uint32_t)0x80000000)) >> 31;
    *tdminten = (localVal & ((uint32_t)0x40000000)) >> 30;
    *tdmiosel = (localVal & ((uint32_t)0x20000000)) >> 29;
    *tdmdataadjust = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *tdmdatasize = (localVal & ((uint32_t)0x00200000)) >> 21;
    *tdmfifosel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *tdmfifolen = (localVal & ((uint32_t)0x00000FFF)) >> 0;
}

__INLINE uint8_t lm_tdm_control_1_tdm_port_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void lm_tdm_control_1_tdm_port_en_setf(uint8_t tdmporten)
{
    ASSERT_ERR((((uint32_t)tdmporten << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)tdmporten << 31));
}

__INLINE uint8_t lm_tdm_control_1_tdm_int_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void lm_tdm_control_1_tdm_int_en_setf(uint8_t tdminten)
{
    ASSERT_ERR((((uint32_t)tdminten << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)tdminten << 30));
}

__INLINE uint8_t lm_tdm_control_1_tdm_io_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void lm_tdm_control_1_tdm_io_sel_setf(uint8_t tdmiosel)
{
    ASSERT_ERR((((uint32_t)tdmiosel << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)tdmiosel << 29));
}

__INLINE uint8_t lm_tdm_control_1_tdm_data_adjust_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void lm_tdm_control_1_tdm_data_adjust_setf(uint8_t tdmdataadjust)
{
    ASSERT_ERR((((uint32_t)tdmdataadjust << 22) & ~((uint32_t)0x00C00000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)tdmdataadjust << 22));
}

__INLINE uint8_t lm_tdm_control_1_tdm_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void lm_tdm_control_1_tdm_data_size_setf(uint8_t tdmdatasize)
{
    ASSERT_ERR((((uint32_t)tdmdatasize << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)tdmdatasize << 21));
}

__INLINE uint8_t lm_tdm_control_1_tdm_fifo_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void lm_tdm_control_1_tdm_fifo_sel_setf(uint8_t tdmfifosel)
{
    ASSERT_ERR((((uint32_t)tdmfifosel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)tdmfifosel << 16));
}

__INLINE uint16_t lm_tdm_control_1_tdm_fifo_len_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CONTROL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

__INLINE void lm_tdm_control_1_tdm_fifo_len_setf(uint16_t tdmfifolen)
{
    ASSERT_ERR((((uint32_t)tdmfifolen << 0) & ~((uint32_t)0x00000FFF)) == 0);
    REG_PL_WR(LM_TDM_CONTROL_1_ADDR, (REG_PL_RD(LM_TDM_CONTROL_1_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)tdmfifolen << 0));
}

/**
 * @brief TDM_CHANNEL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:28          TDM_CNT_SEL   0x0
 *  27:16         TDM_CNT_THRE   0x0
 *  07:00       TDM_CHANNEL_EN   0x0
 * </pre>
 */
#define LM_TDM_CHANNEL_1_ADDR   0x0005FFCC
#define LM_TDM_CHANNEL_1_OFFSET 0x000000CC
#define LM_TDM_CHANNEL_1_INDEX  0x00000033
#define LM_TDM_CHANNEL_1_RESET  0x00000000

__INLINE uint32_t lm_tdm_channel_1_get(void)
{
    return REG_PL_RD(LM_TDM_CHANNEL_1_ADDR);
}

__INLINE void lm_tdm_channel_1_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_CHANNEL_1_ADDR, value);
}

// field definitions
#define LM_TDM_CHANNEL_1_TDM_CNT_SEL_MASK      ((uint32_t)0xF0000000)
#define LM_TDM_CHANNEL_1_TDM_CNT_SEL_LSB       28
#define LM_TDM_CHANNEL_1_TDM_CNT_SEL_WIDTH     ((uint32_t)0x00000004)
#define LM_TDM_CHANNEL_1_TDM_CNT_THRE_MASK     ((uint32_t)0x0FFF0000)
#define LM_TDM_CHANNEL_1_TDM_CNT_THRE_LSB      16
#define LM_TDM_CHANNEL_1_TDM_CNT_THRE_WIDTH    ((uint32_t)0x0000000C)
#define LM_TDM_CHANNEL_1_TDM_CHANNEL_EN_MASK   ((uint32_t)0x000000FF)
#define LM_TDM_CHANNEL_1_TDM_CHANNEL_EN_LSB    0
#define LM_TDM_CHANNEL_1_TDM_CHANNEL_EN_WIDTH  ((uint32_t)0x00000008)

#define LM_TDM_CHANNEL_1_TDM_CNT_SEL_RST       0x0
#define LM_TDM_CHANNEL_1_TDM_CNT_THRE_RST      0x0
#define LM_TDM_CHANNEL_1_TDM_CHANNEL_EN_RST    0x0

__INLINE void lm_tdm_channel_1_pack(uint8_t tdmcntsel, uint16_t tdmcntthre, uint8_t tdmchannelen)
{
    ASSERT_ERR((((uint32_t)tdmcntsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmcntthre << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)tdmchannelen << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_1_ADDR,  ((uint32_t)tdmcntsel << 28) | ((uint32_t)tdmcntthre << 16) | ((uint32_t)tdmchannelen << 0));
}

__INLINE void lm_tdm_channel_1_unpack(uint8_t* tdmcntsel, uint16_t* tdmcntthre, uint8_t* tdmchannelen)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_1_ADDR);
    *tdmcntsel = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *tdmcntthre = (localVal & ((uint32_t)0x0FFF0000)) >> 16;
    *tdmchannelen = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t lm_tdm_channel_1_tdm_cnt_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_1_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}

__INLINE void lm_tdm_channel_1_tdm_cnt_sel_setf(uint8_t tdmcntsel)
{
    ASSERT_ERR((((uint32_t)tdmcntsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_1_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_1_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)tdmcntsel << 28));
}

__INLINE uint16_t lm_tdm_channel_1_tdm_cnt_thre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_1_ADDR);
    return ((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}

__INLINE void lm_tdm_channel_1_tdm_cnt_thre_setf(uint16_t tdmcntthre)
{
    ASSERT_ERR((((uint32_t)tdmcntthre << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_1_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_1_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)tdmcntthre << 16));
}

__INLINE uint8_t lm_tdm_channel_1_tdm_channel_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_CHANNEL_1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void lm_tdm_channel_1_tdm_channel_en_setf(uint8_t tdmchannelen)
{
    ASSERT_ERR((((uint32_t)tdmchannelen << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(LM_TDM_CHANNEL_1_ADDR, (REG_PL_RD(LM_TDM_CHANNEL_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tdmchannelen << 0));
}

/**
 * @brief TDM_FIFO_ADDR_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  27:24         TDM_FIFO_SEL   0x0
 *  15:00       TDM_START_ADDR   0x0
 * </pre>
 */
#define LM_TDM_FIFO_ADDR_1_ADDR   0x0005FFD0
#define LM_TDM_FIFO_ADDR_1_OFFSET 0x000000D0
#define LM_TDM_FIFO_ADDR_1_INDEX  0x00000034
#define LM_TDM_FIFO_ADDR_1_RESET  0x00000000

__INLINE uint32_t lm_tdm_fifo_addr_1_get(void)
{
    return REG_PL_RD(LM_TDM_FIFO_ADDR_1_ADDR);
}

__INLINE void lm_tdm_fifo_addr_1_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_FIFO_ADDR_1_ADDR, value);
}

// field definitions
#define LM_TDM_FIFO_ADDR_1_TDM_FIFO_SEL_MASK     ((uint32_t)0x0F000000)
#define LM_TDM_FIFO_ADDR_1_TDM_FIFO_SEL_LSB      24
#define LM_TDM_FIFO_ADDR_1_TDM_FIFO_SEL_WIDTH    ((uint32_t)0x00000004)
#define LM_TDM_FIFO_ADDR_1_TDM_START_ADDR_MASK   ((uint32_t)0x0000FFFF)
#define LM_TDM_FIFO_ADDR_1_TDM_START_ADDR_LSB    0
#define LM_TDM_FIFO_ADDR_1_TDM_START_ADDR_WIDTH  ((uint32_t)0x00000010)

#define LM_TDM_FIFO_ADDR_1_TDM_FIFO_SEL_RST      0x0
#define LM_TDM_FIFO_ADDR_1_TDM_START_ADDR_RST    0x0

__INLINE void lm_tdm_fifo_addr_1_unpack(uint8_t* tdmfifosel, uint16_t* tdmstartaddr)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_1_ADDR);
    *tdmfifosel = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *tdmstartaddr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t lm_tdm_fifo_addr_1_tdm_fifo_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_1_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

__INLINE uint16_t lm_tdm_fifo_addr_1_tdm_start_addr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_FIFO_ADDR_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_tdm_fifo_addr_1_tdm_start_addr_setf(uint16_t tdmstartaddr)
{
    ASSERT_ERR((((uint32_t)tdmstartaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_TDM_FIFO_ADDR_1_ADDR, (uint32_t)tdmstartaddr << 0);
}

/**
 * @brief TDM_OUT_POINTER_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16               RD_PTR   0x0
 *  15:00               WR_PTR   0x0
 * </pre>
 */
#define LM_TDM_OUT_POINTER_1_ADDR   0x0005FFD4
#define LM_TDM_OUT_POINTER_1_OFFSET 0x000000D4
#define LM_TDM_OUT_POINTER_1_INDEX  0x00000035
#define LM_TDM_OUT_POINTER_1_RESET  0x00000000

__INLINE uint32_t lm_tdm_out_pointer_1_get(void)
{
    return REG_PL_RD(LM_TDM_OUT_POINTER_1_ADDR);
}

__INLINE void lm_tdm_out_pointer_1_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_OUT_POINTER_1_ADDR, value);
}

// field definitions
#define LM_TDM_OUT_POINTER_1_RD_PTR_MASK   ((uint32_t)0xFFFF0000)
#define LM_TDM_OUT_POINTER_1_RD_PTR_LSB    16
#define LM_TDM_OUT_POINTER_1_RD_PTR_WIDTH  ((uint32_t)0x00000010)
#define LM_TDM_OUT_POINTER_1_WR_PTR_MASK   ((uint32_t)0x0000FFFF)
#define LM_TDM_OUT_POINTER_1_WR_PTR_LSB    0
#define LM_TDM_OUT_POINTER_1_WR_PTR_WIDTH  ((uint32_t)0x00000010)

#define LM_TDM_OUT_POINTER_1_RD_PTR_RST    0x0
#define LM_TDM_OUT_POINTER_1_WR_PTR_RST    0x0

__INLINE void lm_tdm_out_pointer_1_unpack(uint16_t* rdptr, uint16_t* wrptr)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_1_ADDR);
    *rdptr = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *wrptr = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint16_t lm_tdm_out_pointer_1_rd_ptr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_1_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE uint16_t lm_tdm_out_pointer_1_wr_ptr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_TDM_OUT_POINTER_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void lm_tdm_out_pointer_1_wr_ptr_setf(uint16_t wrptr)
{
    ASSERT_ERR((((uint32_t)wrptr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(LM_TDM_OUT_POINTER_1_ADDR, (uint32_t)wrptr << 0);
}

/**
 * @brief TDM_STATUS_1 register definition
 */
#define LM_TDM_STATUS_1_ADDR   0x0005FFD8
#define LM_TDM_STATUS_1_OFFSET 0x000000D8
#define LM_TDM_STATUS_1_INDEX  0x00000036
#define LM_TDM_STATUS_1_RESET  0x00000000

__INLINE uint32_t lm_tdm_status_1_get(void)
{
    return REG_PL_RD(LM_TDM_STATUS_1_ADDR);
}

__INLINE void lm_tdm_status_1_set(uint32_t value)
{
    REG_PL_WR(LM_TDM_STATUS_1_ADDR, value);
}

/**
 * @brief FIFO_CONFIG_4 register definition
 */
#define LM_FIFO_CONFIG_4_ADDR   0x0005FFE0
#define LM_FIFO_CONFIG_4_OFFSET 0x000000E0
#define LM_FIFO_CONFIG_4_INDEX  0x00000038
#define LM_FIFO_CONFIG_4_RESET  0x00000000

__INLINE uint32_t lm_fifo_config_4_get(void)
{
    return REG_PL_RD(LM_FIFO_CONFIG_4_ADDR);
}

__INLINE void lm_fifo_config_4_set(uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONFIG_4_ADDR, value);
}

/**
 * @brief FIFO_CONFIG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28        MODEM_RAM_SEL   0x0
 * </pre>
 */
#define LM_FIFO_CONFIG_5_ADDR   0x0005FFE4
#define LM_FIFO_CONFIG_5_OFFSET 0x000000E4
#define LM_FIFO_CONFIG_5_INDEX  0x00000039
#define LM_FIFO_CONFIG_5_RESET  0x00000000

__INLINE uint32_t lm_fifo_config_5_get(void)
{
    return REG_PL_RD(LM_FIFO_CONFIG_5_ADDR);
}

__INLINE void lm_fifo_config_5_set(uint32_t value)
{
    REG_PL_WR(LM_FIFO_CONFIG_5_ADDR, value);
}

// field definitions
#define LM_FIFO_CONFIG_5_MODEM_RAM_SEL_MASK   ((uint32_t)0x30000000)
#define LM_FIFO_CONFIG_5_MODEM_RAM_SEL_LSB    28
#define LM_FIFO_CONFIG_5_MODEM_RAM_SEL_WIDTH  ((uint32_t)0x00000002)

#define LM_FIFO_CONFIG_5_MODEM_RAM_SEL_RST    0x0

__INLINE uint8_t lm_fifo_config_5_modem_ram_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_FIFO_CONFIG_5_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x30000000)) == 0);
    return (localVal >> 28);
}

__INLINE void lm_fifo_config_5_modem_ram_sel_setf(uint8_t modemramsel)
{
    ASSERT_ERR((((uint32_t)modemramsel << 28) & ~((uint32_t)0x30000000)) == 0);
    REG_PL_WR(LM_FIFO_CONFIG_5_ADDR, (uint32_t)modemramsel << 28);
}

/**
 * @brief LM_VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:16              CHIP_ID   0x0
 *  15:08     IP_MAJOR_VERSION   0x0
 *  07:00     IP_MINOR_VERSION   0x0
 * </pre>
 */
#define LM_LM_VERSION_ADDR   0x0005FFF0
#define LM_LM_VERSION_OFFSET 0x000000F0
#define LM_LM_VERSION_INDEX  0x0000003C
#define LM_LM_VERSION_RESET  0x00000000

__INLINE uint32_t lm_lm_version_get(void)
{
    return REG_PL_RD(LM_LM_VERSION_ADDR);
}

__INLINE void lm_lm_version_set(uint32_t value)
{
    REG_PL_WR(LM_LM_VERSION_ADDR, value);
}

// field definitions
#define LM_LM_VERSION_CHIP_ID_MASK            ((uint32_t)0x00FF0000)
#define LM_LM_VERSION_CHIP_ID_LSB             16
#define LM_LM_VERSION_CHIP_ID_WIDTH           ((uint32_t)0x00000008)
#define LM_LM_VERSION_IP_MAJOR_VERSION_MASK   ((uint32_t)0x0000FF00)
#define LM_LM_VERSION_IP_MAJOR_VERSION_LSB    8
#define LM_LM_VERSION_IP_MAJOR_VERSION_WIDTH  ((uint32_t)0x00000008)
#define LM_LM_VERSION_IP_MINOR_VERSION_MASK   ((uint32_t)0x000000FF)
#define LM_LM_VERSION_IP_MINOR_VERSION_LSB    0
#define LM_LM_VERSION_IP_MINOR_VERSION_WIDTH  ((uint32_t)0x00000008)

#define LM_LM_VERSION_CHIP_ID_RST             0x0
#define LM_LM_VERSION_IP_MAJOR_VERSION_RST    0x0
#define LM_LM_VERSION_IP_MINOR_VERSION_RST    0x0

__INLINE void lm_lm_version_unpack(uint8_t* chipid, uint8_t* ipmajorversion, uint8_t* ipminorversion)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_LM_VERSION_ADDR);
    *chipid = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *ipmajorversion = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *ipminorversion = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t lm_lm_version_chip_id_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_LM_VERSION_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

__INLINE uint8_t lm_lm_version_ip_major_version_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_LM_VERSION_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE uint8_t lm_lm_version_ip_minor_version_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(LM_LM_VERSION_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}


#endif // _REG_LM_H_

