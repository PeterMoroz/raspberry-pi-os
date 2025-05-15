/*
SECTIONS
{
	.text.boot : { *(.text.boot) }
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	. = ALIGN(0x8);
	bss_begin = .;
	.bss : { *(.bss*) } 
	bss_end = .;
}
*/

SECTIONS
{ 
  .text : { KEEP(*(.text.boot)) *(.text .text.* .gnu.linkonce.t*) }
  .rodata : { *(.rodata .rodata.* .gnu.linkonce.r*) }
  PROVIDE(_data = .);
  .data : { *(.data .data.* .gnu.linkonce.d*) }
  .bss (NOLOAD) : {
      . = ALIGN(16);
      bss_begin = .;
      *(.bss .bss.*)
      *(COMMON)
      bss_end = .;
   }
   _end = .;

   /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) }
}

