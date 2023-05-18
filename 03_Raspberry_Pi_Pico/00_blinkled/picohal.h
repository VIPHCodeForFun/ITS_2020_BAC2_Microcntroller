#ifndef PICOHAL_H
#define PICOHAL_H
/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */
#include <stdint.h> // For uintXX_t types

#include "rp2040define.h"

/* Bit Operations */
#define BIT_SET(address, bit) (*(address) |= (1 << (bit)))
#define BIT_CLR(address, bit) (*(address) &= ~(1 << (bit)))
#define BIT_IS_SET(address, bit) (!!(*(address)) & (1 << bit))

#define UINT32_T_SET(address, uint32_t) (*(address) |= uint32_t)
#define UINT32_T_CLR(address, uint32_t) (*(address) &= ~uint32_t)

/* PINS */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//... bis 29

/**Reset control.
 * If a bit is set it means the peripheral is in reset. 0 means the peripheral’s reset is deasserted.
 * Reset is done ATOMIC !
 * Register: RESET, ATOMIC_CLEAR and RESET_DONE
 */
void clearReset(uint8_t functionSelect)
{
    *RESET_ATOMIC_CLEAR = (uint32_t)(1 << functionSelect);
    while (BIT_IS_SET(RESET_DONE, functionSelect))
    { /*
     Reset done. If a bit is set then a reset done signal has been returned by the peripheral.
     This indicates that the peripheral’s registers are ready to be accessed.
      */
    }
}

/* TIMER*/

/**--- getTime p.538 ------------------------------
 * @returns time from TIMELR and TIMEHR register
 * ! not clear what timer is read
 */
uint64_t getTime()
{
    /* not save ! but simple */
    uint32_t low = ((uint32_t)*TIMELR << 0);
    uint32_t high = ((uint32_t)*TIMEHR << 31);
    return ((uint64_t)high << 32u) | low;
}

/**
 * Wait Poling for Time to went by.
 */
void waitMicrosecond(uint64_t microsecond)
{
    uint64_t waitingTime = getTime() + microsecond;
    while (getTime() < waitingTime)
    {
        // Wait til time is over
    }
}

/**--- XXXXXXX p.xxx ------------------------------*/

/**--- XXXXXXX p.xxx ------------------------------*/

/**--- XXXXXXX p.xxx ------------------------------*/

#endif // PICOHAL_H