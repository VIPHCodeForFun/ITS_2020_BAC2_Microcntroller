/* source: https://github.com/cpq/mdk/blob/main/esp32/mdk.h */
#ifndef PIN_DEFINE_H_
#define PIN_DEFINE_H_

#include <stdint.h>

#define BIT(x) ((uint32_t)1U << (x))
#define REG(x) ((volatile uint32_t *)(x))

// API GPIO
#define GPIO_FUNC_OUT_SEL_CFG_REG REG(0X3ff44530) // Pins 0-39
#define GPIO_FUNC_IN_SEL_CFG_REG REG(0X3ff44130)  // Pins 0-39
#define GPIO_OUT_REG REG(0X3ff44004)              // Pins 0-31
#define GPIO_IN_REG REG(0x3FF4403C)               // Pins 0-31
#define GPIO_ENABLE_REG REG(0X3ff44020)           // Pins 0-31
#define GPIO_OUT1_REG REG(0X3ff44010)             // Pins 32-39
#define GPIO_IN1_REG REG(0X3ff44040)              // Pins 32-39
#define GPIO_ENABLE1_REG REG(0X3ff4402c)          // Pins 32-39



#endif /* PIN_DEFINE_H_ */