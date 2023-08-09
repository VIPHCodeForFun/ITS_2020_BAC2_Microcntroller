/*
 * bit.h
 * This header is used to abstract bit operations like setting and clearing
 * bits. This header is generally usable for all C programs. Created: 28.06.2023
 * 15:00:15 Author: Philipp Vidmar
 */

#ifndef BIT_H_
#define BIT_H_

#define BIT_SET(byte, bit) (byte |= (1 << (bit)))
#define BIT_CLR(byte, bit) (byte &= ~(1 << (bit)))
#define BIT_IS_SET(byte, bit) (!!((byte) & (1 << bit)))

#define BIT_SET_ADDRESS(address, bit) (*(address) |= (1 << (bit)))
#define BIT_CLR_ADDRESS(address, bit) (*(address) &= ~(1 << (bit)))
#define BIT_IS_SET_ADDRESS(address, bit) (!!(*(address)) & (1 << bit))

#define UINT32_T_SET(address, uint32_t) (*(address) |= uint32_t)
#define UINT32_T_CLR(address, uint32_t) (*(address) &= ~uint32_t)

#endif /* BIT_H_ */