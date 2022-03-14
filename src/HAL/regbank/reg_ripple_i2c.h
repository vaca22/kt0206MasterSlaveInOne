#ifndef _REG_RIPPLE_I2C_H_
#define _REG_RIPPLE_I2C_H_

#include <stdint.h>
#include "_reg_ripple_i2c.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_RIPPLE_I2C_COUNT 324

#define REG_RIPPLE_I2C_DECODING_MASK 0x000001FF

/**
 * @brief BTDMD_RATE_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02    btmdm_rate_mux_en   1
 *  01:00       btmdm_rate_mux   0x1
 * </pre>
 */
#define RIPL_BTDMD_RATE_CTRL_ADDR   0x00000004
#define RIPL_BTDMD_RATE_CTRL_OFFSET 0x00000004
#define RIPL_BTDMD_RATE_CTRL_INDEX  0x00000004
#define RIPL_BTDMD_RATE_CTRL_RESET  0x00000005

__INLINE uint8_t ripl_btdmd_rate_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR);
}

__INLINE void ripl_btdmd_rate_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BTDMD_RATE_CTRL_ADDR, value);
}

// field definitions
#define RIPL_BTMDM_RATE_MUX_EN_BIT    ((uint8_t)0x00000004)
#define RIPL_BTMDM_RATE_MUX_EN_POS    2
#define RIPL_BTMDM_RATE_MUX_MASK      ((uint8_t)0x00000003)
#define RIPL_BTMDM_RATE_MUX_LSB       0
#define RIPL_BTMDM_RATE_MUX_WIDTH     ((uint8_t)0x00000002)

#define RIPL_BTMDM_RATE_MUX_EN_RST    0x1
#define RIPL_BTMDM_RATE_MUX_RST       0x1

__INLINE void ripl_btdmd_rate_ctrl_pack(uint8_t btmdmratemuxen, uint8_t btmdmratemux)
{
    ASSERT_ERR((((uint8_t)btmdmratemuxen << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)btmdmratemux << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_BTDMD_RATE_CTRL_ADDR,  ((uint8_t)btmdmratemuxen << 2) | ((uint8_t)btmdmratemux << 0));
}

__INLINE void ripl_btdmd_rate_ctrl_unpack(uint8_t* btmdmratemuxen, uint8_t* btmdmratemux)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR);
    *btmdmratemuxen = (localVal & ((uint8_t)0x00000004)) >> 2;
    *btmdmratemux = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_btmdm_rate_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_btmdm_rate_mux_en_setf(uint8_t btmdmratemuxen)
{
    ASSERT_ERR((((uint8_t)btmdmratemuxen << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_BTDMD_RATE_CTRL_ADDR, (REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)btmdmratemuxen << 2));
}

__INLINE uint8_t ripl_btmdm_rate_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_btmdm_rate_mux_setf(uint8_t btmdmratemux)
{
    ASSERT_ERR((((uint8_t)btmdmratemux << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_BTDMD_RATE_CTRL_ADDR, (REG_RIPL_RD(RIPL_BTDMD_RATE_CTRL_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)btmdmratemux << 0));
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07          PD_AUPGA2_L   1
 *  06:04        AUPGA2_GAIN_L   0x1
 *     02             PD_AUPGA   1
 *  01:00        AUPGA1_GAIN_L   0x1
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR   0x00000005
#define RIPL_ANA_AUDIO_INPUT_CTRL1_OFFSET 0x00000005
#define RIPL_ANA_AUDIO_INPUT_CTRL1_INDEX  0x00000005
#define RIPL_ANA_AUDIO_INPUT_CTRL1_RESET  0x00000095

__INLINE uint8_t ripl_ana_audio_input_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_PD_AUPGA2_L_BIT      ((uint8_t)0x00000080)
#define RIPL_PD_AUPGA2_L_POS      7
#define RIPL_AUPGA2_GAIN_L_MASK   ((uint8_t)0x00000070)
#define RIPL_AUPGA2_GAIN_L_LSB    4
#define RIPL_AUPGA2_GAIN_L_WIDTH  ((uint8_t)0x00000003)
#define RIPL_PD_AUPGA_BIT         ((uint8_t)0x00000004)
#define RIPL_PD_AUPGA_POS         2
#define RIPL_AUPGA1_GAIN_L_MASK   ((uint8_t)0x00000003)
#define RIPL_AUPGA1_GAIN_L_LSB    0
#define RIPL_AUPGA1_GAIN_L_WIDTH  ((uint8_t)0x00000002)

#define RIPL_PD_AUPGA2_L_RST      0x1
#define RIPL_AUPGA2_GAIN_L_RST    0x1
#define RIPL_PD_AUPGA_RST         0x1
#define RIPL_AUPGA1_GAIN_L_RST    0x1

__INLINE void ripl_ana_audio_input_ctrl1_pack(uint8_t pdaupga2l, uint8_t aupga2gainl, uint8_t pdaupga, uint8_t aupga1gainl)
{
    ASSERT_ERR((((uint8_t)pdaupga2l << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)aupga2gainl << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)pdaupga << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)aupga1gainl << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR,  ((uint8_t)pdaupga2l << 7) | ((uint8_t)aupga2gainl << 4) | ((uint8_t)pdaupga << 2) | ((uint8_t)aupga1gainl << 0));
}

__INLINE void ripl_ana_audio_input_ctrl1_unpack(uint8_t* pdaupga2l, uint8_t* aupga2gainl, uint8_t* pdaupga, uint8_t* aupga1gainl)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
    *pdaupga2l = (localVal & ((uint8_t)0x00000080)) >> 7;
    *aupga2gainl = (localVal & ((uint8_t)0x00000070)) >> 4;
    *pdaupga = (localVal & ((uint8_t)0x00000004)) >> 2;
    *aupga1gainl = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_pd_aupga2_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_pd_aupga2_l_setf(uint8_t pdaupga2l)
{
    ASSERT_ERR((((uint8_t)pdaupga2l << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)pdaupga2l << 7));
}

__INLINE uint8_t ripl_aupga2_gain_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_aupga2_gain_l_setf(uint8_t aupga2gainl)
{
    ASSERT_ERR((((uint8_t)aupga2gainl << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)aupga2gainl << 4));
}

__INLINE uint8_t ripl_pd_aupga_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_aupga_setf(uint8_t pdaupga)
{
    ASSERT_ERR((((uint8_t)pdaupga << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdaupga << 2));
}

__INLINE uint8_t ripl_aupga1_gain_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_aupga1_gain_l_setf(uint8_t aupga1gainl)
{
    ASSERT_ERR((((uint8_t)aupga1gainl << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL1_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)aupga1gainl << 0));
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03          PD_AUPGA2_R   1
 *     02          PD_AUPGA1_R   1
 *     01        RESET_AUADC_L   0
 *     00           PD_AUADC_L   1
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR   0x00000006
#define RIPL_ANA_AUDIO_INPUT_CTRL2_OFFSET 0x00000006
#define RIPL_ANA_AUDIO_INPUT_CTRL2_INDEX  0x00000006
#define RIPL_ANA_AUDIO_INPUT_CTRL2_RESET  0x0000000D

__INLINE uint8_t ripl_ana_audio_input_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_PD_AUPGA2_R_BIT      ((uint8_t)0x00000008)
#define RIPL_PD_AUPGA2_R_POS      3
#define RIPL_PD_AUPGA1_R_BIT      ((uint8_t)0x00000004)
#define RIPL_PD_AUPGA1_R_POS      2
#define RIPL_RESET_AUADC_L_BIT    ((uint8_t)0x00000002)
#define RIPL_RESET_AUADC_L_POS    1
#define RIPL_PD_AUADC_L_BIT       ((uint8_t)0x00000001)
#define RIPL_PD_AUADC_L_POS       0

#define RIPL_PD_AUPGA2_R_RST      0x1
#define RIPL_PD_AUPGA1_R_RST      0x1
#define RIPL_RESET_AUADC_L_RST    0x0
#define RIPL_PD_AUADC_L_RST       0x1

__INLINE void ripl_ana_audio_input_ctrl2_pack(uint8_t pdaupga2r, uint8_t pdaupga1r, uint8_t resetauadcl, uint8_t pdauadcl)
{
    ASSERT_ERR((((uint8_t)pdaupga2r << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)pdaupga1r << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)resetauadcl << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)pdauadcl << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR,  ((uint8_t)pdaupga2r << 3) | ((uint8_t)pdaupga1r << 2) | ((uint8_t)resetauadcl << 1) | ((uint8_t)pdauadcl << 0));
}

__INLINE void ripl_ana_audio_input_ctrl2_unpack(uint8_t* pdaupga2r, uint8_t* pdaupga1r, uint8_t* resetauadcl, uint8_t* pdauadcl)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
    *pdaupga2r = (localVal & ((uint8_t)0x00000008)) >> 3;
    *pdaupga1r = (localVal & ((uint8_t)0x00000004)) >> 2;
    *resetauadcl = (localVal & ((uint8_t)0x00000002)) >> 1;
    *pdauadcl = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_pd_aupga2_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_pd_aupga2_r_setf(uint8_t pdaupga2r)
{
    ASSERT_ERR((((uint8_t)pdaupga2r << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)pdaupga2r << 3));
}

__INLINE uint8_t ripl_pd_aupga1_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_aupga1_r_setf(uint8_t pdaupga1r)
{
    ASSERT_ERR((((uint8_t)pdaupga1r << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdaupga1r << 2));
}

__INLINE uint8_t ripl_reset_auadc_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_reset_auadc_l_setf(uint8_t resetauadcl)
{
    ASSERT_ERR((((uint8_t)resetauadcl << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)resetauadcl << 1));
}

__INLINE uint8_t ripl_pd_auadc_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_auadc_l_setf(uint8_t pdauadcl)
{
    ASSERT_ERR((((uint8_t)pdauadcl << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdauadcl << 0));
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07        RESET_AUADC_R   1
 *  06:04        AUPGA2_GAIN_R   0x1
 *     02           PD_AUADC_R   1
 *  01:00        AUPGA1_GAIN_R   0x1
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR   0x00000007
#define RIPL_ANA_AUDIO_INPUT_CTRL3_OFFSET 0x00000007
#define RIPL_ANA_AUDIO_INPUT_CTRL3_INDEX  0x00000007
#define RIPL_ANA_AUDIO_INPUT_CTRL3_RESET  0x00000095

__INLINE uint8_t ripl_ana_audio_input_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_RESET_AUADC_R_BIT    ((uint8_t)0x00000080)
#define RIPL_RESET_AUADC_R_POS    7
#define RIPL_AUPGA2_GAIN_R_MASK   ((uint8_t)0x00000070)
#define RIPL_AUPGA2_GAIN_R_LSB    4
#define RIPL_AUPGA2_GAIN_R_WIDTH  ((uint8_t)0x00000003)
#define RIPL_PD_AUADC_R_BIT       ((uint8_t)0x00000004)
#define RIPL_PD_AUADC_R_POS       2
#define RIPL_AUPGA1_GAIN_R_MASK   ((uint8_t)0x00000003)
#define RIPL_AUPGA1_GAIN_R_LSB    0
#define RIPL_AUPGA1_GAIN_R_WIDTH  ((uint8_t)0x00000002)

#define RIPL_RESET_AUADC_R_RST    0x1
#define RIPL_AUPGA2_GAIN_R_RST    0x1
#define RIPL_PD_AUADC_R_RST       0x1
#define RIPL_AUPGA1_GAIN_R_RST    0x1

__INLINE void ripl_ana_audio_input_ctrl3_pack(uint8_t resetauadcr, uint8_t aupga2gainr, uint8_t pdauadcr, uint8_t aupga1gainr)
{
    ASSERT_ERR((((uint8_t)resetauadcr << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)aupga2gainr << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)pdauadcr << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)aupga1gainr << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR,  ((uint8_t)resetauadcr << 7) | ((uint8_t)aupga2gainr << 4) | ((uint8_t)pdauadcr << 2) | ((uint8_t)aupga1gainr << 0));
}

__INLINE void ripl_ana_audio_input_ctrl3_unpack(uint8_t* resetauadcr, uint8_t* aupga2gainr, uint8_t* pdauadcr, uint8_t* aupga1gainr)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
    *resetauadcr = (localVal & ((uint8_t)0x00000080)) >> 7;
    *aupga2gainr = (localVal & ((uint8_t)0x00000070)) >> 4;
    *pdauadcr = (localVal & ((uint8_t)0x00000004)) >> 2;
    *aupga1gainr = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_reset_auadc_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_reset_auadc_r_setf(uint8_t resetauadcr)
{
    ASSERT_ERR((((uint8_t)resetauadcr << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)resetauadcr << 7));
}

__INLINE uint8_t ripl_aupga2_gain_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_aupga2_gain_r_setf(uint8_t aupga2gainr)
{
    ASSERT_ERR((((uint8_t)aupga2gainr << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)aupga2gainr << 4));
}

__INLINE uint8_t ripl_pd_auadc_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_auadc_r_setf(uint8_t pdauadcr)
{
    ASSERT_ERR((((uint8_t)pdauadcr << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdauadcr << 2));
}

__INLINE uint8_t ripl_aupga1_gain_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_aupga1_gain_r_setf(uint8_t aupga1gainr)
{
    ASSERT_ERR((((uint8_t)aupga1gainr << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL3_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)aupga1gainr << 0));
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:00          TUNE_CAP_AU   0x7
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL4_ADDR   0x00000008
#define RIPL_ANA_AUDIO_INPUT_CTRL4_OFFSET 0x00000008
#define RIPL_ANA_AUDIO_INPUT_CTRL4_INDEX  0x00000008
#define RIPL_ANA_AUDIO_INPUT_CTRL4_RESET  0x00000007

__INLINE uint8_t ripl_ana_audio_input_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL4_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_TUNE_CAP_AU_MASK   ((uint8_t)0x0000000F)
#define RIPL_TUNE_CAP_AU_LSB    0
#define RIPL_TUNE_CAP_AU_WIDTH  ((uint8_t)0x00000004)

#define RIPL_TUNE_CAP_AU_RST    0x7

__INLINE uint8_t ripl_tune_cap_au_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000000F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_tune_cap_au_setf(uint8_t tunecapau)
{
    ASSERT_ERR((((uint8_t)tunecapau << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL4_ADDR, (uint8_t)tunecapau << 0);
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        PD_MICBIAS_AU   1
 *     01         PD_AUDIO_LDO   1
 *     00      PD_AUDIODRI_LDO   1
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR   0x00000009
#define RIPL_ANA_AUDIO_INPUT_CTRL5_OFFSET 0x00000009
#define RIPL_ANA_AUDIO_INPUT_CTRL5_INDEX  0x00000009
#define RIPL_ANA_AUDIO_INPUT_CTRL5_RESET  0x00000007

__INLINE uint8_t ripl_ana_audio_input_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR, value);
}

// field definitions
#define RIPL_PD_MICBIAS_AU_BIT      ((uint8_t)0x00000004)
#define RIPL_PD_MICBIAS_AU_POS      2
#define RIPL_PD_AUDIO_LDO_BIT       ((uint8_t)0x00000002)
#define RIPL_PD_AUDIO_LDO_POS       1
#define RIPL_PD_AUDIODRI_LDO_BIT    ((uint8_t)0x00000001)
#define RIPL_PD_AUDIODRI_LDO_POS    0

#define RIPL_PD_MICBIAS_AU_RST      0x1
#define RIPL_PD_AUDIO_LDO_RST       0x1
#define RIPL_PD_AUDIODRI_LDO_RST    0x1

__INLINE void ripl_ana_audio_input_ctrl5_pack(uint8_t pdmicbiasau, uint8_t pdaudioldo, uint8_t pdaudiodrildo)
{
    ASSERT_ERR((((uint8_t)pdmicbiasau << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)pdaudioldo << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)pdaudiodrildo << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR,  ((uint8_t)pdmicbiasau << 2) | ((uint8_t)pdaudioldo << 1) | ((uint8_t)pdaudiodrildo << 0));
}

__INLINE void ripl_ana_audio_input_ctrl5_unpack(uint8_t* pdmicbiasau, uint8_t* pdaudioldo, uint8_t* pdaudiodrildo)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR);
    *pdmicbiasau = (localVal & ((uint8_t)0x00000004)) >> 2;
    *pdaudioldo = (localVal & ((uint8_t)0x00000002)) >> 1;
    *pdaudiodrildo = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_pd_micbias_au_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_micbias_au_setf(uint8_t pdmicbiasau)
{
    ASSERT_ERR((((uint8_t)pdmicbiasau << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdmicbiasau << 2));
}

__INLINE uint8_t ripl_pd_audio_ldo_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_pd_audio_ldo_setf(uint8_t pdaudioldo)
{
    ASSERT_ERR((((uint8_t)pdaudioldo << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)pdaudioldo << 1));
}

__INLINE uint8_t ripl_pd_audiodri_ldo_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_audiodri_ldo_setf(uint8_t pdaudiodrildo)
{
    ASSERT_ERR((((uint8_t)pdaudiodrildo << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL5_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdaudiodrildo << 0));
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04             ADCOUT_R   0x3
 *  02:00             ADCOUT_L   0x3
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL6_ADDR   0x0000000A
#define RIPL_ANA_AUDIO_INPUT_CTRL6_OFFSET 0x0000000A
#define RIPL_ANA_AUDIO_INPUT_CTRL6_INDEX  0x0000000A
#define RIPL_ANA_AUDIO_INPUT_CTRL6_RESET  0x00000033

__INLINE uint8_t ripl_ana_audio_input_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL6_ADDR);
}

// field definitions
#define RIPL_ADCOUT_R_MASK   ((uint8_t)0x00000070)
#define RIPL_ADCOUT_R_LSB    4
#define RIPL_ADCOUT_R_WIDTH  ((uint8_t)0x00000003)
#define RIPL_ADCOUT_L_MASK   ((uint8_t)0x00000007)
#define RIPL_ADCOUT_L_LSB    0
#define RIPL_ADCOUT_L_WIDTH  ((uint8_t)0x00000003)

#define RIPL_ADCOUT_R_RST    0x3
#define RIPL_ADCOUT_L_RST    0x3

__INLINE void ripl_ana_audio_input_ctrl6_unpack(uint8_t* adcoutr, uint8_t* adcoutl)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL6_ADDR);
    *adcoutr = (localVal & ((uint8_t)0x00000070)) >> 4;
    *adcoutl = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_adcout_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE uint8_t ripl_adcout_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

/**
 * @brief ANA_AUDIO_INPUT_CTRL7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04        OFFSET_PGA2_R   0x0
 *  02:00        OFFSET_PGA2_L   0x0
 * </pre>
 */
#define RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR   0x0000000B
#define RIPL_ANA_AUDIO_INPUT_CTRL7_OFFSET 0x0000000B
#define RIPL_ANA_AUDIO_INPUT_CTRL7_INDEX  0x0000000B
#define RIPL_ANA_AUDIO_INPUT_CTRL7_RESET  0x00000000

__INLINE uint8_t ripl_ana_audio_input_ctrl7_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR);
}

__INLINE void ripl_ana_audio_input_ctrl7_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR, value);
}

// field definitions
#define RIPL_OFFSET_PGA2_R_MASK   ((uint8_t)0x00000070)
#define RIPL_OFFSET_PGA2_R_LSB    4
#define RIPL_OFFSET_PGA2_R_WIDTH  ((uint8_t)0x00000003)
#define RIPL_OFFSET_PGA2_L_MASK   ((uint8_t)0x00000007)
#define RIPL_OFFSET_PGA2_L_LSB    0
#define RIPL_OFFSET_PGA2_L_WIDTH  ((uint8_t)0x00000003)

#define RIPL_OFFSET_PGA2_R_RST    0x0
#define RIPL_OFFSET_PGA2_L_RST    0x0

__INLINE void ripl_ana_audio_input_ctrl7_pack(uint8_t offsetpga2r, uint8_t offsetpga2l)
{
    ASSERT_ERR((((uint8_t)offsetpga2r << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)offsetpga2l << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR,  ((uint8_t)offsetpga2r << 4) | ((uint8_t)offsetpga2l << 0));
}

__INLINE void ripl_ana_audio_input_ctrl7_unpack(uint8_t* offsetpga2r, uint8_t* offsetpga2l)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR);
    *offsetpga2r = (localVal & ((uint8_t)0x00000070)) >> 4;
    *offsetpga2l = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_offset_pga2_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_offset_pga2_r_setf(uint8_t offsetpga2r)
{
    ASSERT_ERR((((uint8_t)offsetpga2r << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)offsetpga2r << 4));
}

__INLINE uint8_t ripl_offset_pga2_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_offset_pga2_l_setf(uint8_t offsetpga2l)
{
    ASSERT_ERR((((uint8_t)offsetpga2l << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_INPUT_CTRL7_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)offsetpga2l << 0));
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:04                ITRIM   0x0
 *     00              TRIM_EN   0
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR   0x0000000E
#define RIPL_ANA_AUDIO_OUTPUT_CTRL3_OFFSET 0x0000000E
#define RIPL_ANA_AUDIO_OUTPUT_CTRL3_INDEX  0x0000000E
#define RIPL_ANA_AUDIO_OUTPUT_CTRL3_RESET  0x00000000

__INLINE uint8_t ripl_ana_audio_output_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_ITRIM_MASK     ((uint8_t)0x000000F0)
#define RIPL_ITRIM_LSB      4
#define RIPL_ITRIM_WIDTH    ((uint8_t)0x00000004)
#define RIPL_TRIM_EN_BIT    ((uint8_t)0x00000001)
#define RIPL_TRIM_EN_POS    0

#define RIPL_ITRIM_RST      0x0
#define RIPL_TRIM_EN_RST    0x0

__INLINE void ripl_ana_audio_output_ctrl3_pack(uint8_t itrim, uint8_t trimen)
{
    ASSERT_ERR((((uint8_t)itrim << 4) & ~((uint8_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint8_t)trimen << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR,  ((uint8_t)itrim << 4) | ((uint8_t)trimen << 0));
}

__INLINE void ripl_ana_audio_output_ctrl3_unpack(uint8_t* itrim, uint8_t* trimen)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR);
    *itrim = (localVal & ((uint8_t)0x000000F0)) >> 4;
    *trimen = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_itrim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x000000F0)) >> 4);
}

__INLINE void ripl_itrim_setf(uint8_t itrim)
{
    ASSERT_ERR((((uint8_t)itrim << 4) & ~((uint8_t)0x000000F0)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR) & ~((uint8_t)0x000000F0)) | ((uint8_t)itrim << 4));
}

__INLINE uint8_t ripl_trim_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_trim_en_setf(uint8_t trimen)
{
    ASSERT_ERR((((uint8_t)trimen << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL3_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)trimen << 0));
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00             ISET_DRI   0x0
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL4_ADDR   0x0000000F
#define RIPL_ANA_AUDIO_OUTPUT_CTRL4_OFFSET 0x0000000F
#define RIPL_ANA_AUDIO_OUTPUT_CTRL4_INDEX  0x0000000F
#define RIPL_ANA_AUDIO_OUTPUT_CTRL4_RESET  0x00000000

__INLINE uint8_t ripl_ana_audio_output_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL4_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_ISET_DRI_MASK   ((uint8_t)0x00000003)
#define RIPL_ISET_DRI_LSB    0
#define RIPL_ISET_DRI_WIDTH  ((uint8_t)0x00000002)

#define RIPL_ISET_DRI_RST    0x0

__INLINE uint8_t ripl_iset_dri_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_iset_dri_setf(uint8_t isetdri)
{
    ASSERT_ERR((((uint8_t)isetdri << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL4_ADDR, (uint8_t)isetdri << 0);
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:00              CT_TEST   0x0
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL5_ADDR   0x00000010
#define RIPL_ANA_AUDIO_OUTPUT_CTRL5_OFFSET 0x00000010
#define RIPL_ANA_AUDIO_OUTPUT_CTRL5_INDEX  0x00000010
#define RIPL_ANA_AUDIO_OUTPUT_CTRL5_RESET  0x00000000

__INLINE uint8_t ripl_ana_audio_output_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL5_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL5_ADDR, value);
}

// field definitions
#define RIPL_CT_TEST_MASK   ((uint8_t)0x0000000F)
#define RIPL_CT_TEST_LSB    0
#define RIPL_CT_TEST_WIDTH  ((uint8_t)0x00000004)

#define RIPL_CT_TEST_RST    0x0

__INLINE uint8_t ripl_ct_test_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL5_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000000F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_ct_test_setf(uint8_t cttest)
{
    ASSERT_ERR((((uint8_t)cttest << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL5_ADDR, (uint8_t)cttest << 0);
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:04         ANAGAIN_1V_R   0x0
 *  03:00         ANAGAIN_1V_L   0x0
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR   0x00000011
#define RIPL_ANA_AUDIO_OUTPUT_CTRL6_OFFSET 0x00000011
#define RIPL_ANA_AUDIO_OUTPUT_CTRL6_INDEX  0x00000011
#define RIPL_ANA_AUDIO_OUTPUT_CTRL6_RESET  0x00000000

__INLINE uint8_t ripl_ana_audio_output_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl6_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR, value);
}

// field definitions
#define RIPL_ANAGAIN_1V_R_MASK   ((uint8_t)0x000000F0)
#define RIPL_ANAGAIN_1V_R_LSB    4
#define RIPL_ANAGAIN_1V_R_WIDTH  ((uint8_t)0x00000004)
#define RIPL_ANAGAIN_1V_L_MASK   ((uint8_t)0x0000000F)
#define RIPL_ANAGAIN_1V_L_LSB    0
#define RIPL_ANAGAIN_1V_L_WIDTH  ((uint8_t)0x00000004)

#define RIPL_ANAGAIN_1V_R_RST    0x0
#define RIPL_ANAGAIN_1V_L_RST    0x0

__INLINE void ripl_ana_audio_output_ctrl6_pack(uint8_t anagain1vr, uint8_t anagain1vl)
{
    ASSERT_ERR((((uint8_t)anagain1vr << 4) & ~((uint8_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint8_t)anagain1vl << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR,  ((uint8_t)anagain1vr << 4) | ((uint8_t)anagain1vl << 0));
}

__INLINE void ripl_ana_audio_output_ctrl6_unpack(uint8_t* anagain1vr, uint8_t* anagain1vl)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR);
    *anagain1vr = (localVal & ((uint8_t)0x000000F0)) >> 4;
    *anagain1vl = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_anagain_1v_r_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x000000F0)) >> 4);
}

__INLINE void ripl_anagain_1v_r_setf(uint8_t anagain1vr)
{
    ASSERT_ERR((((uint8_t)anagain1vr << 4) & ~((uint8_t)0x000000F0)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR) & ~((uint8_t)0x000000F0)) | ((uint8_t)anagain1vr << 4));
}

__INLINE uint8_t ripl_anagain_1v_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_anagain_1v_l_setf(uint8_t anagain1vl)
{
    ASSERT_ERR((((uint8_t)anagain1vl << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL6_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)anagain1vl << 0));
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05             PD_R_DRI   1
 *     04             PD_R_I2V   1
 *     03             PD_R_DAC   1
 *     02             PD_L_DRI   1
 *     01             PD_L_I2V   1
 *     00             PD_L_DAC   1
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR   0x00000012
#define RIPL_ANA_AUDIO_OUTPUT_CTRL7_OFFSET 0x00000012
#define RIPL_ANA_AUDIO_OUTPUT_CTRL7_INDEX  0x00000012
#define RIPL_ANA_AUDIO_OUTPUT_CTRL7_RESET  0x0000003F

__INLINE uint8_t ripl_ana_audio_output_ctrl7_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl7_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, value);
}

// field definitions
#define RIPL_PD_R_DRI_BIT    ((uint8_t)0x00000020)
#define RIPL_PD_R_DRI_POS    5
#define RIPL_PD_R_I2V_BIT    ((uint8_t)0x00000010)
#define RIPL_PD_R_I2V_POS    4
#define RIPL_PD_R_DAC_BIT    ((uint8_t)0x00000008)
#define RIPL_PD_R_DAC_POS    3
#define RIPL_PD_L_DRI_BIT    ((uint8_t)0x00000004)
#define RIPL_PD_L_DRI_POS    2
#define RIPL_PD_L_I2V_BIT    ((uint8_t)0x00000002)
#define RIPL_PD_L_I2V_POS    1
#define RIPL_PD_L_DAC_BIT    ((uint8_t)0x00000001)
#define RIPL_PD_L_DAC_POS    0

#define RIPL_PD_R_DRI_RST    0x1
#define RIPL_PD_R_I2V_RST    0x1
#define RIPL_PD_R_DAC_RST    0x1
#define RIPL_PD_L_DRI_RST    0x1
#define RIPL_PD_L_I2V_RST    0x1
#define RIPL_PD_L_DAC_RST    0x1

__INLINE void ripl_ana_audio_output_ctrl7_pack(uint8_t pdrdri, uint8_t pdri2v, uint8_t pdrdac, uint8_t pdldri, uint8_t pdli2v, uint8_t pdldac)
{
    ASSERT_ERR((((uint8_t)pdrdri << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)pdri2v << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)pdrdac << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)pdldri << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)pdli2v << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)pdldac << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR,  ((uint8_t)pdrdri << 5) | ((uint8_t)pdri2v << 4) | ((uint8_t)pdrdac << 3) | ((uint8_t)pdldri << 2) | ((uint8_t)pdli2v << 1) | ((uint8_t)pdldac << 0));
}

__INLINE void ripl_ana_audio_output_ctrl7_unpack(uint8_t* pdrdri, uint8_t* pdri2v, uint8_t* pdrdac, uint8_t* pdldri, uint8_t* pdli2v, uint8_t* pdldac)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    *pdrdri = (localVal & ((uint8_t)0x00000020)) >> 5;
    *pdri2v = (localVal & ((uint8_t)0x00000010)) >> 4;
    *pdrdac = (localVal & ((uint8_t)0x00000008)) >> 3;
    *pdldri = (localVal & ((uint8_t)0x00000004)) >> 2;
    *pdli2v = (localVal & ((uint8_t)0x00000002)) >> 1;
    *pdldac = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_pd_r_dri_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_pd_r_dri_setf(uint8_t pdrdri)
{
    ASSERT_ERR((((uint8_t)pdrdri << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)pdrdri << 5));
}

__INLINE uint8_t ripl_pd_r_i2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_pd_r_i2v_setf(uint8_t pdri2v)
{
    ASSERT_ERR((((uint8_t)pdri2v << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)pdri2v << 4));
}

__INLINE uint8_t ripl_pd_r_dac_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_pd_r_dac_setf(uint8_t pdrdac)
{
    ASSERT_ERR((((uint8_t)pdrdac << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)pdrdac << 3));
}

__INLINE uint8_t ripl_pd_l_dri_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_l_dri_setf(uint8_t pdldri)
{
    ASSERT_ERR((((uint8_t)pdldri << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdldri << 2));
}

__INLINE uint8_t ripl_pd_l_i2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_pd_l_i2v_setf(uint8_t pdli2v)
{
    ASSERT_ERR((((uint8_t)pdli2v << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)pdli2v << 1));
}

__INLINE uint8_t ripl_pd_l_dac_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_l_dac_setf(uint8_t pdldac)
{
    ASSERT_ERR((((uint8_t)pdldac << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL7_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdldac << 0));
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL8 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       PD_VCM_AUDIOIN   1
 *     01        SEL_V_MICBIAS   0
 *     00         PD_ADDA_BIAS   1
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR   0x00000013
#define RIPL_ANA_AUDIO_OUTPUT_CTRL8_OFFSET 0x00000013
#define RIPL_ANA_AUDIO_OUTPUT_CTRL8_INDEX  0x00000013
#define RIPL_ANA_AUDIO_OUTPUT_CTRL8_RESET  0x00000005

__INLINE uint8_t ripl_ana_audio_output_ctrl8_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl8_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR, value);
}

// field definitions
#define RIPL_PD_VCM_AUDIOIN_BIT    ((uint8_t)0x00000004)
#define RIPL_PD_VCM_AUDIOIN_POS    2
#define RIPL_SEL_V_MICBIAS_BIT     ((uint8_t)0x00000002)
#define RIPL_SEL_V_MICBIAS_POS     1
#define RIPL_PD_ADDA_BIAS_BIT      ((uint8_t)0x00000001)
#define RIPL_PD_ADDA_BIAS_POS      0

#define RIPL_PD_VCM_AUDIOIN_RST    0x1
#define RIPL_SEL_V_MICBIAS_RST     0x0
#define RIPL_PD_ADDA_BIAS_RST      0x1

__INLINE void ripl_ana_audio_output_ctrl8_pack(uint8_t pdvcmaudioin, uint8_t selvmicbias, uint8_t pdaddabias)
{
    ASSERT_ERR((((uint8_t)pdvcmaudioin << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)selvmicbias << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)pdaddabias << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR,  ((uint8_t)pdvcmaudioin << 2) | ((uint8_t)selvmicbias << 1) | ((uint8_t)pdaddabias << 0));
}

__INLINE void ripl_ana_audio_output_ctrl8_unpack(uint8_t* pdvcmaudioin, uint8_t* selvmicbias, uint8_t* pdaddabias)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR);
    *pdvcmaudioin = (localVal & ((uint8_t)0x00000004)) >> 2;
    *selvmicbias = (localVal & ((uint8_t)0x00000002)) >> 1;
    *pdaddabias = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_pd_vcm_audioin_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_pd_vcm_audioin_setf(uint8_t pdvcmaudioin)
{
    ASSERT_ERR((((uint8_t)pdvcmaudioin << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)pdvcmaudioin << 2));
}

__INLINE uint8_t ripl_sel_v_micbias_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sel_v_micbias_setf(uint8_t selvmicbias)
{
    ASSERT_ERR((((uint8_t)selvmicbias << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)selvmicbias << 1));
}

__INLINE uint8_t ripl_pd_adda_bias_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_adda_bias_setf(uint8_t pdaddabias)
{
    ASSERT_ERR((((uint8_t)pdaddabias << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL8_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdaddabias << 0));
}

/**
 * @brief ANA_AUDIO_OUTPUT_CTRL9 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04           TUNE_AULDO   0x1
 *  02:00       TUNE_AUDRV_LDO   0x1
 * </pre>
 */
#define RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR   0x00000014
#define RIPL_ANA_AUDIO_OUTPUT_CTRL9_OFFSET 0x00000014
#define RIPL_ANA_AUDIO_OUTPUT_CTRL9_INDEX  0x00000014
#define RIPL_ANA_AUDIO_OUTPUT_CTRL9_RESET  0x00000011

__INLINE uint8_t ripl_ana_audio_output_ctrl9_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR);
}

__INLINE void ripl_ana_audio_output_ctrl9_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR, value);
}

// field definitions
#define RIPL_TUNE_AULDO_MASK       ((uint8_t)0x00000070)
#define RIPL_TUNE_AULDO_LSB        4
#define RIPL_TUNE_AULDO_WIDTH      ((uint8_t)0x00000003)
#define RIPL_TUNE_AUDRV_LDO_MASK   ((uint8_t)0x00000007)
#define RIPL_TUNE_AUDRV_LDO_LSB    0
#define RIPL_TUNE_AUDRV_LDO_WIDTH  ((uint8_t)0x00000003)

#define RIPL_TUNE_AULDO_RST        0x1
#define RIPL_TUNE_AUDRV_LDO_RST    0x1

__INLINE void ripl_ana_audio_output_ctrl9_pack(uint8_t tuneauldo, uint8_t tuneaudrvldo)
{
    ASSERT_ERR((((uint8_t)tuneauldo << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)tuneaudrvldo << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR,  ((uint8_t)tuneauldo << 4) | ((uint8_t)tuneaudrvldo << 0));
}

__INLINE void ripl_ana_audio_output_ctrl9_unpack(uint8_t* tuneauldo, uint8_t* tuneaudrvldo)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR);
    *tuneauldo = (localVal & ((uint8_t)0x00000070)) >> 4;
    *tuneaudrvldo = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_tune_auldo_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_tune_auldo_setf(uint8_t tuneauldo)
{
    ASSERT_ERR((((uint8_t)tuneauldo << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)tuneauldo << 4));
}

__INLINE uint8_t ripl_tune_audrv_ldo_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_tune_audrv_ldo_setf(uint8_t tuneaudrvldo)
{
    ASSERT_ERR((((uint8_t)tuneaudrvldo << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR, (REG_RIPL_RD(RIPL_ANA_AUDIO_OUTPUT_CTRL9_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)tuneaudrvldo << 0));
}

/**
 * @brief ANA_CHARGER_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:04             CH_STATE   0x0
 *  03:01       CH_CURRENT_SEL   0x0
 *     00           EN_CHARGER   0
 * </pre>
 */
#define RIPL_ANA_CHARGER_CTRL1_ADDR   0x0000001A
#define RIPL_ANA_CHARGER_CTRL1_OFFSET 0x0000001A
#define RIPL_ANA_CHARGER_CTRL1_INDEX  0x0000001A
#define RIPL_ANA_CHARGER_CTRL1_RESET  0x00000000

__INLINE uint8_t ripl_ana_charger_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR);
}

__INLINE void ripl_ana_charger_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_CH_STATE_MASK         ((uint8_t)0x000000F0)
#define RIPL_CH_STATE_LSB          4
#define RIPL_CH_STATE_WIDTH        ((uint8_t)0x00000004)
#define RIPL_CH_CURRENT_SEL_MASK   ((uint8_t)0x0000000E)
#define RIPL_CH_CURRENT_SEL_LSB    1
#define RIPL_CH_CURRENT_SEL_WIDTH  ((uint8_t)0x00000003)
#define RIPL_EN_CHARGER_BIT        ((uint8_t)0x00000001)
#define RIPL_EN_CHARGER_POS        0

#define RIPL_CH_STATE_RST          0x0
#define RIPL_CH_CURRENT_SEL_RST    0x0
#define RIPL_EN_CHARGER_RST        0x0

__INLINE void ripl_ana_charger_ctrl1_pack(uint8_t chcurrentsel, uint8_t encharger)
{
    ASSERT_ERR((((uint8_t)chcurrentsel << 1) & ~((uint8_t)0x0000000E)) == 0);
    ASSERT_ERR((((uint8_t)encharger << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL1_ADDR,  ((uint8_t)chcurrentsel << 1) | ((uint8_t)encharger << 0));
}

__INLINE void ripl_ana_charger_ctrl1_unpack(uint8_t* chstate, uint8_t* chcurrentsel, uint8_t* encharger)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR);
    *chstate = (localVal & ((uint8_t)0x000000F0)) >> 4;
    *chcurrentsel = (localVal & ((uint8_t)0x0000000E)) >> 1;
    *encharger = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_ch_state_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x000000F0)) >> 4);
}

__INLINE uint8_t ripl_ch_current_sel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x0000000E)) >> 1);
}

__INLINE void ripl_ch_current_sel_setf(uint8_t chcurrentsel)
{
    ASSERT_ERR((((uint8_t)chcurrentsel << 1) & ~((uint8_t)0x0000000E)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR) & ~((uint8_t)0x0000000E)) | ((uint8_t)chcurrentsel << 1));
}

__INLINE uint8_t ripl_en_charger_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_en_charger_setf(uint8_t encharger)
{
    ASSERT_ERR((((uint8_t)encharger << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)encharger << 0));
}

/**
 * @brief ANA_CHARGER_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:05        OSC_100K_FSEL   0x3
 *  04:00            VREF_CTRL   0x10
 * </pre>
 */
#define RIPL_ANA_CHARGER_CTRL2_ADDR   0x0000001B
#define RIPL_ANA_CHARGER_CTRL2_OFFSET 0x0000001B
#define RIPL_ANA_CHARGER_CTRL2_INDEX  0x0000001B
#define RIPL_ANA_CHARGER_CTRL2_RESET  0x00000070

__INLINE uint8_t ripl_ana_charger_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR);
}

__INLINE void ripl_ana_charger_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_OSC_100K_FSEL_MASK   ((uint8_t)0x00000060)
#define RIPL_OSC_100K_FSEL_LSB    5
#define RIPL_OSC_100K_FSEL_WIDTH  ((uint8_t)0x00000002)
#define RIPL_VREF_CTRL_MASK       ((uint8_t)0x0000001F)
#define RIPL_VREF_CTRL_LSB        0
#define RIPL_VREF_CTRL_WIDTH      ((uint8_t)0x00000005)

#define RIPL_OSC_100K_FSEL_RST    0x3
#define RIPL_VREF_CTRL_RST        0x10

__INLINE void ripl_ana_charger_ctrl2_pack(uint8_t osc100kfsel, uint8_t vrefctrl)
{
    ASSERT_ERR((((uint8_t)osc100kfsel << 5) & ~((uint8_t)0x00000060)) == 0);
    ASSERT_ERR((((uint8_t)vrefctrl << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL2_ADDR,  ((uint8_t)osc100kfsel << 5) | ((uint8_t)vrefctrl << 0));
}

__INLINE void ripl_ana_charger_ctrl2_unpack(uint8_t* osc100kfsel, uint8_t* vrefctrl)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR);
    *osc100kfsel = (localVal & ((uint8_t)0x00000060)) >> 5;
    *vrefctrl = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_osc_100k_fsel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000060)) >> 5);
}

__INLINE void ripl_osc_100k_fsel_setf(uint8_t osc100kfsel)
{
    ASSERT_ERR((((uint8_t)osc100kfsel << 5) & ~((uint8_t)0x00000060)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR) & ~((uint8_t)0x00000060)) | ((uint8_t)osc100kfsel << 5));
}

__INLINE uint8_t ripl_vref_ctrl_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_vref_ctrl_setf(uint8_t vrefctrl)
{
    ASSERT_ERR((((uint8_t)vrefctrl << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_ANA_CHARGER_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_CHARGER_CTRL2_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)vrefctrl << 0));
}

/**
 * @brief RSTGEN_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   n_digcore_clkgen_rst_spi_mux   0
 *     06   n_digcore_clkgen_rst   1
 *     05   n_rpll_ld_rst_spi_mux   0
 *     04        n_rpll_ld_rst   0
 *     03   rpll_locnt_rst_spi_mux   0
 *     02     n_rpll_locnt_rst   0
 *     01   sar_adc_rst_spi_mux   0
 *     00        n_sar_adc_rst   0
 * </pre>
 */
#define RIPL_RSTGEN_CTRL1_ADDR   0x00000020
#define RIPL_RSTGEN_CTRL1_OFFSET 0x00000020
#define RIPL_RSTGEN_CTRL1_INDEX  0x00000020
#define RIPL_RSTGEN_CTRL1_RESET  0x00000040

__INLINE uint8_t ripl_rstgen_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
}

__INLINE void ripl_rstgen_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_N_DIGCORE_CLKGEN_RST_SPI_MUX_BIT    ((uint8_t)0x00000080)
#define RIPL_N_DIGCORE_CLKGEN_RST_SPI_MUX_POS    7
#define RIPL_N_DIGCORE_CLKGEN_RST_BIT            ((uint8_t)0x00000040)
#define RIPL_N_DIGCORE_CLKGEN_RST_POS            6
#define RIPL_N_RPLL_LD_RST_SPI_MUX_BIT           ((uint8_t)0x00000020)
#define RIPL_N_RPLL_LD_RST_SPI_MUX_POS           5
#define RIPL_N_RPLL_LD_RST_BIT                   ((uint8_t)0x00000010)
#define RIPL_N_RPLL_LD_RST_POS                   4
#define RIPL_RPLL_LOCNT_RST_SPI_MUX_BIT          ((uint8_t)0x00000008)
#define RIPL_RPLL_LOCNT_RST_SPI_MUX_POS          3
#define RIPL_N_RPLL_LOCNT_RST_BIT                ((uint8_t)0x00000004)
#define RIPL_N_RPLL_LOCNT_RST_POS                2
#define RIPL_SAR_ADC_RST_SPI_MUX_BIT             ((uint8_t)0x00000002)
#define RIPL_SAR_ADC_RST_SPI_MUX_POS             1
#define RIPL_N_SAR_ADC_RST_BIT                   ((uint8_t)0x00000001)
#define RIPL_N_SAR_ADC_RST_POS                   0

#define RIPL_N_DIGCORE_CLKGEN_RST_SPI_MUX_RST    0x0
#define RIPL_N_DIGCORE_CLKGEN_RST_RST            0x1
#define RIPL_N_RPLL_LD_RST_SPI_MUX_RST           0x0
#define RIPL_N_RPLL_LD_RST_RST                   0x0
#define RIPL_RPLL_LOCNT_RST_SPI_MUX_RST          0x0
#define RIPL_N_RPLL_LOCNT_RST_RST                0x0
#define RIPL_SAR_ADC_RST_SPI_MUX_RST             0x0
#define RIPL_N_SAR_ADC_RST_RST                   0x0

__INLINE void ripl_rstgen_ctrl1_pack(uint8_t ndigcoreclkgenrstspimux, uint8_t ndigcoreclkgenrst, uint8_t nrpllldrstspimux, uint8_t nrpllldrst, uint8_t rplllocntrstspimux, uint8_t nrplllocntrst, uint8_t saradcrstspimux, uint8_t nsaradcrst)
{
    ASSERT_ERR((((uint8_t)ndigcoreclkgenrstspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)ndigcoreclkgenrst << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)nrpllldrstspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)nrpllldrst << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)rplllocntrstspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)nrplllocntrst << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)saradcrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)nsaradcrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR,  ((uint8_t)ndigcoreclkgenrstspimux << 7) | ((uint8_t)ndigcoreclkgenrst << 6) | ((uint8_t)nrpllldrstspimux << 5) | ((uint8_t)nrpllldrst << 4) | ((uint8_t)rplllocntrstspimux << 3) | ((uint8_t)nrplllocntrst << 2) | ((uint8_t)saradcrstspimux << 1) | ((uint8_t)nsaradcrst << 0));
}

__INLINE void ripl_rstgen_ctrl1_unpack(uint8_t* ndigcoreclkgenrstspimux, uint8_t* ndigcoreclkgenrst, uint8_t* nrpllldrstspimux, uint8_t* nrpllldrst, uint8_t* rplllocntrstspimux, uint8_t* nrplllocntrst, uint8_t* saradcrstspimux, uint8_t* nsaradcrst)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    *ndigcoreclkgenrstspimux = (localVal & ((uint8_t)0x00000080)) >> 7;
    *ndigcoreclkgenrst = (localVal & ((uint8_t)0x00000040)) >> 6;
    *nrpllldrstspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *nrpllldrst = (localVal & ((uint8_t)0x00000010)) >> 4;
    *rplllocntrstspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *nrplllocntrst = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradcrstspimux = (localVal & ((uint8_t)0x00000002)) >> 1;
    *nsaradcrst = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_n_digcore_clkgen_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_n_digcore_clkgen_rst_spi_mux_setf(uint8_t ndigcoreclkgenrstspimux)
{
    ASSERT_ERR((((uint8_t)ndigcoreclkgenrstspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)ndigcoreclkgenrstspimux << 7));
}

__INLINE uint8_t ripl_n_digcore_clkgen_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_n_digcore_clkgen_rst_setf(uint8_t ndigcoreclkgenrst)
{
    ASSERT_ERR((((uint8_t)ndigcoreclkgenrst << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)ndigcoreclkgenrst << 6));
}

__INLINE uint8_t ripl_n_rpll_ld_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_n_rpll_ld_rst_spi_mux_setf(uint8_t nrpllldrstspimux)
{
    ASSERT_ERR((((uint8_t)nrpllldrstspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)nrpllldrstspimux << 5));
}

__INLINE uint8_t ripl_n_rpll_ld_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_n_rpll_ld_rst_setf(uint8_t nrpllldrst)
{
    ASSERT_ERR((((uint8_t)nrpllldrst << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)nrpllldrst << 4));
}

__INLINE uint8_t ripl_rpll_locnt_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_rpll_locnt_rst_spi_mux_setf(uint8_t rplllocntrstspimux)
{
    ASSERT_ERR((((uint8_t)rplllocntrstspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)rplllocntrstspimux << 3));
}

__INLINE uint8_t ripl_n_rpll_locnt_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_n_rpll_locnt_rst_setf(uint8_t nrplllocntrst)
{
    ASSERT_ERR((((uint8_t)nrplllocntrst << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)nrplllocntrst << 2));
}

__INLINE uint8_t ripl_sar_adc_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sar_adc_rst_spi_mux_setf(uint8_t saradcrstspimux)
{
    ASSERT_ERR((((uint8_t)saradcrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)saradcrstspimux << 1));
}

__INLINE uint8_t ripl_n_sar_adc_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_n_sar_adc_rst_setf(uint8_t nsaradcrst)
{
    ASSERT_ERR((((uint8_t)nsaradcrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)nsaradcrst << 0));
}

/**
 * @brief RSTGEN_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   rpll_rccal_rst_spi_mux   0
 *     06     n_rpll_rccal_rst   0
 *     05   dcoffset_fsm_rst_spi_mux   0
 *     04   n_dcoffset_fsm_rst   0
 *     03   rpll_fsm_rst_spi_mux   0
 *     02       n_rpll_fsm_rst   0
 *     01     dpll_rst_spi_mux   0
 *     00           n_dpll_rst   1
 * </pre>
 */
#define RIPL_RSTGEN_CTRL2_ADDR   0x00000021
#define RIPL_RSTGEN_CTRL2_OFFSET 0x00000021
#define RIPL_RSTGEN_CTRL2_INDEX  0x00000021
#define RIPL_RSTGEN_CTRL2_RESET  0x00000001

__INLINE uint8_t ripl_rstgen_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
}

__INLINE void ripl_rstgen_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_RPLL_RCCAL_RST_SPI_MUX_BIT      ((uint8_t)0x00000080)
#define RIPL_RPLL_RCCAL_RST_SPI_MUX_POS      7
#define RIPL_N_RPLL_RCCAL_RST_BIT            ((uint8_t)0x00000040)
#define RIPL_N_RPLL_RCCAL_RST_POS            6
#define RIPL_DCOFFSET_FSM_RST_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_DCOFFSET_FSM_RST_SPI_MUX_POS    5
#define RIPL_N_DCOFFSET_FSM_RST_BIT          ((uint8_t)0x00000010)
#define RIPL_N_DCOFFSET_FSM_RST_POS          4
#define RIPL_RPLL_FSM_RST_SPI_MUX_BIT        ((uint8_t)0x00000008)
#define RIPL_RPLL_FSM_RST_SPI_MUX_POS        3
#define RIPL_N_RPLL_FSM_RST_BIT              ((uint8_t)0x00000004)
#define RIPL_N_RPLL_FSM_RST_POS              2
#define RIPL_DPLL_RST_SPI_MUX_BIT            ((uint8_t)0x00000002)
#define RIPL_DPLL_RST_SPI_MUX_POS            1
#define RIPL_N_DPLL_RST_BIT                  ((uint8_t)0x00000001)
#define RIPL_N_DPLL_RST_POS                  0

#define RIPL_RPLL_RCCAL_RST_SPI_MUX_RST      0x0
#define RIPL_N_RPLL_RCCAL_RST_RST            0x0
#define RIPL_DCOFFSET_FSM_RST_SPI_MUX_RST    0x0
#define RIPL_N_DCOFFSET_FSM_RST_RST          0x0
#define RIPL_RPLL_FSM_RST_SPI_MUX_RST        0x0
#define RIPL_N_RPLL_FSM_RST_RST              0x0
#define RIPL_DPLL_RST_SPI_MUX_RST            0x0
#define RIPL_N_DPLL_RST_RST                  0x1

__INLINE void ripl_rstgen_ctrl2_pack(uint8_t rpllrccalrstspimux, uint8_t nrpllrccalrst, uint8_t dcoffsetfsmrstspimux, uint8_t ndcoffsetfsmrst, uint8_t rpllfsmrstspimux, uint8_t nrpllfsmrst, uint8_t dpllrstspimux, uint8_t ndpllrst)
{
    ASSERT_ERR((((uint8_t)rpllrccalrstspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)nrpllrccalrst << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)dcoffsetfsmrstspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ndcoffsetfsmrst << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)rpllfsmrstspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)nrpllfsmrst << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)dpllrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)ndpllrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR,  ((uint8_t)rpllrccalrstspimux << 7) | ((uint8_t)nrpllrccalrst << 6) | ((uint8_t)dcoffsetfsmrstspimux << 5) | ((uint8_t)ndcoffsetfsmrst << 4) | ((uint8_t)rpllfsmrstspimux << 3) | ((uint8_t)nrpllfsmrst << 2) | ((uint8_t)dpllrstspimux << 1) | ((uint8_t)ndpllrst << 0));
}

__INLINE void ripl_rstgen_ctrl2_unpack(uint8_t* rpllrccalrstspimux, uint8_t* nrpllrccalrst, uint8_t* dcoffsetfsmrstspimux, uint8_t* ndcoffsetfsmrst, uint8_t* rpllfsmrstspimux, uint8_t* nrpllfsmrst, uint8_t* dpllrstspimux, uint8_t* ndpllrst)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    *rpllrccalrstspimux = (localVal & ((uint8_t)0x00000080)) >> 7;
    *nrpllrccalrst = (localVal & ((uint8_t)0x00000040)) >> 6;
    *dcoffsetfsmrstspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ndcoffsetfsmrst = (localVal & ((uint8_t)0x00000010)) >> 4;
    *rpllfsmrstspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *nrpllfsmrst = (localVal & ((uint8_t)0x00000004)) >> 2;
    *dpllrstspimux = (localVal & ((uint8_t)0x00000002)) >> 1;
    *ndpllrst = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_rpll_rccal_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_rpll_rccal_rst_spi_mux_setf(uint8_t rpllrccalrstspimux)
{
    ASSERT_ERR((((uint8_t)rpllrccalrstspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)rpllrccalrstspimux << 7));
}

__INLINE uint8_t ripl_n_rpll_rccal_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_n_rpll_rccal_rst_setf(uint8_t nrpllrccalrst)
{
    ASSERT_ERR((((uint8_t)nrpllrccalrst << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)nrpllrccalrst << 6));
}

__INLINE uint8_t ripl_dcoffset_fsm_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_dcoffset_fsm_rst_spi_mux_setf(uint8_t dcoffsetfsmrstspimux)
{
    ASSERT_ERR((((uint8_t)dcoffsetfsmrstspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)dcoffsetfsmrstspimux << 5));
}

__INLINE uint8_t ripl_n_dcoffset_fsm_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_n_dcoffset_fsm_rst_setf(uint8_t ndcoffsetfsmrst)
{
    ASSERT_ERR((((uint8_t)ndcoffsetfsmrst << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)ndcoffsetfsmrst << 4));
}

__INLINE uint8_t ripl_rpll_fsm_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_rpll_fsm_rst_spi_mux_setf(uint8_t rpllfsmrstspimux)
{
    ASSERT_ERR((((uint8_t)rpllfsmrstspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)rpllfsmrstspimux << 3));
}

__INLINE uint8_t ripl_n_rpll_fsm_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_n_rpll_fsm_rst_setf(uint8_t nrpllfsmrst)
{
    ASSERT_ERR((((uint8_t)nrpllfsmrst << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)nrpllfsmrst << 2));
}

__INLINE uint8_t ripl_dpll_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_dpll_rst_spi_mux_setf(uint8_t dpllrstspimux)
{
    ASSERT_ERR((((uint8_t)dpllrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)dpllrstspimux << 1));
}

__INLINE uint8_t ripl_n_dpll_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_n_dpll_rst_setf(uint8_t ndpllrst)
{
    ASSERT_ERR((((uint8_t)ndpllrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)ndpllrst << 0));
}

/**
 * @brief RSTGEN_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   spi_sar_adc_lowclk_sel_mux_en   0
 *     04   spi_sar_adc_lowclk_sel_mux   0
 *     03   spi_sar_adc_clk_sel_mux_en   0
 *     02   spi_sar_adc_clk_sel_mux   0
 *     01   filt_rccat_rst_spi_mux   0
 *     00     n_filt_rccal_rst   0
 * </pre>
 */
#define RIPL_RSTGEN_CTRL3_ADDR   0x00000022
#define RIPL_RSTGEN_CTRL3_OFFSET 0x00000022
#define RIPL_RSTGEN_CTRL3_INDEX  0x00000022
#define RIPL_RSTGEN_CTRL3_RESET  0x00000000

__INLINE uint8_t ripl_rstgen_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
}

__INLINE void ripl_rstgen_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_EN_BIT    ((uint8_t)0x00000020)
#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_EN_POS    5
#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_BIT       ((uint8_t)0x00000010)
#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_POS       4
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_EN_BIT       ((uint8_t)0x00000008)
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_EN_POS       3
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_BIT          ((uint8_t)0x00000004)
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_POS          2
#define RIPL_FILT_RCCAT_RST_SPI_MUX_BIT           ((uint8_t)0x00000002)
#define RIPL_FILT_RCCAT_RST_SPI_MUX_POS           1
#define RIPL_N_FILT_RCCAL_RST_BIT                 ((uint8_t)0x00000001)
#define RIPL_N_FILT_RCCAL_RST_POS                 0

#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_EN_RST    0x0
#define RIPL_SPI_SAR_ADC_LOWCLK_SEL_MUX_RST       0x0
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_EN_RST       0x0
#define RIPL_SPI_SAR_ADC_CLK_SEL_MUX_RST          0x0
#define RIPL_FILT_RCCAT_RST_SPI_MUX_RST           0x0
#define RIPL_N_FILT_RCCAL_RST_RST                 0x0

__INLINE void ripl_rstgen_ctrl3_pack(uint8_t spisaradclowclkselmuxen, uint8_t spisaradclowclkselmux, uint8_t spisaradcclkselmuxen, uint8_t spisaradcclkselmux, uint8_t filtrccatrstspimux, uint8_t nfiltrccalrst)
{
    ASSERT_ERR((((uint8_t)spisaradclowclkselmuxen << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)spisaradclowclkselmux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)spisaradcclkselmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)spisaradcclkselmux << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)filtrccatrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)nfiltrccalrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR,  ((uint8_t)spisaradclowclkselmuxen << 5) | ((uint8_t)spisaradclowclkselmux << 4) | ((uint8_t)spisaradcclkselmuxen << 3) | ((uint8_t)spisaradcclkselmux << 2) | ((uint8_t)filtrccatrstspimux << 1) | ((uint8_t)nfiltrccalrst << 0));
}

__INLINE void ripl_rstgen_ctrl3_unpack(uint8_t* spisaradclowclkselmuxen, uint8_t* spisaradclowclkselmux, uint8_t* spisaradcclkselmuxen, uint8_t* spisaradcclkselmux, uint8_t* filtrccatrstspimux, uint8_t* nfiltrccalrst)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    *spisaradclowclkselmuxen = (localVal & ((uint8_t)0x00000020)) >> 5;
    *spisaradclowclkselmux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *spisaradcclkselmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *spisaradcclkselmux = (localVal & ((uint8_t)0x00000004)) >> 2;
    *filtrccatrstspimux = (localVal & ((uint8_t)0x00000002)) >> 1;
    *nfiltrccalrst = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_spi_sar_adc_lowclk_sel_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_spi_sar_adc_lowclk_sel_mux_en_setf(uint8_t spisaradclowclkselmuxen)
{
    ASSERT_ERR((((uint8_t)spisaradclowclkselmuxen << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)spisaradclowclkselmuxen << 5));
}

__INLINE uint8_t ripl_spi_sar_adc_lowclk_sel_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_spi_sar_adc_lowclk_sel_mux_setf(uint8_t spisaradclowclkselmux)
{
    ASSERT_ERR((((uint8_t)spisaradclowclkselmux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)spisaradclowclkselmux << 4));
}

__INLINE uint8_t ripl_spi_sar_adc_clk_sel_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_spi_sar_adc_clk_sel_mux_en_setf(uint8_t spisaradcclkselmuxen)
{
    ASSERT_ERR((((uint8_t)spisaradcclkselmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)spisaradcclkselmuxen << 3));
}

__INLINE uint8_t ripl_spi_sar_adc_clk_sel_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_spi_sar_adc_clk_sel_mux_setf(uint8_t spisaradcclkselmux)
{
    ASSERT_ERR((((uint8_t)spisaradcclkselmux << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)spisaradcclkselmux << 2));
}

__INLINE uint8_t ripl_filt_rccat_rst_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_filt_rccat_rst_spi_mux_setf(uint8_t filtrccatrstspimux)
{
    ASSERT_ERR((((uint8_t)filtrccatrstspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)filtrccatrstspimux << 1));
}

__INLINE uint8_t ripl_n_filt_rccal_rst_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_n_filt_rccal_rst_setf(uint8_t nfiltrccalrst)
{
    ASSERT_ERR((((uint8_t)nfiltrccalrst << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RSTGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RSTGEN_CTRL3_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)nfiltrccalrst << 0));
}

/**
 * @brief RST_EN_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07            Xo_rst_en   0
 *     05      Rfpinmux_rst_en   0
 *     04     Audio_rst_en_12m   1
 *     03     Audio_rst_en_13M   1
 *     02      Dig_core_rst_en   0
 *     01        Apbreg_rst_en   0
 *     00           Apb_rst_en   0
 * </pre>
 */
#define RIPL_RST_EN_CTRL1_ADDR   0x00000023
#define RIPL_RST_EN_CTRL1_OFFSET 0x00000023
#define RIPL_RST_EN_CTRL1_INDEX  0x00000023
#define RIPL_RST_EN_CTRL1_RESET  0x00000018

__INLINE uint8_t ripl_rst_en_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
}

__INLINE void ripl_rst_en_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_XO_RST_EN_BIT            ((uint8_t)0x00000080)
#define RIPL_XO_RST_EN_POS            7
#define RIPL_RFPINMUX_RST_EN_BIT      ((uint8_t)0x00000020)
#define RIPL_RFPINMUX_RST_EN_POS      5
#define RIPL_AUDIO_RST_EN__12M_BIT    ((uint8_t)0x00000010)
#define RIPL_AUDIO_RST_EN__12M_POS    4
#define RIPL_AUDIO_RST_EN__13M_BIT    ((uint8_t)0x00000008)
#define RIPL_AUDIO_RST_EN__13M_POS    3
#define RIPL_DIG_CORE_RST_EN_BIT      ((uint8_t)0x00000004)
#define RIPL_DIG_CORE_RST_EN_POS      2
#define RIPL_APBREG_RST_EN_BIT        ((uint8_t)0x00000002)
#define RIPL_APBREG_RST_EN_POS        1
#define RIPL_APB_RST_EN_BIT           ((uint8_t)0x00000001)
#define RIPL_APB_RST_EN_POS           0

#define RIPL_XO_RST_EN_RST            0x0
#define RIPL_RFPINMUX_RST_EN_RST      0x0
#define RIPL_AUDIO_RST_EN__12M_RST    0x1
#define RIPL_AUDIO_RST_EN__13M_RST    0x1
#define RIPL_DIG_CORE_RST_EN_RST      0x0
#define RIPL_APBREG_RST_EN_RST        0x0
#define RIPL_APB_RST_EN_RST           0x0

__INLINE void ripl_rst_en_ctrl1_pack(uint8_t xorsten, uint8_t rfpinmuxrsten, uint8_t audiorsten12m, uint8_t audiorsten13m, uint8_t digcorersten, uint8_t apbregrsten, uint8_t apbrsten)
{
    ASSERT_ERR((((uint8_t)xorsten << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)rfpinmuxrsten << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)audiorsten12m << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)audiorsten13m << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)digcorersten << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)apbregrsten << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)apbrsten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR,  ((uint8_t)xorsten << 7) | ((uint8_t)rfpinmuxrsten << 5) | ((uint8_t)audiorsten12m << 4) | ((uint8_t)audiorsten13m << 3) | ((uint8_t)digcorersten << 2) | ((uint8_t)apbregrsten << 1) | ((uint8_t)apbrsten << 0));
}

__INLINE void ripl_rst_en_ctrl1_unpack(uint8_t* xorsten, uint8_t* rfpinmuxrsten, uint8_t* audiorsten12m, uint8_t* audiorsten13m, uint8_t* digcorersten, uint8_t* apbregrsten, uint8_t* apbrsten)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    *xorsten = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfpinmuxrsten = (localVal & ((uint8_t)0x00000020)) >> 5;
    *audiorsten12m = (localVal & ((uint8_t)0x00000010)) >> 4;
    *audiorsten13m = (localVal & ((uint8_t)0x00000008)) >> 3;
    *digcorersten = (localVal & ((uint8_t)0x00000004)) >> 2;
    *apbregrsten = (localVal & ((uint8_t)0x00000002)) >> 1;
    *apbrsten = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_xo_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_xo_rst_en_setf(uint8_t xorsten)
{
    ASSERT_ERR((((uint8_t)xorsten << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)xorsten << 7));
}

__INLINE uint8_t ripl_rfpinmux_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_rfpinmux_rst_en_setf(uint8_t rfpinmuxrsten)
{
    ASSERT_ERR((((uint8_t)rfpinmuxrsten << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)rfpinmuxrsten << 5));
}

__INLINE uint8_t ripl_audio_rst_en__12m_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_audio_rst_en__12m_setf(uint8_t audiorsten12m)
{
    ASSERT_ERR((((uint8_t)audiorsten12m << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)audiorsten12m << 4));
}

__INLINE uint8_t ripl_audio_rst_en__13m_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_audio_rst_en__13m_setf(uint8_t audiorsten13m)
{
    ASSERT_ERR((((uint8_t)audiorsten13m << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)audiorsten13m << 3));
}

__INLINE uint8_t ripl_dig_core_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_dig_core_rst_en_setf(uint8_t digcorersten)
{
    ASSERT_ERR((((uint8_t)digcorersten << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)digcorersten << 2));
}

__INLINE uint8_t ripl_apbreg_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_apbreg_rst_en_setf(uint8_t apbregrsten)
{
    ASSERT_ERR((((uint8_t)apbregrsten << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)apbregrsten << 1));
}

__INLINE uint8_t ripl_apb_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_apb_rst_en_setf(uint8_t apbrsten)
{
    ASSERT_ERR((((uint8_t)apbrsten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RST_EN_CTRL1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)apbrsten << 0));
}

/**
 * @brief RST_EN_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00       i2c_reg_rst_en   0
 * </pre>
 */
#define RIPL_RST_EN_CTRL2_ADDR   0x00000024
#define RIPL_RST_EN_CTRL2_OFFSET 0x00000024
#define RIPL_RST_EN_CTRL2_INDEX  0x00000024
#define RIPL_RST_EN_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_rst_en_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RST_EN_CTRL2_ADDR);
}

__INLINE void ripl_rst_en_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RST_EN_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_I_2C_REG_RST_EN_BIT    ((uint8_t)0x00000001)
#define RIPL_I_2C_REG_RST_EN_POS    0

#define RIPL_I_2C_REG_RST_EN_RST    0x0

__INLINE uint8_t ripl_i_2c_reg_rst_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_EN_CTRL2_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_i_2c_reg_rst_en_setf(uint8_t i2cregrsten)
{
    ASSERT_ERR((((uint8_t)i2cregrsten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RST_EN_CTRL2_ADDR, (uint8_t)i2cregrsten << 0);
}

/**
 * @brief ATB_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03            ATB_EN_3V   0
 *  02:00           ATB_SEL_3V   0x0
 * </pre>
 */
#define RIPL_ATB_CTRL_ADDR   0x00000028
#define RIPL_ATB_CTRL_OFFSET 0x00000028
#define RIPL_ATB_CTRL_INDEX  0x00000028
#define RIPL_ATB_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_atb_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_ATB_CTRL_ADDR);
}

__INLINE void ripl_atb_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ATB_CTRL_ADDR, value);
}

// field definitions
#define RIPL_ATB_EN_3V_BIT     ((uint8_t)0x00000008)
#define RIPL_ATB_EN_3V_POS     3
#define RIPL_ATB_SEL_3V_MASK   ((uint8_t)0x00000007)
#define RIPL_ATB_SEL_3V_LSB    0
#define RIPL_ATB_SEL_3V_WIDTH  ((uint8_t)0x00000003)

#define RIPL_ATB_EN_3V_RST     0x0
#define RIPL_ATB_SEL_3V_RST    0x0

__INLINE void ripl_atb_ctrl_pack(uint8_t atben3v, uint8_t atbsel3v)
{
    ASSERT_ERR((((uint8_t)atben3v << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)atbsel3v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ATB_CTRL_ADDR,  ((uint8_t)atben3v << 3) | ((uint8_t)atbsel3v << 0));
}

__INLINE void ripl_atb_ctrl_unpack(uint8_t* atben3v, uint8_t* atbsel3v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ATB_CTRL_ADDR);
    *atben3v = (localVal & ((uint8_t)0x00000008)) >> 3;
    *atbsel3v = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_atb_en_3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ATB_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_atb_en_3v_setf(uint8_t atben3v)
{
    ASSERT_ERR((((uint8_t)atben3v << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_ATB_CTRL_ADDR, (REG_RIPL_RD(RIPL_ATB_CTRL_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)atben3v << 3));
}

__INLINE uint8_t ripl_atb_sel_3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ATB_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_atb_sel_3v_setf(uint8_t atbsel3v)
{
    ASSERT_ERR((((uint8_t)atbsel3v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ATB_CTRL_ADDR, (REG_RIPL_RD(RIPL_ATB_CTRL_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)atbsel3v << 0));
}

/**
 * @brief ANA_LDO_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02          COMPOUT1P5V   0
 * </pre>
 */
#define RIPL_ANA_LDO_CTRL4_ADDR   0x0000002F
#define RIPL_ANA_LDO_CTRL4_OFFSET 0x0000002F
#define RIPL_ANA_LDO_CTRL4_INDEX  0x0000002F
#define RIPL_ANA_LDO_CTRL4_RESET  0x00000000

__INLINE uint8_t ripl_ana_ldo_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_LDO_CTRL4_ADDR);
}

__INLINE void ripl_ana_ldo_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_LDO_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_COMPOUT1P5V_BIT    ((uint8_t)0x00000004)
#define RIPL_COMPOUT1P5V_POS    2

#define RIPL_COMPOUT1P5V_RST    0x0

__INLINE uint8_t ripl_compout1p5v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_LDO_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000004)) == 0);
    return (localVal >> 2);
}

/**
 * @brief ANA_LOW_POWER_POR_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04        DCDC_OSC_TUNE   0x4
 *  03:01        DCDC_KCOMP_EN   0x4
 *     00           PD_POR_BUF   1
 * </pre>
 */
#define RIPL_ANA_LOW_POWER_POR_CTRL_ADDR   0x00000033
#define RIPL_ANA_LOW_POWER_POR_CTRL_OFFSET 0x00000033
#define RIPL_ANA_LOW_POWER_POR_CTRL_INDEX  0x00000033
#define RIPL_ANA_LOW_POWER_POR_CTRL_RESET  0x00000049

__INLINE uint8_t ripl_ana_low_power_por_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR);
}

__INLINE void ripl_ana_low_power_por_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR, value);
}

// field definitions
#define RIPL_DCDC_OSC_TUNE_MASK   ((uint8_t)0x00000070)
#define RIPL_DCDC_OSC_TUNE_LSB    4
#define RIPL_DCDC_OSC_TUNE_WIDTH  ((uint8_t)0x00000003)
#define RIPL_DCDC_KCOMP_EN_MASK   ((uint8_t)0x0000000E)
#define RIPL_DCDC_KCOMP_EN_LSB    1
#define RIPL_DCDC_KCOMP_EN_WIDTH  ((uint8_t)0x00000003)
#define RIPL_PD_POR_BUF_BIT       ((uint8_t)0x00000001)
#define RIPL_PD_POR_BUF_POS       0

#define RIPL_DCDC_OSC_TUNE_RST    0x4
#define RIPL_DCDC_KCOMP_EN_RST    0x4
#define RIPL_PD_POR_BUF_RST       0x1

__INLINE void ripl_ana_low_power_por_ctrl_pack(uint8_t dcdcosctune, uint8_t dcdckcompen, uint8_t pdporbuf)
{
    ASSERT_ERR((((uint8_t)dcdcosctune << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)dcdckcompen << 1) & ~((uint8_t)0x0000000E)) == 0);
    ASSERT_ERR((((uint8_t)pdporbuf << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR,  ((uint8_t)dcdcosctune << 4) | ((uint8_t)dcdckcompen << 1) | ((uint8_t)pdporbuf << 0));
}

__INLINE void ripl_ana_low_power_por_ctrl_unpack(uint8_t* dcdcosctune, uint8_t* dcdckcompen, uint8_t* pdporbuf)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR);
    *dcdcosctune = (localVal & ((uint8_t)0x00000070)) >> 4;
    *dcdckcompen = (localVal & ((uint8_t)0x0000000E)) >> 1;
    *pdporbuf = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_dcdc_osc_tune_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_dcdc_osc_tune_setf(uint8_t dcdcosctune)
{
    ASSERT_ERR((((uint8_t)dcdcosctune << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR, (REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)dcdcosctune << 4));
}

__INLINE uint8_t ripl_dcdc_kcomp_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x0000000E)) >> 1);
}

__INLINE void ripl_dcdc_kcomp_en_setf(uint8_t dcdckcompen)
{
    ASSERT_ERR((((uint8_t)dcdckcompen << 1) & ~((uint8_t)0x0000000E)) == 0);
    REG_RIPL_WR(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR, (REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR) & ~((uint8_t)0x0000000E)) | ((uint8_t)dcdckcompen << 1));
}

__INLINE uint8_t ripl_pd_por_buf_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_por_buf_setf(uint8_t pdporbuf)
{
    ASSERT_ERR((((uint8_t)pdporbuf << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR, (REG_RIPL_RD(RIPL_ANA_LOW_POWER_POR_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdporbuf << 0));
}

/**
 * @brief ANA_BAT_DIVIDER_CRTL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:05           DCDC_KVOUT   0x4
 *  02:01              VSEL_3V   0x0
 *     00        PD_BAT_DIV_3V   1
 * </pre>
 */
#define RIPL_ANA_BAT_DIVIDER_CRTL_ADDR   0x00000035
#define RIPL_ANA_BAT_DIVIDER_CRTL_OFFSET 0x00000035
#define RIPL_ANA_BAT_DIVIDER_CRTL_INDEX  0x00000035
#define RIPL_ANA_BAT_DIVIDER_CRTL_RESET  0x00000081

__INLINE uint8_t ripl_ana_bat_divider_crtl_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR);
}

__INLINE void ripl_ana_bat_divider_crtl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR, value);
}

// field definitions
#define RIPL_DCDC_KVOUT_MASK      ((uint8_t)0x000000E0)
#define RIPL_DCDC_KVOUT_LSB       5
#define RIPL_DCDC_KVOUT_WIDTH     ((uint8_t)0x00000003)
#define RIPL_VSEL_3V_MASK         ((uint8_t)0x00000006)
#define RIPL_VSEL_3V_LSB          1
#define RIPL_VSEL_3V_WIDTH        ((uint8_t)0x00000002)
#define RIPL_PD_BAT_DIV_3V_BIT    ((uint8_t)0x00000001)
#define RIPL_PD_BAT_DIV_3V_POS    0

#define RIPL_DCDC_KVOUT_RST       0x4
#define RIPL_VSEL_3V_RST          0x0
#define RIPL_PD_BAT_DIV_3V_RST    0x1

__INLINE void ripl_ana_bat_divider_crtl_pack(uint8_t dcdckvout, uint8_t vsel3v, uint8_t pdbatdiv3v)
{
    ASSERT_ERR((((uint8_t)dcdckvout << 5) & ~((uint8_t)0x000000E0)) == 0);
    ASSERT_ERR((((uint8_t)vsel3v << 1) & ~((uint8_t)0x00000006)) == 0);
    ASSERT_ERR((((uint8_t)pdbatdiv3v << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR,  ((uint8_t)dcdckvout << 5) | ((uint8_t)vsel3v << 1) | ((uint8_t)pdbatdiv3v << 0));
}

__INLINE void ripl_ana_bat_divider_crtl_unpack(uint8_t* dcdckvout, uint8_t* vsel3v, uint8_t* pdbatdiv3v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR);
    *dcdckvout = (localVal & ((uint8_t)0x000000E0)) >> 5;
    *vsel3v = (localVal & ((uint8_t)0x00000006)) >> 1;
    *pdbatdiv3v = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_dcdc_kvout_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR);
    return ((localVal & ((uint8_t)0x000000E0)) >> 5);
}

__INLINE void ripl_dcdc_kvout_setf(uint8_t dcdckvout)
{
    ASSERT_ERR((((uint8_t)dcdckvout << 5) & ~((uint8_t)0x000000E0)) == 0);
    REG_RIPL_WR(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR, (REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR) & ~((uint8_t)0x000000E0)) | ((uint8_t)dcdckvout << 5));
}

__INLINE uint8_t ripl_vsel_3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR);
    return ((localVal & ((uint8_t)0x00000006)) >> 1);
}

__INLINE void ripl_vsel_3v_setf(uint8_t vsel3v)
{
    ASSERT_ERR((((uint8_t)vsel3v << 1) & ~((uint8_t)0x00000006)) == 0);
    REG_RIPL_WR(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR, (REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR) & ~((uint8_t)0x00000006)) | ((uint8_t)vsel3v << 1));
}

__INLINE uint8_t ripl_pd_bat_div_3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_pd_bat_div_3v_setf(uint8_t pdbatdiv3v)
{
    ASSERT_ERR((((uint8_t)pdbatdiv3v << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR, (REG_RIPL_RD(RIPL_ANA_BAT_DIVIDER_CRTL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)pdbatdiv3v << 0));
}

/**
 * @brief BBPLL_CLK_GEN_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   Bbpllclkgen_r_clk_run_en   0
 * </pre>
 */
#define RIPL_BBPLL_CLK_GEN_CTRL_ADDR   0x0000003B
#define RIPL_BBPLL_CLK_GEN_CTRL_OFFSET 0x0000003B
#define RIPL_BBPLL_CLK_GEN_CTRL_INDEX  0x0000003B
#define RIPL_BBPLL_CLK_GEN_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_bbpll_clk_gen_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_BBPLL_CLK_GEN_CTRL_ADDR);
}

__INLINE void ripl_bbpll_clk_gen_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BBPLL_CLK_GEN_CTRL_ADDR, value);
}

// field definitions
#define RIPL_BBPLLCLKGEN_R_CLK_RUN_EN_BIT    ((uint8_t)0x00000001)
#define RIPL_BBPLLCLKGEN_R_CLK_RUN_EN_POS    0

#define RIPL_BBPLLCLKGEN_R_CLK_RUN_EN_RST    0x0

__INLINE uint8_t ripl_bbpllclkgen_r_clk_run_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CLK_GEN_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_bbpllclkgen_r_clk_run_en_setf(uint8_t bbpllclkgenrclkrunen)
{
    ASSERT_ERR((((uint8_t)bbpllclkgenrclkrunen << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CLK_GEN_CTRL_ADDR, (uint8_t)bbpllclkgenrclkrunen << 0);
}

/**
 * @brief BT_ATB_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   n_digrfswout_en_mux_en   0
 *     00      n_digrfswout_en   1
 * </pre>
 */
#define RIPL_BT_ATB_CTRL_ADDR   0x0000003C
#define RIPL_BT_ATB_CTRL_OFFSET 0x0000003C
#define RIPL_BT_ATB_CTRL_INDEX  0x0000003C
#define RIPL_BT_ATB_CTRL_RESET  0x00000001

__INLINE uint8_t ripl_bt_atb_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR);
}

__INLINE void ripl_bt_atb_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BT_ATB_CTRL_ADDR, value);
}

// field definitions
#define RIPL_N_DIGRFSWOUT_EN_MUX_EN_BIT    ((uint8_t)0x00000002)
#define RIPL_N_DIGRFSWOUT_EN_MUX_EN_POS    1
#define RIPL_N_DIGRFSWOUT_EN_BIT           ((uint8_t)0x00000001)
#define RIPL_N_DIGRFSWOUT_EN_POS           0

#define RIPL_N_DIGRFSWOUT_EN_MUX_EN_RST    0x0
#define RIPL_N_DIGRFSWOUT_EN_RST           0x1

__INLINE void ripl_bt_atb_ctrl_pack(uint8_t ndigrfswoutenmuxen, uint8_t ndigrfswouten)
{
    ASSERT_ERR((((uint8_t)ndigrfswoutenmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)ndigrfswouten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_BT_ATB_CTRL_ADDR,  ((uint8_t)ndigrfswoutenmuxen << 1) | ((uint8_t)ndigrfswouten << 0));
}

__INLINE void ripl_bt_atb_ctrl_unpack(uint8_t* ndigrfswoutenmuxen, uint8_t* ndigrfswouten)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR);
    *ndigrfswoutenmuxen = (localVal & ((uint8_t)0x00000002)) >> 1;
    *ndigrfswouten = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_n_digrfswout_en_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_n_digrfswout_en_mux_en_setf(uint8_t ndigrfswoutenmuxen)
{
    ASSERT_ERR((((uint8_t)ndigrfswoutenmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_BT_ATB_CTRL_ADDR, (REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)ndigrfswoutenmuxen << 1));
}

__INLINE uint8_t ripl_n_digrfswout_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_n_digrfswout_en_setf(uint8_t ndigrfswouten)
{
    ASSERT_ERR((((uint8_t)ndigrfswouten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_BT_ATB_CTRL_ADDR, (REG_RIPL_RD(RIPL_BT_ATB_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)ndigrfswouten << 0));
}

/**
 * @brief RF_POWER_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01      rx_down_out_sel   0
 *     00      tx_doun_out_sel   0
 * </pre>
 */
#define RIPL_RF_POWER_CTRL_ADDR   0x00000043
#define RIPL_RF_POWER_CTRL_OFFSET 0x00000043
#define RIPL_RF_POWER_CTRL_INDEX  0x00000043
#define RIPL_RF_POWER_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_rf_power_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR);
}

__INLINE void ripl_rf_power_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_POWER_CTRL_ADDR, value);
}

// field definitions
#define RIPL_RX_DOWN_OUT_SEL_BIT    ((uint8_t)0x00000002)
#define RIPL_RX_DOWN_OUT_SEL_POS    1
#define RIPL_TX_DOUN_OUT_SEL_BIT    ((uint8_t)0x00000001)
#define RIPL_TX_DOUN_OUT_SEL_POS    0

#define RIPL_RX_DOWN_OUT_SEL_RST    0x0
#define RIPL_TX_DOUN_OUT_SEL_RST    0x0

__INLINE void ripl_rf_power_ctrl_pack(uint8_t rxdownoutsel, uint8_t txdounoutsel)
{
    ASSERT_ERR((((uint8_t)rxdownoutsel << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)txdounoutsel << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RF_POWER_CTRL_ADDR,  ((uint8_t)rxdownoutsel << 1) | ((uint8_t)txdounoutsel << 0));
}

__INLINE void ripl_rf_power_ctrl_unpack(uint8_t* rxdownoutsel, uint8_t* txdounoutsel)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR);
    *rxdownoutsel = (localVal & ((uint8_t)0x00000002)) >> 1;
    *txdounoutsel = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_rx_down_out_sel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_rx_down_out_sel_setf(uint8_t rxdownoutsel)
{
    ASSERT_ERR((((uint8_t)rxdownoutsel << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RF_POWER_CTRL_ADDR, (REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)rxdownoutsel << 1));
}

__INLINE uint8_t ripl_tx_doun_out_sel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_tx_doun_out_sel_setf(uint8_t txdounoutsel)
{
    ASSERT_ERR((((uint8_t)txdounoutsel << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RF_POWER_CTRL_ADDR, (REG_RIPL_RD(RIPL_RF_POWER_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)txdounoutsel << 0));
}

/**
 * @brief RF_AGC_FSM_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:04         RFAGC_T_IDLE   0x1
 *     03          RFAGC_PD_EN   0
 *     02   RFAGC_RFGAIN_CONV_DIS   0
 *  01:00     RFAGC_MAXGAIN_RF   0x0
 * </pre>
 */
#define RIPL_RF_AGC_FSM_CTRL1_ADDR   0x00000048
#define RIPL_RF_AGC_FSM_CTRL1_OFFSET 0x00000048
#define RIPL_RF_AGC_FSM_CTRL1_INDEX  0x00000048
#define RIPL_RF_AGC_FSM_CTRL1_RESET  0x00000010

__INLINE uint8_t ripl_rf_agc_fsm_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_RFAGC_T_IDLE_MASK            ((uint8_t)0x00000030)
#define RIPL_RFAGC_T_IDLE_LSB             4
#define RIPL_RFAGC_T_IDLE_WIDTH           ((uint8_t)0x00000002)
#define RIPL_RFAGC_PD_EN_BIT              ((uint8_t)0x00000008)
#define RIPL_RFAGC_PD_EN_POS              3
#define RIPL_RFAGC_RFGAIN_CONV_DIS_BIT    ((uint8_t)0x00000004)
#define RIPL_RFAGC_RFGAIN_CONV_DIS_POS    2
#define RIPL_RFAGC_MAXGAIN_RF_MASK        ((uint8_t)0x00000003)
#define RIPL_RFAGC_MAXGAIN_RF_LSB         0
#define RIPL_RFAGC_MAXGAIN_RF_WIDTH       ((uint8_t)0x00000002)

#define RIPL_RFAGC_T_IDLE_RST             0x1
#define RIPL_RFAGC_PD_EN_RST              0x0
#define RIPL_RFAGC_RFGAIN_CONV_DIS_RST    0x0
#define RIPL_RFAGC_MAXGAIN_RF_RST         0x0

__INLINE void ripl_rf_agc_fsm_ctrl1_pack(uint8_t rfagctidle, uint8_t rfagcpden, uint8_t rfagcrfgainconvdis, uint8_t rfagcmaxgainrf)
{
    ASSERT_ERR((((uint8_t)rfagctidle << 4) & ~((uint8_t)0x00000030)) == 0);
    ASSERT_ERR((((uint8_t)rfagcpden << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)rfagcrfgainconvdis << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)rfagcmaxgainrf << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR,  ((uint8_t)rfagctidle << 4) | ((uint8_t)rfagcpden << 3) | ((uint8_t)rfagcrfgainconvdis << 2) | ((uint8_t)rfagcmaxgainrf << 0));
}

__INLINE void ripl_rf_agc_fsm_ctrl1_unpack(uint8_t* rfagctidle, uint8_t* rfagcpden, uint8_t* rfagcrfgainconvdis, uint8_t* rfagcmaxgainrf)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
    *rfagctidle = (localVal & ((uint8_t)0x00000030)) >> 4;
    *rfagcpden = (localVal & ((uint8_t)0x00000008)) >> 3;
    *rfagcrfgainconvdis = (localVal & ((uint8_t)0x00000004)) >> 2;
    *rfagcmaxgainrf = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_rfagc_t_idle_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000030)) >> 4);
}

__INLINE void ripl_rfagc_t_idle_setf(uint8_t rfagctidle)
{
    ASSERT_ERR((((uint8_t)rfagctidle << 4) & ~((uint8_t)0x00000030)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000030)) | ((uint8_t)rfagctidle << 4));
}

__INLINE uint8_t ripl_rfagc_pd_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_rfagc_pd_en_setf(uint8_t rfagcpden)
{
    ASSERT_ERR((((uint8_t)rfagcpden << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)rfagcpden << 3));
}

__INLINE uint8_t ripl_rfagc_rfgain_conv_dis_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_rfagc_rfgain_conv_dis_setf(uint8_t rfagcrfgainconvdis)
{
    ASSERT_ERR((((uint8_t)rfagcrfgainconvdis << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)rfagcrfgainconvdis << 2));
}

__INLINE uint8_t ripl_rfagc_maxgain_rf_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_rfagc_maxgain_rf_setf(uint8_t rfagcmaxgainrf)
{
    ASSERT_ERR((((uint8_t)rfagcmaxgainrf << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)rfagcmaxgainrf << 0));
}

/**
 * @brief RF_AGC_FSM_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04          RFAGC_DELAY   0x5
 *  03:00   RFAGC_RFGAIN_BYREG   0x1
 * </pre>
 */
#define RIPL_RF_AGC_FSM_CTRL2_ADDR   0x00000049
#define RIPL_RF_AGC_FSM_CTRL2_OFFSET 0x00000049
#define RIPL_RF_AGC_FSM_CTRL2_INDEX  0x00000049
#define RIPL_RF_AGC_FSM_CTRL2_RESET  0x00000051

__INLINE uint8_t ripl_rf_agc_fsm_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_RFAGC_DELAY_MASK          ((uint8_t)0x00000070)
#define RIPL_RFAGC_DELAY_LSB           4
#define RIPL_RFAGC_DELAY_WIDTH         ((uint8_t)0x00000003)
#define RIPL_RFAGC_RFGAIN_BYREG_MASK   ((uint8_t)0x0000000F)
#define RIPL_RFAGC_RFGAIN_BYREG_LSB    0
#define RIPL_RFAGC_RFGAIN_BYREG_WIDTH  ((uint8_t)0x00000004)

#define RIPL_RFAGC_DELAY_RST           0x5
#define RIPL_RFAGC_RFGAIN_BYREG_RST    0x1

__INLINE void ripl_rf_agc_fsm_ctrl2_pack(uint8_t rfagcdelay, uint8_t rfagcrfgainbyreg)
{
    ASSERT_ERR((((uint8_t)rfagcdelay << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)rfagcrfgainbyreg << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL2_ADDR,  ((uint8_t)rfagcdelay << 4) | ((uint8_t)rfagcrfgainbyreg << 0));
}

__INLINE void ripl_rf_agc_fsm_ctrl2_unpack(uint8_t* rfagcdelay, uint8_t* rfagcrfgainbyreg)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR);
    *rfagcdelay = (localVal & ((uint8_t)0x00000070)) >> 4;
    *rfagcrfgainbyreg = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_rfagc_delay_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_rfagc_delay_setf(uint8_t rfagcdelay)
{
    ASSERT_ERR((((uint8_t)rfagcdelay << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)rfagcdelay << 4));
}

__INLINE uint8_t ripl_rfagc_rfgain_byreg_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_rfagc_rfgain_byreg_setf(uint8_t rfagcrfgainbyreg)
{
    ASSERT_ERR((((uint8_t)rfagcrfgainbyreg << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL2_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)rfagcrfgainbyreg << 0));
}

/**
 * @brief RF_AGC_FSM_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00      RFAGC_COUNTER_H   0x5
 * </pre>
 */
#define RIPL_RF_AGC_FSM_CTRL3_ADDR   0x0000004A
#define RIPL_RF_AGC_FSM_CTRL3_OFFSET 0x0000004A
#define RIPL_RF_AGC_FSM_CTRL3_INDEX  0x0000004A
#define RIPL_RF_AGC_FSM_CTRL3_RESET  0x00000005

__INLINE uint8_t ripl_rf_agc_fsm_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL3_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_RFAGC_COUNTER_H_MASK   ((uint8_t)0x0000003F)
#define RIPL_RFAGC_COUNTER_H_LSB    0
#define RIPL_RFAGC_COUNTER_H_WIDTH  ((uint8_t)0x00000006)

#define RIPL_RFAGC_COUNTER_H_RST    0x5

__INLINE uint8_t ripl_rfagc_counter_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL3_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_rfagc_counter_h_setf(uint8_t rfagccounterh)
{
    ASSERT_ERR((((uint8_t)rfagccounterh << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL3_ADDR, (uint8_t)rfagccounterh << 0);
}

/**
 * @brief RF_AGC_FSM_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00      RFAGC_COUNTER_I   0x5
 * </pre>
 */
#define RIPL_RF_AGC_FSM_CTRL4_ADDR   0x0000004B
#define RIPL_RF_AGC_FSM_CTRL4_OFFSET 0x0000004B
#define RIPL_RF_AGC_FSM_CTRL4_INDEX  0x0000004B
#define RIPL_RF_AGC_FSM_CTRL4_RESET  0x00000005

__INLINE uint8_t ripl_rf_agc_fsm_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL4_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_RFAGC_COUNTER_I_MASK   ((uint8_t)0x0000003F)
#define RIPL_RFAGC_COUNTER_I_LSB    0
#define RIPL_RFAGC_COUNTER_I_WIDTH  ((uint8_t)0x00000006)

#define RIPL_RFAGC_COUNTER_I_RST    0x5

__INLINE uint8_t ripl_rfagc_counter_i_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_rfagc_counter_i_setf(uint8_t rfagccounteri)
{
    ASSERT_ERR((((uint8_t)rfagccounteri << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL4_ADDR, (uint8_t)rfagccounteri << 0);
}

/**
 * @brief RF_AGC_FSM_CTRL5 register definition
 */
#define RIPL_RF_AGC_FSM_CTRL5_ADDR   0x0000004C
#define RIPL_RF_AGC_FSM_CTRL5_OFFSET 0x0000004C
#define RIPL_RF_AGC_FSM_CTRL5_INDEX  0x0000004C
#define RIPL_RF_AGC_FSM_CTRL5_RESET  0x00000000

__INLINE uint8_t ripl_rf_agc_fsm_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL5_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL5_ADDR, value);
}

/**
 * @brief RF_AGC_FSM_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   RFAGC_RXLNA_GAIN_MUX_EN   1
 *  05:04     RFAGC_RXLNA_GAIN   0x3
 *     03   RFAGC_RXMIX_GAIN_MUX_EN   1
 *  02:00     RFAGC_RXMIX_GAIN   0x7
 * </pre>
 */
#define RIPL_RF_AGC_FSM_CTRL6_ADDR   0x0000004D
#define RIPL_RF_AGC_FSM_CTRL6_OFFSET 0x0000004D
#define RIPL_RF_AGC_FSM_CTRL6_INDEX  0x0000004D
#define RIPL_RF_AGC_FSM_CTRL6_RESET  0x0000007F

__INLINE uint8_t ripl_rf_agc_fsm_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
}

__INLINE void ripl_rf_agc_fsm_ctrl6_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR, value);
}

// field definitions
#define RIPL_RFAGC_RXLNA_GAIN_MUX_EN_BIT    ((uint8_t)0x00000040)
#define RIPL_RFAGC_RXLNA_GAIN_MUX_EN_POS    6
#define RIPL_RFAGC_RXLNA_GAIN_MASK          ((uint8_t)0x00000030)
#define RIPL_RFAGC_RXLNA_GAIN_LSB           4
#define RIPL_RFAGC_RXLNA_GAIN_WIDTH         ((uint8_t)0x00000002)
#define RIPL_RFAGC_RXMIX_GAIN_MUX_EN_BIT    ((uint8_t)0x00000008)
#define RIPL_RFAGC_RXMIX_GAIN_MUX_EN_POS    3
#define RIPL_RFAGC_RXMIX_GAIN_MASK          ((uint8_t)0x00000007)
#define RIPL_RFAGC_RXMIX_GAIN_LSB           0
#define RIPL_RFAGC_RXMIX_GAIN_WIDTH         ((uint8_t)0x00000003)

#define RIPL_RFAGC_RXLNA_GAIN_MUX_EN_RST    0x1
#define RIPL_RFAGC_RXLNA_GAIN_RST           0x3
#define RIPL_RFAGC_RXMIX_GAIN_MUX_EN_RST    0x1
#define RIPL_RFAGC_RXMIX_GAIN_RST           0x7

__INLINE void ripl_rf_agc_fsm_ctrl6_pack(uint8_t rfagcrxlnagainmuxen, uint8_t rfagcrxlnagain, uint8_t rfagcrxmixgainmuxen, uint8_t rfagcrxmixgain)
{
    ASSERT_ERR((((uint8_t)rfagcrxlnagainmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)rfagcrxlnagain << 4) & ~((uint8_t)0x00000030)) == 0);
    ASSERT_ERR((((uint8_t)rfagcrxmixgainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)rfagcrxmixgain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR,  ((uint8_t)rfagcrxlnagainmuxen << 6) | ((uint8_t)rfagcrxlnagain << 4) | ((uint8_t)rfagcrxmixgainmuxen << 3) | ((uint8_t)rfagcrxmixgain << 0));
}

__INLINE void ripl_rf_agc_fsm_ctrl6_unpack(uint8_t* rfagcrxlnagainmuxen, uint8_t* rfagcrxlnagain, uint8_t* rfagcrxmixgainmuxen, uint8_t* rfagcrxmixgain)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
    *rfagcrxlnagainmuxen = (localVal & ((uint8_t)0x00000040)) >> 6;
    *rfagcrxlnagain = (localVal & ((uint8_t)0x00000030)) >> 4;
    *rfagcrxmixgainmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *rfagcrxmixgain = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_rfagc_rxlna_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rfagc_rxlna_gain_mux_en_setf(uint8_t rfagcrxlnagainmuxen)
{
    ASSERT_ERR((((uint8_t)rfagcrxlnagainmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rfagcrxlnagainmuxen << 6));
}

__INLINE uint8_t ripl_rfagc_rxlna_gain_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000030)) >> 4);
}

__INLINE void ripl_rfagc_rxlna_gain_setf(uint8_t rfagcrxlnagain)
{
    ASSERT_ERR((((uint8_t)rfagcrxlnagain << 4) & ~((uint8_t)0x00000030)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR) & ~((uint8_t)0x00000030)) | ((uint8_t)rfagcrxlnagain << 4));
}

__INLINE uint8_t ripl_rfagc_rxmix_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_rfagc_rxmix_gain_mux_en_setf(uint8_t rfagcrxmixgainmuxen)
{
    ASSERT_ERR((((uint8_t)rfagcrxmixgainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)rfagcrxmixgainmuxen << 3));
}

__INLINE uint8_t ripl_rfagc_rxmix_gain_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_rfagc_rxmix_gain_setf(uint8_t rfagcrxmixgain)
{
    ASSERT_ERR((((uint8_t)rfagcrxmixgain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RF_AGC_FSM_CTRL6_ADDR, (REG_RIPL_RD(RIPL_RF_AGC_FSM_CTRL6_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)rfagcrxmixgain << 0));
}

/**
 * @brief MODEM_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:01            MDM_RXPWR   0x0
 *     00     MDM_GAIN_SET_STS   0
 * </pre>
 */
#define RIPL_MODEM_CTRL_ADDR   0x0000004E
#define RIPL_MODEM_CTRL_OFFSET 0x0000004E
#define RIPL_MODEM_CTRL_INDEX  0x0000004E
#define RIPL_MODEM_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_modem_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_CTRL_ADDR);
}

__INLINE void ripl_modem_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_MODEM_CTRL_ADDR, value);
}

// field definitions
#define RIPL_MDM_RXPWR_MASK          ((uint8_t)0x0000007E)
#define RIPL_MDM_RXPWR_LSB           1
#define RIPL_MDM_RXPWR_WIDTH         ((uint8_t)0x00000006)
#define RIPL_MDM_GAIN_SET_STS_BIT    ((uint8_t)0x00000001)
#define RIPL_MDM_GAIN_SET_STS_POS    0

#define RIPL_MDM_RXPWR_RST           0x0
#define RIPL_MDM_GAIN_SET_STS_RST    0x0

__INLINE void ripl_modem_ctrl_unpack(uint8_t* mdmrxpwr, uint8_t* mdmgainsetsts)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_CTRL_ADDR);
    *mdmrxpwr = (localVal & ((uint8_t)0x0000007E)) >> 1;
    *mdmgainsetsts = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_mdm_rxpwr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x0000007E)) >> 1);
}

__INLINE uint8_t ripl_mdm_gain_set_sts_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_mdm_gain_set_sts_setf(uint8_t mdmgainsetsts)
{
    ASSERT_ERR((((uint8_t)mdmgainsetsts << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_MODEM_CTRL_ADDR, (uint8_t)mdmgainsetsts << 0);
}

/**
 * @brief RF_PLL_FSM_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07       RPLL_CALI_DONE   0
 *     02   RFPLL_LOCKDET_BYPASS   0
 *     01   ICPCALI_CALI_BYPASS   0
 *     00   VCOCALI_CALI_BYPASS   0
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL1_ADDR   0x00000050
#define RIPL_RF_PLL_FSM_CTRL1_OFFSET 0x00000050
#define RIPL_RF_PLL_FSM_CTRL1_INDEX  0x00000050
#define RIPL_RF_PLL_FSM_CTRL1_RESET  0x00000000

__INLINE uint8_t ripl_rf_pll_fsm_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_RPLL_CALI_DONE_BIT          ((uint8_t)0x00000080)
#define RIPL_RPLL_CALI_DONE_POS          7
#define RIPL_RFPLL_LOCKDET_BYPASS_BIT    ((uint8_t)0x00000004)
#define RIPL_RFPLL_LOCKDET_BYPASS_POS    2
#define RIPL_ICPCALI_CALI_BYPASS_BIT     ((uint8_t)0x00000002)
#define RIPL_ICPCALI_CALI_BYPASS_POS     1
#define RIPL_VCOCALI_CALI_BYPASS_BIT     ((uint8_t)0x00000001)
#define RIPL_VCOCALI_CALI_BYPASS_POS     0

#define RIPL_RPLL_CALI_DONE_RST          0x0
#define RIPL_RFPLL_LOCKDET_BYPASS_RST    0x0
#define RIPL_ICPCALI_CALI_BYPASS_RST     0x0
#define RIPL_VCOCALI_CALI_BYPASS_RST     0x0

__INLINE void ripl_rf_pll_fsm_ctrl1_pack(uint8_t rfplllockdetbypass, uint8_t icpcalicalibypass, uint8_t vcocalicalibypass)
{
    ASSERT_ERR((((uint8_t)rfplllockdetbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)icpcalicalibypass << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)vcocalicalibypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL1_ADDR,  ((uint8_t)rfplllockdetbypass << 2) | ((uint8_t)icpcalicalibypass << 1) | ((uint8_t)vcocalicalibypass << 0));
}

__INLINE void ripl_rf_pll_fsm_ctrl1_unpack(uint8_t* rpllcalidone, uint8_t* rfplllockdetbypass, uint8_t* icpcalicalibypass, uint8_t* vcocalicalibypass)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
    *rpllcalidone = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfplllockdetbypass = (localVal & ((uint8_t)0x00000004)) >> 2;
    *icpcalicalibypass = (localVal & ((uint8_t)0x00000002)) >> 1;
    *vcocalicalibypass = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_rpll_cali_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_rfpll_lockdet_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_rfpll_lockdet_bypass_setf(uint8_t rfplllockdetbypass)
{
    ASSERT_ERR((((uint8_t)rfplllockdetbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)rfplllockdetbypass << 2));
}

__INLINE uint8_t ripl_icpcali_cali_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_icpcali_cali_bypass_setf(uint8_t icpcalicalibypass)
{
    ASSERT_ERR((((uint8_t)icpcalicalibypass << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)icpcalicalibypass << 1));
}

__INLINE uint8_t ripl_vcocali_cali_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_vcocali_cali_bypass_setf(uint8_t vcocalicalibypass)
{
    ASSERT_ERR((((uint8_t)vcocalicalibypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)vcocalicalibypass << 0));
}

/**
 * @brief RF_PLL_FSM_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   ICPCALI_KVCOSTEP_NUM_L   0x50
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL2_ADDR   0x00000051
#define RIPL_RF_PLL_FSM_CTRL2_OFFSET 0x00000051
#define RIPL_RF_PLL_FSM_CTRL2_INDEX  0x00000051
#define RIPL_RF_PLL_FSM_CTRL2_RESET  0x00000050

__INLINE uint8_t ripl_rf_pll_fsm_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL2_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_KVCOSTEP_NUM_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_ICPCALI_KVCOSTEP_NUM_L_LSB    0
#define RIPL_ICPCALI_KVCOSTEP_NUM_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_ICPCALI_KVCOSTEP_NUM_L_RST    0x50

__INLINE uint8_t ripl_icpcali_kvcostep_num_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL2_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_icpcali_kvcostep_num_l_setf(uint8_t icpcalikvcostepnuml)
{
    ASSERT_ERR((((uint8_t)icpcalikvcostepnuml << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL2_ADDR, (uint8_t)icpcalikvcostepnuml << 0);
}

/**
 * @brief RF_PLL_FSM_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02   ICPCALI_KVCOSTEP_NUM_OUT_EN   0
 *  01:00   ICPCALI_KVCOSTEP_NUM_H   0x0
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL3_ADDR   0x00000052
#define RIPL_RF_PLL_FSM_CTRL3_OFFSET 0x00000052
#define RIPL_RF_PLL_FSM_CTRL3_INDEX  0x00000052
#define RIPL_RF_PLL_FSM_CTRL3_RESET  0x00000000

__INLINE uint8_t ripl_rf_pll_fsm_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_KVCOSTEP_NUM_OUT_EN_BIT    ((uint8_t)0x00000004)
#define RIPL_ICPCALI_KVCOSTEP_NUM_OUT_EN_POS    2
#define RIPL_ICPCALI_KVCOSTEP_NUM_H_MASK        ((uint8_t)0x00000003)
#define RIPL_ICPCALI_KVCOSTEP_NUM_H_LSB         0
#define RIPL_ICPCALI_KVCOSTEP_NUM_H_WIDTH       ((uint8_t)0x00000002)

#define RIPL_ICPCALI_KVCOSTEP_NUM_OUT_EN_RST    0x0
#define RIPL_ICPCALI_KVCOSTEP_NUM_H_RST         0x0

__INLINE void ripl_rf_pll_fsm_ctrl3_pack(uint8_t icpcalikvcostepnumouten, uint8_t icpcalikvcostepnumh)
{
    ASSERT_ERR((((uint8_t)icpcalikvcostepnumouten << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)icpcalikvcostepnumh << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL3_ADDR,  ((uint8_t)icpcalikvcostepnumouten << 2) | ((uint8_t)icpcalikvcostepnumh << 0));
}

__INLINE void ripl_rf_pll_fsm_ctrl3_unpack(uint8_t* icpcalikvcostepnumouten, uint8_t* icpcalikvcostepnumh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR);
    *icpcalikvcostepnumouten = (localVal & ((uint8_t)0x00000004)) >> 2;
    *icpcalikvcostepnumh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_icpcali_kvcostep_num_out_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_icpcali_kvcostep_num_out_en_setf(uint8_t icpcalikvcostepnumouten)
{
    ASSERT_ERR((((uint8_t)icpcalikvcostepnumouten << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)icpcalikvcostepnumouten << 2));
}

__INLINE uint8_t ripl_icpcali_kvcostep_num_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_icpcali_kvcostep_num_h_setf(uint8_t icpcalikvcostepnumh)
{
    ASSERT_ERR((((uint8_t)icpcalikvcostepnumh << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL3_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)icpcalikvcostepnumh << 0));
}

/**
 * @brief RF_PLL_FSM_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   ICPCALI_LUT_ICP_IN_DLY1_L   0x0
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL4_ADDR   0x00000053
#define RIPL_RF_PLL_FSM_CTRL4_OFFSET 0x00000053
#define RIPL_RF_PLL_FSM_CTRL4_INDEX  0x00000053
#define RIPL_RF_PLL_FSM_CTRL4_RESET  0x00000000

__INLINE uint8_t ripl_rf_pll_fsm_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL4_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_L_LSB    0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_L_RST    0x0

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly1_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly1_l_setf(uint8_t icpcaliluticpindly1l)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly1l << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL4_ADDR, (uint8_t)icpcaliluticpindly1l << 0);
}

/**
 * @brief RF_PLL_FSM_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   ICPCALI_LUT_ICP_IN_DLY1_OUT_EN   0
 *  03:00   ICPCALI_LUT_ICP_IN_DLY1_H   0x8
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL5_ADDR   0x00000054
#define RIPL_RF_PLL_FSM_CTRL5_OFFSET 0x00000054
#define RIPL_RF_PLL_FSM_CTRL5_INDEX  0x00000054
#define RIPL_RF_PLL_FSM_CTRL5_RESET  0x00000008

__INLINE uint8_t ripl_rf_pll_fsm_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL5_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_OUT_EN_BIT    ((uint8_t)0x00000010)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_OUT_EN_POS    4
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_H_MASK        ((uint8_t)0x0000000F)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_H_LSB         0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_H_WIDTH       ((uint8_t)0x00000004)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_OUT_EN_RST    0x0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY1_H_RST         0x8

__INLINE void ripl_rf_pll_fsm_ctrl5_pack(uint8_t icpcaliluticpindly1outen, uint8_t icpcaliluticpindly1h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly1outen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)icpcaliluticpindly1h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL5_ADDR,  ((uint8_t)icpcaliluticpindly1outen << 4) | ((uint8_t)icpcaliluticpindly1h << 0));
}

__INLINE void ripl_rf_pll_fsm_ctrl5_unpack(uint8_t* icpcaliluticpindly1outen, uint8_t* icpcaliluticpindly1h)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR);
    *icpcaliluticpindly1outen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *icpcaliluticpindly1h = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly1_out_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_icpcali_lut_icp_in_dly1_out_en_setf(uint8_t icpcaliluticpindly1outen)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly1outen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL5_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)icpcaliluticpindly1outen << 4));
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly1_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly1_h_setf(uint8_t icpcaliluticpindly1h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly1h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL5_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL5_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)icpcaliluticpindly1h << 0));
}

/**
 * @brief RF_PLL_FSM_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   ICPCALI_LUT_ICP_IN_DLY2_L   0x0
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL6_ADDR   0x00000055
#define RIPL_RF_PLL_FSM_CTRL6_OFFSET 0x00000055
#define RIPL_RF_PLL_FSM_CTRL6_INDEX  0x00000055
#define RIPL_RF_PLL_FSM_CTRL6_RESET  0x00000000

__INLINE uint8_t ripl_rf_pll_fsm_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL6_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl6_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL6_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_L_LSB    0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_L_RST    0x0

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly2_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL6_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly2_l_setf(uint8_t icpcaliluticpindly2l)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly2l << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL6_ADDR, (uint8_t)icpcaliluticpindly2l << 0);
}

/**
 * @brief RF_PLL_FSM_CTRL7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   ICPCALI_LUT_ICP_IN_DLY2_OUT_EN   0
 *  03:00   ICPCALI_LUT_ICP_IN_DLY2_H   0x8
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL7_ADDR   0x00000056
#define RIPL_RF_PLL_FSM_CTRL7_OFFSET 0x00000056
#define RIPL_RF_PLL_FSM_CTRL7_INDEX  0x00000056
#define RIPL_RF_PLL_FSM_CTRL7_RESET  0x00000008

__INLINE uint8_t ripl_rf_pll_fsm_ctrl7_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl7_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL7_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_OUT_EN_BIT    ((uint8_t)0x00000010)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_OUT_EN_POS    4
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_H_MASK        ((uint8_t)0x0000000F)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_H_LSB         0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_H_WIDTH       ((uint8_t)0x00000004)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_OUT_EN_RST    0x0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY2_H_RST         0x8

__INLINE void ripl_rf_pll_fsm_ctrl7_pack(uint8_t icpcaliluticpindly2outen, uint8_t icpcaliluticpindly2h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly2outen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)icpcaliluticpindly2h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL7_ADDR,  ((uint8_t)icpcaliluticpindly2outen << 4) | ((uint8_t)icpcaliluticpindly2h << 0));
}

__INLINE void ripl_rf_pll_fsm_ctrl7_unpack(uint8_t* icpcaliluticpindly2outen, uint8_t* icpcaliluticpindly2h)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR);
    *icpcaliluticpindly2outen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *icpcaliluticpindly2h = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly2_out_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_icpcali_lut_icp_in_dly2_out_en_setf(uint8_t icpcaliluticpindly2outen)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly2outen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL7_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)icpcaliluticpindly2outen << 4));
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly2_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly2_h_setf(uint8_t icpcaliluticpindly2h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly2h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL7_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL7_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)icpcaliluticpindly2h << 0));
}

/**
 * @brief RF_PLL_FSM_CTRL8 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   ICPCALI_LUT_ICP_IN_DLY3_L   0x0
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL8_ADDR   0x00000057
#define RIPL_RF_PLL_FSM_CTRL8_OFFSET 0x00000057
#define RIPL_RF_PLL_FSM_CTRL8_INDEX  0x00000057
#define RIPL_RF_PLL_FSM_CTRL8_RESET  0x00000000

__INLINE uint8_t ripl_rf_pll_fsm_ctrl8_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL8_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl8_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL8_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_L_LSB    0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_L_RST    0x0

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly3_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL8_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly3_l_setf(uint8_t icpcaliluticpindly3l)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly3l << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL8_ADDR, (uint8_t)icpcaliluticpindly3l << 0);
}

/**
 * @brief RF_PLL_FSM_CTRL9 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   ICPCALI_LUT_ICP_IN_DLY3_OUT_EN   0
 *  03:00   ICPCALI_LUT_ICP_IN_DLY3_H   0x8
 * </pre>
 */
#define RIPL_RF_PLL_FSM_CTRL9_ADDR   0x00000058
#define RIPL_RF_PLL_FSM_CTRL9_OFFSET 0x00000058
#define RIPL_RF_PLL_FSM_CTRL9_INDEX  0x00000058
#define RIPL_RF_PLL_FSM_CTRL9_RESET  0x00000008

__INLINE uint8_t ripl_rf_pll_fsm_ctrl9_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR);
}

__INLINE void ripl_rf_pll_fsm_ctrl9_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL9_ADDR, value);
}

// field definitions
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_OUT_EN_BIT    ((uint8_t)0x00000010)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_OUT_EN_POS    4
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_H_MASK        ((uint8_t)0x0000000F)
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_H_LSB         0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_H_WIDTH       ((uint8_t)0x00000004)

#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_OUT_EN_RST    0x0
#define RIPL_ICPCALI_LUT_ICP_IN_DLY3_H_RST         0x8

__INLINE void ripl_rf_pll_fsm_ctrl9_pack(uint8_t icpcaliluticpindly3outen, uint8_t icpcaliluticpindly3h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly3outen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)icpcaliluticpindly3h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL9_ADDR,  ((uint8_t)icpcaliluticpindly3outen << 4) | ((uint8_t)icpcaliluticpindly3h << 0));
}

__INLINE void ripl_rf_pll_fsm_ctrl9_unpack(uint8_t* icpcaliluticpindly3outen, uint8_t* icpcaliluticpindly3h)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR);
    *icpcaliluticpindly3outen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *icpcaliluticpindly3h = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly3_out_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_icpcali_lut_icp_in_dly3_out_en_setf(uint8_t icpcaliluticpindly3outen)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly3outen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL9_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)icpcaliluticpindly3outen << 4));
}

__INLINE uint8_t ripl_icpcali_lut_icp_in_dly3_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_icpcali_lut_icp_in_dly3_h_setf(uint8_t icpcaliluticpindly3h)
{
    ASSERT_ERR((((uint8_t)icpcaliluticpindly3h << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_FSM_CTRL9_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_FSM_CTRL9_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)icpcaliluticpindly3h << 0));
}

/**
 * @brief STANDBYFSM_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   STDBYFSM_BPLL_RST_DLY   0x3
 * </pre>
 */
#define RIPL_STANDBYFSM_CTRL1_ADDR   0x0000005A
#define RIPL_STANDBYFSM_CTRL1_OFFSET 0x0000005A
#define RIPL_STANDBYFSM_CTRL1_INDEX  0x0000005A
#define RIPL_STANDBYFSM_CTRL1_RESET  0x00000003

__INLINE uint8_t ripl_standbyfsm_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_STANDBYFSM_CTRL1_ADDR);
}

__INLINE void ripl_standbyfsm_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_STDBYFSM_BPLL_RST_DLY_MASK   ((uint8_t)0x000000FF)
#define RIPL_STDBYFSM_BPLL_RST_DLY_LSB    0
#define RIPL_STDBYFSM_BPLL_RST_DLY_WIDTH  ((uint8_t)0x00000008)

#define RIPL_STDBYFSM_BPLL_RST_DLY_RST    0x3

__INLINE uint8_t ripl_stdbyfsm_bpll_rst_dly_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL1_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_stdbyfsm_bpll_rst_dly_setf(uint8_t stdbyfsmbpllrstdly)
{
    ASSERT_ERR((((uint8_t)stdbyfsmbpllrstdly << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL1_ADDR, (uint8_t)stdbyfsmbpllrstdly << 0);
}

/**
 * @brief STANDBYFSM_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06     STDBYFSM_GO_STBY   0
 *  05:00   STDBYFSM_SHUNT_ISEL_TGT   0x28
 * </pre>
 */
#define RIPL_STANDBYFSM_CTRL2_ADDR   0x0000005B
#define RIPL_STANDBYFSM_CTRL2_OFFSET 0x0000005B
#define RIPL_STANDBYFSM_CTRL2_INDEX  0x0000005B
#define RIPL_STANDBYFSM_CTRL2_RESET  0x00000028

__INLINE uint8_t ripl_standbyfsm_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR);
}

__INLINE void ripl_standbyfsm_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_STDBYFSM_GO_STBY_BIT           ((uint8_t)0x00000040)
#define RIPL_STDBYFSM_GO_STBY_POS           6
#define RIPL_STDBYFSM_SHUNT_ISEL_TGT_MASK   ((uint8_t)0x0000003F)
#define RIPL_STDBYFSM_SHUNT_ISEL_TGT_LSB    0
#define RIPL_STDBYFSM_SHUNT_ISEL_TGT_WIDTH  ((uint8_t)0x00000006)

#define RIPL_STDBYFSM_GO_STBY_RST           0x0
#define RIPL_STDBYFSM_SHUNT_ISEL_TGT_RST    0x28

__INLINE void ripl_standbyfsm_ctrl2_pack(uint8_t stdbyfsmgostby, uint8_t stdbyfsmshuntiseltgt)
{
    ASSERT_ERR((((uint8_t)stdbyfsmgostby << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmshuntiseltgt << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL2_ADDR,  ((uint8_t)stdbyfsmgostby << 6) | ((uint8_t)stdbyfsmshuntiseltgt << 0));
}

__INLINE void ripl_standbyfsm_ctrl2_unpack(uint8_t* stdbyfsmgostby, uint8_t* stdbyfsmshuntiseltgt)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR);
    *stdbyfsmgostby = (localVal & ((uint8_t)0x00000040)) >> 6;
    *stdbyfsmshuntiseltgt = (localVal & ((uint8_t)0x0000003F)) >> 0;
}

__INLINE uint8_t ripl_stdbyfsm_go_stby_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_stdbyfsm_go_stby_setf(uint8_t stdbyfsmgostby)
{
    ASSERT_ERR((((uint8_t)stdbyfsmgostby << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL2_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)stdbyfsmgostby << 6));
}

__INLINE uint8_t ripl_stdbyfsm_shunt_isel_tgt_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x0000003F)) >> 0);
}

__INLINE void ripl_stdbyfsm_shunt_isel_tgt_setf(uint8_t stdbyfsmshuntiseltgt)
{
    ASSERT_ERR((((uint8_t)stdbyfsmshuntiseltgt << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL2_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL2_ADDR) & ~((uint8_t)0x0000003F)) | ((uint8_t)stdbyfsmshuntiseltgt << 0));
}

/**
 * @brief STANDBYFSM_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   STDBYFSM_R_SHUNT_ISEL_MUX_EN   1
 *  05:00   STDBYFSM_R_SHUNT_ISEL_MUX   0x0
 * </pre>
 */
#define RIPL_STANDBYFSM_CTRL3_ADDR   0x0000005C
#define RIPL_STANDBYFSM_CTRL3_OFFSET 0x0000005C
#define RIPL_STANDBYFSM_CTRL3_INDEX  0x0000005C
#define RIPL_STANDBYFSM_CTRL3_RESET  0x00000040

__INLINE uint8_t ripl_standbyfsm_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR);
}

__INLINE void ripl_standbyfsm_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_EN_BIT    ((uint8_t)0x00000040)
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_EN_POS    6
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_MASK      ((uint8_t)0x0000003F)
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_LSB       0
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_WIDTH     ((uint8_t)0x00000006)

#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_EN_RST    0x1
#define RIPL_STDBYFSM_R_SHUNT_ISEL_MUX_RST       0x0

__INLINE void ripl_standbyfsm_ctrl3_pack(uint8_t stdbyfsmrshuntiselmuxen, uint8_t stdbyfsmrshuntiselmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntiselmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntiselmux << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL3_ADDR,  ((uint8_t)stdbyfsmrshuntiselmuxen << 6) | ((uint8_t)stdbyfsmrshuntiselmux << 0));
}

__INLINE void ripl_standbyfsm_ctrl3_unpack(uint8_t* stdbyfsmrshuntiselmuxen, uint8_t* stdbyfsmrshuntiselmux)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR);
    *stdbyfsmrshuntiselmuxen = (localVal & ((uint8_t)0x00000040)) >> 6;
    *stdbyfsmrshuntiselmux = (localVal & ((uint8_t)0x0000003F)) >> 0;
}

__INLINE uint8_t ripl_stdbyfsm_r_shunt_isel_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_stdbyfsm_r_shunt_isel_mux_en_setf(uint8_t stdbyfsmrshuntiselmuxen)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntiselmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL3_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)stdbyfsmrshuntiselmuxen << 6));
}

__INLINE uint8_t ripl_stdbyfsm_r_shunt_isel_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x0000003F)) >> 0);
}

__INLINE void ripl_stdbyfsm_r_shunt_isel_mux_setf(uint8_t stdbyfsmrshuntiselmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntiselmux << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL3_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL3_ADDR) & ~((uint8_t)0x0000003F)) | ((uint8_t)stdbyfsmrshuntiselmux << 0));
}

/**
 * @brief STANDBYFSM_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   STDBYFSM_R_CLK_RUN_EN_MUX_EN   1
 *     04   STDBYFSM_R_CLK_RUN_EN_MUX   0
 *     03   STDBYFSM_R_STBLDO_PD_MUX_EN   1
 *     02   STDBYFSM_R_STBLDO_PD_MUX   0
 *     01   STDBYFSM_R_SHUNTLDO_PD_MUX_EN   1
 *     00   STDBYFSM_R_SHUNTLDO_PD_MUX   0
 * </pre>
 */
#define RIPL_STANDBYFSM_CTRL4_ADDR   0x0000005D
#define RIPL_STANDBYFSM_CTRL4_OFFSET 0x0000005D
#define RIPL_STANDBYFSM_CTRL4_INDEX  0x0000005D
#define RIPL_STANDBYFSM_CTRL4_RESET  0x0000002A

__INLINE uint8_t ripl_standbyfsm_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
}

__INLINE void ripl_standbyfsm_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_EN_BIT     ((uint8_t)0x00000020)
#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_EN_POS     5
#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_BIT        ((uint8_t)0x00000010)
#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_POS        4
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_EN_BIT      ((uint8_t)0x00000008)
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_EN_POS      3
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_BIT         ((uint8_t)0x00000004)
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_POS         2
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_EN_BIT    ((uint8_t)0x00000002)
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_EN_POS    1
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_BIT       ((uint8_t)0x00000001)
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_POS       0

#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_EN_RST     0x1
#define RIPL_STDBYFSM_R_CLK_RUN_EN_MUX_RST        0x0
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_EN_RST      0x1
#define RIPL_STDBYFSM_R_STBLDO_PD_MUX_RST         0x0
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_EN_RST    0x1
#define RIPL_STDBYFSM_R_SHUNTLDO_PD_MUX_RST       0x0

__INLINE void ripl_standbyfsm_ctrl4_pack(uint8_t stdbyfsmrclkrunenmuxen, uint8_t stdbyfsmrclkrunenmux, uint8_t stdbyfsmrstbldopdmuxen, uint8_t stdbyfsmrstbldopdmux, uint8_t stdbyfsmrshuntldopdmuxen, uint8_t stdbyfsmrshuntldopdmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrclkrunenmuxen << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrclkrunenmux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrstbldopdmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrstbldopdmux << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntldopdmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntldopdmux << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR,  ((uint8_t)stdbyfsmrclkrunenmuxen << 5) | ((uint8_t)stdbyfsmrclkrunenmux << 4) | ((uint8_t)stdbyfsmrstbldopdmuxen << 3) | ((uint8_t)stdbyfsmrstbldopdmux << 2) | ((uint8_t)stdbyfsmrshuntldopdmuxen << 1) | ((uint8_t)stdbyfsmrshuntldopdmux << 0));
}

__INLINE void ripl_standbyfsm_ctrl4_unpack(uint8_t* stdbyfsmrclkrunenmuxen, uint8_t* stdbyfsmrclkrunenmux, uint8_t* stdbyfsmrstbldopdmuxen, uint8_t* stdbyfsmrstbldopdmux, uint8_t* stdbyfsmrshuntldopdmuxen, uint8_t* stdbyfsmrshuntldopdmux)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    *stdbyfsmrclkrunenmuxen = (localVal & ((uint8_t)0x00000020)) >> 5;
    *stdbyfsmrclkrunenmux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *stdbyfsmrstbldopdmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *stdbyfsmrstbldopdmux = (localVal & ((uint8_t)0x00000004)) >> 2;
    *stdbyfsmrshuntldopdmuxen = (localVal & ((uint8_t)0x00000002)) >> 1;
    *stdbyfsmrshuntldopdmux = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_stdbyfsm_r_clk_run_en_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_stdbyfsm_r_clk_run_en_mux_en_setf(uint8_t stdbyfsmrclkrunenmuxen)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrclkrunenmuxen << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)stdbyfsmrclkrunenmuxen << 5));
}

__INLINE uint8_t ripl_stdbyfsm_r_clk_run_en_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_stdbyfsm_r_clk_run_en_mux_setf(uint8_t stdbyfsmrclkrunenmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrclkrunenmux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)stdbyfsmrclkrunenmux << 4));
}

__INLINE uint8_t ripl_stdbyfsm_r_stbldo_pd_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_stdbyfsm_r_stbldo_pd_mux_en_setf(uint8_t stdbyfsmrstbldopdmuxen)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrstbldopdmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)stdbyfsmrstbldopdmuxen << 3));
}

__INLINE uint8_t ripl_stdbyfsm_r_stbldo_pd_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_stdbyfsm_r_stbldo_pd_mux_setf(uint8_t stdbyfsmrstbldopdmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrstbldopdmux << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)stdbyfsmrstbldopdmux << 2));
}

__INLINE uint8_t ripl_stdbyfsm_r_shuntldo_pd_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_stdbyfsm_r_shuntldo_pd_mux_en_setf(uint8_t stdbyfsmrshuntldopdmuxen)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntldopdmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)stdbyfsmrshuntldopdmuxen << 1));
}

__INLINE uint8_t ripl_stdbyfsm_r_shuntldo_pd_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_stdbyfsm_r_shuntldo_pd_mux_setf(uint8_t stdbyfsmrshuntldopdmux)
{
    ASSERT_ERR((((uint8_t)stdbyfsmrshuntldopdmux << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL4_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL4_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)stdbyfsmrshuntldopdmux << 0));
}

/**
 * @brief STANDBYFSM_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06      STDBY_CALI_DONE   0
 *     05      STBLDO_CALIEN3V   0
 *     04   Stbldo_calicode3v_mux_en   0
 *  03:00    StbLdo_calicode3v   0x0
 * </pre>
 */
#define RIPL_STANDBYFSM_CTRL5_ADDR   0x0000005E
#define RIPL_STANDBYFSM_CTRL5_OFFSET 0x0000005E
#define RIPL_STANDBYFSM_CTRL5_INDEX  0x0000005E
#define RIPL_STANDBYFSM_CTRL5_RESET  0x00000000

__INLINE uint8_t ripl_standbyfsm_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
}

__INLINE void ripl_standbyfsm_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL5_ADDR, value);
}

// field definitions
#define RIPL_STDBY_CALI_DONE_BIT              ((uint8_t)0x00000040)
#define RIPL_STDBY_CALI_DONE_POS              6
#define RIPL_STBLDO_CALIEN3V_BIT              ((uint8_t)0x00000020)
#define RIPL_STBLDO_CALIEN3V_POS              5
#define RIPL_STBLDO_CALICODE_3V_MUX_EN_BIT    ((uint8_t)0x00000010)
#define RIPL_STBLDO_CALICODE_3V_MUX_EN_POS    4
#define RIPL_STB_LDO_CALICODE_3V_MASK         ((uint8_t)0x0000000F)
#define RIPL_STB_LDO_CALICODE_3V_LSB          0
#define RIPL_STB_LDO_CALICODE_3V_WIDTH        ((uint8_t)0x00000004)

#define RIPL_STDBY_CALI_DONE_RST              0x0
#define RIPL_STBLDO_CALIEN3V_RST              0x0
#define RIPL_STBLDO_CALICODE_3V_MUX_EN_RST    0x0
#define RIPL_STB_LDO_CALICODE_3V_RST          0x0

__INLINE void ripl_standbyfsm_ctrl5_pack(uint8_t stbldocalien3v, uint8_t stbldocalicode3vmuxen, uint8_t stbldocalicode3v)
{
    ASSERT_ERR((((uint8_t)stbldocalien3v << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)stbldocalicode3vmuxen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)stbldocalicode3v << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL5_ADDR,  ((uint8_t)stbldocalien3v << 5) | ((uint8_t)stbldocalicode3vmuxen << 4) | ((uint8_t)stbldocalicode3v << 0));
}

__INLINE void ripl_standbyfsm_ctrl5_unpack(uint8_t* stdbycalidone, uint8_t* stbldocalien3v, uint8_t* stbldocalicode3vmuxen, uint8_t* stbldocalicode3v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
    *stdbycalidone = (localVal & ((uint8_t)0x00000040)) >> 6;
    *stbldocalien3v = (localVal & ((uint8_t)0x00000020)) >> 5;
    *stbldocalicode3vmuxen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *stbldocalicode3v = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_stdby_cali_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_stbldo_calien3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_stbldo_calien3v_setf(uint8_t stbldocalien3v)
{
    ASSERT_ERR((((uint8_t)stbldocalien3v << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL5_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)stbldocalien3v << 5));
}

__INLINE uint8_t ripl_stbldo_calicode_3v_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_stbldo_calicode_3v_mux_en_setf(uint8_t stbldocalicode3vmuxen)
{
    ASSERT_ERR((((uint8_t)stbldocalicode3vmuxen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL5_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)stbldocalicode3vmuxen << 4));
}

__INLINE uint8_t ripl_stb_ldo_calicode_3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_stb_ldo_calicode_3v_setf(uint8_t stbldocalicode3v)
{
    ASSERT_ERR((((uint8_t)stbldocalicode3v << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_STANDBYFSM_CTRL5_ADDR, (REG_RIPL_RD(RIPL_STANDBYFSM_CTRL5_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)stbldocalicode3v << 0));
}

/**
 * @brief DIGCORE_CLK_GEN_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02   AUDIO_DAC_12M_CLK_EN   0
 *     01   AUDIO_ADC_12M_CLK_EN   0
 *     00      XTAL_SWITCH_SEL   1
 * </pre>
 */
#define RIPL_DIGCORE_CLK_GEN_CTRL_ADDR   0x00000060
#define RIPL_DIGCORE_CLK_GEN_CTRL_OFFSET 0x00000060
#define RIPL_DIGCORE_CLK_GEN_CTRL_INDEX  0x00000060
#define RIPL_DIGCORE_CLK_GEN_CTRL_RESET  0x00000001

__INLINE uint8_t ripl_digcore_clk_gen_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR);
}

__INLINE void ripl_digcore_clk_gen_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR, value);
}

// field definitions
#define RIPL_AUDIO_DAC_12M_CLK_EN_BIT    ((uint8_t)0x00000004)
#define RIPL_AUDIO_DAC_12M_CLK_EN_POS    2
#define RIPL_AUDIO_ADC_12M_CLK_EN_BIT    ((uint8_t)0x00000002)
#define RIPL_AUDIO_ADC_12M_CLK_EN_POS    1
#define RIPL_XTAL_SWITCH_SEL_BIT         ((uint8_t)0x00000001)
#define RIPL_XTAL_SWITCH_SEL_POS         0

#define RIPL_AUDIO_DAC_12M_CLK_EN_RST    0x0
#define RIPL_AUDIO_ADC_12M_CLK_EN_RST    0x0
#define RIPL_XTAL_SWITCH_SEL_RST         0x1

__INLINE void ripl_digcore_clk_gen_ctrl_pack(uint8_t audiodac12mclken, uint8_t audioadc12mclken, uint8_t xtalswitchsel)
{
    ASSERT_ERR((((uint8_t)audiodac12mclken << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)audioadc12mclken << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)xtalswitchsel << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR,  ((uint8_t)audiodac12mclken << 2) | ((uint8_t)audioadc12mclken << 1) | ((uint8_t)xtalswitchsel << 0));
}

__INLINE void ripl_digcore_clk_gen_ctrl_unpack(uint8_t* audiodac12mclken, uint8_t* audioadc12mclken, uint8_t* xtalswitchsel)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR);
    *audiodac12mclken = (localVal & ((uint8_t)0x00000004)) >> 2;
    *audioadc12mclken = (localVal & ((uint8_t)0x00000002)) >> 1;
    *xtalswitchsel = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_audio_dac_12m_clk_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_audio_dac_12m_clk_en_setf(uint8_t audiodac12mclken)
{
    ASSERT_ERR((((uint8_t)audiodac12mclken << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR, (REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)audiodac12mclken << 2));
}

__INLINE uint8_t ripl_audio_adc_12m_clk_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_audio_adc_12m_clk_en_setf(uint8_t audioadc12mclken)
{
    ASSERT_ERR((((uint8_t)audioadc12mclken << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR, (REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)audioadc12mclken << 1));
}

__INLINE uint8_t ripl_xtal_switch_sel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_xtal_switch_sel_setf(uint8_t xtalswitchsel)
{
    ASSERT_ERR((((uint8_t)xtalswitchsel << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR, (REG_RIPL_RD(RIPL_DIGCORE_CLK_GEN_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)xtalswitchsel << 0));
}

/**
 * @brief RST_GEN_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00           I2C_SLV_EN   1
 * </pre>
 */
#define RIPL_RST_GEN_CTRL_ADDR   0x00000065
#define RIPL_RST_GEN_CTRL_OFFSET 0x00000065
#define RIPL_RST_GEN_CTRL_INDEX  0x00000065
#define RIPL_RST_GEN_CTRL_RESET  0x00000001

__INLINE uint8_t ripl_rst_gen_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_RST_GEN_CTRL_ADDR);
}

__INLINE void ripl_rst_gen_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RST_GEN_CTRL_ADDR, value);
}

// field definitions
#define RIPL_I2C_SLV_EN_BIT    ((uint8_t)0x00000001)
#define RIPL_I2C_SLV_EN_POS    0

#define RIPL_I2C_SLV_EN_RST    0x1

__INLINE uint8_t ripl_i2c_slv_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RST_GEN_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_i2c_slv_en_setf(uint8_t i2cslven)
{
    ASSERT_ERR((((uint8_t)i2cslven << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RST_GEN_CTRL_ADDR, (uint8_t)i2cslven << 0);
}

/**
 * @brief MODEM_DEBUG_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00              MDM_TXQ   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL1_ADDR   0x00000070
#define RIPL_MODEM_DEBUG_CTRL1_OFFSET 0x00000070
#define RIPL_MODEM_DEBUG_CTRL1_INDEX  0x00000070
#define RIPL_MODEM_DEBUG_CTRL1_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL1_ADDR);
}

// field definitions
#define RIPL_MDM_TXQ_MASK   ((uint8_t)0x0000003F)
#define RIPL_MDM_TXQ_LSB    0
#define RIPL_MDM_TXQ_WIDTH  ((uint8_t)0x00000006)

#define RIPL_MDM_TXQ_RST    0x0

__INLINE uint8_t ripl_mdm_txq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL1_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

/**
 * @brief MODEM_DEBUG_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00              MDM_TXI   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL2_ADDR   0x00000071
#define RIPL_MODEM_DEBUG_CTRL2_OFFSET 0x00000071
#define RIPL_MODEM_DEBUG_CTRL2_INDEX  0x00000071
#define RIPL_MODEM_DEBUG_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL2_ADDR);
}

// field definitions
#define RIPL_MDM_TXI_MASK   ((uint8_t)0x0000003F)
#define RIPL_MDM_TXI_LSB    0
#define RIPL_MDM_TXI_WIDTH  ((uint8_t)0x00000006)

#define RIPL_MDM_TXI_RST    0x0

__INLINE uint8_t ripl_mdm_txi_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL2_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

/**
 * @brief MODEM_DEBUG_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00              MDM_RXI   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL3_ADDR   0x00000072
#define RIPL_MODEM_DEBUG_CTRL3_OFFSET 0x00000072
#define RIPL_MODEM_DEBUG_CTRL3_INDEX  0x00000072
#define RIPL_MODEM_DEBUG_CTRL3_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL3_ADDR);
}

__INLINE void ripl_modem_debug_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_MODEM_DEBUG_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_MDM_RXI_MASK   ((uint8_t)0x0000003F)
#define RIPL_MDM_RXI_LSB    0
#define RIPL_MDM_RXI_WIDTH  ((uint8_t)0x00000006)

#define RIPL_MDM_RXI_RST    0x0

__INLINE uint8_t ripl_mdm_rxi_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL3_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_mdm_rxi_setf(uint8_t mdmrxi)
{
    ASSERT_ERR((((uint8_t)mdmrxi << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_MODEM_DEBUG_CTRL3_ADDR, (uint8_t)mdmrxi << 0);
}

/**
 * @brief MODEM_DEBUG_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  05:00              MDM_RXQ   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL4_ADDR   0x00000073
#define RIPL_MODEM_DEBUG_CTRL4_OFFSET 0x00000073
#define RIPL_MODEM_DEBUG_CTRL4_INDEX  0x00000073
#define RIPL_MODEM_DEBUG_CTRL4_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL4_ADDR);
}

__INLINE void ripl_modem_debug_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_MODEM_DEBUG_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_MDM_RXQ_MASK   ((uint8_t)0x0000003F)
#define RIPL_MDM_RXQ_LSB    0
#define RIPL_MDM_RXQ_WIDTH  ((uint8_t)0x00000006)

#define RIPL_MDM_RXQ_RST    0x0

__INLINE uint8_t ripl_mdm_rxq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x0000003F)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_mdm_rxq_setf(uint8_t mdmrxq)
{
    ASSERT_ERR((((uint8_t)mdmrxq << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_MODEM_DEBUG_CTRL4_ADDR, (uint8_t)mdmrxq << 0);
}

/**
 * @brief MODEM_DEBUG_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00              MDM_DGP   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL5_ADDR   0x00000074
#define RIPL_MODEM_DEBUG_CTRL5_OFFSET 0x00000074
#define RIPL_MODEM_DEBUG_CTRL5_INDEX  0x00000074
#define RIPL_MODEM_DEBUG_CTRL5_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL5_ADDR);
}

// field definitions
#define RIPL_MDM_DGP_MASK   ((uint8_t)0x000000FF)
#define RIPL_MDM_DGP_LSB    0
#define RIPL_MDM_DGP_WIDTH  ((uint8_t)0x00000008)

#define RIPL_MDM_DGP_RST    0x0

__INLINE uint8_t ripl_mdm_dgp_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL5_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief MODEM_DEBUG_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00             MDM_DGP1   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL6_ADDR   0x00000075
#define RIPL_MODEM_DEBUG_CTRL6_OFFSET 0x00000075
#define RIPL_MODEM_DEBUG_CTRL6_INDEX  0x00000075
#define RIPL_MODEM_DEBUG_CTRL6_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL6_ADDR);
}

// field definitions
#define RIPL_MDM_DGP1_MASK   ((uint8_t)0x000000FF)
#define RIPL_MDM_DGP1_LSB    0
#define RIPL_MDM_DGP1_WIDTH  ((uint8_t)0x00000008)

#define RIPL_MDM_DGP1_RST    0x0

__INLINE uint8_t ripl_mdm_dgp1_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL6_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief MODEM_DEBUG_CTRL7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00             MDM_DGP2   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL7_ADDR   0x00000076
#define RIPL_MODEM_DEBUG_CTRL7_OFFSET 0x00000076
#define RIPL_MODEM_DEBUG_CTRL7_INDEX  0x00000076
#define RIPL_MODEM_DEBUG_CTRL7_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl7_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL7_ADDR);
}

// field definitions
#define RIPL_MDM_DGP2_MASK   ((uint8_t)0x000000FF)
#define RIPL_MDM_DGP2_LSB    0
#define RIPL_MDM_DGP2_WIDTH  ((uint8_t)0x00000008)

#define RIPL_MDM_DGP2_RST    0x0

__INLINE uint8_t ripl_mdm_dgp2_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL7_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief MODEM_DEBUG_CTRL8 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00             MDM_DGP3   0x0
 * </pre>
 */
#define RIPL_MODEM_DEBUG_CTRL8_ADDR   0x00000077
#define RIPL_MODEM_DEBUG_CTRL8_OFFSET 0x00000077
#define RIPL_MODEM_DEBUG_CTRL8_INDEX  0x00000077
#define RIPL_MODEM_DEBUG_CTRL8_RESET  0x00000000

__INLINE uint8_t ripl_modem_debug_ctrl8_get(void)
{
    return REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL8_ADDR);
}

// field definitions
#define RIPL_MDM_DGP3_MASK   ((uint8_t)0x000000FF)
#define RIPL_MDM_DGP3_LSB    0
#define RIPL_MDM_DGP3_WIDTH  ((uint8_t)0x00000008)

#define RIPL_MDM_DGP3_RST    0x0

__INLINE uint8_t ripl_mdm_dgp3_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_MODEM_DEBUG_CTRL8_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief RAMPGEN_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07    TXMIX_GAIN_MUX_EN   1
 *  06:04       TXMIX_GAIN_MUX   0x2
 *     03     TXPA_GAIN_MUX_EN   1
 *  02:00            TXPA_GAIN   0x0
 * </pre>
 */
#define RIPL_RAMPGEN_CTRL1_ADDR   0x0000007A
#define RIPL_RAMPGEN_CTRL1_OFFSET 0x0000007A
#define RIPL_RAMPGEN_CTRL1_INDEX  0x0000007A
#define RIPL_RAMPGEN_CTRL1_RESET  0x000000A8

__INLINE uint8_t ripl_rampgen_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
}

__INLINE void ripl_rampgen_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_TXMIX_GAIN_MUX_EN_BIT    ((uint8_t)0x00000080)
#define RIPL_TXMIX_GAIN_MUX_EN_POS    7
#define RIPL_TXMIX_GAIN_MUX_MASK      ((uint8_t)0x00000070)
#define RIPL_TXMIX_GAIN_MUX_LSB       4
#define RIPL_TXMIX_GAIN_MUX_WIDTH     ((uint8_t)0x00000003)
#define RIPL_TXPA_GAIN_MUX_EN_BIT     ((uint8_t)0x00000008)
#define RIPL_TXPA_GAIN_MUX_EN_POS     3
#define RIPL_TXPA_GAIN_MASK           ((uint8_t)0x00000007)
#define RIPL_TXPA_GAIN_LSB            0
#define RIPL_TXPA_GAIN_WIDTH          ((uint8_t)0x00000003)

#define RIPL_TXMIX_GAIN_MUX_EN_RST    0x1
#define RIPL_TXMIX_GAIN_MUX_RST       0x2
#define RIPL_TXPA_GAIN_MUX_EN_RST     0x1
#define RIPL_TXPA_GAIN_RST            0x0

__INLINE void ripl_rampgen_ctrl1_pack(uint8_t txmixgainmuxen, uint8_t txmixgainmux, uint8_t txpagainmuxen, uint8_t txpagain)
{
    ASSERT_ERR((((uint8_t)txmixgainmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)txmixgainmux << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)txpagainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)txpagain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR,  ((uint8_t)txmixgainmuxen << 7) | ((uint8_t)txmixgainmux << 4) | ((uint8_t)txpagainmuxen << 3) | ((uint8_t)txpagain << 0));
}

__INLINE void ripl_rampgen_ctrl1_unpack(uint8_t* txmixgainmuxen, uint8_t* txmixgainmux, uint8_t* txpagainmuxen, uint8_t* txpagain)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
    *txmixgainmuxen = (localVal & ((uint8_t)0x00000080)) >> 7;
    *txmixgainmux = (localVal & ((uint8_t)0x00000070)) >> 4;
    *txpagainmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *txpagain = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_txmix_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_txmix_gain_mux_en_setf(uint8_t txmixgainmuxen)
{
    ASSERT_ERR((((uint8_t)txmixgainmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)txmixgainmuxen << 7));
}

__INLINE uint8_t ripl_txmix_gain_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_txmix_gain_mux_setf(uint8_t txmixgainmux)
{
    ASSERT_ERR((((uint8_t)txmixgainmux << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)txmixgainmux << 4));
}

__INLINE uint8_t ripl_txpa_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_txpa_gain_mux_en_setf(uint8_t txpagainmuxen)
{
    ASSERT_ERR((((uint8_t)txpagainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)txpagainmuxen << 3));
}

__INLINE uint8_t ripl_txpa_gain_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_txpa_gain_setf(uint8_t txpagain)
{
    ASSERT_ERR((((uint8_t)txpagain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL1_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)txpagain << 0));
}

/**
 * @brief RAMPGEN_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   TX_DACQ_GAIN_MUX_EN   1
 *  06:04         TX_DACQ_GAIN   0x0
 *     03   TX_DACI_GAIN_MUX_EN   1
 *  02:00         TX_DACI_GAIN   0x0
 * </pre>
 */
#define RIPL_RAMPGEN_CTRL2_ADDR   0x0000007B
#define RIPL_RAMPGEN_CTRL2_OFFSET 0x0000007B
#define RIPL_RAMPGEN_CTRL2_INDEX  0x0000007B
#define RIPL_RAMPGEN_CTRL2_RESET  0x00000088

__INLINE uint8_t ripl_rampgen_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
}

__INLINE void ripl_rampgen_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_TX_DACQ_GAIN_MUX_EN_BIT    ((uint8_t)0x00000080)
#define RIPL_TX_DACQ_GAIN_MUX_EN_POS    7
#define RIPL_TX_DACQ_GAIN_MASK          ((uint8_t)0x00000070)
#define RIPL_TX_DACQ_GAIN_LSB           4
#define RIPL_TX_DACQ_GAIN_WIDTH         ((uint8_t)0x00000003)
#define RIPL_TX_DACI_GAIN_MUX_EN_BIT    ((uint8_t)0x00000008)
#define RIPL_TX_DACI_GAIN_MUX_EN_POS    3
#define RIPL_TX_DACI_GAIN_MASK          ((uint8_t)0x00000007)
#define RIPL_TX_DACI_GAIN_LSB           0
#define RIPL_TX_DACI_GAIN_WIDTH         ((uint8_t)0x00000003)

#define RIPL_TX_DACQ_GAIN_MUX_EN_RST    0x1
#define RIPL_TX_DACQ_GAIN_RST           0x0
#define RIPL_TX_DACI_GAIN_MUX_EN_RST    0x1
#define RIPL_TX_DACI_GAIN_RST           0x0

__INLINE void ripl_rampgen_ctrl2_pack(uint8_t txdacqgainmuxen, uint8_t txdacqgain, uint8_t txdacigainmuxen, uint8_t txdacigain)
{
    ASSERT_ERR((((uint8_t)txdacqgainmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)txdacqgain << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)txdacigainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)txdacigain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR,  ((uint8_t)txdacqgainmuxen << 7) | ((uint8_t)txdacqgain << 4) | ((uint8_t)txdacigainmuxen << 3) | ((uint8_t)txdacigain << 0));
}

__INLINE void ripl_rampgen_ctrl2_unpack(uint8_t* txdacqgainmuxen, uint8_t* txdacqgain, uint8_t* txdacigainmuxen, uint8_t* txdacigain)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
    *txdacqgainmuxen = (localVal & ((uint8_t)0x00000080)) >> 7;
    *txdacqgain = (localVal & ((uint8_t)0x00000070)) >> 4;
    *txdacigainmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *txdacigain = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_tx_dacq_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_tx_dacq_gain_mux_en_setf(uint8_t txdacqgainmuxen)
{
    ASSERT_ERR((((uint8_t)txdacqgainmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)txdacqgainmuxen << 7));
}

__INLINE uint8_t ripl_tx_dacq_gain_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_tx_dacq_gain_setf(uint8_t txdacqgain)
{
    ASSERT_ERR((((uint8_t)txdacqgain << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)txdacqgain << 4));
}

__INLINE uint8_t ripl_tx_daci_gain_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_tx_daci_gain_mux_en_setf(uint8_t txdacigainmuxen)
{
    ASSERT_ERR((((uint8_t)txdacigainmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)txdacigainmuxen << 3));
}

__INLINE uint8_t ripl_tx_daci_gain_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_tx_daci_gain_setf(uint8_t txdacigain)
{
    ASSERT_ERR((((uint8_t)txdacigain << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL2_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)txdacigain << 0));
}

/**
 * @brief RAMPGEN_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04      SHUNTLDO_VSEL3V   0x0
 *     03   FILT_GAIN_REG_MUX_EN   0
 *  02:00        FILT_GAIN_REG   0x7
 * </pre>
 */
#define RIPL_RAMPGEN_CTRL3_ADDR   0x0000007C
#define RIPL_RAMPGEN_CTRL3_OFFSET 0x0000007C
#define RIPL_RAMPGEN_CTRL3_INDEX  0x0000007C
#define RIPL_RAMPGEN_CTRL3_RESET  0x00000007

__INLINE uint8_t ripl_rampgen_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR);
}

__INLINE void ripl_rampgen_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_SHUNTLDO_VSEL3V_MASK        ((uint8_t)0x00000070)
#define RIPL_SHUNTLDO_VSEL3V_LSB         4
#define RIPL_SHUNTLDO_VSEL3V_WIDTH       ((uint8_t)0x00000003)
#define RIPL_FILT_GAIN_REG_MUX_EN_BIT    ((uint8_t)0x00000008)
#define RIPL_FILT_GAIN_REG_MUX_EN_POS    3
#define RIPL_FILT_GAIN_REG_MASK          ((uint8_t)0x00000007)
#define RIPL_FILT_GAIN_REG_LSB           0
#define RIPL_FILT_GAIN_REG_WIDTH         ((uint8_t)0x00000003)

#define RIPL_SHUNTLDO_VSEL3V_RST         0x0
#define RIPL_FILT_GAIN_REG_MUX_EN_RST    0x0
#define RIPL_FILT_GAIN_REG_RST           0x7

__INLINE void ripl_rampgen_ctrl3_pack(uint8_t shuntldovsel3v, uint8_t filtgainregmuxen, uint8_t filtgainreg)
{
    ASSERT_ERR((((uint8_t)shuntldovsel3v << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)filtgainregmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)filtgainreg << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL3_ADDR,  ((uint8_t)shuntldovsel3v << 4) | ((uint8_t)filtgainregmuxen << 3) | ((uint8_t)filtgainreg << 0));
}

__INLINE void ripl_rampgen_ctrl3_unpack(uint8_t* shuntldovsel3v, uint8_t* filtgainregmuxen, uint8_t* filtgainreg)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR);
    *shuntldovsel3v = (localVal & ((uint8_t)0x00000070)) >> 4;
    *filtgainregmuxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *filtgainreg = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_shuntldo_vsel3v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_shuntldo_vsel3v_setf(uint8_t shuntldovsel3v)
{
    ASSERT_ERR((((uint8_t)shuntldovsel3v << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)shuntldovsel3v << 4));
}

__INLINE uint8_t ripl_filt_gain_reg_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_filt_gain_reg_mux_en_setf(uint8_t filtgainregmuxen)
{
    ASSERT_ERR((((uint8_t)filtgainregmuxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)filtgainregmuxen << 3));
}

__INLINE uint8_t ripl_filt_gain_reg_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_filt_gain_reg_setf(uint8_t filtgainreg)
{
    ASSERT_ERR((((uint8_t)filtgainreg << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RAMPGEN_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RAMPGEN_CTRL3_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)filtgainreg << 0));
}

/**
 * @brief ANA_ATBSEL_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   ATBSEL_BT_32_MUX_EN   0
 *  06:04         ATBSEL_BT_32   0x0
 *     03   ATBSEL_BT_10_MUX_EN   0
 *  02:00         ATBSEL_BT_10   0x0
 * </pre>
 */
#define RIPL_ANA_ATBSEL_CTRL1_ADDR   0x00000085
#define RIPL_ANA_ATBSEL_CTRL1_OFFSET 0x00000085
#define RIPL_ANA_ATBSEL_CTRL1_INDEX  0x00000085
#define RIPL_ANA_ATBSEL_CTRL1_RESET  0x00000000

__INLINE uint8_t ripl_ana_atbsel_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
}

__INLINE void ripl_ana_atbsel_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_ATBSEL_BT_32_MUX_EN_BIT    ((uint8_t)0x00000080)
#define RIPL_ATBSEL_BT_32_MUX_EN_POS    7
#define RIPL_ATBSEL_BT_32_MASK          ((uint8_t)0x00000070)
#define RIPL_ATBSEL_BT_32_LSB           4
#define RIPL_ATBSEL_BT_32_WIDTH         ((uint8_t)0x00000003)
#define RIPL_ATBSEL_BT_10_MUX_EN_BIT    ((uint8_t)0x00000008)
#define RIPL_ATBSEL_BT_10_MUX_EN_POS    3
#define RIPL_ATBSEL_BT_10_MASK          ((uint8_t)0x00000007)
#define RIPL_ATBSEL_BT_10_LSB           0
#define RIPL_ATBSEL_BT_10_WIDTH         ((uint8_t)0x00000003)

#define RIPL_ATBSEL_BT_32_MUX_EN_RST    0x0
#define RIPL_ATBSEL_BT_32_RST           0x0
#define RIPL_ATBSEL_BT_10_MUX_EN_RST    0x0
#define RIPL_ATBSEL_BT_10_RST           0x0

__INLINE void ripl_ana_atbsel_ctrl1_pack(uint8_t atbselbt32muxen, uint8_t atbselbt32, uint8_t atbselbt10muxen, uint8_t atbselbt10)
{
    ASSERT_ERR((((uint8_t)atbselbt32muxen << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)atbselbt32 << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)atbselbt10muxen << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)atbselbt10 << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR,  ((uint8_t)atbselbt32muxen << 7) | ((uint8_t)atbselbt32 << 4) | ((uint8_t)atbselbt10muxen << 3) | ((uint8_t)atbselbt10 << 0));
}

__INLINE void ripl_ana_atbsel_ctrl1_unpack(uint8_t* atbselbt32muxen, uint8_t* atbselbt32, uint8_t* atbselbt10muxen, uint8_t* atbselbt10)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
    *atbselbt32muxen = (localVal & ((uint8_t)0x00000080)) >> 7;
    *atbselbt32 = (localVal & ((uint8_t)0x00000070)) >> 4;
    *atbselbt10muxen = (localVal & ((uint8_t)0x00000008)) >> 3;
    *atbselbt10 = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_atbsel_bt_32_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_atbsel_bt_32_mux_en_setf(uint8_t atbselbt32muxen)
{
    ASSERT_ERR((((uint8_t)atbselbt32muxen << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)atbselbt32muxen << 7));
}

__INLINE uint8_t ripl_atbsel_bt_32_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_atbsel_bt_32_setf(uint8_t atbselbt32)
{
    ASSERT_ERR((((uint8_t)atbselbt32 << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)atbselbt32 << 4));
}

__INLINE uint8_t ripl_atbsel_bt_10_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_atbsel_bt_10_mux_en_setf(uint8_t atbselbt10muxen)
{
    ASSERT_ERR((((uint8_t)atbselbt10muxen << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)atbselbt10muxen << 3));
}

__INLINE uint8_t ripl_atbsel_bt_10_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_atbsel_bt_10_setf(uint8_t atbselbt10)
{
    ASSERT_ERR((((uint8_t)atbselbt10 << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL1_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)atbselbt10 << 0));
}

/**
 * @brief ANA_ATBSEL_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   Atbsel_bt_en_mux_en   0
 *     00         Atbsel_bt_en   0
 * </pre>
 */
#define RIPL_ANA_ATBSEL_CTRL2_ADDR   0x00000086
#define RIPL_ANA_ATBSEL_CTRL2_OFFSET 0x00000086
#define RIPL_ANA_ATBSEL_CTRL2_INDEX  0x00000086
#define RIPL_ANA_ATBSEL_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_ana_atbsel_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR);
}

__INLINE void ripl_ana_atbsel_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_ATBSEL_BT_EN_MUX_EN_BIT    ((uint8_t)0x00000002)
#define RIPL_ATBSEL_BT_EN_MUX_EN_POS    1
#define RIPL_ATBSEL_BT_EN_BIT           ((uint8_t)0x00000001)
#define RIPL_ATBSEL_BT_EN_POS           0

#define RIPL_ATBSEL_BT_EN_MUX_EN_RST    0x0
#define RIPL_ATBSEL_BT_EN_RST           0x0

__INLINE void ripl_ana_atbsel_ctrl2_pack(uint8_t atbselbtenmuxen, uint8_t atbselbten)
{
    ASSERT_ERR((((uint8_t)atbselbtenmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)atbselbten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL2_ADDR,  ((uint8_t)atbselbtenmuxen << 1) | ((uint8_t)atbselbten << 0));
}

__INLINE void ripl_ana_atbsel_ctrl2_unpack(uint8_t* atbselbtenmuxen, uint8_t* atbselbten)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR);
    *atbselbtenmuxen = (localVal & ((uint8_t)0x00000002)) >> 1;
    *atbselbten = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_atbsel_bt_en_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_atbsel_bt_en_mux_en_setf(uint8_t atbselbtenmuxen)
{
    ASSERT_ERR((((uint8_t)atbselbtenmuxen << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)atbselbtenmuxen << 1));
}

__INLINE uint8_t ripl_atbsel_bt_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_atbsel_bt_en_setf(uint8_t atbselbten)
{
    ASSERT_ERR((((uint8_t)atbselbten << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_ANA_ATBSEL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_ATBSEL_CTRL2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)atbselbten << 0));
}

/**
 * @brief DSP_PINMIX_CONFIG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_PINMUX_CONFIG_3   0x80
 * </pre>
 */
#define RIPL_DSP_PINMIX_CONFIG_3_ADDR   0x00000092
#define RIPL_DSP_PINMIX_CONFIG_3_OFFSET 0x00000092
#define RIPL_DSP_PINMIX_CONFIG_3_INDEX  0x00000092
#define RIPL_DSP_PINMIX_CONFIG_3_RESET  0x00000080

__INLINE uint8_t ripl_dsp_pinmix_config_3_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_3_ADDR);
}

__INLINE void ripl_dsp_pinmix_config_3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_3_ADDR, value);
}

// field definitions
#define RIPL_DSP_PINMUX_CONFIG_3_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_PINMUX_CONFIG_3_LSB    0
#define RIPL_DSP_PINMUX_CONFIG_3_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_PINMUX_CONFIG_3_RST    0x80

__INLINE uint8_t ripl_dsp_pinmux_config_3_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_3_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_pinmux_config_3_setf(uint8_t dsppinmuxconfig3)
{
    ASSERT_ERR((((uint8_t)dsppinmuxconfig3 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_3_ADDR, (uint8_t)dsppinmuxconfig3 << 0);
}

/**
 * @brief DSP_PINMIX_CONFIG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_PINMUX_CONFIG_2   0x0
 * </pre>
 */
#define RIPL_DSP_PINMIX_CONFIG_2_ADDR   0x00000093
#define RIPL_DSP_PINMIX_CONFIG_2_OFFSET 0x00000093
#define RIPL_DSP_PINMIX_CONFIG_2_INDEX  0x00000093
#define RIPL_DSP_PINMIX_CONFIG_2_RESET  0x00000000

__INLINE uint8_t ripl_dsp_pinmix_config_2_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_2_ADDR);
}

__INLINE void ripl_dsp_pinmix_config_2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_2_ADDR, value);
}

// field definitions
#define RIPL_DSP_PINMUX_CONFIG_2_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_PINMUX_CONFIG_2_LSB    0
#define RIPL_DSP_PINMUX_CONFIG_2_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_PINMUX_CONFIG_2_RST    0x0

__INLINE uint8_t ripl_dsp_pinmux_config_2_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_2_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_pinmux_config_2_setf(uint8_t dsppinmuxconfig2)
{
    ASSERT_ERR((((uint8_t)dsppinmuxconfig2 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_2_ADDR, (uint8_t)dsppinmuxconfig2 << 0);
}

/**
 * @brief DSP_PINMIX_CONFIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_PINMUX_CONFIG_1   0xE3
 * </pre>
 */
#define RIPL_DSP_PINMIX_CONFIG_1_ADDR   0x00000094
#define RIPL_DSP_PINMIX_CONFIG_1_OFFSET 0x00000094
#define RIPL_DSP_PINMIX_CONFIG_1_INDEX  0x00000094
#define RIPL_DSP_PINMIX_CONFIG_1_RESET  0x000000E3

__INLINE uint8_t ripl_dsp_pinmix_config_1_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_1_ADDR);
}

__INLINE void ripl_dsp_pinmix_config_1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_1_ADDR, value);
}

// field definitions
#define RIPL_DSP_PINMUX_CONFIG_1_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_PINMUX_CONFIG_1_LSB    0
#define RIPL_DSP_PINMUX_CONFIG_1_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_PINMUX_CONFIG_1_RST    0xE3

__INLINE uint8_t ripl_dsp_pinmux_config_1_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_1_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_pinmux_config_1_setf(uint8_t dsppinmuxconfig1)
{
    ASSERT_ERR((((uint8_t)dsppinmuxconfig1 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_1_ADDR, (uint8_t)dsppinmuxconfig1 << 0);
}

/**
 * @brief DSP_PINMIX_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_PINMUX_CONFIG_0   0xE3
 * </pre>
 */
#define RIPL_DSP_PINMIX_CONFIG_0_ADDR   0x00000095
#define RIPL_DSP_PINMIX_CONFIG_0_OFFSET 0x00000095
#define RIPL_DSP_PINMIX_CONFIG_0_INDEX  0x00000095
#define RIPL_DSP_PINMIX_CONFIG_0_RESET  0x000000E3

__INLINE uint8_t ripl_dsp_pinmix_config_0_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_0_ADDR);
}

__INLINE void ripl_dsp_pinmix_config_0_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_0_ADDR, value);
}

// field definitions
#define RIPL_DSP_PINMUX_CONFIG_0_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_PINMUX_CONFIG_0_LSB    0
#define RIPL_DSP_PINMUX_CONFIG_0_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_PINMUX_CONFIG_0_RST    0xE3

__INLINE uint8_t ripl_dsp_pinmux_config_0_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_PINMIX_CONFIG_0_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_pinmux_config_0_setf(uint8_t dsppinmuxconfig0)
{
    ASSERT_ERR((((uint8_t)dsppinmuxconfig0 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_PINMIX_CONFIG_0_ADDR, (uint8_t)dsppinmuxconfig0 << 0);
}

/**
 * @brief DSP_FILTER_CONFIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_FILTER_CONFIG_1   0x3F
 * </pre>
 */
#define RIPL_DSP_FILTER_CONFIG_1_ADDR   0x00000096
#define RIPL_DSP_FILTER_CONFIG_1_OFFSET 0x00000096
#define RIPL_DSP_FILTER_CONFIG_1_INDEX  0x00000096
#define RIPL_DSP_FILTER_CONFIG_1_RESET  0x0000003F

__INLINE uint8_t ripl_dsp_filter_config_1_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_FILTER_CONFIG_1_ADDR);
}

__INLINE void ripl_dsp_filter_config_1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_FILTER_CONFIG_1_ADDR, value);
}

// field definitions
#define RIPL_DSP_FILTER_CONFIG_1_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_FILTER_CONFIG_1_LSB    0
#define RIPL_DSP_FILTER_CONFIG_1_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_FILTER_CONFIG_1_RST    0x3F

__INLINE uint8_t ripl_dsp_filter_config_1_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_FILTER_CONFIG_1_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_filter_config_1_setf(uint8_t dspfilterconfig1)
{
    ASSERT_ERR((((uint8_t)dspfilterconfig1 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_FILTER_CONFIG_1_ADDR, (uint8_t)dspfilterconfig1 << 0);
}

/**
 * @brief DSP_FILTER_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   DSP_FILTER_CONFIG_0   0xF2
 * </pre>
 */
#define RIPL_DSP_FILTER_CONFIG_0_ADDR   0x00000097
#define RIPL_DSP_FILTER_CONFIG_0_OFFSET 0x00000097
#define RIPL_DSP_FILTER_CONFIG_0_INDEX  0x00000097
#define RIPL_DSP_FILTER_CONFIG_0_RESET  0x000000F2

__INLINE uint8_t ripl_dsp_filter_config_0_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_FILTER_CONFIG_0_ADDR);
}

__INLINE void ripl_dsp_filter_config_0_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_FILTER_CONFIG_0_ADDR, value);
}

// field definitions
#define RIPL_DSP_FILTER_CONFIG_0_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_FILTER_CONFIG_0_LSB    0
#define RIPL_DSP_FILTER_CONFIG_0_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_FILTER_CONFIG_0_RST    0xF2

__INLINE uint8_t ripl_dsp_filter_config_0_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_FILTER_CONFIG_0_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_filter_config_0_setf(uint8_t dspfilterconfig0)
{
    ASSERT_ERR((((uint8_t)dspfilterconfig0 << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_FILTER_CONFIG_0_ADDR, (uint8_t)dspfilterconfig0 << 0);
}

/**
 * @brief DSP_ADC_VOL_LEFT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00     DSP_ADC_VOL_LEFT   0x1A
 * </pre>
 */
#define RIPL_DSP_ADC_VOL_LEFT_ADDR   0x00000098
#define RIPL_DSP_ADC_VOL_LEFT_OFFSET 0x00000098
#define RIPL_DSP_ADC_VOL_LEFT_INDEX  0x00000098
#define RIPL_DSP_ADC_VOL_LEFT_RESET  0x0000001A

__INLINE uint8_t ripl_dsp_adc_vol_left_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_ADC_VOL_LEFT_ADDR);
}

__INLINE void ripl_dsp_adc_vol_left_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_ADC_VOL_LEFT_ADDR, value);
}

// field definitions
#define RIPL_DSP_ADC_VOL_LEFT_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_ADC_VOL_LEFT_LSB    0
#define RIPL_DSP_ADC_VOL_LEFT_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_ADC_VOL_LEFT_RST    0x1A

__INLINE uint8_t ripl_dsp_adc_vol_left_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_ADC_VOL_LEFT_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_adc_vol_left_setf(uint8_t dspadcvolleft)
{
    ASSERT_ERR((((uint8_t)dspadcvolleft << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_ADC_VOL_LEFT_ADDR, (uint8_t)dspadcvolleft << 0);
}

/**
 * @brief DSP_ADC_VOL_RIGHT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00    DSP_ADC_VOL_RIGHT   0x1A
 * </pre>
 */
#define RIPL_DSP_ADC_VOL_RIGHT_ADDR   0x00000099
#define RIPL_DSP_ADC_VOL_RIGHT_OFFSET 0x00000099
#define RIPL_DSP_ADC_VOL_RIGHT_INDEX  0x00000099
#define RIPL_DSP_ADC_VOL_RIGHT_RESET  0x0000001A

__INLINE uint8_t ripl_dsp_adc_vol_right_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_ADC_VOL_RIGHT_ADDR);
}

__INLINE void ripl_dsp_adc_vol_right_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_ADC_VOL_RIGHT_ADDR, value);
}

// field definitions
#define RIPL_DSP_ADC_VOL_RIGHT_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_ADC_VOL_RIGHT_LSB    0
#define RIPL_DSP_ADC_VOL_RIGHT_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_ADC_VOL_RIGHT_RST    0x1A

__INLINE uint8_t ripl_dsp_adc_vol_right_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_ADC_VOL_RIGHT_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_adc_vol_right_setf(uint8_t dspadcvolright)
{
    ASSERT_ERR((((uint8_t)dspadcvolright << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_ADC_VOL_RIGHT_ADDR, (uint8_t)dspadcvolright << 0);
}

/**
 * @brief DSP_DAC_VOL_LEFT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00     DSP_DAC_VOL_LEFT   0x1A
 * </pre>
 */
#define RIPL_DSP_DAC_VOL_LEFT_ADDR   0x0000009A
#define RIPL_DSP_DAC_VOL_LEFT_OFFSET 0x0000009A
#define RIPL_DSP_DAC_VOL_LEFT_INDEX  0x0000009A
#define RIPL_DSP_DAC_VOL_LEFT_RESET  0x0000001A

__INLINE uint8_t ripl_dsp_dac_vol_left_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_DAC_VOL_LEFT_ADDR);
}

__INLINE void ripl_dsp_dac_vol_left_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_DAC_VOL_LEFT_ADDR, value);
}

// field definitions
#define RIPL_DSP_DAC_VOL_LEFT_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_DAC_VOL_LEFT_LSB    0
#define RIPL_DSP_DAC_VOL_LEFT_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_DAC_VOL_LEFT_RST    0x1A

__INLINE uint8_t ripl_dsp_dac_vol_left_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_DAC_VOL_LEFT_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_dac_vol_left_setf(uint8_t dspdacvolleft)
{
    ASSERT_ERR((((uint8_t)dspdacvolleft << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_DAC_VOL_LEFT_ADDR, (uint8_t)dspdacvolleft << 0);
}

/**
 * @brief DSP_DAC_VOL_RIGHT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00    DSP_DAC_VOL_RIGHT   0x1A
 * </pre>
 */
#define RIPL_DSP_DAC_VOL_RIGHT_ADDR   0x0000009B
#define RIPL_DSP_DAC_VOL_RIGHT_OFFSET 0x0000009B
#define RIPL_DSP_DAC_VOL_RIGHT_INDEX  0x0000009B
#define RIPL_DSP_DAC_VOL_RIGHT_RESET  0x0000001A

__INLINE uint8_t ripl_dsp_dac_vol_right_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_DAC_VOL_RIGHT_ADDR);
}

__INLINE void ripl_dsp_dac_vol_right_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_DAC_VOL_RIGHT_ADDR, value);
}

// field definitions
#define RIPL_DSP_DAC_VOL_RIGHT_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_DAC_VOL_RIGHT_LSB    0
#define RIPL_DSP_DAC_VOL_RIGHT_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_DAC_VOL_RIGHT_RST    0x1A

__INLINE uint8_t ripl_dsp_dac_vol_right_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_DAC_VOL_RIGHT_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_dsp_dac_vol_right_setf(uint8_t dspdacvolright)
{
    ASSERT_ERR((((uint8_t)dspdacvolright << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_DSP_DAC_VOL_RIGHT_ADDR, (uint8_t)dspdacvolright << 0);
}

/**
 * @brief DSP_HW_CH_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   CORRECTION_FIFO_EN   1
 *     00           HW_CHAN_EN   1
 * </pre>
 */
#define RIPL_DSP_HW_CH_CTRL_ADDR   0x0000009C
#define RIPL_DSP_HW_CH_CTRL_OFFSET 0x0000009C
#define RIPL_DSP_HW_CH_CTRL_INDEX  0x0000009C
#define RIPL_DSP_HW_CH_CTRL_RESET  0x00000011

__INLINE uint8_t ripl_dsp_hw_ch_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR);
}

__INLINE void ripl_dsp_hw_ch_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_DSP_HW_CH_CTRL_ADDR, value);
}

// field definitions
#define RIPL_CORRECTION_FIFO_EN_BIT    ((uint8_t)0x00000010)
#define RIPL_CORRECTION_FIFO_EN_POS    4
#define RIPL_HW_CHAN_EN_BIT            ((uint8_t)0x00000001)
#define RIPL_HW_CHAN_EN_POS            0

#define RIPL_CORRECTION_FIFO_EN_RST    0x1
#define RIPL_HW_CHAN_EN_RST            0x1

__INLINE void ripl_dsp_hw_ch_ctrl_pack(uint8_t correctionfifoen, uint8_t hwchanen)
{
    ASSERT_ERR((((uint8_t)correctionfifoen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)hwchanen << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_DSP_HW_CH_CTRL_ADDR,  ((uint8_t)correctionfifoen << 4) | ((uint8_t)hwchanen << 0));
}

__INLINE void ripl_dsp_hw_ch_ctrl_unpack(uint8_t* correctionfifoen, uint8_t* hwchanen)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR);
    *correctionfifoen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *hwchanen = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_correction_fifo_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_correction_fifo_en_setf(uint8_t correctionfifoen)
{
    ASSERT_ERR((((uint8_t)correctionfifoen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_DSP_HW_CH_CTRL_ADDR, (REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)correctionfifoen << 4));
}

__INLINE uint8_t ripl_hw_chan_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_hw_chan_en_setf(uint8_t hwchanen)
{
    ASSERT_ERR((((uint8_t)hwchanen << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_DSP_HW_CH_CTRL_ADDR, (REG_RIPL_RD(RIPL_DSP_HW_CH_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)hwchanen << 0));
}

/**
 * @brief DSP_CODEC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00     DSP_CODEC_STATUS   0x0
 * </pre>
 */
#define RIPL_DSP_CODEC_STATUS_ADDR   0x0000009D
#define RIPL_DSP_CODEC_STATUS_OFFSET 0x0000009D
#define RIPL_DSP_CODEC_STATUS_INDEX  0x0000009D
#define RIPL_DSP_CODEC_STATUS_RESET  0x00000000

__INLINE uint8_t ripl_dsp_codec_status_get(void)
{
    return REG_RIPL_RD(RIPL_DSP_CODEC_STATUS_ADDR);
}

// field definitions
#define RIPL_DSP_CODEC_STATUS_MASK   ((uint8_t)0x000000FF)
#define RIPL_DSP_CODEC_STATUS_LSB    0
#define RIPL_DSP_CODEC_STATUS_WIDTH  ((uint8_t)0x00000008)

#define RIPL_DSP_CODEC_STATUS_RST    0x0

__INLINE uint8_t ripl_dsp_codec_status_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_DSP_CODEC_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief POS_NEGE_COUNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07       NEGE_COUNT_CLR   0
 *  06:04           NEGE_COUNT   0x0
 *     03        POS_COUNT_CLR   0
 *  02:00            POS_COUNT   0x0
 * </pre>
 */
#define RIPL_POS_NEGE_COUNT_ADDR   0x000000A3
#define RIPL_POS_NEGE_COUNT_OFFSET 0x000000A3
#define RIPL_POS_NEGE_COUNT_INDEX  0x000000A3
#define RIPL_POS_NEGE_COUNT_RESET  0x00000000

__INLINE uint8_t ripl_pos_nege_count_get(void)
{
    return REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR);
}

__INLINE void ripl_pos_nege_count_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_POS_NEGE_COUNT_ADDR, value);
}

// field definitions
#define RIPL_NEGE_COUNT_CLR_BIT    ((uint8_t)0x00000080)
#define RIPL_NEGE_COUNT_CLR_POS    7
#define RIPL_NEGE_COUNT_MASK       ((uint8_t)0x00000070)
#define RIPL_NEGE_COUNT_LSB        4
#define RIPL_NEGE_COUNT_WIDTH      ((uint8_t)0x00000003)
#define RIPL_POS_COUNT_CLR_BIT     ((uint8_t)0x00000008)
#define RIPL_POS_COUNT_CLR_POS     3
#define RIPL_POS_COUNT_MASK        ((uint8_t)0x00000007)
#define RIPL_POS_COUNT_LSB         0
#define RIPL_POS_COUNT_WIDTH       ((uint8_t)0x00000003)

#define RIPL_NEGE_COUNT_CLR_RST    0x0
#define RIPL_NEGE_COUNT_RST        0x0
#define RIPL_POS_COUNT_CLR_RST     0x0
#define RIPL_POS_COUNT_RST         0x0

__INLINE void ripl_pos_nege_count_pack(uint8_t negecountclr, uint8_t poscountclr)
{
    ASSERT_ERR((((uint8_t)negecountclr << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)poscountclr << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_POS_NEGE_COUNT_ADDR,  ((uint8_t)negecountclr << 7) | ((uint8_t)poscountclr << 3));
}

__INLINE void ripl_pos_nege_count_unpack(uint8_t* negecountclr, uint8_t* negecount, uint8_t* poscountclr, uint8_t* poscount)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR);
    *negecountclr = (localVal & ((uint8_t)0x00000080)) >> 7;
    *negecount = (localVal & ((uint8_t)0x00000070)) >> 4;
    *poscountclr = (localVal & ((uint8_t)0x00000008)) >> 3;
    *poscount = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE void ripl_nege_count_clr_setf(uint8_t negecountclr)
{
    ASSERT_ERR((((uint8_t)negecountclr << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_POS_NEGE_COUNT_ADDR, (REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)negecountclr << 7));
}

__INLINE uint8_t ripl_nege_count_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_pos_count_clr_setf(uint8_t poscountclr)
{
    ASSERT_ERR((((uint8_t)poscountclr << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_POS_NEGE_COUNT_ADDR, (REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)poscountclr << 3));
}

__INLINE uint8_t ripl_pos_count_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_POS_NEGE_COUNT_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

/**
 * @brief INTC_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       POWER_DOWN_IRQ   0
 *     01   SOFTWARE_DET_VOL_DEC   0
 *     00   SOFTWARE_DET_VOL_INC   0
 * </pre>
 */
#define RIPL_INTC_CTRL_ADDR   0x000000A4
#define RIPL_INTC_CTRL_OFFSET 0x000000A4
#define RIPL_INTC_CTRL_INDEX  0x000000A4
#define RIPL_INTC_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_intc_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_CTRL_ADDR);
}

__INLINE void ripl_intc_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_CTRL_ADDR, value);
}

// field definitions
#define RIPL_POWER_DOWN_IRQ_BIT          ((uint8_t)0x00000004)
#define RIPL_POWER_DOWN_IRQ_POS          2
#define RIPL_SOFTWARE_DET_VOL_DEC_BIT    ((uint8_t)0x00000002)
#define RIPL_SOFTWARE_DET_VOL_DEC_POS    1
#define RIPL_SOFTWARE_DET_VOL_INC_BIT    ((uint8_t)0x00000001)
#define RIPL_SOFTWARE_DET_VOL_INC_POS    0

#define RIPL_POWER_DOWN_IRQ_RST          0x0
#define RIPL_SOFTWARE_DET_VOL_DEC_RST    0x0
#define RIPL_SOFTWARE_DET_VOL_INC_RST    0x0

__INLINE void ripl_intc_ctrl_pack(uint8_t powerdownirq, uint8_t softwaredetvoldec, uint8_t softwaredetvolinc)
{
    ASSERT_ERR((((uint8_t)powerdownirq << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)softwaredetvoldec << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)softwaredetvolinc << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CTRL_ADDR,  ((uint8_t)powerdownirq << 2) | ((uint8_t)softwaredetvoldec << 1) | ((uint8_t)softwaredetvolinc << 0));
}

__INLINE void ripl_intc_ctrl_unpack(uint8_t* powerdownirq, uint8_t* softwaredetvoldec, uint8_t* softwaredetvolinc)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CTRL_ADDR);
    *powerdownirq = (localVal & ((uint8_t)0x00000004)) >> 2;
    *softwaredetvoldec = (localVal & ((uint8_t)0x00000002)) >> 1;
    *softwaredetvolinc = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_power_down_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_power_down_irq_setf(uint8_t powerdownirq)
{
    ASSERT_ERR((((uint8_t)powerdownirq << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_CTRL_ADDR, (REG_RIPL_RD(RIPL_INTC_CTRL_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)powerdownirq << 2));
}

__INLINE uint8_t ripl_software_det_vol_dec_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_software_det_vol_dec_setf(uint8_t softwaredetvoldec)
{
    ASSERT_ERR((((uint8_t)softwaredetvoldec << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_CTRL_ADDR, (REG_RIPL_RD(RIPL_INTC_CTRL_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)softwaredetvoldec << 1));
}

__INLINE uint8_t ripl_software_det_vol_inc_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_software_det_vol_inc_setf(uint8_t softwaredetvolinc)
{
    ASSERT_ERR((((uint8_t)softwaredetvolinc << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CTRL_ADDR, (REG_RIPL_RD(RIPL_INTC_CTRL_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)softwaredetvolinc << 0));
}

/**
 * @brief INTC_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07          ADC_DET_IRQ   0
 *     06      RF_PLL_DONE_IRQ   0
 *     05     CHARGER_DONE_IRQ   0
 *     04           USB_ON_IRQ   0
 *     03       ON_OFF_POS_IRQ   0
 *     02      ON_OFF_NEGE_IRQ   0
 *     01          VOL_DEC_IRQ   0
 *     00          VOL_INC_IRQ   0
 * </pre>
 */
#define RIPL_INTC_STATUS0_ADDR   0x000000A5
#define RIPL_INTC_STATUS0_OFFSET 0x000000A5
#define RIPL_INTC_STATUS0_INDEX  0x000000A5
#define RIPL_INTC_STATUS0_RESET  0x00000000

__INLINE uint8_t ripl_intc_status0_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
}

// field definitions
#define RIPL_ADC_DET_IRQ_BIT         ((uint8_t)0x00000080)
#define RIPL_ADC_DET_IRQ_POS         7
#define RIPL_RF_PLL_DONE_IRQ_BIT     ((uint8_t)0x00000040)
#define RIPL_RF_PLL_DONE_IRQ_POS     6
#define RIPL_CHARGER_DONE_IRQ_BIT    ((uint8_t)0x00000020)
#define RIPL_CHARGER_DONE_IRQ_POS    5
#define RIPL_USB_ON_IRQ_BIT          ((uint8_t)0x00000010)
#define RIPL_USB_ON_IRQ_POS          4
#define RIPL_ON_OFF_POS_IRQ_BIT      ((uint8_t)0x00000008)
#define RIPL_ON_OFF_POS_IRQ_POS      3
#define RIPL_ON_OFF_NEGE_IRQ_BIT     ((uint8_t)0x00000004)
#define RIPL_ON_OFF_NEGE_IRQ_POS     2
#define RIPL_VOL_DEC_IRQ_BIT         ((uint8_t)0x00000002)
#define RIPL_VOL_DEC_IRQ_POS         1
#define RIPL_VOL_INC_IRQ_BIT         ((uint8_t)0x00000001)
#define RIPL_VOL_INC_IRQ_POS         0

#define RIPL_ADC_DET_IRQ_RST         0x0
#define RIPL_RF_PLL_DONE_IRQ_RST     0x0
#define RIPL_CHARGER_DONE_IRQ_RST    0x0
#define RIPL_USB_ON_IRQ_RST          0x0
#define RIPL_ON_OFF_POS_IRQ_RST      0x0
#define RIPL_ON_OFF_NEGE_IRQ_RST     0x0
#define RIPL_VOL_DEC_IRQ_RST         0x0
#define RIPL_VOL_INC_IRQ_RST         0x0

__INLINE void ripl_intc_status0_unpack(uint8_t* adcdetirq, uint8_t* rfplldoneirq, uint8_t* chargerdoneirq, uint8_t* usbonirq, uint8_t* onoffposirq, uint8_t* onoffnegeirq, uint8_t* voldecirq, uint8_t* volincirq)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    *adcdetirq = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfplldoneirq = (localVal & ((uint8_t)0x00000040)) >> 6;
    *chargerdoneirq = (localVal & ((uint8_t)0x00000020)) >> 5;
    *usbonirq = (localVal & ((uint8_t)0x00000010)) >> 4;
    *onoffposirq = (localVal & ((uint8_t)0x00000008)) >> 3;
    *onoffnegeirq = (localVal & ((uint8_t)0x00000004)) >> 2;
    *voldecirq = (localVal & ((uint8_t)0x00000002)) >> 1;
    *volincirq = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_adc_det_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_rf_pll_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_charger_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_usb_on_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_on_off_pos_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_on_off_nege_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_vol_dec_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_vol_inc_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_STATUS1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01    BB_PLL_UNLOCK_IRQ   0
 *     00    RF_PLL_UNLOCK_IRQ   0
 * </pre>
 */
#define RIPL_INTC_STATUS1_ADDR   0x000000A6
#define RIPL_INTC_STATUS1_OFFSET 0x000000A6
#define RIPL_INTC_STATUS1_INDEX  0x000000A6
#define RIPL_INTC_STATUS1_RESET  0x00000000

__INLINE uint8_t ripl_intc_status1_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_STATUS1_ADDR);
}

// field definitions
#define RIPL_BB_PLL_UNLOCK_IRQ_BIT    ((uint8_t)0x00000002)
#define RIPL_BB_PLL_UNLOCK_IRQ_POS    1
#define RIPL_RF_PLL_UNLOCK_IRQ_BIT    ((uint8_t)0x00000001)
#define RIPL_RF_PLL_UNLOCK_IRQ_POS    0

#define RIPL_BB_PLL_UNLOCK_IRQ_RST    0x0
#define RIPL_RF_PLL_UNLOCK_IRQ_RST    0x0

__INLINE void ripl_intc_status1_unpack(uint8_t* bbpllunlockirq, uint8_t* rfpllunlockirq)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS1_ADDR);
    *bbpllunlockirq = (localVal & ((uint8_t)0x00000002)) >> 1;
    *rfpllunlockirq = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_bb_pll_unlock_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_rf_pll_unlock_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_STATUS2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07    SAR_ADC7_DONE_IRQ   0
 *     06    SAR_ADC6_DONE_IRQ   0
 *     05    SAR_ADC5_DONE_IRQ   0
 *     04    SAR_ADC4_DONE_IRQ   0
 *     03    SAR_ADC3_DONE_IRQ   0
 *     02    SAR_ADC2_DONE_IRQ   0
 *     01    SAR_ADC1_DONE_IRQ   0
 *     00    SAR_ADC0_DONE_IRQ   0
 * </pre>
 */
#define RIPL_INTC_STATUS2_ADDR   0x000000A7
#define RIPL_INTC_STATUS2_OFFSET 0x000000A7
#define RIPL_INTC_STATUS2_INDEX  0x000000A7
#define RIPL_INTC_STATUS2_RESET  0x00000000

__INLINE uint8_t ripl_intc_status2_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
}

// field definitions
#define RIPL_SAR_ADC7_DONE_IRQ_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC7_DONE_IRQ_POS    7
#define RIPL_SAR_ADC6_DONE_IRQ_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC6_DONE_IRQ_POS    6
#define RIPL_SAR_ADC5_DONE_IRQ_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC5_DONE_IRQ_POS    5
#define RIPL_SAR_ADC4_DONE_IRQ_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC4_DONE_IRQ_POS    4
#define RIPL_SAR_ADC3_DONE_IRQ_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC3_DONE_IRQ_POS    3
#define RIPL_SAR_ADC2_DONE_IRQ_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC2_DONE_IRQ_POS    2
#define RIPL_SAR_ADC1_DONE_IRQ_BIT    ((uint8_t)0x00000002)
#define RIPL_SAR_ADC1_DONE_IRQ_POS    1
#define RIPL_SAR_ADC0_DONE_IRQ_BIT    ((uint8_t)0x00000001)
#define RIPL_SAR_ADC0_DONE_IRQ_POS    0

#define RIPL_SAR_ADC7_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC6_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC5_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC4_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC3_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC2_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC1_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC0_DONE_IRQ_RST    0x0

__INLINE void ripl_intc_status2_unpack(uint8_t* saradc7doneirq, uint8_t* saradc6doneirq, uint8_t* saradc5doneirq, uint8_t* saradc4doneirq, uint8_t* saradc3doneirq, uint8_t* saradc2doneirq, uint8_t* saradc1doneirq, uint8_t* saradc0doneirq)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    *saradc7doneirq = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc6doneirq = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc5doneirq = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc4doneirq = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc3doneirq = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc2doneirq = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc1doneirq = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc0doneirq = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc7_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_sar_adc6_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_sar_adc5_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_sar_adc4_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_sar_adc3_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_sar_adc2_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc1_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_sar_adc0_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_STATUS3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC15_DONE_IRQ   0
 *     06   SAR_ADC14_DONE_IRQ   0
 *     05   SAR_ADC13_DONE_IRQ   0
 *     04   SAR_ADC12_DONE_IRQ   0
 *     03   SAR_ADC11_DONE_IRQ   0
 *     02   SAR_ADC10_DONE_IRQ   0
 *     01    SAR_ADC9_DONE_IRQ   0
 *     00    SAR_ADC8_DONE_IRQ   0
 * </pre>
 */
#define RIPL_INTC_STATUS3_ADDR   0x000000A8
#define RIPL_INTC_STATUS3_OFFSET 0x000000A8
#define RIPL_INTC_STATUS3_INDEX  0x000000A8
#define RIPL_INTC_STATUS3_RESET  0x00000000

__INLINE uint8_t ripl_intc_status3_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
}

// field definitions
#define RIPL_SAR_ADC15_DONE_IRQ_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC15_DONE_IRQ_POS    7
#define RIPL_SAR_ADC14_DONE_IRQ_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC14_DONE_IRQ_POS    6
#define RIPL_SAR_ADC13_DONE_IRQ_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC13_DONE_IRQ_POS    5
#define RIPL_SAR_ADC12_DONE_IRQ_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC12_DONE_IRQ_POS    4
#define RIPL_SAR_ADC11_DONE_IRQ_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC11_DONE_IRQ_POS    3
#define RIPL_SAR_ADC10_DONE_IRQ_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC10_DONE_IRQ_POS    2
#define RIPL_SAR_ADC9_DONE_IRQ_BIT     ((uint8_t)0x00000002)
#define RIPL_SAR_ADC9_DONE_IRQ_POS     1
#define RIPL_SAR_ADC8_DONE_IRQ_BIT     ((uint8_t)0x00000001)
#define RIPL_SAR_ADC8_DONE_IRQ_POS     0

#define RIPL_SAR_ADC15_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC14_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC13_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC12_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC11_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC10_DONE_IRQ_RST    0x0
#define RIPL_SAR_ADC9_DONE_IRQ_RST     0x0
#define RIPL_SAR_ADC8_DONE_IRQ_RST     0x0

__INLINE void ripl_intc_status3_unpack(uint8_t* saradc15doneirq, uint8_t* saradc14doneirq, uint8_t* saradc13doneirq, uint8_t* saradc12doneirq, uint8_t* saradc11doneirq, uint8_t* saradc10doneirq, uint8_t* saradc9doneirq, uint8_t* saradc8doneirq)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    *saradc15doneirq = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc14doneirq = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc13doneirq = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc12doneirq = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc11doneirq = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc10doneirq = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc9doneirq = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc8doneirq = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc15_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_sar_adc14_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_sar_adc13_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_sar_adc12_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_sar_adc11_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_sar_adc10_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc9_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_sar_adc8_done_irq_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_RAW_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07      ADC_DET_IRQ_RAW   0
 *     06   RF_PLL_DONE_IRQ_RAW   0
 *     05   CHARGER_DONE_IRQ_RAW   0
 *     04       USB_ON_IRQ_RAW   0
 *     03   ON_OFF_POS_IRQ_RAW   0
 *     02   ON_OFF_NEGE_IRQ_RAW   0
 *     01      VOL_DEC_IRQ_RAW   0
 *     00      VOL_INC_IRQ_RAW   0
 * </pre>
 */
#define RIPL_INTC_RAW_STATUS0_ADDR   0x000000A9
#define RIPL_INTC_RAW_STATUS0_OFFSET 0x000000A9
#define RIPL_INTC_RAW_STATUS0_INDEX  0x000000A9
#define RIPL_INTC_RAW_STATUS0_RESET  0x00000000

__INLINE uint8_t ripl_intc_raw_status0_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
}

// field definitions
#define RIPL_ADC_DET_IRQ_RAW_BIT         ((uint8_t)0x00000080)
#define RIPL_ADC_DET_IRQ_RAW_POS         7
#define RIPL_RF_PLL_DONE_IRQ_RAW_BIT     ((uint8_t)0x00000040)
#define RIPL_RF_PLL_DONE_IRQ_RAW_POS     6
#define RIPL_CHARGER_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000020)
#define RIPL_CHARGER_DONE_IRQ_RAW_POS    5
#define RIPL_USB_ON_IRQ_RAW_BIT          ((uint8_t)0x00000010)
#define RIPL_USB_ON_IRQ_RAW_POS          4
#define RIPL_ON_OFF_POS_IRQ_RAW_BIT      ((uint8_t)0x00000008)
#define RIPL_ON_OFF_POS_IRQ_RAW_POS      3
#define RIPL_ON_OFF_NEGE_IRQ_RAW_BIT     ((uint8_t)0x00000004)
#define RIPL_ON_OFF_NEGE_IRQ_RAW_POS     2
#define RIPL_VOL_DEC_IRQ_RAW_BIT         ((uint8_t)0x00000002)
#define RIPL_VOL_DEC_IRQ_RAW_POS         1
#define RIPL_VOL_INC_IRQ_RAW_BIT         ((uint8_t)0x00000001)
#define RIPL_VOL_INC_IRQ_RAW_POS         0

#define RIPL_ADC_DET_IRQ_RAW_RST         0x0
#define RIPL_RF_PLL_DONE_IRQ_RAW_RST     0x0
#define RIPL_CHARGER_DONE_IRQ_RAW_RST    0x0
#define RIPL_USB_ON_IRQ_RAW_RST          0x0
#define RIPL_ON_OFF_POS_IRQ_RAW_RST      0x0
#define RIPL_ON_OFF_NEGE_IRQ_RAW_RST     0x0
#define RIPL_VOL_DEC_IRQ_RAW_RST         0x0
#define RIPL_VOL_INC_IRQ_RAW_RST         0x0

__INLINE void ripl_intc_raw_status0_unpack(uint8_t* adcdetirqraw, uint8_t* rfplldoneirqraw, uint8_t* chargerdoneirqraw, uint8_t* usbonirqraw, uint8_t* onoffposirqraw, uint8_t* onoffnegeirqraw, uint8_t* voldecirqraw, uint8_t* volincirqraw)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    *adcdetirqraw = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfplldoneirqraw = (localVal & ((uint8_t)0x00000040)) >> 6;
    *chargerdoneirqraw = (localVal & ((uint8_t)0x00000020)) >> 5;
    *usbonirqraw = (localVal & ((uint8_t)0x00000010)) >> 4;
    *onoffposirqraw = (localVal & ((uint8_t)0x00000008)) >> 3;
    *onoffnegeirqraw = (localVal & ((uint8_t)0x00000004)) >> 2;
    *voldecirqraw = (localVal & ((uint8_t)0x00000002)) >> 1;
    *volincirqraw = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_adc_det_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_rf_pll_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_charger_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_usb_on_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_on_off_pos_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_on_off_nege_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_vol_dec_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_vol_inc_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS0_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_RAW_STATUS1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   BB_PLL_UNLOCK_IRQ_RAW   0
 *     00   RF_PLL_UNLOCK_IRQ_RAW   0
 * </pre>
 */
#define RIPL_INTC_RAW_STATUS1_ADDR   0x000000AA
#define RIPL_INTC_RAW_STATUS1_OFFSET 0x000000AA
#define RIPL_INTC_RAW_STATUS1_INDEX  0x000000AA
#define RIPL_INTC_RAW_STATUS1_RESET  0x00000000

__INLINE uint8_t ripl_intc_raw_status1_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_RAW_STATUS1_ADDR);
}

// field definitions
#define RIPL_BB_PLL_UNLOCK_IRQ_RAW_BIT    ((uint8_t)0x00000002)
#define RIPL_BB_PLL_UNLOCK_IRQ_RAW_POS    1
#define RIPL_RF_PLL_UNLOCK_IRQ_RAW_BIT    ((uint8_t)0x00000001)
#define RIPL_RF_PLL_UNLOCK_IRQ_RAW_POS    0

#define RIPL_BB_PLL_UNLOCK_IRQ_RAW_RST    0x0
#define RIPL_RF_PLL_UNLOCK_IRQ_RAW_RST    0x0

__INLINE void ripl_intc_raw_status1_unpack(uint8_t* bbpllunlockirqraw, uint8_t* rfpllunlockirqraw)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS1_ADDR);
    *bbpllunlockirqraw = (localVal & ((uint8_t)0x00000002)) >> 1;
    *rfpllunlockirqraw = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_bb_pll_unlock_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_rf_pll_unlock_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_RAW_STATUS2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC7_DONE_IRQ_RAW   0
 *     06   SAR_ADC6_DONE_IRQ_RAW   0
 *     05   SAR_ADC5_DONE_IRQ_RAW   0
 *     04   SAR_ADC4_DONE_IRQ_RAW   0
 *     03   SAR_ADC3_DONE_IRQ_RAW   0
 *     02   SAR_ADC2_DONE_IRQ_RAW   0
 *     01   SAR_ADC1_DONE_IRQ_RAW   0
 *     00   SAR_ADC0_DONE_IRQ_RAW   0
 * </pre>
 */
#define RIPL_INTC_RAW_STATUS2_ADDR   0x000000AB
#define RIPL_INTC_RAW_STATUS2_OFFSET 0x000000AB
#define RIPL_INTC_RAW_STATUS2_INDEX  0x000000AB
#define RIPL_INTC_RAW_STATUS2_RESET  0x00000000

__INLINE uint8_t ripl_intc_raw_status2_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
}

// field definitions
#define RIPL_SAR_ADC7_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC7_DONE_IRQ_RAW_POS    7
#define RIPL_SAR_ADC6_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC6_DONE_IRQ_RAW_POS    6
#define RIPL_SAR_ADC5_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC5_DONE_IRQ_RAW_POS    5
#define RIPL_SAR_ADC4_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC4_DONE_IRQ_RAW_POS    4
#define RIPL_SAR_ADC3_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC3_DONE_IRQ_RAW_POS    3
#define RIPL_SAR_ADC2_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC2_DONE_IRQ_RAW_POS    2
#define RIPL_SAR_ADC1_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000002)
#define RIPL_SAR_ADC1_DONE_IRQ_RAW_POS    1
#define RIPL_SAR_ADC0_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000001)
#define RIPL_SAR_ADC0_DONE_IRQ_RAW_POS    0

#define RIPL_SAR_ADC7_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC6_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC5_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC4_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC3_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC2_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC1_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC0_DONE_IRQ_RAW_RST    0x0

__INLINE void ripl_intc_raw_status2_unpack(uint8_t* saradc7doneirqraw, uint8_t* saradc6doneirqraw, uint8_t* saradc5doneirqraw, uint8_t* saradc4doneirqraw, uint8_t* saradc3doneirqraw, uint8_t* saradc2doneirqraw, uint8_t* saradc1doneirqraw, uint8_t* saradc0doneirqraw)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    *saradc7doneirqraw = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc6doneirqraw = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc5doneirqraw = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc4doneirqraw = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc3doneirqraw = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc2doneirqraw = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc1doneirqraw = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc0doneirqraw = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc7_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_sar_adc6_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_sar_adc5_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_sar_adc4_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_sar_adc3_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_sar_adc2_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc1_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_sar_adc0_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_RAW_STATUS3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC15_DONE_IRQ_RAW   0
 *     06   SAR_ADC14_DONE_IRQ_RAW   0
 *     05   SAR_ADC13_DONE_IRQ_RAW   0
 *     04   SAR_ADC12_DONE_IRQ_RAW   0
 *     03   SAR_ADC11_DONE_IRQ_RAW   0
 *     02   SAR_ADC10_DONE_IRQ_RAW   0
 *     01   SAR_ADC9_DONE_IRQ_RAW   0
 *     00   SAR_ADC8_DONE_IRQ_RAW   0
 * </pre>
 */
#define RIPL_INTC_RAW_STATUS3_ADDR   0x000000AC
#define RIPL_INTC_RAW_STATUS3_OFFSET 0x000000AC
#define RIPL_INTC_RAW_STATUS3_INDEX  0x000000AC
#define RIPL_INTC_RAW_STATUS3_RESET  0x00000000

__INLINE uint8_t ripl_intc_raw_status3_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
}

// field definitions
#define RIPL_SAR_ADC15_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC15_DONE_IRQ_RAW_POS    7
#define RIPL_SAR_ADC14_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC14_DONE_IRQ_RAW_POS    6
#define RIPL_SAR_ADC13_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC13_DONE_IRQ_RAW_POS    5
#define RIPL_SAR_ADC12_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC12_DONE_IRQ_RAW_POS    4
#define RIPL_SAR_ADC11_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC11_DONE_IRQ_RAW_POS    3
#define RIPL_SAR_ADC10_DONE_IRQ_RAW_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC10_DONE_IRQ_RAW_POS    2
#define RIPL_SAR_ADC9_DONE_IRQ_RAW_BIT     ((uint8_t)0x00000002)
#define RIPL_SAR_ADC9_DONE_IRQ_RAW_POS     1
#define RIPL_SAR_ADC8_DONE_IRQ_RAW_BIT     ((uint8_t)0x00000001)
#define RIPL_SAR_ADC8_DONE_IRQ_RAW_POS     0

#define RIPL_SAR_ADC15_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC14_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC13_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC12_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC11_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC10_DONE_IRQ_RAW_RST    0x0
#define RIPL_SAR_ADC9_DONE_IRQ_RAW_RST     0x0
#define RIPL_SAR_ADC8_DONE_IRQ_RAW_RST     0x0

__INLINE void ripl_intc_raw_status3_unpack(uint8_t* saradc15doneirqraw, uint8_t* saradc14doneirqraw, uint8_t* saradc13doneirqraw, uint8_t* saradc12doneirqraw, uint8_t* saradc11doneirqraw, uint8_t* saradc10doneirqraw, uint8_t* saradc9doneirqraw, uint8_t* saradc8doneirqraw)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    *saradc15doneirqraw = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc14doneirqraw = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc13doneirqraw = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc12doneirqraw = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc11doneirqraw = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc10doneirqraw = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc9doneirqraw = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc8doneirqraw = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc15_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE uint8_t ripl_sar_adc14_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE uint8_t ripl_sar_adc13_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_sar_adc12_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE uint8_t ripl_sar_adc11_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_sar_adc10_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc9_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE uint8_t ripl_sar_adc8_done_irq_raw_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_RAW_STATUS3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

/**
 * @brief INTC_MASK0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07      ADC_DET_IRQ_MSK   0
 *     06   RF_PLL_DONE_IRQ_MASK   0
 *     05   CHARGER_DONE_IRQ_MASK   0
 *     04       USB_ON_IRQ_MSK   0
 *     03   ON_OFF_POS_IRQ_MSK   0
 *     02   ON_OFF_NEGE_IRQ_MSK   0
 *     01      VOL_DEC_IRQ_MSK   0
 *     00      VOL_INC_IRQ_MSK   0
 * </pre>
 */
#define RIPL_INTC_MASK0_ADDR   0x000000AD
#define RIPL_INTC_MASK0_OFFSET 0x000000AD
#define RIPL_INTC_MASK0_INDEX  0x000000AD
#define RIPL_INTC_MASK0_RESET  0x00000000

__INLINE uint8_t ripl_intc_mask0_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
}

__INLINE void ripl_intc_mask0_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, value);
}

// field definitions
#define RIPL_ADC_DET_IRQ_MSK_BIT          ((uint8_t)0x00000080)
#define RIPL_ADC_DET_IRQ_MSK_POS          7
#define RIPL_RF_PLL_DONE_IRQ_MASK_BIT     ((uint8_t)0x00000040)
#define RIPL_RF_PLL_DONE_IRQ_MASK_POS     6
#define RIPL_CHARGER_DONE_IRQ_MASK_BIT    ((uint8_t)0x00000020)
#define RIPL_CHARGER_DONE_IRQ_MASK_POS    5
#define RIPL_USB_ON_IRQ_MSK_BIT           ((uint8_t)0x00000010)
#define RIPL_USB_ON_IRQ_MSK_POS           4
#define RIPL_ON_OFF_POS_IRQ_MSK_BIT       ((uint8_t)0x00000008)
#define RIPL_ON_OFF_POS_IRQ_MSK_POS       3
#define RIPL_ON_OFF_NEGE_IRQ_MSK_BIT      ((uint8_t)0x00000004)
#define RIPL_ON_OFF_NEGE_IRQ_MSK_POS      2
#define RIPL_VOL_DEC_IRQ_MSK_BIT          ((uint8_t)0x00000002)
#define RIPL_VOL_DEC_IRQ_MSK_POS          1
#define RIPL_VOL_INC_IRQ_MSK_BIT          ((uint8_t)0x00000001)
#define RIPL_VOL_INC_IRQ_MSK_POS          0

#define RIPL_ADC_DET_IRQ_MSK_RST          0x0
#define RIPL_RF_PLL_DONE_IRQ_MASK_RST     0x0
#define RIPL_CHARGER_DONE_IRQ_MASK_RST    0x0
#define RIPL_USB_ON_IRQ_MSK_RST           0x0
#define RIPL_ON_OFF_POS_IRQ_MSK_RST       0x0
#define RIPL_ON_OFF_NEGE_IRQ_MSK_RST      0x0
#define RIPL_VOL_DEC_IRQ_MSK_RST          0x0
#define RIPL_VOL_INC_IRQ_MSK_RST          0x0

__INLINE void ripl_intc_mask0_pack(uint8_t adcdetirqmsk, uint8_t rfplldoneirqmask, uint8_t chargerdoneirqmask, uint8_t usbonirqmsk, uint8_t onoffposirqmsk, uint8_t onoffnegeirqmsk, uint8_t voldecirqmsk, uint8_t volincirqmsk)
{
    ASSERT_ERR((((uint8_t)adcdetirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)rfplldoneirqmask << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)chargerdoneirqmask << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)usbonirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)onoffposirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)onoffnegeirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)voldecirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)volincirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR,  ((uint8_t)adcdetirqmsk << 7) | ((uint8_t)rfplldoneirqmask << 6) | ((uint8_t)chargerdoneirqmask << 5) | ((uint8_t)usbonirqmsk << 4) | ((uint8_t)onoffposirqmsk << 3) | ((uint8_t)onoffnegeirqmsk << 2) | ((uint8_t)voldecirqmsk << 1) | ((uint8_t)volincirqmsk << 0));
}

__INLINE void ripl_intc_mask0_unpack(uint8_t* adcdetirqmsk, uint8_t* rfplldoneirqmask, uint8_t* chargerdoneirqmask, uint8_t* usbonirqmsk, uint8_t* onoffposirqmsk, uint8_t* onoffnegeirqmsk, uint8_t* voldecirqmsk, uint8_t* volincirqmsk)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    *adcdetirqmsk = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfplldoneirqmask = (localVal & ((uint8_t)0x00000040)) >> 6;
    *chargerdoneirqmask = (localVal & ((uint8_t)0x00000020)) >> 5;
    *usbonirqmsk = (localVal & ((uint8_t)0x00000010)) >> 4;
    *onoffposirqmsk = (localVal & ((uint8_t)0x00000008)) >> 3;
    *onoffnegeirqmsk = (localVal & ((uint8_t)0x00000004)) >> 2;
    *voldecirqmsk = (localVal & ((uint8_t)0x00000002)) >> 1;
    *volincirqmsk = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_adc_det_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_adc_det_irq_msk_setf(uint8_t adcdetirqmsk)
{
    ASSERT_ERR((((uint8_t)adcdetirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)adcdetirqmsk << 7));
}

__INLINE uint8_t ripl_rf_pll_done_irq_mask_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rf_pll_done_irq_mask_setf(uint8_t rfplldoneirqmask)
{
    ASSERT_ERR((((uint8_t)rfplldoneirqmask << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rfplldoneirqmask << 6));
}

__INLINE uint8_t ripl_charger_done_irq_mask_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_charger_done_irq_mask_setf(uint8_t chargerdoneirqmask)
{
    ASSERT_ERR((((uint8_t)chargerdoneirqmask << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)chargerdoneirqmask << 5));
}

__INLINE uint8_t ripl_usb_on_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_usb_on_irq_msk_setf(uint8_t usbonirqmsk)
{
    ASSERT_ERR((((uint8_t)usbonirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)usbonirqmsk << 4));
}

__INLINE uint8_t ripl_on_off_pos_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_on_off_pos_irq_msk_setf(uint8_t onoffposirqmsk)
{
    ASSERT_ERR((((uint8_t)onoffposirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)onoffposirqmsk << 3));
}

__INLINE uint8_t ripl_on_off_nege_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_on_off_nege_irq_msk_setf(uint8_t onoffnegeirqmsk)
{
    ASSERT_ERR((((uint8_t)onoffnegeirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)onoffnegeirqmsk << 2));
}

__INLINE uint8_t ripl_vol_dec_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_vol_dec_irq_msk_setf(uint8_t voldecirqmsk)
{
    ASSERT_ERR((((uint8_t)voldecirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)voldecirqmsk << 1));
}

__INLINE uint8_t ripl_vol_inc_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK0_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_vol_inc_irq_msk_setf(uint8_t volincirqmsk)
{
    ASSERT_ERR((((uint8_t)volincirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK0_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK0_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)volincirqmsk << 0));
}

/**
 * @brief INTC_MASK1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   BB_PLL_UNLOCK_IRQ_MSK   0
 *     00   RF_PLL_UNLOCK_IRQ_MSK   0
 * </pre>
 */
#define RIPL_INTC_MASK1_ADDR   0x000000AE
#define RIPL_INTC_MASK1_OFFSET 0x000000AE
#define RIPL_INTC_MASK1_INDEX  0x000000AE
#define RIPL_INTC_MASK1_RESET  0x00000000

__INLINE uint8_t ripl_intc_mask1_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_MASK1_ADDR);
}

__INLINE void ripl_intc_mask1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_MASK1_ADDR, value);
}

// field definitions
#define RIPL_BB_PLL_UNLOCK_IRQ_MSK_BIT    ((uint8_t)0x00000002)
#define RIPL_BB_PLL_UNLOCK_IRQ_MSK_POS    1
#define RIPL_RF_PLL_UNLOCK_IRQ_MSK_BIT    ((uint8_t)0x00000001)
#define RIPL_RF_PLL_UNLOCK_IRQ_MSK_POS    0

#define RIPL_BB_PLL_UNLOCK_IRQ_MSK_RST    0x0
#define RIPL_RF_PLL_UNLOCK_IRQ_MSK_RST    0x0

__INLINE void ripl_intc_mask1_pack(uint8_t bbpllunlockirqmsk, uint8_t rfpllunlockirqmsk)
{
    ASSERT_ERR((((uint8_t)bbpllunlockirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)rfpllunlockirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK1_ADDR,  ((uint8_t)bbpllunlockirqmsk << 1) | ((uint8_t)rfpllunlockirqmsk << 0));
}

__INLINE void ripl_intc_mask1_unpack(uint8_t* bbpllunlockirqmsk, uint8_t* rfpllunlockirqmsk)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK1_ADDR);
    *bbpllunlockirqmsk = (localVal & ((uint8_t)0x00000002)) >> 1;
    *rfpllunlockirqmsk = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_bb_pll_unlock_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_bb_pll_unlock_irq_msk_setf(uint8_t bbpllunlockirqmsk)
{
    ASSERT_ERR((((uint8_t)bbpllunlockirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK1_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)bbpllunlockirqmsk << 1));
}

__INLINE uint8_t ripl_rf_pll_unlock_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_rf_pll_unlock_irq_msk_setf(uint8_t rfpllunlockirqmsk)
{
    ASSERT_ERR((((uint8_t)rfpllunlockirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK1_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)rfpllunlockirqmsk << 0));
}

/**
 * @brief INTC_MASK2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC7_DONE_IRQ_MSK   0
 *     06   SAR_ADC6_DONE_IRQ_MSK   0
 *     05   SAR_ADC5_DONE_IRQ_MSK   0
 *     04   SAR_ADC4_DONE_IRQ_MSK   0
 *     03   SAR_ADC3_DONE_IRQ_MSK   0
 *     02   SAR_ADC2_DONE_IRQ_MSK   0
 *     01   SAR_ADC1_DONE_IRQ_MSK   0
 *     00   SAR_ADC0_DONE_IRQ_MSK   0
 * </pre>
 */
#define RIPL_INTC_MASK2_ADDR   0x000000AF
#define RIPL_INTC_MASK2_OFFSET 0x000000AF
#define RIPL_INTC_MASK2_INDEX  0x000000AF
#define RIPL_INTC_MASK2_RESET  0x00000000

__INLINE uint8_t ripl_intc_mask2_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
}

__INLINE void ripl_intc_mask2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, value);
}

// field definitions
#define RIPL_SAR_ADC7_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC7_DONE_IRQ_MSK_POS    7
#define RIPL_SAR_ADC6_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC6_DONE_IRQ_MSK_POS    6
#define RIPL_SAR_ADC5_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC5_DONE_IRQ_MSK_POS    5
#define RIPL_SAR_ADC4_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC4_DONE_IRQ_MSK_POS    4
#define RIPL_SAR_ADC3_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC3_DONE_IRQ_MSK_POS    3
#define RIPL_SAR_ADC2_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC2_DONE_IRQ_MSK_POS    2
#define RIPL_SAR_ADC1_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000002)
#define RIPL_SAR_ADC1_DONE_IRQ_MSK_POS    1
#define RIPL_SAR_ADC0_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000001)
#define RIPL_SAR_ADC0_DONE_IRQ_MSK_POS    0

#define RIPL_SAR_ADC7_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC6_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC5_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC4_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC3_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC2_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC1_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC0_DONE_IRQ_MSK_RST    0x0

__INLINE void ripl_intc_mask2_pack(uint8_t saradc7doneirqmsk, uint8_t saradc6doneirqmsk, uint8_t saradc5doneirqmsk, uint8_t saradc4doneirqmsk, uint8_t saradc3doneirqmsk, uint8_t saradc2doneirqmsk, uint8_t saradc1doneirqmsk, uint8_t saradc0doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc7doneirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)saradc6doneirqmsk << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)saradc5doneirqmsk << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)saradc4doneirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)saradc3doneirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)saradc2doneirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)saradc1doneirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)saradc0doneirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR,  ((uint8_t)saradc7doneirqmsk << 7) | ((uint8_t)saradc6doneirqmsk << 6) | ((uint8_t)saradc5doneirqmsk << 5) | ((uint8_t)saradc4doneirqmsk << 4) | ((uint8_t)saradc3doneirqmsk << 3) | ((uint8_t)saradc2doneirqmsk << 2) | ((uint8_t)saradc1doneirqmsk << 1) | ((uint8_t)saradc0doneirqmsk << 0));
}

__INLINE void ripl_intc_mask2_unpack(uint8_t* saradc7doneirqmsk, uint8_t* saradc6doneirqmsk, uint8_t* saradc5doneirqmsk, uint8_t* saradc4doneirqmsk, uint8_t* saradc3doneirqmsk, uint8_t* saradc2doneirqmsk, uint8_t* saradc1doneirqmsk, uint8_t* saradc0doneirqmsk)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    *saradc7doneirqmsk = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc6doneirqmsk = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc5doneirqmsk = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc4doneirqmsk = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc3doneirqmsk = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc2doneirqmsk = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc1doneirqmsk = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc0doneirqmsk = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc7_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_sar_adc7_done_irq_msk_setf(uint8_t saradc7doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc7doneirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)saradc7doneirqmsk << 7));
}

__INLINE uint8_t ripl_sar_adc6_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_sar_adc6_done_irq_msk_setf(uint8_t saradc6doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc6doneirqmsk << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)saradc6doneirqmsk << 6));
}

__INLINE uint8_t ripl_sar_adc5_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_sar_adc5_done_irq_msk_setf(uint8_t saradc5doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc5doneirqmsk << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)saradc5doneirqmsk << 5));
}

__INLINE uint8_t ripl_sar_adc4_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_sar_adc4_done_irq_msk_setf(uint8_t saradc4doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc4doneirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)saradc4doneirqmsk << 4));
}

__INLINE uint8_t ripl_sar_adc3_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_sar_adc3_done_irq_msk_setf(uint8_t saradc3doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc3doneirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)saradc3doneirqmsk << 3));
}

__INLINE uint8_t ripl_sar_adc2_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_sar_adc2_done_irq_msk_setf(uint8_t saradc2doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc2doneirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)saradc2doneirqmsk << 2));
}

__INLINE uint8_t ripl_sar_adc1_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sar_adc1_done_irq_msk_setf(uint8_t saradc1doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc1doneirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)saradc1doneirqmsk << 1));
}

__INLINE uint8_t ripl_sar_adc0_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_sar_adc0_done_irq_msk_setf(uint8_t saradc0doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc0doneirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK2_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)saradc0doneirqmsk << 0));
}

/**
 * @brief INTC_MASK3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC15_DONE_IRQ_MSK   0
 *     06   SAR_ADC14_DONE_IRQ_MSK   0
 *     05   SAR_ADC13_DONE_IRQ_MSK   0
 *     04   SAR_ADC12_DONE_IRQ_MSK   0
 *     03   SAR_ADC11_DONE_IRQ_MSK   0
 *     02   SAR_ADC10_DONE_IRQ_MSK   0
 *     01   SAR_ADC9_DONE_IRQ_MSK   0
 *     00   SAR_ADC8_DONE_IRQ_MSK   0
 * </pre>
 */
#define RIPL_INTC_MASK3_ADDR   0x000000B0
#define RIPL_INTC_MASK3_OFFSET 0x000000B0
#define RIPL_INTC_MASK3_INDEX  0x000000B0
#define RIPL_INTC_MASK3_RESET  0x00000000

__INLINE uint8_t ripl_intc_mask3_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
}

__INLINE void ripl_intc_mask3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, value);
}

// field definitions
#define RIPL_SAR_ADC15_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC15_DONE_IRQ_MSK_POS    7
#define RIPL_SAR_ADC14_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC14_DONE_IRQ_MSK_POS    6
#define RIPL_SAR_ADC13_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC13_DONE_IRQ_MSK_POS    5
#define RIPL_SAR_ADC12_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC12_DONE_IRQ_MSK_POS    4
#define RIPL_SAR_ADC11_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC11_DONE_IRQ_MSK_POS    3
#define RIPL_SAR_ADC10_DONE_IRQ_MSK_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC10_DONE_IRQ_MSK_POS    2
#define RIPL_SAR_ADC9_DONE_IRQ_MSK_BIT     ((uint8_t)0x00000002)
#define RIPL_SAR_ADC9_DONE_IRQ_MSK_POS     1
#define RIPL_SAR_ADC8_DONE_IRQ_MSK_BIT     ((uint8_t)0x00000001)
#define RIPL_SAR_ADC8_DONE_IRQ_MSK_POS     0

#define RIPL_SAR_ADC15_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC14_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC13_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC12_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC11_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC10_DONE_IRQ_MSK_RST    0x0
#define RIPL_SAR_ADC9_DONE_IRQ_MSK_RST     0x0
#define RIPL_SAR_ADC8_DONE_IRQ_MSK_RST     0x0

__INLINE void ripl_intc_mask3_pack(uint8_t saradc15doneirqmsk, uint8_t saradc14doneirqmsk, uint8_t saradc13doneirqmsk, uint8_t saradc12doneirqmsk, uint8_t saradc11doneirqmsk, uint8_t saradc10doneirqmsk, uint8_t saradc9doneirqmsk, uint8_t saradc8doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc15doneirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)saradc14doneirqmsk << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)saradc13doneirqmsk << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)saradc12doneirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)saradc11doneirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)saradc10doneirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)saradc9doneirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)saradc8doneirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR,  ((uint8_t)saradc15doneirqmsk << 7) | ((uint8_t)saradc14doneirqmsk << 6) | ((uint8_t)saradc13doneirqmsk << 5) | ((uint8_t)saradc12doneirqmsk << 4) | ((uint8_t)saradc11doneirqmsk << 3) | ((uint8_t)saradc10doneirqmsk << 2) | ((uint8_t)saradc9doneirqmsk << 1) | ((uint8_t)saradc8doneirqmsk << 0));
}

__INLINE void ripl_intc_mask3_unpack(uint8_t* saradc15doneirqmsk, uint8_t* saradc14doneirqmsk, uint8_t* saradc13doneirqmsk, uint8_t* saradc12doneirqmsk, uint8_t* saradc11doneirqmsk, uint8_t* saradc10doneirqmsk, uint8_t* saradc9doneirqmsk, uint8_t* saradc8doneirqmsk)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    *saradc15doneirqmsk = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc14doneirqmsk = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc13doneirqmsk = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc12doneirqmsk = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc11doneirqmsk = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc10doneirqmsk = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc9doneirqmsk = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc8doneirqmsk = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc15_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_sar_adc15_done_irq_msk_setf(uint8_t saradc15doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc15doneirqmsk << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)saradc15doneirqmsk << 7));
}

__INLINE uint8_t ripl_sar_adc14_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_sar_adc14_done_irq_msk_setf(uint8_t saradc14doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc14doneirqmsk << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)saradc14doneirqmsk << 6));
}

__INLINE uint8_t ripl_sar_adc13_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_sar_adc13_done_irq_msk_setf(uint8_t saradc13doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc13doneirqmsk << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)saradc13doneirqmsk << 5));
}

__INLINE uint8_t ripl_sar_adc12_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_sar_adc12_done_irq_msk_setf(uint8_t saradc12doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc12doneirqmsk << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)saradc12doneirqmsk << 4));
}

__INLINE uint8_t ripl_sar_adc11_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_sar_adc11_done_irq_msk_setf(uint8_t saradc11doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc11doneirqmsk << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)saradc11doneirqmsk << 3));
}

__INLINE uint8_t ripl_sar_adc10_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_sar_adc10_done_irq_msk_setf(uint8_t saradc10doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc10doneirqmsk << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)saradc10doneirqmsk << 2));
}

__INLINE uint8_t ripl_sar_adc9_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sar_adc9_done_irq_msk_setf(uint8_t saradc9doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc9doneirqmsk << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)saradc9doneirqmsk << 1));
}

__INLINE uint8_t ripl_sar_adc8_done_irq_msk_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_MASK3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_sar_adc8_done_irq_msk_setf(uint8_t saradc8doneirqmsk)
{
    ASSERT_ERR((((uint8_t)saradc8doneirqmsk << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_MASK3_ADDR, (REG_RIPL_RD(RIPL_INTC_MASK3_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)saradc8doneirqmsk << 0));
}

/**
 * @brief INTC_CLR0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07      ADC_DET_IRQ_CLR   0
 *     06   RF_PLL_DONE_IRQ_CLR   0
 *     05   CHARGER_DONE_IRQ_CLR   0
 *     04       USB_ON_IRQ_CLR   0
 *     03   ON_OFF_POS_IRQ_CLR   0
 *     02   ON_OFF_NEGE_IRQ_CLR   0
 *     01      VOL_DEC_IRQ_CLR   0
 *     00      VOL_INC_IRQ_CLR   0
 * </pre>
 */
#define RIPL_INTC_CLR0_ADDR   0x000000B1
#define RIPL_INTC_CLR0_OFFSET 0x000000B1
#define RIPL_INTC_CLR0_INDEX  0x000000B1
#define RIPL_INTC_CLR0_RESET  0x00000000

__INLINE uint8_t ripl_intc_clr0_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
}

__INLINE void ripl_intc_clr0_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, value);
}

// field definitions
#define RIPL_ADC_DET_IRQ_CLR_BIT         ((uint8_t)0x00000080)
#define RIPL_ADC_DET_IRQ_CLR_POS         7
#define RIPL_RF_PLL_DONE_IRQ_CLR_BIT     ((uint8_t)0x00000040)
#define RIPL_RF_PLL_DONE_IRQ_CLR_POS     6
#define RIPL_CHARGER_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000020)
#define RIPL_CHARGER_DONE_IRQ_CLR_POS    5
#define RIPL_USB_ON_IRQ_CLR_BIT          ((uint8_t)0x00000010)
#define RIPL_USB_ON_IRQ_CLR_POS          4
#define RIPL_ON_OFF_POS_IRQ_CLR_BIT      ((uint8_t)0x00000008)
#define RIPL_ON_OFF_POS_IRQ_CLR_POS      3
#define RIPL_ON_OFF_NEGE_IRQ_CLR_BIT     ((uint8_t)0x00000004)
#define RIPL_ON_OFF_NEGE_IRQ_CLR_POS     2
#define RIPL_VOL_DEC_IRQ_CLR_BIT         ((uint8_t)0x00000002)
#define RIPL_VOL_DEC_IRQ_CLR_POS         1
#define RIPL_VOL_INC_IRQ_CLR_BIT         ((uint8_t)0x00000001)
#define RIPL_VOL_INC_IRQ_CLR_POS         0

#define RIPL_ADC_DET_IRQ_CLR_RST         0x0
#define RIPL_RF_PLL_DONE_IRQ_CLR_RST     0x0
#define RIPL_CHARGER_DONE_IRQ_CLR_RST    0x0
#define RIPL_USB_ON_IRQ_CLR_RST          0x0
#define RIPL_ON_OFF_POS_IRQ_CLR_RST      0x0
#define RIPL_ON_OFF_NEGE_IRQ_CLR_RST     0x0
#define RIPL_VOL_DEC_IRQ_CLR_RST         0x0
#define RIPL_VOL_INC_IRQ_CLR_RST         0x0

__INLINE void ripl_intc_clr0_pack(uint8_t adcdetirqclr, uint8_t rfplldoneirqclr, uint8_t chargerdoneirqclr, uint8_t usbonirqclr, uint8_t onoffposirqclr, uint8_t onoffnegeirqclr, uint8_t voldecirqclr, uint8_t volincirqclr)
{
    ASSERT_ERR((((uint8_t)adcdetirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)rfplldoneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)chargerdoneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)usbonirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)onoffposirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)onoffnegeirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)voldecirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)volincirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR,  ((uint8_t)adcdetirqclr << 7) | ((uint8_t)rfplldoneirqclr << 6) | ((uint8_t)chargerdoneirqclr << 5) | ((uint8_t)usbonirqclr << 4) | ((uint8_t)onoffposirqclr << 3) | ((uint8_t)onoffnegeirqclr << 2) | ((uint8_t)voldecirqclr << 1) | ((uint8_t)volincirqclr << 0));
}

__INLINE void ripl_intc_clr0_unpack(uint8_t* adcdetirqclr, uint8_t* rfplldoneirqclr, uint8_t* chargerdoneirqclr, uint8_t* usbonirqclr, uint8_t* onoffposirqclr, uint8_t* onoffnegeirqclr, uint8_t* voldecirqclr, uint8_t* volincirqclr)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    *adcdetirqclr = (localVal & ((uint8_t)0x00000080)) >> 7;
    *rfplldoneirqclr = (localVal & ((uint8_t)0x00000040)) >> 6;
    *chargerdoneirqclr = (localVal & ((uint8_t)0x00000020)) >> 5;
    *usbonirqclr = (localVal & ((uint8_t)0x00000010)) >> 4;
    *onoffposirqclr = (localVal & ((uint8_t)0x00000008)) >> 3;
    *onoffnegeirqclr = (localVal & ((uint8_t)0x00000004)) >> 2;
    *voldecirqclr = (localVal & ((uint8_t)0x00000002)) >> 1;
    *volincirqclr = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_adc_det_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_adc_det_irq_clr_setf(uint8_t adcdetirqclr)
{
    ASSERT_ERR((((uint8_t)adcdetirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)adcdetirqclr << 7));
}

__INLINE uint8_t ripl_rf_pll_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rf_pll_done_irq_clr_setf(uint8_t rfplldoneirqclr)
{
    ASSERT_ERR((((uint8_t)rfplldoneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rfplldoneirqclr << 6));
}

__INLINE uint8_t ripl_charger_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_charger_done_irq_clr_setf(uint8_t chargerdoneirqclr)
{
    ASSERT_ERR((((uint8_t)chargerdoneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)chargerdoneirqclr << 5));
}

__INLINE uint8_t ripl_usb_on_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_usb_on_irq_clr_setf(uint8_t usbonirqclr)
{
    ASSERT_ERR((((uint8_t)usbonirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)usbonirqclr << 4));
}

__INLINE uint8_t ripl_on_off_pos_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_on_off_pos_irq_clr_setf(uint8_t onoffposirqclr)
{
    ASSERT_ERR((((uint8_t)onoffposirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)onoffposirqclr << 3));
}

__INLINE uint8_t ripl_on_off_nege_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_on_off_nege_irq_clr_setf(uint8_t onoffnegeirqclr)
{
    ASSERT_ERR((((uint8_t)onoffnegeirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)onoffnegeirqclr << 2));
}

__INLINE uint8_t ripl_vol_dec_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_vol_dec_irq_clr_setf(uint8_t voldecirqclr)
{
    ASSERT_ERR((((uint8_t)voldecirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)voldecirqclr << 1));
}

__INLINE uint8_t ripl_vol_inc_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR0_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_vol_inc_irq_clr_setf(uint8_t volincirqclr)
{
    ASSERT_ERR((((uint8_t)volincirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR0_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR0_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)volincirqclr << 0));
}

/**
 * @brief INTC_CLR1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   BB_PLL_UNLOCK_IRQ_CLR   0
 *     00   RF_PLL_UNLOCK_IRQ_CLR   0
 * </pre>
 */
#define RIPL_INTC_CLR1_ADDR   0x000000B2
#define RIPL_INTC_CLR1_OFFSET 0x000000B2
#define RIPL_INTC_CLR1_INDEX  0x000000B2
#define RIPL_INTC_CLR1_RESET  0x00000000

__INLINE uint8_t ripl_intc_clr1_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_CLR1_ADDR);
}

__INLINE void ripl_intc_clr1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_CLR1_ADDR, value);
}

// field definitions
#define RIPL_BB_PLL_UNLOCK_IRQ_CLR_BIT    ((uint8_t)0x00000002)
#define RIPL_BB_PLL_UNLOCK_IRQ_CLR_POS    1
#define RIPL_RF_PLL_UNLOCK_IRQ_CLR_BIT    ((uint8_t)0x00000001)
#define RIPL_RF_PLL_UNLOCK_IRQ_CLR_POS    0

#define RIPL_BB_PLL_UNLOCK_IRQ_CLR_RST    0x0
#define RIPL_RF_PLL_UNLOCK_IRQ_CLR_RST    0x0

__INLINE void ripl_intc_clr1_pack(uint8_t bbpllunlockirqclr, uint8_t rfpllunlockirqclr)
{
    ASSERT_ERR((((uint8_t)bbpllunlockirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)rfpllunlockirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR1_ADDR,  ((uint8_t)bbpllunlockirqclr << 1) | ((uint8_t)rfpllunlockirqclr << 0));
}

__INLINE void ripl_intc_clr1_unpack(uint8_t* bbpllunlockirqclr, uint8_t* rfpllunlockirqclr)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR1_ADDR);
    *bbpllunlockirqclr = (localVal & ((uint8_t)0x00000002)) >> 1;
    *rfpllunlockirqclr = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_bb_pll_unlock_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_bb_pll_unlock_irq_clr_setf(uint8_t bbpllunlockirqclr)
{
    ASSERT_ERR((((uint8_t)bbpllunlockirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR1_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)bbpllunlockirqclr << 1));
}

__INLINE uint8_t ripl_rf_pll_unlock_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_rf_pll_unlock_irq_clr_setf(uint8_t rfpllunlockirqclr)
{
    ASSERT_ERR((((uint8_t)rfpllunlockirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR1_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)rfpllunlockirqclr << 0));
}

/**
 * @brief INTC_CLR2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC7_DONE_IRQ_CLR   0
 *     06   SAR_ADC6_DONE_IRQ_CLR   0
 *     05   SAR_ADC5_DONE_IRQ_CLR   0
 *     04   SAR_ADC4_DONE_IRQ_CLR   0
 *     03   SAR_ADC3_DONE_IRQ_CLR   0
 *     02   SAR_ADC2_DONE_IRQ_CLR   0
 *     01   SAR_ADC1_DONE_IRQ_CLR   0
 *     00   SAR_ADC0_DONE_IRQ_CLR   0
 * </pre>
 */
#define RIPL_INTC_CLR2_ADDR   0x000000B3
#define RIPL_INTC_CLR2_OFFSET 0x000000B3
#define RIPL_INTC_CLR2_INDEX  0x000000B3
#define RIPL_INTC_CLR2_RESET  0x00000000

__INLINE uint8_t ripl_intc_clr2_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
}

__INLINE void ripl_intc_clr2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, value);
}

// field definitions
#define RIPL_SAR_ADC7_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC7_DONE_IRQ_CLR_POS    7
#define RIPL_SAR_ADC6_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC6_DONE_IRQ_CLR_POS    6
#define RIPL_SAR_ADC5_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC5_DONE_IRQ_CLR_POS    5
#define RIPL_SAR_ADC4_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC4_DONE_IRQ_CLR_POS    4
#define RIPL_SAR_ADC3_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC3_DONE_IRQ_CLR_POS    3
#define RIPL_SAR_ADC2_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC2_DONE_IRQ_CLR_POS    2
#define RIPL_SAR_ADC1_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000002)
#define RIPL_SAR_ADC1_DONE_IRQ_CLR_POS    1
#define RIPL_SAR_ADC0_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000001)
#define RIPL_SAR_ADC0_DONE_IRQ_CLR_POS    0

#define RIPL_SAR_ADC7_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC6_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC5_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC4_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC3_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC2_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC1_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC0_DONE_IRQ_CLR_RST    0x0

__INLINE void ripl_intc_clr2_pack(uint8_t saradc7doneirqclr, uint8_t saradc6doneirqclr, uint8_t saradc5doneirqclr, uint8_t saradc4doneirqclr, uint8_t saradc3doneirqclr, uint8_t saradc2doneirqclr, uint8_t saradc1doneirqclr, uint8_t saradc0doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc7doneirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)saradc6doneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)saradc5doneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)saradc4doneirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)saradc3doneirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)saradc2doneirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)saradc1doneirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)saradc0doneirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR,  ((uint8_t)saradc7doneirqclr << 7) | ((uint8_t)saradc6doneirqclr << 6) | ((uint8_t)saradc5doneirqclr << 5) | ((uint8_t)saradc4doneirqclr << 4) | ((uint8_t)saradc3doneirqclr << 3) | ((uint8_t)saradc2doneirqclr << 2) | ((uint8_t)saradc1doneirqclr << 1) | ((uint8_t)saradc0doneirqclr << 0));
}

__INLINE void ripl_intc_clr2_unpack(uint8_t* saradc7doneirqclr, uint8_t* saradc6doneirqclr, uint8_t* saradc5doneirqclr, uint8_t* saradc4doneirqclr, uint8_t* saradc3doneirqclr, uint8_t* saradc2doneirqclr, uint8_t* saradc1doneirqclr, uint8_t* saradc0doneirqclr)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    *saradc7doneirqclr = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc6doneirqclr = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc5doneirqclr = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc4doneirqclr = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc3doneirqclr = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc2doneirqclr = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc1doneirqclr = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc0doneirqclr = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc7_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_sar_adc7_done_irq_clr_setf(uint8_t saradc7doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc7doneirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)saradc7doneirqclr << 7));
}

__INLINE uint8_t ripl_sar_adc6_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_sar_adc6_done_irq_clr_setf(uint8_t saradc6doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc6doneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)saradc6doneirqclr << 6));
}

__INLINE uint8_t ripl_sar_adc5_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_sar_adc5_done_irq_clr_setf(uint8_t saradc5doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc5doneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)saradc5doneirqclr << 5));
}

__INLINE uint8_t ripl_sar_adc4_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_sar_adc4_done_irq_clr_setf(uint8_t saradc4doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc4doneirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)saradc4doneirqclr << 4));
}

__INLINE uint8_t ripl_sar_adc3_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_sar_adc3_done_irq_clr_setf(uint8_t saradc3doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc3doneirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)saradc3doneirqclr << 3));
}

__INLINE uint8_t ripl_sar_adc2_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_sar_adc2_done_irq_clr_setf(uint8_t saradc2doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc2doneirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)saradc2doneirqclr << 2));
}

__INLINE uint8_t ripl_sar_adc1_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sar_adc1_done_irq_clr_setf(uint8_t saradc1doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc1doneirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)saradc1doneirqclr << 1));
}

__INLINE uint8_t ripl_sar_adc0_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_sar_adc0_done_irq_clr_setf(uint8_t saradc0doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc0doneirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR2_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)saradc0doneirqclr << 0));
}

/**
 * @brief INTC_CLR3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07   SAR_ADC15_DONE_IRQ_CLR   0
 *     06   SAR_ADC14_DONE_IRQ_CLR   0
 *     05   SAR_ADC13_DONE_IRQ_CLR   0
 *     04   SAR_ADC12_DONE_IRQ_CLR   0
 *     03   SAR_ADC11_DONE_IRQ_CLR   0
 *     02   SAR_ADC10_DONE_IRQ_CLR   0
 *     01   SAR_ADC9_DONE_IRQ_CLR   0
 *     00   SAR_ADC8_DONE_IRQ_CLR   0
 * </pre>
 */
#define RIPL_INTC_CLR3_ADDR   0x000000B4
#define RIPL_INTC_CLR3_OFFSET 0x000000B4
#define RIPL_INTC_CLR3_INDEX  0x000000B4
#define RIPL_INTC_CLR3_RESET  0x00000000

__INLINE uint8_t ripl_intc_clr3_get(void)
{
    return REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
}

__INLINE void ripl_intc_clr3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, value);
}

// field definitions
#define RIPL_SAR_ADC15_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000080)
#define RIPL_SAR_ADC15_DONE_IRQ_CLR_POS    7
#define RIPL_SAR_ADC14_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000040)
#define RIPL_SAR_ADC14_DONE_IRQ_CLR_POS    6
#define RIPL_SAR_ADC13_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000020)
#define RIPL_SAR_ADC13_DONE_IRQ_CLR_POS    5
#define RIPL_SAR_ADC12_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000010)
#define RIPL_SAR_ADC12_DONE_IRQ_CLR_POS    4
#define RIPL_SAR_ADC11_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000008)
#define RIPL_SAR_ADC11_DONE_IRQ_CLR_POS    3
#define RIPL_SAR_ADC10_DONE_IRQ_CLR_BIT    ((uint8_t)0x00000004)
#define RIPL_SAR_ADC10_DONE_IRQ_CLR_POS    2
#define RIPL_SAR_ADC9_DONE_IRQ_CLR_BIT     ((uint8_t)0x00000002)
#define RIPL_SAR_ADC9_DONE_IRQ_CLR_POS     1
#define RIPL_SAR_ADC8_DONE_IRQ_CLR_BIT     ((uint8_t)0x00000001)
#define RIPL_SAR_ADC8_DONE_IRQ_CLR_POS     0

#define RIPL_SAR_ADC15_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC14_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC13_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC12_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC11_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC10_DONE_IRQ_CLR_RST    0x0
#define RIPL_SAR_ADC9_DONE_IRQ_CLR_RST     0x0
#define RIPL_SAR_ADC8_DONE_IRQ_CLR_RST     0x0

__INLINE void ripl_intc_clr3_pack(uint8_t saradc15doneirqclr, uint8_t saradc14doneirqclr, uint8_t saradc13doneirqclr, uint8_t saradc12doneirqclr, uint8_t saradc11doneirqclr, uint8_t saradc10doneirqclr, uint8_t saradc9doneirqclr, uint8_t saradc8doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc15doneirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)saradc14doneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)saradc13doneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)saradc12doneirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)saradc11doneirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)saradc10doneirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)saradc9doneirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)saradc8doneirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR,  ((uint8_t)saradc15doneirqclr << 7) | ((uint8_t)saradc14doneirqclr << 6) | ((uint8_t)saradc13doneirqclr << 5) | ((uint8_t)saradc12doneirqclr << 4) | ((uint8_t)saradc11doneirqclr << 3) | ((uint8_t)saradc10doneirqclr << 2) | ((uint8_t)saradc9doneirqclr << 1) | ((uint8_t)saradc8doneirqclr << 0));
}

__INLINE void ripl_intc_clr3_unpack(uint8_t* saradc15doneirqclr, uint8_t* saradc14doneirqclr, uint8_t* saradc13doneirqclr, uint8_t* saradc12doneirqclr, uint8_t* saradc11doneirqclr, uint8_t* saradc10doneirqclr, uint8_t* saradc9doneirqclr, uint8_t* saradc8doneirqclr)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    *saradc15doneirqclr = (localVal & ((uint8_t)0x00000080)) >> 7;
    *saradc14doneirqclr = (localVal & ((uint8_t)0x00000040)) >> 6;
    *saradc13doneirqclr = (localVal & ((uint8_t)0x00000020)) >> 5;
    *saradc12doneirqclr = (localVal & ((uint8_t)0x00000010)) >> 4;
    *saradc11doneirqclr = (localVal & ((uint8_t)0x00000008)) >> 3;
    *saradc10doneirqclr = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc9doneirqclr = (localVal & ((uint8_t)0x00000002)) >> 1;
    *saradc8doneirqclr = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_sar_adc15_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_sar_adc15_done_irq_clr_setf(uint8_t saradc15doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc15doneirqclr << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)saradc15doneirqclr << 7));
}

__INLINE uint8_t ripl_sar_adc14_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_sar_adc14_done_irq_clr_setf(uint8_t saradc14doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc14doneirqclr << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)saradc14doneirqclr << 6));
}

__INLINE uint8_t ripl_sar_adc13_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_sar_adc13_done_irq_clr_setf(uint8_t saradc13doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc13doneirqclr << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)saradc13doneirqclr << 5));
}

__INLINE uint8_t ripl_sar_adc12_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_sar_adc12_done_irq_clr_setf(uint8_t saradc12doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc12doneirqclr << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)saradc12doneirqclr << 4));
}

__INLINE uint8_t ripl_sar_adc11_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_sar_adc11_done_irq_clr_setf(uint8_t saradc11doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc11doneirqclr << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)saradc11doneirqclr << 3));
}

__INLINE uint8_t ripl_sar_adc10_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_sar_adc10_done_irq_clr_setf(uint8_t saradc10doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc10doneirqclr << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)saradc10doneirqclr << 2));
}

__INLINE uint8_t ripl_sar_adc9_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_sar_adc9_done_irq_clr_setf(uint8_t saradc9doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc9doneirqclr << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)saradc9doneirqclr << 1));
}

__INLINE uint8_t ripl_sar_adc8_done_irq_clr_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_INTC_CLR3_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_sar_adc8_done_irq_clr_setf(uint8_t saradc8doneirqclr)
{
    ASSERT_ERR((((uint8_t)saradc8doneirqclr << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_INTC_CLR3_ADDR, (REG_RIPL_RD(RIPL_INTC_CLR3_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)saradc8doneirqclr << 0));
}

/**
 * @brief SPI_PAD_MUX_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00       SPI_PAD_MUX_BP   0
 * </pre>
 */
#define RIPL_SPI_PAD_MUX_CTRL_ADDR   0x000000C5
#define RIPL_SPI_PAD_MUX_CTRL_OFFSET 0x000000C5
#define RIPL_SPI_PAD_MUX_CTRL_INDEX  0x000000C5
#define RIPL_SPI_PAD_MUX_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_spi_pad_mux_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_SPI_PAD_MUX_CTRL_ADDR);
}

__INLINE void ripl_spi_pad_mux_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_SPI_PAD_MUX_CTRL_ADDR, value);
}

// field definitions
#define RIPL_SPI_PAD_MUX_BP_BIT    ((uint8_t)0x00000001)
#define RIPL_SPI_PAD_MUX_BP_POS    0

#define RIPL_SPI_PAD_MUX_BP_RST    0x0

__INLINE uint8_t ripl_spi_pad_mux_bp_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SPI_PAD_MUX_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_spi_pad_mux_bp_setf(uint8_t spipadmuxbp)
{
    ASSERT_ERR((((uint8_t)spipadmuxbp << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_SPI_PAD_MUX_CTRL_ADDR, (uint8_t)spipadmuxbp << 0);
}

/**
 * @brief RF_PINMUX_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      MATCH_THRESHOLD   0xF
 * </pre>
 */
#define RIPL_RF_PINMUX_CTRL1_ADDR   0x000000C6
#define RIPL_RF_PINMUX_CTRL1_OFFSET 0x000000C6
#define RIPL_RF_PINMUX_CTRL1_INDEX  0x000000C6
#define RIPL_RF_PINMUX_CTRL1_RESET  0x0000000F

__INLINE uint8_t ripl_rf_pinmux_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PINMUX_CTRL1_ADDR);
}

__INLINE void ripl_rf_pinmux_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_MATCH_THRESHOLD_MASK   ((uint8_t)0x000000FF)
#define RIPL_MATCH_THRESHOLD_LSB    0
#define RIPL_MATCH_THRESHOLD_WIDTH  ((uint8_t)0x00000008)

#define RIPL_MATCH_THRESHOLD_RST    0xF

__INLINE uint8_t ripl_match_threshold_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL1_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_match_threshold_setf(uint8_t matchthreshold)
{
    ASSERT_ERR((((uint8_t)matchthreshold << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL1_ADDR, (uint8_t)matchthreshold << 0);
}

/**
 * @brief RF_PINMUX_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   RFPINMUX_PAD_MUX_BP   0
 *     05           BB_IN_SYNC   0
 *     04               BYPASS   0
 *     03               ENABLE   0
 *     02             CLK_MODE   0
 *  01:00         REFRESH_MODE   0x0
 * </pre>
 */
#define RIPL_RF_PINMUX_CTRL2_ADDR   0x000000C7
#define RIPL_RF_PINMUX_CTRL2_OFFSET 0x000000C7
#define RIPL_RF_PINMUX_CTRL2_INDEX  0x000000C7
#define RIPL_RF_PINMUX_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_rf_pinmux_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
}

__INLINE void ripl_rf_pinmux_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_RFPINMUX_PAD_MUX_BP_BIT    ((uint8_t)0x00000040)
#define RIPL_RFPINMUX_PAD_MUX_BP_POS    6
#define RIPL_BB_IN_SYNC_BIT             ((uint8_t)0x00000020)
#define RIPL_BB_IN_SYNC_POS             5
#define RIPL_BYPASS_BIT                 ((uint8_t)0x00000010)
#define RIPL_BYPASS_POS                 4
#define RIPL_ENABLE_BIT                 ((uint8_t)0x00000008)
#define RIPL_ENABLE_POS                 3
#define RIPL_CLK_MODE_BIT               ((uint8_t)0x00000004)
#define RIPL_CLK_MODE_POS               2
#define RIPL_REFRESH_MODE_MASK          ((uint8_t)0x00000003)
#define RIPL_REFRESH_MODE_LSB           0
#define RIPL_REFRESH_MODE_WIDTH         ((uint8_t)0x00000002)

#define RIPL_RFPINMUX_PAD_MUX_BP_RST    0x0
#define RIPL_BB_IN_SYNC_RST             0x0
#define RIPL_BYPASS_RST                 0x0
#define RIPL_ENABLE_RST                 0x0
#define RIPL_CLK_MODE_RST               0x0
#define RIPL_REFRESH_MODE_RST           0x0

__INLINE void ripl_rf_pinmux_ctrl2_pack(uint8_t rfpinmuxpadmuxbp, uint8_t bbinsync, uint8_t bypass, uint8_t enable, uint8_t clkmode, uint8_t refreshmode)
{
    ASSERT_ERR((((uint8_t)rfpinmuxpadmuxbp << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)bbinsync << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)bypass << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)enable << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)clkmode << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)refreshmode << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR,  ((uint8_t)rfpinmuxpadmuxbp << 6) | ((uint8_t)bbinsync << 5) | ((uint8_t)bypass << 4) | ((uint8_t)enable << 3) | ((uint8_t)clkmode << 2) | ((uint8_t)refreshmode << 0));
}

__INLINE void ripl_rf_pinmux_ctrl2_unpack(uint8_t* rfpinmuxpadmuxbp, uint8_t* bbinsync, uint8_t* bypass, uint8_t* enable, uint8_t* clkmode, uint8_t* refreshmode)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    *rfpinmuxpadmuxbp = (localVal & ((uint8_t)0x00000040)) >> 6;
    *bbinsync = (localVal & ((uint8_t)0x00000020)) >> 5;
    *bypass = (localVal & ((uint8_t)0x00000010)) >> 4;
    *enable = (localVal & ((uint8_t)0x00000008)) >> 3;
    *clkmode = (localVal & ((uint8_t)0x00000004)) >> 2;
    *refreshmode = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_rfpinmux_pad_mux_bp_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rfpinmux_pad_mux_bp_setf(uint8_t rfpinmuxpadmuxbp)
{
    ASSERT_ERR((((uint8_t)rfpinmuxpadmuxbp << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rfpinmuxpadmuxbp << 6));
}

__INLINE uint8_t ripl_bb_in_sync_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_bb_in_sync_setf(uint8_t bbinsync)
{
    ASSERT_ERR((((uint8_t)bbinsync << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)bbinsync << 5));
}

__INLINE uint8_t ripl_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_bypass_setf(uint8_t bypass)
{
    ASSERT_ERR((((uint8_t)bypass << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)bypass << 4));
}

__INLINE uint8_t ripl_enable_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_enable_setf(uint8_t enable)
{
    ASSERT_ERR((((uint8_t)enable << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)enable << 3));
}

__INLINE uint8_t ripl_clk_mode_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_clk_mode_setf(uint8_t clkmode)
{
    ASSERT_ERR((((uint8_t)clkmode << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)clkmode << 2));
}

__INLINE uint8_t ripl_refresh_mode_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_refresh_mode_setf(uint8_t refreshmode)
{
    ASSERT_ERR((((uint8_t)refreshmode << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL2_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)refreshmode << 0));
}

/**
 * @brief RF_PINMUX_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      TRX_ADD_DELAY_L   0x0
 * </pre>
 */
#define RIPL_RF_PINMUX_CTRL3_ADDR   0x000000C8
#define RIPL_RF_PINMUX_CTRL3_OFFSET 0x000000C8
#define RIPL_RF_PINMUX_CTRL3_INDEX  0x000000C8
#define RIPL_RF_PINMUX_CTRL3_RESET  0x00000000

__INLINE uint8_t ripl_rf_pinmux_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PINMUX_CTRL3_ADDR);
}

__INLINE void ripl_rf_pinmux_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_TRX_ADD_DELAY_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_TRX_ADD_DELAY_L_LSB    0
#define RIPL_TRX_ADD_DELAY_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_TRX_ADD_DELAY_L_RST    0x0

__INLINE uint8_t ripl_trx_add_delay_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL3_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_trx_add_delay_l_setf(uint8_t trxadddelayl)
{
    ASSERT_ERR((((uint8_t)trxadddelayl << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL3_ADDR, (uint8_t)trxadddelayl << 0);
}

/**
 * @brief RF_PINMUX_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03           RF_IN_SYNC   0
 *     02   TRX_ADD_DELAY_OUT_EN   0
 *  01:00      TRX_ADD_DELAY_H   0x0
 * </pre>
 */
#define RIPL_RF_PINMUX_CTRL4_ADDR   0x000000C9
#define RIPL_RF_PINMUX_CTRL4_OFFSET 0x000000C9
#define RIPL_RF_PINMUX_CTRL4_INDEX  0x000000C9
#define RIPL_RF_PINMUX_CTRL4_RESET  0x00000000

__INLINE uint8_t ripl_rf_pinmux_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR);
}

__INLINE void ripl_rf_pinmux_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_RF_IN_SYNC_BIT              ((uint8_t)0x00000008)
#define RIPL_RF_IN_SYNC_POS              3
#define RIPL_TRX_ADD_DELAY_OUT_EN_BIT    ((uint8_t)0x00000004)
#define RIPL_TRX_ADD_DELAY_OUT_EN_POS    2
#define RIPL_TRX_ADD_DELAY_H_MASK        ((uint8_t)0x00000003)
#define RIPL_TRX_ADD_DELAY_H_LSB         0
#define RIPL_TRX_ADD_DELAY_H_WIDTH       ((uint8_t)0x00000002)

#define RIPL_RF_IN_SYNC_RST              0x0
#define RIPL_TRX_ADD_DELAY_OUT_EN_RST    0x0
#define RIPL_TRX_ADD_DELAY_H_RST         0x0

__INLINE void ripl_rf_pinmux_ctrl4_pack(uint8_t trxadddelayouten, uint8_t trxadddelayh)
{
    ASSERT_ERR((((uint8_t)trxadddelayouten << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)trxadddelayh << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL4_ADDR,  ((uint8_t)trxadddelayouten << 2) | ((uint8_t)trxadddelayh << 0));
}

__INLINE void ripl_rf_pinmux_ctrl4_unpack(uint8_t* rfinsync, uint8_t* trxadddelayouten, uint8_t* trxadddelayh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR);
    *rfinsync = (localVal & ((uint8_t)0x00000008)) >> 3;
    *trxadddelayouten = (localVal & ((uint8_t)0x00000004)) >> 2;
    *trxadddelayh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_rf_in_sync_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE uint8_t ripl_trx_add_delay_out_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_trx_add_delay_out_en_setf(uint8_t trxadddelayouten)
{
    ASSERT_ERR((((uint8_t)trxadddelayouten << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL4_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)trxadddelayouten << 2));
}

__INLINE uint8_t ripl_trx_add_delay_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_trx_add_delay_h_setf(uint8_t trxadddelayh)
{
    ASSERT_ERR((((uint8_t)trxadddelayh << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_RF_PINMUX_CTRL4_ADDR, (REG_RIPL_RD(RIPL_RF_PINMUX_CTRL4_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)trxadddelayh << 0));
}

/**
 * @brief RX_LNA_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07    RXLNA_TRIM_MUX_EN   0
 *  06:04   SPI_RXLNA_TRIM_MUX   0x3
 *     03   LNA_TANK_1P2V_SPI_MUX   0
 *  02:00        LNA_TANK_1P2V   0x3
 * </pre>
 */
#define RIPL_RX_LNA_CTRL_ADDR   0x000000CF
#define RIPL_RX_LNA_CTRL_OFFSET 0x000000CF
#define RIPL_RX_LNA_CTRL_INDEX  0x000000CF
#define RIPL_RX_LNA_CTRL_RESET  0x00000033

__INLINE uint8_t ripl_rx_lna_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
}

__INLINE void ripl_rx_lna_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR, value);
}

// field definitions
#define RIPL_RXLNA_TRIM_MUX_EN_BIT        ((uint8_t)0x00000080)
#define RIPL_RXLNA_TRIM_MUX_EN_POS        7
#define RIPL_SPI_RXLNA_TRIM_MUX_MASK      ((uint8_t)0x00000070)
#define RIPL_SPI_RXLNA_TRIM_MUX_LSB       4
#define RIPL_SPI_RXLNA_TRIM_MUX_WIDTH     ((uint8_t)0x00000003)
#define RIPL_LNA_TANK_1P2V_SPI_MUX_BIT    ((uint8_t)0x00000008)
#define RIPL_LNA_TANK_1P2V_SPI_MUX_POS    3
#define RIPL_LNA_TANK_1P2V_MASK           ((uint8_t)0x00000007)
#define RIPL_LNA_TANK_1P2V_LSB            0
#define RIPL_LNA_TANK_1P2V_WIDTH          ((uint8_t)0x00000003)

#define RIPL_RXLNA_TRIM_MUX_EN_RST        0x0
#define RIPL_SPI_RXLNA_TRIM_MUX_RST       0x3
#define RIPL_LNA_TANK_1P2V_SPI_MUX_RST    0x0
#define RIPL_LNA_TANK_1P2V_RST            0x3

__INLINE void ripl_rx_lna_ctrl_pack(uint8_t rxlnatrimmuxen, uint8_t spirxlnatrimmux, uint8_t lnatank1p2vspimux, uint8_t lnatank1p2v)
{
    ASSERT_ERR((((uint8_t)rxlnatrimmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)spirxlnatrimmux << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)lnatank1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)lnatank1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR,  ((uint8_t)rxlnatrimmuxen << 7) | ((uint8_t)spirxlnatrimmux << 4) | ((uint8_t)lnatank1p2vspimux << 3) | ((uint8_t)lnatank1p2v << 0));
}

__INLINE void ripl_rx_lna_ctrl_unpack(uint8_t* rxlnatrimmuxen, uint8_t* spirxlnatrimmux, uint8_t* lnatank1p2vspimux, uint8_t* lnatank1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
    *rxlnatrimmuxen = (localVal & ((uint8_t)0x00000080)) >> 7;
    *spirxlnatrimmux = (localVal & ((uint8_t)0x00000070)) >> 4;
    *lnatank1p2vspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *lnatank1p2v = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_rxlna_trim_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_rxlna_trim_mux_en_setf(uint8_t rxlnatrimmuxen)
{
    ASSERT_ERR((((uint8_t)rxlnatrimmuxen << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)rxlnatrimmuxen << 7));
}

__INLINE uint8_t ripl_spi_rxlna_trim_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_spi_rxlna_trim_mux_setf(uint8_t spirxlnatrimmux)
{
    ASSERT_ERR((((uint8_t)spirxlnatrimmux << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)spirxlnatrimmux << 4));
}

__INLINE uint8_t ripl_lna_tank_1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_lna_tank_1p2v_spi_mux_setf(uint8_t lnatank1p2vspimux)
{
    ASSERT_ERR((((uint8_t)lnatank1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)lnatank1p2vspimux << 3));
}

__INLINE uint8_t ripl_lna_tank_1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_lna_tank_1p2v_setf(uint8_t lnatank1p2v)
{
    ASSERT_ERR((((uint8_t)lnatank1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RX_LNA_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_LNA_CTRL_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)lnatank1p2v << 0));
}

/**
 * @brief RX_MIXER_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   GAIN_SEL1P2V_SPI_MUX   0
 *     03   GAIN_SEL1P2V_DAP_MUX   0
 *  02:00         GAIN_SEL1P2V   0x7
 * </pre>
 */
#define RIPL_RX_MIXER_CTRL_ADDR   0x000000D2
#define RIPL_RX_MIXER_CTRL_OFFSET 0x000000D2
#define RIPL_RX_MIXER_CTRL_INDEX  0x000000D2
#define RIPL_RX_MIXER_CTRL_RESET  0x00000007

__INLINE uint8_t ripl_rx_mixer_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR);
}

__INLINE void ripl_rx_mixer_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RX_MIXER_CTRL_ADDR, value);
}

// field definitions
#define RIPL_GAIN_SEL1P2V_SPI_MUX_BIT    ((uint8_t)0x00000010)
#define RIPL_GAIN_SEL1P2V_SPI_MUX_POS    4
#define RIPL_GAIN_SEL1P2V_DAP_MUX_BIT    ((uint8_t)0x00000008)
#define RIPL_GAIN_SEL1P2V_DAP_MUX_POS    3
#define RIPL_GAIN_SEL1P2V_MASK           ((uint8_t)0x00000007)
#define RIPL_GAIN_SEL1P2V_LSB            0
#define RIPL_GAIN_SEL1P2V_WIDTH          ((uint8_t)0x00000003)

#define RIPL_GAIN_SEL1P2V_SPI_MUX_RST    0x0
#define RIPL_GAIN_SEL1P2V_DAP_MUX_RST    0x0
#define RIPL_GAIN_SEL1P2V_RST            0x7

__INLINE void ripl_rx_mixer_ctrl_pack(uint8_t gainsel1p2vspimux, uint8_t gainsel1p2vdapmux, uint8_t gainsel1p2v)
{
    ASSERT_ERR((((uint8_t)gainsel1p2vspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)gainsel1p2vdapmux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)gainsel1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RX_MIXER_CTRL_ADDR,  ((uint8_t)gainsel1p2vspimux << 4) | ((uint8_t)gainsel1p2vdapmux << 3) | ((uint8_t)gainsel1p2v << 0));
}

__INLINE void ripl_rx_mixer_ctrl_unpack(uint8_t* gainsel1p2vspimux, uint8_t* gainsel1p2vdapmux, uint8_t* gainsel1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR);
    *gainsel1p2vspimux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *gainsel1p2vdapmux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *gainsel1p2v = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_gain_sel1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_gain_sel1p2v_spi_mux_setf(uint8_t gainsel1p2vspimux)
{
    ASSERT_ERR((((uint8_t)gainsel1p2vspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RX_MIXER_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)gainsel1p2vspimux << 4));
}

__INLINE uint8_t ripl_gain_sel1p2v_dap_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_gain_sel1p2v_dap_mux_setf(uint8_t gainsel1p2vdapmux)
{
    ASSERT_ERR((((uint8_t)gainsel1p2vdapmux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RX_MIXER_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)gainsel1p2vdapmux << 3));
}

__INLINE uint8_t ripl_gain_sel1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_gain_sel1p2v_setf(uint8_t gainsel1p2v)
{
    ASSERT_ERR((((uint8_t)gainsel1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RX_MIXER_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_MIXER_CTRL_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)gainsel1p2v << 0));
}

/**
 * @brief RX_ADC_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07     GAIN_CFG_SPI_MUX   0
 *  06:05             GAIN_CFG   0x0
 *     04     BIAS_CFG_SPI_MUX   0
 *  03:00             BIAS_CFG   0x1
 * </pre>
 */
#define RIPL_RX_ADC_CTRL1_ADDR   0x000000D3
#define RIPL_RX_ADC_CTRL1_OFFSET 0x000000D3
#define RIPL_RX_ADC_CTRL1_INDEX  0x000000D3
#define RIPL_RX_ADC_CTRL1_RESET  0x00000001

__INLINE uint8_t ripl_rx_adc_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
}

__INLINE void ripl_rx_adc_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_GAIN_CFG_SPI_MUX_BIT    ((uint8_t)0x00000080)
#define RIPL_GAIN_CFG_SPI_MUX_POS    7
#define RIPL_GAIN_CFG_MASK           ((uint8_t)0x00000060)
#define RIPL_GAIN_CFG_LSB            5
#define RIPL_GAIN_CFG_WIDTH          ((uint8_t)0x00000002)
#define RIPL_BIAS_CFG_SPI_MUX_BIT    ((uint8_t)0x00000010)
#define RIPL_BIAS_CFG_SPI_MUX_POS    4
#define RIPL_BIAS_CFG_MASK           ((uint8_t)0x0000000F)
#define RIPL_BIAS_CFG_LSB            0
#define RIPL_BIAS_CFG_WIDTH          ((uint8_t)0x00000004)

#define RIPL_GAIN_CFG_SPI_MUX_RST    0x0
#define RIPL_GAIN_CFG_RST            0x0
#define RIPL_BIAS_CFG_SPI_MUX_RST    0x0
#define RIPL_BIAS_CFG_RST            0x1

__INLINE void ripl_rx_adc_ctrl1_pack(uint8_t gaincfgspimux, uint8_t gaincfg, uint8_t biascfgspimux, uint8_t biascfg)
{
    ASSERT_ERR((((uint8_t)gaincfgspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    ASSERT_ERR((((uint8_t)gaincfg << 5) & ~((uint8_t)0x00000060)) == 0);
    ASSERT_ERR((((uint8_t)biascfgspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)biascfg << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR,  ((uint8_t)gaincfgspimux << 7) | ((uint8_t)gaincfg << 5) | ((uint8_t)biascfgspimux << 4) | ((uint8_t)biascfg << 0));
}

__INLINE void ripl_rx_adc_ctrl1_unpack(uint8_t* gaincfgspimux, uint8_t* gaincfg, uint8_t* biascfgspimux, uint8_t* biascfg)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
    *gaincfgspimux = (localVal & ((uint8_t)0x00000080)) >> 7;
    *gaincfg = (localVal & ((uint8_t)0x00000060)) >> 5;
    *biascfgspimux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *biascfg = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_gain_cfg_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000080)) >> 7);
}

__INLINE void ripl_gain_cfg_spi_mux_setf(uint8_t gaincfgspimux)
{
    ASSERT_ERR((((uint8_t)gaincfgspimux << 7) & ~((uint8_t)0x00000080)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR) & ~((uint8_t)0x00000080)) | ((uint8_t)gaincfgspimux << 7));
}

__INLINE uint8_t ripl_gain_cfg_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000060)) >> 5);
}

__INLINE void ripl_gain_cfg_setf(uint8_t gaincfg)
{
    ASSERT_ERR((((uint8_t)gaincfg << 5) & ~((uint8_t)0x00000060)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR) & ~((uint8_t)0x00000060)) | ((uint8_t)gaincfg << 5));
}

__INLINE uint8_t ripl_bias_cfg_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_bias_cfg_spi_mux_setf(uint8_t biascfgspimux)
{
    ASSERT_ERR((((uint8_t)biascfgspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)biascfgspimux << 4));
}

__INLINE uint8_t ripl_bias_cfg_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_bias_cfg_setf(uint8_t biascfg)
{
    ASSERT_ERR((((uint8_t)biascfg << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL1_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)biascfg << 0));
}

/**
 * @brief RX_ADC_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        RXADC_CLAMPEN   0
 *     01          RXADC_AUXEN   0
 *     00        RXADC_ZEROOFF   0
 * </pre>
 */
#define RIPL_RX_ADC_CTRL2_ADDR   0x000000D4
#define RIPL_RX_ADC_CTRL2_OFFSET 0x000000D4
#define RIPL_RX_ADC_CTRL2_INDEX  0x000000D4
#define RIPL_RX_ADC_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_rx_adc_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR);
}

__INLINE void ripl_rx_adc_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RX_ADC_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_RXADC_CLAMPEN_BIT    ((uint8_t)0x00000004)
#define RIPL_RXADC_CLAMPEN_POS    2
#define RIPL_RXADC_AUXEN_BIT      ((uint8_t)0x00000002)
#define RIPL_RXADC_AUXEN_POS      1
#define RIPL_RXADC_ZEROOFF_BIT    ((uint8_t)0x00000001)
#define RIPL_RXADC_ZEROOFF_POS    0

#define RIPL_RXADC_CLAMPEN_RST    0x0
#define RIPL_RXADC_AUXEN_RST      0x0
#define RIPL_RXADC_ZEROOFF_RST    0x0

__INLINE void ripl_rx_adc_ctrl2_pack(uint8_t rxadcclampen, uint8_t rxadcauxen, uint8_t rxadczerooff)
{
    ASSERT_ERR((((uint8_t)rxadcclampen << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)rxadcauxen << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)rxadczerooff << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL2_ADDR,  ((uint8_t)rxadcclampen << 2) | ((uint8_t)rxadcauxen << 1) | ((uint8_t)rxadczerooff << 0));
}

__INLINE void ripl_rx_adc_ctrl2_unpack(uint8_t* rxadcclampen, uint8_t* rxadcauxen, uint8_t* rxadczerooff)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR);
    *rxadcclampen = (localVal & ((uint8_t)0x00000004)) >> 2;
    *rxadcauxen = (localVal & ((uint8_t)0x00000002)) >> 1;
    *rxadczerooff = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_rxadc_clampen_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_rxadc_clampen_setf(uint8_t rxadcclampen)
{
    ASSERT_ERR((((uint8_t)rxadcclampen << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)rxadcclampen << 2));
}

__INLINE uint8_t ripl_rxadc_auxen_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_rxadc_auxen_setf(uint8_t rxadcauxen)
{
    ASSERT_ERR((((uint8_t)rxadcauxen << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)rxadcauxen << 1));
}

__INLINE uint8_t ripl_rxadc_zerooff_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_rxadc_zerooff_setf(uint8_t rxadczerooff)
{
    ASSERT_ERR((((uint8_t)rxadczerooff << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_RX_ADC_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RX_ADC_CTRL2_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)rxadczerooff << 0));
}

/**
 * @brief RX_RSSI_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   RSSI_CFG1P2V_SPI_MUX   0
 *  05:00         RSSI_CFG1P2V   0x9
 * </pre>
 */
#define RIPL_RX_RSSI_CTRL_ADDR   0x000000D5
#define RIPL_RX_RSSI_CTRL_OFFSET 0x000000D5
#define RIPL_RX_RSSI_CTRL_INDEX  0x000000D5
#define RIPL_RX_RSSI_CTRL_RESET  0x00000009

__INLINE uint8_t ripl_rx_rssi_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR);
}

__INLINE void ripl_rx_rssi_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RX_RSSI_CTRL_ADDR, value);
}

// field definitions
#define RIPL_RSSI_CFG1P2V_SPI_MUX_BIT    ((uint8_t)0x00000040)
#define RIPL_RSSI_CFG1P2V_SPI_MUX_POS    6
#define RIPL_RSSI_CFG1P2V_MASK           ((uint8_t)0x0000003F)
#define RIPL_RSSI_CFG1P2V_LSB            0
#define RIPL_RSSI_CFG1P2V_WIDTH          ((uint8_t)0x00000006)

#define RIPL_RSSI_CFG1P2V_SPI_MUX_RST    0x0
#define RIPL_RSSI_CFG1P2V_RST            0x9

__INLINE void ripl_rx_rssi_ctrl_pack(uint8_t rssicfg1p2vspimux, uint8_t rssicfg1p2v)
{
    ASSERT_ERR((((uint8_t)rssicfg1p2vspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)rssicfg1p2v << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_RX_RSSI_CTRL_ADDR,  ((uint8_t)rssicfg1p2vspimux << 6) | ((uint8_t)rssicfg1p2v << 0));
}

__INLINE void ripl_rx_rssi_ctrl_unpack(uint8_t* rssicfg1p2vspimux, uint8_t* rssicfg1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR);
    *rssicfg1p2vspimux = (localVal & ((uint8_t)0x00000040)) >> 6;
    *rssicfg1p2v = (localVal & ((uint8_t)0x0000003F)) >> 0;
}

__INLINE uint8_t ripl_rssi_cfg1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rssi_cfg1p2v_spi_mux_setf(uint8_t rssicfg1p2vspimux)
{
    ASSERT_ERR((((uint8_t)rssicfg1p2vspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RX_RSSI_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rssicfg1p2vspimux << 6));
}

__INLINE uint8_t ripl_rssi_cfg1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x0000003F)) >> 0);
}

__INLINE void ripl_rssi_cfg1p2v_setf(uint8_t rssicfg1p2v)
{
    ASSERT_ERR((((uint8_t)rssicfg1p2v << 0) & ~((uint8_t)0x0000003F)) == 0);
    REG_RIPL_WR(RIPL_RX_RSSI_CTRL_ADDR, (REG_RIPL_RD(RIPL_RX_RSSI_CTRL_ADDR) & ~((uint8_t)0x0000003F)) | ((uint8_t)rssicfg1p2v << 0));
}

/**
 * @brief TX_MIXER_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   TXMIX_EDRBIAS_TRIM_1P2V_SPI_MUX   0
 *  02:00   TXMIX_EDRBIAS_TRIM_1P2V   0x3
 * </pre>
 */
#define RIPL_TX_MIXER_CTRL_ADDR   0x00000000
#define RIPL_TX_MIXER_CTRL_OFFSET 0x00000000
#define RIPL_TX_MIXER_CTRL_INDEX  0x00000000
#define RIPL_TX_MIXER_CTRL_RESET  0x00000003

__INLINE uint8_t ripl_tx_mixer_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR);
}

__INLINE void ripl_tx_mixer_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TX_MIXER_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_SPI_MUX_BIT    ((uint8_t)0x00000008)
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_SPI_MUX_POS    3
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_MASK           ((uint8_t)0x00000007)
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_LSB            0
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_WIDTH          ((uint8_t)0x00000003)

#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_SPI_MUX_RST    0x0
#define RIPL_TXMIX_EDRBIAS_TRIM_1P2V_RST            0x3

__INLINE void ripl_tx_mixer_ctrl_pack(uint8_t txmixedrbiastrim1p2vspimux, uint8_t txmixedrbiastrim1p2v)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrim1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)txmixedrbiastrim1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_TX_MIXER_CTRL_ADDR,  ((uint8_t)txmixedrbiastrim1p2vspimux << 3) | ((uint8_t)txmixedrbiastrim1p2v << 0));
}

__INLINE void ripl_tx_mixer_ctrl_unpack(uint8_t* txmixedrbiastrim1p2vspimux, uint8_t* txmixedrbiastrim1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR);
    *txmixedrbiastrim1p2vspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *txmixedrbiastrim1p2v = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_txmix_edrbias_trim_1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_txmix_edrbias_trim_1p2v_spi_mux_setf(uint8_t txmixedrbiastrim1p2vspimux)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrim1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_TX_MIXER_CTRL_ADDR, (REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)txmixedrbiastrim1p2vspimux << 3));
}

__INLINE uint8_t ripl_txmix_edrbias_trim_1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_txmix_edrbias_trim_1p2v_setf(uint8_t txmixedrbiastrim1p2v)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrim1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_TX_MIXER_CTRL_ADDR, (REG_RIPL_RD(RIPL_TX_MIXER_CTRL_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)txmixedrbiastrim1p2v << 0));
}

/**
 * @brief TX_PA_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   TXMIX_EDRBIAS_TRIM_SPI_MUX   0
 *  02:00   TXMIX_EDRBIAS_TRIM   0x3
 * </pre>
 */
#define RIPL_TX_PA_CTRL_ADDR   0x000000D6
#define RIPL_TX_PA_CTRL_OFFSET 0x000000D6
#define RIPL_TX_PA_CTRL_INDEX  0x000000D6
#define RIPL_TX_PA_CTRL_RESET  0x00000003

__INLINE uint8_t ripl_tx_pa_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR);
}

__INLINE void ripl_tx_pa_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TX_PA_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TXMIX_EDRBIAS_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000008)
#define RIPL_TXMIX_EDRBIAS_TRIM_SPI_MUX_POS    3
#define RIPL_TXMIX_EDRBIAS_TRIM_MASK           ((uint8_t)0x00000007)
#define RIPL_TXMIX_EDRBIAS_TRIM_LSB            0
#define RIPL_TXMIX_EDRBIAS_TRIM_WIDTH          ((uint8_t)0x00000003)

#define RIPL_TXMIX_EDRBIAS_TRIM_SPI_MUX_RST    0x0
#define RIPL_TXMIX_EDRBIAS_TRIM_RST            0x3

__INLINE void ripl_tx_pa_ctrl_pack(uint8_t txmixedrbiastrimspimux, uint8_t txmixedrbiastrim)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrimspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)txmixedrbiastrim << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CTRL_ADDR,  ((uint8_t)txmixedrbiastrimspimux << 3) | ((uint8_t)txmixedrbiastrim << 0));
}

__INLINE void ripl_tx_pa_ctrl_unpack(uint8_t* txmixedrbiastrimspimux, uint8_t* txmixedrbiastrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR);
    *txmixedrbiastrimspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *txmixedrbiastrim = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_txmix_edrbias_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_txmix_edrbias_trim_spi_mux_setf(uint8_t txmixedrbiastrimspimux)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrimspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CTRL_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)txmixedrbiastrimspimux << 3));
}

__INLINE uint8_t ripl_txmix_edrbias_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_txmix_edrbias_trim_setf(uint8_t txmixedrbiastrim)
{
    ASSERT_ERR((((uint8_t)txmixedrbiastrim << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CTRL_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CTRL_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)txmixedrbiastrim << 0));
}

/**
 * @brief TX_PA_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   RSSI_PRELOAD_EN_MUX_EN   0
 *     05   SPI_RSSI_PRELOAD_EN_MUX   0
 *     04      TXPA_CFG_MUX_EN   0
 *  03:00     SPI_TXPA_CFG_MUX   0x6
 * </pre>
 */
#define RIPL_TX_PA_CFG_ADDR   0x000000D7
#define RIPL_TX_PA_CFG_OFFSET 0x000000D7
#define RIPL_TX_PA_CFG_INDEX  0x000000D7
#define RIPL_TX_PA_CFG_RESET  0x00000006

__INLINE uint8_t ripl_tx_pa_cfg_get(void)
{
    return REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
}

__INLINE void ripl_tx_pa_cfg_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR, value);
}

// field definitions
#define RIPL_RSSI_PRELOAD_EN_MUX_EN_BIT     ((uint8_t)0x00000040)
#define RIPL_RSSI_PRELOAD_EN_MUX_EN_POS     6
#define RIPL_SPI_RSSI_PRELOAD_EN_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_SPI_RSSI_PRELOAD_EN_MUX_POS    5
#define RIPL_TXPA_CFG_MUX_EN_BIT            ((uint8_t)0x00000010)
#define RIPL_TXPA_CFG_MUX_EN_POS            4
#define RIPL_SPI_TXPA_CFG_MUX_MASK          ((uint8_t)0x0000000F)
#define RIPL_SPI_TXPA_CFG_MUX_LSB           0
#define RIPL_SPI_TXPA_CFG_MUX_WIDTH         ((uint8_t)0x00000004)

#define RIPL_RSSI_PRELOAD_EN_MUX_EN_RST     0x0
#define RIPL_SPI_RSSI_PRELOAD_EN_MUX_RST    0x0
#define RIPL_TXPA_CFG_MUX_EN_RST            0x0
#define RIPL_SPI_TXPA_CFG_MUX_RST           0x6

__INLINE void ripl_tx_pa_cfg_pack(uint8_t rssipreloadenmuxen, uint8_t spirssipreloadenmux, uint8_t txpacfgmuxen, uint8_t spitxpacfgmux)
{
    ASSERT_ERR((((uint8_t)rssipreloadenmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)spirssipreloadenmux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)txpacfgmuxen << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)spitxpacfgmux << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR,  ((uint8_t)rssipreloadenmuxen << 6) | ((uint8_t)spirssipreloadenmux << 5) | ((uint8_t)txpacfgmuxen << 4) | ((uint8_t)spitxpacfgmux << 0));
}

__INLINE void ripl_tx_pa_cfg_unpack(uint8_t* rssipreloadenmuxen, uint8_t* spirssipreloadenmux, uint8_t* txpacfgmuxen, uint8_t* spitxpacfgmux)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
    *rssipreloadenmuxen = (localVal & ((uint8_t)0x00000040)) >> 6;
    *spirssipreloadenmux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *txpacfgmuxen = (localVal & ((uint8_t)0x00000010)) >> 4;
    *spitxpacfgmux = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_rssi_preload_en_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rssi_preload_en_mux_en_setf(uint8_t rssipreloadenmuxen)
{
    ASSERT_ERR((((uint8_t)rssipreloadenmuxen << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rssipreloadenmuxen << 6));
}

__INLINE uint8_t ripl_spi_rssi_preload_en_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_spi_rssi_preload_en_mux_setf(uint8_t spirssipreloadenmux)
{
    ASSERT_ERR((((uint8_t)spirssipreloadenmux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)spirssipreloadenmux << 5));
}

__INLINE uint8_t ripl_txpa_cfg_mux_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_txpa_cfg_mux_en_setf(uint8_t txpacfgmuxen)
{
    ASSERT_ERR((((uint8_t)txpacfgmuxen << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)txpacfgmuxen << 4));
}

__INLINE uint8_t ripl_spi_txpa_cfg_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_spi_txpa_cfg_mux_setf(uint8_t spitxpacfgmux)
{
    ASSERT_ERR((((uint8_t)spitxpacfgmux << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_TX_PA_CFG_ADDR, (REG_RIPL_RD(RIPL_TX_PA_CFG_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)spitxpacfgmux << 0));
}

/**
 * @brief ANA_XO_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02   XO_BUFFER_BIAS_SPI_MUX   0
 *  01:00       XO_BUFFER_BIAS   0x2
 * </pre>
 */
#define RIPL_ANA_XO_CTRL1_ADDR   0x000000DD
#define RIPL_ANA_XO_CTRL1_OFFSET 0x000000DD
#define RIPL_ANA_XO_CTRL1_INDEX  0x000000DD
#define RIPL_ANA_XO_CTRL1_RESET  0x00000002

__INLINE uint8_t ripl_ana_xo_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR);
}

__INLINE void ripl_ana_xo_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_XO_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_XO_BUFFER_BIAS_SPI_MUX_BIT    ((uint8_t)0x00000004)
#define RIPL_XO_BUFFER_BIAS_SPI_MUX_POS    2
#define RIPL_XO_BUFFER_BIAS_MASK           ((uint8_t)0x00000003)
#define RIPL_XO_BUFFER_BIAS_LSB            0
#define RIPL_XO_BUFFER_BIAS_WIDTH          ((uint8_t)0x00000002)

#define RIPL_XO_BUFFER_BIAS_SPI_MUX_RST    0x0
#define RIPL_XO_BUFFER_BIAS_RST            0x2

__INLINE void ripl_ana_xo_ctrl1_pack(uint8_t xobufferbiasspimux, uint8_t xobufferbias)
{
    ASSERT_ERR((((uint8_t)xobufferbiasspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)xobufferbias << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL1_ADDR,  ((uint8_t)xobufferbiasspimux << 2) | ((uint8_t)xobufferbias << 0));
}

__INLINE void ripl_ana_xo_ctrl1_unpack(uint8_t* xobufferbiasspimux, uint8_t* xobufferbias)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR);
    *xobufferbiasspimux = (localVal & ((uint8_t)0x00000004)) >> 2;
    *xobufferbias = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_xo_buffer_bias_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_xo_buffer_bias_spi_mux_setf(uint8_t xobufferbiasspimux)
{
    ASSERT_ERR((((uint8_t)xobufferbiasspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)xobufferbiasspimux << 2));
}

__INLINE uint8_t ripl_xo_buffer_bias_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_xo_buffer_bias_setf(uint8_t xobufferbias)
{
    ASSERT_ERR((((uint8_t)xobufferbias << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL1_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL1_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)xobufferbias << 0));
}

/**
 * @brief ANA_XO_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04   XO_BIAS1P2V_SPI_MUX   0
 *  03:00          XO_BIAS1P2V   0xF
 * </pre>
 */
#define RIPL_ANA_XO_CTRL2_ADDR   0x000000DE
#define RIPL_ANA_XO_CTRL2_OFFSET 0x000000DE
#define RIPL_ANA_XO_CTRL2_INDEX  0x000000DE
#define RIPL_ANA_XO_CTRL2_RESET  0x0000000F

__INLINE uint8_t ripl_ana_xo_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR);
}

__INLINE void ripl_ana_xo_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_XO_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_XO_BIAS1P2V_SPI_MUX_BIT    ((uint8_t)0x00000010)
#define RIPL_XO_BIAS1P2V_SPI_MUX_POS    4
#define RIPL_XO_BIAS1P2V_MASK           ((uint8_t)0x0000000F)
#define RIPL_XO_BIAS1P2V_LSB            0
#define RIPL_XO_BIAS1P2V_WIDTH          ((uint8_t)0x00000004)

#define RIPL_XO_BIAS1P2V_SPI_MUX_RST    0x0
#define RIPL_XO_BIAS1P2V_RST            0xF

__INLINE void ripl_ana_xo_ctrl2_pack(uint8_t xobias1p2vspimux, uint8_t xobias1p2v)
{
    ASSERT_ERR((((uint8_t)xobias1p2vspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)xobias1p2v << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL2_ADDR,  ((uint8_t)xobias1p2vspimux << 4) | ((uint8_t)xobias1p2v << 0));
}

__INLINE void ripl_ana_xo_ctrl2_unpack(uint8_t* xobias1p2vspimux, uint8_t* xobias1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR);
    *xobias1p2vspimux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *xobias1p2v = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_xo_bias1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_xo_bias1p2v_spi_mux_setf(uint8_t xobias1p2vspimux)
{
    ASSERT_ERR((((uint8_t)xobias1p2vspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)xobias1p2vspimux << 4));
}

__INLINE uint8_t ripl_xo_bias1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_xo_bias1p2v_setf(uint8_t xobias1p2v)
{
    ASSERT_ERR((((uint8_t)xobias1p2v << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL2_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL2_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)xobias1p2v << 0));
}

/**
 * @brief ANA_XO_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06           OUTMODE_1V   0
 *     04             ANA_EN1V   1
 *  01:00      PULL_MOSE_SEL1V   0x2
 * </pre>
 */
#define RIPL_ANA_XO_CTRL3_ADDR   0x000000DF
#define RIPL_ANA_XO_CTRL3_OFFSET 0x000000DF
#define RIPL_ANA_XO_CTRL3_INDEX  0x000000DF
#define RIPL_ANA_XO_CTRL3_RESET  0x00000012

__INLINE uint8_t ripl_ana_xo_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR);
}

__INLINE void ripl_ana_xo_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_ANA_XO_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_OUTMODE_1V_BIT         ((uint8_t)0x00000040)
#define RIPL_OUTMODE_1V_POS         6
#define RIPL_ANA_EN1V_BIT           ((uint8_t)0x00000010)
#define RIPL_ANA_EN1V_POS           4
#define RIPL_PULL_MOSE_SEL1V_MASK   ((uint8_t)0x00000003)
#define RIPL_PULL_MOSE_SEL1V_LSB    0
#define RIPL_PULL_MOSE_SEL1V_WIDTH  ((uint8_t)0x00000002)

#define RIPL_OUTMODE_1V_RST         0x0
#define RIPL_ANA_EN1V_RST           0x1
#define RIPL_PULL_MOSE_SEL1V_RST    0x2

__INLINE void ripl_ana_xo_ctrl3_pack(uint8_t outmode1v, uint8_t anaen1v, uint8_t pullmosesel1v)
{
    ASSERT_ERR((((uint8_t)outmode1v << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)anaen1v << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)pullmosesel1v << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL3_ADDR,  ((uint8_t)outmode1v << 6) | ((uint8_t)anaen1v << 4) | ((uint8_t)pullmosesel1v << 0));
}

__INLINE void ripl_ana_xo_ctrl3_unpack(uint8_t* outmode1v, uint8_t* anaen1v, uint8_t* pullmosesel1v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR);
    *outmode1v = (localVal & ((uint8_t)0x00000040)) >> 6;
    *anaen1v = (localVal & ((uint8_t)0x00000010)) >> 4;
    *pullmosesel1v = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_outmode_1v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_outmode_1v_setf(uint8_t outmode1v)
{
    ASSERT_ERR((((uint8_t)outmode1v << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)outmode1v << 6));
}

__INLINE uint8_t ripl_ana_en1v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_ana_en1v_setf(uint8_t anaen1v)
{
    ASSERT_ERR((((uint8_t)anaen1v << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)anaen1v << 4));
}

__INLINE uint8_t ripl_pull_mose_sel1v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_pull_mose_sel1v_setf(uint8_t pullmosesel1v)
{
    ASSERT_ERR((((uint8_t)pullmosesel1v << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_ANA_XO_CTRL3_ADDR, (REG_RIPL_RD(RIPL_ANA_XO_CTRL3_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)pullmosesel1v << 0));
}

/**
 * @brief BBPLL_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  06:04     BBPLL_TRIM_IBVCO   0x3
 *  03:02   BBPLL_TRIM_KVCO_SEL   0x1
 *     01   DPLL_LOOP_DIV_SPI_EN   0
 *     00        DPLL_LOOP_DIV   0
 * </pre>
 */
#define RIPL_BBPLL_CTRL1_ADDR   0x000000E3
#define RIPL_BBPLL_CTRL1_OFFSET 0x000000E3
#define RIPL_BBPLL_CTRL1_INDEX  0x000000E3
#define RIPL_BBPLL_CTRL1_RESET  0x00000034

__INLINE uint8_t ripl_bbpll_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
}

__INLINE void ripl_bbpll_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_BBPLL_TRIM_IBVCO_MASK       ((uint8_t)0x00000070)
#define RIPL_BBPLL_TRIM_IBVCO_LSB        4
#define RIPL_BBPLL_TRIM_IBVCO_WIDTH      ((uint8_t)0x00000003)
#define RIPL_BBPLL_TRIM_KVCO_SEL_MASK    ((uint8_t)0x0000000C)
#define RIPL_BBPLL_TRIM_KVCO_SEL_LSB     2
#define RIPL_BBPLL_TRIM_KVCO_SEL_WIDTH   ((uint8_t)0x00000002)
#define RIPL_DPLL_LOOP_DIV_SPI_EN_BIT    ((uint8_t)0x00000002)
#define RIPL_DPLL_LOOP_DIV_SPI_EN_POS    1
#define RIPL_DPLL_LOOP_DIV_BIT           ((uint8_t)0x00000001)
#define RIPL_DPLL_LOOP_DIV_POS           0

#define RIPL_BBPLL_TRIM_IBVCO_RST        0x3
#define RIPL_BBPLL_TRIM_KVCO_SEL_RST     0x1
#define RIPL_DPLL_LOOP_DIV_SPI_EN_RST    0x0
#define RIPL_DPLL_LOOP_DIV_RST           0x0

__INLINE void ripl_bbpll_ctrl1_pack(uint8_t bbplltrimibvco, uint8_t bbplltrimkvcosel, uint8_t dpllloopdivspien, uint8_t dpllloopdiv)
{
    ASSERT_ERR((((uint8_t)bbplltrimibvco << 4) & ~((uint8_t)0x00000070)) == 0);
    ASSERT_ERR((((uint8_t)bbplltrimkvcosel << 2) & ~((uint8_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint8_t)dpllloopdivspien << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)dpllloopdiv << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR,  ((uint8_t)bbplltrimibvco << 4) | ((uint8_t)bbplltrimkvcosel << 2) | ((uint8_t)dpllloopdivspien << 1) | ((uint8_t)dpllloopdiv << 0));
}

__INLINE void ripl_bbpll_ctrl1_unpack(uint8_t* bbplltrimibvco, uint8_t* bbplltrimkvcosel, uint8_t* dpllloopdivspien, uint8_t* dpllloopdiv)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
    *bbplltrimibvco = (localVal & ((uint8_t)0x00000070)) >> 4;
    *bbplltrimkvcosel = (localVal & ((uint8_t)0x0000000C)) >> 2;
    *dpllloopdivspien = (localVal & ((uint8_t)0x00000002)) >> 1;
    *dpllloopdiv = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_bbpll_trim_ibvco_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000070)) >> 4);
}

__INLINE void ripl_bbpll_trim_ibvco_setf(uint8_t bbplltrimibvco)
{
    ASSERT_ERR((((uint8_t)bbplltrimibvco << 4) & ~((uint8_t)0x00000070)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR) & ~((uint8_t)0x00000070)) | ((uint8_t)bbplltrimibvco << 4));
}

__INLINE uint8_t ripl_bbpll_trim_kvco_sel_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x0000000C)) >> 2);
}

__INLINE void ripl_bbpll_trim_kvco_sel_setf(uint8_t bbplltrimkvcosel)
{
    ASSERT_ERR((((uint8_t)bbplltrimkvcosel << 2) & ~((uint8_t)0x0000000C)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR) & ~((uint8_t)0x0000000C)) | ((uint8_t)bbplltrimkvcosel << 2));
}

__INLINE uint8_t ripl_dpll_loop_div_spi_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_dpll_loop_div_spi_en_setf(uint8_t dpllloopdivspien)
{
    ASSERT_ERR((((uint8_t)dpllloopdivspien << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)dpllloopdivspien << 1));
}

__INLINE uint8_t ripl_dpll_loop_div_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_dpll_loop_div_setf(uint8_t dpllloopdiv)
{
    ASSERT_ERR((((uint8_t)dpllloopdiv << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL1_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)dpllloopdiv << 0));
}

/**
 * @brief BBPLL_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05           BBPLL_LOCK   0
 *     04   BBPLL_TRIM_CODE_LOAD_OK   0
 *     03   IBVCO_1P2V_SPI_MUX   0
 *  02:00           IBVCO_1P2V   0x3
 * </pre>
 */
#define RIPL_BBPLL_CTRL2_ADDR   0x000000E4
#define RIPL_BBPLL_CTRL2_OFFSET 0x000000E4
#define RIPL_BBPLL_CTRL2_INDEX  0x000000E4
#define RIPL_BBPLL_CTRL2_RESET  0x00000003

__INLINE uint8_t ripl_bbpll_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
}

__INLINE void ripl_bbpll_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BBPLL_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_BBPLL_LOCK_BIT                 ((uint8_t)0x00000020)
#define RIPL_BBPLL_LOCK_POS                 5
#define RIPL_BBPLL_TRIM_CODE_LOAD_OK_BIT    ((uint8_t)0x00000010)
#define RIPL_BBPLL_TRIM_CODE_LOAD_OK_POS    4
#define RIPL_IBVCO_1P2V_SPI_MUX_BIT         ((uint8_t)0x00000008)
#define RIPL_IBVCO_1P2V_SPI_MUX_POS         3
#define RIPL_IBVCO_1P2V_MASK                ((uint8_t)0x00000007)
#define RIPL_IBVCO_1P2V_LSB                 0
#define RIPL_IBVCO_1P2V_WIDTH               ((uint8_t)0x00000003)

#define RIPL_BBPLL_LOCK_RST                 0x0
#define RIPL_BBPLL_TRIM_CODE_LOAD_OK_RST    0x0
#define RIPL_IBVCO_1P2V_SPI_MUX_RST         0x0
#define RIPL_IBVCO_1P2V_RST                 0x3

__INLINE void ripl_bbpll_ctrl2_pack(uint8_t bbplltrimcodeloadok, uint8_t ibvco1p2vspimux, uint8_t ibvco1p2v)
{
    ASSERT_ERR((((uint8_t)bbplltrimcodeloadok << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)ibvco1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)ibvco1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL2_ADDR,  ((uint8_t)bbplltrimcodeloadok << 4) | ((uint8_t)ibvco1p2vspimux << 3) | ((uint8_t)ibvco1p2v << 0));
}

__INLINE void ripl_bbpll_ctrl2_unpack(uint8_t* bbplllock, uint8_t* bbplltrimcodeloadok, uint8_t* ibvco1p2vspimux, uint8_t* ibvco1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
    *bbplllock = (localVal & ((uint8_t)0x00000020)) >> 5;
    *bbplltrimcodeloadok = (localVal & ((uint8_t)0x00000010)) >> 4;
    *ibvco1p2vspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *ibvco1p2v = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_bbpll_lock_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE uint8_t ripl_bbpll_trim_code_load_ok_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_bbpll_trim_code_load_ok_setf(uint8_t bbplltrimcodeloadok)
{
    ASSERT_ERR((((uint8_t)bbplltrimcodeloadok << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)bbplltrimcodeloadok << 4));
}

__INLINE uint8_t ripl_ibvco_1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_ibvco_1p2v_spi_mux_setf(uint8_t ibvco1p2vspimux)
{
    ASSERT_ERR((((uint8_t)ibvco1p2vspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)ibvco1p2vspimux << 3));
}

__INLINE uint8_t ripl_ibvco_1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_ibvco_1p2v_setf(uint8_t ibvco1p2v)
{
    ASSERT_ERR((((uint8_t)ibvco1p2v << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL2_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)ibvco1p2v << 0));
}

/**
 * @brief BBPLL_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   IBVCOBUFFER_1P2V_SPI_MUX   0
 *  05:04     IBVCOBUFFER_1P2V   0x3
 *     02   KVCO_SEL1P2V_SPI_MUX   1
 *  01:00         KVCO_SEL1P2V   0x1
 * </pre>
 */
#define RIPL_BBPLL_CTRL3_ADDR   0x000000E5
#define RIPL_BBPLL_CTRL3_OFFSET 0x000000E5
#define RIPL_BBPLL_CTRL3_INDEX  0x000000E5
#define RIPL_BBPLL_CTRL3_RESET  0x00000035

__INLINE uint8_t ripl_bbpll_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
}

__INLINE void ripl_bbpll_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_IBVCOBUFFER_1P2V_SPI_MUX_BIT    ((uint8_t)0x00000040)
#define RIPL_IBVCOBUFFER_1P2V_SPI_MUX_POS    6
#define RIPL_IBVCOBUFFER_1P2V_MASK           ((uint8_t)0x00000030)
#define RIPL_IBVCOBUFFER_1P2V_LSB            4
#define RIPL_IBVCOBUFFER_1P2V_WIDTH          ((uint8_t)0x00000002)
#define RIPL_KVCO_SEL1P2V_SPI_MUX_BIT        ((uint8_t)0x00000004)
#define RIPL_KVCO_SEL1P2V_SPI_MUX_POS        2
#define RIPL_KVCO_SEL1P2V_MASK               ((uint8_t)0x00000003)
#define RIPL_KVCO_SEL1P2V_LSB                0
#define RIPL_KVCO_SEL1P2V_WIDTH              ((uint8_t)0x00000002)

#define RIPL_IBVCOBUFFER_1P2V_SPI_MUX_RST    0x0
#define RIPL_IBVCOBUFFER_1P2V_RST            0x3
#define RIPL_KVCO_SEL1P2V_SPI_MUX_RST        0x1
#define RIPL_KVCO_SEL1P2V_RST                0x1

__INLINE void ripl_bbpll_ctrl3_pack(uint8_t ibvcobuffer1p2vspimux, uint8_t ibvcobuffer1p2v, uint8_t kvcosel1p2vspimux, uint8_t kvcosel1p2v)
{
    ASSERT_ERR((((uint8_t)ibvcobuffer1p2vspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)ibvcobuffer1p2v << 4) & ~((uint8_t)0x00000030)) == 0);
    ASSERT_ERR((((uint8_t)kvcosel1p2vspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)kvcosel1p2v << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR,  ((uint8_t)ibvcobuffer1p2vspimux << 6) | ((uint8_t)ibvcobuffer1p2v << 4) | ((uint8_t)kvcosel1p2vspimux << 2) | ((uint8_t)kvcosel1p2v << 0));
}

__INLINE void ripl_bbpll_ctrl3_unpack(uint8_t* ibvcobuffer1p2vspimux, uint8_t* ibvcobuffer1p2v, uint8_t* kvcosel1p2vspimux, uint8_t* kvcosel1p2v)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
    *ibvcobuffer1p2vspimux = (localVal & ((uint8_t)0x00000040)) >> 6;
    *ibvcobuffer1p2v = (localVal & ((uint8_t)0x00000030)) >> 4;
    *kvcosel1p2vspimux = (localVal & ((uint8_t)0x00000004)) >> 2;
    *kvcosel1p2v = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_ibvcobuffer_1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_ibvcobuffer_1p2v_spi_mux_setf(uint8_t ibvcobuffer1p2vspimux)
{
    ASSERT_ERR((((uint8_t)ibvcobuffer1p2vspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)ibvcobuffer1p2vspimux << 6));
}

__INLINE uint8_t ripl_ibvcobuffer_1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000030)) >> 4);
}

__INLINE void ripl_ibvcobuffer_1p2v_setf(uint8_t ibvcobuffer1p2v)
{
    ASSERT_ERR((((uint8_t)ibvcobuffer1p2v << 4) & ~((uint8_t)0x00000030)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR) & ~((uint8_t)0x00000030)) | ((uint8_t)ibvcobuffer1p2v << 4));
}

__INLINE uint8_t ripl_kvco_sel1p2v_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_kvco_sel1p2v_spi_mux_setf(uint8_t kvcosel1p2vspimux)
{
    ASSERT_ERR((((uint8_t)kvcosel1p2vspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)kvcosel1p2vspimux << 2));
}

__INLINE uint8_t ripl_kvco_sel1p2v_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_kvco_sel1p2v_setf(uint8_t kvcosel1p2v)
{
    ASSERT_ERR((((uint8_t)kvcosel1p2v << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_BBPLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_BBPLL_CTRL3_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)kvcosel1p2v << 0));
}

/**
 * @brief RF_PLL_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05    RPLL_IVCO_SPI_MUX   0
 *  04:00            RPLL_IVCO   0x1F
 * </pre>
 */
#define RIPL_RF_PLL_CTRL1_ADDR   0x000000E8
#define RIPL_RF_PLL_CTRL1_OFFSET 0x000000E8
#define RIPL_RF_PLL_CTRL1_INDEX  0x000000E8
#define RIPL_RF_PLL_CTRL1_RESET  0x0000001F

__INLINE uint8_t ripl_rf_pll_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR);
}

__INLINE void ripl_rf_pll_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_RPLL_IVCO_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_RPLL_IVCO_SPI_MUX_POS    5
#define RIPL_RPLL_IVCO_MASK           ((uint8_t)0x0000001F)
#define RIPL_RPLL_IVCO_LSB            0
#define RIPL_RPLL_IVCO_WIDTH          ((uint8_t)0x00000005)

#define RIPL_RPLL_IVCO_SPI_MUX_RST    0x0
#define RIPL_RPLL_IVCO_RST            0x1F

__INLINE void ripl_rf_pll_ctrl1_pack(uint8_t rpllivcospimux, uint8_t rpllivco)
{
    ASSERT_ERR((((uint8_t)rpllivcospimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)rpllivco << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL1_ADDR,  ((uint8_t)rpllivcospimux << 5) | ((uint8_t)rpllivco << 0));
}

__INLINE void ripl_rf_pll_ctrl1_unpack(uint8_t* rpllivcospimux, uint8_t* rpllivco)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR);
    *rpllivcospimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *rpllivco = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_rpll_ivco_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_rpll_ivco_spi_mux_setf(uint8_t rpllivcospimux)
{
    ASSERT_ERR((((uint8_t)rpllivcospimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)rpllivcospimux << 5));
}

__INLINE uint8_t ripl_rpll_ivco_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_rpll_ivco_setf(uint8_t rpllivco)
{
    ASSERT_ERR((((uint8_t)rpllivco << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL1_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL1_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)rpllivco << 0));
}

/**
 * @brief RF_PLL_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   RPLL_IVCO_BUF_TRIM_SPI_MUX   0
 *  02:00   RPLL_IVCO_BUF_TRIM   0x3
 * </pre>
 */
#define RIPL_RF_PLL_CTRL2_ADDR   0x000000E9
#define RIPL_RF_PLL_CTRL2_OFFSET 0x000000E9
#define RIPL_RF_PLL_CTRL2_INDEX  0x000000E9
#define RIPL_RF_PLL_CTRL2_RESET  0x00000003

__INLINE uint8_t ripl_rf_pll_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR);
}

__INLINE void ripl_rf_pll_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_RPLL_IVCO_BUF_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000008)
#define RIPL_RPLL_IVCO_BUF_TRIM_SPI_MUX_POS    3
#define RIPL_RPLL_IVCO_BUF_TRIM_MASK           ((uint8_t)0x00000007)
#define RIPL_RPLL_IVCO_BUF_TRIM_LSB            0
#define RIPL_RPLL_IVCO_BUF_TRIM_WIDTH          ((uint8_t)0x00000003)

#define RIPL_RPLL_IVCO_BUF_TRIM_SPI_MUX_RST    0x0
#define RIPL_RPLL_IVCO_BUF_TRIM_RST            0x3

__INLINE void ripl_rf_pll_ctrl2_pack(uint8_t rpllivcobuftrimspimux, uint8_t rpllivcobuftrim)
{
    ASSERT_ERR((((uint8_t)rpllivcobuftrimspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)rpllivcobuftrim << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL2_ADDR,  ((uint8_t)rpllivcobuftrimspimux << 3) | ((uint8_t)rpllivcobuftrim << 0));
}

__INLINE void ripl_rf_pll_ctrl2_unpack(uint8_t* rpllivcobuftrimspimux, uint8_t* rpllivcobuftrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR);
    *rpllivcobuftrimspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *rpllivcobuftrim = (localVal & ((uint8_t)0x00000007)) >> 0;
}

__INLINE uint8_t ripl_rpll_ivco_buf_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_rpll_ivco_buf_trim_spi_mux_setf(uint8_t rpllivcobuftrimspimux)
{
    ASSERT_ERR((((uint8_t)rpllivcobuftrimspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)rpllivcobuftrimspimux << 3));
}

__INLINE uint8_t ripl_rpll_ivco_buf_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000007)) >> 0);
}

__INLINE void ripl_rpll_ivco_buf_trim_setf(uint8_t rpllivcobuftrim)
{
    ASSERT_ERR((((uint8_t)rpllivcobuftrim << 0) & ~((uint8_t)0x00000007)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL2_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL2_ADDR) & ~((uint8_t)0x00000007)) | ((uint8_t)rpllivcobuftrim << 0));
}

/**
 * @brief RF_PLL_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   RPLL_LD_UNLOCK_CNT_SPI_MUX   0
 *     05   RPLL_VCOFC_SPI_MUX   1
 *  04:00           RPLL_VCOFC   0x0
 * </pre>
 */
#define RIPL_RF_PLL_CTRL3_ADDR   0x000000EA
#define RIPL_RF_PLL_CTRL3_OFFSET 0x000000EA
#define RIPL_RF_PLL_CTRL3_INDEX  0x000000EA
#define RIPL_RF_PLL_CTRL3_RESET  0x00000020

__INLINE uint8_t ripl_rf_pll_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR);
}

__INLINE void ripl_rf_pll_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_RPLL_LD_UNLOCK_CNT_SPI_MUX_BIT    ((uint8_t)0x00000040)
#define RIPL_RPLL_LD_UNLOCK_CNT_SPI_MUX_POS    6
#define RIPL_RPLL_VCOFC_SPI_MUX_BIT            ((uint8_t)0x00000020)
#define RIPL_RPLL_VCOFC_SPI_MUX_POS            5
#define RIPL_RPLL_VCOFC_MASK                   ((uint8_t)0x0000001F)
#define RIPL_RPLL_VCOFC_LSB                    0
#define RIPL_RPLL_VCOFC_WIDTH                  ((uint8_t)0x00000005)

#define RIPL_RPLL_LD_UNLOCK_CNT_SPI_MUX_RST    0x0
#define RIPL_RPLL_VCOFC_SPI_MUX_RST            0x1
#define RIPL_RPLL_VCOFC_RST                    0x0

__INLINE void ripl_rf_pll_ctrl3_pack(uint8_t rpllldunlockcntspimux, uint8_t rpllvcofcspimux, uint8_t rpllvcofc)
{
    ASSERT_ERR((((uint8_t)rpllldunlockcntspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)rpllvcofcspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)rpllvcofc << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL3_ADDR,  ((uint8_t)rpllldunlockcntspimux << 6) | ((uint8_t)rpllvcofcspimux << 5) | ((uint8_t)rpllvcofc << 0));
}

__INLINE void ripl_rf_pll_ctrl3_unpack(uint8_t* rpllldunlockcntspimux, uint8_t* rpllvcofcspimux, uint8_t* rpllvcofc)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR);
    *rpllldunlockcntspimux = (localVal & ((uint8_t)0x00000040)) >> 6;
    *rpllvcofcspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *rpllvcofc = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_rpll_ld_unlock_cnt_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_rpll_ld_unlock_cnt_spi_mux_setf(uint8_t rpllldunlockcntspimux)
{
    ASSERT_ERR((((uint8_t)rpllldunlockcntspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)rpllldunlockcntspimux << 6));
}

__INLINE uint8_t ripl_rpll_vcofc_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_rpll_vcofc_spi_mux_setf(uint8_t rpllvcofcspimux)
{
    ASSERT_ERR((((uint8_t)rpllvcofcspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)rpllvcofcspimux << 5));
}

__INLINE uint8_t ripl_rpll_vcofc_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_rpll_vcofc_setf(uint8_t rpllvcofc)
{
    ASSERT_ERR((((uint8_t)rpllvcofc << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL3_ADDR, (REG_RIPL_RD(RIPL_RF_PLL_CTRL3_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)rpllvcofc << 0));
}

/**
 * @brief RF_PLL_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00   RPLL_LD_UNLOCK_CNT   0x3
 * </pre>
 */
#define RIPL_RF_PLL_CTRL4_ADDR   0x000000EB
#define RIPL_RF_PLL_CTRL4_OFFSET 0x000000EB
#define RIPL_RF_PLL_CTRL4_INDEX  0x000000EB
#define RIPL_RF_PLL_CTRL4_RESET  0x00000003

__INLINE uint8_t ripl_rf_pll_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_RF_PLL_CTRL4_ADDR);
}

__INLINE void ripl_rf_pll_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_RF_PLL_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_RPLL_LD_UNLOCK_CNT_MASK   ((uint8_t)0x000000FF)
#define RIPL_RPLL_LD_UNLOCK_CNT_LSB    0
#define RIPL_RPLL_LD_UNLOCK_CNT_WIDTH  ((uint8_t)0x00000008)

#define RIPL_RPLL_LD_UNLOCK_CNT_RST    0x3

__INLINE uint8_t ripl_rpll_ld_unlock_cnt_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_RF_PLL_CTRL4_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_rpll_ld_unlock_cnt_setf(uint8_t rpllldunlockcnt)
{
    ASSERT_ERR((((uint8_t)rpllldunlockcnt << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_RF_PLL_CTRL4_ADDR, (uint8_t)rpllldunlockcnt << 0);
}

/**
 * @brief LDOS_IN_BT_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05      TRIM_IN_SPI_MUX   0
 *  04:00              TRIM_IN   0x4
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL1_ADDR   0x000000F0
#define RIPL_LDOS_IN_BT_CTRL1_OFFSET 0x000000F0
#define RIPL_LDOS_IN_BT_CTRL1_INDEX  0x000000F0
#define RIPL_LDOS_IN_BT_CTRL1_RESET  0x00000004

__INLINE uint8_t ripl_ldos_in_bt_ctrl1_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL1_ADDR, value);
}

// field definitions
#define RIPL_TRIM_IN_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_TRIM_IN_SPI_MUX_POS    5
#define RIPL_TRIM_IN_MASK           ((uint8_t)0x0000001F)
#define RIPL_TRIM_IN_LSB            0
#define RIPL_TRIM_IN_WIDTH          ((uint8_t)0x00000005)

#define RIPL_TRIM_IN_SPI_MUX_RST    0x0
#define RIPL_TRIM_IN_RST            0x4

__INLINE void ripl_ldos_in_bt_ctrl1_pack(uint8_t triminspimux, uint8_t trimin)
{
    ASSERT_ERR((((uint8_t)triminspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)trimin << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL1_ADDR,  ((uint8_t)triminspimux << 5) | ((uint8_t)trimin << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl1_unpack(uint8_t* triminspimux, uint8_t* trimin)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR);
    *triminspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *trimin = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_trim_in_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_trim_in_spi_mux_setf(uint8_t triminspimux)
{
    ASSERT_ERR((((uint8_t)triminspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)triminspimux << 5));
}

__INLINE uint8_t ripl_trim_in_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_trim_in_setf(uint8_t trimin)
{
    ASSERT_ERR((((uint8_t)trimin << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL1_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL1_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)trimin << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06   LDO_RXTX_BYPASS_SPI_MUX   0
 *     05      LDO_RXTX_BYPASS   0
 *     04   LDO_XO_BYPASS_SPI_MUX   0
 *     03        LDO_XO_BYPASS   0
 *     02   LDO_XO_TRIM_SPI_MUX   0
 *  01:00          LDO_XO_TRIM   0x0
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL2_ADDR   0x000000F1
#define RIPL_LDOS_IN_BT_CTRL2_OFFSET 0x000000F1
#define RIPL_LDOS_IN_BT_CTRL2_INDEX  0x000000F1
#define RIPL_LDOS_IN_BT_CTRL2_RESET  0x00000000

__INLINE uint8_t ripl_ldos_in_bt_ctrl2_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, value);
}

// field definitions
#define RIPL_LDO_RXTX_BYPASS_SPI_MUX_BIT    ((uint8_t)0x00000040)
#define RIPL_LDO_RXTX_BYPASS_SPI_MUX_POS    6
#define RIPL_LDO_RXTX_BYPASS_BIT            ((uint8_t)0x00000020)
#define RIPL_LDO_RXTX_BYPASS_POS            5
#define RIPL_LDO_XO_BYPASS_SPI_MUX_BIT      ((uint8_t)0x00000010)
#define RIPL_LDO_XO_BYPASS_SPI_MUX_POS      4
#define RIPL_LDO_XO_BYPASS_BIT              ((uint8_t)0x00000008)
#define RIPL_LDO_XO_BYPASS_POS              3
#define RIPL_LDO_XO_TRIM_SPI_MUX_BIT        ((uint8_t)0x00000004)
#define RIPL_LDO_XO_TRIM_SPI_MUX_POS        2
#define RIPL_LDO_XO_TRIM_MASK               ((uint8_t)0x00000003)
#define RIPL_LDO_XO_TRIM_LSB                0
#define RIPL_LDO_XO_TRIM_WIDTH              ((uint8_t)0x00000002)

#define RIPL_LDO_RXTX_BYPASS_SPI_MUX_RST    0x0
#define RIPL_LDO_RXTX_BYPASS_RST            0x0
#define RIPL_LDO_XO_BYPASS_SPI_MUX_RST      0x0
#define RIPL_LDO_XO_BYPASS_RST              0x0
#define RIPL_LDO_XO_TRIM_SPI_MUX_RST        0x0
#define RIPL_LDO_XO_TRIM_RST                0x0

__INLINE void ripl_ldos_in_bt_ctrl2_pack(uint8_t ldorxtxbypassspimux, uint8_t ldorxtxbypass, uint8_t ldoxobypassspimux, uint8_t ldoxobypass, uint8_t ldoxotrimspimux, uint8_t ldoxotrim)
{
    ASSERT_ERR((((uint8_t)ldorxtxbypassspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)ldorxtxbypass << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldoxobypassspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)ldoxobypass << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)ldoxotrimspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)ldoxotrim << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR,  ((uint8_t)ldorxtxbypassspimux << 6) | ((uint8_t)ldorxtxbypass << 5) | ((uint8_t)ldoxobypassspimux << 4) | ((uint8_t)ldoxobypass << 3) | ((uint8_t)ldoxotrimspimux << 2) | ((uint8_t)ldoxotrim << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl2_unpack(uint8_t* ldorxtxbypassspimux, uint8_t* ldorxtxbypass, uint8_t* ldoxobypassspimux, uint8_t* ldoxobypass, uint8_t* ldoxotrimspimux, uint8_t* ldoxotrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    *ldorxtxbypassspimux = (localVal & ((uint8_t)0x00000040)) >> 6;
    *ldorxtxbypass = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldoxobypassspimux = (localVal & ((uint8_t)0x00000010)) >> 4;
    *ldoxobypass = (localVal & ((uint8_t)0x00000008)) >> 3;
    *ldoxotrimspimux = (localVal & ((uint8_t)0x00000004)) >> 2;
    *ldoxotrim = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_ldo_rxtx_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_ldo_rxtx_bypass_spi_mux_setf(uint8_t ldorxtxbypassspimux)
{
    ASSERT_ERR((((uint8_t)ldorxtxbypassspimux << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)ldorxtxbypassspimux << 6));
}

__INLINE uint8_t ripl_ldo_rxtx_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_rxtx_bypass_setf(uint8_t ldorxtxbypass)
{
    ASSERT_ERR((((uint8_t)ldorxtxbypass << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldorxtxbypass << 5));
}

__INLINE uint8_t ripl_ldo_xo_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_ldo_xo_bypass_spi_mux_setf(uint8_t ldoxobypassspimux)
{
    ASSERT_ERR((((uint8_t)ldoxobypassspimux << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)ldoxobypassspimux << 4));
}

__INLINE uint8_t ripl_ldo_xo_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_ldo_xo_bypass_setf(uint8_t ldoxobypass)
{
    ASSERT_ERR((((uint8_t)ldoxobypass << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)ldoxobypass << 3));
}

__INLINE uint8_t ripl_ldo_xo_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_ldo_xo_trim_spi_mux_setf(uint8_t ldoxotrimspimux)
{
    ASSERT_ERR((((uint8_t)ldoxotrimspimux << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)ldoxotrimspimux << 2));
}

__INLINE uint8_t ripl_ldo_xo_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

__INLINE void ripl_ldo_xo_trim_setf(uint8_t ldoxotrim)
{
    ASSERT_ERR((((uint8_t)ldoxotrim << 0) & ~((uint8_t)0x00000003)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL2_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL2_ADDR) & ~((uint8_t)0x00000003)) | ((uint8_t)ldoxotrim << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   LDO_VCO_TRIM_SPI_MUX   0
 *  04:00         LDO_VCO_TRIM   0x4
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL3_ADDR   0x000000F2
#define RIPL_LDOS_IN_BT_CTRL3_OFFSET 0x000000F2
#define RIPL_LDOS_IN_BT_CTRL3_INDEX  0x000000F2
#define RIPL_LDOS_IN_BT_CTRL3_RESET  0x00000004

__INLINE uint8_t ripl_ldos_in_bt_ctrl3_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL3_ADDR, value);
}

// field definitions
#define RIPL_LDO_VCO_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_LDO_VCO_TRIM_SPI_MUX_POS    5
#define RIPL_LDO_VCO_TRIM_MASK           ((uint8_t)0x0000001F)
#define RIPL_LDO_VCO_TRIM_LSB            0
#define RIPL_LDO_VCO_TRIM_WIDTH          ((uint8_t)0x00000005)

#define RIPL_LDO_VCO_TRIM_SPI_MUX_RST    0x0
#define RIPL_LDO_VCO_TRIM_RST            0x4

__INLINE void ripl_ldos_in_bt_ctrl3_pack(uint8_t ldovcotrimspimux, uint8_t ldovcotrim)
{
    ASSERT_ERR((((uint8_t)ldovcotrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldovcotrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL3_ADDR,  ((uint8_t)ldovcotrimspimux << 5) | ((uint8_t)ldovcotrim << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl3_unpack(uint8_t* ldovcotrimspimux, uint8_t* ldovcotrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR);
    *ldovcotrimspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldovcotrim = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_ldo_vco_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_vco_trim_spi_mux_setf(uint8_t ldovcotrimspimux)
{
    ASSERT_ERR((((uint8_t)ldovcotrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldovcotrimspimux << 5));
}

__INLINE uint8_t ripl_ldo_vco_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_ldo_vco_trim_setf(uint8_t ldovcotrim)
{
    ASSERT_ERR((((uint8_t)ldovcotrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL3_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL3_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)ldovcotrim << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   LDO_BB_TRIM_SPI_MUX   0
 *  04:00          LDO_BB_TRIM   0x4
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL4_ADDR   0x000000F3
#define RIPL_LDOS_IN_BT_CTRL4_OFFSET 0x000000F3
#define RIPL_LDOS_IN_BT_CTRL4_INDEX  0x000000F3
#define RIPL_LDOS_IN_BT_CTRL4_RESET  0x00000004

__INLINE uint8_t ripl_ldos_in_bt_ctrl4_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl4_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL4_ADDR, value);
}

// field definitions
#define RIPL_LDO_BB_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_LDO_BB_TRIM_SPI_MUX_POS    5
#define RIPL_LDO_BB_TRIM_MASK           ((uint8_t)0x0000001F)
#define RIPL_LDO_BB_TRIM_LSB            0
#define RIPL_LDO_BB_TRIM_WIDTH          ((uint8_t)0x00000005)

#define RIPL_LDO_BB_TRIM_SPI_MUX_RST    0x0
#define RIPL_LDO_BB_TRIM_RST            0x4

__INLINE void ripl_ldos_in_bt_ctrl4_pack(uint8_t ldobbtrimspimux, uint8_t ldobbtrim)
{
    ASSERT_ERR((((uint8_t)ldobbtrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldobbtrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL4_ADDR,  ((uint8_t)ldobbtrimspimux << 5) | ((uint8_t)ldobbtrim << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl4_unpack(uint8_t* ldobbtrimspimux, uint8_t* ldobbtrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR);
    *ldobbtrimspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldobbtrim = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_ldo_bb_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_bb_trim_spi_mux_setf(uint8_t ldobbtrimspimux)
{
    ASSERT_ERR((((uint8_t)ldobbtrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL4_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldobbtrimspimux << 5));
}

__INLINE uint8_t ripl_ldo_bb_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_ldo_bb_trim_setf(uint8_t ldobbtrim)
{
    ASSERT_ERR((((uint8_t)ldobbtrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL4_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL4_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)ldobbtrim << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   LDO_BBPLL_ON_SPI_MUX   1
 *     04         LDO_BBPLL_ON   1
 *     03   LDO_BB_BYPASS_SPI_MUX   0
 *     02        LDO_BB_BYPASS   0
 *     01   LDO_VCO_BYPASS_SPI_MUX   0
 *     00       LDO_VCO_BYPASS   0
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL5_ADDR   0x000000F4
#define RIPL_LDOS_IN_BT_CTRL5_OFFSET 0x000000F4
#define RIPL_LDOS_IN_BT_CTRL5_INDEX  0x000000F4
#define RIPL_LDOS_IN_BT_CTRL5_RESET  0x00000030

__INLINE uint8_t ripl_ldos_in_bt_ctrl5_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl5_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, value);
}

// field definitions
#define RIPL_LDO_BBPLL_ON_SPI_MUX_BIT      ((uint8_t)0x00000020)
#define RIPL_LDO_BBPLL_ON_SPI_MUX_POS      5
#define RIPL_LDO_BBPLL_ON_BIT              ((uint8_t)0x00000010)
#define RIPL_LDO_BBPLL_ON_POS              4
#define RIPL_LDO_BB_BYPASS_SPI_MUX_BIT     ((uint8_t)0x00000008)
#define RIPL_LDO_BB_BYPASS_SPI_MUX_POS     3
#define RIPL_LDO_BB_BYPASS_BIT             ((uint8_t)0x00000004)
#define RIPL_LDO_BB_BYPASS_POS             2
#define RIPL_LDO_VCO_BYPASS_SPI_MUX_BIT    ((uint8_t)0x00000002)
#define RIPL_LDO_VCO_BYPASS_SPI_MUX_POS    1
#define RIPL_LDO_VCO_BYPASS_BIT            ((uint8_t)0x00000001)
#define RIPL_LDO_VCO_BYPASS_POS            0

#define RIPL_LDO_BBPLL_ON_SPI_MUX_RST      0x1
#define RIPL_LDO_BBPLL_ON_RST              0x1
#define RIPL_LDO_BB_BYPASS_SPI_MUX_RST     0x0
#define RIPL_LDO_BB_BYPASS_RST             0x0
#define RIPL_LDO_VCO_BYPASS_SPI_MUX_RST    0x0
#define RIPL_LDO_VCO_BYPASS_RST            0x0

__INLINE void ripl_ldos_in_bt_ctrl5_pack(uint8_t ldobbpllonspimux, uint8_t ldobbpllon, uint8_t ldobbbypassspimux, uint8_t ldobbbypass, uint8_t ldovcobypassspimux, uint8_t ldovcobypass)
{
    ASSERT_ERR((((uint8_t)ldobbpllonspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldobbpllon << 4) & ~((uint8_t)0x00000010)) == 0);
    ASSERT_ERR((((uint8_t)ldobbbypassspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)ldobbbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)ldovcobypassspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)ldovcobypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR,  ((uint8_t)ldobbpllonspimux << 5) | ((uint8_t)ldobbpllon << 4) | ((uint8_t)ldobbbypassspimux << 3) | ((uint8_t)ldobbbypass << 2) | ((uint8_t)ldovcobypassspimux << 1) | ((uint8_t)ldovcobypass << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl5_unpack(uint8_t* ldobbpllonspimux, uint8_t* ldobbpllon, uint8_t* ldobbbypassspimux, uint8_t* ldobbbypass, uint8_t* ldovcobypassspimux, uint8_t* ldovcobypass)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    *ldobbpllonspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldobbpllon = (localVal & ((uint8_t)0x00000010)) >> 4;
    *ldobbbypassspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *ldobbbypass = (localVal & ((uint8_t)0x00000004)) >> 2;
    *ldovcobypassspimux = (localVal & ((uint8_t)0x00000002)) >> 1;
    *ldovcobypass = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_ldo_bbpll_on_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_bbpll_on_spi_mux_setf(uint8_t ldobbpllonspimux)
{
    ASSERT_ERR((((uint8_t)ldobbpllonspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldobbpllonspimux << 5));
}

__INLINE uint8_t ripl_ldo_bbpll_on_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000010)) >> 4);
}

__INLINE void ripl_ldo_bbpll_on_setf(uint8_t ldobbpllon)
{
    ASSERT_ERR((((uint8_t)ldobbpllon << 4) & ~((uint8_t)0x00000010)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000010)) | ((uint8_t)ldobbpllon << 4));
}

__INLINE uint8_t ripl_ldo_bb_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_ldo_bb_bypass_spi_mux_setf(uint8_t ldobbbypassspimux)
{
    ASSERT_ERR((((uint8_t)ldobbbypassspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)ldobbbypassspimux << 3));
}

__INLINE uint8_t ripl_ldo_bb_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_ldo_bb_bypass_setf(uint8_t ldobbbypass)
{
    ASSERT_ERR((((uint8_t)ldobbbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)ldobbbypass << 2));
}

__INLINE uint8_t ripl_ldo_vco_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_ldo_vco_bypass_spi_mux_setf(uint8_t ldovcobypassspimux)
{
    ASSERT_ERR((((uint8_t)ldovcobypassspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)ldovcobypassspimux << 1));
}

__INLINE uint8_t ripl_ldo_vco_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_ldo_vco_bypass_setf(uint8_t ldovcobypass)
{
    ASSERT_ERR((((uint8_t)ldovcobypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL5_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL5_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)ldovcobypass << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   LDO_BBPLL_TRIM_SPI_MUX   0
 *  04:00       LDO_BBPLL_TRIM   0x4
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL6_ADDR   0x000000F5
#define RIPL_LDOS_IN_BT_CTRL6_OFFSET 0x000000F5
#define RIPL_LDOS_IN_BT_CTRL6_INDEX  0x000000F5
#define RIPL_LDOS_IN_BT_CTRL6_RESET  0x00000004

__INLINE uint8_t ripl_ldos_in_bt_ctrl6_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl6_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL6_ADDR, value);
}

// field definitions
#define RIPL_LDO_BBPLL_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_LDO_BBPLL_TRIM_SPI_MUX_POS    5
#define RIPL_LDO_BBPLL_TRIM_MASK           ((uint8_t)0x0000001F)
#define RIPL_LDO_BBPLL_TRIM_LSB            0
#define RIPL_LDO_BBPLL_TRIM_WIDTH          ((uint8_t)0x00000005)

#define RIPL_LDO_BBPLL_TRIM_SPI_MUX_RST    0x0
#define RIPL_LDO_BBPLL_TRIM_RST            0x4

__INLINE void ripl_ldos_in_bt_ctrl6_pack(uint8_t ldobbplltrimspimux, uint8_t ldobbplltrim)
{
    ASSERT_ERR((((uint8_t)ldobbplltrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldobbplltrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL6_ADDR,  ((uint8_t)ldobbplltrimspimux << 5) | ((uint8_t)ldobbplltrim << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl6_unpack(uint8_t* ldobbplltrimspimux, uint8_t* ldobbplltrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR);
    *ldobbplltrimspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldobbplltrim = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_ldo_bbpll_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_bbpll_trim_spi_mux_setf(uint8_t ldobbplltrimspimux)
{
    ASSERT_ERR((((uint8_t)ldobbplltrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL6_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldobbplltrimspimux << 5));
}

__INLINE uint8_t ripl_ldo_bbpll_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_ldo_bbpll_trim_setf(uint8_t ldobbplltrim)
{
    ASSERT_ERR((((uint8_t)ldobbplltrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL6_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL6_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)ldobbplltrim << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05   LDO_PLL_TRIM_SPI_MUX   0
 *  04:00         LDO_PLL_TRIM   0x4
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL7_ADDR   0x000000F6
#define RIPL_LDOS_IN_BT_CTRL7_OFFSET 0x000000F6
#define RIPL_LDOS_IN_BT_CTRL7_INDEX  0x000000F6
#define RIPL_LDOS_IN_BT_CTRL7_RESET  0x00000004

__INLINE uint8_t ripl_ldos_in_bt_ctrl7_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl7_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL7_ADDR, value);
}

// field definitions
#define RIPL_LDO_PLL_TRIM_SPI_MUX_BIT    ((uint8_t)0x00000020)
#define RIPL_LDO_PLL_TRIM_SPI_MUX_POS    5
#define RIPL_LDO_PLL_TRIM_MASK           ((uint8_t)0x0000001F)
#define RIPL_LDO_PLL_TRIM_LSB            0
#define RIPL_LDO_PLL_TRIM_WIDTH          ((uint8_t)0x00000005)

#define RIPL_LDO_PLL_TRIM_SPI_MUX_RST    0x0
#define RIPL_LDO_PLL_TRIM_RST            0x4

__INLINE void ripl_ldos_in_bt_ctrl7_pack(uint8_t ldoplltrimspimux, uint8_t ldoplltrim)
{
    ASSERT_ERR((((uint8_t)ldoplltrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    ASSERT_ERR((((uint8_t)ldoplltrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL7_ADDR,  ((uint8_t)ldoplltrimspimux << 5) | ((uint8_t)ldoplltrim << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl7_unpack(uint8_t* ldoplltrimspimux, uint8_t* ldoplltrim)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR);
    *ldoplltrimspimux = (localVal & ((uint8_t)0x00000020)) >> 5;
    *ldoplltrim = (localVal & ((uint8_t)0x0000001F)) >> 0;
}

__INLINE uint8_t ripl_ldo_pll_trim_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x00000020)) >> 5);
}

__INLINE void ripl_ldo_pll_trim_spi_mux_setf(uint8_t ldoplltrimspimux)
{
    ASSERT_ERR((((uint8_t)ldoplltrimspimux << 5) & ~((uint8_t)0x00000020)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR) & ~((uint8_t)0x00000020)) | ((uint8_t)ldoplltrimspimux << 5));
}

__INLINE uint8_t ripl_ldo_pll_trim_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR);
    return ((localVal & ((uint8_t)0x0000001F)) >> 0);
}

__INLINE void ripl_ldo_pll_trim_setf(uint8_t ldoplltrim)
{
    ASSERT_ERR((((uint8_t)ldoplltrim << 0) & ~((uint8_t)0x0000001F)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL7_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL7_ADDR) & ~((uint8_t)0x0000001F)) | ((uint8_t)ldoplltrim << 0));
}

/**
 * @brief LDOS_IN_BT_CTRL8 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   LDO_PLL_BYPASS_SPI_MUX   0
 *     02       LDO_PLL_BYPASS   0
 *     01   LDO_BBPLL_BYPASS_SPI_MUX   0
 *     00     LDO_BBPLL_BYPASS   0
 * </pre>
 */
#define RIPL_LDOS_IN_BT_CTRL8_ADDR   0x000000F7
#define RIPL_LDOS_IN_BT_CTRL8_OFFSET 0x000000F7
#define RIPL_LDOS_IN_BT_CTRL8_INDEX  0x000000F7
#define RIPL_LDOS_IN_BT_CTRL8_RESET  0x00000000

__INLINE uint8_t ripl_ldos_in_bt_ctrl8_get(void)
{
    return REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
}

__INLINE void ripl_ldos_in_bt_ctrl8_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR, value);
}

// field definitions
#define RIPL_LDO_PLL_BYPASS_SPI_MUX_BIT      ((uint8_t)0x00000008)
#define RIPL_LDO_PLL_BYPASS_SPI_MUX_POS      3
#define RIPL_LDO_PLL_BYPASS_BIT              ((uint8_t)0x00000004)
#define RIPL_LDO_PLL_BYPASS_POS              2
#define RIPL_LDO_BBPLL_BYPASS_SPI_MUX_BIT    ((uint8_t)0x00000002)
#define RIPL_LDO_BBPLL_BYPASS_SPI_MUX_POS    1
#define RIPL_LDO_BBPLL_BYPASS_BIT            ((uint8_t)0x00000001)
#define RIPL_LDO_BBPLL_BYPASS_POS            0

#define RIPL_LDO_PLL_BYPASS_SPI_MUX_RST      0x0
#define RIPL_LDO_PLL_BYPASS_RST              0x0
#define RIPL_LDO_BBPLL_BYPASS_SPI_MUX_RST    0x0
#define RIPL_LDO_BBPLL_BYPASS_RST            0x0

__INLINE void ripl_ldos_in_bt_ctrl8_pack(uint8_t ldopllbypassspimux, uint8_t ldopllbypass, uint8_t ldobbpllbypassspimux, uint8_t ldobbpllbypass)
{
    ASSERT_ERR((((uint8_t)ldopllbypassspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    ASSERT_ERR((((uint8_t)ldopllbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    ASSERT_ERR((((uint8_t)ldobbpllbypassspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    ASSERT_ERR((((uint8_t)ldobbpllbypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR,  ((uint8_t)ldopllbypassspimux << 3) | ((uint8_t)ldopllbypass << 2) | ((uint8_t)ldobbpllbypassspimux << 1) | ((uint8_t)ldobbpllbypass << 0));
}

__INLINE void ripl_ldos_in_bt_ctrl8_unpack(uint8_t* ldopllbypassspimux, uint8_t* ldopllbypass, uint8_t* ldobbpllbypassspimux, uint8_t* ldobbpllbypass)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
    *ldopllbypassspimux = (localVal & ((uint8_t)0x00000008)) >> 3;
    *ldopllbypass = (localVal & ((uint8_t)0x00000004)) >> 2;
    *ldobbpllbypassspimux = (localVal & ((uint8_t)0x00000002)) >> 1;
    *ldobbpllbypass = (localVal & ((uint8_t)0x00000001)) >> 0;
}

__INLINE uint8_t ripl_ldo_pll_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000008)) >> 3);
}

__INLINE void ripl_ldo_pll_bypass_spi_mux_setf(uint8_t ldopllbypassspimux)
{
    ASSERT_ERR((((uint8_t)ldopllbypassspimux << 3) & ~((uint8_t)0x00000008)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR) & ~((uint8_t)0x00000008)) | ((uint8_t)ldopllbypassspimux << 3));
}

__INLINE uint8_t ripl_ldo_pll_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE void ripl_ldo_pll_bypass_setf(uint8_t ldopllbypass)
{
    ASSERT_ERR((((uint8_t)ldopllbypass << 2) & ~((uint8_t)0x00000004)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR) & ~((uint8_t)0x00000004)) | ((uint8_t)ldopllbypass << 2));
}

__INLINE uint8_t ripl_ldo_bbpll_bypass_spi_mux_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000002)) >> 1);
}

__INLINE void ripl_ldo_bbpll_bypass_spi_mux_setf(uint8_t ldobbpllbypassspimux)
{
    ASSERT_ERR((((uint8_t)ldobbpllbypassspimux << 1) & ~((uint8_t)0x00000002)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR) & ~((uint8_t)0x00000002)) | ((uint8_t)ldobbpllbypassspimux << 1));
}

__INLINE uint8_t ripl_ldo_bbpll_bypass_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR);
    return ((localVal & ((uint8_t)0x00000001)) >> 0);
}

__INLINE void ripl_ldo_bbpll_bypass_setf(uint8_t ldobbpllbypass)
{
    ASSERT_ERR((((uint8_t)ldobbpllbypass << 0) & ~((uint8_t)0x00000001)) == 0);
    REG_RIPL_WR(RIPL_LDOS_IN_BT_CTRL8_ADDR, (REG_RIPL_RD(RIPL_LDOS_IN_BT_CTRL8_ADDR) & ~((uint8_t)0x00000001)) | ((uint8_t)ldobbpllbypass << 0));
}

/**
 * @brief SAR_ADC0_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC0_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC0_VAL_L_ADDR   0x00000110
#define RIPL_SAR_ADC0_VAL_L_OFFSET 0x00000110
#define RIPL_SAR_ADC0_VAL_L_INDEX  0x00000110
#define RIPL_SAR_ADC0_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc0_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC0_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC0_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC0_VAL_L_LSB    0
#define RIPL_SAR_ADC0_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC0_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc0_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC0_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC0_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC0_DONE   0
 *  01:00       SAR_ADC0_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC0_VAL_H_ADDR   0x00000111
#define RIPL_SAR_ADC0_VAL_H_OFFSET 0x00000111
#define RIPL_SAR_ADC0_VAL_H_INDEX  0x00000111
#define RIPL_SAR_ADC0_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc0_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC0_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC0_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC0_DONE_POS     2
#define RIPL_SAR_ADC0_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC0_VAL_H_LSB    0
#define RIPL_SAR_ADC0_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC0_DONE_RST     0x0
#define RIPL_SAR_ADC0_VAL_H_RST    0x0

__INLINE void ripl_sar_adc0_val_h_unpack(uint8_t* saradc0done, uint8_t* saradc0valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC0_VAL_H_ADDR);
    *saradc0done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc0valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc0_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC0_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc0_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC0_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC1_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC1_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC1_VAL_L_ADDR   0x00000112
#define RIPL_SAR_ADC1_VAL_L_OFFSET 0x00000112
#define RIPL_SAR_ADC1_VAL_L_INDEX  0x00000112
#define RIPL_SAR_ADC1_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc1_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC1_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC1_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC1_VAL_L_LSB    0
#define RIPL_SAR_ADC1_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC1_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc1_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC1_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC1_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC1_DONE   0
 *  01:00       SAR_ADC1_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC1_VAL_H_ADDR   0x00000113
#define RIPL_SAR_ADC1_VAL_H_OFFSET 0x00000113
#define RIPL_SAR_ADC1_VAL_H_INDEX  0x00000113
#define RIPL_SAR_ADC1_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc1_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC1_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC1_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC1_DONE_POS     2
#define RIPL_SAR_ADC1_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC1_VAL_H_LSB    0
#define RIPL_SAR_ADC1_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC1_DONE_RST     0x0
#define RIPL_SAR_ADC1_VAL_H_RST    0x0

__INLINE void ripl_sar_adc1_val_h_unpack(uint8_t* saradc1done, uint8_t* saradc1valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC1_VAL_H_ADDR);
    *saradc1done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc1valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc1_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC1_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc1_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC1_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC2_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC2_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC2_VAL_L_ADDR   0x00000114
#define RIPL_SAR_ADC2_VAL_L_OFFSET 0x00000114
#define RIPL_SAR_ADC2_VAL_L_INDEX  0x00000114
#define RIPL_SAR_ADC2_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc2_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC2_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC2_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC2_VAL_L_LSB    0
#define RIPL_SAR_ADC2_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC2_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc2_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC2_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC2_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC2_DONE   0
 *  01:00       SAR_ADC2_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC2_VAL_H_ADDR   0x00000115
#define RIPL_SAR_ADC2_VAL_H_OFFSET 0x00000115
#define RIPL_SAR_ADC2_VAL_H_INDEX  0x00000115
#define RIPL_SAR_ADC2_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc2_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC2_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC2_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC2_DONE_POS     2
#define RIPL_SAR_ADC2_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC2_VAL_H_LSB    0
#define RIPL_SAR_ADC2_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC2_DONE_RST     0x0
#define RIPL_SAR_ADC2_VAL_H_RST    0x0

__INLINE void ripl_sar_adc2_val_h_unpack(uint8_t* saradc2done, uint8_t* saradc2valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC2_VAL_H_ADDR);
    *saradc2done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc2valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc2_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC2_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc2_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC2_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC3_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC3_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC3_VAL_L_ADDR   0x00000116
#define RIPL_SAR_ADC3_VAL_L_OFFSET 0x00000116
#define RIPL_SAR_ADC3_VAL_L_INDEX  0x00000116
#define RIPL_SAR_ADC3_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc3_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC3_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC3_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC3_VAL_L_LSB    0
#define RIPL_SAR_ADC3_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC3_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc3_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC3_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC3_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC3_DONE   0
 *  01:00       SAR_ADC3_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC3_VAL_H_ADDR   0x00000117
#define RIPL_SAR_ADC3_VAL_H_OFFSET 0x00000117
#define RIPL_SAR_ADC3_VAL_H_INDEX  0x00000117
#define RIPL_SAR_ADC3_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc3_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC3_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC3_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC3_DONE_POS     2
#define RIPL_SAR_ADC3_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC3_VAL_H_LSB    0
#define RIPL_SAR_ADC3_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC3_DONE_RST     0x0
#define RIPL_SAR_ADC3_VAL_H_RST    0x0

__INLINE void ripl_sar_adc3_val_h_unpack(uint8_t* saradc3done, uint8_t* saradc3valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC3_VAL_H_ADDR);
    *saradc3done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc3valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc3_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC3_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc3_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC3_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC4_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC4_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC4_VAL_L_ADDR   0x00000118
#define RIPL_SAR_ADC4_VAL_L_OFFSET 0x00000118
#define RIPL_SAR_ADC4_VAL_L_INDEX  0x00000118
#define RIPL_SAR_ADC4_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc4_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC4_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC4_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC4_VAL_L_LSB    0
#define RIPL_SAR_ADC4_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC4_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc4_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC4_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC4_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC4_DONE   0
 *  01:00       SAR_ADC4_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC4_VAL_H_ADDR   0x00000119
#define RIPL_SAR_ADC4_VAL_H_OFFSET 0x00000119
#define RIPL_SAR_ADC4_VAL_H_INDEX  0x00000119
#define RIPL_SAR_ADC4_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc4_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC4_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC4_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC4_DONE_POS     2
#define RIPL_SAR_ADC4_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC4_VAL_H_LSB    0
#define RIPL_SAR_ADC4_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC4_DONE_RST     0x0
#define RIPL_SAR_ADC4_VAL_H_RST    0x0

__INLINE void ripl_sar_adc4_val_h_unpack(uint8_t* saradc4done, uint8_t* saradc4valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC4_VAL_H_ADDR);
    *saradc4done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc4valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc4_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC4_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc4_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC4_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC5_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC5_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC5_VAL_L_ADDR   0x0000011A
#define RIPL_SAR_ADC5_VAL_L_OFFSET 0x0000011A
#define RIPL_SAR_ADC5_VAL_L_INDEX  0x0000011A
#define RIPL_SAR_ADC5_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc5_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC5_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC5_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC5_VAL_L_LSB    0
#define RIPL_SAR_ADC5_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC5_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc5_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC5_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC5_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC5_DONE   0
 *  01:00       SAR_ADC5_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC5_VAL_H_ADDR   0x0000011B
#define RIPL_SAR_ADC5_VAL_H_OFFSET 0x0000011B
#define RIPL_SAR_ADC5_VAL_H_INDEX  0x0000011B
#define RIPL_SAR_ADC5_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc5_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC5_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC5_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC5_DONE_POS     2
#define RIPL_SAR_ADC5_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC5_VAL_H_LSB    0
#define RIPL_SAR_ADC5_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC5_DONE_RST     0x0
#define RIPL_SAR_ADC5_VAL_H_RST    0x0

__INLINE void ripl_sar_adc5_val_h_unpack(uint8_t* saradc5done, uint8_t* saradc5valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC5_VAL_H_ADDR);
    *saradc5done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc5valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc5_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC5_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc5_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC5_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC6_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC6_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC6_VAL_L_ADDR   0x0000011C
#define RIPL_SAR_ADC6_VAL_L_OFFSET 0x0000011C
#define RIPL_SAR_ADC6_VAL_L_INDEX  0x0000011C
#define RIPL_SAR_ADC6_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc6_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC6_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC6_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC6_VAL_L_LSB    0
#define RIPL_SAR_ADC6_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC6_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc6_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC6_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC6_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC6_DONE   0
 *  01:00       SAR_ADC6_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC6_VAL_H_ADDR   0x0000011D
#define RIPL_SAR_ADC6_VAL_H_OFFSET 0x0000011D
#define RIPL_SAR_ADC6_VAL_H_INDEX  0x0000011D
#define RIPL_SAR_ADC6_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc6_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC6_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC6_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC6_DONE_POS     2
#define RIPL_SAR_ADC6_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC6_VAL_H_LSB    0
#define RIPL_SAR_ADC6_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC6_DONE_RST     0x0
#define RIPL_SAR_ADC6_VAL_H_RST    0x0

__INLINE void ripl_sar_adc6_val_h_unpack(uint8_t* saradc6done, uint8_t* saradc6valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC6_VAL_H_ADDR);
    *saradc6done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc6valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc6_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC6_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc6_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC6_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC7_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC7_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC7_VAL_L_ADDR   0x0000011E
#define RIPL_SAR_ADC7_VAL_L_OFFSET 0x0000011E
#define RIPL_SAR_ADC7_VAL_L_INDEX  0x0000011E
#define RIPL_SAR_ADC7_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc7_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC7_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC7_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC7_VAL_L_LSB    0
#define RIPL_SAR_ADC7_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC7_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc7_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC7_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC7_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC7_DONE   0
 *  01:00       SAR_ADC7_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC7_VAL_H_ADDR   0x0000011F
#define RIPL_SAR_ADC7_VAL_H_OFFSET 0x0000011F
#define RIPL_SAR_ADC7_VAL_H_INDEX  0x0000011F
#define RIPL_SAR_ADC7_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc7_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC7_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC7_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC7_DONE_POS     2
#define RIPL_SAR_ADC7_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC7_VAL_H_LSB    0
#define RIPL_SAR_ADC7_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC7_DONE_RST     0x0
#define RIPL_SAR_ADC7_VAL_H_RST    0x0

__INLINE void ripl_sar_adc7_val_h_unpack(uint8_t* saradc7done, uint8_t* saradc7valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC7_VAL_H_ADDR);
    *saradc7done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc7valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc7_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC7_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc7_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC7_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC8_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC8_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC8_VAL_L_ADDR   0x00000120
#define RIPL_SAR_ADC8_VAL_L_OFFSET 0x00000120
#define RIPL_SAR_ADC8_VAL_L_INDEX  0x00000120
#define RIPL_SAR_ADC8_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc8_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC8_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC8_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC8_VAL_L_LSB    0
#define RIPL_SAR_ADC8_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC8_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc8_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC8_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC8_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC8_DONE   0
 *  01:00       SAR_ADC8_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC8_VAL_H_ADDR   0x00000121
#define RIPL_SAR_ADC8_VAL_H_OFFSET 0x00000121
#define RIPL_SAR_ADC8_VAL_H_INDEX  0x00000121
#define RIPL_SAR_ADC8_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc8_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC8_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC8_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC8_DONE_POS     2
#define RIPL_SAR_ADC8_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC8_VAL_H_LSB    0
#define RIPL_SAR_ADC8_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC8_DONE_RST     0x0
#define RIPL_SAR_ADC8_VAL_H_RST    0x0

__INLINE void ripl_sar_adc8_val_h_unpack(uint8_t* saradc8done, uint8_t* saradc8valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC8_VAL_H_ADDR);
    *saradc8done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc8valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc8_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC8_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc8_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC8_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC9_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       SAR_ADC9_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC9_VAL_L_ADDR   0x00000122
#define RIPL_SAR_ADC9_VAL_L_OFFSET 0x00000122
#define RIPL_SAR_ADC9_VAL_L_INDEX  0x00000122
#define RIPL_SAR_ADC9_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc9_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC9_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC9_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC9_VAL_L_LSB    0
#define RIPL_SAR_ADC9_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC9_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc9_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC9_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC9_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02        SAR_ADC9_DONE   0
 *  01:00       SAR_ADC9_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC9_VAL_H_ADDR   0x00000123
#define RIPL_SAR_ADC9_VAL_H_OFFSET 0x00000123
#define RIPL_SAR_ADC9_VAL_H_INDEX  0x00000123
#define RIPL_SAR_ADC9_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc9_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC9_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC9_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC9_DONE_POS     2
#define RIPL_SAR_ADC9_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC9_VAL_H_LSB    0
#define RIPL_SAR_ADC9_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC9_DONE_RST     0x0
#define RIPL_SAR_ADC9_VAL_H_RST    0x0

__INLINE void ripl_sar_adc9_val_h_unpack(uint8_t* saradc9done, uint8_t* saradc9valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC9_VAL_H_ADDR);
    *saradc9done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc9valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc9_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC9_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc9_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC9_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC10_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC10_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC10_VAL_L_ADDR   0x00000124
#define RIPL_SAR_ADC10_VAL_L_OFFSET 0x00000124
#define RIPL_SAR_ADC10_VAL_L_INDEX  0x00000124
#define RIPL_SAR_ADC10_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc10_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC10_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC10_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC10_VAL_L_LSB    0
#define RIPL_SAR_ADC10_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC10_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc10_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC10_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC10_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC10_DONE   0
 *  01:00      SAR_ADC10_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC10_VAL_H_ADDR   0x00000125
#define RIPL_SAR_ADC10_VAL_H_OFFSET 0x00000125
#define RIPL_SAR_ADC10_VAL_H_INDEX  0x00000125
#define RIPL_SAR_ADC10_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc10_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC10_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC10_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC10_DONE_POS     2
#define RIPL_SAR_ADC10_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC10_VAL_H_LSB    0
#define RIPL_SAR_ADC10_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC10_DONE_RST     0x0
#define RIPL_SAR_ADC10_VAL_H_RST    0x0

__INLINE void ripl_sar_adc10_val_h_unpack(uint8_t* saradc10done, uint8_t* saradc10valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC10_VAL_H_ADDR);
    *saradc10done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc10valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc10_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC10_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc10_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC10_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC11_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC11_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC11_VAL_L_ADDR   0x00000126
#define RIPL_SAR_ADC11_VAL_L_OFFSET 0x00000126
#define RIPL_SAR_ADC11_VAL_L_INDEX  0x00000126
#define RIPL_SAR_ADC11_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc11_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC11_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC11_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC11_VAL_L_LSB    0
#define RIPL_SAR_ADC11_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC11_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc11_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC11_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC11_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC11_DONE   0
 *  01:00      SAR_ADC11_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC11_VAL_H_ADDR   0x00000127
#define RIPL_SAR_ADC11_VAL_H_OFFSET 0x00000127
#define RIPL_SAR_ADC11_VAL_H_INDEX  0x00000127
#define RIPL_SAR_ADC11_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc11_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC11_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC11_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC11_DONE_POS     2
#define RIPL_SAR_ADC11_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC11_VAL_H_LSB    0
#define RIPL_SAR_ADC11_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC11_DONE_RST     0x0
#define RIPL_SAR_ADC11_VAL_H_RST    0x0

__INLINE void ripl_sar_adc11_val_h_unpack(uint8_t* saradc11done, uint8_t* saradc11valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC11_VAL_H_ADDR);
    *saradc11done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc11valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc11_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC11_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc11_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC11_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC12_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC12_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC12_VAL_L_ADDR   0x00000128
#define RIPL_SAR_ADC12_VAL_L_OFFSET 0x00000128
#define RIPL_SAR_ADC12_VAL_L_INDEX  0x00000128
#define RIPL_SAR_ADC12_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc12_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC12_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC12_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC12_VAL_L_LSB    0
#define RIPL_SAR_ADC12_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC12_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc12_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC12_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC12_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC12_DONE   0
 *  01:00      SAR_ADC12_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC12_VAL_H_ADDR   0x00000129
#define RIPL_SAR_ADC12_VAL_H_OFFSET 0x00000129
#define RIPL_SAR_ADC12_VAL_H_INDEX  0x00000129
#define RIPL_SAR_ADC12_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc12_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC12_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC12_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC12_DONE_POS     2
#define RIPL_SAR_ADC12_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC12_VAL_H_LSB    0
#define RIPL_SAR_ADC12_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC12_DONE_RST     0x0
#define RIPL_SAR_ADC12_VAL_H_RST    0x0

__INLINE void ripl_sar_adc12_val_h_unpack(uint8_t* saradc12done, uint8_t* saradc12valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC12_VAL_H_ADDR);
    *saradc12done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc12valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc12_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC12_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc12_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC12_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC13_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC13_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC13_VAL_L_ADDR   0x0000012A
#define RIPL_SAR_ADC13_VAL_L_OFFSET 0x0000012A
#define RIPL_SAR_ADC13_VAL_L_INDEX  0x0000012A
#define RIPL_SAR_ADC13_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc13_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC13_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC13_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC13_VAL_L_LSB    0
#define RIPL_SAR_ADC13_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC13_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc13_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC13_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC13_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC13_DONE   0
 *  01:00      SAR_ADC13_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC13_VAL_H_ADDR   0x0000012B
#define RIPL_SAR_ADC13_VAL_H_OFFSET 0x0000012B
#define RIPL_SAR_ADC13_VAL_H_INDEX  0x0000012B
#define RIPL_SAR_ADC13_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc13_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC13_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC13_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC13_DONE_POS     2
#define RIPL_SAR_ADC13_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC13_VAL_H_LSB    0
#define RIPL_SAR_ADC13_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC13_DONE_RST     0x0
#define RIPL_SAR_ADC13_VAL_H_RST    0x0

__INLINE void ripl_sar_adc13_val_h_unpack(uint8_t* saradc13done, uint8_t* saradc13valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC13_VAL_H_ADDR);
    *saradc13done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc13valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc13_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC13_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc13_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC13_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC14_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC14_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC14_VAL_L_ADDR   0x0000012C
#define RIPL_SAR_ADC14_VAL_L_OFFSET 0x0000012C
#define RIPL_SAR_ADC14_VAL_L_INDEX  0x0000012C
#define RIPL_SAR_ADC14_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc14_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC14_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC14_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC14_VAL_L_LSB    0
#define RIPL_SAR_ADC14_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC14_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc14_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC14_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC14_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC14_DONE   0
 *  01:00      SAR_ADC14_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC14_VAL_H_ADDR   0x0000012D
#define RIPL_SAR_ADC14_VAL_H_OFFSET 0x0000012D
#define RIPL_SAR_ADC14_VAL_H_INDEX  0x0000012D
#define RIPL_SAR_ADC14_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc14_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC14_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC14_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC14_DONE_POS     2
#define RIPL_SAR_ADC14_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC14_VAL_H_LSB    0
#define RIPL_SAR_ADC14_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC14_DONE_RST     0x0
#define RIPL_SAR_ADC14_VAL_H_RST    0x0

__INLINE void ripl_sar_adc14_val_h_unpack(uint8_t* saradc14done, uint8_t* saradc14valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC14_VAL_H_ADDR);
    *saradc14done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc14valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc14_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC14_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc14_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC14_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief SAR_ADC15_VAL_L register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      SAR_ADC15_VAL_L   0x0
 * </pre>
 */
#define RIPL_SAR_ADC15_VAL_L_ADDR   0x0000012E
#define RIPL_SAR_ADC15_VAL_L_OFFSET 0x0000012E
#define RIPL_SAR_ADC15_VAL_L_INDEX  0x0000012E
#define RIPL_SAR_ADC15_VAL_L_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc15_val_l_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC15_VAL_L_ADDR);
}

// field definitions
#define RIPL_SAR_ADC15_VAL_L_MASK   ((uint8_t)0x000000FF)
#define RIPL_SAR_ADC15_VAL_L_LSB    0
#define RIPL_SAR_ADC15_VAL_L_WIDTH  ((uint8_t)0x00000008)

#define RIPL_SAR_ADC15_VAL_L_RST    0x0

__INLINE uint8_t ripl_sar_adc15_val_l_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC15_VAL_L_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAR_ADC15_VAL_H register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02       SAR_ADC15_DONE   0
 *  01:00      SAR_ADC15_VAL_H   0x0
 * </pre>
 */
#define RIPL_SAR_ADC15_VAL_H_ADDR   0x0000012F
#define RIPL_SAR_ADC15_VAL_H_OFFSET 0x0000012F
#define RIPL_SAR_ADC15_VAL_H_INDEX  0x0000012F
#define RIPL_SAR_ADC15_VAL_H_RESET  0x00000000

__INLINE uint8_t ripl_sar_adc15_val_h_get(void)
{
    return REG_RIPL_RD(RIPL_SAR_ADC15_VAL_H_ADDR);
}

// field definitions
#define RIPL_SAR_ADC15_DONE_BIT     ((uint8_t)0x00000004)
#define RIPL_SAR_ADC15_DONE_POS     2
#define RIPL_SAR_ADC15_VAL_H_MASK   ((uint8_t)0x00000003)
#define RIPL_SAR_ADC15_VAL_H_LSB    0
#define RIPL_SAR_ADC15_VAL_H_WIDTH  ((uint8_t)0x00000002)

#define RIPL_SAR_ADC15_DONE_RST     0x0
#define RIPL_SAR_ADC15_VAL_H_RST    0x0

__INLINE void ripl_sar_adc15_val_h_unpack(uint8_t* saradc15done, uint8_t* saradc15valh)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC15_VAL_H_ADDR);
    *saradc15done = (localVal & ((uint8_t)0x00000004)) >> 2;
    *saradc15valh = (localVal & ((uint8_t)0x00000003)) >> 0;
}

__INLINE uint8_t ripl_sar_adc15_done_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC15_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000004)) >> 2);
}

__INLINE uint8_t ripl_sar_adc15_val_h_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_SAR_ADC15_VAL_H_ADDR);
    return ((localVal & ((uint8_t)0x00000003)) >> 0);
}

/**
 * @brief TEST_MUX0_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       TEST_MUX0_CTRL   0x0
 * </pre>
 */
#define RIPL_TEST_MUX0_CTRL_ADDR   0x00000135
#define RIPL_TEST_MUX0_CTRL_OFFSET 0x00000135
#define RIPL_TEST_MUX0_CTRL_INDEX  0x00000135
#define RIPL_TEST_MUX0_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_test_mux0_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TEST_MUX0_CTRL_ADDR);
}

__INLINE void ripl_test_mux0_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TEST_MUX0_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TEST_MUX0_CTRL_MASK   ((uint8_t)0x000000FF)
#define RIPL_TEST_MUX0_CTRL_LSB    0
#define RIPL_TEST_MUX0_CTRL_WIDTH  ((uint8_t)0x00000008)

#define RIPL_TEST_MUX0_CTRL_RST    0x0

__INLINE uint8_t ripl_test_mux0_ctrl_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX0_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_test_mux0_ctrl_setf(uint8_t testmux0ctrl)
{
    ASSERT_ERR((((uint8_t)testmux0ctrl << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX0_CTRL_ADDR, (uint8_t)testmux0ctrl << 0);
}

/**
 * @brief TEST_MUX1_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       TEST_MUX1_CTRL   0x0
 * </pre>
 */
#define RIPL_TEST_MUX1_CTRL_ADDR   0x00000136
#define RIPL_TEST_MUX1_CTRL_OFFSET 0x00000136
#define RIPL_TEST_MUX1_CTRL_INDEX  0x00000136
#define RIPL_TEST_MUX1_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_test_mux1_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TEST_MUX1_CTRL_ADDR);
}

__INLINE void ripl_test_mux1_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TEST_MUX1_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TEST_MUX1_CTRL_MASK   ((uint8_t)0x000000FF)
#define RIPL_TEST_MUX1_CTRL_LSB    0
#define RIPL_TEST_MUX1_CTRL_WIDTH  ((uint8_t)0x00000008)

#define RIPL_TEST_MUX1_CTRL_RST    0x0

__INLINE uint8_t ripl_test_mux1_ctrl_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX1_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_test_mux1_ctrl_setf(uint8_t testmux1ctrl)
{
    ASSERT_ERR((((uint8_t)testmux1ctrl << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX1_CTRL_ADDR, (uint8_t)testmux1ctrl << 0);
}

/**
 * @brief TEST_MUX2_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       TEST_MUX2_CTRL   0x0
 * </pre>
 */
#define RIPL_TEST_MUX2_CTRL_ADDR   0x00000137
#define RIPL_TEST_MUX2_CTRL_OFFSET 0x00000137
#define RIPL_TEST_MUX2_CTRL_INDEX  0x00000137
#define RIPL_TEST_MUX2_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_test_mux2_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TEST_MUX2_CTRL_ADDR);
}

__INLINE void ripl_test_mux2_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TEST_MUX2_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TEST_MUX2_CTRL_MASK   ((uint8_t)0x000000FF)
#define RIPL_TEST_MUX2_CTRL_LSB    0
#define RIPL_TEST_MUX2_CTRL_WIDTH  ((uint8_t)0x00000008)

#define RIPL_TEST_MUX2_CTRL_RST    0x0

__INLINE uint8_t ripl_test_mux2_ctrl_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX2_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_test_mux2_ctrl_setf(uint8_t testmux2ctrl)
{
    ASSERT_ERR((((uint8_t)testmux2ctrl << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX2_CTRL_ADDR, (uint8_t)testmux2ctrl << 0);
}

/**
 * @brief TEST_MUX3_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       TEST_MUX3_CTRL   0x0
 * </pre>
 */
#define RIPL_TEST_MUX3_CTRL_ADDR   0x00000138
#define RIPL_TEST_MUX3_CTRL_OFFSET 0x00000138
#define RIPL_TEST_MUX3_CTRL_INDEX  0x00000138
#define RIPL_TEST_MUX3_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_test_mux3_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TEST_MUX3_CTRL_ADDR);
}

__INLINE void ripl_test_mux3_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TEST_MUX3_CTRL_ADDR, value);
}

// field definitions
#define RIPL_TEST_MUX3_CTRL_MASK   ((uint8_t)0x000000FF)
#define RIPL_TEST_MUX3_CTRL_LSB    0
#define RIPL_TEST_MUX3_CTRL_WIDTH  ((uint8_t)0x00000008)

#define RIPL_TEST_MUX3_CTRL_RST    0x0

__INLINE uint8_t ripl_test_mux3_ctrl_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX3_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint8_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void ripl_test_mux3_ctrl_setf(uint8_t testmux3ctrl)
{
    ASSERT_ERR((((uint8_t)testmux3ctrl << 0) & ~((uint8_t)0x000000FF)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX3_CTRL_ADDR, (uint8_t)testmux3ctrl << 0);
}

/**
 * @brief TEST_MUX_PAD_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06           LED_PAD_EN   0
 *  05:04         LED_PAD_DATA   0x0
 *  03:00             RFSW_OUT   0x0
 * </pre>
 */
#define RIPL_TEST_MUX_PAD_CTRL_ADDR   0x00000139
#define RIPL_TEST_MUX_PAD_CTRL_OFFSET 0x00000139
#define RIPL_TEST_MUX_PAD_CTRL_INDEX  0x00000139
#define RIPL_TEST_MUX_PAD_CTRL_RESET  0x00000000

__INLINE uint8_t ripl_test_mux_pad_ctrl_get(void)
{
    return REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR);
}

__INLINE void ripl_test_mux_pad_ctrl_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_TEST_MUX_PAD_CTRL_ADDR, value);
}

// field definitions
#define RIPL_LED_PAD_EN_BIT      ((uint8_t)0x00000040)
#define RIPL_LED_PAD_EN_POS      6
#define RIPL_LED_PAD_DATA_MASK   ((uint8_t)0x00000030)
#define RIPL_LED_PAD_DATA_LSB    4
#define RIPL_LED_PAD_DATA_WIDTH  ((uint8_t)0x00000002)
#define RIPL_RFSW_OUT_MASK       ((uint8_t)0x0000000F)
#define RIPL_RFSW_OUT_LSB        0
#define RIPL_RFSW_OUT_WIDTH      ((uint8_t)0x00000004)

#define RIPL_LED_PAD_EN_RST      0x0
#define RIPL_LED_PAD_DATA_RST    0x0
#define RIPL_RFSW_OUT_RST        0x0

__INLINE void ripl_test_mux_pad_ctrl_pack(uint8_t ledpaden, uint8_t ledpaddata, uint8_t rfswout)
{
    ASSERT_ERR((((uint8_t)ledpaden << 6) & ~((uint8_t)0x00000040)) == 0);
    ASSERT_ERR((((uint8_t)ledpaddata << 4) & ~((uint8_t)0x00000030)) == 0);
    ASSERT_ERR((((uint8_t)rfswout << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX_PAD_CTRL_ADDR,  ((uint8_t)ledpaden << 6) | ((uint8_t)ledpaddata << 4) | ((uint8_t)rfswout << 0));
}

__INLINE void ripl_test_mux_pad_ctrl_unpack(uint8_t* ledpaden, uint8_t* ledpaddata, uint8_t* rfswout)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR);
    *ledpaden = (localVal & ((uint8_t)0x00000040)) >> 6;
    *ledpaddata = (localVal & ((uint8_t)0x00000030)) >> 4;
    *rfswout = (localVal & ((uint8_t)0x0000000F)) >> 0;
}

__INLINE uint8_t ripl_led_pad_en_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000040)) >> 6);
}

__INLINE void ripl_led_pad_en_setf(uint8_t ledpaden)
{
    ASSERT_ERR((((uint8_t)ledpaden << 6) & ~((uint8_t)0x00000040)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX_PAD_CTRL_ADDR, (REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR) & ~((uint8_t)0x00000040)) | ((uint8_t)ledpaden << 6));
}

__INLINE uint8_t ripl_led_pad_data_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x00000030)) >> 4);
}

__INLINE void ripl_led_pad_data_setf(uint8_t ledpaddata)
{
    ASSERT_ERR((((uint8_t)ledpaddata << 4) & ~((uint8_t)0x00000030)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX_PAD_CTRL_ADDR, (REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR) & ~((uint8_t)0x00000030)) | ((uint8_t)ledpaddata << 4));
}

__INLINE uint8_t ripl_rfsw_out_getf(void)
{
    uint8_t localVal;

    localVal = REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR);
    return ((localVal & ((uint8_t)0x0000000F)) >> 0);
}

__INLINE void ripl_rfsw_out_setf(uint8_t rfswout)
{
    ASSERT_ERR((((uint8_t)rfswout << 0) & ~((uint8_t)0x0000000F)) == 0);
    REG_RIPL_WR(RIPL_TEST_MUX_PAD_CTRL_ADDR, (REG_RIPL_RD(RIPL_TEST_MUX_PAD_CTRL_ADDR) & ~((uint8_t)0x0000000F)) | ((uint8_t)rfswout << 0));
}

/**
 * @brief R_SPARE_REG0 register definition
 */
#define RIPL_R_SPARE_REG0_ADDR   0x00000140
#define RIPL_R_SPARE_REG0_OFFSET 0x00000140
#define RIPL_R_SPARE_REG0_INDEX  0x00000140
#define RIPL_R_SPARE_REG0_RESET  0x00000000

__INLINE uint8_t ripl_r_spare_reg0_get(void)
{
    return REG_RIPL_RD(RIPL_R_SPARE_REG0_ADDR);
}

__INLINE void ripl_r_spare_reg0_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_R_SPARE_REG0_ADDR, value);
}

/**
 * @brief R_SPARE_REG1 register definition
 */
#define RIPL_R_SPARE_REG1_ADDR   0x00000141
#define RIPL_R_SPARE_REG1_OFFSET 0x00000141
#define RIPL_R_SPARE_REG1_INDEX  0x00000141
#define RIPL_R_SPARE_REG1_RESET  0x00000000

__INLINE uint8_t ripl_r_spare_reg1_get(void)
{
    return REG_RIPL_RD(RIPL_R_SPARE_REG1_ADDR);
}

__INLINE void ripl_r_spare_reg1_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_R_SPARE_REG1_ADDR, value);
}

/**
 * @brief R_SPARE_REG2 register definition
 */
#define RIPL_R_SPARE_REG2_ADDR   0x00000142
#define RIPL_R_SPARE_REG2_OFFSET 0x00000142
#define RIPL_R_SPARE_REG2_INDEX  0x00000142
#define RIPL_R_SPARE_REG2_RESET  0x00000000

__INLINE uint8_t ripl_r_spare_reg2_get(void)
{
    return REG_RIPL_RD(RIPL_R_SPARE_REG2_ADDR);
}

__INLINE void ripl_r_spare_reg2_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_R_SPARE_REG2_ADDR, value);
}

/**
 * @brief R_SPARE_REG3 register definition
 */
#define RIPL_R_SPARE_REG3_ADDR   0x00000143
#define RIPL_R_SPARE_REG3_OFFSET 0x00000143
#define RIPL_R_SPARE_REG3_INDEX  0x00000143
#define RIPL_R_SPARE_REG3_RESET  0x00000000

__INLINE uint8_t ripl_r_spare_reg3_get(void)
{
    return REG_RIPL_RD(RIPL_R_SPARE_REG3_ADDR);
}

__INLINE void ripl_r_spare_reg3_set(uint8_t value)
{
    REG_RIPL_WR(RIPL_R_SPARE_REG3_ADDR, value);
}


#endif // _REG_RIPPLE_I2C_H_

