/*
 * pwm_hal.c
 *
 * Created: 03.07.2023 15:27:01
 *  Author: Philipp Vidmar
 */

#include "pwm-hal.h"

void setupPWM()
{
    // Clear Reset
    BIT_SET_PTR(DPORT_PERIP_CLK_EN_REG, 17); // DPORT_PWM0_CLK_EN

    // 1 Timer Configuration by specifying the PWM signal’s frequency and duty cycle resolution.

    // 2 Channel Configuration by associating it with the timer and GPIO to output the PWM signal.

    // 3 Change PWM Signal that drives the output in order to change LED’s intensity.This can be done under the full control of software or with hardware fading functions.
}

void updatePWM(uint16_t value)
{
}
