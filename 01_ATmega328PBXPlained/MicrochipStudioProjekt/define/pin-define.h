/*
 * pin-define.h
 * In this header file the required addresses for the microcontroller "" are abstracted in
 * macros according to the data sheet for better readability. 
 * Created: 28.06.2023 14:59:35
 *  Author: Philipp Vidmar
 */ 

#ifndef PINDEFINE_H_
#define PINDEFINE_H_

// Ports as General Digital I/O p.85
#define PORTB (volatile uint8_t *) 0x25
#define DDRB (volatile uint8_t *) 0x24 
#define PORTC (volatile uint8_t *) 0x28
#define DDRC (volatile uint8_t *) 0x27
#define PORTD (volatile uint8_t *) 0x2B
#define DDRD (volatile uint8_t *) 0x2A
#define PORTE (volatile uint8_t *) 0x2E
#define DDRE (volatile uint8_t *) 0x2D

// Alternate Port Functions p.88
#define PINB0 (volatile uint8_t) 0
#define PINB1 (volatile uint8_t) 1
#define PINB2 (volatile uint8_t) 2
#define PINB3 (volatile uint8_t) 3
#define PINB4 (volatile uint8_t) 4
#define PINB5 (volatile uint8_t) 5
#define PINB6 (volatile uint8_t) 6
#define PINB7 (volatile uint8_t) 7

#define PINC0 (volatile uint8_t) 8
#define PINC1 (volatile uint8_t) 9
#define PINC2 (volatile uint8_t) 10
#define PINC3 (volatile uint8_t) 11
#define PINC4 (volatile uint8_t) 12
#define PINC5 (volatile uint8_t) 13
#define PINC6 (volatile uint8_t) 14
#define PINC7 (volatile uint8_t) 15

#define PIND0 (volatile uint8_t) 16
#define PIND1 (volatile uint8_t) 17
#define PIND2 (volatile uint8_t) 18
#define PIND3 (volatile uint8_t) 19
#define PIND4 (volatile uint8_t) 20
#define PIND5 (volatile uint8_t) 21
#define PIND6 (volatile uint8_t) 22
#define PIND7 (volatile uint8_t) 23

#define PINE0 (volatile uint8_t) 24
#define PINE1 (volatile uint8_t) 25
#define PINE2 (volatile uint8_t) 26
#define PINE3 (volatile uint8_t) 27

#endif /* PINDEFINE_H_ */