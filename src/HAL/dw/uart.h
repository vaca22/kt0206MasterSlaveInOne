/**
 ****************************************************************************************
 *
 * @file uart.h
 *
 * @brief UART Driver for HCI over UART operation.
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 *
 ****************************************************************************************
 */

#ifndef _UART_H_
#define _UART_H_

/**
 ****************************************************************************************
 * @defgroup UART UART
 * @ingroup DRIVERS
 * @brief UART driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions


/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

typedef uint16_t uart_size_t;

/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

/// Generic enable/disable enum for UART driver
enum
{
    /// uart disable
    UART_DISABLE = 0,
    /// uart enable
    UART_ENABLE  = 1
};

/// Character format
enum
{
    /// char format 5
    UART_CHARFORMAT_5 = 0,
    /// char format 6
    UART_CHARFORMAT_6 = 1,
    /// char format 7
    UART_CHARFORMAT_7 = 2,
    /// char format 8
    UART_CHARFORMAT_8 = 3
};

/// Stop bit
enum
{
    /// stop bit 1
    UART_STOPBITS_1 = 0,
    /* Note: The number of stop bits is 1.5 if a
     * character format with 5 bit is chosen */
    /// stop bit 2
    UART_STOPBITS_2 = 1
};

/// Parity bit
enum
{
    /// even parity
    UART_PARITYBIT_NO    = 0,
    /// odd parity
    UART_PARITYBIT_ODD   = 1,
    /// space parity
    UART_PARITYBIT_EVNT  = 2, // The parity bit is always 0.
};

/* Error detection */
enum
{
    /// error detection disabled
    UART_ERROR_DETECT_DISABLED = 0,
    /// error detection enabled
    UART_ERROR_DETECT_ENABLED  = 1
};

/* Trigger level in receiver FIFO at witch the Receive Data Available Interrupt is generated. */
enum
{
    UART_RCVR_T_1_CHAR       = 0,
    UART_RCVR_T_QUARTER_FULL = 1,
    UART_RCVR_T_HALF_FULL    = 2,
    UART_RCVR_T_FULL         = 3
};

/* Empty threshold level at witch the Transmit Holding Register Empty Interrupt is generated. */
enum
{
    UART_TXEMP_T_EMPTY        = 0,
    UART_TXEMP_T_2_CHAR       = 1,
    UART_TXEMP_T_QUARTER_FULL = 2,
    UART_TXEMP_T_HALF_FULL    = 3
};

typedef struct
{
	volatile uint16_t rd;
    volatile uint16_t wr;
    volatile uint8_t *buf;
    volatile uint16_t buf_size;
    volatile uint8_t full_flag;
}uart_transs_t;

typedef struct
{
    uart_transs_t tx;
    uart_transs_t rx;
}uart_t;

extern uart_t g_uart;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

extern char uart_getchar(void);
extern uint16_t uart_in_waiting(void);
extern uint16_t uart_read(uint8_t *buf, uint16_t buf_size);
extern uint32_t uart_init(uint32_t BaudRate);
extern uint32_t new_uart_init(uint32_t uBaudRate);

extern uint32_t uart_start(uint32_t BaudRate);
extern void uart_stop(void);
extern void uart_uninit(void);
extern uint16_t uart_write(uint8_t *buf, uint16_t buf_size);
extern void uart_flush(void);
extern int uart_write_flush(uint8_t *buf, int buf_size);
extern int uart_send_byte(uint8_t ucData);
extern int uart_send_byte_flush(uint8_t ucData);

extern void uart_tx_buf_size_set(uint16_t byte_size);
extern uint16_t uart_tx_buf_size_get();
extern void uart_rx_buf_size_set(uint16_t byte_size);
extern uint16_t uart_rx_buf_size_get();

extern uint32_t uart_buf_init(uint16_t txbuf_size, uint16_t rxbuf_size);
extern uint32_t new_uart_init(uint32_t uBaudRate);

extern inline void uart_putchar(uint8_t dat);



/// @} UART

#endif /* _UART_H_ */
