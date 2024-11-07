
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/defines.h"
#include "dio.h"

/* initializing a full port in a one direction */

void DIO_PORT_INIT(uint8_t port_name, uint8_t direction){
	
	switch (port_name)
	{
	case PORT_A:
		if (direction == IN){
			DDRA = 0x00;
		}
		else if (direction == OUT){
			DDRA = 0xff;
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
	case PORT_B:
		if (direction == IN){
			DDRB = 0x00;
		}
		else if (direction == OUT){
			DDRB = 0xff;
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
	case PORT_C:
		if (direction == IN){
			DDRC = 0x00;
		}
		else if (direction == OUT){
			DDRC = 0xff;
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
	case PORT_D:
		if (direction == IN){
			DDRD = 0x00;
		}
		else if (direction == OUT){
			DDRD = 0xff;
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
	
	default :printf("ERROR INITIALIZING PORT %s",port_name);
	}
}

/* initializing a single pin of a port in as input or output */

void DIO_PIN_INIT(uint8_t pin_num, uint8_t port_name, uint8_t direction){
	
		switch (port_name)
		{
		case PORT_A:
		if (direction == IN){
			DDRA &= ~(1<<pin_num);
		}
		else if (direction == OUT){
			DDRA |= (1<<pin_num);
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
		case PORT_B:
		if (direction == IN){
			DDRB &= ~(1<<pin_num);
		}
		else if (direction == OUT){
			DDRB |= (1<<pin_num);
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
		case PORT_C:
		if (direction == IN){
			DDRC &= ~(1<<pin_num);
		}
		else if (direction == OUT){
			DDRC |= (1<<pin_num);
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
		case PORT_D:
		if (direction == IN){
			DDRD &= ~(1>>pin_num);
		}
		else if (direction == OUT){
			DDRD |= (1>>pin_num);
		}
		else printf("ERROR WRONG PORT DIRECTION ON PORT %s",port_name);
		break;
		
	default :printf("ERROR INITIALIZING PORT %s",port_name);
	}
}
	
	
	
	/* writes a high or low to an output port */
	

void DIO_PORT_WRITE(uint8_t port_name, uint8_t state){
	
	switch (port_name)
	{
		case PORT_A:
			PORTA = state;
		break;
		
		case PORT_B:
			PORTB = state;
		break;
		
		case PORT_C:
			PORTC = state;
		break;
		
		case PORT_D:
			PORTD = state;
		break;
	
	default :printf("ERROR WRITING ON PORT %s",port_name);
	}
}

	/* writes a high or low to an output pin */

void DIO_PIN_WRITE(uint8_t pin_num, uint8_t port_name, uint8_t state){
	
	switch (port_name)
	{
		case PORT_A:
		if (state == LOW){
			PORTA &= ~(1<<pin_num);
		}
		else if (state == HIGH){
			PORTA |= (1<<pin_num);
		}
		else printf("ERROR WRONG PIN VALUE ON PORT %s",port_name);
		break;
		
		case PORT_B:
		if (state == LOW){
			PORTB &= ~(1<<pin_num);
		}
		else if (state == HIGH){
			PORTB |= (1<<pin_num);
		}
		else printf("ERROR WRONG PIN VALUE ON PORT %s",port_name);
		break;
		
		case PORT_C:
		if (state == LOW){
			PORTC &= ~(1<<pin_num);
		}
		else if (state == HIGH){
			PORTC |= (1<<pin_num);
		}
		else printf("ERROR WRONG PIN VALUE ON PORT %s",port_name);
		break;
		
		case PORT_D:
		if (state == LOW){
			PORTD &= ~(1<<pin_num);
		}
		else if (state == HIGH){
			PORTD |= (1<<pin_num);
		}
		else printf("ERROR WRONG PIN VALUE ON PORT %s",port_name);
		break;
		
		default :printf("ERROR WRITING ON PORT %s",port_name);
	}
}
	
	
	/* reads the state of an input pin */
	
void DIO_PIN_READ(uint8_t pin_num, uint8_t port_name, uint8_t *state)	
{
	//uint8_t state;
	switch (port_name)
	{
		
		case PORT_A:	
			state =(PINA&(1<<pin_num))>>pin_num;
		break;
		
		case PORT_B:	
			state =(PINB&(1<<pin_num))>>pin_num;
		break;
		
		case PORT_C:	
			state =(PINC&(1<<pin_num))>>pin_num;
		break;
		
		case PORT_D:	
			state =(PIND&(1<<pin_num))>>pin_num;
		break;

	}
	return state;
}


	/* changes the state of an output pin */


void DIO_PIN_TOGGLE(uint8_t pin_num, uint8_t port_name){
	
	switch (port_name)
	{
		
		case PORT_A:
		PORTA ^= (1<<pin_num);
		break;
		
		case PORT_B:
		PORTB ^= (1<<pin_num);;
		break;
		
		case PORT_C:
		PORTC ^= (1<<pin_num);;
		break;
		
		case PORT_D:
		PORTD ^= (1<<pin_num);;
		break;

	}	
	
}
	
	
	
	
	
	
	

