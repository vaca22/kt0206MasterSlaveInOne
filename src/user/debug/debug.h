
/**
 * \file debug.h
 * \brief Debug functions
 * 
 * Copyright 2020 KTMicro Inc.
 */

#ifndef _DEBUG_H_
#define _DEBUG_H_
#include "stdio.h"
#include "uart.h"

/*debug on/off-------------------------------------------------------------------*/
#define KT020x_DEBUG

#ifdef KT020x_DEBUG
	#define uartInit(uBaudRate) new_uart_init(uBaudRate)
#else
	#define uartInit(uBaudRate)
#endif

/*user debug-------------------------------------------------------------------*/
#define UART_DEBUG_USER

#if (defined(KT020x_DEBUG) && defined(UART_DEBUG_USER))
	#define USER_DBG_OUT(...) 	printf(__VA_ARGS__)
#else
	#define USER_DBG_OUT(...)
#endif

/*api debug-------------------------------------------------------------------*/
/* Bitmask for selecting debug level information */
#define DBG_LVL_NONE        0x00 /* No print */
#define DBG_LVL_ERROR       0x01 /* Any error condition */
#define DBG_LVL_WARNING     0x02 /* Any warning condition */
#define DBG_LVL_INFO        0x04 /* Un-categorized information */
#define DBG_LVL_FUNC     	0x08 /* API function (except tick) */
#define DBG_LVL_SYS			0x10 /* print short messege*/
#define DBG_LVL_ALL 		0xFF /* open all print level*/

	/*control debug level*/
#ifdef KT020x_DEBUG
	#define DEBUG_LEVEL    	(DBG_LVL_WARNING | DBG_LVL_ERROR)
#else
	#define DEBUG_LEVEL 	DBG_LVL_NONE
#endif

#if (DEBUG_LEVEL & DBG_LVL_ERROR)
	#define DBG_OUT_ERR(msg, args...) 	printf("#ERROR:[%s:%d] "msg, __FUNCTION__, __LINE__, ##args)
#else
	#define DBG_OUT_ERR(msg, args...) 
#endif
#if (DEBUG_LEVEL & DBG_LVL_WARNING)
	#define DBG_OUT_WARN(msg, args...) 	printf("#WARNING:[%s:%d] "msg, __FUNCTION__, __LINE__, ##args)
#else
	#define DBG_OUT_WARN(msg, args...) 
#endif
#if (DEBUG_LEVEL & DBG_LVL_INFO)
	#define DBG_OUT_INFO(msg, args...) 	printf("#INFO:[%s:%d] "msg, __FUNCTION__, __LINE__, ##args)
#else
	#define DBG_OUT_INFO(msg, args...) 
#endif
#if (DEBUG_LEVEL & DBG_LVL_FUNC)
	#define DBG_OUT_FUNC(msg, args...) 	printf("#FUNC:[%s:%d] "msg, __FUNCTION__, __LINE__, ##args)
#else
	#define DBG_OUT_FUNC(msg, args...) 
#endif
#if (DEBUG_LEVEL & DBG_LVL_SYS)
	#define DBG_OUT_SYS(msg, args...) 	printf("#SYS:"msg, ##args)
#else
	#define DBG_OUT_SYS(msg, args...) 
#endif

#endif
