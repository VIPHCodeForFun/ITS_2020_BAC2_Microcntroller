/*
 * ioHAL.h
 * 
 * Created: 28.06.2023 15:19:50
 *  Author: Philipp Vidmar
 */ 

#ifndef IOHAL_H_
#define IOHAL_H_

#include <stdint.h>

#include "../define/bit.h"
#include "../define/pin-define.h"

#define OUTPUT (uint8_t) 1

/**/
void setupModeIO(uint8_t pin, uint8_t mode);
/**/
void setPinsetPin(uint8_t pin);
/**/
void clearPin(uint8_t pin);


#endif /* IOHAL_H_ */