/*
 * ioHAL.h
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */

#ifndef IOHAL_H_
#define IOHAL_H_

#include <stdint.h>

#include "pinbit.h"

#define OUTPUT (uint8_t)1

#define IO_BANK0 5

/**--- Atomic Register Access p.18 ------------------------------
 * Each peripheral register block is allocated 4kB of address space, with registers accessed using one of 4 methods,
 * selected by address decode.
 */
#define NORMAL 0x00000000       // normal read write access
#define ATOMIC_XOR 0x00001000   // atomic XOR on write
#define ATOMIC_WRITE 0x00002000 // atomic bitmask set on write
#define ATOMIC_CLEAR 0x00003000 // atomic bitmask clear on write

#define RESETS_BASE 0x4000c000                                     // Table p.178
#define RESET (volatile uint32_t *)(RESETS_BASE + 0x00000000)      // Reset control.
#define RESET_DONE (volatile uint32_t *)(RESETS_BASE + 0x00000008) // Reset done.

#define BANK_IO_BASE 0x40014000                                       // Table p.243
#define GPIO0_STATUS (volatile uint32_t *)(BANK_IO_BASE + 0x00000000) // 0x000 	GPIO0_STATUS 	GPIO status
#define GPIO0_CTRL (volatile uint32_t *)(BANK_IO_BASE + 0x00000004)   // 0x004 	GPIO0_CTRL 		GPIO control including function select and overrides.
// GPIO1_STATUS...
// GPIO1_CTRL...
// ...

#define SIO_BASE 0xd0000000                                       // Table p.42
#define GPIO_OUT (volatile uint32_t *)(SIO_BASE + 0x00000010)     // 0x010 	GPIO_OUT 		GPIO output value
#define GPIO_OUT_SET (volatile uint32_t *)(SIO_BASE + 0x00000014) // 0x014 	GPIO_OUT_SET    GPIO output value set
#define GPIO_OUT_CLR (volatile uint32_t *)(SIO_BASE + 0x00000018) // 0x018 	GPIO_OUT_CLR    GPIO output value clear

#define GPIO_OE (volatile uint32_t *)(SIO_BASE + 0x00000020) // 0x020 	GPIO_OE GPIO 	output enable

#define RESET_ATOMIC_CLEAR (volatile uint32_t *)(RESET + ATOMIC_CLEAR)

void setupModeIO(uint8_t pin, uint8_t mode)
{
    *RESET_ATOMIC_CLEAR = (uint32_t)(1 << IO_BANK0);
    while (BIT_IS_SET(*RESET_DONE, IO_BANK0))
    { /*
        Reset done. If a bit is set then a reset done signal has been returned by the peripheral.
        This indicates that the peripheral’s registers are ready to be accessed.
     */
    }

    // Just works for PIN0 !
    pin = 0;

    UINT32_T_CLR(GPIO0_CTRL, 0x0000001f);  // Clear reset value null
    UINT32_T_SET(GPIO0_CTRL, (uint32_t)5); // Function select p.247

    BIT_SET(*GPIO_OE, pin); // Output enable registers 1 for drive high/low based on GPIO_OUT

    return;
}

void setPin(uint8_t pin)
{
    BIT_SET(*GPIO_OUT_SET, pin); // Perform an atomic bit-set on GPIO_OUT p.47
    return;
}

void clearPin(uint8_t pin)
{
    BIT_SET(*GPIO_OUT_CLR, pin); // Perform an atomic bit-clear on GPIO_OUT p.47
    return;
}

#endif /* IOHAL_H_ */