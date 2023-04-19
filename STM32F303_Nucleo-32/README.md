# Code läuft unter CubeIDE

# Fehler in der Toolchain auf dem Rasp

arm-none-eabi-objcopy -O binary firmware.elf firmware.bin
st-flash --reset write firmware.bin 0x8000000
st-flash 1.6.1
2023-04-19T21:33:03 WARN common.c: unknown chip id! 0x374b
Failed to connect to target
make: *** [Makefile:10: default] Fehler 255