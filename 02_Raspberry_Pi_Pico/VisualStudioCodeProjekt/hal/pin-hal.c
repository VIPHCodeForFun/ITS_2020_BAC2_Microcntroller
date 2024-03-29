/*
 * ioHAL.c
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */
#include "pin-hal.h"

void setupModeIO(uint8_t pin, uint8_t mode)
{
	// Clear IO Reset !! maby it has to be ATOMIC
	// BIT_CLR(*RESET, IO_BANK0);
	BIT_SET_PTR((RESET + ATOMIC_CLEAR), IO_BANK0);
	// Wait till Reset is finished.
	while (BIT_IS_SET_PTR(RESET_DONE, IO_BANK0))
	{
		/*Reset done. If a bit is set then a reset done signal has been returned by the peripheral.
		This indicates that the peripheral’s registers are ready to be accessed.*/
	}

	switch (mode)
	{
	case OUTPUT:
		// Just works for PIN0 !
		pin = 0;
		// GPIO0_CTRL = PIN 0 !! maby PIN x 									p.244
		// Clear [Resetstate= 0x1f= 0001 1111] in 4:0 FUNCSEL 					p.248
		UINT32_T_CLR(GPIO0_CTRL, 0x0000001f);  // Clear reset value null
		UINT32_T_SET(GPIO0_CTRL, (uint32_t)5); // Function select p.247
		BIT_SET_PTR(GPIO_OE, pin);			   // Output enable registers 1 for drive high/low based on GPIO_OUT

		break;
	// case IMPUT:
	default:
		/* End switch (mode) */

		return;
	}
}

void setPin(uint8_t pin)
{
	BIT_SET_PTR(GPIO_OUT_SET, pin); // Perform an atomic bit-set on GPIO_OUT p.47
}

void clearPin(uint8_t pin)
{
	BIT_SET_PTR(GPIO_OUT_CLR, pin); // Perform an atomic bit-clear on GPIO_OUT p.47
}