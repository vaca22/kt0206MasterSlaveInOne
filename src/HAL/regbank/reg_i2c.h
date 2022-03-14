#ifndef _REG_I2C_H_
#define _REG_I2C_H_

#include <stdint.h>
#include "_reg_i2c.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_I2C_COUNT 64

#define REG_I2C_DECODING_MASK 0x000000FF

/**
 * @brief CON register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06        SLAVE_DISABLE   0
 *     05           RESTART_EN   0
 *     04       ADDR_MASTER_RO   0
 *     03           ADDR_SLAVE   0
 *  02:01                SPEED   0x0
 *     00          MASTER_MODE   0
 * </pre>
 */
#define I2C_CON_ADDR   0xC0011C00
#define I2C_CON_OFFSET 0x00000000
#define I2C_CON_INDEX  0x00000000
#define I2C_CON_RESET  0x00000000

__INLINE uint32_t i2c_con_get(void)
{
    return REG_PL_RD(I2C_CON_ADDR);
}

__INLINE void i2c_con_set(uint32_t value)
{
    REG_PL_WR(I2C_CON_ADDR, value);
}

// field definitions
#define I2C_SLAVE_DISABLE_BIT     ((uint32_t)0x00000040)
#define I2C_SLAVE_DISABLE_POS     6
#define I2C_RESTART_EN_BIT        ((uint32_t)0x00000020)
#define I2C_RESTART_EN_POS        5
#define I2C_ADDR_MASTER_RO_BIT    ((uint32_t)0x00000010)
#define I2C_ADDR_MASTER_RO_POS    4
#define I2C_ADDR_SLAVE_BIT        ((uint32_t)0x00000008)
#define I2C_ADDR_SLAVE_POS        3
#define I2C_SPEED_MASK            ((uint32_t)0x00000006)
#define I2C_SPEED_LSB             1
#define I2C_SPEED_WIDTH           ((uint32_t)0x00000002)
#define I2C_MASTER_MODE_BIT       ((uint32_t)0x00000001)
#define I2C_MASTER_MODE_POS       0

#define I2C_SLAVE_DISABLE_RST     0x0
#define I2C_RESTART_EN_RST        0x0
#define I2C_ADDR_MASTER_RO_RST    0x0
#define I2C_ADDR_SLAVE_RST        0x0
#define I2C_SPEED_RST             0x0
#define I2C_MASTER_MODE_RST       0x0

__INLINE void i2c_con_pack(uint8_t slavedisable, uint8_t restarten, uint8_t addrslave, uint8_t speed, uint8_t mastermode)
{
    ASSERT_ERR((((uint32_t)slavedisable << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)restarten << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)addrslave << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)speed << 1) & ~((uint32_t)0x00000006)) == 0);
    ASSERT_ERR((((uint32_t)mastermode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_CON_ADDR,  ((uint32_t)slavedisable << 6) | ((uint32_t)restarten << 5) | ((uint32_t)addrslave << 3) | ((uint32_t)speed << 1) | ((uint32_t)mastermode << 0));
}

__INLINE void i2c_con_unpack(uint8_t* slavedisable, uint8_t* restarten, uint8_t* addrmasterro, uint8_t* addrslave, uint8_t* speed, uint8_t* mastermode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    *slavedisable = (localVal & ((uint32_t)0x00000040)) >> 6;
    *restarten = (localVal & ((uint32_t)0x00000020)) >> 5;
    *addrmasterro = (localVal & ((uint32_t)0x00000010)) >> 4;
    *addrslave = (localVal & ((uint32_t)0x00000008)) >> 3;
    *speed = (localVal & ((uint32_t)0x00000006)) >> 1;
    *mastermode = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_slave_disable_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void i2c_slave_disable_setf(uint8_t slavedisable)
{
    ASSERT_ERR((((uint32_t)slavedisable << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(I2C_CON_ADDR, (REG_PL_RD(I2C_CON_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)slavedisable << 6));
}

__INLINE uint8_t i2c_restart_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void i2c_restart_en_setf(uint8_t restarten)
{
    ASSERT_ERR((((uint32_t)restarten << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(I2C_CON_ADDR, (REG_PL_RD(I2C_CON_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)restarten << 5));
}

__INLINE uint8_t i2c_addr_master_ro_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_addr_slave_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void i2c_addr_slave_setf(uint8_t addrslave)
{
    ASSERT_ERR((((uint32_t)addrslave << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(I2C_CON_ADDR, (REG_PL_RD(I2C_CON_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)addrslave << 3));
}

__INLINE uint8_t i2c_speed_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000006)) >> 1);
}

__INLINE void i2c_speed_setf(uint8_t speed)
{
    ASSERT_ERR((((uint32_t)speed << 1) & ~((uint32_t)0x00000006)) == 0);
    REG_PL_WR(I2C_CON_ADDR, (REG_PL_RD(I2C_CON_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)speed << 1));
}

__INLINE uint8_t i2c_master_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CON_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void i2c_master_mode_setf(uint8_t mastermode)
{
    ASSERT_ERR((((uint32_t)mastermode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_CON_ADDR, (REG_PL_RD(I2C_CON_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)mastermode << 0));
}

/**
 * @brief TAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     12          ADDR_MASTER   0
 *     11              SPECIAL   0
 *     10          GC_OR_START   0
 *  09:00                  TAR   0x0
 * </pre>
 */
#define I2C_TAR_ADDR   0xC0011C04
#define I2C_TAR_OFFSET 0x00000004
#define I2C_TAR_INDEX  0x00000001
#define I2C_TAR_RESET  0x00000000

__INLINE uint32_t i2c_tar_get(void)
{
    return REG_PL_RD(I2C_TAR_ADDR);
}

__INLINE void i2c_tar_set(uint32_t value)
{
    REG_PL_WR(I2C_TAR_ADDR, value);
}

// field definitions
#define I2C_ADDR_MASTER_BIT    ((uint32_t)0x00001000)
#define I2C_ADDR_MASTER_POS    12
#define I2C_SPECIAL_BIT        ((uint32_t)0x00000800)
#define I2C_SPECIAL_POS        11
#define I2C_GC_OR_START_BIT    ((uint32_t)0x00000400)
#define I2C_GC_OR_START_POS    10
#define I2C_TAR_MASK           ((uint32_t)0x000003FF)
#define I2C_TAR_LSB            0
#define I2C_TAR_WIDTH          ((uint32_t)0x0000000A)

#define I2C_ADDR_MASTER_RST    0x0
#define I2C_SPECIAL_RST        0x0
#define I2C_GC_OR_START_RST    0x0
#define I2C_TAR_RST            0x0

__INLINE void i2c_tar_pack(uint8_t addrmaster, uint8_t special, uint8_t gcorstart, uint16_t tar)
{
    ASSERT_ERR((((uint32_t)addrmaster << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)special << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)gcorstart << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)tar << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(I2C_TAR_ADDR,  ((uint32_t)addrmaster << 12) | ((uint32_t)special << 11) | ((uint32_t)gcorstart << 10) | ((uint32_t)tar << 0));
}

__INLINE void i2c_tar_unpack(uint8_t* addrmaster, uint8_t* special, uint8_t* gcorstart, uint16_t* tar)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TAR_ADDR);
    *addrmaster = (localVal & ((uint32_t)0x00001000)) >> 12;
    *special = (localVal & ((uint32_t)0x00000800)) >> 11;
    *gcorstart = (localVal & ((uint32_t)0x00000400)) >> 10;
    *tar = (localVal & ((uint32_t)0x000003FF)) >> 0;
}

__INLINE uint8_t i2c_addr_master_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TAR_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void i2c_addr_master_setf(uint8_t addrmaster)
{
    ASSERT_ERR((((uint32_t)addrmaster << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(I2C_TAR_ADDR, (REG_PL_RD(I2C_TAR_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)addrmaster << 12));
}

__INLINE uint8_t i2c_special_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TAR_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void i2c_special_setf(uint8_t special)
{
    ASSERT_ERR((((uint32_t)special << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(I2C_TAR_ADDR, (REG_PL_RD(I2C_TAR_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)special << 11));
}

__INLINE uint8_t i2c_gc_or_start_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TAR_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void i2c_gc_or_start_setf(uint8_t gcorstart)
{
    ASSERT_ERR((((uint32_t)gcorstart << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(I2C_TAR_ADDR, (REG_PL_RD(I2C_TAR_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gcorstart << 10));
}

__INLINE uint16_t i2c_tar_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TAR_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}

__INLINE void i2c_tar_setf(uint16_t tar)
{
    ASSERT_ERR((((uint32_t)tar << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(I2C_TAR_ADDR, (REG_PL_RD(I2C_TAR_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)tar << 0));
}

/**
 * @brief SAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  09:00                  SAR   0x0
 * </pre>
 */
#define I2C_SAR_ADDR   0xC0011C08
#define I2C_SAR_OFFSET 0x00000008
#define I2C_SAR_INDEX  0x00000002
#define I2C_SAR_RESET  0x00000000

__INLINE uint32_t i2c_sar_get(void)
{
    return REG_PL_RD(I2C_SAR_ADDR);
}

__INLINE void i2c_sar_set(uint32_t value)
{
    REG_PL_WR(I2C_SAR_ADDR, value);
}

// field definitions
#define I2C_SAR_MASK   ((uint32_t)0x000003FF)
#define I2C_SAR_LSB    0
#define I2C_SAR_WIDTH  ((uint32_t)0x0000000A)

#define I2C_SAR_RST    0x0

__INLINE uint16_t i2c_sar_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_SAR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000003FF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_sar_setf(uint16_t sar)
{
    ASSERT_ERR((((uint32_t)sar << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(I2C_SAR_ADDR, (uint32_t)sar << 0);
}

/**
 * @brief HS_MADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  02:00               HS_MAR   0x0
 * </pre>
 */
#define I2C_HS_MADDR_ADDR   0xC0011C0C
#define I2C_HS_MADDR_OFFSET 0x0000000C
#define I2C_HS_MADDR_INDEX  0x00000003
#define I2C_HS_MADDR_RESET  0x00000000

__INLINE uint32_t i2c_hs_maddr_get(void)
{
    return REG_PL_RD(I2C_HS_MADDR_ADDR);
}

__INLINE void i2c_hs_maddr_set(uint32_t value)
{
    REG_PL_WR(I2C_HS_MADDR_ADDR, value);
}

// field definitions
#define I2C_HS_MAR_MASK   ((uint32_t)0x00000007)
#define I2C_HS_MAR_LSB    0
#define I2C_HS_MAR_WIDTH  ((uint32_t)0x00000003)

#define I2C_HS_MAR_RST    0x0

__INLINE uint8_t i2c_hs_mar_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_HS_MADDR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000007)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_hs_mar_setf(uint8_t hsmar)
{
    ASSERT_ERR((((uint32_t)hsmar << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(I2C_HS_MADDR_ADDR, (uint32_t)hsmar << 0);
}

/**
 * @brief DATA_CMD register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     08                  CMD   0
 *  07:00                  DAT   0x0
 * </pre>
 */
#define I2C_DATA_CMD_ADDR   0xC0011C10
#define I2C_DATA_CMD_OFFSET 0x00000010
#define I2C_DATA_CMD_INDEX  0x00000004
#define I2C_DATA_CMD_RESET  0x00000000

__INLINE uint32_t i2c_data_cmd_get(void)
{
    return REG_PL_RD(I2C_DATA_CMD_ADDR);
}

__INLINE void i2c_data_cmd_set(uint32_t value)
{
    REG_PL_WR(I2C_DATA_CMD_ADDR, value);
}

// field definitions
#define I2C_CMD_BIT    ((uint32_t)0x00000100)
#define I2C_CMD_POS    8
#define I2C_DAT_MASK   ((uint32_t)0x000000FF)
#define I2C_DAT_LSB    0
#define I2C_DAT_WIDTH  ((uint32_t)0x00000008)

#define I2C_CMD_RST    0x0
#define I2C_DAT_RST    0x0

__INLINE void i2c_data_cmd_pack(uint8_t cmd, uint8_t dat)
{
    ASSERT_ERR((((uint32_t)cmd << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)dat << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(I2C_DATA_CMD_ADDR,  ((uint32_t)cmd << 8) | ((uint32_t)dat << 0));
}

__INLINE void i2c_data_cmd_unpack(uint8_t* cmd, uint8_t* dat)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DATA_CMD_ADDR);
    *cmd = (localVal & ((uint32_t)0x00000100)) >> 8;
    *dat = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE void i2c_cmd_setf(uint8_t cmd)
{
    ASSERT_ERR((((uint32_t)cmd << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(I2C_DATA_CMD_ADDR, (REG_PL_RD(I2C_DATA_CMD_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmd << 8));
}

__INLINE uint8_t i2c_dat_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DATA_CMD_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void i2c_dat_setf(uint8_t dat)
{
    ASSERT_ERR((((uint32_t)dat << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(I2C_DATA_CMD_ADDR, (REG_PL_RD(I2C_DATA_CMD_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)dat << 0));
}

/**
 * @brief SS_SCL_HCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          SS_SCL_HCNT   0x0
 * </pre>
 */
#define I2C_SS_SCL_HCNT_ADDR   0xC0011C14
#define I2C_SS_SCL_HCNT_OFFSET 0x00000014
#define I2C_SS_SCL_HCNT_INDEX  0x00000005
#define I2C_SS_SCL_HCNT_RESET  0x00000000

__INLINE uint32_t i2c_ss_scl_hcnt_get(void)
{
    return REG_PL_RD(I2C_SS_SCL_HCNT_ADDR);
}

__INLINE void i2c_ss_scl_hcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_SS_SCL_HCNT_ADDR, value);
}

// field definitions
#define I2C_SS_SCL_HCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_SS_SCL_HCNT_LSB    0
#define I2C_SS_SCL_HCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_SS_SCL_HCNT_RST    0x0

__INLINE uint16_t i2c_ss_scl_hcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_SS_SCL_HCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_ss_scl_hcnt_setf(uint16_t sssclhcnt)
{
    ASSERT_ERR((((uint32_t)sssclhcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_SS_SCL_HCNT_ADDR, (uint32_t)sssclhcnt << 0);
}

/**
 * @brief SS_SCL_LCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          SS_SCL_LCNT   0x0
 * </pre>
 */
#define I2C_SS_SCL_LCNT_ADDR   0xC0011C18
#define I2C_SS_SCL_LCNT_OFFSET 0x00000018
#define I2C_SS_SCL_LCNT_INDEX  0x00000006
#define I2C_SS_SCL_LCNT_RESET  0x00000000

__INLINE uint32_t i2c_ss_scl_lcnt_get(void)
{
    return REG_PL_RD(I2C_SS_SCL_LCNT_ADDR);
}

__INLINE void i2c_ss_scl_lcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_SS_SCL_LCNT_ADDR, value);
}

// field definitions
#define I2C_SS_SCL_LCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_SS_SCL_LCNT_LSB    0
#define I2C_SS_SCL_LCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_SS_SCL_LCNT_RST    0x0

__INLINE uint16_t i2c_ss_scl_lcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_SS_SCL_LCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_ss_scl_lcnt_setf(uint16_t ssscllcnt)
{
    ASSERT_ERR((((uint32_t)ssscllcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_SS_SCL_LCNT_ADDR, (uint32_t)ssscllcnt << 0);
}

/**
 * @brief FS_SCL_HCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          FS_SCL_HCNT   0x0
 * </pre>
 */
#define I2C_FS_SCL_HCNT_ADDR   0xC0011C1C
#define I2C_FS_SCL_HCNT_OFFSET 0x0000001C
#define I2C_FS_SCL_HCNT_INDEX  0x00000007
#define I2C_FS_SCL_HCNT_RESET  0x00000000

__INLINE uint32_t i2c_fs_scl_hcnt_get(void)
{
    return REG_PL_RD(I2C_FS_SCL_HCNT_ADDR);
}

__INLINE void i2c_fs_scl_hcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_FS_SCL_HCNT_ADDR, value);
}

// field definitions
#define I2C_FS_SCL_HCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_FS_SCL_HCNT_LSB    0
#define I2C_FS_SCL_HCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_FS_SCL_HCNT_RST    0x0

__INLINE uint16_t i2c_fs_scl_hcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_FS_SCL_HCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_fs_scl_hcnt_setf(uint16_t fssclhcnt)
{
    ASSERT_ERR((((uint32_t)fssclhcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_FS_SCL_HCNT_ADDR, (uint32_t)fssclhcnt << 0);
}

/**
 * @brief FS_SCL_LCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          FS_SCL_LCNT   0x0
 * </pre>
 */
#define I2C_FS_SCL_LCNT_ADDR   0xC0011C20
#define I2C_FS_SCL_LCNT_OFFSET 0x00000020
#define I2C_FS_SCL_LCNT_INDEX  0x00000008
#define I2C_FS_SCL_LCNT_RESET  0x00000000

__INLINE uint32_t i2c_fs_scl_lcnt_get(void)
{
    return REG_PL_RD(I2C_FS_SCL_LCNT_ADDR);
}

__INLINE void i2c_fs_scl_lcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_FS_SCL_LCNT_ADDR, value);
}

// field definitions
#define I2C_FS_SCL_LCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_FS_SCL_LCNT_LSB    0
#define I2C_FS_SCL_LCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_FS_SCL_LCNT_RST    0x0

__INLINE uint16_t i2c_fs_scl_lcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_FS_SCL_LCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_fs_scl_lcnt_setf(uint16_t fsscllcnt)
{
    ASSERT_ERR((((uint32_t)fsscllcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_FS_SCL_LCNT_ADDR, (uint32_t)fsscllcnt << 0);
}

/**
 * @brief HS_SCL_HCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          HS_SCL_HCNT   0x0
 * </pre>
 */
#define I2C_HS_SCL_HCNT_ADDR   0xC0011C24
#define I2C_HS_SCL_HCNT_OFFSET 0x00000024
#define I2C_HS_SCL_HCNT_INDEX  0x00000009
#define I2C_HS_SCL_HCNT_RESET  0x00000000

__INLINE uint32_t i2c_hs_scl_hcnt_get(void)
{
    return REG_PL_RD(I2C_HS_SCL_HCNT_ADDR);
}

__INLINE void i2c_hs_scl_hcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_HS_SCL_HCNT_ADDR, value);
}

// field definitions
#define I2C_HS_SCL_HCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_HS_SCL_HCNT_LSB    0
#define I2C_HS_SCL_HCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_HS_SCL_HCNT_RST    0x0

__INLINE uint16_t i2c_hs_scl_hcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_HS_SCL_HCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_hs_scl_hcnt_setf(uint16_t hssclhcnt)
{
    ASSERT_ERR((((uint32_t)hssclhcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_HS_SCL_HCNT_ADDR, (uint32_t)hssclhcnt << 0);
}

/**
 * @brief HS_SCL_LCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00          HS_SCL_LCNT   0x0
 * </pre>
 */
#define I2C_HS_SCL_LCNT_ADDR   0xC0011C28
#define I2C_HS_SCL_LCNT_OFFSET 0x00000028
#define I2C_HS_SCL_LCNT_INDEX  0x0000000A
#define I2C_HS_SCL_LCNT_RESET  0x00000000

__INLINE uint32_t i2c_hs_scl_lcnt_get(void)
{
    return REG_PL_RD(I2C_HS_SCL_LCNT_ADDR);
}

__INLINE void i2c_hs_scl_lcnt_set(uint32_t value)
{
    REG_PL_WR(I2C_HS_SCL_LCNT_ADDR, value);
}

// field definitions
#define I2C_HS_SCL_LCNT_MASK   ((uint32_t)0x0000FFFF)
#define I2C_HS_SCL_LCNT_LSB    0
#define I2C_HS_SCL_LCNT_WIDTH  ((uint32_t)0x00000010)

#define I2C_HS_SCL_LCNT_RST    0x0

__INLINE uint16_t i2c_hs_scl_lcnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_HS_SCL_LCNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_hs_scl_lcnt_setf(uint16_t hsscllcnt)
{
    ASSERT_ERR((((uint32_t)hsscllcnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_HS_SCL_LCNT_ADDR, (uint32_t)hsscllcnt << 0);
}

/**
 * @brief INTR_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     11           R_GEN_CALL   0
 *     10          R_START_DET   0
 *     09           R_STOP_DET   0
 *     08           R_ACTIVITY   0
 *     07            R_RX_DONE   0
 *     06            R_TX_ABRT   0
 *     05             R_RD_REQ   0
 *     04           R_TX_EMPTY   0
 *     03            R_TX_OVER   0
 *     02            R_RX_FULL   0
 *     01            R_RX_OVER   0
 *     00           R_RX_UNDER   0
 * </pre>
 */
#define I2C_INTR_STAT_ADDR   0xC0011C2C
#define I2C_INTR_STAT_OFFSET 0x0000002C
#define I2C_INTR_STAT_INDEX  0x0000000B
#define I2C_INTR_STAT_RESET  0x00000000

__INLINE uint32_t i2c_intr_stat_get(void)
{
    return REG_PL_RD(I2C_INTR_STAT_ADDR);
}

// field definitions
#define I2C_R_GEN_CALL_BIT     ((uint32_t)0x00000800)
#define I2C_R_GEN_CALL_POS     11
#define I2C_R_START_DET_BIT    ((uint32_t)0x00000400)
#define I2C_R_START_DET_POS    10
#define I2C_R_STOP_DET_BIT     ((uint32_t)0x00000200)
#define I2C_R_STOP_DET_POS     9
#define I2C_R_ACTIVITY_BIT     ((uint32_t)0x00000100)
#define I2C_R_ACTIVITY_POS     8
#define I2C_R_RX_DONE_BIT      ((uint32_t)0x00000080)
#define I2C_R_RX_DONE_POS      7
#define I2C_R_TX_ABRT_BIT      ((uint32_t)0x00000040)
#define I2C_R_TX_ABRT_POS      6
#define I2C_R_RD_REQ_BIT       ((uint32_t)0x00000020)
#define I2C_R_RD_REQ_POS       5
#define I2C_R_TX_EMPTY_BIT     ((uint32_t)0x00000010)
#define I2C_R_TX_EMPTY_POS     4
#define I2C_R_TX_OVER_BIT      ((uint32_t)0x00000008)
#define I2C_R_TX_OVER_POS      3
#define I2C_R_RX_FULL_BIT      ((uint32_t)0x00000004)
#define I2C_R_RX_FULL_POS      2
#define I2C_R_RX_OVER_BIT      ((uint32_t)0x00000002)
#define I2C_R_RX_OVER_POS      1
#define I2C_R_RX_UNDER_BIT     ((uint32_t)0x00000001)
#define I2C_R_RX_UNDER_POS     0

#define I2C_R_GEN_CALL_RST     0x0
#define I2C_R_START_DET_RST    0x0
#define I2C_R_STOP_DET_RST     0x0
#define I2C_R_ACTIVITY_RST     0x0
#define I2C_R_RX_DONE_RST      0x0
#define I2C_R_TX_ABRT_RST      0x0
#define I2C_R_RD_REQ_RST       0x0
#define I2C_R_TX_EMPTY_RST     0x0
#define I2C_R_TX_OVER_RST      0x0
#define I2C_R_RX_FULL_RST      0x0
#define I2C_R_RX_OVER_RST      0x0
#define I2C_R_RX_UNDER_RST     0x0

__INLINE void i2c_intr_stat_unpack(uint8_t* rgencall, uint8_t* rstartdet, uint8_t* rstopdet, uint8_t* ractivity, uint8_t* rrxdone, uint8_t* rtxabrt, uint8_t* rrdreq, uint8_t* rtxempty, uint8_t* rtxover, uint8_t* rrxfull, uint8_t* rrxover, uint8_t* rrxunder)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    *rgencall = (localVal & ((uint32_t)0x00000800)) >> 11;
    *rstartdet = (localVal & ((uint32_t)0x00000400)) >> 10;
    *rstopdet = (localVal & ((uint32_t)0x00000200)) >> 9;
    *ractivity = (localVal & ((uint32_t)0x00000100)) >> 8;
    *rrxdone = (localVal & ((uint32_t)0x00000080)) >> 7;
    *rtxabrt = (localVal & ((uint32_t)0x00000040)) >> 6;
    *rrdreq = (localVal & ((uint32_t)0x00000020)) >> 5;
    *rtxempty = (localVal & ((uint32_t)0x00000010)) >> 4;
    *rtxover = (localVal & ((uint32_t)0x00000008)) >> 3;
    *rrxfull = (localVal & ((uint32_t)0x00000004)) >> 2;
    *rrxover = (localVal & ((uint32_t)0x00000002)) >> 1;
    *rrxunder = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_r_gen_call_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t i2c_r_start_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t i2c_r_stop_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t i2c_r_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t i2c_r_rx_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t i2c_r_tx_abrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t i2c_r_rd_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t i2c_r_tx_empty_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_r_tx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t i2c_r_rx_full_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t i2c_r_rx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t i2c_r_rx_under_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INTR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     11           M_GEN_CALL   0
 *     10          M_START_DET   0
 *     09           M_STOP_DET   0
 *     08           M_ACTIVITY   0
 *     07            M_RX_DONE   0
 *     06            M_TX_ABRT   0
 *     05             M_RD_REQ   0
 *     04           M_TX_EMPTY   0
 *     03            M_TX_OVER   0
 *     02            M_RX_FULL   0
 *     01            M_RX_OVER   0
 *     00           M_RX_UNDER   0
 * </pre>
 */
#define I2C_INTR_MASK_ADDR   0xC0011C30
#define I2C_INTR_MASK_OFFSET 0x00000030
#define I2C_INTR_MASK_INDEX  0x0000000C
#define I2C_INTR_MASK_RESET  0x00000000

__INLINE uint32_t i2c_intr_mask_get(void)
{
    return REG_PL_RD(I2C_INTR_MASK_ADDR);
}

__INLINE void i2c_intr_mask_set(uint32_t value)
{
    REG_PL_WR(I2C_INTR_MASK_ADDR, value);
}

// field definitions
#define I2C_M_GEN_CALL_BIT     ((uint32_t)0x00000800)
#define I2C_M_GEN_CALL_POS     11
#define I2C_M_START_DET_BIT    ((uint32_t)0x00000400)
#define I2C_M_START_DET_POS    10
#define I2C_M_STOP_DET_BIT     ((uint32_t)0x00000200)
#define I2C_M_STOP_DET_POS     9
#define I2C_M_ACTIVITY_BIT     ((uint32_t)0x00000100)
#define I2C_M_ACTIVITY_POS     8
#define I2C_M_RX_DONE_BIT      ((uint32_t)0x00000080)
#define I2C_M_RX_DONE_POS      7
#define I2C_M_TX_ABRT_BIT      ((uint32_t)0x00000040)
#define I2C_M_TX_ABRT_POS      6
#define I2C_M_RD_REQ_BIT       ((uint32_t)0x00000020)
#define I2C_M_RD_REQ_POS       5
#define I2C_M_TX_EMPTY_BIT     ((uint32_t)0x00000010)
#define I2C_M_TX_EMPTY_POS     4
#define I2C_M_TX_OVER_BIT      ((uint32_t)0x00000008)
#define I2C_M_TX_OVER_POS      3
#define I2C_M_RX_FULL_BIT      ((uint32_t)0x00000004)
#define I2C_M_RX_FULL_POS      2
#define I2C_M_RX_OVER_BIT      ((uint32_t)0x00000002)
#define I2C_M_RX_OVER_POS      1
#define I2C_M_RX_UNDER_BIT     ((uint32_t)0x00000001)
#define I2C_M_RX_UNDER_POS     0

#define I2C_M_GEN_CALL_RST     0x0
#define I2C_M_START_DET_RST    0x0
#define I2C_M_STOP_DET_RST     0x0
#define I2C_M_ACTIVITY_RST     0x0
#define I2C_M_RX_DONE_RST      0x0
#define I2C_M_TX_ABRT_RST      0x0
#define I2C_M_RD_REQ_RST       0x0
#define I2C_M_TX_EMPTY_RST     0x0
#define I2C_M_TX_OVER_RST      0x0
#define I2C_M_RX_FULL_RST      0x0
#define I2C_M_RX_OVER_RST      0x0
#define I2C_M_RX_UNDER_RST     0x0

__INLINE void i2c_intr_mask_pack(uint8_t mgencall, uint8_t mstartdet, uint8_t mstopdet, uint8_t mactivity, uint8_t mrxdone, uint8_t mtxabrt, uint8_t mrdreq, uint8_t mtxempty, uint8_t mtxover, uint8_t mrxfull, uint8_t mrxover, uint8_t mrxunder)
{
    ASSERT_ERR((((uint32_t)mgencall << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)mstartdet << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)mstopdet << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)mactivity << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)mrxdone << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)mtxabrt << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)mrdreq << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)mtxempty << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)mtxover << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)mrxfull << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)mrxover << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)mrxunder << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR,  ((uint32_t)mgencall << 11) | ((uint32_t)mstartdet << 10) | ((uint32_t)mstopdet << 9) | ((uint32_t)mactivity << 8) | ((uint32_t)mrxdone << 7) | ((uint32_t)mtxabrt << 6) | ((uint32_t)mrdreq << 5) | ((uint32_t)mtxempty << 4) | ((uint32_t)mtxover << 3) | ((uint32_t)mrxfull << 2) | ((uint32_t)mrxover << 1) | ((uint32_t)mrxunder << 0));
}

__INLINE void i2c_intr_mask_unpack(uint8_t* mgencall, uint8_t* mstartdet, uint8_t* mstopdet, uint8_t* mactivity, uint8_t* mrxdone, uint8_t* mtxabrt, uint8_t* mrdreq, uint8_t* mtxempty, uint8_t* mtxover, uint8_t* mrxfull, uint8_t* mrxover, uint8_t* mrxunder)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    *mgencall = (localVal & ((uint32_t)0x00000800)) >> 11;
    *mstartdet = (localVal & ((uint32_t)0x00000400)) >> 10;
    *mstopdet = (localVal & ((uint32_t)0x00000200)) >> 9;
    *mactivity = (localVal & ((uint32_t)0x00000100)) >> 8;
    *mrxdone = (localVal & ((uint32_t)0x00000080)) >> 7;
    *mtxabrt = (localVal & ((uint32_t)0x00000040)) >> 6;
    *mrdreq = (localVal & ((uint32_t)0x00000020)) >> 5;
    *mtxempty = (localVal & ((uint32_t)0x00000010)) >> 4;
    *mtxover = (localVal & ((uint32_t)0x00000008)) >> 3;
    *mrxfull = (localVal & ((uint32_t)0x00000004)) >> 2;
    *mrxover = (localVal & ((uint32_t)0x00000002)) >> 1;
    *mrxunder = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_m_gen_call_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void i2c_m_gen_call_setf(uint8_t mgencall)
{
    ASSERT_ERR((((uint32_t)mgencall << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)mgencall << 11));
}

__INLINE uint8_t i2c_m_start_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void i2c_m_start_det_setf(uint16_t mstartdet)
{
    ASSERT_ERR((((uint32_t)mstartdet << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)mstartdet << 10));
}

__INLINE uint8_t i2c_m_stop_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void i2c_m_stop_det_setf(uint16_t mstopdet)
{
    ASSERT_ERR((((uint32_t)mstopdet << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)mstopdet << 9));
}

__INLINE uint8_t i2c_m_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void i2c_m_activity_setf(uint8_t mactivity)
{
    ASSERT_ERR((((uint32_t)mactivity << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)mactivity << 8));
}

__INLINE uint8_t i2c_m_rx_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void i2c_m_rx_done_setf(uint8_t mrxdone)
{
    ASSERT_ERR((((uint32_t)mrxdone << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)mrxdone << 7));
}

__INLINE uint8_t i2c_m_tx_abrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void i2c_m_tx_abrt_setf(uint8_t mtxabrt)
{
    ASSERT_ERR((((uint32_t)mtxabrt << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)mtxabrt << 6));
}

__INLINE uint8_t i2c_m_rd_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void i2c_m_rd_req_setf(uint8_t mrdreq)
{
    ASSERT_ERR((((uint32_t)mrdreq << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)mrdreq << 5));
}

__INLINE uint8_t i2c_m_tx_empty_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void i2c_m_tx_empty_setf(uint8_t mtxempty)
{
    ASSERT_ERR((((uint32_t)mtxempty << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)mtxempty << 4));
}

__INLINE uint8_t i2c_m_tx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void i2c_m_tx_over_setf(uint8_t mtxover)
{
    ASSERT_ERR((((uint32_t)mtxover << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mtxover << 3));
}

__INLINE uint8_t i2c_m_rx_full_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void i2c_m_rx_full_setf(uint8_t mrxfull)
{
    ASSERT_ERR((((uint32_t)mrxfull << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)mrxfull << 2));
}

__INLINE uint8_t i2c_m_rx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void i2c_m_rx_over_setf(uint8_t mrxover)
{
    ASSERT_ERR((((uint32_t)mrxover << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)mrxover << 1));
}

__INLINE uint8_t i2c_m_rx_under_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_INTR_MASK_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void i2c_m_rx_under_setf(uint8_t mrxunder)
{
    ASSERT_ERR((((uint32_t)mrxunder << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_INTR_MASK_ADDR, (REG_PL_RD(I2C_INTR_MASK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)mrxunder << 0));
}

/**
 * @brief RAW_INTR_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     11             GEN_CALL   0
 *     10            START_DET   0
 *     09             STOP_DET   0
 *     08        ACTIVITY_INTR   0
 *     07              RX_DONE   0
 *     06              TX_ABRT   0
 *     05               RD_REQ   0
 *     04             TX_EMPTY   0
 *     03              TX_OVER   0
 *     02              RX_FULL   0
 *     01              RX_OVER   0
 *     00             RX_UNDER   0
 * </pre>
 */
#define I2C_RAW_INTR_STAT_ADDR   0xC0011C34
#define I2C_RAW_INTR_STAT_OFFSET 0x00000034
#define I2C_RAW_INTR_STAT_INDEX  0x0000000D
#define I2C_RAW_INTR_STAT_RESET  0x00000000

__INLINE uint32_t i2c_raw_intr_stat_get(void)
{
    return REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
}

// field definitions
#define I2C_GEN_CALL_BIT         ((uint32_t)0x00000800)
#define I2C_GEN_CALL_POS         11
#define I2C_START_DET_BIT        ((uint32_t)0x00000400)
#define I2C_START_DET_POS        10
#define I2C_STOP_DET_BIT         ((uint32_t)0x00000200)
#define I2C_STOP_DET_POS         9
#define I2C_ACTIVITY_INTR_BIT    ((uint32_t)0x00000100)
#define I2C_ACTIVITY_INTR_POS    8
#define I2C_RX_DONE_BIT          ((uint32_t)0x00000080)
#define I2C_RX_DONE_POS          7
#define I2C_TX_ABRT_BIT          ((uint32_t)0x00000040)
#define I2C_TX_ABRT_POS          6
#define I2C_RD_REQ_BIT           ((uint32_t)0x00000020)
#define I2C_RD_REQ_POS           5
#define I2C_TX_EMPTY_BIT         ((uint32_t)0x00000010)
#define I2C_TX_EMPTY_POS         4
#define I2C_TX_OVER_BIT          ((uint32_t)0x00000008)
#define I2C_TX_OVER_POS          3
#define I2C_RX_FULL_BIT          ((uint32_t)0x00000004)
#define I2C_RX_FULL_POS          2
#define I2C_RX_OVER_BIT          ((uint32_t)0x00000002)
#define I2C_RX_OVER_POS          1
#define I2C_RX_UNDER_BIT         ((uint32_t)0x00000001)
#define I2C_RX_UNDER_POS         0

#define I2C_GEN_CALL_RST         0x0
#define I2C_START_DET_RST        0x0
#define I2C_STOP_DET_RST         0x0
#define I2C_ACTIVITY_INTR_RST    0x0
#define I2C_RX_DONE_RST          0x0
#define I2C_TX_ABRT_RST          0x0
#define I2C_RD_REQ_RST           0x0
#define I2C_TX_EMPTY_RST         0x0
#define I2C_TX_OVER_RST          0x0
#define I2C_RX_FULL_RST          0x0
#define I2C_RX_OVER_RST          0x0
#define I2C_RX_UNDER_RST         0x0

__INLINE void i2c_raw_intr_stat_unpack(uint8_t* gencall, uint8_t* startdet, uint8_t* stopdet, uint8_t* activityintr, uint8_t* rxdone, uint8_t* txabrt, uint8_t* rdreq, uint8_t* txempty, uint8_t* txover, uint8_t* rxfull, uint8_t* rxover, uint8_t* rxunder)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    *gencall = (localVal & ((uint32_t)0x00000800)) >> 11;
    *startdet = (localVal & ((uint32_t)0x00000400)) >> 10;
    *stopdet = (localVal & ((uint32_t)0x00000200)) >> 9;
    *activityintr = (localVal & ((uint32_t)0x00000100)) >> 8;
    *rxdone = (localVal & ((uint32_t)0x00000080)) >> 7;
    *txabrt = (localVal & ((uint32_t)0x00000040)) >> 6;
    *rdreq = (localVal & ((uint32_t)0x00000020)) >> 5;
    *txempty = (localVal & ((uint32_t)0x00000010)) >> 4;
    *txover = (localVal & ((uint32_t)0x00000008)) >> 3;
    *rxfull = (localVal & ((uint32_t)0x00000004)) >> 2;
    *rxover = (localVal & ((uint32_t)0x00000002)) >> 1;
    *rxunder = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_gen_call_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t i2c_start_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t i2c_stop_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t i2c_activity_intr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t i2c_rx_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t i2c_tx_abrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t i2c_rd_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t i2c_tx_empty_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_tx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t i2c_rx_full_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t i2c_rx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t i2c_rx_under_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RAW_INTR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RX_TL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                RX_TL   0x0
 * </pre>
 */
#define I2C_RX_TL_ADDR   0xC0011C38
#define I2C_RX_TL_OFFSET 0x00000038
#define I2C_RX_TL_INDEX  0x0000000E
#define I2C_RX_TL_RESET  0x00000000

__INLINE uint32_t i2c_rx_tl_get(void)
{
    return REG_PL_RD(I2C_RX_TL_ADDR);
}

__INLINE void i2c_rx_tl_set(uint32_t value)
{
    REG_PL_WR(I2C_RX_TL_ADDR, value);
}

// field definitions
#define I2C_RX_TL_MASK   ((uint32_t)0x000000FF)
#define I2C_RX_TL_LSB    0
#define I2C_RX_TL_WIDTH  ((uint32_t)0x00000008)

#define I2C_RX_TL_RST    0x0

__INLINE uint8_t i2c_rx_tl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RX_TL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_rx_tl_setf(uint8_t rxtl)
{
    ASSERT_ERR((((uint32_t)rxtl << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(I2C_RX_TL_ADDR, (uint32_t)rxtl << 0);
}

/**
 * @brief TX_TL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                TX_TL   0x0
 * </pre>
 */
#define I2C_TX_TL_ADDR   0xC0011C3C
#define I2C_TX_TL_OFFSET 0x0000003C
#define I2C_TX_TL_INDEX  0x0000000F
#define I2C_TX_TL_RESET  0x00000000

__INLINE uint32_t i2c_tx_tl_get(void)
{
    return REG_PL_RD(I2C_TX_TL_ADDR);
}

__INLINE void i2c_tx_tl_set(uint32_t value)
{
    REG_PL_WR(I2C_TX_TL_ADDR, value);
}

// field definitions
#define I2C_TX_TL_MASK   ((uint32_t)0x000000FF)
#define I2C_TX_TL_LSB    0
#define I2C_TX_TL_WIDTH  ((uint32_t)0x00000008)

#define I2C_TX_TL_RST    0x0

__INLINE uint8_t i2c_tx_tl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_TL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_tx_tl_setf(uint8_t txtl)
{
    ASSERT_ERR((((uint32_t)txtl << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(I2C_TX_TL_ADDR, (uint32_t)txtl << 0);
}

/**
 * @brief CLR_INTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00             CLR_INTR   0
 * </pre>
 */
#define I2C_CLR_INTR_ADDR   0xC0011C40
#define I2C_CLR_INTR_OFFSET 0x00000040
#define I2C_CLR_INTR_INDEX  0x00000010
#define I2C_CLR_INTR_RESET  0x00000000

__INLINE uint32_t i2c_clr_intr_get(void)
{
    return REG_PL_RD(I2C_CLR_INTR_ADDR);
}

// field definitions
#define I2C_CLR_INTR_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_INTR_POS    0

#define I2C_CLR_INTR_RST    0x0

__INLINE uint8_t i2c_clr_intr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_INTR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_RX_UNDER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00         CLR_RX_UNDER   0
 * </pre>
 */
#define I2C_CLR_RX_UNDER_ADDR   0xC0011C44
#define I2C_CLR_RX_UNDER_OFFSET 0x00000044
#define I2C_CLR_RX_UNDER_INDEX  0x00000011
#define I2C_CLR_RX_UNDER_RESET  0x00000000

__INLINE uint32_t i2c_clr_rx_under_get(void)
{
    return REG_PL_RD(I2C_CLR_RX_UNDER_ADDR);
}

// field definitions
#define I2C_CLR_RX_UNDER_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_RX_UNDER_POS    0

#define I2C_CLR_RX_UNDER_RST    0x0

__INLINE uint8_t i2c_clr_rx_under_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_RX_UNDER_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_RX_OVER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00          CLR_RX_OVER   0
 * </pre>
 */
#define I2C_CLR_RX_OVER_ADDR   0xC0011C48
#define I2C_CLR_RX_OVER_OFFSET 0x00000048
#define I2C_CLR_RX_OVER_INDEX  0x00000012
#define I2C_CLR_RX_OVER_RESET  0x00000000

__INLINE uint32_t i2c_clr_rx_over_get(void)
{
    return REG_PL_RD(I2C_CLR_RX_OVER_ADDR);
}

// field definitions
#define I2C_CLR_RX_OVER_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_RX_OVER_POS    0

#define I2C_CLR_RX_OVER_RST    0x0

__INLINE uint8_t i2c_clr_rx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_RX_OVER_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_TX_OVER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00          CLR_TX_OVER   0
 * </pre>
 */
#define I2C_CLR_TX_OVER_ADDR   0xC0011C4C
#define I2C_CLR_TX_OVER_OFFSET 0x0000004C
#define I2C_CLR_TX_OVER_INDEX  0x00000013
#define I2C_CLR_TX_OVER_RESET  0x00000000

__INLINE uint32_t i2c_clr_tx_over_get(void)
{
    return REG_PL_RD(I2C_CLR_TX_OVER_ADDR);
}

// field definitions
#define I2C_CLR_TX_OVER_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_TX_OVER_POS    0

#define I2C_CLR_TX_OVER_RST    0x0

__INLINE uint8_t i2c_clr_tx_over_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_TX_OVER_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_RD_REQ register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00           CLR_RD_REQ   0
 * </pre>
 */
#define I2C_CLR_RD_REQ_ADDR   0xC0011C50
#define I2C_CLR_RD_REQ_OFFSET 0x00000050
#define I2C_CLR_RD_REQ_INDEX  0x00000014
#define I2C_CLR_RD_REQ_RESET  0x00000000

__INLINE uint32_t i2c_clr_rd_req_get(void)
{
    return REG_PL_RD(I2C_CLR_RD_REQ_ADDR);
}

// field definitions
#define I2C_CLR_RD_REQ_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_RD_REQ_POS    0

#define I2C_CLR_RD_REQ_RST    0x0

__INLINE uint8_t i2c_clr_rd_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_RD_REQ_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_TX_ABRT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00          CLR_TX_ABRT   0
 * </pre>
 */
#define I2C_CLR_TX_ABRT_ADDR   0xC0011C54
#define I2C_CLR_TX_ABRT_OFFSET 0x00000054
#define I2C_CLR_TX_ABRT_INDEX  0x00000015
#define I2C_CLR_TX_ABRT_RESET  0x00000000

__INLINE uint32_t i2c_clr_tx_abrt_get(void)
{
    return REG_PL_RD(I2C_CLR_TX_ABRT_ADDR);
}

// field definitions
#define I2C_CLR_TX_ABRT_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_TX_ABRT_POS    0

#define I2C_CLR_TX_ABRT_RST    0x0

__INLINE uint8_t i2c_clr_tx_abrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_TX_ABRT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_RX_DONE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00          CLR_RX_DONE   0
 * </pre>
 */
#define I2C_CLR_RX_DONE_ADDR   0xC0011C58
#define I2C_CLR_RX_DONE_OFFSET 0x00000058
#define I2C_CLR_RX_DONE_INDEX  0x00000016
#define I2C_CLR_RX_DONE_RESET  0x00000000

__INLINE uint32_t i2c_clr_rx_done_get(void)
{
    return REG_PL_RD(I2C_CLR_RX_DONE_ADDR);
}

// field definitions
#define I2C_CLR_RX_DONE_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_RX_DONE_POS    0

#define I2C_CLR_RX_DONE_RST    0x0

__INLINE uint8_t i2c_clr_rx_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_RX_DONE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_ACTIVITY register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00         CLR_ACTIVITY   0
 * </pre>
 */
#define I2C_CLR_ACTIVITY_ADDR   0xC0011C5C
#define I2C_CLR_ACTIVITY_OFFSET 0x0000005C
#define I2C_CLR_ACTIVITY_INDEX  0x00000017
#define I2C_CLR_ACTIVITY_RESET  0x00000000

__INLINE uint32_t i2c_clr_activity_get(void)
{
    return REG_PL_RD(I2C_CLR_ACTIVITY_ADDR);
}

// field definitions
#define I2C_CLR_ACTIVITY_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_ACTIVITY_POS    0

#define I2C_CLR_ACTIVITY_RST    0x0

__INLINE uint8_t i2c_clr_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_ACTIVITY_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_STOP_DET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00         CLR_STOP_DET   0
 * </pre>
 */
#define I2C_CLR_STOP_DET_ADDR   0xC0011C60
#define I2C_CLR_STOP_DET_OFFSET 0x00000060
#define I2C_CLR_STOP_DET_INDEX  0x00000018
#define I2C_CLR_STOP_DET_RESET  0x00000000

__INLINE uint32_t i2c_clr_stop_det_get(void)
{
    return REG_PL_RD(I2C_CLR_STOP_DET_ADDR);
}

// field definitions
#define I2C_CLR_STOP_DET_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_STOP_DET_POS    0

#define I2C_CLR_STOP_DET_RST    0x0

__INLINE uint8_t i2c_clr_stop_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_STOP_DET_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_START_DET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00        CLR_START_DET   0
 * </pre>
 */
#define I2C_CLR_START_DET_ADDR   0xC0011C64
#define I2C_CLR_START_DET_OFFSET 0x00000064
#define I2C_CLR_START_DET_INDEX  0x00000019
#define I2C_CLR_START_DET_RESET  0x00000000

__INLINE uint32_t i2c_clr_start_det_get(void)
{
    return REG_PL_RD(I2C_CLR_START_DET_ADDR);
}

// field definitions
#define I2C_CLR_START_DET_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_START_DET_POS    0

#define I2C_CLR_START_DET_RST    0x0

__INLINE uint8_t i2c_clr_start_det_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_START_DET_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLR_GEN_CALL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00         CLR_GEN_CALL   0
 * </pre>
 */
#define I2C_CLR_GEN_CALL_ADDR   0xC0011C68
#define I2C_CLR_GEN_CALL_OFFSET 0x00000068
#define I2C_CLR_GEN_CALL_INDEX  0x0000001A
#define I2C_CLR_GEN_CALL_RESET  0x00000000

__INLINE uint32_t i2c_clr_gen_call_get(void)
{
    return REG_PL_RD(I2C_CLR_GEN_CALL_ADDR);
}

// field definitions
#define I2C_CLR_GEN_CALL_BIT    ((uint32_t)0x00000001)
#define I2C_CLR_GEN_CALL_POS    0

#define I2C_CLR_GEN_CALL_RST    0x0

__INLINE uint8_t i2c_clr_gen_call_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_CLR_GEN_CALL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ENABLE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00               ENABLE   0
 * </pre>
 */
#define I2C_ENABLE_ADDR   0xC0011C6C
#define I2C_ENABLE_OFFSET 0x0000006C
#define I2C_ENABLE_INDEX  0x0000001B
#define I2C_ENABLE_RESET  0x00000000

__INLINE uint32_t i2c_enable_get(void)
{
    return REG_PL_RD(I2C_ENABLE_ADDR);
}

__INLINE void i2c_enable_set(uint32_t value)
{
    REG_PL_WR(I2C_ENABLE_ADDR, value);
}

// field definitions
#define I2C_ENABLE_BIT    ((uint32_t)0x00000001)
#define I2C_ENABLE_POS    0

#define I2C_ENABLE_RST    0x0

__INLINE uint8_t i2c_enable_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ENABLE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_enable_setf(uint8_t enable)
{
    ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_ENABLE_ADDR, (uint32_t)enable << 0);
}

/**
 * @brief STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06         SLV_ACTIVITY   0
 *     05         MST_ACTIVITY   0
 *     04                  RFF   0
 *     03                 RFNE   0
 *     02                  TFE   0
 *     01                 TFNF   0
 *     00             ACTIVITY   0
 * </pre>
 */
#define I2C_STATUS_ADDR   0xC0011C70
#define I2C_STATUS_OFFSET 0x00000070
#define I2C_STATUS_INDEX  0x0000001C
#define I2C_STATUS_RESET  0x00000000

__INLINE uint32_t i2c_status_get(void)
{
    return REG_PL_RD(I2C_STATUS_ADDR);
}

// field definitions
#define I2C_SLV_ACTIVITY_BIT    ((uint32_t)0x00000040)
#define I2C_SLV_ACTIVITY_POS    6
#define I2C_MST_ACTIVITY_BIT    ((uint32_t)0x00000020)
#define I2C_MST_ACTIVITY_POS    5
#define I2C_RFF_BIT             ((uint32_t)0x00000010)
#define I2C_RFF_POS             4
#define I2C_RFNE_BIT            ((uint32_t)0x00000008)
#define I2C_RFNE_POS            3
#define I2C_TFE_BIT             ((uint32_t)0x00000004)
#define I2C_TFE_POS             2
#define I2C_TFNF_BIT            ((uint32_t)0x00000002)
#define I2C_TFNF_POS            1
#define I2C_ACTIVITY_BIT        ((uint32_t)0x00000001)
#define I2C_ACTIVITY_POS        0

#define I2C_SLV_ACTIVITY_RST    0x0
#define I2C_MST_ACTIVITY_RST    0x0
#define I2C_RFF_RST             0x0
#define I2C_RFNE_RST            0x0
#define I2C_TFE_RST             0x0
#define I2C_TFNF_RST            0x0
#define I2C_ACTIVITY_RST        0x0

__INLINE void i2c_status_unpack(uint8_t* slvactivity, uint8_t* mstactivity, uint8_t* rff, uint8_t* rfne, uint8_t* tfe, uint8_t* tfnf, uint8_t* activity)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    *slvactivity = (localVal & ((uint32_t)0x00000040)) >> 6;
    *mstactivity = (localVal & ((uint32_t)0x00000020)) >> 5;
    *rff = (localVal & ((uint32_t)0x00000010)) >> 4;
    *rfne = (localVal & ((uint32_t)0x00000008)) >> 3;
    *tfe = (localVal & ((uint32_t)0x00000004)) >> 2;
    *tfnf = (localVal & ((uint32_t)0x00000002)) >> 1;
    *activity = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_slv_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t i2c_mst_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t i2c_rff_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_rfne_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t i2c_tfe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t i2c_tfnf_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t i2c_activity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXFLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00                TXFLR   0x0
 * </pre>
 */
#define I2C_TXFLR_ADDR   0xC0011C74
#define I2C_TXFLR_OFFSET 0x00000074
#define I2C_TXFLR_INDEX  0x0000001D
#define I2C_TXFLR_RESET  0x00000000

__INLINE uint32_t i2c_txflr_get(void)
{
    return REG_PL_RD(I2C_TXFLR_ADDR);
}

// field definitions
#define I2C_TXFLR_MASK   ((uint32_t)0x0000FFFF)
#define I2C_TXFLR_LSB    0
#define I2C_TXFLR_WIDTH  ((uint32_t)0x00000010)

#define I2C_TXFLR_RST    0x0

__INLINE uint16_t i2c_txflr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TXFLR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief RXFLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00                RXFLR   0x0
 * </pre>
 */
#define I2C_RXFLR_ADDR   0xC0011C78
#define I2C_RXFLR_OFFSET 0x00000078
#define I2C_RXFLR_INDEX  0x0000001E
#define I2C_RXFLR_RESET  0x00000000

__INLINE uint32_t i2c_rxflr_get(void)
{
    return REG_PL_RD(I2C_RXFLR_ADDR);
}

// field definitions
#define I2C_RXFLR_MASK   ((uint32_t)0x0000FFFF)
#define I2C_RXFLR_LSB    0
#define I2C_RXFLR_WIDTH  ((uint32_t)0x00000010)

#define I2C_RXFLR_RST    0x0

__INLINE uint16_t i2c_rxflr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_RXFLR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief TX_ABRT_SOURCE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     15      ABRT_SLVRD_INTX   0
 *     14     ABRT_SLV_ARBLOST   0
 *     13   ABRT_SLVFLUSH_TXFIFO   0
 *     12             ARB_LOST   0
 *     11      ABRT_MASTER_DIS   0
 *     10   ABRT_10B_RD_NORSTRT   0
 *     09   ABRT_SBYTE_NORSTRT   0
 *     08      ABRT_HS_NORSTRT   0
 *     07    ABRT_SBYTE_ACKDET   0
 *     06       ABRT_HS_ACKDET   0
 *     05      ABRT_GCALL_READ   0
 *     04     ABRT_GCALL_NOACK   0
 *     03    ABRT_TXDATA_NOACK   0
 *     02   ABRT_10ADDR2_NOACK   0
 *     01   ABRT_10ADDR1_NOACK   0
 *     00   ABRT_7B_ADDR_NOACK   0
 * </pre>
 */
#define I2C_TX_ABRT_SOURCE_ADDR   0xC0011C80
#define I2C_TX_ABRT_SOURCE_OFFSET 0x00000080
#define I2C_TX_ABRT_SOURCE_INDEX  0x00000020
#define I2C_TX_ABRT_SOURCE_RESET  0x00000000

__INLINE uint32_t i2c_tx_abrt_source_get(void)
{
    return REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
}

// field definitions
#define I2C_ABRT_SLVRD_INTX_BIT         ((uint32_t)0x00008000)
#define I2C_ABRT_SLVRD_INTX_POS         15
#define I2C_ABRT_SLV_ARBLOST_BIT        ((uint32_t)0x00004000)
#define I2C_ABRT_SLV_ARBLOST_POS        14
#define I2C_ABRT_SLVFLUSH_TXFIFO_BIT    ((uint32_t)0x00002000)
#define I2C_ABRT_SLVFLUSH_TXFIFO_POS    13
#define I2C_ARB_LOST_BIT                ((uint32_t)0x00001000)
#define I2C_ARB_LOST_POS                12
#define I2C_ABRT_MASTER_DIS_BIT         ((uint32_t)0x00000800)
#define I2C_ABRT_MASTER_DIS_POS         11
#define I2C_ABRT_10B_RD_NORSTRT_BIT     ((uint32_t)0x00000400)
#define I2C_ABRT_10B_RD_NORSTRT_POS     10
#define I2C_ABRT_SBYTE_NORSTRT_BIT      ((uint32_t)0x00000200)
#define I2C_ABRT_SBYTE_NORSTRT_POS      9
#define I2C_ABRT_HS_NORSTRT_BIT         ((uint32_t)0x00000100)
#define I2C_ABRT_HS_NORSTRT_POS         8
#define I2C_ABRT_SBYTE_ACKDET_BIT       ((uint32_t)0x00000080)
#define I2C_ABRT_SBYTE_ACKDET_POS       7
#define I2C_ABRT_HS_ACKDET_BIT          ((uint32_t)0x00000040)
#define I2C_ABRT_HS_ACKDET_POS          6
#define I2C_ABRT_GCALL_READ_BIT         ((uint32_t)0x00000020)
#define I2C_ABRT_GCALL_READ_POS         5
#define I2C_ABRT_GCALL_NOACK_BIT        ((uint32_t)0x00000010)
#define I2C_ABRT_GCALL_NOACK_POS        4
#define I2C_ABRT_TXDATA_NOACK_BIT       ((uint32_t)0x00000008)
#define I2C_ABRT_TXDATA_NOACK_POS       3
#define I2C_ABRT_10ADDR2_NOACK_BIT      ((uint32_t)0x00000004)
#define I2C_ABRT_10ADDR2_NOACK_POS      2
#define I2C_ABRT_10ADDR1_NOACK_BIT      ((uint32_t)0x00000002)
#define I2C_ABRT_10ADDR1_NOACK_POS      1
#define I2C_ABRT_7B_ADDR_NOACK_BIT      ((uint32_t)0x00000001)
#define I2C_ABRT_7B_ADDR_NOACK_POS      0

#define I2C_ABRT_SLVRD_INTX_RST         0x0
#define I2C_ABRT_SLV_ARBLOST_RST        0x0
#define I2C_ABRT_SLVFLUSH_TXFIFO_RST    0x0
#define I2C_ARB_LOST_RST                0x0
#define I2C_ABRT_MASTER_DIS_RST         0x0
#define I2C_ABRT_10B_RD_NORSTRT_RST     0x0
#define I2C_ABRT_SBYTE_NORSTRT_RST      0x0
#define I2C_ABRT_HS_NORSTRT_RST         0x0
#define I2C_ABRT_SBYTE_ACKDET_RST       0x0
#define I2C_ABRT_HS_ACKDET_RST          0x0
#define I2C_ABRT_GCALL_READ_RST         0x0
#define I2C_ABRT_GCALL_NOACK_RST        0x0
#define I2C_ABRT_TXDATA_NOACK_RST       0x0
#define I2C_ABRT_10ADDR2_NOACK_RST      0x0
#define I2C_ABRT_10ADDR1_NOACK_RST      0x0
#define I2C_ABRT_7B_ADDR_NOACK_RST      0x0

__INLINE void i2c_tx_abrt_source_unpack(uint8_t* abrtslvrdintx, uint8_t* abrtslvarblost, uint8_t* abrtslvflushtxfifo, uint8_t* arblost, uint8_t* abrtmasterdis, uint8_t* abrt10brdnorstrt, uint8_t* abrtsbytenorstrt, uint8_t* abrthsnorstrt, uint8_t* abrtsbyteackdet, uint8_t* abrthsackdet, uint8_t* abrtgcallread, uint8_t* abrtgcallnoack, uint8_t* abrttxdatanoack, uint8_t* abrt10addr2noack, uint8_t* abrt10addr1noack, uint8_t* abrt7baddrnoack)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    *abrtslvrdintx = (localVal & ((uint32_t)0x00008000)) >> 15;
    *abrtslvarblost = (localVal & ((uint32_t)0x00004000)) >> 14;
    *abrtslvflushtxfifo = (localVal & ((uint32_t)0x00002000)) >> 13;
    *arblost = (localVal & ((uint32_t)0x00001000)) >> 12;
    *abrtmasterdis = (localVal & ((uint32_t)0x00000800)) >> 11;
    *abrt10brdnorstrt = (localVal & ((uint32_t)0x00000400)) >> 10;
    *abrtsbytenorstrt = (localVal & ((uint32_t)0x00000200)) >> 9;
    *abrthsnorstrt = (localVal & ((uint32_t)0x00000100)) >> 8;
    *abrtsbyteackdet = (localVal & ((uint32_t)0x00000080)) >> 7;
    *abrthsackdet = (localVal & ((uint32_t)0x00000040)) >> 6;
    *abrtgcallread = (localVal & ((uint32_t)0x00000020)) >> 5;
    *abrtgcallnoack = (localVal & ((uint32_t)0x00000010)) >> 4;
    *abrttxdatanoack = (localVal & ((uint32_t)0x00000008)) >> 3;
    *abrt10addr2noack = (localVal & ((uint32_t)0x00000004)) >> 2;
    *abrt10addr1noack = (localVal & ((uint32_t)0x00000002)) >> 1;
    *abrt7baddrnoack = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_abrt_slvrd_intx_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE uint8_t i2c_abrt_slv_arblost_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE uint8_t i2c_abrt_slvflush_txfifo_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE uint8_t i2c_arb_lost_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE uint8_t i2c_abrt_master_dis_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t i2c_abrt_10b_rd_norstrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t i2c_abrt_sbyte_norstrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t i2c_abrt_hs_norstrt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t i2c_abrt_sbyte_ackdet_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t i2c_abrt_hs_ackdet_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t i2c_abrt_gcall_read_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t i2c_abrt_gcall_noack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_abrt_txdata_noack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t i2c_abrt_10addr2_noack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t i2c_abrt_10addr1_noack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t i2c_abrt_7b_addr_noack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_TX_ABRT_SOURCE_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief SLV_DATA_NACK_ONLY register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00                 NACK   0
 * </pre>
 */
#define I2C_SLV_DATA_NACK_ONLY_ADDR   0xC0011C84
#define I2C_SLV_DATA_NACK_ONLY_OFFSET 0x00000084
#define I2C_SLV_DATA_NACK_ONLY_INDEX  0x00000021
#define I2C_SLV_DATA_NACK_ONLY_RESET  0x00000000

__INLINE uint32_t i2c_slv_data_nack_only_get(void)
{
    return REG_PL_RD(I2C_SLV_DATA_NACK_ONLY_ADDR);
}

__INLINE void i2c_slv_data_nack_only_set(uint32_t value)
{
    REG_PL_WR(I2C_SLV_DATA_NACK_ONLY_ADDR, value);
}

// field definitions
#define I2C_NACK_BIT    ((uint32_t)0x00000001)
#define I2C_NACK_POS    0

#define I2C_NACK_RST    0x0

__INLINE uint8_t i2c_nack_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_SLV_DATA_NACK_ONLY_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_nack_setf(uint8_t nack)
{
    ASSERT_ERR((((uint32_t)nack << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_SLV_DATA_NACK_ONLY_ADDR, (uint32_t)nack << 0);
}

/**
 * @brief DMA_CR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01                TDMAE   0
 *     00                RDMAE   0
 * </pre>
 */
#define I2C_DMA_CR_ADDR   0xC0011C88
#define I2C_DMA_CR_OFFSET 0x00000088
#define I2C_DMA_CR_INDEX  0x00000022
#define I2C_DMA_CR_RESET  0x00000000

__INLINE uint32_t i2c_dma_cr_get(void)
{
    return REG_PL_RD(I2C_DMA_CR_ADDR);
}

__INLINE void i2c_dma_cr_set(uint32_t value)
{
    REG_PL_WR(I2C_DMA_CR_ADDR, value);
}

// field definitions
#define I2C_TDMAE_BIT    ((uint32_t)0x00000002)
#define I2C_TDMAE_POS    1
#define I2C_RDMAE_BIT    ((uint32_t)0x00000001)
#define I2C_RDMAE_POS    0

#define I2C_TDMAE_RST    0x0
#define I2C_RDMAE_RST    0x0

__INLINE void i2c_dma_cr_pack(uint8_t tdmae, uint8_t rdmae)
{
    ASSERT_ERR((((uint32_t)tdmae << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)rdmae << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_DMA_CR_ADDR,  ((uint32_t)tdmae << 1) | ((uint32_t)rdmae << 0));
}

__INLINE void i2c_dma_cr_unpack(uint8_t* tdmae, uint8_t* rdmae)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DMA_CR_ADDR);
    *tdmae = (localVal & ((uint32_t)0x00000002)) >> 1;
    *rdmae = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_tdmae_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DMA_CR_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void i2c_tdmae_setf(uint8_t tdmae)
{
    ASSERT_ERR((((uint32_t)tdmae << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(I2C_DMA_CR_ADDR, (REG_PL_RD(I2C_DMA_CR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)tdmae << 1));
}

__INLINE uint8_t i2c_rdmae_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DMA_CR_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void i2c_rdmae_setf(uint8_t rdmae)
{
    ASSERT_ERR((((uint32_t)rdmae << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_DMA_CR_ADDR, (REG_PL_RD(I2C_DMA_CR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rdmae << 0));
}

/**
 * @brief DMA_TDLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00               DMATDL   0x0
 * </pre>
 */
#define I2C_DMA_TDLR_ADDR   0xC0011C8C
#define I2C_DMA_TDLR_OFFSET 0x0000008C
#define I2C_DMA_TDLR_INDEX  0x00000023
#define I2C_DMA_TDLR_RESET  0x00000000

__INLINE uint32_t i2c_dma_tdlr_get(void)
{
    return REG_PL_RD(I2C_DMA_TDLR_ADDR);
}

__INLINE void i2c_dma_tdlr_set(uint32_t value)
{
    REG_PL_WR(I2C_DMA_TDLR_ADDR, value);
}

// field definitions
#define I2C_DMATDL_MASK   ((uint32_t)0x0000FFFF)
#define I2C_DMATDL_LSB    0
#define I2C_DMATDL_WIDTH  ((uint32_t)0x00000010)

#define I2C_DMATDL_RST    0x0

__INLINE uint16_t i2c_dmatdl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DMA_TDLR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_dmatdl_setf(uint16_t dmatdl)
{
    ASSERT_ERR((((uint32_t)dmatdl << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_DMA_TDLR_ADDR, (uint32_t)dmatdl << 0);
}

/**
 * @brief DMA_RDLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00               DMARDL   0x0
 * </pre>
 */
#define I2C_DMA_RDLR_ADDR   0xC0011C90
#define I2C_DMA_RDLR_OFFSET 0x00000090
#define I2C_DMA_RDLR_INDEX  0x00000024
#define I2C_DMA_RDLR_RESET  0x00000000

__INLINE uint32_t i2c_dma_rdlr_get(void)
{
    return REG_PL_RD(I2C_DMA_RDLR_ADDR);
}

__INLINE void i2c_dma_rdlr_set(uint32_t value)
{
    REG_PL_WR(I2C_DMA_RDLR_ADDR, value);
}

// field definitions
#define I2C_DMARDL_MASK   ((uint32_t)0x0000FFFF)
#define I2C_DMARDL_LSB    0
#define I2C_DMARDL_WIDTH  ((uint32_t)0x00000010)

#define I2C_DMARDL_RST    0x0

__INLINE uint16_t i2c_dmardl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_DMA_RDLR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_dmardl_setf(uint16_t dmardl)
{
    ASSERT_ERR((((uint32_t)dmardl << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(I2C_DMA_RDLR_ADDR, (uint32_t)dmardl << 0);
}

/**
 * @brief SDA_SETUP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00            SDA_SETUP   0x0
 * </pre>
 */
#define I2C_SDA_SETUP_ADDR   0xC0011C94
#define I2C_SDA_SETUP_OFFSET 0x00000094
#define I2C_SDA_SETUP_INDEX  0x00000025
#define I2C_SDA_SETUP_RESET  0x00000000

__INLINE uint32_t i2c_sda_setup_get(void)
{
    return REG_PL_RD(I2C_SDA_SETUP_ADDR);
}

__INLINE void i2c_sda_setup_set(uint32_t value)
{
    REG_PL_WR(I2C_SDA_SETUP_ADDR, value);
}

// field definitions
#define I2C_SDA_SETUP_MASK   ((uint32_t)0x000000FF)
#define I2C_SDA_SETUP_LSB    0
#define I2C_SDA_SETUP_WIDTH  ((uint32_t)0x00000008)

#define I2C_SDA_SETUP_RST    0x0

__INLINE uint8_t i2c_sda_setup_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_SDA_SETUP_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_sda_setup_setf(uint8_t sdasetup)
{
    ASSERT_ERR((((uint32_t)sdasetup << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(I2C_SDA_SETUP_ADDR, (uint32_t)sdasetup << 0);
}

/**
 * @brief ACK_GENERAL_CALL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00         ACK_GEN_CALL   0
 * </pre>
 */
#define I2C_ACK_GENERAL_CALL_ADDR   0xC0011C98
#define I2C_ACK_GENERAL_CALL_OFFSET 0x00000098
#define I2C_ACK_GENERAL_CALL_INDEX  0x00000026
#define I2C_ACK_GENERAL_CALL_RESET  0x00000000

__INLINE uint32_t i2c_ack_general_call_get(void)
{
    return REG_PL_RD(I2C_ACK_GENERAL_CALL_ADDR);
}

__INLINE void i2c_ack_general_call_set(uint32_t value)
{
    REG_PL_WR(I2C_ACK_GENERAL_CALL_ADDR, value);
}

// field definitions
#define I2C_ACK_GEN_CALL_BIT    ((uint32_t)0x00000001)
#define I2C_ACK_GEN_CALL_POS    0

#define I2C_ACK_GEN_CALL_RST    0x0

__INLINE uint8_t i2c_ack_gen_call_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ACK_GENERAL_CALL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void i2c_ack_gen_call_setf(uint8_t ackgencall)
{
    ASSERT_ERR((((uint32_t)ackgencall << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(I2C_ACK_GENERAL_CALL_ADDR, (uint32_t)ackgencall << 0);
}

/**
 * @brief ENABLE_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02   SLV_FIFO_FILLED_AND_FLUSHED   0
 *     01       SLV_RX_ABORTED   0
 *     00                   EN   0
 * </pre>
 */
#define I2C_ENABLE_STATUS_ADDR   0xC0011C9C
#define I2C_ENABLE_STATUS_OFFSET 0x0000009C
#define I2C_ENABLE_STATUS_INDEX  0x00000027
#define I2C_ENABLE_STATUS_RESET  0x00000000

__INLINE uint32_t i2c_enable_status_get(void)
{
    return REG_PL_RD(I2C_ENABLE_STATUS_ADDR);
}

// field definitions
#define I2C_SLV_FIFO_FILLED_AND_FLUSHED_BIT    ((uint32_t)0x00000004)
#define I2C_SLV_FIFO_FILLED_AND_FLUSHED_POS    2
#define I2C_SLV_RX_ABORTED_BIT                 ((uint32_t)0x00000002)
#define I2C_SLV_RX_ABORTED_POS                 1
#define I2C_EN_BIT                             ((uint32_t)0x00000001)
#define I2C_EN_POS                             0

#define I2C_SLV_FIFO_FILLED_AND_FLUSHED_RST    0x0
#define I2C_SLV_RX_ABORTED_RST                 0x0
#define I2C_EN_RST                             0x0

__INLINE void i2c_enable_status_unpack(uint8_t* slvfifofilledandflushed, uint8_t* slvrxaborted, uint8_t* en)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ENABLE_STATUS_ADDR);
    *slvfifofilledandflushed = (localVal & ((uint32_t)0x00000004)) >> 2;
    *slvrxaborted = (localVal & ((uint32_t)0x00000002)) >> 1;
    *en = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t i2c_slv_fifo_filled_and_flushed_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ENABLE_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t i2c_slv_rx_aborted_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ENABLE_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t i2c_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_ENABLE_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief COMP_PARAM_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:16      TX_BUFFER_DEPTH   0x0
 *  15:08      RX_BUFFER_DEPTH   0x0
 *     07   ADD_ENCODED_PARAMS   0
 *     06              HAS_DMA   0
 *     05              INTR_IO   0
 *     04      HC_COUNT_VALUES   0
 *  03:02       MAX_SPEED_MODE   0x0
 *  01:00       APB_DATA_WIDTH   0x0
 * </pre>
 */
#define I2C_COMP_PARAM_1_ADDR   0xC0011CF4
#define I2C_COMP_PARAM_1_OFFSET 0x000000F4
#define I2C_COMP_PARAM_1_INDEX  0x0000003D
#define I2C_COMP_PARAM_1_RESET  0x00000000

__INLINE uint32_t i2c_comp_param_1_get(void)
{
    return REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
}

// field definitions
#define I2C_TX_BUFFER_DEPTH_MASK      ((uint32_t)0x00FF0000)
#define I2C_TX_BUFFER_DEPTH_LSB       16
#define I2C_TX_BUFFER_DEPTH_WIDTH     ((uint32_t)0x00000008)
#define I2C_RX_BUFFER_DEPTH_MASK      ((uint32_t)0x0000FF00)
#define I2C_RX_BUFFER_DEPTH_LSB       8
#define I2C_RX_BUFFER_DEPTH_WIDTH     ((uint32_t)0x00000008)
#define I2C_ADD_ENCODED_PARAMS_BIT    ((uint32_t)0x00000080)
#define I2C_ADD_ENCODED_PARAMS_POS    7
#define I2C_HAS_DMA_BIT               ((uint32_t)0x00000040)
#define I2C_HAS_DMA_POS               6
#define I2C_INTR_IO_BIT               ((uint32_t)0x00000020)
#define I2C_INTR_IO_POS               5
#define I2C_HC_COUNT_VALUES_BIT       ((uint32_t)0x00000010)
#define I2C_HC_COUNT_VALUES_POS       4
#define I2C_MAX_SPEED_MODE_MASK       ((uint32_t)0x0000000C)
#define I2C_MAX_SPEED_MODE_LSB        2
#define I2C_MAX_SPEED_MODE_WIDTH      ((uint32_t)0x00000002)
#define I2C_APB_DATA_WIDTH_MASK       ((uint32_t)0x00000003)
#define I2C_APB_DATA_WIDTH_LSB        0
#define I2C_APB_DATA_WIDTH_WIDTH      ((uint32_t)0x00000002)

#define I2C_TX_BUFFER_DEPTH_RST       0x0
#define I2C_RX_BUFFER_DEPTH_RST       0x0
#define I2C_ADD_ENCODED_PARAMS_RST    0x0
#define I2C_HAS_DMA_RST               0x0
#define I2C_INTR_IO_RST               0x0
#define I2C_HC_COUNT_VALUES_RST       0x0
#define I2C_MAX_SPEED_MODE_RST        0x0
#define I2C_APB_DATA_WIDTH_RST        0x0

__INLINE void i2c_comp_param_1_unpack(uint8_t* txbufferdepth, uint8_t* rxbufferdepth, uint8_t* addencodedparams, uint8_t* hasdma, uint8_t* intrio, uint8_t* hccountvalues, uint8_t* maxspeedmode, uint8_t* apbdatawidth)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    *txbufferdepth = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *rxbufferdepth = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *addencodedparams = (localVal & ((uint32_t)0x00000080)) >> 7;
    *hasdma = (localVal & ((uint32_t)0x00000040)) >> 6;
    *intrio = (localVal & ((uint32_t)0x00000020)) >> 5;
    *hccountvalues = (localVal & ((uint32_t)0x00000010)) >> 4;
    *maxspeedmode = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *apbdatawidth = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t i2c_tx_buffer_depth_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

__INLINE uint8_t i2c_rx_buffer_depth_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE uint8_t i2c_add_encoded_params_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t i2c_has_dma_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t i2c_intr_io_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t i2c_hc_count_values_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t i2c_max_speed_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE uint8_t i2c_apb_data_width_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_PARAM_1_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief COMP_VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         COMP_VERSION   0x0
 * </pre>
 */
#define I2C_COMP_VERSION_ADDR   0xC0011CF8
#define I2C_COMP_VERSION_OFFSET 0x000000F8
#define I2C_COMP_VERSION_INDEX  0x0000003E
#define I2C_COMP_VERSION_RESET  0x00000000

__INLINE uint32_t i2c_comp_version_get(void)
{
    return REG_PL_RD(I2C_COMP_VERSION_ADDR);
}

// field definitions
#define I2C_COMP_VERSION_MASK   ((uint32_t)0xFFFFFFFF)
#define I2C_COMP_VERSION_LSB    0
#define I2C_COMP_VERSION_WIDTH  ((uint32_t)0x00000020)

#define I2C_COMP_VERSION_RST    0x0

__INLINE uint32_t i2c_comp_version_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_VERSION_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief COMP_TYPE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00            COMP_TYPE   0x0
 * </pre>
 */
#define I2C_COMP_TYPE_ADDR   0xC0011CFC
#define I2C_COMP_TYPE_OFFSET 0x000000FC
#define I2C_COMP_TYPE_INDEX  0x0000003F
#define I2C_COMP_TYPE_RESET  0x00000000

__INLINE uint32_t i2c_comp_type_get(void)
{
    return REG_PL_RD(I2C_COMP_TYPE_ADDR);
}

// field definitions
#define I2C_COMP_TYPE_MASK   ((uint32_t)0xFFFFFFFF)
#define I2C_COMP_TYPE_LSB    0
#define I2C_COMP_TYPE_WIDTH  ((uint32_t)0x00000020)

#define I2C_COMP_TYPE_RST    0x0

__INLINE uint32_t i2c_comp_type_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(I2C_COMP_TYPE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_I2C_H_

