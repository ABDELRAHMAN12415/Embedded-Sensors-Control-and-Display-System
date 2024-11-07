#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/defines.h"
#include "adc.h"


void ADC_Init(uint8_t adc_frq, uint8_t adc_ref)
{
	switch (adc_frq)
	{
	case 128: 
	ADCSRA = 0x87;   				   /* Enable ADC, with freq/128  */
		break;
		
	case 64: 
	ADCSRA = 0x86;   				   /* Enable ADC, with freq/64  */
		break;
		
	case 32: 
	ADCSRA = 0x85;   				   /* Enable ADC, with freq/32  */
	break;
	
	case 16: 
	ADCSRA = 0x84;   				   /* Enable ADC, with freq/16  */
	break;
	
	case 8: 
	ADCSRA = 0x83;   				   /* Enable ADC, with freq/8  */
	break;
	
	case 4: 
	ADCSRA = 0x82;   				   /* Enable ADC, with freq/4  */
	break;
	
	case 2: 
	ADCSRA = 0x80;   				   /* Enable ADC, with freq/2  */
	break;
	}

	ADMUX = (adc_ref << 6);   /* Vref: adc_ref */
}



uint16_t ADC_Read(uint8_t adc_pin)
{
	uint16_t result;
	ADMUX = 0x40 | (adc_pin & 0x07);   /* set input channel to read */
	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
	result = ADCL | (ADCH << 8);         /* Reaf ADC value */
	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
	return result;         /* Return ADC value */
}