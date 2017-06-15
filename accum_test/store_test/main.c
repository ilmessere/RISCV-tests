#include "rocc_accum.h"

int vect[] = {0xAA, 0xBB, 0xCC, 0xDD};
int rf[4];

void hang_core();
void check_rocc_reg(int*);
void reset_rocc_reg();

int main(){
	register int a1 __asm__("a1");
	register int a2 __asm__("a2");
	register int a3 __asm__("a3");
	register int a4 __asm__("a4");
	register int a5 __asm__("a5");
	register int a6 __asm__("a6");
	register int a7 __asm__("a7");
	register int sp __asm__("sp");

	int stack[4];
	int stack_dest[4];
	
	for(a1=0; a1 < 4; a1++){
		stack[a1] = vect[a1];
	}

	while(1){
		a1 = 1;
		a2 = 2;
		a3 = 3;
		
		ROCC_LOAD(&stack[0], __zero__); // load from stack
		ROCC_LOAD(&stack[1], a1); // load from stack
		ROCC_LOAD(&stack[2], a2); // load from stack
		ROCC_LOAD(&stack[3], a3); // load from stack

		check_rocc_reg(stack);	
		
		NOP5();

		reset_rocc_reg();

		ROCC_BURST_LOAD(stack);

		check_rocc_reg(stack);

		NOP5();
		
		ROCC_STORE(&stack_dest[0], __zero__);
		ROCC_STORE(&stack_dest[1], a1);
		ROCC_STORE(&stack_dest[2], a2);
		ROCC_STORE(&stack_dest[3], a3);
		
		check_rocc_reg(stack_dest);

		NOP5();

		ROCC_BURST_STORE(rf);
		
		check_rocc_reg(rf);

		NOP5();

		reset_rocc_reg();

		ROCC_BURST_LOAD(rf);

		check_rocc_reg(rf);

		NOP();
	}
}

void reset_rocc_reg(){
	int i;
	for(i=0; i<4; i++){
		ROCC_WRITE(__zero__, i);
	}
}

void check_rocc_reg(int *ptr){
	int i;
	int val;
	for(i=0; i<4; i++){
		ROCC_READ(val, i);
		if(val != ptr[i])
			hang_core();
	}
}

void hang_core(){
	while(1);
}
