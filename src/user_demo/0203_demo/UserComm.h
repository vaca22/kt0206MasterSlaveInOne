#ifndef __COMM_H__
#define __COMM_H__


#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>
#include <nds32_intrinsic.h>
#include <nds32_utils_math.h>

#define BIT0 (0x01ul)
#define BIT1 (0x02ul)
#define BIT2 (0x04ul)
#define BIT3 (0x08ul)
#define BIT4 (0x10ul)
#define BIT5 (0x20ul)
#define BIT6 (0x40ul)
#define BIT7 (0x80ul)

#define BIT8  (0x0100ul)
#define BIT9  (0x0200ul)
#define BIT10 (0x0400ul)
#define BIT11 (0x0800ul)
#define BIT12 (0x1000ul)
#define BIT13 (0x2000ul)
#define BIT14 (0x4000ul)
#define BIT15 (0x8000ul)

#define BIT16 (0x010000ul)
#define BIT17 (0x020000ul)
#define BIT18 (0x040000ul)
#define BIT19 (0x080000ul)
#define BIT20 (0x100000ul)
#define BIT21 (0x200000ul)
#define BIT22 (0x400000ul)
#define BIT23 (0x800000ul)

#define BIT24 (0x01000000ul)
#define BIT25 (0x02000000ul)
#define BIT26 (0x04000000ul)
#define BIT27 (0x08000000ul)
#define BIT28 (0x10000000ul)
#define BIT29 (0x20000000ul)
#define BIT30 (0x40000000ul)
#define BIT31 (0x80000000ul)

extern void Delay_Us(uint16_t Nus);
extern void Delay_Ms(uint16_t Nms);

#ifdef  __cplusplus
}
#endif

#endif

