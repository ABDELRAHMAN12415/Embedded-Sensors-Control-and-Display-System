# Embedded Sensors Control and Display System

## Overview
This project involves the development of a control and display system for embedded sensors, focused on reading sensor values, applying plausibility checks, and controlling a motor based on sensor data. The system uses speed sensors, brake position sensors (BPS), and throttle position sensors (APPS) to monitor and control motor operations. The system displays sensor values and status on an LCD.

## Features
- **Sensor Input:**
  - Reads values from speed sensors, brake position sensors (BPS), and throttle position sensors (APPS).
  - Uses ADC to process sensor readings.
  
- **Motor Control:**
  - Motor is controlled based on the sensor values, with checks for plausibility to ensure safe operation.
  - The motor stops if invalid sensor readings are detected (e.g., brake position and throttle position both above a threshold).

- **Display System:**
  - Displays real-time sensor values and system status on an LCD screen.
  - Shows speed in km/h, brake position percentage, and throttle position percentage.

- **Error Handling:**
  - Applies plausibility checks to ensure sensor values are within expected ranges.
  - Triggers buzzer alerts if conditions are met, indicating that the system is ready for the motor to start.

## Components Used
- **Microcontroller:** [Insert the name/model of the microcontroller used]
- **Sensors:** 
  - Speed Sensors
  - Brake Position Sensors (BPS)
  - Throttle Position Sensors (APPS)
- **LCD Display:** [Insert the type/model of the LCD used]
- **Buzzer:** To alert when the system is ready to start
- **Motor Driver:** To control the motor based on sensor values

## How It Works
### Initialization
- The system initializes ADC for sensor readings and configures pins for input/output.
- The LCD is initialized to display system status and sensor values.
  
### Sensor Readings and Plausibility Checks
- The system continuously reads sensor values for BPS and APPS.
- If the BPS values are outside an acceptable range, the motor is disabled.
- If the throttle position is above a certain threshold while brake position is high, the motor is stopped.

### Interrupt Service Routines (ISRs)
- Interrupts are used for counting the sensor signals and updating speed values in real-time.
- Timer interrupts help in controlling the timing for the motor operation and sensor checks.

### Motor Control
- When all conditions are met, the motor is activated, and the system is marked as ready to drive.

## Files and Directories
- `application.c`: Contains the main application logic for reading sensor values, controlling the motor, and displaying information on the LCD.
- `speed_sensor.c`: Contains functions for initializing and reading speed sensor values.
- `lcd.c`: Contains functions to initialize and manage the LCD display.
- `types.h`: Header file for custom data types used across the project.
- `defines.h`: Header file containing macro definitions for pin configurations and sensor settings.
- `bit_manipulation.h`: Header file for bit manipulation operations on the microcontroller.
- `registers.h`: Header file for accessing and controlling hardware registers.

## Setup and Installation

1. **Hardware Setup:**
   - Connect the sensors (BPS, APPS, speed sensors) to the appropriate pins on the microcontroller.
   - Connect the motor driver and LCD display.
   - Set up the buzzer for alerts.

2. **Software Setup:**
   - Clone the repository to your local machine:
     ```bash
     git clone https://github.com/yourusername/embedded-sensors-control-display.git
     ```
   - Open the project in your preferred IDE (e.g., MPLAB X, Atmel Studio, etc.).
   - Compile the code and upload it to the microcontroller.

## How to Use
1. Once the system is powered on, it will start reading the sensor values.
2. The LCD will display the current speed, brake position, and throttle position.
3. If the brake position is above the threshold and the start button is pressed, the system will enable the motor control and start the motor.
4. If any sensor readings are invalid, the motor will be disabled and a buzzer will alert the user.

## Contributing
If you would like to contribute to this project, please fork the repository, make your changes, and submit a pull request. Contributions may include:
- Adding more sensors or features
- Improving code readability and efficiency
- Enhancing error handling and robustness
