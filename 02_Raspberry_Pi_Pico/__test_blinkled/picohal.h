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
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15
#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23
#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31

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

/* TIMER */

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