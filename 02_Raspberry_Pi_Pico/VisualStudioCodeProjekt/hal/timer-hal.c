/*
 * timer_hal.c
 *
 * Created: 01.07.2023 17:43:40
 *  Author: Philipp Vidmar
 */

#include "timer-hal.h"

void setupTime()
{
    /* look pin-hal.c */
    BIT_SET_PTR((RESET + ATOMIC_CLEAR), TIMER);
    while (BIT_IS_SET_PTR(RESET_DONE, TIMER))
    {
    }
}

/* uint32_t to uint64_t */
uint64_t milliSeconds()
{
    /* not save ! but simple */
    uint32_t low = ((uint32_t)*TIMELR << 0);
    uint32_t high = ((uint32_t)*TIMEHR << 31);
    uint64_t microSeconds = ((uint64_t)high << 32u) | low;
    uint64_t milliSeconds = microSeconds * 0.001;
    return milliSeconds;
}

void delayMilliSeconds(uint32_t milliSecondsDelay)
{
    /* Create Timestamp */
    /* uint32_t to uint64_t */
    uint64_t timeStamp = milliSeconds() + milliSecondsDelay; // mili to micro
    while (timeStamp > milliSeconds())
    {
        // Wait till Timestamp is reached
    }
}
