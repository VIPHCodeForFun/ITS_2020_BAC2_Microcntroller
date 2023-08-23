/*
 * pin-define.h
 * In this header file the required addresses for the microcontroller "" are abstracted in
 * macros according to the data sheet for better readability.
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */

#ifndef PINDEFINE_H_
#define PINDEFINE_H_

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
#define GPIOA_BRR (volatile uint32_t *)(GPIOA_BASE + 0x00000028) 	// RM0316_Reference_manual p.242

#endif /* PINDEFINE_H_ */
