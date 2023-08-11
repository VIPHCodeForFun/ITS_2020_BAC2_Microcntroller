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
}

void updatePWM(uint16_t value)
{
}
