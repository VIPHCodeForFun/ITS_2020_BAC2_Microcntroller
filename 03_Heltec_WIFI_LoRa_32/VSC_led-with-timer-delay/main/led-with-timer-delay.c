/*
 * led_with_timer_delay.c
 *
 * Created: 010.08.2023 14:07:41
 *  Author: Philipp Vidmar
 */

#include "../hal/pin-hal.h"
#include "../hal/timer-hal.h"

#define PIN 23

int app_main(void)
{
  /* Bootsection */
  setupModeIO(PIN, OUTPUT);
  setupTime();

  /* Programmsection */
  while (1)
  {
    setPin(PIN);
    delayMilliSeconds(1000);
    clearPin(PIN);
    delayMilliSeconds(1000);
  }
}