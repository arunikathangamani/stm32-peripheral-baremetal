# SPI Master Transmit

## Overview
This project demonstrates SPI1 Master Transmit communication on the STM32F401RE using direct register programming (Bare Metal) without HAL or LL libraries.

## Features
- Bare-metal register-level programming
- SPI1 configured in Master mode
- Software Slave Management (SSM)
- 8-bit data transmission
- Polling-based transmission

## Hardware
- Board: STM32 Nucleo-F401RE
- SPI Peripheral: SPI1

## Pin Configuration

| Pin | Function |
|------|----------|
| PA5 | SPI1_SCK |
| PA6 | SPI1_MISO |
| PA7 | SPI1_MOSI |

## Registers Used
- RCC_AHB1ENR
- RCC_APB2ENR
- GPIOA_MODER
- GPIOA_AFRL
- SPI1_CR1
- SPI1_CR2
- SPI1_SR
- SPI1_DR

## Description
The program initializes SPI1 in Master mode and continuously transmits the character 'A' using polling.

## Author
Arunika T K
