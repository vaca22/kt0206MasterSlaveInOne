/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_audio_app.h
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/
#ifndef USB_AUDIO_ADK_H_
#define USB_AUDIO_ADK_H_
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include"nds32_math_types.h"
#include"comm.h"
#include "usb_com.h"
#include "usb_ch9.h"
#include "usb_hid_app.h"
#include "usb_app.h"
#include "audio_process_adc2usb.h"
#include "audio_process_usb2dac.h"
#include "audio_in.h"
#include "audio_out.h"
#include "co_rbuf.h"
/*
 * MACRO DEFINES
 ****************************************************************************************
 */

/*
 * ENUM DEFINES
 ****************************************************************************************
 */

/*
 * STRUCTURE DEFINES
 ****************************************************************************************
 */
typedef struct usb_sdk_ftable_stru
{
	void (*AudioOutSpeaker)(q31_t *, q31_t *, q31_t *, q31_t *, UINT16 , UINT16);
	void (*USBOutSpeaker)   (void);
	void (*AudioInSpeaker)  (q31_t *, q31_t *, q31_t *, q31_t *, UINT16 , UINT16 );
	void (*USBInSpeaker)  (void);
	void (*OutTestRead)   (q31_t *, q31_t *, q31_t *, q31_t *, UINT16 , UINT16 );
	void (*InTestWrite)    (q31_t *, q31_t *, q31_t *, q31_t *, UINT16 , UINT16 );
	void (*InDongleWrite)   (q31_t *, q31_t * , q31_t *, q31_t *, UINT16 , UINT16);
	void (*InDongleRead)   (void);
	void (*InterfaceAdcDac) (void);
	void (*InterfaceI2S) (void);
	uint32_t (*BufInit)    (uint32_t);
} usb_sdk_ftable_t;
/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern co_rbuf_t *pRBufAudioL;
extern co_rbuf_t *pRBufAudioR;
extern stUSB_Audio_Dev stUsbAudio;
extern const int32_t sin_data[];
extern int32_t usb_data[96];//rom里面定义的, adc in data after asrc
extern int32_t usb_data_in[48];//rom里面定义的，adc或者i2s_in中断来了以后，调用new_patch_Audio_In_Speaker函数，把adc或i2s buffer里面的数据放到usb_data_in[48]里面
extern int32_t usb_data_left[96]; //usb out data after asrc
extern int32_t usb_data_right[96];//usb out data after asrc

extern volatile uint8_t AuOutStartFlg;
extern uint8_t g_u8SamPointNum;
extern usb_sdk_ftable_t *pusb_sdk_ftabl;
extern int8_t u8UsbReadFlag;
extern int8_t u8AdcWriteFlag;
extern uint32_t u32USBOutIsrCnt;
volatile uint8_t u8DacNeedStart;
extern int32_t DAC_DC_CALI_L;
extern int32_t DAC_DC_CALI_R;

extern uint32_t dac_l_mute_det_cnt;
extern uint32_t dac_l_peak_dat;
extern uint8_t  dac_mute_flag;

extern volatile uint32_t new_ramp_signal;
extern volatile uint16_t rampcnt;
extern uint8_t Audio_DAC_PowerOff_Status;
extern uint32_t Audio_DAC_PowerOff_CNT;
extern uint8_t AUDAC_MUTE_BY_PDDAC_EN;		//for OTP
extern uint8_t AUDAC_POWEROFF_CNT_WIN; 	//for OTP
extern uint8_t AUDAC_MUTE_DET_WIN;		//for OTP, UNIT ms
extern uint32_t AUDAC_MUTE_DET_THRD;    //for OTP,
extern volatile uint8_t AuOutIntFlg;
extern volatile uint8_t IsRampDown;
extern volatile uint8_t DacMuteByPdFlg;
extern volatile uint8_t DacRecoverFromPdFlg;
extern uint32_t ramp_dcoffset;	//for OTP
extern uint32_t rampup_step;		//for OTP
extern uint32_t rampdown_step;		//for OTP
extern volatile int32_t cos_ramp_signal;
//0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
extern const uint32_t DAC_FS_TABLE[];

//int32_t new_usb_data_in[AUDIO_SAMPLE_BLOCK_SIZE*2]={0};
//int32_t new_usb_data_mute[96] = {0};//usb录音关闭的时候，把0送往usb,可能还得放回函数里每次都初始化

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */
void Audio_In_Speaker(q31_t *pAdc0Addr, q31_t *pAdc1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal);
void Audio_Out_Speaker(q31_t *pDac0Addr,  q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal);
void Audio_Out_Test_Read(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal);
void Audio_In_Test_Write(q31_t *pAdcAddr, q31_t *pAdc1Addr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT16 Signal);
void Audio_In_Dongle_Write(q31_t *pAdc0Addr,q31_t *pAdc1Addr, q31_t *pI2sInlAddr, q31_t *pI2sInrAddr, UINT16 SampleNum, UINT16 Signal);
void USB_In_Speaker(void);
void USB_Out_Speaker(void);
void USB_In_Dongle_Read(void);
void I2S_Audio_Out_Speaker(q31_t *pDac0Addr, q31_t *pDac1Addr, q31_t *pI2sOutlAddr, q31_t *pI2sOutrAddr, UINT16 SampleNum, UINT16 Signal);
void USB_InterfaceSetting_I2S(void);
void USB_InterfaceSetting_adc_dac(void);
uint32_t USB_Buf_Init(uint32_t uInBaseAddr);
void usb_sdk_patch_init(void);
extern void new_usb_sdk_patch_init(void);

void asrc_write_ringbuf(
	    int32_t *pUSB_dacbuf_left,
	    int32_t *pUSB_dacbuf_right);
extern void patch_USB_Out_Speaker(void); //USB 1ms interrupt

#endif//USB_AUDIO_APP_H_

