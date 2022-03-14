/*
 * gpio_ctrl.h
 *
 *  Created on: May 16, 2019
 *      Author: chenbowen
 */

#ifndef GPIO_CTRL_H_
#define GPIO_CTRL_H_

/*
 * INCLUDE FILES
 **************************************************************************************************
 */
#include "com_includes.h"
#include "reg_apb.h"

/*
 * MACRO DEFINITIONS
 **************************************************************************************************
 */
#define DEBUG_GPIO1_SET() apb_pad_gpio_func_cfg0_gpio1_func_sel_setf(5);
#define DEBUG_GPIO1_CLR() apb_pad_gpio_func_cfg0_gpio1_func_sel_setf(4);

#define DEBUG_GPIO2_SET() apb_pad_gpio_func_cfg0_gpio2_func_sel_setf(5);
#define DEBUG_GPIO2_CLR() apb_pad_gpio_func_cfg0_gpio2_func_sel_setf(4);

#define DEBUG_GPIO4_SET() apb_pad_gpio_func_cfg0_gpio4_func_sel_setf(5);
#define DEBUG_GPIO4_CLR() apb_pad_gpio_func_cfg0_gpio4_func_sel_setf(4);

#define DEBUG_GPIO5_SET() apb_pad_gpio_func_cfg0_gpio5_func_sel_setf(5);
#define DEBUG_GPIO5_CLR() apb_pad_gpio_func_cfg0_gpio5_func_sel_setf(4);

#define DEBUG_GPIO6_SET() apb_pad_gpio_func_cfg0_gpio6_func_sel_setf(5);
#define DEBUG_GPIO6_CLR() apb_pad_gpio_func_cfg0_gpio6_func_sel_setf(4);

#define DEBUG_GPIO9_SET() apb_pad_gpio_func_cfg1_gpio9_func_sel_setf(5);
#define DEBUG_GPIO9_CLR() apb_pad_gpio_func_cfg1_gpio9_func_sel_setf(4);

#define DEBUG_GPIO10_SET() apb_pad_gpio_func_cfg1_gpio10_func_sel_setf(5);
#define DEBUG_GPIO10_CLR() apb_pad_gpio_func_cfg1_gpio10_func_sel_setf(4);

/*
 * STRUCTURE DEFINES
 **************************************************************************************************
 */
typedef enum GPIO_PIN_DEF_enum 
{
	GPIO1			= 0,
	GPIO2			= 1,
	GPIO3			= 2,
	GPIO4			= 3,
	GPIO5			= 4,
	GPIO6			= 5,
	GPIO7			= 6,
	GPIO8			= 7,

	//don't open SPI pad to user
	SPI_PAD_Start	= 8,
	SPI_CLK			= 8,
	SPI_NSS			= 9,
	SPI_MOSI		= 10,
	SPI_MISO		= 11,
	SPI_WP			= 12,
	SPI_HOLD		= 13,

	I2S0_PAD_Start	= 16,
	I2S0_MCLK 		= 16,
	I2S0_SCLK		= 17,
	I2S0_LRCLK		= 18,
	I2S0_SDOUT		= 20,

	I2S1_PAD_Start  = 24,
	I2S1_SCLK		= 25,
	I2S1_LRCLK		= 26,
	I2S1_SDOUT		= 28,

	GPIO9			= 32,
	GPIO10			= 33,

	GPIO_NUM,
}GPIO_PIN_DEF_t;

typedef enum GPIO_FUNC_DEF_enum 
{
	GPIO_Func0				= 0,	//All GPIO

	GPIO_Func1				= 1,	//GPIO1~GPIO10
	GPIO_AuxADC				= 2,	//GPIO1~GPIO10

	GPIO_DigInput			= 3,	//All GPIO (I2S included)
	GPIO_DigOutput0			= 4,	//All GPIO
	GPIO_DigOutput1			= 5,	//All GPIO

	GPIO_IntrInput			= 8,	//GPIO3~8

	GPIO_HighZ				= 15,	//All GPIO

	GPIO_PullDownInput		= 16,	//All GPIO
	GPIO_PullUpInput		= 17,	//All GPIO
}GPIO_FUNC_DEF_t;

typedef union 
{
	struct 
	{
		uint32_t	gpio_sw_ctrl1;
		uint32_t	gpio_sw_ctrl2;
		uint32_t	spi_sw_ctrl1;
		uint32_t	spi_sw_ctrl2;
		uint32_t	i2s_sw_ctrl1;
		uint32_t	i2s_sw_ctrl2;
		uint32_t 	gpio_sw_ctrl3;
	};
	uint32_t		all32[7];
	uint8_t			all8[28];
}PAD_SW_CTRL_BAK_t;


PAD_SW_CTRL_BAK_t pad_sw_bak;
/*
 * EXPORTED FUNCTION DEFINITIONS
 **************************************************************************************************
 */
void GPIO_FuncSet(GPIO_PIN_DEF_t GPIOx, GPIO_FUNC_DEF_t FuncX);      // defined in rom
void New_GPIO_Toggle(GPIO_PIN_DEF_t GPIOx);
uint8_t GPIO_InputGet(GPIO_PIN_DEF_t GPIOx);

#endif /* GPIO_CTRL_H_ */
