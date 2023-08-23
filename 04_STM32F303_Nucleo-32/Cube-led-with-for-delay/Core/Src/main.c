#include "hal/pin-hal.h"

#define PIN 1

int main(void) {
	/* Bootsection */
	setupModeIO(PIN, OUTPUT);
	// Setup for delay
	uint32_t tick = 0;
	uint32_t ticks = 1600000;

	/* Programmsection */
	while (1) {
		for (tick = 0; tick < ticks; tick++) {
			// Wait
		}
		setPin(PIN);

		for (tick = 0; tick < ticks; tick++) {
			// Wait
		}
		clearPin(PIN);
	}
}
