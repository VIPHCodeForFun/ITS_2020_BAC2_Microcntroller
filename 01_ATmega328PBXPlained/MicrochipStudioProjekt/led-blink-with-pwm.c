/*
 * led_blink_with_pwm.c
 *
 * Created: 03.07.2023 15:22:48
 *  Author: Philipp Vidmar
 */ 

#include "hal/timer-hal.h"
#include "hal/pwm-hal.h"

#define  PIN 22

int main(void){
	/* Bootsection */
	setupPWM();
	setupTime();
	sei();
	
	/* Programmsection */
	while(1){
	updatePWM(50);
	delayMilliSeconds(1000);
	updatePWM(255);
	delayMilliSeconds(1000);
	}
}