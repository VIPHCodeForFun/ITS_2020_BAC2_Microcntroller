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

#define RESET_ATOMIC_CLEAR (volatile uint32_t *)(RESET + ATOMIC_CLEAR)

/**--- SINGLE CYCLE IO (SIO) p.27 ------------------------------
 */
/* List of Registers  */
#define SIO_BASE 0xd0000000 // Table p.42
// 0x000 	CPUID 			Processor core identifier
// 0x004 	GPIO_IN 	    Input value for GPIO pins
// 0x008 	GPIO_HI_IN 		Input value for QSPI pins
#define GPIO_OUT (volatile uint32_t *)(SIO_BASE + 0x00000010)     // 0x010 	GPIO_OUT 		GPIO output value
#define GPIO_OUT_SET (volatile uint32_t *)(SIO_BASE + 0x00000014) // 0x014 	GPIO_OUT_SET    GPIO output value set
// 0x018 	GPIO_OUT_CLR    GPIO output value clear
// 0x01c 	GPIO_OUT_XOR    GPIO output value XOR
#define GPIO_OE (volatile uint32_t *)(SIO_BASE + 0x00000020)     // 0x020 	GPIO_OE GPIO 	output enable
#define GPIO_OE_SET (volatile uint32_t *)(SIO_BASE + 0x00000024) // 0x024 	GPIO_OE_SET     GPIO output enable set
// 0x028 	GPIO_OE_CLR     GPIO output enable clear
// 0x02c 	GPIO_OE_XOR     GPIO output enable XOR
// 0x030 	GPIO_HI_OUT     QSPI output value
// 0x034 	GPIO_HI_OUT_SET QSPI output value set
// 0x038 	GPIO_HI_OUT_CLR QSPI output value clear
// 0x03c 	GPIO_HI_OUT_XOR QSPI output value XOR
// 0x040 	GPIO_HI_OE      QSPI output enable
// 0x044 	GPIO_HI_OE_SET  QSPI output enable set
// 0x048 	GPIO_HI_OE_CLR  QSPI output enable clear
// 0x04c 	GPIO_HI_OE_XOR  QSPI output enable XOR

/**--- System control p.xxx ------------------------------*/
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

#endif // RP2040DEFINE_H