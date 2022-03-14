#ifndef _CLK_H_
#define _CLK_H_

#define OSC_HIGH_CLK		(384000000UL) //384MHz unit Hz
#define OSC_HIGH_CLK_KHZ	(384000UL) //384MHz unit KHz

typedef struct 
{
	uint8_t apb_div_sel : 2;
	uint8_t ahb_div_sel : 2;
	uint8_t osc_div_sel : 4;
	uint8_t uart_div_sel : 2;
	uint8_t rfu : 4;
	uint8_t qspi_div_sel : 2;
}clk_div_cfg_t;

const uint16_t g_ClkOscHighDivSel[16];

//return clock frequence, unit Hz
extern uint32_t Get_OSC_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_Core_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_AHB_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_APB_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_QSPI_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_I2C_Clk(void);

//return clock frequence, unit Hz
extern uint32_t Get_UART_Clk(void);

//input register config value
extern void Set_Clk_Div_Sel(uint8_t osc_div_sel, uint8_t ahb_div_sel, uint8_t apb_div_sel, uint8_t qspi_div_sel);

extern void new_Set_Clk_Div_Sel(uint8_t osc_div_sel, uint8_t ahb_div_sel, uint8_t apb_div_sel, uint8_t qspi_div_sel, uint8_t uart_div_sel);

#endif

