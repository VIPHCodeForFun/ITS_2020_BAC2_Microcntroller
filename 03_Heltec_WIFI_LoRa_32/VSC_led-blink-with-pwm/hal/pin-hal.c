/*
 * pin-hal.c
 *
 * Created: 10.08.2023 16:21:37
 *  Author: Philipp Vidmar
 */
#include "pin-hal.h"

void setupModeIO(uint8_t pin, uint8_t mode)
{
	switch (mode)
	{
	case OUTPUT:
		GPIO_FUNC_OUT_SEL_CFG_REG[pin] = 256;
		BIT_CLR_PTR(GPIO_ENABLE_REG, pin); // Clear first
		BIT_SET_PTR(GPIO_ENABLE_REG, pin); // Then set
		break;
	default:
		return;
	}
}

void setPin(uint8_t pin)
{
	BIT_CLR_PTR(GPIO_OUT_REG, pin); // Clear first
	BIT_SET_PTR(GPIO_OUT_REG, pin); // Then set
}

void clearPin(uint8_t pin)
{
	BIT_CLR_PTR(GPIO_OUT_REG, pin); // Clear
}

/* -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#- */
