#include "mini_uart.h"
#include "utils.h"

void kernel_main(void)
{
    unsigned long core = get_core_id();

    if (core == 0) {
    	uart_init();
    } else {
        delay(1000000 * core);
    }

    switch (core) {
        case 0:
            uart_send_string("Hello from CPU core #0\r\n");
            break;

        case 1:
            uart_send_string("Hello from CPU core #1\r\n");
            break;

        case 2:
            uart_send_string("Hello from CPU core #2\r\n");
            break;

        case 3:
            uart_send_string("Hello from CPU core #3\r\n");
            break;
    }

    if (core == 0) {
    	while (1) {
	    	uart_send(uart_recv());
    	}
    } else {
        while (1) {
            asm volatile("nop");
        }
    }
}
