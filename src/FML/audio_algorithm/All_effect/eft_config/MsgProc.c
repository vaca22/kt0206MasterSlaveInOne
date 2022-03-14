/*
 * MsgProc.c
 *
 *  Created on: 2020-04-24
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "MsgProc.h"
#include "chipEftCfg.h"
#include "chip_config.h"
#include "bll_config.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

/*
 * LOCAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * LOCAL FUNCTION DEFINITIONS
 ****************************************************************************************
 */


/*
 * EXPORTED FUNCTION DEFINITIONS
 ****************************************************************************************
 */

void MsgSchedule(void)
{
    MSG_t m = GetMessage();

    if (m.Message != MSG_None) {
        MsgProc(m);   //MsgProc
    }
}

void MsgProc(MSG_t m)
{
    switch (m.Message) {
    case MSG_DSPRegUpdate : {
//    	ChipEftReg_update(ChipEffect_t *pChipEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize);
        ChipEftReg_update(g_st_pHeadsetEft, &g_pstConfig->DSPRegAll, m.Param, AUDIO_SAMPLE_BLOCK_SIZE);      

    }
    break;
    case MSG_EffectCloseDone : {
//        DSP_EffectCloseDone(m.Param);
    }

    default : {
        ;
    }
    break;
    }
}
