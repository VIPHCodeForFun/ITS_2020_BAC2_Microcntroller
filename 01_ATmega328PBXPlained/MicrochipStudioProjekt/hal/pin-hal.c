/*
 * ioHAL.c
 *
 * Created: 28.06.2023 15:21:48
 *  Author: Philipp Vidmar
 */ 
#include "pin-hal.h"

void setupModeIO(uint8_t pin, uint8_t mode){
	switch(mode) {
		case OUTPUT: 
			/* DDRx always 8 bit means 0-7 -> (pin % 8) */
			if (pin >= 0 && pin <= 7){ // DDRB 
				BIT_SET(DDRB, (pin % 8));	
			}else if (pin >= 8 && pin <= 15){ // DDRC 
				BIT_SET(DDRC, (pin % 8));
			}else if (pin >= 16 && pin <= 23){ // DDRD
				BIT_SET(DDRD, (pin % 8));
			}else if (pin >= 24 && pin <= 27){ // DDRE
				BIT_SET(DDRE, (pin % 8));
			}
			break;
		// case IMPUT:
		default: return;
	}
}

void setPin(uint8_t pin){
	if (pin >= 0 && pin <= 7){ 
		BIT_SET(PORTB, (pin % 8));
	}else if (pin >= 8 && pin <= 15){ 
		BIT_SET(PORTC, (pin % 8));
	}else if (pin >= 16 && pin <= 23){ 
		BIT_SET(PORTD, (pin % 8));
	}else if (pin >= 24 && pin <= 27){ 
		BIT_SET(PORTE, (pin % 8));
	}
}

void clearPin(uint8_t pin){
	if (pin >= 0 && pin <= 7){
		BIT_CLR(PORTB, (pin % 8));
		}else if (pin >= 8 && pin <= 15){
		BIT_CLR(PORTC, (pin % 8));
		}else if (pin >= 16 && pin <= 23){
		BIT_CLR(PORTD, (pin % 8));
		}else if (pin >= 24 && pin <= 27){  
		BIT_CLR(PORTE, (pin % 8));
	}			
}



