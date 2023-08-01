/*
 * timer_hal.h
 *
 * Created: 01.07.2023 17:43:10
 *  Author: Philipp Vidmar
 */

#ifndef TIMER_HAL_H_
#define TIMER_HAL_H_

#include <stdint.h> // uintx_t

#include "../define/bit.h"
#include "../define/reset.h"
#include "../define/timer-define.h"

/**/
void setupTime();
/**/
uint64_t milliSeconds();
/**/
void delayMilliSeconds(uint32_t milliSekondsDelay);

#endif /* TIMER-HAL_H_ */