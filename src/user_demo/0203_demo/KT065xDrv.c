
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "KT065xDrv.h"
#include <stdlib.h>

#define  Delay_Time     //

/***************************** Extern *******************************/


//strI2s chipAI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_RIGHT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//strI2s chipBI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_LEFT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//

//strI2s chipBI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_MASTER,KT_I2S_STRREO,KT_I2S_RIGHT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//

//strI2s chipAI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_LEFT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};

static void Pll_Band_Cali(const SoftI2C_t *I2CDef, uint8_t CLl, uint8_t CLh);
static void PLL_Reset(const SoftI2C_t *I2CDef);


#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
       static void selXtal(const SoftI2C_t *I2CDef, Bool xtalSel);
       static void caclXtal(const SoftI2C_t *I2CDef, int32_t Freq);
    #endif
#endif


void KT_Bus_Write(const SoftI2C_t *I2CDef, uint16_t RegAddr, uint8_t Byte_Data)
{
	SoftI2C_WriteReg(I2CDef, RegAddr, Byte_Data);
}


uint8_t KT_Bus_Read(const SoftI2C_t *I2CDef, uint16_t RegAddr)
{
	uint32_t Byte_Data;
	SoftI2C_ReadReg(I2CDef, RegAddr, &Byte_Data);
	return (Byte_Data&0xff);
}


uint8_t KT_WirelessMicRx_PreInit(const SoftI2C_t *I2CDef)
{
    uint8_t regx;
    uint8_t i;

    for (i = 0; i < INIT_FAIL_TH; i++)
    {
        regx = KT_Bus_Read(I2CDef, 0x0192);       //Read Manufactory ID
        if (regx == 0x4B)
        {
            #ifdef KT0656M
        	    regx = KT_Bus_Read(I2CDef, 0x002d); //dcdc
				KT_Bus_Write(I2CDef, 0x002d,(regx & ~0x04)|(DCDC_EN<<2));
			#endif
				KT_WirelessMicRx_Volume(I2CDef, 0);
            return(1);
        }
    }
    return(0);
}


uint8_t KT_WirelessMicRx_Init(const SoftI2C_t *I2CDef)
{
    uint8_t regx;

    while(!(KT_Bus_Read(I2CDef, 0x007F) & 0x01)); //power_on finish

//    regx = KT_Bus_Read(I2CDef, 0x007F);
//    KT_Bus_Write(I2CDef, 0x007F,(regx & 0xfe)); //

	regx = KT_Bus_Read(I2CDef, 0x010f);//FIRMWARE_VERSION
	if((regx!=0x10)&&(regx!=0x11))
		return 0;

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,(regx&0x1f)|(XTAL_SEL1<<7)|(XTAL_SEL2<<6)|(HLSI_INV<<5)); //hlsi

	regx = KT_Bus_Read(I2CDef, 0x001f);
	KT_Bus_Write(I2CDef, 0x001f,(regx&0x1f)|0x40); //0.4V

	KT_Bus_Write(I2CDef, 0x000d,0xcf); //6mA

	//
	KT_Bus_Write(I2CDef, 0x0109,0x90); //

//	regx = KT_Bus_Read(I2CDef, 0x0224);
//	KT_Bus_Write(I2CDef, 0x0224,(regx&0x9f)|0x20); //

#ifdef AUTOMUTE_EN

    KT_Bus_Write(I2CDef, 0x0082,0x89); //fast_rssi_mute_th=0x89
	//auto_mute control
    regx = KT_Bus_Read(I2CDef, 0x0081);
    KT_Bus_Write(I2CDef, 0x0081,(regx & 0x8f) | (FAST_RSSI_MUTE_EN<<6) |
                 (FAST_RSSI_PD_MUTE_EN<<5) | (SUPER_RSSI_MUTE_EN<<4));

    KT_Bus_Write(I2CDef, 0x0079,AUTOMUTE_SNR_LOWTH);
    KT_Bus_Write(I2CDef, 0x007a,AUTOMUTE_SNR_HIGHTH);

	regx = KT_Bus_Read(I2CDef, 0x0201);
    KT_Bus_Write(I2CDef, 0x0201,regx|0x80); //NBW=1
//  KT_Bus_Write(I2CDef, 0x0201,regx&~0x80); //NBW=0

    regx = KT_Bus_Read(I2CDef, 0x0100);
//  KT_Bus_Write(I2CDef, 0x0100,(regx & 0xDF) | (0<<5)); //automute_snr_en=0
    KT_Bus_Write(I2CDef, 0x0100,(regx & 0xDF) | (1<<5)); //automute_snr_en=1


    regx = KT_Bus_Read(I2CDef, 0x0100);

	if(PilotFlag)
	{
		KT_Bus_Write(I2CDef, 0x0100,regx|0x80);    //
	}
	else
	{
		KT_Bus_Write(I2CDef, 0x0100,regx&0x7f);   //
	}

	 regx = KT_Bus_Read(I2CDef, 0x0225); //DC_NOTCH_MUTE_EN=1
     KT_Bus_Write(I2CDef, 0x0225,regx&0xf1);

//     KT_Bus_Write(I2CDef, 0x0225,0x00);         // disable automute

//    regx = KT_Bus_Read(I2CDef, 0x0053);
//    KT_Bus_Write(I2CDef, 0x0053,regx|0x10); //BPSK_PKG_SYN_INT_EN=1
#else
	 regx = KT_Bus_Read(I2CDef, 0x0225); //DC_NOTCH_MUTE_EN=0
     KT_Bus_Write(I2CDef, 0x0225,regx&0xf0);
#endif

#ifdef SQUEAL_EN
    regx = KT_Bus_Read(I2CDef, 0x026f);
    KT_Bus_Write( 0x026f, (regx & 0xC0) | (SQUEAL_ELIM_EN << 5) |(SQEUAL_DET_EN << 3) | (FNOTCH_NOTRESP_TH << 2) | (N_OCTAVE << 0));
    regx = KT_Bus_Read(I2CDef, 0x0270);
    KT_Bus_Write( 0x0270, (regx & 0x00) | (FFT_R_TH << 4) | (FRAME_NUM_TH << 0));
    regx = KT_Bus_Read(I2CDef, 0x0271);
    KT_Bus_Write( 0x0271, (regx & 0x00) | (PMAX_HITH << 4) | (PMAX_LOWTH << 0));
    regx = KT_Bus_Read(I2CDef, 0x0272);
    KT_Bus_Write( 0x0272, (regx & 0x00) | (FDIFF_HITH << 4) | (FDIFF_LOWTH << 0));
#endif

    //config for bpsk
    regx = KT_Bus_Read(I2CDef, 0x241);
    KT_Bus_Write(I2CDef, 0x241,(regx & 0x3f) | (AUXDATA_EN<<7)|(BPSK_NEW_MODE<<6)); //bpsk enable bpsk new mode
    regx = KT_Bus_Read(I2CDef, 0x243);
    KT_Bus_Write(I2CDef, 0x243,(regx & 0x88) | (AUX_CARRY_NUM<<4)| CARRY_NUM_TH);  //
    regx = KT_Bus_Read(I2CDef, 0x245);
    KT_Bus_Write(I2CDef, 0x245,0x22); //

    regx = KT_Bus_Read(I2CDef, 0x0200);
    KT_Bus_Write(I2CDef, 0x0200,(regx&0x8f)|(ADJUST_GAIN<<4)); //adjust gain =50kHz

	regx = KT_Bus_Read(I2CDef, 0x010e);		  	 //
	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		KT_Bus_Write(I2CDef, 0x010e,regx&0xfe);
	}
	else
	{
		KT_Bus_Write(I2CDef, 0x010e,regx|0x01);
	}

	regx = KT_Bus_Read(I2CDef, 0x0087);
	KT_Bus_Write(I2CDef, 0x0087,regx&~0x08);

    regx = KT_Bus_Read(I2CDef, 0x0217); //
    KT_Bus_Write(I2CDef, 0x0217,(regx&0x3f)|(AFC_RNG<<6)|0x01);	// +/-60kHz;

	KT_Bus_Write(I2CDef, 0x0218,0x02); //afc_en=1  AFC_FROZEN=0
//	KT_Bus_Write(I2CDef, 0x0218,0x00); //afc_en=0

    regx = KT_Bus_Read(I2CDef, 0x0256); //comp_tc=0
    KT_Bus_Write(I2CDef, 0x0256,(regx&0x8d)|(COMP_TC<<4)|(EXPAND_MESH<<1));        //

	regx = KT_Bus_Read(I2CDef, 0x002d); //vtr_momitor_en=1
    KT_Bus_Write(I2CDef, 0x002d,regx|0x08);

	regx = KT_Bus_Read(I2CDef, 0x0010); //ref_vtr_vth_sel=1
    KT_Bus_Write(I2CDef, 0x0010,regx|0x80);

	regx = KT_Bus_Read(I2CDef, 0x0030);
	KT_Bus_Write(I2CDef, 0x0030,regx & ~0x80);//LO_LOCK_DET_PD=0

//	regx = KT_Bus_Read(I2CDef, 0x0133);
//    KT_Bus_Write(I2CDef, 0x0133,(regx|0x20)); //PLL_UNLOCK_EN=1

    regx = KT_Bus_Read(I2CDef, 0x0133);
    KT_Bus_Write(I2CDef, 0x0133,(regx|0x40)); //dll_rst_en

//	regx = KT_Bus_Read(I2CDef, 0x010e);
//    KT_Bus_Write(I2CDef, 0x010e,(regx|0x06)); //

	regx = KT_Bus_Read(I2CDef, 0x010e); //
    KT_Bus_Write(I2CDef, 0x010e,regx&0xf7);

	//AUDIO_SEL
	regx = KT_Bus_Read(I2CDef, 0x021c);
    KT_Bus_Write(I2CDef, 0x021c,regx&0xcf);

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,(regx|0x10)); //LOBAND_CALI_SCAN_EN=1 for fasttune
	while(1)
	{
		Delay_Ms(10);
		if(0==(0x10&KT_Bus_Read(I2CDef, 0x0108)))
		break;
	}
	#ifdef KT0655M
	regx = KT_Bus_Read(I2CDef, 0x003a);
	KT_Bus_Write(I2CDef, 0x003a,(regx & 0x1f));	//line in
	Delay_ms(10);
	regx = KT_Bus_Read(I2CDef, 0x003c);
	KT_Bus_Write(I2CDef, 0x003c,(regx & 0x7f));	//au_dig_rst=0
	Delay_ms(15);
	regx = KT_Bus_Read(I2CDef, 0x0330);
	KT_Bus_Write(I2CDef, 0x0330,(regx | 0x3f));	//line_in en=1

	regx = KT_Bus_Read(I2CDef, 0x0234);
	KT_Bus_Write(I2CDef, 0x0234,(regx | 0x04));//

	regx = KT_Bus_Read(I2CDef, 0x0331);
	KT_Bus_Write(I2CDef, 0x0331,(regx & 0xfe)|LINEIN_AGC_DIS);//LINEIN_AGC_DIS

	regx = KT_Bus_Read(I2CDef, 0x0333);
	KT_Bus_Write(I2CDef, 0x0333,(regx & ~0x30)|(COMPEN_GAIN<<4));//COMPEN_GAIN

	regx = KT_Bus_Read(I2CDef, 0x0330);
	KT_Bus_Write(I2CDef, 0x0330,(regx & 0xc1)|(LINEIN_LOCAL_VOL_CTRL<<1));//COMPEN_GAIN

	regx = KT_Bus_Read(I2CDef, 0x0334);
	KT_Bus_Write(I2CDef, 0x0334,(regx & ~0x18)|(PGA_GAIN_SEL<<3));//PGA_GAIN_SEL

	regx = KT_Bus_Read(I2CDef, 0x0336);
	KT_Bus_Write(I2CDef, 0x0336,(regx & 0xc0)|(SLNC_MUTE_TIME<<1)|SLNC_MUTE_DIS);//SLNC_MUTE_DIS  SLNC_MUTE_TIME

	KT_Bus_Write(I2CDef, 0x0337,(SLNC_MUTE_LOW_LEVEL<<4)|SLNC_MUTE_HIGH_LEVEL);//SLNC_MUTE_LEVEL

	KT_Bus_Write(I2CDef, 0x0339,(ALC_DIS<<7)|ALC_VMAX);	 //	ALC_DIS ALC_VMAX

	regx = KT_Bus_Read(I2CDef, 0x033a);
	KT_Bus_Write(I2CDef, 0x033a,(regx & ~0x08)|(ALC_SOFTKNEE<<3));//ALC_SOFTKNEE
	#endif

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,(regx|0x10)); //LOBAND_CALI_SCAN_EN=1 for fasttune
	while(1)
	{
		Delay_Ms(10);                          //

		if(0==(0x10&KT_Bus_Read(I2CDef, 0x0108)))
		break;
	}

	KT_Bus_Write(I2CDef, 0x010b,0x60);

    return(1);
}


uint8_t KT_WirelessMicRx_Volume(const SoftI2C_t *I2CDef, uint8_t cVolume)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x0201);
    KT_Bus_Write(I2CDef, 0x0201, (regx & 0xE0) | (cVolume));

    return(1);
}

uint8_t KT_WirelessMicRx_GetVolume(const SoftI2C_t *I2CDef)
{
	return(KT_Bus_Read(I2CDef, 0x0201)&0x1f);
}


void KT_WirelessMicRx_Tune(const SoftI2C_t *I2CDef, uint32_t Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;
	uint8_t LO_LOCK_DET_PD_SAVE;
	uint8_t state;

//	regx = KT_Bus_Read(I2CDef, 0x0133);
//	KT_Bus_Write(I2CDef, 0x0133,(regx&~0x60)); //dll_rst_en=0  I_PLL_UNLOCK_EN=0
//	regx = KT_Bus_Read(I2CDef, 0x0054);
//	KT_Bus_Write(I2CDef, 0x0054,regx&~0x18);//PL

#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(I2CDef, Freq);//select xtal
	#else
		oldCaclXtal(I2CDef, Freq);
	#endif
#endif

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,regx & ~0x08); //SCAN_MODE=0;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(I2CDef, 0x0045,Freq_H);
    KT_Bus_Write(I2CDef, 0x0046,Freq_M);

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,(regx & 0x0F) | Freq_L );

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		regx = KT_Bus_Read(I2CDef, 0x0053);
		KT_Bus_Write(I2CDef, 0x0053,regx&~0x40);  //rfamp_int_en=0
	}

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,regx | 0x01); //chan_valid=1;

#ifdef  Delay_Time
		Delay_Ms(1);                          //
#endif

    while (!(KT_Bus_Read(I2CDef, 0x0061) & 0x01)); //PLL done

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		regx = KT_Bus_Read(I2CDef, 0x0042);
		KT_Bus_Write(I2CDef, 0x0042,regx | 0x04);//S_DSP_RST

		regx = KT_Bus_Read(I2CDef, 0x0042);
		KT_Bus_Write(I2CDef, 0x0042,regx | 0x10);//S_PLL_SDM_RST

		regx = KT_Bus_Read(I2CDef, 0x0030);
		LO_LOCK_DET_PD_SAVE = regx&0x80;
		KT_Bus_Write(I2CDef, 0x0030,regx | 0x80);//LO_LOCK_DET_PD=1

		regx = KT_Bus_Read(I2CDef, 0x0017); //double+16MHz/V locoarse_var_sel
		state=regx&0x07;
		if(state >= 3)
		{
			state = 7;
		}
		else
		{
			state = (state<<1) + 3;
		}
		regx = (regx&0xf8)|state;
		KT_Bus_Write(I2CDef, 0x0017, regx); //write locoarse/lofine_var_sel

		Pll_Band_Cali(I2CDef, 0, 255);

		PLL_Reset(I2CDef);

		regx = KT_Bus_Read(I2CDef, 0x0042);
		KT_Bus_Write(I2CDef, 0x0042,regx & ~0x10);//C_PLL_SDM_RST

		regx = KT_Bus_Read(I2CDef, 0x0042);
		KT_Bus_Write(I2CDef, 0x0042,regx & ~0x04);//C_DSP_RST

#ifdef  Delay_Time
		Delay_Ms(10);                          //
#endif

		regx = KT_Bus_Read(I2CDef, 0x0030);
		KT_Bus_Write(I2CDef, 0x0030,(regx & ~0x80)|LO_LOCK_DET_PD_SAVE);//LO_LOCK_DET_PD recovery

	//	regx = KT_Bus_Read(I2CDef, 0x0133);
	//    KT_Bus_Write(I2CDef, 0x0133,(regx|0x60)); // dll_rst_en=1 I_PLL_UNLOCK_EN=1

		if(KT_WirelessMicRx_GetSNR(I2CDef)>AUTOMUTE_SNR_LOWTH)
		{
			regx = KT_Bus_Read(I2CDef, 0x0087);			//SOFT_SNR_MUTE
			KT_Bus_Write(I2CDef, 0x0087,regx&~0x02);
		}
	}
	#ifdef I2S_EN
//	    KT_WirelessMicRx_SAIInit(I2CDef, &chipAI2sConfig);
//		KT_Bus_Write(I2CDef, 0x0052,0x01); //i2s_slave_en = 1
//		KT_Bus_Write(I2CDef, 0x004d,0x01); //
//		regx = KT_Bus_Read(I2CDef, 0x004d);
//		KT_Bus_Write(I2CDef, 0x004d,regx|0x80); //unlock_tw_cfg_rdy = 1
//        regx = KT_Bus_Read(I2CDef, 0x0050);
//        KT_Bus_Write(I2CDef, 0x0050,regx|0x40); //i2s_slave_sync_en=1
//        regx = KT_Bus_Read(I2CDef, 0x0052);
//        KT_Bus_Write(I2CDef, 0x0052,regx|0x08); //i2ss_pad_sdout_oen=1
	#endif
}

void KT_WirelessMicRx_FastTune(const SoftI2C_t *I2CDef, uint32_t Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;

#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(I2CDef, Freq);//select xtal
	#else
		oldCaclXtal(I2CDef, Freq);
	#endif
#endif

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,regx | 0x08); //SCAN_MODE=1;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(I2CDef, 0x0045,Freq_H);
    KT_Bus_Write(I2CDef, 0x0046,Freq_M);

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,(regx & 0x0F) | Freq_L );

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		regx = KT_Bus_Read(I2CDef, 0x0053);
		KT_Bus_Write(I2CDef, 0x0053,regx&~0x40);  //rfamp_int_en=0
	}

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,regx | 0x01); //chan_valid=1;

#ifdef  Delay_Time
		Delay_Ms(1);                          //
#endif

    while (!(KT_Bus_Read(I2CDef, 0x0061) & 0x01)); //PLL done
// 	#ifdef I2S_EN
//			KT_WirelessMicRx_SAIInit(I2CDef, &chipAI2sConfig);
//	#endif
	if(KT_WirelessMicRx_GetSNR(I2CDef)>AUTOMUTE_SNR_LOWTH)
	{
		regx = KT_Bus_Read(I2CDef, 0x0087);			//SOFT_SNR_MUTE
		KT_Bus_Write(I2CDef, 0x0087,regx&~0x02);
	}	
}

/************ 新增,将原FastTune拆分使56M跳过延时等待  *************/
void KT_WirelessMicRx_DoFastTune(const SoftI2C_t *I2CDef, uint32_t Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;

#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(I2CDef, Freq);//select xtal
	#else
		oldCaclXtal(I2CDef, Freq);
	#endif
#endif

	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,regx | 0x08); //SCAN_MODE=1;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(I2CDef, 0x0045,Freq_H);
    KT_Bus_Write(I2CDef, 0x0046,Freq_M);

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,(regx & 0x0F) | Freq_L );

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		regx = KT_Bus_Read(I2CDef, 0x0053);
		KT_Bus_Write(I2CDef, 0x0053,regx&~0x40);  //rfamp_int_en=0
	}

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,regx | 0x01); //chan_valid=1;
}

/************ 新增,将原FastTune拆分使56M跳过延时等待 *************/
uint8_t KT_WirelessMicRx_CheckFastTuneOK(const SoftI2C_t *I2CDef)
{
	uint8_t regx;
//    while (!(KT_Bus_Read(I2CDef, 0x0061) & 0x01)); //PLL done
	if((KT_Bus_Read(I2CDef, 0x0061) & 0x01)==0)
	{
		return 0;
	}
// 	#ifdef I2S_EN
//			KT_WirelessMicRx_SAIInit(I2CDef, &chipAI2sConfig);
//	#endif
	if(KT_WirelessMicRx_GetSNR(I2CDef)>AUTOMUTE_SNR_LOWTH)
	{
		regx = KT_Bus_Read(I2CDef, 0x0087);			//SOFT_SNR_MUTE
		KT_Bus_Write(I2CDef, 0x0087,regx&~0x02);
	}
	return 1;
}


void KT_WirelessMicRx_SW_Echo(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cEcho_En)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x0266);
    KT_Bus_Write(I2CDef, 0x0266,(regx & 0x08) | (cEcho_En<<7) | (ECHO_STRU<<6) |
                 (ECHO_GAIN_DOWN<<4) | (ECHO_GAIN_UP<<0));
}

void KT_WirelessMicRx_SetEcho(const SoftI2C_t *I2CDef, uint8_t cEcho_Ratio, uint8_t cEcho_Delay)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x0267);
    KT_Bus_Write(I2CDef, 0x0267,(regx & 0xE0) | (cEcho_Ratio<<0));

    regx = KT_Bus_Read(I2CDef, 0x0268);
    KT_Bus_Write(I2CDef, 0x0268,(regx & 0xE0) | (cEcho_Delay<<0));
}


void KT_WirelessMicRx_SW_Exciter(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cExciter_En)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x0269);
    KT_Bus_Write(I2CDef, 0x0269,(regx & 0x18) | (cExciter_En<<7) | (EXCITER_TUNE<<5) |
                 (EXCITER_DRIVE<<0));
}


void KT_WirelessMicRx_SetExciter(const SoftI2C_t *I2CDef, uint8_t cExciter_Odd, uint8_t cExciter_Even)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x026A);
    KT_Bus_Write(I2CDef, 0x026A,(regx & 0x88) | (cExciter_Odd<<4) | (cExciter_Even<<0));
}


void KT_WirelessMicRx_SW_Equalizer(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t cEqualizer_En)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x0257);
    KT_Bus_Write(I2CDef, 0x0257,(regx & 0xDF) | (cEqualizer_En<<5));
}


void KT_WirelessMicRx_SW_Diversity(const SoftI2C_t *I2CDef, KT065xM_FunctionState_t diversity_En)
{
    uint8_t regx;

    regx = KT_Bus_Read(I2CDef, 0x021c); //
    if(diversity_En)
    {
        KT_Bus_Write(I2CDef, 0x021c,regx|0x40);
    }
    else
    {
        KT_Bus_Write(I2CDef, 0x021c,regx&~0x40);
    }
}


void KT_WirelessMicRx_SetEqualizer(const SoftI2C_t *I2CDef, KT065xM_EQFreq_t cEqualizer_Frq, KT065xM_EQGain_t cEqualizer_Gain)
{ 
    uint8_t regx_1 = 0;

    if(0 == cEqualizer_Frq)
    {
        regx_1 = KT_Bus_Read(I2CDef, 0x0257 + cEqualizer_Frq);
        regx_1 &= 0x20;
        KT_Bus_Write(I2CDef, 0x0257 + cEqualizer_Frq, cEqualizer_Gain | regx_1);
    }
    else
    {
        KT_Bus_Write(I2CDef, 0x0257 + cEqualizer_Frq, cEqualizer_Gain);
    }
}


uint8_t KT_WirelessMicRx_GetAF(const SoftI2C_t *I2CDef)
{
    return( KT_Bus_Read(I2CDef, 0x0209) & 0x0F );
}


uint8_t KT_WirelessMicRx_GetRSSI(const SoftI2C_t *I2CDef)
{
    return(KT_Bus_Read(I2CDef, 0x020C));
//    return(KT_Bus_Read(I2CDef, 0x0221));   //
}


uint8_t KT_WirelessMicRx_GetFastRSSI(const SoftI2C_t *I2CDef)
{
    return(KT_Bus_Read(I2CDef, 0x020A));
//    return(KT_Bus_Read(I2CDef, 0x0222));    // Slave
}

uint8_t KT_WirelessMicRx_GetSNR(const SoftI2C_t *I2CDef)
{
    return(KT_Bus_Read(I2CDef, 0x020D));
//    return(KT_Bus_Read(I2CDef, 0x0223));         // Slave
}

uint8_t KT_WirelessMicRx_Automute(const SoftI2C_t *I2CDef)
{
    uint8_t muteFlag;

    muteFlag = KT_Bus_Read(I2CDef, 0x0088);
    return( muteFlag&0x01);
}


uint8_t KT_WirelessMicRx_CheckAUXCH(const SoftI2C_t *I2CDef)
{
    uint8_t regx;

	regx = KT_Bus_Read(I2CDef, 0x0057);
	if(regx&0x10) //pkg_sync int
	{
		KT_Bus_Write(I2CDef, 0x0057, regx |0x10);
		regx = KT_Bus_Read(I2CDef, 0x0209);
		if(regx&0x40)
			return PKGSYNC;
		else
			return NON_PKGSYNC;
	}
	return NON_PKGSYNC;
}

void KT_WirelessMicRx_GetAUXCH(const SoftI2C_t *I2CDef, KT065xM_BpskData_t *BpskData)
{
	union un_Data_buf
	{
		uint8_t  Byte_Data_buf[8];
		uint16_t halfwordData_buf[4];
		uint32_t wordData_buf[2];
	};
	union un_Data_buf  Data_buf;
	SoftI2C_ReadRegs(I2CDef, 0x0248, Data_buf.Byte_Data_buf, 8);
	BpskData->Bpsk_Data_A = Data_buf.halfwordData_buf[0];
	BpskData->Bpsk_Data_B = Data_buf.halfwordData_buf[1];
	BpskData->Bpsk_Data_C = Data_buf.halfwordData_buf[2];
	BpskData->Bpsk_Data_D = Data_buf.halfwordData_buf[3];
}


uint8_t KT_WirelessMicRx_CheckPilot(const SoftI2C_t *I2CDef)
{
    return((KT_Bus_Read(I2CDef, 0x0209)>>7)&0x01);
}


static void Pll_Band_Cali(const SoftI2C_t *I2CDef, uint8_t CLl, uint8_t CLh)
{
    int32_t Tmp[2],I_VCOCNT_RES_2,I_VCOFREQ_REF;
	uint8_t regx,loVcoBandSelRead;

	regx = KT_Bus_Read(I2CDef, 0x005c);
    if(!(regx&0x40))
    {
        return;
    }
    regx = KT_Bus_Read(I2CDef, 0x0061);
	regx&=0xc7;
	regx|=0x28;					//O_VCOCNT_WIN(5);
    KT_Bus_Write(I2CDef, 0x0061, regx );

	regx = KT_Bus_Read(I2CDef, 0x001c); //S_LO_VCO_BAND_CALI_EN;
    KT_Bus_Write(I2CDef, 0x001c, regx|0x40 );

	regx = KT_Bus_Read(I2CDef, 0x001a);
	regx&=0xc0;
	regx|=0x20;					//O_LO_MMD_MC(32);
    KT_Bus_Write(I2CDef, 0x001a, regx );

	regx = KT_Bus_Read(I2CDef, 0x0061); //S_LOMC_SEL;
    KT_Bus_Write(I2CDef, 0x0061, regx|0x02);

    regx = KT_Bus_Read(I2CDef, 0x0016); //S_LO_DIV128_EN;
    KT_Bus_Write(I2CDef, 0x0016, regx|0x80);


//    Delay_ms(1);
	loVcoBandSelRead = KT_Bus_Read(I2CDef, 0x001e);
	if(loVcoBandSelRead<5)
	{
		KT_Bus_Write(I2CDef, 0x001e, CLl );//R_LO_VCO_BAND_SEL = CLl;
	}
	else
	{
		KT_Bus_Write(I2CDef, 0x001e, loVcoBandSelRead-5 );//R_LO_VCO_BAND_SEL = CLl;
	}    

	regx = KT_Bus_Read(I2CDef, 0x0042); //C_VCOCNT_RST;
    KT_Bus_Write(I2CDef, 0x0042, regx&~0x20);

	regx = KT_Bus_Read(I2CDef, 0x0061);
    KT_Bus_Write(I2CDef, 0x0061, regx|0x40 );  //S_VCOCNT_START;


    while(!(0x80&KT_Bus_Read(I2CDef, 0x0064)));//while(!I_VCOCNT_RDY);

	I_VCOCNT_RES_2=(0x0f & KT_Bus_Read(I2CDef, 0x0064));
	I_VCOCNT_RES_2<<=8;
	I_VCOCNT_RES_2|=KT_Bus_Read(I2CDef, 0x0065);
	I_VCOCNT_RES_2<<=8;
	I_VCOCNT_RES_2|=KT_Bus_Read(I2CDef, 0x0066);
	I_VCOCNT_RES_2>>=2;

	I_VCOFREQ_REF=(0x03 & KT_Bus_Read(I2CDef, 0x0067));
	I_VCOFREQ_REF<<=8;
	I_VCOFREQ_REF|=KT_Bus_Read(I2CDef, 0x0068);
	I_VCOFREQ_REF<<=8;
	I_VCOFREQ_REF|=KT_Bus_Read(I2CDef, 0x0069);

    Tmp[1] = I_VCOCNT_RES_2 - I_VCOFREQ_REF;

	regx = KT_Bus_Read(I2CDef, 0x0042); //S_VCOCNT_RST
    KT_Bus_Write(I2CDef, 0x0042, regx|0x20 );

    while(1)
    {
        regx = KT_Bus_Read(I2CDef, 0x001e); //R_LO_VCO_BAND_SEL++
    	KT_Bus_Write(I2CDef, 0x001e, ++regx );

		regx = KT_Bus_Read(I2CDef, 0x0042); //C_VCOCNT_RST;
    	KT_Bus_Write(I2CDef, 0x0042, regx&~0x20 );

		regx = KT_Bus_Read(I2CDef, 0x0061);
    	KT_Bus_Write(I2CDef, 0x0061, regx|0x40 );  //S_VCOCNT_START;

        while(!(0x80&KT_Bus_Read(I2CDef, 0x0064)));//while(!I_VCOCNT_RDY);
        Tmp[0] = labs(Tmp[1]);
		I_VCOCNT_RES_2=(0x0f & KT_Bus_Read(I2CDef, 0x0064));
		I_VCOCNT_RES_2<<=8;
		I_VCOCNT_RES_2|=KT_Bus_Read(I2CDef, 0x0065);
		I_VCOCNT_RES_2<<=8;
		I_VCOCNT_RES_2|=KT_Bus_Read(I2CDef, 0x0066);
		I_VCOCNT_RES_2>>=2;

		I_VCOFREQ_REF=(0x03 & KT_Bus_Read(I2CDef, 0x0067));
		I_VCOFREQ_REF<<=8;
		I_VCOFREQ_REF|=KT_Bus_Read(I2CDef, 0x0068);
		I_VCOFREQ_REF<<=8;
		I_VCOFREQ_REF|=KT_Bus_Read(I2CDef, 0x0069);
        Tmp[1] = I_VCOCNT_RES_2 - I_VCOFREQ_REF;
        regx = KT_Bus_Read(I2CDef, 0x0042); //S_VCOCNT_RST
    	KT_Bus_Write(I2CDef, 0x0042, regx|0x20 );

        if((labs(Tmp[1]) >= Tmp[0]) && (Tmp[1] <= 0))
        {
            regx = KT_Bus_Read(I2CDef, 0x001e); //R_LO_VCO_BAND_SEL--
    		KT_Bus_Write(I2CDef, 0x001e, --regx );
            break;
        }
        else if(CLh != KT_Bus_Read(I2CDef, 0x001e))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    regx = KT_Bus_Read(I2CDef, 0x001c); //C_LO_VCO_BAND_CALI_EN
    KT_Bus_Write(I2CDef, 0x001c, regx&~0x40 );

	regx = KT_Bus_Read(I2CDef, 0x0016); //C_LO_DIV128_EN;
    KT_Bus_Write(I2CDef, 0x0016, regx&~0x80 );

	regx = KT_Bus_Read(I2CDef, 0x0061); //C_LOMC_SEL;
    KT_Bus_Write(I2CDef, 0x0061, regx&~0x02 );

    return;
}


static void PLL_Reset(const SoftI2C_t *I2CDef)
{
    uint8_t Tmp;
    uint8_t VrefSel;
	uint8_t regx,regy;

    if(0x08&KT_Bus_Read(I2CDef, 0x133))	  //I_PLL_RESET_EN
    {
        regx = KT_Bus_Read(I2CDef, 0x0016);  //Tmp = I_LO_KVCO_CALI_EN;
		Tmp = (regx>>6)&0x01;

        VrefSel = 0x07&KT_Bus_Read(I2CDef, 0x0016);//I_LO_KVCO_COARSE_VREF_SEL;

		regy=KT_Bus_Read(I2CDef, 0x0133);
		regy&=0x07;

		regx = KT_Bus_Read(I2CDef, 0x0018);
		regx&=~0x07;
		regx|=regy;
		KT_Bus_Write(I2CDef, 0x0018, regx );  //O_LO_KVCO_COARSE_VREF_SEL(I_LO_KVCO_COARSE_VREF_SEL_RST);

		regx = KT_Bus_Read(I2CDef, 0x0016);
		KT_Bus_Write(I2CDef, 0x0016, regx|0x40); 	//S_LO_KVCO_CALI_EN;

#ifdef  Delay_Time
		Delay_Ms(10);                          //
#endif

        if(Tmp)
        {
            regx = KT_Bus_Read(I2CDef, 0x0016);
			KT_Bus_Write(I2CDef, 0x0016, regx|0x40 ); 	//S_LO_KVCO_CALI_EN;
        }
        else
        {
            regx = KT_Bus_Read(I2CDef, 0x0016);
			KT_Bus_Write(I2CDef, 0x0016, regx&~0x40 ); 	//C_LO_KVCO_CALI_EN;
        }

		regx = KT_Bus_Read(I2CDef, 0x0018);
		KT_Bus_Write(I2CDef, 0x0018, (regx&0xf8)|VrefSel );  //O_LO_KVCO_COARSE_VREF_SEL(VrefSel);
    }
}


void KT_WirelessMicRx_SelectMS(const SoftI2C_t *I2CDef)
{
//	#ifdef DIVERSITY
//	uint8_t fastRssiSlave,fastRssiMaster;
//	fastRssiMaster=KT_Bus_Read(I2CDef, 0x020a);
//	fastRssiSlave=KT_Bus_Read(I2CDef, 0x0222);
//	if(fastRssiMaster>=fastRssiSlave)
//	{
//		MorSSelect=1;
//	}
//	else
//	{
//		MorSSelect=0;
//	}
//	#else
//		MorSSelect=1;
//	#endif
}


void rfIntCtl(const SoftI2C_t *I2CDef)
{
	uint8_t regx;

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)
	{
		if(!(0x7f&KT_Bus_Read(I2CDef, 0x005b)))
		{
			regx = KT_Bus_Read(I2CDef, 0x0053);
			KT_Bus_Write(I2CDef, 0x0053,regx&~0x40);
		}
		else
		{
			regx = KT_Bus_Read(I2CDef, 0x0053);
			KT_Bus_Write(I2CDef, 0x0053,regx|0x40);
		}
	}
}


void  pilotMuteRefresh(const SoftI2C_t *I2CDef)
{
	uint8_t regx;
	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)
	{
		if(((0x80&KT_Bus_Read(I2CDef, 0x0100))==0x80)&&((0x80&KT_Bus_Read(I2CDef, 0x0209))==0x00))
		{
			regx = KT_Bus_Read(I2CDef, 0x0087);
			KT_Bus_Write(I2CDef, 0x0087,(regx|0x04));
		}
		else
		{
			regx = KT_Bus_Read(I2CDef, 0x0087);
			KT_Bus_Write(I2CDef, 0x0087,(regx&~0x04));
		}
	}
}


void  KT_WirelessMicRx_SetMaxRfGain(const SoftI2C_t *I2CDef, uint8_t sel)//
{
	uint8_t regx;
	uint8_t rfGain;

	if(sel>3)
	sel=3;
	regx = KT_Bus_Read(I2CDef, 0x0102);
	regx&=0xfc;
	regx|=sel;
	KT_Bus_Write(I2CDef, 0x0102,regx);
	regx = KT_Bus_Read(I2CDef, 0x005b);
	rfGain=regx&0x7f;
	if(rfGain>((sel<<2)+42))
	{
		rfGain=(sel<<2)+42;
		KT_Bus_Write(I2CDef, 0x005b,(regx&0x80)|rfGain);
	}
}


void  snrMuteRefresh(const SoftI2C_t *I2CDef)
{
	uint8_t regx;

	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)
	{
		if(((KT_Bus_Read(I2CDef, 0x0100)&0x20)==0x20)&&(KT_Bus_Read(I2CDef, 0x020D)<=AUTOMUTE_SNR_LOWTH))
		{
			regx = KT_Bus_Read(I2CDef, 0x0087);
			KT_Bus_Write(I2CDef, 0x0087,(regx|0x02));
		}
		else if((KT_Bus_Read(I2CDef, 0x020D)>=AUTOMUTE_SNR_HIGHTH)||((KT_Bus_Read(I2CDef, 0x0100)&0x20)==0x00))
		{
			regx = KT_Bus_Read(I2CDef, 0x0087);
			KT_Bus_Write(I2CDef, 0x0087,(regx&~0x02));
		}
		else
		{
		}
	}
}


void KT_WirelessMicRx_Patch(const SoftI2C_t *I2CDef)
{
	rfIntCtl(I2CDef);
	pilotMuteRefresh(I2CDef);
	snrMuteRefresh(I2CDef);
}

uint8_t KT_WirelessMicRx_GetPilotStatus(const SoftI2C_t *I2CDef)
{
	if((KT_Bus_Read(I2CDef, 0x0209)>>7)&0x01)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t KT_WirelessMicRx_GetBpskSyncStatus(const SoftI2C_t *I2CDef)
{
	if((KT_Bus_Read(I2CDef, 0x0209)>>6)&0x01)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Seek_Freq_FastTune(const SoftI2C_t *I2CDef, uint32_t Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;
	if(KT_Bus_Read(I2CDef, 0x010f)==0x10)//a
	{
		regx = KT_Bus_Read(I2CDef, 0x0053);
		KT_Bus_Write(I2CDef, 0x0053,regx&~0x40);  //rfamp_int_en=0
	} 
#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(I2CDef, Freq);//select xtal
	#else
		oldCaclXtal(I2CDef, Freq);
	#endif
#endif 
	regx = KT_Bus_Read(I2CDef, 0x0108);
    KT_Bus_Write(I2CDef, 0x0108,regx | 0x08); //SCAN_MODE=1;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(I2CDef, 0x0045,Freq_H);
    KT_Bus_Write(I2CDef, 0x0046,Freq_M);

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,(regx & 0x0F) | Freq_L );

    regx = KT_Bus_Read(I2CDef, 0x0047);
    KT_Bus_Write(I2CDef, 0x0047,regx | 0x01); //chan_valid=1;
#ifdef  Delay_Time
		Delay_Ms(1);                          //
#endif
}

#ifdef XTAL_DUAL

static void selXtal(const SoftI2C_t *I2CDef, Bool xtalSel)
{
     uint8_t regx,state;

     xtalSel ^= XTAL_SEL1;
     regx = KT_Bus_Read(I2CDef, 0x0012);
     if(((regx&0x80)>>7)!=xtalSel) //
     {
         if(xtalSel==1)
        {
            KT_Bus_Write(I2CDef, 0x0012,regx|0x80);
        }
        else
        {
            KT_Bus_Write(I2CDef, 0x0012,regx&~0x80);
        }
        do
        {
            regx = KT_Bus_Read(I2CDef, 0x00a0);
        }while(!(regx&0x02));
		regx = KT_Bus_Read(I2CDef, 0x00a0);
        KT_Bus_Write(I2CDef, 0x00a0,regx|0x02);

        regx = KT_Bus_Read(I2CDef, 0x0015); //rst dll
        KT_Bus_Write(I2CDef, 0x0015,regx|0x40);
		regx = KT_Bus_Read(I2CDef, 0x002a); //ifadc rst
        KT_Bus_Write(I2CDef, 0x002a,regx|0x80);
		Delay_ms(10);
        regx = KT_Bus_Read(I2CDef, 0x0015);
        KT_Bus_Write(I2CDef, 0x0015,regx&~0x40);
        do
        {
            regx = KT_Bus_Read(I2CDef, 0x0180);
            state=(regx&0x08)>>3;
        }while(!state);
		regx = KT_Bus_Read(I2CDef, 0x002a); //ifadc rst
        KT_Bus_Write(I2CDef, 0x002a,regx&~0x80);

//		regx = KT_Bus_Read(I2CDef, 0x0042);	//dsp_rst
//		KT_Bus_Write(I2CDef, 0x0042,regx | 0x04);
//		Delay_ms(1);
//		regx = KT_Bus_Read(I2CDef, 0x0042);
//		KT_Bus_Write(I2CDef, 0x0042,regx &~ 0x04);
     }
}
#ifdef NEW_SEL_XTAL_MODE

static uint32_t caclFreqFrac(int32_t Freq,int32_t xtal_freq)
{
    uint32_t temp,tempMin=xtal_freq;
    uint8_t i;

    for(i=1;i<4;i++)
    {
        temp = ((xtal_freq/(2*i))-abs(((Freq%(xtal_freq/i))-(xtal_freq/(2*i)))))*i;
        if(temp<tempMin)
        {
            tempMin=temp;
        }
    }
    i=8;
    temp = ((xtal_freq/(2*i))-abs(((Freq%(xtal_freq/i))-(xtal_freq/(2*i)))))*i;
    if(temp<tempMin)
    {
        tempMin=temp;
    }
    return(tempMin*(3072000/xtal_freq));
}

//
const uint32_t use24M[26] =
{   
    490500,492000,516000,541500,556000,565500,566000,590000,614000,615000,639000,651250,688000,
    688500,712000,712250,712500,722500,736500,760500,762000,787500,810000,811500,835500,859500
};

//
const uint32_t use24576M[14] =
{
    7500,9000,10000,10500,12000,13500,14000,15000,16000,16500,18000,19500,20000,22000
};


static void caclXtal(const SoftI2C_t *I2CDef, int32_t Freq)
{
    uint8_t use24M_flag=0,use24576M_flag=0,i;
    uint32_t state_tmp,chan_frac_temp0,chan_frac_temp1;

    for(i=0;i<26;i++)
    {
        if(Freq==use24M[i])
        {
            use24M_flag=1;
            break;
        }
    }
    state_tmp = Freq%24000;
    for(i=0;i<14;i++)
    {
        if(state_tmp==use24576M[i])
        {
            use24576M_flag=1;
            break;
        }
    }
    if (use24M_flag)
    {
        selXtal(I2CDef, XTAL_24M_FREQ);
    }
    else if(use24576M_flag)
    {
        selXtal(XTAL_24P576M_FREQ);
    }
    else
    {
        chan_frac_temp0= caclFreqFrac(Freq,24000);
        chan_frac_temp1= caclFreqFrac(Freq,24576);
        if(chan_frac_temp0>chan_frac_temp1)
        {
            selXtal(XTAL_24M_FREQ);
        }
        else
        {
            selXtal(XTAL_24P576M_FREQ);
        }
    }
}
#endif

#endif

//I2S
#ifdef I2S_EN


void KT_WirelessMicRx_SAIInit(const SoftI2C_t *I2CDef, const KT065xM_I2SConfig_t *i2sConfig)
{
    uint8_t regx;
	// KT_Bus_Write(I2CDef, 0x0052,0x04);
	if(i2sConfig->MasterOrSlave == KT_I2S_MASTER)	 //mater
    {
        regx = KT_Bus_Read(I2CDef, 0x0050);
		KT_Bus_Write(I2CDef, 0x0050,(regx&0xc0)|((i2sConfig->SteroOrMono)<<5)|
		((i2sConfig->LeftOrRight)<<4)|((i2sConfig->Mode)<<2)|(i2sConfig->DataLength));
		regx = KT_Bus_Read(I2CDef, 0x0051);
		if((i2sConfig->LRCLK) ==	KT_I2S_LRCLK48K)
		{			
			KT_Bus_Write(I2CDef, 0x0051, (regx&0xf0)|(i2sConfig->Mode)|0x18);
		}
		else if((i2sConfig->LRCLK) == KT_I2S_LRCLK192K)
		{
			KT_Bus_Write(I2CDef, 0x0051, (regx&0xf0)|(i2sConfig->Mode)|0x14);
		}
		else  //96K
		{
			if((i2sConfig->MCLK) == KT_I2S_MCLK24P576M)
			{
				KT_Bus_Write(I2CDef, 0x0051, (regx&0xf0)|(i2sConfig->Mode)|0x1c);
			}
			else
			{
				KT_Bus_Write(I2CDef, 0x0051, (regx&0xf0)|(i2sConfig->Mode)|0x10);
			}
		}
        KT_Bus_Write(I2CDef, 0x0052, 0x02); //i2s_master_en= 1
    }
    else
    {
        KT_Bus_Write(I2CDef, 0x0052,0x01); //i2s_slave_en = 1
        KT_Bus_Write(I2CDef, 0x004d,0x01); //
        regx = KT_Bus_Read(I2CDef, 0x004d);
        KT_Bus_Write(I2CDef, 0x004d,regx|0x80); //unlock_tw_cfg_rdy = 1
		regx = KT_Bus_Read(I2CDef, 0x0050);
        KT_Bus_Write(I2CDef, 0x0050,(regx&0xc0)|((i2sConfig->SteroOrMono)<<5)|
		((i2sConfig->LeftOrRight)<<4)|((i2sConfig->Mode)<<2)|(i2sConfig->DataLength));
        regx = KT_Bus_Read(I2CDef, 0x0050);
        KT_Bus_Write(I2CDef, 0x0050,regx|0x40); //i2s_slave_sync_en=1
        regx = KT_Bus_Read(I2CDef, 0x0052);
        KT_Bus_Write(I2CDef, 0x0052,regx|0x08); //i2ss_pad_sdout_oen=1
    }
}


uint8_t KT_WirelessMicRx_deltemp(const SoftI2C_t *I2CDef)
{
	uint8_t regx;
	regx = KT_Bus_Read(I2CDef, 0x133);
	KT_Bus_Write(I2CDef, 0x133, regx&~(1<<5));

	regx = KT_Bus_Read(I2CDef, 0x54);
	KT_Bus_Write(I2CDef, 0x54, regx&~(3<<3));

	regx = KT_Bus_Read(I2CDef, 0x78);
	KT_Bus_Write(I2CDef, 0x78, regx|(1<<7));
	return(1);
}


#endif


