#include <stdint.h>

#define RCC_AHB1ENR    (*(volatile uint32_t *)0x40023830)
#define RCC_APB2ENR    (*(volatile uint32_t *)0x40023844)

#define GPIOA_MODER    (*(volatile uint32_t *)0x40020000)
#define GPIOA_AFRL     (*(volatile uint32_t *)0x40020020)

#define SPI1_CR1       (*(volatile uint32_t *)0x40013000)
#define SPI1_CR2       (*(volatile uint32_t *)0x40013004)
#define SPI1_SR        (*(volatile uint32_t *)0x40013008)
#define SPI1_DR        (*(volatile uint32_t *)0x4001300C)

void SPI1_Init(void);
void SPI1_Transmit(uint8_t data);

int main(void)
{
    SPI1_Init();

    while(1)
    {
        SPI1_Transmit('A');

        for(volatile uint32_t i=0;i<500000;i++);
    }
}

void SPI1_Init(void)
{

    RCC_AHB1ENR |= (1<<0);


    RCC_APB2ENR |= (1<<12);

    GPIOA_MODER &= ~(0x3F << 10);
    GPIOA_MODER |=  (0x2A << 10);


    GPIOA_AFRL &= ~(0xFFF << 20);
    GPIOA_AFRL |=  (0x555 << 20);

    SPI1_CR1 = 0;

    SPI1_CR1 |= (1<<2);

    SPI1_CR1 |= (0<<3);

    SPI1_CR1 |= (1<<8);

    SPI1_CR1 |= (1<<9);

    SPI1_CR1 |= (1<<6);
}

void SPI1_Transmit(uint8_t data)
{
    while(!(SPI1_SR & (1<<1)));

    SPI1_DR = data;

    while(SPI1_SR & (1<<7));
}
