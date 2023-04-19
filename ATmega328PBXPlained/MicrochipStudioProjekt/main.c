/*
 * GccApplication1.c
 *
 * Created: 20.03.2023 21:09:50
 * Author : Vidmar Philipp
 * ATmega328PB: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40001906C.pdf
 * Pinout:		https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328PB-Xplained-Mini-UG-DS50002660B.pdf
 * Schematics:	https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328PB_Xplained_Mini_Schematics.pdf
 * g. started:	http://ww1.microchip.com/downloads/en/appnotes/atmel-42482-getting-started-with-atmega328pb_application%20note_at08401.pdf
 * buy at:		https://www.microchip.com/en-us/product/ATMEGA328PB
 * TODO:
 *		ZEIT PASST NICHT ! FCPU ???????????????
 *		Toolchain aufnehmen Video OBS
 *		Time.c und time.h erstellen
 */ 

#define F_CPU 8000000UL //  ATmega328PB p.52 11.5

#include <avr/io.h>
#include <avr/interrupt.h>		 // sei(); 

/* Start time */
#include <util/atomic.h>		 // ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {}

volatile uint32_t timecounter;

timeSetup()
{
	/* Set CTC-MODE */
	TCCR2A = (1 << WGM21);
	
	/* Calculation prescaler */
	// 8 000 000 Hz = 0,125 ms
	// 2048us / 256 = 8 us
	// 8us / 0,125ms = 64
	TCCR2B = (1 << CS22);  // ATmega328PB p.237
	
	// Compare Value = 2000us / 8 = 250 (We use 249, because 0 is also a value)
	OCR2A = 249; // ATmega328PB p.224 12.7.2
	
	/* enable Timer Interrupt */
	TIMSK2 = (1 << OCIE2A);
}

uint32_t milliSeconds()
{
	uint32_t currentTimerCounter = 0;
	uint32_t currentTimerValue = 0;
	
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		currentTimerCounter = timecounter;
		currentTimerValue = TCNT2; // ATmega328PB p.224 12.7.2
	}
	/* timecounter 1 = 2 milliSekonds ------> (*2) */
	currentTimerCounter = currentTimerCounter * 2; // mSekonds
	
	/* When the timer is over half (*0.5) round up */
	if (currentTimerValue >= OCR2A * 0.5) // ATmega328PB p.224 12.7.2
	{
		return currentTimerCounter + 1;
	}
	return currentTimerCounter;
}

void delayMilli(uint32_t milliSekondsDelay)
{
	/* Create Timestamp */
	uint32_t timeStamp = milliSeconds() + milliSekondsDelay;
	
	while (timeStamp > milliSeconds())
	{
		// Wait till Timestamp is reached
	}
}

// Interrupt Service Routine (ISR) CTC-Modus
ISR(TIMER2_COMPA_vect) 
{
	timecounter++;
}
/* END time */

int main(void)
{
	timeSetup();
	sei();
	
	/* Setup IO*/
	DDRB = 0b00000001; // set PIN0 as output
	PORTB = 0b00000000; // set PIN0 LOW
	
	while(1)
	{
		PORTB = 0b00000000; // set PIN0 LOW
		delayMilli(1000);	// 1 Sekond
		PORTB = 0b00000001; // set PIN0 HIGH
		delayMilli(1000);	// 1 Sekond
	}
}

