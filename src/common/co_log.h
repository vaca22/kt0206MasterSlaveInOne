/**
 ****************************************************************************************
 *
 * @file co_log.h
 *
 * @brief Common LOG functions
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 *
 ****************************************************************************************
 */

#ifndef _CO_LOG_H
#define _CO_LOG_H

/**
 ****************************************************************************************
 * @defgroup LOG
 * @ingroup COMMON
 *
 * @brief Common LOG functions
 *
 * @{
 *
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include <stdint.h>
#include <stdarg.h>


/*
 * MACROS DEFINITIONS
 *****************************************************************************************
 */

#if PLF_DEBUG

#define DBG_LOG_OTHER       1
#define DBG_LOG_DEBUG       1
#define DBG_LOG_INFO        1
#define DBG_LOG_ERROR       1

#define DBG_DUMP_LOG(log_lvl, format, ...) log_dump_log(log_lvl, format, ## __VA_ARGS__)

#ifdef DBG_LOG_OTHER
#define LOG_OTHER(format, ...)  DBG_DUMP_LOG(LOG_LVL_OTHER, format,  ## __VA_ARGS__)
#else /* DBG_LOG_OTHER */
#define LOG_OTHER(format, ...)
#endif /* DBG_LOG_OTHER */

#ifdef DBG_LOG_DEBUG
#define LOG_DEBUG(format, ...)  DBG_DUMP_LOG(LOG_LVL_DEBUG, format,  ## __VA_ARGS__)
#else /* DBG_LOG_DEBUG */
#define LOG_DEBUG(format, ...)
#endif /* DBG_LOG_DEBUG */

#ifdef DBG_LOG_INFO
#define LOG_INFO(format, ...)   DBG_DUMP_LOG(LOG_LVL_INFO, format,  ## __VA_ARGS__)
#else /* DBG_LOG_INFO */
#define LOG_INFO(format, ...)
#endif /* DBG_LOG_INFO */

#ifdef DBG_LOG_ERROR
#define LOG_ERROR(format, ...)  DBG_DUMP_LOG(LOG_LVL_ERROR, format,  ## __VA_ARGS__)
#else /* DBG_LOG_ERROR */
#define LOG_ERROR(format, ...)
#endif /* DBG_LOG_ERROR */

#else /* if PLF_DEBUG */

#define LOG_OTHER(format, ...)
#define LOG_DEBUG(format, ...)
#define LOG_INFO(format, ...)
#define LOG_ERROR(format, ...)

#endif /* if PLF_DEBUG */


/*
 * ENUMERATION DEFINITIONS
 *****************************************************************************************
 */

#if PLF_DEBUG
typedef enum {
    LOG_LVL_OTHER = 0,
    LOG_LVL_DEBUG = 1,
    LOG_LVL_INFO  = 2,
    LOG_LVL_ERROR = 3,

    LOG_LVL_MAX,
} dbg_log_lvl_t;
#endif /* if PLF_DEBUG */


/*
 * EXTERNAL VARIABLE DEFINITIONS
 *****************************************************************************************
 */

#if PLF_DEBUG
extern int (*log_output)(char *data, int size);
extern uint32_t (*dbg_get_time_ms)(void);
extern uint8_t log_lvl_enabled[4];
#endif /* if PLF_DEBUG */


/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

#if PLF_DEBUG

int log_printf(const char *format, ...);
int log_vprintf(const char *format, va_list argp);
int log_dump_hex(const void *data, int size);

/**
 * Print time stamp.
 *
 * @return  Length of time stamp string.
 */
int log_dump_timestamp(void);

void log_dump_log(dbg_log_lvl_t log_lvl, const char *format, ...);

#endif /* if PLF_DEBUG */


/// @} LOG

#endif /* _CO_LOG_H */
