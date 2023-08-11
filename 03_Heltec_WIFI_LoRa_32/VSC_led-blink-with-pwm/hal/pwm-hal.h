/*
 * pwm_hal.h
 *
 * Created: 03.07.2023 15:27:13
 *  Author: Philipp Vidmar
 */

#ifndef PWM_HAL_H_
#define PWM_HAL_H_

#include <stdint.h>

#include "../define/bit.h"
#include "../define/pwm-define.h"

/**/
void setupPWM();
/**/
void updatePWM(uint16_t value);

#endif /* PWM-HAL_H_ */