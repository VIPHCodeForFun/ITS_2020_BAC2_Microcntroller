/*
 * pwm_hal.c
 *
 * Created: 03.07.2023 15:27:01
 *  Author: Philipp Vidmar
 */

#include "pwm-hal.h"

/* 4.5. PWM
    4.5.2.4. Clock Divider
*/
/**--- Watchdog p.536 ------------------------------
 */
#define PWM_BASE 0x40050000                                  // Table p.548
#define CH0_CSR (volatile uint32_t *)(PWM_BASE + 0x00000000) //  Control and status register
#define CH0_DIV (volatile uint32_t *)(PWM_BASE + 0x00000004) //  INT and FRAC form a fixed - point fractional number.
#define CH0_CTR (volatile uint32_t *)(PWM_BASE + 0x00000008) //  Direct access to the PWM counter
#define CH0_CC (volatile uint32_t *)(PWM_BASE + 0x0000000c)  //  Counter compare values
#define CH0_TOP (volatile uint32_t *)(PWM_BASE + 0x00000010) //  Counter wrap value

void setupPWM()
{
    /* Clear IO Reset */
    setupModeIO(0, 0);

    /* Clear Reset look pin-hal.c */
    BIT_SET_PTR((RESET + ATOMIC_CLEAR), PWM);
    while (BIT_IS_SET_PTR(RESET_DONE, PWM))
    {
    }
    /* Function Select GPIO PIN0 PWM0 A mode */
    UINT32_T_CLR(GPIO0_CTRL, 0x0000001f);  // Clear reset value null
    UINT32_T_SET(GPIO0_CTRL, (uint32_t)4); // Function select p.247

    /* Counter compare 0xffff = 65535 CHAN A[15:0] B[31:16] */
    *CH0_CC = 0x00007FFF; // 32767 = 50%

    /* set FRAC to 1*/
    UINT32_T_SET(CH0_DIV, 0x00000001);

    // CH0_TOP resetvalue = 0xffff
    BIT_IS_SET_PTR(CH0_CSR, 0); // Enable the PWM channel.
}

void updatePWM(uint16_t value)
{
    *CH0_CC = value;
}
