/**
 ****************************************************************************************
 *
 * @file rlpool.h
 *
 * @brief store the data that read from uart by ring buffer
 *
 * @author Allan
 *
 * Copyright (C), 2017 - 2018,  KT Micro,Inc.
 *
 *
 ****************************************************************************************
 */
#ifndef _RLPOOL_H
#define _RLPOOL_H
/**
 ****************************************************************************************
 * @addtogroup RLPOOL
 * @brief ring buffer for store data that read from uart
 *
 * This module contains the primitives that allow an application accessing and running
 *
 * @{
 ****************************************************************************************
 */

#include "stdint.h"

#include "co_rbuf.h"


/**
 ****************************************************************************************
 * @brief store the data received from uart.
 *
 * @param[in]    transfered  Number of received data from uart
 *****************************************************************************************
 */
void rlpool_read(uart_size_t transfered);
/**
 ****************************************************************************************
 * @brief initialize the ring buffer for read uart data
 *
 * @param[out]   rl_buf      Pointer to the RX buffer for save uart data receive from uart
 *****************************************************************************************
 */
void rlpool_init(char* rl_buf);


/// @} RLPOOL
#endif /* _RLPOOL_H */
