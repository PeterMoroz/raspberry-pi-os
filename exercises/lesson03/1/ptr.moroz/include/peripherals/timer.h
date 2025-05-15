#ifndef	_P_TIMER_H
#define	_P_TIMER_H

#include "peripherals/base.h"

#define SYSTEM_TIMER_CS        (PBASE+0x00003000)
#define SYSTEM_TIMER_CLO       (PBASE+0x00003004)
#define SYSTEM_TIMER_CHI       (PBASE+0x00003008)
#define SYSTEM_TIMER_C0        (PBASE+0x0000300C)
#define SYSTEM_TIMER_C1        (PBASE+0x00003010)
#define SYSTEM_TIMER_C2        (PBASE+0x00003014)
#define SYSTEM_TIMER_C3        (PBASE+0x00003018)

#define SYSTEM_TIMER_CS_M0	(1 << 0)
#define SYSTEM_TIMER_CS_M1	(1 << 1)
#define SYSTEM_TIMER_CS_M2	(1 << 2)
#define SYSTEM_TIMER_CS_M3	(1 << 3)


#define LOCAL_TIMER_CS              0x40000034
#define LOCAL_TIMER_CLR_RELOAD      0x40000038
#define LOCAL_TIMER_IRQ_ROUTING     0x40000024

#define LOCAL_TIMER_IRQ_ENABLE      0x20000000
#define LOCAL_TIMER_ENABLE          0x10000000

#define LOCAL_TIMER_IRQ_CLR         0x80000000
#define LOCAL_TIMER_RELOAD          0x40000000

#endif  /*_P_TIMER_H */
