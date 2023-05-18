/**--- XXXXXXX p.xxx ------------------------------*/
#ifndef RP2040DEFINE_H
#define RP2040DEFINE_H
/**
 * RP2040 C bare metal
 * by Philipp Vidmar
 */

/**--- Atomic Register Access p.18 ------------------------------
 * Each peripheral register block is allocated 4kB of address space, with registers accessed using one of 4 methods,
 * selected by address decode.
 * • Addr + 0x0000 : normal read write access
 * • Addr + 0x1000 : atomic XOR on write
 * • Addr + 0x2000 : atomic bitmask set on write
 * • Addr + 0x3000 : atomic bitmask clear on write
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
// 0x02c 	GPIO_OE_XOR     GPIO output enable XOR
// 0x030 	GPIO_HI_OUT     QSPI output value
// 0x034 	GPIO_HI_OUT_SET QSPI output value set
// 0x038 	GPIO_HI_OUT_CLR QSPI output value clear
// 0x03c 	GPIO_HI_OUT_XOR QSPI output value XOR
// 0x040 	GPIO_HI_OE      QSPI output enable
// 0x044 	GPIO_HI_OE_SET  QSPI output enable set
// 0x048 	GPIO_HI_OE_CLR  QSPI output enable clear
// 0x04c 	GPIO_HI_OE_XOR  QSPI output enable XOR

/**--- System control p.74 ------------------------------
 */
#define PPB_BASE 0xe0000000                                   // Table p.77
#define SYST_CSR (volatile uint32_t *)(PPB_BASE + 0x00000010) // 0xe010 	SYST_CSR 		SysTick Control and Status Register
// 0xe014 	SYST_RVR 		SysTick Reload Value Register
// 0xe018 	SYST_CVR 		SysTick Current Value Register
// 0xe01c 	SYST_CALIB 		SysTick Calibration Value Register
// 0xe100 	NVIC_ISER 		Interrupt Set-Enable Register
// 0xe180 	NVIC_ICER 		Interrupt Clear-Enable Register
// 0xe200 	NVIC_ISPR 		Interrupt Set-Pending Register
// 0xe280 	NVIC_ICPR 		Interrupt Clear-Pending Register
// 0xe400 	NVIC_IPR0 		Interrupt Priority Register 0
// 0xe404 	NVIC_IPR1 		Interrupt Priority Register 1
// 0xe408 	NVIC_IPR2 		Interrupt Priority Register 2
// 0xe40c 	NVIC_IPR3 		Interrupt Priority Register 3
// 0xe410 	NVIC_IPR4 		Interrupt Priority Register 4
// 0xe414 	NVIC_IPR5 		Interrupt Priority Register 5
// 0xe418 	NVIC_IPR6 		Interrupt Priority Register 6
// 0xe41c 	NVIC_IPR7 		Interrupt Priority Register 7
// 0xed00 	CPUID CPUID 	Base Register
// 0xed04 	ICSR 			Interrupt Control and State Register
// 0xed08 	VTOR 			Vector Table Offset Register
// 0xed0c 	AIRCR 		    Application Interrupt and Reset Control Register
// 0xed10 	SCR 			System Control Register
// 0xed14 	CCR 			Configuration and Control Register
// 0xed1c 	SHPR2 System	Handler Priority Register 2
// 0xed20 	SHPR3 System	Handler Priority Register 3
// 0xed24 	SHCSR System	Handler Control and State Register
// 0xed90 	MPU_TYPE MPU	Type Register
// 0xed94 	MPU_CTRL MPU	Control Register
// 0xed98 	MPU_RNR MPU 	Region Number Register
// 0xed9c 	MPU_RBAR MPU	Region Base Address Register
// 0xeda0 	MPU_RASR MPU	Region Attribute and Size Register

/**--- CLOCKS p.181 ------------------------------
 */

/**--- GPIO p.235 ------------------------------
 * An IO pin can perform many different functions and must be configured before use.
 */
#define BANK_IO 0x40014000                                       // Table p.243
#define GPIO0_STATUS (volatile uint32_t *)(BANK_IO + 0x00000000) // 0x000 	GPIO0_STATUS 	GPIO status
#define GPIO0_CTRL (volatile uint32_t *)(BANK_IO + 0x00000004)   // 0x004 	GPIO0_CTRL 		GPIO control including function select and overrides.
// 0x008 	GPIO1_STATUS 	GPIO status
// 0x00c 	GPIO1_CTRL 		GPIO control including function select and overrides.
// 0x010 	GPIO2_STATUS 	GPIO status
// 0x014 	GPIO2_CTRL 		GPIO control including function select and overrides.
// 0x018 	GPIO3_STATUS 	GPIO status
// 0x01c 	GPIO3_CTRL 		GPIO control including function select and overrides.
// 0x020 	GPIO4_STATUS 	GPIO status
//... USW

/** p.247-------*/
#define GPIO_FUNC_XIP (uint32_t)0
#define GPIO_FUNC_SPI (uint32_t)1
#define GPIO_FUNC_UART (uint32_t)2
#define GPIO_FUNC_I2C (uint32_t)3
#define GPIO_FUNC_PWM (uint32_t)4
#define GPIO_FUNC_SIO (uint32_t)5
#define GPIO_FUNC_PIO0 (uint32_t)6
#define GPIO_FUNC_PIO1 (uint32_t)7
#define GPIO_FUNC_GPCK (uint32_t)8
#define GPIO_FUNC_NULL 0x0000001f // ->0001 1111
/**--- TIMER p.536 ------------------------------
 */
#define TIMER_BASE 0x40054000 // Table p.541
// 0x00 TIMEHW Write to bits 63:32 of time always write timelw before timehw
// 0x04 TIMELW Write to bits 31:0 of time writes do not get copied to time until timehw is written
#define TIMEHR (volatile uint32_t *)(TIMER_BASE + 0x00000008) // 0x08 TIMEHR Read from bits 63:32 of time always read timelr before timehr
#define TIMELR (volatile uint32_t *)(TIMER_BASE + 0x0000000c) // 0x0c TIMELR Read from bits 31:0 of time
// 0x10 ALARM0 Arm alarm 0, and configure the time it will fire. Once armed, the alarm fires when TIMER_ALARM0 == TIMELR. The alarm will disarm itself once it fires, and can be disarmed early using the ARMED status register.
// 0x14 ALARM1 Arm alarm 1, and configure the time it will fire. Once armed, the alarm fires when TIMER_ALARM1 == TIMELR. The alarm will disarm itself once it fires, and can be disarmed early using the ARMED status register.
// 0x18 ALARM2 Arm alarm 2, and configure the time it will fire. Once armed, the alarm fires when TIMER_ALARM2 == TIMELR. The alarm will disarm itself once it fires, and can be disarmed early using the ARMED status register.
// 0x1c ALARM3 Arm alarm 3, and configure the time it will fire. Once armed, the alarm fires when TIMER_ALARM3 == TIMELR. The alarm will disarm itself once it fires, and can be disarmed early using the ARMED status register.
// 0x20 ARMED Indicates the armed/disarmed status of each alarm. A write to the corresponding ALARMx register arms the alarm. Alarms automatically disarm upon firing, but writing ones here will disarm immediately without waiting to fire.
// 0x24 TIMERAWH Raw read from bits 63:32 of time (no side effects)
// 0x28 TIMERAWL Raw read from bits 31:0 of time (no side effects)
// 0x2c DBGPAUSE Set bits high to enable pause when the corresponding debug ports are active
// 0x30 PAUSE Set high to pause the timer
// 0x34 INTR Raw Interrupts
// 0x38 INTE Interrupt Enable
// 0x3c INTF Interrupt Force
// 0x40 INTS Interrupt status after masking & forcing

/**--- Watchdog p.536 ------------------------------
 */
#define WATCHDOG_BASE 0x40058000 // Table p.548
// 0x00 CTRL Watchdog control
// 0x04 LOAD Load the watchdog timer.
// 0x08 REASON Logs the reason for the last reset.
// 0x0c SCRATCH0 Scratch register
// 0x10 SCRATCH1 Scratch register
// 0x14 SCRATCH2 Scratch register
// 0x18 SCRATCH3 Scratch register
// 0x1c SCRATCH4 Scratch register
// 0x20 SCRATCH5 Scratch register
// 0x24 SCRATCH6 Scratch register
// 0x28 SCRATCH7 Scratch register
#define TICK (volatile uint32_t *)(WATCHDOG_BASE + 0x0000002c) // 0x2c TICK Controls the tick generator

#endif // RP2040DEFINE_H