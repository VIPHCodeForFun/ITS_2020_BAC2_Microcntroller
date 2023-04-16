/*
 * Documentation: https://www.st.com/en/evaluation-tools/nucleo-f303k8.html#documentation
 * Pinout: https://os.mbed.com/platforms/ST-Nucleo-F303K8/
 */

#include <stdint.h>

/*-- GPIO Addressing p.237 --*/
// GPIOA p.57 0x4800 0000 - 0x4800 03FF 1 K
#define GPIOA_BASE 0x48000000UL
// MODER;        !< GPIO port mode register,               Address offset: 0x00
#define GPIOA_MODER (*((volatile uint32_t *)(GPIOA_BASE + 0x00000000)))
// OTYPER;       !< GPIO port output type register,        Address offset: 0x04
// OSPEEDR;      !< GPIO port output speed register,       Address offset: 0x08
// PUPDR;        !< GPIO port pull-up/pull-down register,  Address offset: 0x0C
// IDR;          !< GPIO port input data register,         Address offset: 0x10
// ODR;          !< GPIO port output data register,        Address offset: 0x14
#define GPIOA_ODR (*((volatile uint32_t *)(GPIOA_BASE + 0x00000014)))
// BSRR;         !< GPIO port bit set/reset register,      Address offset: 0x1A
// LCKR;         !< GPIO port configuration lock register, Address offset: 0x1C
// AFR[2];       !< GPIO alternate function registers,     Address offset: 0x20-0x24
// BRR;          !< GPIO bit reset register,               Address offset: 0x28

int main(void)
{
    /*-- Setup --*/
    // Clear Moder - A0-A15 to 0 (input mode)
    GPIOA_MODER = 0x00000000;
    // set Pin 5 (p.237 MODER4[1:0]) to Output (01)
    GPIOA_MODER = GPIOA_MODER | (1 << 8);

    // Clear GPIOA_ODR p.239
    GPIOA_ODR = 0x00000000;

    while (1)
    {
        // Set Pin 5 to HIGH
        GPIOA_ODR |= (1 << 5);
    }
    return 0;
}
