/*
 * led_blink_with_pwm.c
 *
 * Created: 03.07.2023 15:22:48
 *  Author: Philipp Vidmar
 */

#include "hal/pwm-hal.h"
#include "hal/timer-hal.h"

int main(void)
{
  /* Bootsection */
  setupPWM();
  setupTime();

  /* Programmsection */
  while (1)
  {
    updatePWM(50);
    delayMilliSeconds(1000);
    updatePWM(255);
    delayMilliSeconds(1000);
  }
}