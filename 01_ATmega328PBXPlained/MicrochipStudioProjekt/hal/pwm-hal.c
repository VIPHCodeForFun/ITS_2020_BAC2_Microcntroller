/*
 * pwm_hal.c
 *
 * Created: 03.07.2023 15:27:01
 *  Author: Philipp Vidmar
 */ 

#include "pwm-hal.h"

void setupPWM(){
	// Data Direction Register (DDR) bit corresponding to the OC0A pin must be set in order to enable the output driver
	// PD6 = 22 (Timer/Counter0 Output Compare Match A Output) p.98
	setupModeIO(22, OUTPUT); 
	// Writing the TCCR0A.COM0x[1:0] bits to 0x2 will produce a non-inverted PWM;
	BIT_SET(TCCR0A, 7); // COM0A1

	// Fast PWM OCRA Update of OCR0x at BOTTOM p.
	BIT_SET(TCCR0A, 0); // WGM00
	BIT_SET(TCCR0A, 1); // WGM01

	/* Compare match */
	OCR0A = 128;
	
	/* Prescaler 1024 p.128 */
	/* 16 000 000 HZ / 1204 = 15525 Hz	 */
	/* 15525 Hz -> 6,4*10^-5 sek		 */
	/* 6,4*10^-5 sek * 255 OCR = 0,01632 sek */
	BIT_SET(TCCR0B, 0); // CS00
	BIT_SET(TCCR0B, 2); // CS02
}

void updatePWM(uint8_t value){
	OCR0A = value;
}