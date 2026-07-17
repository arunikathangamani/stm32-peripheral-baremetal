# Button Toggle LED

## Description
This project demonstrates how to toggle the onboard LED (LD2) connected to PA5 using the onboard user button (B1) connected to PC13 on the STM32F401RE Nucleo board.

## Features
- Configures PA5 as a GPIO output.
- Configures PC13 as a GPIO input.
- Toggles the LED on every button press.
- Waits for the button to be released before accepting the next press (basic software debouncing).

## Hardware
- Board: STM32F401RE Nucleo
- LED: PA5 (LD2)
- User Button: PC13 (B1)

## Programming Method
- Embedded C
- Bare-metal programming
- Direct register-level programming
- No HAL or STM32Cube libraries

## Expected Output
- Initially, the LED is OFF.
- Press the button once → LED turns ON.
- Press the button again → LED turns OFF.
- Each button press toggles the LED state.
