/**
 ****************************************************************************************
 *
 * @file reg_access.h
 *
 * @brief File implementing the basic primitives for register accesses
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 *
 ****************************************************************************************
 */

#ifndef REG_ACCESS_H_
#define REG_ACCESS_H_

/**
 ****************************************************************************************
 * @addtogroup REG REG_ACCESS
 * @ingroup DRIVERS
 *
 * @brief Basic primitives for register access
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>            // string functions


/*
 * MACROS
 ****************************************************************************************
 */
/// Macro to read a platform register
#define REG_PL_RD(addr)             (*(volatile uint32_t *)(addr))

/// Macro to write a platform register
#define REG_PL_WR(addr, value)      (*(volatile uint32_t *)(addr)) = (value)

#include "i2c.h"

#define REG_RIPL_RD                 i2c_read
#define REG_RIPL_WR                 i2c_write

/// @} REG

#endif // REG_ACCESS_H_
