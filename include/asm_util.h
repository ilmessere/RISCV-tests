#ifndef __ASM__UTIL_H__
#define __ASM__UTIL_H__


register unsigned __zero__ asm("zero");

#define NOP()	\
    asm volatile("nop")

#define NOP5() {  \
	NOP();	\
	NOP();	\
	NOP();	\
	NOP();	\
	NOP();	\
}

#define NOP10() { \
	NOP5(); 	\
	NOP5();		\
}

#endif
