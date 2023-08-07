/*
 * ledWithForDelay.c
 *
 * Created: 28.06.2023 15:17:01
 * Author: Philipp Vidmar
 */ 

#include "hal/pin-hal.h"

int main(void){
	/* Bootsection */
	setupModeIO(PIND6, OUTPUT);
	// Setup for delay
	uint32_t tick = 0;
	uint32_t ticks = 1600000;
	
	/* Programmsection */
	while(1){
		setPin(PIND6);
		for (tick = 0; tick < ticks; tick++){
			// Wait
		}
		clearPin(PIND6);
		for (tick = 0; tick < ticks; tick++){
			// Wait
		}	
	}
}