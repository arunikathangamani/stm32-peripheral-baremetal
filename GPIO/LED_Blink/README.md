# GPIO LED Blink

## Overview
This project demonstrates GPIO programming on the STM32F401RE Nucleo board using bare-metal programming (direct register access). The onboard LED (LD2) connected to PA5 is blinked continuously without using the STM32 HAL library.

## Hardware
- STM32 Nucleo-F401RE
- Onboard LED (LD2)

## Software
- STM32CubeIDE
- Embedded C

## Pin Configuration

| Peripheral | Pin | Function |
|------------|-----|----------|
| GPIOA | PA5 | Onboard LED (LD2) |

## Registers Used

- RCC_AHB1ENR
- GPIOA_MODER
- GPIOA_ODR

## Working

1. Enable the GPIOA peripheral clock.
2. Configure PA5 as a GPIO output.
3. Turn the LED ON.
4. Introduce a software delay.
5. Turn the LED OFF.
6. Repeat continuously.

## Folder Structure

```
GPIO/
└── LED_Blink/
    ├── main.c
    ├── README.md

```

## Learning Outcomes

- GPIO clock enabling
- GPIO output configuration
- Register-level programming
- Bit manipulation
- Software delay implementation

## Author

Arunika T K
