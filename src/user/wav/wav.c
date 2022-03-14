#include "wav.h"
#include "nds32_utils_math.h"

#if(WAV_EN)
extern const uint16_t volume_table[128];
extern uint8_t dsp_usb2dac_vol_l;//   = 103;
extern uint8_t dsp_usb2dac_vol_r;//   = 103;

wavStruc_t wavInfo={0};

const wavFileStruct myWavFiles[]=
{
    [0] = { &WAV_start0 , &WAV_size0},
    [1] = { &WAV_start1 , &WAV_size1},
    [2] = { &WAV_start2 , &WAV_size2},
    [3] = { &WAV_start3 , &WAV_size3},
    [4] = { &WAV_start4 , &WAV_size4},
    [5] = { &WAV_start5 , &WAV_size5},
    //[6] = { &WAV_start6 , &WAV_size6},
    // [7] = { &WAV_start7 , &WAV_size7},
    // [8] = { &WAV_start8 , &WAV_size8},
    // [9] = { &WAV_start9 , &WAV_size9},
    // [10] = { &WAV_start10 , &WAV_size10},
    [11] = { &WAV_start11 , &WAV_size11},
    [12] = { &WAV_start12 , &WAV_size12},
    [13] = { &WAV_start13 , &WAV_size13},
    //[14] = { &WAV_start14 , &WAV_size14},
    [15] = { &WAV_start15 , &WAV_size15},
    [16] = { &WAV_start16 , &WAV_size16},
};

#define WAV_HEAD_SIZE 44
void wavPlayerStart(wavFileNameEnum wavFileName)//0:ktv模式 1:男变女 2:女变男 3:娃娃音
{
    wavInfo.playFileStartAddr=myWavFiles[wavFileName].pWavFileAddr+0x100;//前面的信息没用
    wavInfo.AddrMaxOffset=(uint32_t )(myWavFiles[wavFileName].WavFileLength)-0x200;//后面的没用
    wavInfo.currentAddrOffset=0;
    wavInfo.counter=0;
    wavInfo.playFlag=1;
}

void wavPlayer(int32_t *pDataLOut, int32_t *pDataROut, uint32_t Len, uint16_t *volLeft, uint16_t *volRight)
{
    if (wavInfo.playFlag == 1)
    {
        if (wavInfo.currentAddrOffset < wavInfo.AddrMaxOffset)
        {
            uint32_t i = 0;
            uint32_t tmpLen = Len / WAV_DATA_MULT;
            int32_t wavDataDelta = 0;
            int8_t j = 0;
            uint8_t k = 0;

            const int16_t *ptemp = (const int16_t *)wavInfo.playFileStartAddr;
            for (i = 0; i < tmpLen; i++)
            {
                k = i * WAV_DATA_MULT;
                //add a D-value to avoid "sha sha" sound
                wavDataDelta = (*(ptemp + wavInfo.counter + 1) - *(ptemp + wavInfo.counter)) / ((int8_t)WAV_DATA_MULT);

                for(j = 0; j < WAV_DATA_MULT; j++)
                {
                    *(pDataLOut + k + j) = *(ptemp + wavInfo.counter) + (wavDataDelta * j);
                    *(pDataLOut + k + j) <<= 8;
                }    
                wavInfo.counter++;
            }
            nds32_dup_q31(pDataLOut, pDataROut, Len);
            wavInfo.currentAddrOffset = (wavInfo.counter << 1);//16bit, need to x2
        }
        else
        {
            wavInfo.playFlag = 0;
            wavInfo.currentAddrOffset = 0x100;
        }

#if (WAV_USB2DAC_VOL_MOD == WAV_USB2DAC_VOL_DEC)
        if(dsp_usb2dac_vol_l > (WAV_USB2DAC_VOL_DEC + WAV_USB2DAC_VOL_MIN)){
		    *volLeft  = volume_table[dsp_usb2dac_vol_l - WAV_USB2DAC_VOL_DEC];
        }else if(dsp_usb2dac_vol_l == 0){
		    *volLeft  = volume_table[0];
        }else{
		    *volLeft  = volume_table[WAV_USB2DAC_VOL_MIN];
        }
#elif (WAV_USB2DAC_VOL_MOD == WAV_USB2DAC_VOL_FIXED)
		*volLeft  = volume_table[WAV_USB2DAC_VOL_FIXED];
#endif
		*volRight = *volLeft;
    }
}

#else
void wavPlayerStart(wavFileNameEnum wavFileName){};
void wavPlayer(int32_t *pDataLOut, int32_t *pDataROut, uint32_t Len, uint16_t *volLeft, uint16_t *volRight){};
#endif
