
#include <nds32_intrinsic.h>
#include "comm.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "sin1k_32k_q31.h"
#include "nds32_filtering_math.h"
#include "nds32_basic_math.h"
#include "nds32_transform_math.h"
#include "comm.h"

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
#include "i2c.h"
#include "uart.h"
#include "intc.h"
#include "timer.h"

#include "tlpool.h"


#include "comm.h"
#include "config.h"
//#include "interrupt.h"
//#include "sys_init.h"
#include "cache.h"
#include "dw_uart.h"

#include "audio_in_out_test.h"
#include "audio.h"
#include "power_on.h"

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

//const uint8_t EMPTY[2] __attribute__((section(".EMPTY_SECTOR"))) = {};
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
	// i2c_init();

    // Initialize System Control module
    syscntl_init();

    // Initialize the Interrupt Controller
    intc_init();

    // Initialize the timer components
    tim_init();

    // Initialize the UART components
    uart_init();

    tlpool_init();

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

    uart_read((uint8_t *)uart_rcv, 64, uart_read_done);

    return 0;
}

__STATIC void plf_sleep_check(void)
{
}

__STATIC void plf_schedule(void)
{
    ke_event_schedule();
}

volatile q31_t Encode_Buf0[512] = {0};
volatile q31_t Encode_Buf1[512] = {0};
volatile q31_t Encode_Buf2[512] = {0};

void Audio_Encode_Test(q31_t *pAdcAddr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT8 Signal)
{
	UINT16 i;

	for(i = 0; i < SampleNum; i++)
	{
		if((Signal & BIT0) == BIT0){
			Encode_Buf0[i] = pAdcAddr[i];
		}
		if((Signal& (BIT4|BIT5)) == (BIT4|BIT5)){
			Encode_Buf1[i] = pI2sInlAddr[i];
			Encode_Buf2[i] = pI2sInrAddr[i];
		}
	}
}


const q31_t sin_data[] = {

           0  ,     12540   ,    23170   ,    30274  ,     32768  ,     30274  ,     23170  ,     12540  ,
           0  ,    -12540   ,   -23170   ,   -30274  ,    -32768  ,    -30274  ,    -23170  ,    -12540
};

void FIFO_SoftWrite( q31_t *pDaclAddr, q31_t *pDacrAddr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT8 Signal)
{
    static float Fs = 46875;
	static float LFsig = 2000;

    static float ldelta_phase_f;
    static int ldelta_phase = 0;
    static int lphase = 0;
    static int first_flag = 1;
    int lsample;
    UINT16 i;

    if(first_flag)
    {
		ldelta_phase_f = LFsig/Fs *65536;//32768;
		ldelta_phase = (int)ldelta_phase_f;
		first_flag = 0;
    }

	/************************** DAC ************************************/
	for(i = 0; i < SampleNum; i++)
	{
		//left channel
		if(lphase > 65535)//32767)
		{
			lphase = lphase - 65536;//32768;
		}
		lsample = nds32_sin_q15(lphase);
		// lsample = lsample >> 2;  //amp*0.5
		lphase = lphase + ldelta_phase;

//		 lsample = sin_data[i & 0x0F];
//		lsample = Encode_Buf0[i];

		if((Signal & BIT0) == BIT0){
			pDaclAddr[i] = lsample << 12;
		}
		if((Signal & BIT1) == BIT1){
			pDacrAddr[i] = lsample << 12;
		}
		if((Signal & (BIT2|BIT3)) == (BIT2|BIT3)){
			pI2sOutlAddr[i] = lsample << 12;
			pI2sOutrAddr[i] = lsample << 12;
		}
		
	}
}

volatile q31_t Decode_Buf[512] = {0};
void Audio_Decode(q31_t *pDaclAddr, q31_t *pDacrAddr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT8 Signal)
{
	FIFO_SoftWrite(pDaclAddr, pDacrAddr, pI2sOutlAddr, pI2sOutrAddr, SampleNum, Signal);
}

extern char uart_str[];
#define AUDIO_IN_TEST
#define AUDIO_OUT_TEST

int main(void) {

    //TODO - cache test
    cache_on();

    // Initialize the Interrupt Controller
    intc_init();

//    Headset_PO();

#ifdef AUDIO_IN_TEST
	//    g_SysData.IcMode = TX_IC_TX_MODE;
	//g_IoBufSys.audio_in_handler = Audio_Encode;
	IO_BUF_Iint(1, AUDIO_FIFO_ADDR, Audio_Encode_Test, NULL, 0x1, 0);
#endif

#ifdef AUDIO_OUT_TEST
	//    g_SysData.IcMode = RX_IC_RX_MODE;
	//g_IoBufSys.audio_out_handler = Audio_Decode;
	IO_BUF_Iint(0, AUDIO_DAC0_ADDR, Audio_Encode_Test, Audio_Decode, 0, 0x3);
#endif

	// Sys_Init();
    GLOBAL_INT_START();

    while(1) {
        //TODO - add Event FSM loop
        //TEST
    }
}
