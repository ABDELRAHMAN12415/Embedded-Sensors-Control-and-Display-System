
#ifndef TIMER_H_
#define TIMER_H_

/*	    	TIMER PROTOTYPES		 	*/

void SET_TIMER_MODE (uint8_t timer_num, uint8_t timer_mode);
void TIMER_VALUE (uint8_t timer_num, uint8_t initial_or_compare_value);
void TIMER_START (uint8_t timer_num, uint8_t timer_PS);
void TIMER_ov_WAIT (uint8_t timer_num);
void TIMER_STOP (uint8_t timer_num);

#endif 