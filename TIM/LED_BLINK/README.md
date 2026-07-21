# TIM2 LED Blink using Timer (STM32F401RE)

## Overview
This project demonstrates how to use the TIM2 peripheral of the STM32F401RE to generate a precise 1-second delay for blinking the onboard LED. The implementation uses direct register programming without relying on the HAL library.

## Objective
- Learn basic timer configuration using TIM2.
- Generate accurate delays using hardware timers.
- Blink an LED without using software delay loops.

## Hardware
- STM32 Nucleo-F401RE
- USB Cable

## Software
- STM32CubeIDE
- Embedded C

## Working
1. Enable the clocks for GPIOA and TIM2.
2. Configure PA5 as a GPIO output.
3. Set the TIM2 prescaler and auto-reload register for a 1-second delay.
4. Start TIM2.
5. Wait for the timer update event.
6. Clear the update flag.
7. Toggle the onboard LED.
8. Repeat continuously.

## Timer Configuration
- Timer: TIM2
- Prescaler (PSC): 15999
- Auto Reload Register (ARR): 999
- Timer Clock: 16 MHz
- Delay: 1 second


## Author
**Arunika T K**
