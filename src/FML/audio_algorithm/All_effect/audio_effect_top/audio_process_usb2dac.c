

#include "nds32_includes.h"
#include "audio_process_usb2dac.h"


typedef struct process_usb2dac_ftable_stru
{
    void (*AudioProcessDac)   (q31_t *, q31_t *, q31_t *, q31_t *, uint32_t);
    void (*SideToneMixer)   (q31_t *, q31_t *, q31_t *, q31_t *, uint32_t );
    void (*LoopBackMux)   (q31_t *, q31_t *, uint32_t);
    void (*AudioDacRailCtrl)   (q31_t *, q31_t *, q31_t *, uint32_t);
} process_usb2dac_ftable_t;

extern process_usb2dac_ftable_t *pprocess_usb2dac_ftabl;


void new_patch_audio_process_dac (q31_t *pAudioInL, q31_t *pAudioInR, q31_t *pAudioOutL, q31_t *pAudioOutR, uint32_t len)
{
	nds32_dup_q31(pAudioInL, pAudioOutL, len);
	nds32_dup_q31(pAudioInR, pAudioOutR, len);
	return;
}

//side tone mxier to dac
void new_patch_side_tone_mixer(q31_t *pAudioInL, q31_t *pAudioInR, q31_t *pAudioOutL, q31_t *pAudioOutR, uint32_t len)
{
	nds32_dup_q31(pAudioInL, pAudioOutL, len);
	nds32_dup_q31(pAudioInR, pAudioOutR, len);
	return;
}

void new_patch_loop_back_mux(
    q31_t *pFromUsbL,
    q31_t *pFromUsbR,
    uint32_t len)
{
	return;
}
const process_usb2dac_ftable_t new_process_usb2dac_patch_ftable =
{
    .AudioProcessDac          = new_patch_audio_process_dac,
    .SideToneMixer            = new_patch_side_tone_mixer,
    .LoopBackMux              = new_patch_loop_back_mux,
    .AudioDacRailCtrl         = new_patch_audio_dac_rail_ctrl,

};

void new_process_usb2dac_patch_init(void)
{
    pprocess_usb2dac_ftabl = (process_usb2dac_ftable_t *)&new_process_usb2dac_patch_ftable;
}
