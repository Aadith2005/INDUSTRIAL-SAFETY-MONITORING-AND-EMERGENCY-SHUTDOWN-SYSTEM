# INDUSTRIAL-SAFETY-MONITORING-AND-EMERGENCY-SHUTDOWN-SYSTEM
BLOCK DIAGRAM:

<img width="589" height="379" alt="image" src="https://github.com/user-attachments/assets/7ad28356-6830-4938-8b2f-195f2ad884d9" />
# Industrial Safety Monitoring and Emergency Shutdown System Using LPC2129

## Overview

The Industrial Safety Monitoring and Emergency Shutdown System is an
embedded systems mini-project developed using the LPC2129 ARM7
microcontroller.

The project demonstrates how external interrupts can be used to trigger
an emergency motor shutdown. The system provides status information
through a LCD and UART serial communication.

The software is organized into a main application and separate LCD
and UART driver modules, making the code easier to understand and maintain.

## Objectives

- Implement external interrupt handling using the LPC2129.
- Demonstrate emergency motor shutdown using GPIO control.
- Display motor status on an LCD.
- Transmit system status messages through UART.
- Develop modular embedded C code using separate driver modules.
- Understand interrupt handling and peripheral interfacing in ARM7 systems.

## Hardware Components

- LPC2129 ARM7 microcontroller
- DC motor
- Character LCD
- ACTIVE-LOW LED
- UART interface for serial communication
- External interrupt switches
- IR sensor
- L293D Motor driver 
- Power supply and supporting circuitry

## Software and Tools

- Embedded C
- Keil uVision
- LPC2129 device support and header files
- UART serial terminal

## System Architecture

The system consists of the following software modules:

### 1. Main Application

File: `mini_project.c`

The main application is responsible for:

- Configuring the external interrupt pins.
- Configuring the Vector Interrupt Controller (VIC).
- Initializing the LCD and UART peripherals.
- Controlling the motor outputs through GPIO.
- Displaying motor status messages.
- Handling emergency interrupt events through an ISR.

### 2. LCD Driver

File: `lcd_header.h`

The LCD driver provides functions for initializing the LCD,
sending commands and data, displaying strings, and displaying
a scrolling title.

Functions include:

- `LCD_INIT()`
- `LCD_COMMAND()`
- `LCD_DATA()`
- `LCD_STR()`
- `LCD_TITLE()`

### 3. UART Driver

File: `UART_header.h`

The UART driver provides serial communication functions.

Functions include:

- `UART_CONFIG()`
- `UART_TX()`
- `UART_RX()`
- `UART_STR()`
- `UART_INTEGER()`
- `UART_FLOAT()`

These functions support UART configuration, transmission,
reception, and basic formatted data output.

### 4. Delay Function

File: `delay_ms.c`

The delay function uses Timer 0 registers to implement a
software delay based on the timer configuration.

Function:

- `delay_ms()`

## Working Principle

1. The microcontroller initializes the required GPIO pins,
   external interrupts, LCD, UART, and interrupt controller.

2. The system displays the project title on the LCD and through UART.

3. The motor-control outputs are configured to represent the
   motor-running state ("which is different bit on both pins to run the motor and same bit on both pins for motor off").

4. The 'MOTOR RUNNING' statement is displayed in both LCD and UART.

   
5. When a configured external interrupt is detected, the
   interrupt service routine executes.

6. The ISR clears the motor-control outputs and deactivates the
   indicator ACTIVE-LOW LED.

7. The LCD and UART display the emergency message:
   `MOTOR STOP!!`

8. A software flag is updated to indicate that the interrupt
   event has occurred.

10. The main application checks the flag and restores the
   motor-running output state.


## Peripheral Interfacing

### External Interrupts

The application configures EINT1 and EINT2 and enables their
corresponding interrupt sources in the VIC.

The interrupt service routine checks the VIC interrupt status
to identify the interrupt source.

The external interrupt configuration uses edge-sensitive
interrupt mode with falling-edge polarity.

### GPIO Motor Control

The motor-control signals are assigned to GPIO0 pins 21 and 22.

An indicator LED is assigned to GPIO0 pin 23.

The application changes these outputs during the motor-running
and emergency-stop states.

### LCD Interface

The LCD data bus is connected to GPIO1 pins 23 through 30.

The RS and Enable control signals use GPIO1 pins 19 and 18,
respectively.

### UART Communication

UART0 is configured for serial communication.

The UART driver initializes the peripheral and provides functions
for transmitting characters and strings.

## Learning Outcomes

Through this project, the following embedded systems concepts
were explored by me:

- ARM7 LPC2129 peripheral programming
- External interrupt configuration
- Interrupt service routines
- Vector Interrupt Controller configuration
- GPIO-based output control
- UART serial communication
- Character LCD interfacing
- Timer-based delays
- Modular embedded C programming

## Author

Aadith Dilipan

## License
MIT LICENSE
