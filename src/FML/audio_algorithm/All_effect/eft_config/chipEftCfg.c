/*
 * HeadsetEftCfg.c
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "chipEftCfg.h"
#include "eft_malloc.h"
#include "effect_config.h"
#include "volume.h"
#include "chip_config.h"
#include "gpio_ctrl.h"
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
void ChipEftReg_update_all(ChipEffect_t *pChipEft, const un_DSPRegAll_t *pSrc, un_DSPRegAll_t *pDst)
{
    uint32_t ii;
    dsp_EftReg_initial(pSrc, pDst);
    for (ii = 0; ii < sizeof(un_DSPRegAll_t); ii += 4)
    {
        ChipEftReg_update(pChipEft, pDst, (ii >> 2), AUDIO_SAMPLE_BLOCK_SIZE);
    }
}

void ChipEftReg_update(ChipEffect_t *pChipEft, un_DSPRegAll_t *pDSPAll, uint32_t nReg, uint32_t blocksize)
{
    uint32_t Fs = 48000;
    uint32_t index = (nReg);
    #if(EFFECT_EQ_EN)
    if (index >= DSPREG_IDX(EQB15Cfg[0]) && index <= (DSPREG_IDX(EQB15Cfg[14]) + 1))
    {
        uint32_t idx = index - DSPREG_IDX(EQB15Cfg[0]);
        idx >>= 1;
        st_DSP_EQ_CONFIG ctrl = pDSPAll->bs.EQB15Cfg[idx];
        pChipEft->EqB15Stru.pPara[idx]->Fs = Fs;
        pChipEft->EqB15Stru.pPara[idx]->Qv = ctrl.Qv;
        pChipEft->EqB15Stru.pPara[idx]->f0 = ctrl.F0_0p1Hz;
        pChipEft->EqB15Stru.pPara[idx]->dBG = ctrl.Gain_0p1dB;
        pChipEft->EqB15Stru.pPara[idx]->Type = ctrl.EQ_Type;
        pChipEft->EqB15Stru.pPara[idx]->en = ctrl.EQ_EN;
        EqUpdate(&pChipEft->EqB15Stru, idx);
        return;
    }

    if (index >= DSPREG_IDX(EQB5Cfg[0]) && index <= (DSPREG_IDX(EQB5Cfg[4]) + 1))
    {
        uint32_t idx = index - DSPREG_IDX(EQB5Cfg[0]);
        idx >>= 1;
        st_DSP_EQ_CONFIG ctrl = pDSPAll->bs.EQB5Cfg[idx];
        pChipEft->EqB5Stru.pPara[idx]->Fs = Fs;
        pChipEft->EqB5Stru.pPara[idx]->Qv = ctrl.Qv;
        pChipEft->EqB5Stru.pPara[idx]->f0 = ctrl.F0_0p1Hz;
        pChipEft->EqB5Stru.pPara[idx]->dBG = ctrl.Gain_0p1dB;
        pChipEft->EqB5Stru.pPara[idx]->Type = ctrl.EQ_Type;
        pChipEft->EqB5Stru.pPara[idx]->en = ctrl.EQ_EN;
        EqUpdate(&pChipEft->EqB5Stru, idx);
        return;
    }
    #endif

    switch (index)
    {
        case DSPREG_IDX(ADCDigGain) : {
        g_dsp_gain_adc = pDSPAll->bs.ADCDigGain.ADCGain;
        }
        break;
        case DSPREG_IDX(I2SIDigGain) : {
            g_dsp_gain_i2sil = pDSPAll->bs.I2SIDigGain.I2SILGain;
            g_dsp_gain_i2sir = pDSPAll->bs.I2SIDigGain.I2SIRGain;
        }
        break;
        case DSPREG_IDX(DACDigGain) : {
            g_dsp_gain_dacl = pDSPAll->bs.DACDigGain.DACLGain;
            g_dsp_gain_dacr = pDSPAll->bs.DACDigGain.DACRGain;
        }
        break;
        case DSPREG_IDX(I2SODigGain) : {
            g_dsp_gain_i2sol = pDSPAll->bs.I2SODigGain.I2SOLGain;
            g_dsp_gain_i2sor = pDSPAll->bs.I2SODigGain.I2SORGain;
        }
        break;
        case DSPREG_IDX(InVolCfg) : {
            dsp_adc2usb_vol = pDSPAll->bs.InVolCfg.ADCVol;
            dsp_prevol_i2sL = pDSPAll->bs.InVolCfg.I2SILVol;
            dsp_prevol_i2sR = pDSPAll->bs.InVolCfg.I2SIRVol;
            dsp_usb_postvol = pDSPAll->bs.InVolCfg.USBInVol;
        }
        break;
        case DSPREG_IDX(OutVolCfg) : {
            dsp_usb2dac_vol_l = pDSPAll->bs.OutVolCfg.DACLVol;
            dsp_usb2dac_vol_r = pDSPAll->bs.OutVolCfg.DACRVol;
            dsp_i2so_vol_l    = pDSPAll->bs.OutVolCfg.I2SOLVol;
            dsp_i2so_vol_r    = pDSPAll->bs.OutVolCfg.I2SORVol;
        }
        break;
        case DSPREG_IDX(EftVolCfg) : {
            st_DSP_EFTVOLUME_CONFIG ctrl = pDSPAll->bs.EftVolCfg;
            float vol2  = 0.01f * ctrl.dryvol;

            pChipEft->pVolDryPara->dBorPct = VolPCT;
            pChipEft->pVolDryPara->VolFL   = vol2;
            VolumeNew(pChipEft->pVolDryPara, pChipEft->pVolDryStru);
        }
        break;
        #if(EFFECT_POST_SIDETONE_EN)
        case DSPREG_IDX(SideToneCfg) : {
            st_DSP_SIDETONE_CONFIG ctrl = pDSPAll->bs.SideToneCfg;
            int8_t vol1  = (int8_t)ctrl.MixInVol;
            int8_t vol2  = (int8_t)ctrl.MixOutVol;
            VolumePara_t *pPara1 = &pChipEft->pSideTonePara->UsbInVolPara;
            VolumePara_t *pPara2 = &pChipEft->pSideTonePara->UsbOutVolPara;
            pPara1->dBorPct = VolDB;
            pPara2->dBorPct = VolDB;
            pPara1->step    = 8;
            pPara2->step    = 8;
            pPara1->VolFL   = 0.5f * vol1;
            pPara2->VolFL   = 0.5f * vol2;
            pChipEft->pSideTonePara->En = ctrl.En;
            SideToneNew(pChipEft->pSideToneStru, pChipEft->pSideTonePara);
		}
        break;
        #endif
        case DSPREG_IDX(MusicDkCfg0) : {
        st_DSP_MUSICDUCKING_CONFIG0 ctrl = pDSPAll->bs.MusicDkCfg0;

        if (0 == ctrl.En) {
        	pChipEft->pMusicDuckingPara->en = 0;
        	MusicDuckingNew(pChipEft->pMusicDuckingStru, pChipEft->pMusicDuckingPara);
            break;
        }

        if (0 == pChipEft->pMusicDuckingPara->en) {
            uint32_t size0 = sizeof(MusicDuckingPara_t);
            uint32_t size1 = sizeof(MusicDuckingStru_t);
            nds32_set_q31(0, (q31_t *)pChipEft->pMusicDuckingPara, (size0 >> 2));
            nds32_set_q31(0, (q31_t *)pChipEft->pMusicDuckingStru, (size1 >> 2));
            pChipEft->pMusicDuckingPara->fs_Hz  = Fs;
            pChipEft->pMusicDuckingPara->gAT_Ms = pDSPAll->bs.MusicDkCfg1.gAT_Ms;
            pChipEft->pMusicDuckingPara->gRT_Ms = pDSPAll->bs.MusicDkCfg1.gRT_Ms;
            pChipEft->pMusicDuckingPara->signalT_Ms = pDSPAll->bs.MusicDkCfg2.sigT_Ms;
            pChipEft->pMusicDuckingPara->noiseT_Ms  = pDSPAll->bs.MusicDkCfg2.noiseT_Ms;
        }

        int8_t tmp0 = (int8_t)ctrl.THlow_dB;
        int8_t tmp1 = (int8_t)ctrl.THhigh_dB;
        pChipEft->pMusicDuckingPara->fs_Hz      = Fs;
        pChipEft->pMusicDuckingPara->THlow_dB   = tmp0;
        pChipEft->pMusicDuckingPara->THhigh_dB  = tmp1;
        pChipEft->pMusicDuckingPara->DuckingVol_dB = (int8_t)ctrl.DuckVol_dB;
        pChipEft->pMusicDuckingPara->ave_Ms    = ctrl.ave_Ms;
        pChipEft->pMusicDuckingPara->en         = ctrl.En;
        MusicDuckingNew(pChipEft->pMusicDuckingStru, pChipEft->pMusicDuckingPara);
        }
        break;

        case DSPREG_IDX(MusicDkCfg1) : {
            pChipEft->pMusicDuckingPara->fs_Hz  = Fs;
            pChipEft->pMusicDuckingPara->gAT_Ms = pDSPAll->bs.MusicDkCfg1.gAT_Ms;
            pChipEft->pMusicDuckingPara->gRT_Ms = pDSPAll->bs.MusicDkCfg1.gRT_Ms;
            MusicDuckingNew(pChipEft->pMusicDuckingStru, pChipEft->pMusicDuckingPara);
        }
        break;

        case DSPREG_IDX(MusicDkCfg2) : {
            pChipEft->pMusicDuckingPara->fs_Hz      = Fs;
            pChipEft->pMusicDuckingPara->signalT_Ms = pDSPAll->bs.MusicDkCfg2.sigT_Ms;
            pChipEft->pMusicDuckingPara->noiseT_Ms  = pDSPAll->bs.MusicDkCfg2.noiseT_Ms;
            MusicDuckingNew(pChipEft->pMusicDuckingStru, pChipEft->pMusicDuckingPara);
        }
        break;

        #if(EFFECT_SURROUND3D_EN)
        case DSPREG_IDX(SrdCfg0):
        {
            int8_t tmp0 = (int8_t)pDSPAll->bs.SrdCfg0.CenterGain_0p5dB;
            pChipEft->pSrd3DPara->CenterGain_dB = 0.5f * tmp0;
            tmp0 = (int8_t)pDSPAll->bs.SrdCfg0.LRGain_0p5dB;
            pChipEft->pSrd3DPara->FrontGain_dB = 0.5f * tmp0;
            tmp0 = (int8_t)pDSPAll->bs.SrdCfg0.LSRSGain_0p5dB;
            pChipEft->pSrd3DPara->SrdGain_dB = 0.5f * tmp0;
            pChipEft->pSrd3DPara->En = pDSPAll->bs.SrdCfg0.En;
            Surround3DNew(pChipEft->pSrd3DPara, pChipEft->pSrd3DStru);
        }
        break;
        #endif
		#if(EFFECT_SURROUNDMOVE_EN)
		case DSPREG_IDX(SrdMoveCfg0.SrdMovePara.En):
		{
            if (0 == pDSPAll->bs.SrdMoveCfg0.SrdMovePara.En)
            {
            	pChipEft->pSrdMovePara->En=0;
            	SurroundMoveNew(pChipEft->pSrdMoveStru, pChipEft->pSrdMovePara);
				MEM_Free(pChipEft->pSrdMoveBuff);
				pChipEft->pSrdMoveBuff=0;
                break;
            }
            if (0 == pChipEft->pSrdMovePara->En)
            {
                uint32_t size0 = sizeof(SurroundMovePara_t);
                uint32_t size1 = sizeof(SurroundMoveStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pSrdMovePara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pSrdMoveStru, (size1 >> 2));
                uint32_t BuffSize;
                BuffSize = SurroundMove_MaxBuff(pChipEft->pSrdMoveStru, blocksize);
                pChipEft->pSrdMoveBuff = MEM_Malloc(BuffSize);
                if (NULL != pChipEft->pSrdMoveBuff)
                {
                    uint8_t i = 0;

                    pChipEft->pSrdMovePara->PathNum = pDSPAll->bs.SrdMoveCfg0.SrdMovePara.PathNum;
                    for(i = 0; i < PATHNUMMAX; i++) //copy path of 3dMove parameter
                        memcpy(&pChipEft->pSrdMovePara->st_Path[i], &pDSPAll->bs.SrdMoveCfg0.SrdMovePara.st_Path[i], (pDSPAll->bs.SrdMoveCfg0.SrdMovePara.PathNum * sizeof(SurroundMovePath_t)) );

//                	pChipEft->pSrdMovePara->PathNum = 1;
//					pChipEft->pSrdMovePara->st_Path[0].AzimuthStart = 0;
//					pChipEft->pSrdMovePara->st_Path[0].AzimuthStop  = 359;
//					pChipEft->pSrdMovePara->st_Path[0].PathCycNum   = 3;
//					pChipEft->pSrdMovePara->st_Path[0].PathTimeMs   = 10000;
//					pChipEft->pSrdMovePara->st_Path[0].ClockWise    = 1;
//					pChipEft->pSrdMovePara->st_Path[1].AzimuthStart = 359;
//					pChipEft->pSrdMovePara->st_Path[1].AzimuthStop  = 0;
//					pChipEft->pSrdMovePara->st_Path[1].PathCycNum   = 1;
//					pChipEft->pSrdMovePara->st_Path[1].PathTimeMs   = 10000;
//					pChipEft->pSrdMovePara->st_Path[1].ClockWise    = 0;
                	pChipEft->pSrdMovePara->En                      = 1;
                	SurroundMoveNew (pChipEft->pSrdMoveStru, pChipEft->pSrdMovePara);
                	SurroundMoveInit(pChipEft->pSrdMoveStru, pChipEft->pSrdMovePara, (void *)pChipEft->pSrdMoveBuff, blocksize);
                }
            }
            else
            {
            }
		}
		break;
		#endif

        #if(EFFECT_REVERB_EN)
        case DSPREG_IDX(ReverbCfg0):
        {
            st_DSP_REVERB_CONFIG0 ctrl = pDSPAll->bs.ReverbCfg0;

            if (0 == ctrl.En)
            {
                pChipEft->pVolRvbPara->VolFL = 0;
                pChipEft->pVolRvbPara->dBorPct = VolPCT;
                pChipEft->pReverbPara->En = 0;
                VolumeNew(pChipEft->pVolRvbPara, pChipEft->pVolRvbStru);
                Reverb_new(pChipEft->pReverbStru, pChipEft->pReverbPara);
				MEM_Free(pChipEft->pRvbBuff);
				pChipEft->pRvbBuff=0;
                break;
            }

            if (0 == pChipEft->pReverbPara->En)
            {
                uint32_t size0 = sizeof(ReverbPara_t);
                uint32_t size1 = sizeof(ReverbStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pReverbPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pReverbStru, (size1 >> 2));
                pChipEft->pReverbPara->Fs_Hz = Fs / 3;
                st_DSP_REVERB_CONFIG2 ctrl2 = pDSPAll->bs.ReverbCfg2;
                pChipEft->pReverbPara->RoomMax = ctrl2.RoomSizeMax;
                pChipEft->pReverbPara->SprdMax = ctrl2.SpreadMax;
                uint32_t BuffSize;
                pChipEft->Prc512pOpen   = 1;
                BuffSize = Reverb_MaxBuff(pChipEft->pReverbStru, pChipEft->pReverbPara);
                pChipEft->pRvbBuff = MEM_Malloc(BuffSize);
                if (NULL != pChipEft->pRvbBuff)
                {
                    pChipEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
                    pChipEft->pReverbPara->revtime = 0.1f * ctrl.RevTime;
                    pChipEft->pReverbPara->Damping = 0.01f * ctrl.Damping;
                    pChipEft->pReverbPara->spread = 0.1f * ctrl.Spread;
                    pChipEft->pReverbPara->En = ctrl.En;
                    st_DSP_REVERB_CONFIG1 ctrl1 = pDSPAll->bs.ReverbCfg1;
                    pChipEft->pReverbPara->TailLevel = 0.01f * ctrl1.TailLevel;
                    pChipEft->pReverbPara->EarlyLevel = 0.01f * ctrl1.EarlyLevel;
                    pChipEft->pReverbPara->LpfBw = 0.01f * ctrl1.LpfBw;
                    pChipEft->pReverbPara->HpfBw = 0.01f * ctrl1.HpfBw;
                    pChipEft->pReverbPara->LpfEn = ctrl1.LpfEn;
                    pChipEft->pReverbPara->HpfEn = ctrl1.HpfEn;
                    Reverb_new(pChipEft->pReverbStru, pChipEft->pReverbPara);
                    Reverb_init(pChipEft->pReverbStru, (void *)pChipEft->pRvbBuff);
                    float vol0 = 0.01f * ctrl2.WetLevel;
                    pChipEft->pVolRvbPara->VolFL = vol0;
                    pChipEft->pVolRvbPara->dBorPct = VolPCT;
                    VolumeNew(pChipEft->pVolRvbPara, pChipEft->pVolRvbStru);
                }
            }
            else
            {
                pChipEft->pReverbPara->Fs_Hz = Fs / 3;
                pChipEft->pReverbPara->roomsize = 1.0f * ctrl.RoomSize;
                pChipEft->pReverbPara->revtime = 0.1f * ctrl.RevTime;
                pChipEft->pReverbPara->Damping = 0.01f * ctrl.Damping;
                pChipEft->pReverbPara->spread = 0.1f * ctrl.Spread;
                pChipEft->pReverbPara->En = ctrl.En;
                Reverb_new(pChipEft->pReverbStru, pChipEft->pReverbPara);
            }
        }
        break;

        case DSPREG_IDX(ReverbCfg1):
        {
            st_DSP_REVERB_CONFIG1 ctrl = pDSPAll->bs.ReverbCfg1;
            pChipEft->pReverbPara->TailLevel = 0.01f * ctrl.TailLevel;
            pChipEft->pReverbPara->EarlyLevel = 0.01f * ctrl.EarlyLevel;
            pChipEft->pReverbPara->LpfBw = 0.01f * ctrl.LpfBw;
            pChipEft->pReverbPara->HpfBw = 0.01f * ctrl.HpfBw;
            pChipEft->pReverbPara->LpfEn = ctrl.LpfEn;
            pChipEft->pReverbPara->HpfEn = ctrl.HpfEn;
            Reverb_new(pChipEft->pReverbStru, pChipEft->pReverbPara);
        }
        break;

        case DSPREG_IDX(ReverbCfg2):
        {
            st_DSP_REVERB_CONFIG2 ctrl = pDSPAll->bs.ReverbCfg2;
            float vol0 = 0.01f * ctrl.WetLevel;
            pChipEft->pVolRvbPara->dBorPct = VolPCT;
            if (ctrl.CloseReq)
            {
                pChipEft->pVolRvbPara->VolFL = 0;
                VolumeNew(pChipEft->pVolRvbPara, pChipEft->pVolRvbStru);
                //            DSPEft.closeReq[Close_Reverb] = 1;
            }
            else
            {
                pChipEft->pVolRvbPara->VolFL = vol0;
                VolumeNew(pChipEft->pVolRvbPara, pChipEft->pVolRvbStru);
            }
        }
        break;
        #endif
        
        #if(EFFECT_PITCHSHIFT_EN)
        case DSPREG_IDX(PitchShiftCfg):
        {
            if ((0 == pDSPAll->bs.PitchShiftCfg.En)&&(1 == pChipEft->pPsWsolaPara->En))
            {
                pChipEft->pPsWsolaPara->En = 0;
                PitchShiftWsola_New(pChipEft->pPsWsolaStru, pChipEft->pPsWsolaPara);
				MEM_Free(pChipEft->pPitchShiftBuff);    		
                pChipEft->pPitchShiftBuff=0;
//                if(pChipEft->Cnt512pEft == 1)
//                {
//                MEM_Free(pChipEft->pTmpBuff512x3);
//                pChipEft->pTmpBuff512x3=0;
//					pChipEft->Cnt512pEft = 0;
//                }
//                else if(pChipEft->Cnt512pEft > 0)
//                {
//                	pChipEft->Cnt512pEft -= 1;
//                }
//    		    pChipEft->Prc512pOpen   = 0;
                break;
            }
            else if(0==pDSPAll->bs.PitchShiftCfg.En)
            {
                break;
            }
            if (0 == pChipEft->pPsWsolaPara->En)
            {
                uint32_t BuffSize;
                uint32_t size0 = sizeof(PitchShiftWsolaPara_t);
                uint32_t size1 = sizeof(PitchShiftWsolaStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pPsWsolaPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pPsWsolaStru, (size1 >> 2));
                BuffSize = PitchShiftWsola_MaxBuff(pChipEft->pPsWsolaStru, 512);
                pChipEft->pPitchShiftBuff = MEM_Malloc(BuffSize);
//                if(pChipEft->Cnt512pEft == 0)
//                {
//                pChipEft->pTmpBuff512x3 = MEM_Malloc((512 * 3) << 2);
//                }
//                pChipEft->Cnt512pEft += 1;
//                if (NULL != pChipEft->pPitchShiftBuff && NULL != pChipEft->pTmpBuff512x3)
                if (NULL != pChipEft->pPitchShiftBuff)
                {
                    pChipEft->Prc512pOpen = 1;
                    pChipEft->pPsWsolaPara->En = pDSPAll->bs.PitchShiftCfg.En;
                    pChipEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;
                    PitchShiftWsola_New(pChipEft->pPsWsolaStru, pChipEft->pPsWsolaPara);
                    PitchShiftWsola_Init(pChipEft->pPsWsolaStru, (void *)pChipEft->pPitchShiftBuff, 512);
                }
            }
            else
            {
                pChipEft->pPsWsolaPara->En = pDSPAll->bs.PitchShiftCfg.En;
                pChipEft->pPsWsolaPara->ratio = 0.01f * pDSPAll->bs.PitchShiftCfg.ratio;
                PitchShiftWsola_New(pChipEft->pPsWsolaStru, pChipEft->pPsWsolaPara);
            }
        }
        break;
        #endif
        case DSPREG_IDX(PeakDetCfg):
        {
            if ((0 == pDSPAll->bs.PeakDetCfg.En)&&(1 == pChipEft->pPeakDet3BandPara->En))
            {
                pChipEft->pPeakDet3BandPara->En = 0;
                PeakDet3BandNew(pChipEft->pPeakDet3BandPara, pChipEft->pPeakDet3BandStru);
//                if(pChipEft->Cnt512pEft == 1)
//                {
//					MEM_Free(pChipEft->pTmpBuff512x3);
//					pChipEft->pTmpBuff512x3=0;
//					pChipEft->Cnt512pEft = 0;
//                }
//                else if(pChipEft->Cnt512pEft > 0)
//                {
//                	pChipEft->Cnt512pEft -= 1;
//                }
				pChipEft->PrcOut512pOpen   = 0;
				MEM_Free(pChipEft->OutWrapBuff512p.pBuff);
				pChipEft->OutWrapBuff512p.pBuff = 0;
                break;
            }
            else if(0==pDSPAll->bs.PitchShiftCfg.En)
            {
                break;
            }
            if (0 == pChipEft->pPeakDet3BandPara->En)
            {
                uint32_t size0 = sizeof(PitchShiftWsolaPara_t);
                uint32_t size1 = sizeof(PitchShiftWsolaStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pPeakDet3BandPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pPeakDet3BandStru, (size1 >> 2));
                pChipEft->OutWrapBuff512p.BlockSize = blocksize;
                pChipEft->OutWrapBuff512p.FrameSize = 512;
            	uint32_t size  = SWI_WrapBuf_GetSize(&pChipEft->OutWrapBuff512p);
            	void * Buff  =  MEM_Malloc(size);
            	SWI_WrapBuf_Init(&pChipEft->OutWrapBuff512p, (uint32_t)Buff);
//                if(pChipEft->Cnt512pEft == 0)
//                {
//                	pChipEft->pTmpBuff512x3 = MEM_Malloc((512 * 3) << 2);
//                }
//                pChipEft->Cnt512pEft += 1;
//                if (NULL == pChipEft->pTmpBuff512x3)
//                {
//                	break;
//                }
            }
			pChipEft->PrcOut512pOpen = 1;
			pChipEft->pPeakDet3BandPara->En = pDSPAll->bs.PeakDetCfg.En;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[0].Fs_Hz = 48000;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[1].Fs_Hz = 48000;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[2].Fs_Hz = 48000;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[0].aweight_en = 0;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[1].aweight_en = 0;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[2].aweight_en = 0;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[0].det_en = 1;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[1].det_en = 1;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[2].det_en = 1;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[0].PeakWinT_ms = 40;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[1].PeakWinT_ms = 20;
			pChipEft->pPeakDet3BandPara->st_PeakDetPara[2].PeakWinT_ms = 10;
			PeakDet3BandNew(pChipEft->pPeakDet3BandPara, pChipEft->pPeakDet3BandStru);
        }
        break;

        #if(EFFECT_NOISEGATE_EN)
        case DSPREG_IDX(NoiseGateCfg0):
        {
            st_DSP_NOISEGATE_CONFIG0 ctrl = pDSPAll->bs.NoiseGateCfg0;

            if (0 == ctrl.En)
            {
                pChipEft->pNoiseGatePara->en = 0;
                NoiseGateNew(pChipEft->pNoiseGateStru, pChipEft->pNoiseGatePara);
                break;
            }

            if (0 == pChipEft->pNoiseGatePara->en)
            {
                uint32_t size0 = sizeof(NoiseGatePara_t);
                uint32_t size1 = sizeof(NoiseGateStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pNoiseGatePara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pNoiseGateStru, (size1 >> 2));
                pChipEft->pNoiseGatePara->fs_Hz = Fs;
                pChipEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
                pChipEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
                pChipEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
                pChipEft->pNoiseGatePara->noiseT_Ms = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
            }

            int8_t tmp0 = (int8_t)ctrl.THlow_dB;
            int8_t tmp1 = (int8_t)ctrl.THhigh_dB;
            pChipEft->pNoiseGatePara->fs_Hz = Fs;
            pChipEft->pNoiseGatePara->THlow_dB = tmp0;
            pChipEft->pNoiseGatePara->THhigh_dB = tmp1;
            pChipEft->pNoiseGatePara->GateVol_dB = (int8_t)ctrl.GateVol_dB;
            pChipEft->pNoiseGatePara->PkAT_Ms = ctrl.ave_Ms;
            pChipEft->pNoiseGatePara->PkRT_Ms = ctrl.ave_Ms;
            pChipEft->pNoiseGatePara->en = ctrl.En;
            NoiseGateNew(pChipEft->pNoiseGateStru, pChipEft->pNoiseGatePara);
        }
        break;

        case DSPREG_IDX(NoiseGateCfg1):
        {
            pChipEft->pNoiseGatePara->fs_Hz = Fs;
            pChipEft->pNoiseGatePara->gAT_Ms = pDSPAll->bs.NoiseGateCfg1.gAT_Ms;
            pChipEft->pNoiseGatePara->gRT_Ms = pDSPAll->bs.NoiseGateCfg1.gRT_Ms;
            NoiseGateNew(pChipEft->pNoiseGateStru, pChipEft->pNoiseGatePara);
        }
        break;

        case DSPREG_IDX(NoiseGateCfg2):
        {
            pChipEft->pNoiseGatePara->fs_Hz = Fs;
            pChipEft->pNoiseGatePara->signalT_Ms = pDSPAll->bs.NoiseGateCfg2.sigT_Ms;
            pChipEft->pNoiseGatePara->noiseT_Ms = pDSPAll->bs.NoiseGateCfg2.noiseT_Ms;
            NoiseGateNew(pChipEft->pNoiseGateStru, pChipEft->pNoiseGatePara);
        }
        break;
        #endif

        case DSPREG_IDX(LimiterCfg0):
        {
            if (0 == pDSPAll->bs.LimiterCfg0.En)
            {
                pChipEft->pLimiterPara->en = 0;
                LimiterNew(pChipEft->pLimiterStru, pChipEft->pLimiterPara);
                break;
            }

            if (0 == pChipEft->pLimiterPara->en)
            {
                uint32_t size0 = sizeof(LimiterPara_t);
                uint32_t size1 = sizeof(LimiterStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pLimiterPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pLimiterStru, (size1 >> 2));
                pChipEft->pLimiterPara->gAT_Ms = pDSPAll->bs.LimiterCfg1.gAT_Ms;
                pChipEft->pLimiterPara->gRT_Ms = pDSPAll->bs.LimiterCfg1.gRT_Ms;
                pChipEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
                pChipEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
            }

            int8_t tmp = (int8_t)pDSPAll->bs.LimiterCfg0.point_dB;
            pChipEft->pLimiterPara->point_dB = tmp;
            pChipEft->pLimiterPara->soft = pDSPAll->bs.LimiterCfg0.soft;
            pChipEft->pLimiterPara->en = pDSPAll->bs.LimiterCfg0.En;
            LimiterNew(pChipEft->pLimiterStru, pChipEft->pLimiterPara);
        }
        break;

        case DSPREG_IDX(LimiterCfg1):
        {
            pChipEft->pLimiterPara->fs_Hz = Fs;
            pChipEft->pLimiterPara->gAT_Ms = pDSPAll->bs.LimiterCfg1.gAT_Ms;
            pChipEft->pLimiterPara->gRT_Ms = pDSPAll->bs.LimiterCfg1.gRT_Ms;
            LimiterNew(pChipEft->pLimiterStru, pChipEft->pLimiterPara);
        }
        break;

        case DSPREG_IDX(LimiterCfg2):
        {
            pChipEft->pLimiterPara->fs_Hz = Fs;
            pChipEft->pLimiterPara->PkAT_Ms = pDSPAll->bs.LimiterCfg2.PkAT_Ms;
            pChipEft->pLimiterPara->PkRT_Ms = pDSPAll->bs.LimiterCfg2.PkRT_Ms;
            LimiterNew(pChipEft->pLimiterStru, pChipEft->pLimiterPara);
        }
        break;

        #if(EFFECT_HOWLSUPRESS_EN)
        case DSPREG_IDX(HowlSprsCtrl0) : 
        {
            if (0 == pDSPAll->bs.HowlSprsCtrl0.En) {
                pChipEft->pHowlPara->En = 0;
                HowlSupressNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
                break;
            }

            if (0 == pChipEft->pHowlPara->En) {
                uint32_t size0 = sizeof(HowlPara_t);
                uint32_t size1 = sizeof(HowlStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pHowlPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pHowlStru, (size1 >> 2));
                HowlDetPara_t  *pDetPara = &(pChipEft->pHowlPara->DetPara);
                st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
                pDetPara->Fs_Hz            = Fs;
                pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
                pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
                pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
                pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
                pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
                HowlNotchPara_t  *pNotchPara = &(pChipEft->pHowlPara->NotchPara);
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
                HowlGainPara_t  *pGainPara = &(pChipEft->pHowlPara->GainPara);
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
            pChipEft->pHowlPara->ClearEn       = ctrl.ClearEn;
            pChipEft->pHowlPara->DetEn         = ctrl.DetEn;
            pChipEft->pHowlPara->GainCtrlEn    = ctrl.GainCtrlEn;
            pChipEft->pHowlPara->NotchEn       = ctrl.NotchEn;
            pChipEft->pHowlPara->NotchUpdateEn = ctrl.NotchUpdateEn;
            pChipEft->pHowlPara->En            = ctrl.En;
            HowlSupressNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlDetCtrl0) : {
            HowlDetPara_t  *pDetPara = &(pChipEft->pHowlPara->DetPara);
            st_DSP_HOWLDET_CONFIG0  ctrl0 = pDSPAll->bs.HowlDetCtrl0;
            pDetPara->Fs_Hz            = Fs;
            pDetPara->PKLongWinT_S     = ctrl0.PKLongWinT_s;
            pDetPara->PKindexVarTh     = ctrl0.PKindexVarTh;
            pDetPara->PeakLongVarTh    = ctrl0.PKLongVarTh;
            pDetPara->PeakShortVarTh   = ctrl0.PKShortVarTh;
            pDetPara->ZCindexVarTh     = ctrl0.ZCindexVarTh;
            HowlDetParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlNotchCtrl0) : {
            HowlNotchPara_t  *pNotchPara = &(pChipEft->pHowlPara->NotchPara);
            st_DSP_HOWLNOTCH_CONFIG0  ctrl1 = pDSPAll->bs.HowlNotchCtrl0;
            pNotchPara->DetFth_Hz      = ctrl1.DetFth;
            pNotchPara->DetNth         = ctrl1.DetNth;
            pNotchPara->NotchTotalNum  = ctrl1.TotalNum + 1;
            pNotchPara->NotchWantStudy = ctrl1.WantStdy;
            pNotchPara->NotchDf_Hz     = ctrl1.NotchDf;
            pNotchPara->NotchQ         = ctrl1.NotchQ;
            HowlNotchParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlNotchCtrl1) : {
            HowlNotchPara_t  *pNotchPara = &(pChipEft->pHowlPara->NotchPara);
            st_DSP_HOWLNOTCH_CONFIG1  ctrl2 = pDSPAll->bs.HowlNotchCtrl1;
            pNotchPara->NotchLife_S    = ctrl2.Life_s;
            pNotchPara->NotchUpTime_S  = ctrl2.UpTime_s;
            pNotchPara->NotchHold_Ms   = ctrl2.Hold_40Ms * 40;
            pNotchPara->NotchDown_dB   = ctrl2.DownStep_dB;
            pNotchPara->NotchUp_dB     = ctrl2.UpStep_dB;
            pNotchPara->NotchInit_dB   = ctrl2.Init_dB;
            pNotchPara->NotchDeep_dB   = ctrl2.Deep_dB;
            HowlNotchParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlGainCtrl0) : {
            HowlGainPara_t  *pGainPara = &(pChipEft->pHowlPara->GainPara);
            st_DSP_HOWLGAIN_CONFIG0  ctrl3  = pDSPAll->bs.HowlGainCtrl0;
            pGainPara->gAT_Ms          = ctrl3.gAT_Ms;
            pGainPara->gRT_Ms          = ctrl3.gRT_Ms;
            HowlGainParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlGainCtrl1) : {
            HowlGainPara_t  *pGainPara = &(pChipEft->pHowlPara->GainPara);
            st_DSP_HOWLGAIN_CONFIG1  ctrl4  = pDSPAll->bs.HowlGainCtrl1;
            pGainPara->UpWinT_Ms       = ctrl4.UpWinT_Ms;
            pGainPara->NoHowl_Pct      = 0.01f * ctrl4.NoHowlPct_0p01;
            pGainPara->AfterNotchN     = ctrl4.AfterNotchN;
            HowlGainParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }
        break;

        case DSPREG_IDX(HowlGainCtrl2) : {
            HowlGainPara_t  *pGainPara = &(pChipEft->pHowlPara->GainPara);
            st_DSP_HOWLGAIN_CONFIG2  ctrl5  = pDSPAll->bs.HowlGainCtrl2;
            pGainPara->DownStep_dB     = ctrl5.DownStep_dB;
            pGainPara->UpStep0_dB      = ctrl5.UpStep0_dB;
            pGainPara->UpStep1_dB      = ctrl5.UpStep1_dB;
            pGainPara->gMin_dB         = ctrl5.gMin_dB;
            pGainPara->gUp0Th_dB       = ctrl5.gUp0Th_dB;
            HowlGainParaNew(pChipEft->pHowlStru, pChipEft->pHowlPara);
        }break;

        case DSPREG_IDX(FreqShiftCtrl) : {
            st_DSP_FREQSHIFT_CONFIG0 ctrl = pDSPAll->bs.FreqShiftCtrl;
            if (0 == ctrl.En) {
                pChipEft->pFreqShiftPara->En = 0;
                FreqShiftNew(pChipEft->pFreqShiftStru, pChipEft->pFreqShiftPara, blocksize);
                MEM_Free(pChipEft->pFreqShiftBuff);
                break;
            }

            if (0 == pChipEft->pFreqShiftPara->En) {
                uint32_t size0 = sizeof(FreqShiftPara_t);
                uint32_t size1 = sizeof(FreqShiftStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pFreqShiftPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pFreqShiftStru, (size1 >> 2));
                pChipEft->pFreqShiftPara->Bw = ctrl.BW;
                pChipEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
                pChipEft->pFreqShiftPara->En = ctrl.En;
                uint32_t BuffSize;
                BuffSize = FreqShift_MaxBuff(pChipEft->pFreqShiftStru, blocksize);
                pChipEft->pFreqShiftBuff = MEM_Malloc(BuffSize);
                if(NULL == pChipEft->pFreqShiftBuff)
                {
                    pChipEft->pFreqShiftPara->En = 0;
                    break;
                }
                FreqShiftNew (pChipEft->pFreqShiftStru, pChipEft->pFreqShiftPara, blocksize);
                FreqShiftInit(pChipEft->pFreqShiftStru, (void *)pChipEft->pFreqShiftBuff, blocksize);
            } else {
                pChipEft->pFreqShiftPara->Bw = ctrl.BW;
                pChipEft->pFreqShiftPara->dF = (int8_t)ctrl.dF;
                pChipEft->pFreqShiftPara->En = ctrl.En;
                FreqShiftNew (pChipEft->pFreqShiftStru, pChipEft->pFreqShiftPara, blocksize);
            }
        }
        break;
        #endif


        #if(EFFECT_COMPANDER_EN)
        case DSPREG_IDX(ExpandorCfg0):
        {
            if (0 == pDSPAll->bs.ExpandorCfg0.En)
            {
                pChipEft->pExpanderPara->en = 0;
                CompanderNew(pChipEft->pExpanderStru, pChipEft->pExpanderPara);
                break;
            }

            if (0 == pChipEft->pExpanderPara->en)
            {
                uint32_t size0 = sizeof(CompanderPara_t);
                uint32_t size1 = sizeof(CompanderStru_t);
                nds32_set_q31(0, (q31_t *)pChipEft->pExpanderPara, (size0 >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pExpanderStru, (size1 >> 2));
                pChipEft->pExpanderPara->gAT_Ms = pDSPAll->bs.ExpandorCfg1.gAT_Ms;
                pChipEft->pExpanderPara->gRT_Ms = pDSPAll->bs.ExpandorCfg1.gRT_Ms;
            }

            int8_t tmp = (int8_t)pDSPAll->bs.ExpandorCfg0.point_dB;
            pChipEft->pExpanderPara->point_dB = 0.5f * tmp;
            pChipEft->pExpanderPara->soft = pDSPAll->bs.ExpandorCfg0.soft;
            pChipEft->pExpanderPara->compand = 1;
            pChipEft->pExpanderPara->fs_Hz = Fs;
            pChipEft->pExpanderPara->ratio  = 0.01f * pDSPAll->bs.ExpandorCfg0.ratio;
            pChipEft->pExpanderPara->ave_Ms = pDSPAll->bs.ExpandorCfg0.ave_Ms;
            pChipEft->pExpanderPara->en     = pDSPAll->bs.ExpandorCfg0.En;
            CompanderNew(pChipEft->pExpanderStru, pChipEft->pExpanderPara);
        }
        break;
        case DSPREG_IDX(ExpandorCfg1):
        {
            pChipEft->pExpanderPara->compand = 1;
            pChipEft->pExpanderPara->fs_Hz = Fs;
            pChipEft->pExpanderPara->gAT_Ms = pDSPAll->bs.ExpandorCfg1.gAT_Ms;
            pChipEft->pExpanderPara->gRT_Ms = pDSPAll->bs.ExpandorCfg1.gRT_Ms;
            CompanderNew(pChipEft->pExpanderStru, pChipEft->pExpanderPara);
        }
        break;
        #endif

		#if(EFFECT_AGC_EN)
		case DSPREG_IDX(AgcCfg0):
		{
			if (0 == pDSPAll->bs.AgcCfg0.En)
			{
				pChipEft->pAgcPara->en = 0;
				AgcNew(pChipEft->pAgcStru, pChipEft->pAgcPara);
				break;
			}

			if (0 == pChipEft->pAgcPara->en)
			{
				uint32_t size0 = sizeof(AgcPara_t);
				uint32_t size1 = sizeof(AgcStru_t);
				nds32_set_q31(0, (q31_t *)pChipEft->pAgcPara, (size0 >> 2));
				nds32_set_q31(0, (q31_t *)pChipEft->pAgcStru, (size1 >> 2));
				pChipEft->pAgcPara->gAT_Ms  = pDSPAll->bs.AgcCfg1.gAT_Ms;
				pChipEft->pAgcPara->gRT_Ms  = pDSPAll->bs.AgcCfg1.gRT_Ms;
				pChipEft->pAgcPara->ave_Ms  = pDSPAll->bs.AgcCfg2.ave_Ms;
				pChipEft->pAgcPara->hold_Ms = pDSPAll->bs.AgcCfg2.hold_Ms;
			}

			int8_t tmp = (int8_t)pDSPAll->bs.AgcCfg0.point_dB;
			int8_t tmp1 = (int8_t)pDSPAll->bs.AgcCfg0.gMax_dB;
			pChipEft->pAgcPara->point_dB = 0.5f * tmp;
			pChipEft->pAgcPara->gMax_dB  = 0.5f * tmp1;
			pChipEft->pAgcPara->fs_Hz    = Fs;
			pChipEft->pAgcPara->ratio    = 0.1f * pDSPAll->bs.AgcCfg0.ratio;
			pChipEft->pAgcPara->en       = pDSPAll->bs.AgcCfg0.En;
			AgcNew(pChipEft->pAgcStru, pChipEft->pAgcPara);
		}
		break;
		case DSPREG_IDX(AgcCfg1):
		{
			pChipEft->pAgcPara->fs_Hz  = Fs;
			pChipEft->pAgcPara->gAT_Ms = pDSPAll->bs.AgcCfg1.gAT_Ms;
			pChipEft->pAgcPara->gRT_Ms = pDSPAll->bs.AgcCfg1.gRT_Ms;
			AgcNew(pChipEft->pAgcStru, pChipEft->pAgcPara);
		}
		break;
		case DSPREG_IDX(AgcCfg2):
		{
			pChipEft->pAgcPara->fs_Hz   = Fs;
			pChipEft->pAgcPara->ave_Ms  = pDSPAll->bs.AgcCfg2.ave_Ms;
			pChipEft->pAgcPara->hold_Ms = pDSPAll->bs.AgcCfg2.hold_Ms;
			AgcNew(pChipEft->pAgcStru, pChipEft->pAgcPara);
		}
		break;
		#endif
        #if(EFFECT_ECHO_EN)
        case DSPREG_IDX(EchoCfg0) : {
            st_DSP_ECHO_CONFIG0 ctrl = pDSPAll->bs.EchoCfg0;

            if (0 == ctrl.En) {
                pChipEft->pVolEchoPara->dBorPct = VolPCT;
                pChipEft->pVolEchoPara->VolFL   = 0;
                pChipEft->pEchoPara->En = 0;
                VolumeNew(pChipEft->pVolEchoPara, pChipEft->pVolEchoStru);
                Echo_New (pChipEft->pEchoPara,    pChipEft->pEchoStru);
                MEM_Free(pChipEft->pEchoBuff);
                pChipEft->pEchoBuff = 0;
                break;
            }
            if (0 == pChipEft->pEchoPara->En)
            {
                nds32_set_q31(0, (q31_t *)pChipEft->pEchoPara, (sizeof(EchoPara_t) >> 2));
                nds32_set_q31(0, (q31_t *)pChipEft->pEchoStru, (sizeof(EchoStru_t) >> 2));
                pChipEft->pEchoPara->Fs_Hz        = (Fs / 3);
                pChipEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
                pChipEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
                pChipEft->pEchoPara->En           = ctrl.En;
                pChipEft->pEchoPara->DlyMax_Ms    = ctrl.MaxDelay_2MS * 2;

                uint32_t BuffSize;
                pChipEft->Prc512pOpen   = 1;
                BuffSize = Echo_MaxBuff(pChipEft->pEchoPara, pChipEft->pEchoStru);
                pChipEft->pEchoBuff = MEM_Malloc(BuffSize);
                if(NULL == pChipEft->pEchoBuff)
                {
                    pChipEft->pEchoPara->En = 0;
                    break;
                }
                Echo_New (pChipEft->pEchoPara, pChipEft->pEchoStru);
                Echo_Init(pChipEft->pEchoStru, (void *)pChipEft->pEchoBuff);
                float vol0  = 0.01f * (int8_t)pDSPAll->bs.EchoCfg1.WetLevel;
                pChipEft->pVolEchoPara->VolFL   = vol0;
                pChipEft->pVolEchoPara->dBorPct = VolPCT;
                VolumeNew(pChipEft->pVolEchoPara, pChipEft->pVolEchoStru);
            }
            else {
                pChipEft->pEchoPara->Fs_Hz        = (Fs / 3);
                pChipEft->pEchoPara->Dly_Ms       = ctrl.Delay_2MS * 2;
                pChipEft->pEchoPara->LoopRatio_dB = 0.5f * (int8_t)ctrl.LoopRatio;
                pChipEft->pEchoPara->En           = ctrl.En;
                Echo_New(pChipEft->pEchoPara, pChipEft->pEchoStru);
            }
        }break;
        case DSPREG_IDX(EchoCfg1) : {
            st_DSP_ECHO_CONFIG1 ctrl = pDSPAll->bs.EchoCfg1;
            float vol0  = 0.01f * ctrl.WetLevel;
            pChipEft->pVolEchoPara->dBorPct = VolPCT;

            if (ctrl.CloseReq) {
                pChipEft->pVolEchoPara->VolFL = 0;
                VolumeNew(pChipEft->pVolEchoPara, pChipEft->pVolEchoStru);
    //            DSPEft.closeReq[Close_Echo] = 1;
            } else {
                pChipEft->pVolEchoPara->VolFL   = vol0;
                VolumeNew(pChipEft->pVolEchoPara, pChipEft->pVolEchoStru);
            }
        }
        break;
        #endif

        default:
        {
        }
        break;
    }
}
