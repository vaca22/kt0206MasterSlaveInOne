/*
 * patch.h
 *
 *  Created on: Jul 12, 2018
 *      Author: chenbowen
 */

#ifndef PATCH_H_
#define PATCH_H_

#include "patch_main.h"

typedef struct
{
	void (*User_C_Init)(void);
    void (*User_Init)(void);
    void (*User_Schedule)(void);
    uint32_t MagicKey;
}api_ftable_t;


extern const api_ftable_t stApiFunctionTableDft;
extern api_ftable_t *pAFI; //pApiFunctionInterface

extern void patch_Get_Sys_Status(void);
extern void patch___null_function(void);
extern void patch_cinit(void);

#endif /* PATCH_H_ */
