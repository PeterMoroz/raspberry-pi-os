#include "utils.h"
#include "peripherals/pl011_uart.h"
#include "peripherals/gpio.h"

void uart_send ( char c )
{
	while(1) {
		if((get32(UART_FR)&0x20) == 0) 
			break;
	}
	put32(UART_DR,c);
}

char uart_recv ( void )
{
	while(1) {
		if((get32(UART_FR)&0x10) == 0)
			break;
	}
	return(get32(UART_DR)&0xFF);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
    put32(UART_CR,0);                      // turn off UART

	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt5 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

    /**  calculation PL011 baud rate settings:
        If the required baud rate is 115200 and UARTCLK=40MHz then:
        Baud Rate Divisor = (48*10^6)/(16*115200) = 26.041667
        This means BRDI = 26 and BRDF = 0.041667
        Therefore, fractional part = integer((0.041667*64)+0.5) = 3
    */

    put32(UART_ICR,0x7FF);                  // clear interrupts
    put32(UART_IBRD,26);                    // 115200 baud
    put32(UART_FBRD,3);
    put32(UART_LCRH,0x7<<4);                // 8n1, enable FIFOs
    put32(UART_CR,0x301);                   // enable Tx, Rx, UART
}
