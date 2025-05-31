#include "printf.h"
#include "utils.h"
#include "timer.h"
#include "irq.h"
#include "fork.h"
#include "sched.h"
#include "mini_uart.h"


struct process_data
{
    int num;
    char str[32];
};

#define NUM_CHILD_PROCESS 128 

struct process_data pdata[NUM_CHILD_PROCESS];

void process(char *arg)
{
    struct process_data* data = (struct process_data*)arg;
	while (1){
        printf("process n: %d, s: %s\r\n", data->num, data->str);
        delay(1000000);
	}
}

void kernel_main(void)
{
	uart_init();
	init_printf(0, putc);
	irq_vector_init();
	timer_init();
	enable_interrupt_controller();
	enable_irq();

    for (int i = 0; i < NUM_CHILD_PROCESS; i++) {
        pdata[i].num = i;
        sprintf(pdata[i].str, "process %d", i);
        int res = copy_process((unsigned long)&process, (unsigned long)&pdata[i]);
        if (res != 0) {
            printf("error when start process %d\r\n", i);
            return;
        }
    }

	while (1){
		schedule();
	}	
}
