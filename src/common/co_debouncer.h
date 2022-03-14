/**
 ****************************************************************************************
 *
 * @file co_debounce.h
 *
 * @brief Debouncer interface
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 *
 ****************************************************************************************
 */

#ifndef _CO_DEBOUNCER_H_
#define _CO_DEBOUNCER_H_

#include "arch.h"
#include <stdint.h>

typedef struct co_dbunc_stru {
    uint8_t samples_num;
    uint8_t cnt;
} co_dbunc_t;

__INLINE void co_dbunc_init(co_dbunc_t *dbunc, uint8_t samples_num)
{
    if (samples_num != 0) {
        dbunc->samples_num = samples_num;
    } else {
        dbunc->samples_num = 1;
    }
    dbunc->cnt = 0;
}

__INLINE uint8_t co_dbunc_input(co_dbunc_t *dbunc, uint8_t st_old, uint8_t st_new)
{
    if (st_old != st_new) {
        /* New state to be transit */
        if (dbunc->cnt == 0) {
            /* First new state input, start debouncing */
            dbunc->cnt = dbunc->samples_num;
        }

        dbunc->cnt--;
        if (dbunc->cnt == 0) {
            /* Stabilize at the new st_new */
            st_old = st_new;
        }
    } else if (dbunc->cnt != 0) {
        /* Oscillation, stop debounceing */
        dbunc->cnt = 0;
    }

    return st_old;
}

#endif /* _CO_DEBOUNCER_H_ */
