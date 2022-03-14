/*
 * i2s_nco_readbuf.h
 *
 *  Created on: Jun 27, 2018
 *      Author: wangshengli
 */

#ifndef I2S_NCO_READBUF_H_
#define I2S_NCO_READBUF_H_

#include "comm.h"

void i2s_nco_readbuf(
		int32_t *pOutLeftUsb,
		int32_t *pOutRightUsb,
		int32_t USB_ADC_PCM_NUM	);
void nco_patch_init(void);
#endif /* I2S_NCO_READBUF_H_ */
