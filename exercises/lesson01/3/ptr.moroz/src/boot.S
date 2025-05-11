#include "mm.h"

.section ".text.boot"

.globl _start
_start:
    bl get_core_id

    cmp x0, #0
    b.ne _core1
    mov sp, #STACK_CORE0
    b _main

_core1:
    cmp x0, #1
    b.ne _core2
    mov sp, #STACK_CORE1
    b _main

_core2:
    cmp x0, #2
    b.ne _core3
    mov sp, #STACK_CORE2
    b _main

_core3:
    cmp x0, #3
    b.ne _hang
    mov sp, #STACK_CORE3

_main:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero

	bl	kernel_main

_hang:
    b _hang
