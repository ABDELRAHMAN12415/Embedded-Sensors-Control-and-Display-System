
#ifndef ADC_H_
#define ADC_H_

void ADC_Init(uint8_t adc_frq, uint8_t adc_ref);

uint16_t ADC_Read(uint8_t adc_pin);

#endif