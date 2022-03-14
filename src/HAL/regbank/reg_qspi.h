#ifndef _REG_QSPI_H_
#define _REG_QSPI_H_

#include <stdint.h>
#include "_reg_qspi.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_QSPI_COUNT 18

#define REG_QSPI_DECODING_MASK 0x0000007F

/**
 * @brief REGTRAN_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:09             recv_cnt   0x0
 *     08              recv_en   0
 *     04                 ss_n   1
 *  03:02            byte_size   0x0
 *  01:00            line_mode   0x0
 * </pre>
 */
#define QSPI_REGTRAN_CTRL_ADDR   0xC0008000
#define QSPI_REGTRAN_CTRL_OFFSET 0x00000000
#define QSPI_REGTRAN_CTRL_INDEX  0x00000000
#define QSPI_REGTRAN_CTRL_RESET  0x00000010

__INLINE uint32_t qspi_regtran_ctrl_get(void)
{
    return REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
}

__INLINE void qspi_regtran_ctrl_set(uint32_t value)
{
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, value);
}

// field definitions
#define QSPI_REGTRAN_CTRL_RECV_CNT_MASK    ((uint32_t)0x0000FE00)
#define QSPI_REGTRAN_CTRL_RECV_CNT_LSB     9
#define QSPI_REGTRAN_CTRL_RECV_CNT_WIDTH   ((uint32_t)0x00000007)
#define QSPI_REGTRAN_CTRL_RECV_EN_BIT      ((uint32_t)0x00000100)
#define QSPI_REGTRAN_CTRL_RECV_EN_POS      8
#define QSPI_REGTRAN_CTRL_SS_N_BIT         ((uint32_t)0x00000010)
#define QSPI_REGTRAN_CTRL_SS_N_POS         4
#define QSPI_REGTRAN_CTRL_BYTE_SIZE_MASK   ((uint32_t)0x0000000C)
#define QSPI_REGTRAN_CTRL_BYTE_SIZE_LSB    2
#define QSPI_REGTRAN_CTRL_BYTE_SIZE_WIDTH  ((uint32_t)0x00000002)
#define QSPI_REGTRAN_CTRL_LINE_MODE_MASK   ((uint32_t)0x00000003)
#define QSPI_REGTRAN_CTRL_LINE_MODE_LSB    0
#define QSPI_REGTRAN_CTRL_LINE_MODE_WIDTH  ((uint32_t)0x00000002)

#define QSPI_REGTRAN_CTRL_RECV_CNT_RST     0x0
#define QSPI_REGTRAN_CTRL_RECV_EN_RST      0x0
#define QSPI_REGTRAN_CTRL_SS_N_RST         0x1
#define QSPI_REGTRAN_CTRL_BYTE_SIZE_RST    0x0
#define QSPI_REGTRAN_CTRL_LINE_MODE_RST    0x0

__INLINE void qspi_regtran_ctrl_pack(uint8_t recvcnt, uint8_t recven, uint8_t ssn, uint8_t bytesize, uint8_t linemode)
{
    ASSERT_ERR((((uint32_t)recvcnt << 9) & ~((uint32_t)0x0000FE00)) == 0);
    ASSERT_ERR((((uint32_t)recven << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)ssn << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)bytesize << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)linemode << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR,  ((uint32_t)recvcnt << 9) | ((uint32_t)recven << 8) | ((uint32_t)ssn << 4) | ((uint32_t)bytesize << 2) | ((uint32_t)linemode << 0));
}

__INLINE void qspi_regtran_ctrl_unpack(uint8_t* recvcnt, uint8_t* recven, uint8_t* ssn, uint8_t* bytesize, uint8_t* linemode)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    *recvcnt = (localVal & ((uint32_t)0x0000FE00)) >> 9;
    *recven = (localVal & ((uint32_t)0x00000100)) >> 8;
    *ssn = (localVal & ((uint32_t)0x00000010)) >> 4;
    *bytesize = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *linemode = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t qspi_regtran_ctrl_recv_cnt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000FE00)) >> 9);
}

__INLINE void qspi_regtran_ctrl_recv_cnt_setf(uint8_t recvcnt)
{
    ASSERT_ERR((((uint32_t)recvcnt << 9) & ~((uint32_t)0x0000FE00)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, (REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR) & ~((uint32_t)0x0000FE00)) | ((uint32_t)recvcnt << 9));
}

__INLINE uint8_t qspi_regtran_ctrl_recv_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void qspi_regtran_ctrl_recv_en_setf(uint8_t recven)
{
    ASSERT_ERR((((uint32_t)recven << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, (REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)recven << 8));
}

__INLINE uint8_t qspi_regtran_ctrl_ss_n_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void qspi_regtran_ctrl_ss_n_setf(uint8_t ssn)
{
    ASSERT_ERR((((uint32_t)ssn << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, (REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)ssn << 4));
}

__INLINE uint8_t qspi_regtran_ctrl_byte_size_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void qspi_regtran_ctrl_byte_size_setf(uint8_t bytesize)
{
    ASSERT_ERR((((uint32_t)bytesize << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, (REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)bytesize << 2));
}

__INLINE uint8_t qspi_regtran_ctrl_line_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void qspi_regtran_ctrl_line_mode_setf(uint8_t linemode)
{
    ASSERT_ERR((((uint32_t)linemode << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(QSPI_REGTRAN_CTRL_ADDR, (REG_PL_RD(QSPI_REGTRAN_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)linemode << 0));
}

/**
 * @brief XIP_CTRL0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00              xip_req   1
 * </pre>
 */
#define QSPI_XIP_CTRL0_ADDR   0xC0008010
#define QSPI_XIP_CTRL0_OFFSET 0x00000010
#define QSPI_XIP_CTRL0_INDEX  0x00000004
#define QSPI_XIP_CTRL0_RESET  0x00000001

__INLINE uint32_t qspi_xip_ctrl0_get(void)
{
    return REG_PL_RD(QSPI_XIP_CTRL0_ADDR);
}

__INLINE void qspi_xip_ctrl0_set(uint32_t value)
{
    REG_PL_WR(QSPI_XIP_CTRL0_ADDR, value);
}

// field definitions
#define QSPI_XIP_CTRL0_XIP_REQ_BIT    ((uint32_t)0x00000001)
#define QSPI_XIP_CTRL0_XIP_REQ_POS    0

#define QSPI_XIP_CTRL0_XIP_REQ_RST    0x1

__INLINE uint8_t qspi_xip_ctrl0_xip_req_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void qspi_xip_ctrl0_xip_req_setf(uint8_t xipreq)
{
    ASSERT_ERR((((uint32_t)xipreq << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL0_ADDR, (uint32_t)xipreq << 0);
}

/**
 * @brief XIP_CTRL1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     03    xip_wrap_read_sel   0
 *     02    xip_quad_fast_sel   0
 *     01         xip_quad_sel   0
 *     00         xip_dual_sel   0
 * </pre>
 */
#define QSPI_XIP_CTRL1_ADDR   0xC0008014
#define QSPI_XIP_CTRL1_OFFSET 0x00000014
#define QSPI_XIP_CTRL1_INDEX  0x00000005
#define QSPI_XIP_CTRL1_RESET  0x00000000

__INLINE uint32_t qspi_xip_ctrl1_get(void)
{
    return REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
}

__INLINE void qspi_xip_ctrl1_set(uint32_t value)
{
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR, value);
}

// field definitions
#define QSPI_XIP_CTRL1_XIP_WRAP_READ_SEL_BIT    ((uint32_t)0x00000008)
#define QSPI_XIP_CTRL1_XIP_WRAP_READ_SEL_POS    3
#define QSPI_XIP_CTRL1_XIP_QUAD_FAST_SEL_BIT    ((uint32_t)0x00000004)
#define QSPI_XIP_CTRL1_XIP_QUAD_FAST_SEL_POS    2
#define QSPI_XIP_CTRL1_XIP_QUAD_SEL_BIT         ((uint32_t)0x00000002)
#define QSPI_XIP_CTRL1_XIP_QUAD_SEL_POS         1
#define QSPI_XIP_CTRL1_XIP_DUAL_SEL_BIT         ((uint32_t)0x00000001)
#define QSPI_XIP_CTRL1_XIP_DUAL_SEL_POS         0

#define QSPI_XIP_CTRL1_XIP_WRAP_READ_SEL_RST    0x0
#define QSPI_XIP_CTRL1_XIP_QUAD_FAST_SEL_RST    0x0
#define QSPI_XIP_CTRL1_XIP_QUAD_SEL_RST         0x0
#define QSPI_XIP_CTRL1_XIP_DUAL_SEL_RST         0x0

__INLINE void qspi_xip_ctrl1_pack(uint8_t xipwrapreadsel, uint8_t xipquadfastsel, uint8_t xipquadsel, uint8_t xipdualsel)
{
    ASSERT_ERR((((uint32_t)xipwrapreadsel << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)xipquadfastsel << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)xipquadsel << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)xipdualsel << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR,  ((uint32_t)xipwrapreadsel << 3) | ((uint32_t)xipquadfastsel << 2) | ((uint32_t)xipquadsel << 1) | ((uint32_t)xipdualsel << 0));
}

__INLINE void qspi_xip_ctrl1_unpack(uint8_t* xipwrapreadsel, uint8_t* xipquadfastsel, uint8_t* xipquadsel, uint8_t* xipdualsel)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
    *xipwrapreadsel = (localVal & ((uint32_t)0x00000008)) >> 3;
    *xipquadfastsel = (localVal & ((uint32_t)0x00000004)) >> 2;
    *xipquadsel = (localVal & ((uint32_t)0x00000002)) >> 1;
    *xipdualsel = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t qspi_xip_ctrl1_xip_wrap_read_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void qspi_xip_ctrl1_xip_wrap_read_sel_setf(uint8_t xipwrapreadsel)
{
    ASSERT_ERR((((uint32_t)xipwrapreadsel << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR, (REG_PL_RD(QSPI_XIP_CTRL1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)xipwrapreadsel << 3));
}

__INLINE uint8_t qspi_xip_ctrl1_xip_quad_fast_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void qspi_xip_ctrl1_xip_quad_fast_sel_setf(uint8_t xipquadfastsel)
{
    ASSERT_ERR((((uint32_t)xipquadfastsel << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR, (REG_PL_RD(QSPI_XIP_CTRL1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)xipquadfastsel << 2));
}

__INLINE uint8_t qspi_xip_ctrl1_xip_quad_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void qspi_xip_ctrl1_xip_quad_sel_setf(uint8_t xipquadsel)
{
    ASSERT_ERR((((uint32_t)xipquadsel << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR, (REG_PL_RD(QSPI_XIP_CTRL1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)xipquadsel << 1));
}

__INLINE uint8_t qspi_xip_ctrl1_xip_dual_sel_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_CTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void qspi_xip_ctrl1_xip_dual_sel_setf(uint8_t xipdualsel)
{
    ASSERT_ERR((((uint32_t)xipdualsel << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(QSPI_XIP_CTRL1_ADDR, (REG_PL_RD(QSPI_XIP_CTRL1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)xipdualsel << 0));
}

/**
 * @brief XIP_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01     eflash_rdqe_done   0
 *     00            eflash_qe   0
 * </pre>
 */
#define QSPI_XIP_STATUS_ADDR   0xC0008018
#define QSPI_XIP_STATUS_OFFSET 0x00000018
#define QSPI_XIP_STATUS_INDEX  0x00000006
#define QSPI_XIP_STATUS_RESET  0x00000000

__INLINE uint32_t qspi_xip_status_get(void)
{
    return REG_PL_RD(QSPI_XIP_STATUS_ADDR);
}

// field definitions
#define QSPI_XIP_STATUS_EFLASH_RDQE_DONE_BIT    ((uint32_t)0x00000002)
#define QSPI_XIP_STATUS_EFLASH_RDQE_DONE_POS    1
#define QSPI_XIP_STATUS_EFLASH_QE_BIT           ((uint32_t)0x00000001)
#define QSPI_XIP_STATUS_EFLASH_QE_POS           0

#define QSPI_XIP_STATUS_EFLASH_RDQE_DONE_RST    0x0
#define QSPI_XIP_STATUS_EFLASH_QE_RST           0x0

__INLINE void qspi_xip_status_unpack(uint8_t* eflashrdqedone, uint8_t* eflashqe)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_STATUS_ADDR);
    *eflashrdqedone = (localVal & ((uint32_t)0x00000002)) >> 1;
    *eflashqe = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t qspi_xip_status_eflash_rdqe_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t qspi_xip_status_eflash_qe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_XIP_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief FIFO_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:01     fifo_water_level   0x0
 *     00           fifo_flush   0
 * </pre>
 */
#define QSPI_FIFO_CTRL_ADDR   0xC0008020
#define QSPI_FIFO_CTRL_OFFSET 0x00000020
#define QSPI_FIFO_CTRL_INDEX  0x00000008
#define QSPI_FIFO_CTRL_RESET  0x00000000

__INLINE uint32_t qspi_fifo_ctrl_get(void)
{
    return REG_PL_RD(QSPI_FIFO_CTRL_ADDR);
}

__INLINE void qspi_fifo_ctrl_set(uint32_t value)
{
    REG_PL_WR(QSPI_FIFO_CTRL_ADDR, value);
}

// field definitions
#define QSPI_FIFO_CTRL_FIFO_WATER_LEVEL_MASK   ((uint32_t)0x000000FE)
#define QSPI_FIFO_CTRL_FIFO_WATER_LEVEL_LSB    1
#define QSPI_FIFO_CTRL_FIFO_WATER_LEVEL_WIDTH  ((uint32_t)0x00000007)
#define QSPI_FIFO_CTRL_FIFO_FLUSH_BIT          ((uint32_t)0x00000001)
#define QSPI_FIFO_CTRL_FIFO_FLUSH_POS          0

#define QSPI_FIFO_CTRL_FIFO_WATER_LEVEL_RST    0x0
#define QSPI_FIFO_CTRL_FIFO_FLUSH_RST          0x0

__INLINE void qspi_fifo_ctrl_pack(uint8_t fifowaterlevel, uint8_t fifoflush)
{
    ASSERT_ERR((((uint32_t)fifowaterlevel << 1) & ~((uint32_t)0x000000FE)) == 0);
    ASSERT_ERR((((uint32_t)fifoflush << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(QSPI_FIFO_CTRL_ADDR,  ((uint32_t)fifowaterlevel << 1) | ((uint32_t)fifoflush << 0));
}

__INLINE void qspi_fifo_ctrl_unpack(uint8_t* fifowaterlevel, uint8_t* fifoflush)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_CTRL_ADDR);
    *fifowaterlevel = (localVal & ((uint32_t)0x000000FE)) >> 1;
    *fifoflush = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t qspi_fifo_ctrl_fifo_water_level_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000FE)) >> 1);
}

__INLINE void qspi_fifo_ctrl_fifo_water_level_setf(uint8_t fifowaterlevel)
{
    ASSERT_ERR((((uint32_t)fifowaterlevel << 1) & ~((uint32_t)0x000000FE)) == 0);
    REG_PL_WR(QSPI_FIFO_CTRL_ADDR, (REG_PL_RD(QSPI_FIFO_CTRL_ADDR) & ~((uint32_t)0x000000FE)) | ((uint32_t)fifowaterlevel << 1));
}

__INLINE uint8_t qspi_fifo_ctrl_fifo_flush_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void qspi_fifo_ctrl_fifo_flush_setf(uint8_t fifoflush)
{
    ASSERT_ERR((((uint32_t)fifoflush << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(QSPI_FIFO_CTRL_ADDR, (REG_PL_RD(QSPI_FIFO_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fifoflush << 0));
}

/**
 * @brief FIFO_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:24            rx_length   0x0
 *     20            rx_finish   0
 *     19             rx_empty   1
 *     18              rx_full   0
 *     17           rx_loalert   1
 *     16           rx_hialert   0
 *  15:08            tx_length   0x0
 *     04            tx_finish   0
 *     03             tx_empty   1
 *     02              tx_full   0
 *     01           tx_loalert   1
 *     00           tx_hialert   0
 * </pre>
 */
#define QSPI_FIFO_STATUS_ADDR   0xC0008024
#define QSPI_FIFO_STATUS_OFFSET 0x00000024
#define QSPI_FIFO_STATUS_INDEX  0x00000009
#define QSPI_FIFO_STATUS_RESET  0x000A000A

__INLINE uint32_t qspi_fifo_status_get(void)
{
    return REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
}

__INLINE void qspi_fifo_status_set(uint32_t value)
{
    REG_PL_WR(QSPI_FIFO_STATUS_ADDR, value);
}

// field definitions
#define QSPI_FIFO_STATUS_RX_LENGTH_MASK    ((uint32_t)0xFF000000)
#define QSPI_FIFO_STATUS_RX_LENGTH_LSB     24
#define QSPI_FIFO_STATUS_RX_LENGTH_WIDTH   ((uint32_t)0x00000008)
#define QSPI_FIFO_STATUS_RX_FINISH_BIT     ((uint32_t)0x00100000)
#define QSPI_FIFO_STATUS_RX_FINISH_POS     20
#define QSPI_FIFO_STATUS_RX_EMPTY_BIT      ((uint32_t)0x00080000)
#define QSPI_FIFO_STATUS_RX_EMPTY_POS      19
#define QSPI_FIFO_STATUS_RX_FULL_BIT       ((uint32_t)0x00040000)
#define QSPI_FIFO_STATUS_RX_FULL_POS       18
#define QSPI_FIFO_STATUS_RX_LOALERT_BIT    ((uint32_t)0x00020000)
#define QSPI_FIFO_STATUS_RX_LOALERT_POS    17
#define QSPI_FIFO_STATUS_RX_HIALERT_BIT    ((uint32_t)0x00010000)
#define QSPI_FIFO_STATUS_RX_HIALERT_POS    16
#define QSPI_FIFO_STATUS_TX_LENGTH_MASK    ((uint32_t)0x0000FF00)
#define QSPI_FIFO_STATUS_TX_LENGTH_LSB     8
#define QSPI_FIFO_STATUS_TX_LENGTH_WIDTH   ((uint32_t)0x00000008)
#define QSPI_FIFO_STATUS_TX_FINISH_BIT     ((uint32_t)0x00000010)
#define QSPI_FIFO_STATUS_TX_FINISH_POS     4
#define QSPI_FIFO_STATUS_TX_EMPTY_BIT      ((uint32_t)0x00000008)
#define QSPI_FIFO_STATUS_TX_EMPTY_POS      3
#define QSPI_FIFO_STATUS_TX_FULL_BIT       ((uint32_t)0x00000004)
#define QSPI_FIFO_STATUS_TX_FULL_POS       2
#define QSPI_FIFO_STATUS_TX_LOALERT_BIT    ((uint32_t)0x00000002)
#define QSPI_FIFO_STATUS_TX_LOALERT_POS    1
#define QSPI_FIFO_STATUS_TX_HIALERT_BIT    ((uint32_t)0x00000001)
#define QSPI_FIFO_STATUS_TX_HIALERT_POS    0

#define QSPI_FIFO_STATUS_RX_LENGTH_RST     0x0
#define QSPI_FIFO_STATUS_RX_FINISH_RST     0x0
#define QSPI_FIFO_STATUS_RX_EMPTY_RST      0x1
#define QSPI_FIFO_STATUS_RX_FULL_RST       0x0
#define QSPI_FIFO_STATUS_RX_LOALERT_RST    0x1
#define QSPI_FIFO_STATUS_RX_HIALERT_RST    0x0
#define QSPI_FIFO_STATUS_TX_LENGTH_RST     0x0
#define QSPI_FIFO_STATUS_TX_FINISH_RST     0x0
#define QSPI_FIFO_STATUS_TX_EMPTY_RST      0x1
#define QSPI_FIFO_STATUS_TX_FULL_RST       0x0
#define QSPI_FIFO_STATUS_TX_LOALERT_RST    0x1
#define QSPI_FIFO_STATUS_TX_HIALERT_RST    0x0

__INLINE void qspi_fifo_status_unpack(uint8_t* rxlength, uint8_t* rxfinish, uint8_t* rxempty, uint8_t* rxfull, uint8_t* rxloalert, uint8_t* rxhialert, uint8_t* txlength, uint8_t* txfinish, uint8_t* txempty, uint8_t* txfull, uint8_t* txloalert, uint8_t* txhialert)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    *rxlength = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *rxfinish = (localVal & ((uint32_t)0x00100000)) >> 20;
    *rxempty = (localVal & ((uint32_t)0x00080000)) >> 19;
    *rxfull = (localVal & ((uint32_t)0x00040000)) >> 18;
    *rxloalert = (localVal & ((uint32_t)0x00020000)) >> 17;
    *rxhialert = (localVal & ((uint32_t)0x00010000)) >> 16;
    *txlength = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *txfinish = (localVal & ((uint32_t)0x00000010)) >> 4;
    *txempty = (localVal & ((uint32_t)0x00000008)) >> 3;
    *txfull = (localVal & ((uint32_t)0x00000004)) >> 2;
    *txloalert = (localVal & ((uint32_t)0x00000002)) >> 1;
    *txhialert = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t qspi_fifo_status_rx_length_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

__INLINE uint8_t qspi_fifo_status_rx_finish_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

__INLINE uint8_t qspi_fifo_status_rx_empty_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

__INLINE uint8_t qspi_fifo_status_rx_full_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

__INLINE uint8_t qspi_fifo_status_rx_loalert_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

__INLINE uint8_t qspi_fifo_status_rx_hialert_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

__INLINE uint8_t qspi_fifo_status_tx_length_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE uint8_t qspi_fifo_status_tx_finish_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t qspi_fifo_status_tx_empty_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t qspi_fifo_status_tx_full_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t qspi_fifo_status_tx_loalert_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t qspi_fifo_status_tx_hialert_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_FIFO_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief EFLASH_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     23        eflash_pup_en   0
 *  22:00      eflash_pup_time   0x0
 * </pre>
 */
#define QSPI_EFLASH_CTRL_ADDR   0xC0008030
#define QSPI_EFLASH_CTRL_OFFSET 0x00000030
#define QSPI_EFLASH_CTRL_INDEX  0x0000000C
#define QSPI_EFLASH_CTRL_RESET  0x00000000

__INLINE uint32_t qspi_eflash_ctrl_get(void)
{
    return REG_PL_RD(QSPI_EFLASH_CTRL_ADDR);
}

__INLINE void qspi_eflash_ctrl_set(uint32_t value)
{
    REG_PL_WR(QSPI_EFLASH_CTRL_ADDR, value);
}

// field definitions
#define QSPI_EFLASH_CTRL_EFLASH_PUP_EN_BIT      ((uint32_t)0x00800000)
#define QSPI_EFLASH_CTRL_EFLASH_PUP_EN_POS      23
#define QSPI_EFLASH_CTRL_EFLASH_PUP_TIME_MASK   ((uint32_t)0x007FFFFF)
#define QSPI_EFLASH_CTRL_EFLASH_PUP_TIME_LSB    0
#define QSPI_EFLASH_CTRL_EFLASH_PUP_TIME_WIDTH  ((uint32_t)0x00000017)

#define QSPI_EFLASH_CTRL_EFLASH_PUP_EN_RST      0x0
#define QSPI_EFLASH_CTRL_EFLASH_PUP_TIME_RST    0x0

__INLINE void qspi_eflash_ctrl_pack(uint8_t eflashpupen, uint32_t eflashpuptime)
{
    ASSERT_ERR((((uint32_t)eflashpupen << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)eflashpuptime << 0) & ~((uint32_t)0x007FFFFF)) == 0);
    REG_PL_WR(QSPI_EFLASH_CTRL_ADDR,  ((uint32_t)eflashpupen << 23) | ((uint32_t)eflashpuptime << 0));
}

__INLINE void qspi_eflash_ctrl_unpack(uint8_t* eflashpupen, uint32_t* eflashpuptime)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_CTRL_ADDR);
    *eflashpupen = (localVal & ((uint32_t)0x00800000)) >> 23;
    *eflashpuptime = (localVal & ((uint32_t)0x007FFFFF)) >> 0;
}

__INLINE uint8_t qspi_eflash_ctrl_eflash_pup_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

__INLINE void qspi_eflash_ctrl_eflash_pup_en_setf(uint8_t eflashpupen)
{
    ASSERT_ERR((((uint32_t)eflashpupen << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(QSPI_EFLASH_CTRL_ADDR, (REG_PL_RD(QSPI_EFLASH_CTRL_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)eflashpupen << 23));
}

__INLINE uint32_t qspi_eflash_ctrl_eflash_pup_time_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x007FFFFF)) >> 0);
}

__INLINE void qspi_eflash_ctrl_eflash_pup_time_setf(uint32_t eflashpuptime)
{
    ASSERT_ERR((((uint32_t)eflashpuptime << 0) & ~((uint32_t)0x007FFFFF)) == 0);
    REG_PL_WR(QSPI_EFLASH_CTRL_ADDR, (REG_PL_RD(QSPI_EFLASH_CTRL_ADDR) & ~((uint32_t)0x007FFFFF)) | ((uint32_t)eflashpuptime << 0));
}

/**
 * @brief EFLASH_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     24      eflash_pup_done   0
 *  15:08          eflash_line   0x0
 *  07:00          eflash_type   0x0
 * </pre>
 */
#define QSPI_EFLASH_STATUS_ADDR   0xC0008034
#define QSPI_EFLASH_STATUS_OFFSET 0x00000034
#define QSPI_EFLASH_STATUS_INDEX  0x0000000D
#define QSPI_EFLASH_STATUS_RESET  0x00000000

__INLINE uint32_t qspi_eflash_status_get(void)
{
    return REG_PL_RD(QSPI_EFLASH_STATUS_ADDR);
}

// field definitions
#define QSPI_EFLASH_STATUS_EFLASH_PUP_DONE_BIT    ((uint32_t)0x01000000)
#define QSPI_EFLASH_STATUS_EFLASH_PUP_DONE_POS    24
#define QSPI_EFLASH_STATUS_EFLASH_LINE_MASK       ((uint32_t)0x0000FF00)
#define QSPI_EFLASH_STATUS_EFLASH_LINE_LSB        8
#define QSPI_EFLASH_STATUS_EFLASH_LINE_WIDTH      ((uint32_t)0x00000008)
#define QSPI_EFLASH_STATUS_EFLASH_TYPE_MASK       ((uint32_t)0x000000FF)
#define QSPI_EFLASH_STATUS_EFLASH_TYPE_LSB        0
#define QSPI_EFLASH_STATUS_EFLASH_TYPE_WIDTH      ((uint32_t)0x00000008)

#define QSPI_EFLASH_STATUS_EFLASH_PUP_DONE_RST    0x0
#define QSPI_EFLASH_STATUS_EFLASH_LINE_RST        0x0
#define QSPI_EFLASH_STATUS_EFLASH_TYPE_RST        0x0

__INLINE void qspi_eflash_status_unpack(uint8_t* eflashpupdone, uint8_t* eflashline, uint8_t* eflashtype)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_STATUS_ADDR);
    *eflashpupdone = (localVal & ((uint32_t)0x01000000)) >> 24;
    *eflashline = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *eflashtype = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE uint8_t qspi_eflash_status_eflash_pup_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint8_t qspi_eflash_status_eflash_line_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

__INLINE uint8_t qspi_eflash_status_eflash_type_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief EFLASH_ID register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     24     eflash_rdid_done   0
 *  23:00            eflash_id   0x0
 * </pre>
 */
#define QSPI_EFLASH_ID_ADDR   0xC0008038
#define QSPI_EFLASH_ID_OFFSET 0x00000038
#define QSPI_EFLASH_ID_INDEX  0x0000000E
#define QSPI_EFLASH_ID_RESET  0x00000000

__INLINE uint32_t qspi_eflash_id_get(void)
{
    return REG_PL_RD(QSPI_EFLASH_ID_ADDR);
}

// field definitions
#define QSPI_EFLASH_ID_EFLASH_RDID_DONE_BIT    ((uint32_t)0x01000000)
#define QSPI_EFLASH_ID_EFLASH_RDID_DONE_POS    24
#define QSPI_EFLASH_ID_EFLASH_ID_MASK          ((uint32_t)0x00FFFFFF)
#define QSPI_EFLASH_ID_EFLASH_ID_LSB           0
#define QSPI_EFLASH_ID_EFLASH_ID_WIDTH         ((uint32_t)0x00000018)

#define QSPI_EFLASH_ID_EFLASH_RDID_DONE_RST    0x0
#define QSPI_EFLASH_ID_EFLASH_ID_RST           0x0

__INLINE void qspi_eflash_id_unpack(uint8_t* eflashrdiddone, uint32_t* eflashid)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_ID_ADDR);
    *eflashrdiddone = (localVal & ((uint32_t)0x01000000)) >> 24;
    *eflashid = (localVal & ((uint32_t)0x00FFFFFF)) >> 0;
}

__INLINE uint8_t qspi_eflash_id_eflash_rdid_done_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_ID_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

__INLINE uint32_t qspi_eflash_id_eflash_id_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_EFLASH_ID_ADDR);
    return ((localVal & ((uint32_t)0x00FFFFFF)) >> 0);
}

/**
 * @brief TX_DR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                tx_dr   0x0
 * </pre>
 */
#define QSPI_TX_DR_ADDR   0xC0008040
#define QSPI_TX_DR_OFFSET 0x00000040
#define QSPI_TX_DR_INDEX  0x00000010
#define QSPI_TX_DR_RESET  0x00000000

__INLINE uint32_t qspi_tx_dr_get(void)
{
    return REG_PL_RD(QSPI_TX_DR_ADDR);
}

__INLINE void qspi_tx_dr_set(uint32_t value)
{
    REG_PL_WR(QSPI_TX_DR_ADDR, value);
}

// field definitions
#define QSPI_TX_DR_TX_DR_MASK   ((uint32_t)0xFFFFFFFF)
#define QSPI_TX_DR_TX_DR_LSB    0
#define QSPI_TX_DR_TX_DR_WIDTH  ((uint32_t)0x00000020)

#define QSPI_TX_DR_TX_DR_RST    0x0

__INLINE uint32_t qspi_tx_dr_tx_dr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_TX_DR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void qspi_tx_dr_tx_dr_setf(uint32_t txdr)
{
    ASSERT_ERR((((uint32_t)txdr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(QSPI_TX_DR_ADDR, (uint32_t)txdr << 0);
}

/**
 * @brief RX_DR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                rx_dr   0x0
 * </pre>
 */
#define QSPI_RX_DR_ADDR   0xC0008044
#define QSPI_RX_DR_OFFSET 0x00000044
#define QSPI_RX_DR_INDEX  0x00000011
#define QSPI_RX_DR_RESET  0x00000000

__INLINE uint32_t qspi_rx_dr_get(void)
{
    return REG_PL_RD(QSPI_RX_DR_ADDR);
}

// field definitions
#define QSPI_RX_DR_RX_DR_MASK   ((uint32_t)0xFFFFFFFF)
#define QSPI_RX_DR_RX_DR_LSB    0
#define QSPI_RX_DR_RX_DR_WIDTH  ((uint32_t)0x00000020)

#define QSPI_RX_DR_RX_DR_RST    0x0

__INLINE uint32_t qspi_rx_dr_rx_dr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(QSPI_RX_DR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_QSPI_H_

