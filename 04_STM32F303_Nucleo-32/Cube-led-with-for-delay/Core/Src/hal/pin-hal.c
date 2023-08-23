/*
 * ioHAL.c
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */
#include "hal/pin-hal.h"

// works FOR PORT A pins!!
void setupModeIO(uint8_t pin, uint8_t mode)
{
	BIT_SET_PTR(RCC_AHBENR,17);	// Bit 17 IOPAEN: I/O port A clock enable RM0316_Reference_manual p.149

	switch (mode) {
	case OUTPUT:;
		// Calc ModerIndex bit [1,0] = Pin 0 , bit [3,2] Pin 1 , .... 	p.237
		uint8_t moderbit = pin * 2;
		BIT_SET_PTR(GPIOA_MODER,moderbit); // set PA1 (Pin 1) (p.237 MODER4[1:0]) to Output (01)
		break;
	// case IMPUT:
	default:
		/* End switch (mode) */
		return;
	}
}

void setPin(uint8_t pin)
{
	BIT_SET_PTR(GPIOA_BSRR,pin);
}

void clearPin(uint8_t pin)
{
	BIT_SET_PTR(GPIOA_BRR,pin);
}
