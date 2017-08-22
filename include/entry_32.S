#define STACK_POINTER_BASE 0x81000000
#define MSTATUS_XS_MASK    ((1<<15)|(1<<16))

  .section ".text.init", "ax",@progbits
  .globl _start
_start:
  // write dirty state on the XS bits of the 'mstatus' CSR
  // to enable the use of coprocessors
  li sp, MSTATUS_XS_MASK
  csrs mstatus, sp  
  //prepare stack pointer
  li sp, STACK_POINTER_BASE
  j main
