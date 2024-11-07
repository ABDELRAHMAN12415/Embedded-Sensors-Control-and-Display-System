
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/*	    	STATUS REGISTER		 	*/

#define SREG    *((volatile uint8_t*)0x5F)


/*	    	DIO REGISTERS		 	*/

// PORT A REGISTERS
#define DDRA    *((volatile uint8_t*)0x3A)
#define PORTA   *((volatile uint8_t*)0x3B)
#define PINA    *((volatile uint8_t*)0x39)

// PORT B REGISTERS
#define DDRB    *((volatile uint8_t*)0x37)
#define PORTB   *((volatile uint8_t*)0x38)
#define PINB    *((volatile uint8_t*)0x36)

// PORT C REGISTERS
#define DDRC    *((volatile uint8_t*)0x34)
#define PORTC   *((volatile uint8_t*)0x35)
#define PINC    *((volatile uint8_t*)0x33)

// PORT D REGISTERS
#define DDRD    *((volatile uint8_t*)0x31)
#define PORTD   *((volatile uint8_t*)0x32)
#define PIND    *((volatile uint8_t*)0x30)



/*	    	TIMERS REGISTERS		 	*/

// TIMER 0 REGISTERS
#define TCCR0   *((volatile uint8_t*)0x53)
#define TCNT0   *((volatile uint8_t*)0x52)
#define OCR0    *((volatile uint8_t*)0x5C)

// TIMER 1 REGISTERS
#define TCCR1A  *((volatile uint8_t*)0x2F)
#define TCCR1B  *((volatile uint8_t*)0x2E)
#define TCNT1   *((volatile uint8_t*)0x2C)


// TIMER 2 REGISTERS
#define TCCR2   *((volatile uint8_t*)0x45)
#define TCNT2   *((volatile uint8_t*)0x44)
#define OCR2    *((volatile uint8_t*)0x43)



/*	    	INTERRUPTS REGISTERS		 	*/

//EXTERNAL INTERRUPTS ENABLE REGISTERS
#define GICR    *((volatile uint8_t*)0x5B)

// EXTERNAL INTERRUPTS SENCE CONTROL REGISTER
#define MCUCR   *((volatile uint8_t*)0x55)
#define MCUCSR  *((volatile uint8_t*)0x54)

// EXTERNAL INTERRUPTS FLAGS REGISTER
#define GIFR    *((volatile uint8_t*)0x5A)

// TIMERS INTERRUPTS ENABLE REGISTER
#define TIMSK   *((volatile uint8_t*)0x59)

// TIMERS INTERRUPT FLAGS REGISTER
#define TIFR    *((volatile uint8_t*)0x58)


/*	    	ADC REGISTERS		 	*/

#define ADMUX   *((volatile uint8_t*)0x07)

#define ADCSRA  *((volatile uint8_t*)0x06)

#define ADCW    *((volatile uint8_t*)0x04)

#define ADCL    *((volatile uint8_t*)0x04)
#define ADCH    *((volatile uint8_t*)0x05)

#define ACSR    *((volatile uint8_t*)0x08)

#define SFIOR   *((volatile uint8_t*)0x30)

#endif