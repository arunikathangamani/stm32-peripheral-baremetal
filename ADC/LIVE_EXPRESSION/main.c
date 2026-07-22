#include <stdint.h>
#define RCC_AHB1ENR (*(volatile uint32_t*)0x40023830)
#define GPIOA_MODER (*(volatile uint32_t*)0x40020000)
#define GPIOA_ODR   (*(volatile uint32_t*)0x40020014)
#define GPIOC_MODER (*(volatile uint32_t*)0x40020800)
#define GPIOC_IDR   (*(volatile uint32_t*)0x40020810)
#define RCC_APB2ENR (*(volatile uint32_t*)0x40023844)
#define ADC_SR  (*(volatile uint32_t*)0x40012000)
#define ADC_CR1 (*(volatile uint32_t*)0x40012004)
#define ADC_CR2 (*(volatile uint32_t*)0x40012008)
#define ADC_SMPR2 (*(volatile uint32_t*)0x40012010)
#define ADC_SQR1 (*(volatile uint32_t*)0x4001202C)
#define ADC_SQR3 (*(volatile uint32_t*)0x40012034)
#define ADC_DR  (*(volatile uint32_t*)0x4001204C)
#define ADC_CCR (*(volatile uint32_t*)0x40012304)
void ADC_Config()
{
	 RCC_AHB1ENR |= (1 << 0);
	 RCC_APB2ENR |= (1 << 8);
	 GPIOA_MODER |= (1 << 0);
	 GPIOA_MODER |= (1 <<1);
	 ADC_CR1 |= (1<<8);
	 ADC_CR2 |= (1<<0);
	 ADC_CR2 |= (1<<1);
	 ADC_SMPR2 |= (1<<2);
	 ADC_SQR1=0;
	 ADC_SQR3=0;
	// ADC_SR |= (1<<0);
	 ADC_CCR |= (1<<16);
	 ADC_CCR |= (1<<17);
}
volatile uint16_t ADC_Value;
int main(void)
{
   ADC_Config();
   while (1)
   {
       ADC_CR2 |= (1 << 30);
       while (!(ADC_SR & (1 << 1)));
       ADC_Value = (uint16_t)ADC_DR;
   }
}
