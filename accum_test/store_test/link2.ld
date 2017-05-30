OUTPUT_ARCH( "riscv" )

SECTIONS
{
  . = 0x80000000;
  .text.init : { *(.text.init) }
  .tohost : { *(.tohost) }
  .text : { *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) }
  .comment : { *(.comment) }
  _end = .;
}


