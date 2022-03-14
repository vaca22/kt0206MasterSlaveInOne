/*
 * api.h
 *
 *  Created on: Jun 13, 2019
 *      Author: 
 */

#ifndef API_H_
#define API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdbool.h>

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef enum FunctionState_enum {
	Disable		= 0,
	Enable		= 1,
}FunctionState_t;
typedef enum
{
	API_OK,
	API_ERR,

	API_GPIO_NUM_ERR,
	API_GPIO_FUNC_ERR,
	API_GPIO_INPUT0,
	API_GPIO_INPUT1,

	API_TIMRE_ID_ERR,
	API_TIMER_UNIT_ERR,

	API_PWM_ID_ERR,

	API_FLASH_START_ADDR_ILLEGAL,
	API_FLASH_START_ADDR_NOT_ALIGN,
	API_FLASH_END_ADDR_ILLEGAL,
	API_FLASH_ERASE_ERR,
	API_FLASH_WRITE_ERR,
}api_ret_value_e;

typedef enum 
{
	API_GPIO_1			= 0,
	API_GPIO_2			= 1,
	API_GPIO_3			= 2,
	API_GPIO_4			= 3,
	API_GPIO_5			= 4,
	API_GPIO_6			= 5,
	API_GPIO_7			= 6,
	API_GPIO_8			= 7,
	API_GPIO_9			= 32,
	API_GPIO_10			= 33,
}api_gpio_def_e;

typedef enum 
{
//	API_GPIO_Func1			= 0,	/// API_GPIO_1 ~ API_GPIO_10: default function
//	API_GPIO_Func2			= 1,	/// API_GPIO_1 ~ API_GPIO_10:
//	API_GPIO_Func3			= 2,	/// API_GPIO_1 ~ API_GPIO_8: analog
//	API_GPIO_Func4			= 3,	/// API_GPIO_1 ~ API_GPIO_10: digitial input
//	API_GPIO_Func5			= 4,	/// API_GPIO_1 ~ API_GPIO_10: digitial output 0
//	API_GPIO_Func6			= 5,	/// API_GPIO_1 ~ API_GPIO_10: digitial output 1


	API_GPIO_Func1			= 0,	/// API_GPIO_1 ~ API_GPIO_10: default function
	API_GPIO_Func2			= 1,	/// API_GPIO_1 ~ API_GPIO_10:
	API_GPIO_AuxADC			= 2,	/// API_GPIO_1 ~ API_GPIO_8: analog
	API_GPIO_FloatingInput	= 3,	/// API_GPIO_1 ~ API_GPIO_10: digitial input
	API_GPIO_Output0		= 4,	/// API_GPIO_1 ~ API_GPIO_10: digitial output 0
	API_GPIO_Output1		= 5,	/// API_GPIO_1 ~ API_GPIO_10: digitial output 1
	API_GPIO_Func7			= 6,	/// API_GPIO_7 ~ API_GPIO_8:
	API_GPIO_Func8			= 7,	/// API_GPIO_1 ~ API_GPIO_4:
	API_GPIO_Func9			= 8,	/// API_GPIO_3 ~ API_GPIO_8: interrupt input
	API_GPIO_Func10			= 9, 	/// API_GPIO_1 ~ API_GPIO_8: dacsdm_out
	API_GPIO_Func11			= 10,	/// API_GPIO_6 ~ API_GPIO_8: pwm_out0,1,2

	API_GPIO_HighZ			= 15,	/// API_GPIO_1 ~ API_GPIO_10:
	API_GPIO_PullDownInput	= 16,	/// API_GPIO_1 ~ API_GPIO_10:
	API_GPIO_PullUpInput	= 17,	/// API_GPIO_1 ~ API_GPIO_10:
}api_gpio_func_def_e;

typedef enum
{
    API_TIMER_0,
    API_TIM_ID_NUM
}api_tim_id_e;

typedef enum
{
	API_TIM_MS,
	API_TIM_US
}api_tim_unit_e;

typedef void (*api_timer_handler)(void);

typedef enum
{
    API_REPORT_AUDIO_ID = 1,
    API_REPORT_KEYBOARD_ID = 2,
    API_REPORT_K_ID = 0x4B,
    API_REPORT_T_ID = 0x54,
    API_REPORT_ID_MAX = API_REPORT_T_ID,
}api_hid_report_id_e;


typedef enum
{
    API_BAUD_4800 = 4800,
    API_BAUD_9600 = 9600,
    API_BAUD_19200 = 19200,
    API_BAUD_38400 = 38400,
    API_BAUD_57600 = 57600,
    API_BAUD_115200 = 115200,
}api_baud_rate_e;

typedef enum
{
    API_SARADC_MIC,
    API_SARADC_GPIO1,
    API_SARADC_GPIO2,
    API_SARADC_GPIO3,
    API_SARADC_GPIO4,
    API_SARADC_GPIO5,
    API_SARADC_GPIO6,
    API_SARADC_GPIO7,
    API_SARADC_GPIO8,
    API_SARADC_AUDAC_ITRIM_VOUT,
}api_saradc_path_e;

typedef enum
{
	API_PWM_0,
	API_PWM_1,
	API_PWM_2,
	API_PWM_NUM
}api_pwm_id_e;

typedef enum
{
	API_AUDIO_I2S,
	API_AUDIO_ADDA,
}api_audio_path_e;

typedef enum 
{
	API_CORECLK_96M		= 3,
	API_CORECLK_128M    = 2,
	API_CORECLK_154M    = 8,
	API_CORECLK_192M	= 1,
}api_coreclk_def_e;

typedef enum 
{
	API_USBMIC_1_CHANNEL	= 1,
	API_USBMIC_2_CHANNEL    = 2,
}api_usbmic_channel_def_e;

typedef enum 
{
	API_USBMIC_ADC_IN			= 0,
	API_USBMIC_I2S_MASTER_IN    = 1,
	API_USBMIC_I2S_SLAVE_IN   	= 2,
}api_usbmic_insel_def_e;

typedef enum 
{
	API_USBMIC_L_R_IN    	= 0,
	API_USBMIC_L_ADD_R_IN	= 1,
}api_usbmic_incfg_def_e;

/**
 ****************************************************************************************
 * @brief Set GPIO Function.
 *
 * The input params must belong to enum structure api_gpio_def_e and api_gpio_func_def_e.
 *
 * Example: want to use gpio3 for debug, you can pull gpio3 to high on the place you want
 *			like this "api_gpio_func_set(API_GPIO_3, API_GPIO_Func6);";
 *			and you can pull gpio3 to low on the place you want like this 
 *			"api_gpio_func_set(API_GPIO_3, API_GPIO_Func5);"
 *
 * @param[in]     eGPIOx:	gpio id
 * @param[in]     eFuncX: 	gpio function
 *
 * @return	API_OK: gpio function set successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_gpio_func_set(api_gpio_def_e eGPIOx, api_gpio_func_def_e eFuncX);

/**
 ****************************************************************************************
 * @brief Set GPIO Toggle.
 *
 * The function of input param GPIOx must be set to API_GPIO_Func5 or API_GPIO_Func6 
 * before calling this api function.
 * 
 * Example: First, use "api_gpio_func_set(eGPIOx, API_GPIO_Func5);" or use
 *			"api_gpio_func_set(eGPIOx, API_GPIO_Func6);" in user_init, and use 
 *			"api_gpio_toggle(eGPIOx);" for gpio toggle.
 *
 * @param[in]     eGPIOx:	gpio id
 *
 * @return	API_OK: gpio toggle set successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_gpio_toggle(api_gpio_def_e eGPIOx);

/**
 ****************************************************************************************
 * @brief Get GPIO Input Value.
 *
 * The function of input param GPIOx must be set to API_GPIO_Func4 before calling this api
 * function.
 * 
 * Example: First, use "api_gpio_func_set(eGPIOx, API_GPIO_Func4);" and use 
 *			"api_gpio_input_get(eGPIOx);" for receiving gpio input value.
 *
 * @param[in]     eGPIOx:	gpio id
 *
 * @return	API_GPIO_INPUT0: gpio input 0
 *			API_GPIO_INPUT1: gpio input 1
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_gpio_input_get(api_gpio_def_e eGPIOx);

/**
 ****************************************************************************************
 * @brief Start timer to process a handler in a period.
 *
 * The vHandler will be called after u16Num with eUnit when you call this api function.
 *
 * Example: If you want to process a function vHandler after 10ms, you can use this api
 *			like "api_timer_start(eId, 10, TIM_MS, vHandler);"
 *
 * @param[in]     eId:		timer id
 * @param[in]     u16Num: 	number to wait for
 * @param[in]     eUnit: 	the unit of number (include TIM_MS, TIM_US)
 * @param[in]     vHandler: process function after u16Num with eUnit time.
 *
 * @return	API_OK: timer start successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_timer_start(api_tim_id_e eId, uint16_t u16Num, api_tim_unit_e eUnit, api_timer_handler vHandler);

/**
 ****************************************************************************************
 * @brief Stop processing a handler.
 *
 * The vHandler will not be called after you call this api function.
 *
 * Example: If you have been starting a timer to process a function vHandler, and you 
 *			want to stop this action you can use this api like "api_timer_end(eId);"
 *
 * @param[in]     eId:		timer id
 *
 * @return	API_OK: timer stop successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_timer_end(api_tim_id_e eId);

/**
 ****************************************************************************************
 * @brief Delay time.
 *
 * The CPU will hold until delay time finish.
 *
 * Example: If you want to delay 10ms after you call a function, you can use this api 
 *			after your function "api_timer_delay(10, TIM_MS);".
 *
 * @param[in]     u16Num:		delay time length
 * @param[in]     eUnit:		the unit of delay time (include TIM_MS, TIM_US)
 *
 * @return	API_OK: delay time successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_timer_delay(uint16_t u16Num, api_tim_unit_e eUnit);

/**
 ****************************************************************************************
 * @brief connect usb process.
 *
 *****************************************************************************************
 */
void api_connect_usb(void);

/**
 ****************************************************************************************
 * @brief disconnect usb process.
 *
 *****************************************************************************************
 */
void api_disconnect_usb(void);

/**
 ****************************************************************************************
 * @brief hid send report routine.
 *
 *
 * @param[in]     ucAddr:		description address
 * @param[in]     u8Len:		description length
 *
 *****************************************************************************************
 */
void api_hid_report_desc_set(uint8_t* ucAddr, uint16_t usLen);

/**
 ****************************************************************************************
 * @brief usb config decription set routine.
 *
 *
 * @param[in]     ucAddr:		description address
 * @param[in]     u8Len:		description length
 *
 *****************************************************************************************
 */
void api_usb_config_desc_set(uint8_t* ucAddr, uint16_t usLen);

/**
 ****************************************************************************************
 * @brief hid send report routine.
 *
 *
 * @param[in]     u8HidNum:		report id
 * @param[in]     param:		report content
 * @param[in]     u8Len:		report content length
 *
 * @return	TRUE: send report successfully
 *			FALSE: send report failed
 *****************************************************************************************
 */
bool api_hid_send_report(api_hid_report_id_e u8HidNum, void* param, uint8_t u8Len);

/**
 ****************************************************************************************
 * @brief usb keyboard support config routine.
 *
 *
 * @param[in]     ucEn:  0->nonsupport, 1->support
 *
 *****************************************************************************************
 */
void api_keyboard_support_cfg(FunctionState_t NewState);

/**
 ****************************************************************************************
 * @brief usb keyboard continue send routine.
 *
 *
 * @param[in]     ucBuf:	send content point
 * @param[in]     usLen:	report content length
 *
 * @return	TRUE: send successfully
 *			FALSE: send failed
 *****************************************************************************************
 */
uint16_t api_keyboard_continue_send(uint8_t* ucBuf, uint16_t usLen);

/**
 ****************************************************************************************
 * @brief uart init routine.
 *
 * The input params must belong to enum type api_baud_rate_e.
 * 
 * @param[in]     eBaud: uart baud rate 
 *
 * @return	TRUE: uart init successfully
 *			FALSE: uart init failed
 *****************************************************************************************
 */
bool api_uart_init(api_baud_rate_e eBaud);

/**
 ****************************************************************************************
 * @brief check uart received data
 *
 * @return	uart received data number in byte.
 *****************************************************************************************
 */
uint16_t api_uart_in_waiting(void);

/**
 ****************************************************************************************
 * @brief uart receive routine.
 *
 * 
 *
 * @param[in]     buf:		read buffer point
 * @param[in]     len:		expect read data length
 *
 * @return	receive data length
 *****************************************************************************************
 */
uint16_t api_uart_read(uint8_t *buf, uint16_t len);

/**
 ****************************************************************************************
 * @brief uart send routine.
 *
 * 
 *
 * @param[in]     buf:		read buffer point
 * @param[in]     len:		expect read data length
 *
 *****************************************************************************************
 */
void api_uart_write(uint8_t *buf, uint16_t len);

/**
 ****************************************************************************************
 * @brief hid send report routine.
 *
 * 
 *
 * @param[in]     buf:		output string point
 *
 *****************************************************************************************
 */
void api_print_string(char *str);

/**
 ****************************************************************************************
 * @brief Get sar adc value.
 *
 * The input param ePathNum must belong to api_saradc_path_e. Before calling this api, you
 * need to set correct function(API_GPIO_Func4) of gpio that you use.
 *
 * @param[in]     u16AvgNum:	get u16AvgNum times value and average
 * @param[in]     ePathNum:		path num
 *
 * @return	FALSE: get sar adc value failed
 *			others: return sar adc value
 *****************************************************************************************
 */
uint16_t api_saradc_value_get(uint16_t u16AvgNum, api_saradc_path_e ePathNum);

/**
 ****************************************************************************************
 * @brief fixed pwm out.
 *
 * Init pwm function for led. Need to set gpio to funtion 11 for pwm_out before call this
 * api function.
 *
 * Example: If you want to use pwm_out_0 for led, you need to set gpio6 for pwm_out like
 *			"api_gpio_func_set(API_GPIO_6, API_GPIO_Func11);" firstly, and use
 *			"api_pwm_init(API_PWM_0, 0x1, 0x1);" secondly. Both are need to put in user_int.
 *
 * @param[in]     eId:				pwm id
 * @param[in]     u8PwmDutyRatio:	pwm duty ratio
 *									8h'01: high/low is 1:255
 *									8h'02: high/low is 2:254
 *									...
 *									8h'ff: high/low is 255:1
 *
 * @return	API_OK: pwm init successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_pwm_duty_ratio(api_pwm_id_e eId, uint8_t u8PwmDutyRatio);

/**
 ****************************************************************************************
 * @brief pwm init.
 *
 * Init pwm function for led. Need to set gpio to funtion 11 for pwm_out before call this
 * api function.
 *
 * Example: If you want to use pwm_out_0 for led, you need to set gpio6 for pwm_out like
 *			"api_gpio_func_set(API_GPIO_6, API_GPIO_Func11);" firstly, and use
 *			"api_pwm_init(API_PWM_0, 0x1, 0x1);" secondly. Both are need to put in user_int.
 *
 * @param[in]     eId:				pwm id
 * @param[in]     u8PwmRate:		pwm rate level
 *									2b'00: 2s
 *									2b'01: 3s
 *									2b'10: 6s
 *									2b'11: 9s
 * @param[in]     u8PwmDutyRatio:	pwm duty ratio
 *									8h'01: high/low is 1:255
 *									8h'02: high/low is 2:254
 *									...
 *									8h'ff: high/low is 255:1
 *
 * @return	API_OK: pwm init successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_pwm_init(api_pwm_id_e eId, uint8_t u8PwmRate, uint8_t u8PwmDutyRatio);

/**
 ****************************************************************************************
 * @brief pwm start.
 *
 * Need to init pwm before call api_pwm_start.
 *
 * @param[in]     eId:				pwm id
 *
 * @return	API_OK: pwm start successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_pwm_start(api_pwm_id_e	eId);

/**
 ****************************************************************************************
 * @brief pwm stop.
 *
 * Need to init pwm before call api_pwm_stop. When you want to stop pwm, you need to set
 * gpio function to others(ex. api_gpio_func_set(eGPIOx, API_GPIO_Func1)).
 *
 * @param[in]     eId:				pwm id
 *
 * @return	API_OK: pwm stop successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_pwm_stop(api_pwm_id_e eId);

/**
 ****************************************************************************************
 * @brief Audio path select.
 *
 * Select i2s path or adc_dac path to process audio.
 *
 * @param[in]     ePath:	audio path
 *****************************************************************************************
 */
void api_audio_path_set(api_audio_path_e ePath);

/**
 ****************************************************************************************
 * @brief Erase flash.
 *
 * Flash need to be erased before writen. Erase at least one sector(4KBytes) for each time. 
 *
 * @param[in]     u32Addr:		erase start address
 *								legal address is 0x20000~0x3EFFF and 0x40000~...
 * @param[in]     u32Size:		size need to be erased
 *
 * @return	API_OK: flash erased successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_flash_sector_erase(uint32_t u32Addr, uint32_t u32Size);

/**
 ****************************************************************************************
 * @brief Save sound parameters in flash.
 *
 * Save sound parameters in flash for using next time.
 *
 * @param[in]     u32Addr:		address to save
 *								legal address is 0x20000~0x3EFFF and 0x40000~...
 * @param[in]     pu8ParamBuf:	data need to save
 * @param[in]     u32DataSize:	data length of pu8ParamBuf
 *
 * @return	API_OK: save params successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_flash_param_save(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize);

/**
 ****************************************************************************************
 * @brief Read sound parameters from flash.
 *
 * Read sound parameters which have been saved in flash. A cpu reset need to carry out before
 * calling this api.
 *
 * @param[in]     u32Addr:		address to read
 *								legal address is 0x20000~0x3EFFF and 0x40000~...
 * @param[in]     pu8ParamBuf:	buffer for saving sound parameters from flash
 * @param[in]     u32DataSize:	data length of pu8ParamBuf
 *
 * @return	API_OK: read params successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_flash_param_read(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize);

/**
 ****************************************************************************************
 * @brief Read sound parameters from flash.
 *
 * Read sound parameters which have been saved in flash. A cpu reset need to carry out before
 * calling this api.
 *
 * @param[in]     u32Addr:		address to read
 *								legal address is 0x20000~0x3EFFF and 0x40000~...
 * @param[in]     pu8ParamBuf:	buffer for saving sound parameters from flash
 * @param[in]     u32DataSize:	data length of pu8ParamBuf
 *
 * @return	API_OK: read params successfully
 *			others: reference api_ret_value_e enum
 *****************************************************************************************
 */
api_ret_value_e api_flash_param_read_NoCache(uint32_t u32Addr, uint8_t *pu8ParamBuf, uint32_t u32DataSize);

/**
 ****************************************************************************************
 * @brief usb microphone config
 *
 *
 * @param[in]     api_usbmic_channel_def_e:	usb microphone channel options
 * @param[in]     api_usbmic_insel_def_e:	usb microphone input path options
 * @param[in]     api_usbmic_incfg_def_e:	usb microphone input pattern options @i2s input
 *****************************************************************************************
 */
void api_usbmic_set(api_usbmic_channel_def_e eUsbMicChannel, api_usbmic_insel_def_e eUsbMicAudioInSel, 
	api_usbmic_incfg_def_e eUsbMicI2sCfg);


/**
 ****************************************************************************************
 * @brief Enable GLOBAL Interrupt.
 *
 * When the user need write/erase Flash, GLOBAL Interrupt Disable( GLOBAL_INT_STOP() ) is need,
 * then calling this api to Enable GLOBAL Interrupt
 *
 * @param[in]  None
 *
 * @return	   None
 *
 *****************************************************************************************
 */
#define GLOBAL_INT_START() __nds32__setgie_en()

/**
 ****************************************************************************************
 * @brief Disable GLOBAL Interrupt.
 *
 * When the user need write/erase Flash, GLOBAL Interrupt Disable( GLOBAL_INT_STOP() ) is need,
 * calling this api to Disable GLOBAL Interrupt
 *
 * @param[in]  None
 *
 * @return	   None
 *
 *****************************************************************************************
 */
#define GLOBAL_INT_STOP() \
do { \
    __nds32__setgie_dis(); \
    __nds32__dsb(); \
} while (0)

#ifdef KT0203
/**
 ****************************************************************************************
 * @brief define User HID Receive Interrupt Handler
 *
 * buf size must > 4byte
 *
 *****************************************************************************************
 */
typedef void (* User_HID_ReceiveCallbackHandler)(uint8_t *buf);

/**
 ****************************************************************************************
 *
 * @brief Set User HID Receive Interrupt Handler
 *
 * calling this api to Set User HID Receive Interrupt Handler
 *
 *       HID CMD  byte:   0    1     2   3     4   5    6    7    8    9    10
 * USB Host Send Data:  |0x4b|0x00|0x00|0x00|0x00|0xb1| xx | dd | dd | dd | dd |          xx:RFU(hex), dd:data(hex)
 *
 *
 *****************************************************************************************
 */
void Set_User_HID_Receive_Handler(User_HID_ReceiveCallbackHandler HID_Handler);

/**
 ****************************************************************************************
 *
 * @brief User Sendback HID CMD&Data to USB Host
 *
 * len <= 4
 *
 * *       HID CMD  byte:    0    1     2   3     4   5    6    7    8    9    10
 * USB Host Receive Data:  |0x4b|0x00|0x00|0x00|0x00|0xb1| xx | dd | dd | dd | dd |          xx:RFU(hex), dd:data(hex)
 *
 *****************************************************************************************
 */
void User_HID_Send(uint8_t *buf, uint8_t len);

/**
 ****************************************************************************************
 * @brief Set USB Volume(Left And Right)
 *
 * vol = 0(Mute) ~ 127(12dB), 0.5dB/step
 * calling this api.
 *
 *
 *
 * @return	 none
 *
 *****************************************************************************************
 */
void api_post_usb_volume_set(uint8_t vol);

void Uart_Debug_Reg_Response(uint8_t *Rxbuf, uint8_t len);
#endif /* KT0203 */

#endif /* API_H_ */
