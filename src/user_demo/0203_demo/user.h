/*
 * user.h
 *
 */

#ifndef _USER_H_
#define _USER_H_

#define dbg        // 定义串口打印信息

#ifdef 	dbg
	#define DBG(...)	printf(__VA_ARGS__)
#else
	#define DBG(...)
#endif


extern void _user_schedule(void);
extern void _user_init(void);

#endif 
