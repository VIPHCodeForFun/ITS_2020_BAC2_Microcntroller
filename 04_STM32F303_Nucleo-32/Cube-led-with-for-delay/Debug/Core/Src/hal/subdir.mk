################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/hal/pin-hal.c 

OBJS += \
./Core/Src/hal/pin-hal.o 

C_DEPS += \
./Core/Src/hal/pin-hal.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/hal/%.o Core/Src/hal/%.su Core/Src/hal/%.cyclo: ../Core/Src/hal/%.c Core/Src/hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-hal

clean-Core-2f-Src-2f-hal:
	-$(RM) ./Core/Src/hal/pin-hal.cyclo ./Core/Src/hal/pin-hal.d ./Core/Src/hal/pin-hal.o ./Core/Src/hal/pin-hal.su

.PHONY: clean-Core-2f-Src-2f-hal
