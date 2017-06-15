#include "rocc.h"
#include "asm_util.h"


void check_rocc_reg(int *, int, int);

char msg1[17] = "aaaaaaaaaaaaaaaa";
int  vect[8] = {0, 0, 0, 0, 0, 0, 0, 0 };
char msg2[] = "bbbbbbbbbbbbbbbb";


int main(){
  int stack[8];
  int size = 4;
  int start_reg = 1;
  int *msg_ptr = (int*) (msg2);
  
  while(1){ 
    msg_ptr = (msg_ptr == (int*)msg1) ? (int*) msg2 : (int*) msg1;

    NOP5();

    ROCC_SET_BURST_ADDR_REG(msg_ptr);
    ROCC_SET_BURST_SIZE_REG(size);
    ROCC_SET_BURST_PTR_REG(start_reg);

    ROCC_BURST_LOAD();
    
    check_rocc_reg(msg_ptr, size, start_reg);

    NOP10();

    ROCC_SET_BURST_ADDR_REG(vect);
    ROCC_BURST_STORE();

    check_rocc_reg(vect, size, start_reg);

    NOP10();

    ROCC_SET_BURST_ADDR_REG(stack);
    ROCC_BURST_STORE();

    check_rocc_reg(stack, size, start_reg);

    NOP10();

  }
    
}

void check_rocc_reg(int *vect, int size, int ptr){
  int i, a;

  for( i = 0; i < size; i++){
    ROCC_READ_VAL(a, i+ptr);
    if( a != vect[i] ){
      NOP10();
      while(1);
    }
  }

}


