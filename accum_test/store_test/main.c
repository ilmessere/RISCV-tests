#include "rocc_accum.h"

long long vect[] = {0xAA, 0xBB, 0xCC, 0xDD};
long long vect2[] = {0, 1, 2, 3};
long long rf[4];

int main(){
	register int a1 __asm__("a1");
	register int a2 __asm__("a2");
	register int a3 __asm__("a3");
	register int a4 __asm__("a4");
	register int a5 __asm__("a5");
	register int a6 __asm__("a6");
	register int a7 __asm__("a7");

	while(1){
		a1 = 1;
		a2 = 2;
		a3 = 3;
	
		a4 = (int)vect;
		a5 = (int)(&vect[1]);
		a6 = (int)(&vect[2]);
		a7 = (int)(&vect[3]);

		NOP5();
	
		ROCC_LOAD(a4, __zero__);
		ROCC_LOAD(a5, a1);
	        ROCC_LOAD(a6, a2);
		ROCC_LOAD(a7, a3);	
	
		NOP5();
		
		//a4 = (int)rf;
		//a5 = (int)(&rf[1]);
		//a6 = (int)(&rf[2]);
		//a7 = (int)(&rf[3]);
	
		//ROCC_STORE(a4, __zero__);
		//ROCC_STORE(a5, a1);
	        //ROCC_STORE(a6, a2);
		//ROCC_STORE(a7, a3);	
		//
		//NOP5();

		a4 = (int) vect2;	
		ROCC_BURST_LOAD(a4);

		NOP5();

		//a5 = (int) rf;
		//ROCC_BURST_STORE(a5);
	}
		
}
