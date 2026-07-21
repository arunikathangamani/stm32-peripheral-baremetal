#include <stdint.h>

#define RCC_AHB1ENR    (*(volatile uint32_t *)0x40023830)
#define RCC_APB1ENR    (*(volatile uint32_t *)0x40023840)

#define GPIOA_MODER    (*(volatile uint32_t *)0x40020000)
#define GPIOA_ODR      (*(volatile uint32_t *)0x40020014)

#define TIM2_CR1       (*(volatile uint32_t *)0x40000000)
#define TIM2_SR        (*(volatile uint32_t *)0x40000010)
#define TIM2_PSC       (*(volatile uint32_t *)0x40000028)
#define TIM2_ARR       (*(volatile uint32_t *)0x4000002C)

int main(void)
{
    /* Enable GPIOA and TIM2 clocks */
    RCC_AHB1ENR |= (1 << 0);
    RCC_APB1ENR |= (1 << 0);

    /* PA5 as Output */
    GPIOA_MODER &= ~(3 << (5 * 2));
    GPIOA_MODER |=  (1 << (5 * 2));

    /* Timer configuration */
    TIM2_PSC = 16000 - 1;      // 16 MHz -> 1 kHz
    TIM2_ARR = 1000 - 1;       // 1 second

    TIM2_CR1 |= (1 << 0);      // Enable timer

    while (1)
    {
        while (!(TIM2_SR & 1));   // Wait for update event
        TIM2_SR &= ~(1 << 0);     // Clear flag

        GPIOA_ODR ^= (1 << 5);    // Toggle LED
    }
}
