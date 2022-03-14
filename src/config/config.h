#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef  __cplusplus
extern "C" {
#endif

/* Check to see if this file has been included already.  */
#ifndef __ASSEMBLER__
#include <nds32_intrinsic.h>
#endif

//debug options
//#define UART_DEBUG


#define CHIP_ON     0
#define CHIP_OFF    1

#define XTALCLKFREQ             (24 * MHz)
#define APBCLKFREQ1             (XTALCLKFREQ / 2)

/* System Clock */
#define MHz                     (1000000)
#define KHZ                     (1000)



//memory base
#define RAM0_BASE_ADDR      (0x40000u) //0x40000 - 0x47FFF
#define RAM1_BASE_ADDR      (0x48000u) //0x48000 - 0x4FFFF
#define RAM2_BASE_ADDR      (0x50000u) //0x50000 - 0x57FFF
#define RAM3_BASE_ADDR      (0x58000u) //0x58000 - 0x5BFFF

#define AHB_REG_BASE_ADDR   (0xC0000000u)	//0xC0000000 ~ 0xC000FFFF
#define APB_REG_BASE_ADDR   (0xC0010000u)	//0xC0010000 ~ 0xC001FFFF
#define LM_REG_BASE_ADDR 	(0x0005FF00u)	//0x0005FF00 ~ 0x0005FFFF

//peripheral base
#define USB_BASE			(0xC0000000u)	//0xC0000000 ~ 0xC0007FFF
#define QSPIC_BASE			(0xC0008000u)	//0xC0008000 ~ 0xC000FFFF
#define OTPC_BASE			(0xC0010000u)	//0xC0010000 ~ 0xC0010FFF
#define DW_TIMER_BASE		(0xC0011000u)	//0xC0011000 ~ 0xC00113FF
#define DW_WDT_BASE			(0xC0011400u)	//0xC0011400 ~ 0xC00117FF
#define DW_UART_BASE		(0xC0011800u)	//0xC0011800 ~ 0xC0011BFF
#define DW_I2C_BASE			(0xC0011C00u)	//0xC0011C00 ~ 0xC0011FFF
#define SYS_CTRL_BASE		(0xC0012000u)	//0xC0012000 ~ 0xC001FFFF

#define RAM_USB_FIFO_BASE_ADDR  (RAM0_BASE_ADDR)
#define RAM_USB_BUF_BASE_ADDR   (RAM_USB_FIFO_BASE_ADDR + 0x1840)
#define RAM_OTP_REG_BASE_ADDR   (RAM_USB_BUF_BASE_ADDR + (1024 * 3))
#define RAM_DSP_REG_BASE_ADDR   (RAM_OTP_REG_BASE_ADDR + 0x400)
#define RAM_SOFT_REG_BASE_ADDR  (RAM_DSP_REG_BASE_ADDR + 0x2E0)
#define RAM_STUDY_REG_BASE_ADDR (RAM_SOFT_REG_BASE_ADDR + 0x20)
#define RAM_FIFO_BASE_ADDR      (RAM_STUDY_REG_BASE_ADDR + 0x100)

//*****************************************************************//
#define AUDIO_FIFO_ADDR 		(RAM_FIFO_BASE_ADDR)
// #define AUDIO_I2S_Out0_L_ADDR	(AUDIO_FIFO_ADDR       + 0x1000)
// #define AUDIO_I2S_Out0_R_ADDR	(AUDIO_I2S_Out0_L_ADDR + 0x1000)
// #define AUDIO_DAC0_ADDR			(AUDIO_I2S_Out0_R_ADDR + 0x1000)
// #define AUDIO_DAC1_ADDR			(AUDIO_DAC0_ADDR 	   + 0x1000)
// #define AUDIO_I2S_In0_L_ADDR		(AUDIO_DAC1_ADDR 	   + 0x1000)
// #define AUDIO_I2S_In0_R_ADDR		(AUDIO_I2S_In0_L_ADDR  + 0x1000)
// #define AUDIO_ADC0_ADDR			(AUDIO_I2S_In0_R_ADDR  + 0x1000)
//*****************************************************************//
	
#define RAM_CLEAR_SPACE_START_ADDR	(RAM_OTP_REG_BASE_ADDR)	
#define RAM_CLEAR_SPACE_LEN			(0x000)




//#define RD_REG(RegName) { un_##RegName _TmpReg; _TmpReg.overall = RegName;
//#define WR_REG(RegName) RegName = _TmpReg.overall; }
//#define NWR_REG()    }


#ifdef  __cplusplus
}
#endif

#endif /* MUSES_H_ */
