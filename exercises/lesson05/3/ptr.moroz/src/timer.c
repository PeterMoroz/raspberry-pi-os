#include "utils.h"
#include "printf.h"
#include "sched.h"
#include "peripherals/timer.h"

const unsigned int interval = 200000;

void timer_init ( void )
{
    // enable timer, enable irq, reload value (repeat interval)
    put32(TIMER_CS,TIMER_ENABLE | TIMER_IRQ_ENABLE | interval);
    // routing irq to core 0
    put32(TIMER_IRQ_ROUTING, 0);
}

void handle_timer_irq( void )
{
    // clear interrupt flag and reload value
    put32(TIMER_CLR_RELOAD, TIMER_IRQ_CLR | TIMER_RELOAD);
    timer_tick();
}

