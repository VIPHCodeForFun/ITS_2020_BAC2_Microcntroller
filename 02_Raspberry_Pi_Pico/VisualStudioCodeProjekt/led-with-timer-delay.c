/*
 * led_with_timer_delay.c
 *
 * Created: 03.07.2023 14:07:41
 *  Author: Philipp Vidmar
 */

#include "hal/timer-hal.h"
#include "pin-hal.h"

#define PIN 0

int main(void)
{
	/* Bootsection */
	setupModeIO(PIN, OUTPUT);
	setupTime();

	/* Programmsection */
	while (1)
	{
		setPin(PIN);
		delayMilliSeconds(1000);
		clearPin(PIN);
		delayMilliSeconds(1000);
	}
}