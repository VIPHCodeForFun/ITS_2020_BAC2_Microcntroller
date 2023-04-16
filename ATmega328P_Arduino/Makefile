# Makefile for programming the ATmega328P

MCU = atmega328p

default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=$(MCU) -c -o main.o main.c
	avr-gcc -o main.bin main.o
	avr-objcopy -O ihex -R .eeprom main.bin main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clear:
	rm main.o main.bin main.hex