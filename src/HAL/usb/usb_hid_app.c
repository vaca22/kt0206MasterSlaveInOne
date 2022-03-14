/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
 * File Name          : usb_hid_app.c
 * Author             : wanggang
 * Email				 : wanggang@ipgoal.com
 * Version            : V1.0.0
 * Date               : 03/8/2018
 * Description        :
 ********************************************************************************/
#include "usb_ch9.h"
#include "co_rbuf.h"
#include "co_utils.h"
#include "sys_info.h"
#include "reg_dsp.h"
#include "bll_config.h"
#include "reg_misc.h"
#include "api.h"
#include "DongleEftCfg.h"
#include "chipEftCfg.h"
#include "hal_config.h"
#include "chip_config.h"
#include "MsgProc.h"

uint8_t HID_SET_REPORT_DESC[200];
uint8_t bIdleVal;
uint8_t bProtocolVal;
uint8_t _stHIDREV[22];
st_USB_KeyBoard_Report_t _stKeyBoard = {0};
uint8_t HID_AUDIO_CONTROL = 0;
extern USB_REQUEST stUsbSetup;
extern stUSB_Audio_Dev stUsbAudio;
extern const uint8_t  KEYBOARD_REPORT_DESC[35];
extern const uint8_t  HID_REPORT_DESC[33];
extern const uint8_t  HID_CONFIG_DESC[41];
extern const uint8_t  HID_INTERFACE_DESC[0xea];
co_rbuf_t *pHidDataIn;
uint8_t u8HidDataIn[100];
uint8_t u8IsSending;
uint16_t _u16AudioCtl;
typedef struct usb_hid_ftable_stru {
	void (*SetReport)(void);
	void (*SetIdle)(void);
	void (*SetProtocol)(void);
	void (*GetIdle)(void);
	void (*GetProtocol)(void);
	void (*GetReport)(void);
	void (*HIDSend)(void);
	void (*HidOut)(void);
	void (*KeyBoardIn)(st_USB_KeyBoard_Report_t);
	void (*AudioIn)(uint8_t);
} usb_hid_ftable_t;


usb_hid_ftable_t *pusb_hid_ftabl = NULL;


extern const st_OTPRegBank_t OTP_Default_Value;

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_SetReport(void);
void patch_HID_SetReport(void);
/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_SetIdle(void);
void patch_HID_SetIdle(void);

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_SetProtocol(void);
void patch_HID_SetProtocol(void);

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_GetIdle(void);
void patch_HID_GetIdle(void);

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_GetProtocol(void);
void patch_HID_GetProtocol(void);

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_GetReport(void);
void patch_HID_GetReport(void);

void ID_K_HID_In(uint8_t *pucBuf, uint8_t ucLen);
// {
//     uint16_t n;
//     uint16_t u16TagSize;
//     uint8_t u8Char[20] = {0};
//     uint16_t report_len = 10;

//     if(ucLen > report_len)
//     {
//     	u16TagSize = report_len;
//     }
//     else
//     {
//     	u16TagSize = ucLen;
//     }
//     GLOBAL_INT_STOP();
// 	u8Char[0] = report_len + 1;
// 	u8Char[1] = REPORT_K_ID;
// 	for(n = 0; n < u16TagSize; n++)
// 	{
// 		u8Char[n+2] =  pucBuf[n];
// 	}

// 	M_Ep2Index();			// 	if((rSIE_INCSR & B_INPKTRDY_EP1)  == 0)
// 	{
// 		for(n = 0; n < report_len + 1; n++)
// 		{
// 			rSIE_FIFOEP2 =  u8Char[n+1];
// 		}
// 		M_EpxTxCmdModeReady();//
// 	}
// 	else
// 	{
// 		if(co_rbuf_free_blocks_get(pHidDataIn) >= report_len +2)
// 		{
// 			co_rbuf_write(pHidDataIn,u8Char,report_len + 2);
// 		}
// 		else
// 		{
// 			M_Ep2Index();
// 			M_EpxCmdModeTxDoneCheck();//			for(n = 0; n < report_len + 1; n++)
// 			{
// 				rSIE_FIFOEP2 =  u8Char[n+1];
// 			}
// 			M_EpxTxCmdModeReady();//
// 		}
// 	}
// 	GLOBAL_INT_START();
// }

void ID_T_HID_In(uint8_t *pucBuf, uint8_t ucLen);
// {
// 	uint16_t n;
//     uint16_t u16TagSize;
//     uint8_t u8Char[20] = {0};
//     uint16_t report_len = 10;

//     if(ucLen > report_len)
//     {
//     	u16TagSize = report_len;
//     }
//     else
//     {
//     	u16TagSize = ucLen;
//     }
//     GLOBAL_INT_STOP();
// 	u8Char[0] = report_len + 1;
// 	u8Char[1] = REPORT_T_ID;
// 	for(n = 0; n < u16TagSize; n++)
// 	{
// 		u8Char[n+2] =  pucBuf[n];
// 	}

// 	M_Ep2Index();			//// 	if((rSIE_INCSR & B_INPKTRDY_EP1)  == 0)
// 	{
// 		for(n = 0; n < report_len + 1; n++)
// 		{
// 			rSIE_FIFOEP2 =  u8Char[n+1];
// 		}
// 		M_EpxTxCmdModeReady();//
// 	}
// 	else
// 	{
// 		if(co_rbuf_free_blocks_get(pHidDataIn) >= report_len +2)
// 		{
// 			co_rbuf_write(pHidDataIn,u8Char,report_len + 2);
// 		}
// 		else
// 		{
// 			M_Ep2Index();
// 			M_EpxCmdModeTxDoneCheck();//		for(n = 0; n < report_len + 1; n++)
// 			{
// 				rSIE_FIFOEP2 =  u8Char[n+1];
// 			}
// 			M_EpxTxCmdModeReady();//
// 		}
// 	}
// 	GLOBAL_INT_START();
// }

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void  KeyBoard_HID_In(st_USB_KeyBoard_Report_t stKeyBoard);
void patch_KeyBoard_HID_In(st_USB_KeyBoard_Report_t stKeyBoard);
void new_patch_KeyBoard_HID_In(st_USB_KeyBoard_Report_t stKeyBoard)
{
	uint16_t n;
	uint16_t u16TagSize = sizeof(_stKeyBoard)/sizeof(uint8_t);
	uint8_t u8Char[64] = {0};
	GLOBAL_INT_STOP();
	u8Char[0] = u16TagSize + 1;
	u8Char[1] = REPORT_KEYBOARD_ID;
	for(n = 0; n < u16TagSize; n++)
	{
		u8Char[n+2] =  (*(((volatile uint8_t*)(&stKeyBoard))+n));
	}

	M_Ep2Index();			//
	if((rSIE_INCSR & B_INPKTRDY_EP1)  == 0)
	{
		rSIE_FIFOEP2 = REPORT_KEYBOARD_ID;
		for(n = 0; n < u16TagSize; n++)
		{
			rSIE_FIFOEP2 =  u8Char[n+2];
		}
		M_EpxTxCmdModeReady();//
	}
	else
	{
		if(co_rbuf_free_blocks_get(pHidDataIn) >= u16TagSize +2)
		{
			co_rbuf_write(pHidDataIn,u8Char,u16TagSize + 2);
		}
		else
		{
			M_Ep2Index();
			M_EpxCmdModeTxDoneCheck();//		rSIE_FIFOEP2 = REPORT_KEYBOARD_ID;
			rSIE_FIFOEP2 = REPORT_KEYBOARD_ID;
			for(n = 0; n < u16TagSize; n++)
			{
				rSIE_FIFOEP2 =  u8Char[n+2];
			}
			M_EpxTxCmdModeReady();//
		}
	}
	GLOBAL_INT_START();
}

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void HID_Out(void)
{
	return pusb_hid_ftabl->HidOut();
}

extern uint8_t *gp_public_buf;
extern void dsp_parameter_from_flash_init(void);

#ifdef KT0203
User_HID_ReceiveCallbackHandler UserHIDReceiveCallbackHandler = NULL;
#endif

void Computer_Communication(uint8_t CMD, uint32_t ADDR, uint32_t Dat)
{
	uint8_t u8SendBuf[10] = {0};
	uint16_t  ADDRbuf=ADDR;
	if (0x31 == CMD) //WRITE reg
	{
		if (ADDR < config_IDX(RFU1))
		{
			co_write32p(u8SendBuf, ADDR);
			u8SendBuf[4] = CMD;
			u8SendBuf[6] = 0x01; //error
			ID_K_HID_In((uint8_t *)&u8SendBuf, 10);
			return;
		}

		*(&g_pstConfig->ALL32[0] + ADDR) = Dat;
		if (ADDR >= config_IDX(DSPRegAll) && ADDR < config_IDX(RFU2))
		{
			ADDRbuf -= config_IDX(DSPRegAll);
			MSG_t m = {
				.Param   = ADDRbuf,
				.Message = MSG_DSPRegUpdate,
			};
			PostMessage(m);

			// ChipEftReg_update(g_st_pHeadsetEft, &g_pstConfig->DSPRegAll, ADDRbuf, AUDIO_SAMPLE_BLOCK_SIZE);
		}
		else if (ADDR >= config_IDX(USBReg) && ADDR < config_IDX(RFU4))
		{

		}
		else if (ADDR >= config_IDX(FuncCfg) && ADDR < config_IDX(RFU5))
		{

		}
		else if (ADDR >= config_IDX(PerfCfg) && ADDR < config_IDX(RFU6))
		{
			pga_init();
			apb_spare_reg2_set(g_pstConfig->PerfCfg.THDCfg);
		}		
		else{
			
		}


		co_write32p(u8SendBuf, ADDR);
		u8SendBuf[4] = CMD;
		u8SendBuf[6] = 0x03; //ack
		ID_K_HID_In((uint8_t *)&u8SendBuf, 10);
	}
	else if (0x21 == CMD) //READ reg
	{
		Dat = *(&g_pstConfig->ALL32[0] + ADDR);
		co_write32p(u8SendBuf, ADDR);
		u8SendBuf[4] = CMD;
		co_write32p(&u8SendBuf[6], Dat);
		ID_K_HID_In((uint8_t *)&u8SendBuf, 10);
	}
	else if (0x32 == CMD) //SAVE  reg
	{
		GLOBAL_INT_STOP();
		FlashSectorErase(g_pstConfig->SaveDataAddr - 0x80000);
		FlashProgramPage(g_pstConfig->SaveDataAddr - 0x80000, &g_pstConfig->ALL32[0]);
		FlashProgramPage(g_pstConfig->SaveDataAddr + 0x100 - 0x80000, &g_pstConfig->ALL32[64]);
		FlashProgramPage(g_pstConfig->SaveDataAddr + 0x200 - 0x80000, &g_pstConfig->ALL32[128]);
		FlashProgramPage(g_pstConfig->SaveDataAddr + 0x300 - 0x80000, &g_pstConfig->ALL32[192]);
		GLOBAL_INT_START();
		co_write32p(u8SendBuf, ADDR);
		u8SendBuf[4] = CMD;
		u8SendBuf[6] = 0x03; //ack
		ID_K_HID_In((uint8_t *)&u8SendBuf, 10);
		Delay_Ms(30);
		apb_rst_gen_ctrl0_soft_rst_setf(1);   // reset
	}
	else if (0x33 == CMD) //clear reg
	{
		GLOBAL_INT_STOP();
		FlashSectorErase(g_pstConfig->SaveDataAddr - 0x80000);
		GLOBAL_INT_START();
		co_write32p(u8SendBuf, ADDR);
		u8SendBuf[4] = CMD;
		u8SendBuf[6] = 0x03; //ack
		ID_K_HID_In((uint8_t *)&u8SendBuf, 10);
		Delay_Ms(30);
		apb_rst_gen_ctrl0_soft_rst_setf(1);   // reset
	}

}
void new_patch_HID_Out(void)
{
	uint8_t u8ReportID;
	uint32_t i;
	uint8_t u8ReportBuf[10] = {0};
	// uint8_t *pubDownLoad = (uint8_t *)0x41430;
	const uint8_t DownLoadKey[] = "12345678";
	int32_t Ret;

	M_Ep2Index();
	M_EpxRxDoneCheck();
	u8ReportID = rSIE_FIFOEP2;
	if('K' == u8ReportID)
	{
		uint32_t Addr;
		uint8_t Cmd;
		// uint8_t Rfu;
		uint32_t Data;

		for(i = 0; i < 10; i++)
		{
			u8ReportBuf[i] = rSIE_FIFOEP2;
		}
		Addr = co_read32p(&u8ReportBuf[0]);
		Cmd = u8ReportBuf[4];
		// Rfu = u8ReportBuf[5];
		Data = co_read32p(&u8ReportBuf[6]);

		if(0x88 == Cmd) /* Write */
		{
			if(Addr == (FLASH_MEMORY_BASE + 0x520))
			{
				uint32_t uAddr = 0;
				uint32_t *uBuf = NULL;

				GLOBAL_INT_STOP();
				MEM_Cpy_Word((unsigned int *)gp_public_buf, (unsigned int *)FLASH_MEMORY_BASE, 0x400);
				OUTW(&gp_public_buf[0x520], Data);
				FlashSectorErase(0x00);

				for(i = 1; i < 16; i++)
				{
					uAddr = 0x00 + (i * 0x100);
					uBuf = (uint32_t *)(gp_public_buf + i * 0x100);

					FlashProgramPage(uAddr, uBuf);
				}

				i = 0;
				uAddr = 0x00 + (i * 0x100);
				uBuf = (uint32_t *)(gp_public_buf + i * 0x100);
				FlashProgramPage(uAddr, uBuf);
				apb_rst_gen_ctrl0_soft_rst_setf(1);
			}
			else
			{
				OUTW(Addr, Data);
			}
		}
		else if(0x08 == Cmd) /* Read */
		{
			Data = INW(Addr);
			ID_K_HID_In((uint8_t *)&Data, 4);
		}
		else
		{
			Computer_Communication(Cmd,Addr,Data);
		}
	}
	else if('T' == u8ReportID)
	{
		for(i = 0; i < 10; i++)
		{
			u8ReportBuf[i] = rSIE_FIFOEP2;
		}

		if(0x01 == u8ReportBuf[0]) //read version
		{
			ID_T_HID_In((uint8_t *)&OTP_Default_Value.hardware_ver, 8);
			// ID_T_HID_In(DownLoadKey, 10);
		}
		else
		{
			Ret = memcmp(&u8ReportBuf[0], DownLoadKey, 8);
			if(0 == Ret)
			{
				// *pubDownLoad = 0x78;
				SW_USB_DOWNLOAD = 0x12345678;
				apb_rst_gen_ctrl0_soft_rst_setf(1);
			}
		}
	}

}

/*******************************************************************************
 * Function Name  :
 * Description    :
 * Input          :
 * Output         :
 * Return         :
 *
 *******************************************************************************/
void  Audio_HID_In(uint8_t u8AudioCtl);
//void  patch_Audio_HID_In(uint8_t u8AudioCtl);
void  new_patch_Audio_HID_In(uint8_t u8AudioCtl)
{
	uint8_t u8Char[4] = {0};
	uint16_t u16AudioCtl = 0;
	GLOBAL_INT_STOP();
	if(u8AudioCtl&0x01)
	{
		u16AudioCtl = u16AudioCtl|0x01;
	}
	if(u8AudioCtl&0x02)
	{
		u16AudioCtl = u16AudioCtl|0x02;
	}
	if(u8AudioCtl&0x08)
	{
		u16AudioCtl = u16AudioCtl|0x04;
	}
	if(u8AudioCtl&0x10)
	{
		u16AudioCtl = u16AudioCtl|0x04;
	}
	if(u8AudioCtl&0x20)
	{
		u16AudioCtl = u16AudioCtl|0x10;
	}
	if(u8AudioCtl&0x40)
	{
		u16AudioCtl = u16AudioCtl|0x20;
	}
	_u16AudioCtl = u16AudioCtl;
	//	u8Char[0] = 3;
	//	u8Char[1] = REPORT_AUDIO_ID;
	//	u8Char[2] = (u16AudioCtl&0xff);
	//	u8Char[3] = (u16AudioCtl>>8)&0xff;

	u8Char[0] = 2;
	u8Char[1] = REPORT_AUDIO_ID;
	u8Char[2] = (u16AudioCtl&0xff);

	M_Ep2Index();			//
	if(((rSIE_INCSR & B_INPKTRDY_EP1)  == 0)&&(co_rbuf_written_blocks_get(pHidDataIn) == 0))
	{
		while(u8IsSending == TRUE);
		M_EpxCmdModeTxDoneCheck();
		rSIE_FIFOEP2 = REPORT_AUDIO_ID;
		rSIE_FIFOEP2 =  u8Char[2];
		M_EpxTxCmdModeReady();//
	}
	else
	{
		if(co_rbuf_free_blocks_get(pHidDataIn) >= 4)
		{
			co_rbuf_write(pHidDataIn,u8Char,3);
		}
	}
	GLOBAL_INT_START();
}

void  USB_HIDSend(void);
void patch_USB_HIDSend(void);

void USB_HIDBuffInit(void)
{
	uint32_t u32MemSize = 100;
	pHidDataIn = co_rbuf_init(u8HidDataIn, u32MemSize, sizeof(uint8_t));
	_u16AudioCtl = 0;
	u8IsSending = FALSE;
}
const usb_hid_ftable_t new_usb_hid_patch_ftable = {
		.SetReport        = patch_HID_SetReport,
		.SetIdle          = patch_HID_SetIdle,
		.SetProtocol      = patch_HID_SetProtocol,
		.GetIdle          = patch_HID_GetIdle,
		.GetProtocol      = patch_HID_GetProtocol,
		.GetReport        = patch_HID_GetReport,
		.HidOut           = new_patch_HID_Out,
		.KeyBoardIn       = new_patch_KeyBoard_HID_In,
		.AudioIn          = new_patch_Audio_HID_In,
		.HIDSend          = patch_USB_HIDSend,
};

void new_usb_hid_patch_init(void)
{
	pusb_hid_ftabl = (usb_hid_ftable_t *)&new_usb_hid_patch_ftable;
}
