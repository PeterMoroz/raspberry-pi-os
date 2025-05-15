#include "utils.h"
#include "printf.h"
#include "peripherals/timer.h"

const unsigned int interval = 200000;
unsigned int system_timer_val = 0;

void system_timer_init ( void )
{
	system_timer_val = get32(SYSTEM_TIMER_CLO);
	system_timer_val += interval;
	put32(SYSTEM_TIMER_C1, system_timer_val);
}

void handle_system_timer_irq( void ) 
{
	system_timer_val += interval;
	put32(SYSTEM_TIMER_C1, system_timer_val);
	put32(SYSTEM_TIMER_CS, SYSTEM_TIMER_CS_M1);
	printf("system timer interrupt received\n\r");
}

void local_timer_init ( void )
{
    // enable timer, enable irq, reload value
    put32(LOCAL_TIMER_CS, 
        LOCAL_TIMER_ENABLE | LOCAL_TIMER_IRQ_ENABLE | 25000000);
    // routing irq to core 0
    put32(LOCAL_TIMER_IRQ_ROUTING, 0);
}

void handle_local_timer_irq( void ) 
{
    // clear interrupt flag and reload value
    put32(LOCAL_TIMER_CLR_RELOAD, LOCAL_TIMER_IRQ_CLR | LOCAL_TIMER_RELOAD);
	printf("local timer interrupt received\n\r");
}
