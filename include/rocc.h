#ifndef __ROCC_H__
#define __ROCC_H__

#include "custom.h"

#define FUNCT_ROCC_READ		0
#define FUNCT_ROCC_WRITE	1
#define FUNCT_ROCC_LOAD		2
#define FUNCT_ROCC_STORE	3

#define ROCC_READ_REG(core_dest, reg_rocc_src) \
	CUSTOM0_RD(0, core_dest, reg_rocc_src, 0)

#define ROCC_READ_VAL(core_dest, val_rocc_reg)	\
	CUSTOM0_RD_RS1(0, core_dest, val_rocc_reg, 0)

#define ROCC_WRITE_REG(reg_rocc_dest, data)	\
	CUSTOM0_RS1(1, reg_rocc_dest, data, 0);

#define ROCC_WRITE_VAL(val_rocc_dest, data)	\
	CUSTOM0_RS1_RS2(1, 0, data, val_rocc_dest)

#define ROCC_LOAD_REG(reg_rocc_dest, mem_addr)	\
        CUSTOM0_RS1(2, reg_rocc_dest, mem_addr, 0)

#define ROCC_LOAD_VAL(val_rocc_dest, mem_addr) \
	CUSTOM0_RS1_RS2(2, 0, mem_addr, val_rocc_dest)  


#define ROCC_STORE_VAL(mem_addr, val_rocc_src)	\
	CUSTOM0_RS1_RS2(3, 0, mem_addr, val_rocc_src)

#define ROCC_STORE_REG(mem_addr, reg_rocc_src)	\
        CUSTOM0_RS1(3, 0, mem_addr, reg_rocc_src)

#define ROCC_BURST_LOAD()   \
        CUSTOM0(4, 0, 0, 0);

#define ROCC_BURST_STORE()  \
        CUSTOM0(5, 0, 0, 0);

#define ROCC_SET_BURST_ADDR_REG(mem_addr) \
        ROCC_WRITE_REG(31, mem_addr)

#define ROCC_SET_BURST_SIZE_REG(size) \
        ROCC_WRITE_REG(30, size)

#define ROCC_SET_BURST_PTR_REG(ptr) \
        ROCC_WRITE_REG(29, ptr)
#endif
