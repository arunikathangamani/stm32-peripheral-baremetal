# ADC Single Conversion (Live Expressions)

## Overview
This project demonstrates Analog-to-Digital Conversion (ADC) on the STM32F401RE using direct register programming (bare-metal). The ADC continuously reads the analog voltage applied to PA0 (ADC Channel 0), and the converted digital value is monitored using STM32CubeIDE Live Expressions.

## Hardware
- STM32 Nucleo-F401RE
- 10 kΩ Potentiometer
- Jumper wires

## Connections

| Potentiometer | STM32F401RE |
|--------------|-------------|
| VCC | 3.3V |
| GND | GND |
| Wiper | PA0 (ADC1_IN0) |

## Features
- Bare-metal register programming
- ADC1 single-channel configuration
- Continuous analog voltage sampling
- 12-bit ADC resolution
- Output monitored using Live Expressions

## Output
The converted ADC value is stored in the `ADC_Value` variable.

During debugging, add `ADC_Value` to **STM32CubeIDE → Live Expressions** to observe the digital value in real time.

Typical values:

| Input Voltage | ADC Value |
|---------------|---------- |
| 0 V           | 0         |
| 1.65 V        | ~2048     |
| 3.3 V         | 4095      |

Rotating the potentiometer changes the ADC value continuously between **0** and **4095**.

## Learning Outcomes
- Configure ADC using registers
- Configure GPIO in Analog Mode
- Start ADC conversion using software
- Read ADC conversion result
- Monitor variables using Live Expressions
