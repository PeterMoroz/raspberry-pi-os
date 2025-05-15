#include "utils.h"
#include "printf.h"
#include "timer.h"
#include "mini_uart.h"
#include "entry.h"
#include "peripherals/irq.h"

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1 | AUX_IRQ);
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

void handle_irq(void)
{
	unsigned int irq = get32(IRQ_PENDING_1);
	switch (irq) {
		case (SYSTEM_TIMER_IRQ_1):
			handle_timer_irq();
			break;
		case (AUX_IRQ):
			handle_uart_irq();
			break;
		default:
			printf("Unknown pending irq: %x\r\n", irq);
	}

/*
    unsigned int irq = get32(IRQ_BASIC_PENDING);
    // printf("basic pending irq: %x\r\n", irq);
    if (irq == PENDING1_IRQ) {
        irq = get32(IRQ_PENDING_1);
        // printf("pending1 irq: %x\r\n", irq);
        if (irq == SYSTEM_TIMER_IRQ_1) {
            handle_timer_irq();
            return;
        }

        printf("pending1 irq: %x\r\n", irq);

        if (irq == AUX_IRQ) {
            handle_uart_irq();
            return;
        }
        
        printf("pending1 irq: %x\r\n", irq);
    } else if (irq == PENDING2_IRQ) {
        irq = get32(IRQ_PENDING_2);
        //printf("pending2 irq: %x\r\n", irq);
    }

*/
/*
    if (irq == AUX_IRQ) {
        handle_uart_irq();
    }
*/
}
