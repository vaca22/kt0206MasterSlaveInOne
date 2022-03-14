/*
 * patch_main.h
 *
 *  Created on: Jul 10, 2018
 *      Author: chenbowen
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "com_includes.h"
#include "hal_includes.h"
#include "fml_includes.h"
#include "bll_includes.h"
#include "user.h"

typedef struct
{
	void (*h_patch_init)(void);
	void (*h_plf_schedule)(void);
	void (*h_plf_init)(void);
    void (*h_plf_uninit)(void);
    void (*EnterExit_Standby)(void);
}main_ftable_t;

int main_flash(void);

#endif /* MAIN_H_ */
