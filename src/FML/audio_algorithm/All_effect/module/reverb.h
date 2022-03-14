/*
guoaixiang
2019.5.17

*/


#ifndef REVERB_H
#define REVERB_H
#include "nds32_math_types.h"
#include "effect_config.h"
#define FDNORDER 4

typedef enum ReverbMaxBuffLen_enum {

	FDNDELS_0_MAX		 = 0,
	FDNDELS_1_MAX		 = FDNDELS_0_MAX + 1,
	FDNDELS_2_MAX		 = FDNDELS_1_MAX + 1,
	FDNDELS_3_MAX		 = FDNDELS_2_MAX + 1,

	TAPDELAY_0_MAX       = FDNDELS_3_MAX + 1,
	TAPDELAY_1_MAX       = TAPDELAY_0_MAX + 1,
	TAPDELAY_2_MAX       = TAPDELAY_1_MAX + 1,
	TAPDELAY_3_MAX       = TAPDELAY_2_MAX + 1,

	LDIFS_0_MAX          = TAPDELAY_3_MAX + 1,
	LDIFS_1_MAX          = LDIFS_0_MAX + 1,
	LDIFS_2_MAX          = LDIFS_1_MAX + 1,
	LDIFS_3_MAX          = LDIFS_2_MAX + 1,

	RDIFS_0_MAX          = LDIFS_3_MAX + 1,
	RDIFS_1_MAX          = RDIFS_0_MAX + 1,
	RDIFS_2_MAX          = RDIFS_1_MAX + 1,
	RDIFS_3_MAX          = RDIFS_2_MAX + 1,

	TAPDELAY_MAX         = RDIFS_3_MAX + 1,
	REVERB_BUFF_SUM      = TAPDELAY_MAX + 1,
	REVERB_ARRAY         = REVERB_BUFF_SUM + 1
}ReverbMaxBuffLen_t;

extern const uint32_t g_const_reverb_buff_len[REVERB_ARRAY];
typedef struct {
	float roomsize;
	float revtime;
	float spread;
	float TailLevel;
	float EarlyLevel;
	float LpfBw;
	float HpfBw;
	float Damping;
	float RoomMax;
	float SprdMax;
	uint32_t Fs_Hz;
	uint8_t LpfEn;
	uint8_t HpfEn;
	uint8_t HpfOld;
	uint8_t En;
}ReverbPara_t;

typedef struct {
	int16_t *buf;
	int32_t gain;
	int32_t gain_new;
	int64_t gain_olabuf;
	uint16_t delay;
	uint16_t delay_new;
	uint16_t idx;
} ReverbDelayGain_t;

typedef struct {
	int16_t *buf;
	uint16_t delay;
	uint16_t delay_new;
	uint16_t idx;
} ReverbApf_t;

typedef struct {
	int32_t bufout;
	int32_t bufin;
	int16_t damp; //-a1
} ReverbFilt_t;

typedef struct {
	ReverbPara_t      ParaSave   ;
	ReverbDelayGain_t tapdelay[4];
	ReverbDelayGain_t fdndels[4] ;
	ReverbFilt_t      PreLpf     ;
	ReverbFilt_t      PreHpf     ;
	ReverbFilt_t      fdnlpf[4]  ;
	ReverbApf_t       ldifs[4]   ;
	ReverbApf_t       rdifs[4]   ;

	uint32_t          BuffLen[REVERB_ARRAY];
	int32_t           TailFixed  ;
	int32_t           EarlyFixed ;
	int16_t         * pBuff      ;
	int32_t           SrcRampBuf0;
	int16_t           SmoothIndex;
	uint8_t           Ola0       ;
	uint8_t           Ola1       ;
	uint8_t           SmthStart  ;
	uint8_t           gUpdate    ;

} ReverbStru_t;

#if(EFFECT_REVERB_EN)
void Reverb_flt(ReverbStru_t *pInst, int32_t *pSrc, int32_t Len);
void Reverb_fdn(ReverbStru_t *pInst, int32_t *pSrc, int32_t Len);
void Reverb_apf(ReverbStru_t *pInst, int32_t *pSrc, int32_t *yleft, int32_t *yright, int32_t Len);
void Reverb_wet(ReverbStru_t *pInst, int32_t *pSrc, int32_t *yleft, int32_t *yright, int32_t Len);


void Reverb_Room  (float roomsize, uint32_t fs,       uint32_t *BuffLen);
void Reverb_Spread(float spread,   uint32_t fdn_len3, uint32_t *BuffLen);
void Reverb_Time   (float revtime, uint32_t fs,       uint32_t *BuffLen, int32_t *Gain);
void Reverb_new   (ReverbStru_t *pInst, ReverbPara_t *pPara);

uint32_t Reverb_MaxBuff(ReverbStru_t *pInst, ReverbPara_t *pPara);
uint32_t Reverb_init   (ReverbStru_t *pInst, void *pBuff);
//------------------------------------------------
//Patch
//------------------------------------------------
#define REVERB_1_PATCH                          \
const uint16_t * g_const_reverb_buff_len;       \
void (*reverb_new)(void);                       \
void (*reverb_rst)(void);                      \
void (*reverb_tail)(                            \
	ty_reverb *p,                               \
	int32_t *pSrc,                             \
	int32_t Len_div2                           \
);                                             \
void (*reverb_apf)(                             \
	ty_reverb *p,                               \
	int32_t *pSum,                             \
	int32_t *yleft,                            \
	int32_t *yright,                           \
	int32_t reverb_level,                      \
	int32_t Len                                \
);                                             \
void (*reverb_wet)(                             \
	ty_reverb *p,                               \
	int32_t *pSrc,                             \
	int32_t *yl,                               \
	int32_t *yr,                               \
	int32_t reverb_level,                      \
	int32_t Len                                \
);

#define REVERB_1_PATCH_INIT                              \
.g_const_reverb_buff_len    = g_const_reverb_buff_len,    \
.reverb_new                 = reverb_new,                 \
.reverb_rst                = reverb_rst,                \
.reverb_tail                = reverb_tail,                \
.reverb_apf                 = reverb_apf,                 \
.reverb_wet                 = reverb_wet,

#define REVERB_1_PATCH_NUM 6

#endif
#endif
