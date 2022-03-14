#ifndef _BLL_CONFIG_H_
#define _BLL_CONFIG_H_

#include <stdint.h>
#include "reg_eft.h"


typedef struct
{
    char FirmVer[16];
    char mData[16];
    char mTime[16];
    uint8_t VerServer[16];
} version_t;


typedef struct
{
    uint32_t SupportAppleEarphone:  1;          //0->nonsupport, 1->support
    uint32_t SupportUsbKeyboard:    1;          //0->nonsupport, 1->support
    uint32_t JackSenseSel:          1;          //0->jack sense hardware, 1->GPIO key hardware
    uint32_t AudioPathSel:          2;          //1->I2S path, 2->ADC_DAC path
    uint32_t DongleAudioInSel:      2;          //0->adc in, 1->i2s master in, 2->i2s slave in
    uint32_t DongleAudioInCfg:      1;          //0->left + right, 1->left | right
    uint32_t DongleUsbInCfg:        1;          //0->left | right, 1->left + right
    uint32_t DongleUsbInChannel:    2;          //1->1 channel, 2->2 channel
    uint32_t RFU:                   21;         //
} func_config_t;

typedef struct
{
    uint32_t PgaADC: 8 ;
    uint32_t RFU1: 24;
    uint32_t PgaDACR: 15 ;
    uint32_t PgaDACL: 15 ;
    uint32_t RFU2: 2;
    uint32_t THDCfg;
} Perf_config_t;

typedef struct
{
    uint32_t UsbCodeState;    //1
    uint8_t UsbManufact[28];  //7
    uint8_t UsbProduct[28];   //7
    uint8_t UsbSerial[28];    //7
    uint8_t UsbStringID[12];  //3
    uint16_t  RFU0;
    uint16_t UsbProductID;   //1
    uint8_t ucUsbMaxPower;
    uint8_t RFU1[3];         //1
    uint16_t OutFreqEnCtrl; //out_frequency_en;
    uint16_t InFreqEnCtrl; //in_frequency_en;    1
    uint32_t RFU2;          //1
} USB_config_t;

typedef union
{
    struct {
        uint32_t FramFlag;                     		 //  1

        uint32_t RFU[1];    						//   1

        uint32_t SoftCheck;                          //   1

        version_t Version; 							//   16

        uint32_t RFU0[1];                           //   1

        uint32_t SaveDataAddr;  					 //  1

        uint32_t RFU1[1];       					//  2

        un_DSPRegAll_t DSPRegAll;     				//160

        uint32_t RFU2[1];      					    //1  		 ==>0x2E0

        uint32_t STUDY_REG[8];      				 //  8   ��ֹʹ��

        uint32_t RFU3[2];     						  // 2

        USB_config_t USBReg;  						 //29

        uint32_t RFU4[4];      							 //  4

        func_config_t FuncCfg; //IC function config struct  1

        uint32_t RFU5[1];       //                          1

        Perf_config_t PerfCfg;  // performance config struct 3

        uint32_t RFU6[23];       //                          23

        uint32_t FLASHMODE;     //  

        uint32_t Crc16;         //                          1  //240
    };
    uint32_t ALL32[256];
} config_t;

#define config_IDX(mem) (((uint32_t)(&(((config_t *)0)->mem)))>>2)

extern uint8_t isFlashValid;
extern config_t* g_pstConfig;
extern volatile const config_t g_stVendorConfig;
// void ChipCfg_Set(config_t* pstConfig);
void ChipCfg_Init(void);

#endif
