/*********************************************************************
* 版权所有 (C)
* 系统名称: 
* 文件名称: 
* 内容摘要: 
* 当前版本: 
* 作    者: 
* 设计日期: 
* 修改记录: 
* 日    期			版    本		修改人 		修改摘要  
**********************************************************************/

#ifndef VC_BASIC_OP_H
#define VC_BASIC_OP_H
/*___________________________________________________________________________
 |                                                                           |
 |   Constants and Globals                                                   |
 |                                                                           |
 |   $Id $
 |___________________________________________________________________________|
*/
#include "../Include/ecld_typedefs.h"

#define MAX_32 (Word32)0x7fffffffL
#define MIN_32 (Word32)0x80000000L

#define MAX_16 (Word16)+32767	/* 0x7fff */
#define MIN_16 (Word16)-32768	/* 0x8000 */

/*___________________________________________________________________________
 |                                                                           |
 |   Prototypes for basic arithmetic operators                               |
 |___________________________________________________________________________|
*/

/*___________________________________________________________________________
 |                                                                           |
 |   Prototypes for basic arithmetic operators                               |
 |___________________________________________________________________________|
*/
Word16 ECLD_saturate (Word32 L_var1);
Word16 ECLD_add (Word16 var1, Word16 var2);    /* Short ECLD_add,           1   */
Word16 ECLD_sub (Word16 var1, Word16 var2);    /* Short ECLD_sub,           1   */
Word16 ECLD_abs_s (Word16 var1);               /* Short abs,           1   */
Word16 ECLD_shl (Word16 var1, Word16 var2);    /* Short shift left,    1   */
Word16 ECLD_shr (Word16 var1, Word16 var2);    /* Short shift right,   1   */
Word16 ECLD_mult (Word16 var1, Word16 var2);   /* Short ECLD_mult,          1   */
Word32 ECLD_L_mult (Word16 var1, Word16 var2); /* Long ECLD_mult,           1   */
Word16 ECLD_negate (Word16 var1);              /* Short ECLD_negate,        1   */
Word16 ECLD_extract_h (Word32 L_var1);         /* Extract high,        1   */
Word16 ECLD_extract_l (Word32 L_var1);         /* Extract low,         1   */
Word16 ECLD_round (Word32 L_var1);             /* Round,               1   */
Word32 ECLD_L_mac (Word32 L_var3, Word16 var1, Word16 var2);   /* Mac,  1  */
Word32 ECLD_L_msu (Word32 L_var3, Word16 var1, Word16 var2);   /* Msu,  1  */
//Word32 L_macNs (Word32 L_var3, Word16 var1, Word16 var2); /* Mac without
 //                                                            sat, 1   */
//Word32 L_msuNs (Word32 L_var3, Word16 var1, Word16 var2); /* Msu without
//                                                             sat, 1   */
Word32 ECLD_L_add (Word32 L_var1, Word32 L_var2);    /* Long ECLD_add,        2 */
Word32 ECLD_L_sub (Word32 L_var1, Word32 L_var2);    /* Long ECLD_sub,        2 */
//Word32 L_add_c (Word32 L_var1, Word32 L_var2);  /* Long ECLD_add with c, 2 */
//Word32 L_sub_c (Word32 L_var1, Word32 L_var2);  /* Long ECLD_sub with c, 2 */
Word32 ECLD_L_negate (Word32 L_var1);                /* Long ECLD_negate,     2 */
Word16 ECLD_mult_r (Word16 var1, Word16 var2);       /* Mult with ECLD_round, 2 */
Word32 ECLD_L_shl (Word32 L_var1, Word16 var2);      /* Long shift left, 2 */
Word32 ECLD_L_shr (Word32 L_var1, Word16 var2);      /* Long shift right, 2*/
//Word16 shr_r (Word16 var1, Word16 var2);        /* Shift right with
//                                                  ECLD_round, 2           */
//Word16 mac_r (Word32 L_var3, Word16 var1, Word16 var2); /* Mac with
//                                                           rounding,2 */
//Word16 msu_r (Word32 L_var3, Word16 var1, Word16 var2); /* Msu with
//                                                           rounding,2 */
Word32 ECLD_L_deposit_h (Word16 var1);        /* 16 bit var1 -> MSB,     2 */
Word32 ECLD_L_deposit_l (Word16 var1);        /* 16 bit var1 -> LSB,     2 */

Word32 ECLD_L_shr_r (Word32 L_var1, Word16 var2); /* Long shift right with
                                                ECLD_round,  3             */
Word32 ECLD_L_abs (Word32 L_var1);            /* Long abs,              3  */
//Word32 L_sat (Word32 L_var1);          /* Long saturation,       4  */
Word16 ECLD_norm_s (Word16 var1);             /* Short norm,           15  */
Word16 ECLD_div_s (Word16 var1, Word16 var2); /* Short division,       18  */
Word16 ECLD_norm_l (Word32 L_var1);           /* Long norm,            30  */   

//Word32 Div_32(Word32 L_num, Word32 L_denom);

/* 两个Q31相乘,结果是Q31 */
Word32 ECLD_L_mult32(Word32 L_var1, Word32 L_var2);

/* Q31乘与Q15,结果是Q31 */
Word32 ECLD_Mpy_32_16(Word32 L_var, Word16 n);

/* 计算x^(0.5),输入输出都是Q31 */
Word32 ECLD_L_squarent(Word32 L_x);

/* 计算 L_var1/ L_var2,输入输出都是Q31 */
Word32 ECLD_L_div32(Word32 L_var1, Word32 L_var2);

#endif

