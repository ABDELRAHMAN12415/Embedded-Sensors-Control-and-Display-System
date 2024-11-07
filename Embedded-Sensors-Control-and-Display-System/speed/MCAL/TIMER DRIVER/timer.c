#include "../../UTILITIES/types.h"
#include "../../UTILITIES/bit_manipulation.h"
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/defines.h"
#include "timer.h"



	/* defines the mode of the timer */

void SET_TIMER_MODE (uint8_t timer_num, uint8_t timer_mode){
	
	switch(timer_num)
	{
		case TIMER0:
			switch(timer_mode){
				case MODE_NORMAL:
					 CLEAR_BIT(TCCR0,WGM1);
					 CLEAR_BIT(TCCR0,WGM0);
				break;
				
				case MODE_CTC:
					 SET_BIT(TCCR0,WGM1);
					 CLEAR_BIT(TCCR0,WGM0);
				break;
			}
		break;
		
		case TIMER1:
		switch(timer_mode){
			case MODE_NORMAL:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);			
			break;
			
			case MODE_CTC:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		}
		break;
		
		case TIMER2:
			switch(timer_mode){
				case MODE_NORMAL:
					CLEAR_BIT(TCCR2,WGM1);
					CLEAR_BIT(TCCR2,WGM0);
				break;
				
				case MODE_CTC:
					SET_BIT(TCCR0,WGM1);
					CLEAR_BIT(TCCR0,WGM0);
				break;
			}		
		break;

	}
}
	
	/* puts the required value to the timer storage register according to the timer's mode */

void TIMER_VALUE (uint8_t timer_num, uint8_t initial_or_compare_value){
	
	switch (timer_num)
	{
	case TIMER0:
		if (READ_BIT(TCCR0,WGM1)==0)
		{
			TCNT0 = initial_or_compare_value;
		}
		else
		{
			OCR0 = initial_or_compare_value;
		}
	break;
	
	case TIMER1:
	
		TCNT1 = initial_or_compare_value;

	break;
	
	case TIMER2:
		if (READ_BIT(TCCR2,WGM1)==0)
		{
			TCNT2 = initial_or_compare_value;
		}
		else
		{
			OCR2 = initial_or_compare_value;
		}
	break;
	}	
}

	/* starts the timer with the required prescaler */

void TIMER_START (uint8_t timer_num, uint8_t timer_PS){
	
	switch (timer_num)
	{
		case TIMER0:
			switch (timer_PS)
			{
			case CLK1:
				SET_BIT(TCCR0,CS0);
				CLEAR_BIT(TCCR0,CS1);
				CLEAR_BIT(TCCR0,CS2);
			break;
			
			case CLK2:
				CLEAR_BIT(TCCR0,CS0);
				SET_BIT(TCCR0,CS1);
				CLEAR_BIT(TCCR0,CS2);
			break;
			
			case CLK3:
				SET_BIT(TCCR0,CS0);
				SET_BIT(TCCR0,CS1);
				CLEAR_BIT(TCCR0,CS2);
			break;
			
			case CLK4:
				CLEAR_BIT(TCCR0,CS0);
				CLEAR_BIT(TCCR0,CS1);
				SET_BIT(TCCR0,CS2);
			break;
			
			case CLK5:
  				SET_BIT(TCCR0,CS0);
  				CLEAR_BIT(TCCR0,CS1);
 				SET_BIT(TCCR0,CS2);
			break;
			
			case EX_FA:
				CLEAR_BIT(TCCR0,CS0);
				SET_BIT(TCCR0,CS1);
				SET_BIT(TCCR0,CS2);
			break;
			
			case EX_RI:
				SET_BIT(TCCR0,CS0);
				SET_BIT(TCCR0,CS1);
				SET_BIT(TCCR0,CS2);
			break;
			
			}

		break;
		
		case TIMER1:
		switch (timer_PS)
		{
			case CLK1:
			SET_BIT(TCCR1B,CS0);
			CLEAR_BIT(TCCR1B,CS1);
			CLEAR_BIT(TCCR1B,CS2);
			break;
	
			case CLK2:
			CLEAR_BIT(TCCR1B,CS0);
			SET_BIT(TCCR1B,CS1);
			CLEAR_BIT(TCCR1B,CS2);
			break;
	
			case CLK3:
			SET_BIT(TCCR1B,CS0);
			SET_BIT(TCCR1B,CS1);
			CLEAR_BIT(TCCR1B,CS2);
			break;
	
			case CLK4:
			CLEAR_BIT(TCCR1B,CS0);
			CLEAR_BIT(TCCR1B,CS1);
			SET_BIT(TCCR1B,CS2);
			break;
	
			case CLK5:
			SET_BIT(TCCR1B,CS0);
			CLEAR_BIT(TCCR1B,CS1);
			SET_BIT(TCCR1B,CS2);
			break;
	
			case EX_FA:
			CLEAR_BIT(TCCR1B,CS0);
			SET_BIT(TCCR1B,CS1);
			SET_BIT(TCCR1B,CS2);
			break;
	
			case EX_RI:
			SET_BIT(TCCR1B,CS0);
			SET_BIT(TCCR1B,CS1);
			SET_BIT(TCCR1B,CS2);
			break;
	
		}

break;
		
		case TIMER2:
			switch (timer_PS)
			{
				case CLK1:
				CLEAR_BIT(TCCR2,CS0);
				CLEAR_BIT(TCCR2,CS1);
				SET_BIT(TCCR2,CS2);
				break;
				
				case CLK2:
				CLEAR_BIT(TCCR2,CS0);
				SET_BIT(TCCR2,CS1);
				CLEAR_BIT(TCCR2,CS2);
				break;
				
				case CLK3:
				CLEAR_BIT(TCCR2,CS0);
				SET_BIT(TCCR2,CS1);
				SET_BIT(TCCR2,CS2);
				break;
				
				case CLK4:
				SET_BIT(TCCR2,CS0);
				CLEAR_BIT(TCCR2,CS1);
				CLEAR_BIT(TCCR2,CS2);
				break;
				
				case CLK5:
				SET_BIT(TCCR2,CS0);
				CLEAR_BIT(TCCR2,CS1);
				SET_BIT(TCCR2,CS2);
				break;
				
				case EX_FA:
				SET_BIT(TCCR2,CS0);
				SET_BIT(TCCR2,CS1);
				CLEAR_BIT(TCCR2,CS2);
				break;
				
				case EX_RI:
				SET_BIT(TCCR2,CS0);
				SET_BIT(TCCR2,CS1);
				SET_BIT(TCCR2,CS2);
				break;
			}
		break;
	}	
}

	/* stops the timer */

void TIMER_STOP (uint8_t timer_num){
	
	switch (timer_num)
	{
		case TIMER0:
			CLEAR_BIT(TCCR0,CS0);
			CLEAR_BIT(TCCR0,CS1);
			CLEAR_BIT(TCCR0,CS2);
		break;
		
		case TIMER1:
			CLEAR_BIT(TCCR1B,CS0);
			CLEAR_BIT(TCCR1B,CS1);
			CLEAR_BIT(TCCR1B,CS2);
		break;
		
		case TIMER2:
			CLEAR_BIT(TCCR2,CS0);
			CLEAR_BIT(TCCR2,CS1);
			CLEAR_BIT(TCCR2,CS2);
		break;
	}
	
}

	/* waits until the timer over flow flag sets then puts one to it */

void TIMER_ov_WAIT (uint8_t timer_num){
	
	/*while ((TIFR &(1<<0)) == 0);

	TIFR |= (1<<0);*/
	switch (timer_num)
	{
		case TIMER0:
		while ((TIFR &(1<<TOV0)) == 0);

		TIFR |= (1<<TOV0);
		break;
		
		case TIMER1:
		while ((TIFR &(1<<TOV1)) == 0);

		TIFR |= (1<<TOV1);
		break;
		
		case TIMER2:
		while ((TIFR &(1<<TOV2)) == 0);

		TIFR |= (1<<TOV2);
		break;
	}

}