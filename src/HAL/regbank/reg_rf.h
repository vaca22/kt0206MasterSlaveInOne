#ifndef REG_RF_H_
#define REG_RF_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "comm.h"
#include "config.h"

////regname
//typedef struct {
//	//Byte0
//	uint32_t byte0		 				: 1;
//	//Byte1
//	uint32_t byte1						: 1;
//	//Byte2
//	uint32_t byte2						: 1;
//	//Byte3
//	uint32_t byte3						: 1;
//}st_regname;
//typedef union {
//	st_regname						bs;
//	uint32_t							overall;
//}un_regname;


//RX_GFSK_STATUS0
typedef struct {
	//Byte0~3
	uint32_t GFSK_ACQ	 				: 1;
	uint32_t GFSK_EOF					: 1;
	uint32_t RX_BUF0_EOF				: 1;
	uint32_t RX_BUF1_EOF				: 1;
	uint32_t RFU0						: 28;
}st_RX_GFSK_STATUS0;
typedef union {
	st_RX_GFSK_STATUS0					bs;
	uint32_t							overall;
}un_RX_GFSK_STATUS0;


//RX_GFSK_STATUS1
typedef struct {
	//Byte0
	uint32_t DELTAF_COARSE 				: 8;
	//Byte1
	uint32_t DELTAF_FINE				: 8;
	//Byte2
	uint32_t FAST_RSSI					: 8;
	//Byte3
	uint32_t PN_CORR_PEAK				: 7;
	uint32_t RFU0						: 1;
}st_RX_GFSK_STATUS1;
typedef union {
	st_RX_GFSK_STATUS1					bs;
	uint32_t							overall;
}un_RX_GFSK_STATUS1;


//RX_GFSK_CONFIG0
typedef struct {
	//Byte0
	uint32_t GFSK_ACQ_MASK 				: 1;
	uint32_t GFSK_EOF_MASK				: 1;
	uint32_t BUF0_EOF_MASK				: 1;
	uint32_t BUF1_EOF_MASK				: 1;
	uint32_t RFU0						: 28;
}st_RX_GFSK_CONFIG0;
typedef union {
	st_RX_GFSK_CONFIG0					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG0;


//RX_GFSK_CONFIG1
typedef struct {
	//Byte0~2
	uint32_t MAINDATA_LEN 				: 12;
	uint32_t GFSK_DC					: 8;
	uint32_t COARSE_DC_BW				: 2;
	uint32_t PN_AUTODC_EN				: 1;
	uint32_t THRSH_EXTRACT_EN			: 1;
	//Byte3
	uint32_t FRSSI_BIAS					: 5;
	uint32_t RFU0						: 2;
	uint32_t AUTO_MAINDATA_LEN			: 1;
}st_RX_GFSK_CONFIG1;
typedef union {
	st_RX_GFSK_CONFIG1					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG1;


//RX_GFSK_CONFIG2
typedef struct {
	//Byte0~2
	uint32_t PN_LEN		 				: 6;
	uint32_t PN_PEAK_THRSH				: 6;
	uint32_t RFU0						: 4;
	uint32_t MINLEVEL					: 8;
	//Byte3
	uint32_t PN_ACQ_EN					: 1;
	uint32_t AUTO_ACQ_EN				: 1;
	uint32_t PHASEDIFF_EN				: 1;
	uint32_t SCRAMBLE_EN				: 1;
	uint32_t FINE_BITSYNC_EN			: 1;
	uint32_t RFU1						: 3;
}st_RX_GFSK_CONFIG2;
typedef union {
	st_RX_GFSK_CONFIG2					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG2;


//RX_GFSK_CONFIG3
typedef struct {
	//Byte0
	uint32_t GFSK_RATE	 					: 2;
	uint32_t AfterMixer_first_filter_bw		: 2;
	uint32_t AfterMixer_first_filter_gain	: 3;
	uint32_t AfterMixer_first_filter_en		: 1;
	//Byte1
	uint32_t AfterMixer_second_filter_gain	: 3;
	uint32_t AfterMixer_second_filter_en	: 1;
	uint32_t Channel_filter_gain			: 3;
	uint32_t Channel_filter_en				: 1;
	//Byte2~3
	uint32_t Channel_filter_nbw				: 1;
	uint32_t POSTFLT_BW						: 1;
	uint32_t BIT_INV						: 1;
	uint32_t PHASE_INV						: 1;
	uint32_t STROBE_DELAY					: 3;
	uint32_t TMERR_BW						: 2;
	uint32_t RFU0							: 7;
}st_RX_GFSK_CONFIG3;
typedef union {
	st_RX_GFSK_CONFIG3					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG3;


//RX_GFSK_CONFIG4
typedef struct {
	//Byte0~3
	uint32_t SCRAMBLE_INIT 				: 32;
}st_RX_GFSK_CONFIG4;
typedef union {
	st_RX_GFSK_CONFIG4					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG4;


//RX_GFSK_CONFIG5
typedef struct {
	//Byte0~3
	uint32_t PN_SEQ0	 				: 32;
}st_RX_GFSK_CONFIG5;
typedef union {
	st_RX_GFSK_CONFIG5					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG5;


//RX_GFSK_CONFIG6
typedef struct {
	//Byte0~3
	uint32_t PN_SEQ1	 				: 32;
}st_RX_GFSK_CONFIG6;
typedef union {
	st_RX_GFSK_CONFIG6					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG6;


//RX_GFSK_CONFIG7
typedef struct {
	//Byte0~1
	uint32_t RX_BUF0_STARTADDR			: 16;
	//Byte2~3
	uint32_t RX_BUF1_STARTADDR			: 16;
}st_RX_GFSK_CONFIG7;
typedef union {
	st_RX_GFSK_CONFIG7					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG7;


//RX_GFSK_CONFIG8
typedef struct {
	//Byte0~1
	uint32_t RX_RAM_FLT_DATA_LEN		: 16;
	//Byte2~3
	uint32_t RX_RAM_FLT_EN				: 1;
	uint32_t RX_RAM_DATA_FROM_FLT		: 1;
	uint32_t RX_RAM_BIG_ENDIAN_EN		: 1;
	uint32_t RFU0						: 1;
	uint32_t RX_RAM_DEMOD_EN			: 1;
	uint32_t RFU1						: 11;
}st_RX_GFSK_CONFIG8;
typedef union {
	st_RX_GFSK_CONFIG8					bs;
	uint32_t							overall;
}un_RX_GFSK_CONFIG8;


//TX_GFSK_STATUS0
typedef struct {
	//Byte0
	uint32_t ASYNC_FIFO_OVF				: 1;
	uint32_t RFU0						: 3;
	uint32_t TX_EOF						: 1;
	uint32_t RFU1						: 27;
}st_TX_GFSK_STATUS0;
typedef union {
	st_TX_GFSK_STATUS0					bs;
	uint32_t							overall;
}un_TX_GFSK_STATUS0;


//TX_GFSK_CONFIG0
typedef struct {
	//Byte0
	uint32_t TX_MAINDATA_LEN			: 12;
	uint32_t TX_PN_LEN					: 6;
	uint32_t RFU0						: 2;
	uint32_t TX_PRE01_LEN				: 4;
	//Byte3
	uint32_t RFU1						: 8;
}st_TX_GFSK_CONFIG0;
typedef union {
	st_TX_GFSK_CONFIG0					bs;
	uint32_t							overall;
}un_TX_GFSK_CONFIG0;


//TX_GFSK_CONFIG1
typedef struct {
	//Byte0
	uint32_t GFSK_FDEV		 			: 6;
	uint32_t RFU0						: 2;
	//Byte1
	uint32_t GFSK_RATE					: 2;
	uint32_t RFU1						: 1;
	uint32_t GFSK_BT					: 1;
	uint32_t GFSK_EN					: 1;
	uint32_t SCRAM_EN					: 1;
	uint32_t FRAME_EN					: 1;
	uint32_t RFU2						: 1;
	//Byte2~3
	uint32_t GAUSSFLT_EN				: 1;
	uint32_t CRECTFLT_EN				: 1;
	uint32_t INTERP_EN					: 1;
	uint32_t ASYNCFIFO_EN				: 1;
	uint32_t BIG_ENDIAN_EN				: 1;
	uint32_t RAWDATA_EN					: 1;
	uint32_t RFU3						: 10;
}st_TX_GFSK_CONFIG1;
typedef union {
	st_TX_GFSK_CONFIG1					bs;
	uint32_t							overall;
}un_TX_GFSK_CONFIG1;


//TX_GFSK_CREFLT_COEFF0
typedef struct {
	//Byte0
	uint32_t CORRECTION_FILTER_B0		: 8;
	//Byte1
	uint32_t CORRECTION_FILTER_B1		: 8;
	//Byte2
	uint32_t CORRECTION_FILTER_B2		: 8;
	//Byte3
	uint32_t CORRECTION_FILTER_B3		: 8;
}st_TX_GFSK_CREFLT_COEFF0;
typedef union {
	st_TX_GFSK_CREFLT_COEFF0			bs;
	uint32_t							overall;
}un_TX_GFSK_CREFLT_COEFF0;


//TX_GFSK_CREFLT_COEFF1
typedef struct {
	//Byte0
	uint32_t CORRECTION_FILTER_B4		: 8;
	//Byte1
	uint32_t CORRECTION_FILTER_B5		: 8;
	//Byte2
	uint32_t CORRECTION_FILTER_B6		: 8;
	//Byte3
	uint32_t CORRECTION_FILTER_B7		: 8;
}st_TX_GFSK_CREFLT_COEFF1;
typedef union {
	st_TX_GFSK_CREFLT_COEFF1			bs;
	uint32_t							overall;
}un_TX_GFSK_CREFLT_COEFF1;


//TX_GFSK_CREFLT_COEFF2
typedef struct {
	//Byte0
	uint32_t CORRECTION_FILTER_B8		: 8;
	//Byte1
	uint32_t CORRECTION_FILTER_B9		: 8;
	//Byte2
	uint32_t CORRECTION_FILTER_B10		: 8;
	//Byte3
	uint32_t CORRECTION_FILTER_B11		: 8;
}st_TX_GFSK_CREFLT_COEFF2;
typedef union {
	st_TX_GFSK_CREFLT_COEFF2			bs;
	uint32_t							overall;
}un_TX_GFSK_CREFLT_COEFF2;


//TX_GFSK_CREFLT_COEFF3
typedef struct {
	//Byte0
	uint32_t CORRECTION_FILTER_B12		: 8;
	//Byte1
	uint32_t CORRECTION_FILTER_B13		: 8;
	//Byte2
	uint32_t CORRECTION_FILTER_B14		: 8;
	//Byte3
	uint32_t CORRECTION_FILTER_B15		: 8;
}st_TX_GFSK_CREFLT_COEFF3;
typedef union {
	st_TX_GFSK_CREFLT_COEFF3			bs;
	uint32_t							overall;
}un_TX_GFSK_CREFLT_COEFF3;


//TX_GFSK_PN_SEQ0
typedef struct {
	//Byte0~3
	uint32_t TX_PN_SEQ0	 				: 32;
}st_TX_GFSK_PN_SEQ0;
typedef union {
	st_TX_GFSK_PN_SEQ0					bs;
	uint32_t							overall;
}un_TX_GFSK_PN_SEQ0;


//TX_GFSK_PN_SEQ1
typedef struct {
	//Byte0~3
	uint32_t TX_PN_SEQ1	 				: 32;
}st_TX_GFSK_PN_SEQ1;
typedef union {
	st_TX_GFSK_PN_SEQ1					bs;
	uint32_t							overall;
}un_TX_GFSK_PN_SEQ1;


//TX_GFSK_SCRAM_INIT
typedef struct {
	//Byte0~3
	uint32_t TX_SCRAMBLE_INIT			: 32;
}st_TX_GFSK_SCRAM_INIT;
typedef union {
	st_TX_GFSK_SCRAM_INIT				bs;
	uint32_t							overall;
}un_TX_GFSK_SCRAM_INIT;


//TX_GFSK_BUFFER_STARTADDR
typedef struct {
	//Byte0
	uint32_t TX_BUFFER0_STARTADDR		: 16;
	//Byte2
	uint32_t TX_BUFFER1_STARTADDR		: 16;
}st_TX_GFSK_BUFFER_STARTADDR;
typedef union {
	st_TX_GFSK_BUFFER_STARTADDR			bs;
	uint32_t							overall;
}un_TX_GFSK_BUFFER_STARTADDR;


//TX_GFSK_BUFFER_START
typedef struct {
	//Byte0~3
	uint32_t TX_BUFFER0_START			: 1;
	uint32_t TX_BUFFER1_START			: 1;
	uint32_t RFU0						: 30;
}st_TX_GFSK_BUFFER_START;
typedef union {
	st_TX_GFSK_BUFFER_START				bs;
	uint32_t							overall;
}un_TX_GFSK_BUFFER_START;


//TX_DQPSK_TOP_CTRL
typedef struct {
	//Byte0
	uint32_t tx_enable 					: 1;
	uint32_t RFU0						: 3;
	uint32_t tx_mem_width				: 2;
	uint32_t tx_mem_sw_mode				: 1;
	uint32_t RFU1						: 1;
	//Byte1
	uint32_t tx_mseq_init				: 5;
	uint32_t RFU2						: 3;
	//Byte2~3
	uint32_t tx_config_loaded			: 1;
	uint32_t tx_end						: 1;
	uint32_t RFU3						: 14;
}st_TX_DQPSK_TOP_CTRL;
typedef union {
	st_TX_DQPSK_TOP_CTRL				bs;
	uint32_t							overall;
}un_TX_DQPSK_TOP_CTRL;


//TX_DQPSK_MEM_CTRL
typedef struct {
	//Byte0~1
	uint32_t tx_mem_addr_start0			: 16;
	//Byte2~3
	uint32_t tx_mem_addr_start1			: 16;
}st_TX_DQPSK_MEM_CTRL;
typedef union {
	st_TX_DQPSK_MEM_CTRL				bs;
	uint32_t							overall;
}un_TX_DQPSK_MEM_CTRL;


//TX_DQPSK_LEN_CFG
typedef struct {
	//Byte0~1
	uint32_t tx_num_sym_data_frm		: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_num_pad_data_frm		: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_LEN_CFG;
typedef union {
	st_TX_DQPSK_LEN_CFG					bs;
	uint32_t							overall;
}un_TX_DQPSK_LEN_CFG;


//TX_DQPSK_MODE_CFG
typedef struct {
	//Byte0~1
	uint32_t tx_fec_selection			: 2;
	uint32_t RFU0						: 14;
	//Byte2~3
	uint32_t tx_fir_gain				: 11;
	uint32_t RFU1						: 5;
}st_TX_DQPSK_MODE_CFG;
typedef union {
	st_TX_DQPSK_MODE_CFG				bs;
	uint32_t							overall;
}un_TX_DQPSK_MODE_CFG;


//TX_DQPSK_PSC_G0
typedef struct {
	//Byte0~1
	uint32_t tx_psc_0					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_1					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G0;
typedef union {
	st_TX_DQPSK_PSC_G0					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G0;


//TX_DQPSK_PSC_G1
typedef struct {
	//Byte0~1
	uint32_t tx_psc_2					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_3					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G1;
typedef union {
	st_TX_DQPSK_PSC_G1					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G1;


//TX_DQPSK_PSC_G2
typedef struct {
	//Byte0~1
	uint32_t tx_psc_4					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_5					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G2;
typedef union {
	st_TX_DQPSK_PSC_G2					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G2;


//TX_DQPSK_PSC_G3
typedef struct {
	//Byte0~1
	uint32_t tx_psc_6					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_7					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G3;
typedef union {
	st_TX_DQPSK_PSC_G3					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G3;


//TX_DQPSK_PSC_G4
typedef struct {
	//Byte0~1
	uint32_t tx_psc_8					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_9					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G4;
typedef union {
	st_TX_DQPSK_PSC_G4					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G4;


//TX_DQPSK_PSC_G5
typedef struct {
	//Byte0~1
	uint32_t tx_psc_10					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_11					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G5;
typedef union {
	st_TX_DQPSK_PSC_G5					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G5;


//TX_DQPSK_PSC_G6
typedef struct {
	//Byte0~1
	uint32_t tx_psc_12					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_13					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G6;
typedef union {
	st_TX_DQPSK_PSC_G6					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G6;


//TX_DQPSK_PSC_G7
typedef struct {
	//Byte0~1
	uint32_t tx_psc_14					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_15					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G7;
typedef union {
	st_TX_DQPSK_PSC_G7					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G7;


//TX_DQPSK_PSC_G8
typedef struct {
	//Byte0~1
	uint32_t tx_psc_16					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_17					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G8;
typedef union {
	st_TX_DQPSK_PSC_G8					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G8;


//TX_DQPSK_PSC_G9
typedef struct {
	//Byte0~1
	uint32_t tx_psc_18					: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_psc_19					: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_PSC_G9;
typedef union {
	st_TX_DQPSK_PSC_G9					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G9;


//TX_DQPSK_PSC_G10
typedef struct {
	//Byte0~3
	uint32_t tx_psc_20					: 13;
	uint32_t RFU0						: 19;
}st_TX_DQPSK_PSC_G10;
typedef union {
	st_TX_DQPSK_PSC_G10					bs;
	uint32_t							overall;
}un_TX_DQPSK_PSC_G10;


//TX_DQPSK_AAF_G0
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_0 				: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_1				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G0;
typedef union {
	st_TX_DQPSK_AAF_G0					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G0;


//TX_DQPSK_AAF_G1
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_2 				: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_3				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G1;
typedef union {
	st_TX_DQPSK_AAF_G1					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G1;


//TX_DQPSK_AAF_G2
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_4 				: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_5				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G2;
typedef union {
	st_TX_DQPSK_AAF_G2					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G2;


//TX_DQPSK_AAF_G3
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_6 				: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_7				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G3;
typedef union {
	st_TX_DQPSK_AAF_G3					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G3;


//TX_DQPSK_AAF_G4
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_8 				: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_9				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G4;
typedef union {
	st_TX_DQPSK_AAF_G4					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G4;


//TX_DQPSK_AAF_G5
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_10 			: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_11				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G5;
typedef union {
	st_TX_DQPSK_AAF_G5					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G5;


//TX_DQPSK_AAF_G6
typedef struct {
	//Byte0~1
	uint32_t tx_aaf_coef_12 			: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t tx_aaf_coef_13				: 13;
	uint32_t RFU1						: 3;
}st_TX_DQPSK_AAF_G6;
typedef union {
	st_TX_DQPSK_AAF_G6					bs;
	uint32_t							overall;
}un_TX_DQPSK_AAF_G6;


//TX_DQPSK_INT_EN
typedef struct {
	//Byte0~3
	uint32_t tx_int_en_config_loaded	: 1;
	uint32_t tx_int_en_end				: 1;
	uint32_t tx_int_en_sd_pa			: 1;
	uint32_t RFU0						: 29;
}st_TX_DQPSK_INT_EN;
typedef union {
	st_TX_DQPSK_INT_EN					bs;
	uint32_t							overall;
}un_TX_DQPSK_INT_EN;


//TX_DQPSK_INT_STATUS
typedef struct {
	//Byte0~3
	uint32_t tx_config_loaded 			: 1;
	uint32_t tx_end						: 1;
	uint32_t tx_sd_pa					: 1;
	uint32_t RFU0						: 29;
}st_TX_DQPSK_INT_STATUS;
typedef union {
	st_TX_DQPSK_INT_STATUS				bs;
	uint32_t							overall;
}un_TX_DQPSK_INT_STATUS;


//TX_DQPSK_SDPA_DELAY
typedef struct {
	//Byte0~3
	uint32_t tx_sd_pa_delay	 			: 9;
	uint32_t RFU0						: 23;
}st_TX_DQPSK_SDPA_DELAY;
typedef union {
	st_TX_DQPSK_SDPA_DELAY				bs;
	uint32_t							overall;
}un_TX_DQPSK_SDPA_DELAY;


//RX_DQPSK_TOP_CTRL
typedef struct {
	//Byte0
	uint32_t rx_enable	 				: 1;
	uint32_t RFU0						: 3;
	uint32_t rx_top_fsm_mode			: 1;
	uint32_t RFU1						: 3;
	//Byte1
	uint32_t rx_top_fsm_sta				: 2;
	uint32_t RFU2						: 6;
	//Byte2~3
	uint32_t rx_clk_96m_aon				: 1;
	uint32_t rx_dvg_rst_mode			: 1;
	uint32_t RFU3						: 14;
}st_RX_DQPSK_TOP_CTRL;
typedef union {
	st_RX_DQPSK_TOP_CTRL				bs;
	uint32_t							overall;
}un_RX_DQPSK_TOP_CTRL;


//RX_DQPSK_MEM_CTRL
typedef struct {
	//Byte0~1
	uint32_t rx_mem_addr_start0			: 16;
	//Byte2~3
	uint32_t rx_mem_addr_start1			: 16;
}st_RX_DQPSK_MEM_CTRL;
typedef union {
	st_RX_DQPSK_MEM_CTRL				bs;
	uint32_t							overall;
}un_RX_DQPSK_MEM_CTRL;


//RX_DQPSK_LEN_CFG
typedef struct {
	//Byte0~1
	uint32_t rx_num_sym_data_frm		: 13;
	uint32_t RFU0						: 3;
	//Byte2~3
	uint32_t rx_num_pad_data_frm		: 13;
	uint32_t RFU1						: 3;
}st_RX_DQPSK_LEN_CFG;
typedef union {
	st_RX_DQPSK_LEN_CFG					bs;
	uint32_t							overall;
}un_RX_DQPSK_LEN_CFG;


//RX_DQPSK_MODE_CFG
typedef struct {
	//Byte0
	uint32_t rx_fec_selection			: 2;
	uint32_t RFU0						: 2;
	uint32_t rx_mem_width				: 2;
	uint32_t RFU1						: 2;
	//Byte1~3
	uint32_t rx_mseq_init				: 5;
	uint32_t RFU2						: 19;
}st_RX_DQPSK_MODE_CFG;
typedef union {
	st_RX_DQPSK_MODE_CFG				bs;
	uint32_t							overall;
}un_RX_DQPSK_MODE_CFG;


//RX_DQPSK_INT_EN
typedef struct {
	//Byte0
	uint32_t mem0_received				: 1;
	uint32_t mem1_received				: 1;
	uint32_t sync_init_done				: 1;
	uint32_t init_sync_timeout			: 1;
	uint32_t to_diverge					: 1;
	uint32_t fo_diverge					: 1;
	uint32_t prmb_miss					: 1;
	uint32_t csf_mid_frm_gain_intp		: 1;
	//Byte1
	uint32_t prmb_peak_detected			: 1;
	uint32_t fec_error					: 1;
	uint32_t false_prmb					: 1;
	uint32_t csf_min_gain				: 1;
	uint32_t csf_max_gain				: 1;
	uint32_t csf_gain_var				: 1;
	uint32_t cic_min_gain				: 1;
	uint32_t cic_max_gain				: 1;
	//Byte2~3
	uint32_t cic_gain_var				: 1;
	uint32_t frm_end_adj				: 1;
	uint32_t RFU0						: 14;
}st_RX_DQPSK_INT_EN;
typedef union {
	st_RX_DQPSK_INT_EN					bs;
	uint32_t							overall;
}un_RX_DQPSK_INT_EN;


//RX_DQPSK_INT_STATUS
typedef struct {
	//Byte0
	uint32_t mem0_received				: 1;
	uint32_t mem1_reveived				: 1;
	uint32_t sync_init_done				: 1;
	uint32_t init_sync_timeout			: 1;
	uint32_t to_diverge					: 1;
	uint32_t fo_diverge					: 1;
	uint32_t prmb_miss					: 1;
	uint32_t csf_mid_frm_gain_intp		: 1;
	//Byte1
	uint32_t prmb_peak_detected			: 1;
	uint32_t fec_error					: 1;
	uint32_t false_prmb					: 1;
	uint32_t csf_min_gain				: 1;
	uint32_t csf_max_gain				: 1;
	uint32_t csf_gain_var				: 1;
	uint32_t cic_min_gain				: 1;
	uint32_t cic_max_gain				: 1;
	//Byte2~3
	uint32_t cic_gain_var				: 1;
	uint32_t frm_end_adj				: 1;
	uint32_t RFU0						: 14;
}st_RX_DQPSK_INT_STATUS;
typedef union {
	st_RX_DQPSK_INT_STATUS				bs;
	uint32_t							overall;
}un_RX_DQPSK_INT_STATUS;


//RX_DQPSK_CIC_AGC_CFG0
typedef struct {
	//Byte0~1
	uint32_t cic_agc_set_point			: 11;
	uint32_t RFU0						: 5;
	//Byte2~3
	uint32_t cic_agc_window_size		: 16;
}st_RX_DQPSK_CIC_AGC_CFG0;
typedef union {
	st_RX_DQPSK_CIC_AGC_CFG0			bs;
	uint32_t							overall;
}un_RX_DQPSK_CIC_AGC_CFG0;


//RX_DQPSK_CIC_AGC_CFG1
typedef struct {
	//Byte0~1
	uint32_t cic_agc_rssi_exp			: 3;
	uint32_t RFU0						: 5;
	uint32_t cic_gain_var_th			: 5;
	uint32_t RFU1						: 3;
	//Byte2~3
	uint32_t cic_agc_rssi_rb			: 13;
	uint32_t RFU2						: 3;
}st_RX_DQPSK_CIC_AGC_CFG1;
typedef union {
	st_RX_DQPSK_CIC_AGC_CFG1			bs;
	uint32_t							overall;
}un_RX_DQPSK_CIC_AGC_CFG1;


//RX_DQPSK_CIC_AGC_CFG2
typedef struct {
	//Byte0
	uint32_t cic_agc_gain_sel			: 1;
	uint32_t RFU0						: 3;
	uint32_t cic_agc_gain_freeze		: 1;
	uint32_t RFU1						: 3;
	//Byte1~3
	uint32_t cic_agc_gain_ow			: 11;
	uint32_t RFU2						: 1;
	uint32_t cic_agc_gain_rb			: 11;
	uint32_t RFU3						: 1;
}st_RX_DQPSK_CIC_AGC_CFG2;
typedef union {
	st_RX_DQPSK_CIC_AGC_CFG2			bs;
	uint32_t							overall;
}un_RX_DQPSK_CIC_AGC_CFG2;


//RX_DQPSK_HB_FIR_COEF_G0
typedef struct {
	//Byte0~1
	uint32_t hb_fir_coef0 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t hb_fir_coef1				: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_HB_FIR_COEF_G0;
typedef union {
	st_RX_DQPSK_HB_FIR_COEF_G0			bs;
	uint32_t							overall;
}un_RX_DQPSK_HB_FIR_COEF_G0;


//RX_DQPSK_HB_FIR_COEF_G1
typedef struct {
	//Byte0~1
	uint32_t hb_fir_coef4 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t hb_fir_coef6				: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_HB_FIR_COEF_G1;
typedef union {
	st_RX_DQPSK_HB_FIR_COEF_G1			bs;
	uint32_t							overall;
}un_RX_DQPSK_HB_FIR_COEF_G1;


//RX_DQPSK_CSF_COEF_G0
typedef struct {
	//Byte0~1
	uint32_t csf_coef0	 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t csf_coef1					: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_COEF_G0;
typedef union {
	st_RX_DQPSK_CSF_COEF_G0				bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_COEF_G0;


//RX_DQPSK_CSF_COEF_G1
typedef struct {
	//Byte0~1
	uint32_t csf_coef2	 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t csf_coef3					: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_COEF_G1;
typedef union {
	st_RX_DQPSK_CSF_COEF_G1				bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_COEF_G1;


//RX_DQPSK_CSF_COEF_G2
typedef struct {
	//Byte0~1
	uint32_t csf_coef4	 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t csf_coef5					: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_COEF_G2;
typedef union {
	st_RX_DQPSK_CSF_COEF_G2				bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_COEF_G2;


//RX_DQPSK_CSF_COEF_G3
typedef struct {
	//Byte0~1
	uint32_t csf_coef6	 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t csf_coef7					: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_COEF_G3;
typedef union {
	st_RX_DQPSK_CSF_COEF_G3				bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_COEF_G3;


//RX_DQPSK_CSF_COEF_G4
typedef struct {
	//Byte0~1
	uint32_t csf_coef8	 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t csf_coef9					: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_COEF_G4;
typedef union {
	st_RX_DQPSK_CSF_COEF_G4				bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_COEF_G4;


//RX_DQPSK_CSF_AGC_CFG0
typedef struct {
	//Byte0~1
	uint32_t csf_agc_set_point			: 11;
	uint32_t RFU0						: 5;
	//Byte2~3
	uint32_t csf_agc_window_size		: 15;
	uint32_t RFU1						: 1;
}st_RX_DQPSK_CSF_AGC_CFG0;
typedef union {
	st_RX_DQPSK_CSF_AGC_CFG0			bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_AGC_CFG0;


//RX_DQPSK_CSF_AGC_CFG1
typedef struct {
	//Byte0~1
	uint32_t csf_agc_rssi_exp			: 3;
	uint32_t RFU0						: 13;
	//Byte2~3
	uint32_t csf_agc_rssi_rb			: 13;
	uint32_t RFU1						: 3;
}st_RX_DQPSK_CSF_AGC_CFG1;
typedef union {
	st_RX_DQPSK_CSF_AGC_CFG1			bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_AGC_CFG1;


//RX_DQPSK_CSF_AGC_CFG2
typedef struct {
	//Byte0
	uint32_t csf_agc_gain_sel			: 1;
	uint32_t RFU0						: 3;
	uint32_t csf_agc_gain_freeze		: 1;
	uint32_t RFU1						: 3;
	//Byte1~3
	uint32_t csf_agc_gain_ow			: 11;
	uint32_t RFU2						: 1;
	uint32_t csf_agc_gain_rb			: 11;
	uint32_t RFU3						: 1;
}st_RX_DQPSK_CSF_AGC_CFG2;
typedef union {
	st_RX_DQPSK_CSF_AGC_CFG2			bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_AGC_CFG2;


//RX_DQPSK_CSF_AGC_CFG3
typedef struct {
	//Byte0~1
	uint32_t csf_avg_rssi_exp			: 4;
	uint32_t RFU0						: 12;
	//Byte2~3
	uint32_t csf_avg_rssi				: 12;
	uint32_t RFU1						: 4;
}st_RX_DQPSK_CSF_AGC_CFG3;
typedef union {
	st_RX_DQPSK_CSF_AGC_CFG3			bs;
	uint32_t							overall;
}un_RX_DQPSK_CSF_AGC_CFG3;


//RX_DQPSK_NOTCH_FLTx_CFG
typedef struct {
	//Byte0~1
	uint32_t notch_filter_en			: 1;
	uint32_t notch_filter_alpha_p		: 3;
	uint32_t notch_filter_beta_re		: 11;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t notch_filter_beta_im		: 11;
	uint32_t RFU1						: 5;
}st_RX_DQPSK_NOTCH_FLTx_CFG;
typedef union {
	st_RX_DQPSK_NOTCH_FLTx_CFG			bs;
	uint32_t							overall;
}un_RX_DQPSK_NOTCH_FLT0_CFG;
typedef union {
	st_RX_DQPSK_NOTCH_FLTx_CFG			bs;
	uint32_t							overall;
}un_RX_DQPSK_NOTCH_FLT1_CFG;
typedef union {
	st_RX_DQPSK_NOTCH_FLTx_CFG			bs;
	uint32_t							overall;
}un_RX_DQPSK_NOTCH_FLT2_CFG;


//RX_DQPSK_PRMB_CFG0
typedef struct {
	//Byte0~2
	uint32_t preamble_detect_low		: 9;
	uint32_t RFU0						: 3;
	uint32_t preamble_detect_high		: 9;
	uint32_t RFU1						: 3;
	//Byte3
	uint32_t preamble_iir_alpha			: 3;
	uint32_t RFU2						: 5;
}st_RX_DQPSK_PRMB_CFG0;
typedef union {
	st_RX_DQPSK_PRMB_CFG0				bs;
	uint32_t							overall;
}un_RX_DQPSK_PRMB_CFG0;


//RX_DQPSK_PRMB_CFG1
typedef struct {
	//Byte0
	uint32_t fo_est_cnt_th				: 5;
	uint32_t RFU0						: 3;
	//Byte1~2
	uint32_t fo_est_amp_th				: 10;
	uint32_t RFU1						: 6;
	//Byte3
	uint32_t preamble_detect_th			: 3;
	uint32_t RFU2						: 5;
}st_RX_DQPSK_PRMB_CFG1;
typedef union {
	st_RX_DQPSK_PRMB_CFG1				bs;
	uint32_t							overall;
}un_RX_DQPSK_PRMB_CFG1;


//RX_DQPSK_INIT_SYNC_CFG
typedef struct {
	//Byte0
	uint32_t initial_acq_th				: 5;
	uint32_t RFU0						: 3;
	//Byte1
	uint32_t init_sync_timeout			: 8;
	//Byte2~3
	uint32_t RFU1						: 16;
}st_RX_DQPSK_INIT_SYNC_CFG;
typedef union {
	st_RX_DQPSK_INIT_SYNC_CFG			bs;
	uint32_t							overall;
}un_RX_DQPSK_INIT_SYNC_CFG;


//RX_DQPSK_TIMING_OFFSET
typedef struct {
	//Byte0
	uint32_t to_diverge_reset_n			: 2;
	uint32_t to_diverge_th				: 6;
	//Byte1
	uint32_t RFU0						: 4;
	uint32_t to_avg_iir_alpha_exp		: 3;
	uint32_t RFU1						: 1;
	//Byte2~3
	uint32_t to_est_rb					: 15;
	uint32_t RFU2						: 1;
}st_RX_DQPSK_TIMING_OFFSET;
typedef union {
	st_RX_DQPSK_TIMING_OFFSET			bs;
	uint32_t							overall;
}un_RX_DQPSK_TIMING_OFFSET;


//RX_DQPSK_FREQ_OFFSET
typedef struct {
	//Byte0~1
	uint32_t fo_diverge_reset_n			: 2;
	uint32_t fo_diverge_th				: 10;
	uint32_t fo_avg_iir_alpha_exp		: 3;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t fo_est_rb					: 12;
	uint32_t RFU1						: 4;
}st_RX_DQPSK_FREQ_OFFSET;
typedef union {
	st_RX_DQPSK_FREQ_OFFSET				bs;
	uint32_t							overall;
}un_RX_DQPSK_FREQ_OFFSET;


//RX_DQPSK_DEMOD_SETTING
typedef struct {
	//Byte0
	uint32_t data_detect_os_ratio		: 3;
	uint32_t RFU0						: 1;
	uint32_t filter_delay				: 3;
	uint32_t RFU1						: 1;
	//Byte1~3
	uint32_t RFU2						: 24;
}st_RX_DQPSK_DEMOD_SETTING;
typedef union {
	st_RX_DQPSK_DEMOD_SETTING			bs;
	uint32_t							overall;
}un_RX_DQPSK_DEMOD_SETTING;


//RX_DQPSK_ERR_STATUS0
typedef struct {
	//Byte0~1
	uint32_t to_err_cnt					: 10;
	uint32_t RFU0						: 6;
	//Byte2~3
	uint32_t fo_err_cnt					: 10;
	uint32_t RFU1						: 6;
}st_RX_DQPSK_ERR_STATUS0;
typedef union {
	st_RX_DQPSK_ERR_STATUS0				bs;
	uint32_t							overall;
}un_RX_DQPSK_ERR_STATUS0;


//RX_DQPSK_ERR_STATUS1
typedef struct {
	//Byte0~3
	uint32_t prmb_miss_cnt 				: 10;
	uint32_t RFU0						: 22;
}st_RX_DQPSK_ERR_STATUS1;
typedef union {
	st_RX_DQPSK_ERR_STATUS1				bs;
	uint32_t							overall;
}un_RX_DQPSK_ERR_STATUS1;


//RX_DQPSK_FSM_STATUS
typedef struct {
	//Byte0~1
	uint32_t prmb_peak_loc 				: 15;
	uint32_t RFU0						: 1;
	//Byte2~3
	uint32_t frm_end_adjust				: 11;
	uint32_t RFU1						: 5;
}st_RX_DQPSK_FSM_STATUS;
typedef union {
	st_RX_DQPSK_FSM_STATUS				bs;
	uint32_t							overall;
}un_RX_DQPSK_FSM_STATUS;


//RX_DQPSK_FALSE_PRMB_TH0
typedef struct {
	//Byte0~1
	uint32_t false_detection_th			: 10;
	uint32_t RFU0						: 6;
	//Byte2~3
	uint32_t missed_preamble_th			: 10;
	uint32_t RFU1						: 6;
}st_RX_DQPSK_FALSE_PRMB_TH0;
typedef union {
	st_RX_DQPSK_FALSE_PRMB_TH0			bs;
	uint32_t							overall;
}un_RX_DQPSK_FALSE_PRMB_TH0;


//RX_DQPSK_AGC_FRM_END_CTRL
typedef struct {
	//Byte0
	uint32_t cic_agc_frm_end_ls			: 6;
	uint32_t RFU0						: 2;
	//Byte1
	uint32_t cic_agc_frm_end_rs			: 6;
	uint32_t RFU1						: 2;
	//Byte2
	uint32_t frm_end_left_shift			: 6;
	uint32_t RFU2						: 10;
}st_RX_DQPSK_AGC_FRM_END_CTRL;
typedef union {
	st_RX_DQPSK_AGC_FRM_END_CTRL		bs;
	uint32_t							overall;
}un_RX_DQPSK_AGC_FRM_END_CTRL;


//RX_DQPSK_PRMB_ADAPTIVE_TH
typedef struct {
	//Byte0~1
	uint32_t prmb_adaptive_th_low		: 9;
	uint32_t RFU0						: 7;
	//Byte2~3
	uint32_t prmb_adaptive_th_high		: 9;
	uint32_t RFU1						: 6;
	uint32_t prmb_adaptive_th_en		: 1;
}st_RX_DQPSK_PRMB_ADAPTIVE_TH;
typedef union {
	st_RX_DQPSK_PRMB_ADAPTIVE_TH		bs;
	uint32_t							overall;
}un_RX_DQPSK_PRMB_ADAPTIVE_TH;

#define RX_GFSK_STATUS0				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x00)))
#define RX_GFSK_STATUS1				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x04)))
#define RX_GFSK_CONFIG0				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x08)))
#define RX_GFSK_CONFIG1				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x0C)))
#define RX_GFSK_CONFIG2				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x10)))
#define RX_GFSK_CONFIG3				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x14)))
#define RX_GFSK_CONFIG4				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x18)))
#define RX_GFSK_CONFIG5				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x1C)))
#define RX_GFSK_CONFIG6				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x20)))
#define RX_GFSK_CONFIG7				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x24)))
#define RX_GFSK_CONFIG8				(*((volatile uint32_t *)(RX_GFSK_BASE + 0x28)))

#define TX_GFSK_STATUS0				(*((volatile uint32_t *)(TX_GFSK_BASE + 0x00)))
#define TX_GFSK_CONFIG0				(*((volatile uint32_t *)(TX_GFSK_BASE + 0x04)))
#define TX_GFSK_CONFIG1				(*((volatile uint32_t *)(TX_GFSK_BASE + 0x08)))
#define TX_GFSK_CREFLT_COEFF0		(*((volatile uint32_t *)(TX_GFSK_BASE + 0x0C)))
#define TX_GFSK_CREFLT_COEFF1		(*((volatile uint32_t *)(TX_GFSK_BASE + 0x10)))
#define TX_GFSK_CREFLT_COEFF2		(*((volatile uint32_t *)(TX_GFSK_BASE + 0x14)))
#define TX_GFSK_CREFLT_COEFF3		(*((volatile uint32_t *)(TX_GFSK_BASE + 0x18)))
#define TX_GFSK_PN_SEQ0				(*((volatile uint32_t *)(TX_GFSK_BASE + 0x1C)))
#define TX_GFSK_PN_SEQ1				(*((volatile uint32_t *)(TX_GFSK_BASE + 0x20)))
#define TX_GFSK_SCRAM_INIT			(*((volatile uint32_t *)(TX_GFSK_BASE + 0x24)))
#define TX_GFSK_BUFFER_STARTADDR	(*((volatile uint32_t *)(TX_GFSK_BASE + 0x28)))
#define TX_GFSK_BUFFER_START		(*((volatile uint32_t *)(TX_GFSK_BASE + 0x2C)))

#define TX_DQPSK_TOP_CTRL			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x00)))
#define TX_DQPSK_MEM_CTRL			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x04)))
#define TX_DQPSK_LEN_CFG			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x08)))
#define TX_DQPSK_MODE_CFG			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x0C)))
#define TX_DQPSK_PSC_G0				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x10)))
#define TX_DQPSK_PSC_G1				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x14)))
#define TX_DQPSK_PSC_G2				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x18)))
#define TX_DQPSK_PSC_G3				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x1C)))
#define TX_DQPSK_PSC_G4				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x20)))
#define TX_DQPSK_PSC_G5				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x24)))
#define TX_DQPSK_PSC_G6				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x28)))
#define TX_DQPSK_PSC_G7				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x2C)))
#define TX_DQPSK_PSC_G8				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x30)))
#define TX_DQPSK_PSC_G9				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x34)))
#define TX_DQPSK_PSC_G10			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x38)))
//0x3C RFU
#define TX_DQPSK_AAF_G0				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x40)))
#define TX_DQPSK_AAF_G1				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x44)))
#define TX_DQPSK_AAF_G2				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x48)))
#define TX_DQPSK_AAF_G3				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x4C)))
#define TX_DQPSK_AAF_G4				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x50)))
#define TX_DQPSK_AAF_G5				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x54)))
#define TX_DQPSK_AAF_G6				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x58)))
//0x5C RFU
#define TX_DQPSK_INT_EN				(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x60)))
#define TX_DQPSK_INT_STATUS			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x64)))
#define TX_DQPSK_SDPA_DELAY			(*((volatile uint32_t *)(TX_DQPSK_BASE + 0x68)))


#define RX_DQPSK_TOP_CTRL			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x00)))
#define RX_DQPSK_MEM_CTRL			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x04)))
#define RX_DQPSK_LEN_CFG			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x08)))
#define RX_DQPSK_MODE_CFG			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x0C)))
#define RX_DQPSK_INT_EN				(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x10)))
#define RX_DQPSK_INT_STATUS			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x14)))
//0x18~0x1C RFU
#define RX_DQPSK_CIC_AGC_CFG0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x20)))
#define RX_DQPSK_CIC_AGC_CFG1		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x24)))
#define RX_DQPSK_CIC_AGC_CFG2		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x28)))
//0x2C RFU
#define RX_DQPSK_HB_FIR_COEF_G0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x30)))
#define RX_DQPSK_HB_FIR_COEF_G1		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x34)))
//0x38~0x3C RFU
#define RX_DQPSK_CSF_COEF_G0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x40)))
#define RX_DQPSK_CSF_COEF_G1		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x44)))
#define RX_DQPSK_CSF_COEF_G2		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x48)))
#define RX_DQPSK_CSF_COEF_G3		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x4C)))
#define RX_DQPSK_CSF_COEF_G4		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x50)))
//0x54~0x5C RFU
#define RX_DQPSK_CSF_AGC_CFG0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x60)))
#define RX_DQPSK_CSF_AGC_CFG1		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x64)))
#define RX_DQPSK_CSF_AGC_CFG2		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x68)))
#define RX_DQPSK_CSF_AGC_CFG3		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x6C)))
#define RX_DQPSK_NOTCH_FLT0_CFG		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x70)))
#define RX_DQPSK_NOTCH_FLT1_CFG		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x74)))
#define RX_DQPSK_NOTCH_FLT2_CFG		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x78)))
//0x7C RFU
#define RX_DQPSK_PRMB_CFG0			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x80)))
#define RX_DQPSK_PRMB_CFG1			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x84)))
//0x88 RFU
#define RX_DQPSK_INIT_SYNC_CFG		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x8C)))
#define RX_DQPSK_TIMING_OFFSET		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x90)))
#define RX_DQPSK_FREQ_OFFSET		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x94)))
//0x98 RFU
#define RX_DQPSK_DEMOD_SETTING		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0x9C)))
#define RX_DQPSK_ERR_STATUS0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xA0)))
#define RX_DQPSK_ERR_STATUS1		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xA4)))
#define RX_DQPSK_FSM_STATUS			(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xA8)))
#define RX_DQPSK_FALSE_PRMB_TH0		(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xAC)))
#define RX_DQPSK_AGC_FRM_END_CTRL	(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xB0)))
//B4
#define RX_DQPSK_PRMB_ADAPTIVE_TH	(*((volatile uint32_t *)(RX_DQPSK_BASE + 0xB8)))



#ifdef  __cplusplus
}
#endif

#endif /* REG_RF_H_ */
