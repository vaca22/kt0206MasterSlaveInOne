/*
 * api.c
 *
 *  Created on: Jun 13, 2019
 *      Author:
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "gpio_ctrl.h"
#include "api.h"
#include "timer.h"
#include "usb_com.h"
#include "usb_app.h"
#include "saradc.h"
#include "qspi_ctrl.h"
#include "hal_config.h"
#include "bll_config.h"
#include "co_utils.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */
#define FLASH_START_ADDR 0x80000

/*
 * GLOBAL VARIABLE DECLARATION
 ****************************************************************************************
 */


/*
 * GPIO part
 ****************************************************************************************
 */
api_ret_value_e api_gpio_func_set(api_gpio_def_e eGPIOx, api_gpio_func_def_e eFuncX)
{
	switch (eGPIOx) {
		case API_GPIO_1:
		case API_GPIO_2:
		case API_GPIO_3:
		case API_GPIO_4:
		case API_GPIO_5:
		case API_GPIO_6:
		case API_GPIO_7:
		case API_GPIO_8:
		case API_GPIO_9:
		case API_GPIO_10:
			break;
		default:
			return API_GPIO_NUM_ERR;
	}

	switch (eFuncX) {
		case API_GPIO_Func1:
		case API_GPIO_Func2:
		case API_GPIO_AuxADC:
		case API_GPIO_FloatingInput:
		case API_GPIO_Output0:
		case API_GPIO_Output1:
		case API_GPIO_Func7:
		case API_GPIO_Func8:
		case API_GPIO_Func9:
		case API_GPIO_Func10:
		case API_GPIO_Func11:
		case API_GPIO_HighZ:
		case API_GPIO_PullDownInput:
		case API_GPIO_PullUpInput:
			break;
		default:
			return API_GPIO_FUNC_ERR;
	}

	GPIO_FuncSet(eGPIOx, eFuncX);

	return API_OK;
}

api_ret_value_e api_gpio_toggle(api_gpio_def_e eGPIOx)
{
	switch (eGPIOx) {
		case API_GPIO_1:
		case API_GPIO_2:
		case API_GPIO_3:
		case API_GPIO_4:
		case API_GPIO_5:
		case API_GPIO_6:
		case API_GPIO_7:
		case API_GPIO_8:
		case API_GPIO_9:
		case API_GPIO_10:
			break;
		default:
			return API_GPIO_NUM_ERR;
	}

	New_GPIO_Toggle(eGPIOx);

	return API_OK;
}

api_ret_value_e api_gpio_input_get(api_gpio_def_e eGPIOx)
{
	uint8_t u8RetValue;

	switch (eGPIOx) {
		case API_GPIO_1:
		case API_GPIO_2:
		case API_GPIO_3:
		case API_GPIO_4:
		case API_GPIO_5:
		case API_GPIO_6:
		case API_GPIO_7:
		case API_GPIO_8:
		case API_GPIO_9:
		case API_GPIO_10:
			break;
		default:
			return API_GPIO_NUM_ERR;
	}

	u8RetValue = GPIO_InputGet(eGPIOx);
	switch(u8RetValue){
		case 0x0:
			return API_GPIO_INPUT0;
		case 0x1:
			return API_GPIO_INPUT1;
		case 0x2:
		default:
			return API_GPIO_FUNC_ERR;
	}
}

/*
 * Timer part
 ****************************************************************************************
 */
api_ret_value_e api_timer_start(api_tim_id_e eId, uint16_t u16Num, api_tim_unit_e eUnit, api_timer_handler vHandler)
{
	switch(eId){
		case API_TIMER_0:
			break;
		default:
			return API_TIMRE_ID_ERR;
	}

	switch(eUnit){
		case API_TIM_MS:
		case API_TIM_US:
			break;
		default:
			return API_TIMER_UNIT_ERR;
	}

	timer_start_period(eId, u16Num, (timer_handler)vHandler, eUnit);
	return API_OK;
}

api_ret_value_e api_timer_end(api_tim_id_e eId)
{
	switch (eId) {
		case API_TIMER_0:
			break;
		default:
			return API_TIMRE_ID_ERR;
	}

	timer_end(eId);

	return API_OK;
}

api_ret_value_e api_timer_delay(uint16_t u16Num, api_tim_unit_e eUnit)
{
	switch (eUnit) {
		case API_TIM_MS:
		case API_TIM_US:
			break;
		default:
			return API_TIMER_UNIT_ERR;
	}
	timer_delay_length(u16Num, eUnit);
	return API_OK;
}

/*
 * hid part
 ****************************************************************************************
 */
void api_connect_usb(void)
{
	Hal_ConectUsb();
}

void api_disconnect_usb(void)
{
	Hal_DisConectUsb();
}

void api_hid_report_desc_set(uint8_t* ucAddr, uint16_t usLen)
{
	USB_HID_Report_Desc_Set(ucAddr, usLen);
}

void api_usb_config_desc_set(uint8_t* ucAddr, uint16_t usLen)
{
	USB_Config_Desc_Set(ucAddr, usLen);
}

bool api_hid_send_report(api_hid_report_id_e u8HidNum, void* param, uint8_t u8Len)
{
	if (RETURN_OK == USB_SendHidReport(0, u8HidNum, param, u8Len))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void api_keyboard_support_cfg(FunctionState_t NewState)
{
    SupportUsbKeyboard_Set(NewState);
}

uint16_t api_keyboard_continue_send(uint8_t* ucBuf, uint16_t usLen)
{
	return(USB_KeyBoardContinueSend(ucBuf, usLen));
}

/*
 * uart part
 ****************************************************************************************
 */
#if 0
#define DBG_STR_MAX_LEN             128

int (*log_output)(char *data, int size) = NULL;

__STATIC char dbg_str[DBG_STR_MAX_LEN];

int log_printfx(const char *format, ...)
{
	va_list argp;
	uint32_t len;

	if (log_output == NULL) {
		return 0;
	}

	va_start(argp, format);
	len = vsnprintf(dbg_str, DBG_STR_MAX_LEN, format, argp);
	log_output(dbg_str, strlen(dbg_str));
	va_end(argp);

	return len;
}

int log_vprintf(const char *format, va_list argp)
{
	uint32_t len;

	if (log_output == NULL) {
		return 0;
	}

	len = vsnprintf(dbg_str, DBG_STR_MAX_LEN, format, argp);
	log_output(dbg_str, strlen(dbg_str));

	return len;
}

int log_dump_hex(const void *data, int size)
{
	const uint8_t *p = data;
	char *buf = dbg_str;
	int n = 0;

	while (size && (buf - dbg_str < DBG_STR_MAX_LEN - 10)) {
		buf += sprintf(buf, "%02X ", *p);
		p++;
		size--;
		n++;
		if ((n & 0xF) == 0) {
			buf += sprintf(buf, "\r\n");
		}
	}
	log_printfx("%s", dbg_str);

	return n;
}

void log_dump_log(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	log_vprintf(format, args);
	va_end(args);
}
#endif

extern uint16_t g_uart_rx_buf_size;
extern uint16_t g_uart_tx_buf_size;
bool api_uart_init(api_baud_rate_e eBaud)
{
	if (OK == new_uart_init((uint32_t)eBaud))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

uint16_t api_uart_in_waiting(void)
{
	return uart_in_waiting();
}

uint16_t api_uart_read(uint8_t *buf, uint16_t len)
{
	return uart_read(buf, len);
}

void api_uart_write(uint8_t *buf, uint16_t len)
{
	(void)uart_write(buf, len);
}

void api_print_string(char *str)
{
	(void)uart_write((uint8_t*)str, strlen((const char*)str));
}

/*
 * Saradc part
 ****************************************************************************************
 */
uint16_t api_saradc_value_get(uint16_t u16AvgNum, api_saradc_path_e ePathNum)
{
	uint32_t u32Value;

	switch (ePathNum) {
		case API_SARADC_MIC:
		case API_SARADC_GPIO1:
		case API_SARADC_GPIO2:
		case API_SARADC_GPIO3:
		case API_SARADC_GPIO4:
		case API_SARADC_GPIO5:
		case API_SARADC_GPIO6:
		case API_SARADC_GPIO7:
		case API_SARADC_GPIO8:
		case API_SARADC_AUDAC_ITRIM_VOUT:
			break;
		default:
			return FALSE;
	}
	u32Value = Saradc_Convert(u16AvgNum, ePathNum);

	return (uint16_t)u32Value;
}

/*
 * PWM part
 ****************************************************************************************
 */
api_ret_value_e api_pwm_duty_ratio(api_pwm_id_e eId, uint8_t u8PwmDutyRatio)
{
	switch (eId) {
		case API_PWM_0:	
			apb_pwm_ctrl1_pwm_r_en_setf(0);
			Delay_Us(2);
			apb_pwm_ctrl0_pwm_duty_ratio_r_setf(u8PwmDutyRatio);	
			apb_pwm_ctrl1_pwm_r_en_setf(1);
			break;
		case API_PWM_1:
			apb_pwm_ctrl1_pwm_g_en_setf(0);
			Delay_Us(2);
			apb_pwm_ctrl0_pwm_duty_ratio_g_setf(u8PwmDutyRatio);
			apb_pwm_ctrl1_pwm_g_en_setf(1);
			break;
		case API_PWM_2:
			apb_pwm_ctrl1_pwm_b_en_setf(0);
			Delay_Us(2);
			apb_pwm_ctrl1_pwm_duty_ratio_b_setf(u8PwmDutyRatio);
			apb_pwm_ctrl1_pwm_b_en_setf(1);
			break;
		default:
			return API_PWM_ID_ERR;
	}
	
	return API_OK;
}

api_ret_value_e api_pwm_init(api_pwm_id_e eId, uint8_t u8PwmRate, uint8_t u8PwmDutyRatio)
{
	switch (eId) {
		case API_PWM_0:
			apb_pwm_ctrl1_pwm_duty_ratio_b_setf(u8PwmDutyRatio);
			apb_pwm_ctrl1_pwm_freq_b_setf(0);
			apb_pwm_ctrl2_rate_0_setf(u8PwmRate);
			break;
		case API_PWM_1:
			apb_pwm_ctrl0_pwm_duty_ratio_g_setf(u8PwmDutyRatio);
			apb_pwm_ctrl1_pwm_freq_g_setf(0);
			apb_pwm_ctrl2_rate_1_setf(u8PwmRate);
			break;
		case API_PWM_2:
			apb_pwm_ctrl0_pwm_duty_ratio_r_setf(u8PwmDutyRatio);
			apb_pwm_ctrl1_pwm_freq_r_setf(0);
			apb_pwm_ctrl2_rate_2_setf(u8PwmRate);
			break;
		default:
			return API_PWM_ID_ERR;
	}

	return API_OK;
}

api_ret_value_e api_pwm_start(api_pwm_id_e	eId)
{
	switch (eId) {
		case API_PWM_0:
			apb_pwm_ctrl1_pwm_b_en_setf(1);
			apb_pwm_ctrl2_eable_0_setf(1);
			break;
		case API_PWM_1:
			apb_pwm_ctrl1_pwm_g_en_setf(1);
			apb_pwm_ctrl2_eable_1_setf(1);
			break;
		case API_PWM_2:
			apb_pwm_ctrl1_pwm_r_en_setf(1);
			apb_pwm_ctrl2_eable_2_setf(1);
			break;
		default:
			return API_PWM_ID_ERR;
	}

	return API_OK;
}

api_ret_value_e api_pwm_stop(api_pwm_id_e eId)
{
	switch (eId) {
		case API_PWM_0:
			apb_pwm_ctrl1_pwm_b_en_setf(0);
			apb_pwm_ctrl2_eable_0_setf(0);
			break;
		case API_PWM_1:
			apb_pwm_ctrl1_pwm_g_en_setf(0);
			apb_pwm_ctrl2_eable_1_setf(0);
			break;
		case API_PWM_2:
			apb_pwm_ctrl1_pwm_r_en_setf(0);
			apb_pwm_ctrl2_eable_2_setf(0);
			break;
		default:
			return API_PWM_ID_ERR;
	}

	return API_OK;
}

/*
 * Audio part
 ****************************************************************************************
 */
void api_audio_path_set(api_audio_path_e ePath)
{
	switch (ePath) {
		case API_AUDIO_I2S:
			g_pstConfig->FuncCfg.AudioPathSel = 1;
			break;
		case API_AUDIO_ADDA:
			g_pstConfig->FuncCfg.AudioPathSel = 2;
			break;
		default:
			g_pstConfig->FuncCfg.AudioPathSel = 0;
			break;
	}
}

/*
 * Save sound parameters part
 ****************************************************************************************
 */
api_ret_value_e api_flash_sector_erase(uint32_t u32Addr, uint32_t u32Size)
{
	uint16_t u16RetValue = OK;
	uint32_t u32EraseAddrStart, u32EraseSize, u32EraseSectorCnt, i;

	if ((u32Addr < 0x20000) || ((u32Addr >= 0x3F000) && (u32Addr < 0x40000))) {
		return API_FLASH_START_ADDR_ILLEGAL;
	}

	if (u32Addr % SECTOR_SIZE) {
		return API_FLASH_START_ADDR_NOT_ALIGN;
	}

	if (((u32Addr + u32Size- 1) >= 0x3F000) && ((u32Addr + u32Size- 1) < 0x40000)) {
		return API_FLASH_END_ADDR_ILLEGAL;
	}

	u32EraseAddrStart = (u32Addr / SECTOR_SIZE) * SECTOR_SIZE;
	u32EraseSize = u32Addr - u32EraseAddrStart + u32Size;
	u32EraseSectorCnt = (u32EraseSize + SECTOR_SIZE - 1) / SECTOR_SIZE;
	for (i = 0; i < u32EraseSectorCnt; i++) {
		u16RetValue = FlashSectorErase(u32EraseAddrStart);
		if (ERR == u16RetValue) {
			return API_FLASH_ERASE_ERR;
		}
		u32EraseAddrStart += SECTOR_SIZE;
	}

	return API_OK;
}

api_ret_value_e api_flash_param_save(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize)
{
	uint16_t u16RetValue = OK;

	if ((u32Addr < 0x20000) || ((u32Addr >= 0x3F000) && (u32Addr < 0x40000))) {
		return API_FLASH_START_ADDR_ILLEGAL;
	}

	if (((u32Addr + u32DataSize - 1) >= 0x3F000) && ((u32Addr + u32DataSize - 1) < 0x40000)) {
		return API_FLASH_END_ADDR_ILLEGAL;
	}

	u16RetValue = Flash_Write(u32Addr, (uint32_t *)pu8ParamBuf, u32DataSize);
	if (ERR == u16RetValue) {
		return API_FLASH_WRITE_ERR;
	}

	return API_OK;
}

api_ret_value_e api_flash_param_read(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize)
{
	uint32_t i;
	uint32_t *pu32Addr = (uint32_t *)(u32Addr + FLASH_START_ADDR);
	uint32_t *pu32TmpBuf = (uint32_t *)pu8ParamBuf;

	if ((u32Addr < 0x20000) || ((u32Addr >= 0x3F000) && (u32Addr < 0x40000))) {
		return API_FLASH_START_ADDR_ILLEGAL;
	}

	if (((u32Addr + u32DataSize - 1) >= 0x3F000) && ((u32Addr + u32DataSize - 1) < 0x40000)) {
		return API_FLASH_END_ADDR_ILLEGAL;
	}

	for (i = 0; i < ((u32DataSize + 3) / 4); i++) {
		pu32TmpBuf[i] = pu32Addr[i];
	}

	return API_OK;
}

api_ret_value_e api_flash_param_read_NoCache(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize)
{
	uint32_t *pu32TmpBuf = (uint32_t *)pu8ParamBuf;

	if ((u32Addr < 0x20000) || ((u32Addr >= 0x3F000) && (u32Addr < 0x40000))) {
		return API_FLASH_START_ADDR_ILLEGAL;
	}

	if (((u32Addr + u32DataSize - 1) >= 0x3F000) && ((u32Addr + u32DataSize - 1) < 0x40000)) {
		return API_FLASH_END_ADDR_ILLEGAL;
	}

	FlashReadWords_NoCache(pu32TmpBuf, u32Addr, (u32DataSize + 3) / 4);

	return API_OK;

}

/*
 * CLK part
 ****************************************************************************************
 */
// void api_coreclk_set(api_coreclk_def_e eCoreSel)
// {
//     apb_clk_gen_clksel_clk_osc_high_div_sel_setf(eCoreSel);
// }


/*
 * USB MIC config part
 ****************************************************************************************
 */
void api_usbmic_set(api_usbmic_channel_def_e eUsbMicChannel, api_usbmic_insel_def_e eUsbMicAudioInSel,
	api_usbmic_incfg_def_e eUsbMicI2sCfg)
{
    UsbMicCfg_Set(eUsbMicChannel, eUsbMicAudioInSel, eUsbMicI2sCfg);
}

#ifdef	KT0203
/*
 * Config User HID API
 ****************************************************************************************
 */
extern User_HID_ReceiveCallbackHandler UserHIDReceiveCallbackHandler;
void Set_User_HID_Receive_Handler(User_HID_ReceiveCallbackHandler HID_Handler)
{
	if(HID_Handler != NULL)
	{
		UserHIDReceiveCallbackHandler = HID_Handler;
	}
}

/*
 * Config User HID API
 ****************************************************************************************
 */
void User_HID_Send(uint8_t *buf, uint8_t len)
{
	if(len==0)
	{
		return;
	}
	uint8_t i, HIDBuf[10] = {0};
	HIDBuf[4] = 0xb1;        // CMD
	if(len>4)
	{
		len = 4;
	}
    for(i=0;i<len;i++)
    {
    	HIDBuf[6+i] = buf[i];
    }
	ID_K_HID_In(HIDBuf,10);
}

/*
 * User HID Set Volume
 ****************************************************************************************
 */
void api_post_usb_volume_set(uint8_t vol)
{
	pDSP->VolCtrl.postvol_usb = vol;
	dsp_reg_update(DSPREG_IDX(VolCtrl));
}

void Uart_Debug_Reg(uint8_t CMD,uint16_t Addr,uint32_t Val)
{
	uint8_t u8SendBuf[10] = {0};
	uint16_t  ADDRbuf;
	if(0x55 == CMD)//WRITE reg
	{
		*(&g_pstConfig->ALL32[0] + Addr) = Val;
		if(Addr>=config_IDX(ParaCfg)&&Addr<config_IDX(RFU3))
		{
			pga_init();
		}
		else if(Addr>=config_IDX(DongleAudioReg)&&Addr<config_IDX(RFU4))
		{
			ADDRbuf = Addr;
			ADDRbuf -= config_IDX(DongleAudioReg);
			dsp_reg_update(ADDRbuf);
		}
		else if(Addr>=config_IDX(HeadsetAudioReg)&&Addr<config_IDX(RFU5))
		{
			dsp_parameter_from_flash_init();
		}
		else if(Addr>=config_IDX(HeadsetAudioReg2)&&Addr<config_IDX(THDCfg))
		{
			dsp_parameter_from_flash_init();
		}
		co_write16(&u8SendBuf[1],Addr);
		u8SendBuf[0]=CMD;
		u8SendBuf[3]=0x03; //ack
		uart_write_flush(u8SendBuf,8);
	}
	else if(0xaa == CMD)//READ reg
	{
		Val = *(&g_pstConfig->ALL32[0] + Addr);
		co_write16(&u8SendBuf[1], Addr);
		u8SendBuf[0] = CMD;
		co_write32p(&u8SendBuf[3], Val);
		uart_write_flush(u8SendBuf,8);
	}
	else if(0x11 == CMD)  //SAVE  reg
	{
		GLOBAL_INT_STOP();
		FlashSectorErase(g_pstConfig->SaveDataAddr-0x80000);
		FlashProgramPage(g_pstConfig->SaveDataAddr-0x80000,&g_pstConfig->ALL32[0]);
		FlashProgramPage(g_pstConfig->SaveDataAddr+0x100-0x80000,&g_pstConfig->ALL32[64]);
		FlashProgramPage(g_pstConfig->SaveDataAddr+0x200-0x80000,&g_pstConfig->ALL32[128]);
		FlashProgramPage(g_pstConfig->SaveDataAddr+0x300-0x80000,&g_pstConfig->ALL32[192]);
		GLOBAL_INT_START();
		co_write16(&u8SendBuf[1], Addr);
		u8SendBuf[0] = CMD;
		u8SendBuf[3] = 0x03; //ack
		uart_write_flush(u8SendBuf,8);
		Delay_Ms(30);
		apb_rst_gen_ctrl0_soft_rst_setf(1);
	}
	else if(0xa5==CMD) //read ver
	{
		uart_write_flush((uint8_t *)g_pstConfig->PatchSwVerAddr,8);
	}
	else if(0xa6==CMD)//read time1
	{
		uart_write_flush((uint8_t *)g_pstConfig->PatchSwVerAddr+16,16);
	}
	else if(0xa7==CMD)//read TYPE
	{
		uart_write_flush((uint8_t *)g_pstConfig->IcNumberAddr,8);
	}
	else
	{
		;
	}
}
uint8_t check_sum8(uint8_t *data,uint8_t len)
{
	uint8_t sum=0;
	int i;
	for(i=0;i<len;i++)
	{
		sum+=*data++;
	}
	return sum;
}
void Uart_Debug_Reg_Response(uint8_t *Rxbuf, uint8_t len)
{
	uint8_t cmd;
	uint16_t addr;
	uint32_t value;
	if(len==8)
	{
		if(Rxbuf[7]==check_sum8(Rxbuf,7))
		{
			cmd = Rxbuf[0];
			addr = co_read16p(&Rxbuf[1]);
			value = co_read32p(&Rxbuf[3]);
			Uart_Debug_Reg(cmd, addr, value);
		}
	}
}
#endif
