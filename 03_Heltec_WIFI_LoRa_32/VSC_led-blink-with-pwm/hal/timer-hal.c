/*
 * timer_hal.c
 *
 * Created: 01.07.2023 17:43:40
 *  Author: Philipp Vidmar
 */

#include "timer-hal.h"

void setupTime()
{
    /* 16 BIT PRESCALER
    1 mikroSek = 0,000 001 sek => 1 000 000 Hz
    (APB_CLK, normally 80 MHz) p.503
    80 000 000 Hz / 8 000 000 Hz = 80 (16bit Prescaler 2 to 65536) */
    // Clear Reset 0x00001 in REG TIMGn_Tx_DIVIDER [28-13]
    BIT_CLR_PTR(TIMG0_T0CONFIG_REG, 13);
    // Set 80 dez = 0000 0000 0101 0000 bin
    BIT_SET_PTR(TIMG0_T0CONFIG_REG, 17);
    BIT_SET_PTR(TIMG0_T0CONFIG_REG, 19);

    BIT_SET_PTR(TIMG0_T0CONFIG_REG, 30); // [30] TIMG0_T0CONFIG_REG
    BIT_SET_PTR(TIMG0_T0CONFIG_REG, 31); // [31] TIMGn_Tx_EN
}

uint32_t milliSeconds()
{
    BIT_SET_PTR(TIMG0_T0UPDATE_REG, 0);
    uint32_t low = (*TIMG0_T0LO_REG << 0);
    uint32_t high = (*TIMG0_T0HI_REG << 31);
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
