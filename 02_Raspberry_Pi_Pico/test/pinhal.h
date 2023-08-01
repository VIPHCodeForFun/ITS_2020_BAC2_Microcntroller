#ifndef PICOHAL_H
#define PICOHAL_H
/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */
#include <stdint.h> // For uintXX_t types

#include "pinbit.h"

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
#define WDSEL (volatile uint32_t *)(RESETS_BASE + 0x00000004)      // Watchdog select.
#define RESET_DONE (volatile uint32_t *)(RESETS_BASE + 0x00000008) // Reset done.
// ATOMIC ACCSESS
#define RESET_ATOMIC_CLEAR (volatile uint32_t *)(RESET + ATOMIC_CLEAR)

// RESET Bits
#define IO_BANK0 5

/**--- SINGLE CYCLE IO (SIO) p.27 ------------------------------
 */
#define SIO_BASE 0xd0000000 // Table p.42
// 0x000 	CPUID 			Processor core identifier
// 0x004 	GPIO_IN 	    Input value for GPIO pins
// 0x008 	GPIO_HI_IN 		Input value for QSPI pins
#define GPIO_OUT (volatile uint32_t *)(SIO_BASE + 0x00000010)     // 0x010 	GPIO_OUT 		GPIO output value
#define GPIO_OUT_SET (volatile uint32_t *)(SIO_BASE + 0x00000014) // 0x014 	GPIO_OUT_SET    GPIO output value set
#define GPIO_OUT_CLR (volatile uint32_t *)(SIO_BASE + 0x00000018) // 0x018 	GPIO_OUT_CLR    GPIO output value clear
// 0x01c 	GPIO_OUT_XOR    GPIO output value XOR
#define GPIO_OE (volatile uint32_t *)(SIO_BASE + 0x00000020)     // 0x020 	GPIO_OE GPIO 	output enable
#define GPIO_OE_SET (volatile uint32_t *)(SIO_BASE + 0x00000024) // 0x024 	GPIO_OE_SET     GPIO output enable set
#define GPIO_OE_CLR (volatile uint32_t *)(SIO_BASE + 0x00000028) // 0x028 	GPIO_OE_CLR     GPIO output enable clear

#define BANK_IO 0x40014000                                       // Table p.243
#define GPIO0_STATUS (volatile uint32_t *)(BANK_IO + 0x00000000) // 0x000 	GPIO0_STATUS 	GPIO status
#define GPIO0_CTRL (volatile uint32_t *)(BANK_IO + 0x00000004)   // 0x004 	GPIO0_CTRL 		GPIO control including function select and overrides.
//... USW

/** p.247-------*/

#define GPIO_FUNC_SIO (uint32_t)5

#define GPIO_FUNC_NULL 0x0000001f // ->0001 1111

/* PINS */
#define PIN0 0

void clearReset(uint8_t functionSelect)
{
    *RESET_ATOMIC_CLEAR = (uint32_t)(1 << functionSelect);
    while (BIT_IS_SET_PTR(RESET_DONE, functionSelect))
    {
    }
}

#endif // PICOHAL_H