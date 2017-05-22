OUTPUT_ARCH( "riscv" )

SECTIONS
{
  . = 0x80000000;
  .text.init : { *(.text.init) }
  .tohost ALIGN(0x1000) : { *(.tohost) }
  .text ALIGN(0x1000) : { *(.text) }
  .data ALIGN(0x1000) : { *(.data) }
  .comment ALIGN(0x1000) : { *(.comment) }
  .bss : { *(.bss) }
  _end = .;
}

