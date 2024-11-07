
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/bit_manipulation.h"
#include "../../UTILITIES/defines.h"
#include "interrubt.h"
#include "../TIMER DRIVER/timer.h"
#include "../DIO DRIVER/dio.h"

	/* sets pit 7 of the status register to enable the general interrupts */

void EN_GENERAL_INTERRUBTS(void){
	
	SREG |= (1<<7);
	
	
}


/* defines the sense that the external interrupts triggers at */


void EXT_INT_SENSE(uint8_t int_num, uint8_t sense){
	
	switch (int_num)
	{
	case INT0:
		switch (sense)
		{
		case FALLING_EDGE:
		SET_BIT(MCUCR,ISC01);
		CLEAR_BIT(MCUCR,ISC00);
		break;	
		
		case RISING_EDGE:
		SET_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);		
		break;
		}
	break;
	
	case INT1:
	switch (sense)
	{
		case FALLING_EDGE:
		SET_BIT(MCUCR,ISC11);
		CLEAR_BIT(MCUCR,ISC10);
		break;
		
		case RISING_EDGE:
		SET_BIT(MCUCR,ISC11);
		SET_BIT(MCUCR,ISC10);
		break;
	}
	break;	
	
	case INT2:
	switch (sense)
	{
		case FALLING_EDGE:
		CLEAR_BIT(MCUCSR,ISC2);
		break;
		
		case RISING_EDGE:
		SET_BIT(MCUCSR,ISC2);
		break;
	}
	break;	
	}	
}

	/* enables the external interrupts */

void EN_EXT_INT(uint8_t int_num){
	
	switch (int_num)
	{
	case INT0:
		SET_BIT(GICR, int_num);
		break;
		
	case INT1:
		SET_BIT(GICR, int_num);
		break;
		
	case INT2:
		SET_BIT(GICR, int_num);
		break;
	}
}

	/* disables the external interrupts */

void OFF_EXT_INT(uint8_t int_num){
	
	switch (int_num)
	{
		case INT0:
		CLEAR_BIT(GICR, int_num);
		break;
		
		case INT1:
		CLEAR_BIT(GICR, int_num);
		break;
		
		case INT2:
		CLEAR_BIT(GICR, int_num);
		break;
	}
}

	/* enables the timers interrupts according to the timer mode */
	
void EN_TIMER_INT(uint8_t timer_num){

	switch(timer_num){
		case TIMER0:
		if (READ_BIT(TCCR0,WGM1)==0)
		{
			SET_BIT(TIMSK,TOIE0);
		}
		else
		{
			SET_BIT(TIMSK,OCIE0);
		}
		break;
		
		case TIMER1:
			SET_BIT(TIMSK,TOIE1);
		break;
				
		case TIMER2:
		if (READ_BIT(TCCR2,WGM1)==0)
		{
			SET_BIT(TIMSK,TOIE2);
		}
		else
		{
			SET_BIT(TIMSK,OCIE2);
		}
		break;
	}
}
