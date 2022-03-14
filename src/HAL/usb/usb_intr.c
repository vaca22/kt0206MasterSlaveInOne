/*****************Ipgoal Micro electronics(Sichan) Co., Ltd*********************
* File Name          : usb_intr.c
* Author             : wanggang
* Email				 : wanggang@ipgoal.com
* Version            : V1.0.0
* Date               : 03/8/2018
* Description        : 
********************************************************************************/

#include "usb_ch9.h"
#include "usb_cdc.h"
#include "reg_apb.h"
#include "standby_req.h"
#include "gpio_ctrl.h"
#include "reg_timer.h"
#include "hal_config.h"
#include "debug.h"

extern int16_t gwSecCnt;
extern stUSB_Audio_Dev stUsbAudio;
extern volatile uint8_t AuOutStartFlg;
uint8_t g_usb_bus_state = 0;

#ifdef APPLE_LIGHTING_USB_SUPPORT
extern void USB_BULK_InService(void);
extern void USB_BULK_OutService(void);
#endif
/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
typedef struct usb_intr_ftable_stru {
	void (*init)(void);
	void (*deinit)(void);
    void (*conect)(void);
    void (*disconect)(void);
    void (*intr)(void);
    void (*ep1_in)(void);
    void (*ep1_out)(void);
    void (*ep2_in)(void);
    void (*ep2_out)(void);
    void (*ep3)(void);
} usb_intr_ftable_t;

usb_intr_ftable_t *pusb_intr_ftabl = NULL;

void DeInit_SIE(void)
{
	return pusb_intr_ftabl->deinit();
}
extern void patch_DeInit_SIE(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void Hal_ConectUsb(void)
{
	return pusb_intr_ftabl->conect();
}
extern void patch_Hal_ConectUsb(void);

extern uint8_t standby_enable;
void new_patch_Hal_ConectUsb(void)
{
	if(standby_enable)
    {
		rSIE_POWER = B_SOFTCONN_NEW;
	}
	else
	{
		rSIE_POWER = B_SOFTCONN;
	}
}

void Hal_DisConectUsb(void)
{
	return pusb_intr_ftabl->disconect();
}
extern void patch_Hal_DisConectUsb(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
uint16_t bSIE_FRAMENUM;
uint16_t bSIE_FRAMENUM_buf;
uint8_t sof_count = 0;
int32_t coarse_ppm_from_timer = 0;
extern const uint16_t g_ClkAhbDivSel[4];
//coeficient apb_div_sel
extern const uint16_t g_ClkApbDivSel[4];
void Usb_INTR()
{
	return pusb_intr_ftabl->intr();
}
void new_patch_Usb_INTR()
{
	uint8_t bSIE_INTRUSB;
	uint8_t bSIE_INTRIN;
	uint8_t bSIE_INTROUT;


//	DEBUG_GPIO10_SET();
    bSIE_INTRUSB = rSIE_INTRUSB;
    bSIE_INTRIN  = rSIE_INTRIN;
    bSIE_INTROUT = rSIE_INTROUT;

#if(Deleate_Pop_standby == 0)
//     if((bSIE_INTRUSB & B_INT_SOF) != 0)	//SOF interrupt
//     {

//         if(sof_count == 0)
//         {
//        	//timer_start(tim_id_t eId, uint16_t usMs, timer_handler handler, tim_unit_t eUnit)
//         	timer_start(TIMER0, 30, NULL, TIM_MS); //30ms
//         }

//         if(sof_count == 20)
//         {
//         	uint32_t timer_val_0 = timer_load_count_get(TIMER0);
//         	uint32_t timer_val_1 = timer_curr_value_get(TIMER0);  //read timer value ,
//            	timer_end(TIMER0);        	//void timer_end(tim_id_t eId)

// 			timer_tick_init();

//         	//caculate freq error, first get the target value,
// 			uint16_t TmpDiv0, TmpDiv1,TmpDiv2;
// 			TmpDiv0 = apb_clk_gen_clksel_clk_osc_high_div_sel_getf();
// 			TmpDiv1 = apb_clk_gen_clksel_clk_ahb_div_sel_getf();
// 			TmpDiv2 = apb_clk_gen_clksel_clk_apb_div_sel_getf();
// 		   // timer_val_2  =  Get_APB_Clk()*20/1000; //786432, target value = Get_APB_Clk()*20ms
// 			//CoreClk = (OSC_HIGH_CLK * 10) / g_ClkOscHighDivSel[TmpDiv];
// 			////12.288M * 32 = 393.216M, in 20ms
// 		   int32_t timer_val_3 = (393216*10*20) /g_ClkOscHighDivSel[TmpDiv0]/g_ClkAhbDivSel[TmpDiv1] /g_ClkApbDivSel[TmpDiv2];

//            	//calculate ratio
//            	int64_t temp_int64 = (timer_val_0 - timer_val_1);
//            	temp_int64 = timer_val_3 - temp_int64;

//         	coarse_ppm_from_timer = (int32_t) ( (temp_int64<<30)/timer_val_3 ); // ppm  (1e6 == 2^20), in 32Q10
//          	//add protection
//         	if( (coarse_ppm_from_timer >  (20000<<10)) || (coarse_ppm_from_timer < -(20000<<10)) )  // +/-2% range
//         	{
//         		coarse_ppm_from_timer = 0;
//         	}

//         }

//       	if(sof_count < 21)
// 		{
// 			sof_count++;
// 		}
// #if (DAC_POWER_BREAK == 1)
//     	bSIE_FRAMENUM = (uint16_t)(rSIE_FRAMENUM_H & 0x07)*256 + rSIE_FRAMENUM_L;		//get rSIE_FRAMENUM

//     	if((1 == bSIE_FRAMENUM - bSIE_FRAMENUM_buf)
//     		||(0x07FF == bSIE_FRAMENUM_buf - bSIE_FRAMENUM))	//normal
//     	{
//     		;
//     	}
//     	else	//USB SOF losed, means USB port plug out
//     	{
//     		//Audio_DAC_fast_PowerOff();

// 			uint32_t uTmpValue;
// 			/* cg_driver_s1(spare_reg0<21>)=0 */
// 			uTmpValue = apb_spare_reg0_get();
// 			uTmpValue &= 0xFFDFFFFF;
// 			apb_spare_reg0_set(uTmpValue);
// 			/* cg_driver_s2(spare_reg0<20>)=0 */
// 			uTmpValue = apb_spare_reg0_get();
// 			uTmpValue &= 0xFFEFFFFF;
// 			apb_spare_reg0_set(uTmpValue);
// 			/* cg_driver_s3(spare_reg0<19:16>)=0 */
// 			uTmpValue = apb_spare_reg0_get();
// 			uTmpValue &= 0xFFF0FFFF;
// 			apb_spare_reg0_set(uTmpValue);
// 			/* cg_pdl=1 */
// 			apb_power_pd_ctrl1_cg_pdl_setf(1);
// 			/* cg_pdr=1 */
// 			apb_power_pd_ctrl1_cg_pdr_setf(1);
// 			/* Charge pump power down sequence */
// 			Charge_pump_PowerOff();
// 			/* DAC blocks is power down */
// 			apb_audio_pd_rst_audac_l_pd_setf(1);
// 			apb_audio_pd_rst_audac_r_pd_setf(1);
// 			apb_audio_pd_rst_audac_l_aui_2v_pd_setf(1);
// 			apb_audio_pd_rst_audac_r_aui_2v_pd_setf(1);


//     		AuOutStartFlg = 0;

//     	}
//  #endif
//     	bSIE_FRAMENUM_buf = bSIE_FRAMENUM;
//     }
#endif

	if((bSIE_INTRUSB & B_INT_RESET) != 0)
	{
		USB_BusReset();
		g_usb_bus_state |= B_INT_RESET;
		DBG_OUT_SYS("BusReset\n");
		GPIO_FuncSet( GPIO6, GPIO_DigOutput1 );
	}
	if((bSIE_INTRUSB & B_INT_RESUME) != 0)
	{
    	USB_BusResume();
		g_usb_bus_state |= B_INT_RESUME;
		DBG_OUT_SYS("BusResume\n");
		GPIO_FuncSet( GPIO6, GPIO_DigOutput1 );
	}
	if((bSIE_INTRIN & B_INT_EP0) != 0)
	{
		USB_EP0Service();
		bSIE_INTRIN &= ~B_INT_EP0;
		GPIO_FuncSet( GPIO6, GPIO_DigOutput1 );
	}
	//-------------------EP1-------------------------------
	if((bSIE_INTRIN & B_INT_EP1) != 0)//EP1 INTRRUPT IN
	{

		USB_EP1ServiceIN();
		bSIE_INTRIN &= ~B_INT_EP1;
	}
	if((bSIE_INTROUT & B_INT_EP1) != 0)//EP1 INTERRUPT OUT
	{

		USB_EP1ServiceOUT();
		bSIE_INTROUT &= ~B_INT_EP1;
	}
	
	//-------------------EP2-------------------------------	
	if((bSIE_INTRIN & B_INT_EP2) != 0)//EP2 INTRRUPT IN
	{
		USB_HIDSend();
		bSIE_INTRIN &= ~B_INT_EP2;
	}
	if((bSIE_INTROUT & B_INT_EP2) != 0)//EP2 INTERRUPT OUT
	{
		USB_EP2ServiceOUT();	
		bSIE_INTROUT &= ~B_INT_EP2;
	}
	
	//-------------------EP3-------------------------------
	if((bSIE_INTRIN & B_INT_EP3) != 0)//EP3 INTRRUPT IN
	{
		bSIE_INTRIN &= ~B_INT_EP3;
#ifdef APPLE_LIGHTING_USB_SUPPORT
		USB_BULK_InService();
#else
		Delay(0xffff);
		USB_CDCWrite();
#endif
	}

	if((bSIE_INTROUT & B_INT_EP3) != 0)
	{
		bSIE_INTROUT &= ~B_INT_EP3;
#ifdef APPLE_LIGHTING_USB_SUPPORT
		USB_BULK_OutService();
#else
		Delay(0xffff);
		USB_CDCService();
#endif
	}

	if((bSIE_INTRUSB & B_INT_SUSPEND) != 0)//SUSPEND
	{
		if(stUsbAudio.USBStatusFun!=NULL)
		{
			stUsbAudio.USBStatusFun();
		}
		USB_BusSuspend();
		g_usb_bus_state |= B_INT_SUSPEND;
		DBG_OUT_SYS("BusSuspend\n");
		GPIO_FuncSet( GPIO6, GPIO_DigOutput0 );
	}
//	DEBUG_GPIO10_CLR();
}


void Init_SIE(void)
{
	return pusb_intr_ftabl->init();
}
extern void patch_Init_SIE(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_EP1ServiceIN(void)
{
	return pusb_intr_ftabl->ep1_in();
}
extern void patch_USB_EP1ServiceIN(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_EP1ServiceOUT(void)
{
	return pusb_intr_ftabl->ep1_out();
}
extern void patch_USB_EP1ServiceOUT(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_EP2ServiceIN(void)
{
	return pusb_intr_ftabl->ep2_in();
}
extern void patch_USB_EP2ServiceIN(void);


/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_EP2ServiceOUT(void)
{
	return pusb_intr_ftabl->ep2_out();
}
extern void patch_USB_EP2ServiceOUT(void);

/*******************************************************************************
* Function Name  : 
* Description    : 
* Input          : 
* Output         : 
* Return         : 
*                  
*******************************************************************************/
void USB_EP3Service(void)
{
	return pusb_intr_ftabl->ep3();
}
extern void patch_USB_EP3Service(void);

extern void USB_ResumeHost(void);

extern void USB_SuspendmEn(void);

const usb_intr_ftable_t new_usb_intr_patch_ftable = {
    .init         = patch_Init_SIE,
    .deinit       = patch_DeInit_SIE,
    .conect       = new_patch_Hal_ConectUsb,
    .disconect    = patch_Hal_DisConectUsb,
    .intr         = new_patch_Usb_INTR,
    .ep1_in       = patch_USB_EP1ServiceIN,
    .ep1_out      = patch_USB_EP1ServiceOUT,
    .ep2_in       = patch_USB_EP2ServiceIN,
    .ep2_out      = patch_USB_EP2ServiceOUT,
    .ep3          = patch_USB_EP3Service,
};
void new_usb_intr_patch_init(void)
{
	pusb_intr_ftabl = (usb_intr_ftable_t *)&new_usb_intr_patch_ftable;
}
