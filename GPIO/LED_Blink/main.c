#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830)
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000)
#define GPIOA_ODR   (*(volatile uint32_t *)0x40020014)

int main(void)
{
    /* Enable GPIOA clock */
    RCC_AHB1ENR |= (1 << 0);

    /* Configure PA5 as Output */
    GPIOA_MODER &= ~(3 << 10);   // Clear bits 11:10
    GPIOA_MODER |=  (1 << 10);   // Set 01 = Output mode

    while (1)
    {
        /* LED ON */
        GPIOA_ODR |= (1 << 5);
        for (volatile uint32_t i = 0; i < 1000000; i++);

        /* LED OFF */
        GPIOA_ODR &= ~(1 << 5);
        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}
