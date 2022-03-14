#include "debug.h"
#include "reg_uart.h"

/***********************************************
 *用于串口调试，在 debug.h里面通过
 宏定义UART_DEBUG来关打开串口调试
 #define UART_DEBUG  //打开UART调试
 或者注销宏定义UART_DEBUG来关闭串口调试
//#define UART_DEBUG //关闭UART调试
************************************************/


#ifdef UART_DEBUG

char uartDebugBuffer[64];
void UartPrintf(char* pBuffer)
{
    while(*pBuffer!=0)
    {
        while(g_uart.tx.full_flag)
        {
            ;
        }
        uart_putchar(*pBuffer);
        pBuffer++;
    }
    uart_etbei_setf(1);
}

#endif
