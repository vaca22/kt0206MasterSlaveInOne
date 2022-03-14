/*
 * mymath.h
 *
 *  Created on: Jul 4, 2019
 *      Author: guoax
 */

#ifndef MYMATH_H_
#define MYMATH_H_

#include "comm.h"
#ifndef BIT31
#define BIT31 (0x80000000)
#endif
#ifndef BIT0
#define BIT0  (0x00000001)
#endif
int32_t cordic_ln (int32_t x, uint8_t N);
int32_t cordic_exp(int32_t x, uint8_t N);
int cordic_expe(int x);
int cordic_loge(int x);
void ConvertQ16ToQ24(q15_t *pDataIn, int32_t *pDataOut, uint16_t Len);
#if 1
/*******************************************************************************
*
* ????: cvt24to16
* ????: 24-bits sample???16-bits code
* ????: int32_t datain:?????sample,????,-2^NF ~ 2^NF-1
* ???  : int16_t dataout
* ????:
* ????:
*          1 ????:2018/1/2
*            ????:guoax
*            ????:?????
*
*******************************************************************************/
#define NI 7
#define NF 31-NI
static inline int16_t cvt24to16(int32_t datain)
{
	uint32_t cnt;
	int16_t dataout;
	datain = __nds32__clips(datain,NF);
    datain = datain << NI;
    if(datain & BIT31)
    {
    	cnt = __nds32__clo((uint32_t)datain);
    }
    else
    {
    	cnt = __nds32__clz((uint32_t)datain);
    }
    datain = datain << (cnt>>1);
    dataout = (int16_t) (datain>>16);

    if(cnt & BIT0)
    {
    	dataout = dataout | BIT0;
    }
    else
    {
    	dataout = dataout & 0xFFFE;
    }
    return dataout;
}

/*******************************************************************************
*
* ????: cvt16to24
* ????: 16-bits code???24-bits sample
* ????: int16_t datain:?cvt24to16?????code
* ???  : int32_t dataout:?????24-bits sample
* ????:
* ????:
*          1 ????:2018/1/2
*            ????:guoax
*            ????:?????
*
*******************************************************************************/
static inline int32_t cvt16to24(int16_t datain)
{
	uint32_t cnt;
	int32_t dataout;
	int32_t temp;
	uint32_t ind;
	ind = __nds32__btst((uint32_t)datain,0);
	temp = (int32_t)datain << 16;
	temp = __nds32__bclr((uint32_t)temp,16);
    if(temp & BIT31)
    {
    	cnt = __nds32__clo((uint32_t)temp);
    }
    else
    {
    	cnt = __nds32__clz((uint32_t)temp);
    }
    cnt -= ind;
    dataout = temp >> (cnt + NI);

    return dataout;
}
#endif
#endif /* MYMATH_H_ */
