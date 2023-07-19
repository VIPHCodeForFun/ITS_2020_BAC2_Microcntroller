/*
 * timer_hal.c
 *
 * Created: 01.07.2023 17:43:40
 *  Author: Philipp Vidmar
 */

#include <avr/io.h>

#include "timer-hal.h"

void setupTime(){
	TIME_COUNTER = 0;
	BIT_SET(TCCR2A, 1); // p.197 WGM21 Set CTC-MODE

	/* Calculation prescaler */
	// 16 000 000 - 1/f=s -> 6.25 * 10^-8sek
	// 2048us / 256 countersteps = 8 us
	// 8us / 6,25*10^-8 sek = 128

	BIT_SET(TCCR2B, 0); // p.197 CS20 Pres. to 128
	BIT_SET(TCCR2B, 2); // p.197 CA22

	// Compare Value = 2000us / 8 = 250 (We use 249, because 0 is also a value)
	OCR2A = 249;

	/* enable Timer Interrupt */
	BIT_SET(TIMSK2, 1); // p.200 OCIE2A
}

uint32_t milliSeconds(){
	uint32_t currentTimerCounter = 0;
	uint32_t currentTimerValue = 0;

	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		currentTimerCounter = TIME_COUNTER;
		currentTimerValue = TCNT2;
	}
	/* timecounter 1 = 2 milliSekonds ------> (*2) */
	currentTimerCounter = currentTimerCounter * 2; // mSekonds

	/* When the timer is over half (*0.5) round up
	if (currentTimerValue >= (*OCR2A) * 0.5){
		return currentTimerCounter + 1;
	}*/
	return currentTimerCounter;
}

void delayMilliSeconds(uint32_t milliSekondsDelay){
	/* Create Timestamp */
	uint32_t timeStamp = milliSeconds() + milliSekondsDelay;
	while (timeStamp > milliSeconds()){
		// Wait till Timestamp is reached
	}
}

ISR(TIMER2_COMPA_vect){
	TIME_COUNTER++;
}