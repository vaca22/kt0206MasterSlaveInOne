/*
 * MsgProc.h
 *
 *  Created on: 2020-04-24
 *      Author: guoax
 */

#ifndef MSGPROC_H_
#define MSGPROC_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "MsgQ.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * ENUM DEFINES
 ****************************************************************************************
 */
typedef enum {

    MSG_DSPRegUpdate            = 0,
    MSG_EffectCloseDone         = 1,


    MSG_None                    = 0xFF,
} MSG_enum;
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
void MsgProc(MSG_t m);
void MsgSchedule(void);
#endif /* EMPTY_H_ */
