/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <stdint.h>

/*-- RESET and Clock Control RSS --*/
#define RCC_BASE 0x40021000UL 										// RM0316_Reference_manual p.57
#define RCC_AHBENR (volatile uint32_t *)(RCC_BASE + 0x00000014) 	// RM0316_Reference_manual p.148
#define RCC_APB1ENR (volatile uint32_t *)(RCC_BASE + 0x0000001C) 	// RM0316_Reference_manual p.152


/*-- GPIO --*/
#define GPIOA_BASE 0x48000000UL 									// RM0316_Reference_manual p.57
#define GPIOA_MODER (volatile uint32_t *)(GPIOA_BASE + 0x00000000)
// OTYPER
// OSPEEDR
// PUPDR
// IDR
// ODR
#define GPIOA_ODR (volatile uint32_t *)(GPIOA_BASE + 0x00000014)
#define GPIOA_BSRR (volatile uint32_t *)(GPIOA_BASE + 0x00000018) 	// RM0316_Reference_manual p.240
// LCKR
// AFR[2]
// BRR


/*-- General-purpose timer TIM2 ! --*/
#define TIM2_BASE 0x40000000 										// RM0316_Reference_manual p.58
#define TIME2_CR1 (volatile uint32_t *)(TIM2_BASE + 0x00000000) 	// RM0316_Reference_manual p.647
#define TIME2_CR2 (volatile uint32_t *)(TIM2_BASE + 0x00000003)		// RM0316_Reference_manual p.648
// SMCR
// DIER
#define TIME2_SR (volatile uint32_t *)(TIM2_BASE + 0x00000010)		// RM0316_Reference_manual p.654
// EGR
// CCRM1
// CCRM2
// CCER
#define TIM2_CNT (volatile uint32_t *)(TIM2_BASE + 0x00000024) 		// RM0316_Reference_manual p.663
#define TIM2_PSC (volatile uint32_t *)(TIM2_BASE + 0x00000028) 		// RM0316_Reference_manual p.664
#define TIM2_ARR (volatile uint32_t *)(TIM2_BASE + 0x0000002C) 		// RM0316_Reference_manual p.664
#define TIM2_CCR1 (volatile uint32_t *)(TIM2_BASE + 0x00000018) 	// RM0316_Reference_manual p.656
// CCR2
// CCR3
// CCR4
// DCR
// DMAR

void TIM2_IRQHandler(void);


/* Global Variables */
uint32_t timer2count;


int main(void)
{
	// ! Activate Interrupts ????
	// ! Connection lost after uploading !!!!
	// ! Debugging possible ????

	timer2count = 0;

	/*-- Setup GPIO--*/
	*RCC_AHBENR = (uint32_t)(1 << 17); 	// Bit 17 IOPAEN: I/O port A clock enable RM0316_Reference_manual p.149
	*GPIOA_MODER = 0; 					// Clear Moder - A0-A15 to 0 (input mode)
	*GPIOA_BSRR = 0; 					// Clear Moder - A0-A15 to 0 (input mode)
	*GPIOA_MODER |= (uint32_t)(1 << 2); // set PA1 (Pin 1) (p.237 MODER4[1:0]) to Output (01)


	/*-- Setup Timer2 --*/
	*RCC_APB1ENR |= (uint32_t)(1 << 0); // TIM2EN: TIM2 timer clock enable 	RM0316_Reference_manual p.154
	*TIM2_PSC = 11;						// Set Prescaler
	*TIM2_CNT = 0; 						// Set timer value to 0
	*TIM2_ARR = 72727;					// Set Compare Match value
	*TIME2_CR1 |= (uint32_t)(1 << 0); 	// CEN: Counter enable 			   	RM0316_Reference_manual p.648


	while (1)
	{
		if(timer2count > 1000)
		{
		*GPIOA_BSRR |= (uint32_t)(1 << 1); // Set PA1 to HIGH
		timer2count = 0;
		}
	}
}

void TIM2_IRQHandler(void)
{
	timer2count++;
	// Clear the interrupt flag
	*TIME2_SR &= ~((uint32_t)(1 << 0));
}
