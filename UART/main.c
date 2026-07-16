#include <stdint.h>
#define RCC_BASE           0x40023800
#define RCC_AHB1ENR        (*(volatile uint32_t*)(RCC_BASE + 0x30))
#define RCC_APB1ENR        (*(volatile uint32_t*)(RCC_BASE + 0x40))
#define GPIOA_BASE         0x40020000
#define GPIOA_MODER        (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL         (*(volatile uint32_t*)(GPIOA_BASE + 0x20))
#define USART2_BASE        0x40004400
#define USART2_SR          (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_DR          (*(volatile uint32_t*)(USART2_BASE + 0x04))
#define USART2_BRR         (*(volatile uint32_t*)(USART2_BASE + 0x08))
#define USART2_CR1         (*(volatile uint32_t*)(USART2_BASE + 0x0C))
void UART2_Init(void);
void UART2_WriteChar(char ch);
void UART2_WriteString(char *str);
void delay(void);
int main(void)
{
   UART2_Init();
   while (1)
   {
       UART2_WriteString("ARUNIIII\r\n");
       delay();
   }
}
void UART2_Init(void)
{
   RCC_AHB1ENR |= (1 << 0);
   RCC_APB1ENR |= (1 << 17);
   GPIOA_MODER &= ~(0xF << 4);
   GPIOA_MODER |=  (0xA << 4);
   GPIOA_AFRL &= ~(0xFF << 8);
   GPIOA_AFRL |= (7 << 8);
   GPIOA_AFRL |= (7 << 12);
   USART2_BRR = 0x8B;
   USART2_CR1 |= (1 << 3);   // TE
   USART2_CR1 |= (1 << 2);   // RE
   USART2_CR1 |= (1 << 13);  // UE
}
void UART2_WriteChar(char ch)
{
   while (!(USART2_SR & (1 << 7)));   // TXE
   USART2_DR = ch;
}
void UART2_WriteString(char *str)
{
   while (*str)
   {
       UART2_WriteChar(*str++);
   }
}
void delay(void)
{
   for (volatile uint32_t i = 0; i < 500000; i++);
}
