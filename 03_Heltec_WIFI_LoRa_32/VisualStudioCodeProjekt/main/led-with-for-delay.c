/*
 * ledWithForDelay.c
 *
 * Created: 28.06.2023 15:17:01
 * Author: Philipp Vidmar
 */

#include "../hal/pin-hal.h"

#define PIN 23

int app_main(void)
{
  /* Bootsection */
  setupModeIO(PIN, OUTPUT);
  // Setup for delay
  uint32_t tick = 0;
  uint32_t ticks = 8000000;

  /* Programmsection */
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