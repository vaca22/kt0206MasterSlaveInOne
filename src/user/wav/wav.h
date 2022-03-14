#ifndef _WAV_H_
#define _WAV_H_
#include "stdint.h"
#include "wav_linker.h"

#define WAV_USB2DAC_VOL_DISABLE     0//wav volume == main volume
#define WAV_USB2DAC_VOL_FIXED   (63U)//wav volume fixed
#define WAV_USB2DAC_VOL_DEC     (27U)//wav volume decrement and follow main volume
#define WAV_USB2DAC_VOL_MOD  WAV_USB2DAC_VOL_FIXED
#define WAV_USB2DAC_VOL_MIN     (10U)//wav min volume except mute

typedef struct
{
    uint8_t playFlag;
    const uint8_t* playFileStartAddr;
    uint32_t currentAddrOffset;
    uint32_t AddrMaxOffset;
    uint32_t counter;
}wavStruc_t;

typedef enum 
{
    RAWMODE = 0,//原声
    KTVMODE,//ktv mode
    NANBIANNV,//男变女
    NVBIANNAN,//女变男
    LUOLIYIN,//萝莉音
    MOSHOUYIN,//魔兽音
    //KGEMOSHI,
    OUT_STEREO = 11,
    OUT_MEGABASS,
    OUT_SURROUND,
    OUT_3DMOVE,
    OUT_CHIJI,
    OUT_WANGZHE,
}wavFileNameEnum;

typedef struct
{
    uint8_t* pWavFileAddr;
    uint8_t* WavFileLength;
}wavFileStruct;

#if(WAV_EN)
extern wavStruc_t wavInfo;
extern const wavFileStruct myWavFiles[];
#endif

void wavPlayer(int32_t *pDataLOut, int32_t *pDataROut, uint32_t Len, uint16_t *volLeft, uint16_t *volRight);
void wavPlayerStart(wavFileNameEnum wavFileName);

#endif
