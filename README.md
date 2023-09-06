# Solar Power Management System

## Overview

This Arduino-based Solar Power Management System monitors solar and battery voltages, displays the values on an LCD screen, and controls a relay to manage power based on predefined voltage thresholds.

## Components

- Arduino board (e.g., Arduino Uno)
- LiquidCrystal library for the LCD display
- LiquidCrystal display
- Solar panel connected to analog pin A0
- Battery connected to analog pin A1
- Relay module connected to digital pin 7
- Resistors R1 (30,000 ohms) and R2 (7,500 ohms) for voltage division
- Reference Voltage: 5.0V

## Installation and Setup

1. Connect the hardware components as described in the "Components" section.
2. Upload the provided Arduino code to your Arduino board.

## Code Description

The Arduino code performs the following functions:

- Measures solar voltage and displays it on the LCD screen.
- Measures battery voltage and displays it on the LCD screen.
- Controls a relay based on predefined voltage thresholds:
  - If battery voltage falls below 7.5V, the relay is turned on.
  - If battery voltage rises above 13.5V, the relay is turned off.
- Illuminates an LED on pin 5 if battery voltage falls below 7.4V.

## Pin Configuration

- `A0`: Solar panel voltage input
- `A1`: Battery voltage input
- `7`: Relay control pin

## Circuit Diagram

![Circuit Diagram](circuit-diagram/Screenshot%20from%202023-09-06%2017-14-09.png)

## Usage

1. Power on the Arduino board.
2. The LCD screen will display solar and battery voltages.
3. The relay and LED will be controlled based on the battery voltage.

## Troubleshooting

If you encounter any issues:

- Verify your hardware connections.
- Check that the voltage divider resistors R1 and R2 are correctly configured.
- Ensure that the analog pins A0 and A1 are correctly connected to the solar panel and battery.
- Verify the relay connections and functionality.

![image for lcd hardware configuration](circuit-diagram/Screenshot%20from%202023-09-06%2016-26-00.png)

## Contributors

- Manasseh Gitau

## License

This project is open-source and available under the MIT license.
