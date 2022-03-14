/**
 ****************************************************************************************
 *
 * @file plf_init.c
 *
 * @brief Main loop of the application.
 *
 * @author WeighSong
 *
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */

#include "arch.h"
#include "co_math.h"
#include "ke.h"
#include "ke_event.h"

#include "syscntl.h"
//#include "i2c.h"
#include "uart.h"
#include "intc.h"
#include "timer.h"

#include "tlpool.h"
#include "plf.h"

#include "comm.h"
#include "config.h"
//#include "interrupt.h"
//#include "sys_init.h"
#include "cache.h"
//#include "dw_uart.h"

#include "audio.h"

#include "rlpool.h"//auto test
#include "reg_access.h"
//#include "dw_i2c.h"
/**
 ****************************************************************************************
 * @addtogroup DRIVERS
 * @{
 *
 *
 * ****************************************************************************************
 */


/*
 * MACRO DEFINITIONS
 ****************************************************************************************
 */
#define PATCH_MAGIC_NUM_LEN                 4

const uint8_t EMPTY[2] __attribute__((section(".EMPTY_SECTOR"))) = {};
/*
 * STRUCTURE DEFINITIONS
 ****************************************************************************************
 */
typedef struct main_ftable_stru {
    uint8_t magic_num[PATCH_MAGIC_NUM_LEN];
    int (*init)(void);
    void (*schedule)(void);
    void (*sleep_check)(void);
} main_ftable_t;

st_I2C_Init_t g_I2C_SlaveInit_para = {
	.Mode				= I2C_Slave_Mode,
	.Speed              = I2C_Standard_Speed,
	.Addr_Length		= I2C_7bit_Addr,
	.Addr				= 0x50,
	.RX_FIFO_TL			= RX_FIFO_DEPTH / 4 * 3 - 1,	//23
	.TX_FIFO_TL			= 3,		//7
	.Default_Int_Msk	= (
		I2C_IRQ_RD_REQ		|
		I2C_IRQ_RX_FULL 	|
		I2C_IRQ_RX_DONE		|
		I2C_IRQ_START_DET	|
//		I2C_IRQ_STOP_DET	|
	0),
};

/*
 * LOCAL FUNCTION DECLARATIONS
 ****************************************************************************************
 */
__STATIC int plf_init(void);
__STATIC void plf_schedule(void);
__STATIC void plf_sleep_check(void);


/*
 * LOCAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/// Patch magic number keyword
const __STATIC uint32_t patch_magic_number[PATCH_MAGIC_NUM_LEN] = {'P', 'T', 'C', 'H'};

/// Patch functions table
const main_ftable_t patch_ftable __attribute__((section(".PATCH_TABLE_SECTION"))) = {
    .magic_num = {'P', 'T', 'C', 'H'},
    .init = plf_init,
    .schedule = plf_schedule,
    .sleep_check = plf_sleep_check
};


/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */

__STATIC char uart_rcv[64];

__STATIC void uart_read_done(uart_size_t transfered)
{
    LOG_DEBUG("uart rcv[%d(0x%X)]:", transfered, transfered);
    tlpool_write(uart_rcv, transfered);
    log_printf("\r\n");
    log_dump_hex(uart_rcv, transfered);
    log_printf("\r\n");

    uart_read((uint8_t *)uart_rcv, 64, uart_read_done);
}

__STATIC int plf_init(void)
{
    /*
     ************************************************************************************
     * Platform initialization
     ************************************************************************************
     */

    // Initialize random process
    srand(1);

    ke_init();

    // Initialize I2C component
    //i2c_init();

    // Initialize System Control module
    //syscntl_init();
    Sys_Init();
    // Initialize the Interrupt Controller
    intc_init();

    // Initialize the timer components
    tim_init();
    REG_PL_WR(0xC001206C, (REG_PL_RD(0xC001206C) | 5)); /* Clk_apb_div_sel: 00, clk_osc_high_div_sel: 5; 1/16 */
    REG_PL_WR(0xC0012100, (REG_PL_RD(0xC0012100) | 0x111100)); /* PMX_UART_FUNC */
    REG_PL_WR(0xC0012070, (REG_PL_RD(0xC0012070) | 0x23)); /* Enable UART clk */
    // Initialize the UART components
    uart_init();

    tlpool_init();
    rlpool_init(uart_rcv);//auto test
#if PLF_DEBUG
    log_output = tlpool_write;
    dbg_get_time_ms = tim_cur_ms_get;
    log_lvl_enabled[LOG_LVL_OTHER] = 1;
    log_lvl_enabled[LOG_LVL_DEBUG] = 1;
    log_lvl_enabled[LOG_LVL_INFO] = 1;
    log_lvl_enabled[LOG_LVL_ERROR] = 1;
#endif /* if PLF_DEBUG */

    GLOBAL_INT_START();

    LOG_INFO("Plf init done");

    uart_read((uint8_t *)uart_rcv, 64, rlpool_read);//auto test

    return 0;
}

__STATIC void plf_sleep_check(void)
{
}

__STATIC void plf_schedule(void)
{
    ke_event_schedule();
}



extern char uart_str[];


int main(void) {

	//plf_init();
	srand(1);
	ke_init();

	REG_PL_WR(0xC001206C, (REG_PL_RD(0xC001206C) | 5)); /* Clk_apb_div_sel: 00, clk_osc_high_div_sel: 5; 1/16 */
	REG_PL_WR(0xC0012100, (REG_PL_RD(0xC0012100) | 0x111100)); /* PMX_UART_FUNC */
	REG_PL_WR(0xC0012070, (REG_PL_RD(0xC0012070) | 0x23)); /* Enable UART clk */

	Sys_Init();

	intc_init();
	g_I2C_SlaveInit_para.Addr |= ((OTP_inRAM.bs.I2C_SlaveAddr)&0x3)<<2;


	tim_init();
	uart_init();


	i2c_init(&g_I2C_SlaveInit_para);
	tlpool_init();
	rlpool_init(uart_rcv);

#if PLF_DEBUG
    log_output = tlpool_write;
    dbg_get_time_ms = tim_cur_ms_get;
    log_lvl_enabled[LOG_LVL_OTHER] = 1;
    log_lvl_enabled[LOG_LVL_DEBUG] = 1;
    log_lvl_enabled[LOG_LVL_INFO] = 1;
    log_lvl_enabled[LOG_LVL_ERROR] = 1;
#endif /* if PLF_DEBUG */


    GLOBAL_INT_START();



	uart_read((uint8_t *)uart_rcv, 64, rlpool_read);//auto test


	//LOG_INFO("Plf init done");

	LOG_INFO("Plf init done");
	i2c_write(0x01,16);
	uint8_t data = i2c_read(0x1);


    while(1) {
    	/*int i = 0;
    	for(i = 0;i < 10000; i++)
    	{

    	}
    	LOG_INFO("schedule");*/
    	plf_schedule();//auto test
    }
}
