/*
 * pwm_hal.h
 *
 * Created: 03.07.2023 15:27:13
 *  Author: Philipp Vidmar
 */

#ifndef PWM_HAL_H_
#define PWM_HAL_H_

#include "pin-hal.h"

/**/
void setupPWM();
/**/
void updatePWM(uint8_t value);

#endif /* PWM-HAL_H_ */