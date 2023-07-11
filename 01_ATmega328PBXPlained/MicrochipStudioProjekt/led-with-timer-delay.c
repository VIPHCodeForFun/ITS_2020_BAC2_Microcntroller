/*
 * led_with_timer_delay.c
 *
 * Created: 03.07.2023 14:07:41
 *  Author: Philipp Vidmar
 */ 

#include "hal/timer-hal.h"
#include "hal/pin-hal.h"

int main(void){
	/* Bootsection */
	setupModeIO(PIND6 , OUTPUT);
	setupTime();
	sei();
	
	/* Programmsection */
	while(1){
		setPin(PIND6);
		delayMilliSeconds(1000);
		clearPin(PIND6);
		delayMilliSeconds(1000);
	}
}