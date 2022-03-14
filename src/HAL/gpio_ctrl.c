/*
 * gpio_ctrl.c
 *
 *  Created on: May 16, 2019
 *      Author: chenbowen
 */

/*
 * INCLUDE FILES
 **************************************************************************************************
 */
#include "config.h"
#include "gpio_ctrl.h"

/*
 * STRUCTURE DEFINES
 **************************************************************************************************
 */


/*
* LOCAL VARIABLE DECLARATIONS
***************************************************************************************************
*/
PAD_SW_CTRL_BAK_t pad_sw_bak = {{ 0 }};
uint8_t u8GpioList[32] = {GPIO8, GPIO7, GPIO6, GPIO5, GPIO4, GPIO3, GPIO2, GPIO1,
						  I2S0_SDOUT, GPIO_NUM, I2S0_LRCLK, I2S0_SCLK, I2S0_MCLK,
						  SPI_HOLD, SPI_WP, SPI_MISO, SPI_MOSI, SPI_NSS, SPI_CLK,
						  I2S1_SDOUT, GPIO_NUM, I2S1_LRCLK, I2S1_SCLK,
						  GPIO9, GPIO10};

/*
 * LOCAL FUNCTION DEFINITIONS
 **************************************************************************************************
 */
uint8_t pad_id_trans(GPIO_PIN_DEF_t GPIOx)
{
	uint8_t u8GpioId;

	if(GPIOx < I2S0_SDOUT){
		u8GpioId = GPIOx;
	}else if(GPIOx == I2S0_SDOUT){
		u8GpioId = GPIOx - 1;
	}else if(GPIOx < GPIO9){
		if(GPIOx == I2S1_SDOUT){
			u8GpioId = GPIOx - 5;
		}else{
			u8GpioId = GPIOx - 4;
		}
	}else{
		u8GpioId = GPIOx - 8;
	}

	return u8GpioId;
}

uint8_t pad_index_get(GPIO_PIN_DEF_t GPIOx)
{
	uint8_t i;

	for(i=0; i<32; i++){
		if(u8GpioList[i] == GPIOx){
			break;
		}
	}

	return i;
}

void pad_sw_ctrl_set(uint8_t u8GpioId)
{
	uint32_t *pu32SwCtrl;

	u8GpioId >>= 2;
	if(u8GpioId < 5){									/* for sw_ctrl 0~4 */
		pu32SwCtrl = (uint32_t *)(SYS_CTRL_BASE + 0xE8);
		pu32SwCtrl[u8GpioId] = pad_sw_bak.all32[u8GpioId];
	}else if(u8GpioId == 5){							/* for sw_ctrl 5 */
		pu32SwCtrl = (uint32_t *)(SYS_CTRL_BASE + 0xFC);
		*pu32SwCtrl = pad_sw_bak.all32[u8GpioId];
	}else{												/* for sw_ctrl 6 */
		pu32SwCtrl = (uint32_t *)(SYS_CTRL_BASE + 0x124);
		*pu32SwCtrl = pad_sw_bak.all32[u8GpioId];
	}
}

///* Defined in ROM!!!
// * EXPORTED FUNCTION DEFINITIONS
// **************************************************************************************************
// */
//void GPIO_FuncSet(GPIO_PIN_DEF_t GPIOx, GPIO_FUNC_DEF_t FuncX)
//{
//	/* modify pad id for saving in ram */
//	uint8_t	u8GpioId = pad_id_trans(GPIOx);
//
//	if(FuncX <= 15){
//		uint8_t u8TmpId;
//		uint32_t *pu32FuncCfg;
//		if(GPIOx < I2S1_PAD_Start){							/* pad1~pad23 */
//			u8TmpId = GPIOx;
//			pu32FuncCfg = (uint32_t *)(SYS_CTRL_BASE + 0x100);
//		}else{												/* pad24~pad33 */
//			u8TmpId = GPIOx - 24;
//			pu32FuncCfg = (uint32_t *)(SYS_CTRL_BASE + 0x11C);
//		}
//		/* 4 pads in 1 register */
//		pu32FuncCfg += (u8TmpId >> 3);
//
//		/* set func to register */
//		uint8_t u8CfgShift = (u8TmpId & 0x7) << 2;
//		uint32_t u32FuncCfg = *pu32FuncCfg;
//		uint32_t u32Msk = ~(0xFul << u8CfgShift);
//		u32FuncCfg = (u32FuncCfg & u32Msk) | (FuncX << u8CfgShift);
//		*pu32FuncCfg = u32FuncCfg;
//
//		/* clear pad sw func */
//		if(pad_sw_bak.all8[u8GpioId] == 0){
//			return;
//		}
//		pad_sw_bak.all8[u8GpioId] = 0;
//	}else{
//		/* set sw func enable */
//		uint8_t u8SwCtrlEn = (GPIOx <= GPIO2 || GPIOx >= GPIO9) ? (BIT5) : (BIT4);
//		/* save pad sw func in ram */
//		pad_sw_bak.all8[u8GpioId] = (FuncX - 15) + u8SwCtrlEn;
//	}
//
//	/* set pad sw func to register */
//	pad_sw_ctrl_set(u8GpioId);
//}

void New_GPIO_Toggle(GPIO_PIN_DEF_t GPIOx)
{
	uint8_t u8TmpId;
	uint32_t *pu32FuncCfg;

	if(GPIOx < I2S1_PAD_Start){							/* pad1~pad23 */
		u8TmpId = GPIOx;
		pu32FuncCfg = (uint32_t *)(SYS_CTRL_BASE + 0x100);
	}else{												/* pad24~pad33 */
		u8TmpId = GPIOx - 24;
		pu32FuncCfg = (uint32_t *)(SYS_CTRL_BASE + 0x11C);
	}
	/* 4 pads in 1 register */
	pu32FuncCfg += (u8TmpId >> 3);

	u8TmpId = (u8TmpId & 0x7) << 2;
	uint32_t u32FuncCfg = *pu32FuncCfg;
	uint32_t u32Func = (u32FuncCfg >> u8TmpId) & 0xF;
	if((GPIO_DigOutput0 == u32Func) || (GPIO_DigOutput1 == u32Func)){
		*pu32FuncCfg = u32FuncCfg ^ (1ul << u8TmpId);
	}else{
		return;
	}
}

uint8_t GPIO_InputGet(GPIO_PIN_DEF_t GPIOx)
{
	uint8_t u8TmpId;
	uint32_t *pu32InputSt;

	u8TmpId = pad_index_get(GPIOx);
	pu32InputSt = (uint32_t *)(SYS_CTRL_BASE + 0x10C);
	return (((*pu32InputSt) >> u8TmpId) & 0x1);
}
