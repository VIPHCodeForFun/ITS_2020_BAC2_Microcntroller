#ifndef PIN_DEFINE_H_
#define PIN_DEFINE_H_


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

#endif /* PIN_DEFINE_H_ */