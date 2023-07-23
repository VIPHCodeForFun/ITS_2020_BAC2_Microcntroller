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

/**/
void setupModeIO(uint8_t pin, uint8_t mode);
/**/
void setPinsetPin(uint8_t pin);
/**/
void clearPin(uint8_t pin);

#endif /* IOHAL_H_ */