/*
 * ioHAL.h
 *
 * Created: 11.07.2023 16:21:37
 *  Author: Philipp Vidmar
 * source: https://github.com/cpq/mdk/blob/main/esp32/mdk.h
 */

#ifndef IOHAL_H_
#define IOHAL_H_

#include <stdint.h>

#include "../define/bit.h"
#include "../define/pin-define.h"

#define OUTPUT (uint8_t)1

/**/
void setupModeIO(uint8_t pin, uint8_t mode);
/**/
void setPin(uint8_t pin);
/**/
void clearPin(uint8_t pin);

#endif /* IOHAL_H_ */