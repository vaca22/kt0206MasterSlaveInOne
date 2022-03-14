/**
 *
 */
#ifndef _DBG_LOG_H
#define _DBG_LOG_H

#include <stdint.h>
#include <stdarg.h>

#define DBG_LOG_OTHER       1
#define DBG_LOG_DEBUG       1
#define DBG_LOG_INFO        1
#define DBG_LOG_ERROR       1

typedef enum {
    LOG_LVL_OTHER = 0,
    LOG_LVL_DEBUG = 1,
    LOG_LVL_INFO  = 2,
    LOG_LVL_ERROR = 3,

    LOG_LVL_MAX,
} dbg_log_lvl_t;

#define DBG_DUMP_LOG(log_lvl, format, ...) dbg_dump_log(log_lvl, format, ## __VA_ARGS__)

#ifdef DBG_LOG_OTHER
#define LOG_OTHER(format, ...)  DBG_DUMP_LOG(LOG_LVL_OTHER, format,  ## __VA_ARGS__)
#else /* DBG_LOG_OTHER */
#define LOG_OTHER(format, ...)
#endif /* DBG_LOG_OTHER */

#ifdef DBG_LOG_DEBUG
#define LOG_DEBUG(format, ...)  DBG_DUMP_LOG(LOG_LVL_DEBUG, format "\r\n",  ## __VA_ARGS__)
#else /* DBG_LOG_DEBUG */
#define LOG_DEBUG(format, ...)
#endif /* DBG_LOG_DEBUG */

#ifdef DBG_LOG_INFO
#define LOG_INFO(format, ...)   DBG_DUMP_LOG(LOG_LVL_INFO, format "\r\n",  ## __VA_ARGS__)
#else /* DBG_LOG_INFO */
#define LOG_INFO(format, ...)
#endif /* DBG_LOG_INFO */

#ifdef DBG_LOG_ERROR
#define LOG_ERROR(format, ...)  DBG_DUMP_LOG(LOG_LVL_ERROR, format "\r\n",  ## __VA_ARGS__)
#else /* DBG_LOG_ERROR */
#define LOG_ERROR(format, ...)
#endif /* DBG_LOG_ERROR */

extern int (*dbg_putc)(int ch, FILE *f);
extern uint32_t (*dbg_get_time_ms)(void);
extern uint8_t log_lvl_enabled[4];

int dbg_dump_hex(const void *data, int size);
int dbg_dump_timestamp(void);
void dbg_dump_log(dbg_log_lvl_t log_lvl, const char *format, ...);

#endif /* _DBG_LOG_H */
