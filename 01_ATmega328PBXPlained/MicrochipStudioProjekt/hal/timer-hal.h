/*
 * timer_hal.h
 *
 * Created: 01.07.2023 17:43:10
 *  Author: Philipp Vidmar
 */ 


#ifndef TIMER_HAL_H_
#define TIMER_HAL_H_

#include <stdint.h> // uintx_t
#include <util/atomic.h>
#include <avr/interrupt.h>
#include "../define/bit.h"
#include "../define/timer-define.h"

/**/
volatile uint32_t TIME_COUNTER;
/**/
void setupTime();
/**/
uint32_t milliSeconds();
/**/
void delayMilliSeconds(uint32_t milliSekondsDelay);
/**/
ISR(TIMER2_COMPA_vect); // zusätzlich

#endif /* TIMER-HAL_H_ */