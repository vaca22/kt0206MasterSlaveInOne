/*
 * DspEftCfg.c
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "DspEftCfg.h"
#include "eft_malloc.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */

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

void DspEftReg_update_all(DspEffect_t *pDspEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst)
{
    uint32_t ii;
    dsp_EftReg_initial(pSrc, pDst);
    for (ii = 0; ii < (sizeof(un_DSPRegAll_t)>>2); ii+= 4) {
    	DspEftReg_update(pDspEft, pDst, ii*4, 32);
    }
}

void DspEftReg_update(DspEffect_t *pDspEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize)
{
    // uint32_t addr = g_EffectorBuffAddr;
	uint32_t  Fs = 48000;
    uint32_t index = (nReg);

    if (index >= DSPREG_IDX(EQB15Cfg[0]) && index <= (DSPREG_IDX(EQB15Cfg[14]) + 1)) {
        uint32_t idx = index - DSPREG_IDX(EQB15Cfg[0]);
        idx >>= 1;
        st_DSP_EQ_CONFIG ctrl = pDSPAll->bs.EQB15Cfg[idx];
        pDspEft->EqB15MonoStru.pPara[idx]->Fs   = Fs;
        pDspEft->EqB15MonoStru.pPara[idx]->Qv   = ctrl.Qv;
        pDspEft->EqB15MonoStru.pPara[idx]->f0   = ctrl.F0_0p1Hz;
        pDspEft->EqB15MonoStru.pPara[idx]->dBG  = ctrl.Gain_0p1dB;
        pDspEft->EqB15MonoStru.pPara[idx]->Type = ctrl.EQ_Type;
        pDspEft->EqB15MonoStru.pPara[idx]->en   = ctrl.EQ_EN;
        EqUpdate(&pDspEft->EqB15MonoStru, idx);
        return;
    }

    switch (index) {
    case DSPREG_IDX(VolCfg) : {
        st_DSP_VOLUME_CONFIG ctrl = pDSPAll->bs.VolCfg;
//        float vol0  = 0.5f  * (int8_t)ctrl.prevol;
//        float vol1  = 0.5f  * (int8_t)ctrl.postvol;
        float vol2  = 0.01f * ctrl.dryvol;

        pDspEft->pVolDryPara->dBorPct = VolPCT;
        pDspEft->pVolDryPara->VolFL   = vol2;
        VolumeNew(pDspEft->pVolDryPara, pDspEft->pVolDryStru);
    }
    break;

    case DSPREG_IDX(EchoCfg0) : {
        st_DSP_ECHO_CONFIG0 ctrl = pDSPAll->bs.EchoCfg0;

        if (0 == ctrl.En) {
            pDspEft->pVolEchoPara->dBorPct = VolPCT;
            pDspEft->pVolEchoPara->VolFL   = 0;
            pDspEft->pEchoPara->En = 0;
        	VolumeNew(pDspEft->pVolEchoPara, pDspEft->pVolEchoStru);
        	Echo_New (pDspEft->pEchoPara,    pDspEft->pEchoStru);
        	MEM_Free(pDspEft->pEchoBuff);
            break;
        }
        if (0 == pDspEft->pEchoPara->En)
        {
            nds32_set_q31(0, (q31_t *)pDspEft->pEchoPara, (sizeof(EchoPara_t) >> 2));
            nds32_set_q31(0, (q31_t *)pDspEft->pEchoStru, (sizeof(EchoStru_t) >> 2));
            pDspEft->pEchoPara->Fs_Hz        = (Fs / 3);
            pDspEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
            pDspEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
            pDspEft->pEchoPara->En           = ctrl.En;
            pDspEft->pEchoPara->DlyMax_Ms    = ctrl.MaxDelay_2MS * 2;

            uint32_t BuffSize;
            BuffSize = Echo_MaxBuff(pDspEft->pEchoPara, pDspEft->pEchoStru);
            pDspEft->pEchoBuff = MEM_Malloc(BuffSize);
            Echo_New (pDspEft->pEchoPara, pDspEft->pEchoStru);
            Echo_Init(pDspEft->pEchoStru, (void *)pDspEft->pEchoBuff);
            float vol0  = 0.01f * (int8_t)pDSPAll->bs.EchoCfg1.WetLevel;
            pDspEft->pVolEchoPara->VolFL   = vol0;
            pDspEft->pVolEchoPara->dBorPct = VolPCT;
            VolumeNew(pDspEft->pVolEchoPara, pDspEft->pVolEchoStru);
        }
        else {
        	pDspEft->pEchoPara->Fs_Hz        = (Fs / 3);
        	pDspEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
        	pDspEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
        	pDspEft->pEchoPara->En           = ctrl.En;
            Echo_New(pDspEft->pEchoPara, pDspEft->pEchoStru);
        }
    }break;

    case DSPREG_IDX(EchoCfg1) : {
        st_DSP_ECHO_CONFIG1 ctrl = pDSPAll->bs.EchoCfg1;
        float vol0  = 0.01f * (int8_t)ctrl.WetLevel;
        pDspEft->pVolEchoPara->dBorPct = VolPCT;

        if (ctrl.CloseReq) {
        	pDspEft->pVolEchoPara->VolFL = 0;
            VolumeNew(pDspEft->pVolEchoPara, pDspEft->pVolEchoStru);
//            DSPEft.closeReq[Close_Echo] = 1;
        } else {
        	pDspEft->pVolEchoPara->VolFL   = vol0;
        	VolumeNew(pDspEft->pVolEchoPara, pDspEft->pVolEchoStru);
        }
    }
    break;

    case DSPREG_IDX(ReverbCfg0) : {
        st_DSP_REVERB_CONFIG0 ctrl = pDSPAll->bs.ReverbCfg0;

        if (0 == ctrl.En) {
        	pDspEft->pVolRvbPara->VolFL = 0;
        	pDspEft->pVolRvbPara->dBorPct = VolPCT;
        	pDspEft->pReverbPara->En = 0;
			VolumeNew (pDspEft->pVolRvbPara, pDspEft->pVolRvbStru);
			Reverb_new(pDspEft->pReverbStru, pDspEft->pReverbPara);
            break;
        }

        if (0 == pDspEft->pReverbPara->En) {
            uint32_t size0 = sizeof(ReverbPara_t);
            uint32_t size1 = sizeof(ReverbStru_t);
            nds32_set_q31(0, (q31_t *)pDspEft->pReverbPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDspEft->pReverbStru, (size1 >> 2));
            pDspEft->pReverbPara->Fs_Hz    = Fs/3 ;
            pDspEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
            pDspEft->pReverbPara->revtime  = 0.1f  * ctrl.RevTime;
            pDspEft->pReverbPara->Damping  = 0.01f * ctrl.Damping;
            pDspEft->pReverbPara->spread   = 0.1f   * ctrl.Spread;
            pDspEft->pReverbPara->En       = ctrl.En;
            st_DSP_REVERB_CONFIG1 ctrl1    = pDSPAll->bs.ReverbCfg1;
            pDspEft->pReverbPara->TailLevel  = 0.01f * ctrl1.TailLevel;
            pDspEft->pReverbPara->EarlyLevel = 0.01f * ctrl1.EarlyLevel;
            pDspEft->pReverbPara->LpfBw      = 0.01f * ctrl1.LpfBw;
            pDspEft->pReverbPara->HpfBw      = 0.01f * ctrl1.HpfBw;
            pDspEft->pReverbPara->LpfEn      = ctrl1.LpfEn;
            pDspEft->pReverbPara->HpfEn      = ctrl1.HpfEn;
            st_DSP_REVERB_CONFIG2 ctrl2    = pDSPAll->bs.ReverbCfg2;
            pDspEft->pReverbPara->RoomMax    = ctrl2.RoomSizeMax;
            pDspEft->pReverbPara->SprdMax    = ctrl2.SpreadMax;
            uint32_t BuffSize;
            BuffSize = Reverb_MaxBuff(pDspEft->pReverbStru, pDspEft->pReverbPara);
            pDspEft->pRvbBuff = MEM_Malloc(BuffSize);
            Reverb_new (pDspEft->pReverbStru, pDspEft->pReverbPara);
            Reverb_init(pDspEft->pReverbStru, (void *)pDspEft->pRvbBuff);
            float vol0  = 0.01f * (int8_t)ctrl2.WetLevel;
            pDspEft->pVolRvbPara->VolFL   = vol0;
            pDspEft->pVolRvbPara->dBorPct = VolPCT;
            VolumeNew(pDspEft->pVolRvbPara, pDspEft->pVolRvbStru);
        } else {
        	pDspEft->pReverbPara->Fs_Hz    = 24000 ;
        	pDspEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
        	pDspEft->pReverbPara->revtime  = 0.1f  * ctrl.RevTime;
        	pDspEft->pReverbPara->Damping  = 0.01f * ctrl.Damping;
        	pDspEft->pReverbPara->spread   = 0.1f   * ctrl.Spread;
        	pDspEft->pReverbPara->En       = ctrl.En;
            Reverb_new(pDspEft->pReverbStru, pDspEft->pReverbPara);
        }
    }
    break;

    case DSPREG_IDX(ReverbCfg1) : {
        st_DSP_REVERB_CONFIG1 ctrl = pDSPAll->bs.ReverbCfg1;
        pDspEft->pReverbPara->TailLevel  = 0.01f * ctrl.TailLevel;
        pDspEft->pReverbPara->EarlyLevel = 0.01f * ctrl.EarlyLevel;
        pDspEft->pReverbPara->LpfBw      = 0.01f * ctrl.LpfBw;
        pDspEft->pReverbPara->HpfBw      = 0.01f * ctrl.HpfBw;
        pDspEft->pReverbPara->LpfEn      = ctrl.LpfEn;
        pDspEft->pReverbPara->HpfEn      = ctrl.HpfEn;
        Reverb_new(pDspEft->pReverbStru, pDspEft->pReverbPara);
    }
    break;

    case DSPREG_IDX(ReverbCfg2) : {
        st_DSP_REVERB_CONFIG2 ctrl = pDSPAll->bs.ReverbCfg2;
        float vol0  = 0.01f * (int8_t)ctrl.WetLevel;
        pDspEft->pVolRvbPara->dBorPct = VolPCT;
        if (ctrl.CloseReq) {
        	pDspEft->pVolRvbPara->VolFL = 0;
            VolumeNew(pDspEft->pVolRvbPara, pDspEft->pVolRvbStru);
//            DSPEft.closeReq[Close_Reverb] = 1;
        } else {
        	pDspEft->pVolRvbPara->VolFL  = vol0;
            VolumeNew(pDspEft->pVolRvbPara, pDspEft->pVolRvbStru);
        }
    }
    break;

    case DSPREG_IDX(PitchShiftCfg) : {
    	if(0 == pDSPAll->bs.PitchShiftCfg.En)
    	{
    		pDspEft->pPsWsolaPara->En = 0;
    		PitchShiftWsola_New(pDspEft->pPsWsolaStru, pDspEft->pPsWsolaPara);
    		break;
    	}
    	if( 0 == pDspEft->pPsWsolaPara->En)
    	{
			pDspEft->pPsWsolaPara->En    = pDSPAll->bs.PitchShiftCfg.En;
			pDspEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;

            uint32_t BuffSize;
            BuffSize = PitchShiftWsola_MaxBuff(pDspEft->pPsWsolaStru, 512);
            pDspEft->pPitchShiftBuff = MEM_Malloc(BuffSize);
            pDspEft->pTmpBuff512x2 = MEM_Malloc((512*2)<<2);
            pDspEft->Prc512pOpen   = 1;
			PitchShiftWsola_New (pDspEft->pPsWsolaStru, pDspEft->pPsWsolaPara);
			PitchShiftWsola_Init(pDspEft->pPsWsolaStru, (void *)pDspEft->pPitchShiftBuff, 512);
    	}
    	else
    	{
			pDspEft->pPsWsolaPara->En    = pDSPAll->bs.PitchShiftCfg.En;
			pDspEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;
			PitchShiftWsola_New(pDspEft->pPsWsolaStru, pDspEft->pPsWsolaPara);
    	}
		break;

    }break;

    case DSPREG_IDX(HowlSprsCtrl0) : {
        if (0 == pDSPAll->bs.HowlSprsCtrl0.En) {
        	pDspEft->pHowlPara->En = 0;
        	HowlSupressNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
            break;
        }

        if (0 == pDspEft->pHowlPara->En) {
            uint32_t size0 = sizeof(HowlPara_t);
            uint32_t size1 = sizeof(HowlStru_t);
            nds32_set_q31(0, (q31_t *)pDspEft->pHowlPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDspEft->pHowlStru, (size1 >> 2));
            HowlDetPara_t  *pDetPara = &(pDspEft->pHowlPara->DetPara);
            st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
            pDetPara->Fs_Hz            = Fs;
            pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
            pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
            pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
            pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
            pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
            HowlNotchPara_t  *pNotchPara = &(pDspEft->pHowlPara->NotchPara);
            st_DSP_HOWLNOTCH_CONFIG0  ctrl1 = pDSPAll->bs.HowlNotchCtrl0;
            pNotchPara->DetFth_Hz      = ctrl1.DetFth;
            pNotchPara->DetNth         = ctrl1.DetNth;
            pNotchPara->NotchTotalNum  = ctrl1.TotalNum + 1;
            pNotchPara->NotchWantStudy = ctrl1.WantStdy;
            pNotchPara->NotchDf_Hz     = ctrl1.NotchDf;
            pNotchPara->NotchQ         = ctrl1.NotchQ;
            st_DSP_HOWLNOTCH_CONFIG1  ctrl2 = pDSPAll->bs.HowlNotchCtrl1;
            pNotchPara->NotchLife_S    = ctrl2.Life_s;
            pNotchPara->NotchUpTime_S  = ctrl2.UpTime_s;
            pNotchPara->NotchHold_Ms   = ctrl2.Hold_40Ms * 40;
            pNotchPara->NotchDown_dB   = ctrl2.DownStep_dB;
            pNotchPara->NotchUp_dB     = ctrl2.UpStep_dB;
            pNotchPara->NotchInit_dB   = ctrl2.Init_dB;
            pNotchPara->NotchDeep_dB   = ctrl2.Deep_dB;
            HowlGainPara_t  *pGainPara = &(pDspEft->pHowlPara->GainPara);
            st_DSP_HOWLGAIN_CONFIG0  ctrl3  = pDSPAll->bs.HowlGainCtrl0;
            st_DSP_HOWLGAIN_CONFIG1  ctrl4  = pDSPAll->bs.HowlGainCtrl1;
            st_DSP_HOWLGAIN_CONFIG2  ctrl5  = pDSPAll->bs.HowlGainCtrl2;
            pGainPara->gAT_Ms          = ctrl3.gAT_Ms;
            pGainPara->gRT_Ms          = ctrl3.gRT_Ms;
            pGainPara->UpWinT_Ms       = ctrl4.UpWinT_Ms;
            pGainPara->NoHowl_Pct      = 0.01f * ctrl4.NoHowlPct_0p01;
            pGainPara->AfterNotchN     = ctrl4.AfterNotchN;
            pGainPara->DownStep_dB     = ctrl5.DownStep_dB;
            pGainPara->UpStep0_dB      = ctrl5.UpStep0_dB;
            pGainPara->UpStep1_dB      = ctrl5.UpStep1_dB;
            pGainPara->gMin_dB         = ctrl5.gMin_dB;
            pGainPara->gUp0Th_dB       = ctrl5.gUp0Th_dB;
        }
        st_DSP_HOWLSUPRESS_CONFIG0   ctrl = pDSPAll->bs.HowlSprsCtrl0;
        pDspEft->pHowlPara->ClearEn       = ctrl.ClearEn;
        pDspEft->pHowlPara->DetEn         = ctrl.DetEn;
        pDspEft->pHowlPara->GainCtrlEn    = ctrl.GainCtrlEn;
        pDspEft->pHowlPara->NotchEn       = ctrl.NotchEn;
        pDspEft->pHowlPara->NotchUpdateEn = ctrl.NotchUpdateEn;
        pDspEft->pHowlPara->En            = ctrl.En;
        HowlSupressNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlDetCtrl0) : {
        HowlDetPara_t  *pDetPara = &(pDspEft->pHowlPara->DetPara);
        st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
        pDetPara->Fs_Hz            = Fs;
        pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
        pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
        pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
        pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
        pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
        HowlDetParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlNotchCtrl0) : {
        HowlNotchPara_t  *pNotchPara = &(pDspEft->pHowlPara->NotchPara);
        st_DSP_HOWLNOTCH_CONFIG0  ctrl1 = pDSPAll->bs.HowlNotchCtrl0;
        pNotchPara->DetFth_Hz      = ctrl1.DetFth;
        pNotchPara->DetNth         = ctrl1.DetNth;
        pNotchPara->NotchTotalNum  = ctrl1.TotalNum + 1;
        pNotchPara->NotchWantStudy = ctrl1.WantStdy;
        pNotchPara->NotchDf_Hz     = ctrl1.NotchDf;
        pNotchPara->NotchQ         = ctrl1.NotchQ;
        HowlNotchParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlNotchCtrl1) : {
        HowlNotchPara_t  *pNotchPara = &(pDspEft->pHowlPara->NotchPara);
        st_DSP_HOWLNOTCH_CONFIG1  ctrl2 = pDSPAll->bs.HowlNotchCtrl1;
        pNotchPara->NotchLife_S    = ctrl2.Life_s;
        pNotchPara->NotchUpTime_S  = ctrl2.UpTime_s;
        pNotchPara->NotchHold_Ms   = ctrl2.Hold_40Ms * 40;
        pNotchPara->NotchDown_dB   = ctrl2.DownStep_dB;
        pNotchPara->NotchUp_dB     = ctrl2.UpStep_dB;
        pNotchPara->NotchInit_dB   = ctrl2.Init_dB;
        pNotchPara->NotchDeep_dB   = ctrl2.Deep_dB;
        HowlNotchParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl0) : {
        HowlGainPara_t  *pGainPara = &(pDspEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG0  ctrl3  = pDSPAll->bs.HowlGainCtrl0;
        pGainPara->gAT_Ms          = ctrl3.gAT_Ms;
        pGainPara->gRT_Ms          = ctrl3.gRT_Ms;
        HowlGainParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl1) : {
        HowlGainPara_t  *pGainPara = &(pDspEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG1  ctrl4  = pDSPAll->bs.HowlGainCtrl1;
        pGainPara->UpWinT_Ms       = ctrl4.UpWinT_Ms;
        pGainPara->NoHowl_Pct      = 0.01f * ctrl4.NoHowlPct_0p01;
        pGainPara->AfterNotchN     = ctrl4.AfterNotchN;
        HowlGainParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl2) : {
        HowlGainPara_t  *pGainPara = &(pDspEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG2  ctrl5  = pDSPAll->bs.HowlGainCtrl2;
        pGainPara->DownStep_dB     = ctrl5.DownStep_dB;
        pGainPara->UpStep0_dB      = ctrl5.UpStep0_dB;
        pGainPara->UpStep1_dB      = ctrl5.UpStep1_dB;
        pGainPara->gMin_dB         = ctrl5.gMin_dB;
        pGainPara->gUp0Th_dB       = ctrl5.gUp0Th_dB;
        HowlGainParaNew(pDspEft->pHowlStru, pDspEft->pHowlPara);
    }break;

    case DSPREG_IDX(FreqShiftCtrl) : {
        st_DSP_FREQSHIFT_CONFIG0 ctrl = pDSPAll->bs.FreqShiftCtrl;
        if (0 == ctrl.En) {
        	pDspEft->pFreqShiftPara->En = 0;
        	FreqShiftNew(pDspEft->pFreqShiftStru, pDspEft->pFreqShiftPara, blocksize);
            break;
        }

        if (0 == pDspEft->pFreqShiftPara->En) {
            uint32_t size0 = sizeof(FreqShiftPara_t);
            uint32_t size1 = sizeof(FreqShiftStru_t);
            nds32_set_q31(0, (q31_t *)pDspEft->pFreqShiftPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDspEft->pFreqShiftStru, (size1 >> 2));
            pDspEft->pFreqShiftPara->Bw = ctrl.BW;
            pDspEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
            pDspEft->pFreqShiftPara->En = ctrl.En;
            uint32_t BuffSize;
            BuffSize = FreqShift_MaxBuff(pDspEft->pFreqShiftStru, blocksize);
            pDspEft->pFreqShiftBuff = MEM_Malloc(BuffSize);
            FreqShiftNew (pDspEft->pFreqShiftStru, pDspEft->pFreqShiftPara, blocksize);
            FreqShiftInit(pDspEft->pFreqShiftStru, (void *)pDspEft->pFreqShiftBuff, blocksize);
        } else {
        	pDspEft->pFreqShiftPara->Bw = ctrl.BW;
        	pDspEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
        	pDspEft->pFreqShiftPara->En = ctrl.En;
            FreqShiftNew (pDspEft->pFreqShiftStru, pDspEft->pFreqShiftPara, blocksize);
        }
    }
    break;

    case DSPREG_IDX(NoiseGateCfg0) : {
        st_DSP_NOISEGATE_CONFIG0 ctrl = pDSPAll->bs.NoiseGateCfg0;

        if (0 == ctrl.En) {
        	pDspEft->pNoiseGatePara->en = 0;
        	NoiseGateNew(pDspEft->pNoiseGateStru, pDspEft->pNoiseGatePara);
            break;
        }

        if (0 == pDspEft->pNoiseGatePara->en) {
            uint32_t size0 = sizeof(NoiseGatePara_t);
            uint32_t size1 = sizeof(NoiseGateStru_t);
            nds32_set_q31(0, (q31_t *)pDspEft->pNoiseGatePara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDspEft->pNoiseGateStru, (size1 >> 2));
            pDspEft->pNoiseGatePara->fs_Hz  = Fs;
            pDspEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
            pDspEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
            pDspEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
            pDspEft->pNoiseGatePara->noiseT_Ms  = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
        }

        int8_t tmp0 = (int8_t)ctrl.THlow_dB;
        int8_t tmp1 = (int8_t)ctrl.THhigh_dB;
        pDspEft->pNoiseGatePara->fs_Hz      = Fs;
        pDspEft->pNoiseGatePara->THlow_dB   = tmp0;
        pDspEft->pNoiseGatePara->THhigh_dB  = tmp1;
        pDspEft->pNoiseGatePara->GateVol_dB = ctrl.GateVol_dB;
        pDspEft->pNoiseGatePara->PkAT_Ms    = ctrl.ave_Ms;
        pDspEft->pNoiseGatePara->PkRT_Ms    = ctrl.ave_Ms;
        pDspEft->pNoiseGatePara->en         = ctrl.En;
        NoiseGateNew(pDspEft->pNoiseGateStru, pDspEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(NoiseGateCfg1) : {
    	pDspEft->pNoiseGatePara->fs_Hz  = Fs;
    	pDspEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
    	pDspEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
        NoiseGateNew(pDspEft->pNoiseGateStru, pDspEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(NoiseGateCfg2) : {
    	pDspEft->pNoiseGatePara->fs_Hz      = Fs;
    	pDspEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
    	pDspEft->pNoiseGatePara->noiseT_Ms  = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
        NoiseGateNew(pDspEft->pNoiseGateStru, pDspEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(LimiterCfg0) : {
//        if (0 == pDSPAll->bs.LimiterCfg0.En) {
//        	pDspEft->pLimiterPara.en = 0;
//        	LimiterNew(pDspEft->pLimiterStru, pDspEft->pLimiterPara);
//            break;
//        }

//        if (0 == pDspEft->pLimiterPara.en) {
//            uint32_t size0 = sizeof(LimiterPara_t);
//            uint32_t size1 = sizeof(LimiterStru_t);
//            nds32_set_q31(0, (q31_t *)pDspEft->pLimiterPara, (size0 >> 2));
//            nds32_set_q31(0, (q31_t *)pDspEft->pLimiterStru, (size1 >> 2));
//            pDspEft->pLimiterPara->gAT_Ms  = pDSPAll->bs.LimiterCfg1.gAT_Ms;
//            pDspEft->pLimiterPara->gRT_Ms  = pDSPAll->bs.LimiterCfg1.gRT_Ms;
//            pDspEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
//            pDspEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
//        }

//        int8_t tmp = (int8_t)pDSPAll->bs.LimiterCfg0.point_dB;
//        pDspEft->pLimiterPara->point_dB = tmp;
//        pDspEft->pLimiterPara->soft     = pDSPAll->bs.LimiterCfg0.soft;
//        pDspEft->pLimiterPara->en       = pDSPAll->bs.LimiterCfg0.En;
//        LimiterNew(pDspEft->pLimiterStru, pDspEft->pLimiterPara);
    }
    break;

    case DSPREG_IDX(LimiterCfg1) : {
//    	pDspEft->pLimiterPara->fs_Hz  = Fs;
//    	pDspEft->pLimiterPara->gAT_Ms = pDSPAll->bs.LimiterCfg1.gAT_Ms;
//    	pDspEft->pLimiterPara->gRT_Ms = pDSPAll->bs.LimiterCfg1.gRT_Ms;
//        LimiterNew(pDspEft->pLimiterStru, pDspEft->pLimiterPara);
    }
    break;

    case DSPREG_IDX(LimiterCfg2) : {
//    	pDspEft->pLimiterPara->fs_Hz   = Fs;
//    	pDspEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
//    	pDspEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
//        LimiterNew(pDspEft->pLimiterStru, pDspEft->pLimiterPara);
    }
    break;

    default : {
    } break;
    }
}
/*
void DSP_EffectCloseDone(uint32_t CloseReqIdx)
{
    switch (CloseReqIdx) {
    case Close_Echo : {
        if (NULL != DSPEft.pEchoPara) {
            void *ptr0 = DSPEft.pEchoPara;
            void *ptr1 = DSPEft.pEchoStru;
            void *ptr2 = DSPEft.pEchoStru->pBuff;
            DSPEft.pEchoPara = NULL;
            DSPEft.pEchoStru = NULL;
            opus_free(ptr0);
            opus_free(ptr1);
            effector_mem_free(ptr2);
            DSPReg.bs.EchoCfg0.En = 0;
            DSPReg.bs.EchoCfg1.CloseReq = 0;
        }

        break;
    }
    break;

    case Close_Reverb : {
        if (NULL != DSPEft.pReverbPara) {
            void *ptr0 = DSPEft.pReverbPara;
            void *ptr1 = DSPEft.pReverbStru;
            void *ptr2 = DSPEft.pReverbStru->pBuff;
            DSPEft.pReverbPara = NULL;
            DSPEft.pReverbStru = NULL;
            opus_free(ptr0);
            opus_free(ptr1);
            effector_mem_free(ptr2);
            DSPReg.bs.ReverbCfg0.En = 0;
            DSPReg.bs.ReverbCfg2.CloseReq = 0;
        };
    }
    break;
    }
}
*/

