OUTPUT_ARCH( "riscv" )
ENTRY(_start)
SECTIONS
{
  . = 0x80000000;
  .text.init : { *(.text.init) }
  .text ALIGN(0x1000) : { *(.text) }
  .data ALIGN(0x1000) : { *(.data) }
  .comment ALIGN(0x1000) : { *(.comment) }
  .bss : { *(.bss) }
  _end = .;
}

