/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */

#include <stdint.h>
#include "rp2040define.h"

int main(void)
{
    /* Enable IO BASE for GPIO */
    *RESET_ATOMIC_CLEAR = (uint32_t)(1 << 5); // Clears RESET bit 5 -> means the peripheral’s reset is deasserted
    while (*RESET_DONE == 0)                  // If a bit is set then a reset done signal has been returned
    {
        // Wait till reset is done
    }

    /*-- Setup GPIO Pin 0 --*/
    *GPIO0_CTRL = (uint32_t)(5); /* Function select         [4:0] p.247
                                  GPIO_FUNC_XIP = 0,
                                  GPIO_FUNC_SPI = 1,
                                  GPIO_FUNC_UART = 2,
                                  GPIO_FUNC_I2C = 3,
                                  GPIO_FUNC_PWM = 4,
                                  GPIO_FUNC_SIO = 5,
                                  GPIO_FUNC_PIO0 = 6,
                                  GPIO_FUNC_PIO1 = 7,
                                  GPIO_FUNC_GPCK = 8,
                                  GPIO_FUNC_NULL = 0x1f, -> 0001 1111
                                  */

    /*-- Wirte SIO GPIO--*/
    *GPIO_OE = (uint32_t)(1 << 0);      // Output enable registers 1 for drive high/low based on GPIO_OUT
    *GPIO_OE_SET = (uint32_t)(1 << 0);  // Perform an atomic bit-set on GPIO_OE, i.e. GPIO_OE |= wdata
    *GPIO_OUT_SET = (uint32_t)(1 << 0); // Perform an atomic bit-set on GPIO_OUT, i.e. GPIO_OUT |= wdata

    while (1)
    {
        // Do Nothing
    }
    return 0;
}