/*
 * DongleEftCfg.h
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

#ifndef DONGLEEFTCFG_H_
#define DONGLEEFTCFG_H_


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "reg_eft.h"
#include "DongleEffect_top.h"
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
void DongleEftReg_update_all(DongleEffect_t *pDongleEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst);
void DongleEftReg_update    (DongleEffect_t *pDongleEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize);
#endif /* DONGLEEFTCFG_H_ */
