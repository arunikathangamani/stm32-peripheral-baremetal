# PWM Generation using TIM2 (STM32F401RE)

## Overview
This project demonstrates how to generate a Pulse Width Modulation (PWM) signal using the TIM2 peripheral of the STM32F401RE through direct register programming. The PWM output is generated on PA0 (TIM2 Channel 1) without using the HAL library.

## Objective
- Learn PWM generation using TIM2.
- Configure GPIO alternate function mode.
- Generate a PWM waveform with a fixed frequency and duty cycle.
- Understand the relationship between timer configuration and PWM output.

## Hardware
- STM32 Nucleo-F401RE
- USB Cable
- Oscilloscope or Logic Analyzer (recommended for observing the PWM waveform)

## Software
- STM32CubeIDE
- Embedded C

## Working
1. Enable the clocks for GPIOA and TIM2.
2. Configure PA0 as Alternate Function mode.
3. Select AF1 to connect PA0 to TIM2 Channel 1.
4. Configure the timer prescaler and auto-reload register.
5. Set the compare register (CCR1) to define the duty cycle.
6. Configure TIM2 in PWM Mode 1.
7. Enable the timer channel and start the timer.
8. A PWM waveform is generated continuously on PA0.

## PWM Configuration
- Timer: TIM2
- Channel: CH1
- Output Pin: PA0
- Alternate Function: AF1
- Timer Clock: 1 MHz
- PWM Frequency: 1 kHz
- Duty Cycle: 50% (modifiable by changing `TIM2_CCR1`)

## Learning Outcomes
- Understanding PWM generation using timers.
- Configuring Alternate Function (AF) pins.
- Setting PWM frequency using PSC and ARR.
- Controlling duty cycle using CCR1.
- Generating hardware-based PWM without software delays.

## Author
**Arunika T K**
