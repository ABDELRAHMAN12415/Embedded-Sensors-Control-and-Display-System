#include "../../UTILITIES/types.h"
#include "../../UTILITIES/defines.h"
#include "../../MCAL/DIO DRIVER/dio.h"
#include "../../MCAL/INTERRUBTS/interrubt.h"
#include "speed_sensor.h"


void SPEED_SENSOR_INIT (uint8_t int_num)
{

	switch (int_num)
	{

		case INT0:
		DIO_PIN_INIT(PIN2,PORT_D,IN);
		EXT_INT_SENSE(INT0,RISING_EDGE);
		EN_EXT_INT(INT0);
		break;
				
				
		case INT1:
		DIO_PIN_INIT(PIN3,PORT_D,IN);
		EXT_INT_SENSE(INT1,RISING_EDGE);
		EN_EXT_INT(INT1);
		break;

		case INT2:
		DIO_PIN_INIT(PIN2,PORT_B,IN);
		EXT_INT_SENSE(INT2,RISING_EDGE);
		EN_EXT_INT(INT2);
		break;
	}
	EN_GENERAL_INTERRUBTS();
}


