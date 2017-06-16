#ifndef __ROCC_H__
#define __ROCC_H__

#include "custom.h"

#define FUNCT_ROCC_READ		      (unsigned)(0)
#define FUNCT_ROCC_WRITE	      (unsigned)(1)
#define FUNCT_ROCC_LOAD		      (unsigned)(2)
#define FUNCT_ROCC_STORE	      (unsigned)(3)
#define FUNCT_ROCC_BURST_LOAD   (unsigned)(4)
#define FUNCT_ROCC_BURST_STORE  (unsigned)(5)
#define FUNCT_ROCC_COMPUTE      (unsigned)(6)

#define ROCC_BURST_ADDR_REG     (unsigned)(31)
#define ROCC_BURST_SIZE_REG     (unsigned)(30)
#define ROCC_BURST_PTR_REG      (unsigned)(29)


#define ROCC_BLOCKCIPHER_CFG_REG      (unsigned)(28)


#define ROCC_READ_REG(core_dest, reg_rocc_src) \
	core_dest = custom0_rd(FUNCT_ROCC_READ, core_dest, reg_rocc_src, 0) 

#define ROCC_READ_VAL(core_dest, val_rocc_reg)	\
	core_dest = custom0_rd_rs1(FUNCT_ROCC_READ, core_dest, val_rocc_reg, 0) 

#define ROCC_WRITE_REG(reg_rocc_dest, data)	\
	custom0_rs1(FUNCT_ROCC_WRITE, reg_rocc_dest, data, 0);

#define ROCC_WRITE_VAL(val_rocc_dest, data)	\
	custom0_rs1_rs2(FUNCT_ROCC_WRITE, 0, data, val_rocc_dest)

#define ROCC_LOAD_REG(reg_rocc_dest, mem_addr)	\
  custom0_rs1(FUNCT_ROCC_LOAD, reg_rocc_dest, mem_addr, 0) 

#define ROCC_LOAD_VAL(val_rocc_dest, mem_addr) \
	custom0_rs1_rs2(FUNCT_ROCC_LOAD, 0, mem_addr, val_rocc_dest)  

#define ROCC_STORE_VAL(mem_addr, val_rocc_src)	\
	custom0_rs1_rs2(FUNCT_ROCC_STORE, 0, mem_addr, val_rocc_src) 

#define ROCC_STORE_REG(mem_addr, reg_rocc_src)	\
  custom0_rs1(FUNCT_ROCC_STORE, 0, mem_addr, reg_rocc_src)

#define ROCC_BURST_LOAD()   \
  custom0(FUNCT_ROCC_BURST_LOAD, 0, 0, 0);

#define ROCC_BURST_STORE()  \
  custom0(FUNCT_ROCC_BURST_STORE, 0, 0, 0);


#define ROCC_BURST_LOAD_RES(res)   \
  res = custom0_rd(FUNCT_ROCC_BURST_LOAD, res, 0, 0);

#define ROCC_BURST_STORE_RES(res)  \
  res = custom0_rd(FUNCT_ROCC_BURST_STORE, res, 0, 0);

#define ROCC_SET_BURST_ADDR_REG(mem_addr) \
  ROCC_WRITE_REG(ROCC_BURST_ADDR_REG, mem_addr)

#define ROCC_SET_BURST_SIZE_REG(size) \
  ROCC_WRITE_REG(ROCC_BURST_SIZE_REG, size)

#define ROCC_SET_BURST_PTR_REG(ptr) \
  ROCC_WRITE_REG(ROCC_BURST_PTR_REG, ptr)

#define ROCC_SET_BLOCKCIPHER_CFG(cfg) \
  ROCC_WRITE_REG(ROCC_BLOCKCIPHER_CFG_REG, cfg)


#define ROCC_COMPUTE() \
  custom0(FUNCT_ROCC_COMPUTE, 0,0,0)

 


#endif
