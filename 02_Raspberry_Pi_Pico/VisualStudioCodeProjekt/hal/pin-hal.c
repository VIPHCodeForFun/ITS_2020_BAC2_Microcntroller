/*
 * ioHAL.c
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */
#include "pin-hal.h"

void setupModeIO(uint8_t pin, uint8_t mode)
{
	// Clear Reset 
	// RESETS_RESET io_rw_32  	p.177 
	uint32_t *ptr = io_rw_32[5]; // 0x00000020 [5] : io_bank0 (1)
	// RESETS_RESET_DONE	p.178
	io_ro_32[5] // 0x00000020 [5] : io_bank0 (0)
 

	switch (mode)
	{
	case OUTPUT:

		break;
	// case IMPUT:
	default:
		return;
	}
}

void setPin(uint8_t pin)
{
}

void clearPin(uint8_t pin)
{
}

/* -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#- */

/* without AT ac TRY */
void clearReset(uint8_t functionSelect)
{
	*RESET_ATOMIC_CLEAR = (uint32_t)(1 << functionSelect);
	while (BIT_IS_SET(RESET_DONE, functionSelect))
	{ /*
	 Reset done. If a bit is set then a reset done signal has been returned by the peripheral.
	 This indicates that the peripheral’s registers are ready to be accessed.
	  */
	}
}