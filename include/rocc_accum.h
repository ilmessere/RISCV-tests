#include "custom.h"

#ifndef __ROCC_ACCUMULATOR__
#define __ROCC_ACCUMULATOR__

#define NORMAL_NOP 1

#define ROCC_WRITE(data, dest)	             \
    CUSTOM0_RS1_RS2(0, 0, data, dest)

#define ROCC_ACCUM(data, dest)   \
    CUSTOM0_RS1_RS2(3, 0, data, dest)

#define ROCC_READ(res, src)   \
    CUSTOM0_RD_RS1_RS2(1, res, __zero__, src)

#define ROCC_LOAD(addr, dest) \
    CUSTOM0_RS1_RS2(2, 0, addr, dest)

#define ROCC_STORE(addr, src)   \
    CUSTOM0_RS1_RS2(4, 0, addr, src)

#define ROCC_BURST_LOAD(addr)   \
    CUSTOM0_RS1(5, 0, addr, 0)

#define ROCC_BURST_STORE(addr)  \
    CUSTOM0_RS1(6, 0,addr, 0)


#if NORMAL_NOP == 1 
    #define NOP()	\
        asm volatile("nop\t\n")
#else
    #define NOP()	\
        asm volatile("bne zero, zero, main")
#endif


#define ADD(res, src1, src2)                 \
    asm volatile("add %0, %1, %2"            \
		    : "=r"(res)              \
		    : "r"(src1), "r"(src2))

#define NOP5(){		\
	NOP();		\
	NOP();		\
	NOP();		\
	NOP();		\
	NOP();		\
}


#endif // __ROCC_ACCUMULATOR__
