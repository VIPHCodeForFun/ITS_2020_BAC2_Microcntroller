/*
 * ledWithForDelay.c
 *
 * Created: 28.06.2023 15:17:01
 * Author: Philipp Vidmar
 */

#include "hal/pin-hal.h"

#define PIN 22

int main(void)
{
	/* Boot section */
	setupModeIO(PIN, OUTPUT);
	// Setup for delay
	uint32_t tick = 0;
	uint32_t ticks = 1600000;

	/* Program section */
	while (1)
	{
		setPin(PIN);
		for (tick = 0; tick < ticks; tick++)
		{
			// Wait
		}
		clearPin(PIN);
		for (tick = 0; tick < ticks; tick++)
		{
			// Wait
		}
	}
}