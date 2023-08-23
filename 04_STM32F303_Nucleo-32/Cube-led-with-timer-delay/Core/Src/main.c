#include "main.h"
#include "hal/pin-hal.h"
#include "hal/timer-hal.h"

#define PIN 1

int main(void) {
	/* Boot section */
	setupModeIO(PIN, OUTPUT);
	setupTime();

	/* Program section */
	while (1) {
	    setPin(PIN);
	    delayMilliSeconds(1000);
	    clearPin(PIN);
	    delayMilliSeconds(1000);
	}
}
