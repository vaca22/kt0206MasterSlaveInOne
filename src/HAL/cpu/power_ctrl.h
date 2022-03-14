/*
 * power_ctrl.h
 *
 *  Created on: Apr 13, 2018
 *      Author: chenbowen
 */

#ifndef POWER_CTRL_H_
#define POWER_CTRL_H_

#include "comm.h"

extern void PFT_mode(uint8_t ucLevel);
extern void power_ctrl_patch_init(void);

extern void PwrBrk_enable(uint8_t ucLevel);
extern void PwrBrk_disable(void);

#endif /* POWER_CTRL_H_ */
