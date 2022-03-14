/*
 * asrc_dac_fs_ppm.c
 *
 *  Created on: May 11, 2018
 *      Author: lizhen
 */
// 2018-11-27, coarse_ppm protection to [-15000,15000]ppm
// 2018-12-05, (1) use  memset() to clear buf,
//             (2) clear buffer in ppm_init() for avoiding the start up noise
//             (3) delete asrc filter performance 0/1,
//             (4) change memset() back to for(...), memset() is too slow
//2018-12-06   (1) Do not clear the  dac_ringbuf_left[],  dac_ringbuf_right[],
//2018-12-14   (1) clear buffer in the coarse_ppm, reduce peak CPU usage
//             (2) do asrc freq ratio cali  after usb_write_firstxx_packet_thrsh/2,
//2018-12-19   (1) change to support [-5%, 5%] high osc freq error
//2019-01-24   (1) add mag compensation for Fs=44.1k
//             (2) add relock_init() function
#include "hal_config.h"
#include "com_includes.h"
#include "asrc_dac_fs_ppm.h"
#include "asrc_codec_filter.h"
#include "nds32_filtering_math.h"
#include "asrc_codec_filter_fast.h"
#include "gpio_ctrl.h"
#include "asrc_adc_fs_ppm.h"

uint8_t dac_interrupt_cnt;
int32_t *dac_ringbuf_left = NULL;
int32_t *dac_ringbuf_right = NULL;
int32_t *dac_xinbuf_left = NULL;
int32_t *dac_xinbuf_right = NULL;

int32_t ASRC_RINGBUF_LEN_patch;
int32_t DAC_MAX_PPM ;
int32_t dac_fs_ratio;
int32_t dpll_bw_sel;
int16_t usb_write_firstxx_packet;
int16_t usb_write_packet_num;
int16_t usb_write_firstxx_packet_thrsh;
int16_t usb_audio_out_off_cnt_thrsh;
int16_t dac_loop_out_scale;
extern int32_t adc_coarse_locked   ;
extern int32_t adc_narrow_state   ;
extern int32_t adc_fine_ppm       ;
extern int32_t adc_coarse_ppm_abs ;
extern int16_t adc_dpll_bw_sel    ;
extern int32_t adc_coarse_ppm_scale;
extern int32_t USB_DAC_FS_D;
extern uint32_t Audio_DAC_PowerOff_CNT;
extern volatile uint8_t u8UsbInSpeakerSts;
extern int32_t coarse_ppm_from_timer;
int32_t  dac_ringbuf_right_rp ;
int32_t  dac_ringbuf_right_wp ;
int16_t  stereo_phase_a = 0;  //OTP
int16_t  stereo_phase_b = 1;  //OTP
int16_t  stereo_phase_c = 1;  //OTP
int8_t   left_mag_delta = 0;   //OTP
int8_t   right_mag_delta = 0;  //OTP
//----------------- Mag compensation for fs = 44.1k -------------------------------------------//
// coeff in 32Q28, [b0,b1,b2,-a1,-a2], shiftpositive=3
q31_t mag_compen_coeff[5]         = {0};  //  coeff for mag compensation , 32x32 EQ
q31_t mag_compen_left_state[4]    = {0};  //state for left mag compensation
q31_t mag_compen_right_state[4]   = {0};  //state for left mag compensation
nds32_bq_df1_q31_t   mag_compen_left_inst  = {1, mag_compen_left_state,   mag_compen_coeff,  (int8_t)3};
nds32_bq_df1_q31_t   mag_compen_right_inst = {1, mag_compen_left_state,   mag_compen_coeff,  (int8_t)3};
//---------------------------------------------------------------------------------------------
//performance level, SNDR and CPU cost tradeoff option
// 0:pfzero 10M , 1:pflow 20M, 2:pfmid 30M,3: pfhigh 40M for 48k stereo audio
// 0 or 1, pflow,  2: pfmid, 3:pfhigh for 96k stereo audio
uint8_t ASRC_DAC_PFORMANCE      = 0; //only support 0,2,3
uint8_t ASRC_DAC_PFORMANCE_96K  = 0; //only support 2,3
uint8_t g_ppm_range = 5;
int32_t  asrc_xinbuf_len = ASRC_XINBUF_LEN; // asrc_xinbuf_len <= ASRC_XINBUF_LEN
int32_t  dac_ringbuf_rp  = 0;
int32_t  dac_ringbuf_wp =  (ASRC_RINGBUF_LEN / 2);

int32_t USB_DAC_FS   = 8;         //0:8k, 1:11.025k, 2:12k,3:16k,4:22.05k,5:24k,6:32k,7:44.1k,8:48k,9:96k
int32_t USB_DAC_FS_D = -1; //sample rate delay
int32_t USB_DAC_EOF_FLAG     = 0;
int32_t USB_DAC_ASRC_ENABLE  = 1;

extern int32_t USB_DAC_PCM_NUM;  //PCM sample number in 1ms seconds
int32_t DAC_FS_RATIO_Q26  = 68719477;  //Fsin/Fsout in Q26 format, 48k/46.875k*2^26
int32_t DAC_STEREO_MODE  = 1;
int32_t DAC_REMAIN_NUM_TARGET = 270;
int32_t coarse_cnt      = 0 ;
int32_t coarse_cnt2     = 0 ;

int32_t start_coarse_ppm   = 0;
int32_t start_coarse_ppm_d = 0;
int32_t usb_audio_out_off_cnt = 0;

int32_t coarse_state     = 0;
//int32_t coarse_nxtstate  = 0;

int32_t remain_num_d     = 0;
int32_t remain_num       = 0;
int32_t remain_num_min   = 0;
int32_t remain_num_min0  = 0;
int32_t remain_min_search = 888;

//int32_t continuous_win   = 8;
int32_t coarse_ppm_scale = 2333;
int32_t coarse_ppm       = 0;
int32_t coarse_ppm_hold  = 0;
int32_t coarse_locked    = 0;
int32_t fine_ppm         = 0;
int32_t fine_locked      = 0;
int32_t narrow_state     = 0;
int32_t cnt_for_narrow   = 0;
int32_t loopflt_out      = 0 ;
int32_t dac_Ka           = 0;
int32_t dac_Kb           = 0;
int32_t dpll_err_d1      = 0;
int32_t DAC_MAX_PIDSTEP   = 200 << 10;
int32_t DAC_MAX_NARROWCNT = 6000;
int64_t dac_nco_left = 0;
int64_t dac_nco_right = 0;
int64_t dac_nco_buf_left = 0;
int64_t dac_nco_buf_right = 0;
int32_t remain_delta0;
int32_t coarse_unlock;
int32_t coarse_ppm_abs;
extern uint8_t  asrc_return_flag;
extern int32_t (*fir_poly_pffast)[11];
const int32_t  new_fir_poly_pffast[32][11] =
{
    {    63, 2911, -7141, -108867, -71943, 317200, 306480, -79980, -105121, -5716, 2733,    },
    {    41, 3090, -8686, -112504, -63419, 327427, 295302, -87522, -101286, -4405, 2556,    },
    {    55, 3267, -10351, -116016, -54418, 337129, 283700, -94561, -97381, -3205, 2381,    },
    {    70, 3441, -12141, -119381, -44952, 346276, 271709, -101095, -93421, -2113, 2211,   },
    {    89, 3610, -14058, -122581, -35036, 354838, 259367, -107119, -89424, -1124, 2045,   },
    {   111, 3771, -16103, -125595, -24685, 362788, 246712, -112634, -85406, -234, 1884,   },
    {   137, 3923, -18277, -128404, -13917, 370099, 233782, -117641, -81382,  562, 1730,   },
    {   167, 4063, -20583, -130987, -2753, 376750, 220614, -122142, -77367, 1269, 1582,    },
    {   200, 4187, -23019, -133325, 8786, 382717, 207249, -126142, -73375, 1891, 1441,    },
    {   239, 4295, -25586, -135396, 20677, 387982, 193726, -129646, -69418, 2432, 1308,    },
    {   282, 4381, -28282, -137180, 32893, 392527, 180083, -132664, -65509, 2899, 1182,    },
    {   331, 4444, -31107, -138659, 45409, 396338, 166360, -135203, -61659, 3294, 1064,    },
    {   386, 4478, -34058, -139813, 58196, 399401, 152595, -137274, -57878, 3625,  954,    },
    {   446, 4482, -37131, -140623, 71224, 401708, 138826, -138889, -54176, 3894,  851,    },
    {   513, 4451, -40323, -141070, 84461, 403250, 125092, -140062, -50562, 4106,  755,    },
    {   587, 4381, -43629, -141136, 97874, 404022, 111429, -140806, -47044, 4267,  668,    },
    {   668, 4267, -47044, -140806, 111429, 404022, 97874, -141136, -43629, 4381,  587,    },
    {   755, 4106, -50562, -140062, 125092, 403250, 84461, -141070, -40323, 4451,  513,    },
    {   851, 3894, -54176, -138889, 138826, 401708, 71224, -140623, -37131, 4482,  446,    },
    {   954, 3625, -57878, -137274, 152595, 399401, 58196, -139813, -34058, 4478,  386,    },
    {  1064, 3294, -61659, -135203, 166360, 396338, 45409, -138659, -31107, 4444,  331,    },
    {  1182, 2899, -65509, -132664, 180083, 392527, 32893, -137180, -28282, 4381,  282,    },
    {  1308, 2432, -69418, -129646, 193726, 387982, 20677, -135396, -25586, 4295,  239,    },
    {  1441, 1891, -73375, -126142, 207249, 382717, 8786, -133325, -23019, 4187,  200,    },
    {  1582, 1269, -77367, -122142, 220614, 376750, -2753, -130987, -20583, 4063,  167,    },
    {  1730,  562, -81382, -117641, 233782, 370099, -13917, -128404, -18277, 3923,  137,   },
    {  1884, -234, -85406, -112634, 246712, 362788, -24685, -125595, -16103, 3771,  111,   },
    {  2045, -1124, -89424, -107119, 259367, 354838, -35036, -122581, -14058, 3610,   89,   },
    {  2211, -2113, -93421, -101095, 271709, 346276, -44952, -119381, -12141, 3441,   70,   },
    {  2381, -3205, -97381, -94561, 283700, 337129, -54418, -116016, -10351, 3267,   55,    },
    {  2556, -4405, -101286, -87522, 295302, 327427, -63419, -112504, -8686, 3090,   41,    },
    {  2733, -5716, -105121, -79980, 306480, 317200, -71943, -108867, -7141, 2911,   63,    },
};
extern int32_t (*fir_poly_96k_pffast)[5];
const int32_t new_fir_poly_96k_pffast[32][5] =
{
    {    57, 17131, 116341, 113122, 15497,  },
    {    55, 18880, 119435, 109792, 13975,  },
    {    81, 20746, 122391, 106364, 12562,  },
    {   114, 22732, 125196, 102852, 11254,  },
    {   157, 24837, 127837, 99271, 10047,   },
    {   210, 27064, 130304, 95634, 8938,   },
    {   276, 29413, 132583, 91956, 7922,   },
    {   357, 31882, 134667, 88249, 6994,   },
    {   455, 34471, 136543, 84528, 6150,   },
    {   572, 37178, 138205, 80805, 5385,   },
    {   711, 40000, 139645, 77093, 4694,   },
    {   876, 42933, 140855, 73404, 4073,   },
    {  1069, 45974, 141830, 69749, 3517,   },
    {  1293, 49117, 142565, 66141, 3022,   },
    {  1553, 52358, 143057, 62588, 2582,   },
    {  1852, 55688, 143304, 59100, 2193,   },
    {  2193, 59100, 143304, 55688, 1852,   },
    {  2582, 62588, 143057, 52358, 1553,   },
    {  3022, 66141, 142565, 49117, 1293,   },
    {  3517, 69749, 141830, 45974, 1069,   },
    {  4073, 73404, 140855, 42933,  876,   },
    {  4694, 77093, 139645, 40000,  711,   },
    {  5385, 80805, 138205, 37178,  572,   },
    {  6150, 84528, 136543, 34471,  455,   },
    {  6994, 88249, 134667, 31882,  357,   },
    {  7922, 91956, 132583, 29413,  276,   },
    {  8938, 95634, 130304, 27064,  210,   },
    { 10047, 99271, 127837, 24837,  157,   },
    { 11254, 102852, 125196, 22732,  114,  },
    { 12562, 106364, 122391, 20746,   81,  },
    { 13975, 109792, 119435, 18880,   55,  },
    { 15497, 113122, 116341, 17131,   57,  },
};
extern int32_t (*DAC_MAG_COEFF_ARRAY)[5];
const int32_t new_DAC_MAG_COEFF_ARRAY[5][5] =
{
    {133170884,   -30323202,    30338612,    30323202,   104925960}, //mag1 for 48k/32k/24k/16k/12k/8k
    {402354770,   423410250,    68232679,  -423410250,  -202151993}, //mag0 for 44.1k/22.05k/11.025k
    {122472762,   -16762415,    29643787,    16762415,   116318907},//mag0 for 44.1k/22.05k/11.025k
    {494469914,   468018092,    -7190830,  -468018092,  -218843628}, //mag1 for 44.1k/22.05k/11.025k
    {323788280,   -14150237,    36637165,    14150237,   -91989989},//mag0 for 96k, mag1 not used
};

extern int8_t u8UsbReadFlag;
extern volatile uint8_t AuInStartFlg;
extern int16_t adc_dpll_bw_sel;
extern int32_t ADC_MAX_PPM;
extern int32_t adc_coarse_ppm_abs;
extern int16_t adc_loop_out_scale;
extern int32_t DAC_MAX_PIDSTEP;
st_THDCoeff  THDCoeff;
//uint16_t Crosstalk_cmp_fact=531;      //for OTP, DAC Crosstalk compensation factor
// (1/531)*65536 = 123
uint16_t Crosstalk_cmp_fact = 123;      //for avoding division
typedef struct
{
    uint32_t (*Asrc_Dac_Fs_Ppm_Init)(uint32_t uInBaseAddr);
    void (*estimation_ppm_init)(void);
    void (*estimate_coarse_ppm)(void);
    void (*estimate_fine_ppm)(void);
    void (*asrc_dac_top)(int32_t *pUSB_dacbuf_left,
                         int32_t *pUSB_dacbuf_right,
                         int32_t *pOUT_dacbuf_left,
                         int32_t *pOUT_dacbuf_right);
    void (*asrc_Clean_RingBuf)(void);
    void (*estimation_ppm_relock_init)(void);
} asrc_dac_ftable_t;

asrc_dac_ftable_t *pasrc_dac_ftabl = NULL;

uint32_t Asrc_Dac_Fs_Ppm_Init(uint32_t uInBaseAddr)
{
    return pasrc_dac_ftabl->Asrc_Dac_Fs_Ppm_Init(uInBaseAddr);
}

extern uint32_t Patch_Asrc_Dac_Fs_Ppm_Init(uint32_t uInBaseAddr);

uint32_t new_Patch_Asrc_Dac_Fs_Ppm_Init(uint32_t uInBaseAddr)
{

	USB_DAC_FS_D     = -1;
	start_coarse_ppm = 0;
	Audio_DAC_PowerOff_CNT = 0;

	ASRC_RINGBUF_LEN_patch   = (512*2);
	asrc_xinbuf_len = ASRC_XINBUF_LEN_patch;
    uInBaseAddr = ((uInBaseAddr + 3) & 0xFFFFFFFC); //int32_t align

    dac_ringbuf_left = (int32_t *)(uInBaseAddr);
    uInBaseAddr += ASRC_RINGBUF_LEN_patch * sizeof(int32_t);

    dac_ringbuf_right = (int32_t *)(uInBaseAddr);
    uInBaseAddr += ASRC_RINGBUF_LEN_patch * sizeof(int32_t);

    dac_xinbuf_left = (int32_t *)(uInBaseAddr);
    uInBaseAddr += ASRC_XINBUF_LEN_patch * sizeof(int32_t);

    dac_xinbuf_right = (int32_t *)(uInBaseAddr);
    uInBaseAddr += ASRC_XINBUF_LEN_patch * sizeof(int32_t);

    return uInBaseAddr;
}


void estimation_ppm_init(void)
{
    pasrc_dac_ftabl->estimation_ppm_init();
}

void new_Patch_estimation_ppm_init(void)
{
    int16_t ii;
    int16_t stereo_phase = 0;

    mag_compen_left_inst.nstage = 1;
    mag_compen_left_inst.state = mag_compen_left_state;
    mag_compen_left_inst.coeff = mag_compen_coeff;
    mag_compen_left_inst.shift = (int8_t)3;

    mag_compen_right_inst.nstage = 1;
    mag_compen_right_inst.state = mag_compen_right_state;
    mag_compen_right_inst.coeff = mag_compen_coeff;
    mag_compen_right_inst.shift = (int8_t)3;

    for (ii = 0; ii < 4; ii++)
    {
        mag_compen_left_state[ii] = 0;
        mag_compen_right_state[ii] = 0;
    }
    //272741622   451088578   230867461  -451088578  -235173627 //2dB
    // 271656136   450273979   231043504  -450273979  -234264184 //1.5dB
    mag_compen_coeff[0] =  271656136;
    mag_compen_coeff[1] =  450273979;
    mag_compen_coeff[2] =  231043504;
    mag_compen_coeff[3] = -450273979;
    mag_compen_coeff[4] = -234264184;

    dac_interrupt_cnt = 0;
    ASRC_DAC_PFORMANCE = 0; //only support 2,3
    ASRC_DAC_PFORMANCE_96K = 0;
    DAC_MAX_PPM  = ((g_ppm_range * 10000) << 10); //max ppm in Q10
    DAC_MAX_PIDSTEP = 50 << 10;
    usb_write_firstxx_packet_thrsh = 12 * 8; // 32 ms
    dac_nco_left    = 0;
    dac_nco_right   = 0;
    usb_write_firstxx_packet       = 0;

    if     (ASRC_DAC_PFORMANCE == 0)
        asrc_xinbuf_len = 5 + ASRC_OBUF_LEN_patch + (ASRC_OBUF_LEN_patch >> 1);
    else if (ASRC_DAC_PFORMANCE == 1)
        asrc_xinbuf_len = 13 + ASRC_OBUF_LEN_patch + (ASRC_OBUF_LEN_patch >> 1);
    else if (ASRC_DAC_PFORMANCE == 2)
        asrc_xinbuf_len = 19 + ASRC_OBUF_LEN_patch + (ASRC_OBUF_LEN_patch >> 1);
    else
        asrc_xinbuf_len = 26 + ASRC_OBUF_LEN_patch + (ASRC_OBUF_LEN_patch >> 1);

    if (USB_DAC_FS ==  7 ) //44.1k
    {
        stereo_phase = stereo_phase_a;
        dac_ringbuf_rp   = 0;
        dac_ringbuf_right_rp  = 0;  //100/1000 @44.1k  <==> 16.3degree @20kHz
    }
    else if (USB_DAC_FS == 8 ) //48k
    {
        stereo_phase = stereo_phase_b; //2.5degree  ////100/1000 @48k  <==> 15degree @20kHz
        dac_ringbuf_rp   = 0;
        dac_ringbuf_right_rp  = 0;
    }
    else if (USB_DAC_FS == 9 )
    {
        stereo_phase = stereo_phase_c;
        dac_ringbuf_rp   = 0;
        dac_ringbuf_right_rp  = 0;
    }
    else
    {
        dac_ringbuf_rp   = 0;
        dac_ringbuf_right_rp  = 0;
    }

    dac_nco_buf_left = ( ((int64_t) 67108864 * stereo_phase ) / 1000) ; // 2^26 is one unit,  ((nco)>>(5+21));
    dac_nco_buf_right = 0;

    // dac_ringbuf_wp        =  ASRC_RINGBUF_LEN_patch / 2 - 96;
    // dac_ringbuf_right_wp  =  ASRC_RINGBUF_LEN_patch / 2 - 96;

    //when 48kHz mode, Muses DAC FS = 12M/256 = 46.875K
    //when 96kHz mode, Muses DAC FS = 12M/128 = 93.75k
    //round(Fsin/Fsout*2^26)
#if (ASRC_OBUF_LEN_patch == 16)
    if (USB_DAC_FS <= 8)
        usb_audio_out_off_cnt_thrsh = 6;
    else
        usb_audio_out_off_cnt_thrsh = 12;
#else
    if (USB_DAC_FS <= 8)
        usb_audio_out_off_cnt_thrsh = 3;
    else
        usb_audio_out_off_cnt_thrsh = 6;
		
#endif
    switch (USB_DAC_FS)
    {
    case 0:   // usb audio out freq
    { DAC_FS_RATIO_Q26 =  11184811;  coarse_ppm_scale  = 1313; dac_loop_out_scale = 12; DAC_REMAIN_NUM_TARGET = 138 * 2;} break; //8k
    case 1:
    { DAC_FS_RATIO_Q26 =  15414067;  coarse_ppm_scale  = 955; dac_loop_out_scale = 10; DAC_REMAIN_NUM_TARGET = 143 * 2;} break; //11.025k
    case 2:
    { DAC_FS_RATIO_Q26 =  16777216;  coarse_ppm_scale  = 876; dac_loop_out_scale = 8; DAC_REMAIN_NUM_TARGET = 144 * 2;} break; //12k
    case 3:
    { DAC_FS_RATIO_Q26 =  22369621;  coarse_ppm_scale = 657; dac_loop_out_scale = 6; DAC_REMAIN_NUM_TARGET = 150 * 2;} break; //16k
    case 4:
    { DAC_FS_RATIO_Q26 =  30828134;  coarse_ppm_scale = 478; dac_loop_out_scale = 6; DAC_REMAIN_NUM_TARGET = 159 * 2;} break; //22.05k
    case 5:
    { DAC_FS_RATIO_Q26 =  33554432;  coarse_ppm_scale = 438; dac_loop_out_scale = 4; DAC_REMAIN_NUM_TARGET = 162 * 2;} break; //24k
    case 6:
    { DAC_FS_RATIO_Q26 =  44739243;  coarse_ppm_scale = 328; dac_loop_out_scale = 4; DAC_REMAIN_NUM_TARGET = 174 * 2;} break; //32k
    case 7:
    { DAC_FS_RATIO_Q26 =  61656269;  coarse_ppm_scale = 238; dac_loop_out_scale = 3; DAC_REMAIN_NUM_TARGET = ASRC_RINGBUF_LEN_patch / 2;} break; //44.1k
    case 8:
    { DAC_FS_RATIO_Q26 =  67108864;  coarse_ppm_scale = 219; dac_loop_out_scale = 2; DAC_REMAIN_NUM_TARGET = ASRC_RINGBUF_LEN_patch / 2;} break; //48k
    default:
    { DAC_FS_RATIO_Q26 =  67108864;  coarse_ppm_scale = 128; dac_loop_out_scale = 2; DAC_REMAIN_NUM_TARGET = ASRC_RINGBUF_LEN_patch / 2 + 96;} break; //96k
    }
    dac_ringbuf_wp        =  DAC_REMAIN_NUM_TARGET;
    dac_ringbuf_right_wp  =  DAC_REMAIN_NUM_TARGET;

    fir_poly_pffast = (int32_t (*)[])new_fir_poly_pffast;
    fir_poly_96k_pffast = (int32_t (*)[])new_fir_poly_96k_pffast;
    DAC_MAG_COEFF_ARRAY = (int32_t (*)[])new_DAC_MAG_COEFF_ARRAY;
    pffast_dac_mag_init(USB_DAC_FS);
    // estimation_ppm_relock_init();
}

void estimation_ppm_relock_init(void)
{
    pasrc_dac_ftabl->estimation_ppm_relock_init();
}
extern void Patch_estimation_ppm_relock_init(void);


//int32_t flag_change;
int32_t remain_delta0;
int32_t coarse_unlock;
int32_t coarse_ppm_abs;

void estimate_coarse_ppm(void)
{
    pasrc_dac_ftabl->estimate_coarse_ppm();
}

//extern void Patch_estimate_coarse_ppm(void);
#if (ASRC_OBUF_LEN_patch == 16)
void new_Patch_estimate_coarse_ppm(void)
{
//(0)update ppm_scale

	if( start_coarse_ppm  || (USB_DAC_FS_D != USB_DAC_FS) )
	{
		start_coarse_ppm = 0;
		USB_DAC_FS_D = USB_DAC_FS;
	    estimation_ppm_init();

		if(USB_DAC_FS<=8)
		{
			apb_dac_filt_config_left_dac_fs96k_setf(0);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
		else
		{
			apb_dac_filt_config_left_dac_fs96k_setf(1);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
	}


   //ringbuf underflow or overflow detection and reset
    coarse_unlock = ( remain_num<= ASRC_OBUF_LEN_patch) || (remain_num >= ASRC_RINGBUF_LEN_patch -1 - 96);

    //(1) search locak min value
    int32_t  LOCAL_MIN_WINDOW = (9*ASRC_OBUF_LEN_patch/8);


	   if(coarse_cnt2 < LOCAL_MIN_WINDOW)
	   {
		   coarse_cnt2 += 1;
		   if(remain_min_search > remain_num)
			   remain_min_search = remain_num;
	   }
	   else
	   {
		   coarse_cnt2 = 0;
		   remain_num_min = remain_min_search;
		   remain_min_search = 888;
	   }

   int16_t ii;
 //(2) FSM
    switch(coarse_state)
    {
       case 0:
        {
           // clear the buffer
	       for(ii=0;ii<ASRC_RINGBUF_LEN_patch/2;ii++)
	       {
	          dac_ringbuf_left[ii] = 0;
	          dac_ringbuf_right[ii] = 0;
	       }

        	coarse_cnt = 0;
        	coarse_locked = 0;
        	coarse_state += 1;
        	//else
        	//	coarse_nxtstate = coarse_state;

        }break;

       case 1:         //record the remain_num_min0 in step0
       {
       	  // clear the buffer
         	  for(ii=ASRC_RINGBUF_LEN_patch/2;ii<ASRC_RINGBUF_LEN_patch;ii++)
           	  {
	           		  dac_ringbuf_left[ii] = 0;
	           		  dac_ringbuf_right[ii] = 0;
           	  }

         	 remain_num_min0 = remain_num;
         	 coarse_state += 1;
         	 coarse_cnt  = 0;

       }break;

       case 2:
       {
    	  remain_delta0 = remain_num - remain_num_min0;
    	  coarse_ppm     = 0;
    	  coarse_ppm_abs = 0;
		  coarse_locked = 0;

		  if(coarse_ppm_from_timer != 0)
		  {
			  coarse_locked = 1;
			  coarse_ppm = coarse_ppm_from_timer;
			  coarse_state  += 1 ;

		  }
		  else
		  {
    	  //wait until remain_num changed delta >= 64 or about 0.1seconds (for small ppm )
        	   if(remain_delta0 >= 64 || remain_delta0 <= -64 || coarse_cnt >= 100)
        	   {
        		   coarse_state += 1;
        		   if(coarse_cnt != 0)     //
        		   {
        			  coarse_ppm = (int32_t) (((int64_t)coarse_ppm_scale*65536)/coarse_cnt); // coarse ppm in 32Q10 format
        			  coarse_ppm = (coarse_ppm * remain_delta0); //
          		   }
        	   }
        	   else
        	   {
        	         coarse_cnt +=1;
        	   }
		  }

       }break;

       case 3:
       {
      	    coarse_state+=1;
        	//apb_dac_filt_config_left_volume_setf(0x1A);		//digital volume set 0
        	//apb_dac_filt_config_right_volume_setf(0x1A);

	    	if(coarse_ppm > DAC_MAX_PPM)
	    	  coarse_ppm = DAC_MAX_PPM ;
	    	else if(coarse_ppm < -DAC_MAX_PPM)
	    	  coarse_ppm = -DAC_MAX_PPM;

       }break;

       case 4:    // unlock detection
       {
    	   coarse_locked = 1;
    	   if(coarse_unlock)
    	   {
    		    coarse_state       = 0;
    		    coarse_locked      = 0;
    		    start_coarse_ppm   = 1;
    		    estimation_ppm_relock_init();

    	   }

       }break;
    }//end switch
 }
#else
void start_coarse_ppm_init(void)
{
	if( start_coarse_ppm  || (USB_DAC_FS_D != USB_DAC_FS) )
	{
		// DEBUG_GPIO4_SET();
		start_coarse_ppm = 0;
		USB_DAC_FS_D = USB_DAC_FS;
	    estimation_ppm_init();
	    estimation_ppm_relock_init();

		if(USB_DAC_FS<=8)
		{
			apb_dac_filt_config_left_dac_fs96k_setf(0);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
		else
		{
			apb_dac_filt_config_left_dac_fs96k_setf(1);
			apb_dac_filt_config_left_sync_bit_setf(1);
			apb_dac_filt_config_right_sync_bit_setf(1);
		}
		// DEBUG_GPIO4_CLR();
	}
}

void new_Patch_estimate_coarse_ppm(void)
{
   //ringbuf underflow or overflow detection and reset
    coarse_unlock = ( remain_num<= ASRC_OBUF_LEN_patch) || (remain_num >= ASRC_RINGBUF_LEN_patch -1 - 96);

    //(1) search locak min value
//     int32_t  LOCAL_MIN_WINDOW = (9*ASRC_OBUF_LEN_patch/8);
//	   if(coarse_cnt2 < LOCAL_MIN_WINDOW)
//	   {
//		   coarse_cnt2 += 1;
//		   if(remain_min_search > remain_num)
//			   remain_min_search = remain_num;
//	   }
//	   else
//	   {
//		   coarse_cnt2 = 0;
//		   remain_num_min = remain_min_search;
//		   remain_min_search = 888;
//	   }
   int16_t ii;
 //(2) FSM
    switch(coarse_state)
    {
       case 0:
       {
           // clear the buffer
        	for(ii=0;ii<ASRC_RINGBUF_LEN_patch;ii++)
	       {
	          dac_ringbuf_left[ii] = 0;
	          dac_ringbuf_right[ii] = 0;
	       }
        	coarse_cnt = 0;
        	coarse_locked = 1;
        	coarse_state = 4;
        	coarse_ppm  = 0;
       }break;
       case 1:         //record the remain_num_min0 in step0
       {
       }break;
       case 2:
       {
       }break;

       case 3:
       {
       }break;
       case 4:    // unlock detection
       {
    	   coarse_locked = 1;
    	   if(coarse_unlock)
    	   {
    		    coarse_locked      = 0;
    		    start_coarse_ppm   = 1;
    	   }

       }break;
    }//end switch
 }
#endif

//void estimate_fine_ppm(void)
//{
//    pasrc_dac_ftabl->estimate_fine_ppm();
//}
//
//extern void new_Patch_estimate_fine_ppm(void);
#define ERR_AVG_LEN  (16)
#define ERR_SHIFT    (4)
int16_t dpll_err_array[ERR_AVG_LEN];
int16_t dpll_err_array2[ERR_AVG_LEN];
//int32_t fine_ppm_array[4];

void new_Patch_estimate_fine_ppm(void)
{
    int32_t dpll_err, delta_u;

    //coarse_locked = 1;
#if (ASRC_OBUF_LEN_patch == 16)
    if (narrow_state < 1)
    {  dac_Ka = 40160;    dac_Kb = 40000;  DAC_MAX_PIDSTEP = 2000 << 10; }
    else if (narrow_state < 2)
    {  dac_Ka = 8080;     dac_Kb = 8000;  DAC_MAX_PIDSTEP = 2000 << 10;  }
    else
    {  dac_Ka = 602;     dac_Kb = 600;  DAC_MAX_PIDSTEP = 2000 << 10;  }
#else
	if (narrow_state < 1)
	{  dac_Ka = 40160;    dac_Kb = 40000;  DAC_MAX_PIDSTEP = 1000 << 10; }
	else if (narrow_state < 2)
	{  dac_Ka = 40160/8;  dac_Kb = 40000/8;  DAC_MAX_PIDSTEP = 200 << 10; }
#endif
    if ( (!coarse_locked) )
    {
        narrow_state    = 0;
        cnt_for_narrow  = 0;
        loopflt_out     = 0;
        fine_ppm        = coarse_ppm;
        coarse_ppm_hold = coarse_ppm;
        dpll_err_d1     = 0;
    }
    else
    {
        if (cnt_for_narrow < 2000)
        {
            narrow_state = 0;
            cnt_for_narrow += 1;
        }
        else if (cnt_for_narrow < 3000) //DAC_MAX_NARROWCNT
        {
            narrow_state = 1;
            cnt_for_narrow += 1;
        }
        else
        {
            narrow_state = 2;
        }

//        if (narrow_state > 0)
//            dpll_err    = remain_num_min - DAC_REMAIN_NUM_TARGET;
//        else
//            dpll_err    = remain_num - DAC_REMAIN_NUM_TARGET;



        int8_t ii;
		for(ii=ERR_AVG_LEN-1;ii>0;ii--)
		{
			dpll_err_array[ii] = dpll_err_array[ii-1];
		}

		dpll_err_array[0]  = remain_num - DAC_REMAIN_NUM_TARGET;
		if(__nds32__abs(dpll_err_array[0]) > 32)
		{
			__nds32__nop();
		}

		if (narrow_state < 2) //moving average
		{
			dpll_err = 0;
			for(ii=0;ii<ERR_AVG_LEN;ii++)
			{
				dpll_err += dpll_err_array[ii];
			}
		}
		else  //median filter
		{
			//========================================================================
				for(ii=0;ii<ERR_AVG_LEN;ii++)
				{
					dpll_err_array2[ii]=dpll_err_array[ii];
				}
				//=============== sort ==============
				int8_t jj;
				int16_t temp;
				for(ii=1;ii<ERR_AVG_LEN;ii++)
				{
					temp = dpll_err_array2[ii];
					jj = ii-1;
					while(jj>=0 && dpll_err_array2[jj]>temp)
					{
						dpll_err_array2[jj+1] = dpll_err_array2[jj];
						jj--;
					}
					dpll_err_array2[jj+1] = temp;
				}
				dpll_err = dpll_err_array2[ERR_AVG_LEN>>1];	//return the median value
		}

		// delta_u   = (para->dac_Ka*dpll_err_avg - para->dac_Kb * para->dpll_err_avg_d1)>>3;
        delta_u   = (dac_Ka * dpll_err - dac_Kb * dpll_err_d1);   //PI control
        dpll_err_d1 = dpll_err;


        loopflt_out = ((loopflt_out<<ERR_SHIFT)+delta_u)>>ERR_SHIFT;


        if ( loopflt_out > DAC_MAX_PPM   ) // ppm in Q10,
            loopflt_out = DAC_MAX_PPM ;
        else if (loopflt_out < -DAC_MAX_PPM  )
            loopflt_out = -DAC_MAX_PPM ;



       fine_ppm = (coarse_ppm_hold + loopflt_out * dac_loop_out_scale); //fine ppm in Q10
       // fine_ppm = 0;

#if 0
        for(ii=3;ii>0;ii--)
		{
        	fine_ppm_array[ii] = fine_ppm_array[ii-1];
		}
        fine_ppm_array[0]=(coarse_ppm_hold + loopflt_out * dac_loop_out_scale);

		fine_ppm = 0;
		for(ii=0;ii<4;ii++)
		{
			fine_ppm += fine_ppm_array[ii];
		}
		fine_ppm >>=2;
#endif

    }

}


#ifdef DATA_RECORD
int32_t remain_num_array[6000] = {0};
int32_t fine_ppm_array[6000] = {0};
int32_t arr = 0;
int32_t ppm_idx = 0;
#endif


void THD_compensate(int32_t *pOUT_dacbuf_left, int32_t *pOUT_dacbuf_right, uint16_t usLen)
{
    uint16_t ii;
    int64_t temp_int64;

#if (THD_COMPENSATE_DBG_CFG == ENABLE)
	uint32_t uSpareReg2 = apb_spare_reg2_get();

    THDCoeff.R_coeff3 = (uint8_t)uSpareReg2;
    uSpareReg2 >>= 8;
    THDCoeff.R_coeff2 = (uint8_t)uSpareReg2;
    uSpareReg2 >>= 8;
    THDCoeff.L_coeff3 = (uint8_t)uSpareReg2;
    uSpareReg2 >>= 8;
    THDCoeff.L_coeff2 = (uint8_t)uSpareReg2;
#else
    THDCoeff.R_coeff3 = pOtpInRam->thd_r_coeff3;
    THDCoeff.R_coeff2 = pOtpInRam->thd_r_coeff2;
    THDCoeff.L_coeff3 = pOtpInRam->thd_l_coeff3;
    THDCoeff.L_coeff2 = pOtpInRam->thd_l_coeff2;
#endif

    THDCoeff.L_coeff2 -= 128;
    THDCoeff.L_coeff3 -= 128;
    THDCoeff.R_coeff2 -= 128;
    THDCoeff.R_coeff3 -= 128;

    for (ii = 0; ii < usLen; ii++)
    {
        temp_int64 = (int64_t)pOUT_dacbuf_left[ii] * pOUT_dacbuf_left[ii];
        temp_int64 >>= 23;
        pOUT_dacbuf_left[ii] -= (int32_t)( (temp_int64 * THDCoeff.L_coeff2) >> 18);

        temp_int64 *= pOUT_dacbuf_left[ii];
        temp_int64 *= THDCoeff.L_coeff3;
        temp_int64 >>= (23 + 17); //
        pOUT_dacbuf_left[ii] -= (int32_t)temp_int64;


        temp_int64 = (int64_t)pOUT_dacbuf_right[ii] * pOUT_dacbuf_right[ii];
        temp_int64 >>= 23;
        pOUT_dacbuf_right[ii] -= (int32_t)( (temp_int64 * THDCoeff.R_coeff2) >> 18); //

        temp_int64 *= pOUT_dacbuf_right[ii];
        temp_int64 *= THDCoeff.R_coeff3;
        temp_int64 >>= (23 + 17); //
        pOUT_dacbuf_right[ii] -= (int32_t)temp_int64;
    }
}
#if (ASRC_OBUF_LEN_patch == 16)

void asrc_dac_top(
    int32_t *pUSB_dacbuf_left,
    int32_t *pUSB_dacbuf_right,
    int32_t *pOUT_dacbuf_left,
    int32_t *pOUT_dacbuf_right)
{
    pasrc_dac_ftabl->asrc_dac_top(pUSB_dacbuf_left, pUSB_dacbuf_right, pOUT_dacbuf_left, pOUT_dacbuf_right);
}

int32_t temp_data[96];
int temp_flag = 0;
void new_Patch_asrc_dac_top(        //driven by DAC Interrupt , ASRC_OBUF_LEN=8, 8 PCM samples per Interrupt
    //uint8_t *pUSBData, // USB data in Bytes
    int32_t *pUSB_dacbuf_left,
    int32_t *pUSB_dacbuf_right,

    int32_t *pOUT_dacbuf_left,
    int32_t *pOUT_dacbuf_right)
{
    int32_t  ii = 0;

    //(0.0) USB & DAC ON/OFF judge
    // when   USB_DAC_EOF_FLAG == 0 continuous 10 times, output to DAC '0'
    if ( USB_DAC_EOF_FLAG )
    {

        USB_DAC_EOF_FLAG = 0;
        usb_audio_out_off_cnt = 0;
        dac_interrupt_cnt = 0;
        if (USB_DAC_FS <= 8)
            usb_audio_out_off_cnt_thrsh = 6;  //3*2
        else
            usb_audio_out_off_cnt_thrsh = 12; //6*2

        if (usb_write_firstxx_packet < 32767)
            usb_write_firstxx_packet += 1;
    }
    else  // detect continuous DAC interrupt
    {
        if (dac_interrupt_cnt < 8)
        {
            dac_interrupt_cnt++;
        }
        if (usb_audio_out_off_cnt < 66) //avoid overflow
        {
            usb_audio_out_off_cnt ++ ;
        }
    }
    int32_t temp_num;
    // the  USB_EOF_FLAG is set to 1, in USB 1ms interrupt
    if ((dac_interrupt_cnt == 0) && (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8) )
    {
        if ( (USB_DAC_PCM_NUM == 48) || (USB_DAC_PCM_NUM == 96) )
        {

            if ( dac_ringbuf_wp + (USB_DAC_PCM_NUM >> 1) < ASRC_RINGBUF_LEN_patch - 1 )
            {
                for (ii = 0; ii < (USB_DAC_PCM_NUM >> 1); ii++) //write to ringbuf
                {
                    dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
                }
            }
            else
            {
                temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_wp;
                for (ii = 0; ii < temp_num; ii++) //write to ringbuf
                {
                    dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
                }

                dac_ringbuf_wp =  -1;
                for (; ii < (USB_DAC_PCM_NUM >> 1); ii++) //write to ringbuf
                {
                    dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
                }
            }

            if ( dac_ringbuf_right_wp + (USB_DAC_PCM_NUM >> 1) < ASRC_RINGBUF_LEN_patch - 1 )
            {
                for (ii = 0; ii < (USB_DAC_PCM_NUM >> 1); ii++) //write to ringbuf
                {
                    dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
                }
            }
            else
            {
                temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_right_wp;
                for (ii = 0; ii < temp_num; ii++) //write to ringbuf
                {
                    dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
                }

                dac_ringbuf_right_wp =  -1;
                for (; ii < (USB_DAC_PCM_NUM >> 1); ii++) //write to ringbuf
                {
                    dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
                }
            }
        }
    }

    if ((dac_interrupt_cnt == 1) && (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8) ) //after receive firstxx_packets from USB host
    {
// todo: DATA_RECORD only for debug, please undefine it
#ifdef DATA_RECORD
        if (arr < 6000)
            remain_num_array[arr++] = remain_num;
        else
        {
            arr = 0;
            __nds32__nop();
        }
#endif

        //(0) copy USB data to ringbuffer
        uint8_t u8temp_num = 0;
        uint8_t next_half_start;
        if ( (USB_DAC_PCM_NUM == 48) || (USB_DAC_PCM_NUM == 96) )
        {
            u8temp_num = USB_DAC_PCM_NUM / 2;
            next_half_start = USB_DAC_PCM_NUM / 2;
        }
        else
        {
            u8temp_num = USB_DAC_PCM_NUM;
            next_half_start = 0;
        }

        if ( dac_ringbuf_wp + u8temp_num < ASRC_RINGBUF_LEN_patch - 1 )
        {
            for (ii = 0; ii < u8temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[next_half_start + ii];  //USB data format 24bits ?
            }
        }
        else
        {
            temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_wp;
            for (ii = 0; ii < temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[next_half_start + ii];  //USB data format 24bits ?
            }

            dac_ringbuf_wp =  -1;
            for (; ii < u8temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[next_half_start + ii];  //USB data format 24bits ?
            }
        }

        if ( dac_ringbuf_right_wp + u8temp_num < ASRC_RINGBUF_LEN_patch - 1 )
        {
            for (ii = 0; ii < u8temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[next_half_start + ii];  //USB data format 24bits ?
            }
        }
        else
        {
            temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_right_wp;
            for (ii = 0; ii < temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[next_half_start + ii];  //USB data format 24bits ?
            }

            dac_ringbuf_right_wp =  -1;
            for (; ii < u8temp_num; ii++) //write to ringbuf
            {
                dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[next_half_start + ii];  //USB data format 24bits ?
            }
        }

        //(1) caculate remain_num when USB_EOF_FLAG
        if (dac_ringbuf_wp < dac_ringbuf_rp)
        {
            remain_num = ASRC_RINGBUF_LEN_patch  + dac_ringbuf_wp - dac_ringbuf_rp;
        }
        else
        {
            remain_num = dac_ringbuf_wp - dac_ringbuf_rp;
        }



        //(2) estimate coarse_ppm , estimate_fine_ppm and update dac_fs_ratio
        estimate_coarse_ppm(); //get coarse_ppm

        estimate_fine_ppm ();  //get fine_ppm

        //(3) update clock_ratio
        dac_fs_ratio = DAC_FS_RATIO_Q26 + (fine_ppm >> 4); //fine_ppm inQ10

#ifdef DATA_RECORD
        if (ppm_idx < 6000)
            fine_ppm_array[ppm_idx ++] = fine_ppm;
#endif
    }  //end if(USB_DAC_EOF_FLAG)

    //when USB SOF OFF duration for thrsh DAC interrupt period
    if ( (usb_audio_out_off_cnt > usb_audio_out_off_cnt_thrsh )&&(usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
    {
      	    int recover_pcm_num = (usb_audio_out_off_cnt_thrsh-6)*ASRC_OBUF_LEN;

      	    if (USB_DAC_FS <= 8 ) // Fs <= 48k
      	    {
      	    	recover_pcm_num = (usb_audio_out_off_cnt_thrsh-3)*ASRC_OBUF_LEN;
      	    }

            usb_write_firstxx_packet = 0;
            dac_interrupt_cnt = 0;

            dac_ringbuf_rp       -= recover_pcm_num;
            dac_ringbuf_right_rp -= recover_pcm_num;

            while(dac_ringbuf_rp <0)
            {
            	dac_ringbuf_rp += ASRC_RINGBUF_LEN_patch;
            }

            while(dac_ringbuf_right_rp <0)
            {
            	dac_ringbuf_right_rp += ASRC_RINGBUF_LEN_patch;
            }


        for (ii = 0; ii < ASRC_OBUF_LEN; ii++)
        {
            pOUT_dacbuf_right[ii] = 0;
            pOUT_dacbuf_left[ii]  = 0;
        }

    }

    //(4) read from ringbuf and do ASRC
    // all situation: USB_DAC_FS=0~9, ASRC_DAC_PFORMANCE 0~3
    if ( (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
    {
        if (USB_DAC_FS <= 8 ) // Fs <= 48k
        {
            new_asrc_codec_readbuf_fast(
                dac_ringbuf_left   , //data format 32Q23, 24bits Audio
                dac_ringbuf_right  , //data format 32Q23, 24bits Audio
                dac_xinbuf_left    , //data format 32Q19 for asrc filter
                dac_xinbuf_right   , //data format 32Q19 for asrc filter
                ASRC_RINGBUF_LEN_patch       ,
                asrc_xinbuf_len        , //xin buffer length, according to asrc performance level
                &dac_nco_buf_left      ,
                &dac_nco_buf_right     ,
                &dac_ringbuf_rp        ,
                &dac_ringbuf_right_rp  ,
                DAC_STEREO_MODE
            );
        }
        else    // Fs == 96k
        {
//			  int32_t bitcut_en ;
//			  bitcut_en =  (ASRC_DAC_PFORMANCE_96K <= 2); //0,1:pflow, 2:pfmid, 3:pfhigh

				  new_asrc_codec_readbuf_fast(
					  dac_ringbuf_left  , //32Q23, 24bits audio
					  dac_ringbuf_right , //32Q23, 24bits audio
					  dac_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
					  dac_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
					  ASRC_RINGBUF_LEN_patch      ,
					  asrc_xinbuf_len        , //xinbuffer length
					  &dac_nco_buf_left      ,
					  &dac_nco_buf_right     ,
					  &dac_ringbuf_rp        ,
					  &dac_ringbuf_right_rp  ,
					  //bitcut_en              ,  // bitcut = 0 :high performance, 1: mid or low performance
					  DAC_STEREO_MODE        );


        }
    }



	if ( (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
	{
		if(1 == asrc_return_flag )
		{
			new_asrc_filter_nco_nop(
					ASRC_OBUF_LEN			,
					&dac_nco_left           ,
					&dac_nco_buf_left       ,
					dac_fs_ratio             ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

			if (DAC_STEREO_MODE > 0)
			{
				new_asrc_filter_nco_nop(
						ASRC_OBUF_LEN		 ,
						&dac_nco_right       ,
						&dac_nco_buf_right   ,
						dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
		}
		else
		{
			  if (USB_DAC_FS <= 8 ) // Fs <= 48k
			  {

					asrc_codec48k_pffast(
						dac_xinbuf_left       ,  // ringbuffer, data format 32Q19 !!!
						//dac_xinbuf_right    ,  // ringbuffer, data format 32Q19 !!!
						pOUT_dacbuf_left          ,  // outbuffer,  data format 32Q23
						//pOUT_dacbuf_right       ,  // outbuffer,  data format 32Q23
						ASRC_OBUF_LEN            ,
						&dac_nco_left             ,
						&dac_nco_buf_left         ,
						dac_fs_ratio             ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

					if (DAC_STEREO_MODE > 0)
					{
						asrc_codec48k_pffast(
							//dac_xinbuf_left     ,  // ringbuffer, data format 32Q19 !!!
							dac_xinbuf_right      ,  // ringbuffer, data format 32Q19 !!!
							//pOUT_dacbuf_left        ,  // outbuffer,  data format 32Q23
							pOUT_dacbuf_right         ,  // outbuffer,  data format 32Q23
							ASRC_OBUF_LEN         ,
							&dac_nco_right         ,
							&dac_nco_buf_right     ,
							dac_fs_ratio          ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
					}

			 }
			  else//96k
			 {

					new_asrc_codec96k_pffast(
						dac_xinbuf_left   ,  //  data format 32Q20 !!!
						pOUT_dacbuf_left     ,  //  data format 32Q23, 24bits Audio
						ASRC_OBUF_LEN        ,
						&dac_nco_left        ,
						&dac_nco_buf_left    ,
						dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

					if (DAC_STEREO_MODE > 0)
					{
						new_asrc_codec96k_pffast(
							dac_xinbuf_right  ,  //  data format 32Q20 !!!
							pOUT_dacbuf_right    ,  //  data format 32Q23, 24bits Audio
							ASRC_OBUF_LEN        ,
							&dac_nco_right       ,
							&dac_nco_buf_right   ,
							dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
					}

		   }//end 96k
		}

		if(1 == asrc_return_flag)
		{
			return;
		}

        if (USB_DAC_FS == 7) //44.1k, mag compensation
        {
            nds32_bq_df1_q31(&mag_compen_left_inst,  pOUT_dacbuf_left, pOUT_dacbuf_left,  ASRC_OBUF_LEN);
            if (DAC_STEREO_MODE > 0)
            {
                nds32_bq_df1_q31(&mag_compen_right_inst, pOUT_dacbuf_right , pOUT_dacbuf_right ,  ASRC_OBUF_LEN);
            }
        }

        if (DAC_STEREO_MODE == 0) //when mono mode
        {
            for (ii = 0; ii < ASRC_OBUF_LEN; ii++)
            {
                pOUT_dacbuf_right[ii] =  pOUT_dacbuf_left[ii];
            }
        }
    }


    if ( usb_write_firstxx_packet < usb_write_firstxx_packet_thrsh/8 ) // output '0' for the firstxx_packet
    {

        for (ii = 0; ii < ASRC_OBUF_LEN; ii++)
        {
            pOUT_dacbuf_right[ii] = 0;
            pOUT_dacbuf_left[ii]  = 0;
        }
    }
//    else
//    {
//        for (ii = 0; ii < ASRC_OBUF_LEN; ii++)
//        {
//            pOUT_dacbuf_right[ii] += ( pOUT_dacbuf_right[ii] * right_mag_delta ) >> 7;
//            pOUT_dacbuf_left[ii]  += ( pOUT_dacbuf_left[ii] * left_mag_delta  ) >> 7;
//        }
//
//		THD_compensate(pOUT_dacbuf_left, pOUT_dacbuf_right, ASRC_OBUF_LEN);
//
//        //improve cross-talk peformance
//        if (USB_TYPEC_TO_3P5 == pOtpInRam->PMOD)
//        {
//            int32_t temp_left, temp_right;
//
//			for (ii = 0; ii < ASRC_OBUF_LEN; ii++)
//			{
//				temp_left =  pOUT_dacbuf_left[ii];
//				temp_right = pOUT_dacbuf_right[ii];
//
//				pOUT_dacbuf_left[ii]   = temp_left  + ((temp_right * Crosstalk_cmp_fact) >> 16);
//				pOUT_dacbuf_right[ii]  = temp_right + ((temp_left * Crosstalk_cmp_fact ) >> 16);
//
////				if(TRUE == u8UsbInSpeakerSts)			//USB In on, for DAC to ADC crosstalk
////				{
////					pOUT_dacbuf_right[ii] = -pOUT_dacbuf_right[ii];
////				}
//			}
//        }
//    }

}

#else
void asrc_write_ringbuf(
	    int32_t *pUSB_dacbuf_left,
	    int32_t *pUSB_dacbuf_right)
{
	int16_t temp_num, ii;

	//(1) write to ringbuf

		if (usb_write_firstxx_packet < 32767)
			usb_write_firstxx_packet += 1;
	    int16_t writeSpace = (dac_ringbuf_rp + ASRC_RINGBUF_LEN_patch - dac_ringbuf_wp - 8); //left headroom 8

	    if (writeSpace >=  ASRC_RINGBUF_LEN_patch ) {
	        writeSpace -= ASRC_RINGBUF_LEN_patch;
	    }

	    int16_t writeNum = USB_DAC_PCM_NUM;

	    if (writeNum > writeSpace) {
	        writeNum = writeSpace;
	    }


	if ( usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8 )
	{

		if ( dac_ringbuf_wp + (writeNum) < ASRC_RINGBUF_LEN_patch - 1 )
		{
			for (ii = 0; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
			}
		}
		else
		{
			temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_wp;
			for (ii = 0; ii < temp_num; ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
			}

			dac_ringbuf_wp =  -1;
			for (; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = pUSB_dacbuf_left[ii];  //USB data format 24bits ?
			}
		}

		if ( dac_ringbuf_right_wp + (writeNum) < ASRC_RINGBUF_LEN_patch - 1 )
		{
			for (ii = 0; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}
		}
		else
		{
			temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_right_wp;
			for (ii = 0; ii < temp_num; ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}

			dac_ringbuf_right_wp =  -1;
			for (; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = pUSB_dacbuf_right[ii];  //USB data format 24bits ?
			}
		}
	}
}

void asrc_padding_ringbuf(
	    int32_t dataLeft,
	    int32_t dataRight,
	    int16_t writeNum)
{
	int16_t temp_num, ii;
	if ( 1 )
	{

		if ( dac_ringbuf_wp + (writeNum) < ASRC_RINGBUF_LEN_patch - 1 )
		{
			for (ii = 0; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = dataLeft;  //padding the same data
			}
		}
		else
		{
			temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_wp;
			for (ii = 0; ii < temp_num; ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = dataLeft;  //
			}

			dac_ringbuf_wp =  -1;
			for (; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_left [++dac_ringbuf_wp]        = dataLeft;  //
			}
		}

		if ( dac_ringbuf_right_wp + (writeNum) < ASRC_RINGBUF_LEN_patch - 1 )
		{
			for (ii = 0; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = dataRight;
			}
		}
		else
		{
			temp_num = ASRC_RINGBUF_LEN_patch - 1 - dac_ringbuf_right_wp;
			for (ii = 0; ii < temp_num; ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = dataRight;
			}

			dac_ringbuf_right_wp =  -1;
			for (; ii < (writeNum); ii++) //write to ringbuf
			{
				dac_ringbuf_right [++dac_ringbuf_right_wp]        = dataRight;
			}
		}
	}
}

void asrc_dac_top(
    int32_t *pUSB_dacbuf_left,
    int32_t *pUSB_dacbuf_right,
    int32_t *pOUT_dacbuf_left,
    int32_t *pOUT_dacbuf_right)
{
    pasrc_dac_ftabl->asrc_dac_top(pUSB_dacbuf_left, pUSB_dacbuf_right, pOUT_dacbuf_left, pOUT_dacbuf_right);
}

//int32_t temp_data[96];
int temp_flag = 0;
void new_Patch_asrc_dac_top(        //driven by DAC Interrupt , ASRC_OBUF_LEN=8, 8 PCM samples per Interrupt
    //uint8_t *pUSBData, // USB data in Bytes
    int32_t *pUSB_dacbuf_left,
    int32_t *pUSB_dacbuf_right,

    int32_t *pOUT_dacbuf_left,
    int32_t *pOUT_dacbuf_right)
{
    int32_t  ii = 0;

    //(0.0) USB & DAC ON/OFF judge
    // when   USB_DAC_EOF_FLAG == 0 continuous 10 times, output to DAC '0'
    if ( USB_DAC_EOF_FLAG )
    {

        USB_DAC_EOF_FLAG = 0;
        usb_audio_out_off_cnt = 0;
//        dac_interrupt_cnt = 0;
        if (USB_DAC_FS <= 8)
            usb_audio_out_off_cnt_thrsh = 3;//3; //6
        else
            usb_audio_out_off_cnt_thrsh = 6;//6; //12

        if (dac_interrupt_cnt < 8)
        {
            dac_interrupt_cnt++;
        }
    }
    else  // detect continuous DAC interrupt
    {

        if (usb_audio_out_off_cnt < 66) //avoid overflow
        {
            usb_audio_out_off_cnt ++ ;
        }
    }
    // the  USB_EOF_FLAG is set to 1, in USB 1ms interrupt

    //start coarse ppm init

    start_coarse_ppm_init();

    if ((usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8) ) //after receive firstxx_packets from USB host
    {
// todo: DATA_RECORD only for debug, please undefine it
#ifdef DATA_RECORD
        if (arr < 6000)
            remain_num_array[arr++] = remain_num;
        else
        {
            arr = 0;
            __nds32__nop();
        }
#endif

        //(0) copy USB data to ringbuffer (move to USB Interrupt callback)

//        asrc_write_ringbuf(
//        	    pUSB_dacbuf_left,
//        	    pUSB_dacbuf_right);

        //(1) caculate remain_num when USB_EOF_FLAG
        if (dac_ringbuf_wp < dac_ringbuf_rp)
        {
            remain_num = ASRC_RINGBUF_LEN_patch  + dac_ringbuf_wp - dac_ringbuf_rp;
        }
        else
        {
            remain_num = dac_ringbuf_wp - dac_ringbuf_rp;
        }


        //(2) estimate coarse_ppm , estimate_fine_ppm and update dac_fs_ratio
        estimate_coarse_ppm(); //get coarse_ppm

        estimate_fine_ppm ();  //get fine_ppm

        //(3) update clock_ratio
        dac_fs_ratio = DAC_FS_RATIO_Q26 + (fine_ppm >> 4); //fine_ppm inQ10

#ifdef DATA_RECORD
        if (ppm_idx < 6000)
            fine_ppm_array[ppm_idx ++] = fine_ppm;
#endif
    }  //end if(USB_DAC_EOF_FLAG)

    //when USB SOF OFF duration for thrsh DAC interrupt period
    if ( (usb_audio_out_off_cnt > usb_audio_out_off_cnt_thrsh )&&(usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
    {
//      	    int recover_pcm_num = (usb_audio_out_off_cnt_thrsh-3)*ASRC_OBUF_LEN_patch;
//
//      	    if (USB_DAC_FS <= 8 ) // Fs <= 48k
//      	    {
//      	    	recover_pcm_num = (usb_audio_out_off_cnt_thrsh-1)*ASRC_OBUF_LEN_patch;
//      	    }

            usb_write_firstxx_packet = 0;
            dac_interrupt_cnt = 0;

//            dac_ringbuf_rp       -= recover_pcm_num;
//            dac_ringbuf_right_rp -= recover_pcm_num;

            dac_ringbuf_rp       = dac_ringbuf_wp - DAC_REMAIN_NUM_TARGET;
            dac_ringbuf_right_rp = dac_ringbuf_right_wp - DAC_REMAIN_NUM_TARGET;

            while(dac_ringbuf_rp <0)
            {
            	dac_ringbuf_rp += ASRC_RINGBUF_LEN_patch;
            }

            while(dac_ringbuf_right_rp <0)
            {
            	dac_ringbuf_right_rp += ASRC_RINGBUF_LEN_patch;
            }


        for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
        {
            pOUT_dacbuf_right[ii] = 0;
            pOUT_dacbuf_left[ii]  = 0;
        }

    }

    //(4) read from ringbuf and do ASRC
    // all situation: USB_DAC_FS=0~9, ASRC_DAC_PFORMANCE 0~3
    if ( (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
    {
    	if( remain_num <  asrc_xinbuf_len )
    	{
    		int16_t delta_num = (asrc_xinbuf_len  - remain_num);
    		int32_t dataLeft  = dac_ringbuf_left[dac_ringbuf_wp];
    		int32_t dataRight = dac_ringbuf_left[dac_ringbuf_right_wp];
//    		int32_t dataLeft  = (1<<23)-10;
//    		int32_t dataRight = (1<<23)-10;

    		asrc_padding_ringbuf(dataLeft,dataRight,delta_num);

    	}

        if (USB_DAC_FS <= 8 ) // Fs <= 48k
        {
            new_asrc_codec_readbuf_fast(
                dac_ringbuf_left   , //data format 32Q23, 24bits Audio
                dac_ringbuf_right  , //data format 32Q23, 24bits Audio
                dac_xinbuf_left    , //data format 32Q19 for asrc filter
                dac_xinbuf_right   , //data format 32Q19 for asrc filter
                ASRC_RINGBUF_LEN_patch       ,
                asrc_xinbuf_len        , //xin buffer length, according to asrc performance level
                &dac_nco_buf_left      ,
                &dac_nco_buf_right     ,
                &dac_ringbuf_rp        ,
                &dac_ringbuf_right_rp  ,
                DAC_STEREO_MODE
            );
        }
//        else    // Fs == 96k
//        {
////			  int32_t bitcut_en ;
////			  bitcut_en =  (ASRC_DAC_PFORMANCE_96K <= 2); //0,1:pflow, 2:pfmid, 3:pfhigh
//
//				  new_asrc_codec_readbuf_fast(
//					  dac_ringbuf_left  , //32Q23, 24bits audio
//					  dac_ringbuf_right , //32Q23, 24bits audio
//					  dac_xinbuf_left    , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
//					  dac_xinbuf_right   , //32Q23 (bitcut_en ==0),  or 32Q20(bitcut_en==1)
//					  ASRC_RINGBUF_LEN_patch      ,
//					  asrc_xinbuf_len        , //xinbuffer length
//					  &dac_nco_buf_left      ,
//					  &dac_nco_buf_right     ,
//					  &dac_ringbuf_rp        ,
//					  &dac_ringbuf_right_rp  ,
//					  //bitcut_en              ,  // bitcut = 0 :high performance, 1: mid or low performance
//					  DAC_STEREO_MODE        );
//
//
//        }
    }



	if ( (usb_write_firstxx_packet > usb_write_firstxx_packet_thrsh / 8))
	{
		if(1 == asrc_return_flag )
		{
			new_asrc_filter_nco_nop(
					ASRC_OBUF_LEN_patch			,
					&dac_nco_left           ,
					&dac_nco_buf_left       ,
					dac_fs_ratio             ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

			if (DAC_STEREO_MODE > 0)
			{
				new_asrc_filter_nco_nop(
						ASRC_OBUF_LEN_patch		 ,
						&dac_nco_right       ,
						&dac_nco_buf_right   ,
						dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
			}
		}
		else
		{
			  if (USB_DAC_FS <= 8 ) // Fs <= 48k
			  {

					asrc_codec48k_pffast(
						dac_xinbuf_left       ,  // ringbuffer, data format 32Q19 !!!
						//dac_xinbuf_right    ,  // ringbuffer, data format 32Q19 !!!
						pOUT_dacbuf_left          ,  // outbuffer,  data format 32Q23
						//pOUT_dacbuf_right       ,  // outbuffer,  data format 32Q23
						ASRC_OBUF_LEN_patch            ,
						&dac_nco_left             ,
						&dac_nco_buf_left         ,
						dac_fs_ratio             ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)

					if (DAC_STEREO_MODE > 0)
					{
						asrc_codec48k_pffast(
							//dac_xinbuf_left     ,  // ringbuffer, data format 32Q19 !!!
							dac_xinbuf_right      ,  // ringbuffer, data format 32Q19 !!!
							//pOUT_dacbuf_left        ,  // outbuffer,  data format 32Q23
							pOUT_dacbuf_right         ,  // outbuffer,  data format 32Q23
							ASRC_OBUF_LEN_patch         ,
							&dac_nco_right         ,
							&dac_nco_buf_right     ,
							dac_fs_ratio          ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
					}

			 }
//			  else//96k
//			 {
//
//					new_asrc_codec96k_pffast(
//						dac_xinbuf_left   ,  //  data format 32Q20 !!!
//						pOUT_dacbuf_left     ,  //  data format 32Q23, 24bits Audio
//						ASRC_OBUF_LEN_patch        ,
//						&dac_nco_left        ,
//						&dac_nco_buf_left    ,
//						dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//
//					if (DAC_STEREO_MODE > 0)
//					{
//						new_asrc_codec96k_pffast(
//							dac_xinbuf_right  ,  //  data format 32Q20 !!!
//							pOUT_dacbuf_right    ,  //  data format 32Q23, 24bits Audio
//							ASRC_OBUF_LEN_patch        ,
//							&dac_nco_right       ,
//							&dac_nco_buf_right   ,
//							dac_fs_ratio        ); //in 32Q21 format, clock_ratio = (Fsin/Fsout*32)
//					}
//
//		   }//end 96k
		}

		if(1 == asrc_return_flag)
		{
			return;
		}

//        if (USB_DAC_FS == 7) //44.1k, mag compensation
//        {
//            nds32_bq_df1_q31(&mag_compen_left_inst,  pOUT_dacbuf_left, pOUT_dacbuf_left,  ASRC_OBUF_LEN_patch);
//            if (DAC_STEREO_MODE > 0)
//            {
//                nds32_bq_df1_q31(&mag_compen_right_inst, pOUT_dacbuf_right , pOUT_dacbuf_right ,  ASRC_OBUF_LEN_patch);
//            }
//        }
//
//        if (DAC_STEREO_MODE == 0) //when mono mode
//        {
//            for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
//            {
//                pOUT_dacbuf_right[ii] =  pOUT_dacbuf_left[ii];
//            }
//        }
    }


    if ( usb_write_firstxx_packet <= usb_write_firstxx_packet_thrsh/8 ) // output '0' for the firstxx_packet
    {

        for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
        {
            pOUT_dacbuf_right[ii] = 0;
            pOUT_dacbuf_left[ii]  = 0;
        }
    }
//    else
//    {
//        for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
//        {
//            pOUT_dacbuf_right[ii] += ( pOUT_dacbuf_right[ii] * right_mag_delta ) >> 7;
//            pOUT_dacbuf_left[ii]  += ( pOUT_dacbuf_left[ii] * left_mag_delta  ) >> 7;
//        }
//
//	//	THD_compensate(pOUT_dacbuf_left, pOUT_dacbuf_right, ASRC_OBUF_LEN_patch);
//
////        //improve cross-talk peformance
////        if (USB_TYPEC_TO_3P5 == pOtpInRam->PMOD)
////        {
////            int32_t temp_left, temp_right;
////
////			for (ii = 0; ii < ASRC_OBUF_LEN_patch; ii++)
////			{
////				temp_left =  pOUT_dacbuf_left[ii];
////				temp_right = pOUT_dacbuf_right[ii];
////
////				pOUT_dacbuf_left[ii]   = temp_left  + ((temp_right * Crosstalk_cmp_fact) >> 16);
////				pOUT_dacbuf_right[ii]  = temp_right + ((temp_left * Crosstalk_cmp_fact ) >> 16);
////
//////				if(TRUE == u8UsbInSpeakerSts)			//USB In on, for DAC to ADC crosstalk
//////				{
//////					pOUT_dacbuf_right[ii] = -pOUT_dacbuf_right[ii];
//////				}
////			}
////        }
//    }

}
#endif
void asrc_Clean_RingBuf(void)
{
    pasrc_dac_ftabl->asrc_Clean_RingBuf();
}

extern void Patch_asrc_Clean_RingBuf(void);

const asrc_dac_ftable_t new_asrc_dac_patch_ftable =
{
    .Asrc_Dac_Fs_Ppm_Init = new_Patch_Asrc_Dac_Fs_Ppm_Init,
    .estimation_ppm_init = new_Patch_estimation_ppm_init,
    .estimate_coarse_ppm = new_Patch_estimate_coarse_ppm,
    .estimate_fine_ppm = new_Patch_estimate_fine_ppm,
    .asrc_dac_top = new_Patch_asrc_dac_top,
    .asrc_Clean_RingBuf = Patch_asrc_Clean_RingBuf,
    .estimation_ppm_relock_init = Patch_estimation_ppm_relock_init,
};

void new_asrc_dac_patch_init(void)
{
    pasrc_dac_ftabl = (asrc_dac_ftable_t *)&new_asrc_dac_patch_ftable;
}
