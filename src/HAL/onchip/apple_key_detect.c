/*
 *
 */
#include "hal_config.h"
#include "reg_apb.h"
#include "intc.h"
#include "power_on.h"
#include "power_off.h"
#include "earphone_key_detect.h"
#include "earphone_insert_remove_detect.h"
#include "earphone_key_wakeup_detect.h"
#include "standby_req.h"
#include "usb_intr.h"
#include "usb_com.h"
#include "saradc.h"
#include "usb_app.h"
#include "nds32_transform_math.h"
#include "bll_config.h"
#include "gpio_ctrl.h"
#include "bll_misc.h"
#include "chip_config.h"
#include "debug.h"

volatile uint8_t g_ucCloseAppleKeyDetFlg = 0; //0->open apple earphone key det, 1->close earphone key det
uint8_t g_ucButtType = 0; //0->apple earphone key, 1->other earphone key
int16_t *g_psAdc1Data; //ADC1 data buff point, buff length = 1Kbyte
uint16_t fifo_cnt;
uint16_t pre_fifo_cnt;
uint32_t max_abs_sqrt;
uint32_t total_abs_sqrt;
uint32_t sig_abs_sqrt;
uint32_t tmp_abs_sqrt;
uint16_t max_index;
uint16_t valid_key_flag;
uint16_t valid_key_flag_ack;
uint16_t fifo_cnt_lock;
uint16_t valid_data_cnt;
uint16_t fifo_cnt_diff;
extern uint8_t *gp_public_buf;
uint8_t g_ucKeyTypeBackUp;

void key_decoder_init(void)
{
	DBG_OUT_FUNC("entry\n");
	if((0 == g_pstConfig->FuncCfg.SupportAppleEarphone) || (1 == g_ucCloseAppleKeyDetFlg))
	{
		return;
	}
	apb_key_ctrl_set(BIT20 | BIT19 | 0x0F0);
	fifo_cnt = 0;
	pre_fifo_cnt = 0x1FFF;
	valid_key_flag = 0;
	valid_key_flag_ack = 0;
	g_ucButtType = 0;
	g_psAdc1Data = (int16_t *)gp_public_buf;
	apb_key_ctrl_set(BIT20 | BIT18 | 0x028);
	DBG_OUT_FUNC("exit\n");
}

#ifdef APPLE_EARPHONE_KEY_SUPPORT

void key_fifo_check(void)
{
	if((0 == g_pstConfig->FuncCfg.SupportAppleEarphone) || (1 == g_ucButtType) || (1 == g_ucCloseAppleKeyDetFlg))
	{
		return;
	}

	fifo_cnt = (lm_fifo_status_data_num_getf(1) >> 2);
	if (pre_fifo_cnt == 0x1FFF)
	{
		pre_fifo_cnt = fifo_cnt;
		valid_data_cnt = 0;
		valid_key_flag = 0;
	}
	else if (valid_key_flag == 0)
	{
		if (fifo_cnt != pre_fifo_cnt)
		{
			fifo_cnt_diff = (((fifo_cnt + 1024) - pre_fifo_cnt) & 1023); //computer fifo_cnt diff
			if ((fifo_cnt_diff > 300) && (fifo_cnt_diff < 400))
			{
				valid_data_cnt += 1;
			}
			else
			{
				if (valid_data_cnt >= 5) //at least consecutive of 5 interrupt
				{
					valid_key_flag = 1;
					valid_data_cnt = 0;
					fifo_cnt_lock = fifo_cnt;
					lm_fifo_control_fifo_en_setf(1, 0);//to be confirm
				}
				else
				{
					//restart
					lm_fifo_control_fifo_en_setf(1, 0);
					valid_data_cnt = 0;
					lm_fifo_control_fifo_en_setf(1, 1);
				}
			}
		}
		else
		{
			if (valid_data_cnt >= 5) //at least consecutive of 5 interrupt
			{
				valid_key_flag = 1;
				valid_data_cnt = 0;
				fifo_cnt_lock = fifo_cnt;
				lm_fifo_control_fifo_en_setf(1, 0);//to be confirm
			}
			else
			{
				//restart
				lm_fifo_control_fifo_en_setf(1, 0);
				valid_data_cnt = 0;
				lm_fifo_control_fifo_en_setf(1, 1);
			}
		}
	}
	pre_fifo_cnt = fifo_cnt;
	if (valid_key_flag_ack != 0)
	{
		valid_key_flag = 0;
	}
}


uint8_t Apple_KEY_decoder(void)
{
	uint16_t u16AudioCtl;
	int16_t i, index;
	uint32_t *temp_addr = (uint32_t *)(lm_fifo_control_start_addr_getf(1) << 4);

	//key type
#define key_plus 3
#define key_minus 2
#define key_release 1
	uint8_t key_type = 0xFF;

	// static uint8_t ucTFlag = 0;
	// static uint32_t uTBuf1;
	// static uint32_t uTBuf2;

	// ucTFlag = 0;
	if ((0 == g_pstConfig->FuncCfg.SupportAppleEarphone) || (1 == g_ucButtType) || (1 == g_ucCloseAppleKeyDetFlg))
	{
		return 0xff;
	}

	//key check
	if ((valid_key_flag == 1) && (g_ucButtType == 0))
	{
		//copy data
		for (i = 0 ; i < 512; i++ )
		{
			index = (((fifo_cnt_lock + i) + (1024 - 512 - 256)) & 1023); //offset is -256
			g_psAdc1Data[i] = (((temp_addr[index]) & 0xffff) << 0);
		}
		__nds32__nop();
		lm_fifo_control_fifo_en_setf(1, 0);
		__nds32__nop();
		__nds32__nop();
		nds32_rfft_q15(g_psAdc1Data, 9);

		// max value
		max_index = 0;
		max_abs_sqrt = 0;
		total_abs_sqrt = 0;
		for (i = 0 ; i < 512; i += 2 )
		{
			tmp_abs_sqrt = (int32_t)(g_psAdc1Data[i]) * (int32_t)(g_psAdc1Data[i]) +
			               (int32_t)(g_psAdc1Data[i + 1]) * (int32_t)(g_psAdc1Data[i + 1]);
			total_abs_sqrt = total_abs_sqrt + tmp_abs_sqrt;
			if (tmp_abs_sqrt > max_abs_sqrt)
			{
				max_index = (i >> 1);
				max_abs_sqrt = tmp_abs_sqrt;
			}
		}
		sig_abs_sqrt = 0;
		if (max_index > 5)
		{
			for (i = 2 * (max_index - 3) ; i < 2 * (max_index + 4); i += 2 )
			{
				sig_abs_sqrt += (int32_t)(g_psAdc1Data[i]) * (int32_t)(g_psAdc1Data[i]) +
				                (int32_t)(g_psAdc1Data[i + 1]) * (int32_t)(g_psAdc1Data[i + 1]);
			}
		}
		// uTBuf1 = total_abs_sqrt;
		// uTBuf2 = (sig_abs_sqrt + (sig_abs_sqrt >> 1));
		// ucTFlag = 1;
		if ((total_abs_sqrt < (sig_abs_sqrt + (sig_abs_sqrt >> 1))) && (g_ucButtType == 0))
		{
			if ((max_index < 60) & (max_index > 40))
			{
				key_type = key_release;
				__nds32__nop();
			}
			else if ((max_index >= 60) & (max_index < 75)) //key of -
			{
				key_type = key_minus;
			}
			else if ((max_index >= 75) & (max_index < 95)) //key of +
			{
				key_type = key_plus;
			}
		}
	}
	if (valid_key_flag == 0)
	{
		valid_key_flag_ack = 0;
	}

	//usb key transmit
	if ((key_type != 0xFF) && (g_ucKeyTypeBackUp != key_type))
	{
		if (key_type == key_plus)
		{
			u16AudioCtl |= BIT0;
			USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
		}
		else if (key_type == key_minus)
		{
			u16AudioCtl |= BIT1;
			USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
		}
		else if (key_type == key_release)
		{
			u16AudioCtl = 0;
			USB_SendHidReport(0, REPORT_AUDIO_ID, &u16AudioCtl, sizeof(uint8_t));
		}
		g_ucKeyTypeBackUp = key_type;
	}

	if (valid_key_flag == 1)
	{
		valid_key_flag_ack = 1;
		lm_fifo_control_fifo_en_setf(1, 1);
	}

	// if(ucTFlag)
	// {
	// 	uTBuf1 = co_bswap32(uTBuf1);
	// 	uart_write((uint8_t*)&uTBuf1, 4);
	// 	uTBuf2 = co_bswap32(uTBuf2);
	// 	uart_write((uint8_t*)&uTBuf2, 4);
	// }
#if (APPLE_EARPHONE_VOL_KEY_WAKEUP_CFG == SUPPORT)
	if ((1 == UsbSuspendSt) && (key_type != 0xFF))
	{
		USB_ResumeHost();
		UsbSuspendSt = 0;
	}
#endif
	return key_type;
}

#endif
