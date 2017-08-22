#ifndef __CUSTOM__
#define __CUSTOM__

#define str_expand(x) #x
#define xstr(x) str_expand(x)

/***************************************************************************************************************
 *                                             INLINE MACROS                                                   *
 **************************************************************************************************************/


#define CUSTOM0_RD_RS1_RS2(X,res, op1, op2)                 \
    asm volatile("custom0_RD_RS1_RS2_" #X " %0, %1, %2"	    \
		    : "=r"(res)                      	                  \
		    : "r"(op1), "r"(op2) )

#define CUSTOM0_RD_RS2(X,res, rs1, op2)                     \
    asm volatile("custom0_RD_RS2_" #X " %0, x"#rs1", %1"    \
        : "=r"(res)                                         \
        : "r"(op2) )

#define CUSTOM0_RD_RS1(X,res, op1, rs2)                     \
    asm volatile("custom0_RD_RS1_" #X " %0, %1, x"#rs2	    \
		    : "=r"(res)                                         \
		    : "r"(op1) )

#define CUSTOM0_RS1_RS2(X,rd, op1, op2)                     \
    asm volatile("custom0_RS1_RS2_" #X " x"#rd", %0, %1"    \
		    :                       	                          \
		    : "r"(op1), "r"(op2) )

#define CUSTOM0_RS2(X,rd, rs1, op2)                        \
    asm volatile("custom0_RS2_" #X " x"#rd", x"#rs1", %0"  \
		    : : "r"(op2) )

#define CUSTOM0_RS1(X,rd, op1, rs2)                        \
    asm volatile("custom0_RS1_" #X " x"#rd", %0, x"#rs2    \
		    : : "r"(op1) )

#define CUSTOM0_RD(X,res, rs1, rs2)                         \
    asm volatile("custom0_RD_" #X " %0, x"#rs1 ", x" #rs2   \
		    : "=r"(res)				                                  \
		    :)

#define CUSTOM0(X,rd, rs1, rs2)                             \
    asm volatile("custom0_" #X " x"#rd", x"#rs1", x"#rs2)   \




/***************************************************************************************************************
 *                                             INLINE FUNCTIONS                                                *
 **************************************************************************************************************/

volatile static inline unsigned custom0_rd_rs1_rs2(const unsigned x, unsigned res, unsigned op1, unsigned op2){
    asm volatile("custom0_RD_RS1_RS2_%c[funct] %[rd], %[rs1], %[rs2]"	    
		    :  [rd]"=r"(res)                     	                  
		    :  [rs1]"r"(op1), [rs2]"r"(op2), [funct]"i"(x));
    return res;
}

volatile static inline unsigned custom0_rd_rs2(const unsigned x, unsigned res, const unsigned rs1, unsigned op2){
    asm volatile("custom0_RD_RS2_%c[funct] %[rd], x%c[rs1], %[rs2]"	    
		    :  [rd]"=r"(res)                   	                  
		    :  [rs1]"i"(rs1), [rs2]"r"(op2), [funct]"i"(x));
    return res;
}

volatile static inline unsigned custom0_rd_rs1(const unsigned x, unsigned res, unsigned op1, const unsigned rs2){
    asm volatile("custom0_RD_RS1_%c[funct] %[rd], %[rs1], x%c[rs2]"	    
		    :  [rd]"=r"(res)                   	                  
		    :  [rs1]"r"(op1), [rs2]"i"(rs2), [funct]"i"(x));
    return res;
}

volatile static inline void custom0_rs1_rs2(const unsigned x, const unsigned rd, unsigned op1, unsigned op2){
    asm volatile("custom0_RS1_RS2_%c3 x%c0, %1, %2"	    
		    :                       	                  
		    : "i"(rd), "r"(op1), "r"(op2), "i"(x));
}

volatile static inline void custom0_rs2(const unsigned x, const unsigned rd, const unsigned rs1, unsigned op2){
    asm volatile("custom0_RS2_%c3 x%c0, x%c1, %2"	    
		    :                       	                  
		    : "i"(rd), "i"(rs1), "r"(op2), "i"(x));
}

volatile static inline void custom0_rs1(const unsigned x, const unsigned rd, unsigned op1, const unsigned rs2){
    asm volatile("custom0_RS1_%c3 x%c0, %1, x%c2"	    
		    :                       	                  
		    : "i"(rd), "r"(op1), "i"(rs2), "i"(x));
}

volatile static inline unsigned custom0_rd(const unsigned x, unsigned res, const unsigned rs1, const unsigned rs2){
    asm volatile("custom0_RD_%c[funct] %[rd], x%c[rs1], x%c[rs2]"	    
		    :  [rd]"=r"(res)                   	                  
		    :  [rs1]"i"(rs1), [rs2]"i"(rs2), [funct]"i"(x));
    return res;
}

//volatile static inline unsigned custom0_rd(const unsigned x, const unsigned rs1, const unsigned rs2){
//    volatile unsigned res;
//    asm volatile("custom0_RD_%c[funct] %[rd], x%c[rs1], x%c[rs2]"	    
//		    : [rd]"=r"(res)                      	                  
//		    : [rs1]"i"(rs1), [rs2]"i"(rs2), [funct]"i"(x));
//    return res;
//}
//volatile static inline void custom0_rd(const unsigned x, volatile unsigned *res, const unsigned rs1, const unsigned rs2){
//    asm volatile("custom0_RD_%c[funct] %[rd], x%c[rs1], x%c[rs2]"	    
//		    : [rd]"=r"(*res)                      	                  
//		    : [rs1]"i"(rs1), [rs2]"i"(rs2), [funct]"i"(x));
//}


volatile static inline void custom0(const unsigned x, const unsigned rd, const unsigned rs1, const unsigned rs2){
    asm volatile("custom0_%c3 x%c0, x%c1, x%c2"	    
		    :                       	                  
		    : "i"(rd), "i"(rs1), "i"(rs2), "i"(x));
}

#endif // __CUSTOM__
