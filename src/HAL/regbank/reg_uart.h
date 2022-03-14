#ifndef _REG_UART_H_
#define _REG_UART_H_

#include <stdint.h>
#include "_reg_uart.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_UART_COUNT 64

#define REG_UART_DECODING_MASK 0x000000FF

/**
 * @brief RBR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00               RXDATA   0x0
 * </pre>
 */
#define UART_RBR_ADDR   0xC0011800
#define UART_RBR_OFFSET 0x00000000
#define UART_RBR_INDEX  0x00000000
#define UART_RBR_RESET  0x00000000

__INLINE uint32_t uart_rbr_get(void)
{
    return REG_PL_RD(UART_RBR_ADDR);
}

// field definitions
#define UART_RXDATA_MASK   ((uint32_t)0x000000FF)
#define UART_RXDATA_LSB    0
#define UART_RXDATA_WIDTH  ((uint32_t)0x00000008)

#define UART_RXDATA_RST    0x0

__INLINE uint8_t uart_rxdata_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_RBR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief THR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00               TXDATA   0x0
 * </pre>
 */
#define UART_THR_ADDR   0xC0011800
#define UART_THR_OFFSET 0x00000000
#define UART_THR_INDEX  0x00000000
#define UART_THR_RESET  0x00000000

__INLINE void uart_thr_set(uint32_t value)
{
    REG_PL_WR(UART_THR_ADDR, value);
}

// field definitions
#define UART_TXDATA_MASK   ((uint32_t)0x000000FF)
#define UART_TXDATA_LSB    0
#define UART_TXDATA_WIDTH  ((uint32_t)0x00000008)

#define UART_TXDATA_RST    0x0

__INLINE void uart_txdata_setf(uint8_t txdata)
{
    ASSERT_ERR((((uint32_t)txdata << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_THR_ADDR, (uint32_t)txdata << 0);
}

/**
 * @brief DLL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00               BD_DIV   0x0
 * </pre>
 */
#define UART_DLL_ADDR   0xC0011800
#define UART_DLL_OFFSET 0x00000000
#define UART_DLL_INDEX  0x00000000
#define UART_DLL_RESET  0x00000000

__INLINE uint32_t uart_dll_get(void)
{
    return REG_PL_RD(UART_DLL_ADDR);
}

__INLINE void uart_dll_set(uint32_t value)
{
    REG_PL_WR(UART_DLL_ADDR, value);
}

// field definitions
#define UART_BD_DIV_MASK   ((uint32_t)0x000000FF)
#define UART_BD_DIV_LSB    0
#define UART_BD_DIV_WIDTH  ((uint32_t)0x00000008)

#define UART_BD_DIV_RST    0x0

__INLINE uint8_t uart_bd_div_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_DLL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_bd_div_setf(uint8_t bddiv)
{
    ASSERT_ERR((((uint32_t)bddiv << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_DLL_ADDR, (uint32_t)bddiv << 0);
}

/**
 * @brief DLH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                  DLH   0x0
 * </pre>
 */
#define UART_DLH_ADDR   0xC0011804
#define UART_DLH_OFFSET 0x00000004
#define UART_DLH_INDEX  0x00000001
#define UART_DLH_RESET  0x00000000

__INLINE uint32_t uart_dlh_get(void)
{
    return REG_PL_RD(UART_DLH_ADDR);
}

__INLINE void uart_dlh_set(uint32_t value)
{
    REG_PL_WR(UART_DLH_ADDR, value);
}

// field definitions
#define UART_DLH_MASK   ((uint32_t)0x000000FF)
#define UART_DLH_LSB    0
#define UART_DLH_WIDTH  ((uint32_t)0x00000008)

#define UART_DLH_RST    0x0

__INLINE uint8_t uart_dlh_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_DLH_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_dlh_setf(uint8_t dlh)
{
    ASSERT_ERR((((uint32_t)dlh << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_DLH_ADDR, (uint32_t)dlh << 0);
}

/**
 * @brief IER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07                PTIME   0
 *     03                EDSSI   0
 *     02                 ELSI   0
 *     01                ETBEI   0
 *     00                ERBFI   0
 * </pre>
 */
#define UART_IER_ADDR   0xC0011804
#define UART_IER_OFFSET 0x00000004
#define UART_IER_INDEX  0x00000001
#define UART_IER_RESET  0x00000000

__INLINE uint32_t uart_ier_get(void)
{
    return REG_PL_RD(UART_IER_ADDR);
}

__INLINE void uart_ier_set(uint32_t value)
{
    REG_PL_WR(UART_IER_ADDR, value);
}

// field definitions
#define UART_PTIME_BIT    ((uint32_t)0x00000080)
#define UART_PTIME_POS    7
#define UART_EDSSI_BIT    ((uint32_t)0x00000008)
#define UART_EDSSI_POS    3
#define UART_ELSI_BIT     ((uint32_t)0x00000004)
#define UART_ELSI_POS     2
#define UART_ETBEI_BIT    ((uint32_t)0x00000002)
#define UART_ETBEI_POS    1
#define UART_ERBFI_BIT    ((uint32_t)0x00000001)
#define UART_ERBFI_POS    0

#define UART_PTIME_RST    0x0
#define UART_EDSSI_RST    0x0
#define UART_ELSI_RST     0x0
#define UART_ETBEI_RST    0x0
#define UART_ERBFI_RST    0x0

__INLINE void uart_ier_pack(uint8_t ptime, uint8_t edssi, uint8_t elsi, uint8_t etbei, uint8_t erbfi)
{
    ASSERT_ERR((((uint32_t)ptime << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)edssi << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)elsi << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)etbei << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)erbfi << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_IER_ADDR,  ((uint32_t)ptime << 7) | ((uint32_t)edssi << 3) | ((uint32_t)elsi << 2) | ((uint32_t)etbei << 1) | ((uint32_t)erbfi << 0));
}

__INLINE void uart_ier_unpack(uint8_t* ptime, uint8_t* edssi, uint8_t* elsi, uint8_t* etbei, uint8_t* erbfi)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    *ptime = (localVal & ((uint32_t)0x00000080)) >> 7;
    *edssi = (localVal & ((uint32_t)0x00000008)) >> 3;
    *elsi = (localVal & ((uint32_t)0x00000004)) >> 2;
    *etbei = (localVal & ((uint32_t)0x00000002)) >> 1;
    *erbfi = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t uart_ptime_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void uart_ptime_setf(uint8_t ptime)
{
    ASSERT_ERR((((uint32_t)ptime << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)ptime << 7));
}

__INLINE uint8_t uart_edssi_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void uart_edssi_setf(uint8_t edssi)
{
    ASSERT_ERR((((uint32_t)edssi << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)edssi << 3));
}

__INLINE uint8_t uart_elsi_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void uart_elsi_setf(uint8_t elsi)
{
    ASSERT_ERR((((uint32_t)elsi << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)elsi << 2));
}

__INLINE uint8_t uart_etbei_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void uart_etbei_setf(uint8_t etbei)
{
    ASSERT_ERR((((uint32_t)etbei << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)etbei << 1));
}

__INLINE uint8_t uart_erbfi_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IER_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void uart_erbfi_setf(uint8_t erbfi)
{
    ASSERT_ERR((((uint32_t)erbfi << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)erbfi << 0));
}

/**
 * @brief IIR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:06               FIFOSE   0x0
 *  03:00                  IID   0x0
 * </pre>
 */
#define UART_IIR_ADDR   0xC0011808
#define UART_IIR_OFFSET 0x00000008
#define UART_IIR_INDEX  0x00000002
#define UART_IIR_RESET  0x00000000

__INLINE uint32_t uart_iir_get(void)
{
    return REG_PL_RD(UART_IIR_ADDR);
}

// field definitions
#define UART_FIFOSE_MASK   ((uint32_t)0x000000C0)
#define UART_FIFOSE_LSB    6
#define UART_FIFOSE_WIDTH  ((uint32_t)0x00000002)
#define UART_IID_MASK      ((uint32_t)0x0000000F)
#define UART_IID_LSB       0
#define UART_IID_WIDTH     ((uint32_t)0x00000004)

#define UART_FIFOSE_RST    0x0
#define UART_IID_RST       0x0

__INLINE void uart_iir_unpack(uint8_t* fifose, uint8_t* iid)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IIR_ADDR);
    *fifose = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *iid = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

__INLINE uint8_t uart_fifose_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IIR_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE uint8_t uart_iid_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_IIR_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief FCR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:06               RCVR_T   0x0
 *  05:04             TX_EMP_T   0x0
 *     03                 DMAM   0
 *     02            XFIFO_RES   0
 *     01            RFIFO_RES   0
 *     00              FIFO_EN   0
 * </pre>
 */
#define UART_FCR_ADDR   0xC0011808
#define UART_FCR_OFFSET 0x00000008
#define UART_FCR_INDEX  0x00000002
#define UART_FCR_RESET  0x00000000

__INLINE void uart_fcr_set(uint32_t value)
{
    REG_PL_WR(UART_FCR_ADDR, value);
}

// field definitions
#define UART_RCVR_T_MASK      ((uint32_t)0x000000C0)
#define UART_RCVR_T_LSB       6
#define UART_RCVR_T_WIDTH     ((uint32_t)0x00000002)
#define UART_TX_EMP_T_MASK    ((uint32_t)0x00000030)
#define UART_TX_EMP_T_LSB     4
#define UART_TX_EMP_T_WIDTH   ((uint32_t)0x00000002)
#define UART_DMAM_BIT         ((uint32_t)0x00000008)
#define UART_DMAM_POS         3
#define UART_XFIFO_RES_BIT    ((uint32_t)0x00000004)
#define UART_XFIFO_RES_POS    2
#define UART_RFIFO_RES_BIT    ((uint32_t)0x00000002)
#define UART_RFIFO_RES_POS    1
#define UART_FIFO_EN_BIT      ((uint32_t)0x00000001)
#define UART_FIFO_EN_POS      0

#define UART_RCVR_T_RST       0x0
#define UART_TX_EMP_T_RST     0x0
#define UART_DMAM_RST         0x0
#define UART_XFIFO_RES_RST    0x0
#define UART_RFIFO_RES_RST    0x0
#define UART_FIFO_EN_RST      0x0

__INLINE void uart_fcr_pack(uint8_t rcvrt, uint8_t txempt, uint8_t dmam, uint8_t xfifores, uint8_t rfifores, uint8_t fifoen)
{
    ASSERT_ERR((((uint32_t)rcvrt << 6) & ~((uint32_t)0x000000C0)) == 0);
    ASSERT_ERR((((uint32_t)txempt << 4) & ~((uint32_t)0x00000030)) == 0);
    ASSERT_ERR((((uint32_t)dmam << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)xfifores << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)rfifores << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)fifoen << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_FCR_ADDR,  ((uint32_t)rcvrt << 6) | ((uint32_t)txempt << 4) | ((uint32_t)dmam << 3) | ((uint32_t)xfifores << 2) | ((uint32_t)rfifores << 1) | ((uint32_t)fifoen << 0));
}

__INLINE void uart_rcvr_t_setf(uint8_t rcvrt)
{
    ASSERT_ERR((((uint32_t)rcvrt << 6) & ~((uint32_t)0x000000C0)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)rcvrt << 6));
}

__INLINE void uart_tx_emp_t_setf(uint8_t txempt)
{
    ASSERT_ERR((((uint32_t)txempt << 4) & ~((uint32_t)0x00000030)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)txempt << 4));
}

__INLINE void uart_dmam_setf(uint8_t dmam)
{
    ASSERT_ERR((((uint32_t)dmam << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)dmam << 3));
}

__INLINE void uart_xfifo_res_setf(uint8_t xfifores)
{
    ASSERT_ERR((((uint32_t)xfifores << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)xfifores << 2));
}

__INLINE void uart_rfifo_res_setf(uint8_t rfifores)
{
    ASSERT_ERR((((uint32_t)rfifores << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rfifores << 1));
}

__INLINE void uart_fifo_en_setf(uint8_t fifoen)
{
    ASSERT_ERR((((uint32_t)fifoen << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fifoen << 0));
}

/**
 * @brief LCR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07                 DLAB   0
 *     06                   BC   0
 *     04                  EPS   0
 *     03            PARITY_EN   0
 *     02                 STOP   0
 *  01:00                  DLS   0x0
 * </pre>
 */
#define UART_LCR_ADDR   0xC001180C
#define UART_LCR_OFFSET 0x0000000C
#define UART_LCR_INDEX  0x00000003
#define UART_LCR_RESET  0x00000000

__INLINE uint32_t uart_lcr_get(void)
{
    return REG_PL_RD(UART_LCR_ADDR);
}

__INLINE void uart_lcr_set(uint32_t value)
{
    REG_PL_WR(UART_LCR_ADDR, value);
}

// field definitions
#define UART_DLAB_BIT         ((uint32_t)0x00000080)
#define UART_DLAB_POS         7
#define UART_BC_BIT           ((uint32_t)0x00000040)
#define UART_BC_POS           6
#define UART_EPS_BIT          ((uint32_t)0x00000010)
#define UART_EPS_POS          4
#define UART_PARITY_EN_BIT    ((uint32_t)0x00000008)
#define UART_PARITY_EN_POS    3
#define UART_STOP_BIT         ((uint32_t)0x00000004)
#define UART_STOP_POS         2
#define UART_DLS_MASK         ((uint32_t)0x00000003)
#define UART_DLS_LSB          0
#define UART_DLS_WIDTH        ((uint32_t)0x00000002)

#define UART_DLAB_RST         0x0
#define UART_BC_RST           0x0
#define UART_EPS_RST          0x0
#define UART_PARITY_EN_RST    0x0
#define UART_STOP_RST         0x0
#define UART_DLS_RST          0x0

__INLINE void uart_lcr_pack(uint8_t dlab, uint8_t bc, uint8_t eps, uint8_t parityen, uint8_t stop, uint8_t dls)
{
    ASSERT_ERR((((uint32_t)dlab << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)bc << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)eps << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)parityen << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)stop << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)dls << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(UART_LCR_ADDR,  ((uint32_t)dlab << 7) | ((uint32_t)bc << 6) | ((uint32_t)eps << 4) | ((uint32_t)parityen << 3) | ((uint32_t)stop << 2) | ((uint32_t)dls << 0));
}

__INLINE void uart_lcr_unpack(uint8_t* dlab, uint8_t* bc, uint8_t* eps, uint8_t* parityen, uint8_t* stop, uint8_t* dls)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    *dlab = (localVal & ((uint32_t)0x00000080)) >> 7;
    *bc = (localVal & ((uint32_t)0x00000040)) >> 6;
    *eps = (localVal & ((uint32_t)0x00000010)) >> 4;
    *parityen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *stop = (localVal & ((uint32_t)0x00000004)) >> 2;
    *dls = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t uart_dlab_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE void uart_dlab_setf(uint8_t dlab)
{
    ASSERT_ERR((((uint32_t)dlab << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)dlab << 7));
}

__INLINE uint8_t uart_bc_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void uart_bc_setf(uint8_t bc)
{
    ASSERT_ERR((((uint32_t)bc << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)bc << 6));
}

__INLINE uint8_t uart_eps_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void uart_eps_setf(uint8_t eps)
{
    ASSERT_ERR((((uint32_t)eps << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)eps << 4));
}

__INLINE uint8_t uart_parity_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void uart_parity_en_setf(uint8_t parityen)
{
    ASSERT_ERR((((uint32_t)parityen << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)parityen << 3));
}

__INLINE uint8_t uart_stop_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void uart_stop_setf(uint8_t stop)
{
    ASSERT_ERR((((uint32_t)stop << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)stop << 2));
}

__INLINE uint8_t uart_dls_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LCR_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void uart_dls_setf(uint8_t dls)
{
    ASSERT_ERR((((uint32_t)dls << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)dls << 0));
}

/**
 * @brief MCR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     06                 SIRE   0
 *     05                 AFCE   0
 *     04                   LB   0
 *     03                 OUT2   0
 *     02                 OUT1   0
 *     01                  RTS   0
 *     00                  DTR   0
 * </pre>
 */
#define UART_MCR_ADDR   0xC0011810
#define UART_MCR_OFFSET 0x00000010
#define UART_MCR_INDEX  0x00000004
#define UART_MCR_RESET  0x00000000

__INLINE uint32_t uart_mcr_get(void)
{
    return REG_PL_RD(UART_MCR_ADDR);
}

__INLINE void uart_mcr_set(uint32_t value)
{
    REG_PL_WR(UART_MCR_ADDR, value);
}

// field definitions
#define UART_SIRE_BIT    ((uint32_t)0x00000040)
#define UART_SIRE_POS    6
#define UART_AFCE_BIT    ((uint32_t)0x00000020)
#define UART_AFCE_POS    5
#define UART_LB_BIT      ((uint32_t)0x00000010)
#define UART_LB_POS      4
#define UART_OUT2_BIT    ((uint32_t)0x00000008)
#define UART_OUT2_POS    3
#define UART_OUT1_BIT    ((uint32_t)0x00000004)
#define UART_OUT1_POS    2
#define UART_RTS_BIT     ((uint32_t)0x00000002)
#define UART_RTS_POS     1
#define UART_DTR_BIT     ((uint32_t)0x00000001)
#define UART_DTR_POS     0

#define UART_SIRE_RST    0x0
#define UART_AFCE_RST    0x0
#define UART_LB_RST      0x0
#define UART_OUT2_RST    0x0
#define UART_OUT1_RST    0x0
#define UART_RTS_RST     0x0
#define UART_DTR_RST     0x0

__INLINE void uart_mcr_pack(uint8_t sire, uint8_t afce, uint8_t lb, uint8_t out2, uint8_t out1, uint8_t rts, uint8_t dtr)
{
    ASSERT_ERR((((uint32_t)sire << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)afce << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)lb << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)out2 << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)out1 << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)rts << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)dtr << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_MCR_ADDR,  ((uint32_t)sire << 6) | ((uint32_t)afce << 5) | ((uint32_t)lb << 4) | ((uint32_t)out2 << 3) | ((uint32_t)out1 << 2) | ((uint32_t)rts << 1) | ((uint32_t)dtr << 0));
}

__INLINE void uart_mcr_unpack(uint8_t* sire, uint8_t* afce, uint8_t* lb, uint8_t* out2, uint8_t* out1, uint8_t* rts, uint8_t* dtr)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    *sire = (localVal & ((uint32_t)0x00000040)) >> 6;
    *afce = (localVal & ((uint32_t)0x00000020)) >> 5;
    *lb = (localVal & ((uint32_t)0x00000010)) >> 4;
    *out2 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *out1 = (localVal & ((uint32_t)0x00000004)) >> 2;
    *rts = (localVal & ((uint32_t)0x00000002)) >> 1;
    *dtr = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t uart_sire_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE void uart_sire_setf(uint8_t sire)
{
    ASSERT_ERR((((uint32_t)sire << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)sire << 6));
}

__INLINE uint8_t uart_afce_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE void uart_afce_setf(uint8_t afce)
{
    ASSERT_ERR((((uint32_t)afce << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)afce << 5));
}

__INLINE uint8_t uart_lb_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE void uart_lb_setf(uint8_t lb)
{
    ASSERT_ERR((((uint32_t)lb << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lb << 4));
}

__INLINE uint8_t uart_out2_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void uart_out2_setf(uint8_t out2)
{
    ASSERT_ERR((((uint32_t)out2 << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)out2 << 3));
}

__INLINE uint8_t uart_out1_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void uart_out1_setf(uint8_t out1)
{
    ASSERT_ERR((((uint32_t)out1 << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)out1 << 2));
}

__INLINE uint8_t uart_rts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void uart_rts_setf(uint8_t rts)
{
    ASSERT_ERR((((uint32_t)rts << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rts << 1));
}

__INLINE uint8_t uart_dtr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MCR_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void uart_dtr_setf(uint8_t dtr)
{
    ASSERT_ERR((((uint32_t)dtr << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dtr << 0));
}

/**
 * @brief LSR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07                  RFE   0
 *     06                 TEMT   0
 *     05                 THRE   0
 *     04                   BI   0
 *     03            FRAME_ERR   0
 *     02           PARITY_ERR   0
 *     01          OVERRUN_ERR   0
 *     00             DATA_RDY   0
 * </pre>
 */
#define UART_LSR_ADDR   0xC0011814
#define UART_LSR_OFFSET 0x00000014
#define UART_LSR_INDEX  0x00000005
#define UART_LSR_RESET  0x00000000

__INLINE uint32_t uart_lsr_get(void)
{
    return REG_PL_RD(UART_LSR_ADDR);
}

// field definitions
#define UART_RFE_BIT            ((uint32_t)0x00000080)
#define UART_RFE_POS            7
#define UART_TEMT_BIT           ((uint32_t)0x00000040)
#define UART_TEMT_POS           6
#define UART_THRE_BIT           ((uint32_t)0x00000020)
#define UART_THRE_POS           5
#define UART_BI_BIT             ((uint32_t)0x00000010)
#define UART_BI_POS             4
#define UART_FRAME_ERR_BIT      ((uint32_t)0x00000008)
#define UART_FRAME_ERR_POS      3
#define UART_PARITY_ERR_BIT     ((uint32_t)0x00000004)
#define UART_PARITY_ERR_POS     2
#define UART_OVERRUN_ERR_BIT    ((uint32_t)0x00000002)
#define UART_OVERRUN_ERR_POS    1
#define UART_DATA_RDY_BIT       ((uint32_t)0x00000001)
#define UART_DATA_RDY_POS       0

#define UART_RFE_RST            0x0
#define UART_TEMT_RST           0x0
#define UART_THRE_RST           0x0
#define UART_BI_RST             0x0
#define UART_FRAME_ERR_RST      0x0
#define UART_PARITY_ERR_RST     0x0
#define UART_OVERRUN_ERR_RST    0x0
#define UART_DATA_RDY_RST       0x0

__INLINE void uart_lsr_unpack(uint8_t* rfe, uint8_t* temt, uint8_t* thre, uint8_t* bi, uint8_t* frameerr, uint8_t* parityerr, uint8_t* overrunerr, uint8_t* datardy)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    *rfe = (localVal & ((uint32_t)0x00000080)) >> 7;
    *temt = (localVal & ((uint32_t)0x00000040)) >> 6;
    *thre = (localVal & ((uint32_t)0x00000020)) >> 5;
    *bi = (localVal & ((uint32_t)0x00000010)) >> 4;
    *frameerr = (localVal & ((uint32_t)0x00000008)) >> 3;
    *parityerr = (localVal & ((uint32_t)0x00000004)) >> 2;
    *overrunerr = (localVal & ((uint32_t)0x00000002)) >> 1;
    *datardy = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t uart_rfe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t uart_temt_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t uart_thre_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t uart_bi_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t uart_frame_err_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t uart_parity_err_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t uart_overrun_err_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t uart_data_rdy_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LSR_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief MSR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     07                  DCD   0
 *     06                   RI   0
 *     05                  DSR   0
 *     04                  CTS   0
 *     03                 DDCD   0
 *     02                 TERI   0
 *     01                 DDSR   0
 *     00            DELTA_CTS   0
 * </pre>
 */
#define UART_MSR_ADDR   0xC0011818
#define UART_MSR_OFFSET 0x00000018
#define UART_MSR_INDEX  0x00000006
#define UART_MSR_RESET  0x00000000

__INLINE uint32_t uart_msr_get(void)
{
    return REG_PL_RD(UART_MSR_ADDR);
}

// field definitions
#define UART_DCD_BIT          ((uint32_t)0x00000080)
#define UART_DCD_POS          7
#define UART_RI_BIT           ((uint32_t)0x00000040)
#define UART_RI_POS           6
#define UART_DSR_BIT          ((uint32_t)0x00000020)
#define UART_DSR_POS          5
#define UART_CTS_BIT          ((uint32_t)0x00000010)
#define UART_CTS_POS          4
#define UART_DDCD_BIT         ((uint32_t)0x00000008)
#define UART_DDCD_POS         3
#define UART_TERI_BIT         ((uint32_t)0x00000004)
#define UART_TERI_POS         2
#define UART_DDSR_BIT         ((uint32_t)0x00000002)
#define UART_DDSR_POS         1
#define UART_DELTA_CTS_BIT    ((uint32_t)0x00000001)
#define UART_DELTA_CTS_POS    0

#define UART_DCD_RST          0x0
#define UART_RI_RST           0x0
#define UART_DSR_RST          0x0
#define UART_CTS_RST          0x0
#define UART_DDCD_RST         0x0
#define UART_TERI_RST         0x0
#define UART_DDSR_RST         0x0
#define UART_DELTA_CTS_RST    0x0

__INLINE void uart_msr_unpack(uint8_t* dcd, uint8_t* ri, uint8_t* dsr, uint8_t* cts, uint8_t* ddcd, uint8_t* teri, uint8_t* ddsr, uint8_t* deltacts)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    *dcd = (localVal & ((uint32_t)0x00000080)) >> 7;
    *ri = (localVal & ((uint32_t)0x00000040)) >> 6;
    *dsr = (localVal & ((uint32_t)0x00000020)) >> 5;
    *cts = (localVal & ((uint32_t)0x00000010)) >> 4;
    *ddcd = (localVal & ((uint32_t)0x00000008)) >> 3;
    *teri = (localVal & ((uint32_t)0x00000004)) >> 2;
    *ddsr = (localVal & ((uint32_t)0x00000002)) >> 1;
    *deltacts = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t uart_dcd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t uart_ri_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t uart_dsr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t uart_cts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t uart_ddcd_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t uart_teri_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t uart_ddsr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t uart_delta_cts_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_MSR_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief SCR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                  SCR   0x0
 * </pre>
 */
#define UART_SCR_ADDR   0xC001181C
#define UART_SCR_OFFSET 0x0000001C
#define UART_SCR_INDEX  0x00000007
#define UART_SCR_RESET  0x00000000

__INLINE uint32_t uart_scr_get(void)
{
    return REG_PL_RD(UART_SCR_ADDR);
}

__INLINE void uart_scr_set(uint32_t value)
{
    REG_PL_WR(UART_SCR_ADDR, value);
}

// field definitions
#define UART_SCR_MASK   ((uint32_t)0x000000FF)
#define UART_SCR_LSB    0
#define UART_SCR_WIDTH  ((uint32_t)0x00000008)

#define UART_SCR_RST    0x0

__INLINE uint8_t uart_scr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SCR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_scr_setf(uint8_t scr)
{
    ASSERT_ERR((((uint32_t)scr << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_SCR_ADDR, (uint32_t)scr << 0);
}

/**
 * @brief LPDLL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                LPDLL   0x0
 * </pre>
 */
#define UART_LPDLL_ADDR   0xC001181C
#define UART_LPDLL_OFFSET 0x0000001C
#define UART_LPDLL_INDEX  0x00000007
#define UART_LPDLL_RESET  0x00000000

__INLINE uint32_t uart_lpdll_get(void)
{
    return REG_PL_RD(UART_LPDLL_ADDR);
}

__INLINE void uart_lpdll_set(uint32_t value)
{
    REG_PL_WR(UART_LPDLL_ADDR, value);
}

// field definitions
#define UART_LPDLL_MASK   ((uint32_t)0x000000FF)
#define UART_LPDLL_LSB    0
#define UART_LPDLL_WIDTH  ((uint32_t)0x00000008)

#define UART_LPDLL_RST    0x0

__INLINE uint8_t uart_lpdll_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LPDLL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_lpdll_setf(uint8_t lpdll)
{
    ASSERT_ERR((((uint32_t)lpdll << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_LPDLL_ADDR, (uint32_t)lpdll << 0);
}

/**
 * @brief LPDLH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                LPDLH   0x0
 * </pre>
 */
#define UART_LPDLH_ADDR   0xC001181C
#define UART_LPDLH_OFFSET 0x0000001C
#define UART_LPDLH_INDEX  0x00000007
#define UART_LPDLH_RESET  0x00000000

__INLINE uint32_t uart_lpdlh_get(void)
{
    return REG_PL_RD(UART_LPDLH_ADDR);
}

__INLINE void uart_lpdlh_set(uint32_t value)
{
    REG_PL_WR(UART_LPDLH_ADDR, value);
}

// field definitions
#define UART_LPDLH_MASK   ((uint32_t)0x000000FF)
#define UART_LPDLH_LSB    0
#define UART_LPDLH_WIDTH  ((uint32_t)0x00000008)

#define UART_LPDLH_RST    0x0

__INLINE uint8_t uart_lpdlh_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_LPDLH_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_lpdlh_setf(uint8_t lpdlh)
{
    ASSERT_ERR((((uint32_t)lpdlh << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_LPDLH_ADDR, (uint32_t)lpdlh << 0);
}

/**
 * @brief SRBR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                 SRBR   0x0
 * </pre>
 */
#define UART_SRBR_ADDR   0xC0011830
#define UART_SRBR_OFFSET 0x00000030
#define UART_SRBR_INDEX  0x0000000C
#define UART_SRBR_RESET  0x00000000
#define UART_SRBR_COUNT  16

__INLINE uint32_t uart_srbr_get(int reg_idx)
{
    return REG_PL_RD(UART_SRBR_ADDR + reg_idx * 4);
}

// field definitions
#define UART_SRBR_MASK   ((uint32_t)0x000000FF)
#define UART_SRBR_LSB    0
#define UART_SRBR_WIDTH  ((uint32_t)0x00000008)

#define UART_SRBR_RST    0x0

__INLINE uint8_t uart_srbr_getf(int reg_idx)
{
    uint32_t localVal;

    ASSERT_ERR(reg_idx <= 15);

    localVal = REG_PL_RD(UART_SRBR_ADDR + reg_idx * 4);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief STHR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                 STHR   0x0
 * </pre>
 */
#define UART_STHR_ADDR   0xC0011830
#define UART_STHR_OFFSET 0x00000030
#define UART_STHR_INDEX  0x0000000C
#define UART_STHR_RESET  0x00000000
#define UART_STHR_COUNT  16

__INLINE void uart_sthr_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(UART_STHR_ADDR + reg_idx * 4, value);
}

// field definitions
#define UART_STHR_MASK   ((uint32_t)0x000000FF)
#define UART_STHR_LSB    0
#define UART_STHR_WIDTH  ((uint32_t)0x00000008)

#define UART_STHR_RST    0x0

__INLINE void uart_sthr_setf(int reg_idx, uint8_t sthr)
{
    ASSERT_ERR((((uint32_t)sthr << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_STHR_ADDR + reg_idx * 4, (uint32_t)sthr << 0);
}

/**
 * @brief FAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00          FIFO_Access   0
 * </pre>
 */
#define UART_FAR_ADDR   0xC0011870
#define UART_FAR_OFFSET 0x00000070
#define UART_FAR_INDEX  0x0000001C
#define UART_FAR_RESET  0x00000000

__INLINE uint32_t uart_far_get(void)
{
    return REG_PL_RD(UART_FAR_ADDR);
}

__INLINE void uart_far_set(uint32_t value)
{
    REG_PL_WR(UART_FAR_ADDR, value);
}

// field definitions
#define UART_FIFO__ACCESS_BIT    ((uint32_t)0x00000001)
#define UART_FIFO__ACCESS_POS    0

#define UART_FIFO__ACCESS_RST    0x0

__INLINE uint8_t uart_fifo__access_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_FAR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_fifo__access_setf(uint8_t fifoaccess)
{
    ASSERT_ERR((((uint32_t)fifoaccess << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_FAR_ADDR, (uint32_t)fifoaccess << 0);
}

/**
 * @brief TFR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00                  TFR   0x0
 * </pre>
 */
#define UART_TFR_ADDR   0xC0011874
#define UART_TFR_OFFSET 0x00000074
#define UART_TFR_INDEX  0x0000001D
#define UART_TFR_RESET  0x00000000

__INLINE uint32_t uart_tfr_get(void)
{
    return REG_PL_RD(UART_TFR_ADDR);
}

// field definitions
#define UART_TFR_MASK   ((uint32_t)0x000000FF)
#define UART_TFR_LSB    0
#define UART_TFR_WIDTH  ((uint32_t)0x00000008)

#define UART_TFR_RST    0x0

__INLINE uint8_t uart_tfr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_TFR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief RFW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     09                 RFFE   0
 *     08                 RFPE   0
 *  07:00                 RFWD   0x0
 * </pre>
 */
#define UART_RFW_ADDR   0xC0011878
#define UART_RFW_OFFSET 0x00000078
#define UART_RFW_INDEX  0x0000001E
#define UART_RFW_RESET  0x00000000

__INLINE void uart_rfw_set(uint32_t value)
{
    REG_PL_WR(UART_RFW_ADDR, value);
}

// field definitions
#define UART_RFFE_BIT    ((uint32_t)0x00000200)
#define UART_RFFE_POS    9
#define UART_RFPE_BIT    ((uint32_t)0x00000100)
#define UART_RFPE_POS    8
#define UART_RFWD_MASK   ((uint32_t)0x000000FF)
#define UART_RFWD_LSB    0
#define UART_RFWD_WIDTH  ((uint32_t)0x00000008)

#define UART_RFFE_RST    0x0
#define UART_RFPE_RST    0x0
#define UART_RFWD_RST    0x0

__INLINE void uart_rfw_pack(uint8_t rffe, uint8_t rfpe, uint8_t rfwd)
{
    ASSERT_ERR((((uint32_t)rffe << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)rfpe << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)rfwd << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_RFW_ADDR,  ((uint32_t)rffe << 9) | ((uint32_t)rfpe << 8) | ((uint32_t)rfwd << 0));
}

__INLINE void uart_rffe_setf(uint8_t rffe)
{
    ASSERT_ERR((((uint32_t)rffe << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(UART_RFW_ADDR, (REG_PL_RD(UART_RFW_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)rffe << 9));
}

__INLINE void uart_rfpe_setf(uint8_t rfpe)
{
    ASSERT_ERR((((uint32_t)rfpe << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(UART_RFW_ADDR, (REG_PL_RD(UART_RFW_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rfpe << 8));
}

__INLINE void uart_rfwd_setf(uint8_t rfwd)
{
    ASSERT_ERR((((uint32_t)rfwd << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(UART_RFW_ADDR, (REG_PL_RD(UART_RFW_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rfwd << 0));
}

/**
 * @brief USR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     04                  RFF   0
 *     03                 RFNE   0
 *     02                  TFE   0
 *     01                 TFNF   0
 *     00                 BUSY   0
 * </pre>
 */
#define UART_USR_ADDR   0xC001187C
#define UART_USR_OFFSET 0x0000007C
#define UART_USR_INDEX  0x0000001F
#define UART_USR_RESET  0x00000000

__INLINE uint32_t uart_usr_get(void)
{
    return REG_PL_RD(UART_USR_ADDR);
}

// field definitions
#define UART_RFF_BIT     ((uint32_t)0x00000010)
#define UART_RFF_POS     4
#define UART_RFNE_BIT    ((uint32_t)0x00000008)
#define UART_RFNE_POS    3
#define UART_TFE_BIT     ((uint32_t)0x00000004)
#define UART_TFE_POS     2
#define UART_TFNF_BIT    ((uint32_t)0x00000002)
#define UART_TFNF_POS    1
#define UART_BUSY_BIT    ((uint32_t)0x00000001)
#define UART_BUSY_POS    0

#define UART_RFF_RST     0x0
#define UART_RFNE_RST    0x0
#define UART_TFE_RST     0x0
#define UART_TFNF_RST    0x0
#define UART_BUSY_RST    0x0

__INLINE void uart_usr_unpack(uint8_t* rff, uint8_t* rfne, uint8_t* tfe, uint8_t* tfnf, uint8_t* busy)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    *rff = (localVal & ((uint32_t)0x00000010)) >> 4;
    *rfne = (localVal & ((uint32_t)0x00000008)) >> 3;
    *tfe = (localVal & ((uint32_t)0x00000004)) >> 2;
    *tfnf = (localVal & ((uint32_t)0x00000002)) >> 1;
    *busy = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t uart_rff_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t uart_rfne_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE uint8_t uart_tfe_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE uint8_t uart_tfnf_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t uart_busy_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_USR_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TFL register definition
 */
#define UART_TFL_ADDR   0xC0011880
#define UART_TFL_OFFSET 0x00000080
#define UART_TFL_INDEX  0x00000020
#define UART_TFL_RESET  0x00000000

__INLINE uint32_t uart_tfl_get(void)
{
    return REG_PL_RD(UART_TFL_ADDR);
}

/**
 * @brief SRR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     02                  XFR   0
 *     01                  RFR   0
 *     00                   UR   0
 * </pre>
 */
#define UART_SRR_ADDR   0xC0011888
#define UART_SRR_OFFSET 0x00000088
#define UART_SRR_INDEX  0x00000022
#define UART_SRR_RESET  0x00000000

__INLINE void uart_srr_set(uint32_t value)
{
    REG_PL_WR(UART_SRR_ADDR, value);
}

// field definitions
#define UART_XFR_BIT    ((uint32_t)0x00000004)
#define UART_XFR_POS    2
#define UART_RFR_BIT    ((uint32_t)0x00000002)
#define UART_RFR_POS    1
#define UART_UR_BIT     ((uint32_t)0x00000001)
#define UART_UR_POS     0

#define UART_XFR_RST    0x0
#define UART_RFR_RST    0x0
#define UART_UR_RST     0x0

__INLINE void uart_srr_pack(uint8_t xfr, uint8_t rfr, uint8_t ur)
{
    ASSERT_ERR((((uint32_t)xfr << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)rfr << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)ur << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SRR_ADDR,  ((uint32_t)xfr << 2) | ((uint32_t)rfr << 1) | ((uint32_t)ur << 0));
}

__INLINE void uart_xfr_setf(uint8_t xfr)
{
    ASSERT_ERR((((uint32_t)xfr << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(UART_SRR_ADDR, (REG_PL_RD(UART_SRR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)xfr << 2));
}

__INLINE void uart_rfr_setf(uint8_t rfr)
{
    ASSERT_ERR((((uint32_t)rfr << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(UART_SRR_ADDR, (REG_PL_RD(UART_SRR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rfr << 1));
}

__INLINE void uart_ur_setf(uint8_t ur)
{
    ASSERT_ERR((((uint32_t)ur << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SRR_ADDR, (REG_PL_RD(UART_SRR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ur << 0));
}

/**
 * @brief SRTS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00                SRTS0   0
 * </pre>
 */
#define UART_SRTS_ADDR   0xC001188C
#define UART_SRTS_OFFSET 0x0000008C
#define UART_SRTS_INDEX  0x00000023
#define UART_SRTS_RESET  0x00000000

__INLINE uint32_t uart_srts_get(void)
{
    return REG_PL_RD(UART_SRTS_ADDR);
}

__INLINE void uart_srts_set(uint32_t value)
{
    REG_PL_WR(UART_SRTS_ADDR, value);
}

// field definitions
#define UART_SRTS0_BIT    ((uint32_t)0x00000001)
#define UART_SRTS0_POS    0

#define UART_SRTS0_RST    0x0

__INLINE uint8_t uart_srts0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SRTS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_srts0_setf(uint8_t srts0)
{
    ASSERT_ERR((((uint32_t)srts0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SRTS_ADDR, (uint32_t)srts0 << 0);
}

/**
 * @brief SBCR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00                SBCR0   0
 * </pre>
 */
#define UART_SBCR_ADDR   0xC0011890
#define UART_SBCR_OFFSET 0x00000090
#define UART_SBCR_INDEX  0x00000024
#define UART_SBCR_RESET  0x00000000

__INLINE uint32_t uart_sbcr_get(void)
{
    return REG_PL_RD(UART_SBCR_ADDR);
}

__INLINE void uart_sbcr_set(uint32_t value)
{
    REG_PL_WR(UART_SBCR_ADDR, value);
}

// field definitions
#define UART_SBCR0_BIT    ((uint32_t)0x00000001)
#define UART_SBCR0_POS    0

#define UART_SBCR0_RST    0x0

__INLINE uint8_t uart_sbcr0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SBCR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_sbcr0_setf(uint8_t sbcr0)
{
    ASSERT_ERR((((uint32_t)sbcr0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SBCR_ADDR, (uint32_t)sbcr0 << 0);
}

/**
 * @brief SDMAM register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00               SDMAM0   0
 * </pre>
 */
#define UART_SDMAM_ADDR   0xC0011894
#define UART_SDMAM_OFFSET 0x00000094
#define UART_SDMAM_INDEX  0x00000025
#define UART_SDMAM_RESET  0x00000000

__INLINE uint32_t uart_sdmam_get(void)
{
    return REG_PL_RD(UART_SDMAM_ADDR);
}

__INLINE void uart_sdmam_set(uint32_t value)
{
    REG_PL_WR(UART_SDMAM_ADDR, value);
}

// field definitions
#define UART_SDMAM0_BIT    ((uint32_t)0x00000001)
#define UART_SDMAM0_POS    0

#define UART_SDMAM0_RST    0x0

__INLINE uint8_t uart_sdmam0_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SDMAM_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_sdmam0_setf(uint8_t sdmam0)
{
    ASSERT_ERR((((uint32_t)sdmam0 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SDMAM_ADDR, (uint32_t)sdmam0 << 0);
}

/**
 * @brief SFE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00             SFIFO_En   0
 * </pre>
 */
#define UART_SFE_ADDR   0xC0011898
#define UART_SFE_OFFSET 0x00000098
#define UART_SFE_INDEX  0x00000026
#define UART_SFE_RESET  0x00000000

__INLINE uint32_t uart_sfe_get(void)
{
    return REG_PL_RD(UART_SFE_ADDR);
}

__INLINE void uart_sfe_set(uint32_t value)
{
    REG_PL_WR(UART_SFE_ADDR, value);
}

// field definitions
#define UART_SFIFO__EN_BIT    ((uint32_t)0x00000001)
#define UART_SFIFO__EN_POS    0

#define UART_SFIFO__EN_RST    0x0

__INLINE uint8_t uart_sfifo__en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SFE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_sfifo__en_setf(uint8_t sfifoen)
{
    ASSERT_ERR((((uint32_t)sfifoen << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_SFE_ADDR, (uint32_t)sfifoen << 0);
}

/**
 * @brief SRT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00            S_RCVR_Tr   0x0
 * </pre>
 */
#define UART_SRT_ADDR   0xC001189C
#define UART_SRT_OFFSET 0x0000009C
#define UART_SRT_INDEX  0x00000027
#define UART_SRT_RESET  0x00000000

__INLINE uint32_t uart_srt_get(void)
{
    return REG_PL_RD(UART_SRT_ADDR);
}

__INLINE void uart_srt_set(uint32_t value)
{
    REG_PL_WR(UART_SRT_ADDR, value);
}

// field definitions
#define UART_S_RCVR__TR_MASK   ((uint32_t)0x00000003)
#define UART_S_RCVR__TR_LSB    0
#define UART_S_RCVR__TR_WIDTH  ((uint32_t)0x00000002)

#define UART_S_RCVR__TR_RST    0x0

__INLINE uint8_t uart_s_rcvr__tr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_SRT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_s_rcvr__tr_setf(uint8_t srcvrtr)
{
    ASSERT_ERR((((uint32_t)srcvrtr << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(UART_SRT_ADDR, (uint32_t)srcvrtr << 0);
}

/**
 * @brief STET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00          S_TX_Emp_Tr   0x0
 * </pre>
 */
#define UART_STET_ADDR   0xC00118A0
#define UART_STET_OFFSET 0x000000A0
#define UART_STET_INDEX  0x00000028
#define UART_STET_RESET  0x00000000

__INLINE uint32_t uart_stet_get(void)
{
    return REG_PL_RD(UART_STET_ADDR);
}

__INLINE void uart_stet_set(uint32_t value)
{
    REG_PL_WR(UART_STET_ADDR, value);
}

// field definitions
#define UART_S_TX__EMP__TR_MASK   ((uint32_t)0x00000003)
#define UART_S_TX__EMP__TR_LSB    0
#define UART_S_TX__EMP__TR_WIDTH  ((uint32_t)0x00000002)

#define UART_S_TX__EMP__TR_RST    0x0

__INLINE uint8_t uart_s_tx__emp__tr_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_STET_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_s_tx__emp__tr_setf(uint8_t stxemptr)
{
    ASSERT_ERR((((uint32_t)stxemptr << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(UART_STET_ADDR, (uint32_t)stxemptr << 0);
}

/**
 * @brief HTX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00               HTX_EN   0
 * </pre>
 */
#define UART_HTX_ADDR   0xC00118A4
#define UART_HTX_OFFSET 0x000000A4
#define UART_HTX_INDEX  0x00000029
#define UART_HTX_RESET  0x00000000

__INLINE uint32_t uart_htx_get(void)
{
    return REG_PL_RD(UART_HTX_ADDR);
}

__INLINE void uart_htx_set(uint32_t value)
{
    REG_PL_WR(UART_HTX_ADDR, value);
}

// field definitions
#define UART_HTX_EN_BIT    ((uint32_t)0x00000001)
#define UART_HTX_EN_POS    0

#define UART_HTX_EN_RST    0x0

__INLINE uint8_t uart_htx_en_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_HTX_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_htx_en_setf(uint8_t htxen)
{
    ASSERT_ERR((((uint32_t)htxen << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_HTX_ADDR, (uint32_t)htxen << 0);
}

/**
 * @brief DMASA register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00              DMAS_Ac   0
 * </pre>
 */
#define UART_DMASA_ADDR   0xC00118A8
#define UART_DMASA_OFFSET 0x000000A8
#define UART_DMASA_INDEX  0x0000002A
#define UART_DMASA_RESET  0x00000000

__INLINE uint32_t uart_dmasa_get(void)
{
    return REG_PL_RD(UART_DMASA_ADDR);
}

__INLINE void uart_dmasa_set(uint32_t value)
{
    REG_PL_WR(UART_DMASA_ADDR, value);
}

// field definitions
#define UART_DMAS__AC_BIT    ((uint32_t)0x00000001)
#define UART_DMAS__AC_POS    0

#define UART_DMAS__AC_RST    0x0

__INLINE uint8_t uart_dmas__ac_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_DMASA_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void uart_dmas__ac_setf(uint8_t dmasac)
{
    ASSERT_ERR((((uint32_t)dmasac << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(UART_DMASA_ADDR, (uint32_t)dmasac << 0);
}

/**
 * @brief CPR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  23:16            FIFO_MODE   0x0
 *     13            DMA_EXTRA   0
 *     12   UART_ADD_ENCODED_PARAMS   0
 *     11               SHADOW   0
 *     10            FIFO_STAT   0
 *     09          FIFO_ACCESS   0
 *     08      ADDITIONAL_FEAT   0
 *     07          SIR_LP_MODE   0
 *     06             SIR_MODE   0
 *     05            THRE_MODE   0
 *     04            AFCE_MODE   0
 *  01:00       APB_DATA_WIDTH   0x0
 * </pre>
 */
#define UART_CPR_ADDR   0xC00118F4
#define UART_CPR_OFFSET 0x000000F4
#define UART_CPR_INDEX  0x0000003D
#define UART_CPR_RESET  0x00000000

__INLINE uint32_t uart_cpr_get(void)
{
    return REG_PL_RD(UART_CPR_ADDR);
}

// field definitions
#define UART_FIFO_MODE_MASK                 ((uint32_t)0x00FF0000)
#define UART_FIFO_MODE_LSB                  16
#define UART_FIFO_MODE_WIDTH                ((uint32_t)0x00000008)
#define UART_DMA_EXTRA_BIT                  ((uint32_t)0x00002000)
#define UART_DMA_EXTRA_POS                  13
#define UART_UART_ADD_ENCODED_PARAMS_BIT    ((uint32_t)0x00001000)
#define UART_UART_ADD_ENCODED_PARAMS_POS    12
#define UART_SHADOW_BIT                     ((uint32_t)0x00000800)
#define UART_SHADOW_POS                     11
#define UART_FIFO_STAT_BIT                  ((uint32_t)0x00000400)
#define UART_FIFO_STAT_POS                  10
#define UART_FIFO_ACCESS_BIT                ((uint32_t)0x00000200)
#define UART_FIFO_ACCESS_POS                9
#define UART_ADDITIONAL_FEAT_BIT            ((uint32_t)0x00000100)
#define UART_ADDITIONAL_FEAT_POS            8
#define UART_SIR_LP_MODE_BIT                ((uint32_t)0x00000080)
#define UART_SIR_LP_MODE_POS                7
#define UART_SIR_MODE_BIT                   ((uint32_t)0x00000040)
#define UART_SIR_MODE_POS                   6
#define UART_THRE_MODE_BIT                  ((uint32_t)0x00000020)
#define UART_THRE_MODE_POS                  5
#define UART_AFCE_MODE_BIT                  ((uint32_t)0x00000010)
#define UART_AFCE_MODE_POS                  4
#define UART_APB_DATA_WIDTH_MASK            ((uint32_t)0x00000003)
#define UART_APB_DATA_WIDTH_LSB             0
#define UART_APB_DATA_WIDTH_WIDTH           ((uint32_t)0x00000002)

#define UART_FIFO_MODE_RST                  0x0
#define UART_DMA_EXTRA_RST                  0x0
#define UART_UART_ADD_ENCODED_PARAMS_RST    0x0
#define UART_SHADOW_RST                     0x0
#define UART_FIFO_STAT_RST                  0x0
#define UART_FIFO_ACCESS_RST                0x0
#define UART_ADDITIONAL_FEAT_RST            0x0
#define UART_SIR_LP_MODE_RST                0x0
#define UART_SIR_MODE_RST                   0x0
#define UART_THRE_MODE_RST                  0x0
#define UART_AFCE_MODE_RST                  0x0
#define UART_APB_DATA_WIDTH_RST             0x0

__INLINE void uart_cpr_unpack(uint8_t* fifomode, uint8_t* dmaextra, uint8_t* uartaddencodedparams, uint8_t* shadow, uint8_t* fifostat, uint8_t* fifoaccess, uint8_t* additionalfeat, uint8_t* sirlpmode, uint8_t* sirmode, uint8_t* thremode, uint8_t* afcemode, uint8_t* apbdatawidth)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    *fifomode = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *dmaextra = (localVal & ((uint32_t)0x00002000)) >> 13;
    *uartaddencodedparams = (localVal & ((uint32_t)0x00001000)) >> 12;
    *shadow = (localVal & ((uint32_t)0x00000800)) >> 11;
    *fifostat = (localVal & ((uint32_t)0x00000400)) >> 10;
    *fifoaccess = (localVal & ((uint32_t)0x00000200)) >> 9;
    *additionalfeat = (localVal & ((uint32_t)0x00000100)) >> 8;
    *sirlpmode = (localVal & ((uint32_t)0x00000080)) >> 7;
    *sirmode = (localVal & ((uint32_t)0x00000040)) >> 6;
    *thremode = (localVal & ((uint32_t)0x00000020)) >> 5;
    *afcemode = (localVal & ((uint32_t)0x00000010)) >> 4;
    *apbdatawidth = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t uart_fifo_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

__INLINE uint8_t uart_dma_extra_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE uint8_t uart_uart_add_encoded_params_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE uint8_t uart_shadow_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

__INLINE uint8_t uart_fifo_stat_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

__INLINE uint8_t uart_fifo_access_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

__INLINE uint8_t uart_additional_feat_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE uint8_t uart_sir_lp_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

__INLINE uint8_t uart_sir_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

__INLINE uint8_t uart_thre_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

__INLINE uint8_t uart_afce_mode_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

__INLINE uint8_t uart_apb_data_width_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CPR_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief UCV register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    UART_Componet_Ver   0x0
 * </pre>
 */
#define UART_UCV_ADDR   0xC00118F8
#define UART_UCV_OFFSET 0x000000F8
#define UART_UCV_INDEX  0x0000003E
#define UART_UCV_RESET  0x00000000

__INLINE uint32_t uart_ucv_get(void)
{
    return REG_PL_RD(UART_UCV_ADDR);
}

// field definitions
#define UART_UART__COMPONET__VER_MASK   ((uint32_t)0xFFFFFFFF)
#define UART_UART__COMPONET__VER_LSB    0
#define UART_UART__COMPONET__VER_WIDTH  ((uint32_t)0x00000020)

#define UART_UART__COMPONET__VER_RST    0x0

__INLINE uint32_t uart_uart__componet__ver_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_UCV_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief CTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00              Peri_ID   0x0
 * </pre>
 */
#define UART_CTR_ADDR   0xC00118FC
#define UART_CTR_OFFSET 0x000000FC
#define UART_CTR_INDEX  0x0000003F
#define UART_CTR_RESET  0x00000000

__INLINE uint32_t uart_ctr_get(void)
{
    return REG_PL_RD(UART_CTR_ADDR);
}

// field definitions
#define UART_PERI_ID_MASK   ((uint32_t)0xFFFFFFFF)
#define UART_PERI_ID_LSB    0
#define UART_PERI_ID_WIDTH  ((uint32_t)0x00000020)

#define UART_PERI_ID_RST    0x0

__INLINE uint32_t uart_peri_id_getf(void)
{
    uint32_t localVal;

    localVal = REG_PL_RD(UART_CTR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_UART_H_

