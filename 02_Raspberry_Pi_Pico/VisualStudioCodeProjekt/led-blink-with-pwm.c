/*
 * led_blink_with_pwm.c
 *
 * Created: 03.07.2023 15:22:48
 *  Author: Philipp Vidmar
 */

#include "hal/timer-hal.h"
#include "hal/pwm-hal.h"

int main(void)
{
	/* Boot section */
	setupPWM();
	setupTime();

	/* Program section */
	while (1)
	{
		updatePWM(32767); // 50 %
		delayMilliSeconds(1000);
		updatePWM(65535); // 100 %
		delayMilliSeconds(1000);
	}
}