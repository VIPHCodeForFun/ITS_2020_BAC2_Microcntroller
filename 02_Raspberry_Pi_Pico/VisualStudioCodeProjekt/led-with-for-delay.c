#include <stdio.h>

#include "hal/pin-hal.h"

#define PIN 0

int main(void)
{
  /* Boot section */
  setupModeIO(PIN, OUTPUT);
  // Setup for delay
  volatile uint32_t tick = 0;
  volatile uint32_t ticks = 12500000;

  /* Program section */
  while (1)
  {
    setPin(PIN);
    for (tick = 0; tick < ticks; tick++)
    {
      // Wait
    }
    clearPin(PIN);
    for (tick = 0; tick < ticks; tick++)
    {
      // Wait
    }
  }
}