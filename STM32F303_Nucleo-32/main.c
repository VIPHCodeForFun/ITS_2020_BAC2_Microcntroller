/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* USER CODE BEGIN Includes */
#include <stdint.h>


/*-- Timer ! --*/
#define F_CPU 8000000UL // STM32F303x6x8 p.17
#define TIM1_BASE // TIM1  0x4001 2C00 - 0x4001 2FFF 	RM0316_Reference_manual p.58
#define TIM1_PSC (volatile uint32_t *)(TIM1_BASE + 0x00000028) // RM0316_Reference_manual p.586


/*-- RESET and Clock Control RSS --*/
#define RCC_BASE 0x40021000UL // RSS 0x40021000 - 0x400213FF 	RM0316_Reference_manual p.57
// AHBENR; 		!<peripheral clock enable register 			 	   Address offset: 0x14
#define RCC_AHBENR (volatile uint32_t *)(RCC_BASE + 0x00000014) // RM0316_Reference_manual p.148


/*-- GPIO --*/
#define GPIOA_BASE 0x48000000UL // GPIOA p.57 0x4800 0000 - 0x4800 03FF 1 K
// MODER;        !< GPIO port mode register,               Address offset: 0x00
#define GPIOA_MODER (volatile uint32_t *)(GPIOA_BASE + 0x00000000)
// OTYPER;       !< GPIO port output type register,        Address offset: 0x
// OSPEEDR;      !< GPIO port output speed register,       Address offset: 0x
// PUPDR;        !< GPIO port pull-up/pull-down register,  Address offset: 0x
// IDR;          !< GPIO port input data register,         Address offset: 0x
// ODR;          !< GPIO port output data register,        Address offset: 0x14
#define GPIOA_ODR (volatile uint32_t *)(GPIOA_BASE + 0x00000014)
// BSRR;         !< GPIO port bit set/reset register,      Address offset: 0x18
#define GPIOA_BSRR (volatile uint32_t *)(GPIOA_BASE + 0x00000018) // RM0316_Reference_manual p.240
// LCKR;         !< GPIO port configuration lock register, Address offset: 0x
// AFR[2];       !< GPIO alternate function registers,     Address offset: 0x
// BRR;          !< GPIO bit reset register,               Address offset: 0x
/* USER CODE END Includes */

int main(void)
{
	/*-- Setup --*/
	// Bit 17 IOPAEN: I/O port A clock enable	RM0316_Reference_manual p.149
		// ! <1 =  I/O port A clock enabled
	*RCC_AHBENR = (uint32_t)(1 << 17);

	// Clear Moder - A0-A15 to 0 (input mode)
	*GPIOA_MODER = 0;
	*GPIOA_BSRR = 0;

	// set PA1 (Pin 1) (p.237 MODER4[1:0]) to Output (01)
	*GPIOA_MODER |= (uint32_t)(1 << 2);

	while (1)
	{
		// Set PA1 to HIGH
		*GPIOA_BSRR |= (uint32_t)(1 << 1);
	}
}

