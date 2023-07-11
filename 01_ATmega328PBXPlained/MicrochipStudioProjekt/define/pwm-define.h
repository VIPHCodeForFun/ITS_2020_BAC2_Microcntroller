/*
 * pwm_define.h
 *
 * Created: 03.07.2023 15:28:30
 *  Author: Philipp Vidmar
 */ 

#ifndef PWM_DEFINE_H_
#define PWM_DEFINE_H_

#define MAX 0xFF
#define BOTTOM 0x00

/* TC0 - 8-bit Timer/Counter0 with PWM p.112 */
#define TCCR0A (volatile uint8_t *) 0x44 // p.124
#define TCCR0B (volatile uint8_t *) 0x45 // p.127
#define OCR0A (volatile uint8_t *) 0x47 // p.130

#endif /* PWM-DEFINE_H_ */