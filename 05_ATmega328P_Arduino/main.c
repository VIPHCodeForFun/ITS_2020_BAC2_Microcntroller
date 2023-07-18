/*
 * Philipp Vidmar
 * https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
 *  https://www.youtube.com/watch?v=j4xw8QomkXs&t=312s
 */
/* Dieser Code verwendet die AVR-Library avr/io.h, um auf die Register des Mikrocontrollers zuzugreifen. */
#include <avr/io.h>
/* Die Funktion _delay_ms(1000) ist eine Funktion aus der util/delay.h-Bibliothek, die eine Pause von einer */
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PD0); // Setze Pin 8 als Ausgang

    while (1)
    {
        PORTB |= (1 << PD0);  // Schalte die LED ein
        _delay_ms(1000);      // Warte eine Sekunde
        PORTB &= ~(1 << PD0); // Schalte die LED aus
        _delay_ms(1000);      // Warte eine weitere Sekunde
    }
    return 0;
}