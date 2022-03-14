/**
 ****************************************************************************************
 *
 * @file uart.c
 *
 * @brief UART driver
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup UART
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>

#include "arch.h"
#include "co_math.h"
#include "co_mem.h"
#include "intc.h"
#include "uart.h"       // uart definition
#include "clk.h"
#include "reg_clkrst.h" // Onchip Register
#include "reg_uart.h"   // uart register

/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */
uint32_t uart_buf_init(uint16_t txbuf_size, uint16_t rxbuf_size)
{
    uart_tx_buf_size_set(txbuf_size);
    uart_rx_buf_size_set(rxbuf_size);
    memset(&g_uart, 0, sizeof(uart_t));
    g_uart.rx.buf_size = uart_rx_buf_size_get();
    g_uart.rx.buf = (uint8_t *)mem_malloc("uart_rx", g_uart.rx.buf_size, 1);
    if(NULL == g_uart.rx.buf)
    {
        return ERR;
    }
    g_uart.tx.buf_size = uart_tx_buf_size_get();
    g_uart.tx.buf = (uint8_t *)mem_malloc("uart_tx", g_uart.tx.buf_size, 1);
    if(NULL == g_uart.tx.buf)
    {
        return ERR;
    }
    return OK;
}

uint32_t new_uart_init(uint32_t uBaudRate)
{
    uint32_t uRet;
    double BaudRate;

    BaudRate = uBaudRate/((double)24.576/24);
    uRet = uart_start(BaudRate);
    if(uRet != OK)
    {
        return ERR;
    }
    return OK;
}
