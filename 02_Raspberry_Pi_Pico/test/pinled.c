#include <stdio.h>

#include "pinhal.h"

#define PIN 0

int main(void)
{
  /* Bootsection */
  setupModeIO(PIN, OUTPUT);

  // Setup for delay
  uint32_t tick = 0;
  uint32_t ticks = 1000000;

  /* Programmsection */
  while (1)
  {
    setPin(PIN);
    for (tick = 0; tick < ticks; tick++)
    {
      // Wait
    }
    // clearPin(PIN);
    for (tick = 0; tick < ticks; tick++)
    {
      // Wait
    }
  }
}