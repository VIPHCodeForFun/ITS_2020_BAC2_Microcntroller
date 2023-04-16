/*
 * arm-none-eabi-gcc -mcpu=cortex-m4 main.c -c
 * arm-none-eabi-objdump -h main.o
 * arm-none-eabi-gcc -T link.ld -nostdlib main.o -o firmware.elf
 * arm-none-eabi-objdump -h firmware.elf
 * arm-none-eabi-objcopy -O binary firmware.elf firmware.bin
 * st-flash --reset write firmware.bin 0x8000000
 */

#include <stdint.h>

/*-- GPIO Addressing p.237 --*/
// GPIOA p.57 0x4800 0000 - 0x4800 03FF 1 K
#define GPIOA_BASE 0x48000000UL
// MODER;        !< GPIO port mode register,               Address offset: 0x00
#define GPIOA_MODER (*((volatile uint32_t *)(GPIOA_BASE + 0x00000000)))
// OTYPER;       !< GPIO port output type register,        Address offset: 0x
// OSPEEDR;      !< GPIO port output speed register,       Address offset: 0x
// PUPDR;        !< GPIO port pull-up/pull-down register,  Address offset: 0x
// IDR;          !< GPIO port input data register,         Address offset: 0x
// ODR;          !< GPIO port output data register,        Address offset: 0x14
#define GPIOA_ODR (*((volatile uint32_t *)(GPIOA_BASE + 0x00000014)))
// BSRR;         !< GPIO port bit set/reset register,      Address offset: 0x18
#define GPIOA_BSRR (*((volatile uint32_t *)(GPIOA_BASE + 0x00000018)))
// LCKR;         !< GPIO port configuration lock register, Address offset: 0x
// AFR[2];       !< GPIO alternate function registers,     Address offset: 0x
// BRR;          !< GPIO bit reset register,               Address offset: 0

int main(void)
{
    /*-- Setup --*/
    // Clear Moder - A0-A15 to 0 (input mode)
    GPIOA_MODER = 0x00000000;

    // set PA1 (Pin 1) (p.237 MODER4[1:0]) to Output (01)
    GPIOA_MODER = GPIOA_MODER | (1 << 0);
    GPIOA_MODER = GPIOA_MODER | (1 << 2);
    GPIOA_MODER = GPIOA_MODER | (1 << 4);
    GPIOA_MODER = GPIOA_MODER | (1 << 6);

    // Clear GPIOA_ODR p.239
    // GPIOA_ODR = 0x00000000;

    while (1)
    {
        // Set PA1 to HIGH
        GPIOA_BSRR |= (1 << 0);
        GPIOA_BSRR |= (1 << 1);
        GPIOA_BSRR |= (1 << 2);
        GPIOA_BSRR |= (1 << 3);
    }
    return 0;
}

// Startup code
__attribute__((naked, noreturn)) void _reset(void)
{
    // memset .bss to zero, and copy .data section to RAM region
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *src = &_sbss; src < &_ebss; src++)
        *src = 0;
    for (long *src = &_sdata, *dst = &_sidata; src < &_edata;)
        *src++ = *dst++;

    main(); // Call main()
    for (;;)
        (void)0; // Infinite loop in the case if main() returns
}

extern void _estack(void); // Defined in link.ld

// 16 standard and 80 (p.289) STM32-specific handlers
__attribute__((section(".vectors"))) void (*tab[16 + 80])(void) = {_estack,
                                                                   _reset};