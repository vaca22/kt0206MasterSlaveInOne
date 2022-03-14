/*
 * power_ctrl.c
 *
 *  Created on: Apr 13, 2018
 *      Author: chenbowen
 */

#include "power_ctrl.h"

typedef struct ftable_stru
{
	void (*PFT_mode)(uint8_t ucLevel);
}ftable_t;

ftable_t *power_ctrl_ftable;

/* ucLevel: 0~15 */
void PFT_mode(uint8_t ucLevel)
{
	power_ctrl_ftable->PFT_mode(ucLevel);
}

extern void rom_PFT_mode(uint8_t ucLevel);

void PwrBrk_enable(uint8_t ucLevel)
{
	uint32_t uTmp;

	/* get value of MSC_CFG register */
	uTmp = __nds32__mfsr(NDS32_SR_MSC_CFG);

	if (0x1 == ((uTmp >> 26) & 0x1))
	{
		/* get value of PSW register */
		uTmp = __nds32__mfsr(NDS32_SR_PSW);

		/* set PFT_EN to 1 */
		uTmp = uTmp | (0x1 << 21);

		/* set value to PSW register */
		__nds32__mtsr(uTmp, NDS32_SR_PSW);

		/* get value of PFT_CTL register */
		uTmp = __nds32__mfsr(__NDS32_REG_PFT_CTL__);

		/* set T_LEVEL to target value and set FAST_INT to 1 */
		uTmp = uTmp | (ucLevel << 4) | (0x1 << 8);
		
		/* set value to PFT_CTL register */
		__nds32__mtsr(uTmp, __NDS32_REG_PFT_CTL__);
	}
}

void PwrBrk_disable(void)
{
	uint32_t uTmp;

	/* get value of PSW register */
	uTmp = __nds32__mfsr(NDS32_SR_PSW);

	/* set PFT_EN to 0 */
	uTmp = uTmp & ~(0x1<<21);

	/* set value to PSW register */
	__nds32__mtsr(uTmp, NDS32_SR_PSW);
}

const ftable_t rom_power_ctrl_fi_table = 
{
	.PFT_mode = rom_PFT_mode,
};

void power_ctrl_patch_init(void)
{
	power_ctrl_ftable = (ftable_t *)&rom_power_ctrl_fi_table;
}
