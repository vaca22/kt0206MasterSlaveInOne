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
#include "power_on.h"
#include "qspi_ctrl.h"

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

unsigned char Buf[256] =
{
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,

	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xf1, 0xf0,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0x04, 0x10, 0x00, 0x00,
};


// #define READ_QE
#define READ_ID
#define ERASE
#define PROGRAM

int main(void) {

	//plf_init();
	srand(1);
	ke_init();

	Headset_PowerOn(&g_stPowerOnPara);

	REG_PL_WR(0xC001206C, (REG_PL_RD(0xC001206C) | 5)); /* Clk_apb_div_sel: 00, clk_osc_high_div_sel: 5; 1/16 */
	REG_PL_WR(0xC0012100, (REG_PL_RD(0xC0012100) | 0x111100)); /* PMX_UART_FUNC */
	REG_PL_WR(0xC0012070, (REG_PL_RD(0xC0012070) | 0x23)); /* Enable UART clk */

	Sys_Init();

	intc_init();
	//g_I2C_SlaveInit_para.Addr |= ((OTP_inRAM.bs.I2C_SlaveAddr)&0x3)<<2;


	tim_init();
	uart_init();


	//i2c_init(&g_I2C_SlaveInit_para);
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


	// LOG_INFO("Plf init done \n");

	// LOG_INFO("Plf init done \n");
	//i2c_write(0x01,16);
	//uint8_t data = i2c_read(0x1);

    // Usb_Init(0X41840,0);
    // Usb_Set_HWConfing(0,0);
    // Usb_Opean(0,0,0,0);
    
	/*********************************************************************************************/

	uint32_t uID;
	uint16_t i;
	uint16_t usRetValue;
	uint8_t ucQE;

	uint32_t uSector_address = 0x0;
	uint32_t uPage_address = 0x0;


	QSPI_Init();

	LOG_INFO("Muses~Here \n");

#ifdef READ_QE
	while(1)
	{
		if(1 == qspi_xip_status_eflash_rdqe_done_getf())
		{
			break;
		}
	}
	ucQE = qspi_xip_status_eflash_qe_getf();
	LOG_INFO("qe1 = 0x%01x \n", ucQE);

	/* 0. 退出xip */
    qspi_xip_ctrl0_xip_req_setf(0);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 1. read QE 0x35 */
    qspi_tx_dr_tx_dr_setf(eflash_ReadStatus2);

    /* ss=0 */
    qspi_regtran_ctrl_ss_n_setf(0);

    /* wait tx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_tx_finish_getf())
        {
            break;
        }
    }

    /* 开启接收 */
    qspi_regtran_ctrl_byte_size_setf(0);
    qspi_regtran_ctrl_recv_en_setf(1);
    qspi_regtran_ctrl_recv_cnt_setf(1);

    /* wait rx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_rx_finish_getf())
        {
            break;
        }
    }

    // 取得id值
    ucQE = qspi_rx_dr_rx_dr_getf();

    /* ss=1 */
    qspi_regtran_ctrl_ss_n_setf(1);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 2. 进入xip */
    qspi_xip_ctrl0_xip_req_setf(1);

    LOG_INFO("qe2 = 0x%02x \n", ucQE);


    uID = qspi_eflash_status_eflash_line_getf();
    LOG_INFO("eflash_line = 0x%02x \n", uID);

    uID = qspi_eflash_status_eflash_type_getf();
    LOG_INFO("eflash_type = 0x%02x \n", uID);
#endif

#ifdef READ_ID
	uID = QSPI_ID_Read();
	LOG_INFO("id1 = 0x%06x \n", uID);

	// while(1)
	// {
	// 	if(1 == qspi_eflash_id_eflash_rdid_done_getf())
	// 	{
	// 		break;
	// 	}
	// }
	// uID = qspi_eflash_id_eflash_id_getf();
	// LOG_INFO("id2 = 0x%06x \n", uID);
	LOG_INFO("Muses~Here \n");
#endif	

#ifdef ERASE
	LOG_INFO("Erase Sector Start \n");

	for(i=0; i<64; i++)
	{
		usRetValue = Flash_SectorErase(uSector_address);
		if(ERR == usRetValue)
		{
			LOG_INFO("Erase Sector %d failed \n", i);
			break;
		}
		uSector_address += SECTOR_SIZE;
	}

	if(ERR != usRetValue)
	{
		LOG_INFO("Erase Sector success \n");
	}
	
	LOG_INFO("Muses~Here \n");
#endif

#ifdef READ_QE
	while(1)
	{
		if(1 == qspi_xip_status_eflash_rdqe_done_getf())
		{
			break;
		}
	}
	uID = qspi_xip_status_eflash_qe_getf();
	LOG_INFO("qe1 = 0x%01x \n", uID);

	/* 0. 退出xip */
    qspi_xip_ctrl0_xip_req_setf(0);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 1. read QE 0x35 */
    qspi_tx_dr_tx_dr_setf(eflash_ReadStatus2);

    /* ss=0 */
    qspi_regtran_ctrl_ss_n_setf(0);

    /* wait tx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_tx_finish_getf())
        {
            break;
        }
    }

    /* 开启接收 */
    qspi_regtran_ctrl_byte_size_setf(0);
    qspi_regtran_ctrl_recv_en_setf(1);
    qspi_regtran_ctrl_recv_cnt_setf(1);

    /* wait rx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_rx_finish_getf())
        {
            break;
        }
    }

    // 取得id值
    uID = qspi_rx_dr_rx_dr_getf();

    /* ss=1 */
    qspi_regtran_ctrl_ss_n_setf(1);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 2. 进入xip */
    qspi_xip_ctrl0_xip_req_setf(1);

    LOG_INFO("qe2 = 0x%02x \n", uID);


    uID = qspi_eflash_status_eflash_line_getf();
    LOG_INFO("eflash_line = 0x%02x \n", uID);

    uID = qspi_eflash_status_eflash_type_getf();
    LOG_INFO("eflash_type = 0x%02x \n", uID);
#endif

#ifdef PROGRAM
	LOG_INFO("Write Page Start \n");

	for(i=0; i<1024; i++)
	{
		usRetValue = Flash_PageWrite(uPage_address, Buf);
		if(ERR == usRetValue)
		{
			LOG_INFO("Write Page %d failed \n", i+1);
			break;
		}
		uPage_address += PAGE_SIZE;
	}

	if(ERR != usRetValue)
	{
		LOG_INFO("Write Page success \n");
	}
	
	LOG_INFO("Muses~Here \n");
#endif

#ifdef READ_QE
	while(1)
	{
		if(1 == qspi_xip_status_eflash_rdqe_done_getf())
		{
			break;
		}
	}
	uID = qspi_xip_status_eflash_qe_getf();
	LOG_INFO("qe1 = 0x%01x \n", uID);

	/* 0. 退出xip */
    qspi_xip_ctrl0_xip_req_setf(0);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 1. read QE 0x35 */
    qspi_tx_dr_tx_dr_setf(eflash_ReadStatus2);

    /* ss=0 */
    qspi_regtran_ctrl_ss_n_setf(0);

    /* wait tx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_tx_finish_getf())
        {
            break;
        }
    }

    /* 开启接收 */
    qspi_regtran_ctrl_byte_size_setf(0);
    qspi_regtran_ctrl_recv_en_setf(1);
    qspi_regtran_ctrl_recv_cnt_setf(1);

    /* wait rx finish */
    while(1)
    {
        if(1 == qspi_fifo_status_rx_finish_getf())
        {
            break;
        }
    }

    // 取得id值
    uID = qspi_rx_dr_rx_dr_getf();

    /* ss=1 */
    qspi_regtran_ctrl_ss_n_setf(1);

    //flush fifo
    qspi_fifo_ctrl_fifo_flush_setf(1);

    /* 2. 进入xip */
    qspi_xip_ctrl0_xip_req_setf(1);

    LOG_INFO("qe2 = 0x%02x \n", uID);


    uID = qspi_eflash_status_eflash_line_getf();
    LOG_INFO("eflash_line = 0x%02x \n", uID);

    uID = qspi_eflash_status_eflash_type_getf();
    LOG_INFO("eflash_type = 0x%02x \n", uID);
#endif

	// while(1)
	// {
	// 	LOG_INFO("Muses~Here \n");
	// }

	/*********************************************************************************************/

    while(1) {
    	int i = 0;
    	for(i = 0;i < 10000; i++)
    	{

    	}
    	// LOG_INFO("Muses~Here \n");
    	// LOG_INFO("schedule \n");
    	plf_schedule();//auto test
    }
}
