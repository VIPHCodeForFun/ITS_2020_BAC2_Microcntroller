/*
 * timer_define.h
 *
 * Created: 03.07.2023 13:23:31
 *  Author: Philipp Vidmar
 */ 

#ifndef TIMER_DEFINE_H_
#define TIMER_DEFINE_H_

/* TC2 - 8-bit Timer/Counter2 with PWM and Asynchronous Operation p.181 */
#define TCCR2A (volatile uint8_t *) 0xB0 // p.195
#define TCCR2B (volatile uint8_t *) 0xB1 // p.198
#define TCNT2 (volatile uint8_t *) 0xB2 // p.199
#define OCR2A (volatile uint8_t *) 0xB3 // p.199
#define TIMSK2 (volatile uint8_t *) 0x70 // p.200

#endif /* TIMER-DEFINE_H_ */