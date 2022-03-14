#ifndef _REG_APB_H_
#define _REG_APB_H_

#include <stdint.h>
#include "_reg_apb.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"
#include "co_assert.h"

#define REG_APB_COUNT 1024

#define REG_APB_DECODING_MASK 0x00000FFF

/**
 * @brief AUDIO_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:28   Saradc_pdata_avg_num   0x0
 *     25   Audac_cali_start_flag   0
 *     24     Audac_itrim_flag   0
 *     23   Audac_cali_start_reg   0
 *     22      dudio_det_1_out   0
 *     20       audac_itrim_en   0
 *  19:16          audac_itrim   0x0
 *  07:04      audac_R_anagain   0x0
 *  03:00      audac_L_anagain   0x0
 * </pre>
 */
#define APB_AUDIO_CTRL0_ADDR   0xC0012000
#define APB_AUDIO_CTRL0_OFFSET 0x00000000
#define APB_AUDIO_CTRL0_INDEX  0x00000000
#define APB_AUDIO_CTRL0_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl0_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
}

__INLINE void apb_audio_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL0_SARADC_PDATA_AVG_NUM_MASK    ((uint32_t)0xF0000000)
#define APB_AUDIO_CTRL0_SARADC_PDATA_AVG_NUM_LSB     28
#define APB_AUDIO_CTRL0_SARADC_PDATA_AVG_NUM_WIDTH   ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_FLAG_BIT    ((uint32_t)0x02000000)
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_FLAG_POS    25
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_FLAG_BIT         ((uint32_t)0x01000000)
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_FLAG_POS         24
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_REG_BIT     ((uint32_t)0x00800000)
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_REG_POS     23
#define APB_AUDIO_CTRL0_DUDIO_DET__1_OUT_BIT         ((uint32_t)0x00400000)
#define APB_AUDIO_CTRL0_DUDIO_DET__1_OUT_POS         22
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_EN_BIT           ((uint32_t)0x00100000)
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_EN_POS           20
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_MASK             ((uint32_t)0x000F0000)
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_LSB              16
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_WIDTH            ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL0_AUDAC_R_ANAGAIN_MASK         ((uint32_t)0x000000F0)
#define APB_AUDIO_CTRL0_AUDAC_R_ANAGAIN_LSB          4
#define APB_AUDIO_CTRL0_AUDAC_R_ANAGAIN_WIDTH        ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL0_AUDAC_L_ANAGAIN_MASK         ((uint32_t)0x0000000F)
#define APB_AUDIO_CTRL0_AUDAC_L_ANAGAIN_LSB          0
#define APB_AUDIO_CTRL0_AUDAC_L_ANAGAIN_WIDTH        ((uint32_t)0x00000004)

#define APB_AUDIO_CTRL0_SARADC_PDATA_AVG_NUM_RST     0x0
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_FLAG_RST    0x0
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_FLAG_RST         0x0
#define APB_AUDIO_CTRL0_AUDAC_CALI_START_REG_RST     0x0
#define APB_AUDIO_CTRL0_DUDIO_DET__1_OUT_RST         0x0
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_EN_RST           0x0
#define APB_AUDIO_CTRL0_AUDAC_ITRIM_RST              0x0
#define APB_AUDIO_CTRL0_AUDAC_R_ANAGAIN_RST          0x0
#define APB_AUDIO_CTRL0_AUDAC_L_ANAGAIN_RST          0x0

__INLINE void apb_audio_ctrl0_pack(uint8_t saradcpdataavgnum, uint8_t audaccalistartflag, uint8_t audacitrimflag, uint8_t audaccalistartreg, uint8_t audacitrimen, uint8_t audacitrim, uint8_t audacranagain, uint8_t audaclanagain)
{
    ASSERT_ERR((((uint32_t)saradcpdataavgnum << 28) & ~((uint32_t)0xF0000000)) == 0);
    ASSERT_ERR((((uint32_t)audaccalistartflag << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)audacitrimflag << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)audaccalistartreg << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)audacitrimen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)audacitrim << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)audacranagain << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)audaclanagain << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR,  ((uint32_t)saradcpdataavgnum << 28) | ((uint32_t)audaccalistartflag << 25) | ((uint32_t)audacitrimflag << 24) | ((uint32_t)audaccalistartreg << 23) | ((uint32_t)audacitrimen << 20) | ((uint32_t)audacitrim << 16) | ((uint32_t)audacranagain << 4) | ((uint32_t)audaclanagain << 0));
}

__INLINE void apb_audio_ctrl0_unpack(uint8_t* saradcpdataavgnum, uint8_t* audaccalistartflag, uint8_t* audacitrimflag, uint8_t* audaccalistartreg, uint8_t* dudiodet1out, uint8_t* audacitrimen, uint8_t* audacitrim, uint8_t* audacranagain, uint8_t* audaclanagain)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    *saradcpdataavgnum = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *audaccalistartflag = (localVal & ((uint32_t)0x02000000)) >> 25;
    *audacitrimflag = (localVal & ((uint32_t)0x01000000)) >> 24;
    *audaccalistartreg = (localVal & ((uint32_t)0x00800000)) >> 23;
    *dudiodet1out = (localVal & ((uint32_t)0x00400000)) >> 22;
    *audacitrimen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *audacitrim = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *audacranagain = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *audaclanagain = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_audio_ctrl0_saradc_pdata_avg_num_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}

__INLINE void apb_audio_ctrl0_saradc_pdata_avg_num_setf(uint8_t saradcpdataavgnum)
{
    ASSERT_ERR((((uint32_t)saradcpdataavgnum << 28) & ~((uint32_t)0xF0000000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)saradcpdataavgnum << 28));
}

__INLINE uint8_t apb_audio_ctrl0_audac_cali_start_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_audio_ctrl0_audac_cali_start_flag_setf(uint8_t audaccalistartflag)
{
    ASSERT_ERR((((uint32_t)audaccalistartflag << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)audaccalistartflag << 25));
}

__INLINE uint8_t apb_audio_ctrl0_audac_itrim_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_audio_ctrl0_audac_itrim_flag_setf(uint8_t audacitrimflag)
{
    ASSERT_ERR((((uint32_t)audacitrimflag << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)audacitrimflag << 24));
}

__INLINE uint8_t apb_audio_ctrl0_audac_cali_start_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_audio_ctrl0_audac_cali_start_reg_setf(uint8_t audaccalistartreg)
{
    ASSERT_ERR((((uint32_t)audaccalistartreg << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)audaccalistartreg << 23));
}

__INLINE uint8_t apb_audio_ctrl0_dudio_det__1_out_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_audio_ctrl0_audac_itrim_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_audio_ctrl0_audac_itrim_en_setf(uint8_t audacitrimen)
{
    ASSERT_ERR((((uint32_t)audacitrimen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)audacitrimen << 20));
}

__INLINE uint8_t apb_audio_ctrl0_audac_itrim_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_audio_ctrl0_audac_itrim_setf(uint8_t audacitrim)
{
    ASSERT_ERR((((uint32_t)audacitrim << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)audacitrim << 16));
}

__INLINE uint8_t apb_audio_ctrl0_audac_r_anagain_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_audio_ctrl0_audac_r_anagain_setf(uint8_t audacranagain)
{
    ASSERT_ERR((((uint32_t)audacranagain << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)audacranagain << 4));
}

__INLINE uint8_t apb_audio_ctrl0_audac_l_anagain_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_audio_ctrl0_audac_l_anagain_setf(uint8_t audaclanagain)
{
    ASSERT_ERR((((uint32_t)audaclanagain << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL0_ADDR, (REG_PL_RD(APB_AUDIO_CTRL0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)audaclanagain << 0));
}

/**
 * @brief AUDIO_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     08   Audio_pga_jack_pin_order_sts   0
 *  07:06   Audio_pga_vcm_ctrl   0x0
 *  05:04       audac_dir_isel   0x0
 *  03:00    audio_det_vth_sel   0x4
 * </pre>
 */
#define APB_AUDIO_CTRL1_ADDR   0xC0012004
#define APB_AUDIO_CTRL1_OFFSET 0x00000004
#define APB_AUDIO_CTRL1_INDEX  0x00000001
#define APB_AUDIO_CTRL1_RESET  0x00000004

__INLINE uint32_t apb_audio_ctrl1_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
}

__INLINE void apb_audio_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL1_AUDIO_PGA_JACK_PIN_ORDER_STS_BIT    ((uint32_t)0x00000100)
#define APB_AUDIO_CTRL1_AUDIO_PGA_JACK_PIN_ORDER_STS_POS    8
#define APB_AUDIO_CTRL1_AUDIO_PGA_VCM_CTRL_MASK             ((uint32_t)0x000000C0)
#define APB_AUDIO_CTRL1_AUDIO_PGA_VCM_CTRL_LSB              6
#define APB_AUDIO_CTRL1_AUDIO_PGA_VCM_CTRL_WIDTH            ((uint32_t)0x00000002)
#define APB_AUDIO_CTRL1_AUDAC_DIR_ISEL_MASK                 ((uint32_t)0x00000030)
#define APB_AUDIO_CTRL1_AUDAC_DIR_ISEL_LSB                  4
#define APB_AUDIO_CTRL1_AUDAC_DIR_ISEL_WIDTH                ((uint32_t)0x00000002)
#define APB_AUDIO_CTRL1_AUDIO_DET_VTH_SEL_MASK              ((uint32_t)0x0000000F)
#define APB_AUDIO_CTRL1_AUDIO_DET_VTH_SEL_LSB               0
#define APB_AUDIO_CTRL1_AUDIO_DET_VTH_SEL_WIDTH             ((uint32_t)0x00000004)

#define APB_AUDIO_CTRL1_AUDIO_PGA_JACK_PIN_ORDER_STS_RST    0x0
#define APB_AUDIO_CTRL1_AUDIO_PGA_VCM_CTRL_RST              0x0
#define APB_AUDIO_CTRL1_AUDAC_DIR_ISEL_RST                  0x0
#define APB_AUDIO_CTRL1_AUDIO_DET_VTH_SEL_RST               0x4

__INLINE void apb_audio_ctrl1_pack(uint8_t audiopgajackpinordersts, uint8_t audiopgavcmctrl, uint8_t audacdirisel, uint8_t audiodetvthsel)
{
    ASSERT_ERR((((uint32_t)audiopgajackpinordersts << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)audiopgavcmctrl << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)audacdirisel << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)audiodetvthsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR,  ((uint32_t)audiopgajackpinordersts << 8) | ((uint32_t)audiopgavcmctrl << 6) | ((uint32_t)audacdirisel << 4) | ((uint32_t)audiodetvthsel << 0));
}

__INLINE void apb_audio_ctrl1_unpack(uint8_t* audiopgajackpinordersts, uint8_t* audiopgavcmctrl, uint8_t* audacdirisel, uint8_t* audiodetvthsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
    *audiopgajackpinordersts = (localVal & ((uint32_t)0x00000100)) >> 8;
    *audiopgavcmctrl = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *audacdirisel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *audiodetvthsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_audio_ctrl1_audio_pga_jack_pin_order_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_audio_ctrl1_audio_pga_jack_pin_order_sts_setf(uint8_t audiopgajackpinordersts)
{
    ASSERT_ERR((((uint32_t)audiopgajackpinordersts << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR, (REG_PL_RD(APB_AUDIO_CTRL1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)audiopgajackpinordersts << 8));
}

__INLINE uint8_t apb_audio_ctrl1_audio_pga_vcm_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_audio_ctrl1_audio_pga_vcm_ctrl_setf(uint8_t audiopgavcmctrl)
{
    ASSERT_ERR((((uint32_t)audiopgavcmctrl << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR, (REG_PL_RD(APB_AUDIO_CTRL1_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)audiopgavcmctrl << 6));
}

__INLINE uint8_t apb_audio_ctrl1_audac_dir_isel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_audio_ctrl1_audac_dir_isel_setf(uint8_t audacdirisel)
{
    ASSERT_ERR((((uint32_t)audacdirisel << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR, (REG_PL_RD(APB_AUDIO_CTRL1_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)audacdirisel << 4));
}

__INLINE uint8_t apb_audio_ctrl1_audio_det_vth_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_audio_ctrl1_audio_det_vth_sel_setf(uint8_t audiodetvthsel)
{
    ASSERT_ERR((((uint32_t)audiodetvthsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL1_ADDR, (REG_PL_RD(APB_AUDIO_CTRL1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)audiodetvthsel << 0));
}

/**
 * @brief AUDIO_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     24      Audac_cali_done   0
 *  23:16   saradc_pdata_out_0p45   0x0
 *  15:08   saradc_pdata_out_0p55   0x0
 * </pre>
 */
#define APB_AUDIO_CTRL2_ADDR   0xC0012008
#define APB_AUDIO_CTRL2_OFFSET 0x00000008
#define APB_AUDIO_CTRL2_INDEX  0x00000002
#define APB_AUDIO_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl2_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL2_ADDR);
}

__INLINE void apb_audio_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL2_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL2_AUDAC_CALI_DONE_BIT            ((uint32_t)0x01000000)
#define APB_AUDIO_CTRL2_AUDAC_CALI_DONE_POS            24
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_45_MASK   ((uint32_t)0x00FF0000)
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_45_LSB    16
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_45_WIDTH  ((uint32_t)0x00000008)
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_55_MASK   ((uint32_t)0x0000FF00)
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_55_LSB    8
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_55_WIDTH  ((uint32_t)0x00000008)

#define APB_AUDIO_CTRL2_AUDAC_CALI_DONE_RST            0x0
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_45_RST    0x0
#define APB_AUDIO_CTRL2_SARADC_PDATA_OUT__0P_55_RST    0x0

__INLINE void apb_audio_ctrl2_pack(uint8_t saradcpdataout0p45, uint8_t saradcpdataout0p55)
{
    ASSERT_ERR((((uint32_t)saradcpdataout0p45 << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)saradcpdataout0p55 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL2_ADDR,  ((uint32_t)saradcpdataout0p45 << 16) | ((uint32_t)saradcpdataout0p55 << 8));
}

__INLINE void apb_audio_ctrl2_unpack(uint8_t* audaccalidone, uint8_t* saradcpdataout0p45, uint8_t* saradcpdataout0p55)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL2_ADDR);
    *audaccalidone = (localVal & ((uint32_t)0x01000000)) >> 24;
    *saradcpdataout0p45 = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *saradcpdataout0p55 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
}

__INLINE uint8_t apb_audio_ctrl2_audac_cali_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t apb_audio_ctrl2_saradc_pdata_out__0p_45_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

__INLINE void apb_audio_ctrl2_saradc_pdata_out__0p_45_setf(uint8_t saradcpdataout0p45)
{
    ASSERT_ERR((((uint32_t)saradcpdataout0p45 << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL2_ADDR, (REG_PL_RD(APB_AUDIO_CTRL2_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)saradcpdataout0p45 << 16));
}

__INLINE uint8_t apb_audio_ctrl2_saradc_pdata_out__0p_55_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE void apb_audio_ctrl2_saradc_pdata_out__0p_55_setf(uint8_t saradcpdataout0p55)
{
    ASSERT_ERR((((uint32_t)saradcpdataout0p55 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL2_ADDR, (REG_PL_RD(APB_AUDIO_CTRL2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)saradcpdataout0p55 << 8));
}

/**
 * @brief AUDIO_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00      adldo_1p2v_tune   0x0
 * </pre>
 */
#define APB_AUDIO_CTRL3_ADDR   0xC001200C
#define APB_AUDIO_CTRL3_OFFSET 0x0000000C
#define APB_AUDIO_CTRL3_INDEX  0x00000003
#define APB_AUDIO_CTRL3_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl3_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL3_ADDR);
}

__INLINE void apb_audio_ctrl3_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL3_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL3_ADLDO__1P_2V_TUNE_MASK   ((uint32_t)0x00000003)
#define APB_AUDIO_CTRL3_ADLDO__1P_2V_TUNE_LSB    0
#define APB_AUDIO_CTRL3_ADLDO__1P_2V_TUNE_WIDTH  ((uint32_t)0x00000002)

#define APB_AUDIO_CTRL3_ADLDO__1P_2V_TUNE_RST    0x0

__INLINE uint8_t apb_audio_ctrl3_adldo__1p_2v_tune_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL3_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_audio_ctrl3_adldo__1p_2v_tune_setf(uint8_t adldo1p2vtune)
{
    ASSERT_ERR((((uint32_t)adldo1p2vtune << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL3_ADDR, (uint32_t)adldo1p2vtune << 0);
}

/**
 * @brief AUDIO_CTRL4 register definition
 */
#define APB_AUDIO_CTRL4_ADDR   0xC0012010
#define APB_AUDIO_CTRL4_OFFSET 0x00000010
#define APB_AUDIO_CTRL4_INDEX  0x00000004
#define APB_AUDIO_CTRL4_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl4_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL4_ADDR);
}

__INLINE void apb_audio_ctrl4_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL4_ADDR, value);
}

/**
 * @brief AUDIO_CTRL5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     24    audio_rccali_done   0
 *  23:20    audio_rccali_code   0x7
 *     19    Audio_rccali_flag   0
 *     18   Audio_rccali_start_flag   0
 *     17   audio_rccali_start   0
 *     16   audio_rccali_compout   0
 *     15      audio_rccali_en   0
 *     09        auldo_1p2v_pd   1
 *  07:00          audio_probe   0x0
 * </pre>
 */
#define APB_AUDIO_CTRL5_ADDR   0xC0012014
#define APB_AUDIO_CTRL5_OFFSET 0x00000014
#define APB_AUDIO_CTRL5_INDEX  0x00000005
#define APB_AUDIO_CTRL5_RESET  0x00700200

__INLINE uint32_t apb_audio_ctrl5_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
}

__INLINE void apb_audio_ctrl5_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_DONE_BIT          ((uint32_t)0x01000000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_DONE_POS          24
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_CODE_MASK         ((uint32_t)0x00F00000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_CODE_LSB          20
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_CODE_WIDTH        ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_FLAG_BIT          ((uint32_t)0x00080000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_FLAG_POS          19
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_FLAG_BIT    ((uint32_t)0x00040000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_FLAG_POS    18
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_BIT         ((uint32_t)0x00020000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_POS         17
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_COMPOUT_BIT       ((uint32_t)0x00010000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_COMPOUT_POS       16
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_EN_BIT            ((uint32_t)0x00008000)
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_EN_POS            15
#define APB_AUDIO_CTRL5_AULDO__1P_2V_PD_BIT            ((uint32_t)0x00000200)
#define APB_AUDIO_CTRL5_AULDO__1P_2V_PD_POS            9
#define APB_AUDIO_CTRL5_AUDIO_PROBE_MASK               ((uint32_t)0x000000FF)
#define APB_AUDIO_CTRL5_AUDIO_PROBE_LSB                0
#define APB_AUDIO_CTRL5_AUDIO_PROBE_WIDTH              ((uint32_t)0x00000008)

#define APB_AUDIO_CTRL5_AUDIO_RCCALI_DONE_RST          0x0
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_CODE_RST          0x7
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_FLAG_RST          0x0
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_FLAG_RST    0x0
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_START_RST         0x0
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_COMPOUT_RST       0x0
#define APB_AUDIO_CTRL5_AUDIO_RCCALI_EN_RST            0x0
#define APB_AUDIO_CTRL5_AULDO__1P_2V_PD_RST            0x1
#define APB_AUDIO_CTRL5_AUDIO_PROBE_RST                0x0

__INLINE void apb_audio_ctrl5_pack(uint8_t audiorccalicode, uint8_t audiorccaliflag, uint8_t audiorccalistartflag, uint8_t audiorccalistart, uint8_t audiorccalien, uint8_t auldo1p2vpd, uint8_t audioprobe)
{
    ASSERT_ERR((((uint32_t)audiorccalicode << 20) & ~((uint32_t)0x00F00000)) == 0);
    ASSERT_ERR((((uint32_t)audiorccaliflag << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)audiorccalistartflag << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)audiorccalistart << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)audiorccalien << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)auldo1p2vpd << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)audioprobe << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR,  ((uint32_t)audiorccalicode << 20) | ((uint32_t)audiorccaliflag << 19) | ((uint32_t)audiorccalistartflag << 18) | ((uint32_t)audiorccalistart << 17) | ((uint32_t)audiorccalien << 15) | ((uint32_t)auldo1p2vpd << 9) | ((uint32_t)audioprobe << 0));
}

__INLINE void apb_audio_ctrl5_unpack(uint8_t* audiorccalidone, uint8_t* audiorccalicode, uint8_t* audiorccaliflag, uint8_t* audiorccalistartflag, uint8_t* audiorccalistart, uint8_t* audiorccalicompout, uint8_t* audiorccalien, uint8_t* auldo1p2vpd, uint8_t* audioprobe)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    *audiorccalidone = (localVal & ((uint32_t)0x01000000)) >> 24;
    *audiorccalicode = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *audiorccaliflag = (localVal & ((uint32_t)0x00080000)) >> 19;
    *audiorccalistartflag = (localVal & ((uint32_t)0x00040000)) >> 18;
    *audiorccalistart = (localVal & ((uint32_t)0x00020000)) >> 17;
    *audiorccalicompout = (localVal & ((uint32_t)0x00010000)) >> 16;
    *audiorccalien = (localVal & ((uint32_t)0x00008000)) >> 15;
    *auldo1p2vpd = (localVal & ((uint32_t)0x00000200)) >> 9;
    *audioprobe = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_code_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

__INLINE void apb_audio_ctrl5_audio_rccali_code_setf(uint8_t audiorccalicode)
{
    ASSERT_ERR((((uint32_t)audiorccalicode << 20) & ~((uint32_t)0x00F00000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)audiorccalicode << 20));
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_audio_ctrl5_audio_rccali_flag_setf(uint8_t audiorccaliflag)
{
    ASSERT_ERR((((uint32_t)audiorccaliflag << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)audiorccaliflag << 19));
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_start_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_audio_ctrl5_audio_rccali_start_flag_setf(uint8_t audiorccalistartflag)
{
    ASSERT_ERR((((uint32_t)audiorccalistartflag << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)audiorccalistartflag << 18));
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_start_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_audio_ctrl5_audio_rccali_start_setf(uint8_t audiorccalistart)
{
    ASSERT_ERR((((uint32_t)audiorccalistart << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)audiorccalistart << 17));
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_compout_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE uint8_t apb_audio_ctrl5_audio_rccali_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_audio_ctrl5_audio_rccali_en_setf(uint8_t audiorccalien)
{
    ASSERT_ERR((((uint32_t)audiorccalien << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)audiorccalien << 15));
}

__INLINE uint8_t apb_audio_ctrl5_auldo__1p_2v_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_audio_ctrl5_auldo__1p_2v_pd_setf(uint8_t auldo1p2vpd)
{
    ASSERT_ERR((((uint32_t)auldo1p2vpd << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)auldo1p2vpd << 9));
}

__INLINE uint8_t apb_audio_ctrl5_audio_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL5_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_audio_ctrl5_audio_probe_setf(uint8_t audioprobe)
{
    ASSERT_ERR((((uint32_t)audioprobe << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL5_ADDR, (REG_PL_RD(APB_AUDIO_CTRL5_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)audioprobe << 0));
}

/**
 * @brief AUDIO_CTRL6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:20      Audac_itrim_fsm   0x0
 *  19:16   Audio_rccali_code_fsm   0x0
 *  13:00   audio_in_valid_counter_1L   0x0
 * </pre>
 */
#define APB_AUDIO_CTRL6_ADDR   0xC0012018
#define APB_AUDIO_CTRL6_OFFSET 0x00000018
#define APB_AUDIO_CTRL6_INDEX  0x00000006
#define APB_AUDIO_CTRL6_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl6_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL6_ADDR);
}

__INLINE void apb_audio_ctrl6_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL6_ADDR, value);
}

// field definitions
#define APB_AUDIO_CTRL6_AUDAC_ITRIM_FSM_MASK              ((uint32_t)0x00F00000)
#define APB_AUDIO_CTRL6_AUDAC_ITRIM_FSM_LSB               20
#define APB_AUDIO_CTRL6_AUDAC_ITRIM_FSM_WIDTH             ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL6_AUDIO_RCCALI_CODE_FSM_MASK        ((uint32_t)0x000F0000)
#define APB_AUDIO_CTRL6_AUDIO_RCCALI_CODE_FSM_LSB         16
#define APB_AUDIO_CTRL6_AUDIO_RCCALI_CODE_FSM_WIDTH       ((uint32_t)0x00000004)
#define APB_AUDIO_CTRL6_AUDIO_IN_VALID_COUNTER__1L_MASK   ((uint32_t)0x00003FFF)
#define APB_AUDIO_CTRL6_AUDIO_IN_VALID_COUNTER__1L_LSB    0
#define APB_AUDIO_CTRL6_AUDIO_IN_VALID_COUNTER__1L_WIDTH  ((uint32_t)0x0000000E)

#define APB_AUDIO_CTRL6_AUDAC_ITRIM_FSM_RST               0x0
#define APB_AUDIO_CTRL6_AUDIO_RCCALI_CODE_FSM_RST         0x0
#define APB_AUDIO_CTRL6_AUDIO_IN_VALID_COUNTER__1L_RST    0x0

__INLINE void apb_audio_ctrl6_pack(uint8_t audacitrimfsm, uint8_t audiorccalicodefsm)
{
    ASSERT_ERR((((uint32_t)audacitrimfsm << 20) & ~((uint32_t)0x00F00000)) == 0);
    ASSERT_ERR((((uint32_t)audiorccalicodefsm << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL6_ADDR,  ((uint32_t)audacitrimfsm << 20) | ((uint32_t)audiorccalicodefsm << 16));
}

__INLINE void apb_audio_ctrl6_unpack(uint8_t* audacitrimfsm, uint8_t* audiorccalicodefsm, uint16_t* audioinvalidcounter1l)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL6_ADDR);
    *audacitrimfsm = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *audiorccalicodefsm = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *audioinvalidcounter1l = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

__INLINE uint8_t apb_audio_ctrl6_audac_itrim_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL6_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

__INLINE void apb_audio_ctrl6_audac_itrim_fsm_setf(uint8_t audacitrimfsm)
{
    ASSERT_ERR((((uint32_t)audacitrimfsm << 20) & ~((uint32_t)0x00F00000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL6_ADDR, (REG_PL_RD(APB_AUDIO_CTRL6_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)audacitrimfsm << 20));
}

__INLINE uint8_t apb_audio_ctrl6_audio_rccali_code_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL6_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_audio_ctrl6_audio_rccali_code_fsm_setf(uint8_t audiorccalicodefsm)
{
    ASSERT_ERR((((uint32_t)audiorccalicodefsm << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_AUDIO_CTRL6_ADDR, (REG_PL_RD(APB_AUDIO_CTRL6_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)audiorccalicodefsm << 16));
}

__INLINE uint16_t apb_audio_ctrl6_audio_in_valid_counter__1l_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_CTRL6_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

/**
 * @brief AUDIO_CTRL7 register definition
 */
#define APB_AUDIO_CTRL7_ADDR   0xC001201C
#define APB_AUDIO_CTRL7_OFFSET 0x0000001C
#define APB_AUDIO_CTRL7_INDEX  0x00000007
#define APB_AUDIO_CTRL7_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl7_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL7_ADDR);
}

__INLINE void apb_audio_ctrl7_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL7_ADDR, value);
}

/**
 * @brief AUDIO_CTRL8 register definition
 */
#define APB_AUDIO_CTRL8_ADDR   0xC0012020
#define APB_AUDIO_CTRL8_OFFSET 0x00000020
#define APB_AUDIO_CTRL8_INDEX  0x00000008
#define APB_AUDIO_CTRL8_RESET  0x00000000

__INLINE uint32_t apb_audio_ctrl8_get(void)
{
    return REG_PL_RD(APB_AUDIO_CTRL8_ADDR);
}

__INLINE void apb_audio_ctrl8_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_CTRL8_ADDR, value);
}

/**
 * @brief AUDIO_PD_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     29     audac_R_aui2v_pd   1
 *     28     audac_L_aui2v_pd   1
 *     24           audac_R_pd   1
 *     23           audac_L_pd   1
 *     19           auadc_1_pd   1
 *     18        audac_bias_pd   1
 *     09         auadc_vcm_pd   1
 *     08         audio_det_pd   1
 *     06          audet_rst_n   0
 *     01            auadc_rst   1
 *     00       auadc_vcmo_rst   1
 * </pre>
 */
#define APB_AUDIO_PD_RST_ADDR   0xC0012024
#define APB_AUDIO_PD_RST_OFFSET 0x00000024
#define APB_AUDIO_PD_RST_INDEX  0x00000009
#define APB_AUDIO_PD_RST_RESET  0x318C0303

__INLINE uint32_t apb_audio_pd_rst_get(void)
{
    return REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
}

__INLINE void apb_audio_pd_rst_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, value);
}

// field definitions
#define APB_AUDIO_PD_RST_AUDAC_R_AUI_2V_PD_BIT    ((uint32_t)0x20000000)
#define APB_AUDIO_PD_RST_AUDAC_R_AUI_2V_PD_POS    29
#define APB_AUDIO_PD_RST_AUDAC_L_AUI_2V_PD_BIT    ((uint32_t)0x10000000)
#define APB_AUDIO_PD_RST_AUDAC_L_AUI_2V_PD_POS    28
#define APB_AUDIO_PD_RST_AUDAC_R_PD_BIT           ((uint32_t)0x01000000)
#define APB_AUDIO_PD_RST_AUDAC_R_PD_POS           24
#define APB_AUDIO_PD_RST_AUDAC_L_PD_BIT           ((uint32_t)0x00800000)
#define APB_AUDIO_PD_RST_AUDAC_L_PD_POS           23
#define APB_AUDIO_PD_RST_AUADC__1_PD_BIT          ((uint32_t)0x00080000)
#define APB_AUDIO_PD_RST_AUADC__1_PD_POS          19
#define APB_AUDIO_PD_RST_AUDAC_BIAS_PD_BIT        ((uint32_t)0x00040000)
#define APB_AUDIO_PD_RST_AUDAC_BIAS_PD_POS        18
#define APB_AUDIO_PD_RST_AUADC_VCM_PD_BIT         ((uint32_t)0x00000200)
#define APB_AUDIO_PD_RST_AUADC_VCM_PD_POS         9
#define APB_AUDIO_PD_RST_AUDIO_DET_PD_BIT         ((uint32_t)0x00000100)
#define APB_AUDIO_PD_RST_AUDIO_DET_PD_POS         8
#define APB_AUDIO_PD_RST_AUDET_RST_N_BIT          ((uint32_t)0x00000040)
#define APB_AUDIO_PD_RST_AUDET_RST_N_POS          6
#define APB_AUDIO_PD_RST_AUADC_RST_BIT            ((uint32_t)0x00000002)
#define APB_AUDIO_PD_RST_AUADC_RST_POS            1
#define APB_AUDIO_PD_RST_AUADC_VCMO_RST_BIT       ((uint32_t)0x00000001)
#define APB_AUDIO_PD_RST_AUADC_VCMO_RST_POS       0

#define APB_AUDIO_PD_RST_AUDAC_R_AUI_2V_PD_RST    0x1
#define APB_AUDIO_PD_RST_AUDAC_L_AUI_2V_PD_RST    0x1
#define APB_AUDIO_PD_RST_AUDAC_R_PD_RST           0x1
#define APB_AUDIO_PD_RST_AUDAC_L_PD_RST           0x1
#define APB_AUDIO_PD_RST_AUADC__1_PD_RST          0x1
#define APB_AUDIO_PD_RST_AUDAC_BIAS_PD_RST        0x1
#define APB_AUDIO_PD_RST_AUADC_VCM_PD_RST         0x1
#define APB_AUDIO_PD_RST_AUDIO_DET_PD_RST         0x1
#define APB_AUDIO_PD_RST_AUDET_RST_N_RST          0x0
#define APB_AUDIO_PD_RST_AUADC_RST_RST            0x1
#define APB_AUDIO_PD_RST_AUADC_VCMO_RST_RST       0x1

__INLINE void apb_audio_pd_rst_pack(uint8_t audacraui2vpd, uint8_t audaclaui2vpd, uint8_t audacrpd, uint8_t audaclpd, uint8_t auadc1pd, uint8_t audacbiaspd, uint8_t auadcvcmpd, uint8_t audiodetpd, uint8_t audetrstn, uint8_t auadcrst, uint8_t auadcvcmorst)
{
    ASSERT_ERR((((uint32_t)audacraui2vpd << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)audaclaui2vpd << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)audacrpd << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)audaclpd << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)auadc1pd << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)audacbiaspd << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)auadcvcmpd << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)audiodetpd << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)audetrstn << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)auadcrst << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)auadcvcmorst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR,  ((uint32_t)audacraui2vpd << 29) | ((uint32_t)audaclaui2vpd << 28) | ((uint32_t)audacrpd << 24) | ((uint32_t)audaclpd << 23) | ((uint32_t)auadc1pd << 19) | ((uint32_t)audacbiaspd << 18) | ((uint32_t)auadcvcmpd << 9) | ((uint32_t)audiodetpd << 8) | ((uint32_t)audetrstn << 6) | ((uint32_t)auadcrst << 1) | ((uint32_t)auadcvcmorst << 0));
}

__INLINE void apb_audio_pd_rst_unpack(uint8_t* audacraui2vpd, uint8_t* audaclaui2vpd, uint8_t* audacrpd, uint8_t* audaclpd, uint8_t* auadc1pd, uint8_t* audacbiaspd, uint8_t* auadcvcmpd, uint8_t* audiodetpd, uint8_t* audetrstn, uint8_t* auadcrst, uint8_t* auadcvcmorst)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    *audacraui2vpd = (localVal & ((uint32_t)0x20000000)) >> 29;
    *audaclaui2vpd = (localVal & ((uint32_t)0x10000000)) >> 28;
    *audacrpd = (localVal & ((uint32_t)0x01000000)) >> 24;
    *audaclpd = (localVal & ((uint32_t)0x00800000)) >> 23;
    *auadc1pd = (localVal & ((uint32_t)0x00080000)) >> 19;
    *audacbiaspd = (localVal & ((uint32_t)0x00040000)) >> 18;
    *auadcvcmpd = (localVal & ((uint32_t)0x00000200)) >> 9;
    *audiodetpd = (localVal & ((uint32_t)0x00000100)) >> 8;
    *audetrstn = (localVal & ((uint32_t)0x00000040)) >> 6;
    *auadcrst = (localVal & ((uint32_t)0x00000002)) >> 1;
    *auadcvcmorst = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_audio_pd_rst_audac_r_aui_2v_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void apb_audio_pd_rst_audac_r_aui_2v_pd_setf(uint8_t audacraui2vpd)
{
    ASSERT_ERR((((uint32_t)audacraui2vpd << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)audacraui2vpd << 29));
}

__INLINE uint8_t apb_audio_pd_rst_audac_l_aui_2v_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void apb_audio_pd_rst_audac_l_aui_2v_pd_setf(uint8_t audaclaui2vpd)
{
    ASSERT_ERR((((uint32_t)audaclaui2vpd << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)audaclaui2vpd << 28));
}

__INLINE uint8_t apb_audio_pd_rst_audac_r_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_audio_pd_rst_audac_r_pd_setf(uint8_t audacrpd)
{
    ASSERT_ERR((((uint32_t)audacrpd << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)audacrpd << 24));
}

__INLINE uint8_t apb_audio_pd_rst_audac_l_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_audio_pd_rst_audac_l_pd_setf(uint8_t audaclpd)
{
    ASSERT_ERR((((uint32_t)audaclpd << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)audaclpd << 23));
}

__INLINE uint8_t apb_audio_pd_rst_auadc__1_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_audio_pd_rst_auadc__1_pd_setf(uint8_t auadc1pd)
{
    ASSERT_ERR((((uint32_t)auadc1pd << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)auadc1pd << 19));
}

__INLINE uint8_t apb_audio_pd_rst_audac_bias_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_audio_pd_rst_audac_bias_pd_setf(uint8_t audacbiaspd)
{
    ASSERT_ERR((((uint32_t)audacbiaspd << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)audacbiaspd << 18));
}

__INLINE uint8_t apb_audio_pd_rst_auadc_vcm_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_audio_pd_rst_auadc_vcm_pd_setf(uint8_t auadcvcmpd)
{
    ASSERT_ERR((((uint32_t)auadcvcmpd << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)auadcvcmpd << 9));
}

__INLINE uint8_t apb_audio_pd_rst_audio_det_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_audio_pd_rst_audio_det_pd_setf(uint8_t audiodetpd)
{
    ASSERT_ERR((((uint32_t)audiodetpd << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)audiodetpd << 8));
}

__INLINE uint8_t apb_audio_pd_rst_audet_rst_n_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void apb_audio_pd_rst_audet_rst_n_setf(uint8_t audetrstn)
{
    ASSERT_ERR((((uint32_t)audetrstn << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)audetrstn << 6));
}

__INLINE uint8_t apb_audio_pd_rst_auadc_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_audio_pd_rst_auadc_rst_setf(uint8_t auadcrst)
{
    ASSERT_ERR((((uint32_t)auadcrst << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)auadcrst << 1));
}

__INLINE uint8_t apb_audio_pd_rst_auadc_vcmo_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_PD_RST_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_audio_pd_rst_auadc_vcmo_rst_setf(uint8_t auadcvcmorst)
{
    ASSERT_ERR((((uint32_t)auadcvcmorst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_PD_RST_ADDR, (REG_PL_RD(APB_AUDIO_PD_RST_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)auadcvcmorst << 0));
}

/**
 * @brief AUDIO_PD_RST_RESERVE register definition
 */
#define APB_AUDIO_PD_RST_RESERVE_ADDR   0xC0012028
#define APB_AUDIO_PD_RST_RESERVE_OFFSET 0x00000028
#define APB_AUDIO_PD_RST_RESERVE_INDEX  0x0000000A
#define APB_AUDIO_PD_RST_RESERVE_RESET  0x00000000

__INLINE uint32_t apb_audio_pd_rst_reserve_get(void)
{
    return REG_PL_RD(APB_AUDIO_PD_RST_RESERVE_ADDR);
}

__INLINE void apb_audio_pd_rst_reserve_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_PD_RST_RESERVE_ADDR, value);
}

/**
 * @brief BBPLL_CTRL0 register definition
 */
#define APB_BBPLL_CTRL0_ADDR   0xC001202C
#define APB_BBPLL_CTRL0_OFFSET 0x0000002C
#define APB_BBPLL_CTRL0_INDEX  0x0000000B
#define APB_BBPLL_CTRL0_RESET  0x00000000

__INLINE uint32_t apb_bbpll_ctrl0_get(void)
{
    return REG_PL_RD(APB_BBPLL_CTRL0_ADDR);
}

__INLINE void apb_bbpll_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_BBPLL_CTRL0_ADDR, value);
}

/**
 * @brief BBPLL_CTRL1 register definition
 */
#define APB_BBPLL_CTRL1_ADDR   0xC0012030
#define APB_BBPLL_CTRL1_OFFSET 0x00000030
#define APB_BBPLL_CTRL1_INDEX  0x0000000C
#define APB_BBPLL_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_bbpll_ctrl1_get(void)
{
    return REG_PL_RD(APB_BBPLL_CTRL1_ADDR);
}

__INLINE void apb_bbpll_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_BBPLL_CTRL1_ADDR, value);
}

/**
 * @brief BBPLL_CTRL2 register definition
 */
#define APB_BBPLL_CTRL2_ADDR   0xC0012034
#define APB_BBPLL_CTRL2_OFFSET 0x00000034
#define APB_BBPLL_CTRL2_INDEX  0x0000000D
#define APB_BBPLL_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_bbpll_ctrl2_get(void)
{
    return REG_PL_RD(APB_BBPLL_CTRL2_ADDR);
}

__INLINE void apb_bbpll_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_BBPLL_CTRL2_ADDR, value);
}

/**
 * @brief VCO_COUNTER_CFG register definition
 */
#define APB_VCO_COUNTER_CFG_ADDR   0xC0012038
#define APB_VCO_COUNTER_CFG_OFFSET 0x00000038
#define APB_VCO_COUNTER_CFG_INDEX  0x0000000E
#define APB_VCO_COUNTER_CFG_RESET  0x00000000

__INLINE uint32_t apb_vco_counter_cfg_get(void)
{
    return REG_PL_RD(APB_VCO_COUNTER_CFG_ADDR);
}

__INLINE void apb_vco_counter_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_VCO_COUNTER_CFG_ADDR, value);
}

/**
 * @brief DIGLDO_CTRL0 register definition
 */
#define APB_DIGLDO_CTRL0_ADDR   0xC001203C
#define APB_DIGLDO_CTRL0_OFFSET 0x0000003C
#define APB_DIGLDO_CTRL0_INDEX  0x0000000F
#define APB_DIGLDO_CTRL0_RESET  0x00000000

__INLINE uint32_t apb_digldo_ctrl0_get(void)
{
    return REG_PL_RD(APB_DIGLDO_CTRL0_ADDR);
}

__INLINE void apb_digldo_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_DIGLDO_CTRL0_ADDR, value);
}

/**
 * @brief DIGLDO_CTRL1 register definition
 */
#define APB_DIGLDO_CTRL1_ADDR   0xC0012040
#define APB_DIGLDO_CTRL1_OFFSET 0x00000040
#define APB_DIGLDO_CTRL1_INDEX  0x00000010
#define APB_DIGLDO_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_digldo_ctrl1_get(void)
{
    return REG_PL_RD(APB_DIGLDO_CTRL1_ADDR);
}

__INLINE void apb_digldo_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_DIGLDO_CTRL1_ADDR, value);
}

/**
 * @brief DIGLDO_CTRL_RESERVE register definition
 */
#define APB_DIGLDO_CTRL_RESERVE_ADDR   0xC0012044
#define APB_DIGLDO_CTRL_RESERVE_OFFSET 0x00000044
#define APB_DIGLDO_CTRL_RESERVE_INDEX  0x00000011
#define APB_DIGLDO_CTRL_RESERVE_RESET  0x00000000

__INLINE uint32_t apb_digldo_ctrl_reserve_get(void)
{
    return REG_PL_RD(APB_DIGLDO_CTRL_RESERVE_ADDR);
}

__INLINE void apb_digldo_ctrl_reserve_set(uint32_t value)
{
    REG_PL_WR(APB_DIGLDO_CTRL_RESERVE_ADDR, value);
}

/**
 * @brief OSC_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:02          osc_fre_sel   0x1
 *     00            osc_probe   0
 * </pre>
 */
#define APB_OSC_CTRL_ADDR   0xC0012048
#define APB_OSC_CTRL_OFFSET 0x00000048
#define APB_OSC_CTRL_INDEX  0x00000012
#define APB_OSC_CTRL_RESET  0x00000004

__INLINE uint32_t apb_osc_ctrl_get(void)
{
    return REG_PL_RD(APB_OSC_CTRL_ADDR);
}

__INLINE void apb_osc_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_OSC_CTRL_ADDR, value);
}

// field definitions
#define APB_OSC_CTRL_OSC_FRE_SEL_MASK   ((uint32_t)0x0000000C)
#define APB_OSC_CTRL_OSC_FRE_SEL_LSB    2
#define APB_OSC_CTRL_OSC_FRE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_OSC_CTRL_OSC_PROBE_BIT      ((uint32_t)0x00000001)
#define APB_OSC_CTRL_OSC_PROBE_POS      0

#define APB_OSC_CTRL_OSC_FRE_SEL_RST    0x1
#define APB_OSC_CTRL_OSC_PROBE_RST      0x0

__INLINE void apb_osc_ctrl_pack(uint8_t oscfresel, uint8_t oscprobe)
{
    ASSERT_ERR((((uint32_t)oscfresel << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)oscprobe << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_OSC_CTRL_ADDR,  ((uint32_t)oscfresel << 2) | ((uint32_t)oscprobe << 0));
}

__INLINE void apb_osc_ctrl_unpack(uint8_t* oscfresel, uint8_t* oscprobe)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CTRL_ADDR);
    *oscfresel = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *oscprobe = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_osc_ctrl_osc_fre_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_osc_ctrl_osc_fre_sel_setf(uint8_t oscfresel)
{
    ASSERT_ERR((((uint32_t)oscfresel << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_OSC_CTRL_ADDR, (REG_PL_RD(APB_OSC_CTRL_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)oscfresel << 2));
}

__INLINE uint8_t apb_osc_ctrl_osc_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_osc_ctrl_osc_probe_setf(uint8_t oscprobe)
{
    ASSERT_ERR((((uint32_t)oscprobe << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_OSC_CTRL_ADDR, (REG_PL_RD(APB_OSC_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)oscprobe << 0));
}

/**
 * @brief REF_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  04:03         ref_vreg_sel   0x0
 *     02             ref_pd3v   0
 *  01:00            ref_probe   0x0
 * </pre>
 */
#define APB_REF_CTRL_ADDR   0xC001204C
#define APB_REF_CTRL_OFFSET 0x0000004C
#define APB_REF_CTRL_INDEX  0x00000013
#define APB_REF_CTRL_RESET  0x00000000

__INLINE uint32_t apb_ref_ctrl_get(void)
{
    return REG_PL_RD(APB_REF_CTRL_ADDR);
}

__INLINE void apb_ref_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_REF_CTRL_ADDR, value);
}

// field definitions
#define APB_REF_CTRL_REF_VREG_SEL_MASK   ((uint32_t)0x00000018)
#define APB_REF_CTRL_REF_VREG_SEL_LSB    3
#define APB_REF_CTRL_REF_VREG_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_REF_CTRL_REF_PD_3V_BIT       ((uint32_t)0x00000004)
#define APB_REF_CTRL_REF_PD_3V_POS       2
#define APB_REF_CTRL_REF_PROBE_MASK      ((uint32_t)0x00000003)
#define APB_REF_CTRL_REF_PROBE_LSB       0
#define APB_REF_CTRL_REF_PROBE_WIDTH     ((uint32_t)0x00000002)

#define APB_REF_CTRL_REF_VREG_SEL_RST    0x0
#define APB_REF_CTRL_REF_PD_3V_RST       0x0
#define APB_REF_CTRL_REF_PROBE_RST       0x0

__INLINE void apb_ref_ctrl_pack(uint8_t refvregsel, uint8_t refprobe)
{
    ASSERT_ERR((((uint32_t)refvregsel << 3) & ~((uint32_t)0x00000018)) == 0);
    ASSERT_ERR((((uint32_t)refprobe << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_REF_CTRL_ADDR,  ((uint32_t)refvregsel << 3) | ((uint32_t)refprobe << 0));
}

__INLINE void apb_ref_ctrl_unpack(uint8_t* refvregsel, uint8_t* refpd3v, uint8_t* refprobe)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_REF_CTRL_ADDR);
    *refvregsel = (localVal & ((uint32_t)0x00000018)) >> 3;
    *refpd3v = (localVal & ((uint32_t)0x00000004)) >> 2;
    *refprobe = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_ref_ctrl_ref_vreg_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_REF_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000018)) >> 3);
}

__INLINE void apb_ref_ctrl_ref_vreg_sel_setf(uint8_t refvregsel)
{
    ASSERT_ERR((((uint32_t)refvregsel << 3) & ~((uint32_t)0x00000018)) == 0);
    REG_PL_WR(APB_REF_CTRL_ADDR, (REG_PL_RD(APB_REF_CTRL_ADDR) & ~((uint32_t)0x00000018)) | ((uint32_t)refvregsel << 3));
}

__INLINE uint8_t apb_ref_ctrl_ref_pd_3v_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_REF_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_ref_ctrl_ref_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_REF_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void apb_ref_ctrl_ref_probe_setf(uint8_t refprobe)
{
    ASSERT_ERR((((uint32_t)refprobe << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_REF_CTRL_ADDR, (REG_PL_RD(APB_REF_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)refprobe << 0));
}

/**
 * @brief SARADC_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     25         saradc_probe   0
 *     24       saradc_clk_sel   0
 *  23:22       saradc_ldo_sel   0x0
 *     17    saradc_pdata_done   0
 *  16:07     saradc_pdata_out   0x200
 *     03            saradc_pd   1
 *     02     saradc_dig_rst_n   0
 *     01        saradc_ldo_pd   1
 *     00    Saradc_ctrl_start   0
 * </pre>
 */
#define APB_SARADC_CTRL_ADDR   0xC0012050
#define APB_SARADC_CTRL_OFFSET 0x00000050
#define APB_SARADC_CTRL_INDEX  0x00000014
#define APB_SARADC_CTRL_RESET  0x0001000A

__INLINE uint32_t apb_saradc_ctrl_get(void)
{
    return REG_PL_RD(APB_SARADC_CTRL_ADDR);
}

__INLINE void apb_saradc_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_SARADC_CTRL_ADDR, value);
}

// field definitions
#define APB_SARADC_CTRL_SARADC_PROBE_BIT         ((uint32_t)0x02000000)
#define APB_SARADC_CTRL_SARADC_PROBE_POS         25
#define APB_SARADC_CTRL_SARADC_CLK_SEL_BIT       ((uint32_t)0x01000000)
#define APB_SARADC_CTRL_SARADC_CLK_SEL_POS       24
#define APB_SARADC_CTRL_SARADC_LDO_SEL_MASK      ((uint32_t)0x00C00000)
#define APB_SARADC_CTRL_SARADC_LDO_SEL_LSB       22
#define APB_SARADC_CTRL_SARADC_LDO_SEL_WIDTH     ((uint32_t)0x00000002)
#define APB_SARADC_CTRL_SARADC_PDATA_DONE_BIT    ((uint32_t)0x00020000)
#define APB_SARADC_CTRL_SARADC_PDATA_DONE_POS    17
#define APB_SARADC_CTRL_SARADC_PDATA_OUT_MASK    ((uint32_t)0x0001FF80)
#define APB_SARADC_CTRL_SARADC_PDATA_OUT_LSB     7
#define APB_SARADC_CTRL_SARADC_PDATA_OUT_WIDTH   ((uint32_t)0x0000000A)
#define APB_SARADC_CTRL_SARADC_PD_BIT            ((uint32_t)0x00000008)
#define APB_SARADC_CTRL_SARADC_PD_POS            3
#define APB_SARADC_CTRL_SARADC_DIG_RST_N_BIT     ((uint32_t)0x00000004)
#define APB_SARADC_CTRL_SARADC_DIG_RST_N_POS     2
#define APB_SARADC_CTRL_SARADC_LDO_PD_BIT        ((uint32_t)0x00000002)
#define APB_SARADC_CTRL_SARADC_LDO_PD_POS        1
#define APB_SARADC_CTRL_SARADC_CTRL_START_BIT    ((uint32_t)0x00000001)
#define APB_SARADC_CTRL_SARADC_CTRL_START_POS    0

#define APB_SARADC_CTRL_SARADC_PROBE_RST         0x0
#define APB_SARADC_CTRL_SARADC_CLK_SEL_RST       0x0
#define APB_SARADC_CTRL_SARADC_LDO_SEL_RST       0x0
#define APB_SARADC_CTRL_SARADC_PDATA_DONE_RST    0x0
#define APB_SARADC_CTRL_SARADC_PDATA_OUT_RST     0x200
#define APB_SARADC_CTRL_SARADC_PD_RST            0x1
#define APB_SARADC_CTRL_SARADC_DIG_RST_N_RST     0x0
#define APB_SARADC_CTRL_SARADC_LDO_PD_RST        0x1
#define APB_SARADC_CTRL_SARADC_CTRL_START_RST    0x0

__INLINE void apb_saradc_ctrl_pack(uint8_t saradcprobe, uint8_t saradcclksel, uint8_t saradcldosel, uint8_t saradcpd, uint8_t saradcdigrstn, uint8_t saradcldopd, uint8_t saradcctrlstart)
{
    ASSERT_ERR((((uint32_t)saradcprobe << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)saradcclksel << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)saradcldosel << 22) & ~((uint32_t)0x00C00000)) == 0);
    ASSERT_ERR((((uint32_t)saradcpd << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)saradcdigrstn << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)saradcldopd << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)saradcctrlstart << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR,  ((uint32_t)saradcprobe << 25) | ((uint32_t)saradcclksel << 24) | ((uint32_t)saradcldosel << 22) | ((uint32_t)saradcpd << 3) | ((uint32_t)saradcdigrstn << 2) | ((uint32_t)saradcldopd << 1) | ((uint32_t)saradcctrlstart << 0));
}

__INLINE void apb_saradc_ctrl_unpack(uint8_t* saradcprobe, uint8_t* saradcclksel, uint8_t* saradcldosel, uint8_t* saradcpdatadone, uint16_t* saradcpdataout, uint8_t* saradcpd, uint8_t* saradcdigrstn, uint8_t* saradcldopd, uint8_t* saradcctrlstart)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    *saradcprobe = (localVal & ((uint32_t)0x02000000)) >> 25;
    *saradcclksel = (localVal & ((uint32_t)0x01000000)) >> 24;
    *saradcldosel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *saradcpdatadone = (localVal & ((uint32_t)0x00020000)) >> 17;
    *saradcpdataout = (localVal & ((uint32_t)0x0001FF80)) >> 7;
    *saradcpd = (localVal & ((uint32_t)0x00000008)) >> 3;
    *saradcdigrstn = (localVal & ((uint32_t)0x00000004)) >> 2;
    *saradcldopd = (localVal & ((uint32_t)0x00000002)) >> 1;
    *saradcctrlstart = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_saradc_ctrl_saradc_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_saradc_ctrl_saradc_probe_setf(uint8_t saradcprobe)
{
    ASSERT_ERR((((uint32_t)saradcprobe << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)saradcprobe << 25));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_clk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_saradc_ctrl_saradc_clk_sel_setf(uint8_t saradcclksel)
{
    ASSERT_ERR((((uint32_t)saradcclksel << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)saradcclksel << 24));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_ldo_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void apb_saradc_ctrl_saradc_ldo_sel_setf(uint8_t saradcldosel)
{
    ASSERT_ERR((((uint32_t)saradcldosel << 22) & ~((uint32_t)0x00C00000)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)saradcldosel << 22));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_pdata_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE uint16_t apb_saradc_ctrl_saradc_pdata_out_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0001FF80)) >> 7);
}

__INLINE uint8_t apb_saradc_ctrl_saradc_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_saradc_ctrl_saradc_pd_setf(uint8_t saradcpd)
{
    ASSERT_ERR((((uint32_t)saradcpd << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)saradcpd << 3));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_dig_rst_n_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_saradc_ctrl_saradc_dig_rst_n_setf(uint8_t saradcdigrstn)
{
    ASSERT_ERR((((uint32_t)saradcdigrstn << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)saradcdigrstn << 2));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_ldo_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_saradc_ctrl_saradc_ldo_pd_setf(uint8_t saradcldopd)
{
    ASSERT_ERR((((uint32_t)saradcldopd << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)saradcldopd << 1));
}

__INLINE uint8_t apb_saradc_ctrl_saradc_ctrl_start_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SARADC_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_saradc_ctrl_saradc_ctrl_start_setf(uint8_t saradcctrlstart)
{
    ASSERT_ERR((((uint32_t)saradcctrlstart << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_SARADC_CTRL_ADDR, (REG_PL_RD(APB_SARADC_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)saradcctrlstart << 0));
}

/**
 * @brief SARADC_CTRL_RESERVE register definition
 */
#define APB_SARADC_CTRL_RESERVE_ADDR   0xC0012054
#define APB_SARADC_CTRL_RESERVE_OFFSET 0x00000054
#define APB_SARADC_CTRL_RESERVE_INDEX  0x00000015
#define APB_SARADC_CTRL_RESERVE_RESET  0x00000000

__INLINE uint32_t apb_saradc_ctrl_reserve_get(void)
{
    return REG_PL_RD(APB_SARADC_CTRL_RESERVE_ADDR);
}

__INLINE void apb_saradc_ctrl_reserve_set(uint32_t value)
{
    REG_PL_WR(APB_SARADC_CTRL_RESERVE_ADDR, value);
}

/**
 * @brief XTAL_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     18        xtal_smit_dis   0
 *  17:16        xtal_buf_isel   0x2
 *  15:12            xtal_isel   0x6
 *  11:08         xtalldo_vsel   0x0
 *     04        xtalldo_rst_n   0
 *     03         xtalldo_pd3v   0
 *     02            xtal_pd3v   0
 *  01:00           xtal_probe   0x0
 * </pre>
 */
#define APB_XTAL_CTRL_ADDR   0xC0012058
#define APB_XTAL_CTRL_OFFSET 0x00000058
#define APB_XTAL_CTRL_INDEX  0x00000016
#define APB_XTAL_CTRL_RESET  0x00026000

__INLINE uint32_t apb_xtal_ctrl_get(void)
{
    return REG_PL_RD(APB_XTAL_CTRL_ADDR);
}

__INLINE void apb_xtal_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_XTAL_CTRL_ADDR, value);
}

// field definitions
#define APB_XTAL_CTRL_XTAL_SMIT_DIS_BIT    ((uint32_t)0x00040000)
#define APB_XTAL_CTRL_XTAL_SMIT_DIS_POS    18
#define APB_XTAL_CTRL_XTAL_BUF_ISEL_MASK   ((uint32_t)0x00030000)
#define APB_XTAL_CTRL_XTAL_BUF_ISEL_LSB    16
#define APB_XTAL_CTRL_XTAL_BUF_ISEL_WIDTH  ((uint32_t)0x00000002)
#define APB_XTAL_CTRL_XTAL_ISEL_MASK       ((uint32_t)0x0000F000)
#define APB_XTAL_CTRL_XTAL_ISEL_LSB        12
#define APB_XTAL_CTRL_XTAL_ISEL_WIDTH      ((uint32_t)0x00000004)
#define APB_XTAL_CTRL_XTALLDO_VSEL_MASK    ((uint32_t)0x00000F00)
#define APB_XTAL_CTRL_XTALLDO_VSEL_LSB     8
#define APB_XTAL_CTRL_XTALLDO_VSEL_WIDTH   ((uint32_t)0x00000004)
#define APB_XTAL_CTRL_XTALLDO_RST_N_BIT    ((uint32_t)0x00000010)
#define APB_XTAL_CTRL_XTALLDO_RST_N_POS    4
#define APB_XTAL_CTRL_XTALLDO_PD_3V_BIT    ((uint32_t)0x00000008)
#define APB_XTAL_CTRL_XTALLDO_PD_3V_POS    3
#define APB_XTAL_CTRL_XTAL_PD_3V_BIT       ((uint32_t)0x00000004)
#define APB_XTAL_CTRL_XTAL_PD_3V_POS       2
#define APB_XTAL_CTRL_XTAL_PROBE_MASK      ((uint32_t)0x00000003)
#define APB_XTAL_CTRL_XTAL_PROBE_LSB       0
#define APB_XTAL_CTRL_XTAL_PROBE_WIDTH     ((uint32_t)0x00000002)

#define APB_XTAL_CTRL_XTAL_SMIT_DIS_RST    0x0
#define APB_XTAL_CTRL_XTAL_BUF_ISEL_RST    0x2
#define APB_XTAL_CTRL_XTAL_ISEL_RST        0x6
#define APB_XTAL_CTRL_XTALLDO_VSEL_RST     0x0
#define APB_XTAL_CTRL_XTALLDO_RST_N_RST    0x0
#define APB_XTAL_CTRL_XTALLDO_PD_3V_RST    0x0
#define APB_XTAL_CTRL_XTAL_PD_3V_RST       0x0
#define APB_XTAL_CTRL_XTAL_PROBE_RST       0x0

__INLINE void apb_xtal_ctrl_pack(uint8_t xtalsmitdis, uint8_t xtalbufisel, uint8_t xtalisel, uint8_t xtalldovsel, uint8_t xtalldorstn, uint8_t xtalprobe)
{
    ASSERT_ERR((((uint32_t)xtalsmitdis << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)xtalbufisel << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)xtalisel << 12) & ~((uint32_t)0x0000F000)) == 0);
    ASSERT_ERR((((uint32_t)xtalldovsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)xtalldorstn << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)xtalprobe << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR,  ((uint32_t)xtalsmitdis << 18) | ((uint32_t)xtalbufisel << 16) | ((uint32_t)xtalisel << 12) | ((uint32_t)xtalldovsel << 8) | ((uint32_t)xtalldorstn << 4) | ((uint32_t)xtalprobe << 0));
}

__INLINE void apb_xtal_ctrl_unpack(uint8_t* xtalsmitdis, uint8_t* xtalbufisel, uint8_t* xtalisel, uint8_t* xtalldovsel, uint8_t* xtalldorstn, uint8_t* xtalldopd3v, uint8_t* xtalpd3v, uint8_t* xtalprobe)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    *xtalsmitdis = (localVal & ((uint32_t)0x00040000)) >> 18;
    *xtalbufisel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *xtalisel = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *xtalldovsel = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *xtalldorstn = (localVal & ((uint32_t)0x00000010)) >> 4;
    *xtalldopd3v = (localVal & ((uint32_t)0x00000008)) >> 3;
    *xtalpd3v = (localVal & ((uint32_t)0x00000004)) >> 2;
    *xtalprobe = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_xtal_ctrl_xtal_smit_dis_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_xtal_ctrl_xtal_smit_dis_setf(uint8_t xtalsmitdis)
{
    ASSERT_ERR((((uint32_t)xtalsmitdis << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)xtalsmitdis << 18));
}

__INLINE uint8_t apb_xtal_ctrl_xtal_buf_isel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_xtal_ctrl_xtal_buf_isel_setf(uint8_t xtalbufisel)
{
    ASSERT_ERR((((uint32_t)xtalbufisel << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)xtalbufisel << 16));
}

__INLINE uint8_t apb_xtal_ctrl_xtal_isel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}

__INLINE void apb_xtal_ctrl_xtal_isel_setf(uint8_t xtalisel)
{
    ASSERT_ERR((((uint32_t)xtalisel << 12) & ~((uint32_t)0x0000F000)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)xtalisel << 12));
}

__INLINE uint8_t apb_xtal_ctrl_xtalldo_vsel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void apb_xtal_ctrl_xtalldo_vsel_setf(uint8_t xtalldovsel)
{
    ASSERT_ERR((((uint32_t)xtalldovsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)xtalldovsel << 8));
}

__INLINE uint8_t apb_xtal_ctrl_xtalldo_rst_n_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_xtal_ctrl_xtalldo_rst_n_setf(uint8_t xtalldorstn)
{
    ASSERT_ERR((((uint32_t)xtalldorstn << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)xtalldorstn << 4));
}

__INLINE uint8_t apb_xtal_ctrl_xtalldo_pd_3v_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t apb_xtal_ctrl_xtal_pd_3v_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_xtal_ctrl_xtal_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_XTAL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void apb_xtal_ctrl_xtal_probe_setf(uint8_t xtalprobe)
{
    ASSERT_ERR((((uint32_t)xtalprobe << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_XTAL_CTRL_ADDR, (REG_PL_RD(APB_XTAL_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)xtalprobe << 0));
}

/**
 * @brief XTAL_CTRL_RESERVE register definition
 */
#define APB_XTAL_CTRL_RESERVE_ADDR   0xC001205C
#define APB_XTAL_CTRL_RESERVE_OFFSET 0x0000005C
#define APB_XTAL_CTRL_RESERVE_INDEX  0x00000017
#define APB_XTAL_CTRL_RESERVE_RESET  0x00000000

__INLINE uint32_t apb_xtal_ctrl_reserve_get(void)
{
    return REG_PL_RD(APB_XTAL_CTRL_RESERVE_ADDR);
}

__INLINE void apb_xtal_ctrl_reserve_set(uint32_t value)
{
    REG_PL_WR(APB_XTAL_CTRL_RESERVE_ADDR, value);
}

/**
 * @brief PAD_CTRL_RESERVE register definition
 */
#define APB_PAD_CTRL_RESERVE_ADDR   0xC0012060
#define APB_PAD_CTRL_RESERVE_OFFSET 0x00000060
#define APB_PAD_CTRL_RESERVE_INDEX  0x00000018
#define APB_PAD_CTRL_RESERVE_RESET  0x00000000

__INLINE uint32_t apb_pad_ctrl_reserve_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_RESERVE_ADDR);
}

__INLINE void apb_pad_ctrl_reserve_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_RESERVE_ADDR, value);
}

/**
 * @brief PAD_CTRL_RESERVE2 register definition
 */
#define APB_PAD_CTRL_RESERVE2_ADDR   0xC0012064
#define APB_PAD_CTRL_RESERVE2_OFFSET 0x00000064
#define APB_PAD_CTRL_RESERVE2_INDEX  0x00000019
#define APB_PAD_CTRL_RESERVE2_RESET  0x00000000

__INLINE uint32_t apb_pad_ctrl_reserve2_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_RESERVE2_ADDR);
}

__INLINE void apb_pad_ctrl_reserve2_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_RESERVE2_ADDR, value);
}

/**
 * @brief CLK_GEN_XTAL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00              xtal_ok   0
 * </pre>
 */
#define APB_CLK_GEN_XTAL_ADDR   0xC0012068
#define APB_CLK_GEN_XTAL_OFFSET 0x00000068
#define APB_CLK_GEN_XTAL_INDEX  0x0000001A
#define APB_CLK_GEN_XTAL_RESET  0x00000000

__INLINE uint32_t apb_clk_gen_xtal_get(void)
{
    return REG_PL_RD(APB_CLK_GEN_XTAL_ADDR);
}

__INLINE void apb_clk_gen_xtal_set(uint32_t value)
{
    REG_PL_WR(APB_CLK_GEN_XTAL_ADDR, value);
}

// field definitions
#define APB_CLK_GEN_XTAL_XTAL_OK_BIT    ((uint32_t)0x00000001)
#define APB_CLK_GEN_XTAL_XTAL_OK_POS    0

#define APB_CLK_GEN_XTAL_XTAL_OK_RST    0x0

__INLINE uint8_t apb_clk_gen_xtal_xtal_ok_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_XTAL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CLK_GEN_CLKSEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28        tdm_lrclk_sel   0x0
 *  27:26         tdm_mclk_sel   0x0
 *  25:24     i2s_eval_clk_sel   0x1
 *     22        i2sm_sclk_sel   0
 *  21:20        i2sm_mclk_sel   0x0
 *  19:18     clk_mclk_div_sel   0x2
 *  17:16     clk_uart_div_sel   0x2
 *  14:13         cali_clk_sel   0x0
 *  12:10      clk_i2c_div_sel   0x3
 *  09:08     clk_qspi_div_sel   0x0
 *  07:06      clk_ahb_div_sel   0x0
 *  05:04      clk_apb_div_sel   0x0
 *  03:00   clk_osc_high_div_sel   0x6
 * </pre>
 */
#define APB_CLK_GEN_CLKSEL_ADDR   0xC001206C
#define APB_CLK_GEN_CLKSEL_OFFSET 0x0000006C
#define APB_CLK_GEN_CLKSEL_INDEX  0x0000001B
#define APB_CLK_GEN_CLKSEL_RESET  0x010A0C06

__INLINE uint32_t apb_clk_gen_clksel_get(void)
{
    return REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
}

__INLINE void apb_clk_gen_clksel_set(uint32_t value)
{
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, value);
}

// field definitions
#define APB_CLK_GEN_CLKSEL_TDM_LRCLK_SEL_MASK          ((uint32_t)0x30000000)
#define APB_CLK_GEN_CLKSEL_TDM_LRCLK_SEL_LSB           28
#define APB_CLK_GEN_CLKSEL_TDM_LRCLK_SEL_WIDTH         ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_TDM_MCLK_SEL_MASK           ((uint32_t)0x0C000000)
#define APB_CLK_GEN_CLKSEL_TDM_MCLK_SEL_LSB            26
#define APB_CLK_GEN_CLKSEL_TDM_MCLK_SEL_WIDTH          ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_I_2S_EVAL_CLK_SEL_MASK      ((uint32_t)0x03000000)
#define APB_CLK_GEN_CLKSEL_I_2S_EVAL_CLK_SEL_LSB       24
#define APB_CLK_GEN_CLKSEL_I_2S_EVAL_CLK_SEL_WIDTH     ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_I_2SM_SCLK_SEL_BIT          ((uint32_t)0x00400000)
#define APB_CLK_GEN_CLKSEL_I_2SM_SCLK_SEL_POS          22
#define APB_CLK_GEN_CLKSEL_I_2SM_MCLK_SEL_MASK         ((uint32_t)0x00300000)
#define APB_CLK_GEN_CLKSEL_I_2SM_MCLK_SEL_LSB          20
#define APB_CLK_GEN_CLKSEL_I_2SM_MCLK_SEL_WIDTH        ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_MCLK_DIV_SEL_MASK       ((uint32_t)0x000C0000)
#define APB_CLK_GEN_CLKSEL_CLK_MCLK_DIV_SEL_LSB        18
#define APB_CLK_GEN_CLKSEL_CLK_MCLK_DIV_SEL_WIDTH      ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_UART_DIV_SEL_MASK       ((uint32_t)0x00030000)
#define APB_CLK_GEN_CLKSEL_CLK_UART_DIV_SEL_LSB        16
#define APB_CLK_GEN_CLKSEL_CLK_UART_DIV_SEL_WIDTH      ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CALI_CLK_SEL_MASK           ((uint32_t)0x00006000)
#define APB_CLK_GEN_CLKSEL_CALI_CLK_SEL_LSB            13
#define APB_CLK_GEN_CLKSEL_CALI_CLK_SEL_WIDTH          ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_I_2C_DIV_SEL_MASK       ((uint32_t)0x00001C00)
#define APB_CLK_GEN_CLKSEL_CLK_I_2C_DIV_SEL_LSB        10
#define APB_CLK_GEN_CLKSEL_CLK_I_2C_DIV_SEL_WIDTH      ((uint32_t)0x00000003)
#define APB_CLK_GEN_CLKSEL_CLK_QSPI_DIV_SEL_MASK       ((uint32_t)0x00000300)
#define APB_CLK_GEN_CLKSEL_CLK_QSPI_DIV_SEL_LSB        8
#define APB_CLK_GEN_CLKSEL_CLK_QSPI_DIV_SEL_WIDTH      ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_AHB_DIV_SEL_MASK        ((uint32_t)0x000000C0)
#define APB_CLK_GEN_CLKSEL_CLK_AHB_DIV_SEL_LSB         6
#define APB_CLK_GEN_CLKSEL_CLK_AHB_DIV_SEL_WIDTH       ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_APB_DIV_SEL_MASK        ((uint32_t)0x00000030)
#define APB_CLK_GEN_CLKSEL_CLK_APB_DIV_SEL_LSB         4
#define APB_CLK_GEN_CLKSEL_CLK_APB_DIV_SEL_WIDTH       ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKSEL_CLK_OSC_HIGH_DIV_SEL_MASK   ((uint32_t)0x0000000F)
#define APB_CLK_GEN_CLKSEL_CLK_OSC_HIGH_DIV_SEL_LSB    0
#define APB_CLK_GEN_CLKSEL_CLK_OSC_HIGH_DIV_SEL_WIDTH  ((uint32_t)0x00000004)

#define APB_CLK_GEN_CLKSEL_TDM_LRCLK_SEL_RST           0x0
#define APB_CLK_GEN_CLKSEL_TDM_MCLK_SEL_RST            0x0
#define APB_CLK_GEN_CLKSEL_I_2S_EVAL_CLK_SEL_RST       0x1
#define APB_CLK_GEN_CLKSEL_I_2SM_SCLK_SEL_RST          0x0
#define APB_CLK_GEN_CLKSEL_I_2SM_MCLK_SEL_RST          0x0
#define APB_CLK_GEN_CLKSEL_CLK_MCLK_DIV_SEL_RST        0x2
#define APB_CLK_GEN_CLKSEL_CLK_UART_DIV_SEL_RST        0x2
#define APB_CLK_GEN_CLKSEL_CALI_CLK_SEL_RST            0x0
#define APB_CLK_GEN_CLKSEL_CLK_I_2C_DIV_SEL_RST        0x3
#define APB_CLK_GEN_CLKSEL_CLK_QSPI_DIV_SEL_RST        0x0
#define APB_CLK_GEN_CLKSEL_CLK_AHB_DIV_SEL_RST         0x0
#define APB_CLK_GEN_CLKSEL_CLK_APB_DIV_SEL_RST         0x0
#define APB_CLK_GEN_CLKSEL_CLK_OSC_HIGH_DIV_SEL_RST    0x6

__INLINE void apb_clk_gen_clksel_pack(uint8_t tdmlrclksel, uint8_t tdmmclksel, uint8_t i2sevalclksel, uint8_t i2smsclksel, uint8_t i2smmclksel, uint8_t clkmclkdivsel, uint8_t clkuartdivsel, uint8_t caliclksel, uint8_t clki2cdivsel, uint8_t clkqspidivsel, uint8_t clkahbdivsel, uint8_t clkapbdivsel, uint8_t clkoschighdivsel)
{
    ASSERT_ERR((((uint32_t)tdmlrclksel << 28) & ~((uint32_t)0x30000000)) == 0);
    ASSERT_ERR((((uint32_t)tdmmclksel << 26) & ~((uint32_t)0x0C000000)) == 0);
    ASSERT_ERR((((uint32_t)i2sevalclksel << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)i2smsclksel << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)i2smmclksel << 20) & ~((uint32_t)0x00300000)) == 0);
    ASSERT_ERR((((uint32_t)clkmclkdivsel << 18) & ~((uint32_t)0x000C0000)) == 0);
    ASSERT_ERR((((uint32_t)clkuartdivsel << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)caliclksel << 13) & ~((uint32_t)0x00006000)) == 0);
    ASSERT_ERR((((uint32_t)clki2cdivsel << 10) & ~((uint32_t)0x00001C00)) == 0);
    ASSERT_ERR((((uint32_t)clkqspidivsel << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)clkahbdivsel << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)clkapbdivsel << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)clkoschighdivsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR,  ((uint32_t)tdmlrclksel << 28) | ((uint32_t)tdmmclksel << 26) | ((uint32_t)i2sevalclksel << 24) | ((uint32_t)i2smsclksel << 22) | ((uint32_t)i2smmclksel << 20) | ((uint32_t)clkmclkdivsel << 18) | ((uint32_t)clkuartdivsel << 16) | ((uint32_t)caliclksel << 13) | ((uint32_t)clki2cdivsel << 10) | ((uint32_t)clkqspidivsel << 8) | ((uint32_t)clkahbdivsel << 6) | ((uint32_t)clkapbdivsel << 4) | ((uint32_t)clkoschighdivsel << 0));
}

__INLINE void apb_clk_gen_clksel_unpack(uint8_t* tdmlrclksel, uint8_t* tdmmclksel, uint8_t* i2sevalclksel, uint8_t* i2smsclksel, uint8_t* i2smmclksel, uint8_t* clkmclkdivsel, uint8_t* clkuartdivsel, uint8_t* caliclksel, uint8_t* clki2cdivsel, uint8_t* clkqspidivsel, uint8_t* clkahbdivsel, uint8_t* clkapbdivsel, uint8_t* clkoschighdivsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    *tdmlrclksel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *tdmmclksel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *i2sevalclksel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *i2smsclksel = (localVal & ((uint32_t)0x00400000)) >> 22;
    *i2smmclksel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *clkmclkdivsel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *clkuartdivsel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *caliclksel = (localVal & ((uint32_t)0x00006000)) >> 13;
    *clki2cdivsel = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *clkqspidivsel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *clkahbdivsel = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *clkapbdivsel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *clkoschighdivsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_clk_gen_clksel_tdm_lrclk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void apb_clk_gen_clksel_tdm_lrclk_sel_setf(uint8_t tdmlrclksel)
{
    ASSERT_ERR((((uint32_t)tdmlrclksel << 28) & ~((uint32_t)0x30000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)tdmlrclksel << 28));
}

__INLINE uint8_t apb_clk_gen_clksel_tdm_mclk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void apb_clk_gen_clksel_tdm_mclk_sel_setf(uint8_t tdmmclksel)
{
    ASSERT_ERR((((uint32_t)tdmmclksel << 26) & ~((uint32_t)0x0C000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)tdmmclksel << 26));
}

__INLINE uint8_t apb_clk_gen_clksel_i_2s_eval_clk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void apb_clk_gen_clksel_i_2s_eval_clk_sel_setf(uint8_t i2sevalclksel)
{
    ASSERT_ERR((((uint32_t)i2sevalclksel << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)i2sevalclksel << 24));
}

__INLINE uint8_t apb_clk_gen_clksel_i_2sm_sclk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_clk_gen_clksel_i_2sm_sclk_sel_setf(uint8_t i2smsclksel)
{
    ASSERT_ERR((((uint32_t)i2smsclksel << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)i2smsclksel << 22));
}

__INLINE uint8_t apb_clk_gen_clksel_i_2sm_mclk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void apb_clk_gen_clksel_i_2sm_mclk_sel_setf(uint8_t i2smmclksel)
{
    ASSERT_ERR((((uint32_t)i2smmclksel << 20) & ~((uint32_t)0x00300000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)i2smmclksel << 20));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_mclk_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void apb_clk_gen_clksel_clk_mclk_div_sel_setf(uint8_t clkmclkdivsel)
{
    ASSERT_ERR((((uint32_t)clkmclkdivsel << 18) & ~((uint32_t)0x000C0000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)clkmclkdivsel << 18));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_uart_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_clk_gen_clksel_clk_uart_div_sel_setf(uint8_t clkuartdivsel)
{
    ASSERT_ERR((((uint32_t)clkuartdivsel << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)clkuartdivsel << 16));
}

__INLINE uint8_t apb_clk_gen_clksel_cali_clk_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00006000)) >> 13);
}

__INLINE void apb_clk_gen_clksel_cali_clk_sel_setf(uint8_t caliclksel)
{
    ASSERT_ERR((((uint32_t)caliclksel << 13) & ~((uint32_t)0x00006000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00006000)) | ((uint32_t)caliclksel << 13));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_i_2c_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

__INLINE void apb_clk_gen_clksel_clk_i_2c_div_sel_setf(uint8_t clki2cdivsel)
{
    ASSERT_ERR((((uint32_t)clki2cdivsel << 10) & ~((uint32_t)0x00001C00)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)clki2cdivsel << 10));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_qspi_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void apb_clk_gen_clksel_clk_qspi_div_sel_setf(uint8_t clkqspidivsel)
{
    ASSERT_ERR((((uint32_t)clkqspidivsel << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)clkqspidivsel << 8));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_ahb_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_clk_gen_clksel_clk_ahb_div_sel_setf(uint8_t clkahbdivsel)
{
    ASSERT_ERR((((uint32_t)clkahbdivsel << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)clkahbdivsel << 6));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_apb_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_clk_gen_clksel_clk_apb_div_sel_setf(uint8_t clkapbdivsel)
{
    ASSERT_ERR((((uint32_t)clkapbdivsel << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)clkapbdivsel << 4));
}

__INLINE uint8_t apb_clk_gen_clksel_clk_osc_high_div_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_clk_gen_clksel_clk_osc_high_div_sel_setf(uint8_t clkoschighdivsel)
{
    ASSERT_ERR((((uint32_t)clkoschighdivsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKSEL_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKSEL_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)clkoschighdivsel << 0));
}

/**
 * @brief CLK_GEN_CLKEN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     26         i2ss1_tdm_en   0
 *     25         i2ss0_tdm_en   0
 *     24         i2sm1_tdm_en   0
 *     23         i2sm0_tdm_en   0
 *     22      i2s_eval_clk_en   0
 *     21     clk_dac_right_en   0
 *     20      clk_dac_left_en   0
 *     18           clk_dac_en   0
 *     17     clk_adc_dnsp1_en   0
 *     16        clk_auxadc_en   0
 *     15           clk_adc_en   0
 *     14       clk_dlm_arb_en   1
 *     13          clk_qspi_en   0
 *     12           clk_otp_en   1
 *     11             i2ss1_en   0
 *     10             i2ss0_en   0
 *     09             i2sm1_en   0
 *     08             i2sm0_en   0
 *     07      clk_core_dis_en   0
 *     06           clk_usb_en   1
 *     05          clk_uart_en   0
 *     04           clk_i2c_en   0
 *     03           clk_wdt_en   0
 *     02       clk_cpu_dis_en   0
 *     01      clk_hss_ctrl_en   0
 *     00         clk_timer_en   0
 * </pre>
 */
#define APB_CLK_GEN_CLKEN_ADDR   0xC0012070
#define APB_CLK_GEN_CLKEN_OFFSET 0x00000070
#define APB_CLK_GEN_CLKEN_INDEX  0x0000001C
#define APB_CLK_GEN_CLKEN_RESET  0x00005040

__INLINE uint32_t apb_clk_gen_clken_get(void)
{
    return REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
}

__INLINE void apb_clk_gen_clken_set(uint32_t value)
{
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, value);
}

// field definitions
#define APB_CLK_GEN_CLKEN_I_2SS_1_TDM_EN_BIT       ((uint32_t)0x04000000)
#define APB_CLK_GEN_CLKEN_I_2SS_1_TDM_EN_POS       26
#define APB_CLK_GEN_CLKEN_I_2SS_0_TDM_EN_BIT       ((uint32_t)0x02000000)
#define APB_CLK_GEN_CLKEN_I_2SS_0_TDM_EN_POS       25
#define APB_CLK_GEN_CLKEN_I_2SM_1_TDM_EN_BIT       ((uint32_t)0x01000000)
#define APB_CLK_GEN_CLKEN_I_2SM_1_TDM_EN_POS       24
#define APB_CLK_GEN_CLKEN_I_2SM_0_TDM_EN_BIT       ((uint32_t)0x00800000)
#define APB_CLK_GEN_CLKEN_I_2SM_0_TDM_EN_POS       23
#define APB_CLK_GEN_CLKEN_I_2S_EVAL_CLK_EN_BIT     ((uint32_t)0x00400000)
#define APB_CLK_GEN_CLKEN_I_2S_EVAL_CLK_EN_POS     22
#define APB_CLK_GEN_CLKEN_CLK_DAC_RIGHT_EN_BIT     ((uint32_t)0x00200000)
#define APB_CLK_GEN_CLKEN_CLK_DAC_RIGHT_EN_POS     21
#define APB_CLK_GEN_CLKEN_CLK_DAC_LEFT_EN_BIT      ((uint32_t)0x00100000)
#define APB_CLK_GEN_CLKEN_CLK_DAC_LEFT_EN_POS      20
#define APB_CLK_GEN_CLKEN_CLK_DAC_EN_BIT           ((uint32_t)0x00040000)
#define APB_CLK_GEN_CLKEN_CLK_DAC_EN_POS           18
#define APB_CLK_GEN_CLKEN_CLK_ADC_DNSP_1_EN_BIT    ((uint32_t)0x00020000)
#define APB_CLK_GEN_CLKEN_CLK_ADC_DNSP_1_EN_POS    17
#define APB_CLK_GEN_CLKEN_CLK_AUXADC_EN_BIT        ((uint32_t)0x00010000)
#define APB_CLK_GEN_CLKEN_CLK_AUXADC_EN_POS        16
#define APB_CLK_GEN_CLKEN_CLK_ADC_EN_BIT           ((uint32_t)0x00008000)
#define APB_CLK_GEN_CLKEN_CLK_ADC_EN_POS           15
#define APB_CLK_GEN_CLKEN_CLK_DLM_ARB_EN_BIT       ((uint32_t)0x00004000)
#define APB_CLK_GEN_CLKEN_CLK_DLM_ARB_EN_POS       14
#define APB_CLK_GEN_CLKEN_CLK_QSPI_EN_BIT          ((uint32_t)0x00002000)
#define APB_CLK_GEN_CLKEN_CLK_QSPI_EN_POS          13
#define APB_CLK_GEN_CLKEN_CLK_OTP_EN_BIT           ((uint32_t)0x00001000)
#define APB_CLK_GEN_CLKEN_CLK_OTP_EN_POS           12
#define APB_CLK_GEN_CLKEN_I_2SS_1_EN_BIT           ((uint32_t)0x00000800)
#define APB_CLK_GEN_CLKEN_I_2SS_1_EN_POS           11
#define APB_CLK_GEN_CLKEN_I_2SS_0_EN_BIT           ((uint32_t)0x00000400)
#define APB_CLK_GEN_CLKEN_I_2SS_0_EN_POS           10
#define APB_CLK_GEN_CLKEN_I_2SM_1_EN_BIT           ((uint32_t)0x00000200)
#define APB_CLK_GEN_CLKEN_I_2SM_1_EN_POS           9
#define APB_CLK_GEN_CLKEN_I_2SM_0_EN_BIT           ((uint32_t)0x00000100)
#define APB_CLK_GEN_CLKEN_I_2SM_0_EN_POS           8
#define APB_CLK_GEN_CLKEN_CLK_CORE_DIS_EN_BIT      ((uint32_t)0x00000080)
#define APB_CLK_GEN_CLKEN_CLK_CORE_DIS_EN_POS      7
#define APB_CLK_GEN_CLKEN_CLK_USB_EN_BIT           ((uint32_t)0x00000040)
#define APB_CLK_GEN_CLKEN_CLK_USB_EN_POS           6
#define APB_CLK_GEN_CLKEN_CLK_UART_EN_BIT          ((uint32_t)0x00000020)
#define APB_CLK_GEN_CLKEN_CLK_UART_EN_POS          5
#define APB_CLK_GEN_CLKEN_CLK_I_2C_EN_BIT          ((uint32_t)0x00000010)
#define APB_CLK_GEN_CLKEN_CLK_I_2C_EN_POS          4
#define APB_CLK_GEN_CLKEN_CLK_WDT_EN_BIT           ((uint32_t)0x00000008)
#define APB_CLK_GEN_CLKEN_CLK_WDT_EN_POS           3
#define APB_CLK_GEN_CLKEN_CLK_CPU_DIS_EN_BIT       ((uint32_t)0x00000004)
#define APB_CLK_GEN_CLKEN_CLK_CPU_DIS_EN_POS       2
#define APB_CLK_GEN_CLKEN_CLK_HSS_CTRL_EN_BIT      ((uint32_t)0x00000002)
#define APB_CLK_GEN_CLKEN_CLK_HSS_CTRL_EN_POS      1
#define APB_CLK_GEN_CLKEN_CLK_TIMER_EN_BIT         ((uint32_t)0x00000001)
#define APB_CLK_GEN_CLKEN_CLK_TIMER_EN_POS         0

#define APB_CLK_GEN_CLKEN_I_2SS_1_TDM_EN_RST       0x0
#define APB_CLK_GEN_CLKEN_I_2SS_0_TDM_EN_RST       0x0
#define APB_CLK_GEN_CLKEN_I_2SM_1_TDM_EN_RST       0x0
#define APB_CLK_GEN_CLKEN_I_2SM_0_TDM_EN_RST       0x0
#define APB_CLK_GEN_CLKEN_I_2S_EVAL_CLK_EN_RST     0x0
#define APB_CLK_GEN_CLKEN_CLK_DAC_RIGHT_EN_RST     0x0
#define APB_CLK_GEN_CLKEN_CLK_DAC_LEFT_EN_RST      0x0
#define APB_CLK_GEN_CLKEN_CLK_DAC_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_CLK_ADC_DNSP_1_EN_RST    0x0
#define APB_CLK_GEN_CLKEN_CLK_AUXADC_EN_RST        0x0
#define APB_CLK_GEN_CLKEN_CLK_ADC_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_CLK_DLM_ARB_EN_RST       0x1
#define APB_CLK_GEN_CLKEN_CLK_QSPI_EN_RST          0x0
#define APB_CLK_GEN_CLKEN_CLK_OTP_EN_RST           0x1
#define APB_CLK_GEN_CLKEN_I_2SS_1_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_I_2SS_0_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_I_2SM_1_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_I_2SM_0_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_CLK_CORE_DIS_EN_RST      0x0
#define APB_CLK_GEN_CLKEN_CLK_USB_EN_RST           0x1
#define APB_CLK_GEN_CLKEN_CLK_UART_EN_RST          0x0
#define APB_CLK_GEN_CLKEN_CLK_I_2C_EN_RST          0x0
#define APB_CLK_GEN_CLKEN_CLK_WDT_EN_RST           0x0
#define APB_CLK_GEN_CLKEN_CLK_CPU_DIS_EN_RST       0x0
#define APB_CLK_GEN_CLKEN_CLK_HSS_CTRL_EN_RST      0x0
#define APB_CLK_GEN_CLKEN_CLK_TIMER_EN_RST         0x0

__INLINE void apb_clk_gen_clken_pack(uint8_t i2ss1tdmen, uint8_t i2ss0tdmen, uint8_t i2sm1tdmen, uint8_t i2sm0tdmen, uint8_t i2sevalclken, uint8_t clkdacrighten, uint8_t clkdacleften, uint8_t clkdacen, uint8_t clkadcdnsp1en, uint8_t clkauxadcen, uint8_t clkadcen, uint8_t clkdlmarben, uint8_t clkqspien, uint8_t clkotpen, uint8_t i2ss1en, uint8_t i2ss0en, uint8_t i2sm1en, uint8_t i2sm0en, uint8_t clkcoredisen, uint8_t clkusben, uint8_t clkuarten, uint8_t clki2cen, uint8_t clkwdten, uint8_t clkcpudisen, uint8_t clkhssctrlen, uint8_t clktimeren)
{
    ASSERT_ERR((((uint32_t)i2ss1tdmen << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)i2ss0tdmen << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)i2sm1tdmen << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)i2sm0tdmen << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)i2sevalclken << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)clkdacrighten << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)clkdacleften << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)clkdacen << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)clkadcdnsp1en << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)clkauxadcen << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)clkadcen << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)clkdlmarben << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)clkqspien << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)clkotpen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)i2ss1en << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)i2ss0en << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)i2sm1en << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)i2sm0en << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)clkcoredisen << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)clkusben << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)clkuarten << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)clki2cen << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)clkwdten << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)clkcpudisen << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)clkhssctrlen << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)clktimeren << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR,  ((uint32_t)i2ss1tdmen << 26) | ((uint32_t)i2ss0tdmen << 25) | ((uint32_t)i2sm1tdmen << 24) | ((uint32_t)i2sm0tdmen << 23) | ((uint32_t)i2sevalclken << 22) | ((uint32_t)clkdacrighten << 21) | ((uint32_t)clkdacleften << 20) | ((uint32_t)clkdacen << 18) | ((uint32_t)clkadcdnsp1en << 17) | ((uint32_t)clkauxadcen << 16) | ((uint32_t)clkadcen << 15) | ((uint32_t)clkdlmarben << 14) | ((uint32_t)clkqspien << 13) | ((uint32_t)clkotpen << 12) | ((uint32_t)i2ss1en << 11) | ((uint32_t)i2ss0en << 10) | ((uint32_t)i2sm1en << 9) | ((uint32_t)i2sm0en << 8) | ((uint32_t)clkcoredisen << 7) | ((uint32_t)clkusben << 6) | ((uint32_t)clkuarten << 5) | ((uint32_t)clki2cen << 4) | ((uint32_t)clkwdten << 3) | ((uint32_t)clkcpudisen << 2) | ((uint32_t)clkhssctrlen << 1) | ((uint32_t)clktimeren << 0));
}

__INLINE void apb_clk_gen_clken_unpack(uint8_t* i2ss1tdmen, uint8_t* i2ss0tdmen, uint8_t* i2sm1tdmen, uint8_t* i2sm0tdmen, uint8_t* i2sevalclken, uint8_t* clkdacrighten, uint8_t* clkdacleften, uint8_t* clkdacen, uint8_t* clkadcdnsp1en, uint8_t* clkauxadcen, uint8_t* clkadcen, uint8_t* clkdlmarben, uint8_t* clkqspien, uint8_t* clkotpen, uint8_t* i2ss1en, uint8_t* i2ss0en, uint8_t* i2sm1en, uint8_t* i2sm0en, uint8_t* clkcoredisen, uint8_t* clkusben, uint8_t* clkuarten, uint8_t* clki2cen, uint8_t* clkwdten, uint8_t* clkcpudisen, uint8_t* clkhssctrlen, uint8_t* clktimeren)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    *i2ss1tdmen = (localVal & ((uint32_t)0x04000000)) >> 26;
    *i2ss0tdmen = (localVal & ((uint32_t)0x02000000)) >> 25;
    *i2sm1tdmen = (localVal & ((uint32_t)0x01000000)) >> 24;
    *i2sm0tdmen = (localVal & ((uint32_t)0x00800000)) >> 23;
    *i2sevalclken = (localVal & ((uint32_t)0x00400000)) >> 22;
    *clkdacrighten = (localVal & ((uint32_t)0x00200000)) >> 21;
    *clkdacleften = (localVal & ((uint32_t)0x00100000)) >> 20;
    *clkdacen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *clkadcdnsp1en = (localVal & ((uint32_t)0x00020000)) >> 17;
    *clkauxadcen = (localVal & ((uint32_t)0x00010000)) >> 16;
    *clkadcen = (localVal & ((uint32_t)0x00008000)) >> 15;
    *clkdlmarben = (localVal & ((uint32_t)0x00004000)) >> 14;
    *clkqspien = (localVal & ((uint32_t)0x00002000)) >> 13;
    *clkotpen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *i2ss1en = (localVal & ((uint32_t)0x00000800)) >> 11;
    *i2ss0en = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2sm1en = (localVal & ((uint32_t)0x00000200)) >> 9;
    *i2sm0en = (localVal & ((uint32_t)0x00000100)) >> 8;
    *clkcoredisen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *clkusben = (localVal & ((uint32_t)0x00000040)) >> 6;
    *clkuarten = (localVal & ((uint32_t)0x00000020)) >> 5;
    *clki2cen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *clkwdten = (localVal & ((uint32_t)0x00000008)) >> 3;
    *clkcpudisen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *clkhssctrlen = (localVal & ((uint32_t)0x00000002)) >> 1;
    *clktimeren = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_clk_gen_clken_i_2ss_1_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void apb_clk_gen_clken_i_2ss_1_tdm_en_setf(uint8_t i2ss1tdmen)
{
    ASSERT_ERR((((uint32_t)i2ss1tdmen << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)i2ss1tdmen << 26));
}

__INLINE uint8_t apb_clk_gen_clken_i_2ss_0_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_clk_gen_clken_i_2ss_0_tdm_en_setf(uint8_t i2ss0tdmen)
{
    ASSERT_ERR((((uint32_t)i2ss0tdmen << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)i2ss0tdmen << 25));
}

__INLINE uint8_t apb_clk_gen_clken_i_2sm_1_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_clk_gen_clken_i_2sm_1_tdm_en_setf(uint8_t i2sm1tdmen)
{
    ASSERT_ERR((((uint32_t)i2sm1tdmen << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)i2sm1tdmen << 24));
}

__INLINE uint8_t apb_clk_gen_clken_i_2sm_0_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_clk_gen_clken_i_2sm_0_tdm_en_setf(uint8_t i2sm0tdmen)
{
    ASSERT_ERR((((uint32_t)i2sm0tdmen << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)i2sm0tdmen << 23));
}

__INLINE uint8_t apb_clk_gen_clken_i_2s_eval_clk_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_clk_gen_clken_i_2s_eval_clk_en_setf(uint8_t i2sevalclken)
{
    ASSERT_ERR((((uint32_t)i2sevalclken << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)i2sevalclken << 22));
}

__INLINE uint8_t apb_clk_gen_clken_clk_dac_right_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_clk_gen_clken_clk_dac_right_en_setf(uint8_t clkdacrighten)
{
    ASSERT_ERR((((uint32_t)clkdacrighten << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)clkdacrighten << 21));
}

__INLINE uint8_t apb_clk_gen_clken_clk_dac_left_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_clk_gen_clken_clk_dac_left_en_setf(uint8_t clkdacleften)
{
    ASSERT_ERR((((uint32_t)clkdacleften << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)clkdacleften << 20));
}

__INLINE uint8_t apb_clk_gen_clken_clk_dac_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_clk_gen_clken_clk_dac_en_setf(uint8_t clkdacen)
{
    ASSERT_ERR((((uint32_t)clkdacen << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)clkdacen << 18));
}

__INLINE uint8_t apb_clk_gen_clken_clk_adc_dnsp_1_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_clk_gen_clken_clk_adc_dnsp_1_en_setf(uint8_t clkadcdnsp1en)
{
    ASSERT_ERR((((uint32_t)clkadcdnsp1en << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)clkadcdnsp1en << 17));
}

__INLINE uint8_t apb_clk_gen_clken_clk_auxadc_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_clk_gen_clken_clk_auxadc_en_setf(uint8_t clkauxadcen)
{
    ASSERT_ERR((((uint32_t)clkauxadcen << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)clkauxadcen << 16));
}

__INLINE uint8_t apb_clk_gen_clken_clk_adc_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_clk_gen_clken_clk_adc_en_setf(uint8_t clkadcen)
{
    ASSERT_ERR((((uint32_t)clkadcen << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)clkadcen << 15));
}

__INLINE uint8_t apb_clk_gen_clken_clk_dlm_arb_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_clk_gen_clken_clk_dlm_arb_en_setf(uint8_t clkdlmarben)
{
    ASSERT_ERR((((uint32_t)clkdlmarben << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)clkdlmarben << 14));
}

__INLINE uint8_t apb_clk_gen_clken_clk_qspi_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_clk_gen_clken_clk_qspi_en_setf(uint8_t clkqspien)
{
    ASSERT_ERR((((uint32_t)clkqspien << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)clkqspien << 13));
}

__INLINE uint8_t apb_clk_gen_clken_clk_otp_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_clk_gen_clken_clk_otp_en_setf(uint8_t clkotpen)
{
    ASSERT_ERR((((uint32_t)clkotpen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)clkotpen << 12));
}

__INLINE uint8_t apb_clk_gen_clken_i_2ss_1_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_clk_gen_clken_i_2ss_1_en_setf(uint8_t i2ss1en)
{
    ASSERT_ERR((((uint32_t)i2ss1en << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)i2ss1en << 11));
}

__INLINE uint8_t apb_clk_gen_clken_i_2ss_0_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_clk_gen_clken_i_2ss_0_en_setf(uint8_t i2ss0en)
{
    ASSERT_ERR((((uint32_t)i2ss0en << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)i2ss0en << 10));
}

__INLINE uint8_t apb_clk_gen_clken_i_2sm_1_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_clk_gen_clken_i_2sm_1_en_setf(uint8_t i2sm1en)
{
    ASSERT_ERR((((uint32_t)i2sm1en << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)i2sm1en << 9));
}

__INLINE uint8_t apb_clk_gen_clken_i_2sm_0_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_clk_gen_clken_i_2sm_0_en_setf(uint8_t i2sm0en)
{
    ASSERT_ERR((((uint32_t)i2sm0en << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)i2sm0en << 8));
}

__INLINE uint8_t apb_clk_gen_clken_clk_core_dis_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void apb_clk_gen_clken_clk_core_dis_en_setf(uint8_t clkcoredisen)
{
    ASSERT_ERR((((uint32_t)clkcoredisen << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)clkcoredisen << 7));
}

__INLINE uint8_t apb_clk_gen_clken_clk_usb_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void apb_clk_gen_clken_clk_usb_en_setf(uint8_t clkusben)
{
    ASSERT_ERR((((uint32_t)clkusben << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)clkusben << 6));
}

__INLINE uint8_t apb_clk_gen_clken_clk_uart_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void apb_clk_gen_clken_clk_uart_en_setf(uint8_t clkuarten)
{
    ASSERT_ERR((((uint32_t)clkuarten << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)clkuarten << 5));
}

__INLINE uint8_t apb_clk_gen_clken_clk_i_2c_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_clk_gen_clken_clk_i_2c_en_setf(uint8_t clki2cen)
{
    ASSERT_ERR((((uint32_t)clki2cen << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)clki2cen << 4));
}

__INLINE uint8_t apb_clk_gen_clken_clk_wdt_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_clk_gen_clken_clk_wdt_en_setf(uint8_t clkwdten)
{
    ASSERT_ERR((((uint32_t)clkwdten << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)clkwdten << 3));
}

__INLINE uint8_t apb_clk_gen_clken_clk_cpu_dis_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_clk_gen_clken_clk_cpu_dis_en_setf(uint8_t clkcpudisen)
{
    ASSERT_ERR((((uint32_t)clkcpudisen << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)clkcpudisen << 2));
}

__INLINE uint8_t apb_clk_gen_clken_clk_hss_ctrl_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_clk_gen_clken_clk_hss_ctrl_en_setf(uint8_t clkhssctrlen)
{
    ASSERT_ERR((((uint32_t)clkhssctrlen << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)clkhssctrlen << 1));
}

__INLINE uint8_t apb_clk_gen_clken_clk_timer_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_clk_gen_clken_clk_timer_en_setf(uint8_t clktimeren)
{
    ASSERT_ERR((((uint32_t)clktimeren << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_CLK_GEN_CLKEN_ADDR, (REG_PL_RD(APB_CLK_GEN_CLKEN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)clktimeren << 0));
}

/**
 * @brief RST_GEN_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31         soft_wdt_rst   0
 *  30:26       soft_timer_rst   0x0
 *     25         soft_iic_rst   0
 *     24   soft_uart_sclk_rst   0
 *     23        soft_uart_rst   0
 *     22    Soft_eval_clk_rst   0
 *     21     soft_usb_phy_rst   0
 *     20    soft_usb_xclk_rst   0
 *     19          dlm_arb_rst   0
 *     18   Soft_dig_stdby_ldo_rst   0
 *     17              adc_rst   0
 *     16    soft_osc_cali_rst   0
 *     15           auxadc_rst   0
 *     14         hss_ctrl_rst   0
 *     13          sdm_mix_rst   0
 *     12        sdm_right_rst   0
 *     11         sdm_left_rst   0
 *     10             otpc_rst   0
 *  09:08              i2s_rst   0x0
 *  07:06              tdm_rst   0x0
 *     05             i2cs_rst   0
 *     04         i2sm_clk_rst   0
 *     03         qspi_clk_rst   0
 *     02          apb_clk_rst   0
 *     01           digreg_rst   0
 *     00             soft_rst   0
 * </pre>
 */
#define APB_RST_GEN_CTRL0_ADDR   0xC0012078
#define APB_RST_GEN_CTRL0_OFFSET 0x00000078
#define APB_RST_GEN_CTRL0_INDEX  0x0000001E
#define APB_RST_GEN_CTRL0_RESET  0x00000000

__INLINE uint32_t apb_rst_gen_ctrl0_get(void)
{
    return REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
}

__INLINE void apb_rst_gen_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, value);
}

// field definitions
#define APB_RST_GEN_CTRL0_SOFT_WDT_RST_BIT              ((uint32_t)0x80000000)
#define APB_RST_GEN_CTRL0_SOFT_WDT_RST_POS              31
#define APB_RST_GEN_CTRL0_SOFT_TIMER_RST_MASK           ((uint32_t)0x7C000000)
#define APB_RST_GEN_CTRL0_SOFT_TIMER_RST_LSB            26
#define APB_RST_GEN_CTRL0_SOFT_TIMER_RST_WIDTH          ((uint32_t)0x00000005)
#define APB_RST_GEN_CTRL0_SOFT_IIC_RST_BIT              ((uint32_t)0x02000000)
#define APB_RST_GEN_CTRL0_SOFT_IIC_RST_POS              25
#define APB_RST_GEN_CTRL0_SOFT_UART_SCLK_RST_BIT        ((uint32_t)0x01000000)
#define APB_RST_GEN_CTRL0_SOFT_UART_SCLK_RST_POS        24
#define APB_RST_GEN_CTRL0_SOFT_UART_RST_BIT             ((uint32_t)0x00800000)
#define APB_RST_GEN_CTRL0_SOFT_UART_RST_POS             23
#define APB_RST_GEN_CTRL0_SOFT_EVAL_CLK_RST_BIT         ((uint32_t)0x00400000)
#define APB_RST_GEN_CTRL0_SOFT_EVAL_CLK_RST_POS         22
#define APB_RST_GEN_CTRL0_SOFT_USB_PHY_RST_BIT          ((uint32_t)0x00200000)
#define APB_RST_GEN_CTRL0_SOFT_USB_PHY_RST_POS          21
#define APB_RST_GEN_CTRL0_SOFT_USB_XCLK_RST_BIT         ((uint32_t)0x00100000)
#define APB_RST_GEN_CTRL0_SOFT_USB_XCLK_RST_POS         20
#define APB_RST_GEN_CTRL0_DLM_ARB_RST_BIT               ((uint32_t)0x00080000)
#define APB_RST_GEN_CTRL0_DLM_ARB_RST_POS               19
#define APB_RST_GEN_CTRL0_SOFT_DIG_STDBY_LDO_RST_BIT    ((uint32_t)0x00040000)
#define APB_RST_GEN_CTRL0_SOFT_DIG_STDBY_LDO_RST_POS    18
#define APB_RST_GEN_CTRL0_ADC_RST_BIT                   ((uint32_t)0x00020000)
#define APB_RST_GEN_CTRL0_ADC_RST_POS                   17
#define APB_RST_GEN_CTRL0_SOFT_OSC_CALI_RST_BIT         ((uint32_t)0x00010000)
#define APB_RST_GEN_CTRL0_SOFT_OSC_CALI_RST_POS         16
#define APB_RST_GEN_CTRL0_AUXADC_RST_BIT                ((uint32_t)0x00008000)
#define APB_RST_GEN_CTRL0_AUXADC_RST_POS                15
#define APB_RST_GEN_CTRL0_HSS_CTRL_RST_BIT              ((uint32_t)0x00004000)
#define APB_RST_GEN_CTRL0_HSS_CTRL_RST_POS              14
#define APB_RST_GEN_CTRL0_SDM_MIX_RST_BIT               ((uint32_t)0x00002000)
#define APB_RST_GEN_CTRL0_SDM_MIX_RST_POS               13
#define APB_RST_GEN_CTRL0_SDM_RIGHT_RST_BIT             ((uint32_t)0x00001000)
#define APB_RST_GEN_CTRL0_SDM_RIGHT_RST_POS             12
#define APB_RST_GEN_CTRL0_SDM_LEFT_RST_BIT              ((uint32_t)0x00000800)
#define APB_RST_GEN_CTRL0_SDM_LEFT_RST_POS              11
#define APB_RST_GEN_CTRL0_OTPC_RST_BIT                  ((uint32_t)0x00000400)
#define APB_RST_GEN_CTRL0_OTPC_RST_POS                  10
#define APB_RST_GEN_CTRL0_I_2S_RST_MASK                 ((uint32_t)0x00000300)
#define APB_RST_GEN_CTRL0_I_2S_RST_LSB                  8
#define APB_RST_GEN_CTRL0_I_2S_RST_WIDTH                ((uint32_t)0x00000002)
#define APB_RST_GEN_CTRL0_TDM_RST_MASK                  ((uint32_t)0x000000C0)
#define APB_RST_GEN_CTRL0_TDM_RST_LSB                   6
#define APB_RST_GEN_CTRL0_TDM_RST_WIDTH                 ((uint32_t)0x00000002)
#define APB_RST_GEN_CTRL0_I_2CS_RST_BIT                 ((uint32_t)0x00000020)
#define APB_RST_GEN_CTRL0_I_2CS_RST_POS                 5
#define APB_RST_GEN_CTRL0_I_2SM_CLK_RST_BIT             ((uint32_t)0x00000010)
#define APB_RST_GEN_CTRL0_I_2SM_CLK_RST_POS             4
#define APB_RST_GEN_CTRL0_QSPI_CLK_RST_BIT              ((uint32_t)0x00000008)
#define APB_RST_GEN_CTRL0_QSPI_CLK_RST_POS              3
#define APB_RST_GEN_CTRL0_APB_CLK_RST_BIT               ((uint32_t)0x00000004)
#define APB_RST_GEN_CTRL0_APB_CLK_RST_POS               2
#define APB_RST_GEN_CTRL0_DIGREG_RST_BIT                ((uint32_t)0x00000002)
#define APB_RST_GEN_CTRL0_DIGREG_RST_POS                1
#define APB_RST_GEN_CTRL0_SOFT_RST_BIT                  ((uint32_t)0x00000001)
#define APB_RST_GEN_CTRL0_SOFT_RST_POS                  0

#define APB_RST_GEN_CTRL0_SOFT_WDT_RST_RST              0x0
#define APB_RST_GEN_CTRL0_SOFT_TIMER_RST_RST            0x0
#define APB_RST_GEN_CTRL0_SOFT_IIC_RST_RST              0x0
#define APB_RST_GEN_CTRL0_SOFT_UART_SCLK_RST_RST        0x0
#define APB_RST_GEN_CTRL0_SOFT_UART_RST_RST             0x0
#define APB_RST_GEN_CTRL0_SOFT_EVAL_CLK_RST_RST         0x0
#define APB_RST_GEN_CTRL0_SOFT_USB_PHY_RST_RST          0x0
#define APB_RST_GEN_CTRL0_SOFT_USB_XCLK_RST_RST         0x0
#define APB_RST_GEN_CTRL0_DLM_ARB_RST_RST               0x0
#define APB_RST_GEN_CTRL0_SOFT_DIG_STDBY_LDO_RST_RST    0x0
#define APB_RST_GEN_CTRL0_ADC_RST_RST                   0x0
#define APB_RST_GEN_CTRL0_SOFT_OSC_CALI_RST_RST         0x0
#define APB_RST_GEN_CTRL0_AUXADC_RST_RST                0x0
#define APB_RST_GEN_CTRL0_HSS_CTRL_RST_RST              0x0
#define APB_RST_GEN_CTRL0_SDM_MIX_RST_RST               0x0
#define APB_RST_GEN_CTRL0_SDM_RIGHT_RST_RST             0x0
#define APB_RST_GEN_CTRL0_SDM_LEFT_RST_RST              0x0
#define APB_RST_GEN_CTRL0_OTPC_RST_RST                  0x0
#define APB_RST_GEN_CTRL0_I_2S_RST_RST                  0x0
#define APB_RST_GEN_CTRL0_TDM_RST_RST                   0x0
#define APB_RST_GEN_CTRL0_I_2CS_RST_RST                 0x0
#define APB_RST_GEN_CTRL0_I_2SM_CLK_RST_RST             0x0
#define APB_RST_GEN_CTRL0_QSPI_CLK_RST_RST              0x0
#define APB_RST_GEN_CTRL0_APB_CLK_RST_RST               0x0
#define APB_RST_GEN_CTRL0_DIGREG_RST_RST                0x0
#define APB_RST_GEN_CTRL0_SOFT_RST_RST                  0x0

__INLINE void apb_rst_gen_ctrl0_pack(uint8_t softwdtrst, uint8_t softtimerrst, uint8_t softiicrst, uint8_t softuartsclkrst, uint8_t softuartrst, uint8_t softevalclkrst, uint8_t softusbphyrst, uint8_t softusbxclkrst, uint8_t dlmarbrst, uint8_t softdigstdbyldorst, uint8_t adcrst, uint8_t softosccalirst, uint8_t auxadcrst, uint8_t hssctrlrst, uint8_t sdmmixrst, uint8_t sdmrightrst, uint8_t sdmleftrst, uint8_t otpcrst, uint8_t i2srst, uint8_t tdmrst, uint8_t i2csrst, uint8_t i2smclkrst, uint8_t qspiclkrst, uint8_t apbclkrst, uint8_t digregrst, uint8_t softrst)
{
    ASSERT_ERR((((uint32_t)softwdtrst << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)softtimerrst << 26) & ~((uint32_t)0x7C000000)) == 0);
    ASSERT_ERR((((uint32_t)softiicrst << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)softuartsclkrst << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)softuartrst << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)softevalclkrst << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)softusbphyrst << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)softusbxclkrst << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)dlmarbrst << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)softdigstdbyldorst << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)adcrst << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)softosccalirst << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)auxadcrst << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)hssctrlrst << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)sdmmixrst << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)sdmrightrst << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)sdmleftrst << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)otpcrst << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)i2srst << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)tdmrst << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)i2csrst << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkrst << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)qspiclkrst << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)apbclkrst << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)digregrst << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)softrst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR,  ((uint32_t)softwdtrst << 31) | ((uint32_t)softtimerrst << 26) | ((uint32_t)softiicrst << 25) | ((uint32_t)softuartsclkrst << 24) | ((uint32_t)softuartrst << 23) | ((uint32_t)softevalclkrst << 22) | ((uint32_t)softusbphyrst << 21) | ((uint32_t)softusbxclkrst << 20) | ((uint32_t)dlmarbrst << 19) | ((uint32_t)softdigstdbyldorst << 18) | ((uint32_t)adcrst << 17) | ((uint32_t)softosccalirst << 16) | ((uint32_t)auxadcrst << 15) | ((uint32_t)hssctrlrst << 14) | ((uint32_t)sdmmixrst << 13) | ((uint32_t)sdmrightrst << 12) | ((uint32_t)sdmleftrst << 11) | ((uint32_t)otpcrst << 10) | ((uint32_t)i2srst << 8) | ((uint32_t)tdmrst << 6) | ((uint32_t)i2csrst << 5) | ((uint32_t)i2smclkrst << 4) | ((uint32_t)qspiclkrst << 3) | ((uint32_t)apbclkrst << 2) | ((uint32_t)digregrst << 1) | ((uint32_t)softrst << 0));
}

__INLINE void apb_rst_gen_ctrl0_unpack(uint8_t* softwdtrst, uint8_t* softtimerrst, uint8_t* softiicrst, uint8_t* softuartsclkrst, uint8_t* softuartrst, uint8_t* softevalclkrst, uint8_t* softusbphyrst, uint8_t* softusbxclkrst, uint8_t* dlmarbrst, uint8_t* softdigstdbyldorst, uint8_t* adcrst, uint8_t* softosccalirst, uint8_t* auxadcrst, uint8_t* hssctrlrst, uint8_t* sdmmixrst, uint8_t* sdmrightrst, uint8_t* sdmleftrst, uint8_t* otpcrst, uint8_t* i2srst, uint8_t* tdmrst, uint8_t* i2csrst, uint8_t* i2smclkrst, uint8_t* qspiclkrst, uint8_t* apbclkrst, uint8_t* digregrst, uint8_t* softrst)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    *softwdtrst = (localVal & ((uint32_t)0x80000000)) >> 31;
    *softtimerrst = (localVal & ((uint32_t)0x7C000000)) >> 26;
    *softiicrst = (localVal & ((uint32_t)0x02000000)) >> 25;
    *softuartsclkrst = (localVal & ((uint32_t)0x01000000)) >> 24;
    *softuartrst = (localVal & ((uint32_t)0x00800000)) >> 23;
    *softevalclkrst = (localVal & ((uint32_t)0x00400000)) >> 22;
    *softusbphyrst = (localVal & ((uint32_t)0x00200000)) >> 21;
    *softusbxclkrst = (localVal & ((uint32_t)0x00100000)) >> 20;
    *dlmarbrst = (localVal & ((uint32_t)0x00080000)) >> 19;
    *softdigstdbyldorst = (localVal & ((uint32_t)0x00040000)) >> 18;
    *adcrst = (localVal & ((uint32_t)0x00020000)) >> 17;
    *softosccalirst = (localVal & ((uint32_t)0x00010000)) >> 16;
    *auxadcrst = (localVal & ((uint32_t)0x00008000)) >> 15;
    *hssctrlrst = (localVal & ((uint32_t)0x00004000)) >> 14;
    *sdmmixrst = (localVal & ((uint32_t)0x00002000)) >> 13;
    *sdmrightrst = (localVal & ((uint32_t)0x00001000)) >> 12;
    *sdmleftrst = (localVal & ((uint32_t)0x00000800)) >> 11;
    *otpcrst = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2srst = (localVal & ((uint32_t)0x00000300)) >> 8;
    *tdmrst = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *i2csrst = (localVal & ((uint32_t)0x00000020)) >> 5;
    *i2smclkrst = (localVal & ((uint32_t)0x00000010)) >> 4;
    *qspiclkrst = (localVal & ((uint32_t)0x00000008)) >> 3;
    *apbclkrst = (localVal & ((uint32_t)0x00000004)) >> 2;
    *digregrst = (localVal & ((uint32_t)0x00000002)) >> 1;
    *softrst = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_wdt_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_rst_gen_ctrl0_soft_wdt_rst_setf(uint8_t softwdtrst)
{
    ASSERT_ERR((((uint32_t)softwdtrst << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)softwdtrst << 31));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_timer_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x7C000000)) >> 26);
}

__INLINE void apb_rst_gen_ctrl0_soft_timer_rst_setf(uint8_t softtimerrst)
{
    ASSERT_ERR((((uint32_t)softtimerrst << 26) & ~((uint32_t)0x7C000000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x7C000000)) | ((uint32_t)softtimerrst << 26));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_iic_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_rst_gen_ctrl0_soft_iic_rst_setf(uint8_t softiicrst)
{
    ASSERT_ERR((((uint32_t)softiicrst << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)softiicrst << 25));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_uart_sclk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_rst_gen_ctrl0_soft_uart_sclk_rst_setf(uint8_t softuartsclkrst)
{
    ASSERT_ERR((((uint32_t)softuartsclkrst << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)softuartsclkrst << 24));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_uart_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_rst_gen_ctrl0_soft_uart_rst_setf(uint8_t softuartrst)
{
    ASSERT_ERR((((uint32_t)softuartrst << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)softuartrst << 23));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_eval_clk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_rst_gen_ctrl0_soft_eval_clk_rst_setf(uint8_t softevalclkrst)
{
    ASSERT_ERR((((uint32_t)softevalclkrst << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)softevalclkrst << 22));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_usb_phy_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_rst_gen_ctrl0_soft_usb_phy_rst_setf(uint8_t softusbphyrst)
{
    ASSERT_ERR((((uint32_t)softusbphyrst << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)softusbphyrst << 21));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_usb_xclk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_rst_gen_ctrl0_soft_usb_xclk_rst_setf(uint8_t softusbxclkrst)
{
    ASSERT_ERR((((uint32_t)softusbxclkrst << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)softusbxclkrst << 20));
}

__INLINE uint8_t apb_rst_gen_ctrl0_dlm_arb_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_rst_gen_ctrl0_dlm_arb_rst_setf(uint8_t dlmarbrst)
{
    ASSERT_ERR((((uint32_t)dlmarbrst << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)dlmarbrst << 19));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_rst_gen_ctrl0_soft_dig_stdby_ldo_rst_setf(uint8_t softdigstdbyldorst)
{
    ASSERT_ERR((((uint32_t)softdigstdbyldorst << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)softdigstdbyldorst << 18));
}

__INLINE uint8_t apb_rst_gen_ctrl0_adc_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_rst_gen_ctrl0_adc_rst_setf(uint8_t adcrst)
{
    ASSERT_ERR((((uint32_t)adcrst << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)adcrst << 17));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_osc_cali_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_rst_gen_ctrl0_soft_osc_cali_rst_setf(uint8_t softosccalirst)
{
    ASSERT_ERR((((uint32_t)softosccalirst << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)softosccalirst << 16));
}

__INLINE uint8_t apb_rst_gen_ctrl0_auxadc_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_rst_gen_ctrl0_auxadc_rst_setf(uint8_t auxadcrst)
{
    ASSERT_ERR((((uint32_t)auxadcrst << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)auxadcrst << 15));
}

__INLINE uint8_t apb_rst_gen_ctrl0_hss_ctrl_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_rst_gen_ctrl0_hss_ctrl_rst_setf(uint8_t hssctrlrst)
{
    ASSERT_ERR((((uint32_t)hssctrlrst << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)hssctrlrst << 14));
}

__INLINE uint8_t apb_rst_gen_ctrl0_sdm_mix_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_rst_gen_ctrl0_sdm_mix_rst_setf(uint8_t sdmmixrst)
{
    ASSERT_ERR((((uint32_t)sdmmixrst << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)sdmmixrst << 13));
}

__INLINE uint8_t apb_rst_gen_ctrl0_sdm_right_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_rst_gen_ctrl0_sdm_right_rst_setf(uint8_t sdmrightrst)
{
    ASSERT_ERR((((uint32_t)sdmrightrst << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)sdmrightrst << 12));
}

__INLINE uint8_t apb_rst_gen_ctrl0_sdm_left_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_rst_gen_ctrl0_sdm_left_rst_setf(uint8_t sdmleftrst)
{
    ASSERT_ERR((((uint32_t)sdmleftrst << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)sdmleftrst << 11));
}

__INLINE uint8_t apb_rst_gen_ctrl0_otpc_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_rst_gen_ctrl0_otpc_rst_setf(uint8_t otpcrst)
{
    ASSERT_ERR((((uint32_t)otpcrst << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)otpcrst << 10));
}

__INLINE uint8_t apb_rst_gen_ctrl0_i_2s_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void apb_rst_gen_ctrl0_i_2s_rst_setf(uint8_t i2srst)
{
    ASSERT_ERR((((uint32_t)i2srst << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)i2srst << 8));
}

__INLINE uint8_t apb_rst_gen_ctrl0_tdm_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_rst_gen_ctrl0_tdm_rst_setf(uint8_t tdmrst)
{
    ASSERT_ERR((((uint32_t)tdmrst << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)tdmrst << 6));
}

__INLINE uint8_t apb_rst_gen_ctrl0_i_2cs_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void apb_rst_gen_ctrl0_i_2cs_rst_setf(uint8_t i2csrst)
{
    ASSERT_ERR((((uint32_t)i2csrst << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)i2csrst << 5));
}

__INLINE uint8_t apb_rst_gen_ctrl0_i_2sm_clk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_rst_gen_ctrl0_i_2sm_clk_rst_setf(uint8_t i2smclkrst)
{
    ASSERT_ERR((((uint32_t)i2smclkrst << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)i2smclkrst << 4));
}

__INLINE uint8_t apb_rst_gen_ctrl0_qspi_clk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_rst_gen_ctrl0_qspi_clk_rst_setf(uint8_t qspiclkrst)
{
    ASSERT_ERR((((uint32_t)qspiclkrst << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)qspiclkrst << 3));
}

__INLINE uint8_t apb_rst_gen_ctrl0_apb_clk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_rst_gen_ctrl0_apb_clk_rst_setf(uint8_t apbclkrst)
{
    ASSERT_ERR((((uint32_t)apbclkrst << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)apbclkrst << 2));
}

__INLINE uint8_t apb_rst_gen_ctrl0_digreg_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_rst_gen_ctrl0_digreg_rst_setf(uint8_t digregrst)
{
    ASSERT_ERR((((uint32_t)digregrst << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)digregrst << 1));
}

__INLINE uint8_t apb_rst_gen_ctrl0_soft_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_rst_gen_ctrl0_soft_rst_setf(uint8_t softrst)
{
    ASSERT_ERR((((uint32_t)softrst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL0_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)softrst << 0));
}

/**
 * @brief RST_GEN_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03          tdm_clk_rst   0
 *     02   Soft_audac_itrim_rst   0
 *     01   Soft_auadc_rccali_rst   0
 *     00         soft_usb_rst   0
 * </pre>
 */
#define APB_RST_GEN_CTRL1_ADDR   0xC001207C
#define APB_RST_GEN_CTRL1_OFFSET 0x0000007C
#define APB_RST_GEN_CTRL1_INDEX  0x0000001F
#define APB_RST_GEN_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_rst_gen_ctrl1_get(void)
{
    return REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
}

__INLINE void apb_rst_gen_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR, value);
}

// field definitions
#define APB_RST_GEN_CTRL1_TDM_CLK_RST_BIT              ((uint32_t)0x00000008)
#define APB_RST_GEN_CTRL1_TDM_CLK_RST_POS              3
#define APB_RST_GEN_CTRL1_SOFT_AUDAC_ITRIM_RST_BIT     ((uint32_t)0x00000004)
#define APB_RST_GEN_CTRL1_SOFT_AUDAC_ITRIM_RST_POS     2
#define APB_RST_GEN_CTRL1_SOFT_AUADC_RCCALI_RST_BIT    ((uint32_t)0x00000002)
#define APB_RST_GEN_CTRL1_SOFT_AUADC_RCCALI_RST_POS    1
#define APB_RST_GEN_CTRL1_SOFT_USB_RST_BIT             ((uint32_t)0x00000001)
#define APB_RST_GEN_CTRL1_SOFT_USB_RST_POS             0

#define APB_RST_GEN_CTRL1_TDM_CLK_RST_RST              0x0
#define APB_RST_GEN_CTRL1_SOFT_AUDAC_ITRIM_RST_RST     0x0
#define APB_RST_GEN_CTRL1_SOFT_AUADC_RCCALI_RST_RST    0x0
#define APB_RST_GEN_CTRL1_SOFT_USB_RST_RST             0x0

__INLINE void apb_rst_gen_ctrl1_pack(uint8_t tdmclkrst, uint8_t softaudacitrimrst, uint8_t softauadcrccalirst, uint8_t softusbrst)
{
    ASSERT_ERR((((uint32_t)tdmclkrst << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)softaudacitrimrst << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)softauadcrccalirst << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)softusbrst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR,  ((uint32_t)tdmclkrst << 3) | ((uint32_t)softaudacitrimrst << 2) | ((uint32_t)softauadcrccalirst << 1) | ((uint32_t)softusbrst << 0));
}

__INLINE void apb_rst_gen_ctrl1_unpack(uint8_t* tdmclkrst, uint8_t* softaudacitrimrst, uint8_t* softauadcrccalirst, uint8_t* softusbrst)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
    *tdmclkrst = (localVal & ((uint32_t)0x00000008)) >> 3;
    *softaudacitrimrst = (localVal & ((uint32_t)0x00000004)) >> 2;
    *softauadcrccalirst = (localVal & ((uint32_t)0x00000002)) >> 1;
    *softusbrst = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_rst_gen_ctrl1_tdm_clk_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_rst_gen_ctrl1_tdm_clk_rst_setf(uint8_t tdmclkrst)
{
    ASSERT_ERR((((uint32_t)tdmclkrst << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)tdmclkrst << 3));
}

__INLINE uint8_t apb_rst_gen_ctrl1_soft_audac_itrim_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_rst_gen_ctrl1_soft_audac_itrim_rst_setf(uint8_t softaudacitrimrst)
{
    ASSERT_ERR((((uint32_t)softaudacitrimrst << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)softaudacitrimrst << 2));
}

__INLINE uint8_t apb_rst_gen_ctrl1_soft_auadc_rccali_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_rst_gen_ctrl1_soft_auadc_rccali_rst_setf(uint8_t softauadcrccalirst)
{
    ASSERT_ERR((((uint32_t)softauadcrccalirst << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)softauadcrccalirst << 1));
}

__INLINE uint8_t apb_rst_gen_ctrl1_soft_usb_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_RST_GEN_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_rst_gen_ctrl1_soft_usb_rst_setf(uint8_t softusbrst)
{
    ASSERT_ERR((((uint32_t)softusbrst << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_RST_GEN_CTRL1_ADDR, (REG_PL_RD(APB_RST_GEN_CTRL1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)softusbrst << 0));
}

/**
 * @brief I2S_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  17:00   I2s0_tim_win_num_lrclk   0x0
 * </pre>
 */
#define APB_I2S_STATUS0_ADDR   0xC0012084
#define APB_I2S_STATUS0_OFFSET 0x00000084
#define APB_I2S_STATUS0_INDEX  0x00000021
#define APB_I2S_STATUS0_RESET  0x00000000

__INLINE uint32_t apb_i2s_status0_get(void)
{
    return REG_PL_RD(APB_I2S_STATUS0_ADDR);
}

__INLINE void apb_i2s_status0_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_STATUS0_ADDR, value);
}

// field definitions
#define APB_I2S_STATUS0_I_2S_0_TIM_WIN_NUM_LRCLK_MASK   ((uint32_t)0x0003FFFF)
#define APB_I2S_STATUS0_I_2S_0_TIM_WIN_NUM_LRCLK_LSB    0
#define APB_I2S_STATUS0_I_2S_0_TIM_WIN_NUM_LRCLK_WIDTH  ((uint32_t)0x00000012)

#define APB_I2S_STATUS0_I_2S_0_TIM_WIN_NUM_LRCLK_RST    0x0

__INLINE uint32_t apb_i2s_status0_i_2s_0_tim_win_num_lrclk_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_STATUS0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0003FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief I2S_STATUS1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  17:00   I2s1_tim_win_num_lrclk   0x0
 * </pre>
 */
#define APB_I2S_STATUS1_ADDR   0xC0012088
#define APB_I2S_STATUS1_OFFSET 0x00000088
#define APB_I2S_STATUS1_INDEX  0x00000022
#define APB_I2S_STATUS1_RESET  0x00000000

__INLINE uint32_t apb_i2s_status1_get(void)
{
    return REG_PL_RD(APB_I2S_STATUS1_ADDR);
}

__INLINE void apb_i2s_status1_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_STATUS1_ADDR, value);
}

// field definitions
#define APB_I2S_STATUS1_I_2S_1_TIM_WIN_NUM_LRCLK_MASK   ((uint32_t)0x0003FFFF)
#define APB_I2S_STATUS1_I_2S_1_TIM_WIN_NUM_LRCLK_LSB    0
#define APB_I2S_STATUS1_I_2S_1_TIM_WIN_NUM_LRCLK_WIDTH  ((uint32_t)0x00000012)

#define APB_I2S_STATUS1_I_2S_1_TIM_WIN_NUM_LRCLK_RST    0x0

__INLINE uint32_t apb_i2s_status1_i_2s_1_tim_win_num_lrclk_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_STATUS1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0003FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief I2S_STATUS2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  27:00     I2s0_tim_win_num   0x0
 * </pre>
 */
#define APB_I2S_STATUS2_ADDR   0xC001208C
#define APB_I2S_STATUS2_OFFSET 0x0000008C
#define APB_I2S_STATUS2_INDEX  0x00000023
#define APB_I2S_STATUS2_RESET  0x00000000

__INLINE uint32_t apb_i2s_status2_get(void)
{
    return REG_PL_RD(APB_I2S_STATUS2_ADDR);
}

__INLINE void apb_i2s_status2_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_STATUS2_ADDR, value);
}

// field definitions
#define APB_I2S_STATUS2_I_2S_0_TIM_WIN_NUM_MASK   ((uint32_t)0x0FFFFFFF)
#define APB_I2S_STATUS2_I_2S_0_TIM_WIN_NUM_LSB    0
#define APB_I2S_STATUS2_I_2S_0_TIM_WIN_NUM_WIDTH  ((uint32_t)0x0000001C)

#define APB_I2S_STATUS2_I_2S_0_TIM_WIN_NUM_RST    0x0

__INLINE uint32_t apb_i2s_status2_i_2s_0_tim_win_num_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_STATUS2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0FFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief I2S_STATUS3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  27:00     I2s1_tim_win_num   0x0
 * </pre>
 */
#define APB_I2S_STATUS3_ADDR   0xC0012090
#define APB_I2S_STATUS3_OFFSET 0x00000090
#define APB_I2S_STATUS3_INDEX  0x00000024
#define APB_I2S_STATUS3_RESET  0x00000000

__INLINE uint32_t apb_i2s_status3_get(void)
{
    return REG_PL_RD(APB_I2S_STATUS3_ADDR);
}

__INLINE void apb_i2s_status3_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_STATUS3_ADDR, value);
}

// field definitions
#define APB_I2S_STATUS3_I_2S_1_TIM_WIN_NUM_MASK   ((uint32_t)0x0FFFFFFF)
#define APB_I2S_STATUS3_I_2S_1_TIM_WIN_NUM_LSB    0
#define APB_I2S_STATUS3_I_2S_1_TIM_WIN_NUM_WIDTH  ((uint32_t)0x0000001C)

#define APB_I2S_STATUS3_I_2S_1_TIM_WIN_NUM_RST    0x0

__INLINE uint32_t apb_i2s_status3_i_2s_1_tim_win_num_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_STATUS3_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0FFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief I2S_CTTRL0 register definition
 */
#define APB_I2S_CTTRL0_ADDR   0xC0012094
#define APB_I2S_CTTRL0_OFFSET 0x00000094
#define APB_I2S_CTTRL0_INDEX  0x00000025
#define APB_I2S_CTTRL0_RESET  0x00000000

__INLINE uint32_t apb_i2s_cttrl0_get(void)
{
    return REG_PL_RD(APB_I2S_CTTRL0_ADDR);
}

__INLINE void apb_i2s_cttrl0_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_CTTRL0_ADDR, value);
}

/**
 * @brief I2S_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16        i2s_fcw_delta   0x0
 *  13:12     i2ss1_lrclk_mode   0x0
 *  11:10      nco_adj_tim_win   0x0
 *     09   i2s1_tim_win_num_valid   0
 *     08   i2s0_tim_win_num_valid   0
 *  07:06    i2s1_tim_win_mode   0x0
 *  05:04    i2s0_tim_win_mode   0x0
 *     03         i2s1_eval_en   0
 *     02         i2s0_eval_en   0
 *  01:00     i2ss0_lrclk_mode   0x0
 * </pre>
 */
#define APB_I2S_CTRL1_ADDR   0xC0012098
#define APB_I2S_CTRL1_OFFSET 0x00000098
#define APB_I2S_CTRL1_INDEX  0x00000026
#define APB_I2S_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_i2s_ctrl1_get(void)
{
    return REG_PL_RD(APB_I2S_CTRL1_ADDR);
}

__INLINE void apb_i2s_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_CTRL1_ADDR, value);
}

// field definitions
#define APB_I2S_CTRL1_I_2S_FCW_DELTA_MASK             ((uint32_t)0xFFFF0000)
#define APB_I2S_CTRL1_I_2S_FCW_DELTA_LSB              16
#define APB_I2S_CTRL1_I_2S_FCW_DELTA_WIDTH            ((uint32_t)0x00000010)
#define APB_I2S_CTRL1_I_2SS_1_LRCLK_MODE_MASK         ((uint32_t)0x00003000)
#define APB_I2S_CTRL1_I_2SS_1_LRCLK_MODE_LSB          12
#define APB_I2S_CTRL1_I_2SS_1_LRCLK_MODE_WIDTH        ((uint32_t)0x00000002)
#define APB_I2S_CTRL1_NCO_ADJ_TIM_WIN_MASK            ((uint32_t)0x00000C00)
#define APB_I2S_CTRL1_NCO_ADJ_TIM_WIN_LSB             10
#define APB_I2S_CTRL1_NCO_ADJ_TIM_WIN_WIDTH           ((uint32_t)0x00000002)
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_NUM_VALID_BIT    ((uint32_t)0x00000200)
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_NUM_VALID_POS    9
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_NUM_VALID_BIT    ((uint32_t)0x00000100)
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_NUM_VALID_POS    8
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_MODE_MASK        ((uint32_t)0x000000C0)
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_MODE_LSB         6
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_MODE_WIDTH       ((uint32_t)0x00000002)
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_MODE_MASK        ((uint32_t)0x00000030)
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_MODE_LSB         4
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_MODE_WIDTH       ((uint32_t)0x00000002)
#define APB_I2S_CTRL1_I_2S_1_EVAL_EN_BIT              ((uint32_t)0x00000008)
#define APB_I2S_CTRL1_I_2S_1_EVAL_EN_POS              3
#define APB_I2S_CTRL1_I_2S_0_EVAL_EN_BIT              ((uint32_t)0x00000004)
#define APB_I2S_CTRL1_I_2S_0_EVAL_EN_POS              2
#define APB_I2S_CTRL1_I_2SS_0_LRCLK_MODE_MASK         ((uint32_t)0x00000003)
#define APB_I2S_CTRL1_I_2SS_0_LRCLK_MODE_LSB          0
#define APB_I2S_CTRL1_I_2SS_0_LRCLK_MODE_WIDTH        ((uint32_t)0x00000002)

#define APB_I2S_CTRL1_I_2S_FCW_DELTA_RST              0x0
#define APB_I2S_CTRL1_I_2SS_1_LRCLK_MODE_RST          0x0
#define APB_I2S_CTRL1_NCO_ADJ_TIM_WIN_RST             0x0
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_NUM_VALID_RST    0x0
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_NUM_VALID_RST    0x0
#define APB_I2S_CTRL1_I_2S_1_TIM_WIN_MODE_RST         0x0
#define APB_I2S_CTRL1_I_2S_0_TIM_WIN_MODE_RST         0x0
#define APB_I2S_CTRL1_I_2S_1_EVAL_EN_RST              0x0
#define APB_I2S_CTRL1_I_2S_0_EVAL_EN_RST              0x0
#define APB_I2S_CTRL1_I_2SS_0_LRCLK_MODE_RST          0x0

__INLINE void apb_i2s_ctrl1_pack(uint16_t i2sfcwdelta, uint8_t i2ss1lrclkmode, uint8_t ncoadjtimwin, uint8_t i2s1timwinnumvalid, uint8_t i2s0timwinnumvalid, uint8_t i2s1timwinmode, uint8_t i2s0timwinmode, uint8_t i2s1evalen, uint8_t i2s0evalen, uint8_t i2ss0lrclkmode)
{
    ASSERT_ERR((((uint32_t)i2sfcwdelta << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)i2ss1lrclkmode << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)ncoadjtimwin << 10) & ~((uint32_t)0x00000C00)) == 0);
    ASSERT_ERR((((uint32_t)i2s1timwinnumvalid << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)i2s0timwinnumvalid << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)i2s1timwinmode << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)i2s0timwinmode << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)i2s1evalen << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)i2s0evalen << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)i2ss0lrclkmode << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR,  ((uint32_t)i2sfcwdelta << 16) | ((uint32_t)i2ss1lrclkmode << 12) | ((uint32_t)ncoadjtimwin << 10) | ((uint32_t)i2s1timwinnumvalid << 9) | ((uint32_t)i2s0timwinnumvalid << 8) | ((uint32_t)i2s1timwinmode << 6) | ((uint32_t)i2s0timwinmode << 4) | ((uint32_t)i2s1evalen << 3) | ((uint32_t)i2s0evalen << 2) | ((uint32_t)i2ss0lrclkmode << 0));
}

__INLINE void apb_i2s_ctrl1_unpack(uint16_t* i2sfcwdelta, uint8_t* i2ss1lrclkmode, uint8_t* ncoadjtimwin, uint8_t* i2s1timwinnumvalid, uint8_t* i2s0timwinnumvalid, uint8_t* i2s1timwinmode, uint8_t* i2s0timwinmode, uint8_t* i2s1evalen, uint8_t* i2s0evalen, uint8_t* i2ss0lrclkmode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    *i2sfcwdelta = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *i2ss1lrclkmode = (localVal & ((uint32_t)0x00003000)) >> 12;
    *ncoadjtimwin = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *i2s1timwinnumvalid = (localVal & ((uint32_t)0x00000200)) >> 9;
    *i2s0timwinnumvalid = (localVal & ((uint32_t)0x00000100)) >> 8;
    *i2s1timwinmode = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *i2s0timwinmode = (localVal & ((uint32_t)0x00000030)) >> 4;
    *i2s1evalen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *i2s0evalen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *i2ss0lrclkmode = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint16_t apb_i2s_ctrl1_i_2s_fcw_delta_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE void apb_i2s_ctrl1_i_2s_fcw_delta_setf(uint16_t i2sfcwdelta)
{
    ASSERT_ERR((((uint32_t)i2sfcwdelta << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)i2sfcwdelta << 16));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2ss_1_lrclk_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void apb_i2s_ctrl1_i_2ss_1_lrclk_mode_setf(uint8_t i2ss1lrclkmode)
{
    ASSERT_ERR((((uint32_t)i2ss1lrclkmode << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)i2ss1lrclkmode << 12));
}

__INLINE uint8_t apb_i2s_ctrl1_nco_adj_tim_win_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE void apb_i2s_ctrl1_nco_adj_tim_win_setf(uint8_t ncoadjtimwin)
{
    ASSERT_ERR((((uint32_t)ncoadjtimwin << 10) & ~((uint32_t)0x00000C00)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)ncoadjtimwin << 10));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_1_tim_win_num_valid_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_i2s_ctrl1_i_2s_1_tim_win_num_valid_setf(uint8_t i2s1timwinnumvalid)
{
    ASSERT_ERR((((uint32_t)i2s1timwinnumvalid << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)i2s1timwinnumvalid << 9));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_0_tim_win_num_valid_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_i2s_ctrl1_i_2s_0_tim_win_num_valid_setf(uint8_t i2s0timwinnumvalid)
{
    ASSERT_ERR((((uint32_t)i2s0timwinnumvalid << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)i2s0timwinnumvalid << 8));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_1_tim_win_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_i2s_ctrl1_i_2s_1_tim_win_mode_setf(uint8_t i2s1timwinmode)
{
    ASSERT_ERR((((uint32_t)i2s1timwinmode << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)i2s1timwinmode << 6));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_0_tim_win_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_i2s_ctrl1_i_2s_0_tim_win_mode_setf(uint8_t i2s0timwinmode)
{
    ASSERT_ERR((((uint32_t)i2s0timwinmode << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)i2s0timwinmode << 4));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_1_eval_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_i2s_ctrl1_i_2s_1_eval_en_setf(uint8_t i2s1evalen)
{
    ASSERT_ERR((((uint32_t)i2s1evalen << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)i2s1evalen << 3));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2s_0_eval_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_i2s_ctrl1_i_2s_0_eval_en_setf(uint8_t i2s0evalen)
{
    ASSERT_ERR((((uint32_t)i2s0evalen << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)i2s0evalen << 2));
}

__INLINE uint8_t apb_i2s_ctrl1_i_2ss_0_lrclk_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void apb_i2s_ctrl1_i_2ss_0_lrclk_mode_setf(uint8_t i2ss0lrclkmode)
{
    ASSERT_ERR((((uint32_t)i2ss0lrclkmode << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_I2S_CTRL1_ADDR, (REG_PL_RD(APB_I2S_CTRL1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)i2ss0lrclkmode << 0));
}

/**
 * @brief I2S_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     27              fcw_smp   0
 *     26               nco_en   0
 *  25:00              i2s_fcw   0x0
 * </pre>
 */
#define APB_I2S_CTRL2_ADDR   0xC001209C
#define APB_I2S_CTRL2_OFFSET 0x0000009C
#define APB_I2S_CTRL2_INDEX  0x00000027
#define APB_I2S_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_i2s_ctrl2_get(void)
{
    return REG_PL_RD(APB_I2S_CTRL2_ADDR);
}

__INLINE void apb_i2s_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_I2S_CTRL2_ADDR, value);
}

// field definitions
#define APB_I2S_CTRL2_FCW_SMP_BIT     ((uint32_t)0x08000000)
#define APB_I2S_CTRL2_FCW_SMP_POS     27
#define APB_I2S_CTRL2_NCO_EN_BIT      ((uint32_t)0x04000000)
#define APB_I2S_CTRL2_NCO_EN_POS      26
#define APB_I2S_CTRL2_I_2S_FCW_MASK   ((uint32_t)0x03FFFFFF)
#define APB_I2S_CTRL2_I_2S_FCW_LSB    0
#define APB_I2S_CTRL2_I_2S_FCW_WIDTH  ((uint32_t)0x0000001A)

#define APB_I2S_CTRL2_FCW_SMP_RST     0x0
#define APB_I2S_CTRL2_NCO_EN_RST      0x0
#define APB_I2S_CTRL2_I_2S_FCW_RST    0x0

__INLINE void apb_i2s_ctrl2_pack(uint8_t fcwsmp, uint8_t ncoen, uint32_t i2sfcw)
{
    ASSERT_ERR((((uint32_t)fcwsmp << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)ncoen << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)i2sfcw << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
    REG_PL_WR(APB_I2S_CTRL2_ADDR,  ((uint32_t)fcwsmp << 27) | ((uint32_t)ncoen << 26) | ((uint32_t)i2sfcw << 0));
}

__INLINE void apb_i2s_ctrl2_unpack(uint8_t* fcwsmp, uint8_t* ncoen, uint32_t* i2sfcw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL2_ADDR);
    *fcwsmp = (localVal & ((uint32_t)0x08000000)) >> 27;
    *ncoen = (localVal & ((uint32_t)0x04000000)) >> 26;
    *i2sfcw = (localVal & ((uint32_t)0x03FFFFFF)) >> 0;
}

__INLINE uint8_t apb_i2s_ctrl2_fcw_smp_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE void apb_i2s_ctrl2_fcw_smp_setf(uint8_t fcwsmp)
{
    ASSERT_ERR((((uint32_t)fcwsmp << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_I2S_CTRL2_ADDR, (REG_PL_RD(APB_I2S_CTRL2_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)fcwsmp << 27));
}

__INLINE uint8_t apb_i2s_ctrl2_nco_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void apb_i2s_ctrl2_nco_en_setf(uint8_t ncoen)
{
    ASSERT_ERR((((uint32_t)ncoen << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_I2S_CTRL2_ADDR, (REG_PL_RD(APB_I2S_CTRL2_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)ncoen << 26));
}

__INLINE uint32_t apb_i2s_ctrl2_i_2s_fcw_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x03FFFFFF)) >> 0);
}

__INLINE void apb_i2s_ctrl2_i_2s_fcw_setf(uint32_t i2sfcw)
{
    ASSERT_ERR((((uint32_t)i2sfcw << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
    REG_PL_WR(APB_I2S_CTRL2_ADDR, (REG_PL_RD(APB_I2S_CTRL2_ADDR) & ~((uint32_t)0x03FFFFFF)) | ((uint32_t)i2sfcw << 0));
}

/**
 * @brief I2C_SLAVE_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00            i_addrlsb   0x0
 * </pre>
 */
#define APB_I2C_SLAVE_CTRL_ADDR   0xC00120A0
#define APB_I2C_SLAVE_CTRL_OFFSET 0x000000A0
#define APB_I2C_SLAVE_CTRL_INDEX  0x00000028
#define APB_I2C_SLAVE_CTRL_RESET  0x00000000

__INLINE uint32_t apb_i2c_slave_ctrl_get(void)
{
    return REG_PL_RD(APB_I2C_SLAVE_CTRL_ADDR);
}

__INLINE void apb_i2c_slave_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_I2C_SLAVE_CTRL_ADDR, value);
}

// field definitions
#define APB_I2C_SLAVE_CTRL_I_ADDRLSB_MASK   ((uint32_t)0x00000003)
#define APB_I2C_SLAVE_CTRL_I_ADDRLSB_LSB    0
#define APB_I2C_SLAVE_CTRL_I_ADDRLSB_WIDTH  ((uint32_t)0x00000002)

#define APB_I2C_SLAVE_CTRL_I_ADDRLSB_RST    0x0

__INLINE uint8_t apb_i2c_slave_ctrl_i_addrlsb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2C_SLAVE_CTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_i2c_slave_ctrl_i_addrlsb_setf(uint8_t iaddrlsb)
{
    ASSERT_ERR((((uint32_t)iaddrlsb << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_I2C_SLAVE_CTRL_ADDR, (uint32_t)iaddrlsb << 0);
}

/**
 * @brief MUTE_DET_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   audio_det_in_1L_en   0
 * </pre>
 */
#define APB_MUTE_DET_EN_ADDR   0xC00120A4
#define APB_MUTE_DET_EN_OFFSET 0x000000A4
#define APB_MUTE_DET_EN_INDEX  0x00000029
#define APB_MUTE_DET_EN_RESET  0x00000000

__INLINE uint32_t apb_mute_det_en_get(void)
{
    return REG_PL_RD(APB_MUTE_DET_EN_ADDR);
}

__INLINE void apb_mute_det_en_set(uint32_t value)
{
    REG_PL_WR(APB_MUTE_DET_EN_ADDR, value);
}

// field definitions
#define APB_MUTE_DET_EN_AUDIO_DET_IN__1L_EN_BIT    ((uint32_t)0x00000001)
#define APB_MUTE_DET_EN_AUDIO_DET_IN__1L_EN_POS    0

#define APB_MUTE_DET_EN_AUDIO_DET_IN__1L_EN_RST    0x0

__INLINE uint8_t apb_mute_det_en_audio_det_in__1l_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_MUTE_DET_EN_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_mute_det_en_audio_det_in__1l_en_setf(uint8_t audiodetin1len)
{
    ASSERT_ERR((((uint32_t)audiodetin1len << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_MUTE_DET_EN_ADDR, (uint32_t)audiodetin1len << 0);
}

/**
 * @brief MUTE_DET_THR0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00     audio_det_thr_1L   0x40
 * </pre>
 */
#define APB_MUTE_DET_THR0_ADDR   0xC00120A8
#define APB_MUTE_DET_THR0_OFFSET 0x000000A8
#define APB_MUTE_DET_THR0_INDEX  0x0000002A
#define APB_MUTE_DET_THR0_RESET  0x00000040

__INLINE uint32_t apb_mute_det_thr0_get(void)
{
    return REG_PL_RD(APB_MUTE_DET_THR0_ADDR);
}

__INLINE void apb_mute_det_thr0_set(uint32_t value)
{
    REG_PL_WR(APB_MUTE_DET_THR0_ADDR, value);
}

// field definitions
#define APB_MUTE_DET_THR0_AUDIO_DET_THR__1L_MASK   ((uint32_t)0x000000FF)
#define APB_MUTE_DET_THR0_AUDIO_DET_THR__1L_LSB    0
#define APB_MUTE_DET_THR0_AUDIO_DET_THR__1L_WIDTH  ((uint32_t)0x00000008)

#define APB_MUTE_DET_THR0_AUDIO_DET_THR__1L_RST    0x40

__INLINE uint8_t apb_mute_det_thr0_audio_det_thr__1l_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_MUTE_DET_THR0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_mute_det_thr0_audio_det_thr__1l_setf(uint8_t audiodetthr1l)
{
    ASSERT_ERR((((uint32_t)audiodetthr1l << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_MUTE_DET_THR0_ADDR, (uint32_t)audiodetthr1l << 0);
}

/**
 * @brief MUTE_DET_THR1 register definition
 */
#define APB_MUTE_DET_THR1_ADDR   0xC00120AC
#define APB_MUTE_DET_THR1_OFFSET 0x000000AC
#define APB_MUTE_DET_THR1_INDEX  0x0000002B
#define APB_MUTE_DET_THR1_RESET  0x00000000

__INLINE uint32_t apb_mute_det_thr1_get(void)
{
    return REG_PL_RD(APB_MUTE_DET_THR1_ADDR);
}

__INLINE void apb_mute_det_thr1_set(uint32_t value)
{
    REG_PL_WR(APB_MUTE_DET_THR1_ADDR, value);
}

/**
 * @brief MUTE_DET_LONG_WINDOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   audio_counter_long_window   0xABA94DC
 * </pre>
 */
#define APB_MUTE_DET_LONG_WINDOW_ADDR   0xC00120B0
#define APB_MUTE_DET_LONG_WINDOW_OFFSET 0x000000B0
#define APB_MUTE_DET_LONG_WINDOW_INDEX  0x0000002C
#define APB_MUTE_DET_LONG_WINDOW_RESET  0x0ABA94DC

__INLINE uint32_t apb_mute_det_long_window_get(void)
{
    return REG_PL_RD(APB_MUTE_DET_LONG_WINDOW_ADDR);
}

__INLINE void apb_mute_det_long_window_set(uint32_t value)
{
    REG_PL_WR(APB_MUTE_DET_LONG_WINDOW_ADDR, value);
}

// field definitions
#define APB_MUTE_DET_LONG_WINDOW_AUDIO_COUNTER_LONG_WINDOW_MASK   ((uint32_t)0xFFFFFFFF)
#define APB_MUTE_DET_LONG_WINDOW_AUDIO_COUNTER_LONG_WINDOW_LSB    0
#define APB_MUTE_DET_LONG_WINDOW_AUDIO_COUNTER_LONG_WINDOW_WIDTH  ((uint32_t)0x00000020)

#define APB_MUTE_DET_LONG_WINDOW_AUDIO_COUNTER_LONG_WINDOW_RST    0xABA94DC

__INLINE uint32_t apb_mute_det_long_window_audio_counter_long_window_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_MUTE_DET_LONG_WINDOW_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_mute_det_long_window_audio_counter_long_window_setf(uint32_t audiocounterlongwindow)
{
    ASSERT_ERR((((uint32_t)audiocounterlongwindow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(APB_MUTE_DET_LONG_WINDOW_ADDR, (uint32_t)audiocounterlongwindow << 0);
}

/**
 * @brief MUTE_DET_SHORT_WINDOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  13:00   audio_counter_short_window   0x3FF
 * </pre>
 */
#define APB_MUTE_DET_SHORT_WINDOW_ADDR   0xC00120B4
#define APB_MUTE_DET_SHORT_WINDOW_OFFSET 0x000000B4
#define APB_MUTE_DET_SHORT_WINDOW_INDEX  0x0000002D
#define APB_MUTE_DET_SHORT_WINDOW_RESET  0x000003FF

__INLINE uint32_t apb_mute_det_short_window_get(void)
{
    return REG_PL_RD(APB_MUTE_DET_SHORT_WINDOW_ADDR);
}

__INLINE void apb_mute_det_short_window_set(uint32_t value)
{
    REG_PL_WR(APB_MUTE_DET_SHORT_WINDOW_ADDR, value);
}

// field definitions
#define APB_MUTE_DET_SHORT_WINDOW_AUDIO_COUNTER_SHORT_WINDOW_MASK   ((uint32_t)0x00003FFF)
#define APB_MUTE_DET_SHORT_WINDOW_AUDIO_COUNTER_SHORT_WINDOW_LSB    0
#define APB_MUTE_DET_SHORT_WINDOW_AUDIO_COUNTER_SHORT_WINDOW_WIDTH  ((uint32_t)0x0000000E)

#define APB_MUTE_DET_SHORT_WINDOW_AUDIO_COUNTER_SHORT_WINDOW_RST    0x3FF

__INLINE uint16_t apb_mute_det_short_window_audio_counter_short_window_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_MUTE_DET_SHORT_WINDOW_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00003FFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_mute_det_short_window_audio_counter_short_window_setf(uint16_t audiocountershortwindow)
{
    ASSERT_ERR((((uint32_t)audiocountershortwindow << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(APB_MUTE_DET_SHORT_WINDOW_ADDR, (uint32_t)audiocountershortwindow << 0);
}

/**
 * @brief CPU_OTP_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03        cpu_tc_otp_en   0
 *     02       i2cs_tc_otp_en   0
 *     01    otp_read_exit_req   0
 *     00   otp_read_enter_req   0
 * </pre>
 */
#define APB_CPU_OTP_CFG0_ADDR   0xC00120B8
#define APB_CPU_OTP_CFG0_OFFSET 0x000000B8
#define APB_CPU_OTP_CFG0_INDEX  0x0000002E
#define APB_CPU_OTP_CFG0_RESET  0x00000000

__INLINE uint32_t apb_cpu_otp_cfg0_get(void)
{
    return REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
}

__INLINE void apb_cpu_otp_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR, value);
}

// field definitions
#define APB_CPU_OTP_CFG0_CPU_TC_OTP_EN_BIT         ((uint32_t)0x00000008)
#define APB_CPU_OTP_CFG0_CPU_TC_OTP_EN_POS         3
#define APB_CPU_OTP_CFG0_I_2CS_TC_OTP_EN_BIT       ((uint32_t)0x00000004)
#define APB_CPU_OTP_CFG0_I_2CS_TC_OTP_EN_POS       2
#define APB_CPU_OTP_CFG0_OTP_READ_EXIT_REQ_BIT     ((uint32_t)0x00000002)
#define APB_CPU_OTP_CFG0_OTP_READ_EXIT_REQ_POS     1
#define APB_CPU_OTP_CFG0_OTP_READ_ENTER_REQ_BIT    ((uint32_t)0x00000001)
#define APB_CPU_OTP_CFG0_OTP_READ_ENTER_REQ_POS    0

#define APB_CPU_OTP_CFG0_CPU_TC_OTP_EN_RST         0x0
#define APB_CPU_OTP_CFG0_I_2CS_TC_OTP_EN_RST       0x0
#define APB_CPU_OTP_CFG0_OTP_READ_EXIT_REQ_RST     0x0
#define APB_CPU_OTP_CFG0_OTP_READ_ENTER_REQ_RST    0x0

__INLINE void apb_cpu_otp_cfg0_pack(uint8_t cputcotpen, uint8_t i2cstcotpen, uint8_t otpreadexitreq, uint8_t otpreadenterreq)
{
    ASSERT_ERR((((uint32_t)cputcotpen << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)i2cstcotpen << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)otpreadexitreq << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)otpreadenterreq << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR,  ((uint32_t)cputcotpen << 3) | ((uint32_t)i2cstcotpen << 2) | ((uint32_t)otpreadexitreq << 1) | ((uint32_t)otpreadenterreq << 0));
}

__INLINE void apb_cpu_otp_cfg0_unpack(uint8_t* cputcotpen, uint8_t* i2cstcotpen, uint8_t* otpreadexitreq, uint8_t* otpreadenterreq)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
    *cputcotpen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *i2cstcotpen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *otpreadexitreq = (localVal & ((uint32_t)0x00000002)) >> 1;
    *otpreadenterreq = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_cpu_otp_cfg0_cpu_tc_otp_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_cpu_otp_cfg0_cpu_tc_otp_en_setf(uint8_t cputcotpen)
{
    ASSERT_ERR((((uint32_t)cputcotpen << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_CFG0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)cputcotpen << 3));
}

__INLINE uint8_t apb_cpu_otp_cfg0_i_2cs_tc_otp_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_cpu_otp_cfg0_i_2cs_tc_otp_en_setf(uint8_t i2cstcotpen)
{
    ASSERT_ERR((((uint32_t)i2cstcotpen << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_CFG0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)i2cstcotpen << 2));
}

__INLINE uint8_t apb_cpu_otp_cfg0_otp_read_exit_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_cpu_otp_cfg0_otp_read_exit_req_setf(uint8_t otpreadexitreq)
{
    ASSERT_ERR((((uint32_t)otpreadexitreq << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_CFG0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)otpreadexitreq << 1));
}

__INLINE uint8_t apb_cpu_otp_cfg0_otp_read_enter_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_cpu_otp_cfg0_otp_read_enter_req_setf(uint8_t otpreadenterreq)
{
    ASSERT_ERR((((uint32_t)otpreadenterreq << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_CPU_OTP_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_CFG0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)otpreadenterreq << 0));
}

/**
 * @brief CPU_OTP_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   no_otp_program_req   0
 *     02      otp_program_req   0
 *     01     otp_read_exit_ok   0
 *     00    otp_read_enter_ok   0
 * </pre>
 */
#define APB_CPU_OTP_STATUS0_ADDR   0xC00120BC
#define APB_CPU_OTP_STATUS0_OFFSET 0x000000BC
#define APB_CPU_OTP_STATUS0_INDEX  0x0000002F
#define APB_CPU_OTP_STATUS0_RESET  0x00000000

__INLINE uint32_t apb_cpu_otp_status0_get(void)
{
    return REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
}

__INLINE void apb_cpu_otp_status0_set(uint32_t value)
{
    REG_PL_WR(APB_CPU_OTP_STATUS0_ADDR, value);
}

// field definitions
#define APB_CPU_OTP_STATUS0_NO_OTP_PROGRAM_REQ_BIT    ((uint32_t)0x00000008)
#define APB_CPU_OTP_STATUS0_NO_OTP_PROGRAM_REQ_POS    3
#define APB_CPU_OTP_STATUS0_OTP_PROGRAM_REQ_BIT       ((uint32_t)0x00000004)
#define APB_CPU_OTP_STATUS0_OTP_PROGRAM_REQ_POS       2
#define APB_CPU_OTP_STATUS0_OTP_READ_EXIT_OK_BIT      ((uint32_t)0x00000002)
#define APB_CPU_OTP_STATUS0_OTP_READ_EXIT_OK_POS      1
#define APB_CPU_OTP_STATUS0_OTP_READ_ENTER_OK_BIT     ((uint32_t)0x00000001)
#define APB_CPU_OTP_STATUS0_OTP_READ_ENTER_OK_POS     0

#define APB_CPU_OTP_STATUS0_NO_OTP_PROGRAM_REQ_RST    0x0
#define APB_CPU_OTP_STATUS0_OTP_PROGRAM_REQ_RST       0x0
#define APB_CPU_OTP_STATUS0_OTP_READ_EXIT_OK_RST      0x0
#define APB_CPU_OTP_STATUS0_OTP_READ_ENTER_OK_RST     0x0

__INLINE void apb_cpu_otp_status0_unpack(uint8_t* nootpprogramreq, uint8_t* otpprogramreq, uint8_t* otpreadexitok, uint8_t* otpreadenterok)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
    *nootpprogramreq = (localVal & ((uint32_t)0x00000008)) >> 3;
    *otpprogramreq = (localVal & ((uint32_t)0x00000004)) >> 2;
    *otpreadexitok = (localVal & ((uint32_t)0x00000002)) >> 1;
    *otpreadenterok = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_cpu_otp_status0_no_otp_program_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_cpu_otp_status0_no_otp_program_req_setf(uint8_t nootpprogramreq)
{
    ASSERT_ERR((((uint32_t)nootpprogramreq << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_CPU_OTP_STATUS0_ADDR, (uint32_t)nootpprogramreq << 3);
}

__INLINE uint8_t apb_cpu_otp_status0_otp_program_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_cpu_otp_status0_otp_read_exit_ok_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_cpu_otp_status0_otp_read_enter_ok_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief CPU_OTP_TEST_REG_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     21          CPU_T_PGMEN   0
 *     20         CPU_T_READEN   0
 *     19           CPU_T_RSTB   1
 *     18            CPU_T_WEB   1
 *     17         CPU_T_CPUMEN   0
 *     16            CPU_T_DIN   0
 *     15            CPU_T_DLE   0
 *     14            CPU_T_CLE   0
 *     13            CPU_T_CEB   1
 *  12:00              CPU_T_A   0x0
 * </pre>
 */
#define APB_CPU_OTP_TEST_REG_CFG0_ADDR   0xC00120C0
#define APB_CPU_OTP_TEST_REG_CFG0_OFFSET 0x000000C0
#define APB_CPU_OTP_TEST_REG_CFG0_INDEX  0x00000030
#define APB_CPU_OTP_TEST_REG_CFG0_RESET  0x000C2000

__INLINE uint32_t apb_cpu_otp_test_reg_cfg0_get(void)
{
    return REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, value);
}

// field definitions
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_PGMEN_BIT     ((uint32_t)0x00200000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_PGMEN_POS     21
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_READEN_BIT    ((uint32_t)0x00100000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_READEN_POS    20
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_RSTB_BIT      ((uint32_t)0x00080000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_RSTB_POS      19
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_WEB_BIT       ((uint32_t)0x00040000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_WEB_POS       18
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CPUMEN_BIT    ((uint32_t)0x00020000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CPUMEN_POS    17
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DIN_BIT       ((uint32_t)0x00010000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DIN_POS       16
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DLE_BIT       ((uint32_t)0x00008000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DLE_POS       15
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CLE_BIT       ((uint32_t)0x00004000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CLE_POS       14
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CEB_BIT       ((uint32_t)0x00002000)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CEB_POS       13
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_A_MASK        ((uint32_t)0x00001FFF)
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_A_LSB         0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_A_WIDTH       ((uint32_t)0x0000000D)

#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_PGMEN_RST     0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_READEN_RST    0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_RSTB_RST      0x1
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_WEB_RST       0x1
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CPUMEN_RST    0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DIN_RST       0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_DLE_RST       0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CLE_RST       0x0
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_CEB_RST       0x1
#define APB_CPU_OTP_TEST_REG_CFG0_CPU_T_A_RST         0x0

__INLINE void apb_cpu_otp_test_reg_cfg0_pack(uint8_t cputpgmen, uint8_t cputreaden, uint8_t cputrstb, uint8_t cputweb, uint8_t cputcpumen, uint8_t cputdin, uint8_t cputdle, uint8_t cputcle, uint8_t cputceb, uint16_t cputa)
{
    ASSERT_ERR((((uint32_t)cputpgmen << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)cputreaden << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)cputrstb << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)cputweb << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)cputcpumen << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)cputdin << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)cputdle << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)cputcle << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)cputceb << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)cputa << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR,  ((uint32_t)cputpgmen << 21) | ((uint32_t)cputreaden << 20) | ((uint32_t)cputrstb << 19) | ((uint32_t)cputweb << 18) | ((uint32_t)cputcpumen << 17) | ((uint32_t)cputdin << 16) | ((uint32_t)cputdle << 15) | ((uint32_t)cputcle << 14) | ((uint32_t)cputceb << 13) | ((uint32_t)cputa << 0));
}

__INLINE void apb_cpu_otp_test_reg_cfg0_unpack(uint8_t* cputpgmen, uint8_t* cputreaden, uint8_t* cputrstb, uint8_t* cputweb, uint8_t* cputcpumen, uint8_t* cputdin, uint8_t* cputdle, uint8_t* cputcle, uint8_t* cputceb, uint16_t* cputa)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    *cputpgmen = (localVal & ((uint32_t)0x00200000)) >> 21;
    *cputreaden = (localVal & ((uint32_t)0x00100000)) >> 20;
    *cputrstb = (localVal & ((uint32_t)0x00080000)) >> 19;
    *cputweb = (localVal & ((uint32_t)0x00040000)) >> 18;
    *cputcpumen = (localVal & ((uint32_t)0x00020000)) >> 17;
    *cputdin = (localVal & ((uint32_t)0x00010000)) >> 16;
    *cputdle = (localVal & ((uint32_t)0x00008000)) >> 15;
    *cputcle = (localVal & ((uint32_t)0x00004000)) >> 14;
    *cputceb = (localVal & ((uint32_t)0x00002000)) >> 13;
    *cputa = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_pgmen_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_pgmen_setf(uint8_t cputpgmen)
{
    ASSERT_ERR((((uint32_t)cputpgmen << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)cputpgmen << 21));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_readen_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_readen_setf(uint8_t cputreaden)
{
    ASSERT_ERR((((uint32_t)cputreaden << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)cputreaden << 20));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_rstb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_rstb_setf(uint8_t cputrstb)
{
    ASSERT_ERR((((uint32_t)cputrstb << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)cputrstb << 19));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_web_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_web_setf(uint8_t cputweb)
{
    ASSERT_ERR((((uint32_t)cputweb << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)cputweb << 18));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_cpumen_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_cpumen_setf(uint8_t cputcpumen)
{
    ASSERT_ERR((((uint32_t)cputcpumen << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)cputcpumen << 17));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_din_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_din_setf(uint8_t cputdin)
{
    ASSERT_ERR((((uint32_t)cputdin << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)cputdin << 16));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_dle_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_dle_setf(uint8_t cputdle)
{
    ASSERT_ERR((((uint32_t)cputdle << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)cputdle << 15));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_cle_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_cle_setf(uint8_t cputcle)
{
    ASSERT_ERR((((uint32_t)cputcle << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)cputcle << 14));
}

__INLINE uint8_t apb_cpu_otp_test_reg_cfg0_cpu_t_ceb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_ceb_setf(uint8_t cputceb)
{
    ASSERT_ERR((((uint32_t)cputceb << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)cputceb << 13));
}

__INLINE uint16_t apb_cpu_otp_test_reg_cfg0_cpu_t_a_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

__INLINE void apb_cpu_otp_test_reg_cfg0_cpu_t_a_setf(uint16_t cputa)
{
    ASSERT_ERR((((uint32_t)cputa << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_CFG0_ADDR, (REG_PL_RD(APB_CPU_OTP_TEST_REG_CFG0_ADDR) & ~((uint32_t)0x00001FFF)) | ((uint32_t)cputa << 0));
}

/**
 * @brief CPU_OTP_TEST_REG_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:08              CPU_T_D   0x0
 *     00           CPU_T_LOCK   0
 * </pre>
 */
#define APB_CPU_OTP_TEST_REG_STATUS0_ADDR   0xC00120C4
#define APB_CPU_OTP_TEST_REG_STATUS0_OFFSET 0x000000C4
#define APB_CPU_OTP_TEST_REG_STATUS0_INDEX  0x00000031
#define APB_CPU_OTP_TEST_REG_STATUS0_RESET  0x00000000

__INLINE uint32_t apb_cpu_otp_test_reg_status0_get(void)
{
    return REG_PL_RD(APB_CPU_OTP_TEST_REG_STATUS0_ADDR);
}

__INLINE void apb_cpu_otp_test_reg_status0_set(uint32_t value)
{
    REG_PL_WR(APB_CPU_OTP_TEST_REG_STATUS0_ADDR, value);
}

// field definitions
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_D_MASK      ((uint32_t)0x0000FF00)
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_D_LSB       8
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_D_WIDTH     ((uint32_t)0x00000008)
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_LOCK_BIT    ((uint32_t)0x00000001)
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_LOCK_POS    0

#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_D_RST       0x0
#define APB_CPU_OTP_TEST_REG_STATUS0_CPU_T_LOCK_RST    0x0

__INLINE void apb_cpu_otp_test_reg_status0_unpack(uint8_t* cputd, uint8_t* cputlock)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_STATUS0_ADDR);
    *cputd = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *cputlock = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_cpu_otp_test_reg_status0_cpu_t_d_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE void apb_cpu_otp_test_reg_status0_cpu_t_d_setf(uint8_t cputd)
{
    ASSERT_ERR((((uint32_t)cputd << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(APB_CPU_OTP_TEST_REG_STATUS0_ADDR, (uint32_t)cputd << 8);
}

__INLINE uint8_t apb_cpu_otp_test_reg_status0_cpu_t_lock_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_CPU_OTP_TEST_REG_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief ADC_FILT_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31             SYNC_BIT   0
 *     24            CIC1_EN_2   1
 *     23            CIC2_EN_1   1
 *     22            CIC1_EN_1   1
 *  21:16              ADC_VOL   0x1A
 *  14:12           DCNOTCG_BW   0x4
 *     09           DCNOTCH_EN   1
 *     08               FIR_EN   1
 *     07           INVSINC_EN   1
 *     06              CIC7_EN   1
 *     05              CIC6_EN   1
 *     04              CIC5_EN   1
 *     03              CIC4_EN   1
 *     02              CIC3_EN   1
 *     01            CIC2_EN_0   1
 *     00            CIC1_EN_0   1
 * </pre>
 */
#define APB_ADC_FILT_CONFIG_0_ADDR   0xC00120C8
#define APB_ADC_FILT_CONFIG_0_OFFSET 0x000000C8
#define APB_ADC_FILT_CONFIG_0_INDEX  0x00000032
#define APB_ADC_FILT_CONFIG_0_RESET  0x01DA43FF

__INLINE uint32_t apb_adc_filt_config_0_get(void)
{
    return REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
}

__INLINE void apb_adc_filt_config_0_set(uint32_t value)
{
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, value);
}

// field definitions
#define APB_ADC_FILT_CONFIG_0_SYNC_BIT_BIT      ((uint32_t)0x80000000)
#define APB_ADC_FILT_CONFIG_0_SYNC_BIT_POS      31
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_2_BIT     ((uint32_t)0x01000000)
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_2_POS     24
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_1_BIT     ((uint32_t)0x00800000)
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_1_POS     23
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_1_BIT     ((uint32_t)0x00400000)
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_1_POS     22
#define APB_ADC_FILT_CONFIG_0_ADC_VOL_MASK      ((uint32_t)0x003F0000)
#define APB_ADC_FILT_CONFIG_0_ADC_VOL_LSB       16
#define APB_ADC_FILT_CONFIG_0_ADC_VOL_WIDTH     ((uint32_t)0x00000006)
#define APB_ADC_FILT_CONFIG_0_DCNOTCG_BW_MASK   ((uint32_t)0x00007000)
#define APB_ADC_FILT_CONFIG_0_DCNOTCG_BW_LSB    12
#define APB_ADC_FILT_CONFIG_0_DCNOTCG_BW_WIDTH  ((uint32_t)0x00000003)
#define APB_ADC_FILT_CONFIG_0_DCNOTCH_EN_BIT    ((uint32_t)0x00000200)
#define APB_ADC_FILT_CONFIG_0_DCNOTCH_EN_POS    9
#define APB_ADC_FILT_CONFIG_0_FIR_EN_BIT        ((uint32_t)0x00000100)
#define APB_ADC_FILT_CONFIG_0_FIR_EN_POS        8
#define APB_ADC_FILT_CONFIG_0_INVSINC_EN_BIT    ((uint32_t)0x00000080)
#define APB_ADC_FILT_CONFIG_0_INVSINC_EN_POS    7
#define APB_ADC_FILT_CONFIG_0_CIC7_EN_BIT       ((uint32_t)0x00000040)
#define APB_ADC_FILT_CONFIG_0_CIC7_EN_POS       6
#define APB_ADC_FILT_CONFIG_0_CIC6_EN_BIT       ((uint32_t)0x00000020)
#define APB_ADC_FILT_CONFIG_0_CIC6_EN_POS       5
#define APB_ADC_FILT_CONFIG_0_CIC5_EN_BIT       ((uint32_t)0x00000010)
#define APB_ADC_FILT_CONFIG_0_CIC5_EN_POS       4
#define APB_ADC_FILT_CONFIG_0_CIC4_EN_BIT       ((uint32_t)0x00000008)
#define APB_ADC_FILT_CONFIG_0_CIC4_EN_POS       3
#define APB_ADC_FILT_CONFIG_0_CIC3_EN_BIT       ((uint32_t)0x00000004)
#define APB_ADC_FILT_CONFIG_0_CIC3_EN_POS       2
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_0_BIT     ((uint32_t)0x00000002)
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_0_POS     1
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_0_BIT     ((uint32_t)0x00000001)
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_0_POS     0

#define APB_ADC_FILT_CONFIG_0_SYNC_BIT_RST      0x0
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_2_RST     0x1
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_1_RST     0x1
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_1_RST     0x1
#define APB_ADC_FILT_CONFIG_0_ADC_VOL_RST       0x1A
#define APB_ADC_FILT_CONFIG_0_DCNOTCG_BW_RST    0x4
#define APB_ADC_FILT_CONFIG_0_DCNOTCH_EN_RST    0x1
#define APB_ADC_FILT_CONFIG_0_FIR_EN_RST        0x1
#define APB_ADC_FILT_CONFIG_0_INVSINC_EN_RST    0x1
#define APB_ADC_FILT_CONFIG_0_CIC7_EN_RST       0x1
#define APB_ADC_FILT_CONFIG_0_CIC6_EN_RST       0x1
#define APB_ADC_FILT_CONFIG_0_CIC5_EN_RST       0x1
#define APB_ADC_FILT_CONFIG_0_CIC4_EN_RST       0x1
#define APB_ADC_FILT_CONFIG_0_CIC3_EN_RST       0x1
#define APB_ADC_FILT_CONFIG_0_CIC2_EN_0_RST     0x1
#define APB_ADC_FILT_CONFIG_0_CIC1_EN_0_RST     0x1

__INLINE void apb_adc_filt_config_0_pack(uint8_t syncbit, uint8_t cic1en2, uint8_t cic2en1, uint8_t cic1en1, uint8_t adcvol, uint8_t dcnotcgbw, uint8_t dcnotchen, uint8_t firen, uint8_t invsincen, uint8_t cic7en, uint8_t cic6en, uint8_t cic5en, uint8_t cic4en, uint8_t cic3en, uint8_t cic2en0, uint8_t cic1en0)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)cic1en2 << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)cic2en1 << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)cic1en1 << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)adcvol << 16) & ~((uint32_t)0x003F0000)) == 0);
    ASSERT_ERR((((uint32_t)dcnotcgbw << 12) & ~((uint32_t)0x00007000)) == 0);
    ASSERT_ERR((((uint32_t)dcnotchen << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)firen << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)invsincen << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)cic7en << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)cic6en << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)cic5en << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)cic4en << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)cic3en << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)cic2en0 << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)cic1en0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR,  ((uint32_t)syncbit << 31) | ((uint32_t)cic1en2 << 24) | ((uint32_t)cic2en1 << 23) | ((uint32_t)cic1en1 << 22) | ((uint32_t)adcvol << 16) | ((uint32_t)dcnotcgbw << 12) | ((uint32_t)dcnotchen << 9) | ((uint32_t)firen << 8) | ((uint32_t)invsincen << 7) | ((uint32_t)cic7en << 6) | ((uint32_t)cic6en << 5) | ((uint32_t)cic5en << 4) | ((uint32_t)cic4en << 3) | ((uint32_t)cic3en << 2) | ((uint32_t)cic2en0 << 1) | ((uint32_t)cic1en0 << 0));
}

__INLINE void apb_adc_filt_config_0_unpack(uint8_t* syncbit, uint8_t* cic1en2, uint8_t* cic2en1, uint8_t* cic1en1, uint8_t* adcvol, uint8_t* dcnotcgbw, uint8_t* dcnotchen, uint8_t* firen, uint8_t* invsincen, uint8_t* cic7en, uint8_t* cic6en, uint8_t* cic5en, uint8_t* cic4en, uint8_t* cic3en, uint8_t* cic2en0, uint8_t* cic1en0)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    *syncbit = (localVal & ((uint32_t)0x80000000)) >> 31;
    *cic1en2 = (localVal & ((uint32_t)0x01000000)) >> 24;
    *cic2en1 = (localVal & ((uint32_t)0x00800000)) >> 23;
    *cic1en1 = (localVal & ((uint32_t)0x00400000)) >> 22;
    *adcvol = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *dcnotcgbw = (localVal & ((uint32_t)0x00007000)) >> 12;
    *dcnotchen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *firen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *invsincen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *cic7en = (localVal & ((uint32_t)0x00000040)) >> 6;
    *cic6en = (localVal & ((uint32_t)0x00000020)) >> 5;
    *cic5en = (localVal & ((uint32_t)0x00000010)) >> 4;
    *cic4en = (localVal & ((uint32_t)0x00000008)) >> 3;
    *cic3en = (localVal & ((uint32_t)0x00000004)) >> 2;
    *cic2en0 = (localVal & ((uint32_t)0x00000002)) >> 1;
    *cic1en0 = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_adc_filt_config_0_sync_bit_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_adc_filt_config_0_sync_bit_setf(uint8_t syncbit)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)syncbit << 31));
}

__INLINE uint8_t apb_adc_filt_config_0_cic1_en_2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_adc_filt_config_0_cic1_en_2_setf(uint8_t cic1en2)
{
    ASSERT_ERR((((uint32_t)cic1en2 << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)cic1en2 << 24));
}

__INLINE uint8_t apb_adc_filt_config_0_cic2_en_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_adc_filt_config_0_cic2_en_1_setf(uint8_t cic2en1)
{
    ASSERT_ERR((((uint32_t)cic2en1 << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)cic2en1 << 23));
}

__INLINE uint8_t apb_adc_filt_config_0_cic1_en_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_adc_filt_config_0_cic1_en_1_setf(uint8_t cic1en1)
{
    ASSERT_ERR((((uint32_t)cic1en1 << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)cic1en1 << 22));
}

__INLINE uint8_t apb_adc_filt_config_0_adc_vol_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

__INLINE void apb_adc_filt_config_0_adc_vol_setf(uint8_t adcvol)
{
    ASSERT_ERR((((uint32_t)adcvol << 16) & ~((uint32_t)0x003F0000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)adcvol << 16));
}

__INLINE uint8_t apb_adc_filt_config_0_dcnotcg_bw_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00007000)) >> 12);
}

__INLINE void apb_adc_filt_config_0_dcnotcg_bw_setf(uint8_t dcnotcgbw)
{
    ASSERT_ERR((((uint32_t)dcnotcgbw << 12) & ~((uint32_t)0x00007000)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)dcnotcgbw << 12));
}

__INLINE uint8_t apb_adc_filt_config_0_dcnotch_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_adc_filt_config_0_dcnotch_en_setf(uint8_t dcnotchen)
{
    ASSERT_ERR((((uint32_t)dcnotchen << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)dcnotchen << 9));
}

__INLINE uint8_t apb_adc_filt_config_0_fir_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_adc_filt_config_0_fir_en_setf(uint8_t firen)
{
    ASSERT_ERR((((uint32_t)firen << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)firen << 8));
}

__INLINE uint8_t apb_adc_filt_config_0_invsinc_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void apb_adc_filt_config_0_invsinc_en_setf(uint8_t invsincen)
{
    ASSERT_ERR((((uint32_t)invsincen << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)invsincen << 7));
}

__INLINE uint8_t apb_adc_filt_config_0_cic7_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void apb_adc_filt_config_0_cic7_en_setf(uint8_t cic7en)
{
    ASSERT_ERR((((uint32_t)cic7en << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)cic7en << 6));
}

__INLINE uint8_t apb_adc_filt_config_0_cic6_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void apb_adc_filt_config_0_cic6_en_setf(uint8_t cic6en)
{
    ASSERT_ERR((((uint32_t)cic6en << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)cic6en << 5));
}

__INLINE uint8_t apb_adc_filt_config_0_cic5_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_adc_filt_config_0_cic5_en_setf(uint8_t cic5en)
{
    ASSERT_ERR((((uint32_t)cic5en << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)cic5en << 4));
}

__INLINE uint8_t apb_adc_filt_config_0_cic4_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_adc_filt_config_0_cic4_en_setf(uint8_t cic4en)
{
    ASSERT_ERR((((uint32_t)cic4en << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)cic4en << 3));
}

__INLINE uint8_t apb_adc_filt_config_0_cic3_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_adc_filt_config_0_cic3_en_setf(uint8_t cic3en)
{
    ASSERT_ERR((((uint32_t)cic3en << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)cic3en << 2));
}

__INLINE uint8_t apb_adc_filt_config_0_cic2_en_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_adc_filt_config_0_cic2_en_0_setf(uint8_t cic2en0)
{
    ASSERT_ERR((((uint32_t)cic2en0 << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)cic2en0 << 1));
}

__INLINE uint8_t apb_adc_filt_config_0_cic1_en_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_adc_filt_config_0_cic1_en_0_setf(uint8_t cic1en0)
{
    ASSERT_ERR((((uint32_t)cic1en0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_ADC_FILT_CONFIG_0_ADDR, (REG_PL_RD(APB_ADC_FILT_CONFIG_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)cic1en0 << 0));
}

/**
 * @brief ADC_FILT_CONFIG_1 register definition
 */
#define APB_ADC_FILT_CONFIG_1_ADDR   0xC00120CC
#define APB_ADC_FILT_CONFIG_1_OFFSET 0x000000CC
#define APB_ADC_FILT_CONFIG_1_INDEX  0x00000033
#define APB_ADC_FILT_CONFIG_1_RESET  0x00000000

__INLINE uint32_t apb_adc_filt_config_1_get(void)
{
    return REG_PL_RD(APB_ADC_FILT_CONFIG_1_ADDR);
}

__INLINE void apb_adc_filt_config_1_set(uint32_t value)
{
    REG_PL_WR(APB_ADC_FILT_CONFIG_1_ADDR, value);
}

/**
 * @brief ADC_FILT_CONFIG_2 register definition
 */
#define APB_ADC_FILT_CONFIG_2_ADDR   0xC00120D0
#define APB_ADC_FILT_CONFIG_2_OFFSET 0x000000D0
#define APB_ADC_FILT_CONFIG_2_INDEX  0x00000034
#define APB_ADC_FILT_CONFIG_2_RESET  0x00000000

__INLINE uint32_t apb_adc_filt_config_2_get(void)
{
    return REG_PL_RD(APB_ADC_FILT_CONFIG_2_ADDR);
}

__INLINE void apb_adc_filt_config_2_set(uint32_t value)
{
    REG_PL_WR(APB_ADC_FILT_CONFIG_2_ADDR, value);
}

/**
 * @brief ADC_FILT_CONFIG_3 register definition
 */
#define APB_ADC_FILT_CONFIG_3_ADDR   0xC00120D4
#define APB_ADC_FILT_CONFIG_3_OFFSET 0x000000D4
#define APB_ADC_FILT_CONFIG_3_INDEX  0x00000035
#define APB_ADC_FILT_CONFIG_3_RESET  0x00000000

__INLINE uint32_t apb_adc_filt_config_3_get(void)
{
    return REG_PL_RD(APB_ADC_FILT_CONFIG_3_ADDR);
}

__INLINE void apb_adc_filt_config_3_set(uint32_t value)
{
    REG_PL_WR(APB_ADC_FILT_CONFIG_3_ADDR, value);
}

/**
 * @brief DAC_FILT_CONFIG_LEFT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31             SYNC_BIT   0
 *     25            DAC_FS96K   0
 *     24          HALFBAND_EN   1
 *  22:20          TEST_CONFIG   0x0
 *     18               DWA_EN   1
 *  17:16               DC_SET   0x0
 *  15:14       DWA_OFFSET_EQU   0x2
 *  13:12           DWA_OFFSET   0x0
 *     11           SDM_LOW_EN   1
 *     10          SDM_HIGH_EN   1
 *     09               CIC_EN   1
 *     08           INVSINC_EN   1
 *  05:00               VOLUME   0x1A
 * </pre>
 */
#define APB_DAC_FILT_CONFIG_LEFT_ADDR   0xC00120D8
#define APB_DAC_FILT_CONFIG_LEFT_OFFSET 0x000000D8
#define APB_DAC_FILT_CONFIG_LEFT_INDEX  0x00000036
#define APB_DAC_FILT_CONFIG_LEFT_RESET  0x01048F1A

__INLINE uint32_t apb_dac_filt_config_left_get(void)
{
    return REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
}

__INLINE void apb_dac_filt_config_left_set(uint32_t value)
{
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, value);
}

// field definitions
#define APB_DAC_FILT_CONFIG_LEFT_SYNC_BIT_BIT          ((uint32_t)0x80000000)
#define APB_DAC_FILT_CONFIG_LEFT_SYNC_BIT_POS          31
#define APB_DAC_FILT_CONFIG_LEFT_DAC_FS96K_BIT         ((uint32_t)0x02000000)
#define APB_DAC_FILT_CONFIG_LEFT_DAC_FS96K_POS         25
#define APB_DAC_FILT_CONFIG_LEFT_HALFBAND_EN_BIT       ((uint32_t)0x01000000)
#define APB_DAC_FILT_CONFIG_LEFT_HALFBAND_EN_POS       24
#define APB_DAC_FILT_CONFIG_LEFT_TEST_CONFIG_MASK      ((uint32_t)0x00700000)
#define APB_DAC_FILT_CONFIG_LEFT_TEST_CONFIG_LSB       20
#define APB_DAC_FILT_CONFIG_LEFT_TEST_CONFIG_WIDTH     ((uint32_t)0x00000003)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_EN_BIT            ((uint32_t)0x00040000)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_EN_POS            18
#define APB_DAC_FILT_CONFIG_LEFT_DC_SET_MASK           ((uint32_t)0x00030000)
#define APB_DAC_FILT_CONFIG_LEFT_DC_SET_LSB            16
#define APB_DAC_FILT_CONFIG_LEFT_DC_SET_WIDTH          ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_EQU_MASK   ((uint32_t)0x0000C000)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_EQU_LSB    14
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_EQU_WIDTH  ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_MASK       ((uint32_t)0x00003000)
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_LSB        12
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_WIDTH      ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_LEFT_SDM_LOW_EN_BIT        ((uint32_t)0x00000800)
#define APB_DAC_FILT_CONFIG_LEFT_SDM_LOW_EN_POS        11
#define APB_DAC_FILT_CONFIG_LEFT_SDM_HIGH_EN_BIT       ((uint32_t)0x00000400)
#define APB_DAC_FILT_CONFIG_LEFT_SDM_HIGH_EN_POS       10
#define APB_DAC_FILT_CONFIG_LEFT_CIC_EN_BIT            ((uint32_t)0x00000200)
#define APB_DAC_FILT_CONFIG_LEFT_CIC_EN_POS            9
#define APB_DAC_FILT_CONFIG_LEFT_INVSINC_EN_BIT        ((uint32_t)0x00000100)
#define APB_DAC_FILT_CONFIG_LEFT_INVSINC_EN_POS        8
#define APB_DAC_FILT_CONFIG_LEFT_VOLUME_MASK           ((uint32_t)0x0000003F)
#define APB_DAC_FILT_CONFIG_LEFT_VOLUME_LSB            0
#define APB_DAC_FILT_CONFIG_LEFT_VOLUME_WIDTH          ((uint32_t)0x00000006)

#define APB_DAC_FILT_CONFIG_LEFT_SYNC_BIT_RST          0x0
#define APB_DAC_FILT_CONFIG_LEFT_DAC_FS96K_RST         0x0
#define APB_DAC_FILT_CONFIG_LEFT_HALFBAND_EN_RST       0x1
#define APB_DAC_FILT_CONFIG_LEFT_TEST_CONFIG_RST       0x0
#define APB_DAC_FILT_CONFIG_LEFT_DWA_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_LEFT_DC_SET_RST            0x0
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_EQU_RST    0x2
#define APB_DAC_FILT_CONFIG_LEFT_DWA_OFFSET_RST        0x0
#define APB_DAC_FILT_CONFIG_LEFT_SDM_LOW_EN_RST        0x1
#define APB_DAC_FILT_CONFIG_LEFT_SDM_HIGH_EN_RST       0x1
#define APB_DAC_FILT_CONFIG_LEFT_CIC_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_LEFT_INVSINC_EN_RST        0x1
#define APB_DAC_FILT_CONFIG_LEFT_VOLUME_RST            0x1A

__INLINE void apb_dac_filt_config_left_pack(uint8_t syncbit, uint8_t dacfs96k, uint8_t halfbanden, uint8_t testconfig, uint8_t dwaen, uint8_t dcset, uint8_t dwaoffsetequ, uint8_t dwaoffset, uint8_t sdmlowen, uint8_t sdmhighen, uint8_t cicen, uint8_t invsincen, uint8_t volume)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)dacfs96k << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)halfbanden << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)testconfig << 20) & ~((uint32_t)0x00700000)) == 0);
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)invsincen << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR,  ((uint32_t)syncbit << 31) | ((uint32_t)dacfs96k << 25) | ((uint32_t)halfbanden << 24) | ((uint32_t)testconfig << 20) | ((uint32_t)dwaen << 18) | ((uint32_t)dcset << 16) | ((uint32_t)dwaoffsetequ << 14) | ((uint32_t)dwaoffset << 12) | ((uint32_t)sdmlowen << 11) | ((uint32_t)sdmhighen << 10) | ((uint32_t)cicen << 9) | ((uint32_t)invsincen << 8) | ((uint32_t)volume << 0));
}

__INLINE void apb_dac_filt_config_left_unpack(uint8_t* syncbit, uint8_t* dacfs96k, uint8_t* halfbanden, uint8_t* testconfig, uint8_t* dwaen, uint8_t* dcset, uint8_t* dwaoffsetequ, uint8_t* dwaoffset, uint8_t* sdmlowen, uint8_t* sdmhighen, uint8_t* cicen, uint8_t* invsincen, uint8_t* volume)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    *syncbit = (localVal & ((uint32_t)0x80000000)) >> 31;
    *dacfs96k = (localVal & ((uint32_t)0x02000000)) >> 25;
    *halfbanden = (localVal & ((uint32_t)0x01000000)) >> 24;
    *testconfig = (localVal & ((uint32_t)0x00700000)) >> 20;
    *dwaen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *dcset = (localVal & ((uint32_t)0x00030000)) >> 16;
    *dwaoffsetequ = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *dwaoffset = (localVal & ((uint32_t)0x00003000)) >> 12;
    *sdmlowen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *sdmhighen = (localVal & ((uint32_t)0x00000400)) >> 10;
    *cicen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *invsincen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *volume = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

__INLINE uint8_t apb_dac_filt_config_left_sync_bit_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_dac_filt_config_left_sync_bit_setf(uint8_t syncbit)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)syncbit << 31));
}

__INLINE uint8_t apb_dac_filt_config_left_dac_fs96k_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_dac_filt_config_left_dac_fs96k_setf(uint8_t dacfs96k)
{
    ASSERT_ERR((((uint32_t)dacfs96k << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)dacfs96k << 25));
}

__INLINE uint8_t apb_dac_filt_config_left_halfband_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_dac_filt_config_left_halfband_en_setf(uint8_t halfbanden)
{
    ASSERT_ERR((((uint32_t)halfbanden << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)halfbanden << 24));
}

__INLINE uint8_t apb_dac_filt_config_left_test_config_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00700000)) >> 20);
}

__INLINE void apb_dac_filt_config_left_test_config_setf(uint8_t testconfig)
{
    ASSERT_ERR((((uint32_t)testconfig << 20) & ~((uint32_t)0x00700000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)testconfig << 20));
}

__INLINE uint8_t apb_dac_filt_config_left_dwa_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_dac_filt_config_left_dwa_en_setf(uint8_t dwaen)
{
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)dwaen << 18));
}

__INLINE uint8_t apb_dac_filt_config_left_dc_set_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_dac_filt_config_left_dc_set_setf(uint8_t dcset)
{
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)dcset << 16));
}

__INLINE uint8_t apb_dac_filt_config_left_dwa_offset_equ_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void apb_dac_filt_config_left_dwa_offset_equ_setf(uint8_t dwaoffsetequ)
{
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)dwaoffsetequ << 14));
}

__INLINE uint8_t apb_dac_filt_config_left_dwa_offset_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void apb_dac_filt_config_left_dwa_offset_setf(uint8_t dwaoffset)
{
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)dwaoffset << 12));
}

__INLINE uint8_t apb_dac_filt_config_left_sdm_low_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_dac_filt_config_left_sdm_low_en_setf(uint8_t sdmlowen)
{
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)sdmlowen << 11));
}

__INLINE uint8_t apb_dac_filt_config_left_sdm_high_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_dac_filt_config_left_sdm_high_en_setf(uint8_t sdmhighen)
{
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)sdmhighen << 10));
}

__INLINE uint8_t apb_dac_filt_config_left_cic_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_dac_filt_config_left_cic_en_setf(uint8_t cicen)
{
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)cicen << 9));
}

__INLINE uint8_t apb_dac_filt_config_left_invsinc_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_dac_filt_config_left_invsinc_en_setf(uint8_t invsincen)
{
    ASSERT_ERR((((uint32_t)invsincen << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)invsincen << 8));
}

__INLINE uint8_t apb_dac_filt_config_left_volume_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

__INLINE void apb_dac_filt_config_left_volume_setf(uint8_t volume)
{
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_LEFT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_LEFT_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)volume << 0));
}

/**
 * @brief DAC_FILT_CONFIG_RIGHT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31             SYNC_BIT   0
 *     18               DWA_EN   1
 *  17:16               DC_SET   0x0
 *  15:14       DWA_OFFSET_EQU   0x2
 *  13:12           DWA_OFFSET   0x0
 *     11           SDM_LOW_EN   1
 *     10          SDM_HIGH_EN   1
 *     09               CIC_EN   1
 *  05:00               VOLUME   0x1A
 * </pre>
 */
#define APB_DAC_FILT_CONFIG_RIGHT_ADDR   0xC00120DC
#define APB_DAC_FILT_CONFIG_RIGHT_OFFSET 0x000000DC
#define APB_DAC_FILT_CONFIG_RIGHT_INDEX  0x00000037
#define APB_DAC_FILT_CONFIG_RIGHT_RESET  0x00048E1A

__INLINE uint32_t apb_dac_filt_config_right_get(void)
{
    return REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
}

__INLINE void apb_dac_filt_config_right_set(uint32_t value)
{
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, value);
}

// field definitions
#define APB_DAC_FILT_CONFIG_RIGHT_SYNC_BIT_BIT          ((uint32_t)0x80000000)
#define APB_DAC_FILT_CONFIG_RIGHT_SYNC_BIT_POS          31
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_EN_BIT            ((uint32_t)0x00040000)
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_EN_POS            18
#define APB_DAC_FILT_CONFIG_RIGHT_DC_SET_MASK           ((uint32_t)0x00030000)
#define APB_DAC_FILT_CONFIG_RIGHT_DC_SET_LSB            16
#define APB_DAC_FILT_CONFIG_RIGHT_DC_SET_WIDTH          ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_EQU_MASK   ((uint32_t)0x0000C000)
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_EQU_LSB    14
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_EQU_WIDTH  ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_MASK       ((uint32_t)0x00003000)
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_LSB        12
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_WIDTH      ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_LOW_EN_BIT        ((uint32_t)0x00000800)
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_LOW_EN_POS        11
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_HIGH_EN_BIT       ((uint32_t)0x00000400)
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_HIGH_EN_POS       10
#define APB_DAC_FILT_CONFIG_RIGHT_CIC_EN_BIT            ((uint32_t)0x00000200)
#define APB_DAC_FILT_CONFIG_RIGHT_CIC_EN_POS            9
#define APB_DAC_FILT_CONFIG_RIGHT_VOLUME_MASK           ((uint32_t)0x0000003F)
#define APB_DAC_FILT_CONFIG_RIGHT_VOLUME_LSB            0
#define APB_DAC_FILT_CONFIG_RIGHT_VOLUME_WIDTH          ((uint32_t)0x00000006)

#define APB_DAC_FILT_CONFIG_RIGHT_SYNC_BIT_RST          0x0
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_RIGHT_DC_SET_RST            0x0
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_EQU_RST    0x2
#define APB_DAC_FILT_CONFIG_RIGHT_DWA_OFFSET_RST        0x0
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_LOW_EN_RST        0x1
#define APB_DAC_FILT_CONFIG_RIGHT_SDM_HIGH_EN_RST       0x1
#define APB_DAC_FILT_CONFIG_RIGHT_CIC_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_RIGHT_VOLUME_RST            0x1A

__INLINE void apb_dac_filt_config_right_pack(uint8_t syncbit, uint8_t dwaen, uint8_t dcset, uint8_t dwaoffsetequ, uint8_t dwaoffset, uint8_t sdmlowen, uint8_t sdmhighen, uint8_t cicen, uint8_t volume)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR,  ((uint32_t)syncbit << 31) | ((uint32_t)dwaen << 18) | ((uint32_t)dcset << 16) | ((uint32_t)dwaoffsetequ << 14) | ((uint32_t)dwaoffset << 12) | ((uint32_t)sdmlowen << 11) | ((uint32_t)sdmhighen << 10) | ((uint32_t)cicen << 9) | ((uint32_t)volume << 0));
}

__INLINE void apb_dac_filt_config_right_unpack(uint8_t* syncbit, uint8_t* dwaen, uint8_t* dcset, uint8_t* dwaoffsetequ, uint8_t* dwaoffset, uint8_t* sdmlowen, uint8_t* sdmhighen, uint8_t* cicen, uint8_t* volume)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    *syncbit = (localVal & ((uint32_t)0x80000000)) >> 31;
    *dwaen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *dcset = (localVal & ((uint32_t)0x00030000)) >> 16;
    *dwaoffsetequ = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *dwaoffset = (localVal & ((uint32_t)0x00003000)) >> 12;
    *sdmlowen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *sdmhighen = (localVal & ((uint32_t)0x00000400)) >> 10;
    *cicen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *volume = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

__INLINE uint8_t apb_dac_filt_config_right_sync_bit_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_dac_filt_config_right_sync_bit_setf(uint8_t syncbit)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)syncbit << 31));
}

__INLINE uint8_t apb_dac_filt_config_right_dwa_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_dac_filt_config_right_dwa_en_setf(uint8_t dwaen)
{
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)dwaen << 18));
}

__INLINE uint8_t apb_dac_filt_config_right_dc_set_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_dac_filt_config_right_dc_set_setf(uint8_t dcset)
{
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)dcset << 16));
}

__INLINE uint8_t apb_dac_filt_config_right_dwa_offset_equ_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void apb_dac_filt_config_right_dwa_offset_equ_setf(uint8_t dwaoffsetequ)
{
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)dwaoffsetequ << 14));
}

__INLINE uint8_t apb_dac_filt_config_right_dwa_offset_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void apb_dac_filt_config_right_dwa_offset_setf(uint8_t dwaoffset)
{
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)dwaoffset << 12));
}

__INLINE uint8_t apb_dac_filt_config_right_sdm_low_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_dac_filt_config_right_sdm_low_en_setf(uint8_t sdmlowen)
{
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)sdmlowen << 11));
}

__INLINE uint8_t apb_dac_filt_config_right_sdm_high_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_dac_filt_config_right_sdm_high_en_setf(uint8_t sdmhighen)
{
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)sdmhighen << 10));
}

__INLINE uint8_t apb_dac_filt_config_right_cic_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_dac_filt_config_right_cic_en_setf(uint8_t cicen)
{
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)cicen << 9));
}

__INLINE uint8_t apb_dac_filt_config_right_volume_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

__INLINE void apb_dac_filt_config_right_volume_setf(uint8_t volume)
{
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_RIGHT_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_RIGHT_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)volume << 0));
}

/**
 * @brief DAC_CIC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01                 Ovf1   0
 *     00                 Ovf0   0
 * </pre>
 */
#define APB_DAC_CIC_STATUS_ADDR   0xC00120E0
#define APB_DAC_CIC_STATUS_OFFSET 0x000000E0
#define APB_DAC_CIC_STATUS_INDEX  0x00000038
#define APB_DAC_CIC_STATUS_RESET  0x00000000

__INLINE uint32_t apb_dac_cic_status_get(void)
{
    return REG_PL_RD(APB_DAC_CIC_STATUS_ADDR);
}

__INLINE void apb_dac_cic_status_set(uint32_t value)
{
    REG_PL_WR(APB_DAC_CIC_STATUS_ADDR, value);
}

// field definitions
#define APB_DAC_CIC_STATUS_OVF_1_BIT    ((uint32_t)0x00000002)
#define APB_DAC_CIC_STATUS_OVF_1_POS    1
#define APB_DAC_CIC_STATUS_OVF_0_BIT    ((uint32_t)0x00000001)
#define APB_DAC_CIC_STATUS_OVF_0_POS    0

#define APB_DAC_CIC_STATUS_OVF_1_RST    0x0
#define APB_DAC_CIC_STATUS_OVF_0_RST    0x0

__INLINE void apb_dac_cic_status_unpack(uint8_t* ovf1, uint8_t* ovf0)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_CIC_STATUS_ADDR);
    *ovf1 = (localVal & ((uint32_t)0x00000002)) >> 1;
    *ovf0 = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_dac_cic_status_ovf_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_CIC_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_dac_cic_status_ovf_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_CIC_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief DAC_FILT_CONFIG_THIRD register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31             SYNC_BIT   0
 *     24          HALFBAND_EN   1
 *     18               DWA_EN   1
 *  17:16               DC_SET   0x0
 *  15:14       DWA_OFFSET_EQU   0x2
 *  13:12           DWA_OFFSET   0x0
 *     11           SDM_LOW_EN   1
 *     10          SDM_HIGH_EN   1
 *     09               CIC_EN   1
 *  05:00               VOLUME   0x1A
 * </pre>
 */
#define APB_DAC_FILT_CONFIG_THIRD_ADDR   0xC00120E4
#define APB_DAC_FILT_CONFIG_THIRD_OFFSET 0x000000E4
#define APB_DAC_FILT_CONFIG_THIRD_INDEX  0x00000039
#define APB_DAC_FILT_CONFIG_THIRD_RESET  0x01048E1A

__INLINE uint32_t apb_dac_filt_config_third_get(void)
{
    return REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
}

__INLINE void apb_dac_filt_config_third_set(uint32_t value)
{
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, value);
}

// field definitions
#define APB_DAC_FILT_CONFIG_THIRD_SYNC_BIT_BIT          ((uint32_t)0x80000000)
#define APB_DAC_FILT_CONFIG_THIRD_SYNC_BIT_POS          31
#define APB_DAC_FILT_CONFIG_THIRD_HALFBAND_EN_BIT       ((uint32_t)0x01000000)
#define APB_DAC_FILT_CONFIG_THIRD_HALFBAND_EN_POS       24
#define APB_DAC_FILT_CONFIG_THIRD_DWA_EN_BIT            ((uint32_t)0x00040000)
#define APB_DAC_FILT_CONFIG_THIRD_DWA_EN_POS            18
#define APB_DAC_FILT_CONFIG_THIRD_DC_SET_MASK           ((uint32_t)0x00030000)
#define APB_DAC_FILT_CONFIG_THIRD_DC_SET_LSB            16
#define APB_DAC_FILT_CONFIG_THIRD_DC_SET_WIDTH          ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_EQU_MASK   ((uint32_t)0x0000C000)
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_EQU_LSB    14
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_EQU_WIDTH  ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_MASK       ((uint32_t)0x00003000)
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_LSB        12
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_WIDTH      ((uint32_t)0x00000002)
#define APB_DAC_FILT_CONFIG_THIRD_SDM_LOW_EN_BIT        ((uint32_t)0x00000800)
#define APB_DAC_FILT_CONFIG_THIRD_SDM_LOW_EN_POS        11
#define APB_DAC_FILT_CONFIG_THIRD_SDM_HIGH_EN_BIT       ((uint32_t)0x00000400)
#define APB_DAC_FILT_CONFIG_THIRD_SDM_HIGH_EN_POS       10
#define APB_DAC_FILT_CONFIG_THIRD_CIC_EN_BIT            ((uint32_t)0x00000200)
#define APB_DAC_FILT_CONFIG_THIRD_CIC_EN_POS            9
#define APB_DAC_FILT_CONFIG_THIRD_VOLUME_MASK           ((uint32_t)0x0000003F)
#define APB_DAC_FILT_CONFIG_THIRD_VOLUME_LSB            0
#define APB_DAC_FILT_CONFIG_THIRD_VOLUME_WIDTH          ((uint32_t)0x00000006)

#define APB_DAC_FILT_CONFIG_THIRD_SYNC_BIT_RST          0x0
#define APB_DAC_FILT_CONFIG_THIRD_HALFBAND_EN_RST       0x1
#define APB_DAC_FILT_CONFIG_THIRD_DWA_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_THIRD_DC_SET_RST            0x0
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_EQU_RST    0x2
#define APB_DAC_FILT_CONFIG_THIRD_DWA_OFFSET_RST        0x0
#define APB_DAC_FILT_CONFIG_THIRD_SDM_LOW_EN_RST        0x1
#define APB_DAC_FILT_CONFIG_THIRD_SDM_HIGH_EN_RST       0x1
#define APB_DAC_FILT_CONFIG_THIRD_CIC_EN_RST            0x1
#define APB_DAC_FILT_CONFIG_THIRD_VOLUME_RST            0x1A

__INLINE void apb_dac_filt_config_third_pack(uint8_t syncbit, uint8_t halfbanden, uint8_t dwaen, uint8_t dcset, uint8_t dwaoffsetequ, uint8_t dwaoffset, uint8_t sdmlowen, uint8_t sdmhighen, uint8_t cicen, uint8_t volume)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)halfbanden << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR,  ((uint32_t)syncbit << 31) | ((uint32_t)halfbanden << 24) | ((uint32_t)dwaen << 18) | ((uint32_t)dcset << 16) | ((uint32_t)dwaoffsetequ << 14) | ((uint32_t)dwaoffset << 12) | ((uint32_t)sdmlowen << 11) | ((uint32_t)sdmhighen << 10) | ((uint32_t)cicen << 9) | ((uint32_t)volume << 0));
}

__INLINE void apb_dac_filt_config_third_unpack(uint8_t* syncbit, uint8_t* halfbanden, uint8_t* dwaen, uint8_t* dcset, uint8_t* dwaoffsetequ, uint8_t* dwaoffset, uint8_t* sdmlowen, uint8_t* sdmhighen, uint8_t* cicen, uint8_t* volume)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    *syncbit = (localVal & ((uint32_t)0x80000000)) >> 31;
    *halfbanden = (localVal & ((uint32_t)0x01000000)) >> 24;
    *dwaen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *dcset = (localVal & ((uint32_t)0x00030000)) >> 16;
    *dwaoffsetequ = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *dwaoffset = (localVal & ((uint32_t)0x00003000)) >> 12;
    *sdmlowen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *sdmhighen = (localVal & ((uint32_t)0x00000400)) >> 10;
    *cicen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *volume = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

__INLINE uint8_t apb_dac_filt_config_third_sync_bit_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_dac_filt_config_third_sync_bit_setf(uint8_t syncbit)
{
    ASSERT_ERR((((uint32_t)syncbit << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)syncbit << 31));
}

__INLINE uint8_t apb_dac_filt_config_third_halfband_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_dac_filt_config_third_halfband_en_setf(uint8_t halfbanden)
{
    ASSERT_ERR((((uint32_t)halfbanden << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)halfbanden << 24));
}

__INLINE uint8_t apb_dac_filt_config_third_dwa_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_dac_filt_config_third_dwa_en_setf(uint8_t dwaen)
{
    ASSERT_ERR((((uint32_t)dwaen << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)dwaen << 18));
}

__INLINE uint8_t apb_dac_filt_config_third_dc_set_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_dac_filt_config_third_dc_set_setf(uint8_t dcset)
{
    ASSERT_ERR((((uint32_t)dcset << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)dcset << 16));
}

__INLINE uint8_t apb_dac_filt_config_third_dwa_offset_equ_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void apb_dac_filt_config_third_dwa_offset_equ_setf(uint8_t dwaoffsetequ)
{
    ASSERT_ERR((((uint32_t)dwaoffsetequ << 14) & ~((uint32_t)0x0000C000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)dwaoffsetequ << 14));
}

__INLINE uint8_t apb_dac_filt_config_third_dwa_offset_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void apb_dac_filt_config_third_dwa_offset_setf(uint8_t dwaoffset)
{
    ASSERT_ERR((((uint32_t)dwaoffset << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)dwaoffset << 12));
}

__INLINE uint8_t apb_dac_filt_config_third_sdm_low_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_dac_filt_config_third_sdm_low_en_setf(uint8_t sdmlowen)
{
    ASSERT_ERR((((uint32_t)sdmlowen << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)sdmlowen << 11));
}

__INLINE uint8_t apb_dac_filt_config_third_sdm_high_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_dac_filt_config_third_sdm_high_en_setf(uint8_t sdmhighen)
{
    ASSERT_ERR((((uint32_t)sdmhighen << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)sdmhighen << 10));
}

__INLINE uint8_t apb_dac_filt_config_third_cic_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_dac_filt_config_third_cic_en_setf(uint8_t cicen)
{
    ASSERT_ERR((((uint32_t)cicen << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)cicen << 9));
}

__INLINE uint8_t apb_dac_filt_config_third_volume_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

__INLINE void apb_dac_filt_config_third_volume_setf(uint8_t volume)
{
    ASSERT_ERR((((uint32_t)volume << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_DAC_FILT_CONFIG_THIRD_ADDR, (REG_PL_RD(APB_DAC_FILT_CONFIG_THIRD_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)volume << 0));
}

/**
 * @brief PAD_GPIO_SW_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28     GPIO4_SW_CTRL_EN   0
 *     27      GPIO4_OUT_EN_SW   0
 *     26      GPIO4_ANA_EN_SW   0
 *  25:24   GPIO4_PULL_MODE_SEL_SW   0x0
 *     20     GPIO3_SW_CTRL_EN   0
 *     19      GPIO3_OUT_EN_SW   0
 *     18      GPIO3_ANA_EN_SW   0
 *  17:16   GPIO3_PULL_MODE_SEL_SW   0x0
 *     13     GPIO2_SW_CTRL_EN   0
 *     12     GPIO2_SPI_IIC_SW   0
 *     11      GPIO2_OUT_EN_SW   0
 *     10      GPIO2_ANA_EN_SW   0
 *  09:08   GPIO2_PULL_MODE_SEL_SW   0x0
 *     05     GPIO1_SW_CTRL_EN   0
 *     04     GPIO1_SPI_IIC_SW   0
 *     03      GPIO1_OUT_EN_SW   0
 *     02      GPIO1_ANA_EN_SW   0
 *  01:00   GPIO1_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_GPIO_SW_CTRL1_ADDR   0xC00120E8
#define APB_PAD_GPIO_SW_CTRL1_OFFSET 0x000000E8
#define APB_PAD_GPIO_SW_CTRL1_INDEX  0x0000003A
#define APB_PAD_GPIO_SW_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_pad_gpio_sw_ctrl1_get(void)
{
    return REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR);
}

__INLINE void apb_pad_gpio_sw_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, value);
}

// field definitions
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_SW_CTRL_EN_BIT          ((uint32_t)0x10000000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_SW_CTRL_EN_POS          28
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_OUT_EN_SW_BIT           ((uint32_t)0x08000000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_OUT_EN_SW_POS           27
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_ANA_EN_SW_BIT           ((uint32_t)0x04000000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_ANA_EN_SW_POS           26
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x03000000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_PULL_MODE_SEL_SW_LSB    24
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_SW_CTRL_EN_BIT          ((uint32_t)0x00100000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_SW_CTRL_EN_POS          20
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_OUT_EN_SW_BIT           ((uint32_t)0x00080000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_OUT_EN_SW_POS           19
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_ANA_EN_SW_BIT           ((uint32_t)0x00040000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_ANA_EN_SW_POS           18
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00030000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_PULL_MODE_SEL_SW_LSB    16
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SW_CTRL_EN_BIT          ((uint32_t)0x00002000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SW_CTRL_EN_POS          13
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SPI_IIC_SW_BIT          ((uint32_t)0x00001000)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SPI_IIC_SW_POS          12
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_OUT_EN_SW_BIT           ((uint32_t)0x00000800)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_OUT_EN_SW_POS           11
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_ANA_EN_SW_BIT           ((uint32_t)0x00000400)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_ANA_EN_SW_POS           10
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000300)
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_PULL_MODE_SEL_SW_LSB    8
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SW_CTRL_EN_BIT          ((uint32_t)0x00000020)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SW_CTRL_EN_POS          5
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SPI_IIC_SW_BIT          ((uint32_t)0x00000010)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SPI_IIC_SW_POS          4
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_OUT_EN_SW_BIT           ((uint32_t)0x00000008)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_OUT_EN_SW_POS           3
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_ANA_EN_SW_BIT           ((uint32_t)0x00000004)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_ANA_EN_SW_POS           2
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000003)
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_PULL_MODE_SEL_SW_LSB    0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_GPIO_SW_CTRL1_GPIO4_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO4_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO3_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_SPI_IIC_SW_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO2_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_SPI_IIC_SW_RST          0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL1_GPIO1_PULL_MODE_SEL_SW_RST    0x0

__INLINE void apb_pad_gpio_sw_ctrl1_pack(uint8_t gpio4swctrlen, uint8_t gpio4outensw, uint8_t gpio4anaensw, uint8_t gpio4pullmodeselsw, uint8_t gpio3swctrlen, uint8_t gpio3outensw, uint8_t gpio3anaensw, uint8_t gpio3pullmodeselsw, uint8_t gpio2swctrlen, uint8_t gpio2spiiicsw, uint8_t gpio2outensw, uint8_t gpio2anaensw, uint8_t gpio2pullmodeselsw, uint8_t gpio1swctrlen, uint8_t gpio1spiiicsw, uint8_t gpio1outensw, uint8_t gpio1anaensw, uint8_t gpio1pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio4swctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio4outensw << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio4anaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio4pullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio3swctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)gpio3outensw << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)gpio3anaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)gpio3pullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)gpio2swctrlen << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)gpio2spiiicsw << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)gpio2outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)gpio2anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)gpio2pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)gpio1swctrlen << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)gpio1spiiicsw << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)gpio1outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)gpio1anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)gpio1pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR,  ((uint32_t)gpio4swctrlen << 28) | ((uint32_t)gpio4outensw << 27) | ((uint32_t)gpio4anaensw << 26) | ((uint32_t)gpio4pullmodeselsw << 24) | ((uint32_t)gpio3swctrlen << 20) | ((uint32_t)gpio3outensw << 19) | ((uint32_t)gpio3anaensw << 18) | ((uint32_t)gpio3pullmodeselsw << 16) | ((uint32_t)gpio2swctrlen << 13) | ((uint32_t)gpio2spiiicsw << 12) | ((uint32_t)gpio2outensw << 11) | ((uint32_t)gpio2anaensw << 10) | ((uint32_t)gpio2pullmodeselsw << 8) | ((uint32_t)gpio1swctrlen << 5) | ((uint32_t)gpio1spiiicsw << 4) | ((uint32_t)gpio1outensw << 3) | ((uint32_t)gpio1anaensw << 2) | ((uint32_t)gpio1pullmodeselsw << 0));
}

__INLINE void apb_pad_gpio_sw_ctrl1_unpack(uint8_t* gpio4swctrlen, uint8_t* gpio4outensw, uint8_t* gpio4anaensw, uint8_t* gpio4pullmodeselsw, uint8_t* gpio3swctrlen, uint8_t* gpio3outensw, uint8_t* gpio3anaensw, uint8_t* gpio3pullmodeselsw, uint8_t* gpio2swctrlen, uint8_t* gpio2spiiicsw, uint8_t* gpio2outensw, uint8_t* gpio2anaensw, uint8_t* gpio2pullmodeselsw, uint8_t* gpio1swctrlen, uint8_t* gpio1spiiicsw, uint8_t* gpio1outensw, uint8_t* gpio1anaensw, uint8_t* gpio1pullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR);
    *gpio4swctrlen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *gpio4outensw = (localVal & ((uint32_t)0x08000000)) >> 27;
    *gpio4anaensw = (localVal & ((uint32_t)0x04000000)) >> 26;
    *gpio4pullmodeselsw = (localVal & ((uint32_t)0x03000000)) >> 24;
    *gpio3swctrlen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *gpio3outensw = (localVal & ((uint32_t)0x00080000)) >> 19;
    *gpio3anaensw = (localVal & ((uint32_t)0x00040000)) >> 18;
    *gpio3pullmodeselsw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *gpio2swctrlen = (localVal & ((uint32_t)0x00002000)) >> 13;
    *gpio2spiiicsw = (localVal & ((uint32_t)0x00001000)) >> 12;
    *gpio2outensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *gpio2anaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *gpio2pullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *gpio1swctrlen = (localVal & ((uint32_t)0x00000020)) >> 5;
    *gpio1spiiicsw = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpio1outensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio1anaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio1pullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio4_sw_ctrl_en_setf(uint8_t gpio4swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio4swctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)gpio4swctrlen << 28));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio4_out_en_sw_setf(uint8_t gpio4outensw)
{
    ASSERT_ERR((((uint32_t)gpio4outensw << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)gpio4outensw << 27));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio4_ana_en_sw_setf(uint8_t gpio4anaensw)
{
    ASSERT_ERR((((uint32_t)gpio4anaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)gpio4anaensw << 26));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio4_pull_mode_sel_sw_setf(uint8_t gpio4pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio4pullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)gpio4pullmodeselsw << 24));
}

__INLINE uint8_t apb_pad_gpio_sw_ctrl1_gpio3_sw_ctrl_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio3_sw_ctrl_en_setf(uint8_t gpio3swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio3swctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)gpio3swctrlen << 20));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio3_out_en_sw_setf(uint8_t gpio3outensw)
{
    ASSERT_ERR((((uint32_t)gpio3outensw << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)gpio3outensw << 19));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio3_ana_en_sw_setf(uint8_t gpio3anaensw)
{
    ASSERT_ERR((((uint32_t)gpio3anaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)gpio3anaensw << 18));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio3_pull_mode_sel_sw_setf(uint8_t gpio3pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio3pullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)gpio3pullmodeselsw << 16));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio2_sw_ctrl_en_setf(uint8_t gpio2swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio2swctrlen << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)gpio2swctrlen << 13));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio2_spi_iic_sw_setf(uint8_t gpio2spiiicsw)
{
    ASSERT_ERR((((uint32_t)gpio2spiiicsw << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpio2spiiicsw << 12));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio2_out_en_sw_setf(uint8_t gpio2outensw)
{
    ASSERT_ERR((((uint32_t)gpio2outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpio2outensw << 11));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio2_ana_en_sw_setf(uint8_t gpio2anaensw)
{
    ASSERT_ERR((((uint32_t)gpio2anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpio2anaensw << 10));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio2_pull_mode_sel_sw_setf(uint8_t gpio2pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio2pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)gpio2pullmodeselsw << 8));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio1_sw_ctrl_en_setf(uint8_t gpio1swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio1swctrlen << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)gpio1swctrlen << 5));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio1_spi_iic_sw_setf(uint8_t gpio1spiiicsw)
{
    ASSERT_ERR((((uint32_t)gpio1spiiicsw << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)gpio1spiiicsw << 4));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio1_out_en_sw_setf(uint8_t gpio1outensw)
{
    ASSERT_ERR((((uint32_t)gpio1outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gpio1outensw << 3));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio1_ana_en_sw_setf(uint8_t gpio1anaensw)
{
    ASSERT_ERR((((uint32_t)gpio1anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)gpio1anaensw << 2));
}

__INLINE void apb_pad_gpio_sw_ctrl1_gpio1_pull_mode_sel_sw_setf(uint8_t gpio1pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio1pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)gpio1pullmodeselsw << 0));
}

/**
 * @brief PAD_GPIO_SW_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28     GPIO8_SW_CTRL_EN   0
 *     27      GPIO8_OUT_EN_SW   0
 *     26      GPIO8_ANA_EN_SW   0
 *  25:24   GPIO8_PULL_MODE_SEL_SW   0x0
 *     20     GPIO7_SW_CTRL_EN   0
 *     19      GPIO7_OUT_EN_SW   0
 *     18      GPIO7_ANA_EN_SW   0
 *  17:16   GPIO7_PULL_MODE_SEL_SW   0x0
 *     12     GPIO6_SW_CTRL_EN   0
 *     11      GPIO6_OUT_EN_SW   0
 *     10      GPIO6_ANA_EN_SW   0
 *  09:08   GPIO6_PULL_MODE_SEL_SW   0x0
 *     04     GPIO5_SW_CTRL_EN   0
 *     03      GPIO5_OUT_EN_SW   0
 *     02      GPIO5_ANA_EN_SW   0
 *  01:00   GPIO5_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_GPIO_SW_CTRL2_ADDR   0xC00120EC
#define APB_PAD_GPIO_SW_CTRL2_OFFSET 0x000000EC
#define APB_PAD_GPIO_SW_CTRL2_INDEX  0x0000003B
#define APB_PAD_GPIO_SW_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_pad_gpio_sw_ctrl2_get(void)
{
    return REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR);
}

__INLINE void apb_pad_gpio_sw_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, value);
}

// field definitions
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_SW_CTRL_EN_BIT          ((uint32_t)0x10000000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_SW_CTRL_EN_POS          28
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_OUT_EN_SW_BIT           ((uint32_t)0x08000000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_OUT_EN_SW_POS           27
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_ANA_EN_SW_BIT           ((uint32_t)0x04000000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_ANA_EN_SW_POS           26
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x03000000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_PULL_MODE_SEL_SW_LSB    24
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_SW_CTRL_EN_BIT          ((uint32_t)0x00100000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_SW_CTRL_EN_POS          20
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_OUT_EN_SW_BIT           ((uint32_t)0x00080000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_OUT_EN_SW_POS           19
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_ANA_EN_SW_BIT           ((uint32_t)0x00040000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_ANA_EN_SW_POS           18
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00030000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_PULL_MODE_SEL_SW_LSB    16
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_SW_CTRL_EN_BIT          ((uint32_t)0x00001000)
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_SW_CTRL_EN_POS          12
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_OUT_EN_SW_BIT           ((uint32_t)0x00000800)
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_OUT_EN_SW_POS           11
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_ANA_EN_SW_BIT           ((uint32_t)0x00000400)
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_ANA_EN_SW_POS           10
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000300)
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_PULL_MODE_SEL_SW_LSB    8
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_SW_CTRL_EN_BIT          ((uint32_t)0x00000010)
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_SW_CTRL_EN_POS          4
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_OUT_EN_SW_BIT           ((uint32_t)0x00000008)
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_OUT_EN_SW_POS           3
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_ANA_EN_SW_BIT           ((uint32_t)0x00000004)
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_ANA_EN_SW_POS           2
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000003)
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_PULL_MODE_SEL_SW_LSB    0
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_GPIO_SW_CTRL2_GPIO8_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO8_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO7_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO6_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL2_GPIO5_PULL_MODE_SEL_SW_RST    0x0

__INLINE void apb_pad_gpio_sw_ctrl2_pack(uint8_t gpio8swctrlen, uint8_t gpio8outensw, uint8_t gpio8anaensw, uint8_t gpio8pullmodeselsw, uint8_t gpio7swctrlen, uint8_t gpio7outensw, uint8_t gpio7anaensw, uint8_t gpio7pullmodeselsw, uint8_t gpio6swctrlen, uint8_t gpio6outensw, uint8_t gpio6anaensw, uint8_t gpio6pullmodeselsw, uint8_t gpio5swctrlen, uint8_t gpio5outensw, uint8_t gpio5anaensw, uint8_t gpio5pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio8swctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio8outensw << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio8anaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio8pullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio7swctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)gpio7outensw << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)gpio7anaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)gpio7pullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)gpio6swctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)gpio6outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)gpio6anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)gpio6pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)gpio5swctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)gpio5outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)gpio5anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)gpio5pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR,  ((uint32_t)gpio8swctrlen << 28) | ((uint32_t)gpio8outensw << 27) | ((uint32_t)gpio8anaensw << 26) | ((uint32_t)gpio8pullmodeselsw << 24) | ((uint32_t)gpio7swctrlen << 20) | ((uint32_t)gpio7outensw << 19) | ((uint32_t)gpio7anaensw << 18) | ((uint32_t)gpio7pullmodeselsw << 16) | ((uint32_t)gpio6swctrlen << 12) | ((uint32_t)gpio6outensw << 11) | ((uint32_t)gpio6anaensw << 10) | ((uint32_t)gpio6pullmodeselsw << 8) | ((uint32_t)gpio5swctrlen << 4) | ((uint32_t)gpio5outensw << 3) | ((uint32_t)gpio5anaensw << 2) | ((uint32_t)gpio5pullmodeselsw << 0));
}

__INLINE void apb_pad_gpio_sw_ctrl2_unpack(uint8_t* gpio8swctrlen, uint8_t* gpio8outensw, uint8_t* gpio8anaensw, uint8_t* gpio8pullmodeselsw, uint8_t* gpio7swctrlen, uint8_t* gpio7outensw, uint8_t* gpio7anaensw, uint8_t* gpio7pullmodeselsw, uint8_t* gpio6swctrlen, uint8_t* gpio6outensw, uint8_t* gpio6anaensw, uint8_t* gpio6pullmodeselsw, uint8_t* gpio5swctrlen, uint8_t* gpio5outensw, uint8_t* gpio5anaensw, uint8_t* gpio5pullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR);
    *gpio8swctrlen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *gpio8outensw = (localVal & ((uint32_t)0x08000000)) >> 27;
    *gpio8anaensw = (localVal & ((uint32_t)0x04000000)) >> 26;
    *gpio8pullmodeselsw = (localVal & ((uint32_t)0x03000000)) >> 24;
    *gpio7swctrlen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *gpio7outensw = (localVal & ((uint32_t)0x00080000)) >> 19;
    *gpio7anaensw = (localVal & ((uint32_t)0x00040000)) >> 18;
    *gpio7pullmodeselsw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *gpio6swctrlen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *gpio6outensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *gpio6anaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *gpio6pullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *gpio5swctrlen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpio5outensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio5anaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio5pullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio8_sw_ctrl_en_setf(uint8_t gpio8swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio8swctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)gpio8swctrlen << 28));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio8_out_en_sw_setf(uint8_t gpio8outensw)
{
    ASSERT_ERR((((uint32_t)gpio8outensw << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)gpio8outensw << 27));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio8_ana_en_sw_setf(uint8_t gpio8anaensw)
{
    ASSERT_ERR((((uint32_t)gpio8anaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)gpio8anaensw << 26));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio8_pull_mode_sel_sw_setf(uint8_t gpio8pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio8pullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)gpio8pullmodeselsw << 24));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio7_sw_ctrl_en_setf(uint8_t gpio7swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio7swctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)gpio7swctrlen << 20));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio7_out_en_sw_setf(uint8_t gpio7outensw)
{
    ASSERT_ERR((((uint32_t)gpio7outensw << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)gpio7outensw << 19));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio7_ana_en_sw_setf(uint8_t gpio7anaensw)
{
    ASSERT_ERR((((uint32_t)gpio7anaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)gpio7anaensw << 18));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio7_pull_mode_sel_sw_setf(uint8_t gpio7pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio7pullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)gpio7pullmodeselsw << 16));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio6_sw_ctrl_en_setf(uint8_t gpio6swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio6swctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpio6swctrlen << 12));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio6_out_en_sw_setf(uint8_t gpio6outensw)
{
    ASSERT_ERR((((uint32_t)gpio6outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpio6outensw << 11));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio6_ana_en_sw_setf(uint8_t gpio6anaensw)
{
    ASSERT_ERR((((uint32_t)gpio6anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpio6anaensw << 10));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio6_pull_mode_sel_sw_setf(uint8_t gpio6pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio6pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)gpio6pullmodeselsw << 8));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio5_sw_ctrl_en_setf(uint8_t gpio5swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio5swctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)gpio5swctrlen << 4));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio5_out_en_sw_setf(uint8_t gpio5outensw)
{
    ASSERT_ERR((((uint32_t)gpio5outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gpio5outensw << 3));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio5_ana_en_sw_setf(uint8_t gpio5anaensw)
{
    ASSERT_ERR((((uint32_t)gpio5anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)gpio5anaensw << 2));
}

__INLINE void apb_pad_gpio_sw_ctrl2_gpio5_pull_mode_sel_sw_setf(uint8_t gpio5pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio5pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)gpio5pullmodeselsw << 0));
}

/**
 * @brief PAD_SPI_SW_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28   SPI_MISO_SW_CTRL_EN   0
 *     27   SPI_MISO_OUT_EN_SW   0
 *     26   SPI_MISO_ANA_EN_SW   0
 *  25:24   SPI_MISO_PULL_MODE_SEL_SW   0x0
 *     20   SPI_MOSI_SW_CTRL_EN   0
 *     19   SPI_MOSI_OUT_EN_SW   0
 *     18   SPI_MOSI_ANA_EN_SW   0
 *  17:16   SPI_MOSI_PULL_MODE_SEL_SW   0x0
 *     12   SPI_NSS_SW_CTRL_EN   0
 *     11    SPI_NSS_OUT_EN_SW   0
 *     10    SPI_NSS_ANA_EN_SW   0
 *  09:08   SPI_NSS_PULL_MODE_SEL_SW   0x0
 *     04   SPI_SCLK_SW_CTRL_EN   0
 *     03   SPI_SCLK_OUT_EN_SW   0
 *     02   SPI_SCLK_ANA_EN_SW   0
 *  01:00   SPI_SCLK_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_SPI_SW_CTRL1_ADDR   0xC00120F0
#define APB_PAD_SPI_SW_CTRL1_OFFSET 0x000000F0
#define APB_PAD_SPI_SW_CTRL1_INDEX  0x0000003C
#define APB_PAD_SPI_SW_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_pad_spi_sw_ctrl1_get(void)
{
    return REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR);
}

__INLINE void apb_pad_spi_sw_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, value);
}

// field definitions
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_SW_CTRL_EN_BIT          ((uint32_t)0x10000000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_SW_CTRL_EN_POS          28
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_OUT_EN_SW_BIT           ((uint32_t)0x08000000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_OUT_EN_SW_POS           27
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_ANA_EN_SW_BIT           ((uint32_t)0x04000000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_ANA_EN_SW_POS           26
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x03000000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_PULL_MODE_SEL_SW_LSB    24
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_SW_CTRL_EN_BIT          ((uint32_t)0x00100000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_SW_CTRL_EN_POS          20
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_OUT_EN_SW_BIT           ((uint32_t)0x00080000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_OUT_EN_SW_POS           19
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_ANA_EN_SW_BIT           ((uint32_t)0x00040000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_ANA_EN_SW_POS           18
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00030000)
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_PULL_MODE_SEL_SW_LSB    16
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_SW_CTRL_EN_BIT           ((uint32_t)0x00001000)
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_SW_CTRL_EN_POS           12
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_OUT_EN_SW_BIT            ((uint32_t)0x00000800)
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_OUT_EN_SW_POS            11
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_ANA_EN_SW_BIT            ((uint32_t)0x00000400)
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_ANA_EN_SW_POS            10
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_PULL_MODE_SEL_SW_MASK    ((uint32_t)0x00000300)
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_PULL_MODE_SEL_SW_LSB     8
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_PULL_MODE_SEL_SW_WIDTH   ((uint32_t)0x00000002)
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_SW_CTRL_EN_BIT          ((uint32_t)0x00000010)
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_SW_CTRL_EN_POS          4
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_OUT_EN_SW_BIT           ((uint32_t)0x00000008)
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_OUT_EN_SW_POS           3
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_ANA_EN_SW_BIT           ((uint32_t)0x00000004)
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_ANA_EN_SW_POS           2
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000003)
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_PULL_MODE_SEL_SW_LSB    0
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_SW_CTRL_EN_RST          0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_OUT_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_ANA_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MISO_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_SW_CTRL_EN_RST          0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_OUT_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_ANA_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_MOSI_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_SW_CTRL_EN_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_OUT_EN_SW_RST            0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_ANA_EN_SW_RST            0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_NSS_PULL_MODE_SEL_SW_RST     0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_SW_CTRL_EN_RST          0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_OUT_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_ANA_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL1_SPI_SCLK_PULL_MODE_SEL_SW_RST    0x0

__INLINE void apb_pad_spi_sw_ctrl1_pack(uint8_t spimisoswctrlen, uint8_t spimisooutensw, uint8_t spimisoanaensw, uint8_t spimisopullmodeselsw, uint8_t spimosiswctrlen, uint8_t spimosioutensw, uint8_t spimosianaensw, uint8_t spimosipullmodeselsw, uint8_t spinssswctrlen, uint8_t spinssoutensw, uint8_t spinssanaensw, uint8_t spinsspullmodeselsw, uint8_t spisclkswctrlen, uint8_t spisclkoutensw, uint8_t spisclkanaensw, uint8_t spisclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spimisoswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)spimisooutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)spimisoanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)spimisopullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)spimosiswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)spimosioutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)spimosianaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)spimosipullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)spinssswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)spinssoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)spinssanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)spinsspullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)spisclkswctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)spisclkoutensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)spisclkanaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)spisclkpullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR,  ((uint32_t)spimisoswctrlen << 28) | ((uint32_t)spimisooutensw << 27) | ((uint32_t)spimisoanaensw << 26) | ((uint32_t)spimisopullmodeselsw << 24) | ((uint32_t)spimosiswctrlen << 20) | ((uint32_t)spimosioutensw << 19) | ((uint32_t)spimosianaensw << 18) | ((uint32_t)spimosipullmodeselsw << 16) | ((uint32_t)spinssswctrlen << 12) | ((uint32_t)spinssoutensw << 11) | ((uint32_t)spinssanaensw << 10) | ((uint32_t)spinsspullmodeselsw << 8) | ((uint32_t)spisclkswctrlen << 4) | ((uint32_t)spisclkoutensw << 3) | ((uint32_t)spisclkanaensw << 2) | ((uint32_t)spisclkpullmodeselsw << 0));
}

__INLINE void apb_pad_spi_sw_ctrl1_unpack(uint8_t* spimisoswctrlen, uint8_t* spimisooutensw, uint8_t* spimisoanaensw, uint8_t* spimisopullmodeselsw, uint8_t* spimosiswctrlen, uint8_t* spimosioutensw, uint8_t* spimosianaensw, uint8_t* spimosipullmodeselsw, uint8_t* spinssswctrlen, uint8_t* spinssoutensw, uint8_t* spinssanaensw, uint8_t* spinsspullmodeselsw, uint8_t* spisclkswctrlen, uint8_t* spisclkoutensw, uint8_t* spisclkanaensw, uint8_t* spisclkpullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR);
    *spimisoswctrlen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *spimisooutensw = (localVal & ((uint32_t)0x08000000)) >> 27;
    *spimisoanaensw = (localVal & ((uint32_t)0x04000000)) >> 26;
    *spimisopullmodeselsw = (localVal & ((uint32_t)0x03000000)) >> 24;
    *spimosiswctrlen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *spimosioutensw = (localVal & ((uint32_t)0x00080000)) >> 19;
    *spimosianaensw = (localVal & ((uint32_t)0x00040000)) >> 18;
    *spimosipullmodeselsw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *spinssswctrlen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *spinssoutensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *spinssanaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *spinsspullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *spisclkswctrlen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *spisclkoutensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *spisclkanaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *spisclkpullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_miso_sw_ctrl_en_setf(uint8_t spimisoswctrlen)
{
    ASSERT_ERR((((uint32_t)spimisoswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)spimisoswctrlen << 28));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_miso_out_en_sw_setf(uint8_t spimisooutensw)
{
    ASSERT_ERR((((uint32_t)spimisooutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)spimisooutensw << 27));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_miso_ana_en_sw_setf(uint8_t spimisoanaensw)
{
    ASSERT_ERR((((uint32_t)spimisoanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)spimisoanaensw << 26));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_miso_pull_mode_sel_sw_setf(uint8_t spimisopullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spimisopullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)spimisopullmodeselsw << 24));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_mosi_sw_ctrl_en_setf(uint8_t spimosiswctrlen)
{
    ASSERT_ERR((((uint32_t)spimosiswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)spimosiswctrlen << 20));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_mosi_out_en_sw_setf(uint8_t spimosioutensw)
{
    ASSERT_ERR((((uint32_t)spimosioutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)spimosioutensw << 19));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_mosi_ana_en_sw_setf(uint8_t spimosianaensw)
{
    ASSERT_ERR((((uint32_t)spimosianaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)spimosianaensw << 18));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_mosi_pull_mode_sel_sw_setf(uint8_t spimosipullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spimosipullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)spimosipullmodeselsw << 16));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_nss_sw_ctrl_en_setf(uint8_t spinssswctrlen)
{
    ASSERT_ERR((((uint32_t)spinssswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)spinssswctrlen << 12));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_nss_out_en_sw_setf(uint8_t spinssoutensw)
{
    ASSERT_ERR((((uint32_t)spinssoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)spinssoutensw << 11));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_nss_ana_en_sw_setf(uint8_t spinssanaensw)
{
    ASSERT_ERR((((uint32_t)spinssanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)spinssanaensw << 10));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_nss_pull_mode_sel_sw_setf(uint8_t spinsspullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spinsspullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)spinsspullmodeselsw << 8));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_sclk_sw_ctrl_en_setf(uint8_t spisclkswctrlen)
{
    ASSERT_ERR((((uint32_t)spisclkswctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)spisclkswctrlen << 4));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_sclk_out_en_sw_setf(uint8_t spisclkoutensw)
{
    ASSERT_ERR((((uint32_t)spisclkoutensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)spisclkoutensw << 3));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_sclk_ana_en_sw_setf(uint8_t spisclkanaensw)
{
    ASSERT_ERR((((uint32_t)spisclkanaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)spisclkanaensw << 2));
}

__INLINE void apb_pad_spi_sw_ctrl1_spi_sclk_pull_mode_sel_sw_setf(uint8_t spisclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spisclkpullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)spisclkpullmodeselsw << 0));
}

/**
 * @brief PAD_SPI_SW_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     12   SPI_IO3_SW_CTRL_EN   0
 *     11    SPI_IO3_OUT_EN_SW   0
 *     10    SPI_IO3_ANA_EN_SW   0
 *  09:08   SPI_IO3_PULL_MODE_SEL_SW   0x0
 *     04   SPI_IO2_SW_CTRL_EN   0
 *     03    SPI_IO2_OUT_EN_SW   0
 *     02    SPI_IO2_ANA_EN_SW   0
 *  01:00   SPI_IO2_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_SPI_SW_CTRL2_ADDR   0xC00120F4
#define APB_PAD_SPI_SW_CTRL2_OFFSET 0x000000F4
#define APB_PAD_SPI_SW_CTRL2_INDEX  0x0000003D
#define APB_PAD_SPI_SW_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_pad_spi_sw_ctrl2_get(void)
{
    return REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR);
}

__INLINE void apb_pad_spi_sw_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, value);
}

// field definitions
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_SW_CTRL_EN_BIT          ((uint32_t)0x00001000)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_SW_CTRL_EN_POS          12
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_OUT_EN_SW_BIT           ((uint32_t)0x00000800)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_OUT_EN_SW_POS           11
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_ANA_EN_SW_BIT           ((uint32_t)0x00000400)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_ANA_EN_SW_POS           10
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000300)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_PULL_MODE_SEL_SW_LSB    8
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_SW_CTRL_EN_BIT          ((uint32_t)0x00000010)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_SW_CTRL_EN_POS          4
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_OUT_EN_SW_BIT           ((uint32_t)0x00000008)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_OUT_EN_SW_POS           3
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_ANA_EN_SW_BIT           ((uint32_t)0x00000004)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_ANA_EN_SW_POS           2
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000003)
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_PULL_MODE_SEL_SW_LSB    0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_SW_CTRL_EN_RST          0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_OUT_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_ANA_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO3_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_SW_CTRL_EN_RST          0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_OUT_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_ANA_EN_SW_RST           0x0
#define APB_PAD_SPI_SW_CTRL2_SPI_IO2_PULL_MODE_SEL_SW_RST    0x0

__INLINE void apb_pad_spi_sw_ctrl2_pack(uint8_t spiio3swctrlen, uint8_t spiio3outensw, uint8_t spiio3anaensw, uint8_t spiio3pullmodeselsw, uint8_t spiio2swctrlen, uint8_t spiio2outensw, uint8_t spiio2anaensw, uint8_t spiio2pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spiio3swctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)spiio3outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)spiio3anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)spiio3pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)spiio2swctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)spiio2outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)spiio2anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)spiio2pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR,  ((uint32_t)spiio3swctrlen << 12) | ((uint32_t)spiio3outensw << 11) | ((uint32_t)spiio3anaensw << 10) | ((uint32_t)spiio3pullmodeselsw << 8) | ((uint32_t)spiio2swctrlen << 4) | ((uint32_t)spiio2outensw << 3) | ((uint32_t)spiio2anaensw << 2) | ((uint32_t)spiio2pullmodeselsw << 0));
}

__INLINE void apb_pad_spi_sw_ctrl2_unpack(uint8_t* spiio3swctrlen, uint8_t* spiio3outensw, uint8_t* spiio3anaensw, uint8_t* spiio3pullmodeselsw, uint8_t* spiio2swctrlen, uint8_t* spiio2outensw, uint8_t* spiio2anaensw, uint8_t* spiio2pullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR);
    *spiio3swctrlen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *spiio3outensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *spiio3anaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *spiio3pullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *spiio2swctrlen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *spiio2outensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *spiio2anaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *spiio2pullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io3_sw_ctrl_en_setf(uint8_t spiio3swctrlen)
{
    ASSERT_ERR((((uint32_t)spiio3swctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)spiio3swctrlen << 12));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io3_out_en_sw_setf(uint8_t spiio3outensw)
{
    ASSERT_ERR((((uint32_t)spiio3outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)spiio3outensw << 11));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io3_ana_en_sw_setf(uint8_t spiio3anaensw)
{
    ASSERT_ERR((((uint32_t)spiio3anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)spiio3anaensw << 10));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io3_pull_mode_sel_sw_setf(uint8_t spiio3pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spiio3pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)spiio3pullmodeselsw << 8));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io2_sw_ctrl_en_setf(uint8_t spiio2swctrlen)
{
    ASSERT_ERR((((uint32_t)spiio2swctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)spiio2swctrlen << 4));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io2_out_en_sw_setf(uint8_t spiio2outensw)
{
    ASSERT_ERR((((uint32_t)spiio2outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)spiio2outensw << 3));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io2_ana_en_sw_setf(uint8_t spiio2anaensw)
{
    ASSERT_ERR((((uint32_t)spiio2anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)spiio2anaensw << 2));
}

__INLINE void apb_pad_spi_sw_ctrl2_spi_io2_pull_mode_sel_sw_setf(uint8_t spiio2pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)spiio2pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_SPI_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_SPI_SW_CTRL2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)spiio2pullmodeselsw << 0));
}

/**
 * @brief PAD_I2S_SW_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28   I2S0_SDOUT_SW_CTRL_EN   0
 *     27   I2S0_SDOUT_OUT_EN_SW   0
 *     26   I2S0_SDOUT_ANA_EN_SW   0
 *  25:24   I2S0_SDOUT_PULL_MODE_SEL_SW   0x0
 *     20   I2S0_LRCLK_SW_CTRL_EN   0
 *     19   I2S0_LRCLK_OUT_EN_SW   0
 *     18   I2S0_LRCLK_ANA_EN_SW   0
 *  17:16   I2S0_LRCLK_PULL_MODE_SEL_SW   0x0
 *     12   I2S0_SCLK_SW_CTRL_EN   0
 *     11   I2S0_SCLK_OUT_EN_SW   0
 *     10   I2S0_SCLK_ANA_EN_SW   0
 *  09:08   I2S0_SCLK_PULL_MODE_SEL_SW   0x0
 *     04   I2S_MCLK_SW_CTRL_EN   0
 *     03   I2S_MCLK_OUT_EN_SW   0
 *     02   I2S_MCLK_ANA_EN_SW   0
 *  01:00   I2S_MCLK_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_I2S_SW_CTRL1_ADDR   0xC00120F8
#define APB_PAD_I2S_SW_CTRL1_OFFSET 0x000000F8
#define APB_PAD_I2S_SW_CTRL1_INDEX  0x0000003E
#define APB_PAD_I2S_SW_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_pad_i2s_sw_ctrl1_get(void)
{
    return REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR);
}

__INLINE void apb_pad_i2s_sw_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, value);
}

// field definitions
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_SW_CTRL_EN_BIT          ((uint32_t)0x10000000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_SW_CTRL_EN_POS          28
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_OUT_EN_SW_BIT           ((uint32_t)0x08000000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_OUT_EN_SW_POS           27
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_ANA_EN_SW_BIT           ((uint32_t)0x04000000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_ANA_EN_SW_POS           26
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x03000000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_PULL_MODE_SEL_SW_LSB    24
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_SW_CTRL_EN_BIT          ((uint32_t)0x00100000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_SW_CTRL_EN_POS          20
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_OUT_EN_SW_BIT           ((uint32_t)0x00080000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_OUT_EN_SW_POS           19
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_ANA_EN_SW_BIT           ((uint32_t)0x00040000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_ANA_EN_SW_POS           18
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00030000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_PULL_MODE_SEL_SW_LSB    16
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_SW_CTRL_EN_BIT           ((uint32_t)0x00001000)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_SW_CTRL_EN_POS           12
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_OUT_EN_SW_BIT            ((uint32_t)0x00000800)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_OUT_EN_SW_POS            11
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_ANA_EN_SW_BIT            ((uint32_t)0x00000400)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_ANA_EN_SW_POS            10
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_PULL_MODE_SEL_SW_MASK    ((uint32_t)0x00000300)
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_PULL_MODE_SEL_SW_LSB     8
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_PULL_MODE_SEL_SW_WIDTH   ((uint32_t)0x00000002)
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_SW_CTRL_EN_BIT            ((uint32_t)0x00000010)
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_SW_CTRL_EN_POS            4
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_OUT_EN_SW_BIT             ((uint32_t)0x00000008)
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_OUT_EN_SW_POS             3
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_ANA_EN_SW_BIT             ((uint32_t)0x00000004)
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_ANA_EN_SW_POS             2
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_PULL_MODE_SEL_SW_MASK     ((uint32_t)0x00000003)
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_PULL_MODE_SEL_SW_LSB      0
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_PULL_MODE_SEL_SW_WIDTH    ((uint32_t)0x00000002)

#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_SW_CTRL_EN_RST          0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_OUT_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_ANA_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SDOUT_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_SW_CTRL_EN_RST          0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_OUT_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_ANA_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_LRCLK_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_SW_CTRL_EN_RST           0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_OUT_EN_SW_RST            0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_ANA_EN_SW_RST            0x0
#define APB_PAD_I2S_SW_CTRL1_I2S0_SCLK_PULL_MODE_SEL_SW_RST     0x0
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_SW_CTRL_EN_RST            0x0
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_OUT_EN_SW_RST             0x0
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_ANA_EN_SW_RST             0x0
#define APB_PAD_I2S_SW_CTRL1_I2S_MCLK_PULL_MODE_SEL_SW_RST      0x0

__INLINE void apb_pad_i2s_sw_ctrl1_pack(uint8_t i2s0sdoutswctrlen, uint8_t i2s0sdoutoutensw, uint8_t i2s0sdoutanaensw, uint8_t i2s0sdoutpullmodeselsw, uint8_t i2s0lrclkswctrlen, uint8_t i2s0lrclkoutensw, uint8_t i2s0lrclkanaensw, uint8_t i2s0lrclkpullmodeselsw, uint8_t i2s0sclkswctrlen, uint8_t i2s0sclkoutensw, uint8_t i2s0sclkanaensw, uint8_t i2s0sclkpullmodeselsw, uint8_t i2smclkswctrlen, uint8_t i2smclkoutensw, uint8_t i2smclkanaensw, uint8_t i2smclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sdoutoutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sdoutanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sdoutpullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0lrclkswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0lrclkoutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0lrclkanaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0lrclkpullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclkswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclkoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclkanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclkpullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkswctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkoutensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkanaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkpullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR,  ((uint32_t)i2s0sdoutswctrlen << 28) | ((uint32_t)i2s0sdoutoutensw << 27) | ((uint32_t)i2s0sdoutanaensw << 26) | ((uint32_t)i2s0sdoutpullmodeselsw << 24) | ((uint32_t)i2s0lrclkswctrlen << 20) | ((uint32_t)i2s0lrclkoutensw << 19) | ((uint32_t)i2s0lrclkanaensw << 18) | ((uint32_t)i2s0lrclkpullmodeselsw << 16) | ((uint32_t)i2s0sclkswctrlen << 12) | ((uint32_t)i2s0sclkoutensw << 11) | ((uint32_t)i2s0sclkanaensw << 10) | ((uint32_t)i2s0sclkpullmodeselsw << 8) | ((uint32_t)i2smclkswctrlen << 4) | ((uint32_t)i2smclkoutensw << 3) | ((uint32_t)i2smclkanaensw << 2) | ((uint32_t)i2smclkpullmodeselsw << 0));
}

__INLINE void apb_pad_i2s_sw_ctrl1_unpack(uint8_t* i2s0sdoutswctrlen, uint8_t* i2s0sdoutoutensw, uint8_t* i2s0sdoutanaensw, uint8_t* i2s0sdoutpullmodeselsw, uint8_t* i2s0lrclkswctrlen, uint8_t* i2s0lrclkoutensw, uint8_t* i2s0lrclkanaensw, uint8_t* i2s0lrclkpullmodeselsw, uint8_t* i2s0sclkswctrlen, uint8_t* i2s0sclkoutensw, uint8_t* i2s0sclkanaensw, uint8_t* i2s0sclkpullmodeselsw, uint8_t* i2smclkswctrlen, uint8_t* i2smclkoutensw, uint8_t* i2smclkanaensw, uint8_t* i2smclkpullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR);
    *i2s0sdoutswctrlen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *i2s0sdoutoutensw = (localVal & ((uint32_t)0x08000000)) >> 27;
    *i2s0sdoutanaensw = (localVal & ((uint32_t)0x04000000)) >> 26;
    *i2s0sdoutpullmodeselsw = (localVal & ((uint32_t)0x03000000)) >> 24;
    *i2s0lrclkswctrlen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *i2s0lrclkoutensw = (localVal & ((uint32_t)0x00080000)) >> 19;
    *i2s0lrclkanaensw = (localVal & ((uint32_t)0x00040000)) >> 18;
    *i2s0lrclkpullmodeselsw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *i2s0sclkswctrlen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *i2s0sclkoutensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *i2s0sclkanaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2s0sclkpullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *i2smclkswctrlen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *i2smclkoutensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *i2smclkanaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *i2smclkpullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sdout_sw_ctrl_en_setf(uint8_t i2s0sdoutswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)i2s0sdoutswctrlen << 28));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sdout_out_en_sw_setf(uint8_t i2s0sdoutoutensw)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutoutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)i2s0sdoutoutensw << 27));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sdout_ana_en_sw_setf(uint8_t i2s0sdoutanaensw)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)i2s0sdoutanaensw << 26));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sdout_pull_mode_sel_sw_setf(uint8_t i2s0sdoutpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutpullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)i2s0sdoutpullmodeselsw << 24));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_lrclk_sw_ctrl_en_setf(uint8_t i2s0lrclkswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s0lrclkswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)i2s0lrclkswctrlen << 20));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_lrclk_out_en_sw_setf(uint8_t i2s0lrclkoutensw)
{
    ASSERT_ERR((((uint32_t)i2s0lrclkoutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)i2s0lrclkoutensw << 19));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_lrclk_ana_en_sw_setf(uint8_t i2s0lrclkanaensw)
{
    ASSERT_ERR((((uint32_t)i2s0lrclkanaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)i2s0lrclkanaensw << 18));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_lrclk_pull_mode_sel_sw_setf(uint8_t i2s0lrclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s0lrclkpullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)i2s0lrclkpullmodeselsw << 16));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sclk_sw_ctrl_en_setf(uint8_t i2s0sclkswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s0sclkswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)i2s0sclkswctrlen << 12));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sclk_out_en_sw_setf(uint8_t i2s0sclkoutensw)
{
    ASSERT_ERR((((uint32_t)i2s0sclkoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)i2s0sclkoutensw << 11));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sclk_ana_en_sw_setf(uint8_t i2s0sclkanaensw)
{
    ASSERT_ERR((((uint32_t)i2s0sclkanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)i2s0sclkanaensw << 10));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s0_sclk_pull_mode_sel_sw_setf(uint8_t i2s0sclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s0sclkpullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)i2s0sclkpullmodeselsw << 8));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s_mclk_sw_ctrl_en_setf(uint8_t i2smclkswctrlen)
{
    ASSERT_ERR((((uint32_t)i2smclkswctrlen << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)i2smclkswctrlen << 4));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s_mclk_out_en_sw_setf(uint8_t i2smclkoutensw)
{
    ASSERT_ERR((((uint32_t)i2smclkoutensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)i2smclkoutensw << 3));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s_mclk_ana_en_sw_setf(uint8_t i2smclkanaensw)
{
    ASSERT_ERR((((uint32_t)i2smclkanaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)i2smclkanaensw << 2));
}

__INLINE void apb_pad_i2s_sw_ctrl1_i2s_mclk_pull_mode_sel_sw_setf(uint8_t i2smclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2smclkpullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL1_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)i2smclkpullmodeselsw << 0));
}

/**
 * @brief PAD_I2S_SW_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28   I2S1_SDOUT_SW_CTRL_EN   0
 *     27   I2S1_SDOUT_OUT_EN_SW   0
 *     26   I2S1_SDOUT_ANA_EN_SW   0
 *  25:24   I2S1_SDOUT_PULL_MODE_SEL_SW   0x0
 *     20   I2S1_LRCLK_SW_CTRL_EN   0
 *     19   I2S1_LRCLK_OUT_EN_SW   0
 *     18   I2S1_LRCLK_ANA_EN_SW   0
 *  17:16   I2S1_LRCLK_PULL_MODE_SEL_SW   0x0
 *     12   I2S1_SCLK_SW_CTRL_EN   0
 *     11   I2S1_SCLK_OUT_EN_SW   0
 *     10   I2S1_SCLK_ANA_EN_SW   0
 *  09:08   I2S1_SCLK_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_I2S_SW_CTRL2_ADDR   0xC00120FC
#define APB_PAD_I2S_SW_CTRL2_OFFSET 0x000000FC
#define APB_PAD_I2S_SW_CTRL2_INDEX  0x0000003F
#define APB_PAD_I2S_SW_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_pad_i2s_sw_ctrl2_get(void)
{
    return REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR);
}

__INLINE void apb_pad_i2s_sw_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, value);
}

// field definitions
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_SW_CTRL_EN_BIT          ((uint32_t)0x10000000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_SW_CTRL_EN_POS          28
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_OUT_EN_SW_BIT           ((uint32_t)0x08000000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_OUT_EN_SW_POS           27
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_ANA_EN_SW_BIT           ((uint32_t)0x04000000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_ANA_EN_SW_POS           26
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x03000000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_PULL_MODE_SEL_SW_LSB    24
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_SW_CTRL_EN_BIT          ((uint32_t)0x00100000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_SW_CTRL_EN_POS          20
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_OUT_EN_SW_BIT           ((uint32_t)0x00080000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_OUT_EN_SW_POS           19
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_ANA_EN_SW_BIT           ((uint32_t)0x00040000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_ANA_EN_SW_POS           18
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00030000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_PULL_MODE_SEL_SW_LSB    16
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_SW_CTRL_EN_BIT           ((uint32_t)0x00001000)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_SW_CTRL_EN_POS           12
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_OUT_EN_SW_BIT            ((uint32_t)0x00000800)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_OUT_EN_SW_POS            11
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_ANA_EN_SW_BIT            ((uint32_t)0x00000400)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_ANA_EN_SW_POS            10
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_PULL_MODE_SEL_SW_MASK    ((uint32_t)0x00000300)
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_PULL_MODE_SEL_SW_LSB     8
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_PULL_MODE_SEL_SW_WIDTH   ((uint32_t)0x00000002)

#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_SW_CTRL_EN_RST          0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_OUT_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_ANA_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SDOUT_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_SW_CTRL_EN_RST          0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_OUT_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_ANA_EN_SW_RST           0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_LRCLK_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_SW_CTRL_EN_RST           0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_OUT_EN_SW_RST            0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_ANA_EN_SW_RST            0x0
#define APB_PAD_I2S_SW_CTRL2_I2S1_SCLK_PULL_MODE_SEL_SW_RST     0x0

__INLINE void apb_pad_i2s_sw_ctrl2_pack(uint8_t i2s1sdoutswctrlen, uint8_t i2s1sdoutoutensw, uint8_t i2s1sdoutanaensw, uint8_t i2s1sdoutpullmodeselsw, uint8_t i2s1lrclkswctrlen, uint8_t i2s1lrclkoutensw, uint8_t i2s1lrclkanaensw, uint8_t i2s1lrclkpullmodeselsw, uint8_t i2s1sclkswctrlen, uint8_t i2s1sclkoutensw, uint8_t i2s1sclkanaensw, uint8_t i2s1sclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sdoutoutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sdoutanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sdoutpullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1lrclkswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1lrclkoutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1lrclkanaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1lrclkpullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclkswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclkoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclkanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclkpullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR,  ((uint32_t)i2s1sdoutswctrlen << 28) | ((uint32_t)i2s1sdoutoutensw << 27) | ((uint32_t)i2s1sdoutanaensw << 26) | ((uint32_t)i2s1sdoutpullmodeselsw << 24) | ((uint32_t)i2s1lrclkswctrlen << 20) | ((uint32_t)i2s1lrclkoutensw << 19) | ((uint32_t)i2s1lrclkanaensw << 18) | ((uint32_t)i2s1lrclkpullmodeselsw << 16) | ((uint32_t)i2s1sclkswctrlen << 12) | ((uint32_t)i2s1sclkoutensw << 11) | ((uint32_t)i2s1sclkanaensw << 10) | ((uint32_t)i2s1sclkpullmodeselsw << 8));
}

__INLINE void apb_pad_i2s_sw_ctrl2_unpack(uint8_t* i2s1sdoutswctrlen, uint8_t* i2s1sdoutoutensw, uint8_t* i2s1sdoutanaensw, uint8_t* i2s1sdoutpullmodeselsw, uint8_t* i2s1lrclkswctrlen, uint8_t* i2s1lrclkoutensw, uint8_t* i2s1lrclkanaensw, uint8_t* i2s1lrclkpullmodeselsw, uint8_t* i2s1sclkswctrlen, uint8_t* i2s1sclkoutensw, uint8_t* i2s1sclkanaensw, uint8_t* i2s1sclkpullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR);
    *i2s1sdoutswctrlen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *i2s1sdoutoutensw = (localVal & ((uint32_t)0x08000000)) >> 27;
    *i2s1sdoutanaensw = (localVal & ((uint32_t)0x04000000)) >> 26;
    *i2s1sdoutpullmodeselsw = (localVal & ((uint32_t)0x03000000)) >> 24;
    *i2s1lrclkswctrlen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *i2s1lrclkoutensw = (localVal & ((uint32_t)0x00080000)) >> 19;
    *i2s1lrclkanaensw = (localVal & ((uint32_t)0x00040000)) >> 18;
    *i2s1lrclkpullmodeselsw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *i2s1sclkswctrlen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *i2s1sclkoutensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *i2s1sclkanaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2s1sclkpullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sdout_sw_ctrl_en_setf(uint8_t i2s1sdoutswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutswctrlen << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)i2s1sdoutswctrlen << 28));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sdout_out_en_sw_setf(uint8_t i2s1sdoutoutensw)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutoutensw << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)i2s1sdoutoutensw << 27));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sdout_ana_en_sw_setf(uint8_t i2s1sdoutanaensw)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutanaensw << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)i2s1sdoutanaensw << 26));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sdout_pull_mode_sel_sw_setf(uint8_t i2s1sdoutpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutpullmodeselsw << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)i2s1sdoutpullmodeselsw << 24));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_lrclk_sw_ctrl_en_setf(uint8_t i2s1lrclkswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s1lrclkswctrlen << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)i2s1lrclkswctrlen << 20));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_lrclk_out_en_sw_setf(uint8_t i2s1lrclkoutensw)
{
    ASSERT_ERR((((uint32_t)i2s1lrclkoutensw << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)i2s1lrclkoutensw << 19));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_lrclk_ana_en_sw_setf(uint8_t i2s1lrclkanaensw)
{
    ASSERT_ERR((((uint32_t)i2s1lrclkanaensw << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)i2s1lrclkanaensw << 18));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_lrclk_pull_mode_sel_sw_setf(uint8_t i2s1lrclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s1lrclkpullmodeselsw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)i2s1lrclkpullmodeselsw << 16));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sclk_sw_ctrl_en_setf(uint8_t i2s1sclkswctrlen)
{
    ASSERT_ERR((((uint32_t)i2s1sclkswctrlen << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)i2s1sclkswctrlen << 12));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sclk_out_en_sw_setf(uint8_t i2s1sclkoutensw)
{
    ASSERT_ERR((((uint32_t)i2s1sclkoutensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)i2s1sclkoutensw << 11));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sclk_ana_en_sw_setf(uint8_t i2s1sclkanaensw)
{
    ASSERT_ERR((((uint32_t)i2s1sclkanaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)i2s1sclkanaensw << 10));
}

__INLINE void apb_pad_i2s_sw_ctrl2_i2s1_sclk_pull_mode_sel_sw_setf(uint8_t i2s1sclkpullmodeselsw)
{
    ASSERT_ERR((((uint32_t)i2s1sclkpullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_I2S_SW_CTRL2_ADDR, (REG_PL_RD(APB_PAD_I2S_SW_CTRL2_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)i2s1sclkpullmodeselsw << 8));
}

/**
 * @brief PAD_GPIO_FUNC_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:28       GPIO8_FUNC_SEL   0x0
 *  27:24       GPIO7_FUNC_SEL   0x0
 *  23:20       GPIO6_FUNC_SEL   0x0
 *  19:16       GPIO5_FUNC_SEL   0x0
 *  15:12       GPIO4_FUNC_SEL   0x0
 *  11:08       GPIO3_FUNC_SEL   0x0
 *  07:04       GPIO2_FUNC_SEL   0x0
 *  03:00       GPIO1_FUNC_SEL   0x0
 * </pre>
 */
#define APB_PAD_GPIO_FUNC_CFG0_ADDR   0xC0012100
#define APB_PAD_GPIO_FUNC_CFG0_OFFSET 0x00000100
#define APB_PAD_GPIO_FUNC_CFG0_INDEX  0x00000040
#define APB_PAD_GPIO_FUNC_CFG0_RESET  0x00000000

__INLINE uint32_t apb_pad_gpio_func_cfg0_get(void)
{
    return REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
}

__INLINE void apb_pad_gpio_func_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, value);
}

// field definitions
#define APB_PAD_GPIO_FUNC_CFG0_GPIO8_FUNC_SEL_MASK   ((uint32_t)0xF0000000)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO8_FUNC_SEL_LSB    28
#define APB_PAD_GPIO_FUNC_CFG0_GPIO8_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO7_FUNC_SEL_MASK   ((uint32_t)0x0F000000)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO7_FUNC_SEL_LSB    24
#define APB_PAD_GPIO_FUNC_CFG0_GPIO7_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO6_FUNC_SEL_MASK   ((uint32_t)0x00F00000)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO6_FUNC_SEL_LSB    20
#define APB_PAD_GPIO_FUNC_CFG0_GPIO6_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO5_FUNC_SEL_MASK   ((uint32_t)0x000F0000)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO5_FUNC_SEL_LSB    16
#define APB_PAD_GPIO_FUNC_CFG0_GPIO5_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO4_FUNC_SEL_MASK   ((uint32_t)0x0000F000)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO4_FUNC_SEL_LSB    12
#define APB_PAD_GPIO_FUNC_CFG0_GPIO4_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO3_FUNC_SEL_MASK   ((uint32_t)0x00000F00)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO3_FUNC_SEL_LSB    8
#define APB_PAD_GPIO_FUNC_CFG0_GPIO3_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO2_FUNC_SEL_MASK   ((uint32_t)0x000000F0)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO2_FUNC_SEL_LSB    4
#define APB_PAD_GPIO_FUNC_CFG0_GPIO2_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO1_FUNC_SEL_MASK   ((uint32_t)0x0000000F)
#define APB_PAD_GPIO_FUNC_CFG0_GPIO1_FUNC_SEL_LSB    0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO1_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)

#define APB_PAD_GPIO_FUNC_CFG0_GPIO8_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO7_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO6_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO5_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO4_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO3_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO2_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG0_GPIO1_FUNC_SEL_RST    0x0

__INLINE void apb_pad_gpio_func_cfg0_pack(uint8_t gpio8funcsel, uint8_t gpio7funcsel, uint8_t gpio6funcsel, uint8_t gpio5funcsel, uint8_t gpio4funcsel, uint8_t gpio3funcsel, uint8_t gpio2funcsel, uint8_t gpio1funcsel)
{
    ASSERT_ERR((((uint32_t)gpio8funcsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio7funcsel << 24) & ~((uint32_t)0x0F000000)) == 0);
    ASSERT_ERR((((uint32_t)gpio6funcsel << 20) & ~((uint32_t)0x00F00000)) == 0);
    ASSERT_ERR((((uint32_t)gpio5funcsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)gpio4funcsel << 12) & ~((uint32_t)0x0000F000)) == 0);
    ASSERT_ERR((((uint32_t)gpio3funcsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)gpio2funcsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)gpio1funcsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR,  ((uint32_t)gpio8funcsel << 28) | ((uint32_t)gpio7funcsel << 24) | ((uint32_t)gpio6funcsel << 20) | ((uint32_t)gpio5funcsel << 16) | ((uint32_t)gpio4funcsel << 12) | ((uint32_t)gpio3funcsel << 8) | ((uint32_t)gpio2funcsel << 4) | ((uint32_t)gpio1funcsel << 0));
}

__INLINE void apb_pad_gpio_func_cfg0_unpack(uint8_t* gpio8funcsel, uint8_t* gpio7funcsel, uint8_t* gpio6funcsel, uint8_t* gpio5funcsel, uint8_t* gpio4funcsel, uint8_t* gpio3funcsel, uint8_t* gpio2funcsel, uint8_t* gpio1funcsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    *gpio8funcsel = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *gpio7funcsel = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *gpio6funcsel = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *gpio5funcsel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *gpio4funcsel = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *gpio3funcsel = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *gpio2funcsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *gpio1funcsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio8_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio8_func_sel_setf(uint8_t gpio8funcsel)
{
    ASSERT_ERR((((uint32_t)gpio8funcsel << 28) & ~((uint32_t)0xF0000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)gpio8funcsel << 28));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio7_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio7_func_sel_setf(uint8_t gpio7funcsel)
{
    ASSERT_ERR((((uint32_t)gpio7funcsel << 24) & ~((uint32_t)0x0F000000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)gpio7funcsel << 24));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio6_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio6_func_sel_setf(uint8_t gpio6funcsel)
{
    ASSERT_ERR((((uint32_t)gpio6funcsel << 20) & ~((uint32_t)0x00F00000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)gpio6funcsel << 20));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio5_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio5_func_sel_setf(uint8_t gpio5funcsel)
{
    ASSERT_ERR((((uint32_t)gpio5funcsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)gpio5funcsel << 16));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio4_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio4_func_sel_setf(uint8_t gpio4funcsel)
{
    ASSERT_ERR((((uint32_t)gpio4funcsel << 12) & ~((uint32_t)0x0000F000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)gpio4funcsel << 12));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio3_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio3_func_sel_setf(uint8_t gpio3funcsel)
{
    ASSERT_ERR((((uint32_t)gpio3funcsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)gpio3funcsel << 8));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio2_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio2_func_sel_setf(uint8_t gpio2funcsel)
{
    ASSERT_ERR((((uint32_t)gpio2funcsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)gpio2funcsel << 4));
}

__INLINE uint8_t apb_pad_gpio_func_cfg0_gpio1_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_pad_gpio_func_cfg0_gpio1_func_sel_setf(uint8_t gpio1funcsel)
{
    ASSERT_ERR((((uint32_t)gpio1funcsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)gpio1funcsel << 0));
}

/**
 * @brief PAD_SPI_FUNC_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:20     SPI_IO3_FUNC_SEL   0x0
 *  19:16     SPI_IO2_FUNC_SEL   0x0
 *  15:12   SPI_IO1_MISO_FUNC_SEL   0x0
 *  11:08   SPI_IO0_MOSI_FUNC_SEL   0x0
 *  07:04     SPI_NSS_FUNC_SEL   0x0
 *  03:00     SPI_CLK_FUNC_SEL   0x0
 * </pre>
 */
#define APB_PAD_SPI_FUNC_CFG_ADDR   0xC0012104
#define APB_PAD_SPI_FUNC_CFG_OFFSET 0x00000104
#define APB_PAD_SPI_FUNC_CFG_INDEX  0x00000041
#define APB_PAD_SPI_FUNC_CFG_RESET  0x00000000

__INLINE uint32_t apb_pad_spi_func_cfg_get(void)
{
    return REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
}

__INLINE void apb_pad_spi_func_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, value);
}

// field definitions
#define APB_PAD_SPI_FUNC_CFG_SPI_IO3_FUNC_SEL_MASK        ((uint32_t)0x00F00000)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO3_FUNC_SEL_LSB         20
#define APB_PAD_SPI_FUNC_CFG_SPI_IO3_FUNC_SEL_WIDTH       ((uint32_t)0x00000004)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO2_FUNC_SEL_MASK        ((uint32_t)0x000F0000)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO2_FUNC_SEL_LSB         16
#define APB_PAD_SPI_FUNC_CFG_SPI_IO2_FUNC_SEL_WIDTH       ((uint32_t)0x00000004)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO1_MISO_FUNC_SEL_MASK   ((uint32_t)0x0000F000)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO1_MISO_FUNC_SEL_LSB    12
#define APB_PAD_SPI_FUNC_CFG_SPI_IO1_MISO_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO0_MOSI_FUNC_SEL_MASK   ((uint32_t)0x00000F00)
#define APB_PAD_SPI_FUNC_CFG_SPI_IO0_MOSI_FUNC_SEL_LSB    8
#define APB_PAD_SPI_FUNC_CFG_SPI_IO0_MOSI_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_SPI_FUNC_CFG_SPI_NSS_FUNC_SEL_MASK        ((uint32_t)0x000000F0)
#define APB_PAD_SPI_FUNC_CFG_SPI_NSS_FUNC_SEL_LSB         4
#define APB_PAD_SPI_FUNC_CFG_SPI_NSS_FUNC_SEL_WIDTH       ((uint32_t)0x00000004)
#define APB_PAD_SPI_FUNC_CFG_SPI_CLK_FUNC_SEL_MASK        ((uint32_t)0x0000000F)
#define APB_PAD_SPI_FUNC_CFG_SPI_CLK_FUNC_SEL_LSB         0
#define APB_PAD_SPI_FUNC_CFG_SPI_CLK_FUNC_SEL_WIDTH       ((uint32_t)0x00000004)

#define APB_PAD_SPI_FUNC_CFG_SPI_IO3_FUNC_SEL_RST         0x0
#define APB_PAD_SPI_FUNC_CFG_SPI_IO2_FUNC_SEL_RST         0x0
#define APB_PAD_SPI_FUNC_CFG_SPI_IO1_MISO_FUNC_SEL_RST    0x0
#define APB_PAD_SPI_FUNC_CFG_SPI_IO0_MOSI_FUNC_SEL_RST    0x0
#define APB_PAD_SPI_FUNC_CFG_SPI_NSS_FUNC_SEL_RST         0x0
#define APB_PAD_SPI_FUNC_CFG_SPI_CLK_FUNC_SEL_RST         0x0

__INLINE void apb_pad_spi_func_cfg_pack(uint8_t spiio3funcsel, uint8_t spiio2funcsel, uint8_t spiio1misofuncsel, uint8_t spiio0mosifuncsel, uint8_t spinssfuncsel, uint8_t spiclkfuncsel)
{
    ASSERT_ERR((((uint32_t)spiio3funcsel << 20) & ~((uint32_t)0x00F00000)) == 0);
    ASSERT_ERR((((uint32_t)spiio2funcsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)spiio1misofuncsel << 12) & ~((uint32_t)0x0000F000)) == 0);
    ASSERT_ERR((((uint32_t)spiio0mosifuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)spinssfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)spiclkfuncsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR,  ((uint32_t)spiio3funcsel << 20) | ((uint32_t)spiio2funcsel << 16) | ((uint32_t)spiio1misofuncsel << 12) | ((uint32_t)spiio0mosifuncsel << 8) | ((uint32_t)spinssfuncsel << 4) | ((uint32_t)spiclkfuncsel << 0));
}

__INLINE void apb_pad_spi_func_cfg_unpack(uint8_t* spiio3funcsel, uint8_t* spiio2funcsel, uint8_t* spiio1misofuncsel, uint8_t* spiio0mosifuncsel, uint8_t* spinssfuncsel, uint8_t* spiclkfuncsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    *spiio3funcsel = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *spiio2funcsel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *spiio1misofuncsel = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *spiio0mosifuncsel = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *spinssfuncsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *spiclkfuncsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_io3_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

__INLINE void apb_pad_spi_func_cfg_spi_io3_func_sel_setf(uint8_t spiio3funcsel)
{
    ASSERT_ERR((((uint32_t)spiio3funcsel << 20) & ~((uint32_t)0x00F00000)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)spiio3funcsel << 20));
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_io2_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_pad_spi_func_cfg_spi_io2_func_sel_setf(uint8_t spiio2funcsel)
{
    ASSERT_ERR((((uint32_t)spiio2funcsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)spiio2funcsel << 16));
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_io1_miso_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}

__INLINE void apb_pad_spi_func_cfg_spi_io1_miso_func_sel_setf(uint8_t spiio1misofuncsel)
{
    ASSERT_ERR((((uint32_t)spiio1misofuncsel << 12) & ~((uint32_t)0x0000F000)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)spiio1misofuncsel << 12));
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_io0_mosi_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void apb_pad_spi_func_cfg_spi_io0_mosi_func_sel_setf(uint8_t spiio0mosifuncsel)
{
    ASSERT_ERR((((uint32_t)spiio0mosifuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)spiio0mosifuncsel << 8));
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_nss_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_pad_spi_func_cfg_spi_nss_func_sel_setf(uint8_t spinssfuncsel)
{
    ASSERT_ERR((((uint32_t)spinssfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)spinssfuncsel << 4));
}

__INLINE uint8_t apb_pad_spi_func_cfg_spi_clk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_pad_spi_func_cfg_spi_clk_func_sel_setf(uint8_t spiclkfuncsel)
{
    ASSERT_ERR((((uint32_t)spiclkfuncsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_SPI_FUNC_CFG_ADDR, (REG_PL_RD(APB_PAD_SPI_FUNC_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)spiclkfuncsel << 0));
}

/**
 * @brief PAD_I2S_FUNC_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  19:16   I2S0_SDOUT_FUNC_SEL   0x0
 *  11:08   I2S0_LRCLK_FUNC_SEL   0x0
 *  07:04   I2S0_SCLK_FUNC_SEL   0x0
 *  03:00    I2S_MCLK_FUNC_SEL   0x0
 * </pre>
 */
#define APB_PAD_I2S_FUNC_CFG0_ADDR   0xC0012108
#define APB_PAD_I2S_FUNC_CFG0_OFFSET 0x00000108
#define APB_PAD_I2S_FUNC_CFG0_INDEX  0x00000042
#define APB_PAD_I2S_FUNC_CFG0_RESET  0x00000000

__INLINE uint32_t apb_pad_i2s_func_cfg0_get(void)
{
    return REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
}

__INLINE void apb_pad_i2s_func_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR, value);
}

// field definitions
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SDOUT_FUNC_SEL_MASK   ((uint32_t)0x000F0000)
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SDOUT_FUNC_SEL_LSB    16
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SDOUT_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_I2S_FUNC_CFG0_I2S0_LRCLK_FUNC_SEL_MASK   ((uint32_t)0x00000F00)
#define APB_PAD_I2S_FUNC_CFG0_I2S0_LRCLK_FUNC_SEL_LSB    8
#define APB_PAD_I2S_FUNC_CFG0_I2S0_LRCLK_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SCLK_FUNC_SEL_MASK    ((uint32_t)0x000000F0)
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SCLK_FUNC_SEL_LSB     4
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SCLK_FUNC_SEL_WIDTH   ((uint32_t)0x00000004)
#define APB_PAD_I2S_FUNC_CFG0_I2S_MCLK_FUNC_SEL_MASK     ((uint32_t)0x0000000F)
#define APB_PAD_I2S_FUNC_CFG0_I2S_MCLK_FUNC_SEL_LSB      0
#define APB_PAD_I2S_FUNC_CFG0_I2S_MCLK_FUNC_SEL_WIDTH    ((uint32_t)0x00000004)

#define APB_PAD_I2S_FUNC_CFG0_I2S0_SDOUT_FUNC_SEL_RST    0x0
#define APB_PAD_I2S_FUNC_CFG0_I2S0_LRCLK_FUNC_SEL_RST    0x0
#define APB_PAD_I2S_FUNC_CFG0_I2S0_SCLK_FUNC_SEL_RST     0x0
#define APB_PAD_I2S_FUNC_CFG0_I2S_MCLK_FUNC_SEL_RST      0x0

__INLINE void apb_pad_i2s_func_cfg0_pack(uint8_t i2s0sdoutfuncsel, uint8_t i2s0lrclkfuncsel, uint8_t i2s0sclkfuncsel, uint8_t i2smclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutfuncsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)i2s0lrclkfuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclkfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)i2smclkfuncsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR,  ((uint32_t)i2s0sdoutfuncsel << 16) | ((uint32_t)i2s0lrclkfuncsel << 8) | ((uint32_t)i2s0sclkfuncsel << 4) | ((uint32_t)i2smclkfuncsel << 0));
}

__INLINE void apb_pad_i2s_func_cfg0_unpack(uint8_t* i2s0sdoutfuncsel, uint8_t* i2s0lrclkfuncsel, uint8_t* i2s0sclkfuncsel, uint8_t* i2smclkfuncsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
    *i2s0sdoutfuncsel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *i2s0lrclkfuncsel = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *i2s0sclkfuncsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *i2smclkfuncsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_pad_i2s_func_cfg0_i2s0_sdout_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_pad_i2s_func_cfg0_i2s0_sdout_func_sel_setf(uint8_t i2s0sdoutfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s0sdoutfuncsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)i2s0sdoutfuncsel << 16));
}

__INLINE uint8_t apb_pad_i2s_func_cfg0_i2s0_lrclk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void apb_pad_i2s_func_cfg0_i2s0_lrclk_func_sel_setf(uint8_t i2s0lrclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s0lrclkfuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)i2s0lrclkfuncsel << 8));
}

__INLINE uint8_t apb_pad_i2s_func_cfg0_i2s0_sclk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_pad_i2s_func_cfg0_i2s0_sclk_func_sel_setf(uint8_t i2s0sclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s0sclkfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)i2s0sclkfuncsel << 4));
}

__INLINE uint8_t apb_pad_i2s_func_cfg0_i2s_mclk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_pad_i2s_func_cfg0_i2s_mclk_func_sel_setf(uint8_t i2smclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2smclkfuncsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG0_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)i2smclkfuncsel << 0));
}

/**
 * @brief PAD_INPUT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     24        PAD_GPIO10_IN   0
 *     23         PAD_GPIO9_IN   0
 *     22     PAD_I2S1_SCLK_IN   0
 *     21    PAD_I2S1_LRCLK_IN   0
 *     20     PAD_I2S1_SDIN_IN   0
 *     19    PAD_I2S1_SDOUT_IN   0
 *     18       PAD_SPI_CLK_IN   0
 *     17       PAD_SPI_NSS_IN   0
 *     16   PAD_SPI_IO0_MOSI_IN   0
 *     15   PAD_SPI_IO1_MISO_IN   0
 *     14       PAD_SPI_IO2_IN   0
 *     13       PAD_SPI_IO3_IN   0
 *     12      PAD_I2S_MCLK_IN   0
 *     11     PAD_I2S0_SCLK_IN   0
 *     10    PAD_I2S0_LRCLK_IN   0
 *     09     PAD_I2S0_SDIN_IN   0
 *     08    PAD_I2S0_SDOUT_IN   0
 *     07         PAD_GPIO1_IN   0
 *     06         PAD_GPIO2_IN   0
 *     05         PAD_GPIO3_IN   0
 *     04         PAD_GPIO4_IN   0
 *     03         PAD_GPIO5_IN   0
 *     02         PAD_GPIO6_IN   0
 *     01         PAD_GPIO7_IN   0
 *     00         PAD_GPIO8_IN   0
 * </pre>
 */
#define APB_PAD_INPUT_STATUS_ADDR   0xC001210C
#define APB_PAD_INPUT_STATUS_OFFSET 0x0000010C
#define APB_PAD_INPUT_STATUS_INDEX  0x00000043
#define APB_PAD_INPUT_STATUS_RESET  0x00000000

__INLINE uint32_t apb_pad_input_status_get(void)
{
    return REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
}

__INLINE void apb_pad_input_status_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR, value);
}

// field definitions
#define APB_PAD_INPUT_STATUS_PAD_GPIO10_IN_BIT          ((uint32_t)0x01000000)
#define APB_PAD_INPUT_STATUS_PAD_GPIO10_IN_POS          24
#define APB_PAD_INPUT_STATUS_PAD_GPIO9_IN_BIT           ((uint32_t)0x00800000)
#define APB_PAD_INPUT_STATUS_PAD_GPIO9_IN_POS           23
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SCLK_IN_BIT       ((uint32_t)0x00400000)
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SCLK_IN_POS       22
#define APB_PAD_INPUT_STATUS_PAD_I2S1_LRCLK_IN_BIT      ((uint32_t)0x00200000)
#define APB_PAD_INPUT_STATUS_PAD_I2S1_LRCLK_IN_POS      21
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDIN_IN_BIT       ((uint32_t)0x00100000)
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDIN_IN_POS       20
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDOUT_IN_BIT      ((uint32_t)0x00080000)
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDOUT_IN_POS      19
#define APB_PAD_INPUT_STATUS_PAD_SPI_CLK_IN_BIT         ((uint32_t)0x00040000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_CLK_IN_POS         18
#define APB_PAD_INPUT_STATUS_PAD_SPI_NSS_IN_BIT         ((uint32_t)0x00020000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_NSS_IN_POS         17
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO0_MOSI_IN_BIT    ((uint32_t)0x00010000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO0_MOSI_IN_POS    16
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO1_MISO_IN_BIT    ((uint32_t)0x00008000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO1_MISO_IN_POS    15
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO2_IN_BIT         ((uint32_t)0x00004000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO2_IN_POS         14
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO3_IN_BIT         ((uint32_t)0x00002000)
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO3_IN_POS         13
#define APB_PAD_INPUT_STATUS_PAD_I2S_MCLK_IN_BIT        ((uint32_t)0x00001000)
#define APB_PAD_INPUT_STATUS_PAD_I2S_MCLK_IN_POS        12
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SCLK_IN_BIT       ((uint32_t)0x00000800)
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SCLK_IN_POS       11
#define APB_PAD_INPUT_STATUS_PAD_I2S0_LRCLK_IN_BIT      ((uint32_t)0x00000400)
#define APB_PAD_INPUT_STATUS_PAD_I2S0_LRCLK_IN_POS      10
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDIN_IN_BIT       ((uint32_t)0x00000200)
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDIN_IN_POS       9
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDOUT_IN_BIT      ((uint32_t)0x00000100)
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDOUT_IN_POS      8
#define APB_PAD_INPUT_STATUS_PAD_GPIO1_IN_BIT           ((uint32_t)0x00000080)
#define APB_PAD_INPUT_STATUS_PAD_GPIO1_IN_POS           7
#define APB_PAD_INPUT_STATUS_PAD_GPIO2_IN_BIT           ((uint32_t)0x00000040)
#define APB_PAD_INPUT_STATUS_PAD_GPIO2_IN_POS           6
#define APB_PAD_INPUT_STATUS_PAD_GPIO3_IN_BIT           ((uint32_t)0x00000020)
#define APB_PAD_INPUT_STATUS_PAD_GPIO3_IN_POS           5
#define APB_PAD_INPUT_STATUS_PAD_GPIO4_IN_BIT           ((uint32_t)0x00000010)
#define APB_PAD_INPUT_STATUS_PAD_GPIO4_IN_POS           4
#define APB_PAD_INPUT_STATUS_PAD_GPIO5_IN_BIT           ((uint32_t)0x00000008)
#define APB_PAD_INPUT_STATUS_PAD_GPIO5_IN_POS           3
#define APB_PAD_INPUT_STATUS_PAD_GPIO6_IN_BIT           ((uint32_t)0x00000004)
#define APB_PAD_INPUT_STATUS_PAD_GPIO6_IN_POS           2
#define APB_PAD_INPUT_STATUS_PAD_GPIO7_IN_BIT           ((uint32_t)0x00000002)
#define APB_PAD_INPUT_STATUS_PAD_GPIO7_IN_POS           1
#define APB_PAD_INPUT_STATUS_PAD_GPIO8_IN_BIT           ((uint32_t)0x00000001)
#define APB_PAD_INPUT_STATUS_PAD_GPIO8_IN_POS           0

#define APB_PAD_INPUT_STATUS_PAD_GPIO10_IN_RST          0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO9_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SCLK_IN_RST       0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S1_LRCLK_IN_RST      0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDIN_IN_RST       0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S1_SDOUT_IN_RST      0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_CLK_IN_RST         0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_NSS_IN_RST         0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO0_MOSI_IN_RST    0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO1_MISO_IN_RST    0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO2_IN_RST         0x0
#define APB_PAD_INPUT_STATUS_PAD_SPI_IO3_IN_RST         0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S_MCLK_IN_RST        0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SCLK_IN_RST       0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S0_LRCLK_IN_RST      0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDIN_IN_RST       0x0
#define APB_PAD_INPUT_STATUS_PAD_I2S0_SDOUT_IN_RST      0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO1_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO2_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO3_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO4_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO5_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO6_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO7_IN_RST           0x0
#define APB_PAD_INPUT_STATUS_PAD_GPIO8_IN_RST           0x0

__INLINE void apb_pad_input_status_pack(uint8_t padi2s1sclkin, uint8_t padi2s1lrclkin, uint8_t padi2s1sdinin, uint8_t padi2s1sdoutin)
{
    ASSERT_ERR((((uint32_t)padi2s1sclkin << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)padi2s1lrclkin << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)padi2s1sdinin << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)padi2s1sdoutin << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR,  ((uint32_t)padi2s1sclkin << 22) | ((uint32_t)padi2s1lrclkin << 21) | ((uint32_t)padi2s1sdinin << 20) | ((uint32_t)padi2s1sdoutin << 19));
}

__INLINE void apb_pad_input_status_unpack(uint8_t* padgpio10in, uint8_t* padgpio9in, uint8_t* padi2s1sclkin, uint8_t* padi2s1lrclkin, uint8_t* padi2s1sdinin, uint8_t* padi2s1sdoutin, uint8_t* padspiclkin, uint8_t* padspinssin, uint8_t* padspiio0mosiin, uint8_t* padspiio1misoin, uint8_t* padspiio2in, uint8_t* padspiio3in, uint8_t* padi2smclkin, uint8_t* padi2s0sclkin, uint8_t* padi2s0lrclkin, uint8_t* padi2s0sdinin, uint8_t* padi2s0sdoutin, uint8_t* padgpio1in, uint8_t* padgpio2in, uint8_t* padgpio3in, uint8_t* padgpio4in, uint8_t* padgpio5in, uint8_t* padgpio6in, uint8_t* padgpio7in, uint8_t* padgpio8in)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    *padgpio10in = (localVal & ((uint32_t)0x01000000)) >> 24;
    *padgpio9in = (localVal & ((uint32_t)0x00800000)) >> 23;
    *padi2s1sclkin = (localVal & ((uint32_t)0x00400000)) >> 22;
    *padi2s1lrclkin = (localVal & ((uint32_t)0x00200000)) >> 21;
    *padi2s1sdinin = (localVal & ((uint32_t)0x00100000)) >> 20;
    *padi2s1sdoutin = (localVal & ((uint32_t)0x00080000)) >> 19;
    *padspiclkin = (localVal & ((uint32_t)0x00040000)) >> 18;
    *padspinssin = (localVal & ((uint32_t)0x00020000)) >> 17;
    *padspiio0mosiin = (localVal & ((uint32_t)0x00010000)) >> 16;
    *padspiio1misoin = (localVal & ((uint32_t)0x00008000)) >> 15;
    *padspiio2in = (localVal & ((uint32_t)0x00004000)) >> 14;
    *padspiio3in = (localVal & ((uint32_t)0x00002000)) >> 13;
    *padi2smclkin = (localVal & ((uint32_t)0x00001000)) >> 12;
    *padi2s0sclkin = (localVal & ((uint32_t)0x00000800)) >> 11;
    *padi2s0lrclkin = (localVal & ((uint32_t)0x00000400)) >> 10;
    *padi2s0sdinin = (localVal & ((uint32_t)0x00000200)) >> 9;
    *padi2s0sdoutin = (localVal & ((uint32_t)0x00000100)) >> 8;
    *padgpio1in = (localVal & ((uint32_t)0x00000080)) >> 7;
    *padgpio2in = (localVal & ((uint32_t)0x00000040)) >> 6;
    *padgpio3in = (localVal & ((uint32_t)0x00000020)) >> 5;
    *padgpio4in = (localVal & ((uint32_t)0x00000010)) >> 4;
    *padgpio5in = (localVal & ((uint32_t)0x00000008)) >> 3;
    *padgpio6in = (localVal & ((uint32_t)0x00000004)) >> 2;
    *padgpio7in = (localVal & ((uint32_t)0x00000002)) >> 1;
    *padgpio8in = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_pad_input_status_pad_gpio10_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio9_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s1_sclk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_pad_input_status_pad_i2s1_sclk_in_setf(uint8_t padi2s1sclkin)
{
    ASSERT_ERR((((uint32_t)padi2s1sclkin << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR, (REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)padi2s1sclkin << 22));
}

__INLINE uint8_t apb_pad_input_status_pad_i2s1_lrclk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_pad_input_status_pad_i2s1_lrclk_in_setf(uint8_t padi2s1lrclkin)
{
    ASSERT_ERR((((uint32_t)padi2s1lrclkin << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR, (REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)padi2s1lrclkin << 21));
}

__INLINE uint8_t apb_pad_input_status_pad_i2s1_sdin_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_pad_input_status_pad_i2s1_sdin_in_setf(uint8_t padi2s1sdinin)
{
    ASSERT_ERR((((uint32_t)padi2s1sdinin << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR, (REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)padi2s1sdinin << 20));
}

__INLINE uint8_t apb_pad_input_status_pad_i2s1_sdout_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_pad_input_status_pad_i2s1_sdout_in_setf(uint8_t padi2s1sdoutin)
{
    ASSERT_ERR((((uint32_t)padi2s1sdoutin << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_PAD_INPUT_STATUS_ADDR, (REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)padi2s1sdoutin << 19));
}

__INLINE uint8_t apb_pad_input_status_pad_spi_clk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t apb_pad_input_status_pad_spi_nss_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE uint8_t apb_pad_input_status_pad_spi_io0_mosi_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE uint8_t apb_pad_input_status_pad_spi_io1_miso_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE uint8_t apb_pad_input_status_pad_spi_io2_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE uint8_t apb_pad_input_status_pad_spi_io3_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s_mclk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s0_sclk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s0_lrclk_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s0_sdin_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t apb_pad_input_status_pad_i2s0_sdout_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio1_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio2_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio3_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio4_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio5_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio6_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio7_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_pad_input_status_pad_gpio8_in_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_INPUT_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief PAD_CTRL_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     29         gpio7_out_en   0
 *     28         gpio7_ana_en   0
 *  27:26   gpio7_pull_mode_sel   0x1
 *     25         gpio6_out_en   0
 *     24         gpio6_ana_en   0
 *  23:22   gpio6_pull_mode_sel   0x1
 *     21         gpio5_out_en   0
 *     20         gpio5_ana_en   0
 *  19:18   gpio5_pull_mode_sel   0x1
 *     17         gpio4_out_en   0
 *     16         gpio4_ana_en   0
 *  15:14   gpio4_pull_mode_sel   0x1
 *     13         gpio3_out_en   0
 *     12         gpio3_ana_en   0
 *  11:10   gpio3_pull_mode_sel   0x1
 *     09        gpio2_spi_iic   0
 *     08         gpio2_out_en   0
 *     07         gpio2_ana_en   0
 *  06:05   gpio2_pull_mode_sel   0x2
 *     04        gpio1_spi_iic   0
 *     03         gpio1_out_en   0
 *     02         gpio1_ana_en   0
 *  01:00   gpio1_pull_mode_sel   0x2
 * </pre>
 */
#define APB_PAD_CTRL_STATUS0_ADDR   0xC0012110
#define APB_PAD_CTRL_STATUS0_OFFSET 0x00000110
#define APB_PAD_CTRL_STATUS0_INDEX  0x00000044
#define APB_PAD_CTRL_STATUS0_RESET  0x04444442

__INLINE uint32_t apb_pad_ctrl_status0_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
}

__INLINE void apb_pad_ctrl_status0_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_STATUS0_ADDR, value);
}

// field definitions
#define APB_PAD_CTRL_STATUS0_GPIO_7_OUT_EN_BIT           ((uint32_t)0x20000000)
#define APB_PAD_CTRL_STATUS0_GPIO_7_OUT_EN_POS           29
#define APB_PAD_CTRL_STATUS0_GPIO_7_ANA_EN_BIT           ((uint32_t)0x10000000)
#define APB_PAD_CTRL_STATUS0_GPIO_7_ANA_EN_POS           28
#define APB_PAD_CTRL_STATUS0_GPIO_7_PULL_MODE_SEL_MASK   ((uint32_t)0x0C000000)
#define APB_PAD_CTRL_STATUS0_GPIO_7_PULL_MODE_SEL_LSB    26
#define APB_PAD_CTRL_STATUS0_GPIO_7_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_6_OUT_EN_BIT           ((uint32_t)0x02000000)
#define APB_PAD_CTRL_STATUS0_GPIO_6_OUT_EN_POS           25
#define APB_PAD_CTRL_STATUS0_GPIO_6_ANA_EN_BIT           ((uint32_t)0x01000000)
#define APB_PAD_CTRL_STATUS0_GPIO_6_ANA_EN_POS           24
#define APB_PAD_CTRL_STATUS0_GPIO_6_PULL_MODE_SEL_MASK   ((uint32_t)0x00C00000)
#define APB_PAD_CTRL_STATUS0_GPIO_6_PULL_MODE_SEL_LSB    22
#define APB_PAD_CTRL_STATUS0_GPIO_6_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_5_OUT_EN_BIT           ((uint32_t)0x00200000)
#define APB_PAD_CTRL_STATUS0_GPIO_5_OUT_EN_POS           21
#define APB_PAD_CTRL_STATUS0_GPIO_5_ANA_EN_BIT           ((uint32_t)0x00100000)
#define APB_PAD_CTRL_STATUS0_GPIO_5_ANA_EN_POS           20
#define APB_PAD_CTRL_STATUS0_GPIO_5_PULL_MODE_SEL_MASK   ((uint32_t)0x000C0000)
#define APB_PAD_CTRL_STATUS0_GPIO_5_PULL_MODE_SEL_LSB    18
#define APB_PAD_CTRL_STATUS0_GPIO_5_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_4_OUT_EN_BIT           ((uint32_t)0x00020000)
#define APB_PAD_CTRL_STATUS0_GPIO_4_OUT_EN_POS           17
#define APB_PAD_CTRL_STATUS0_GPIO_4_ANA_EN_BIT           ((uint32_t)0x00010000)
#define APB_PAD_CTRL_STATUS0_GPIO_4_ANA_EN_POS           16
#define APB_PAD_CTRL_STATUS0_GPIO_4_PULL_MODE_SEL_MASK   ((uint32_t)0x0000C000)
#define APB_PAD_CTRL_STATUS0_GPIO_4_PULL_MODE_SEL_LSB    14
#define APB_PAD_CTRL_STATUS0_GPIO_4_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_3_OUT_EN_BIT           ((uint32_t)0x00002000)
#define APB_PAD_CTRL_STATUS0_GPIO_3_OUT_EN_POS           13
#define APB_PAD_CTRL_STATUS0_GPIO_3_ANA_EN_BIT           ((uint32_t)0x00001000)
#define APB_PAD_CTRL_STATUS0_GPIO_3_ANA_EN_POS           12
#define APB_PAD_CTRL_STATUS0_GPIO_3_PULL_MODE_SEL_MASK   ((uint32_t)0x00000C00)
#define APB_PAD_CTRL_STATUS0_GPIO_3_PULL_MODE_SEL_LSB    10
#define APB_PAD_CTRL_STATUS0_GPIO_3_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_2_SPI_IIC_BIT          ((uint32_t)0x00000200)
#define APB_PAD_CTRL_STATUS0_GPIO_2_SPI_IIC_POS          9
#define APB_PAD_CTRL_STATUS0_GPIO_2_OUT_EN_BIT           ((uint32_t)0x00000100)
#define APB_PAD_CTRL_STATUS0_GPIO_2_OUT_EN_POS           8
#define APB_PAD_CTRL_STATUS0_GPIO_2_ANA_EN_BIT           ((uint32_t)0x00000080)
#define APB_PAD_CTRL_STATUS0_GPIO_2_ANA_EN_POS           7
#define APB_PAD_CTRL_STATUS0_GPIO_2_PULL_MODE_SEL_MASK   ((uint32_t)0x00000060)
#define APB_PAD_CTRL_STATUS0_GPIO_2_PULL_MODE_SEL_LSB    5
#define APB_PAD_CTRL_STATUS0_GPIO_2_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS0_GPIO_1_SPI_IIC_BIT          ((uint32_t)0x00000010)
#define APB_PAD_CTRL_STATUS0_GPIO_1_SPI_IIC_POS          4
#define APB_PAD_CTRL_STATUS0_GPIO_1_OUT_EN_BIT           ((uint32_t)0x00000008)
#define APB_PAD_CTRL_STATUS0_GPIO_1_OUT_EN_POS           3
#define APB_PAD_CTRL_STATUS0_GPIO_1_ANA_EN_BIT           ((uint32_t)0x00000004)
#define APB_PAD_CTRL_STATUS0_GPIO_1_ANA_EN_POS           2
#define APB_PAD_CTRL_STATUS0_GPIO_1_PULL_MODE_SEL_MASK   ((uint32_t)0x00000003)
#define APB_PAD_CTRL_STATUS0_GPIO_1_PULL_MODE_SEL_LSB    0
#define APB_PAD_CTRL_STATUS0_GPIO_1_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_CTRL_STATUS0_GPIO_7_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_7_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_7_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS0_GPIO_6_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_6_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_6_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS0_GPIO_5_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_5_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_5_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS0_GPIO_4_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_4_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_4_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS0_GPIO_3_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_3_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_3_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS0_GPIO_2_SPI_IIC_RST          0x0
#define APB_PAD_CTRL_STATUS0_GPIO_2_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_2_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_2_PULL_MODE_SEL_RST    0x2
#define APB_PAD_CTRL_STATUS0_GPIO_1_SPI_IIC_RST          0x0
#define APB_PAD_CTRL_STATUS0_GPIO_1_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_1_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS0_GPIO_1_PULL_MODE_SEL_RST    0x2

__INLINE void apb_pad_ctrl_status0_unpack(uint8_t* gpio7outen, uint8_t* gpio7anaen, uint8_t* gpio7pullmodesel, uint8_t* gpio6outen, uint8_t* gpio6anaen, uint8_t* gpio6pullmodesel, uint8_t* gpio5outen, uint8_t* gpio5anaen, uint8_t* gpio5pullmodesel, uint8_t* gpio4outen, uint8_t* gpio4anaen, uint8_t* gpio4pullmodesel, uint8_t* gpio3outen, uint8_t* gpio3anaen, uint8_t* gpio3pullmodesel, uint8_t* gpio2spiiic, uint8_t* gpio2outen, uint8_t* gpio2anaen, uint8_t* gpio2pullmodesel, uint8_t* gpio1spiiic, uint8_t* gpio1outen, uint8_t* gpio1anaen, uint8_t* gpio1pullmodesel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    *gpio7outen = (localVal & ((uint32_t)0x20000000)) >> 29;
    *gpio7anaen = (localVal & ((uint32_t)0x10000000)) >> 28;
    *gpio7pullmodesel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *gpio6outen = (localVal & ((uint32_t)0x02000000)) >> 25;
    *gpio6anaen = (localVal & ((uint32_t)0x01000000)) >> 24;
    *gpio6pullmodesel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *gpio5outen = (localVal & ((uint32_t)0x00200000)) >> 21;
    *gpio5anaen = (localVal & ((uint32_t)0x00100000)) >> 20;
    *gpio5pullmodesel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *gpio4outen = (localVal & ((uint32_t)0x00020000)) >> 17;
    *gpio4anaen = (localVal & ((uint32_t)0x00010000)) >> 16;
    *gpio4pullmodesel = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *gpio3outen = (localVal & ((uint32_t)0x00002000)) >> 13;
    *gpio3anaen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *gpio3pullmodesel = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *gpio2spiiic = (localVal & ((uint32_t)0x00000200)) >> 9;
    *gpio2outen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *gpio2anaen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *gpio2pullmodesel = (localVal & ((uint32_t)0x00000060)) >> 5;
    *gpio1spiiic = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpio1outen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio1anaen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio1pullmodesel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_7_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_7_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_7_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_6_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_6_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_6_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_5_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_5_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_5_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_4_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_4_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_4_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void apb_pad_ctrl_status0_gpio_3_out_en_setf(uint8_t gpio3outen)
{
    ASSERT_ERR((((uint32_t)gpio3outen << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_PAD_CTRL_STATUS0_ADDR, (uint32_t)gpio3outen << 13);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_3_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_3_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_2_spi_iic_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_2_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_2_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_2_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000060)) >> 5);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_1_spi_iic_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_1_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_1_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_pad_ctrl_status0_gpio_1_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS0_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief PAD_CTRL_STATUS1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31     i2s_sdout_out_en   0
 *     30     i2s_sdout_ana_en   0
 *  29:28   i2s_sdout_pull_mode_sel   0x1
 *     27       spi_clk_out_en   0
 *     26       spi_clk_ana_en   0
 *  25:24   spi_clk_pull_mode_sel   0x1
 *     23       spi_nss_out_en   0
 *     22       spi_nss_ana_en   0
 *  21:20   spi_nss_pull_mode_sel   0x1
 *     19   spi_io0_mosi_out_en   0
 *     18   spi_io0_mosi_ana_en   0
 *  17:16   spi_io0_mosi_pull_mode_sel   0x1
 *     15   spi_io1_miso_out_en   0
 *     14   spi_io1_miso_ana_en   0
 *  13:12   spi_io1_miso_pull_mode_sel   0x1
 *     11       spi_io2_out_en   0
 *     10       spi_io2_ana_en   0
 *  09:08   spi_io2_pull_mode_sel   0x1
 *     07       spi_io3_out_en   0
 *     06       spi_io3_ana_en   0
 *  05:04   spi_io3_pull_mode_sel   0x1
 *     03         gpio8_out_en   0
 *     02         gpio8_ana_en   0
 *  01:00   gpio8_pull_mode_sel   0x1
 * </pre>
 */
#define APB_PAD_CTRL_STATUS1_ADDR   0xC0012114
#define APB_PAD_CTRL_STATUS1_OFFSET 0x00000114
#define APB_PAD_CTRL_STATUS1_INDEX  0x00000045
#define APB_PAD_CTRL_STATUS1_RESET  0x11111111

__INLINE uint32_t apb_pad_ctrl_status1_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
}

__INLINE void apb_pad_ctrl_status1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_STATUS1_ADDR, value);
}

// field definitions
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_OUT_EN_BIT              ((uint32_t)0x80000000)
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_OUT_EN_POS              31
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_ANA_EN_BIT              ((uint32_t)0x40000000)
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_ANA_EN_POS              30
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_PULL_MODE_SEL_MASK      ((uint32_t)0x30000000)
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_PULL_MODE_SEL_LSB       28
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_PULL_MODE_SEL_WIDTH     ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_CLK_OUT_EN_BIT                 ((uint32_t)0x08000000)
#define APB_PAD_CTRL_STATUS1_SPI_CLK_OUT_EN_POS                 27
#define APB_PAD_CTRL_STATUS1_SPI_CLK_ANA_EN_BIT                 ((uint32_t)0x04000000)
#define APB_PAD_CTRL_STATUS1_SPI_CLK_ANA_EN_POS                 26
#define APB_PAD_CTRL_STATUS1_SPI_CLK_PULL_MODE_SEL_MASK         ((uint32_t)0x03000000)
#define APB_PAD_CTRL_STATUS1_SPI_CLK_PULL_MODE_SEL_LSB          24
#define APB_PAD_CTRL_STATUS1_SPI_CLK_PULL_MODE_SEL_WIDTH        ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_NSS_OUT_EN_BIT                 ((uint32_t)0x00800000)
#define APB_PAD_CTRL_STATUS1_SPI_NSS_OUT_EN_POS                 23
#define APB_PAD_CTRL_STATUS1_SPI_NSS_ANA_EN_BIT                 ((uint32_t)0x00400000)
#define APB_PAD_CTRL_STATUS1_SPI_NSS_ANA_EN_POS                 22
#define APB_PAD_CTRL_STATUS1_SPI_NSS_PULL_MODE_SEL_MASK         ((uint32_t)0x00300000)
#define APB_PAD_CTRL_STATUS1_SPI_NSS_PULL_MODE_SEL_LSB          20
#define APB_PAD_CTRL_STATUS1_SPI_NSS_PULL_MODE_SEL_WIDTH        ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_OUT_EN_BIT           ((uint32_t)0x00080000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_OUT_EN_POS           19
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_ANA_EN_BIT           ((uint32_t)0x00040000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_ANA_EN_POS           18
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_PULL_MODE_SEL_MASK   ((uint32_t)0x00030000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_PULL_MODE_SEL_LSB    16
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_OUT_EN_BIT           ((uint32_t)0x00008000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_OUT_EN_POS           15
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_ANA_EN_BIT           ((uint32_t)0x00004000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_ANA_EN_POS           14
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_PULL_MODE_SEL_MASK   ((uint32_t)0x00003000)
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_PULL_MODE_SEL_LSB    12
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_OUT_EN_BIT                ((uint32_t)0x00000800)
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_OUT_EN_POS                11
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_ANA_EN_BIT                ((uint32_t)0x00000400)
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_ANA_EN_POS                10
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_PULL_MODE_SEL_MASK        ((uint32_t)0x00000300)
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_PULL_MODE_SEL_LSB         8
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_PULL_MODE_SEL_WIDTH       ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_OUT_EN_BIT                ((uint32_t)0x00000080)
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_OUT_EN_POS                7
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_ANA_EN_BIT                ((uint32_t)0x00000040)
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_ANA_EN_POS                6
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_PULL_MODE_SEL_MASK        ((uint32_t)0x00000030)
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_PULL_MODE_SEL_LSB         4
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_PULL_MODE_SEL_WIDTH       ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS1_GPIO_8_OUT_EN_BIT                  ((uint32_t)0x00000008)
#define APB_PAD_CTRL_STATUS1_GPIO_8_OUT_EN_POS                  3
#define APB_PAD_CTRL_STATUS1_GPIO_8_ANA_EN_BIT                  ((uint32_t)0x00000004)
#define APB_PAD_CTRL_STATUS1_GPIO_8_ANA_EN_POS                  2
#define APB_PAD_CTRL_STATUS1_GPIO_8_PULL_MODE_SEL_MASK          ((uint32_t)0x00000003)
#define APB_PAD_CTRL_STATUS1_GPIO_8_PULL_MODE_SEL_LSB           0
#define APB_PAD_CTRL_STATUS1_GPIO_8_PULL_MODE_SEL_WIDTH         ((uint32_t)0x00000002)

#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_OUT_EN_RST              0x0
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_ANA_EN_RST              0x0
#define APB_PAD_CTRL_STATUS1_I_2S_SDOUT_PULL_MODE_SEL_RST       0x1
#define APB_PAD_CTRL_STATUS1_SPI_CLK_OUT_EN_RST                 0x0
#define APB_PAD_CTRL_STATUS1_SPI_CLK_ANA_EN_RST                 0x0
#define APB_PAD_CTRL_STATUS1_SPI_CLK_PULL_MODE_SEL_RST          0x1
#define APB_PAD_CTRL_STATUS1_SPI_NSS_OUT_EN_RST                 0x0
#define APB_PAD_CTRL_STATUS1_SPI_NSS_ANA_EN_RST                 0x0
#define APB_PAD_CTRL_STATUS1_SPI_NSS_PULL_MODE_SEL_RST          0x1
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_0_MOSI_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_1_MISO_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_OUT_EN_RST                0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_ANA_EN_RST                0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_2_PULL_MODE_SEL_RST         0x1
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_OUT_EN_RST                0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_ANA_EN_RST                0x0
#define APB_PAD_CTRL_STATUS1_SPI_IO_3_PULL_MODE_SEL_RST         0x1
#define APB_PAD_CTRL_STATUS1_GPIO_8_OUT_EN_RST                  0x0
#define APB_PAD_CTRL_STATUS1_GPIO_8_ANA_EN_RST                  0x0
#define APB_PAD_CTRL_STATUS1_GPIO_8_PULL_MODE_SEL_RST           0x1

__INLINE void apb_pad_ctrl_status1_unpack(uint8_t* i2ssdoutouten, uint8_t* i2ssdoutanaen, uint8_t* i2ssdoutpullmodesel, uint8_t* spiclkouten, uint8_t* spiclkanaen, uint8_t* spiclkpullmodesel, uint8_t* spinssouten, uint8_t* spinssanaen, uint8_t* spinsspullmodesel, uint8_t* spiio0mosiouten, uint8_t* spiio0mosianaen, uint8_t* spiio0mosipullmodesel, uint8_t* spiio1misoouten, uint8_t* spiio1misoanaen, uint8_t* spiio1misopullmodesel, uint8_t* spiio2outen, uint8_t* spiio2anaen, uint8_t* spiio2pullmodesel, uint8_t* spiio3outen, uint8_t* spiio3anaen, uint8_t* spiio3pullmodesel, uint8_t* gpio8outen, uint8_t* gpio8anaen, uint8_t* gpio8pullmodesel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    *i2ssdoutouten = (localVal & ((uint32_t)0x80000000)) >> 31;
    *i2ssdoutanaen = (localVal & ((uint32_t)0x40000000)) >> 30;
    *i2ssdoutpullmodesel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *spiclkouten = (localVal & ((uint32_t)0x08000000)) >> 27;
    *spiclkanaen = (localVal & ((uint32_t)0x04000000)) >> 26;
    *spiclkpullmodesel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *spinssouten = (localVal & ((uint32_t)0x00800000)) >> 23;
    *spinssanaen = (localVal & ((uint32_t)0x00400000)) >> 22;
    *spinsspullmodesel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *spiio0mosiouten = (localVal & ((uint32_t)0x00080000)) >> 19;
    *spiio0mosianaen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *spiio0mosipullmodesel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *spiio1misoouten = (localVal & ((uint32_t)0x00008000)) >> 15;
    *spiio1misoanaen = (localVal & ((uint32_t)0x00004000)) >> 14;
    *spiio1misopullmodesel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *spiio2outen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *spiio2anaen = (localVal & ((uint32_t)0x00000400)) >> 10;
    *spiio2pullmodesel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *spiio3outen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *spiio3anaen = (localVal & ((uint32_t)0x00000040)) >> 6;
    *spiio3pullmodesel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *gpio8outen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio8anaen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio8pullmodesel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_pad_ctrl_status1_i_2s_sdout_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE uint8_t apb_pad_ctrl_status1_i_2s_sdout_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE uint8_t apb_pad_ctrl_status1_i_2s_sdout_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_clk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_clk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_clk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_nss_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_nss_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_nss_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_0_mosi_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_0_mosi_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_0_mosi_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_1_miso_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_1_miso_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_1_miso_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_2_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_2_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_2_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_3_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_3_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t apb_pad_ctrl_status1_spi_io_3_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE uint8_t apb_pad_ctrl_status1_gpio_8_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t apb_pad_ctrl_status1_gpio_8_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_pad_ctrl_status1_gpio_8_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS1_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief PAD_CTRL_STATUS2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     27     i2s1_sclk_out_en   0
 *     26     i2s1_sclk_ana_en   0
 *  25:24   i2s1_sclk_pull_mode_sel   0x1
 *     23    i2s1_lrclk_out_en   0
 *     22    i2s1_lrclk_ana_en   0
 *  21:20   i2s1_lrclk_pull_mode_sel   0x1
 *     19    i2s1_sdout_out_en   0
 *     18    i2s1_sdout_ana_en   0
 *  17:16   i2s1_sdout_pull_mode_sel   0x1
 *     15      i2s_mclk_out_en   0
 *     14      i2s_mclk_ana_en   0
 *  13:12   i2s_mclk_pull_mode_sel   0x1
 *     11     i2s0_sclk_out_en   0
 *     10     i2s0_sclk_ana_en   0
 *  09:08   i2s0_sclk_pull_mode_sel   0x1
 *     07    i2s0_lrclk_out_en   0
 *     06    i2s0_lrclk_ana_en   0
 *  05:04   i2s0_lrclk_pull_mode_sel   0x1
 * </pre>
 */
#define APB_PAD_CTRL_STATUS2_ADDR   0xC0012118
#define APB_PAD_CTRL_STATUS2_OFFSET 0x00000118
#define APB_PAD_CTRL_STATUS2_INDEX  0x00000046
#define APB_PAD_CTRL_STATUS2_RESET  0x01111110

__INLINE uint32_t apb_pad_ctrl_status2_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
}

__INLINE void apb_pad_ctrl_status2_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_STATUS2_ADDR, value);
}

// field definitions
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_OUT_EN_BIT            ((uint32_t)0x08000000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_OUT_EN_POS            27
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_ANA_EN_BIT            ((uint32_t)0x04000000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_ANA_EN_POS            26
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_PULL_MODE_SEL_MASK    ((uint32_t)0x03000000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_PULL_MODE_SEL_LSB     24
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_PULL_MODE_SEL_WIDTH   ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_OUT_EN_BIT           ((uint32_t)0x00800000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_OUT_EN_POS           23
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_ANA_EN_BIT           ((uint32_t)0x00400000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_ANA_EN_POS           22
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_PULL_MODE_SEL_MASK   ((uint32_t)0x00300000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_PULL_MODE_SEL_LSB    20
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_OUT_EN_BIT           ((uint32_t)0x00080000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_OUT_EN_POS           19
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_ANA_EN_BIT           ((uint32_t)0x00040000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_ANA_EN_POS           18
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_PULL_MODE_SEL_MASK   ((uint32_t)0x00030000)
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_PULL_MODE_SEL_LSB    16
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_OUT_EN_BIT              ((uint32_t)0x00008000)
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_OUT_EN_POS              15
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_ANA_EN_BIT              ((uint32_t)0x00004000)
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_ANA_EN_POS              14
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_PULL_MODE_SEL_MASK      ((uint32_t)0x00003000)
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_PULL_MODE_SEL_LSB       12
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_PULL_MODE_SEL_WIDTH     ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_OUT_EN_BIT            ((uint32_t)0x00000800)
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_OUT_EN_POS            11
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_ANA_EN_BIT            ((uint32_t)0x00000400)
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_ANA_EN_POS            10
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_PULL_MODE_SEL_MASK    ((uint32_t)0x00000300)
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_PULL_MODE_SEL_LSB     8
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_PULL_MODE_SEL_WIDTH   ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_OUT_EN_BIT           ((uint32_t)0x00000080)
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_OUT_EN_POS           7
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_ANA_EN_BIT           ((uint32_t)0x00000040)
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_ANA_EN_POS           6
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_PULL_MODE_SEL_MASK   ((uint32_t)0x00000030)
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_PULL_MODE_SEL_LSB    4
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)

#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_OUT_EN_RST            0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_ANA_EN_RST            0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_SCLK_PULL_MODE_SEL_RST     0x1
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_LRCLK_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_1_SDOUT_PULL_MODE_SEL_RST    0x1
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_OUT_EN_RST              0x0
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_ANA_EN_RST              0x0
#define APB_PAD_CTRL_STATUS2_I_2S_MCLK_PULL_MODE_SEL_RST       0x1
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_OUT_EN_RST            0x0
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_ANA_EN_RST            0x0
#define APB_PAD_CTRL_STATUS2_I_2S_0_SCLK_PULL_MODE_SEL_RST     0x1
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS2_I_2S_0_LRCLK_PULL_MODE_SEL_RST    0x1

__INLINE void apb_pad_ctrl_status2_unpack(uint8_t* i2s1sclkouten, uint8_t* i2s1sclkanaen, uint8_t* i2s1sclkpullmodesel, uint8_t* i2s1lrclkouten, uint8_t* i2s1lrclkanaen, uint8_t* i2s1lrclkpullmodesel, uint8_t* i2s1sdoutouten, uint8_t* i2s1sdoutanaen, uint8_t* i2s1sdoutpullmodesel, uint8_t* i2smclkouten, uint8_t* i2smclkanaen, uint8_t* i2smclkpullmodesel, uint8_t* i2s0sclkouten, uint8_t* i2s0sclkanaen, uint8_t* i2s0sclkpullmodesel, uint8_t* i2s0lrclkouten, uint8_t* i2s0lrclkanaen, uint8_t* i2s0lrclkpullmodesel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    *i2s1sclkouten = (localVal & ((uint32_t)0x08000000)) >> 27;
    *i2s1sclkanaen = (localVal & ((uint32_t)0x04000000)) >> 26;
    *i2s1sclkpullmodesel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *i2s1lrclkouten = (localVal & ((uint32_t)0x00800000)) >> 23;
    *i2s1lrclkanaen = (localVal & ((uint32_t)0x00400000)) >> 22;
    *i2s1lrclkpullmodesel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *i2s1sdoutouten = (localVal & ((uint32_t)0x00080000)) >> 19;
    *i2s1sdoutanaen = (localVal & ((uint32_t)0x00040000)) >> 18;
    *i2s1sdoutpullmodesel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *i2smclkouten = (localVal & ((uint32_t)0x00008000)) >> 15;
    *i2smclkanaen = (localVal & ((uint32_t)0x00004000)) >> 14;
    *i2smclkpullmodesel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *i2s0sclkouten = (localVal & ((uint32_t)0x00000800)) >> 11;
    *i2s0sclkanaen = (localVal & ((uint32_t)0x00000400)) >> 10;
    *i2s0sclkpullmodesel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *i2s0lrclkouten = (localVal & ((uint32_t)0x00000080)) >> 7;
    *i2s0lrclkanaen = (localVal & ((uint32_t)0x00000040)) >> 6;
    *i2s0lrclkpullmodesel = (localVal & ((uint32_t)0x00000030)) >> 4;
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sclk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sclk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sclk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_lrclk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_lrclk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_lrclk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sdout_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sdout_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_1_sdout_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_mclk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_mclk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_mclk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_sclk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_sclk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_sclk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_lrclk_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_lrclk_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t apb_pad_ctrl_status2_i_2s_0_lrclk_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS2_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

/**
 * @brief PAD_I2S_FUNC_CFG1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  19:16   I2S1_SDOUT_FUNC_SEL   0x0
 *  11:08   I2S1_LRCLK_FUNC_SEL   0x0
 *  07:04   I2S1_SCLK_FUNC_SEL   0x0
 * </pre>
 */
#define APB_PAD_I2S_FUNC_CFG1_ADDR   0xC001211C
#define APB_PAD_I2S_FUNC_CFG1_OFFSET 0x0000011C
#define APB_PAD_I2S_FUNC_CFG1_INDEX  0x00000047
#define APB_PAD_I2S_FUNC_CFG1_RESET  0x00000000

__INLINE uint32_t apb_pad_i2s_func_cfg1_get(void)
{
    return REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR);
}

__INLINE void apb_pad_i2s_func_cfg1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG1_ADDR, value);
}

// field definitions
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SDOUT_FUNC_SEL_MASK   ((uint32_t)0x000F0000)
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SDOUT_FUNC_SEL_LSB    16
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SDOUT_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_I2S_FUNC_CFG1_I2S1_LRCLK_FUNC_SEL_MASK   ((uint32_t)0x00000F00)
#define APB_PAD_I2S_FUNC_CFG1_I2S1_LRCLK_FUNC_SEL_LSB    8
#define APB_PAD_I2S_FUNC_CFG1_I2S1_LRCLK_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SCLK_FUNC_SEL_MASK    ((uint32_t)0x000000F0)
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SCLK_FUNC_SEL_LSB     4
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SCLK_FUNC_SEL_WIDTH   ((uint32_t)0x00000004)

#define APB_PAD_I2S_FUNC_CFG1_I2S1_SDOUT_FUNC_SEL_RST    0x0
#define APB_PAD_I2S_FUNC_CFG1_I2S1_LRCLK_FUNC_SEL_RST    0x0
#define APB_PAD_I2S_FUNC_CFG1_I2S1_SCLK_FUNC_SEL_RST     0x0

__INLINE void apb_pad_i2s_func_cfg1_pack(uint8_t i2s1sdoutfuncsel, uint8_t i2s1lrclkfuncsel, uint8_t i2s1sclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutfuncsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)i2s1lrclkfuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclkfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG1_ADDR,  ((uint32_t)i2s1sdoutfuncsel << 16) | ((uint32_t)i2s1lrclkfuncsel << 8) | ((uint32_t)i2s1sclkfuncsel << 4));
}

__INLINE void apb_pad_i2s_func_cfg1_unpack(uint8_t* i2s1sdoutfuncsel, uint8_t* i2s1lrclkfuncsel, uint8_t* i2s1sclkfuncsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR);
    *i2s1sdoutfuncsel = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *i2s1lrclkfuncsel = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *i2s1sclkfuncsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
}

__INLINE uint8_t apb_pad_i2s_func_cfg1_i2s1_sdout_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE void apb_pad_i2s_func_cfg1_i2s1_sdout_func_sel_setf(uint8_t i2s1sdoutfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s1sdoutfuncsel << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG1_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)i2s1sdoutfuncsel << 16));
}

__INLINE uint8_t apb_pad_i2s_func_cfg1_i2s1_lrclk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void apb_pad_i2s_func_cfg1_i2s1_lrclk_func_sel_setf(uint8_t i2s1lrclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s1lrclkfuncsel << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG1_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)i2s1lrclkfuncsel << 8));
}

__INLINE uint8_t apb_pad_i2s_func_cfg1_i2s1_sclk_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_pad_i2s_func_cfg1_i2s1_sclk_func_sel_setf(uint8_t i2s1sclkfuncsel)
{
    ASSERT_ERR((((uint32_t)i2s1sclkfuncsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_I2S_FUNC_CFG1_ADDR, (REG_PL_RD(APB_PAD_I2S_FUNC_CFG1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)i2s1sclkfuncsel << 4));
}

/**
 * @brief PAD_GPIO_FUNC_CFG1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:04      GPIO10_FUNC_SEL   0x0
 *  03:00       GPIO9_FUNC_SEL   0x0
 * </pre>
 */
#define APB_PAD_GPIO_FUNC_CFG1_ADDR   0xC0012120
#define APB_PAD_GPIO_FUNC_CFG1_OFFSET 0x00000120
#define APB_PAD_GPIO_FUNC_CFG1_INDEX  0x00000048
#define APB_PAD_GPIO_FUNC_CFG1_RESET  0x00000000

__INLINE uint32_t apb_pad_gpio_func_cfg1_get(void)
{
    return REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR);
}

__INLINE void apb_pad_gpio_func_cfg1_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG1_ADDR, value);
}

// field definitions
#define APB_PAD_GPIO_FUNC_CFG1_GPIO10_FUNC_SEL_MASK   ((uint32_t)0x000000F0)
#define APB_PAD_GPIO_FUNC_CFG1_GPIO10_FUNC_SEL_LSB    4
#define APB_PAD_GPIO_FUNC_CFG1_GPIO10_FUNC_SEL_WIDTH  ((uint32_t)0x00000004)
#define APB_PAD_GPIO_FUNC_CFG1_GPIO9_FUNC_SEL_MASK    ((uint32_t)0x0000000F)
#define APB_PAD_GPIO_FUNC_CFG1_GPIO9_FUNC_SEL_LSB     0
#define APB_PAD_GPIO_FUNC_CFG1_GPIO9_FUNC_SEL_WIDTH   ((uint32_t)0x00000004)

#define APB_PAD_GPIO_FUNC_CFG1_GPIO10_FUNC_SEL_RST    0x0
#define APB_PAD_GPIO_FUNC_CFG1_GPIO9_FUNC_SEL_RST     0x0

__INLINE void apb_pad_gpio_func_cfg1_pack(uint8_t gpio10funcsel, uint8_t gpio9funcsel)
{
    ASSERT_ERR((((uint32_t)gpio10funcsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)gpio9funcsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG1_ADDR,  ((uint32_t)gpio10funcsel << 4) | ((uint32_t)gpio9funcsel << 0));
}

__INLINE void apb_pad_gpio_func_cfg1_unpack(uint8_t* gpio10funcsel, uint8_t* gpio9funcsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR);
    *gpio10funcsel = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *gpio9funcsel = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_pad_gpio_func_cfg1_gpio10_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

__INLINE void apb_pad_gpio_func_cfg1_gpio10_func_sel_setf(uint8_t gpio10funcsel)
{
    ASSERT_ERR((((uint32_t)gpio10funcsel << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG1_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)gpio10funcsel << 4));
}

__INLINE uint8_t apb_pad_gpio_func_cfg1_gpio9_func_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_pad_gpio_func_cfg1_gpio9_func_sel_setf(uint8_t gpio9funcsel)
{
    ASSERT_ERR((((uint32_t)gpio9funcsel << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_PAD_GPIO_FUNC_CFG1_ADDR, (REG_PL_RD(APB_PAD_GPIO_FUNC_CFG1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)gpio9funcsel << 0));
}

/**
 * @brief PAD_GPIO_SW_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     13    GPIO10_SW_CTRL_EN   0
 *     12    GPIO10_SPI_IIC_SW   0
 *     11     GPIO10_OUT_EN_SW   0
 *     10     GPIO10_ANA_EN_SW   0
 *  09:08   GPIO10_PULL_MODE_SEL_SW   0x0
 *     05     GPIO9_SW_CTRL_EN   0
 *     04     GPIO9_SPI_IIC_SW   0
 *     03      GPIO9_OUT_EN_SW   0
 *     02      GPIO9_ANA_EN_SW   0
 *  01:00   GPIO9_PULL_MODE_SEL_SW   0x0
 * </pre>
 */
#define APB_PAD_GPIO_SW_CTRL3_ADDR   0xC0012124
#define APB_PAD_GPIO_SW_CTRL3_OFFSET 0x00000124
#define APB_PAD_GPIO_SW_CTRL3_INDEX  0x00000049
#define APB_PAD_GPIO_SW_CTRL3_RESET  0x00000000

__INLINE uint32_t apb_pad_gpio_sw_ctrl3_get(void)
{
    return REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR);
}

__INLINE void apb_pad_gpio_sw_ctrl3_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, value);
}

// field definitions
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SW_CTRL_EN_BIT          ((uint32_t)0x00002000)
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SW_CTRL_EN_POS          13
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SPI_IIC_SW_BIT          ((uint32_t)0x00001000)
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SPI_IIC_SW_POS          12
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_OUT_EN_SW_BIT           ((uint32_t)0x00000800)
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_OUT_EN_SW_POS           11
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_ANA_EN_SW_BIT           ((uint32_t)0x00000400)
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_ANA_EN_SW_POS           10
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_PULL_MODE_SEL_SW_MASK   ((uint32_t)0x00000300)
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_PULL_MODE_SEL_SW_LSB    8
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_PULL_MODE_SEL_SW_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SW_CTRL_EN_BIT           ((uint32_t)0x00000020)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SW_CTRL_EN_POS           5
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SPI_IIC_SW_BIT           ((uint32_t)0x00000010)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SPI_IIC_SW_POS           4
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_OUT_EN_SW_BIT            ((uint32_t)0x00000008)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_OUT_EN_SW_POS            3
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_ANA_EN_SW_BIT            ((uint32_t)0x00000004)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_ANA_EN_SW_POS            2
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_PULL_MODE_SEL_SW_MASK    ((uint32_t)0x00000003)
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_PULL_MODE_SEL_SW_LSB     0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_PULL_MODE_SEL_SW_WIDTH   ((uint32_t)0x00000002)

#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SW_CTRL_EN_RST          0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_SPI_IIC_SW_RST          0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_OUT_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_ANA_EN_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO10_PULL_MODE_SEL_SW_RST    0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SW_CTRL_EN_RST           0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_SPI_IIC_SW_RST           0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_OUT_EN_SW_RST            0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_ANA_EN_SW_RST            0x0
#define APB_PAD_GPIO_SW_CTRL3_GPIO9_PULL_MODE_SEL_SW_RST     0x0

__INLINE void apb_pad_gpio_sw_ctrl3_pack(uint8_t gpio10swctrlen, uint8_t gpio10spiiicsw, uint8_t gpio10outensw, uint8_t gpio10anaensw, uint8_t gpio10pullmodeselsw, uint8_t gpio9swctrlen, uint8_t gpio9spiiicsw, uint8_t gpio9outensw, uint8_t gpio9anaensw, uint8_t gpio9pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio10swctrlen << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)gpio10spiiicsw << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)gpio10outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)gpio10anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)gpio10pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    ASSERT_ERR((((uint32_t)gpio9swctrlen << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)gpio9spiiicsw << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)gpio9outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)gpio9anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)gpio9pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR,  ((uint32_t)gpio10swctrlen << 13) | ((uint32_t)gpio10spiiicsw << 12) | ((uint32_t)gpio10outensw << 11) | ((uint32_t)gpio10anaensw << 10) | ((uint32_t)gpio10pullmodeselsw << 8) | ((uint32_t)gpio9swctrlen << 5) | ((uint32_t)gpio9spiiicsw << 4) | ((uint32_t)gpio9outensw << 3) | ((uint32_t)gpio9anaensw << 2) | ((uint32_t)gpio9pullmodeselsw << 0));
}

__INLINE void apb_pad_gpio_sw_ctrl3_unpack(uint8_t* gpio10swctrlen, uint8_t* gpio10spiiicsw, uint8_t* gpio10outensw, uint8_t* gpio10anaensw, uint8_t* gpio10pullmodeselsw, uint8_t* gpio9swctrlen, uint8_t* gpio9spiiicsw, uint8_t* gpio9outensw, uint8_t* gpio9anaensw, uint8_t* gpio9pullmodeselsw)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR);
    *gpio10swctrlen = (localVal & ((uint32_t)0x00002000)) >> 13;
    *gpio10spiiicsw = (localVal & ((uint32_t)0x00001000)) >> 12;
    *gpio10outensw = (localVal & ((uint32_t)0x00000800)) >> 11;
    *gpio10anaensw = (localVal & ((uint32_t)0x00000400)) >> 10;
    *gpio10pullmodeselsw = (localVal & ((uint32_t)0x00000300)) >> 8;
    *gpio9swctrlen = (localVal & ((uint32_t)0x00000020)) >> 5;
    *gpio9spiiicsw = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpio9outensw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio9anaensw = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio9pullmodeselsw = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio10_sw_ctrl_en_setf(uint8_t gpio10swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio10swctrlen << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)gpio10swctrlen << 13));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio10_spi_iic_sw_setf(uint8_t gpio10spiiicsw)
{
    ASSERT_ERR((((uint32_t)gpio10spiiicsw << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpio10spiiicsw << 12));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio10_out_en_sw_setf(uint8_t gpio10outensw)
{
    ASSERT_ERR((((uint32_t)gpio10outensw << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpio10outensw << 11));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio10_ana_en_sw_setf(uint8_t gpio10anaensw)
{
    ASSERT_ERR((((uint32_t)gpio10anaensw << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpio10anaensw << 10));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio10_pull_mode_sel_sw_setf(uint8_t gpio10pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio10pullmodeselsw << 8) & ~((uint32_t)0x00000300)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)gpio10pullmodeselsw << 8));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio9_sw_ctrl_en_setf(uint8_t gpio9swctrlen)
{
    ASSERT_ERR((((uint32_t)gpio9swctrlen << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)gpio9swctrlen << 5));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio9_spi_iic_sw_setf(uint8_t gpio9spiiicsw)
{
    ASSERT_ERR((((uint32_t)gpio9spiiicsw << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)gpio9spiiicsw << 4));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio9_out_en_sw_setf(uint8_t gpio9outensw)
{
    ASSERT_ERR((((uint32_t)gpio9outensw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gpio9outensw << 3));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio9_ana_en_sw_setf(uint8_t gpio9anaensw)
{
    ASSERT_ERR((((uint32_t)gpio9anaensw << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)gpio9anaensw << 2));
}

__INLINE void apb_pad_gpio_sw_ctrl3_gpio9_pull_mode_sel_sw_setf(uint8_t gpio9pullmodeselsw)
{
    ASSERT_ERR((((uint32_t)gpio9pullmodeselsw << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_PAD_GPIO_SW_CTRL3_ADDR, (REG_PL_RD(APB_PAD_GPIO_SW_CTRL3_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)gpio9pullmodeselsw << 0));
}

/**
 * @brief PAD_CTRL_STATUS3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     09       Gpio10_spi_iic   0
 *     08        Gpio10_out_en   0
 *     07        Gpio10_ana_en   0
 *  06:05   Gpio10_pull_mode_sel   0x2
 *     04        Gpio9_spi_iic   0
 *     03         Gpio9_out_en   0
 *     02         Gpio9_ana_en   0
 *  01:00   Gpio9_pull_mode_sel   0x2
 * </pre>
 */
#define APB_PAD_CTRL_STATUS3_ADDR   0xC0012128
#define APB_PAD_CTRL_STATUS3_OFFSET 0x00000128
#define APB_PAD_CTRL_STATUS3_INDEX  0x0000004A
#define APB_PAD_CTRL_STATUS3_RESET  0x00000042

__INLINE uint32_t apb_pad_ctrl_status3_get(void)
{
    return REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
}

__INLINE void apb_pad_ctrl_status3_set(uint32_t value)
{
    REG_PL_WR(APB_PAD_CTRL_STATUS3_ADDR, value);
}

// field definitions
#define APB_PAD_CTRL_STATUS3_GPIO_10_SPI_IIC_BIT          ((uint32_t)0x00000200)
#define APB_PAD_CTRL_STATUS3_GPIO_10_SPI_IIC_POS          9
#define APB_PAD_CTRL_STATUS3_GPIO_10_OUT_EN_BIT           ((uint32_t)0x00000100)
#define APB_PAD_CTRL_STATUS3_GPIO_10_OUT_EN_POS           8
#define APB_PAD_CTRL_STATUS3_GPIO_10_ANA_EN_BIT           ((uint32_t)0x00000080)
#define APB_PAD_CTRL_STATUS3_GPIO_10_ANA_EN_POS           7
#define APB_PAD_CTRL_STATUS3_GPIO_10_PULL_MODE_SEL_MASK   ((uint32_t)0x00000060)
#define APB_PAD_CTRL_STATUS3_GPIO_10_PULL_MODE_SEL_LSB    5
#define APB_PAD_CTRL_STATUS3_GPIO_10_PULL_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
#define APB_PAD_CTRL_STATUS3_GPIO_9_SPI_IIC_BIT           ((uint32_t)0x00000010)
#define APB_PAD_CTRL_STATUS3_GPIO_9_SPI_IIC_POS           4
#define APB_PAD_CTRL_STATUS3_GPIO_9_OUT_EN_BIT            ((uint32_t)0x00000008)
#define APB_PAD_CTRL_STATUS3_GPIO_9_OUT_EN_POS            3
#define APB_PAD_CTRL_STATUS3_GPIO_9_ANA_EN_BIT            ((uint32_t)0x00000004)
#define APB_PAD_CTRL_STATUS3_GPIO_9_ANA_EN_POS            2
#define APB_PAD_CTRL_STATUS3_GPIO_9_PULL_MODE_SEL_MASK    ((uint32_t)0x00000003)
#define APB_PAD_CTRL_STATUS3_GPIO_9_PULL_MODE_SEL_LSB     0
#define APB_PAD_CTRL_STATUS3_GPIO_9_PULL_MODE_SEL_WIDTH   ((uint32_t)0x00000002)

#define APB_PAD_CTRL_STATUS3_GPIO_10_SPI_IIC_RST          0x0
#define APB_PAD_CTRL_STATUS3_GPIO_10_OUT_EN_RST           0x0
#define APB_PAD_CTRL_STATUS3_GPIO_10_ANA_EN_RST           0x0
#define APB_PAD_CTRL_STATUS3_GPIO_10_PULL_MODE_SEL_RST    0x2
#define APB_PAD_CTRL_STATUS3_GPIO_9_SPI_IIC_RST           0x0
#define APB_PAD_CTRL_STATUS3_GPIO_9_OUT_EN_RST            0x0
#define APB_PAD_CTRL_STATUS3_GPIO_9_ANA_EN_RST            0x0
#define APB_PAD_CTRL_STATUS3_GPIO_9_PULL_MODE_SEL_RST     0x2

__INLINE void apb_pad_ctrl_status3_unpack(uint8_t* gpio10spiiic, uint8_t* gpio10outen, uint8_t* gpio10anaen, uint8_t* gpio10pullmodesel, uint8_t* gpio9spiiic, uint8_t* gpio9outen, uint8_t* gpio9anaen, uint8_t* gpio9pullmodesel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    *gpio10spiiic = (localVal & ((uint32_t)0x00000200)) >> 9;
    *gpio10outen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *gpio10anaen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *gpio10pullmodesel = (localVal & ((uint32_t)0x00000060)) >> 5;
    *gpio9spiiic = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpio9outen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *gpio9anaen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *gpio9pullmodesel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_10_spi_iic_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_10_out_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_10_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_10_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000060)) >> 5);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_9_spi_iic_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_pad_ctrl_status3_gpio_9_out_en_setf(uint8_t gpio9outen)
{
    ASSERT_ERR((((uint32_t)gpio9outen << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_PAD_CTRL_STATUS3_ADDR, (uint32_t)gpio9outen << 3);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_9_ana_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_pad_ctrl_status3_gpio_9_pull_mode_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PAD_CTRL_STATUS3_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief KEY_STATUS0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00      gpio_key_status   0x0
 * </pre>
 */
#define APB_KEY_STATUS0_ADDR   0xC0012138
#define APB_KEY_STATUS0_OFFSET 0x00000138
#define APB_KEY_STATUS0_INDEX  0x0000004E
#define APB_KEY_STATUS0_RESET  0x00000000

__INLINE uint32_t apb_key_status0_get(void)
{
    return REG_PL_RD(APB_KEY_STATUS0_ADDR);
}

__INLINE void apb_key_status0_set(uint32_t value)
{
    REG_PL_WR(APB_KEY_STATUS0_ADDR, value);
}

// field definitions
#define APB_KEY_STATUS0_GPIO_KEY_STATUS_MASK   ((uint32_t)0x000000FF)
#define APB_KEY_STATUS0_GPIO_KEY_STATUS_LSB    0
#define APB_KEY_STATUS0_GPIO_KEY_STATUS_WIDTH  ((uint32_t)0x00000008)

#define APB_KEY_STATUS0_GPIO_KEY_STATUS_RST    0x0

__INLINE uint8_t apb_key_status0_gpio_key_status_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_STATUS0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief KEY_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     29         Gpio_key_pol   0
 *     28   clk_mic_key_det_en   0
 *     27      mic_key_det_rst   0
 *     26       micin_int_mask   0
 *     25        micin_int_clr   0
 *  24:23        micin_key_deb   0x0
 *     22     gpio_key_int_clr   0
 *     21     gpio_key_det_rst   0
 *     20   clk_gpio_key_det_en   0
 *  17:16         gpio_key_deb   0x0
 *     15         Micin_det_pd   1
 *  14:12   Micin_det_vth_ctrl   0x0
 *     10             Hss_mask   0
 *     09           Micin_mask   0
 *     08            Gpio_mask   0
 *  07:00    gpio_key_int_mask   0x0
 * </pre>
 */
#define APB_KEY_CTRL0_ADDR   0xC001213C
#define APB_KEY_CTRL0_OFFSET 0x0000013C
#define APB_KEY_CTRL0_INDEX  0x0000004F
#define APB_KEY_CTRL0_RESET  0x00008000

__INLINE uint32_t apb_key_ctrl0_get(void)
{
    return REG_PL_RD(APB_KEY_CTRL0_ADDR);
}

__INLINE void apb_key_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_KEY_CTRL0_ADDR, value);
}

// field definitions
#define APB_KEY_CTRL0_GPIO_KEY_POL_BIT           ((uint32_t)0x20000000)
#define APB_KEY_CTRL0_GPIO_KEY_POL_POS           29
#define APB_KEY_CTRL0_CLK_MIC_KEY_DET_EN_BIT     ((uint32_t)0x10000000)
#define APB_KEY_CTRL0_CLK_MIC_KEY_DET_EN_POS     28
#define APB_KEY_CTRL0_MIC_KEY_DET_RST_BIT        ((uint32_t)0x08000000)
#define APB_KEY_CTRL0_MIC_KEY_DET_RST_POS        27
#define APB_KEY_CTRL0_MICIN_INT_MASK_BIT         ((uint32_t)0x04000000)
#define APB_KEY_CTRL0_MICIN_INT_MASK_POS         26
#define APB_KEY_CTRL0_MICIN_INT_CLR_BIT          ((uint32_t)0x02000000)
#define APB_KEY_CTRL0_MICIN_INT_CLR_POS          25
#define APB_KEY_CTRL0_MICIN_KEY_DEB_MASK         ((uint32_t)0x01800000)
#define APB_KEY_CTRL0_MICIN_KEY_DEB_LSB          23
#define APB_KEY_CTRL0_MICIN_KEY_DEB_WIDTH        ((uint32_t)0x00000002)
#define APB_KEY_CTRL0_GPIO_KEY_INT_CLR_BIT       ((uint32_t)0x00400000)
#define APB_KEY_CTRL0_GPIO_KEY_INT_CLR_POS       22
#define APB_KEY_CTRL0_GPIO_KEY_DET_RST_BIT       ((uint32_t)0x00200000)
#define APB_KEY_CTRL0_GPIO_KEY_DET_RST_POS       21
#define APB_KEY_CTRL0_CLK_GPIO_KEY_DET_EN_BIT    ((uint32_t)0x00100000)
#define APB_KEY_CTRL0_CLK_GPIO_KEY_DET_EN_POS    20
#define APB_KEY_CTRL0_GPIO_KEY_DEB_MASK          ((uint32_t)0x00030000)
#define APB_KEY_CTRL0_GPIO_KEY_DEB_LSB           16
#define APB_KEY_CTRL0_GPIO_KEY_DEB_WIDTH         ((uint32_t)0x00000002)
#define APB_KEY_CTRL0_MICIN_DET_PD_BIT           ((uint32_t)0x00008000)
#define APB_KEY_CTRL0_MICIN_DET_PD_POS           15
#define APB_KEY_CTRL0_MICIN_DET_VTH_CTRL_MASK    ((uint32_t)0x00007000)
#define APB_KEY_CTRL0_MICIN_DET_VTH_CTRL_LSB     12
#define APB_KEY_CTRL0_MICIN_DET_VTH_CTRL_WIDTH   ((uint32_t)0x00000003)
#define APB_KEY_CTRL0_HSS_MASK_BIT               ((uint32_t)0x00000400)
#define APB_KEY_CTRL0_HSS_MASK_POS               10
#define APB_KEY_CTRL0_MICIN_MASK_BIT             ((uint32_t)0x00000200)
#define APB_KEY_CTRL0_MICIN_MASK_POS             9
#define APB_KEY_CTRL0_GPIO_MASK_BIT              ((uint32_t)0x00000100)
#define APB_KEY_CTRL0_GPIO_MASK_POS              8
#define APB_KEY_CTRL0_GPIO_KEY_INT_MASK_MASK     ((uint32_t)0x000000FF)
#define APB_KEY_CTRL0_GPIO_KEY_INT_MASK_LSB      0
#define APB_KEY_CTRL0_GPIO_KEY_INT_MASK_WIDTH    ((uint32_t)0x00000008)

#define APB_KEY_CTRL0_GPIO_KEY_POL_RST           0x0
#define APB_KEY_CTRL0_CLK_MIC_KEY_DET_EN_RST     0x0
#define APB_KEY_CTRL0_MIC_KEY_DET_RST_RST        0x0
#define APB_KEY_CTRL0_MICIN_INT_MASK_RST         0x0
#define APB_KEY_CTRL0_MICIN_INT_CLR_RST          0x0
#define APB_KEY_CTRL0_MICIN_KEY_DEB_RST          0x0
#define APB_KEY_CTRL0_GPIO_KEY_INT_CLR_RST       0x0
#define APB_KEY_CTRL0_GPIO_KEY_DET_RST_RST       0x0
#define APB_KEY_CTRL0_CLK_GPIO_KEY_DET_EN_RST    0x0
#define APB_KEY_CTRL0_GPIO_KEY_DEB_RST           0x0
#define APB_KEY_CTRL0_MICIN_DET_PD_RST           0x1
#define APB_KEY_CTRL0_MICIN_DET_VTH_CTRL_RST     0x0
#define APB_KEY_CTRL0_HSS_MASK_RST               0x0
#define APB_KEY_CTRL0_MICIN_MASK_RST             0x0
#define APB_KEY_CTRL0_GPIO_MASK_RST              0x0
#define APB_KEY_CTRL0_GPIO_KEY_INT_MASK_RST      0x0

__INLINE void apb_key_ctrl0_pack(uint8_t gpiokeypol, uint8_t clkmickeydeten, uint8_t mickeydetrst, uint8_t micinintmask, uint8_t micinintclr, uint8_t micinkeydeb, uint8_t gpiokeyintclr, uint8_t gpiokeydetrst, uint8_t clkgpiokeydeten, uint8_t gpiokeydeb, uint8_t micindetpd, uint8_t micindetvthctrl, uint8_t hssmask, uint8_t micinmask, uint8_t gpiomask, uint8_t gpiokeyintmask)
{
    ASSERT_ERR((((uint32_t)gpiokeypol << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)clkmickeydeten << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)mickeydetrst << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)micinintmask << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)micinintclr << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)micinkeydeb << 23) & ~((uint32_t)0x01800000)) == 0);
    ASSERT_ERR((((uint32_t)gpiokeyintclr << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)gpiokeydetrst << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)clkgpiokeydeten << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)gpiokeydeb << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)micindetpd << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)micindetvthctrl << 12) & ~((uint32_t)0x00007000)) == 0);
    ASSERT_ERR((((uint32_t)hssmask << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)micinmask << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)gpiomask << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)gpiokeyintmask << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR,  ((uint32_t)gpiokeypol << 29) | ((uint32_t)clkmickeydeten << 28) | ((uint32_t)mickeydetrst << 27) | ((uint32_t)micinintmask << 26) | ((uint32_t)micinintclr << 25) | ((uint32_t)micinkeydeb << 23) | ((uint32_t)gpiokeyintclr << 22) | ((uint32_t)gpiokeydetrst << 21) | ((uint32_t)clkgpiokeydeten << 20) | ((uint32_t)gpiokeydeb << 16) | ((uint32_t)micindetpd << 15) | ((uint32_t)micindetvthctrl << 12) | ((uint32_t)hssmask << 10) | ((uint32_t)micinmask << 9) | ((uint32_t)gpiomask << 8) | ((uint32_t)gpiokeyintmask << 0));
}

__INLINE void apb_key_ctrl0_unpack(uint8_t* gpiokeypol, uint8_t* clkmickeydeten, uint8_t* mickeydetrst, uint8_t* micinintmask, uint8_t* micinintclr, uint8_t* micinkeydeb, uint8_t* gpiokeyintclr, uint8_t* gpiokeydetrst, uint8_t* clkgpiokeydeten, uint8_t* gpiokeydeb, uint8_t* micindetpd, uint8_t* micindetvthctrl, uint8_t* hssmask, uint8_t* micinmask, uint8_t* gpiomask, uint8_t* gpiokeyintmask)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    *gpiokeypol = (localVal & ((uint32_t)0x20000000)) >> 29;
    *clkmickeydeten = (localVal & ((uint32_t)0x10000000)) >> 28;
    *mickeydetrst = (localVal & ((uint32_t)0x08000000)) >> 27;
    *micinintmask = (localVal & ((uint32_t)0x04000000)) >> 26;
    *micinintclr = (localVal & ((uint32_t)0x02000000)) >> 25;
    *micinkeydeb = (localVal & ((uint32_t)0x01800000)) >> 23;
    *gpiokeyintclr = (localVal & ((uint32_t)0x00400000)) >> 22;
    *gpiokeydetrst = (localVal & ((uint32_t)0x00200000)) >> 21;
    *clkgpiokeydeten = (localVal & ((uint32_t)0x00100000)) >> 20;
    *gpiokeydeb = (localVal & ((uint32_t)0x00030000)) >> 16;
    *micindetpd = (localVal & ((uint32_t)0x00008000)) >> 15;
    *micindetvthctrl = (localVal & ((uint32_t)0x00007000)) >> 12;
    *hssmask = (localVal & ((uint32_t)0x00000400)) >> 10;
    *micinmask = (localVal & ((uint32_t)0x00000200)) >> 9;
    *gpiomask = (localVal & ((uint32_t)0x00000100)) >> 8;
    *gpiokeyintmask = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_key_ctrl0_gpio_key_pol_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void apb_key_ctrl0_gpio_key_pol_setf(uint8_t gpiokeypol)
{
    ASSERT_ERR((((uint32_t)gpiokeypol << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)gpiokeypol << 29));
}

__INLINE uint8_t apb_key_ctrl0_clk_mic_key_det_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void apb_key_ctrl0_clk_mic_key_det_en_setf(uint8_t clkmickeydeten)
{
    ASSERT_ERR((((uint32_t)clkmickeydeten << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)clkmickeydeten << 28));
}

__INLINE uint8_t apb_key_ctrl0_mic_key_det_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE void apb_key_ctrl0_mic_key_det_rst_setf(uint8_t mickeydetrst)
{
    ASSERT_ERR((((uint32_t)mickeydetrst << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)mickeydetrst << 27));
}

__INLINE uint8_t apb_key_ctrl0_micin_int_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void apb_key_ctrl0_micin_int_mask_setf(uint8_t micinintmask)
{
    ASSERT_ERR((((uint32_t)micinintmask << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)micinintmask << 26));
}

__INLINE uint8_t apb_key_ctrl0_micin_int_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_key_ctrl0_micin_int_clr_setf(uint8_t micinintclr)
{
    ASSERT_ERR((((uint32_t)micinintclr << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)micinintclr << 25));
}

__INLINE uint8_t apb_key_ctrl0_micin_key_deb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x01800000)) >> 23);
}

__INLINE void apb_key_ctrl0_micin_key_deb_setf(uint8_t micinkeydeb)
{
    ASSERT_ERR((((uint32_t)micinkeydeb << 23) & ~((uint32_t)0x01800000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x01800000)) | ((uint32_t)micinkeydeb << 23));
}

__INLINE uint8_t apb_key_ctrl0_gpio_key_int_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_key_ctrl0_gpio_key_int_clr_setf(uint8_t gpiokeyintclr)
{
    ASSERT_ERR((((uint32_t)gpiokeyintclr << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)gpiokeyintclr << 22));
}

__INLINE uint8_t apb_key_ctrl0_gpio_key_det_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_key_ctrl0_gpio_key_det_rst_setf(uint8_t gpiokeydetrst)
{
    ASSERT_ERR((((uint32_t)gpiokeydetrst << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)gpiokeydetrst << 21));
}

__INLINE uint8_t apb_key_ctrl0_clk_gpio_key_det_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_key_ctrl0_clk_gpio_key_det_en_setf(uint8_t clkgpiokeydeten)
{
    ASSERT_ERR((((uint32_t)clkgpiokeydeten << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)clkgpiokeydeten << 20));
}

__INLINE uint8_t apb_key_ctrl0_gpio_key_deb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_key_ctrl0_gpio_key_deb_setf(uint8_t gpiokeydeb)
{
    ASSERT_ERR((((uint32_t)gpiokeydeb << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)gpiokeydeb << 16));
}

__INLINE uint8_t apb_key_ctrl0_micin_det_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_key_ctrl0_micin_det_pd_setf(uint8_t micindetpd)
{
    ASSERT_ERR((((uint32_t)micindetpd << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)micindetpd << 15));
}

__INLINE uint8_t apb_key_ctrl0_micin_det_vth_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00007000)) >> 12);
}

__INLINE void apb_key_ctrl0_micin_det_vth_ctrl_setf(uint8_t micindetvthctrl)
{
    ASSERT_ERR((((uint32_t)micindetvthctrl << 12) & ~((uint32_t)0x00007000)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)micindetvthctrl << 12));
}

__INLINE uint8_t apb_key_ctrl0_hss_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_key_ctrl0_hss_mask_setf(uint8_t hssmask)
{
    ASSERT_ERR((((uint32_t)hssmask << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)hssmask << 10));
}

__INLINE uint8_t apb_key_ctrl0_micin_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_key_ctrl0_micin_mask_setf(uint8_t micinmask)
{
    ASSERT_ERR((((uint32_t)micinmask << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)micinmask << 9));
}

__INLINE uint8_t apb_key_ctrl0_gpio_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_key_ctrl0_gpio_mask_setf(uint8_t gpiomask)
{
    ASSERT_ERR((((uint32_t)gpiomask << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)gpiomask << 8));
}

__INLINE uint8_t apb_key_ctrl0_gpio_key_int_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_key_ctrl0_gpio_key_int_mask_setf(uint8_t gpiokeyintmask)
{
    ASSERT_ERR((((uint32_t)gpiokeyintmask << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_KEY_CTRL0_ADDR, (REG_PL_RD(APB_KEY_CTRL0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)gpiokeyintmask << 0));
}

/**
 * @brief AUX_ADC_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28   auxadc_cali_en_reg   0
 *  20:17       saradc_sel_reg   0x0
 *     16     saradc_start_reg   0
 *     03     auxadc_scan_mode   0
 *     02       Auxadc_int_clr   0
 *     01       auxadc_ctrl_sw   0
 *     00      auxadc_fsm_mode   0
 * </pre>
 */
#define APB_AUX_ADC_CTRL0_ADDR   0xC0012140
#define APB_AUX_ADC_CTRL0_OFFSET 0x00000140
#define APB_AUX_ADC_CTRL0_INDEX  0x00000050
#define APB_AUX_ADC_CTRL0_RESET  0x00000000

__INLINE uint32_t apb_aux_adc_ctrl0_get(void)
{
    return REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
}

__INLINE void apb_aux_adc_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, value);
}

// field definitions
#define APB_AUX_ADC_CTRL0_AUXADC_CALI_EN_REG_BIT    ((uint32_t)0x10000000)
#define APB_AUX_ADC_CTRL0_AUXADC_CALI_EN_REG_POS    28
#define APB_AUX_ADC_CTRL0_SARADC_SEL_REG_MASK       ((uint32_t)0x001E0000)
#define APB_AUX_ADC_CTRL0_SARADC_SEL_REG_LSB        17
#define APB_AUX_ADC_CTRL0_SARADC_SEL_REG_WIDTH      ((uint32_t)0x00000004)
#define APB_AUX_ADC_CTRL0_SARADC_START_REG_BIT      ((uint32_t)0x00010000)
#define APB_AUX_ADC_CTRL0_SARADC_START_REG_POS      16
#define APB_AUX_ADC_CTRL0_AUXADC_SCAN_MODE_BIT      ((uint32_t)0x00000008)
#define APB_AUX_ADC_CTRL0_AUXADC_SCAN_MODE_POS      3
#define APB_AUX_ADC_CTRL0_AUXADC_INT_CLR_BIT        ((uint32_t)0x00000004)
#define APB_AUX_ADC_CTRL0_AUXADC_INT_CLR_POS        2
#define APB_AUX_ADC_CTRL0_AUXADC_CTRL_SW_BIT        ((uint32_t)0x00000002)
#define APB_AUX_ADC_CTRL0_AUXADC_CTRL_SW_POS        1
#define APB_AUX_ADC_CTRL0_AUXADC_FSM_MODE_BIT       ((uint32_t)0x00000001)
#define APB_AUX_ADC_CTRL0_AUXADC_FSM_MODE_POS       0

#define APB_AUX_ADC_CTRL0_AUXADC_CALI_EN_REG_RST    0x0
#define APB_AUX_ADC_CTRL0_SARADC_SEL_REG_RST        0x0
#define APB_AUX_ADC_CTRL0_SARADC_START_REG_RST      0x0
#define APB_AUX_ADC_CTRL0_AUXADC_SCAN_MODE_RST      0x0
#define APB_AUX_ADC_CTRL0_AUXADC_INT_CLR_RST        0x0
#define APB_AUX_ADC_CTRL0_AUXADC_CTRL_SW_RST        0x0
#define APB_AUX_ADC_CTRL0_AUXADC_FSM_MODE_RST       0x0

__INLINE void apb_aux_adc_ctrl0_pack(uint8_t auxadccalienreg, uint8_t saradcselreg, uint8_t saradcstartreg, uint8_t auxadcscanmode, uint8_t auxadcintclr, uint8_t auxadcfsmmode)
{
    ASSERT_ERR((((uint32_t)auxadccalienreg << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)saradcselreg << 17) & ~((uint32_t)0x001E0000)) == 0);
    ASSERT_ERR((((uint32_t)saradcstartreg << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)auxadcscanmode << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)auxadcintclr << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)auxadcfsmmode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR,  ((uint32_t)auxadccalienreg << 28) | ((uint32_t)saradcselreg << 17) | ((uint32_t)saradcstartreg << 16) | ((uint32_t)auxadcscanmode << 3) | ((uint32_t)auxadcintclr << 2) | ((uint32_t)auxadcfsmmode << 0));
}

__INLINE void apb_aux_adc_ctrl0_unpack(uint8_t* auxadccalienreg, uint8_t* saradcselreg, uint8_t* saradcstartreg, uint8_t* auxadcscanmode, uint8_t* auxadcintclr, uint8_t* auxadcctrlsw, uint8_t* auxadcfsmmode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    *auxadccalienreg = (localVal & ((uint32_t)0x10000000)) >> 28;
    *saradcselreg = (localVal & ((uint32_t)0x001E0000)) >> 17;
    *saradcstartreg = (localVal & ((uint32_t)0x00010000)) >> 16;
    *auxadcscanmode = (localVal & ((uint32_t)0x00000008)) >> 3;
    *auxadcintclr = (localVal & ((uint32_t)0x00000004)) >> 2;
    *auxadcctrlsw = (localVal & ((uint32_t)0x00000002)) >> 1;
    *auxadcfsmmode = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_aux_adc_ctrl0_auxadc_cali_en_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void apb_aux_adc_ctrl0_auxadc_cali_en_reg_setf(uint8_t auxadccalienreg)
{
    ASSERT_ERR((((uint32_t)auxadccalienreg << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)auxadccalienreg << 28));
}

__INLINE uint8_t apb_aux_adc_ctrl0_saradc_sel_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x001E0000)) >> 17);
}

__INLINE void apb_aux_adc_ctrl0_saradc_sel_reg_setf(uint8_t saradcselreg)
{
    ASSERT_ERR((((uint32_t)saradcselreg << 17) & ~((uint32_t)0x001E0000)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x001E0000)) | ((uint32_t)saradcselreg << 17));
}

__INLINE uint8_t apb_aux_adc_ctrl0_saradc_start_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_aux_adc_ctrl0_saradc_start_reg_setf(uint8_t saradcstartreg)
{
    ASSERT_ERR((((uint32_t)saradcstartreg << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)saradcstartreg << 16));
}

__INLINE uint8_t apb_aux_adc_ctrl0_auxadc_scan_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_aux_adc_ctrl0_auxadc_scan_mode_setf(uint8_t auxadcscanmode)
{
    ASSERT_ERR((((uint32_t)auxadcscanmode << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)auxadcscanmode << 3));
}

__INLINE uint8_t apb_aux_adc_ctrl0_auxadc_int_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_aux_adc_ctrl0_auxadc_int_clr_setf(uint8_t auxadcintclr)
{
    ASSERT_ERR((((uint32_t)auxadcintclr << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)auxadcintclr << 2));
}

__INLINE uint8_t apb_aux_adc_ctrl0_auxadc_ctrl_sw_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_aux_adc_ctrl0_auxadc_fsm_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_aux_adc_ctrl0_auxadc_fsm_mode_setf(uint8_t auxadcfsmmode)
{
    ASSERT_ERR((((uint32_t)auxadcfsmmode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL0_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)auxadcfsmmode << 0));
}

/**
 * @brief AUX_ADC_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:22             Ch2_thrd   0x0
 *  20:11             Ch1_thrd   0x0
 *  09:00             Ch0_thrd   0x0
 * </pre>
 */
#define APB_AUX_ADC_CTRL1_ADDR   0xC0012144
#define APB_AUX_ADC_CTRL1_OFFSET 0x00000144
#define APB_AUX_ADC_CTRL1_INDEX  0x00000051
#define APB_AUX_ADC_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_aux_adc_ctrl1_get(void)
{
    return REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR);
}

__INLINE void apb_aux_adc_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_AUX_ADC_CTRL1_ADDR, value);
}

// field definitions
#define APB_AUX_ADC_CTRL1_CH_2_THRD_MASK   ((uint32_t)0xFFC00000)
#define APB_AUX_ADC_CTRL1_CH_2_THRD_LSB    22
#define APB_AUX_ADC_CTRL1_CH_2_THRD_WIDTH  ((uint32_t)0x0000000A)
#define APB_AUX_ADC_CTRL1_CH_1_THRD_MASK   ((uint32_t)0x001FF800)
#define APB_AUX_ADC_CTRL1_CH_1_THRD_LSB    11
#define APB_AUX_ADC_CTRL1_CH_1_THRD_WIDTH  ((uint32_t)0x0000000A)
#define APB_AUX_ADC_CTRL1_CH_0_THRD_MASK   ((uint32_t)0x000003FF)
#define APB_AUX_ADC_CTRL1_CH_0_THRD_LSB    0
#define APB_AUX_ADC_CTRL1_CH_0_THRD_WIDTH  ((uint32_t)0x0000000A)

#define APB_AUX_ADC_CTRL1_CH_2_THRD_RST    0x0
#define APB_AUX_ADC_CTRL1_CH_1_THRD_RST    0x0
#define APB_AUX_ADC_CTRL1_CH_0_THRD_RST    0x0

__INLINE void apb_aux_adc_ctrl1_pack(uint16_t ch2thrd, uint16_t ch1thrd, uint16_t ch0thrd)
{
    ASSERT_ERR((((uint32_t)ch2thrd << 22) & ~((uint32_t)0xFFC00000)) == 0);
    ASSERT_ERR((((uint32_t)ch1thrd << 11) & ~((uint32_t)0x001FF800)) == 0);
    ASSERT_ERR((((uint32_t)ch0thrd << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL1_ADDR,  ((uint32_t)ch2thrd << 22) | ((uint32_t)ch1thrd << 11) | ((uint32_t)ch0thrd << 0));
}

__INLINE void apb_aux_adc_ctrl1_unpack(uint16_t* ch2thrd, uint16_t* ch1thrd, uint16_t* ch0thrd)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR);
    *ch2thrd = (localVal & ((uint32_t)0xFFC00000)) >> 22;
    *ch1thrd = (localVal & ((uint32_t)0x001FF800)) >> 11;
    *ch0thrd = (localVal & ((uint32_t)0x000003FF)) >> 0;
}

__INLINE uint16_t apb_aux_adc_ctrl1_ch_2_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0xFFC00000)) >> 22);
}

__INLINE void apb_aux_adc_ctrl1_ch_2_thrd_setf(uint16_t ch2thrd)
{
    ASSERT_ERR((((uint32_t)ch2thrd << 22) & ~((uint32_t)0xFFC00000)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL1_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)ch2thrd << 22));
}

__INLINE uint16_t apb_aux_adc_ctrl1_ch_1_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x001FF800)) >> 11);
}

__INLINE void apb_aux_adc_ctrl1_ch_1_thrd_setf(uint16_t ch1thrd)
{
    ASSERT_ERR((((uint32_t)ch1thrd << 11) & ~((uint32_t)0x001FF800)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL1_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR) & ~((uint32_t)0x001FF800)) | ((uint32_t)ch1thrd << 11));
}

__INLINE uint16_t apb_aux_adc_ctrl1_ch_0_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}

__INLINE void apb_aux_adc_ctrl1_ch_0_thrd_setf(uint16_t ch0thrd)
{
    ASSERT_ERR((((uint32_t)ch0thrd << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL1_ADDR, (REG_PL_RD(APB_AUX_ADC_CTRL1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)ch0thrd << 0));
}

/**
 * @brief AUX_ADC_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  21:12     auxadc_rdata_avg   0x0
 *     10          auxadc_done   0
 *  09:00             Ch3_thrd   0x0
 * </pre>
 */
#define APB_AUX_ADC_CTRL2_ADDR   0xC0012148
#define APB_AUX_ADC_CTRL2_OFFSET 0x00000148
#define APB_AUX_ADC_CTRL2_INDEX  0x00000052
#define APB_AUX_ADC_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_aux_adc_ctrl2_get(void)
{
    return REG_PL_RD(APB_AUX_ADC_CTRL2_ADDR);
}

__INLINE void apb_aux_adc_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_AUX_ADC_CTRL2_ADDR, value);
}

// field definitions
#define APB_AUX_ADC_CTRL2_AUXADC_RDATA_AVG_MASK   ((uint32_t)0x003FF000)
#define APB_AUX_ADC_CTRL2_AUXADC_RDATA_AVG_LSB    12
#define APB_AUX_ADC_CTRL2_AUXADC_RDATA_AVG_WIDTH  ((uint32_t)0x0000000A)
#define APB_AUX_ADC_CTRL2_AUXADC_DONE_BIT         ((uint32_t)0x00000400)
#define APB_AUX_ADC_CTRL2_AUXADC_DONE_POS         10
#define APB_AUX_ADC_CTRL2_CH_3_THRD_MASK          ((uint32_t)0x000003FF)
#define APB_AUX_ADC_CTRL2_CH_3_THRD_LSB           0
#define APB_AUX_ADC_CTRL2_CH_3_THRD_WIDTH         ((uint32_t)0x0000000A)

#define APB_AUX_ADC_CTRL2_AUXADC_RDATA_AVG_RST    0x0
#define APB_AUX_ADC_CTRL2_AUXADC_DONE_RST         0x0
#define APB_AUX_ADC_CTRL2_CH_3_THRD_RST           0x0

__INLINE void apb_aux_adc_ctrl2_unpack(uint16_t* auxadcrdataavg, uint8_t* auxadcdone, uint16_t* ch3thrd)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL2_ADDR);
    *auxadcrdataavg = (localVal & ((uint32_t)0x003FF000)) >> 12;
    *auxadcdone = (localVal & ((uint32_t)0x00000400)) >> 10;
    *ch3thrd = (localVal & ((uint32_t)0x000003FF)) >> 0;
}

__INLINE uint16_t apb_aux_adc_ctrl2_auxadc_rdata_avg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x003FF000)) >> 12);
}

__INLINE uint8_t apb_aux_adc_ctrl2_auxadc_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint16_t apb_aux_adc_ctrl2_ch_3_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}

__INLINE void apb_aux_adc_ctrl2_ch_3_thrd_setf(uint16_t ch3thrd)
{
    ASSERT_ERR((((uint32_t)ch3thrd << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL2_ADDR, (uint32_t)ch3thrd << 0);
}

/**
 * @brief AUX_ADC_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  25:16   Auxadc_chan_status   0x0
 *  09:00     Auxadc_chan_mask   0x0
 * </pre>
 */
#define APB_AUX_ADC_CTRL3_ADDR   0xC001214C
#define APB_AUX_ADC_CTRL3_OFFSET 0x0000014C
#define APB_AUX_ADC_CTRL3_INDEX  0x00000053
#define APB_AUX_ADC_CTRL3_RESET  0x00000000

__INLINE uint32_t apb_aux_adc_ctrl3_get(void)
{
    return REG_PL_RD(APB_AUX_ADC_CTRL3_ADDR);
}

__INLINE void apb_aux_adc_ctrl3_set(uint32_t value)
{
    REG_PL_WR(APB_AUX_ADC_CTRL3_ADDR, value);
}

// field definitions
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_STATUS_MASK   ((uint32_t)0x03FF0000)
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_STATUS_LSB    16
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_STATUS_WIDTH  ((uint32_t)0x0000000A)
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_MASK_MASK     ((uint32_t)0x000003FF)
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_MASK_LSB      0
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_MASK_WIDTH    ((uint32_t)0x0000000A)

#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_STATUS_RST    0x0
#define APB_AUX_ADC_CTRL3_AUXADC_CHAN_MASK_RST      0x0

__INLINE void apb_aux_adc_ctrl3_unpack(uint16_t* auxadcchanstatus, uint16_t* auxadcchanmask)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL3_ADDR);
    *auxadcchanstatus = (localVal & ((uint32_t)0x03FF0000)) >> 16;
    *auxadcchanmask = (localVal & ((uint32_t)0x000003FF)) >> 0;
}

__INLINE uint16_t apb_aux_adc_ctrl3_auxadc_chan_status_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x03FF0000)) >> 16);
}

__INLINE uint16_t apb_aux_adc_ctrl3_auxadc_chan_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUX_ADC_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}

__INLINE void apb_aux_adc_ctrl3_auxadc_chan_mask_setf(uint16_t auxadcchanmask)
{
    ASSERT_ERR((((uint32_t)auxadcchanmask << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(APB_AUX_ADC_CTRL3_ADDR, (uint32_t)auxadcchanmask << 0);
}

/**
 * @brief AUX_ADC_CTRL4 register definition
 */
#define APB_AUX_ADC_CTRL4_ADDR   0xC0012150
#define APB_AUX_ADC_CTRL4_OFFSET 0x00000150
#define APB_AUX_ADC_CTRL4_INDEX  0x00000054
#define APB_AUX_ADC_CTRL4_RESET  0x00000000

__INLINE uint32_t apb_aux_adc_ctrl4_get(void)
{
    return REG_PL_RD(APB_AUX_ADC_CTRL4_ADDR);
}

__INLINE void apb_aux_adc_ctrl4_set(uint32_t value)
{
    REG_PL_WR(APB_AUX_ADC_CTRL4_ADDR, value);
}

/**
 * @brief OSC_CALI_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  17:16        High_osc_rsel   0x0
 *     13        osc_cali_done   0
 *     12    Soft_osc_trim_rst   0
 *     11   osc_cali_start_reg   0
 *     09      Fsm_trim_bp_reg   0
 *     08      osc_trim_en_reg   0
 *  07:06   osc_cali_adjust_thrd   0x0
 *  05:04   osc_cali_adjust_intv   0x0
 *     03   osc_cali_code_flag   1
 *     02          osc_high_en   0
 *     01          osc_high_sw   0
 *     00            Low_power   0
 * </pre>
 */
#define APB_OSC_CALI_CTRL0_ADDR   0xC0012180
#define APB_OSC_CALI_CTRL0_OFFSET 0x00000180
#define APB_OSC_CALI_CTRL0_INDEX  0x00000060
#define APB_OSC_CALI_CTRL0_RESET  0x00000008

__INLINE uint32_t apb_osc_cali_ctrl0_get(void)
{
    return REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
}

__INLINE void apb_osc_cali_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, value);
}

// field definitions
#define APB_OSC_CALI_CTRL0_HIGH_OSC_RSEL_MASK          ((uint32_t)0x00030000)
#define APB_OSC_CALI_CTRL0_HIGH_OSC_RSEL_LSB           16
#define APB_OSC_CALI_CTRL0_HIGH_OSC_RSEL_WIDTH         ((uint32_t)0x00000002)
#define APB_OSC_CALI_CTRL0_OSC_CALI_DONE_BIT           ((uint32_t)0x00002000)
#define APB_OSC_CALI_CTRL0_OSC_CALI_DONE_POS           13
#define APB_OSC_CALI_CTRL0_SOFT_OSC_TRIM_RST_BIT       ((uint32_t)0x00001000)
#define APB_OSC_CALI_CTRL0_SOFT_OSC_TRIM_RST_POS       12
#define APB_OSC_CALI_CTRL0_OSC_CALI_START_REG_BIT      ((uint32_t)0x00000800)
#define APB_OSC_CALI_CTRL0_OSC_CALI_START_REG_POS      11
#define APB_OSC_CALI_CTRL0_FSM_TRIM_BP_REG_BIT         ((uint32_t)0x00000200)
#define APB_OSC_CALI_CTRL0_FSM_TRIM_BP_REG_POS         9
#define APB_OSC_CALI_CTRL0_OSC_TRIM_EN_REG_BIT         ((uint32_t)0x00000100)
#define APB_OSC_CALI_CTRL0_OSC_TRIM_EN_REG_POS         8
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_THRD_MASK   ((uint32_t)0x000000C0)
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_THRD_LSB    6
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_THRD_WIDTH  ((uint32_t)0x00000002)
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_INTV_MASK   ((uint32_t)0x00000030)
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_INTV_LSB    4
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_INTV_WIDTH  ((uint32_t)0x00000002)
#define APB_OSC_CALI_CTRL0_OSC_CALI_CODE_FLAG_BIT      ((uint32_t)0x00000008)
#define APB_OSC_CALI_CTRL0_OSC_CALI_CODE_FLAG_POS      3
#define APB_OSC_CALI_CTRL0_OSC_HIGH_EN_BIT             ((uint32_t)0x00000004)
#define APB_OSC_CALI_CTRL0_OSC_HIGH_EN_POS             2
#define APB_OSC_CALI_CTRL0_OSC_HIGH_SW_BIT             ((uint32_t)0x00000002)
#define APB_OSC_CALI_CTRL0_OSC_HIGH_SW_POS             1
#define APB_OSC_CALI_CTRL0_LOW_POWER_BIT               ((uint32_t)0x00000001)
#define APB_OSC_CALI_CTRL0_LOW_POWER_POS               0

#define APB_OSC_CALI_CTRL0_HIGH_OSC_RSEL_RST           0x0
#define APB_OSC_CALI_CTRL0_OSC_CALI_DONE_RST           0x0
#define APB_OSC_CALI_CTRL0_SOFT_OSC_TRIM_RST_RST       0x0
#define APB_OSC_CALI_CTRL0_OSC_CALI_START_REG_RST      0x0
#define APB_OSC_CALI_CTRL0_FSM_TRIM_BP_REG_RST         0x0
#define APB_OSC_CALI_CTRL0_OSC_TRIM_EN_REG_RST         0x0
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_THRD_RST    0x0
#define APB_OSC_CALI_CTRL0_OSC_CALI_ADJUST_INTV_RST    0x0
#define APB_OSC_CALI_CTRL0_OSC_CALI_CODE_FLAG_RST      0x1
#define APB_OSC_CALI_CTRL0_OSC_HIGH_EN_RST             0x0
#define APB_OSC_CALI_CTRL0_OSC_HIGH_SW_RST             0x0
#define APB_OSC_CALI_CTRL0_LOW_POWER_RST               0x0

__INLINE void apb_osc_cali_ctrl0_pack(uint8_t highoscrsel, uint8_t softosctrimrst, uint8_t osccalistartreg, uint8_t fsmtrimbpreg, uint8_t osctrimenreg, uint8_t osccaliadjustthrd, uint8_t osccaliadjustintv, uint8_t osccalicodeflag, uint8_t oschighen, uint8_t lowpower)
{
    ASSERT_ERR((((uint32_t)highoscrsel << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)softosctrimrst << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)osccalistartreg << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)fsmtrimbpreg << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)osctrimenreg << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)osccaliadjustthrd << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)osccaliadjustintv << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)osccalicodeflag << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)oschighen << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)lowpower << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR,  ((uint32_t)highoscrsel << 16) | ((uint32_t)softosctrimrst << 12) | ((uint32_t)osccalistartreg << 11) | ((uint32_t)fsmtrimbpreg << 9) | ((uint32_t)osctrimenreg << 8) | ((uint32_t)osccaliadjustthrd << 6) | ((uint32_t)osccaliadjustintv << 4) | ((uint32_t)osccalicodeflag << 3) | ((uint32_t)oschighen << 2) | ((uint32_t)lowpower << 0));
}

__INLINE void apb_osc_cali_ctrl0_unpack(uint8_t* highoscrsel, uint8_t* osccalidone, uint8_t* softosctrimrst, uint8_t* osccalistartreg, uint8_t* fsmtrimbpreg, uint8_t* osctrimenreg, uint8_t* osccaliadjustthrd, uint8_t* osccaliadjustintv, uint8_t* osccalicodeflag, uint8_t* oschighen, uint8_t* oschighsw, uint8_t* lowpower)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    *highoscrsel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *osccalidone = (localVal & ((uint32_t)0x00002000)) >> 13;
    *softosctrimrst = (localVal & ((uint32_t)0x00001000)) >> 12;
    *osccalistartreg = (localVal & ((uint32_t)0x00000800)) >> 11;
    *fsmtrimbpreg = (localVal & ((uint32_t)0x00000200)) >> 9;
    *osctrimenreg = (localVal & ((uint32_t)0x00000100)) >> 8;
    *osccaliadjustthrd = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *osccaliadjustintv = (localVal & ((uint32_t)0x00000030)) >> 4;
    *osccalicodeflag = (localVal & ((uint32_t)0x00000008)) >> 3;
    *oschighen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *oschighsw = (localVal & ((uint32_t)0x00000002)) >> 1;
    *lowpower = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_osc_cali_ctrl0_high_osc_rsel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_osc_cali_ctrl0_high_osc_rsel_setf(uint8_t highoscrsel)
{
    ASSERT_ERR((((uint32_t)highoscrsel << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)highoscrsel << 16));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_cali_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE uint8_t apb_osc_cali_ctrl0_soft_osc_trim_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_osc_cali_ctrl0_soft_osc_trim_rst_setf(uint8_t softosctrimrst)
{
    ASSERT_ERR((((uint32_t)softosctrimrst << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)softosctrimrst << 12));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_cali_start_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_osc_cali_ctrl0_osc_cali_start_reg_setf(uint8_t osccalistartreg)
{
    ASSERT_ERR((((uint32_t)osccalistartreg << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)osccalistartreg << 11));
}

__INLINE uint8_t apb_osc_cali_ctrl0_fsm_trim_bp_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_osc_cali_ctrl0_fsm_trim_bp_reg_setf(uint8_t fsmtrimbpreg)
{
    ASSERT_ERR((((uint32_t)fsmtrimbpreg << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)fsmtrimbpreg << 9));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_trim_en_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_osc_cali_ctrl0_osc_trim_en_reg_setf(uint8_t osctrimenreg)
{
    ASSERT_ERR((((uint32_t)osctrimenreg << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)osctrimenreg << 8));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_cali_adjust_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_osc_cali_ctrl0_osc_cali_adjust_thrd_setf(uint8_t osccaliadjustthrd)
{
    ASSERT_ERR((((uint32_t)osccaliadjustthrd << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)osccaliadjustthrd << 6));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_cali_adjust_intv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_osc_cali_ctrl0_osc_cali_adjust_intv_setf(uint8_t osccaliadjustintv)
{
    ASSERT_ERR((((uint32_t)osccaliadjustintv << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)osccaliadjustintv << 4));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_cali_code_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_osc_cali_ctrl0_osc_cali_code_flag_setf(uint8_t osccalicodeflag)
{
    ASSERT_ERR((((uint32_t)osccalicodeflag << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)osccalicodeflag << 3));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_high_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_osc_cali_ctrl0_osc_high_en_setf(uint8_t oschighen)
{
    ASSERT_ERR((((uint32_t)oschighen << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)oschighen << 2));
}

__INLINE uint8_t apb_osc_cali_ctrl0_osc_high_sw_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_osc_cali_ctrl0_low_power_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_osc_cali_ctrl0_low_power_setf(uint8_t lowpower)
{
    ASSERT_ERR((((uint32_t)lowpower << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL0_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lowpower << 0));
}

/**
 * @brief OSC_CALI_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  11:06    osc_cali_code_fsm   0x0
 *  05:00    osc_cali_code_reg   0x0
 * </pre>
 */
#define APB_OSC_CALI_CTRL1_ADDR   0xC0012184
#define APB_OSC_CALI_CTRL1_OFFSET 0x00000184
#define APB_OSC_CALI_CTRL1_INDEX  0x00000061
#define APB_OSC_CALI_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_osc_cali_ctrl1_get(void)
{
    return REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR);
}

__INLINE void apb_osc_cali_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_OSC_CALI_CTRL1_ADDR, value);
}

// field definitions
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_FSM_MASK   ((uint32_t)0x00000FC0)
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_FSM_LSB    6
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_FSM_WIDTH  ((uint32_t)0x00000006)
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_REG_MASK   ((uint32_t)0x0000003F)
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_REG_LSB    0
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_REG_WIDTH  ((uint32_t)0x00000006)

#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_FSM_RST    0x0
#define APB_OSC_CALI_CTRL1_OSC_CALI_CODE_REG_RST    0x0

__INLINE void apb_osc_cali_ctrl1_pack(uint8_t osccalicodefsm, uint8_t osccalicodereg)
{
    ASSERT_ERR((((uint32_t)osccalicodefsm << 6) & ~((uint32_t)0x00000FC0)) == 0);
    ASSERT_ERR((((uint32_t)osccalicodereg << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL1_ADDR,  ((uint32_t)osccalicodefsm << 6) | ((uint32_t)osccalicodereg << 0));
}

__INLINE void apb_osc_cali_ctrl1_unpack(uint8_t* osccalicodefsm, uint8_t* osccalicodereg)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR);
    *osccalicodefsm = (localVal & ((uint32_t)0x00000FC0)) >> 6;
    *osccalicodereg = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

__INLINE uint8_t apb_osc_cali_ctrl1_osc_cali_code_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000FC0)) >> 6);
}

__INLINE void apb_osc_cali_ctrl1_osc_cali_code_fsm_setf(uint8_t osccalicodefsm)
{
    ASSERT_ERR((((uint32_t)osccalicodefsm << 6) & ~((uint32_t)0x00000FC0)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL1_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR) & ~((uint32_t)0x00000FC0)) | ((uint32_t)osccalicodefsm << 6));
}

__INLINE uint8_t apb_osc_cali_ctrl1_osc_cali_code_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

__INLINE void apb_osc_cali_ctrl1_osc_cali_code_reg_setf(uint8_t osccalicodereg)
{
    ASSERT_ERR((((uint32_t)osccalicodereg << 0) & ~((uint32_t)0x0000003F)) == 0);
    REG_PL_WR(APB_OSC_CALI_CTRL1_ADDR, (REG_PL_RD(APB_OSC_CALI_CTRL1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)osccalicodereg << 0));
}

/**
 * @brief OSC_CALI_CTRL2 register definition
 */
#define APB_OSC_CALI_CTRL2_ADDR   0xC0012188
#define APB_OSC_CALI_CTRL2_OFFSET 0x00000188
#define APB_OSC_CALI_CTRL2_INDEX  0x00000062
#define APB_OSC_CALI_CTRL2_RESET  0x00000000

__INLINE uint32_t apb_osc_cali_ctrl2_get(void)
{
    return REG_PL_RD(APB_OSC_CALI_CTRL2_ADDR);
}

__INLINE void apb_osc_cali_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_OSC_CALI_CTRL2_ADDR, value);
}

/**
 * @brief PWM_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:16     pwm_duty_ratio_g   0x1
 *  07:00     pwm_duty_ratio_r   0x1
 * </pre>
 */
#define APB_PWM_CTRL0_ADDR   0xC0012200
#define APB_PWM_CTRL0_OFFSET 0x00000200
#define APB_PWM_CTRL0_INDEX  0x00000080
#define APB_PWM_CTRL0_RESET  0x00010001

__INLINE uint32_t apb_pwm_ctrl0_get(void)
{
    return REG_PL_RD(APB_PWM_CTRL0_ADDR);
}

__INLINE void apb_pwm_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_PWM_CTRL0_ADDR, value);
}

// field definitions
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_G_MASK   ((uint32_t)0x00FF0000)
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_G_LSB    16
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_G_WIDTH  ((uint32_t)0x00000008)
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_R_MASK   ((uint32_t)0x000000FF)
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_R_LSB    0
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_R_WIDTH  ((uint32_t)0x00000008)

#define APB_PWM_CTRL0_PWM_DUTY_RATIO_G_RST    0x1
#define APB_PWM_CTRL0_PWM_DUTY_RATIO_R_RST    0x1

__INLINE void apb_pwm_ctrl0_pack(uint8_t pwmdutyratiog, uint8_t pwmdutyratior)
{
    ASSERT_ERR((((uint32_t)pwmdutyratiog << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)pwmdutyratior << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_PWM_CTRL0_ADDR,  ((uint32_t)pwmdutyratiog << 16) | ((uint32_t)pwmdutyratior << 0));
}

__INLINE void apb_pwm_ctrl0_unpack(uint8_t* pwmdutyratiog, uint8_t* pwmdutyratior)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL0_ADDR);
    *pwmdutyratiog = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *pwmdutyratior = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_pwm_ctrl0_pwm_duty_ratio_g_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

__INLINE void apb_pwm_ctrl0_pwm_duty_ratio_g_setf(uint8_t pwmdutyratiog)
{
    ASSERT_ERR((((uint32_t)pwmdutyratiog << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(APB_PWM_CTRL0_ADDR, (REG_PL_RD(APB_PWM_CTRL0_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)pwmdutyratiog << 16));
}

__INLINE uint8_t apb_pwm_ctrl0_pwm_duty_ratio_r_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_pwm_ctrl0_pwm_duty_ratio_r_setf(uint8_t pwmdutyratior)
{
    ASSERT_ERR((((uint32_t)pwmdutyratior << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_PWM_CTRL0_ADDR, (REG_PL_RD(APB_PWM_CTRL0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)pwmdutyratior << 0));
}

/**
 * @brief PWM_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     26             Pwm_b_en   0
 *     25             Pwm_g_en   0
 *     24             Pwm_r_en   0
 *  21:20           Pwm_freq_b   0x0
 *  19:18           Pwm_freq_g   0x0
 *  17:16           Pwm_freq_r   0x0
 *  07:00     pwm_duty_ratio_b   0x1
 * </pre>
 */
#define APB_PWM_CTRL1_ADDR   0xC0012204
#define APB_PWM_CTRL1_OFFSET 0x00000204
#define APB_PWM_CTRL1_INDEX  0x00000081
#define APB_PWM_CTRL1_RESET  0x00000001

__INLINE uint32_t apb_pwm_ctrl1_get(void)
{
    return REG_PL_RD(APB_PWM_CTRL1_ADDR);
}

__INLINE void apb_pwm_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_PWM_CTRL1_ADDR, value);
}

// field definitions
#define APB_PWM_CTRL1_PWM_B_EN_BIT            ((uint32_t)0x04000000)
#define APB_PWM_CTRL1_PWM_B_EN_POS            26
#define APB_PWM_CTRL1_PWM_G_EN_BIT            ((uint32_t)0x02000000)
#define APB_PWM_CTRL1_PWM_G_EN_POS            25
#define APB_PWM_CTRL1_PWM_R_EN_BIT            ((uint32_t)0x01000000)
#define APB_PWM_CTRL1_PWM_R_EN_POS            24
#define APB_PWM_CTRL1_PWM_FREQ_B_MASK         ((uint32_t)0x00300000)
#define APB_PWM_CTRL1_PWM_FREQ_B_LSB          20
#define APB_PWM_CTRL1_PWM_FREQ_B_WIDTH        ((uint32_t)0x00000002)
#define APB_PWM_CTRL1_PWM_FREQ_G_MASK         ((uint32_t)0x000C0000)
#define APB_PWM_CTRL1_PWM_FREQ_G_LSB          18
#define APB_PWM_CTRL1_PWM_FREQ_G_WIDTH        ((uint32_t)0x00000002)
#define APB_PWM_CTRL1_PWM_FREQ_R_MASK         ((uint32_t)0x00030000)
#define APB_PWM_CTRL1_PWM_FREQ_R_LSB          16
#define APB_PWM_CTRL1_PWM_FREQ_R_WIDTH        ((uint32_t)0x00000002)
#define APB_PWM_CTRL1_PWM_DUTY_RATIO_B_MASK   ((uint32_t)0x000000FF)
#define APB_PWM_CTRL1_PWM_DUTY_RATIO_B_LSB    0
#define APB_PWM_CTRL1_PWM_DUTY_RATIO_B_WIDTH  ((uint32_t)0x00000008)

#define APB_PWM_CTRL1_PWM_B_EN_RST            0x0
#define APB_PWM_CTRL1_PWM_G_EN_RST            0x0
#define APB_PWM_CTRL1_PWM_R_EN_RST            0x0
#define APB_PWM_CTRL1_PWM_FREQ_B_RST          0x0
#define APB_PWM_CTRL1_PWM_FREQ_G_RST          0x0
#define APB_PWM_CTRL1_PWM_FREQ_R_RST          0x0
#define APB_PWM_CTRL1_PWM_DUTY_RATIO_B_RST    0x1

__INLINE void apb_pwm_ctrl1_pack(uint8_t pwmben, uint8_t pwmgen, uint8_t pwmren, uint8_t pwmfreqb, uint8_t pwmfreqg, uint8_t pwmfreqr, uint8_t pwmdutyratiob)
{
    ASSERT_ERR((((uint32_t)pwmben << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)pwmgen << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)pwmren << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)pwmfreqb << 20) & ~((uint32_t)0x00300000)) == 0);
    ASSERT_ERR((((uint32_t)pwmfreqg << 18) & ~((uint32_t)0x000C0000)) == 0);
    ASSERT_ERR((((uint32_t)pwmfreqr << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)pwmdutyratiob << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR,  ((uint32_t)pwmben << 26) | ((uint32_t)pwmgen << 25) | ((uint32_t)pwmren << 24) | ((uint32_t)pwmfreqb << 20) | ((uint32_t)pwmfreqg << 18) | ((uint32_t)pwmfreqr << 16) | ((uint32_t)pwmdutyratiob << 0));
}

__INLINE void apb_pwm_ctrl1_unpack(uint8_t* pwmben, uint8_t* pwmgen, uint8_t* pwmren, uint8_t* pwmfreqb, uint8_t* pwmfreqg, uint8_t* pwmfreqr, uint8_t* pwmdutyratiob)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    *pwmben = (localVal & ((uint32_t)0x04000000)) >> 26;
    *pwmgen = (localVal & ((uint32_t)0x02000000)) >> 25;
    *pwmren = (localVal & ((uint32_t)0x01000000)) >> 24;
    *pwmfreqb = (localVal & ((uint32_t)0x00300000)) >> 20;
    *pwmfreqg = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *pwmfreqr = (localVal & ((uint32_t)0x00030000)) >> 16;
    *pwmdutyratiob = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_b_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void apb_pwm_ctrl1_pwm_b_en_setf(uint8_t pwmben)
{
    ASSERT_ERR((((uint32_t)pwmben << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)pwmben << 26));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_g_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_pwm_ctrl1_pwm_g_en_setf(uint8_t pwmgen)
{
    ASSERT_ERR((((uint32_t)pwmgen << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)pwmgen << 25));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_r_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_pwm_ctrl1_pwm_r_en_setf(uint8_t pwmren)
{
    ASSERT_ERR((((uint32_t)pwmren << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)pwmren << 24));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_freq_b_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void apb_pwm_ctrl1_pwm_freq_b_setf(uint8_t pwmfreqb)
{
    ASSERT_ERR((((uint32_t)pwmfreqb << 20) & ~((uint32_t)0x00300000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)pwmfreqb << 20));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_freq_g_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void apb_pwm_ctrl1_pwm_freq_g_setf(uint8_t pwmfreqg)
{
    ASSERT_ERR((((uint32_t)pwmfreqg << 18) & ~((uint32_t)0x000C0000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)pwmfreqg << 18));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_freq_r_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_pwm_ctrl1_pwm_freq_r_setf(uint8_t pwmfreqr)
{
    ASSERT_ERR((((uint32_t)pwmfreqr << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)pwmfreqr << 16));
}

__INLINE uint8_t apb_pwm_ctrl1_pwm_duty_ratio_b_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_pwm_ctrl1_pwm_duty_ratio_b_setf(uint8_t pwmdutyratiob)
{
    ASSERT_ERR((((uint32_t)pwmdutyratiob << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_PWM_CTRL1_ADDR, (REG_PL_RD(APB_PWM_CTRL1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)pwmdutyratiob << 0));
}

/**
 * @brief PWM_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     30               Eable2   0
 *  29:28                Rate2   0x1
 *     24               Eable1   0
 *  23:22                Rate1   0x1
 *     21         Usb_suspendm   0
 *     20        Usb_powerdown   0
 *     19         Usb_rstn_out   0
 *     18           Usb_phy_pd   0
 *  17:16         Usb_osc_mode   0x0
 *     15    Usb_suspendm_mask   0
 *     14         Aux_adc_mask   0
 *     13    dcache_ram_switch   0
 *     12    icache_ram_switch   0
 *     11      voice_flag_mask   0
 *     10    timeout_flag_mask   0
 *     09       voice_flag_clr   0
 *     08     timeout_flag_clr   0
 *     07          volice_flag   0
 *     06         timeout_flag   0
 *     05   dac_third_i2s_left_sw   0
 *  04:03                Rate0   0x1
 *     00               eable0   0
 * </pre>
 */
#define APB_PWM_CTRL2_ADDR   0xC0012208
#define APB_PWM_CTRL2_OFFSET 0x00000208
#define APB_PWM_CTRL2_INDEX  0x00000082
#define APB_PWM_CTRL2_RESET  0x10400008

__INLINE uint32_t apb_pwm_ctrl2_get(void)
{
    return REG_PL_RD(APB_PWM_CTRL2_ADDR);
}

__INLINE void apb_pwm_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_PWM_CTRL2_ADDR, value);
}

// field definitions
#define APB_PWM_CTRL2_EABLE_2_BIT                   ((uint32_t)0x40000000)
#define APB_PWM_CTRL2_EABLE_2_POS                   30
#define APB_PWM_CTRL2_RATE_2_MASK                   ((uint32_t)0x30000000)
#define APB_PWM_CTRL2_RATE_2_LSB                    28
#define APB_PWM_CTRL2_RATE_2_WIDTH                  ((uint32_t)0x00000002)
#define APB_PWM_CTRL2_EABLE_1_BIT                   ((uint32_t)0x01000000)
#define APB_PWM_CTRL2_EABLE_1_POS                   24
#define APB_PWM_CTRL2_RATE_1_MASK                   ((uint32_t)0x00C00000)
#define APB_PWM_CTRL2_RATE_1_LSB                    22
#define APB_PWM_CTRL2_RATE_1_WIDTH                  ((uint32_t)0x00000002)
#define APB_PWM_CTRL2_USB_SUSPENDM_BIT              ((uint32_t)0x00200000)
#define APB_PWM_CTRL2_USB_SUSPENDM_POS              21
#define APB_PWM_CTRL2_USB_POWERDOWN_BIT             ((uint32_t)0x00100000)
#define APB_PWM_CTRL2_USB_POWERDOWN_POS             20
#define APB_PWM_CTRL2_USB_RSTN_OUT_BIT              ((uint32_t)0x00080000)
#define APB_PWM_CTRL2_USB_RSTN_OUT_POS              19
#define APB_PWM_CTRL2_USB_PHY_PD_BIT                ((uint32_t)0x00040000)
#define APB_PWM_CTRL2_USB_PHY_PD_POS                18
#define APB_PWM_CTRL2_USB_OSC_MODE_MASK             ((uint32_t)0x00030000)
#define APB_PWM_CTRL2_USB_OSC_MODE_LSB              16
#define APB_PWM_CTRL2_USB_OSC_MODE_WIDTH            ((uint32_t)0x00000002)
#define APB_PWM_CTRL2_USB_SUSPENDM_MASK_BIT         ((uint32_t)0x00008000)
#define APB_PWM_CTRL2_USB_SUSPENDM_MASK_POS         15
#define APB_PWM_CTRL2_AUX_ADC_MASK_BIT              ((uint32_t)0x00004000)
#define APB_PWM_CTRL2_AUX_ADC_MASK_POS              14
#define APB_PWM_CTRL2_DCACHE_RAM_SWITCH_BIT         ((uint32_t)0x00002000)
#define APB_PWM_CTRL2_DCACHE_RAM_SWITCH_POS         13
#define APB_PWM_CTRL2_ICACHE_RAM_SWITCH_BIT         ((uint32_t)0x00001000)
#define APB_PWM_CTRL2_ICACHE_RAM_SWITCH_POS         12
#define APB_PWM_CTRL2_VOICE_FLAG_MASK_BIT           ((uint32_t)0x00000800)
#define APB_PWM_CTRL2_VOICE_FLAG_MASK_POS           11
#define APB_PWM_CTRL2_TIMEOUT_FLAG_MASK_BIT         ((uint32_t)0x00000400)
#define APB_PWM_CTRL2_TIMEOUT_FLAG_MASK_POS         10
#define APB_PWM_CTRL2_VOICE_FLAG_CLR_BIT            ((uint32_t)0x00000200)
#define APB_PWM_CTRL2_VOICE_FLAG_CLR_POS            9
#define APB_PWM_CTRL2_TIMEOUT_FLAG_CLR_BIT          ((uint32_t)0x00000100)
#define APB_PWM_CTRL2_TIMEOUT_FLAG_CLR_POS          8
#define APB_PWM_CTRL2_VOLICE_FLAG_BIT               ((uint32_t)0x00000080)
#define APB_PWM_CTRL2_VOLICE_FLAG_POS               7
#define APB_PWM_CTRL2_TIMEOUT_FLAG_BIT              ((uint32_t)0x00000040)
#define APB_PWM_CTRL2_TIMEOUT_FLAG_POS              6
#define APB_PWM_CTRL2_DAC_THIRD_I_2S_LEFT_SW_BIT    ((uint32_t)0x00000020)
#define APB_PWM_CTRL2_DAC_THIRD_I_2S_LEFT_SW_POS    5
#define APB_PWM_CTRL2_RATE_0_MASK                   ((uint32_t)0x00000018)
#define APB_PWM_CTRL2_RATE_0_LSB                    3
#define APB_PWM_CTRL2_RATE_0_WIDTH                  ((uint32_t)0x00000002)
#define APB_PWM_CTRL2_EABLE_0_BIT                   ((uint32_t)0x00000001)
#define APB_PWM_CTRL2_EABLE_0_POS                   0

#define APB_PWM_CTRL2_EABLE_2_RST                   0x0
#define APB_PWM_CTRL2_RATE_2_RST                    0x1
#define APB_PWM_CTRL2_EABLE_1_RST                   0x0
#define APB_PWM_CTRL2_RATE_1_RST                    0x1
#define APB_PWM_CTRL2_USB_SUSPENDM_RST              0x0
#define APB_PWM_CTRL2_USB_POWERDOWN_RST             0x0
#define APB_PWM_CTRL2_USB_RSTN_OUT_RST              0x0
#define APB_PWM_CTRL2_USB_PHY_PD_RST                0x0
#define APB_PWM_CTRL2_USB_OSC_MODE_RST              0x0
#define APB_PWM_CTRL2_USB_SUSPENDM_MASK_RST         0x0
#define APB_PWM_CTRL2_AUX_ADC_MASK_RST              0x0
#define APB_PWM_CTRL2_DCACHE_RAM_SWITCH_RST         0x0
#define APB_PWM_CTRL2_ICACHE_RAM_SWITCH_RST         0x0
#define APB_PWM_CTRL2_VOICE_FLAG_MASK_RST           0x0
#define APB_PWM_CTRL2_TIMEOUT_FLAG_MASK_RST         0x0
#define APB_PWM_CTRL2_VOICE_FLAG_CLR_RST            0x0
#define APB_PWM_CTRL2_TIMEOUT_FLAG_CLR_RST          0x0
#define APB_PWM_CTRL2_VOLICE_FLAG_RST               0x0
#define APB_PWM_CTRL2_TIMEOUT_FLAG_RST              0x0
#define APB_PWM_CTRL2_DAC_THIRD_I_2S_LEFT_SW_RST    0x0
#define APB_PWM_CTRL2_RATE_0_RST                    0x1
#define APB_PWM_CTRL2_EABLE_0_RST                   0x0

__INLINE void apb_pwm_ctrl2_pack(uint8_t eable2, uint8_t rate2, uint8_t eable1, uint8_t rate1, uint8_t usbphypd, uint8_t usboscmode, uint8_t usbsuspendmmask, uint8_t auxadcmask, uint8_t dcacheramswitch, uint8_t icacheramswitch, uint8_t voiceflagmask, uint8_t timeoutflagmask, uint8_t voiceflagclr, uint8_t timeoutflagclr, uint8_t dacthirdi2sleftsw, uint8_t rate0, uint8_t eable0)
{
    ASSERT_ERR((((uint32_t)eable2 << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)rate2 << 28) & ~((uint32_t)0x30000000)) == 0);
    ASSERT_ERR((((uint32_t)eable1 << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)rate1 << 22) & ~((uint32_t)0x00C00000)) == 0);
    ASSERT_ERR((((uint32_t)usbphypd << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)usboscmode << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)usbsuspendmmask << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)auxadcmask << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)dcacheramswitch << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)icacheramswitch << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)voiceflagmask << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)timeoutflagmask << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)voiceflagclr << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)timeoutflagclr << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)dacthirdi2sleftsw << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)rate0 << 3) & ~((uint32_t)0x00000018)) == 0);
    ASSERT_ERR((((uint32_t)eable0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR,  ((uint32_t)eable2 << 30) | ((uint32_t)rate2 << 28) | ((uint32_t)eable1 << 24) | ((uint32_t)rate1 << 22) | ((uint32_t)usbphypd << 18) | ((uint32_t)usboscmode << 16) | ((uint32_t)usbsuspendmmask << 15) | ((uint32_t)auxadcmask << 14) | ((uint32_t)dcacheramswitch << 13) | ((uint32_t)icacheramswitch << 12) | ((uint32_t)voiceflagmask << 11) | ((uint32_t)timeoutflagmask << 10) | ((uint32_t)voiceflagclr << 9) | ((uint32_t)timeoutflagclr << 8) | ((uint32_t)dacthirdi2sleftsw << 5) | ((uint32_t)rate0 << 3) | ((uint32_t)eable0 << 0));
}

__INLINE void apb_pwm_ctrl2_unpack(uint8_t* eable2, uint8_t* rate2, uint8_t* eable1, uint8_t* rate1, uint8_t* usbsuspendm, uint8_t* usbpowerdown, uint8_t* usbrstnout, uint8_t* usbphypd, uint8_t* usboscmode, uint8_t* usbsuspendmmask, uint8_t* auxadcmask, uint8_t* dcacheramswitch, uint8_t* icacheramswitch, uint8_t* voiceflagmask, uint8_t* timeoutflagmask, uint8_t* voiceflagclr, uint8_t* timeoutflagclr, uint8_t* voliceflag, uint8_t* timeoutflag, uint8_t* dacthirdi2sleftsw, uint8_t* rate0, uint8_t* eable0)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    *eable2 = (localVal & ((uint32_t)0x40000000)) >> 30;
    *rate2 = (localVal & ((uint32_t)0x30000000)) >> 28;
    *eable1 = (localVal & ((uint32_t)0x01000000)) >> 24;
    *rate1 = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *usbsuspendm = (localVal & ((uint32_t)0x00200000)) >> 21;
    *usbpowerdown = (localVal & ((uint32_t)0x00100000)) >> 20;
    *usbrstnout = (localVal & ((uint32_t)0x00080000)) >> 19;
    *usbphypd = (localVal & ((uint32_t)0x00040000)) >> 18;
    *usboscmode = (localVal & ((uint32_t)0x00030000)) >> 16;
    *usbsuspendmmask = (localVal & ((uint32_t)0x00008000)) >> 15;
    *auxadcmask = (localVal & ((uint32_t)0x00004000)) >> 14;
    *dcacheramswitch = (localVal & ((uint32_t)0x00002000)) >> 13;
    *icacheramswitch = (localVal & ((uint32_t)0x00001000)) >> 12;
    *voiceflagmask = (localVal & ((uint32_t)0x00000800)) >> 11;
    *timeoutflagmask = (localVal & ((uint32_t)0x00000400)) >> 10;
    *voiceflagclr = (localVal & ((uint32_t)0x00000200)) >> 9;
    *timeoutflagclr = (localVal & ((uint32_t)0x00000100)) >> 8;
    *voliceflag = (localVal & ((uint32_t)0x00000080)) >> 7;
    *timeoutflag = (localVal & ((uint32_t)0x00000040)) >> 6;
    *dacthirdi2sleftsw = (localVal & ((uint32_t)0x00000020)) >> 5;
    *rate0 = (localVal & ((uint32_t)0x00000018)) >> 3;
    *eable0 = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_pwm_ctrl2_eable_2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void apb_pwm_ctrl2_eable_2_setf(uint8_t eable2)
{
    ASSERT_ERR((((uint32_t)eable2 << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)eable2 << 30));
}

__INLINE uint8_t apb_pwm_ctrl2_rate_2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void apb_pwm_ctrl2_rate_2_setf(uint8_t rate2)
{
    ASSERT_ERR((((uint32_t)rate2 << 28) & ~((uint32_t)0x30000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)rate2 << 28));
}

__INLINE uint8_t apb_pwm_ctrl2_eable_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_pwm_ctrl2_eable_1_setf(uint8_t eable1)
{
    ASSERT_ERR((((uint32_t)eable1 << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)eable1 << 24));
}

__INLINE uint8_t apb_pwm_ctrl2_rate_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void apb_pwm_ctrl2_rate_1_setf(uint8_t rate1)
{
    ASSERT_ERR((((uint32_t)rate1 << 22) & ~((uint32_t)0x00C00000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)rate1 << 22));
}

__INLINE uint8_t apb_pwm_ctrl2_usb_suspendm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE uint8_t apb_pwm_ctrl2_usb_powerdown_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE uint8_t apb_pwm_ctrl2_usb_rstn_out_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE uint8_t apb_pwm_ctrl2_usb_phy_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_pwm_ctrl2_usb_phy_pd_setf(uint8_t usbphypd)
{
    ASSERT_ERR((((uint32_t)usbphypd << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)usbphypd << 18));
}

__INLINE uint8_t apb_pwm_ctrl2_usb_osc_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_pwm_ctrl2_usb_osc_mode_setf(uint8_t usboscmode)
{
    ASSERT_ERR((((uint32_t)usboscmode << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)usboscmode << 16));
}

__INLINE uint8_t apb_pwm_ctrl2_usb_suspendm_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_pwm_ctrl2_usb_suspendm_mask_setf(uint8_t usbsuspendmmask)
{
    ASSERT_ERR((((uint32_t)usbsuspendmmask << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)usbsuspendmmask << 15));
}

__INLINE uint8_t apb_pwm_ctrl2_aux_adc_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_pwm_ctrl2_aux_adc_mask_setf(uint8_t auxadcmask)
{
    ASSERT_ERR((((uint32_t)auxadcmask << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)auxadcmask << 14));
}

__INLINE uint8_t apb_pwm_ctrl2_dcache_ram_switch_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_pwm_ctrl2_dcache_ram_switch_setf(uint8_t dcacheramswitch)
{
    ASSERT_ERR((((uint32_t)dcacheramswitch << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)dcacheramswitch << 13));
}

__INLINE uint8_t apb_pwm_ctrl2_icache_ram_switch_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_pwm_ctrl2_icache_ram_switch_setf(uint8_t icacheramswitch)
{
    ASSERT_ERR((((uint32_t)icacheramswitch << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)icacheramswitch << 12));
}

__INLINE uint8_t apb_pwm_ctrl2_voice_flag_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_pwm_ctrl2_voice_flag_mask_setf(uint8_t voiceflagmask)
{
    ASSERT_ERR((((uint32_t)voiceflagmask << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)voiceflagmask << 11));
}

__INLINE uint8_t apb_pwm_ctrl2_timeout_flag_mask_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_pwm_ctrl2_timeout_flag_mask_setf(uint8_t timeoutflagmask)
{
    ASSERT_ERR((((uint32_t)timeoutflagmask << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)timeoutflagmask << 10));
}

__INLINE uint8_t apb_pwm_ctrl2_voice_flag_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_pwm_ctrl2_voice_flag_clr_setf(uint8_t voiceflagclr)
{
    ASSERT_ERR((((uint32_t)voiceflagclr << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)voiceflagclr << 9));
}

__INLINE uint8_t apb_pwm_ctrl2_timeout_flag_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_pwm_ctrl2_timeout_flag_clr_setf(uint8_t timeoutflagclr)
{
    ASSERT_ERR((((uint32_t)timeoutflagclr << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)timeoutflagclr << 8));
}

__INLINE uint8_t apb_pwm_ctrl2_volice_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t apb_pwm_ctrl2_timeout_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t apb_pwm_ctrl2_dac_third_i_2s_left_sw_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void apb_pwm_ctrl2_dac_third_i_2s_left_sw_setf(uint8_t dacthirdi2sleftsw)
{
    ASSERT_ERR((((uint32_t)dacthirdi2sleftsw << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)dacthirdi2sleftsw << 5));
}

__INLINE uint8_t apb_pwm_ctrl2_rate_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000018)) >> 3);
}

__INLINE void apb_pwm_ctrl2_rate_0_setf(uint8_t rate0)
{
    ASSERT_ERR((((uint32_t)rate0 << 3) & ~((uint32_t)0x00000018)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000018)) | ((uint32_t)rate0 << 3));
}

__INLINE uint8_t apb_pwm_ctrl2_eable_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_PWM_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_pwm_ctrl2_eable_0_setf(uint8_t eable0)
{
    ASSERT_ERR((((uint32_t)eable0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_PWM_CTRL2_ADDR, (REG_PL_RD(APB_PWM_CTRL2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)eable0 << 0));
}

/**
 * @brief AUDIO_0_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03   audio0_trans_recv_en   0
 *     02    audio0_mas_slv_en   0
 *     01    audio0_I2S_tdm_en   0
 *     00            audio0_en   0
 * </pre>
 */
#define APB_AUDIO_0_CFG_ADDR   0xC0012210
#define APB_AUDIO_0_CFG_OFFSET 0x00000210
#define APB_AUDIO_0_CFG_INDEX  0x00000084
#define APB_AUDIO_0_CFG_RESET  0x00000000

__INLINE uint32_t apb_audio_0_cfg_get(void)
{
    return REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
}

__INLINE void apb_audio_0_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR, value);
}

// field definitions
#define APB_AUDIO_0_CFG_AUDIO_0_TRANS_RECV_EN_BIT    ((uint32_t)0x00000008)
#define APB_AUDIO_0_CFG_AUDIO_0_TRANS_RECV_EN_POS    3
#define APB_AUDIO_0_CFG_AUDIO_0_MAS_SLV_EN_BIT       ((uint32_t)0x00000004)
#define APB_AUDIO_0_CFG_AUDIO_0_MAS_SLV_EN_POS       2
#define APB_AUDIO_0_CFG_AUDIO_0_I_2S_TDM_EN_BIT      ((uint32_t)0x00000002)
#define APB_AUDIO_0_CFG_AUDIO_0_I_2S_TDM_EN_POS      1
#define APB_AUDIO_0_CFG_AUDIO_0_EN_BIT               ((uint32_t)0x00000001)
#define APB_AUDIO_0_CFG_AUDIO_0_EN_POS               0

#define APB_AUDIO_0_CFG_AUDIO_0_TRANS_RECV_EN_RST    0x0
#define APB_AUDIO_0_CFG_AUDIO_0_MAS_SLV_EN_RST       0x0
#define APB_AUDIO_0_CFG_AUDIO_0_I_2S_TDM_EN_RST      0x0
#define APB_AUDIO_0_CFG_AUDIO_0_EN_RST               0x0

__INLINE void apb_audio_0_cfg_pack(uint8_t audio0transrecven, uint8_t audio0masslven, uint8_t audio0i2stdmen, uint8_t audio0en)
{
    ASSERT_ERR((((uint32_t)audio0transrecven << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)audio0masslven << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)audio0i2stdmen << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)audio0en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR,  ((uint32_t)audio0transrecven << 3) | ((uint32_t)audio0masslven << 2) | ((uint32_t)audio0i2stdmen << 1) | ((uint32_t)audio0en << 0));
}

__INLINE void apb_audio_0_cfg_unpack(uint8_t* audio0transrecven, uint8_t* audio0masslven, uint8_t* audio0i2stdmen, uint8_t* audio0en)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
    *audio0transrecven = (localVal & ((uint32_t)0x00000008)) >> 3;
    *audio0masslven = (localVal & ((uint32_t)0x00000004)) >> 2;
    *audio0i2stdmen = (localVal & ((uint32_t)0x00000002)) >> 1;
    *audio0en = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_audio_0_cfg_audio_0_trans_recv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_audio_0_cfg_audio_0_trans_recv_en_setf(uint8_t audio0transrecven)
{
    ASSERT_ERR((((uint32_t)audio0transrecven << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR, (REG_PL_RD(APB_AUDIO_0_CFG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)audio0transrecven << 3));
}

__INLINE uint8_t apb_audio_0_cfg_audio_0_mas_slv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_audio_0_cfg_audio_0_mas_slv_en_setf(uint8_t audio0masslven)
{
    ASSERT_ERR((((uint32_t)audio0masslven << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR, (REG_PL_RD(APB_AUDIO_0_CFG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)audio0masslven << 2));
}

__INLINE uint8_t apb_audio_0_cfg_audio_0_i_2s_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_audio_0_cfg_audio_0_i_2s_tdm_en_setf(uint8_t audio0i2stdmen)
{
    ASSERT_ERR((((uint32_t)audio0i2stdmen << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR, (REG_PL_RD(APB_AUDIO_0_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)audio0i2stdmen << 1));
}

__INLINE uint8_t apb_audio_0_cfg_audio_0_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_audio_0_cfg_audio_0_en_setf(uint8_t audio0en)
{
    ASSERT_ERR((((uint32_t)audio0en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_0_CFG_ADDR, (REG_PL_RD(APB_AUDIO_0_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)audio0en << 0));
}

/**
 * @brief AUDIO_1_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03    audio1_mas_slv_en   0
 *     02   audio1_trans_recv_en   0
 *     01    audio1_i2s_tdm_en   0
 *     00            audio1_en   0
 * </pre>
 */
#define APB_AUDIO_1_CFG_ADDR   0xC0012214
#define APB_AUDIO_1_CFG_OFFSET 0x00000214
#define APB_AUDIO_1_CFG_INDEX  0x00000085
#define APB_AUDIO_1_CFG_RESET  0x00000000

__INLINE uint32_t apb_audio_1_cfg_get(void)
{
    return REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
}

__INLINE void apb_audio_1_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR, value);
}

// field definitions
#define APB_AUDIO_1_CFG_AUDIO_1_MAS_SLV_EN_BIT       ((uint32_t)0x00000008)
#define APB_AUDIO_1_CFG_AUDIO_1_MAS_SLV_EN_POS       3
#define APB_AUDIO_1_CFG_AUDIO_1_TRANS_RECV_EN_BIT    ((uint32_t)0x00000004)
#define APB_AUDIO_1_CFG_AUDIO_1_TRANS_RECV_EN_POS    2
#define APB_AUDIO_1_CFG_AUDIO_1_I_2S_TDM_EN_BIT      ((uint32_t)0x00000002)
#define APB_AUDIO_1_CFG_AUDIO_1_I_2S_TDM_EN_POS      1
#define APB_AUDIO_1_CFG_AUDIO_1_EN_BIT               ((uint32_t)0x00000001)
#define APB_AUDIO_1_CFG_AUDIO_1_EN_POS               0

#define APB_AUDIO_1_CFG_AUDIO_1_MAS_SLV_EN_RST       0x0
#define APB_AUDIO_1_CFG_AUDIO_1_TRANS_RECV_EN_RST    0x0
#define APB_AUDIO_1_CFG_AUDIO_1_I_2S_TDM_EN_RST      0x0
#define APB_AUDIO_1_CFG_AUDIO_1_EN_RST               0x0

__INLINE void apb_audio_1_cfg_pack(uint8_t audio1masslven, uint8_t audio1transrecven, uint8_t audio1i2stdmen, uint8_t audio1en)
{
    ASSERT_ERR((((uint32_t)audio1masslven << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)audio1transrecven << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)audio1i2stdmen << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)audio1en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR,  ((uint32_t)audio1masslven << 3) | ((uint32_t)audio1transrecven << 2) | ((uint32_t)audio1i2stdmen << 1) | ((uint32_t)audio1en << 0));
}

__INLINE void apb_audio_1_cfg_unpack(uint8_t* audio1masslven, uint8_t* audio1transrecven, uint8_t* audio1i2stdmen, uint8_t* audio1en)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
    *audio1masslven = (localVal & ((uint32_t)0x00000008)) >> 3;
    *audio1transrecven = (localVal & ((uint32_t)0x00000004)) >> 2;
    *audio1i2stdmen = (localVal & ((uint32_t)0x00000002)) >> 1;
    *audio1en = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_audio_1_cfg_audio_1_mas_slv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void apb_audio_1_cfg_audio_1_mas_slv_en_setf(uint8_t audio1masslven)
{
    ASSERT_ERR((((uint32_t)audio1masslven << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR, (REG_PL_RD(APB_AUDIO_1_CFG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)audio1masslven << 3));
}

__INLINE uint8_t apb_audio_1_cfg_audio_1_trans_recv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void apb_audio_1_cfg_audio_1_trans_recv_en_setf(uint8_t audio1transrecven)
{
    ASSERT_ERR((((uint32_t)audio1transrecven << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR, (REG_PL_RD(APB_AUDIO_1_CFG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)audio1transrecven << 2));
}

__INLINE uint8_t apb_audio_1_cfg_audio_1_i_2s_tdm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_audio_1_cfg_audio_1_i_2s_tdm_en_setf(uint8_t audio1i2stdmen)
{
    ASSERT_ERR((((uint32_t)audio1i2stdmen << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR, (REG_PL_RD(APB_AUDIO_1_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)audio1i2stdmen << 1));
}

__INLINE uint8_t apb_audio_1_cfg_audio_1_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_AUDIO_1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_audio_1_cfg_audio_1_en_setf(uint8_t audio1en)
{
    ASSERT_ERR((((uint32_t)audio1en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_AUDIO_1_CFG_ADDR, (REG_PL_RD(APB_AUDIO_1_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)audio1en << 0));
}

/**
 * @brief I2S0_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:06    I2sm_lrclk_inv_en   0x0
 *  05:04     I2sm_sclk_inv_en   0x0
 *  03:02       I2s0_data_mode   0x0
 *     01       I2S0_DATA_SIZE   0
 *     00   I2S0_SCLK_LRCLK_RATE   0
 * </pre>
 */
#define APB_I2S0_CFG_ADDR   0xC0012218
#define APB_I2S0_CFG_OFFSET 0x00000218
#define APB_I2S0_CFG_INDEX  0x00000086
#define APB_I2S0_CFG_RESET  0x00000000

__INLINE uint32_t apb_i2s0_cfg_get(void)
{
    return REG_PL_RD(APB_I2S0_CFG_ADDR);
}

__INLINE void apb_i2s0_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_I2S0_CFG_ADDR, value);
}

// field definitions
#define APB_I2S0_CFG_I_2SM_LRCLK_INV_EN_MASK     ((uint32_t)0x000000C0)
#define APB_I2S0_CFG_I_2SM_LRCLK_INV_EN_LSB      6
#define APB_I2S0_CFG_I_2SM_LRCLK_INV_EN_WIDTH    ((uint32_t)0x00000002)
#define APB_I2S0_CFG_I_2SM_SCLK_INV_EN_MASK      ((uint32_t)0x00000030)
#define APB_I2S0_CFG_I_2SM_SCLK_INV_EN_LSB       4
#define APB_I2S0_CFG_I_2SM_SCLK_INV_EN_WIDTH     ((uint32_t)0x00000002)
#define APB_I2S0_CFG_I_2S_0_DATA_MODE_MASK       ((uint32_t)0x0000000C)
#define APB_I2S0_CFG_I_2S_0_DATA_MODE_LSB        2
#define APB_I2S0_CFG_I_2S_0_DATA_MODE_WIDTH      ((uint32_t)0x00000002)
#define APB_I2S0_CFG_I2S0_DATA_SIZE_BIT          ((uint32_t)0x00000002)
#define APB_I2S0_CFG_I2S0_DATA_SIZE_POS          1
#define APB_I2S0_CFG_I2S0_SCLK_LRCLK_RATE_BIT    ((uint32_t)0x00000001)
#define APB_I2S0_CFG_I2S0_SCLK_LRCLK_RATE_POS    0

#define APB_I2S0_CFG_I_2SM_LRCLK_INV_EN_RST      0x0
#define APB_I2S0_CFG_I_2SM_SCLK_INV_EN_RST       0x0
#define APB_I2S0_CFG_I_2S_0_DATA_MODE_RST        0x0
#define APB_I2S0_CFG_I2S0_DATA_SIZE_RST          0x0
#define APB_I2S0_CFG_I2S0_SCLK_LRCLK_RATE_RST    0x0

__INLINE void apb_i2s0_cfg_pack(uint8_t i2smlrclkinven, uint8_t i2smsclkinven, uint8_t i2s0datamode, uint8_t i2s0datasize, uint8_t i2s0sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)i2smlrclkinven << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)i2smsclkinven << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)i2s0datamode << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)i2s0datasize << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)i2s0sclklrclkrate << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR,  ((uint32_t)i2smlrclkinven << 6) | ((uint32_t)i2smsclkinven << 4) | ((uint32_t)i2s0datamode << 2) | ((uint32_t)i2s0datasize << 1) | ((uint32_t)i2s0sclklrclkrate << 0));
}

__INLINE void apb_i2s0_cfg_unpack(uint8_t* i2smlrclkinven, uint8_t* i2smsclkinven, uint8_t* i2s0datamode, uint8_t* i2s0datasize, uint8_t* i2s0sclklrclkrate)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    *i2smlrclkinven = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *i2smsclkinven = (localVal & ((uint32_t)0x00000030)) >> 4;
    *i2s0datamode = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *i2s0datasize = (localVal & ((uint32_t)0x00000002)) >> 1;
    *i2s0sclklrclkrate = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_i2s0_cfg_i_2sm_lrclk_inv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_i2s0_cfg_i_2sm_lrclk_inv_en_setf(uint8_t i2smlrclkinven)
{
    ASSERT_ERR((((uint32_t)i2smlrclkinven << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR, (REG_PL_RD(APB_I2S0_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)i2smlrclkinven << 6));
}

__INLINE uint8_t apb_i2s0_cfg_i_2sm_sclk_inv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_i2s0_cfg_i_2sm_sclk_inv_en_setf(uint8_t i2smsclkinven)
{
    ASSERT_ERR((((uint32_t)i2smsclkinven << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR, (REG_PL_RD(APB_I2S0_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)i2smsclkinven << 4));
}

__INLINE uint8_t apb_i2s0_cfg_i_2s_0_data_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_i2s0_cfg_i_2s_0_data_mode_setf(uint8_t i2s0datamode)
{
    ASSERT_ERR((((uint32_t)i2s0datamode << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR, (REG_PL_RD(APB_I2S0_CFG_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)i2s0datamode << 2));
}

__INLINE uint8_t apb_i2s0_cfg_i2s0_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_i2s0_cfg_i2s0_data_size_setf(uint8_t i2s0datasize)
{
    ASSERT_ERR((((uint32_t)i2s0datasize << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR, (REG_PL_RD(APB_I2S0_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)i2s0datasize << 1));
}

__INLINE uint8_t apb_i2s0_cfg_i2s0_sclk_lrclk_rate_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S0_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_i2s0_cfg_i2s0_sclk_lrclk_rate_setf(uint8_t i2s0sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)i2s0sclklrclkrate << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_I2S0_CFG_ADDR, (REG_PL_RD(APB_I2S0_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)i2s0sclklrclkrate << 0));
}

/**
 * @brief I2S1_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:02       i2s1_data_mode   0x0
 *     01       I2S1_DATA_SIZE   0
 *     00   I2S1_SCLK_LRCLK_RATE   0
 * </pre>
 */
#define APB_I2S1_CFG_ADDR   0xC001221C
#define APB_I2S1_CFG_OFFSET 0x0000021C
#define APB_I2S1_CFG_INDEX  0x00000087
#define APB_I2S1_CFG_RESET  0x00000000

__INLINE uint32_t apb_i2s1_cfg_get(void)
{
    return REG_PL_RD(APB_I2S1_CFG_ADDR);
}

__INLINE void apb_i2s1_cfg_set(uint32_t value)
{
    REG_PL_WR(APB_I2S1_CFG_ADDR, value);
}

// field definitions
#define APB_I2S1_CFG_I_2S_1_DATA_MODE_MASK       ((uint32_t)0x0000000C)
#define APB_I2S1_CFG_I_2S_1_DATA_MODE_LSB        2
#define APB_I2S1_CFG_I_2S_1_DATA_MODE_WIDTH      ((uint32_t)0x00000002)
#define APB_I2S1_CFG_I2S1_DATA_SIZE_BIT          ((uint32_t)0x00000002)
#define APB_I2S1_CFG_I2S1_DATA_SIZE_POS          1
#define APB_I2S1_CFG_I2S1_SCLK_LRCLK_RATE_BIT    ((uint32_t)0x00000001)
#define APB_I2S1_CFG_I2S1_SCLK_LRCLK_RATE_POS    0

#define APB_I2S1_CFG_I_2S_1_DATA_MODE_RST        0x0
#define APB_I2S1_CFG_I2S1_DATA_SIZE_RST          0x0
#define APB_I2S1_CFG_I2S1_SCLK_LRCLK_RATE_RST    0x0

__INLINE void apb_i2s1_cfg_pack(uint8_t i2s1datamode, uint8_t i2s1datasize, uint8_t i2s1sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)i2s1datamode << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)i2s1datasize << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)i2s1sclklrclkrate << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_I2S1_CFG_ADDR,  ((uint32_t)i2s1datamode << 2) | ((uint32_t)i2s1datasize << 1) | ((uint32_t)i2s1sclklrclkrate << 0));
}

__INLINE void apb_i2s1_cfg_unpack(uint8_t* i2s1datamode, uint8_t* i2s1datasize, uint8_t* i2s1sclklrclkrate)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S1_CFG_ADDR);
    *i2s1datamode = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *i2s1datasize = (localVal & ((uint32_t)0x00000002)) >> 1;
    *i2s1sclklrclkrate = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_i2s1_cfg_i_2s_1_data_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_i2s1_cfg_i_2s_1_data_mode_setf(uint8_t i2s1datamode)
{
    ASSERT_ERR((((uint32_t)i2s1datamode << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_I2S1_CFG_ADDR, (REG_PL_RD(APB_I2S1_CFG_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)i2s1datamode << 2));
}

__INLINE uint8_t apb_i2s1_cfg_i2s1_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void apb_i2s1_cfg_i2s1_data_size_setf(uint8_t i2s1datasize)
{
    ASSERT_ERR((((uint32_t)i2s1datasize << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(APB_I2S1_CFG_ADDR, (REG_PL_RD(APB_I2S1_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)i2s1datasize << 1));
}

__INLINE uint8_t apb_i2s1_cfg_i2s1_sclk_lrclk_rate_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_I2S1_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_i2s1_cfg_i2s1_sclk_lrclk_rate_setf(uint8_t i2s1sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)i2s1sclklrclkrate << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_I2S1_CFG_ADDR, (REG_PL_RD(APB_I2S1_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)i2s1sclklrclkrate << 0));
}

/**
 * @brief TDM0_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  28:27   tdm0_invalid_track_hiz_en   0x0
 *  26:25   tdm0_valid_track_hiz_en   0x0
 *     24   tdm0_sclk_pos_lrclk_en   0
 *     23   tdm0_lrclk_frame_level_track   0
 *     22   tdm0_lrclk_frame_level_en   0
 *     21   tdm0_lrclk_fram_pluse   0
 *     20   tdm0_lrclk_frame_length   0
 *  19:18   tdm0_sclk_lrclk_rate   0x0
 *  17:16       tdm0_track_num   0x0
 *  15:00        tdm0_track_en   0x0
 * </pre>
 */
#define APB_TDM0_CFG0_ADDR   0xC0012220
#define APB_TDM0_CFG0_OFFSET 0x00000220
#define APB_TDM0_CFG0_INDEX  0x00000088
#define APB_TDM0_CFG0_RESET  0x00000000

__INLINE uint32_t apb_tdm0_cfg0_get(void)
{
    return REG_PL_RD(APB_TDM0_CFG0_ADDR);
}

__INLINE void apb_tdm0_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_TDM0_CFG0_ADDR, value);
}

// field definitions
#define APB_TDM0_CFG0_TDM_0_INVALID_TRACK_HIZ_EN_MASK      ((uint32_t)0x18000000)
#define APB_TDM0_CFG0_TDM_0_INVALID_TRACK_HIZ_EN_LSB       27
#define APB_TDM0_CFG0_TDM_0_INVALID_TRACK_HIZ_EN_WIDTH     ((uint32_t)0x00000002)
#define APB_TDM0_CFG0_TDM_0_VALID_TRACK_HIZ_EN_MASK        ((uint32_t)0x06000000)
#define APB_TDM0_CFG0_TDM_0_VALID_TRACK_HIZ_EN_LSB         25
#define APB_TDM0_CFG0_TDM_0_VALID_TRACK_HIZ_EN_WIDTH       ((uint32_t)0x00000002)
#define APB_TDM0_CFG0_TDM_0_SCLK_POS_LRCLK_EN_BIT          ((uint32_t)0x01000000)
#define APB_TDM0_CFG0_TDM_0_SCLK_POS_LRCLK_EN_POS          24
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_TRACK_BIT    ((uint32_t)0x00800000)
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_TRACK_POS    23
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_EN_BIT       ((uint32_t)0x00400000)
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_EN_POS       22
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAM_PLUSE_BIT           ((uint32_t)0x00200000)
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAM_PLUSE_POS           21
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LENGTH_BIT         ((uint32_t)0x00100000)
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LENGTH_POS         20
#define APB_TDM0_CFG0_TDM_0_SCLK_LRCLK_RATE_MASK           ((uint32_t)0x000C0000)
#define APB_TDM0_CFG0_TDM_0_SCLK_LRCLK_RATE_LSB            18
#define APB_TDM0_CFG0_TDM_0_SCLK_LRCLK_RATE_WIDTH          ((uint32_t)0x00000002)
#define APB_TDM0_CFG0_TDM_0_TRACK_NUM_MASK                 ((uint32_t)0x00030000)
#define APB_TDM0_CFG0_TDM_0_TRACK_NUM_LSB                  16
#define APB_TDM0_CFG0_TDM_0_TRACK_NUM_WIDTH                ((uint32_t)0x00000002)
#define APB_TDM0_CFG0_TDM_0_TRACK_EN_MASK                  ((uint32_t)0x0000FFFF)
#define APB_TDM0_CFG0_TDM_0_TRACK_EN_LSB                   0
#define APB_TDM0_CFG0_TDM_0_TRACK_EN_WIDTH                 ((uint32_t)0x00000010)

#define APB_TDM0_CFG0_TDM_0_INVALID_TRACK_HIZ_EN_RST       0x0
#define APB_TDM0_CFG0_TDM_0_VALID_TRACK_HIZ_EN_RST         0x0
#define APB_TDM0_CFG0_TDM_0_SCLK_POS_LRCLK_EN_RST          0x0
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_TRACK_RST    0x0
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LEVEL_EN_RST       0x0
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAM_PLUSE_RST           0x0
#define APB_TDM0_CFG0_TDM_0_LRCLK_FRAME_LENGTH_RST         0x0
#define APB_TDM0_CFG0_TDM_0_SCLK_LRCLK_RATE_RST            0x0
#define APB_TDM0_CFG0_TDM_0_TRACK_NUM_RST                  0x0
#define APB_TDM0_CFG0_TDM_0_TRACK_EN_RST                   0x0

__INLINE void apb_tdm0_cfg0_pack(uint8_t tdm0invalidtrackhizen, uint8_t tdm0validtrackhizen, uint8_t tdm0sclkposlrclken, uint8_t tdm0lrclkframeleveltrack, uint8_t tdm0lrclkframelevelen, uint8_t tdm0lrclkframpluse, uint8_t tdm0lrclkframelength, uint8_t tdm0sclklrclkrate, uint8_t tdm0tracknum, uint16_t tdm0tracken)
{
    ASSERT_ERR((((uint32_t)tdm0invalidtrackhizen << 27) & ~((uint32_t)0x18000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0validtrackhizen << 25) & ~((uint32_t)0x06000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0sclkposlrclken << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0lrclkframeleveltrack << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0lrclkframelevelen << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0lrclkframpluse << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0lrclkframelength << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0sclklrclkrate << 18) & ~((uint32_t)0x000C0000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0tracknum << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)tdm0tracken << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR,  ((uint32_t)tdm0invalidtrackhizen << 27) | ((uint32_t)tdm0validtrackhizen << 25) | ((uint32_t)tdm0sclkposlrclken << 24) | ((uint32_t)tdm0lrclkframeleveltrack << 23) | ((uint32_t)tdm0lrclkframelevelen << 22) | ((uint32_t)tdm0lrclkframpluse << 21) | ((uint32_t)tdm0lrclkframelength << 20) | ((uint32_t)tdm0sclklrclkrate << 18) | ((uint32_t)tdm0tracknum << 16) | ((uint32_t)tdm0tracken << 0));
}

__INLINE void apb_tdm0_cfg0_unpack(uint8_t* tdm0invalidtrackhizen, uint8_t* tdm0validtrackhizen, uint8_t* tdm0sclkposlrclken, uint8_t* tdm0lrclkframeleveltrack, uint8_t* tdm0lrclkframelevelen, uint8_t* tdm0lrclkframpluse, uint8_t* tdm0lrclkframelength, uint8_t* tdm0sclklrclkrate, uint8_t* tdm0tracknum, uint16_t* tdm0tracken)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    *tdm0invalidtrackhizen = (localVal & ((uint32_t)0x18000000)) >> 27;
    *tdm0validtrackhizen = (localVal & ((uint32_t)0x06000000)) >> 25;
    *tdm0sclkposlrclken = (localVal & ((uint32_t)0x01000000)) >> 24;
    *tdm0lrclkframeleveltrack = (localVal & ((uint32_t)0x00800000)) >> 23;
    *tdm0lrclkframelevelen = (localVal & ((uint32_t)0x00400000)) >> 22;
    *tdm0lrclkframpluse = (localVal & ((uint32_t)0x00200000)) >> 21;
    *tdm0lrclkframelength = (localVal & ((uint32_t)0x00100000)) >> 20;
    *tdm0sclklrclkrate = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *tdm0tracknum = (localVal & ((uint32_t)0x00030000)) >> 16;
    *tdm0tracken = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_invalid_track_hiz_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x18000000)) >> 27);
}

__INLINE void apb_tdm0_cfg0_tdm_0_invalid_track_hiz_en_setf(uint8_t tdm0invalidtrackhizen)
{
    ASSERT_ERR((((uint32_t)tdm0invalidtrackhizen << 27) & ~((uint32_t)0x18000000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x18000000)) | ((uint32_t)tdm0invalidtrackhizen << 27));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_valid_track_hiz_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x06000000)) >> 25);
}

__INLINE void apb_tdm0_cfg0_tdm_0_valid_track_hiz_en_setf(uint8_t tdm0validtrackhizen)
{
    ASSERT_ERR((((uint32_t)tdm0validtrackhizen << 25) & ~((uint32_t)0x06000000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x06000000)) | ((uint32_t)tdm0validtrackhizen << 25));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_sclk_pos_lrclk_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_tdm0_cfg0_tdm_0_sclk_pos_lrclk_en_setf(uint8_t tdm0sclkposlrclken)
{
    ASSERT_ERR((((uint32_t)tdm0sclkposlrclken << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)tdm0sclkposlrclken << 24));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_lrclk_frame_level_track_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_tdm0_cfg0_tdm_0_lrclk_frame_level_track_setf(uint8_t tdm0lrclkframeleveltrack)
{
    ASSERT_ERR((((uint32_t)tdm0lrclkframeleveltrack << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)tdm0lrclkframeleveltrack << 23));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_lrclk_frame_level_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_tdm0_cfg0_tdm_0_lrclk_frame_level_en_setf(uint8_t tdm0lrclkframelevelen)
{
    ASSERT_ERR((((uint32_t)tdm0lrclkframelevelen << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)tdm0lrclkframelevelen << 22));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_lrclk_fram_pluse_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_tdm0_cfg0_tdm_0_lrclk_fram_pluse_setf(uint8_t tdm0lrclkframpluse)
{
    ASSERT_ERR((((uint32_t)tdm0lrclkframpluse << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)tdm0lrclkframpluse << 21));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_lrclk_frame_length_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_tdm0_cfg0_tdm_0_lrclk_frame_length_setf(uint8_t tdm0lrclkframelength)
{
    ASSERT_ERR((((uint32_t)tdm0lrclkframelength << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)tdm0lrclkframelength << 20));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_sclk_lrclk_rate_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void apb_tdm0_cfg0_tdm_0_sclk_lrclk_rate_setf(uint8_t tdm0sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)tdm0sclklrclkrate << 18) & ~((uint32_t)0x000C0000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)tdm0sclklrclkrate << 18));
}

__INLINE uint8_t apb_tdm0_cfg0_tdm_0_track_num_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_tdm0_cfg0_tdm_0_track_num_setf(uint8_t tdm0tracknum)
{
    ASSERT_ERR((((uint32_t)tdm0tracknum << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)tdm0tracknum << 16));
}

__INLINE uint16_t apb_tdm0_cfg0_tdm_0_track_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void apb_tdm0_cfg0_tdm_0_track_en_setf(uint16_t tdm0tracken)
{
    ASSERT_ERR((((uint32_t)tdm0tracken << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(APB_TDM0_CFG0_ADDR, (REG_PL_RD(APB_TDM0_CFG0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)tdm0tracken << 0));
}

/**
 * @brief TDM0_CFG1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:02   tdm0_track_data_size   0x0
 *     00   tdm0_track_data_mode   0
 * </pre>
 */
#define APB_TDM0_CFG1_ADDR   0xC0012224
#define APB_TDM0_CFG1_OFFSET 0x00000224
#define APB_TDM0_CFG1_INDEX  0x00000089
#define APB_TDM0_CFG1_RESET  0x00000000

__INLINE uint32_t apb_tdm0_cfg1_get(void)
{
    return REG_PL_RD(APB_TDM0_CFG1_ADDR);
}

__INLINE void apb_tdm0_cfg1_set(uint32_t value)
{
    REG_PL_WR(APB_TDM0_CFG1_ADDR, value);
}

// field definitions
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_SIZE_MASK   ((uint32_t)0x0000000C)
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_SIZE_LSB    2
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_SIZE_WIDTH  ((uint32_t)0x00000002)
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_MODE_BIT    ((uint32_t)0x00000001)
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_MODE_POS    0

#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_SIZE_RST    0x0
#define APB_TDM0_CFG1_TDM_0_TRACK_DATA_MODE_RST    0x0

__INLINE void apb_tdm0_cfg1_pack(uint8_t tdm0trackdatasize, uint8_t tdm0trackdatamode)
{
    ASSERT_ERR((((uint32_t)tdm0trackdatasize << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)tdm0trackdatamode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_TDM0_CFG1_ADDR,  ((uint32_t)tdm0trackdatasize << 2) | ((uint32_t)tdm0trackdatamode << 0));
}

__INLINE void apb_tdm0_cfg1_unpack(uint8_t* tdm0trackdatasize, uint8_t* tdm0trackdatamode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG1_ADDR);
    *tdm0trackdatasize = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *tdm0trackdatamode = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_tdm0_cfg1_tdm_0_track_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_tdm0_cfg1_tdm_0_track_data_size_setf(uint8_t tdm0trackdatasize)
{
    ASSERT_ERR((((uint32_t)tdm0trackdatasize << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_TDM0_CFG1_ADDR, (REG_PL_RD(APB_TDM0_CFG1_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)tdm0trackdatasize << 2));
}

__INLINE uint8_t apb_tdm0_cfg1_tdm_0_track_data_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM0_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_tdm0_cfg1_tdm_0_track_data_mode_setf(uint8_t tdm0trackdatamode)
{
    ASSERT_ERR((((uint32_t)tdm0trackdatamode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_TDM0_CFG1_ADDR, (REG_PL_RD(APB_TDM0_CFG1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)tdm0trackdatamode << 0));
}

/**
 * @brief TDM1_CFG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  28:27   tdm1_invalid_track_hiz_en   0x0
 *  26:25   tdm1_valid_track_hiz_en   0x0
 *     24   tdm1_sclk_pos_lrclk_en   0
 *     23   tdm1_lrclk_frame_level_track   0
 *     22   tdm1_lrclk_frame_level_en   0
 *     21   tdm1_lrclk_fram_pluse   0
 *     20   tdm1_lrclk_frame_length   0
 *  19:18   tdm1_sclk_lrclk_rate   0x0
 *  17:16       tdm1_track_num   0x0
 *  15:00        tdm1_track_en   0x0
 * </pre>
 */
#define APB_TDM1_CFG0_ADDR   0xC0012228
#define APB_TDM1_CFG0_OFFSET 0x00000228
#define APB_TDM1_CFG0_INDEX  0x0000008A
#define APB_TDM1_CFG0_RESET  0x00000000

__INLINE uint32_t apb_tdm1_cfg0_get(void)
{
    return REG_PL_RD(APB_TDM1_CFG0_ADDR);
}

__INLINE void apb_tdm1_cfg0_set(uint32_t value)
{
    REG_PL_WR(APB_TDM1_CFG0_ADDR, value);
}

// field definitions
#define APB_TDM1_CFG0_TDM_1_INVALID_TRACK_HIZ_EN_MASK      ((uint32_t)0x18000000)
#define APB_TDM1_CFG0_TDM_1_INVALID_TRACK_HIZ_EN_LSB       27
#define APB_TDM1_CFG0_TDM_1_INVALID_TRACK_HIZ_EN_WIDTH     ((uint32_t)0x00000002)
#define APB_TDM1_CFG0_TDM_1_VALID_TRACK_HIZ_EN_MASK        ((uint32_t)0x06000000)
#define APB_TDM1_CFG0_TDM_1_VALID_TRACK_HIZ_EN_LSB         25
#define APB_TDM1_CFG0_TDM_1_VALID_TRACK_HIZ_EN_WIDTH       ((uint32_t)0x00000002)
#define APB_TDM1_CFG0_TDM_1_SCLK_POS_LRCLK_EN_BIT          ((uint32_t)0x01000000)
#define APB_TDM1_CFG0_TDM_1_SCLK_POS_LRCLK_EN_POS          24
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_TRACK_BIT    ((uint32_t)0x00800000)
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_TRACK_POS    23
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_EN_BIT       ((uint32_t)0x00400000)
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_EN_POS       22
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAM_PLUSE_BIT           ((uint32_t)0x00200000)
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAM_PLUSE_POS           21
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LENGTH_BIT         ((uint32_t)0x00100000)
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LENGTH_POS         20
#define APB_TDM1_CFG0_TDM_1_SCLK_LRCLK_RATE_MASK           ((uint32_t)0x000C0000)
#define APB_TDM1_CFG0_TDM_1_SCLK_LRCLK_RATE_LSB            18
#define APB_TDM1_CFG0_TDM_1_SCLK_LRCLK_RATE_WIDTH          ((uint32_t)0x00000002)
#define APB_TDM1_CFG0_TDM_1_TRACK_NUM_MASK                 ((uint32_t)0x00030000)
#define APB_TDM1_CFG0_TDM_1_TRACK_NUM_LSB                  16
#define APB_TDM1_CFG0_TDM_1_TRACK_NUM_WIDTH                ((uint32_t)0x00000002)
#define APB_TDM1_CFG0_TDM_1_TRACK_EN_MASK                  ((uint32_t)0x0000FFFF)
#define APB_TDM1_CFG0_TDM_1_TRACK_EN_LSB                   0
#define APB_TDM1_CFG0_TDM_1_TRACK_EN_WIDTH                 ((uint32_t)0x00000010)

#define APB_TDM1_CFG0_TDM_1_INVALID_TRACK_HIZ_EN_RST       0x0
#define APB_TDM1_CFG0_TDM_1_VALID_TRACK_HIZ_EN_RST         0x0
#define APB_TDM1_CFG0_TDM_1_SCLK_POS_LRCLK_EN_RST          0x0
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_TRACK_RST    0x0
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LEVEL_EN_RST       0x0
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAM_PLUSE_RST           0x0
#define APB_TDM1_CFG0_TDM_1_LRCLK_FRAME_LENGTH_RST         0x0
#define APB_TDM1_CFG0_TDM_1_SCLK_LRCLK_RATE_RST            0x0
#define APB_TDM1_CFG0_TDM_1_TRACK_NUM_RST                  0x0
#define APB_TDM1_CFG0_TDM_1_TRACK_EN_RST                   0x0

__INLINE void apb_tdm1_cfg0_pack(uint8_t tdm1invalidtrackhizen, uint8_t tdm1validtrackhizen, uint8_t tdm1sclkposlrclken, uint8_t tdm1lrclkframeleveltrack, uint8_t tdm1lrclkframelevelen, uint8_t tdm1lrclkframpluse, uint8_t tdm1lrclkframelength, uint8_t tdm1sclklrclkrate, uint8_t tdm1tracknum, uint16_t tdm1tracken)
{
    ASSERT_ERR((((uint32_t)tdm1invalidtrackhizen << 27) & ~((uint32_t)0x18000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1validtrackhizen << 25) & ~((uint32_t)0x06000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1sclkposlrclken << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1lrclkframeleveltrack << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1lrclkframelevelen << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1lrclkframpluse << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1lrclkframelength << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1sclklrclkrate << 18) & ~((uint32_t)0x000C0000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1tracknum << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)tdm1tracken << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR,  ((uint32_t)tdm1invalidtrackhizen << 27) | ((uint32_t)tdm1validtrackhizen << 25) | ((uint32_t)tdm1sclkposlrclken << 24) | ((uint32_t)tdm1lrclkframeleveltrack << 23) | ((uint32_t)tdm1lrclkframelevelen << 22) | ((uint32_t)tdm1lrclkframpluse << 21) | ((uint32_t)tdm1lrclkframelength << 20) | ((uint32_t)tdm1sclklrclkrate << 18) | ((uint32_t)tdm1tracknum << 16) | ((uint32_t)tdm1tracken << 0));
}

__INLINE void apb_tdm1_cfg0_unpack(uint8_t* tdm1invalidtrackhizen, uint8_t* tdm1validtrackhizen, uint8_t* tdm1sclkposlrclken, uint8_t* tdm1lrclkframeleveltrack, uint8_t* tdm1lrclkframelevelen, uint8_t* tdm1lrclkframpluse, uint8_t* tdm1lrclkframelength, uint8_t* tdm1sclklrclkrate, uint8_t* tdm1tracknum, uint16_t* tdm1tracken)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    *tdm1invalidtrackhizen = (localVal & ((uint32_t)0x18000000)) >> 27;
    *tdm1validtrackhizen = (localVal & ((uint32_t)0x06000000)) >> 25;
    *tdm1sclkposlrclken = (localVal & ((uint32_t)0x01000000)) >> 24;
    *tdm1lrclkframeleveltrack = (localVal & ((uint32_t)0x00800000)) >> 23;
    *tdm1lrclkframelevelen = (localVal & ((uint32_t)0x00400000)) >> 22;
    *tdm1lrclkframpluse = (localVal & ((uint32_t)0x00200000)) >> 21;
    *tdm1lrclkframelength = (localVal & ((uint32_t)0x00100000)) >> 20;
    *tdm1sclklrclkrate = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *tdm1tracknum = (localVal & ((uint32_t)0x00030000)) >> 16;
    *tdm1tracken = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_invalid_track_hiz_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x18000000)) >> 27);
}

__INLINE void apb_tdm1_cfg0_tdm_1_invalid_track_hiz_en_setf(uint8_t tdm1invalidtrackhizen)
{
    ASSERT_ERR((((uint32_t)tdm1invalidtrackhizen << 27) & ~((uint32_t)0x18000000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x18000000)) | ((uint32_t)tdm1invalidtrackhizen << 27));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_valid_track_hiz_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x06000000)) >> 25);
}

__INLINE void apb_tdm1_cfg0_tdm_1_valid_track_hiz_en_setf(uint8_t tdm1validtrackhizen)
{
    ASSERT_ERR((((uint32_t)tdm1validtrackhizen << 25) & ~((uint32_t)0x06000000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x06000000)) | ((uint32_t)tdm1validtrackhizen << 25));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_sclk_pos_lrclk_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_tdm1_cfg0_tdm_1_sclk_pos_lrclk_en_setf(uint8_t tdm1sclkposlrclken)
{
    ASSERT_ERR((((uint32_t)tdm1sclkposlrclken << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)tdm1sclkposlrclken << 24));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_lrclk_frame_level_track_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_tdm1_cfg0_tdm_1_lrclk_frame_level_track_setf(uint8_t tdm1lrclkframeleveltrack)
{
    ASSERT_ERR((((uint32_t)tdm1lrclkframeleveltrack << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)tdm1lrclkframeleveltrack << 23));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_lrclk_frame_level_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_tdm1_cfg0_tdm_1_lrclk_frame_level_en_setf(uint8_t tdm1lrclkframelevelen)
{
    ASSERT_ERR((((uint32_t)tdm1lrclkframelevelen << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)tdm1lrclkframelevelen << 22));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_lrclk_fram_pluse_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_tdm1_cfg0_tdm_1_lrclk_fram_pluse_setf(uint8_t tdm1lrclkframpluse)
{
    ASSERT_ERR((((uint32_t)tdm1lrclkframpluse << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)tdm1lrclkframpluse << 21));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_lrclk_frame_length_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_tdm1_cfg0_tdm_1_lrclk_frame_length_setf(uint8_t tdm1lrclkframelength)
{
    ASSERT_ERR((((uint32_t)tdm1lrclkframelength << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)tdm1lrclkframelength << 20));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_sclk_lrclk_rate_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void apb_tdm1_cfg0_tdm_1_sclk_lrclk_rate_setf(uint8_t tdm1sclklrclkrate)
{
    ASSERT_ERR((((uint32_t)tdm1sclklrclkrate << 18) & ~((uint32_t)0x000C0000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)tdm1sclklrclkrate << 18));
}

__INLINE uint8_t apb_tdm1_cfg0_tdm_1_track_num_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_tdm1_cfg0_tdm_1_track_num_setf(uint8_t tdm1tracknum)
{
    ASSERT_ERR((((uint32_t)tdm1tracknum << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)tdm1tracknum << 16));
}

__INLINE uint16_t apb_tdm1_cfg0_tdm_1_track_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

__INLINE void apb_tdm1_cfg0_tdm_1_track_en_setf(uint16_t tdm1tracken)
{
    ASSERT_ERR((((uint32_t)tdm1tracken << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(APB_TDM1_CFG0_ADDR, (REG_PL_RD(APB_TDM1_CFG0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)tdm1tracken << 0));
}

/**
 * @brief TDM1_CFG1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  03:02   tdm1_track_data_size   0x0
 *     00   tdm1_track_data_mode   0
 * </pre>
 */
#define APB_TDM1_CFG1_ADDR   0xC001222C
#define APB_TDM1_CFG1_OFFSET 0x0000022C
#define APB_TDM1_CFG1_INDEX  0x0000008B
#define APB_TDM1_CFG1_RESET  0x00000000

__INLINE uint32_t apb_tdm1_cfg1_get(void)
{
    return REG_PL_RD(APB_TDM1_CFG1_ADDR);
}

__INLINE void apb_tdm1_cfg1_set(uint32_t value)
{
    REG_PL_WR(APB_TDM1_CFG1_ADDR, value);
}

// field definitions
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_SIZE_MASK   ((uint32_t)0x0000000C)
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_SIZE_LSB    2
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_SIZE_WIDTH  ((uint32_t)0x00000002)
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_MODE_BIT    ((uint32_t)0x00000001)
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_MODE_POS    0

#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_SIZE_RST    0x0
#define APB_TDM1_CFG1_TDM_1_TRACK_DATA_MODE_RST    0x0

__INLINE void apb_tdm1_cfg1_pack(uint8_t tdm1trackdatasize, uint8_t tdm1trackdatamode)
{
    ASSERT_ERR((((uint32_t)tdm1trackdatasize << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)tdm1trackdatamode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_TDM1_CFG1_ADDR,  ((uint32_t)tdm1trackdatasize << 2) | ((uint32_t)tdm1trackdatamode << 0));
}

__INLINE void apb_tdm1_cfg1_unpack(uint8_t* tdm1trackdatasize, uint8_t* tdm1trackdatamode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG1_ADDR);
    *tdm1trackdatasize = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *tdm1trackdatamode = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_tdm1_cfg1_tdm_1_track_data_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_tdm1_cfg1_tdm_1_track_data_size_setf(uint8_t tdm1trackdatasize)
{
    ASSERT_ERR((((uint32_t)tdm1trackdatasize << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_TDM1_CFG1_ADDR, (REG_PL_RD(APB_TDM1_CFG1_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)tdm1trackdatasize << 2));
}

__INLINE uint8_t apb_tdm1_cfg1_tdm_1_track_data_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_TDM1_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_tdm1_cfg1_tdm_1_track_data_mode_setf(uint8_t tdm1trackdatamode)
{
    ASSERT_ERR((((uint32_t)tdm1trackdatamode << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_TDM1_CFG1_ADDR, (REG_PL_RD(APB_TDM1_CFG1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)tdm1trackdatamode << 0));
}

/**
 * @brief POWER_PD_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  28:25   micbias_cfgregs_outputvoltage   0x0
 *     24           micbias_en   0
 *     23           micbias_pd   1
 *     22              xtal_pd   1
 *     21           xtalldo_pd   1
 *     20               ref_pd   0
 *     18      dig_ldoh_bypass   0
 *     17          dig_ldoh_pd   0
 *     16          dig_ldol_pd   0
 *     15           dig_ref_pd   0
 *  14:12          dig_res_sel   0x0
 *     10       high_osc_rst_n   0
 *     09          high_osc_pd   1
 *     08      high_osc_ldo_pd   1
 * </pre>
 */
#define APB_POWER_PD_CTRL0_ADDR   0xC0012240
#define APB_POWER_PD_CTRL0_OFFSET 0x00000240
#define APB_POWER_PD_CTRL0_INDEX  0x00000090
#define APB_POWER_PD_CTRL0_RESET  0x00E00300

__INLINE uint32_t apb_power_pd_ctrl0_get(void)
{
    return REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
}

__INLINE void apb_power_pd_ctrl0_set(uint32_t value)
{
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, value);
}

// field definitions
#define APB_POWER_PD_CTRL0_MICBIAS_CFGREGS_OUTPUTVOLTAGE_MASK   ((uint32_t)0x1E000000)
#define APB_POWER_PD_CTRL0_MICBIAS_CFGREGS_OUTPUTVOLTAGE_LSB    25
#define APB_POWER_PD_CTRL0_MICBIAS_CFGREGS_OUTPUTVOLTAGE_WIDTH  ((uint32_t)0x00000004)
#define APB_POWER_PD_CTRL0_MICBIAS_EN_BIT                       ((uint32_t)0x01000000)
#define APB_POWER_PD_CTRL0_MICBIAS_EN_POS                       24
#define APB_POWER_PD_CTRL0_MICBIAS_PD_BIT                       ((uint32_t)0x00800000)
#define APB_POWER_PD_CTRL0_MICBIAS_PD_POS                       23
#define APB_POWER_PD_CTRL0_XTAL_PD_BIT                          ((uint32_t)0x00400000)
#define APB_POWER_PD_CTRL0_XTAL_PD_POS                          22
#define APB_POWER_PD_CTRL0_XTALLDO_PD_BIT                       ((uint32_t)0x00200000)
#define APB_POWER_PD_CTRL0_XTALLDO_PD_POS                       21
#define APB_POWER_PD_CTRL0_REF_PD_BIT                           ((uint32_t)0x00100000)
#define APB_POWER_PD_CTRL0_REF_PD_POS                           20
#define APB_POWER_PD_CTRL0_DIG_LDOH_BYPASS_BIT                  ((uint32_t)0x00040000)
#define APB_POWER_PD_CTRL0_DIG_LDOH_BYPASS_POS                  18
#define APB_POWER_PD_CTRL0_DIG_LDOH_PD_BIT                      ((uint32_t)0x00020000)
#define APB_POWER_PD_CTRL0_DIG_LDOH_PD_POS                      17
#define APB_POWER_PD_CTRL0_DIG_LDOL_PD_BIT                      ((uint32_t)0x00010000)
#define APB_POWER_PD_CTRL0_DIG_LDOL_PD_POS                      16
#define APB_POWER_PD_CTRL0_DIG_REF_PD_BIT                       ((uint32_t)0x00008000)
#define APB_POWER_PD_CTRL0_DIG_REF_PD_POS                       15
#define APB_POWER_PD_CTRL0_DIG_RES_SEL_MASK                     ((uint32_t)0x00007000)
#define APB_POWER_PD_CTRL0_DIG_RES_SEL_LSB                      12
#define APB_POWER_PD_CTRL0_DIG_RES_SEL_WIDTH                    ((uint32_t)0x00000003)
#define APB_POWER_PD_CTRL0_HIGH_OSC_RST_N_BIT                   ((uint32_t)0x00000400)
#define APB_POWER_PD_CTRL0_HIGH_OSC_RST_N_POS                   10
#define APB_POWER_PD_CTRL0_HIGH_OSC_PD_BIT                      ((uint32_t)0x00000200)
#define APB_POWER_PD_CTRL0_HIGH_OSC_PD_POS                      9
#define APB_POWER_PD_CTRL0_HIGH_OSC_LDO_PD_BIT                  ((uint32_t)0x00000100)
#define APB_POWER_PD_CTRL0_HIGH_OSC_LDO_PD_POS                  8

#define APB_POWER_PD_CTRL0_MICBIAS_CFGREGS_OUTPUTVOLTAGE_RST    0x0
#define APB_POWER_PD_CTRL0_MICBIAS_EN_RST                       0x0
#define APB_POWER_PD_CTRL0_MICBIAS_PD_RST                       0x1
#define APB_POWER_PD_CTRL0_XTAL_PD_RST                          0x1
#define APB_POWER_PD_CTRL0_XTALLDO_PD_RST                       0x1
#define APB_POWER_PD_CTRL0_REF_PD_RST                           0x0
#define APB_POWER_PD_CTRL0_DIG_LDOH_BYPASS_RST                  0x0
#define APB_POWER_PD_CTRL0_DIG_LDOH_PD_RST                      0x0
#define APB_POWER_PD_CTRL0_DIG_LDOL_PD_RST                      0x0
#define APB_POWER_PD_CTRL0_DIG_REF_PD_RST                       0x0
#define APB_POWER_PD_CTRL0_DIG_RES_SEL_RST                      0x0
#define APB_POWER_PD_CTRL0_HIGH_OSC_RST_N_RST                   0x0
#define APB_POWER_PD_CTRL0_HIGH_OSC_PD_RST                      0x1
#define APB_POWER_PD_CTRL0_HIGH_OSC_LDO_PD_RST                  0x1

__INLINE void apb_power_pd_ctrl0_pack(uint8_t micbiascfgregsoutputvoltage, uint8_t micbiasen, uint8_t micbiaspd, uint8_t xtalpd, uint8_t xtalldopd, uint8_t refpd, uint8_t digldohbypass, uint8_t digldohpd, uint8_t digldolpd, uint8_t digrefpd, uint8_t digressel, uint8_t highoscrstn, uint8_t highoscpd, uint8_t highoscldopd)
{
    ASSERT_ERR((((uint32_t)micbiascfgregsoutputvoltage << 25) & ~((uint32_t)0x1E000000)) == 0);
    ASSERT_ERR((((uint32_t)micbiasen << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)micbiaspd << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)xtalpd << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)xtalldopd << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)refpd << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)digldohbypass << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)digldohpd << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)digldolpd << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)digrefpd << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)digressel << 12) & ~((uint32_t)0x00007000)) == 0);
    ASSERT_ERR((((uint32_t)highoscrstn << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)highoscpd << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)highoscldopd << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR,  ((uint32_t)micbiascfgregsoutputvoltage << 25) | ((uint32_t)micbiasen << 24) | ((uint32_t)micbiaspd << 23) | ((uint32_t)xtalpd << 22) | ((uint32_t)xtalldopd << 21) | ((uint32_t)refpd << 20) | ((uint32_t)digldohbypass << 18) | ((uint32_t)digldohpd << 17) | ((uint32_t)digldolpd << 16) | ((uint32_t)digrefpd << 15) | ((uint32_t)digressel << 12) | ((uint32_t)highoscrstn << 10) | ((uint32_t)highoscpd << 9) | ((uint32_t)highoscldopd << 8));
}

__INLINE void apb_power_pd_ctrl0_unpack(uint8_t* micbiascfgregsoutputvoltage, uint8_t* micbiasen, uint8_t* micbiaspd, uint8_t* xtalpd, uint8_t* xtalldopd, uint8_t* refpd, uint8_t* digldohbypass, uint8_t* digldohpd, uint8_t* digldolpd, uint8_t* digrefpd, uint8_t* digressel, uint8_t* highoscrstn, uint8_t* highoscpd, uint8_t* highoscldopd)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    *micbiascfgregsoutputvoltage = (localVal & ((uint32_t)0x1E000000)) >> 25;
    *micbiasen = (localVal & ((uint32_t)0x01000000)) >> 24;
    *micbiaspd = (localVal & ((uint32_t)0x00800000)) >> 23;
    *xtalpd = (localVal & ((uint32_t)0x00400000)) >> 22;
    *xtalldopd = (localVal & ((uint32_t)0x00200000)) >> 21;
    *refpd = (localVal & ((uint32_t)0x00100000)) >> 20;
    *digldohbypass = (localVal & ((uint32_t)0x00040000)) >> 18;
    *digldohpd = (localVal & ((uint32_t)0x00020000)) >> 17;
    *digldolpd = (localVal & ((uint32_t)0x00010000)) >> 16;
    *digrefpd = (localVal & ((uint32_t)0x00008000)) >> 15;
    *digressel = (localVal & ((uint32_t)0x00007000)) >> 12;
    *highoscrstn = (localVal & ((uint32_t)0x00000400)) >> 10;
    *highoscpd = (localVal & ((uint32_t)0x00000200)) >> 9;
    *highoscldopd = (localVal & ((uint32_t)0x00000100)) >> 8;
}

__INLINE uint8_t apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x1E000000)) >> 25);
}

__INLINE void apb_power_pd_ctrl0_micbias_cfgregs_outputvoltage_setf(uint8_t micbiascfgregsoutputvoltage)
{
    ASSERT_ERR((((uint32_t)micbiascfgregsoutputvoltage << 25) & ~((uint32_t)0x1E000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x1E000000)) | ((uint32_t)micbiascfgregsoutputvoltage << 25));
}

__INLINE uint8_t apb_power_pd_ctrl0_micbias_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_power_pd_ctrl0_micbias_en_setf(uint8_t micbiasen)
{
    ASSERT_ERR((((uint32_t)micbiasen << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)micbiasen << 24));
}

__INLINE uint8_t apb_power_pd_ctrl0_micbias_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void apb_power_pd_ctrl0_micbias_pd_setf(uint8_t micbiaspd)
{
    ASSERT_ERR((((uint32_t)micbiaspd << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)micbiaspd << 23));
}

__INLINE uint8_t apb_power_pd_ctrl0_xtal_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE void apb_power_pd_ctrl0_xtal_pd_setf(uint8_t xtalpd)
{
    ASSERT_ERR((((uint32_t)xtalpd << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)xtalpd << 22));
}

__INLINE uint8_t apb_power_pd_ctrl0_xtalldo_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void apb_power_pd_ctrl0_xtalldo_pd_setf(uint8_t xtalldopd)
{
    ASSERT_ERR((((uint32_t)xtalldopd << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)xtalldopd << 21));
}

__INLINE uint8_t apb_power_pd_ctrl0_ref_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_power_pd_ctrl0_ref_pd_setf(uint8_t refpd)
{
    ASSERT_ERR((((uint32_t)refpd << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)refpd << 20));
}

__INLINE uint8_t apb_power_pd_ctrl0_dig_ldoh_bypass_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_power_pd_ctrl0_dig_ldoh_bypass_setf(uint8_t digldohbypass)
{
    ASSERT_ERR((((uint32_t)digldohbypass << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)digldohbypass << 18));
}

__INLINE uint8_t apb_power_pd_ctrl0_dig_ldoh_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_power_pd_ctrl0_dig_ldoh_pd_setf(uint8_t digldohpd)
{
    ASSERT_ERR((((uint32_t)digldohpd << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)digldohpd << 17));
}

__INLINE uint8_t apb_power_pd_ctrl0_dig_ldol_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_power_pd_ctrl0_dig_ldol_pd_setf(uint8_t digldolpd)
{
    ASSERT_ERR((((uint32_t)digldolpd << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)digldolpd << 16));
}

__INLINE uint8_t apb_power_pd_ctrl0_dig_ref_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_power_pd_ctrl0_dig_ref_pd_setf(uint8_t digrefpd)
{
    ASSERT_ERR((((uint32_t)digrefpd << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)digrefpd << 15));
}

__INLINE uint8_t apb_power_pd_ctrl0_dig_res_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00007000)) >> 12);
}

__INLINE void apb_power_pd_ctrl0_dig_res_sel_setf(uint8_t digressel)
{
    ASSERT_ERR((((uint32_t)digressel << 12) & ~((uint32_t)0x00007000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)digressel << 12));
}

__INLINE uint8_t apb_power_pd_ctrl0_high_osc_rst_n_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_power_pd_ctrl0_high_osc_rst_n_setf(uint8_t highoscrstn)
{
    ASSERT_ERR((((uint32_t)highoscrstn << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)highoscrstn << 10));
}

__INLINE uint8_t apb_power_pd_ctrl0_high_osc_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_power_pd_ctrl0_high_osc_pd_setf(uint8_t highoscpd)
{
    ASSERT_ERR((((uint32_t)highoscpd << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)highoscpd << 9));
}

__INLINE uint8_t apb_power_pd_ctrl0_high_osc_ldo_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_power_pd_ctrl0_high_osc_ldo_pd_setf(uint8_t highoscldopd)
{
    ASSERT_ERR((((uint32_t)highoscldopd << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL0_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)highoscldopd << 8));
}

/**
 * @brief POWER_PD_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31   cg_ldo_output_ctrl   0
 *     30      cg_vdd_rail_sel   0
 *     29          cg_sdr_ctrl   0
 *     28          cg_sdl_ctrl   0
 *     27             cg_cp_pd   0
 *     26               cg_pdr   0
 *     25               cg_pdl   0
 *     24            cg_ldo_pd   0
 *  22:20       cg_cp_freq_sel   0x0
 *     19      audac0p5v_probe   0
 *     18               cg_rst   0
 *     17   audio_det_charge_en   0
 *     16         audio_pga_pd   0
 *  14:12   audio_pga_cfgregs_gain   0x0
 *  11:08          audio_vcmet   0x0
 *  07:00    audio_pga_dftregs   0x0
 * </pre>
 */
#define APB_POWER_PD_CTRL1_ADDR   0xC0012244
#define APB_POWER_PD_CTRL1_OFFSET 0x00000244
#define APB_POWER_PD_CTRL1_INDEX  0x00000091
#define APB_POWER_PD_CTRL1_RESET  0x00000000

__INLINE uint32_t apb_power_pd_ctrl1_get(void)
{
    return REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
}

__INLINE void apb_power_pd_ctrl1_set(uint32_t value)
{
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, value);
}

// field definitions
#define APB_POWER_PD_CTRL1_CG_LDO_OUTPUT_CTRL_BIT        ((uint32_t)0x80000000)
#define APB_POWER_PD_CTRL1_CG_LDO_OUTPUT_CTRL_POS        31
#define APB_POWER_PD_CTRL1_CG_VDD_RAIL_SEL_BIT           ((uint32_t)0x40000000)
#define APB_POWER_PD_CTRL1_CG_VDD_RAIL_SEL_POS           30
#define APB_POWER_PD_CTRL1_CG_SDR_CTRL_BIT               ((uint32_t)0x20000000)
#define APB_POWER_PD_CTRL1_CG_SDR_CTRL_POS               29
#define APB_POWER_PD_CTRL1_CG_SDL_CTRL_BIT               ((uint32_t)0x10000000)
#define APB_POWER_PD_CTRL1_CG_SDL_CTRL_POS               28
#define APB_POWER_PD_CTRL1_CG_CP_PD_BIT                  ((uint32_t)0x08000000)
#define APB_POWER_PD_CTRL1_CG_CP_PD_POS                  27
#define APB_POWER_PD_CTRL1_CG_PDR_BIT                    ((uint32_t)0x04000000)
#define APB_POWER_PD_CTRL1_CG_PDR_POS                    26
#define APB_POWER_PD_CTRL1_CG_PDL_BIT                    ((uint32_t)0x02000000)
#define APB_POWER_PD_CTRL1_CG_PDL_POS                    25
#define APB_POWER_PD_CTRL1_CG_LDO_PD_BIT                 ((uint32_t)0x01000000)
#define APB_POWER_PD_CTRL1_CG_LDO_PD_POS                 24
#define APB_POWER_PD_CTRL1_CG_CP_FREQ_SEL_MASK           ((uint32_t)0x00700000)
#define APB_POWER_PD_CTRL1_CG_CP_FREQ_SEL_LSB            20
#define APB_POWER_PD_CTRL1_CG_CP_FREQ_SEL_WIDTH          ((uint32_t)0x00000003)
#define APB_POWER_PD_CTRL1_AUDAC_0P_5V_PROBE_BIT         ((uint32_t)0x00080000)
#define APB_POWER_PD_CTRL1_AUDAC_0P_5V_PROBE_POS         19
#define APB_POWER_PD_CTRL1_CG_RST_BIT                    ((uint32_t)0x00040000)
#define APB_POWER_PD_CTRL1_CG_RST_POS                    18
#define APB_POWER_PD_CTRL1_AUDIO_DET_CHARGE_EN_BIT       ((uint32_t)0x00020000)
#define APB_POWER_PD_CTRL1_AUDIO_DET_CHARGE_EN_POS       17
#define APB_POWER_PD_CTRL1_AUDIO_PGA_PD_BIT              ((uint32_t)0x00010000)
#define APB_POWER_PD_CTRL1_AUDIO_PGA_PD_POS              16
#define APB_POWER_PD_CTRL1_AUDIO_PGA_CFGREGS_GAIN_MASK   ((uint32_t)0x00007000)
#define APB_POWER_PD_CTRL1_AUDIO_PGA_CFGREGS_GAIN_LSB    12
#define APB_POWER_PD_CTRL1_AUDIO_PGA_CFGREGS_GAIN_WIDTH  ((uint32_t)0x00000003)
#define APB_POWER_PD_CTRL1_AUDIO_VCMET_MASK              ((uint32_t)0x00000F00)
#define APB_POWER_PD_CTRL1_AUDIO_VCMET_LSB               8
#define APB_POWER_PD_CTRL1_AUDIO_VCMET_WIDTH             ((uint32_t)0x00000004)
#define APB_POWER_PD_CTRL1_AUDIO_PGA_DFTREGS_MASK        ((uint32_t)0x000000FF)
#define APB_POWER_PD_CTRL1_AUDIO_PGA_DFTREGS_LSB         0
#define APB_POWER_PD_CTRL1_AUDIO_PGA_DFTREGS_WIDTH       ((uint32_t)0x00000008)

#define APB_POWER_PD_CTRL1_CG_LDO_OUTPUT_CTRL_RST        0x0
#define APB_POWER_PD_CTRL1_CG_VDD_RAIL_SEL_RST           0x0
#define APB_POWER_PD_CTRL1_CG_SDR_CTRL_RST               0x0
#define APB_POWER_PD_CTRL1_CG_SDL_CTRL_RST               0x0
#define APB_POWER_PD_CTRL1_CG_CP_PD_RST                  0x0
#define APB_POWER_PD_CTRL1_CG_PDR_RST                    0x0
#define APB_POWER_PD_CTRL1_CG_PDL_RST                    0x0
#define APB_POWER_PD_CTRL1_CG_LDO_PD_RST                 0x0
#define APB_POWER_PD_CTRL1_CG_CP_FREQ_SEL_RST            0x0
#define APB_POWER_PD_CTRL1_AUDAC_0P_5V_PROBE_RST         0x0
#define APB_POWER_PD_CTRL1_CG_RST_RST                    0x0
#define APB_POWER_PD_CTRL1_AUDIO_DET_CHARGE_EN_RST       0x0
#define APB_POWER_PD_CTRL1_AUDIO_PGA_PD_RST              0x0
#define APB_POWER_PD_CTRL1_AUDIO_PGA_CFGREGS_GAIN_RST    0x0
#define APB_POWER_PD_CTRL1_AUDIO_VCMET_RST               0x0
#define APB_POWER_PD_CTRL1_AUDIO_PGA_DFTREGS_RST         0x0

__INLINE void apb_power_pd_ctrl1_pack(uint8_t cgldooutputctrl, uint8_t cgvddrailsel, uint8_t cgsdrctrl, uint8_t cgsdlctrl, uint8_t cgcppd, uint8_t cgpdr, uint8_t cgpdl, uint8_t cgldopd, uint8_t cgcpfreqsel, uint8_t audac0p5vprobe, uint8_t cgrst, uint8_t audiodetchargeen, uint8_t audiopgapd, uint8_t audiopgacfgregsgain, uint8_t audiopgadftregs)
{
    ASSERT_ERR((((uint32_t)cgldooutputctrl << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)cgvddrailsel << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)cgsdrctrl << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)cgsdlctrl << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)cgcppd << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)cgpdr << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)cgpdl << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)cgldopd << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)cgcpfreqsel << 20) & ~((uint32_t)0x00700000)) == 0);
    ASSERT_ERR((((uint32_t)audac0p5vprobe << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)cgrst << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)audiodetchargeen << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)audiopgapd << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)audiopgacfgregsgain << 12) & ~((uint32_t)0x00007000)) == 0);
    ASSERT_ERR((((uint32_t)audiopgadftregs << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR,  ((uint32_t)cgldooutputctrl << 31) | ((uint32_t)cgvddrailsel << 30) | ((uint32_t)cgsdrctrl << 29) | ((uint32_t)cgsdlctrl << 28) | ((uint32_t)cgcppd << 27) | ((uint32_t)cgpdr << 26) | ((uint32_t)cgpdl << 25) | ((uint32_t)cgldopd << 24) | ((uint32_t)cgcpfreqsel << 20) | ((uint32_t)audac0p5vprobe << 19) | ((uint32_t)cgrst << 18) | ((uint32_t)audiodetchargeen << 17) | ((uint32_t)audiopgapd << 16) | ((uint32_t)audiopgacfgregsgain << 12) | ((uint32_t)audiopgadftregs << 0));
}

__INLINE void apb_power_pd_ctrl1_unpack(uint8_t* cgldooutputctrl, uint8_t* cgvddrailsel, uint8_t* cgsdrctrl, uint8_t* cgsdlctrl, uint8_t* cgcppd, uint8_t* cgpdr, uint8_t* cgpdl, uint8_t* cgldopd, uint8_t* cgcpfreqsel, uint8_t* audac0p5vprobe, uint8_t* cgrst, uint8_t* audiodetchargeen, uint8_t* audiopgapd, uint8_t* audiopgacfgregsgain, uint8_t* audiovcmet, uint8_t* audiopgadftregs)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    *cgldooutputctrl = (localVal & ((uint32_t)0x80000000)) >> 31;
    *cgvddrailsel = (localVal & ((uint32_t)0x40000000)) >> 30;
    *cgsdrctrl = (localVal & ((uint32_t)0x20000000)) >> 29;
    *cgsdlctrl = (localVal & ((uint32_t)0x10000000)) >> 28;
    *cgcppd = (localVal & ((uint32_t)0x08000000)) >> 27;
    *cgpdr = (localVal & ((uint32_t)0x04000000)) >> 26;
    *cgpdl = (localVal & ((uint32_t)0x02000000)) >> 25;
    *cgldopd = (localVal & ((uint32_t)0x01000000)) >> 24;
    *cgcpfreqsel = (localVal & ((uint32_t)0x00700000)) >> 20;
    *audac0p5vprobe = (localVal & ((uint32_t)0x00080000)) >> 19;
    *cgrst = (localVal & ((uint32_t)0x00040000)) >> 18;
    *audiodetchargeen = (localVal & ((uint32_t)0x00020000)) >> 17;
    *audiopgapd = (localVal & ((uint32_t)0x00010000)) >> 16;
    *audiopgacfgregsgain = (localVal & ((uint32_t)0x00007000)) >> 12;
    *audiovcmet = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *audiopgadftregs = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_ldo_output_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void apb_power_pd_ctrl1_cg_ldo_output_ctrl_setf(uint8_t cgldooutputctrl)
{
    ASSERT_ERR((((uint32_t)cgldooutputctrl << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)cgldooutputctrl << 31));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_vdd_rail_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE void apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(uint8_t cgvddrailsel)
{
    ASSERT_ERR((((uint32_t)cgvddrailsel << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)cgvddrailsel << 30));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_sdr_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void apb_power_pd_ctrl1_cg_sdr_ctrl_setf(uint8_t cgsdrctrl)
{
    ASSERT_ERR((((uint32_t)cgsdrctrl << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)cgsdrctrl << 29));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_sdl_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void apb_power_pd_ctrl1_cg_sdl_ctrl_setf(uint8_t cgsdlctrl)
{
    ASSERT_ERR((((uint32_t)cgsdlctrl << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)cgsdlctrl << 28));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_cp_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE void apb_power_pd_ctrl1_cg_cp_pd_setf(uint8_t cgcppd)
{
    ASSERT_ERR((((uint32_t)cgcppd << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)cgcppd << 27));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_pdr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void apb_power_pd_ctrl1_cg_pdr_setf(uint8_t cgpdr)
{
    ASSERT_ERR((((uint32_t)cgpdr << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)cgpdr << 26));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_pdl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE void apb_power_pd_ctrl1_cg_pdl_setf(uint8_t cgpdl)
{
    ASSERT_ERR((((uint32_t)cgpdl << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)cgpdl << 25));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_ldo_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE void apb_power_pd_ctrl1_cg_ldo_pd_setf(uint8_t cgldopd)
{
    ASSERT_ERR((((uint32_t)cgldopd << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)cgldopd << 24));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_cp_freq_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00700000)) >> 20);
}

__INLINE void apb_power_pd_ctrl1_cg_cp_freq_sel_setf(uint8_t cgcpfreqsel)
{
    ASSERT_ERR((((uint32_t)cgcpfreqsel << 20) & ~((uint32_t)0x00700000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)cgcpfreqsel << 20));
}

__INLINE uint8_t apb_power_pd_ctrl1_audac_0p_5v_probe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_power_pd_ctrl1_audac_0p_5v_probe_setf(uint8_t audac0p5vprobe)
{
    ASSERT_ERR((((uint32_t)audac0p5vprobe << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)audac0p5vprobe << 19));
}

__INLINE uint8_t apb_power_pd_ctrl1_cg_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_power_pd_ctrl1_cg_rst_setf(uint8_t cgrst)
{
    ASSERT_ERR((((uint32_t)cgrst << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)cgrst << 18));
}

__INLINE uint8_t apb_power_pd_ctrl1_audio_det_charge_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE void apb_power_pd_ctrl1_audio_det_charge_en_setf(uint8_t audiodetchargeen)
{
    ASSERT_ERR((((uint32_t)audiodetchargeen << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)audiodetchargeen << 17));
}

__INLINE uint8_t apb_power_pd_ctrl1_audio_pga_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void apb_power_pd_ctrl1_audio_pga_pd_setf(uint8_t audiopgapd)
{
    ASSERT_ERR((((uint32_t)audiopgapd << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)audiopgapd << 16));
}

__INLINE uint8_t apb_power_pd_ctrl1_audio_pga_cfgregs_gain_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00007000)) >> 12);
}

__INLINE void apb_power_pd_ctrl1_audio_pga_cfgregs_gain_setf(uint8_t audiopgacfgregsgain)
{
    ASSERT_ERR((((uint32_t)audiopgacfgregsgain << 12) & ~((uint32_t)0x00007000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)audiopgacfgregsgain << 12));
}

__INLINE uint8_t apb_power_pd_ctrl1_audio_vcmet_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE uint8_t apb_power_pd_ctrl1_audio_pga_dftregs_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_power_pd_ctrl1_audio_pga_dftregs_setf(uint8_t audiopgadftregs)
{
    ASSERT_ERR((((uint32_t)audiopgadftregs << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL1_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)audiopgadftregs << 0));
}

/**
 * @brief POWER_PD_CTRL2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     22     Jack_ins_deb_out   0
 *  21:20            Hss_hp_jk   0x0
 *     18   Hss_jack_pin_order_flag   0
 *  17:16       Mic_det_thresh   0x0
 *     15   Hss_jack_type_sts_reg   0
 *     14   Hss_jack_pin_order_sts_reg   0
 *     13       Hss_hp_det_reg   0
 *     12      Hss_mic_det_reg   0
 *     11       Hss_det_pd_reg   1
 *     00        Hss_ctrl_flag   1
 * </pre>
 */
#define APB_POWER_PD_CTRL2_ADDR   0xC0012248
#define APB_POWER_PD_CTRL2_OFFSET 0x00000248
#define APB_POWER_PD_CTRL2_INDEX  0x00000092
#define APB_POWER_PD_CTRL2_RESET  0x00000801

__INLINE uint32_t apb_power_pd_ctrl2_get(void)
{
    return REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
}

__INLINE void apb_power_pd_ctrl2_set(uint32_t value)
{
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, value);
}

// field definitions
#define APB_POWER_PD_CTRL2_JACK_INS_DEB_OUT_BIT              ((uint32_t)0x00400000)
#define APB_POWER_PD_CTRL2_JACK_INS_DEB_OUT_POS              22
#define APB_POWER_PD_CTRL2_HSS_HP_JK_MASK                    ((uint32_t)0x00300000)
#define APB_POWER_PD_CTRL2_HSS_HP_JK_LSB                     20
#define APB_POWER_PD_CTRL2_HSS_HP_JK_WIDTH                   ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_FLAG_BIT       ((uint32_t)0x00040000)
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_FLAG_POS       18
#define APB_POWER_PD_CTRL2_MIC_DET_THRESH_MASK               ((uint32_t)0x00030000)
#define APB_POWER_PD_CTRL2_MIC_DET_THRESH_LSB                16
#define APB_POWER_PD_CTRL2_MIC_DET_THRESH_WIDTH              ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL2_HSS_JACK_TYPE_STS_REG_BIT         ((uint32_t)0x00008000)
#define APB_POWER_PD_CTRL2_HSS_JACK_TYPE_STS_REG_POS         15
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_STS_REG_BIT    ((uint32_t)0x00004000)
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_STS_REG_POS    14
#define APB_POWER_PD_CTRL2_HSS_HP_DET_REG_BIT                ((uint32_t)0x00002000)
#define APB_POWER_PD_CTRL2_HSS_HP_DET_REG_POS                13
#define APB_POWER_PD_CTRL2_HSS_MIC_DET_REG_BIT               ((uint32_t)0x00001000)
#define APB_POWER_PD_CTRL2_HSS_MIC_DET_REG_POS               12
#define APB_POWER_PD_CTRL2_HSS_DET_PD_REG_BIT                ((uint32_t)0x00000800)
#define APB_POWER_PD_CTRL2_HSS_DET_PD_REG_POS                11
#define APB_POWER_PD_CTRL2_HSS_CTRL_FLAG_BIT                 ((uint32_t)0x00000001)
#define APB_POWER_PD_CTRL2_HSS_CTRL_FLAG_POS                 0

#define APB_POWER_PD_CTRL2_JACK_INS_DEB_OUT_RST              0x0
#define APB_POWER_PD_CTRL2_HSS_HP_JK_RST                     0x0
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_FLAG_RST       0x0
#define APB_POWER_PD_CTRL2_MIC_DET_THRESH_RST                0x0
#define APB_POWER_PD_CTRL2_HSS_JACK_TYPE_STS_REG_RST         0x0
#define APB_POWER_PD_CTRL2_HSS_JACK_PIN_ORDER_STS_REG_RST    0x0
#define APB_POWER_PD_CTRL2_HSS_HP_DET_REG_RST                0x0
#define APB_POWER_PD_CTRL2_HSS_MIC_DET_REG_RST               0x0
#define APB_POWER_PD_CTRL2_HSS_DET_PD_REG_RST                0x1
#define APB_POWER_PD_CTRL2_HSS_CTRL_FLAG_RST                 0x1

__INLINE void apb_power_pd_ctrl2_pack(uint8_t micdetthresh, uint8_t hssjacktypestsreg, uint8_t hssjackpinorderstsreg, uint8_t hsshpdetreg, uint8_t hssmicdetreg, uint8_t hssdetpdreg, uint8_t hssctrlflag)
{
    ASSERT_ERR((((uint32_t)micdetthresh << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)hssjacktypestsreg << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)hssjackpinorderstsreg << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)hsshpdetreg << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)hssmicdetreg << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)hssdetpdreg << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)hssctrlflag << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR,  ((uint32_t)micdetthresh << 16) | ((uint32_t)hssjacktypestsreg << 15) | ((uint32_t)hssjackpinorderstsreg << 14) | ((uint32_t)hsshpdetreg << 13) | ((uint32_t)hssmicdetreg << 12) | ((uint32_t)hssdetpdreg << 11) | ((uint32_t)hssctrlflag << 0));
}

__INLINE void apb_power_pd_ctrl2_unpack(uint8_t* jackinsdebout, uint8_t* hsshpjk, uint8_t* hssjackpinorderflag, uint8_t* micdetthresh, uint8_t* hssjacktypestsreg, uint8_t* hssjackpinorderstsreg, uint8_t* hsshpdetreg, uint8_t* hssmicdetreg, uint8_t* hssdetpdreg, uint8_t* hssctrlflag)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    *jackinsdebout = (localVal & ((uint32_t)0x00400000)) >> 22;
    *hsshpjk = (localVal & ((uint32_t)0x00300000)) >> 20;
    *hssjackpinorderflag = (localVal & ((uint32_t)0x00040000)) >> 18;
    *micdetthresh = (localVal & ((uint32_t)0x00030000)) >> 16;
    *hssjacktypestsreg = (localVal & ((uint32_t)0x00008000)) >> 15;
    *hssjackpinorderstsreg = (localVal & ((uint32_t)0x00004000)) >> 14;
    *hsshpdetreg = (localVal & ((uint32_t)0x00002000)) >> 13;
    *hssmicdetreg = (localVal & ((uint32_t)0x00001000)) >> 12;
    *hssdetpdreg = (localVal & ((uint32_t)0x00000800)) >> 11;
    *hssctrlflag = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_power_pd_ctrl2_jack_ins_deb_out_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_hp_jk_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_jack_pin_order_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t apb_power_pd_ctrl2_mic_det_thresh_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_power_pd_ctrl2_mic_det_thresh_setf(uint8_t micdetthresh)
{
    ASSERT_ERR((((uint32_t)micdetthresh << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)micdetthresh << 16));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_jack_type_sts_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_power_pd_ctrl2_hss_jack_type_sts_reg_setf(uint8_t hssjacktypestsreg)
{
    ASSERT_ERR((((uint32_t)hssjacktypestsreg << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)hssjacktypestsreg << 15));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_power_pd_ctrl2_hss_jack_pin_order_sts_reg_setf(uint8_t hssjackpinorderstsreg)
{
    ASSERT_ERR((((uint32_t)hssjackpinorderstsreg << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)hssjackpinorderstsreg << 14));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_hp_det_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_power_pd_ctrl2_hss_hp_det_reg_setf(uint8_t hsshpdetreg)
{
    ASSERT_ERR((((uint32_t)hsshpdetreg << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)hsshpdetreg << 13));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_mic_det_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_power_pd_ctrl2_hss_mic_det_reg_setf(uint8_t hssmicdetreg)
{
    ASSERT_ERR((((uint32_t)hssmicdetreg << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)hssmicdetreg << 12));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_det_pd_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_power_pd_ctrl2_hss_det_pd_reg_setf(uint8_t hssdetpdreg)
{
    ASSERT_ERR((((uint32_t)hssdetpdreg << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hssdetpdreg << 11));
}

__INLINE uint8_t apb_power_pd_ctrl2_hss_ctrl_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL2_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void apb_power_pd_ctrl2_hss_ctrl_flag_setf(uint8_t hssctrlflag)
{
    ASSERT_ERR((((uint32_t)hssctrlflag << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL2_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hssctrlflag << 0));
}

/**
 * @brief POWER_PD_CTRL3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     30   jack_insertion_sts   0
 *     29     E_jack_det_compl   0
 *     28       E_jack_removal   0
 *     27     E_jack_insertion   0
 *     26   jack_pin_order_sts   0
 *     25        jack_type_sts   0
 *     24       micbias_up_sts   0
 *     23         mic_det_done   0
 *     22          hp_det_done   0
 *  21:20          mic_imp_sts   0x0
 *  19:18        ring1_imp_sts   0x0
 *  17:16          tip_imp_sts   0x0
 *     15            hp_det_en   0
 *     14         jack_type_en   0
 *     13   E_jack_insertion_clr   0
 *     12   E_jack_removal_clr   0
 *     11   E_jack_det_compl_clr   0
 *     10     M_jack_insertion   0
 *     09       M_jack_removal   0
 *     08     M_jack_det_compl   0
 *  07:06           hp_det_deb   0x1
 *  05:04         jack_ins_deb   0x1
 *  03:02        jack_det_rate   0x3
 *  01:00         jack_rem_deb   0x3
 * </pre>
 */
#define APB_POWER_PD_CTRL3_ADDR   0xC001224C
#define APB_POWER_PD_CTRL3_OFFSET 0x0000024C
#define APB_POWER_PD_CTRL3_INDEX  0x00000093
#define APB_POWER_PD_CTRL3_RESET  0x0000005F

__INLINE uint32_t apb_power_pd_ctrl3_get(void)
{
    return REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
}

__INLINE void apb_power_pd_ctrl3_set(uint32_t value)
{
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, value);
}

// field definitions
#define APB_POWER_PD_CTRL3_JACK_INSERTION_STS_BIT      ((uint32_t)0x40000000)
#define APB_POWER_PD_CTRL3_JACK_INSERTION_STS_POS      30
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_BIT        ((uint32_t)0x20000000)
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_POS        29
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_BIT          ((uint32_t)0x10000000)
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_POS          28
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_BIT        ((uint32_t)0x08000000)
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_POS        27
#define APB_POWER_PD_CTRL3_JACK_PIN_ORDER_STS_BIT      ((uint32_t)0x04000000)
#define APB_POWER_PD_CTRL3_JACK_PIN_ORDER_STS_POS      26
#define APB_POWER_PD_CTRL3_JACK_TYPE_STS_BIT           ((uint32_t)0x02000000)
#define APB_POWER_PD_CTRL3_JACK_TYPE_STS_POS           25
#define APB_POWER_PD_CTRL3_MICBIAS_UP_STS_BIT          ((uint32_t)0x01000000)
#define APB_POWER_PD_CTRL3_MICBIAS_UP_STS_POS          24
#define APB_POWER_PD_CTRL3_MIC_DET_DONE_BIT            ((uint32_t)0x00800000)
#define APB_POWER_PD_CTRL3_MIC_DET_DONE_POS            23
#define APB_POWER_PD_CTRL3_HP_DET_DONE_BIT             ((uint32_t)0x00400000)
#define APB_POWER_PD_CTRL3_HP_DET_DONE_POS             22
#define APB_POWER_PD_CTRL3_MIC_IMP_STS_MASK            ((uint32_t)0x00300000)
#define APB_POWER_PD_CTRL3_MIC_IMP_STS_LSB             20
#define APB_POWER_PD_CTRL3_MIC_IMP_STS_WIDTH           ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_RING_1_IMP_STS_MASK         ((uint32_t)0x000C0000)
#define APB_POWER_PD_CTRL3_RING_1_IMP_STS_LSB          18
#define APB_POWER_PD_CTRL3_RING_1_IMP_STS_WIDTH        ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_TIP_IMP_STS_MASK            ((uint32_t)0x00030000)
#define APB_POWER_PD_CTRL3_TIP_IMP_STS_LSB             16
#define APB_POWER_PD_CTRL3_TIP_IMP_STS_WIDTH           ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_HP_DET_EN_BIT               ((uint32_t)0x00008000)
#define APB_POWER_PD_CTRL3_HP_DET_EN_POS               15
#define APB_POWER_PD_CTRL3_JACK_TYPE_EN_BIT            ((uint32_t)0x00004000)
#define APB_POWER_PD_CTRL3_JACK_TYPE_EN_POS            14
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_CLR_BIT    ((uint32_t)0x00002000)
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_CLR_POS    13
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_CLR_BIT      ((uint32_t)0x00001000)
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_CLR_POS      12
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_CLR_BIT    ((uint32_t)0x00000800)
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_CLR_POS    11
#define APB_POWER_PD_CTRL3_M_JACK_INSERTION_BIT        ((uint32_t)0x00000400)
#define APB_POWER_PD_CTRL3_M_JACK_INSERTION_POS        10
#define APB_POWER_PD_CTRL3_M_JACK_REMOVAL_BIT          ((uint32_t)0x00000200)
#define APB_POWER_PD_CTRL3_M_JACK_REMOVAL_POS          9
#define APB_POWER_PD_CTRL3_M_JACK_DET_COMPL_BIT        ((uint32_t)0x00000100)
#define APB_POWER_PD_CTRL3_M_JACK_DET_COMPL_POS        8
#define APB_POWER_PD_CTRL3_HP_DET_DEB_MASK             ((uint32_t)0x000000C0)
#define APB_POWER_PD_CTRL3_HP_DET_DEB_LSB              6
#define APB_POWER_PD_CTRL3_HP_DET_DEB_WIDTH            ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_JACK_INS_DEB_MASK           ((uint32_t)0x00000030)
#define APB_POWER_PD_CTRL3_JACK_INS_DEB_LSB            4
#define APB_POWER_PD_CTRL3_JACK_INS_DEB_WIDTH          ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_JACK_DET_RATE_MASK          ((uint32_t)0x0000000C)
#define APB_POWER_PD_CTRL3_JACK_DET_RATE_LSB           2
#define APB_POWER_PD_CTRL3_JACK_DET_RATE_WIDTH         ((uint32_t)0x00000002)
#define APB_POWER_PD_CTRL3_JACK_REM_DEB_MASK           ((uint32_t)0x00000003)
#define APB_POWER_PD_CTRL3_JACK_REM_DEB_LSB            0
#define APB_POWER_PD_CTRL3_JACK_REM_DEB_WIDTH          ((uint32_t)0x00000002)

#define APB_POWER_PD_CTRL3_JACK_INSERTION_STS_RST      0x0
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_RST        0x0
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_RST          0x0
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_RST        0x0
#define APB_POWER_PD_CTRL3_JACK_PIN_ORDER_STS_RST      0x0
#define APB_POWER_PD_CTRL3_JACK_TYPE_STS_RST           0x0
#define APB_POWER_PD_CTRL3_MICBIAS_UP_STS_RST          0x0
#define APB_POWER_PD_CTRL3_MIC_DET_DONE_RST            0x0
#define APB_POWER_PD_CTRL3_HP_DET_DONE_RST             0x0
#define APB_POWER_PD_CTRL3_MIC_IMP_STS_RST             0x0
#define APB_POWER_PD_CTRL3_RING_1_IMP_STS_RST          0x0
#define APB_POWER_PD_CTRL3_TIP_IMP_STS_RST             0x0
#define APB_POWER_PD_CTRL3_HP_DET_EN_RST               0x0
#define APB_POWER_PD_CTRL3_JACK_TYPE_EN_RST            0x0
#define APB_POWER_PD_CTRL3_E_JACK_INSERTION_CLR_RST    0x0
#define APB_POWER_PD_CTRL3_E_JACK_REMOVAL_CLR_RST      0x0
#define APB_POWER_PD_CTRL3_E_JACK_DET_COMPL_CLR_RST    0x0
#define APB_POWER_PD_CTRL3_M_JACK_INSERTION_RST        0x0
#define APB_POWER_PD_CTRL3_M_JACK_REMOVAL_RST          0x0
#define APB_POWER_PD_CTRL3_M_JACK_DET_COMPL_RST        0x0
#define APB_POWER_PD_CTRL3_HP_DET_DEB_RST              0x1
#define APB_POWER_PD_CTRL3_JACK_INS_DEB_RST            0x1
#define APB_POWER_PD_CTRL3_JACK_DET_RATE_RST           0x3
#define APB_POWER_PD_CTRL3_JACK_REM_DEB_RST            0x3

__INLINE void apb_power_pd_ctrl3_pack(uint8_t hpdeten, uint8_t jacktypeen, uint8_t ejackinsertionclr, uint8_t ejackremovalclr, uint8_t ejackdetcomplclr, uint8_t mjackinsertion, uint8_t mjackremoval, uint8_t mjackdetcompl, uint8_t hpdetdeb, uint8_t jackinsdeb, uint8_t jackdetrate, uint8_t jackremdeb)
{
    ASSERT_ERR((((uint32_t)hpdeten << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)jacktypeen << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)ejackinsertionclr << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)ejackremovalclr << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)ejackdetcomplclr << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)mjackinsertion << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)mjackremoval << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)mjackdetcompl << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)hpdetdeb << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)jackinsdeb << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)jackdetrate << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)jackremdeb << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR,  ((uint32_t)hpdeten << 15) | ((uint32_t)jacktypeen << 14) | ((uint32_t)ejackinsertionclr << 13) | ((uint32_t)ejackremovalclr << 12) | ((uint32_t)ejackdetcomplclr << 11) | ((uint32_t)mjackinsertion << 10) | ((uint32_t)mjackremoval << 9) | ((uint32_t)mjackdetcompl << 8) | ((uint32_t)hpdetdeb << 6) | ((uint32_t)jackinsdeb << 4) | ((uint32_t)jackdetrate << 2) | ((uint32_t)jackremdeb << 0));
}

__INLINE void apb_power_pd_ctrl3_unpack(uint8_t* jackinsertionsts, uint8_t* ejackdetcompl, uint8_t* ejackremoval, uint8_t* ejackinsertion, uint8_t* jackpinordersts, uint8_t* jacktypests, uint8_t* micbiasupsts, uint8_t* micdetdone, uint8_t* hpdetdone, uint8_t* micimpsts, uint8_t* ring1impsts, uint8_t* tipimpsts, uint8_t* hpdeten, uint8_t* jacktypeen, uint8_t* ejackinsertionclr, uint8_t* ejackremovalclr, uint8_t* ejackdetcomplclr, uint8_t* mjackinsertion, uint8_t* mjackremoval, uint8_t* mjackdetcompl, uint8_t* hpdetdeb, uint8_t* jackinsdeb, uint8_t* jackdetrate, uint8_t* jackremdeb)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    *jackinsertionsts = (localVal & ((uint32_t)0x40000000)) >> 30;
    *ejackdetcompl = (localVal & ((uint32_t)0x20000000)) >> 29;
    *ejackremoval = (localVal & ((uint32_t)0x10000000)) >> 28;
    *ejackinsertion = (localVal & ((uint32_t)0x08000000)) >> 27;
    *jackpinordersts = (localVal & ((uint32_t)0x04000000)) >> 26;
    *jacktypests = (localVal & ((uint32_t)0x02000000)) >> 25;
    *micbiasupsts = (localVal & ((uint32_t)0x01000000)) >> 24;
    *micdetdone = (localVal & ((uint32_t)0x00800000)) >> 23;
    *hpdetdone = (localVal & ((uint32_t)0x00400000)) >> 22;
    *micimpsts = (localVal & ((uint32_t)0x00300000)) >> 20;
    *ring1impsts = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *tipimpsts = (localVal & ((uint32_t)0x00030000)) >> 16;
    *hpdeten = (localVal & ((uint32_t)0x00008000)) >> 15;
    *jacktypeen = (localVal & ((uint32_t)0x00004000)) >> 14;
    *ejackinsertionclr = (localVal & ((uint32_t)0x00002000)) >> 13;
    *ejackremovalclr = (localVal & ((uint32_t)0x00001000)) >> 12;
    *ejackdetcomplclr = (localVal & ((uint32_t)0x00000800)) >> 11;
    *mjackinsertion = (localVal & ((uint32_t)0x00000400)) >> 10;
    *mjackremoval = (localVal & ((uint32_t)0x00000200)) >> 9;
    *mjackdetcompl = (localVal & ((uint32_t)0x00000100)) >> 8;
    *hpdetdeb = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *jackinsdeb = (localVal & ((uint32_t)0x00000030)) >> 4;
    *jackdetrate = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *jackremdeb = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_insertion_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_det_compl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_removal_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_insertion_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_pin_order_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_type_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}

__INLINE uint8_t apb_power_pd_ctrl3_micbias_up_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t apb_power_pd_ctrl3_mic_det_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE uint8_t apb_power_pd_ctrl3_hp_det_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_power_pd_ctrl3_mic_imp_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE uint8_t apb_power_pd_ctrl3_ring_1_imp_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE uint8_t apb_power_pd_ctrl3_tip_imp_sts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE uint8_t apb_power_pd_ctrl3_hp_det_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void apb_power_pd_ctrl3_hp_det_en_setf(uint8_t hpdeten)
{
    ASSERT_ERR((((uint32_t)hpdeten << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)hpdeten << 15));
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_type_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void apb_power_pd_ctrl3_jack_type_en_setf(uint8_t jacktypeen)
{
    ASSERT_ERR((((uint32_t)jacktypeen << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)jacktypeen << 14));
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_insertion_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void apb_power_pd_ctrl3_e_jack_insertion_clr_setf(uint8_t ejackinsertionclr)
{
    ASSERT_ERR((((uint32_t)ejackinsertionclr << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)ejackinsertionclr << 13));
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_removal_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void apb_power_pd_ctrl3_e_jack_removal_clr_setf(uint8_t ejackremovalclr)
{
    ASSERT_ERR((((uint32_t)ejackremovalclr << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)ejackremovalclr << 12));
}

__INLINE uint8_t apb_power_pd_ctrl3_e_jack_det_compl_clr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE void apb_power_pd_ctrl3_e_jack_det_compl_clr_setf(uint8_t ejackdetcomplclr)
{
    ASSERT_ERR((((uint32_t)ejackdetcomplclr << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)ejackdetcomplclr << 11));
}

__INLINE uint8_t apb_power_pd_ctrl3_m_jack_insertion_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void apb_power_pd_ctrl3_m_jack_insertion_setf(uint8_t mjackinsertion)
{
    ASSERT_ERR((((uint32_t)mjackinsertion << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)mjackinsertion << 10));
}

__INLINE uint8_t apb_power_pd_ctrl3_m_jack_removal_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_power_pd_ctrl3_m_jack_removal_setf(uint8_t mjackremoval)
{
    ASSERT_ERR((((uint32_t)mjackremoval << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)mjackremoval << 9));
}

__INLINE uint8_t apb_power_pd_ctrl3_m_jack_det_compl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_power_pd_ctrl3_m_jack_det_compl_setf(uint8_t mjackdetcompl)
{
    ASSERT_ERR((((uint32_t)mjackdetcompl << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)mjackdetcompl << 8));
}

__INLINE uint8_t apb_power_pd_ctrl3_hp_det_deb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void apb_power_pd_ctrl3_hp_det_deb_setf(uint8_t hpdetdeb)
{
    ASSERT_ERR((((uint32_t)hpdetdeb << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)hpdetdeb << 6));
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_ins_deb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void apb_power_pd_ctrl3_jack_ins_deb_setf(uint8_t jackinsdeb)
{
    ASSERT_ERR((((uint32_t)jackinsdeb << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)jackinsdeb << 4));
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_det_rate_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void apb_power_pd_ctrl3_jack_det_rate_setf(uint8_t jackdetrate)
{
    ASSERT_ERR((((uint32_t)jackdetrate << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)jackdetrate << 2));
}

__INLINE uint8_t apb_power_pd_ctrl3_jack_rem_deb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_POWER_PD_CTRL3_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void apb_power_pd_ctrl3_jack_rem_deb_setf(uint8_t jackremdeb)
{
    ASSERT_ERR((((uint32_t)jackremdeb << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(APB_POWER_PD_CTRL3_ADDR, (REG_PL_RD(APB_POWER_PD_CTRL3_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)jackremdeb << 0));
}

/**
 * @brief DIG_STDBY_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     22     Dig_ldo_pon_done   0
 *     21   dig_stdby_cali_out   0
 *     20   dig_stdby_cali_done_fsm   0
 *  19:16   dig_stdby_cali_code_fsm   0x0
 *     09         Dig_ldo_flag   1
 *     08     Cpu_stdby_req_en   0
 *     07         dig_stdby_pd   1
 *     06    dig_stdby_cali_en   0
 *     05   dig_stdby_cali_flag   0
 *     04   dig_stdby_cali_start   0
 *  03:00   dig_stdby_cali_code   0x0
 * </pre>
 */
#define APB_DIG_STDBY_CTRL_ADDR   0xC0012258
#define APB_DIG_STDBY_CTRL_OFFSET 0x00000258
#define APB_DIG_STDBY_CTRL_INDEX  0x00000096
#define APB_DIG_STDBY_CTRL_RESET  0x00000280

__INLINE uint32_t apb_dig_stdby_ctrl_get(void)
{
    return REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
}

__INLINE void apb_dig_stdby_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, value);
}

// field definitions
#define APB_DIG_STDBY_CTRL_DIG_LDO_PON_DONE_BIT           ((uint32_t)0x00400000)
#define APB_DIG_STDBY_CTRL_DIG_LDO_PON_DONE_POS           22
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_OUT_BIT         ((uint32_t)0x00200000)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_OUT_POS         21
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_DONE_FSM_BIT    ((uint32_t)0x00100000)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_DONE_FSM_POS    20
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_FSM_MASK   ((uint32_t)0x000F0000)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_FSM_LSB    16
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_FSM_WIDTH  ((uint32_t)0x00000004)
#define APB_DIG_STDBY_CTRL_DIG_LDO_FLAG_BIT               ((uint32_t)0x00000200)
#define APB_DIG_STDBY_CTRL_DIG_LDO_FLAG_POS               9
#define APB_DIG_STDBY_CTRL_CPU_STDBY_REQ_EN_BIT           ((uint32_t)0x00000100)
#define APB_DIG_STDBY_CTRL_CPU_STDBY_REQ_EN_POS           8
#define APB_DIG_STDBY_CTRL_DIG_STDBY_PD_BIT               ((uint32_t)0x00000080)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_PD_POS               7
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_EN_BIT          ((uint32_t)0x00000040)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_EN_POS          6
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_FLAG_BIT        ((uint32_t)0x00000020)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_FLAG_POS        5
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_START_BIT       ((uint32_t)0x00000010)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_START_POS       4
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_MASK       ((uint32_t)0x0000000F)
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_LSB        0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_WIDTH      ((uint32_t)0x00000004)

#define APB_DIG_STDBY_CTRL_DIG_LDO_PON_DONE_RST           0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_OUT_RST         0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_DONE_FSM_RST    0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_FSM_RST    0x0
#define APB_DIG_STDBY_CTRL_DIG_LDO_FLAG_RST               0x1
#define APB_DIG_STDBY_CTRL_CPU_STDBY_REQ_EN_RST           0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_PD_RST               0x1
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_EN_RST          0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_FLAG_RST        0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_START_RST       0x0
#define APB_DIG_STDBY_CTRL_DIG_STDBY_CALI_CODE_RST        0x0

__INLINE void apb_dig_stdby_ctrl_pack(uint8_t digldoflag, uint8_t cpustdbyreqen, uint8_t digstdbypd, uint8_t digstdbycalien, uint8_t digstdbycaliflag, uint8_t digstdbycalistart, uint8_t digstdbycalicode)
{
    ASSERT_ERR((((uint32_t)digldoflag << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)cpustdbyreqen << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)digstdbypd << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)digstdbycalien << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)digstdbycaliflag << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)digstdbycalistart << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)digstdbycalicode << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR,  ((uint32_t)digldoflag << 9) | ((uint32_t)cpustdbyreqen << 8) | ((uint32_t)digstdbypd << 7) | ((uint32_t)digstdbycalien << 6) | ((uint32_t)digstdbycaliflag << 5) | ((uint32_t)digstdbycalistart << 4) | ((uint32_t)digstdbycalicode << 0));
}

__INLINE void apb_dig_stdby_ctrl_unpack(uint8_t* digldopondone, uint8_t* digstdbycaliout, uint8_t* digstdbycalidonefsm, uint8_t* digstdbycalicodefsm, uint8_t* digldoflag, uint8_t* cpustdbyreqen, uint8_t* digstdbypd, uint8_t* digstdbycalien, uint8_t* digstdbycaliflag, uint8_t* digstdbycalistart, uint8_t* digstdbycalicode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    *digldopondone = (localVal & ((uint32_t)0x00400000)) >> 22;
    *digstdbycaliout = (localVal & ((uint32_t)0x00200000)) >> 21;
    *digstdbycalidonefsm = (localVal & ((uint32_t)0x00100000)) >> 20;
    *digstdbycalicodefsm = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *digldoflag = (localVal & ((uint32_t)0x00000200)) >> 9;
    *cpustdbyreqen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *digstdbypd = (localVal & ((uint32_t)0x00000080)) >> 7;
    *digstdbycalien = (localVal & ((uint32_t)0x00000040)) >> 6;
    *digstdbycaliflag = (localVal & ((uint32_t)0x00000020)) >> 5;
    *digstdbycalistart = (localVal & ((uint32_t)0x00000010)) >> 4;
    *digstdbycalicode = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_ldo_pon_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_out_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_done_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_code_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_ldo_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void apb_dig_stdby_ctrl_dig_ldo_flag_setf(uint8_t digldoflag)
{
    ASSERT_ERR((((uint32_t)digldoflag << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)digldoflag << 9));
}

__INLINE uint8_t apb_dig_stdby_ctrl_cpu_stdby_req_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void apb_dig_stdby_ctrl_cpu_stdby_req_en_setf(uint8_t cpustdbyreqen)
{
    ASSERT_ERR((((uint32_t)cpustdbyreqen << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cpustdbyreqen << 8));
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_pd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void apb_dig_stdby_ctrl_dig_stdby_pd_setf(uint8_t digstdbypd)
{
    ASSERT_ERR((((uint32_t)digstdbypd << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)digstdbypd << 7));
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void apb_dig_stdby_ctrl_dig_stdby_cali_en_setf(uint8_t digstdbycalien)
{
    ASSERT_ERR((((uint32_t)digstdbycalien << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)digstdbycalien << 6));
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void apb_dig_stdby_ctrl_dig_stdby_cali_flag_setf(uint8_t digstdbycaliflag)
{
    ASSERT_ERR((((uint32_t)digstdbycaliflag << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)digstdbycaliflag << 5));
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_start_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void apb_dig_stdby_ctrl_dig_stdby_cali_start_setf(uint8_t digstdbycalistart)
{
    ASSERT_ERR((((uint32_t)digstdbycalistart << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)digstdbycalistart << 4));
}

__INLINE uint8_t apb_dig_stdby_ctrl_dig_stdby_cali_code_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

__INLINE void apb_dig_stdby_ctrl_dig_stdby_cali_code_setf(uint8_t digstdbycalicode)
{
    ASSERT_ERR((((uint32_t)digstdbycalicode << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(APB_DIG_STDBY_CTRL_ADDR, (REG_PL_RD(APB_DIG_STDBY_CTRL_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)digstdbycalicode << 0));
}

/**
 * @brief KEY_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  27:26     Key_int_polarity   0x0
 *  25:24         Key_int_type   0x0
 *     20       clk_key_det_en   0
 *     19          key_det_rst   0
 *     18        key_detect_en   0
 *  17:16        key_gain_ctrl   0x1
 *  07:00      KEY_detect_thrd   0x94
 * </pre>
 */
#define APB_KEY_CTRL_ADDR   0xC0012260
#define APB_KEY_CTRL_OFFSET 0x00000260
#define APB_KEY_CTRL_INDEX  0x00000098
#define APB_KEY_CTRL_RESET  0x00010094

__INLINE uint32_t apb_key_ctrl_get(void)
{
    return REG_PL_RD(APB_KEY_CTRL_ADDR);
}

__INLINE void apb_key_ctrl_set(uint32_t value)
{
    REG_PL_WR(APB_KEY_CTRL_ADDR, value);
}

// field definitions
#define APB_KEY_CTRL_KEY_INT_POLARITY_MASK   ((uint32_t)0x0C000000)
#define APB_KEY_CTRL_KEY_INT_POLARITY_LSB    26
#define APB_KEY_CTRL_KEY_INT_POLARITY_WIDTH  ((uint32_t)0x00000002)
#define APB_KEY_CTRL_KEY_INT_TYPE_MASK       ((uint32_t)0x03000000)
#define APB_KEY_CTRL_KEY_INT_TYPE_LSB        24
#define APB_KEY_CTRL_KEY_INT_TYPE_WIDTH      ((uint32_t)0x00000002)
#define APB_KEY_CTRL_CLK_KEY_DET_EN_BIT      ((uint32_t)0x00100000)
#define APB_KEY_CTRL_CLK_KEY_DET_EN_POS      20
#define APB_KEY_CTRL_KEY_DET_RST_BIT         ((uint32_t)0x00080000)
#define APB_KEY_CTRL_KEY_DET_RST_POS         19
#define APB_KEY_CTRL_KEY_DETECT_EN_BIT       ((uint32_t)0x00040000)
#define APB_KEY_CTRL_KEY_DETECT_EN_POS       18
#define APB_KEY_CTRL_KEY_GAIN_CTRL_MASK      ((uint32_t)0x00030000)
#define APB_KEY_CTRL_KEY_GAIN_CTRL_LSB       16
#define APB_KEY_CTRL_KEY_GAIN_CTRL_WIDTH     ((uint32_t)0x00000002)
#define APB_KEY_CTRL_KEY_DETECT_THRD_MASK    ((uint32_t)0x000000FF)
#define APB_KEY_CTRL_KEY_DETECT_THRD_LSB     0
#define APB_KEY_CTRL_KEY_DETECT_THRD_WIDTH   ((uint32_t)0x00000008)

#define APB_KEY_CTRL_KEY_INT_POLARITY_RST    0x0
#define APB_KEY_CTRL_KEY_INT_TYPE_RST        0x0
#define APB_KEY_CTRL_CLK_KEY_DET_EN_RST      0x0
#define APB_KEY_CTRL_KEY_DET_RST_RST         0x0
#define APB_KEY_CTRL_KEY_DETECT_EN_RST       0x0
#define APB_KEY_CTRL_KEY_GAIN_CTRL_RST       0x1
#define APB_KEY_CTRL_KEY_DETECT_THRD_RST     0x94

__INLINE void apb_key_ctrl_pack(uint8_t keyintpolarity, uint8_t keyinttype, uint8_t clkkeydeten, uint8_t keydetrst, uint8_t keydetecten, uint8_t keygainctrl, uint8_t keydetectthrd)
{
    ASSERT_ERR((((uint32_t)keyintpolarity << 26) & ~((uint32_t)0x0C000000)) == 0);
    ASSERT_ERR((((uint32_t)keyinttype << 24) & ~((uint32_t)0x03000000)) == 0);
    ASSERT_ERR((((uint32_t)clkkeydeten << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)keydetrst << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)keydetecten << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)keygainctrl << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)keydetectthrd << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR,  ((uint32_t)keyintpolarity << 26) | ((uint32_t)keyinttype << 24) | ((uint32_t)clkkeydeten << 20) | ((uint32_t)keydetrst << 19) | ((uint32_t)keydetecten << 18) | ((uint32_t)keygainctrl << 16) | ((uint32_t)keydetectthrd << 0));
}

__INLINE void apb_key_ctrl_unpack(uint8_t* keyintpolarity, uint8_t* keyinttype, uint8_t* clkkeydeten, uint8_t* keydetrst, uint8_t* keydetecten, uint8_t* keygainctrl, uint8_t* keydetectthrd)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    *keyintpolarity = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *keyinttype = (localVal & ((uint32_t)0x03000000)) >> 24;
    *clkkeydeten = (localVal & ((uint32_t)0x00100000)) >> 20;
    *keydetrst = (localVal & ((uint32_t)0x00080000)) >> 19;
    *keydetecten = (localVal & ((uint32_t)0x00040000)) >> 18;
    *keygainctrl = (localVal & ((uint32_t)0x00030000)) >> 16;
    *keydetectthrd = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t apb_key_ctrl_key_int_polarity_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void apb_key_ctrl_key_int_polarity_setf(uint8_t keyintpolarity)
{
    ASSERT_ERR((((uint32_t)keyintpolarity << 26) & ~((uint32_t)0x0C000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)keyintpolarity << 26));
}

__INLINE uint8_t apb_key_ctrl_key_int_type_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void apb_key_ctrl_key_int_type_setf(uint8_t keyinttype)
{
    ASSERT_ERR((((uint32_t)keyinttype << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)keyinttype << 24));
}

__INLINE uint8_t apb_key_ctrl_clk_key_det_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE void apb_key_ctrl_clk_key_det_en_setf(uint8_t clkkeydeten)
{
    ASSERT_ERR((((uint32_t)clkkeydeten << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)clkkeydeten << 20));
}

__INLINE uint8_t apb_key_ctrl_key_det_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void apb_key_ctrl_key_det_rst_setf(uint8_t keydetrst)
{
    ASSERT_ERR((((uint32_t)keydetrst << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)keydetrst << 19));
}

__INLINE uint8_t apb_key_ctrl_key_detect_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE void apb_key_ctrl_key_detect_en_setf(uint8_t keydetecten)
{
    ASSERT_ERR((((uint32_t)keydetecten << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)keydetecten << 18));
}

__INLINE uint8_t apb_key_ctrl_key_gain_ctrl_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void apb_key_ctrl_key_gain_ctrl_setf(uint8_t keygainctrl)
{
    ASSERT_ERR((((uint32_t)keygainctrl << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)keygainctrl << 16));
}

__INLINE uint8_t apb_key_ctrl_key_detect_thrd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_KEY_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void apb_key_ctrl_key_detect_thrd_setf(uint8_t keydetectthrd)
{
    ASSERT_ERR((((uint32_t)keydetectthrd << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(APB_KEY_CTRL_ADDR, (REG_PL_RD(APB_KEY_CTRL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)keydetectthrd << 0));
}

/**
 * @brief INTR_STS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     05              Hss_int   0
 *     04           Auxadc_int   0
 *     03         Gpio_key_int   0
 *     02        Micin_key_int   0
 *     01         Usb_suspendm   0
 *     00           Voice_flag   0
 * </pre>
 */
#define APB_INTR_STS_ADDR   0xC0012264
#define APB_INTR_STS_OFFSET 0x00000264
#define APB_INTR_STS_INDEX  0x00000099
#define APB_INTR_STS_RESET  0x00000000

__INLINE uint32_t apb_intr_sts_get(void)
{
    return REG_PL_RD(APB_INTR_STS_ADDR);
}

// field definitions
#define APB_INTR_STS_HSS_INT_BIT          ((uint32_t)0x00000020)
#define APB_INTR_STS_HSS_INT_POS          5
#define APB_INTR_STS_AUXADC_INT_BIT       ((uint32_t)0x00000010)
#define APB_INTR_STS_AUXADC_INT_POS       4
#define APB_INTR_STS_GPIO_KEY_INT_BIT     ((uint32_t)0x00000008)
#define APB_INTR_STS_GPIO_KEY_INT_POS     3
#define APB_INTR_STS_MICIN_KEY_INT_BIT    ((uint32_t)0x00000004)
#define APB_INTR_STS_MICIN_KEY_INT_POS    2
#define APB_INTR_STS_USB_SUSPENDM_BIT     ((uint32_t)0x00000002)
#define APB_INTR_STS_USB_SUSPENDM_POS     1
#define APB_INTR_STS_VOICE_FLAG_BIT       ((uint32_t)0x00000001)
#define APB_INTR_STS_VOICE_FLAG_POS       0

#define APB_INTR_STS_HSS_INT_RST          0x0
#define APB_INTR_STS_AUXADC_INT_RST       0x0
#define APB_INTR_STS_GPIO_KEY_INT_RST     0x0
#define APB_INTR_STS_MICIN_KEY_INT_RST    0x0
#define APB_INTR_STS_USB_SUSPENDM_RST     0x0
#define APB_INTR_STS_VOICE_FLAG_RST       0x0

__INLINE void apb_intr_sts_unpack(uint8_t* hssint, uint8_t* auxadcint, uint8_t* gpiokeyint, uint8_t* micinkeyint, uint8_t* usbsuspendm, uint8_t* voiceflag)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    *hssint = (localVal & ((uint32_t)0x00000020)) >> 5;
    *auxadcint = (localVal & ((uint32_t)0x00000010)) >> 4;
    *gpiokeyint = (localVal & ((uint32_t)0x00000008)) >> 3;
    *micinkeyint = (localVal & ((uint32_t)0x00000004)) >> 2;
    *usbsuspendm = (localVal & ((uint32_t)0x00000002)) >> 1;
    *voiceflag = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t apb_intr_sts_hss_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t apb_intr_sts_auxadc_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t apb_intr_sts_gpio_key_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t apb_intr_sts_micin_key_int_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t apb_intr_sts_usb_suspendm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t apb_intr_sts_voice_flag_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_INTR_STS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief DEVICE_ID__REGISTER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16              KT_mark   0x4B54
 *     15                  S_F   1
 *  14:11           Foundry_ID   0x0
 *  10:08           process_ID   0x5
 *  07:06         Mask_version   0x0
 *  05:00          part_number   0x6
 * </pre>
 */
#define APB_DEVICE_ID__REGISTER_ADDR   0xC0012F00
#define APB_DEVICE_ID__REGISTER_OFFSET 0x00000F00
#define APB_DEVICE_ID__REGISTER_INDEX  0x000003C0
#define APB_DEVICE_ID__REGISTER_RESET  0x4B548506

__INLINE uint32_t apb_device_id__register_get(void)
{
    return REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
}

__INLINE void apb_device_id__register_set(uint32_t value)
{
    REG_PL_WR(APB_DEVICE_ID__REGISTER_ADDR, value);
}

// field definitions
#define APB_DEVICE_ID__REGISTER_KT_MARK_MASK        ((uint32_t)0xFFFF0000)
#define APB_DEVICE_ID__REGISTER_KT_MARK_LSB         16
#define APB_DEVICE_ID__REGISTER_KT_MARK_WIDTH       ((uint32_t)0x00000010)
#define APB_DEVICE_ID__REGISTER_S_F_BIT             ((uint32_t)0x00008000)
#define APB_DEVICE_ID__REGISTER_S_F_POS             15
#define APB_DEVICE_ID__REGISTER_FOUNDRY_ID_MASK     ((uint32_t)0x00007800)
#define APB_DEVICE_ID__REGISTER_FOUNDRY_ID_LSB      11
#define APB_DEVICE_ID__REGISTER_FOUNDRY_ID_WIDTH    ((uint32_t)0x00000004)
#define APB_DEVICE_ID__REGISTER_PROCESS_ID_MASK     ((uint32_t)0x00000700)
#define APB_DEVICE_ID__REGISTER_PROCESS_ID_LSB      8
#define APB_DEVICE_ID__REGISTER_PROCESS_ID_WIDTH    ((uint32_t)0x00000003)
#define APB_DEVICE_ID__REGISTER_MASK_VERSION_MASK   ((uint32_t)0x000000C0)
#define APB_DEVICE_ID__REGISTER_MASK_VERSION_LSB    6
#define APB_DEVICE_ID__REGISTER_MASK_VERSION_WIDTH  ((uint32_t)0x00000002)
#define APB_DEVICE_ID__REGISTER_PART_NUMBER_MASK    ((uint32_t)0x0000003F)
#define APB_DEVICE_ID__REGISTER_PART_NUMBER_LSB     0
#define APB_DEVICE_ID__REGISTER_PART_NUMBER_WIDTH   ((uint32_t)0x00000006)

#define APB_DEVICE_ID__REGISTER_KT_MARK_RST         0x4B54
#define APB_DEVICE_ID__REGISTER_S_F_RST             0x1
#define APB_DEVICE_ID__REGISTER_FOUNDRY_ID_RST      0x0
#define APB_DEVICE_ID__REGISTER_PROCESS_ID_RST      0x5
#define APB_DEVICE_ID__REGISTER_MASK_VERSION_RST    0x0
#define APB_DEVICE_ID__REGISTER_PART_NUMBER_RST     0x6

__INLINE void apb_device_id__register_unpack(uint16_t* ktmark, uint8_t* sf, uint8_t* foundryid, uint8_t* processid, uint8_t* maskversion, uint8_t* partnumber)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    *ktmark = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *sf = (localVal & ((uint32_t)0x00008000)) >> 15;
    *foundryid = (localVal & ((uint32_t)0x00007800)) >> 11;
    *processid = (localVal & ((uint32_t)0x00000700)) >> 8;
    *maskversion = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *partnumber = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

__INLINE uint16_t apb_device_id__register_kt_mark_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE uint8_t apb_device_id__register_s_f_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE uint8_t apb_device_id__register_foundry_id_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0x00007800)) >> 11);
}

__INLINE uint8_t apb_device_id__register_process_id_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0x00000700)) >> 8);
}

__INLINE uint8_t apb_device_id__register_mask_version_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE uint8_t apb_device_id__register_part_number_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_DEVICE_ID__REGISTER_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief SPARE_REG0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         r_spare_reg0   0x0
 * </pre>
 */
#define APB_SPARE_REG0_ADDR   0xC0012FF0
#define APB_SPARE_REG0_OFFSET 0x00000FF0
#define APB_SPARE_REG0_INDEX  0x000003FC
#define APB_SPARE_REG0_RESET  0x00000000

__INLINE uint32_t apb_spare_reg0_get(void)
{
    return REG_PL_RD(APB_SPARE_REG0_ADDR);
}

__INLINE void apb_spare_reg0_set(uint32_t value)
{
    REG_PL_WR(APB_SPARE_REG0_ADDR, value);
}

// field definitions
#define APB_SPARE_REG0_R_SPARE_REG_0_MASK   ((uint32_t)0xFFFFFFFF)
#define APB_SPARE_REG0_R_SPARE_REG_0_LSB    0
#define APB_SPARE_REG0_R_SPARE_REG_0_WIDTH  ((uint32_t)0x00000020)

#define APB_SPARE_REG0_R_SPARE_REG_0_RST    0x0

__INLINE uint32_t apb_spare_reg0_r_spare_reg_0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SPARE_REG0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_spare_reg0_r_spare_reg_0_setf(uint32_t rsparereg0)
{
    ASSERT_ERR((((uint32_t)rsparereg0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(APB_SPARE_REG0_ADDR, (uint32_t)rsparereg0 << 0);
}

/**
 * @brief SPARE_REG1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         r_spare_reg1   0x0
 * </pre>
 */
#define APB_SPARE_REG1_ADDR   0xC0012FF4
#define APB_SPARE_REG1_OFFSET 0x00000FF4
#define APB_SPARE_REG1_INDEX  0x000003FD
#define APB_SPARE_REG1_RESET  0x00000000

__INLINE uint32_t apb_spare_reg1_get(void)
{
    return REG_PL_RD(APB_SPARE_REG1_ADDR);
}

__INLINE void apb_spare_reg1_set(uint32_t value)
{
    REG_PL_WR(APB_SPARE_REG1_ADDR, value);
}

// field definitions
#define APB_SPARE_REG1_R_SPARE_REG_1_MASK   ((uint32_t)0xFFFFFFFF)
#define APB_SPARE_REG1_R_SPARE_REG_1_LSB    0
#define APB_SPARE_REG1_R_SPARE_REG_1_WIDTH  ((uint32_t)0x00000020)

#define APB_SPARE_REG1_R_SPARE_REG_1_RST    0x0

__INLINE uint32_t apb_spare_reg1_r_spare_reg_1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SPARE_REG1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_spare_reg1_r_spare_reg_1_setf(uint32_t rsparereg1)
{
    ASSERT_ERR((((uint32_t)rsparereg1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(APB_SPARE_REG1_ADDR, (uint32_t)rsparereg1 << 0);
}

/**
 * @brief SPARE_REG2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         r_spare_reg2   0x0
 * </pre>
 */
#define APB_SPARE_REG2_ADDR   0xC0012FF8
#define APB_SPARE_REG2_OFFSET 0x00000FF8
#define APB_SPARE_REG2_INDEX  0x000003FE
#define APB_SPARE_REG2_RESET  0x00000000

__INLINE uint32_t apb_spare_reg2_get(void)
{
    return REG_PL_RD(APB_SPARE_REG2_ADDR);
}

__INLINE void apb_spare_reg2_set(uint32_t value)
{
    REG_PL_WR(APB_SPARE_REG2_ADDR, value);
}

// field definitions
#define APB_SPARE_REG2_R_SPARE_REG_2_MASK   ((uint32_t)0xFFFFFFFF)
#define APB_SPARE_REG2_R_SPARE_REG_2_LSB    0
#define APB_SPARE_REG2_R_SPARE_REG_2_WIDTH  ((uint32_t)0x00000020)

#define APB_SPARE_REG2_R_SPARE_REG_2_RST    0x0

__INLINE uint32_t apb_spare_reg2_r_spare_reg_2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SPARE_REG2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_spare_reg2_r_spare_reg_2_setf(uint32_t rsparereg2)
{
    ASSERT_ERR((((uint32_t)rsparereg2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(APB_SPARE_REG2_ADDR, (uint32_t)rsparereg2 << 0);
}

/**
 * @brief SPARE_REG3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         r_spare_reg3   0xFFFFFFFF
 * </pre>
 */
#define APB_SPARE_REG3_ADDR   0xC0012FFC
#define APB_SPARE_REG3_OFFSET 0x00000FFC
#define APB_SPARE_REG3_INDEX  0x000003FF
#define APB_SPARE_REG3_RESET  0xFFFFFFFF

__INLINE uint32_t apb_spare_reg3_get(void)
{
    return REG_PL_RD(APB_SPARE_REG3_ADDR);
}

__INLINE void apb_spare_reg3_set(uint32_t value)
{
    REG_PL_WR(APB_SPARE_REG3_ADDR, value);
}

// field definitions
#define APB_SPARE_REG3_R_SPARE_REG_3_MASK   ((uint32_t)0xFFFFFFFF)
#define APB_SPARE_REG3_R_SPARE_REG_3_LSB    0
#define APB_SPARE_REG3_R_SPARE_REG_3_WIDTH  ((uint32_t)0x00000020)

#define APB_SPARE_REG3_R_SPARE_REG_3_RST    0xFFFFFFFF

__INLINE uint32_t apb_spare_reg3_r_spare_reg_3_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(APB_SPARE_REG3_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void apb_spare_reg3_r_spare_reg_3_setf(uint32_t rsparereg3)
{
    ASSERT_ERR((((uint32_t)rsparereg3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(APB_SPARE_REG3_ADDR, (uint32_t)rsparereg3 << 0);
}


#endif // _REG_APB_H_
