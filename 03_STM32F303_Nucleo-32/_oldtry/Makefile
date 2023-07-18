# hir könnte ihr Make stehen


default:
	arm-none-eabi-gcc -mcpu=cortex-m4 main.c -c
	arm-none-eabi-objdump -h main.o
	arm-none-eabi-gcc -T link.ld -nostdlib main.o -o firmware.elf
	arm-none-eabi-objdump -h firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin
	st-flash --reset write firmware.bin 0x8000000

clear:
	rm main.o firmware.bin firmware.elf
	