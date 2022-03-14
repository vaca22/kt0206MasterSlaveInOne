/*********************************************************************
* 版权所有 (C)
* 系统名称: 
* 文件名称: ecld_const_table.h
* 内容摘要: 常量表声明
* 当前版本: V2.B0
* 作    者: 
* 设计日期: 
* 修改记录: 
* 日    期			版    本		修改人 		修改摘要  
**********************************************************************/

#ifndef ECLD_CONST_TABLE_H
#define ECLD_CONST_TABLE_H

#include "../Include/ecld_typedefs.h"
#include "../Include/ecld_const.h"

/*************************  回声抵消部分  **************************/
extern const Word16 EC_SQRT_L_TABLE[49];
extern const Word16 EC_RANDPHASE[16];
extern const Word16 EEC_b[ECLD_Ana_len*ECLD_M];
extern const Word16 EEC_CONST_PHS_TABLE[];
extern const Word16 EEC_CONST_II_TABLE[];
extern const Word16 EEC_CONST_II_TABLE_16K[];
extern const Word16 EEC_CONST_PHS_TABLE_16K[];
extern const Word16 EC_d2_r[ECLD_M];
extern const Word16 EC_d2_i[ECLD_M];
extern const Word16 EC_d2_r_16K[ECLD_M_16K];
extern const Word16 EC_d2_i_16K[ECLD_M_16K];
extern const Word16 EEC_b_16K[ECLD_Ana_len*ECLD_M_16K];

/*************************  噪声抑制部分  **************************/
extern const Word16 WVQE_CONST_TABLE_POW2[];
extern const Word16 WVQE_CONST_TABLE_HYPERGEOM_GAIN[];

extern const Word16 WVQE_CONST_TABLE_FFT_COEF_8K[];
extern const Word16 WVQE_CONST_TABLE_FFT_COEF_Rearrange_8K[];
//extern const Word16 WVQE_CONST_TABLE_PHASE_INDEX_8K[];
extern const Word16 WVQE_CONST_TABLE_WIN_8k[];
extern const Word32 WVQE_CONST_TABLE_BANK_LEFT_8K[];
extern const Word16 WVQE_CONST_TABLE_FILTER_LEFT_8K[];
extern const Word32 WVQE_CONST_TABLE_BANK_RIGHT_8K[];
extern const Word16 WVQE_CONST_TABLE_FILTER_RIGHT_8K[];

extern const Word16 WVQE_CONST_TABLE_FFT_COEF_16K[];
extern const Word16 WVQE_CONST_TABLE_FFT_COEF_Rearrange_16K[];
//extern const Word16 WVQE_CONST_TABLE_PHASE_INDEX_16K[];
extern const Word16 WVQE_CONST_TABLE_WIN_16k[];
extern const Word32 WVQE_CONST_TABLE_BANK_LEFT_16K[];
extern const Word16 WVQE_CONST_TABLE_FILTER_LEFT_16K[];
extern const Word32 WVQE_CONST_TABLE_BANK_RIGHT_16K[];
extern const Word16 WVQE_CONST_TABLE_FILTER_RIGHT_16K[];

extern const UWord8 u8BitRTab[];

extern const Word32 EC_NOISE_LEVEL_TABLE[];

#endif
