#include "hal_config.h"
#include "bll_config.h"

void SupportUsbKeyboard_Set(uint8_t u8cValue)
{
    g_pstConfig->FuncCfg.SupportUsbKeyboard = u8cValue;
}

void UsbMicCfg_Set(uint8_t ucUsbMicChannel, uint8_t ucUsbMicAudioInSel, uint8_t ucUsbMicI2sCfg)
{
    g_pstConfig->FuncCfg.DongleUsbInChannel = ucUsbMicChannel;
    g_pstConfig->FuncCfg.DongleAudioInSel = ucUsbMicAudioInSel;
    g_pstConfig->FuncCfg.DongleUsbInCfg = ucUsbMicI2sCfg;
}
