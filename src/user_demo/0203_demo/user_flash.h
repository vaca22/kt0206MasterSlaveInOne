#ifndef __USER_FLASH_H__
#define __USER_FLASH_H__

#include <stdint.h>
#include "KT065x_SeekFreq.h"

typedef struct               // 需要保存到Flash中数据
{
	uint8_t                     LastSeekFreqOKIndex;       // 上一次搜台OK索引号
	uint8_t  					CurrentVolume;			   // 当前音量值关机保存,未用
	uint16_t					PrivateID;                 // 私人ID码（唯一）
	uint32_t                    RFU;                       // 保留
}SaveSeekData_t;

typedef struct
{
	uint32_t 					SeekFreqTitle;
	SaveSeekData_t 				SeekData_A;
	SaveSeekData_t 				SeekData_B;
	uint32_t 					RFU0;
	uint32_t 					RFU1;
	uint32_t                    CheckSum;
}UserSaveData_t;

extern UserSaveData_t FlashData;           // 用户保存的数据

uint8_t SaveDataToFlash(UserSaveData_t *pData);

uint8_t ReadDataFromFlash(void)  __attribute__((no_ext_zol));

#endif /* SOFT_I2C_H_ */
