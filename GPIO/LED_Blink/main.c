#include <stdint.h>
#define RCC_AHB1ENR (*(volatile uint32_t*)0X40023830)
#define GPIOA_MODER (*(volatile uint32_t*)0X40020000)
#define GPIOA_ODR   (*(volatile uint32_t*)0X40020014)
#define GPIOC_MODER (*(volatile uint32_t*)0X40020800)
#define GPIOC_IDR   (*(volatile uint32_t*)0X40020810)
int main()
{
	RCC_AHB1ENR|=(1<<0);
	RCC_AHB1ENR|=(1<<2);
	GPIOA_MODER |=(1<<10);
	GPIOA_MODER &=~(1<<11);
	GPIOC_MODER &=~(1<<26);
	GPIOC_MODER &=~(1<<27);
	while (1)
	{
	    if ((GPIOC_IDR & (1 << 13)) == 0)
	    {
	        GPIOA_ODR |= (1 << 5);
	    }
	    else
	    {
	        GPIOA_ODR &= ~(1 << 5);
	    }
	}
}
