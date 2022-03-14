#include <nds32_intrinsic.h>
#include "cache.h"
#include "cache_test.h"
#define BIT(x)  (1UL << (x))
PFM_type_e _ePFMtpye = PFM_TYPE_MAX;

void testcode(unsigned int size)
{
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 1)
		return;
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 2)
		return;
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 3)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 4)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 5)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 6)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 7)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 8)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 9)
		return;
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 10)
		return;
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 11)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 12)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 13)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 14)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 15)
	{
		return;
	}
	log_printf("The code for test1 The code for test1 The code for test1 The code for test1");
	log_printf("The code for test2 The code for test2 The code for test2 The code for test2");
	log_printf("The code for test3 The code for test3 The code for test3 The code for test3");
	log_printf("The code for test4 The code for test4 The code for test4 The code for test4");
	log_printf("The code for test5 The code for test5 The code for test5 The code for test5");
	log_printf("The code for test6 The code for test6 The code for test6 The code for test6");
	log_printf("The code for test7 The code for test7 The code for test7 The code for test7");
	log_printf("The code for test8 The code for test8 The code for test8 The code for test8");
	log_printf("The code for test9 The code for test9 The code for test9 The code for test9");
	log_printf("The code for test10 The code for test10 The code for test10 The code for test10");
	log_printf("The code for test11 The code for test11 The code for test11 The code for test11");
	log_printf("The code for test12 The code for test12 The code for test12 The code for test12");
	log_printf("The code for test13 The code for test13 The code for test13 The code for test13");
	if(size == 16)
	{
		return;
	}
}

return_e PFM_start(PFM_type_e ePFMtpye)
{
    unsigned int counter0 = 0, counter1 = 0, counter2 = 0;
    unsigned int ctrl = 0, msc_cfg = 0;
    return_e eRet = RETURN_OK;
	uart_puts("22!\n");
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
    if (!(msc_cfg & 0x4))
    {
    	uart_puts("This CPU config doesn't have pfm to use.\n");
        return RETURN_FAIL;
    }	uart_puts("22!\n");
    //Counter0
    __nds32__mtsr_dsb(counter0, NDS32_SR_PFMC0);
	uart_puts("22!\n");
    //Counter1
    __nds32__mtsr_dsb(counter1, NDS32_SR_PFMC1);
	uart_puts("22!\n");
    //Counter2
    __nds32__mtsr_dsb(counter2, NDS32_SR_PFMC2);
	uart_puts("33!\n");
    /* Enable performance counter0 , counter1, counter2 */
    ctrl |= BIT(0)| BIT(1)| BIT(2);
    /* Calculate Cycles for counter0 */
    ctrl |= (0UL << 15);
    switch(ePFMtpye)
    {
        case PFM_TYPE_HIT_RATE_I:	uart_puts("33!\n");
            /* Calculate ICache access for counter1 */
            ctrl |= (0x11 << 16);
            /* Calculate ICache miss  for counter2 */
            ctrl |= (0x11 << 22);
            break;
        case PFM_TYPE_HIT_RATE_D:	uart_puts("33!\n");
            /* Calculate DCache access for counter1 */
            ctrl |= (0x14 << 16);
            /* Calculate DCache miss for counter2 */
            ctrl |= (0x15 << 22);
            break;
        default:
        	uart_puts("[PFM]Invalid tpye  = %d", ePFMtpye);
            eRet = RETURN_INTPUT_INVALID;
            break;
    }	uart_puts("33!\n");
    _ePFMtpye = ePFMtpye;
    __nds32__mtsr(ctrl, NDS32_SR_PFM_CTL);
    return eRet;
}

return_e PFM_stop()
{
    unsigned int pfm_ctl, msc_cfg = 0;
    return_e eRet = RETURN_OK;
    char uart_str[80]={0};
    msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
    if (!(msc_cfg & 0x4))
    {
    	uart_puts("This CPU config doesn't have pfm to use.\n");
        return RETURN_FAIL;
    }

    pfm_ctl = __nds32__mfsr(NDS32_SR_PFM_CTL);
    //Disable all counters
    pfm_ctl = pfm_ctl & 0xFFFFFFF8;//pfm_ctl = Write4Byte(pfm_ctl,BIT(0)| BIT(1)| BIT(2),FALSE)
    __nds32__mtsr(pfm_ctl, NDS32_SR_PFM_CTL);

    unsigned int counter0 = __nds32__mfsr(NDS32_SR_PFMC0);
    unsigned int counter1 = __nds32__mfsr(NDS32_SR_PFMC1);
    unsigned int counter2 = __nds32__mfsr(NDS32_SR_PFMC2);
    switch(_ePFMtpye)
    {
        case PFM_TYPE_HIT_RATE_I:
            //Read cycles count for counter0
        	sprintf(uart_str,"The cycles for counter0 is = %d \n", counter0);
        	uart_puts(uart_str);
            //Read cycles count for counter0
        	sprintf(uart_str,"The hit rate for I-cache is = %d \n", (counter1*10000)/(counter1+counter2));
        	uart_puts(uart_str);
            //Read ICache access count for counter1
        	sprintf(uart_str,"The I-Cache access count for counter1 is = %d \n", counter1);
        	uart_puts(uart_str);
            //Read DCache access count for counter2
        	sprintf(uart_str,"The I-Cache miss count for counter2 is = %d \n", counter2);
        	uart_puts(uart_str);
            break;
        case PFM_TYPE_HIT_RATE_D:
            //Read cycles count for counter0
        	sprintf(uart_str,"The cycles for counter0 is = %d \n", counter0);
        	uart_puts(uart_str);
            //Read cycles count for counter0
        	sprintf(uart_str,"The hit rate for D-cache is = %d \n", (counter1*10000)/(counter1+counter2));
        	uart_puts(uart_str);
            //Read ICache access count for counter1
        	sprintf(uart_str,"The D-Cache access count for counter1 is = %d \n", counter1);
        	uart_puts(uart_str);
            //Read DCache access count for counter2
        	sprintf(uart_str,"The D-Cache miss count for counter2 is = %d \n", counter2);
        	uart_puts(uart_str);
            break;
        default:
        	uart_puts("[PFM]Invalid tpye  = %d", _ePFMtpye);
            eRet = RETURN_INTPUT_INVALID;
            break;
    }uart_puts("end");
    return eRet;
}
/*
int main(void) {

	//OTP_Operate();

    //switch clock

    //wait XTALOK

    //TODO - cache test
    PFM_start(PFM_TYPE_HIT_RATE_I);
    testcode(iCacheLineSize*iCacheSize*2);
    PFM_stop();
    PFM_start(PFM_TYPE_HIT_RATE_D);
    testcode(iCacheLineSize*iCacheSize*2);
    PFM_stop();
    cache_on();
    PFM_start(PFM_TYPE_HIT_RATE_I);
    testcode(iCacheLineSize*iCacheSize*2);
    PFM_stop();
    PFM_start(PFM_TYPE_HIT_RATE_D);
    testcode(iCacheLineSize*iCacheSize*2);
    PFM_stop();

}
*/
