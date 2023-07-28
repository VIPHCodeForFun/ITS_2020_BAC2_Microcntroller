/*
 * ioHAL.h
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 */

#ifndef IOHAL_H_
#define IOHAL_H_

#include <stdint.h>

#include "../define/bit.h"

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

/**/
void setupModeIO(uint8_t pin, uint8_t mode);
/**/
void setPin(uint8_t pin);
/**/
void clearPin(uint8_t pin);

#endif /* IOHAL_H_ */