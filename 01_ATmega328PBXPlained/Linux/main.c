#include <avr/io.h>

int main(void)
{
    DDRB |= (1 << DDB0);    // Set PB0 as output
    PORTB |= (1 << PORTB0); // Turn on LED at PB0

    while (1)
    {
        // Main loop
    }

    return 0;
}
