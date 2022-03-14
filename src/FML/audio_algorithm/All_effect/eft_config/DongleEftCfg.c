/*
 * DongleEftCfg.c
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "DongleEftCfg.h"
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

void DongleEftReg_update_all(DongleEffect_t *pDongleEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst)
{
    uint32_t ii;
    if( pSrc != pDst)
    {
    	dsp_EftReg_initial(pSrc, pDst);
    }
    for (ii = 0; ii < (sizeof(un_DSPRegAll_t)>>2); ii+= 4) {
    	DongleEftReg_update(pDongleEft, pDst, ii*4, 32);
    }
}

void DongleEftReg_update(DongleEffect_t *pDongleEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize)
{
	uint32_t  Fs = 48000;
    uint32_t index = (nReg);

    if (index >= DSPREG_IDX(EQB15Cfg[0]) && index <= (DSPREG_IDX(EQB15Cfg[14]) + 1)) {
        uint32_t idx = index - DSPREG_IDX(EQB15Cfg[0]);
        idx >>= 1;
        st_DSP_EQ_CONFIG ctrl = pDSPAll->bs.EQB15Cfg[idx];
        pDongleEft->EqB15Stru.pPara[idx]->Fs   = Fs;
        pDongleEft->EqB15Stru.pPara[idx]->Qv   = ctrl.Qv;
        pDongleEft->EqB15Stru.pPara[idx]->f0   = ctrl.F0_0p1Hz;
        pDongleEft->EqB15Stru.pPara[idx]->dBG  = ctrl.Gain_0p1dB;
        pDongleEft->EqB15Stru.pPara[idx]->Type = ctrl.EQ_Type;
        pDongleEft->EqB15Stru.pPara[idx]->en   = ctrl.EQ_EN;
        EqUpdate(&pDongleEft->EqB15Stru, idx);
        return;
    }

    switch (index) {
    case DSPREG_IDX(VolCfg) : {
        st_DSP_VOLUME_CONFIG ctrl = pDSPAll->bs.VolCfg;
        float vol2  = 0.01f * ctrl.dryvol;

        pDongleEft->pVolDryPara->dBorPct = VolPCT;
        pDongleEft->pVolDryPara->VolFL   = vol2;
        VolumeNew(pDongleEft->pVolDryPara, pDongleEft->pVolDryStru);
    }
    break;

    case DSPREG_IDX(EchoCfg0) : {
        st_DSP_ECHO_CONFIG0 ctrl = pDSPAll->bs.EchoCfg0;

        if (0 == ctrl.En) {
        	pDongleEft->pVolEchoPara->dBorPct = VolPCT;
        	pDongleEft->pVolEchoPara->VolFL   = 0;
        	pDongleEft->pEchoPara->En = 0;
        	VolumeNew(pDongleEft->pVolEchoPara, pDongleEft->pVolEchoStru);
        	Echo_New (pDongleEft->pEchoPara,    pDongleEft->pEchoStru);
        	MEM_Free(pDongleEft->pEchoBuff);
            break;
        }
        if (0 == pDongleEft->pEchoPara->En)
        {
            nds32_set_q31(0, (q31_t *)pDongleEft->pEchoPara, (sizeof(EchoPara_t) >> 2));
            nds32_set_q31(0, (q31_t *)pDongleEft->pEchoStru, (sizeof(EchoStru_t) >> 2));
            pDongleEft->pEchoPara->Fs_Hz        = (Fs / 3);
            pDongleEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
            pDongleEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
            pDongleEft->pEchoPara->En           = ctrl.En;
            pDongleEft->pEchoPara->DlyMax_Ms    = ctrl.MaxDelay_2MS * 2;

            uint32_t BuffSize;
            BuffSize = Echo_MaxBuff(pDongleEft->pEchoPara, pDongleEft->pEchoStru);
            pDongleEft->pEchoBuff = MEM_Malloc(BuffSize);
            if(NULL == pDongleEft->pEchoBuff)
            {
            	pDongleEft->pEchoPara->En = 0;
            	break;
            }
            Echo_New (pDongleEft->pEchoPara, pDongleEft->pEchoStru);
            Echo_Init(pDongleEft->pEchoStru, (void *)pDongleEft->pEchoBuff);
            float vol0  = 0.01f * (int8_t)pDSPAll->bs.EchoCfg1.WetLevel;
            pDongleEft->pVolEchoPara->VolFL   = vol0;
            pDongleEft->pVolEchoPara->dBorPct = VolPCT;
            VolumeNew(pDongleEft->pVolEchoPara, pDongleEft->pVolEchoStru);
        }
        else {
        	pDongleEft->pEchoPara->Fs_Hz        = (Fs / 3);
        	pDongleEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
        	pDongleEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
        	pDongleEft->pEchoPara->En           = ctrl.En;
            Echo_New(pDongleEft->pEchoPara, pDongleEft->pEchoStru);
        }
    }break;

    case DSPREG_IDX(EchoCfg1) : {
        st_DSP_ECHO_CONFIG1 ctrl = pDSPAll->bs.EchoCfg1;
        float vol0  = 0.01f * (int8_t)ctrl.WetLevel;
        pDongleEft->pVolEchoPara->dBorPct = VolPCT;

        if (ctrl.CloseReq) {
        	pDongleEft->pVolEchoPara->VolFL = 0;
            VolumeNew(pDongleEft->pVolEchoPara, pDongleEft->pVolEchoStru);
//            DSPEft.closeReq[Close_Echo] = 1;
        } else {
        	pDongleEft->pVolEchoPara->VolFL   = vol0;
        	VolumeNew(pDongleEft->pVolEchoPara, pDongleEft->pVolEchoStru);
        }
    }
    break;

    case DSPREG_IDX(ReverbCfg0) : {
        st_DSP_REVERB_CONFIG0 ctrl = pDSPAll->bs.ReverbCfg0;

        if (0 == ctrl.En) {
        	pDongleEft->pVolRvbPara->VolFL = 0;
        	pDongleEft->pVolRvbPara->dBorPct = VolPCT;
        	pDongleEft->pReverbPara->En = 0;
			VolumeNew (pDongleEft->pVolRvbPara, pDongleEft->pVolRvbStru);
			Reverb_new(pDongleEft->pReverbStru, pDongleEft->pReverbPara);
            break;
        }

        if (0 == pDongleEft->pReverbPara->En) {
            uint32_t size0 = sizeof(ReverbPara_t);
            uint32_t size1 = sizeof(ReverbStru_t);
            nds32_set_q31(0, (q31_t *)pDongleEft->pReverbPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDongleEft->pReverbStru, (size1 >> 2));
            pDongleEft->pReverbPara->Fs_Hz    = Fs/3 ;
            pDongleEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
            pDongleEft->pReverbPara->revtime  = 0.1f  * ctrl.RevTime;
            pDongleEft->pReverbPara->Damping  = 0.01f * ctrl.Damping;
            pDongleEft->pReverbPara->spread   = 0.1f   * ctrl.Spread;
            pDongleEft->pReverbPara->En       = ctrl.En;
            st_DSP_REVERB_CONFIG1 ctrl1    = pDSPAll->bs.ReverbCfg1;
            pDongleEft->pReverbPara->TailLevel  = 0.01f * ctrl1.TailLevel;
            pDongleEft->pReverbPara->EarlyLevel = 0.01f * ctrl1.EarlyLevel;
            pDongleEft->pReverbPara->LpfBw      = 0.01f * ctrl1.LpfBw;
            pDongleEft->pReverbPara->HpfBw      = 0.01f * ctrl1.HpfBw;
            pDongleEft->pReverbPara->LpfEn      = ctrl1.LpfEn;
            pDongleEft->pReverbPara->HpfEn      = ctrl1.HpfEn;
            st_DSP_REVERB_CONFIG2 ctrl2    = pDSPAll->bs.ReverbCfg2;
            pDongleEft->pReverbPara->RoomMax    = ctrl2.RoomSizeMax;
            pDongleEft->pReverbPara->SprdMax    = ctrl2.SpreadMax;
            uint32_t BuffSize;
            BuffSize = Reverb_MaxBuff(pDongleEft->pReverbStru, pDongleEft->pReverbPara);
            pDongleEft->pRvbBuff = MEM_Malloc(BuffSize);
            if(NULL == pDongleEft->pRvbBuff)
            {
            	pDongleEft->pReverbPara->En = 0;
            	break;
            }
            Reverb_new (pDongleEft->pReverbStru, pDongleEft->pReverbPara);
            Reverb_init(pDongleEft->pReverbStru, (void *)pDongleEft->pRvbBuff);
            float vol0  = 0.01f * (int8_t)ctrl2.WetLevel;
            pDongleEft->pVolRvbPara->VolFL   = vol0;
            pDongleEft->pVolRvbPara->dBorPct = VolPCT;
            VolumeNew(pDongleEft->pVolRvbPara, pDongleEft->pVolRvbStru);
        } else {
        	pDongleEft->pReverbPara->Fs_Hz    = 24000 ;
        	pDongleEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
        	pDongleEft->pReverbPara->revtime  = 0.1f  * ctrl.RevTime;
        	pDongleEft->pReverbPara->Damping  = 0.01f * ctrl.Damping;
        	pDongleEft->pReverbPara->spread   = 0.1f   * ctrl.Spread;
        	pDongleEft->pReverbPara->En       = ctrl.En;
            Reverb_new(pDongleEft->pReverbStru, pDongleEft->pReverbPara);
        }
    }
    break;

    case DSPREG_IDX(ReverbCfg1) : {
        st_DSP_REVERB_CONFIG1 ctrl = pDSPAll->bs.ReverbCfg1;
        pDongleEft->pReverbPara->TailLevel  = 0.01f * ctrl.TailLevel;
        pDongleEft->pReverbPara->EarlyLevel = 0.01f * ctrl.EarlyLevel;
        pDongleEft->pReverbPara->LpfBw      = 0.01f * ctrl.LpfBw;
        pDongleEft->pReverbPara->HpfBw      = 0.01f * ctrl.HpfBw;
        pDongleEft->pReverbPara->LpfEn      = ctrl.LpfEn;
        pDongleEft->pReverbPara->HpfEn      = ctrl.HpfEn;
        Reverb_new(pDongleEft->pReverbStru, pDongleEft->pReverbPara);
    }
    break;

    case DSPREG_IDX(ReverbCfg2) : {
        st_DSP_REVERB_CONFIG2 ctrl = pDSPAll->bs.ReverbCfg2;
        float vol0  = 0.01f * (int8_t)ctrl.WetLevel;
        pDongleEft->pVolRvbPara->dBorPct = VolPCT;
        if (ctrl.CloseReq) {
        	pDongleEft->pVolRvbPara->VolFL = 0;
            VolumeNew(pDongleEft->pVolRvbPara, pDongleEft->pVolRvbStru);
//            DSPEft.closeReq[Close_Reverb] = 1;
        } else {
        	pDongleEft->pVolRvbPara->VolFL  = vol0;
            VolumeNew(pDongleEft->pVolRvbPara, pDongleEft->pVolRvbStru);
        }
    }
    break;

    case DSPREG_IDX(PitchShiftCfg) : {
    	if(0 == pDSPAll->bs.PitchShiftCfg.En)
    	{
    		pDongleEft->pPsWsolaPara->En = 0;
    		PitchShiftWsola_New(pDongleEft->pPsWsolaStru, pDongleEft->pPsWsolaPara);
            MEM_Free(pDongleEft->pPitchShiftBuff);
            pDongleEft->pPitchShiftBuff=0;
    		MEM_Free(pDongleEft->pTmpBuff512x2);
            pDongleEft->pTmpBuff512x2=0;
    		pDongleEft->Prc512pOpen   = 0;
    		break;
    	}
    	if( 0 == pDongleEft->pPsWsolaPara->En)
    	{
			pDongleEft->pPsWsolaPara->En    = pDSPAll->bs.PitchShiftCfg.En;
			pDongleEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;

            uint32_t BuffSize;
            BuffSize = PitchShiftWsola_MaxBuff(pDongleEft->pPsWsolaStru, 512);
            pDongleEft->pPitchShiftBuff = MEM_Malloc(BuffSize);
            pDongleEft->pTmpBuff512x2 = MEM_Malloc((512*2)<<2);
            if(NULL == pDongleEft->pPitchShiftBuff || NULL == pDongleEft->pTmpBuff512x2)
            {
            	pDongleEft->pPsWsolaPara->En = 0;
            	break;
            }
            pDongleEft->Prc512pOpen   = 1;
			PitchShiftWsola_New (pDongleEft->pPsWsolaStru, pDongleEft->pPsWsolaPara);
			PitchShiftWsola_Init(pDongleEft->pPsWsolaStru, (void *)pDongleEft->pPitchShiftBuff, 512);
    	}
    	else
    	{
			pDongleEft->pPsWsolaPara->En    = pDSPAll->bs.PitchShiftCfg.En;
			pDongleEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;
			PitchShiftWsola_New(pDongleEft->pPsWsolaStru, pDongleEft->pPsWsolaPara);
    	}
		break;

    }break;

    case DSPREG_IDX(HowlSprsCtrl0) : {
        if (0 == pDSPAll->bs.HowlSprsCtrl0.En) {
        	pDongleEft->pHowlPara->En = 0;
        	HowlSupressNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
            break;
        }

        if (0 == pDongleEft->pHowlPara->En) {
            uint32_t size0 = sizeof(HowlPara_t);
            uint32_t size1 = sizeof(HowlStru_t);
            nds32_set_q31(0, (q31_t *)pDongleEft->pHowlPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDongleEft->pHowlStru, (size1 >> 2));
            HowlDetPara_t  *pDetPara = &(pDongleEft->pHowlPara->DetPara);
            st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
            pDetPara->Fs_Hz            = Fs;
            pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
            pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
            pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
            pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
            pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
            HowlNotchPara_t  *pNotchPara = &(pDongleEft->pHowlPara->NotchPara);
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
            HowlGainPara_t  *pGainPara = &(pDongleEft->pHowlPara->GainPara);
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
        pDongleEft->pHowlPara->ClearEn       = ctrl.ClearEn;
        pDongleEft->pHowlPara->DetEn         = ctrl.DetEn;
        pDongleEft->pHowlPara->GainCtrlEn    = ctrl.GainCtrlEn;
        pDongleEft->pHowlPara->NotchEn       = ctrl.NotchEn;
        pDongleEft->pHowlPara->NotchUpdateEn = ctrl.NotchUpdateEn;
        pDongleEft->pHowlPara->En            = ctrl.En;
        HowlSupressNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlDetCtrl0) : {
        HowlDetPara_t  *pDetPara = &(pDongleEft->pHowlPara->DetPara);
        st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
        pDetPara->Fs_Hz            = Fs;
        pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
        pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
        pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
        pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
        pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
        HowlDetParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlNotchCtrl0) : {
        HowlNotchPara_t  *pNotchPara = &(pDongleEft->pHowlPara->NotchPara);
        st_DSP_HOWLNOTCH_CONFIG0  ctrl1 = pDSPAll->bs.HowlNotchCtrl0;
        pNotchPara->DetFth_Hz      = ctrl1.DetFth;
        pNotchPara->DetNth         = ctrl1.DetNth;
        pNotchPara->NotchTotalNum  = ctrl1.TotalNum + 1;
        pNotchPara->NotchWantStudy = ctrl1.WantStdy;
        pNotchPara->NotchDf_Hz     = ctrl1.NotchDf;
        pNotchPara->NotchQ         = ctrl1.NotchQ;
        HowlNotchParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlNotchCtrl1) : {
        HowlNotchPara_t  *pNotchPara = &(pDongleEft->pHowlPara->NotchPara);
        st_DSP_HOWLNOTCH_CONFIG1  ctrl2 = pDSPAll->bs.HowlNotchCtrl1;
        pNotchPara->NotchLife_S    = ctrl2.Life_s;
        pNotchPara->NotchUpTime_S  = ctrl2.UpTime_s;
        pNotchPara->NotchHold_Ms   = ctrl2.Hold_40Ms * 40;
        pNotchPara->NotchDown_dB   = ctrl2.DownStep_dB;
        pNotchPara->NotchUp_dB     = ctrl2.UpStep_dB;
        pNotchPara->NotchInit_dB   = ctrl2.Init_dB;
        pNotchPara->NotchDeep_dB   = ctrl2.Deep_dB;
        HowlNotchParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl0) : {
        HowlGainPara_t  *pGainPara = &(pDongleEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG0  ctrl3  = pDSPAll->bs.HowlGainCtrl0;
        pGainPara->gAT_Ms          = ctrl3.gAT_Ms;
        pGainPara->gRT_Ms          = ctrl3.gRT_Ms;
        HowlGainParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl1) : {
        HowlGainPara_t  *pGainPara = &(pDongleEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG1  ctrl4  = pDSPAll->bs.HowlGainCtrl1;
        pGainPara->UpWinT_Ms       = ctrl4.UpWinT_Ms;
        pGainPara->NoHowl_Pct      = 0.01f * ctrl4.NoHowlPct_0p01;
        pGainPara->AfterNotchN     = ctrl4.AfterNotchN;
        HowlGainParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }
    break;

    case DSPREG_IDX(HowlGainCtrl2) : {
        HowlGainPara_t  *pGainPara = &(pDongleEft->pHowlPara->GainPara);
        st_DSP_HOWLGAIN_CONFIG2  ctrl5  = pDSPAll->bs.HowlGainCtrl2;
        pGainPara->DownStep_dB     = ctrl5.DownStep_dB;
        pGainPara->UpStep0_dB      = ctrl5.UpStep0_dB;
        pGainPara->UpStep1_dB      = ctrl5.UpStep1_dB;
        pGainPara->gMin_dB         = ctrl5.gMin_dB;
        pGainPara->gUp0Th_dB       = ctrl5.gUp0Th_dB;
        HowlGainParaNew(pDongleEft->pHowlStru, pDongleEft->pHowlPara);
    }break;

    case DSPREG_IDX(FreqShiftCtrl) : {
        st_DSP_FREQSHIFT_CONFIG0 ctrl = pDSPAll->bs.FreqShiftCtrl;
        if (0 == ctrl.En) {
        	pDongleEft->pFreqShiftPara->En = 0;
        	FreqShiftNew(pDongleEft->pFreqShiftStru, pDongleEft->pFreqShiftPara, blocksize);
            MEM_Free(pDongleEft->pFreqShiftBuff);
            break;
        }

        if (0 == pDongleEft->pFreqShiftPara->En) {
            uint32_t size0 = sizeof(FreqShiftPara_t);
            uint32_t size1 = sizeof(FreqShiftStru_t);
            nds32_set_q31(0, (q31_t *)pDongleEft->pFreqShiftPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDongleEft->pFreqShiftStru, (size1 >> 2));
            pDongleEft->pFreqShiftPara->Bw = ctrl.BW;
            pDongleEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
            pDongleEft->pFreqShiftPara->En = ctrl.En;
            uint32_t BuffSize;
            BuffSize = FreqShift_MaxBuff(pDongleEft->pFreqShiftStru, blocksize);
            pDongleEft->pFreqShiftBuff = MEM_Malloc(BuffSize);
            if(NULL == pDongleEft->pFreqShiftBuff)
            {
            	pDongleEft->pFreqShiftPara->En = 0;
            	break;
            }
            FreqShiftNew (pDongleEft->pFreqShiftStru, pDongleEft->pFreqShiftPara, blocksize);
            FreqShiftInit(pDongleEft->pFreqShiftStru, (void *)pDongleEft->pFreqShiftBuff, blocksize);
        } else {
        	pDongleEft->pFreqShiftPara->Bw = ctrl.BW;
        	pDongleEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
        	pDongleEft->pFreqShiftPara->En = ctrl.En;
            FreqShiftNew (pDongleEft->pFreqShiftStru, pDongleEft->pFreqShiftPara, blocksize);
        }
    }
    break;

    case DSPREG_IDX(NoiseGateCfg0) : {
        st_DSP_NOISEGATE_CONFIG0 ctrl = pDSPAll->bs.NoiseGateCfg0;

        if (0 == ctrl.En) {
        	pDongleEft->pNoiseGatePara->en = 0;
        	NoiseGateNew(pDongleEft->pNoiseGateStru, pDongleEft->pNoiseGatePara);
            break;
        }

        if (0 == pDongleEft->pNoiseGatePara->en) {
            uint32_t size0 = sizeof(NoiseGatePara_t);
            uint32_t size1 = sizeof(NoiseGateStru_t);
            nds32_set_q31(0, (q31_t *)pDongleEft->pNoiseGatePara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pDongleEft->pNoiseGateStru, (size1 >> 2));
            pDongleEft->pNoiseGatePara->fs_Hz  = Fs;
            pDongleEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
            pDongleEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
            pDongleEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
            pDongleEft->pNoiseGatePara->noiseT_Ms  = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
        }

        int8_t tmp0 = (int8_t)ctrl.THlow_dB;
        int8_t tmp1 = (int8_t)ctrl.THhigh_dB;
        pDongleEft->pNoiseGatePara->fs_Hz      = Fs;
        pDongleEft->pNoiseGatePara->THlow_dB   = tmp0;
        pDongleEft->pNoiseGatePara->THhigh_dB  = tmp1;
        pDongleEft->pNoiseGatePara->GateVol_dB = ctrl.GateVol_dB;
        pDongleEft->pNoiseGatePara->PkAT_Ms    = ctrl.ave_Ms;
        pDongleEft->pNoiseGatePara->PkRT_Ms    = ctrl.ave_Ms;
        pDongleEft->pNoiseGatePara->en         = ctrl.En;
        NoiseGateNew(pDongleEft->pNoiseGateStru, pDongleEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(NoiseGateCfg1) : {
    	pDongleEft->pNoiseGatePara->fs_Hz  = Fs;
    	pDongleEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
    	pDongleEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
        NoiseGateNew(pDongleEft->pNoiseGateStru, pDongleEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(NoiseGateCfg2) : {
    	pDongleEft->pNoiseGatePara->fs_Hz      = Fs;
    	pDongleEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
    	pDongleEft->pNoiseGatePara->noiseT_Ms  = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
        NoiseGateNew(pDongleEft->pNoiseGateStru, pDongleEft->pNoiseGatePara);
    }
    break;

    case DSPREG_IDX(LimiterCfg0) : {
//        if (0 == pDSPAll->bs.LimiterCfg0.En) {
//        	pDongleEft->pLimiterPara.en = 0;
//        	LimiterNew(pDongleEft->pLimiterStru, pDongleEft->pLimiterPara);
//            break;
//        }

//        if (0 == pDongleEft->pLimiterPara.en) {
//            uint32_t size0 = sizeof(LimiterPara_t);
//            uint32_t size1 = sizeof(LimiterStru_t);
//            nds32_set_q31(0, (q31_t *)pDongleEft->pLimiterPara, (size0 >> 2));
//            nds32_set_q31(0, (q31_t *)pDongleEft->pLimiterStru, (size1 >> 2));
//            pDongleEft->pLimiterPara->gAT_Ms  = pDSPAll->bs.LimiterCfg1.gAT_Ms;
//            pDongleEft->pLimiterPara->gRT_Ms  = pDSPAll->bs.LimiterCfg1.gRT_Ms;
//            pDongleEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
//            pDongleEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
//        }

//        int8_t tmp = (int8_t)pDSPAll->bs.LimiterCfg0.point_dB;
//        pDongleEft->pLimiterPara->point_dB = tmp;
//        pDongleEft->pLimiterPara->soft     = pDSPAll->bs.LimiterCfg0.soft;
//        pDongleEft->pLimiterPara->en       = pDSPAll->bs.LimiterCfg0.En;
//        LimiterNew(pDongleEft->pLimiterStru, pDongleEft->pLimiterPara);
    }
    break;

    case DSPREG_IDX(LimiterCfg1) : {
//    	pDongleEft->pLimiterPara->fs_Hz  = Fs;
//    	pDongleEft->pLimiterPara->gAT_Ms = pDSPAll->bs.LimiterCfg1.gAT_Ms;
//    	pDongleEft->pLimiterPara->gRT_Ms = pDSPAll->bs.LimiterCfg1.gRT_Ms;
//        LimiterNew(pDongleEft->pLimiterStru, pDongleEft->pLimiterPara);
    }
    break;

    case DSPREG_IDX(LimiterCfg2) : {
//    	pDongleEft->pLimiterPara->fs_Hz   = Fs;
//    	pDongleEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
//    	pDongleEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
//        LimiterNew(pDongleEft->pLimiterStru, pDongleEft->pLimiterPara);
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


