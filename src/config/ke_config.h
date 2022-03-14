/**
 ****************************************************************************************
 *
 * @file ke_config.h
 *
 * @brief This file contains all the constant that can be changed in order to
 * tailor the kernel.
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 *
 ****************************************************************************************
 */

#ifndef _KE_CONFIG_H_
#define _KE_CONFIG_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup KERNEL KERNEL
 * @ingroup ROOT
 * @brief The Kernel module.
 *
 * The Kernel is responsible for providing essential OS features like time management,
 * inter-task communication, task management and message handling and administration.
 *
 * @{
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup CFG Settings and Configuration
 * @ingroup KERNEL
 * @brief Kernel Configuration
 *
 * @{
 ****************************************************************************************
 */

/*
 * CONSTANT DEFINITIONS
 ****************************************************************************************
 */
#define KE_MEM_RW       1
#define KE_MEM_LINUX    0
#define KE_MEM_LIBC     0

#define KE_FULL         1
#define KE_SEND_ONLY    0


/*
 * Event types definition
 ****************************************************************************************
 */
enum KE_EVENT_TYPE
{
    KE_EVENT_RLPOOL_RX,//auto test
    KE_EVENT_TLPOOL_TX,
    KE_EVENT_USB,
    KE_EVENT_MAX
};
enum KE_EVENT_MODE
{
    KE_MODE_EVENT,
    KE_MODE_ALWAYS,
    KE_MODE_MAX
};
/// @} CFG

#endif // _KE_CONFIG_H_
