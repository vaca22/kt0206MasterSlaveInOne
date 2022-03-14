#ifndef _REG_TIMER_H_
#define _REG_TIMER_H_

#include <stdint.h>
#include "_reg_timer.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_TIMER_COUNT 44

#define REG_TIMER_DECODING_MASK 0x000000FF

/**
 * @brief LOAD_COUNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00             load_cnt   0x0
 * </pre>
 */
#define TIMER_LOAD_COUNT_ADDR   0xC0011000
#define TIMER_LOAD_COUNT_OFFSET 0x00000000
#define TIMER_LOAD_COUNT_INDEX  0x00000000
#define TIMER_LOAD_COUNT_RESET  0x00000000
#define TIMER_LOAD_COUNT_COUNT  16

__INLINE uint32_t timer_load_count_get(int reg_idx)
{
    return REG_PL_RD(TIMER_LOAD_COUNT_ADDR + reg_idx * 0x14);
}

__INLINE void timer_load_count_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(TIMER_LOAD_COUNT_ADDR + reg_idx * 0x14, value);
}

// field definitions
#define TIMER_LOAD_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define TIMER_LOAD_CNT_LSB    0
#define TIMER_LOAD_CNT_WIDTH  ((uint32_t)0x00000020)

#define TIMER_LOAD_CNT_RST    0x0

__INLINE uint32_t timer_load_cnt_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_LOAD_COUNT_ADDR + reg_idx * 0x14);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void timer_load_cnt_setf(int reg_idx, uint32_t loadcnt)
{
    ASSERT_ERR((((uint32_t)loadcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(TIMER_LOAD_COUNT_ADDR + reg_idx * 0x14, (uint32_t)loadcnt << 0);
}

/**
 * @brief CURR_VALUE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00             curr_val   0x0
 * </pre>
 */
#define TIMER_CURR_VALUE_ADDR   0xC0011004
#define TIMER_CURR_VALUE_OFFSET 0x00000004
#define TIMER_CURR_VALUE_INDEX  0x00000001
#define TIMER_CURR_VALUE_RESET  0x00000000
#define TIMER_CURR_VALUE_COUNT  16

__INLINE uint32_t timer_curr_value_get(int reg_idx)
{
    return REG_PL_RD(TIMER_CURR_VALUE_ADDR + reg_idx * 0x14);
}

__INLINE void timer_curr_value_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(TIMER_CURR_VALUE_ADDR + reg_idx * 0x14, value);
}

// field definitions
#define TIMER_CURR_VAL_MASK   ((uint32_t)0xFFFFFFFF)
#define TIMER_CURR_VAL_LSB    0
#define TIMER_CURR_VAL_WIDTH  ((uint32_t)0x00000020)

#define TIMER_CURR_VAL_RST    0x0

__INLINE uint32_t timer_curr_val_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_CURR_VALUE_ADDR + reg_idx * 0x14);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02             int_mask   0
 *     01                 mode   0
 *     00               enable   0
 * </pre>
 */
#define TIMER_CONTROL_ADDR   0xC0011008
#define TIMER_CONTROL_OFFSET 0x00000008
#define TIMER_CONTROL_INDEX  0x00000002
#define TIMER_CONTROL_RESET  0x00000000
#define TIMER_CONTROL_COUNT  16

__INLINE uint32_t timer_control_get(int reg_idx)
{
    return REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14);
}

__INLINE void timer_control_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(TIMER_CONTROL_ADDR + reg_idx * 0x14, value);
}

// field definitions
#define TIMER_INT_MASK_BIT    ((uint32_t)0x00000004)
#define TIMER_INT_MASK_POS    2
#define TIMER_MODE_BIT        ((uint32_t)0x00000002)
#define TIMER_MODE_POS        1
#define TIMER_ENABLE_BIT      ((uint32_t)0x00000001)
#define TIMER_ENABLE_POS      0

#define TIMER_INT_MASK_RST    0x0
#define TIMER_MODE_RST        0x0
#define TIMER_ENABLE_RST      0x0

__INLINE void timer_control_pack(int reg_idx, uint8_t intmask, uint8_t mode, uint8_t enable)
{
    ASSERT_ERR((((uint32_t)intmask << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)mode << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(TIMER_CONTROL_ADDR + reg_idx * 0x14,  ((uint32_t)intmask << 2) | ((uint32_t)mode << 1) | ((uint32_t)enable << 0));
}

__INLINE void timer_control_unpack(int reg_idx, uint8_t* intmask, uint8_t* mode, uint8_t* enable)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14);
    *intmask = (localVal & ((uint32_t)0x00000004)) >> 2;
    *mode = (localVal & ((uint32_t)0x00000002)) >> 1;
    *enable = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t timer_int_mask_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void timer_int_mask_setf(int reg_idx, uint8_t intmask)
{
    ASSERT_ERR((((uint32_t)intmask << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(TIMER_CONTROL_ADDR + reg_idx * 0x14, (REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14) & ~((uint32_t)0x00000004)) | ((uint32_t)intmask << 2));
}

__INLINE uint8_t timer_mode_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void timer_mode_setf(int reg_idx, uint8_t mode)
{
    ASSERT_ERR((((uint32_t)mode << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(TIMER_CONTROL_ADDR + reg_idx * 0x14, (REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14) & ~((uint32_t)0x00000002)) | ((uint32_t)mode << 1));
}

__INLINE uint8_t timer_enable_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void timer_enable_setf(int reg_idx, uint8_t enable)
{
    ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(TIMER_CONTROL_ADDR + reg_idx * 0x14, (REG_PL_RD(TIMER_CONTROL_ADDR + reg_idx * 0x14) & ~((uint32_t)0x00000001)) | ((uint32_t)enable << 0));
}

/**
 * @brief EOI register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00           end_of_int   0
 * </pre>
 */
#define TIMER_EOI_ADDR   0xC001100C
#define TIMER_EOI_OFFSET 0x0000000C
#define TIMER_EOI_INDEX  0x00000003
#define TIMER_EOI_RESET  0x00000000
#define TIMER_EOI_COUNT  16

__INLINE uint32_t timer_eoi_get(int reg_idx)
{
    return REG_PL_RD(TIMER_EOI_ADDR + reg_idx * 0x14);
}

__INLINE void timer_eoi_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(TIMER_EOI_ADDR + reg_idx * 0x14, value);
}

// field definitions
#define TIMER_END_OF_INT_BIT    ((uint32_t)0x00000001)
#define TIMER_END_OF_INT_POS    0

#define TIMER_END_OF_INT_RST    0x0

__INLINE uint8_t timer_end_of_int_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_EOI_ADDR + reg_idx * 0x14);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief INT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00               int_st   0
 * </pre>
 */
#define TIMER_INT_STATUS_ADDR   0xC0011010
#define TIMER_INT_STATUS_OFFSET 0x00000010
#define TIMER_INT_STATUS_INDEX  0x00000004
#define TIMER_INT_STATUS_RESET  0x00000000
#define TIMER_INT_STATUS_COUNT  16

__INLINE uint32_t timer_int_status_get(int reg_idx)
{
    return REG_PL_RD(TIMER_INT_STATUS_ADDR + reg_idx * 0x14);
}

__INLINE void timer_int_status_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(TIMER_INT_STATUS_ADDR + reg_idx * 0x14, value);
}

// field definitions
#define TIMER_INT_ST_BIT    ((uint32_t)0x00000001)
#define TIMER_INT_ST_POS    0

#define TIMER_INT_ST_RST    0x0

__INLINE uint8_t timer_int_st_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(TIMER_INT_STATUS_ADDR + reg_idx * 0x14);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ALL_INT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:00           all_int_st   0x0
 * </pre>
 */
#define TIMER_ALL_INT_STATUS_ADDR   0xC00110A0
#define TIMER_ALL_INT_STATUS_OFFSET 0x000000A0
#define TIMER_ALL_INT_STATUS_INDEX  0x00000028
#define TIMER_ALL_INT_STATUS_RESET  0x00000000

__INLINE uint32_t timer_all_int_status_get(void)
{
    return REG_PL_RD(TIMER_ALL_INT_STATUS_ADDR);
}

__INLINE void timer_all_int_status_set(uint32_t value)
{
    REG_PL_WR(TIMER_ALL_INT_STATUS_ADDR, value);
}

// field definitions
#define TIMER_ALL_INT_ST_MASK   ((uint32_t)0x0000000F)
#define TIMER_ALL_INT_ST_LSB    0
#define TIMER_ALL_INT_ST_WIDTH  ((uint32_t)0x00000004)

#define TIMER_ALL_INT_ST_RST    0x0

__INLINE uint8_t timer_all_int_st_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(TIMER_ALL_INT_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000000F)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ALL_EOI register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:00       all_end_of_int   0x0
 * </pre>
 */
#define TIMER_ALL_EOI_ADDR   0xC00110A4
#define TIMER_ALL_EOI_OFFSET 0x000000A4
#define TIMER_ALL_EOI_INDEX  0x00000029
#define TIMER_ALL_EOI_RESET  0x00000000

__INLINE uint32_t timer_all_eoi_get(void)
{
    return REG_PL_RD(TIMER_ALL_EOI_ADDR);
}

__INLINE void timer_all_eoi_set(uint32_t value)
{
    REG_PL_WR(TIMER_ALL_EOI_ADDR, value);
}

// field definitions
#define TIMER_ALL_END_OF_INT_MASK   ((uint32_t)0x0000000F)
#define TIMER_ALL_END_OF_INT_LSB    0
#define TIMER_ALL_END_OF_INT_WIDTH  ((uint32_t)0x00000004)

#define TIMER_ALL_END_OF_INT_RST    0x0

__INLINE uint8_t timer_all_end_of_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(TIMER_ALL_EOI_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000000F)) == 0);
    return (localVal >> 0);
}

/**
 * @brief RAW_INT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:00           raw_int_st   0x0
 * </pre>
 */
#define TIMER_RAW_INT_STATUS_ADDR   0xC00110A8
#define TIMER_RAW_INT_STATUS_OFFSET 0x000000A8
#define TIMER_RAW_INT_STATUS_INDEX  0x0000002A
#define TIMER_RAW_INT_STATUS_RESET  0x00000000

__INLINE uint32_t timer_raw_int_status_get(void)
{
    return REG_PL_RD(TIMER_RAW_INT_STATUS_ADDR);
}

__INLINE void timer_raw_int_status_set(uint32_t value)
{
    REG_PL_WR(TIMER_RAW_INT_STATUS_ADDR, value);
}

// field definitions
#define TIMER_RAW_INT_ST_MASK   ((uint32_t)0x0000000F)
#define TIMER_RAW_INT_ST_LSB    0
#define TIMER_RAW_INT_ST_WIDTH  ((uint32_t)0x00000004)

#define TIMER_RAW_INT_ST_RST    0x0

__INLINE uint8_t timer_raw_int_st_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(TIMER_RAW_INT_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000000F)) == 0);
    return (localVal >> 0);
}

/**
 * @brief COMP_VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00              version   0x0
 * </pre>
 */
#define TIMER_COMP_VERSION_ADDR   0xC00110AC
#define TIMER_COMP_VERSION_OFFSET 0x000000AC
#define TIMER_COMP_VERSION_INDEX  0x0000002B
#define TIMER_COMP_VERSION_RESET  0x00000000

__INLINE uint32_t timer_comp_version_get(void)
{
    return REG_PL_RD(TIMER_COMP_VERSION_ADDR);
}

__INLINE void timer_comp_version_set(uint32_t value)
{
    REG_PL_WR(TIMER_COMP_VERSION_ADDR, value);
}

// field definitions
#define TIMER_VERSION_MASK   ((uint32_t)0xFFFFFFFF)
#define TIMER_VERSION_LSB    0
#define TIMER_VERSION_WIDTH  ((uint32_t)0x00000020)

#define TIMER_VERSION_RST    0x0

__INLINE uint32_t timer_version_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(TIMER_COMP_VERSION_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_TIMER_H_

