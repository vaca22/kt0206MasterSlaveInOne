/**
 ****************************************************************************************
 *
 * @file i2c.h
 *
 * @brief I2C Driver.
 *
 * Copyright (C) KT Micro,Inc 2011-2017
 *
 *
 ****************************************************************************************
 */

#ifndef _I2C_H_
#define _I2C_H_

/**
 ****************************************************************************************
 * @defgroup I2C_I2C
 * @ingroup DRIVERS
 * @brief I2C driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
#include "config.h"
#include "comm.h"

#define RX_FIFO_DEPTH           0x8
#define TX_FIFO_DEPTH           0x8

#define RAM_DSP_ADDR	0xC0012000
#define RAM_OTP_ADDR	0xC0010000
#define LM_ADDR			0x0
#define APB_ADDR		0xC0010000

typedef enum {
	I2C_Slave_Mode		= 0,
	I2C_Master_Mode		= 1,
}en_I2C_Mode_t;

//I2C_State enum
typedef enum {
    I2C_STATE_IDLE,
    I2C_STATE_TX,
    I2C_STATE_RX,
}en_I2C_STATE_t;

enum {
    I2C_DISABLE = 0,
    I2C_ENABLE = 1
};

enum {
    I2C_CMD_WRITE = 0,
    I2C_CMD_READ = 1
};

typedef enum {
	I2C_Standard_Speed	= 1,	// 100kbit/s
	I2C_Fast_Speed		= 2,	// 400kbit/s
	I2C_High_Speed		= 3,	// 3.4Mbit/s
}en_I2C_Speed_Mode_t;

typedef enum {
	I2C_7bit_Addr		= 0,
	I2C_10bit_Addr		= 1,
}en_I2C_Addr_Length_t;

//I2C_INTR_MASK
typedef struct{
	uint8_t M_GEN_CALL;
	uint8_t M_START_DET;
	uint8_t M_STOP_DET;
	uint8_t M_ACTIVITY;
	uint8_t M_RX_DONE;
	uint8_t M_TX_ABRT;
	uint8_t M_RD_REQ;
	uint8_t M_TX_EMPTY;
	uint16_t M_TX_OVER;
	uint16_t M_RX_FULL;
	uint16_t M_RX_OVER;
	uint16_t M_RX_UNDER;
}I2C_INTR_MASK;

//I2C_IRQ flag enum
typedef enum {
    I2C_IRQ_NONE        = 0x000,   // Specifies no interrupt
    I2C_IRQ_RX_UNDER 	= 0x001,   // Set if the processor attempts to read
                                   // the receive FIFO when it is empty.
    I2C_IRQ_RX_OVER     = 0x002,   // Set if the receive FIFO was
                                   // completely filled and more data
                                   // arrived.  That data is lost.
    I2C_IRQ_RX_FULL     = 0x004,   // Set when the receive FIFO reaches or
                                   // goes above the receive FIFO
                                   // threshold. It is automatically
                                   // cleared by hardware when the receive
                                   // FIFO level goes below the threshold.
    I2C_IRQ_TX_OVER     = 0x008,   // Set during transmit if the transmit
                                   // FIFO is filled and the processor
                                   // attempts to issue another I2C command
                                   // (read request or write).
    I2C_IRQ_TX_EMPTY    = 0x010,   // Set when the transmit FIFO is at or
                                   // below the transmit FIFO threshold
                                   // level. It is automatically cleared by
                                   // hardware when the transmit FIFO level
                                   // goes above the threshold.
    I2C_IRQ_RD_REQ      = 0x020,   // Set when the I2C is acting as a slave
                                   // and another I2C master is attempting
                                   // to read data from the slave.
    I2C_IRQ_TX_ABT      = 0x040,   // In general, this is set when the I2C
                                   // acting as a master is unable to
                                   // complete a command that the processor
                                   // has sent.
    I2C_IRQ_RX_DONE     = 0x080,   // When the I2C is acting as a
                                   // slave-transmitter, this is set if the
                                   // master does not acknowledge a
                                   // transmitted byte. This occurs on the
                                   // last byte of the transmission,
                                   // indicating that the transmission is
                                   // done.
    I2C_IRQ_ACTIVITY    = 0x100,   // This is set whenever the I2C is busy
                                   // (reading from or writing to the I2C
                                   // bus).
    I2C_IRQ_STOP_DET    = 0x200,   // Indicates whether a stop condition
                                   // has occurred on the I2C bus.
    I2C_IRQ_START_DET   = 0x400,   // Indicates whether a start condition
                                   // has occurred on the I2C bus.
    I2C_IRQ_GEN_CALL    = 0x800,   // Indicates that a general call request
                                   // was received. The I2C stores the
                                   // received data in the receive FIFO.
    I2C_IRQ_ALL         = 0xfff,   // Specifies all I2C interrupts.  This
                                   // combined enumeration that can be
                                   // used with some functions such as
                                   // dw_i2c_clearIrq(), dw_i2c_maskIrq(),
                                   // and so on.
}en_I2C_IRQ_t;

//I2C_Init_Struct
typedef struct {
	en_I2C_Mode_t			Mode			: 1;	//	M/S
	en_I2C_Speed_Mode_t		Speed			: 2;	//	M
	en_I2C_Addr_Length_t	Addr_Length		: 1;	//	S
	uint16_t				MS_Addr			: 12;	//	S  MUSES(slave) I2C address
	uint16_t				Ext_Dev_Addr;			//	M  i2c slave device address, MUSES is master

	uint8_t					RX_FIFO_TL;				//	M/S
	uint8_t					TX_FIFO_TL;				//	M/S
	uint16_t			Default_Int_Msk;			//	M/S
}st_I2C_Init_t;

void i2c_init(const st_I2C_Init_t * const pInit);
void I2C_Write_Data(uint8_t device_addr, uint32_t reg_addr, uint8_t reg_addr_len, uint32_t data, uint8_t data_len);
uint32_t I2C_Read_Data(uint8_t device_addr, uint32_t reg_addr, uint8_t reg_addr_len, uint8_t data_len);
//uint8_t I2C_Read_Data(uint8_t device_addr, uint32_t reg_addr, uint8_t reg_addr_len, uint8_t* rbuf, uint8_t data_len);
void i2c_write(uint8_t reg_addr, uint8_t data);
uint8_t i2c_read(uint8_t reg_addr);
void I2C_SLAVE_ISR(uint32_t id);
inline void I2C_Terminate(void);

#endif
