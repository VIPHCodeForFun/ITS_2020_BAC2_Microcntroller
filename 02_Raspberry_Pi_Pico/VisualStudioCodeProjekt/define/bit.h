/*
 * bit.h
 * This header is used to abstract bit operations like setting and clearing bits.
 * This header is generally usable for all C programs.
 * Created: 28.06.2023 15:00:15
 * Author: Philipp Vidmar
 */

#ifndef BIT_H_
#define BIT_H_

#define BIT_SET(address, bit) (*(address) |= (1 << (bit)))
#define BIT_CLR(address, bit) (*(address) &= ~(1 << (bit)))
#define BIT_IS_SET(address, bit) (!!(*(address)) & (1 << bit))

#endif /* BIT_H_ */