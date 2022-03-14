/*
 * DspEftCfg.h
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

#ifndef DSPEFTCFG_H_
#define DSPEFTCFG_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
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

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void DspEftReg_update    (DspEffect_t *pDspEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize);
void DspEftReg_update_all(DspEffect_t *pDspEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst);

#endif /* DSPEFTCFG_H_ */
