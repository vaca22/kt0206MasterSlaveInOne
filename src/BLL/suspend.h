/*
 * suspend.h
 *
 */

#ifndef _SUSPEND_H_
#define _SUSPEND_H_

extern void Suspend_Init(void);
extern void Suspend_Uninit(void);
extern void Suspend_patch_init(void);
extern void Sys_Suspend(void);
extern void Sys_Resume(void);
void TypeC_to_3p5_Resume(void);
void TypeC_to_3p5_Suspend(void);
extern void new_Suspend_patch_init(void);

#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
extern void Patch_Sys_Suspend_for_AEVKWP(void);
extern void Patch_Sys_Resume_for_AEVKWP(void);
#endif

#endif
