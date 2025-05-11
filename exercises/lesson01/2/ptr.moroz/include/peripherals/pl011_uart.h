#ifndef	_P_PL011_UART_H
#define	_P_PL011_UART_H

#include "peripherals/base.h"

#define UART_DR         (PBASE+0x00201000)
#define UART_FR         (PBASE+0x00201018)
#define UART_IBRD       (PBASE+0x00201024)
#define UART_FBRD       (PBASE+0x00201028)
#define UART_LCRH       (PBASE+0x0020102C)
#define UART_CR         (PBASE+0x00201030)
#define UART_IMSC       (PBASE+0x00201038)
#define UART_ICR        (PBASE+0x00201044)

#endif  /*_P_PL011_UART_H */
