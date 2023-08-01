/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */

#include <stdint.h>  // For uintXX_t types
#include <stdbool.h> // For bool type

#include "pinhal.h"
#include "pinbit.h"

int main(void)
{
  // Setup GPIO
  clearReset(IO_BANK0); // Disable reset status GPIO

  // Pin 0 to outputpin
  UINT32_T_CLR(GPIO0_CTRL, GPIO_FUNC_NULL); // Clear reset value null
  UINT32_T_SET(GPIO0_CTRL, GPIO_FUNC_SIO);  // Function select p.247
  BIT_SET_PTR(GPIO_OE, PIN0);               // Output enable registers 1 for drive high/low based on GPIO_OUT

  // Setup for delay
  volatile uint32_t tick = 0;
  volatile uint32_t ticks = 12500000;

  while (1)
  {
    //-- Wirte SIO GPIO--
    BIT_SET_PTR(GPIO_OUT_SET, PIN0);

    // Wait
    for (tick = 0; tick < ticks; tick++)
    {
    }

    //-- Clear SIO GPIO--
    BIT_SET_PTR(GPIO_OUT_CLR, PIN0);

    // Wait
    for (tick = 0; tick < ticks; tick++)
    {
    }
  }

  return 0;
}