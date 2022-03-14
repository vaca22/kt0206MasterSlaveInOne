#include "uswi_asrc.h"
#include "api.h"
#include "asrc_dac_fs_ppm_pack.h"

// 在USB-I2S_OUT Asrc和I2S_IN-DAC Asrc之间切换使用

extern int32_t USB_ADC_FS;
extern uint8_t g_ppm_range;
extern int32_t DAC_STEREO_MODE;
extern uint8_t dsp_adc2dac_vol;
extern uint8_t AUDIO_IN_I2SSEL;
extern uint8_t AUDIO_OUT_I2SSEL;
uint8_t swiI2SIn2DACFlag = 0;
int32_t g_I2SIn2DacBuf[96] = {0};

static uint32_t packAsrcComStartAddr = 0;
static uint32_t packAsrcComEndAddr = 0;

AsrcIn_t g_st_AsrcI2SIN2Dac = {
	.En = 1,
};

void getAsrcComStartAddr(uint32_t addr)
{
    packAsrcComStartAddr = addr;
}

uint32_t setAsrcComEndAddr(uint32_t addr)
{
    packAsrcComEndAddr = ((addr - packAsrcComStartAddr) > (20 * 1024))? \
        addr : (packAsrcComStartAddr + 20 * 1024);

    return packAsrcComEndAddr;
}


void swiPackAsrc(uint8_t UsbOutStatus)
{
	if(AUDIO_OUT_I2SSEL!=3){
		return;
	}
    static uint8_t preUsbOutStatus = 0;
    
    if (preUsbOutStatus != UsbOutStatus) {
        preUsbOutStatus = UsbOutStatus;

        GLOBAL_INT_STOP();
        nds32_set_q7(0, (int8_t *)packAsrcComStartAddr, \
            packAsrcComEndAddr - packAsrcComStartAddr);
        if (UsbOutStatus) {
            dsp_adc2dac_vol = 0;
            nds32_set_q7(0, (int8_t *)&g_st_AsrcI2S, sizeof(g_st_AsrcI2S));
            g_st_AsrcI2S.En = 1;
            Pack_Asrc_Out_Init(&g_st_AsrcI2S, packAsrcComStartAddr, g_ppm_range, DAC_STEREO_MODE);
        } else {
            dsp_adc2dac_vol = 103;
            nds32_set_q7(0, (int8_t *)&g_st_AsrcI2SIN2Dac, sizeof(g_st_AsrcI2SIN2Dac));
            g_st_AsrcI2SIN2Dac.En = 1;
            Pack_Asrc_In_Init(&g_st_AsrcI2SIN2Dac, packAsrcComStartAddr, 1, g_ppm_range, USB_ADC_FS);
        }
        GLOBAL_INT_START();
    }
}

