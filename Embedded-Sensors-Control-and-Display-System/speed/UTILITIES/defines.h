

#ifndef DEFINES_H_
#define DEFINES_H_


/*	    	DIO MACROS		 	*/

//PORTS MACROS
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//PINS MACROS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//DIRECTION MACROS
#define IN 0
#define OUT 1

//STATE MACROS
#define LOW 0
#define HIGH 1


/*	    	INTERRUBT MACROS		 	*/


//VECTOR MACROS
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3
#define TIMER2_CM __vector_4
#define TIMER2_OV __vector_5
#define TIMER1_OV __vector_9
#define TIMER0_CM __vector_10
#define TIMER0_OV __vector_11
#define ADC       __vector_17
#define ANA_COMP  __vector_19

//ISR MACRO
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//EXTERNAL INTERRUBTS MACROS
#define INT0  6
#define INT1  7
#define INT2  5


//EXTERNAL INTERRUBTS SENSE MACROS
#define RISING_EDGE  11
#define FALLING_EDGE 10


//EXTERNAL INTERRUBTS SENSE CONTROL MACROS
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3
#define ISC2   6


//TIMSK MACROS
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define TOIE2  6
#define OCIE2  7


/*	    	ADC MACROS		 	*/
#define AREF 0
#define AVCC 1
#define Reserved 2
#define IREF 3


// ADCSRA MACROS
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

// ADMUX MACROS
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

// ACSR MACROS
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7



/*	    	TIMER MACROS		 	*/

//TIMERn MACROS
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

//TIMER_MODE MACROS
#define MODE_NORMAL 0
#define MODE_CTC 1
#define MODE_FAST_PWM 2
#define MODE_PC_PWM 3

//CLK MACROS
#define CLK1  001  //clkI/O/(No prescaling)
#define CLK2  010  //clkI/O/8 (From prescaler)
#define CLK3  011  //clkI/O/64 (From prescaler)
#define CLK4  100  //clkI/O/256 (From prescaler)
#define CLK5  101  //clkI/O/1024 (From prescaler)
#define EX_FA 110  // External clock source on T0 pin. Clock on falling edge.
#define EX_RI 111  // External clock source on T0 pin. Clock on rising edge.

//timers 0,2 TCCR MACROS
#define CS0  0
#define CS1  1
#define CS2  2
#define WGM1 3
#define COM0 4
#define COM1 5
#define WGM0 6
#define FOC  7

//timer 1 TCCRA MACROS
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7
//timer 1 TCCRB MACROS
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

//TIFR MACROS
#define TOV0  0
#define OCF0  1
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2  7

#endif 