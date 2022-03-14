/*
 * HardCtrlModule.c
 *
 *  Created on: Mar 11, 2020
 *      Author: guoax
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "HardCtrlModule.h"
#include "reg_apb.h"
#include "effect_config.h"
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
const int32_t g_const_PeakDet3BandCoeff[4][10] = {
		{    70237,      140474,       70237,    524449853,  -256295344,       70237,      140474,       70237,    524449853,  -256295344},
		{262295163,  -524590327,   262295163,    524449853,  -256295344,   262295163,  -524590327,   262295163,    524449853,  -256295344},
		{ 13284859,    26569718,    13284859,    343498714,  -128202693,    13284859,    26569718,    13284859,    343498714,  -128202693},
		{185034216,  -370068431,   185034216,    343498714,  -128202693,   185034216,  -370068431,   185034216,    343498714,  -128202693}
};//Linkwitz-Riley filter
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
void new_patch_audio_dac_rail_ctrl(
    q31_t *pToDacL,
    q31_t *pToDacR,
    q31_t *tempbuff,
    uint32_t len)
{
    q31_t *TtempQ31 = tempbuff;
    q31_t *Ttemp1Q31 = tempbuff + len;
    q31_t tmp;
    uint32_t ii;
    q31_t pTempL[4], pTempR[4]; //only support 16 samples

    uint16_t final_len = len;

    if (USB_DAC_FS >= 9) //96k
    {
        pTempL[0] = pToDacL[0];
        pTempL[1] = pToDacL[4];
        pTempL[2] = pToDacL[8];
        pTempL[3] = pToDacL[12];

        pTempR[0] = pToDacR[2]; //
        pTempR[1] = pToDacR[6];
        pTempR[2] = pToDacR[10];
        pTempR[3] = pToDacR[14];
        final_len = 4;

        nds32_abs_q31(pTempL, TtempQ31, final_len);
        peak_det(TtempQ31, TtempQ31, &g_DacStereoL_PeakState, g_DacStereo_PeakAttack, g_DacStereo_PeakRelease, final_len);
        nds32_abs_q31(pTempR, Ttemp1Q31, final_len);
        peak_det(Ttemp1Q31, Ttemp1Q31, &g_DacStereoR_PeakState, g_DacStereo_PeakAttack, g_DacStereo_PeakRelease, final_len);
    }
    else
    {
        nds32_abs_q31(pToDacL, TtempQ31, len);
        peak_det(TtempQ31, TtempQ31, &g_DacStereoL_PeakState, g_DacStereo_PeakAttack, g_DacStereo_PeakRelease, len);
        nds32_abs_q31(pToDacR, Ttemp1Q31, len);
        peak_det(Ttemp1Q31, Ttemp1Q31, &g_DacStereoR_PeakState, g_DacStereo_PeakAttack, g_DacStereo_PeakRelease, len);
    }


    if (g_classg_rail_ctrl_en)
    {
        for (ii = 0; ii < final_len; ii++)
        {

            tmp = Ttemp1Q31[ii] > TtempQ31[ii] ? Ttemp1Q31[ii] : TtempQ31[ii];

            if (0 == g_classg_rail_ctrl_old)
            {
                if (tmp > g_classg_rail_switch_volt_high)
                {
                    g_classg_rail_ctrl = 1;
                }
                else
                {
                    g_classg_rail_ctrl = 0;
                }
                g_classg_rail_cnt = 0;
            }
            else
            {
                if (tmp < g_classg_rail_switch_volt_low && g_classg_rail_cnt < g_classg_rail_high_hold)
                {
                    g_classg_rail_ctrl = 1;
                    g_classg_rail_cnt++;
                }
                else if (tmp < g_classg_rail_switch_volt_low)
                {
                    g_classg_rail_ctrl = 0;
                    g_classg_rail_cnt = 0;
                }
                else
                {
                    g_classg_rail_ctrl = 1;
                    g_classg_rail_cnt = 0;
                }
            }

            if (g_classg_rail_ctrl) //high rail, cp clk=185kHz @ cp cap=4.7uF
            {
                //charge pump clk: 0:1.5M, 1:3.1M, 2:375k, 3:750k, 4:25k, 5:50k, 6:100k, 7:185kHz
                apb_power_pd_ctrl1_cg_cp_freq_sel_setf(ucHighRailCpClk);
            }
            else //low rail, cp clk=375kHz @ cp cap=4.7uF
            {
                //charge pump clk: 0:1.5M, 1:3.1M, 2:375k, 3:750k, 4:25k, 5:50k, 6:100k, 7:185kHz
                apb_power_pd_ctrl1_cg_cp_freq_sel_setf(ucLowRailCpClk);
            }
            apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(g_classg_rail_ctrl);
//           apb_power_pd_ctrl1_cg_vdd_rail_sel_setf(1);

            //      if(g_classg_rail_ctrl)
            //      {
            //          DEBUG_GPIO6_SET();
            //      }
            //      else
            //      {
            //          DEBUG_GPIO6_CLR();
            //      }
            g_classg_rail_ctrl_old = g_classg_rail_ctrl;

        }
    }
}
#if(EFFECT_POST_SIDETONE_EN)
void SideToneNew(SideToneStru_t *pStru, SideTonePara_t *pPara)
{
	if(NULL == pPara || NULL == pStru){
		return;
	}
	if(0 == pPara->En){
		pStru->En = 0;
		return;
	}
	VolumeNew(&pPara->UsbInVolPara,  &pStru->UsbInVol);
	VolumeNew(&pPara->UsbOutVolPara, &pStru->UsbOutVol);
	pStru->En = pPara->En;
}

void SideToneAdd(SideToneStru_t  *pStru,         MusicDuckingStru_t *pMDStru,
		          const int32_t  *pUsbInL,            const int32_t *pUsbInR,
		                int32_t  *pUsbOutL,                 int32_t *pUsbOutR,
		                int32_t  *pTmpLenOutx3,            uint32_t  LenOut,  uint32_t LenIn)
{
	int32_t  *pTmpL = pTmpLenOutx3;
	int32_t  *pTmpR = pTmpL + LenOut;
	int32_t  *pMDvol = pTmpR + LenOut;
	uint32_t ii;
	uint32_t jj=0;
	if(USB_DAC_FS == 1 || USB_DAC_FS == 4 || USB_DAC_FS == 7 || 0 == LenIn)
	{
		return;
	}
	uint32_t Upx = LenOut/LenIn;
	if(0 == pStru->En || LenOut != LenIn*Upx || Upx > 3)
	{
		return;
	}
	if(Upx == 2)
	{
		for(ii=0; ii<LenIn; ii++)
		{
			pTmpL[jj  ] =  pUsbInL[ii];
			pTmpR[jj++] =  pUsbInR[ii];
			pTmpL[jj  ] =  pUsbInL[ii];
			pTmpR[jj++] =  pUsbInR[ii];
		}
	}
	else if(Upx == 3)
	{
		for(ii=0; ii<LenIn; ii++)
		{
			pTmpL[jj  ] =  pUsbInL[ii];
			pTmpR[jj++] =  pUsbInR[ii];
			pTmpL[jj  ] =  pUsbInL[ii];
			pTmpR[jj++] =  pUsbInR[ii];
			pTmpL[jj  ] =  pUsbInL[ii];
			pTmpR[jj++] =  pUsbInR[ii];
		}
	}
	else
	{
		nds32_dup_q31((int32_t *)pUsbInL, pTmpL, LenOut);
		nds32_dup_q31((int32_t *)pUsbInR, pTmpR, LenOut);
	}
	MusicDuckingCtrl(pTmpL, pMDStru,  pMDvol, LenOut);
//	VolumeStereo(pTmpL, pTmpR, &pStru->UsbInVol,  LenOut);

	MusicDucking(pUsbOutL,  pUsbOutR,  pMDvol, pMDStru,   LenOut);
//	VolumeStereo(pUsbOutL,  pUsbOutR,  &pStru->UsbOutVol, LenOut);

	nds32_add_q31(pUsbOutL, pTmpL, pUsbOutL, LenOut);
	nds32_add_q31(pUsbOutR, pTmpR, pUsbOutR, LenOut);


}

#endif

void PeakDet3BandNew(PeakDet3BandPara_t *pPara, PeakDet3BandStru_t *pInst)
{
	if(NULL == pPara || NULL == pInst)
	{
		return;
	}
	VolumeDetNew(&pPara->st_PeakDetPara[0], &pInst->st_PeakDet[0]);
	VolumeDetNew(&pPara->st_PeakDetPara[1], &pInst->st_PeakDet[1]);
	VolumeDetNew(&pPara->st_PeakDetPara[2], &pInst->st_PeakDet[2]);
	pInst->En = pPara->En;

}

void PeakDet3Band(PeakDet3BandStru_t *pStru, int32_t *pDataL, int32_t *pDataR, int32_t *pTmpLenx2, int32_t Len)
{
	if(pStru == NULL)
	{
		return;
	}
	if(0 == pStru->En)
	{
		pStru->st_PeakDet[0].dBoutEn16 = 0;
		pStru->st_PeakDet[1].dBoutEn16 = 0;
		pStru->st_PeakDet[2].dBoutEn16 = 0;
		return;
	}
	int32_t *pTmpData  = pTmpLenx2;
	int32_t *pTmpData1 = pTmpData  + Len;
	nds32_bq_df1_32x64_q31_t Inst = {
		    . nstage = 2,
		    . state  = pStru->Lpf0State,
		    . coeff  = (int32_t *)&g_const_PeakDet3BandCoeff[0][0],
		    . shift  = 3,
	};
//	nds32_add_q31   (pDataL, pDataR,   pTmpData,  Len);
	nds32_dup_q31   (pDataL, pTmpData, Len);

	/*LF 0~250Hz*/
	nds32_bq_df1_32x64_q31(&Inst,  pTmpData, pTmpData1, Len);
	VolumeDet(&pStru->st_PeakDet[0], pTmpData1, pTmpData1, Len);

	/*MF 250~4kHz*/
	Inst.coeff = (int32_t *)&g_const_PeakDet3BandCoeff[1][0];
	Inst.state = pStru->Hpf0State;
	nds32_bq_df1_32x64_q31(&Inst,  pTmpData,  pTmpData, Len);

	nds32_bq_df1_q31_t Inst1 = {
		    . nstage = 2,
		    . state  = pStru->Lpf1State,
		    . coeff  = (int32_t *)&g_const_PeakDet3BandCoeff[2][0],
		    . shift  = 3,
	};
	nds32_bq_df1_q31(&Inst1,  pTmpData,  pTmpData1, Len);
	VolumeDet(&pStru->st_PeakDet[1], pTmpData1, pTmpData1, Len);

	/*HF 4kHz~20kHz*/
	Inst1.coeff = (int32_t *)&g_const_PeakDet3BandCoeff[3][0];
	Inst1.state = pStru->Hpf1State;
	nds32_bq_df1_q31(&Inst1,  pTmpData,  pTmpData1, Len);
	VolumeDet(&pStru->st_PeakDet[2], pTmpData1, pTmpData1, Len);
}
