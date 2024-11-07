#ifndef APPLICATION_H_
#define APPLICATION_H_


/*         CONTROL OUTPUT PINS            */

#define MOTOR_CONTROL_PIN 6
#define MOTOR_CONTROL_PORT PORT_A

#define BUZZER_PIN 7
#define BUZZER_PORT PORT_A

#define START_BUTTON_PIN 11
#define START_BUTTON_PORT PORT_B

/*         ADC REFFERENCES            */

#define VCC 5

#define ADC_STEP VCC/1024.0


/*         ADC SENSORS RESOLUTION            */

#define BPS_sensor_RESOLUTION (float)0.01

#define APPS_sensor_RESOLUTION  (float)0.01

/*         ADC SENSORS OUTPUT VOLTAGE            */

#define max_volt 5

#define min_volt 1

/*         ADC SENSORS PINS            */

#define BPS_sensor1_pin 0
#define BPS_sensor2_pin 1

#define APPS_sensor1_pin 2
#define APPS_sensor2_pin 3


/*         SPEED SENSORS INTERRUBTS            */

#define SPEED_SENSOR_0_INT INT0
#define SPEED_SENSOR_1_INT INT1
#define SPEED_SENSOR_2_INT INT2


/*           APPLICATION PROTOTYPES         */

void app_init(void);
void app_start(void);



#endif