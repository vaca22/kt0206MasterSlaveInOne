#ifndef __MSGQ_H__
#define __MSGQ_H__

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "nds32_includes.h"
#include <stdbool.h>
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

typedef union {
	struct {
		uint32_t Param		: 24;
		uint8_t  Message	: 8;
	};
	uint32_t	all;
}MSG_t;
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */

bool PostMessage(MSG_t m);
void SendMessage(MSG_t m);//forbidden use in Audio interrupt, don't open to user
MSG_t GetMessage(void);

#endif /* MSGQ_H_ */
