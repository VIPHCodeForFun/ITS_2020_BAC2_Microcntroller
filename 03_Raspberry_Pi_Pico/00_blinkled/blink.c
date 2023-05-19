/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */

#include <stdint.h>  // For uintXX_t types
#include <stdbool.h> // For bool type

#include "rp2040define.h"
#include "picohal.h"

int main(void)
{
    // Setup GPIO
    clearReset(IO_BANK0); // Disable reset status GPIO

    // Pin 0 to outputpin
    UINT32_T_CLR(GPIO0_CTRL, GPIO_FUNC_NULL); // Clear reset value null
    UINT32_T_SET(GPIO0_CTRL, GPIO_FUNC_SIO);  // Function select p.247
    BIT_SET(GPIO_OE, PIN0);                   // Output enable registers 1 for drive high/low based on GPIO_OUT

    // Setup Timer
    clearReset(TIMER); // Disable reset status GPIO

    while (1)
    {
        //-- Wirte SIO GPIO--
        BIT_SET(GPIO_OUT_SET, PIN0);

        // Wait
        waitMicrosecond(5000000);

        //-- Clear SIO GPIO--
        BIT_SET(GPIO_OUT_CLR, PIN0);

        // Wait
        waitMicrosecond(1000000);
    }

    return 0;
}