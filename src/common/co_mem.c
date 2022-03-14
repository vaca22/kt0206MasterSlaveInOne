#include "co_mem.h"

#define STACK_FILL_BYTE   ( 0xA5U )
#define STACK_GROWTH      ( -1 )

extern uint32_t __bss1_end;
volatile uint32_t g_uEndOfStackAddr = (uint32_t)(&__bss1_end);

void stack_fill(void)
{
    extern char _stack;
    memset( (void*)g_uEndOfStackAddr, STACK_FILL_BYTE, (uint32_t)&_stack - g_uEndOfStackAddr - 0x400);
}

uint32_t stack_free_space_get( const uint8_t * pucStackByte )
{
    uint32_t ulCount = 0U;

    while ( *pucStackByte == ( uint8_t ) STACK_FILL_BYTE )
    {
        pucStackByte -= STACK_GROWTH;
        ulCount++;
    }
    return ulCount;
}

uint32_t stack_high_water_mark_get(void)
{
    uint8_t *pucEndOfStack;
    uint32_t uReturn;

    pucEndOfStack = ( uint8_t * ) g_uEndOfStackAddr;
    uReturn = stack_free_space_get( pucEndOfStack );

    return uReturn;
}

