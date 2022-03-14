#include "api.h"


#define  FLASH_ADDR  	0x3E000   //(0xBE000-0x80000), flash start address = 0x80000.
#define  FLASH_LENGTH	0x1000    //4KB(0xBE000~0xBEFFF) not used by system
#define  FLASH_ADDR1  	0x64000  //(0xE4000-0x80000), flash start address = 0x80000.
#define  FLASH_LENGTH1	0x1C000  //112KB(0xE4000~0xFFFFF) not used by system

/**
 * @param pBuf ::Flash address, Must be 4K aligned
 * @param byteNum :Num byte write to flash. Must be a multiple of 4.
 **/
void writeFlash(uint8_t * pBuf, uint32_t byteNum)
{
	int8_t ret = 0;

	if (byteNum % 4 != 0)
	{
		USER_DBG_OUT("Erase flash failed! The byteNum must be a multiple of 4.!!!");
		goto RET;
		
	}
	GLOBAL_INT_STOP();
	ret = api_flash_sector_erase(FLASH_ADDR, byteNum); //Erase 4k at a time, start addr must be 4K aligned. please backup data in sector in which your operating address is located.
	if (ret != API_OK) { goto RET_ERR_ERASE; }
	ret = api_flash_param_save(FLASH_ADDR, pBuf, byteNum);
	if (ret != API_OK) { goto RET_ERR_SAVE; }
	GLOBAL_INT_START();
	// USER_DBG_OUT("Write flash OK! Addr 0x%X, Num %d\n", pBuf, byteNum);
	goto RET;

RET_ERR_ERASE:
	GLOBAL_INT_START();
	USER_DBG_OUT("Erase flash failed, ret = %d\n", ret);
	goto RET;

RET_ERR_SAVE:
	GLOBAL_INT_START();
	USER_DBG_OUT("Save flash failed, ret = %d\n", ret);
	goto RET;

RET:
	return;
}

/**
 * @param pBuf :Flash address.
 * @param byteNum :Num byte read from flash.
 **/
void readFlash(uint8_t * pBuf, uint32_t byteNum)
{
	int8_t ret = 0;

	if (byteNum % 4 != 0)
	{
		USER_DBG_OUT("Read flash failed! The byteNum must be a multiple of 4.!!!");
		goto RET;
	}
	 // ret = api_flash_param_read(FLASH_ADDR, pBuf, byteNum);
	ret = api_flash_param_read_NoCache(FLASH_ADDR, pBuf, byteNum); // read real data from flash hardware.
	if (ret != API_OK) { goto RET_ERR; }
	// USER_DBG_OUT("Read flash OK! Addr 0x%X, Num %d\n", pBuf, byteNum);
	goto RET;

RET_ERR:
	GLOBAL_INT_START();
	USER_DBG_OUT("Read flash failed, ret = %d\n", ret);
	goto RET;

RET:
	return;
}
void displayTime(void)
{
	USER_DBG_OUT("time: %ld ms\n", timer_tick_ms_get());

	uint8_t time = timer_tick_ms_get() / 1000;
	uint8_t buf[4] = {0};
	USER_DBG_OUT("==init read 0x%X 0x%X 0x%X 0x%X\n", buf[0], buf[1], buf[2], buf[3]);
	buf[0] = time;
	buf[1] = ++time;
	buf[2] = ++time;
	buf[3] = ++time;
	USER_DBG_OUT("==save 0x%X 0x%X 0x%X 0x%X\n", buf[0], buf[1], buf[2], buf[3]);
	writeFlash(buf, 4);
	readFlash(buf, 4);
	USER_DBG_OUT("==read 0x%X 0x%X 0x%X 0x%X\n", buf[0], buf[1], buf[2], buf[3]);
}
/**************************print:
==init read 0x0 0x0 0x0 0x0
==save 0x1 0x2 0x3 0x4
==read 0x1 0x2 0x3 0x4
time: 2000 ms
==init read 0x0 0x0 0x0 0x0
==save 0x2 0x3 0x4 0x5
==read 0x2 0x3 0x4 0x5
usb reset! connecting to a usb host.
time: 3636 ms
==init read 0x0 0x0 0x0 0x0
==save 0x3 0x4 0x5 0x6
==read 0x3 0x4 0x5 0x6
time: 4000 ms
==init read 0x0 0x0 0x0 0x0
==save 0x4 0x5 0x6 0x7
==read 0x4 0x5 0x6 0x7
*/