/**
 ****************************************************************************************
 *
 * @file co_assert.h
 *
 * @brief Common Assert module
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 *
 ****************************************************************************************
 */

#ifndef _CO_ASSERT_H
#define _CO_ASSERT_H

/**
 ****************************************************************************************
 * @defgroup ASSERT
 * @ingroup COMMON
 *
 * @brief Assert module
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * ASSERTION CHECK
 ****************************************************************************************
 */
#if PLF_DEBUG

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)                              \
    do {                                              \
        if (!(cond)) {                                \
            assert_err(#cond, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)             \
    do {                                              \
        if (!(cond)) {                                \
            assert_param((int)param0, (int)param1, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)                             \
    do {                                              \
        if (!(cond)) {                                \
            assert_warn(#cond, __MODULE__, __LINE__); \
        }                                             \
    } while(0)

#else
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)

#endif //PLF_DEBUG


/*
 * FUNCTION DECLARATION
 *****************************************************************************************
 */

#if PLF_DEBUG
/**
 ****************************************************************************************
 * @brief Print the assertion error reason and loop forever.
 *
 * @param condition C string containing the condition.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void assert_err(const char *condition, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion error reason and loop forever.
 * The parameter value that is causing the assertion will also be disclosed.
 *
 * @param param parameter value that is caused the assertion.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void assert_param(int param0, int param1, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion warning reason.
 *
 * @param condition C string containing the condition.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void assert_warn(const char *condition, const char * file, int line);

#endif //PLF_DEBUG


/// @} ASSERT

#endif /* ifndef _CO_ASSERT_H */
