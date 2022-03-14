/*
 * chipEftCfg.h
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

#ifndef CHIPEFTCFG_H_
#define CHIPEFTCFG_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "ChipEffect_top.h"
#include "reg_eft.h"
/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern ChipEffect_t *g_st_pHeadsetEft;
/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void ChipEftReg_update_all(ChipEffect_t *pHeadsetEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst);
void ChipEftReg_update(ChipEffect_t *pHeadsetEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize);
#endif /* HEADSETEFTCFG_H_ */
