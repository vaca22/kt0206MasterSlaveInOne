#ifndef __SOFT_I2C_H__
#define __SOFT_I2C_H__

#include <stdint.h>
#include "api.h"
#include "UserComm.h"

#define PACKED __attribute__((packed))

//-------------------------------------------------------
//错误返回值
//-------------------------------------------------------
typedef enum {
	SoftI2C_OK			= 0,
	SoftI2C_NULLPtr		= 1,
	SoftI2C_NoDevice	= 2,
	SoftI2C_AddrNoACK	= 3,
	SoftI2C_DataNoACK	= 4,
} PACKED SoftI2C_Ret_t;

//-------------------------------------------------------
//速度配置
//-------------------------------------------------------
typedef enum {
	SoftI2C_100K		= 0,
	SoftI2C_200K		= 1,
	SoftI2C_300K		= 2,
	SoftI2C_400K		= 3,
} PACKED SoftI2C_Speed_t;

//-------------------------------------------------------
//字节长度配置
//-------------------------------------------------------
typedef enum {
	SoftI2C_1Byte		= 0,
	SoftI2C_2Byte		= 1,
	SoftI2C_4Byte		= 3,
} PACKED SoftI2C_Len_t;

//-------------------------------------------------------
//结构体定义
//-------------------------------------------------------
typedef struct {
	api_gpio_def_e		SCL_Pin;			//SCL的IO号
	api_gpio_def_e		SDA_Pin;			//SDA的IO号

	uint8_t				DeviceAddr;		//高7-bit设备地址, 驱动自己会根据读写设置最后1-bit

	SoftI2C_Len_t		AddrLen		: 2;
	SoftI2C_Len_t		DataLen		: 2;
	SoftI2C_Speed_t		Speed		: 2;
}SoftI2C_t;

//-------------------------------------------------------
//初始化, 将GPIO设置为悬空输入
//-------------------------------------------------------
void SoftI2C_Init(const SoftI2C_t * pSoftI2C);

//-------------------------------------------------------
//单次读寄存器
//RegAddr : 寄存器地址, 由AddrLen指定几字节有效, LSB对齐
//pData   : 读回来的数据统一使用uint32_t存放, 由DataLen指定几字节有效, LSB对齐
//return  : 操作返回值, 指示成功/失败, 错误类型
//-------------------------------------------------------
SoftI2C_Ret_t SoftI2C_ReadReg(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	uint32_t * 			pData
);
#if 0	//操作例程
uint32_t regx;
if(SoftI2C_OK != SoftI2C_ReadReg(&KT0656M, 0x0000, &regx)) {
	;//Error
}
#endif


//-------------------------------------------------------
//单次写寄存器
//RegAddr : 寄存器地址, 由AddrLen指定几字节有效, LSB对齐
//Data    : 要写的数据统一使用uint32_t存放, 由DataLen指定几字节有效, LSB对齐
//return  : 操作返回值, 指示成功/失败, 错误类型
//-------------------------------------------------------
SoftI2C_Ret_t SoftI2C_WriteReg(
	const SoftI2C_t *	pSoftI2C,
	uint32_t			RegAddr,
	uint32_t			Data
);
#if 0	//操作例程
if(SoftI2C_OK != SoftI2C_WriteReg(&KT0656M, 0x0000, 0xAA) {
	;//Error
}
#endif


//-------------------------------------------------------
//连续读寄存器
//RegAddr : 连续读取的寄存器起始地址, 由AddrLen指定几字节有效, LSB对齐
//pData   : 数据是几字节, 就给pData传相应的指针, 读回来的数据按DataLen指定的长度小端存放
//Len     : 要读取的寄存器个数
//return  : 操作返回值, 指示成功/失败, 错误类型
//-------------------------------------------------------
SoftI2C_Ret_t SoftI2C_ReadRegs(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	void *				pData,
	uint32_t			Len
);

#if 0	//操作例程
//KT0656M 2字节地址 1字节数据, 就给pData传uint8_t的指针
uint8_t reg_buf[4];
if(SoftI2C_OK != SoftI2C_ReadRegs(&KT0656M, 0x0000, reg_buf, 4)) {
	;//Error
}

//KT0616M 1字节地址 2字节数据, 就给pData传uint16_t的指针
uint16_t reg_buf[4];
if(SoftI2C_OK != SoftI2C_ReadRegs(&KT0616M, 0x00, reg_buf, 4)) {
	;//Error
}
#endif


//-------------------------------------------------------
//连续写寄存器
//RegAddr : 连续写的寄存器起始地址, 由AddrLen指定几字节有效, LSB对齐
//pData   : 数据是几字节, 就给pData传相应的指针, 数据小端存放
//Len     : 要读取的寄存器个数
//return  : 操作返回值, 指示成功/失败, 错误类型
//-------------------------------------------------------
SoftI2C_Ret_t SoftI2C_WriteRegs(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	const void *		pData,
	uint32_t			Len
);
#if 0	//操作例程
//KT0656M 2字节地址 1字节数据, 就给pData传uint8_t的指针
uint8_t reg_buf[4] = {
	[0] = 0x01,
	[1] = 0x23,
	[2] = 0x45,
	[3] = 0x67,
};
//从0x0000开始写4个寄存器
if(SoftI2C_OK != SoftI2C_WriteRegs(&KT0656M, 0x0000, reg_buf, 4)) {
	;//Error
}

//KT0616M 1字节地址 2字节数据, 就给pData传uint16_t的指针
uint16_t reg_buf[4] = {
	[0] = 0x0123,
	[1] = 0x4567,
	[2] = 0x89AB,
	[3] = 0xCDEF,
};
//从0x00开始写4个寄存器
if(SoftI2C_OK != SoftI2C_WriteRegs(&KT0616M, 0x00, reg_buf, 4)) {
	;//Error
}
#endif

#endif /* SOFT_I2C_H_ */
