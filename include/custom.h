#ifndef __CUSTOM__
#define __CUSTOM__

#define CUSTOM0_RD_RS1_RS2(X,res, op1, op2)                \
    asm volatile("custom0_RD_RS1_RS2_" #X " %0, %1, %2"	   \
		    : "=r"(res)                      	   \
		    : "r"(op1), "r"(op2) )

#define CUSTOM0_RD_RS1(X,res, op1, rs2)                   \
    asm volatile("custom0_RD_RS1_" #X " %0, %1, x"#rs2	  \
		    : "=r"(res)                           \
		    : "r"(op1) )

#define CUSTOM0_RS1_RS2(X,rd, op1, op2)                    \
    asm volatile("custom0_RS1_RS2_" #X " x"#rd", %0, %1"    \
		    :                       	   \
		    : "r"(op1), "r"(op2) )

#define CUSTOM0_RS1(X,rd, op1, rs2)                        \
    asm volatile("custom0_RS1_" #X " x"#rd", %0, x"#rs2    \
		    : : "r"(op1) )

#define CUSTOM0_RD(X,res, rs1, rs2)  \
    asm volatile("custom0_RD_"#X " %0, x"#rs1 ", x" #rs2   \
		    : "=r"(res)				   \
		    :)

#define CUSTOM0(X,rd, rs1, rs2)                             \
    asm volatile("custom0_" #X " x"#rd", x"#rs1", x"#rs2)   \


register unsigned __zero__ asm("zero");

#endif // __CUSTOM__
