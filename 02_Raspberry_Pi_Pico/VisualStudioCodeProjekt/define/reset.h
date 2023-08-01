#ifndef RESET_H_
#define RESET_H_

/**--- Atomic Register Access p.18 ------------------------------
 * Each peripheral register block is allocated 4kB of address space, with registers accessed using one of 4 methods,
 * selected by address decode.
 */
#define NORMAL 0x00000000       // normal read write access
#define ATOMIC_XOR 0x00001000   // atomic XOR on write
#define ATOMIC_WRITE 0x00002000 // atomic bitmask set on write
#define ATOMIC_CLEAR 0x00003000 // atomic bitmask clear on write

/**--- RESET REGISTERS registers p.175 ------------------------------
 * Every peripheral reset by the reset controller is held in reset at power-up.
 * It is up to software to deassert the reset of peripherals it intends to use.
 * !!! Atomic Register Access !!!
 *      Addr + ATOMIC_OFFSET
 */
#define RESETS_BASE 0x4000c000                                     // Table p.178
#define RESET (volatile uint32_t *)(RESETS_BASE + 0x00000000)      // Reset control.
#define WDSEL (volatile uint32_t *)(RESETS_BASE + 0x00000004)      // Watchdog select.
#define RESET_DONE (volatile uint32_t *)(RESETS_BASE + 0x00000008) // Reset done.
// ATOMIC ACCSESS
#define RESET_ATOMIC_CLEAR (volatile uint32_t *)(RESET + ATOMIC_CLEAR)
// RESET Bits
#define USBCTRL 24
#define UART1 23
#define UART0 22
#define TIMER 21
#define TBMAN 20
#define SYSINFO 19
#define SYSCFG 18
#define SPI1 17
#define SPI0 16
#define RTC1 15
#define PWM 14
#define PLL_USB 13
#define PLL_SYS 12
#define PIO1 11
#define PIO0 10
#define PADS_QSPI 9
#define PADS_BANK0 8
#define JTAG 7
#define IO_QSPI 6
#define IO_BANK0 5
#define I2C1 4
#define I2C0 3
#define DMA 2
#define BUSCTRL 1
#define ADC 0

#endif /* RESET_H_ */