#include "rocc_accum.h"

int main(){
	register int a1 asm("a1");
	register int a2 asm("a2");
	register int a3 asm("a3");
	register int a4 asm("a4");
	register int a5 asm("a5");
	register int a6 asm("a6");

	a1 = 1;
	a2 = 2;
	a3 = 3;
	a5 = 0xAA;

	while(1){
		ROCC_WRITE(a5, a1);
		a5 = 0xBB;
		ROCC_WRITE(a5, a2);

		NOP5();
		
		ROCC_READ(a5, a1);
		NOP();
		ADD(a3, a1, a5);

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	//Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);
		
		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);

		NOP5();
		NOP5();

		ROCC_READ(a5, a1);
		NOP();
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a4, a1, a2);	//Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();
	
		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();


		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		ROCC_READ(a5, a1);
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		NOP();
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a4, a1, a2);	// Usefull independend instruction
		ADD(a3, a1, a5);	// Use the vaule read from RoCC

		NOP5();

	}
}
