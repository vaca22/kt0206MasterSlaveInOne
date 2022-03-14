/*
 * KT0203_Drv.c
 *
 *  Created on: Jul 9, 2019
 *      Author: lisy
 */

#include "KT0203_Drv.h"

//extern uint16_t reverb_level_map;

void DSP_Reverb_Set(const DSP_Reverb_Para_t * pPara) {
	pDSP->ReverbCtrl2.all32 = pPara->all32[2];
	pDSP->ReverbCtrl1.all32 = pPara->all32[1];
	register DSP_ReverbCtrl0_t ctrl0;
	ctrl0.all32 = pPara->all32[0] & (~0x3),
	ctrl0.all32 |= pDSP->ReverbCtrl0.all32 & 0x3;
	pDSP->ReverbCtrl0.all32 = ctrl0.all32;

	dsp_reg_update(DSPREG_IDX(ReverbCtrl0));
	dsp_reg_update(DSPREG_IDX(ReverbCtrl1));
	dsp_reg_update(DSPREG_IDX(ReverbCtrl2));
}

void DSP_Reverb_Ctrl(FunctionState_t en) {
	register DSP_ReverbCtrl0_t ctrl0;
	ctrl0.all32 = pDSP->ReverbCtrl0.all32;
	if(en == Enable) {
		if(ctrl0.reverb_en) {
			return;
		}
//		reverb_level_map = 0;
		ctrl0.reverb_en = 1;
	} else {
		if(ctrl0.reverb_en == 0) {
			return;
		}
		ctrl0.reverb_en = 0;
	}
	pDSP->ReverbCtrl0.all32 = ctrl0.all32;
	dsp_reg_update(DSPREG_IDX(ReverbCtrl0));
}

void DSP_Reverb_Level(uint8_t u7level) {
	pDSP->ReverbCtrl1.reverb_level = u7level;
	dsp_reg_update(DSPREG_IDX(ReverbCtrl1));
}

//-------------------------------------------------------------------------
//啸叫抑制
//共分三个部分: 检测部分(HowlingDet)、陷波器控制(HowlingNotch)、压音量控制(HowlingAvc)
//-------------------------------------------------------------------------

void DSP_Howling_Ctrl(const DSP_HowlingCtrl_Para_t * pPara) {
	register split32_t ctrl0;
	ctrl0.uint32 = pDSP->HowlingSprsCtrl0.all32;
	ctrl0.uint8[0] = pPara->para0;
	ctrl0.uint8[3] = pPara->eeprom_save_cycle;
	pDSP->HowlingSprsCtrl0.all32 = ctrl0.uint32;
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl0));
}

void DSP_Howling_ClearReq(void) {
	pDSP->HowlingSprsCtrl0.howling_clear_en = 1;
}

void DSP_Howling_Detect(const DSP_Howling_Detect_Para_t * pPara) {
	pDSP->HowlingSprsCtrl3.all32 = pPara->all32;
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl3));
}

void DSP_Howling_Avc(const DSP_Howling_Avc_Para_t * pPara) {
	pDSP->HowlingSprsCtrl4.all32 = pPara->all32;
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl4));
}

void DSP_Howling_Notch(const DSP_HowlingNotch_Para_t * pPara) {
	pDSP->HowlingSprsCtrl2.all32 = pPara->all32[0];
	register split32_t ctrl1;
	ctrl1.uint32 = pDSP->HowlingSprsCtrl1.all32,
	ctrl1.uint16[0] = pPara->all16[2];
	pDSP->HowlingSprsCtrl1.all32 = ctrl1.uint32;
	pDSP->HowlingSprsCtrl0.howling_notch_n_fixed = pPara->nFixed;
	pDSP->HowlingSprsCtrl0.howling_notch_n_total = pPara->nTotal;
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl2));
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl1));
	dsp_reg_update(DSPREG_IDX(HowlingSprsCtrl0));
}

uint32_t DSP_Howling_NotchGet(void) {
	return (pDSP->Howling_NotchEn_Read);
}
uint32_t DSP_Howling_NotchFixedGet(void) {
	return (pDSP->HowlingStudyNotchFixed);
}


//EQ设置
void DSP_EQ_Set(const DSP_EQ_Para_t * pPara) {
	if(pPara == 0) {
		return;
	}
	uint8_t idx = (uint8_t)pPara->Band;
	if(idx >= EQ_Band_Max) {
		return;
	}

	pDSP->EQ_PTMIC[idx].all32[0] = pPara->all32[0];
	pDSP->EQ_PTMIC[idx].all32[1] = pPara->all32[1] & 0x1FFFFFF;
	dsp_reg_update(DSPREG_IDX(EQ_PTMIC[idx].all32[0]));
	dsp_reg_update(DSPREG_IDX(EQ_PTMIC[idx].all32[1]));
}

//EQ开关
void DSP_EQ_Ctrl(DSP_EQ_Band_t BandX, FunctionState_t en) {
	if(BandX >= EQ_Band_Max) {
		return;
	}
	pDSP->EQ_PTMIC[BandX].Ctrl1.enable = en;
	dsp_reg_update(DSPREG_IDX(EQ_PTMIC[BandX].all32[1]));
}


//-------------------------------------------------------------------------
//Echo设置
//-------------------------------------------------------------------------

void DSP_Echo_Set(const DSP_Echo_Para_t * pPara) {
	register DSP_EchoConfig_t echo_cfg;
	echo_cfg.all32 = pPara->all32;
	echo_cfg.echo_en = pDSP->EchoConfig.echo_en;
	echo_cfg.echo_close_req = 0;
	echo_cfg.echo_wet_ratio_reach_query = 0;
	pDSP->EchoConfig.all32 = echo_cfg.all32;
	dsp_reg_update(DSPREG_IDX(EchoConfig));
}

//Echo控制开关
void DSP_Echo_Ctrl(FunctionState_t en) {
	register DSP_EchoConfig_t echo_cfg;
	echo_cfg.all32 = pDSP->EchoConfig.all32;    // copy
	if(en == Enable)
	{
		if(echo_cfg.echo_en) {
			return;
		}
		echo_cfg.echo_en = 1;
	}
	else    // en == disable
	{
		if(echo_cfg.echo_en == 0) {
			return;
		}
		echo_cfg.echo_en = 0;
	}
	pDSP->EchoConfig.all32 = echo_cfg.all32;   // ��ֵ
	dsp_reg_update(DSPREG_IDX(EchoConfig));
}


