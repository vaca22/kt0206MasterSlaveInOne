#include "user_flash.h"
#include "api.h"

#define		UserDataStartAddr				0x24000     // size = (0x24000-0x20000) = 0x4000 可存放数据 0x4000(16k)k)
#define		UserDataEndAddr		            0x28000     //
#define     UserDataAreaSize                256         // api_flash_param_save每次至少256byte,存储以256byte对齐
#define     Title_flag                      0x55667788


uint8_t AddrIndex = 0;        // 需要保存到Flash的地址索引值，最大256
UserSaveData_t FlashData = {0};

uint8_t SaveDataToFlash(UserSaveData_t *pData)        // buf最大为256byte一页
{
	uint16_t i;
	uint8_t *p = (uint8_t *)pData;
	uint32_t Sum = 0;
	pData->SeekFreqTitle = Title_flag;

	if(AddrIndex < (UserDataEndAddr-UserDataStartAddr)/UserDataAreaSize)
	{
		for(i=0; i<(sizeof(UserSaveData_t)-4); i++)       // for Check Sum
		{
			Sum += *p++;
		}
	    pData->CheckSum = Sum;             //
		GLOBAL_INT_STOP();
		api_flash_param_save(UserDataStartAddr + AddrIndex*UserDataAreaSize, (uint8_t *)pData, sizeof(UserSaveData_t));
		GLOBAL_INT_START();
//		printf("Addr = 0x%08lx\n", (uint32_t)(UserDataStartAddr + AddrIndex*UserDataAreaSize));
		AddrIndex++;               // Flash的地址索引值++
		return 1;
	}
	else
	{
		return 0;  // fail
	}
}

uint8_t ReadDataFromFlash(void)         //
{
	uint32_t i,j;
	uint32_t Title, Sum = 0;
    uint8_t *p = NULL;

    for(i=0;i<(UserDataEndAddr-UserDataStartAddr)/UserDataAreaSize;i++)
    {
    	api_flash_param_read_NoCache((uint32_t)(UserDataEndAddr - (i+1)*UserDataAreaSize), (uint8_t *)&Title, 4);
        if(Title==Title_flag)
        {
        	api_flash_param_read_NoCache(UserDataEndAddr - (i+1)*UserDataAreaSize, (uint8_t *)&FlashData, sizeof(UserSaveData_t));
			p = (uint8_t *)&FlashData;

			for(j=0; j<(sizeof(UserSaveData_t)-4); j++)         // for Check Sum
			{
				Sum += *p++;
			}
			if(Sum==FlashData.CheckSum)
			{
				return 1;          // ture
			}
    	    break;
        }
    }
    return 0;
}










