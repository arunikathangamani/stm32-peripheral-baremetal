#include <stdint.h>

#define RCC_AHB1ENR    (*(volatile uint32_t *)0x40023830)
#define RCC_APB1ENR    (*(volatile uint32_t *)0x40023840)


#define GPIOA_MODER    (*(volatile uint32_t *)0x40020000)
#define GPIOA_AFRL     (*(volatile uint32_t *)0x40020020)

#define TIM2_CR1       (*(volatile uint32_t *)0x40000000)
#define TIM2_CCMR1     (*(volatile uint32_t *)0x40000018)
#define TIM2_CCER      (*(volatile uint32_t *)0x40000020)
#define TIM2_PSC       (*(volatile uint32_t *)0x40000028)
#define TIM2_ARR       (*(volatile uint32_t *)0x4000002C)
#define TIM2_CCR1      (*(volatile uint32_t *)0x40000034)

int main(void)
{

    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_APB1ENR |= (1 << 0);   // TIM2


    GPIOA_MODER &= ~(3 << (0 * 2));
    GPIOA_MODER |=  (2 << (0 * 2));

    /* AF1 = TIM2_CH1 */
    GPIOA_AFRL &= ~(0xF << 0);
    GPIOA_AFRL |=  (1 << 0);

    /* Timer Configuration */
    TIM2_PSC = 16 - 1;         // 16 MHz /16 = 1 MHz
    TIM2_ARR = 1000 - 1;       // PWM Frequency = 1 kHz

    /* 50% Duty Cycle */
    TIM2_CCR1 = 500;

    /* PWM Mode 1 on Channel 1 */
    TIM2_CCMR1 &= ~(7 << 4);
    TIM2_CCMR1 |=  (6 << 4);

    /* Enable preload */
    TIM2_CCMR1 |= (1 << 3);

    /* Enable Channel 1 output */
    TIM2_CCER |= (1 << 0);

    /* Enable Auto-Reload Preload */
    TIM2_CR1 |= (1 << 7);

    /* Start Timer */
    TIM2_CR1 |= (1 << 0);

    while (1)
    {
    }
}
