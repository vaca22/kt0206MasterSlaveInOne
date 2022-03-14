/*
 * MsgQ.c
 *
 *  Created on: 2020-04-24
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "MsgQ.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
//#define UART_DBG
#ifdef UART_DBG
#include <stdio.h>
#endif

#define MsgQ_SIZE 64	//must exp of 2
#define ATOMIC_BEGIN(var, atom_var)									\
{																	\
	do {															\
		atom_var = __nds32__llw((unsigned int *)(&var));

//atomic opteration

#define ATOMIC_END(var, atom_var)									\
	} while(0 == __nds32__scw((unsigned int *)(&var), atom_var));	\
}
/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */
MSG_t MsgQ_Data[MsgQ_SIZE] = {{{ 0 }}};
uint32_t MsgQ_ReadCount = 0;
uint32_t MsgQ_WriteCount = 0;
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
bool PostMessage(MSG_t m) {
#ifdef UART_DBG
	printf("PostMsg:%d, Param:0x%X\n", m.Message, m.Param);
#endif

	if((MsgQ_WriteCount - MsgQ_ReadCount) >= MsgQ_SIZE) {
		return false;
	}

	register uint32_t atomic;
	ATOMIC_BEGIN(MsgQ_WriteCount, atomic)
	atomic++;
	ATOMIC_END(MsgQ_WriteCount, atomic)

	MsgQ_Data[(atomic - 1) & (MsgQ_SIZE - 1)] = m;

	return true;
}
MSG_t GetMessage(void) {
	register MSG_t m = {{ 0 }};
	if(MsgQ_WriteCount <= MsgQ_ReadCount) {
		m.Message = -1;
	} else {
		m = MsgQ_Data[(MsgQ_ReadCount++) & (MsgQ_SIZE - 1)];
	}
#ifdef UART_DBG
	if(m.Message != 0xFF) {
		printf("GetMsg:%d, Param:0x%X\n", m.Message, m.Param);
	}
#endif
	return m;
}

extern void MsgProc(MSG_t m);
void SendMessage(MSG_t m) {
#ifdef UART_DBG
	printf("SendMsg:%d, Param:0x%X\n", m.Message, m.Param);
#endif
//	MsgProc(m);
}
