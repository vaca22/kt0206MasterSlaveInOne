#ifndef _REG_CLKRST_H_
#define _REG_CLKRST_H_

#include <stdint.h>
#include "_reg_clkrst.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_CLKRST_COUNT 26

#define REG_CLKRST_DECODING_MASK 0x0000007F

/**
 * @brief TOP_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31           PD_DLL_PRE   0
 *     29         WLAN_WLRXBSY   0
 *     28         WLAN_FR_SYNC   0
 *     26         CPU_DIV2_SEL   0
 *     21             AUDIO_EN   0
 *     19              UART_EN   0
 *     16     BB_PINMUX_BYPASS   0
 *     15          BB_OUT_SYNC   0
 *     14          BB_CLK_MODE   0
 *  13:12      Bb_Refresh_mode   0x0
 *     10            Bb_enable   0
 *     09            TX_EN_INV   0
 *     08     TOGGLE_SAVE_MODE   0
 *  07:00             RSSI_REG   0x0
 * </pre>
 */
#define CLKRST_TOP_CTRL_ADDR   0xC0012024
#define CLKRST_TOP_CTRL_OFFSET 0x00000024
#define CLKRST_TOP_CTRL_INDEX  0x00000009
#define CLKRST_TOP_CTRL_RESET  0x00000000

__INLINE uint32_t clkrst_top_ctrl_get(void)
{
    return REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
}

__INLINE void clkrst_top_ctrl_set(uint32_t value)
{
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, value);
}

// field definitions
#define CLKRST_PD_DLL_PRE_BIT          ((uint32_t)0x80000000)
#define CLKRST_PD_DLL_PRE_POS          31
#define CLKRST_WLAN_WLRXBSY_BIT        ((uint32_t)0x20000000)
#define CLKRST_WLAN_WLRXBSY_POS        29
#define CLKRST_WLAN_FR_SYNC_BIT        ((uint32_t)0x10000000)
#define CLKRST_WLAN_FR_SYNC_POS        28
#define CLKRST_CPU_DIV2_SEL_BIT        ((uint32_t)0x04000000)
#define CLKRST_CPU_DIV2_SEL_POS        26
#define CLKRST_AUDIO_EN_BIT            ((uint32_t)0x00200000)
#define CLKRST_AUDIO_EN_POS            21
#define CLKRST_UART_EN_BIT             ((uint32_t)0x00080000)
#define CLKRST_UART_EN_POS             19
#define CLKRST_BB_PINMUX_BYPASS_BIT    ((uint32_t)0x00010000)
#define CLKRST_BB_PINMUX_BYPASS_POS    16
#define CLKRST_BB_OUT_SYNC_BIT         ((uint32_t)0x00008000)
#define CLKRST_BB_OUT_SYNC_POS         15
#define CLKRST_BB_CLK_MODE_BIT         ((uint32_t)0x00004000)
#define CLKRST_BB_CLK_MODE_POS         14
#define CLKRST_BB__REFRESH_MODE_MASK   ((uint32_t)0x00003000)
#define CLKRST_BB__REFRESH_MODE_LSB    12
#define CLKRST_BB__REFRESH_MODE_WIDTH  ((uint32_t)0x00000002)
#define CLKRST_BB_ENABLE_BIT           ((uint32_t)0x00000400)
#define CLKRST_BB_ENABLE_POS           10
#define CLKRST_TX_EN_INV_BIT           ((uint32_t)0x00000200)
#define CLKRST_TX_EN_INV_POS           9
#define CLKRST_TOGGLE_SAVE_MODE_BIT    ((uint32_t)0x00000100)
#define CLKRST_TOGGLE_SAVE_MODE_POS    8
#define CLKRST_RSSI_REG_MASK           ((uint32_t)0x000000FF)
#define CLKRST_RSSI_REG_LSB            0
#define CLKRST_RSSI_REG_WIDTH          ((uint32_t)0x00000008)

#define CLKRST_PD_DLL_PRE_RST          0x0
#define CLKRST_WLAN_WLRXBSY_RST        0x0
#define CLKRST_WLAN_FR_SYNC_RST        0x0
#define CLKRST_CPU_DIV2_SEL_RST        0x0
#define CLKRST_AUDIO_EN_RST            0x0
#define CLKRST_UART_EN_RST             0x0
#define CLKRST_BB_PINMUX_BYPASS_RST    0x0
#define CLKRST_BB_OUT_SYNC_RST         0x0
#define CLKRST_BB_CLK_MODE_RST         0x0
#define CLKRST_BB__REFRESH_MODE_RST    0x0
#define CLKRST_BB_ENABLE_RST           0x0
#define CLKRST_TX_EN_INV_RST           0x0
#define CLKRST_TOGGLE_SAVE_MODE_RST    0x0
#define CLKRST_RSSI_REG_RST            0x0

__INLINE void clkrst_top_ctrl_pack(uint8_t pddllpre, uint8_t wlanwlrxbsy, uint8_t wlanfrsync, uint8_t cpudiv2sel, uint8_t audioen, uint8_t uarten, uint8_t bbpinmuxbypass, uint8_t bboutsync, uint8_t bbclkmode, uint8_t bbrefreshmode, uint8_t bbenable, uint8_t txeninv, uint8_t togglesavemode, uint8_t rssireg)
{
    ASSERT_ERR((((uint32_t)pddllpre << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)wlanwlrxbsy << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)wlanfrsync << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)cpudiv2sel << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)audioen << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)uarten << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)bbpinmuxbypass << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)bboutsync << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)bbclkmode << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)bbrefreshmode << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)bbenable << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)txeninv << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)togglesavemode << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)rssireg << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR,  ((uint32_t)pddllpre << 31) | ((uint32_t)wlanwlrxbsy << 29) | ((uint32_t)wlanfrsync << 28) | ((uint32_t)cpudiv2sel << 26) | ((uint32_t)audioen << 21) | ((uint32_t)uarten << 19) | ((uint32_t)bbpinmuxbypass << 16) | ((uint32_t)bboutsync << 15) | ((uint32_t)bbclkmode << 14) | ((uint32_t)bbrefreshmode << 12) | ((uint32_t)bbenable << 10) | ((uint32_t)txeninv << 9) | ((uint32_t)togglesavemode << 8) | ((uint32_t)rssireg << 0));
}

__INLINE void clkrst_top_ctrl_unpack(uint8_t* pddllpre, uint8_t* wlanwlrxbsy, uint8_t* wlanfrsync, uint8_t* cpudiv2sel, uint8_t* audioen, uint8_t* uarten, uint8_t* bbpinmuxbypass, uint8_t* bboutsync, uint8_t* bbclkmode, uint8_t* bbrefreshmode, uint8_t* bbenable, uint8_t* txeninv, uint8_t* togglesavemode, uint8_t* rssireg)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    *pddllpre = (localVal & ((uint32_t)0x80000000)) >> 31;
    *wlanwlrxbsy = (localVal & ((uint32_t)0x20000000)) >> 29;
    *wlanfrsync = (localVal & ((uint32_t)0x10000000)) >> 28;
    *cpudiv2sel = (localVal & ((uint32_t)0x04000000)) >> 26;
    *audioen = (localVal & ((uint32_t)0x00200000)) >> 21;
    *uarten = (localVal & ((uint32_t)0x00080000)) >> 19;
    *bbpinmuxbypass = (localVal & ((uint32_t)0x00010000)) >> 16;
    *bboutsync = (localVal & ((uint32_t)0x00008000)) >> 15;
    *bbclkmode = (localVal & ((uint32_t)0x00004000)) >> 14;
    *bbrefreshmode = (localVal & ((uint32_t)0x00003000)) >> 12;
    *bbenable = (localVal & ((uint32_t)0x00000400)) >> 10;
    *txeninv = (localVal & ((uint32_t)0x00000200)) >> 9;
    *togglesavemode = (localVal & ((uint32_t)0x00000100)) >> 8;
    *rssireg = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t clkrst_pd_dll_pre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void clkrst_pd_dll_pre_setf(uint8_t pddllpre)
{
    ASSERT_ERR((((uint32_t)pddllpre << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)pddllpre << 31));
}

__INLINE uint8_t clkrst_wlan_wlrxbsy_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

__INLINE void clkrst_wlan_wlrxbsy_setf(uint8_t wlanwlrxbsy)
{
    ASSERT_ERR((((uint32_t)wlanwlrxbsy << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)wlanwlrxbsy << 29));
}

__INLINE uint8_t clkrst_wlan_fr_sync_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

__INLINE void clkrst_wlan_fr_sync_setf(uint8_t wlanfrsync)
{
    ASSERT_ERR((((uint32_t)wlanfrsync << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)wlanfrsync << 28));
}

__INLINE uint8_t clkrst_cpu_div2_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

__INLINE void clkrst_cpu_div2_sel_setf(uint8_t cpudiv2sel)
{
    ASSERT_ERR((((uint32_t)cpudiv2sel << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)cpudiv2sel << 26));
}

__INLINE uint8_t clkrst_audio_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

__INLINE void clkrst_audio_en_setf(uint8_t audioen)
{
    ASSERT_ERR((((uint32_t)audioen << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)audioen << 21));
}

__INLINE uint8_t clkrst_uart_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE void clkrst_uart_en_setf(uint8_t uarten)
{
    ASSERT_ERR((((uint32_t)uarten << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)uarten << 19));
}

__INLINE uint8_t clkrst_bb_pinmux_bypass_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE void clkrst_bb_pinmux_bypass_setf(uint8_t bbpinmuxbypass)
{
    ASSERT_ERR((((uint32_t)bbpinmuxbypass << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)bbpinmuxbypass << 16));
}

__INLINE uint8_t clkrst_bb_out_sync_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void clkrst_bb_out_sync_setf(uint8_t bboutsync)
{
    ASSERT_ERR((((uint32_t)bboutsync << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)bboutsync << 15));
}

__INLINE uint8_t clkrst_bb_clk_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void clkrst_bb_clk_mode_setf(uint8_t bbclkmode)
{
    ASSERT_ERR((((uint32_t)bbclkmode << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)bbclkmode << 14));
}

__INLINE uint8_t clkrst_bb__refresh_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void clkrst_bb__refresh_mode_setf(uint8_t bbrefreshmode)
{
    ASSERT_ERR((((uint32_t)bbrefreshmode << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)bbrefreshmode << 12));
}

__INLINE uint8_t clkrst_bb_enable_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE void clkrst_bb_enable_setf(uint8_t bbenable)
{
    ASSERT_ERR((((uint32_t)bbenable << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)bbenable << 10));
}

__INLINE uint8_t clkrst_tx_en_inv_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void clkrst_tx_en_inv_setf(uint8_t txeninv)
{
    ASSERT_ERR((((uint32_t)txeninv << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)txeninv << 9));
}

__INLINE uint8_t clkrst_toggle_save_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void clkrst_toggle_save_mode_setf(uint8_t togglesavemode)
{
    ASSERT_ERR((((uint32_t)togglesavemode << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)togglesavemode << 8));
}

__INLINE uint8_t clkrst_rssi_reg_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void clkrst_rssi_reg_setf(uint8_t rssireg)
{
    ASSERT_ERR((((uint32_t)rssireg << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(CLKRST_TOP_CTRL_ADDR, (REG_PL_RD(CLKRST_TOP_CTRL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssireg << 0));
}

/**
 * @brief RST_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31      SOFT_RST_CLKGEN   0
 *  29:16        SOFT_PRST_REQ   0x0
 *     15         SOFT_RST_ALL   0
 *     14         PCM_SOFT_RST   0
 *  13:00        SOFT_WRST_REQ   0x0
 * </pre>
 */
#define CLKRST_RST_CTRL_ADDR   0xC0012028
#define CLKRST_RST_CTRL_OFFSET 0x00000028
#define CLKRST_RST_CTRL_INDEX  0x0000000A
#define CLKRST_RST_CTRL_RESET  0x00000000

__INLINE uint32_t clkrst_rst_ctrl_get(void)
{
    return REG_PL_RD(CLKRST_RST_CTRL_ADDR);
}

__INLINE void clkrst_rst_ctrl_set(uint32_t value)
{
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, value);
}

// field definitions
#define CLKRST_SOFT_RST_CLKGEN_BIT    ((uint32_t)0x80000000)
#define CLKRST_SOFT_RST_CLKGEN_POS    31
#define CLKRST_SOFT_PRST_REQ_MASK     ((uint32_t)0x3FFF0000)
#define CLKRST_SOFT_PRST_REQ_LSB      16
#define CLKRST_SOFT_PRST_REQ_WIDTH    ((uint32_t)0x0000000E)
#define CLKRST_SOFT_RST_ALL_BIT       ((uint32_t)0x00008000)
#define CLKRST_SOFT_RST_ALL_POS       15
#define CLKRST_PCM_SOFT_RST_BIT       ((uint32_t)0x00004000)
#define CLKRST_PCM_SOFT_RST_POS       14
#define CLKRST_SOFT_WRST_REQ_MASK     ((uint32_t)0x00003FFF)
#define CLKRST_SOFT_WRST_REQ_LSB      0
#define CLKRST_SOFT_WRST_REQ_WIDTH    ((uint32_t)0x0000000E)

#define CLKRST_SOFT_RST_CLKGEN_RST    0x0
#define CLKRST_SOFT_PRST_REQ_RST      0x0
#define CLKRST_SOFT_RST_ALL_RST       0x0
#define CLKRST_PCM_SOFT_RST_RST       0x0
#define CLKRST_SOFT_WRST_REQ_RST      0x0

__INLINE void clkrst_rst_ctrl_pack(uint8_t softrstclkgen, uint16_t softprstreq, uint8_t softrstall, uint8_t pcmsoftrst, uint16_t softwrstreq)
{
    ASSERT_ERR((((uint32_t)softrstclkgen << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)softprstreq << 16) & ~((uint32_t)0x3FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)softrstall << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)pcmsoftrst << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)softwrstreq << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR,  ((uint32_t)softrstclkgen << 31) | ((uint32_t)softprstreq << 16) | ((uint32_t)softrstall << 15) | ((uint32_t)pcmsoftrst << 14) | ((uint32_t)softwrstreq << 0));
}

__INLINE void clkrst_rst_ctrl_unpack(uint8_t* softrstclkgen, uint16_t* softprstreq, uint8_t* softrstall, uint8_t* pcmsoftrst, uint16_t* softwrstreq)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    *softrstclkgen = (localVal & ((uint32_t)0x80000000)) >> 31;
    *softprstreq = (localVal & ((uint32_t)0x3FFF0000)) >> 16;
    *softrstall = (localVal & ((uint32_t)0x00008000)) >> 15;
    *pcmsoftrst = (localVal & ((uint32_t)0x00004000)) >> 14;
    *softwrstreq = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

__INLINE uint8_t clkrst_soft_rst_clkgen_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

__INLINE void clkrst_soft_rst_clkgen_setf(uint8_t softrstclkgen)
{
    ASSERT_ERR((((uint32_t)softrstclkgen << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, (REG_PL_RD(CLKRST_RST_CTRL_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)softrstclkgen << 31));
}

__INLINE uint16_t clkrst_soft_prst_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x3FFF0000)) >> 16);
}

__INLINE void clkrst_soft_prst_req_setf(uint16_t softprstreq)
{
    ASSERT_ERR((((uint32_t)softprstreq << 16) & ~((uint32_t)0x3FFF0000)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, (REG_PL_RD(CLKRST_RST_CTRL_ADDR) & ~((uint32_t)0x3FFF0000)) | ((uint32_t)softprstreq << 16));
}

__INLINE uint8_t clkrst_soft_rst_all_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

__INLINE void clkrst_soft_rst_all_setf(uint8_t softrstall)
{
    ASSERT_ERR((((uint32_t)softrstall << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, (REG_PL_RD(CLKRST_RST_CTRL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)softrstall << 15));
}

__INLINE uint8_t clkrst_pcm_soft_rst_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void clkrst_pcm_soft_rst_setf(uint8_t pcmsoftrst)
{
    ASSERT_ERR((((uint32_t)pcmsoftrst << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, (REG_PL_RD(CLKRST_RST_CTRL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)pcmsoftrst << 14));
}

__INLINE uint16_t clkrst_soft_wrst_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_RST_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

__INLINE void clkrst_soft_wrst_req_setf(uint16_t softwrstreq)
{
    ASSERT_ERR((((uint32_t)softwrstreq << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(CLKRST_RST_CTRL_ADDR, (REG_PL_RD(CLKRST_RST_CTRL_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)softwrstreq << 0));
}

/**
 * @brief DLL_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     09               DTB_EN   0
 *     08               PD_DLL   0
 *  07:06              LOCK_TD   0x0
 *     05       OUT_SEL_FSM_EN   0
 *     04              ATB_SEL   0
 *     03              DET_SEL   0
 *     02              OUT_SEL   0
 *  01:00         DLL_CP_IBSEL   0x0
 * </pre>
 */
#define CLKRST_DLL_CTRL_ADDR   0xC001205C
#define CLKRST_DLL_CTRL_OFFSET 0x0000005C
#define CLKRST_DLL_CTRL_INDEX  0x00000017
#define CLKRST_DLL_CTRL_RESET  0x00000000

__INLINE uint32_t clkrst_dll_ctrl_get(void)
{
    return REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
}

__INLINE void clkrst_dll_ctrl_set(uint32_t value)
{
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, value);
}

// field definitions
#define CLKRST_DTB_EN_BIT            ((uint32_t)0x00000200)
#define CLKRST_DTB_EN_POS            9
#define CLKRST_PD_DLL_BIT            ((uint32_t)0x00000100)
#define CLKRST_PD_DLL_POS            8
#define CLKRST_LOCK_TD_MASK          ((uint32_t)0x000000C0)
#define CLKRST_LOCK_TD_LSB           6
#define CLKRST_LOCK_TD_WIDTH         ((uint32_t)0x00000002)
#define CLKRST_OUT_SEL_FSM_EN_BIT    ((uint32_t)0x00000020)
#define CLKRST_OUT_SEL_FSM_EN_POS    5
#define CLKRST_ATB_SEL_BIT           ((uint32_t)0x00000010)
#define CLKRST_ATB_SEL_POS           4
#define CLKRST_DET_SEL_BIT           ((uint32_t)0x00000008)
#define CLKRST_DET_SEL_POS           3
#define CLKRST_OUT_SEL_BIT           ((uint32_t)0x00000004)
#define CLKRST_OUT_SEL_POS           2
#define CLKRST_DLL_CP_IBSEL_MASK     ((uint32_t)0x00000003)
#define CLKRST_DLL_CP_IBSEL_LSB      0
#define CLKRST_DLL_CP_IBSEL_WIDTH    ((uint32_t)0x00000002)

#define CLKRST_DTB_EN_RST            0x0
#define CLKRST_PD_DLL_RST            0x0
#define CLKRST_LOCK_TD_RST           0x0
#define CLKRST_OUT_SEL_FSM_EN_RST    0x0
#define CLKRST_ATB_SEL_RST           0x0
#define CLKRST_DET_SEL_RST           0x0
#define CLKRST_OUT_SEL_RST           0x0
#define CLKRST_DLL_CP_IBSEL_RST      0x0

__INLINE void clkrst_dll_ctrl_pack(uint8_t dtben, uint8_t pddll, uint8_t locktd, uint8_t outselfsmen, uint8_t atbsel, uint8_t detsel, uint8_t outsel, uint8_t dllcpibsel)
{
    ASSERT_ERR((((uint32_t)dtben << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)pddll << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)locktd << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)outselfsmen << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)atbsel << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)detsel << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)outsel << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)dllcpibsel << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR,  ((uint32_t)dtben << 9) | ((uint32_t)pddll << 8) | ((uint32_t)locktd << 6) | ((uint32_t)outselfsmen << 5) | ((uint32_t)atbsel << 4) | ((uint32_t)detsel << 3) | ((uint32_t)outsel << 2) | ((uint32_t)dllcpibsel << 0));
}

__INLINE void clkrst_dll_ctrl_unpack(uint8_t* dtben, uint8_t* pddll, uint8_t* locktd, uint8_t* outselfsmen, uint8_t* atbsel, uint8_t* detsel, uint8_t* outsel, uint8_t* dllcpibsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    *dtben = (localVal & ((uint32_t)0x00000200)) >> 9;
    *pddll = (localVal & ((uint32_t)0x00000100)) >> 8;
    *locktd = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *outselfsmen = (localVal & ((uint32_t)0x00000020)) >> 5;
    *atbsel = (localVal & ((uint32_t)0x00000010)) >> 4;
    *detsel = (localVal & ((uint32_t)0x00000008)) >> 3;
    *outsel = (localVal & ((uint32_t)0x00000004)) >> 2;
    *dllcpibsel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t clkrst_dtb_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE void clkrst_dtb_en_setf(uint8_t dtben)
{
    ASSERT_ERR((((uint32_t)dtben << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)dtben << 9));
}

__INLINE uint8_t clkrst_pd_dll_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void clkrst_pd_dll_setf(uint8_t pddll)
{
    ASSERT_ERR((((uint32_t)pddll << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)pddll << 8));
}

__INLINE uint8_t clkrst_lock_td_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void clkrst_lock_td_setf(uint8_t locktd)
{
    ASSERT_ERR((((uint32_t)locktd << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)locktd << 6));
}

__INLINE uint8_t clkrst_out_sel_fsm_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void clkrst_out_sel_fsm_en_setf(uint8_t outselfsmen)
{
    ASSERT_ERR((((uint32_t)outselfsmen << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)outselfsmen << 5));
}

__INLINE uint8_t clkrst_atb_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void clkrst_atb_sel_setf(uint8_t atbsel)
{
    ASSERT_ERR((((uint32_t)atbsel << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)atbsel << 4));
}

__INLINE uint8_t clkrst_det_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void clkrst_det_sel_setf(uint8_t detsel)
{
    ASSERT_ERR((((uint32_t)detsel << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)detsel << 3));
}

__INLINE uint8_t clkrst_out_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void clkrst_out_sel_setf(uint8_t outsel)
{
    ASSERT_ERR((((uint32_t)outsel << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)outsel << 2));
}

__INLINE uint8_t clkrst_dll_cp_ibsel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_DLL_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void clkrst_dll_cp_ibsel_setf(uint8_t dllcpibsel)
{
    ASSERT_ERR((((uint32_t)dllcpibsel << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(CLKRST_DLL_CTRL_ADDR, (REG_PL_RD(CLKRST_DLL_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)dllcpibsel << 0));
}

/**
 * @brief TOP_ST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:08      AUDIOPIN_STATUS   0x0
 *     05           PD_DLL_RDY   0
 *     04      DLL_OUT_SEL_FSM   0
 *     03             DLL_LOCK   0
 *     02       BTDM_STDBY_RDY   0
 *     00        BB_RX_IN_SYNC   0
 * </pre>
 */
#define CLKRST_TOP_ST_ADDR   0xC0012060
#define CLKRST_TOP_ST_OFFSET 0x00000060
#define CLKRST_TOP_ST_INDEX  0x00000018
#define CLKRST_TOP_ST_RESET  0x00000000

__INLINE uint32_t clkrst_top_st_get(void)
{
    return REG_PL_RD(CLKRST_TOP_ST_ADDR);
}

__INLINE void clkrst_top_st_set(uint32_t value)
{
    REG_PL_WR(CLKRST_TOP_ST_ADDR, value);
}

// field definitions
#define CLKRST_AUDIOPIN_STATUS_MASK   ((uint32_t)0x00FFFF00)
#define CLKRST_AUDIOPIN_STATUS_LSB    8
#define CLKRST_AUDIOPIN_STATUS_WIDTH  ((uint32_t)0x00000010)
#define CLKRST_PD_DLL_RDY_BIT         ((uint32_t)0x00000020)
#define CLKRST_PD_DLL_RDY_POS         5
#define CLKRST_DLL_OUT_SEL_FSM_BIT    ((uint32_t)0x00000010)
#define CLKRST_DLL_OUT_SEL_FSM_POS    4
#define CLKRST_DLL_LOCK_BIT           ((uint32_t)0x00000008)
#define CLKRST_DLL_LOCK_POS           3
#define CLKRST_BTDM_STDBY_RDY_BIT     ((uint32_t)0x00000004)
#define CLKRST_BTDM_STDBY_RDY_POS     2
#define CLKRST_BB_RX_IN_SYNC_BIT      ((uint32_t)0x00000001)
#define CLKRST_BB_RX_IN_SYNC_POS      0

#define CLKRST_AUDIOPIN_STATUS_RST    0x0
#define CLKRST_PD_DLL_RDY_RST         0x0
#define CLKRST_DLL_OUT_SEL_FSM_RST    0x0
#define CLKRST_DLL_LOCK_RST           0x0
#define CLKRST_BTDM_STDBY_RDY_RST     0x0
#define CLKRST_BB_RX_IN_SYNC_RST      0x0

__INLINE void clkrst_top_st_unpack(uint16_t* audiopinstatus, uint8_t* pddllrdy, uint8_t* dlloutselfsm, uint8_t* dlllock, uint8_t* btdmstdbyrdy, uint8_t* bbrxinsync)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    *audiopinstatus = (localVal & ((uint32_t)0x00FFFF00)) >> 8;
    *pddllrdy = (localVal & ((uint32_t)0x00000020)) >> 5;
    *dlloutselfsm = (localVal & ((uint32_t)0x00000010)) >> 4;
    *dlllock = (localVal & ((uint32_t)0x00000008)) >> 3;
    *btdmstdbyrdy = (localVal & ((uint32_t)0x00000004)) >> 2;
    *bbrxinsync = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint16_t clkrst_audiopin_status_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}

__INLINE uint8_t clkrst_pd_dll_rdy_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t clkrst_dll_out_sel_fsm_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void clkrst_dll_out_sel_fsm_setf(uint8_t dlloutselfsm)
{
    ASSERT_ERR((((uint32_t)dlloutselfsm << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(CLKRST_TOP_ST_ADDR, (uint32_t)dlloutselfsm << 4);
}

__INLINE uint8_t clkrst_dll_lock_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t clkrst_btdm_stdby_rdy_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t clkrst_bb_rx_in_sync_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_TOP_ST_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief PINMUX_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  13:12      PHASE_MATCH_SEL   0x0
 *  11:08       BB_RX_IN_DELAY   0x0
 *  07:00   BB_MATCH_THRESHOLD   0x0
 * </pre>
 */
#define CLKRST_PINMUX_CTRL_ADDR   0xC0012064
#define CLKRST_PINMUX_CTRL_OFFSET 0x00000064
#define CLKRST_PINMUX_CTRL_INDEX  0x00000019
#define CLKRST_PINMUX_CTRL_RESET  0x00000000

__INLINE uint32_t clkrst_pinmux_ctrl_get(void)
{
    return REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR);
}

__INLINE void clkrst_pinmux_ctrl_set(uint32_t value)
{
    REG_PL_WR(CLKRST_PINMUX_CTRL_ADDR, value);
}

// field definitions
#define CLKRST_PHASE_MATCH_SEL_MASK      ((uint32_t)0x00003000)
#define CLKRST_PHASE_MATCH_SEL_LSB       12
#define CLKRST_PHASE_MATCH_SEL_WIDTH     ((uint32_t)0x00000002)
#define CLKRST_BB_RX_IN_DELAY_MASK       ((uint32_t)0x00000F00)
#define CLKRST_BB_RX_IN_DELAY_LSB        8
#define CLKRST_BB_RX_IN_DELAY_WIDTH      ((uint32_t)0x00000004)
#define CLKRST_BB_MATCH_THRESHOLD_MASK   ((uint32_t)0x000000FF)
#define CLKRST_BB_MATCH_THRESHOLD_LSB    0
#define CLKRST_BB_MATCH_THRESHOLD_WIDTH  ((uint32_t)0x00000008)

#define CLKRST_PHASE_MATCH_SEL_RST       0x0
#define CLKRST_BB_RX_IN_DELAY_RST        0x0
#define CLKRST_BB_MATCH_THRESHOLD_RST    0x0

__INLINE void clkrst_pinmux_ctrl_pack(uint8_t phasematchsel, uint8_t bbrxindelay, uint8_t bbmatchthreshold)
{
    ASSERT_ERR((((uint32_t)phasematchsel << 12) & ~((uint32_t)0x00003000)) == 0);
    ASSERT_ERR((((uint32_t)bbrxindelay << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)bbmatchthreshold << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(CLKRST_PINMUX_CTRL_ADDR,  ((uint32_t)phasematchsel << 12) | ((uint32_t)bbrxindelay << 8) | ((uint32_t)bbmatchthreshold << 0));
}

__INLINE void clkrst_pinmux_ctrl_unpack(uint8_t* phasematchsel, uint8_t* bbrxindelay, uint8_t* bbmatchthreshold)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR);
    *phasematchsel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *bbrxindelay = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *bbmatchthreshold = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t clkrst_phase_match_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void clkrst_phase_match_sel_setf(uint8_t phasematchsel)
{
    ASSERT_ERR((((uint32_t)phasematchsel << 12) & ~((uint32_t)0x00003000)) == 0);
    REG_PL_WR(CLKRST_PINMUX_CTRL_ADDR, (REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)phasematchsel << 12));
}

__INLINE uint8_t clkrst_bb_rx_in_delay_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

__INLINE void clkrst_bb_rx_in_delay_setf(uint8_t bbrxindelay)
{
    ASSERT_ERR((((uint32_t)bbrxindelay << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(CLKRST_PINMUX_CTRL_ADDR, (REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)bbrxindelay << 8));
}

__INLINE uint8_t clkrst_bb_match_threshold_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

__INLINE void clkrst_bb_match_threshold_setf(uint8_t bbmatchthreshold)
{
    ASSERT_ERR((((uint32_t)bbmatchthreshold << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(CLKRST_PINMUX_CTRL_ADDR, (REG_PL_RD(CLKRST_PINMUX_CTRL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bbmatchthreshold << 0));
}


#endif // _REG_CLKRST_H_

