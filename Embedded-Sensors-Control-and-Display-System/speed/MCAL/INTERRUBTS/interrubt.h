
#ifndef INTERRUBT_H_
#define INTERRUBT_H_


/*	    	INTERRUBT PROTOTYPES		 	*/

//GLOPAL INTERRUBTS EN MACRO
void EN_GENERAL_INTERRUBTS(void);

//EXTERNAL INTERRUBTS INITIALIZATION
void EXT_INT_SENSE(uint8_t int_num, uint8_t sense);
void EN_EXT_INT(uint8_t int_num);
void OFF_EXT_INT(uint8_t int_num);

//TIMERS INTERRUBTS INITIALIZATION
void EN_TIMER_INT(uint8_t int_num);



#endif 