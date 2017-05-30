#include "rocc_accum.h"

int vect[] = {0xAA, 0xBB, 0xCC, 0xDD};
int vect2[] = {0, 1, 2, 3};
int rf[4];
int data = 0xaaaa;

int main(){
	register int a1 __asm__("a1");
	register int a2 __asm__("a2");
	register int a3 __asm__("a3");
	register int a4 __asm__("a4");
	register int a5 __asm__("a5");
	register int a6 __asm__("a6");
	register int a7 __asm__("a7");
	register int sp __asm__("sp");

	int val1 = 0xABCD;
	int val2 = 0xEF;
	
	a1 = data;

	NOP5();
	
	ROCC_LOAD(&vect[0], __zero__);
	ROCC_LOAD(&vect[1], a1);

	NOP5();
	for(a1 = 0; a1 < 4; a1++){
		ROCC_LOAD(&vect[a1], a1);
	}
	NOP5();

	a1 = 1;
	a2 = 2;

	ROCC_WRITE(a1, __zero__);
	ROCC_LOAD(&val1, a1);
	
	a1 = 0;

			
}
