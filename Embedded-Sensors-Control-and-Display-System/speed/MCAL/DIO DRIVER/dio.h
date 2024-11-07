#ifndef DIO_H_
#define DIO_H_


/*	    	DIO FUNCTIONS		 	*/

void DIO_PORT_INIT(uint8_t port_name, uint8_t direction);
void DIO_PIN_INIT(uint8_t pin_num, uint8_t port_name, uint8_t direction);

void DIO_PORT_WRITE(uint8_t port_name, uint8_t state);
void DIO_PIN_WRITE(uint8_t pin_num, uint8_t port_name, uint8_t state);

void DIO_PIN_READ(uint8_t pin_num, uint8_t port_name, uint8_t *state);

void DIO_PIN_TOGGLE(uint8_t pin_num, uint8_t port_name);



#endif 