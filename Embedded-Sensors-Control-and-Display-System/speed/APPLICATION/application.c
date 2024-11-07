
#include "../UTILITIES/types.h"
#include "../UTILITIES/bit_manipulation.h"
#include "../UTILITIES/registers.h"
#include "../UTILITIES/defines.h"
#include "../ECUAL/HE_SPEED_SENSOR/speed_sensor.h"
#include "../ECUAL/LCD/lcd.h"
#include "application.h"


/*         ADC SENSORS VARIABLES            */

float BPS_sensor1_VALUE;
float BPS_sensor2_VALUE;

float BPS_VALUE;

float APPS_sensor1_VALUE;
float APPS_sensor2_VALUE;

float APPS_VALUE;

float motor_temp_sensor_VALUE;


/*         SPEED SENSORS VARIABLES            */

uint8_t SPEED_SENSOR_0_COUNT;
uint8_t SPEED_SENSOR_1_COUNT;
uint8_t SPEED_SENSOR_2_COUNT;

uint8_t SPEED_0_KMH;
uint8_t SPEED_1_KMH;
uint8_t SPEED_2_KMH;

/*         FLOW CONTROL FLAGS             */

uint8_t flag1 = 0;
uint8_t flag2 = 0;
uint8_t flag3 = 0;
uint8_t flag4 = 0;
uint8_t ready_to_drive = 0;
uint8_t buzz_count = 0;




ISR(TIMER0_OV)//TIMER0_OV_vect
{
	SPEED_0_KMH = SPEED_SENSOR_0_COUNT*1;
	SPEED_1_KMH = SPEED_SENSOR_1_COUNT*1;
	SPEED_2_KMH = SPEED_SENSOR_2_COUNT*1;

	SPEED_SENSOR_0_COUNT = 0;
	SPEED_SENSOR_1_COUNT = 0;
	SPEED_SENSOR_2_COUNT = 0;


	TIMER_VALUE(TIMER0,11);//count register reinitialization
}


ISR(TIMER1_OV)//TIMER_OV_vect
{
	DIO_PIN_WRITE(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, LOW);
	flag3 = 1;
}



ISR(EXT_INT_0)//INT0_vect
{
	SPEED_SENSOR_0_COUNT++;
}


ISR(EXT_INT_1)//INT0_vect
{
	SPEED_SENSOR_1_COUNT++;
}


ISR(EXT_INT_2)//INT2_vect
{
	SPEED_SENSOR_2_COUNT++;
}



void app_init(void){
	
DIO_PORT_INIT(PORT_A, OUT);
ADC_Init(8,AVCC);


DIO_PIN_INIT(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, OUT);
DIO_PIN_INIT(BUZZER_PIN, BUZZER_PORT, OUT);
DIO_PIN_INIT(START_BUTTON_PIN, START_BUTTON_PORT, IN);

DIO_PIN_WRITE(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, LOW);
DIO_PIN_WRITE(BUZZER_PIN, BUZZER_PORT, LOW);


SPEED_SENSOR_INIT(SPEED_SENSOR_0_INT);
SPEED_SENSOR_INIT(SPEED_SENSOR_1_INT);
SPEED_SENSOR_INIT(SPEED_SENSOR_2_INT);


SET_TIMER_MODE(TIMER0 , MODE_NORMAL);	//select normal mode of timer0
TIMER_VALUE(TIMER0,11);					//count register initialization
EN_TIMER_INT(TIMER0);					//enable timer0 OVER_FLOW interrupt	

SET_TIMER_MODE(TIMER1 , MODE_NORMAL);	//select normal mode of timer1
TIMER_VALUE(TIMER1,11);					//count register initialization
EN_TIMER_INT(TIMER1);					//enable timer1 OVER_FLOW interrupt

SET_TIMER_MODE(TIMER2 , MODE_NORMAL);	//select normal mode of timer2
TIMER_VALUE(TIMER2,11);					//count register initialization

TIMER_START(TIMER0,CLK5);				//select F/1024 prescaler of timer0 and start


		/* initialize the lcd */
	LCD_4BIT_INIT();
		/* display the main lines on the lcd */	
	LCD_4BIT_SEND_STRING("SPEED = ");
	LCD_4BIT_CURSOR_MOVE(1,10);
	LCD_4BIT_SEND_STRING("KMH");
	LCD_4BIT_CURSOR_MOVE(2,0);
	LCD_4BIT_SEND_STRING("TP=");
	LCD_4BIT_CURSOR_MOVE(2,6);
	LCD_4BIT_SEND_STRING("%");
	LCD_4BIT_CURSOR_MOVE(2,10);
	LCD_4BIT_SEND_STRING("BP=");
	LCD_4BIT_CURSOR_MOVE(2,16);
	LCD_4BIT_SEND_STRING("%");
	
	}

	
	

void app_start(void){
	
	while(ready_to_drive == 0)
	{
		
	BPS_sensor1_VALUE =           (((ADC_Read(BPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	BPS_sensor2_VALUE =           (((ADC_Read(BPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	
	BPS_VALUE = ((BPS_sensor1_VALUE + BPS_sensor2_VALUE)/2) ;
	
	/* display the brake position */
	LCD_4BIT_CURSOR_MOVE(2,13);
	LCD_4BIT_SEND_INT(BPS_VALUE);
		
		if (BPS_VALUE > 20 && DIO_PIN_READ(START_BUTTON_PIN, START_BUTTON_PORT))
		{
			
				DIO_PIN_WRITE(BUZZER_PIN, BUZZER_PORT,HIGH); //buzzer on
				
				/* delay for x sec */

		while (buzz_count < 200)
		{
			TIMER_START(TIMER2,CLK5);				//select F/ prescaler of timer2 and start			
			TIMER_ov_WAIT(TIMER2);                  //wait till the over flow of the timer2	
			TIMER_STOP(TIMER2);						//stop timer 2		
			
			DIO_PIN_TOGGLE(BUZZER_PIN, BUZZER_PORT);
			
			buzz_count++;
		}
			

			TIMER_STOP(TIMER2);                //stop timer 2
			

				DIO_PIN_WRITE(BUZZER_PIN, BUZZER_PORT, LOW); //buzzer off
				DIO_PIN_WRITE(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, HIGH); //set the motor controller signal as high (the driver can start the motor) 
			
			ready_to_drive = 1;
		}
	}
	

	
	//EN_TIMER_INT(TIMER2);					//enable timer2 OVER_FLOW interrupt
	
	
	while (ready_to_drive == 1)
	{
		
	BPS_sensor1_VALUE =           (((ADC_Read(BPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	BPS_sensor2_VALUE =           (((ADC_Read(BPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);

	APPS_sensor1_VALUE =          (((ADC_Read(APPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	APPS_sensor2_VALUE =          (((ADC_Read(APPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	
	 	
	/*  subtract each sensor two readings to check the 10% rule   */
	//  if > 10% (flag = 1)-> while(time < 100ms){check >10%} -> motor output =0
	//  if < 10% (flag = 0) -> define sensor reading by averaging the two separate sensors

	if ((BPS_sensor1_VALUE - BPS_sensor2_VALUE) > 10 || (BPS_sensor2_VALUE - BPS_sensor1_VALUE) > 10)
	{
		flag1 = 1;
		TIMER_START(TIMER1,CLK5); //start the timer to count the 100ms
	} 
	else
	{
		BPS_VALUE = ((BPS_sensor1_VALUE + BPS_sensor2_VALUE)/2) ;
	}
	
	
	
	
	if ((APPS_sensor1_VALUE - APPS_sensor2_VALUE) > 10 || (APPS_sensor2_VALUE - APPS_sensor1_VALUE) > 10)
	{
		flag2 = 1;
		TIMER_START(TIMER1,CLK5); //start the timer to count the 100ms
	} 
	else
	{
		APPS_VALUE = ((APPS_sensor1_VALUE + APPS_sensor2_VALUE)/2) ;
	}
	
	
	while (flag1 == 1 || flag2 == 1)
	{
		
		BPS_sensor1_VALUE =           (((ADC_Read(BPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
		BPS_sensor2_VALUE =           (((ADC_Read(BPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);

		APPS_sensor1_VALUE =          (((ADC_Read(APPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
		APPS_sensor2_VALUE =          (((ADC_Read(APPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
		
		
		
		
		/* while(time < 100ms){check for plausability >10%} */
		
		if ((BPS_sensor1_VALUE - BPS_sensor2_VALUE) < 10 && (BPS_sensor2_VALUE - BPS_sensor1_VALUE) < 10)
		{
			flag1 = 0;
		}
		if ((APPS_sensor1_VALUE - APPS_sensor2_VALUE) < 10 && (APPS_sensor2_VALUE - APPS_sensor1_VALUE) < 10)
		{
			flag2 = 0;
		}
		
		
		if (flag1 == 0 && flag2 == 0 && flag3 == 0)
		{
			TIMER_STOP(TIMER2); // stop timer 2 to avoid isr trigerring
		}
	}
	
	
	/*  apply plausibility check statement  */
	
	if (BPS_VALUE > 25 && APPS_VALUE > 25)
	{
		flag4 = 1;
		DIO_PIN_WRITE(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, LOW);	//STOP THE MOTOR
	}
   

	
	
	/*  BPS and APPS plausibility actions   */
		
	while (flag4 == 1)
	{
	
	APPS_sensor1_VALUE =          (((ADC_Read(APPS_sensor1_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	APPS_sensor2_VALUE =          (((ADC_Read(APPS_sensor2_pin)* ADC_STEP)-min_volt/(max_volt-min_volt))*100);
	
	APPS_VALUE = ((APPS_sensor1_VALUE + APPS_sensor2_VALUE)/2) ;
	/* display the throttle position */
		LCD_4BIT_CURSOR_MOVE(2,3);
		LCD_4BIT_SEND_INT(APPS_VALUE);
		
	/* keep the motor off until APPS signal < 5% */
		
		if (APPS_VALUE < 5)
		{
			flag4 = 0;
			DIO_PIN_WRITE(MOTOR_CONTROL_PIN, MOTOR_CONTROL_PORT, HIGH);
		}
	}	
	TIMER_STOP(TIMER2);
	
	/*  monitor the result output*/	
	LCD_4BIT_CURSOR_MOVE(1,7);
	LCD_4BIT_SEND_INT(BPS_VALUE);
	LCD_4BIT_CURSOR_MOVE(2,3);
	LCD_4BIT_SEND_INT(APPS_VALUE);
	LCD_4BIT_CURSOR_MOVE(2,13);
	LCD_4BIT_SEND_INT(BPS_VALUE);
	
	}
}






