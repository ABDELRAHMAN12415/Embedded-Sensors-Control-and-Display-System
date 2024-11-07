/* #include "../../UTILITIES/registers.h"
#include "../../UTILITIES/defines.h"
#include "../../UTILITIES/bit_manipulation.h"

void AC_INIT(void){
	
	SET_BIT(SFIOR,ACME);	/* Enable AIN1 for -ve input (where ADEN is already 1)*/
	//ACSR |= (1<<ACIE) | (1<<ACIS1);		/* analog comparator interrupt enable, interrupt mode: falling edge */	
	
//}