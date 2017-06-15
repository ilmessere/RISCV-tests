#include "rocc.h"
#include "asm_util.h"

void init_mem(int *);
void reset_rocc_reg();
void write_rocc_reg(int*);
void load_rocc_reg_loop(int*);
void store_rocc_reg_loop(int*);
void check_rocc_reg(int*, unsigned, unsigned);
void rocc_burst_load(int*, unsigned, unsigned);
void rocc_burst_store(int*, unsigned, unsigned);
void rocc_prepare_burst(int*, unsigned, unsigned);

int vect[32];

int main(){
  register int a1 __asm__("a1");
  register int a2 __asm__("a2");
  register int a3 __asm__("a3");
  register int a4 __asm__("a4");
  register int a5 __asm__("a5");
  
  int i;

  int stack[32];

  init_mem(vect);

  NOP5();

  while(1){
   
    write_rocc_reg(vect);

    NOP5();

    check_rocc_reg(vect, 32, 0);
    
    NOP5(); 

    reset_rocc_reg();

    NOP5();
    
    load_rocc_reg_loop(vect);
   
    NOP5();
    
    check_rocc_reg(vect, 32, 0);

    NOP5();

    store_rocc_reg_loop(stack);

    NOP5();

    check_rocc_reg(stack, 32, 0);

    NOP5();

    reset_rocc_reg();

    NOP5();

    rocc_burst_load(vect, 10, 4);

    NOP5();

    check_rocc_reg(vect, 10, 4);

    NOP5();



  } 
}

void init_mem(int *vect){
  int i;
  for(i = 0; i < 32; i++)
    vect[i] = i;
}

void check_rocc_reg(int *vect, unsigned size, unsigned start_reg){
  unsigned i;
  int a;

  for(i= 0; i< size; i++){
    ROCC_READ_VAL(a, start_reg+i);
    if(a != vect[i])
      while(1);
  }
}

void write_rocc_reg(int *vect){
  int i;
  for(i=0; i<32; i++)
    ROCC_WRITE_VAL(i, vect[i]); // rs1 <- vect[i]
                                // rs2 <- i
                                // Rocc[rs2]  <- rs1
}
   
void load_rocc_reg_loop(int *vect){
  int i;
  for(i=0; i<32; i++)
      ROCC_LOAD_VAL(i, &vect[i]); // rs1 <- vect + i*4 
                                  // rs2 <- i
                                  // Rocc[rs2] <- Mem{rs1}
}   

void store_rocc_reg_loop(int *vect){
  int i;
  for(i=0; i<32; i++)
    ROCC_STORE_VAL(&vect[i], i);
}


void reset_rocc_reg(){
  int i;
  for(i=0; i<32; i++)
    ROCC_WRITE_VAL(i, __zero__);
}

void rocc_burst_store(int *vect, unsigned size, unsigned first_reg){
  ROCC_SET_BURST_ADDR_REG(vect);
  ROCC_SET_BURST_SIZE_REG(size);
  ROCC_SET_BURST_PTR_REG(first_reg);

  ROCC_BURST_STORE();
}

void rocc_burst_load(int *vect, unsigned size, unsigned first_reg){
  ROCC_SET_BURST_ADDR_REG(vect);
  ROCC_SET_BURST_SIZE_REG(size);
  ROCC_SET_BURST_PTR_REG(first_reg);

  ROCC_BURST_LOAD();
} 

void rocc_prepare_burst(int *vect, unsigned size, unsigned first_reg){
  ROCC_SET_BURST_ADDR_REG(vect);
  ROCC_SET_BURST_SIZE_REG(size);
  ROCC_SET_BURST_PTR_REG(first_reg);
}


