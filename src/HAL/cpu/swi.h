#ifndef _SWI_H_
#define _SWI_H_

#include <nds32_intrinsic.h>
#include <stdint.h>





inline void Gen_SWI(void);

inline void Clear_SWI(void);

extern void SWI_ISR(uint32_t id);

#endif


