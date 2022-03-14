#include "soft_i2c.h"

void SoftI2C_Init(const SoftI2C_t * pSoftI2C) {
	if(pSoftI2C == NULL) {
		return;
	}
	api_gpio_func_set(pSoftI2C->SCL_Pin, API_GPIO_PullUpInput);
	api_gpio_func_set(pSoftI2C->SDA_Pin, API_GPIO_PullUpInput);
}
static void I2C_Delay(uint16_t cnt) __attribute__((no_ext_zol));
static void I2C_Delay(uint16_t cnt) {
	while(cnt--) {
		__nds32__nop();
	}//must use "-O2" optimize and -mext-zol
}

static const uint16_t SoftI2C_DelayTab[4]= { 125, 50, 3,  0};//120M	{ 100K, 200K, 300K, 400K }

static const uint8_t I2C_LeftShiftTab[4] = {
	24, 16, 8, 0,
};

static void I2C_Start(
	uint16_t DelayCnt,
	api_gpio_def_e SCL,
	api_gpio_def_e SDA
) {
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SCL, API_GPIO_PullUpInput);
	api_gpio_func_set(SDA, API_GPIO_PullUpInput);
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SDA, API_GPIO_Output0);
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SCL, API_GPIO_Output0);
}

static void I2C_Stop(
	uint16_t DelayCnt,
	api_gpio_def_e SCL,
	api_gpio_def_e SDA
) {
	api_gpio_func_set(SCL, API_GPIO_Output0);
	api_gpio_func_set(SDA, API_GPIO_Output0);
	I2C_Delay(DelayCnt);

	api_gpio_func_set(SCL, API_GPIO_PullUpInput);
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SDA, API_GPIO_PullUpInput);
	I2C_Delay(DelayCnt);
}

//return : ACK from slave
static bool I2C_SendByte(
	uint16_t		DelayCnt,
	api_gpio_def_e	SCL,
	api_gpio_def_e	SDA,
	uint8_t			data
) {
	uint8_t i;
	for(i = 0; i < 8; i++) {
		api_gpio_func_set(SDA, (data & 0x80) ? (API_GPIO_PullUpInput) : (API_GPIO_Output0));
		I2C_Delay(DelayCnt);
		api_gpio_func_set(SCL, API_GPIO_PullUpInput);	//SCL = 1;
		data <<= 1;
		I2C_Delay(DelayCnt);
		api_gpio_func_set(SCL, API_GPIO_Output0);	//SCL = 0;
	}
	api_gpio_func_set(SDA, API_GPIO_PullUpInput);	//SDA = 1;
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SCL, API_GPIO_PullUpInput);		//SCL = 1;
	I2C_Delay(DelayCnt);
	if(api_gpio_input_get(SDA)==API_GPIO_INPUT1)
	   data = 1;			// Read ACK
	else
	   data = 0;           // No ACK
	api_gpio_func_set(SCL, API_GPIO_Output0);		//SCL = 0;

	return data;
}

//return : ACK from slave
static bool I2C_Send(
	uint16_t		DelayCnt,
	api_gpio_def_e	SCL,
	api_gpio_def_e	SDA,
	uint32_t		Data,
	int8_t			Len
) {
	Data <<= I2C_LeftShiftTab[Len];
	while(Len >= 0) {
		Len--;
		Data = __nds32__rotr(Data, 24);
		if(true == I2C_SendByte(DelayCnt, SCL, SDA, (uint8_t)Data)) {
			return true;
		}
	}
	return false;
}

//ACK : ACK to slave
//return : data
static uint8_t I2C_ReceiveByte(
	uint16_t		DelayCnt,
	api_gpio_def_e	SCL,
	api_gpio_def_e	SDA,
	bool			ACK
) {
	api_gpio_func_set(SDA, API_GPIO_PullUpInput);
	uint8_t data = 0,i;
	for(i = 0; i < 8; i++) {
		I2C_Delay(DelayCnt);
		api_gpio_func_set(SCL, API_GPIO_PullUpInput);	//SCL = 1;
		I2C_Delay(DelayCnt);
		data = (data<<1);
		if(api_gpio_input_get(SDA)==API_GPIO_INPUT1)
			data++;
		api_gpio_func_set(SCL, API_GPIO_Output0);	//SCL = 0;
	}

	api_gpio_func_set(SDA, (ACK) ? (API_GPIO_PullUpInput) : (API_GPIO_Output0));
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SCL, API_GPIO_PullUpInput);	//SCL = 1;
	I2C_Delay(DelayCnt);
	api_gpio_func_set(SCL, API_GPIO_Output0);	//SCL = 0;

	return data;
}

//return : data format set by Len
static uint32_t I2C_Receive(
	uint16_t		DelayCnt,
	api_gpio_def_e	SCL,
	api_gpio_def_e	SDA,
	int8_t			Len,
	bool			ACK
) {
	uint32_t Data = 0;
	while(Len >= 0) {
		Len--;
		Data <<= 8;
		Data |= I2C_ReceiveByte(DelayCnt, SCL, SDA, (Len < 0) ? (ACK) : (false));
	}
	return Data;
}

SoftI2C_Ret_t SoftI2C_WriteReg(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	uint32_t 			Data
) {
	if(pSoftI2C == NULL) {
		return SoftI2C_NULLPtr;
	}
	api_gpio_def_e SDA = pSoftI2C->SDA_Pin;
	api_gpio_def_e SCL = pSoftI2C->SCL_Pin;
	uint16_t DelayCnt = SoftI2C_DelayTab[pSoftI2C->Speed];

	//start
	I2C_Start(DelayCnt, SCL, SDA);

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, pSoftI2C->DeviceAddr & 0xFE)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//send reg addr
	if(true == I2C_Send(DelayCnt, SCL, SDA, RegAddr, pSoftI2C->AddrLen)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_AddrNoACK;
	}

	//send data
	if(true == I2C_Send(DelayCnt, SCL, SDA, Data, pSoftI2C->DataLen)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_DataNoACK;
	}

	//stop
	I2C_Stop(DelayCnt, SCL, SDA);

	return SoftI2C_OK;
}

SoftI2C_Ret_t SoftI2C_ReadReg(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	uint32_t *			pData
) {
	if((pSoftI2C == NULL) || (pData == NULL)) {
		return SoftI2C_NULLPtr;
	}
	api_gpio_def_e SDA = pSoftI2C->SDA_Pin;
	api_gpio_def_e SCL = pSoftI2C->SCL_Pin;
	uint16_t DelayCnt = SoftI2C_DelayTab[pSoftI2C->Speed];

	//start
	I2C_Start(DelayCnt, SCL, SDA);

	//get device addr
	uint8_t DeviceAddr = pSoftI2C->DeviceAddr & 0xFE;

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, DeviceAddr)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//send reg addr
	if(true == I2C_Send(DelayCnt, SCL, SDA, RegAddr, pSoftI2C->AddrLen)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_AddrNoACK;
	}

	//re-start
	I2C_Start(DelayCnt, SCL, SDA);

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, DeviceAddr | 0x01)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//read data
	uint32_t Data = I2C_Receive(DelayCnt, SCL, SDA, pSoftI2C->DataLen, true);

	//stop
	I2C_Stop(DelayCnt, SCL, SDA);

	//write data back
	*pData = Data;

	return SoftI2C_OK;
}

SoftI2C_Ret_t SoftI2C_WriteRegs(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	const void *		pData,
	uint32_t			Len
) {
	if(pSoftI2C == NULL) {
		return SoftI2C_NULLPtr;
	}
	api_gpio_def_e SDA = pSoftI2C->SDA_Pin;
	api_gpio_def_e SCL = pSoftI2C->SCL_Pin;
	uint16_t DelayCnt = SoftI2C_DelayTab[pSoftI2C->Speed];

	//start
	I2C_Start(DelayCnt, SCL, SDA);

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, pSoftI2C->DeviceAddr & 0xFE)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//send reg addr
	if(true == I2C_Send(DelayCnt, SCL, SDA, RegAddr, pSoftI2C->AddrLen)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_AddrNoACK;
	}

	//send data
	switch(pSoftI2C->DataLen) {
		case SoftI2C_1Byte : {
			const uint8_t * pu8Data = (const uint8_t *)pData;
			while(Len--) {
				if(true == I2C_Send(DelayCnt, SCL, SDA, *pu8Data++, SoftI2C_1Byte)) {
					I2C_Stop(DelayCnt, SCL, SDA);
					return SoftI2C_DataNoACK;
				}
			}
		} break;
		case SoftI2C_2Byte : {
			const uint16_t * pu16Data = (const uint16_t *)pData;
			while(Len--) {
				if(true == I2C_Send(DelayCnt, SCL, SDA, *pu16Data++, SoftI2C_2Byte)) {
					I2C_Stop(DelayCnt, SCL, SDA);
					return SoftI2C_DataNoACK;
				}
			}
		} break;
		case SoftI2C_4Byte : {
			const uint32_t * pu32Data = (const uint32_t *)pData;
			while(Len--) {
				if(true == I2C_Send(DelayCnt, SCL, SDA, *pu32Data++, SoftI2C_4Byte)) {
					I2C_Stop(DelayCnt, SCL, SDA);
					return SoftI2C_DataNoACK;
				}
			}
		} break;
		default : { } break;
	}//switch(DataLen)

	//stop
	I2C_Stop(DelayCnt, SCL, SDA);

	return SoftI2C_OK;
}

SoftI2C_Ret_t SoftI2C_ReadRegs(
	const SoftI2C_t * 	pSoftI2C,
	uint32_t 			RegAddr,
	void *				pData,
	uint32_t			Len
) {
	if((pSoftI2C == NULL) || (pData == NULL)) {
		return SoftI2C_NULLPtr;
	}
	api_gpio_def_e SDA = pSoftI2C->SDA_Pin;
	api_gpio_def_e SCL = pSoftI2C->SCL_Pin;
	uint16_t DelayCnt = SoftI2C_DelayTab[pSoftI2C->Speed];

	//start
	I2C_Start(DelayCnt, SCL, SDA);

	//get device addr
	uint8_t DeviceAddr = pSoftI2C->DeviceAddr & 0xFE;

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, DeviceAddr)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//send reg addr
	if(true == I2C_Send(DelayCnt, SCL, SDA, RegAddr, pSoftI2C->AddrLen)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_AddrNoACK;
	}

	//re-start
	I2C_Start(DelayCnt, SCL, SDA);

	//send device addr
	if(true == I2C_SendByte(DelayCnt, SCL, SDA, DeviceAddr | 0x01)) {
		I2C_Stop(DelayCnt, SCL, SDA);
		return SoftI2C_NoDevice;
	}

	//read data
	switch(pSoftI2C->DataLen) {
		case SoftI2C_1Byte : {
			uint8_t * pu8Data = (uint8_t *)pData;
			while(Len--) {
				*pu8Data++ = (uint8_t)I2C_Receive(DelayCnt, SCL, SDA, SoftI2C_1Byte, !Len);
			}
		} break;
		case SoftI2C_2Byte : {
			uint16_t * pu16Data = (uint16_t *)pData;
			while(Len--) {
				*pu16Data++ = (uint16_t)I2C_Receive(DelayCnt, SCL, SDA, SoftI2C_2Byte, !Len);
			}
		} break;
		case SoftI2C_4Byte : {
			uint32_t * pu32Data = (uint32_t *)pData;
			while(Len--) {
				*pu32Data++ = I2C_Receive(DelayCnt, SCL, SDA, SoftI2C_4Byte, !Len);
			}
		} break;
		default : { } break;
	}//switch(DataLen)

	//stop
	I2C_Stop(DelayCnt, SCL, SDA);

	return SoftI2C_OK;
}
