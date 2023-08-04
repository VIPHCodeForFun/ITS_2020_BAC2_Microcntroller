# Set cmake_minimum_required Version
cmake_minimum_required(VERSION 3.13)

# include Buildfunctions from Pico SDK
include(pico_sdk_import.cmake)

# Set Project name (as Project_Name) and C/C++ Stamdarts
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Create a pico-sdk subdirectory in the project for the libaries
pico_sdk_init()

# Add the directory where your files are located
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(hal)
include_directories(define)

#### led-with-for-delay ####
# Tell CMake where to find the executable source file
add_executable(led-with-for-delay
    led-with-for-delay.c 
    hal/pin-hal.c
)   

# Vreate map/bin/hex/uf2 files
pico_add_extra_outputs(led-with-for-delay)

# Link to pico_stdlib
target_link_libraries(led-with-for-delay pico_stdlib)

# Serial interface 1 = ON, 0 = OFF
pico_enable_stdio_usb(led-with-for-delay 1)
pico_enable_stdio_uart(led-with-for-delay 0)


#### led-with-timer-delay ####
# Tell CMake where to find the executable source file
add_executable(led-with-timer-delay
led-with-timer-delay.c 
    hal/pin-hal.c
    hal/timer-hal.c
)   

# Vreate map/bin/hex/uf2 files
pico_add_extra_outputs(led-with-timer-delay)

# Link to pico_stdlib
target_link_libraries(led-with-timer-delay pico_stdlib)

# Serial interface 1 = ON, 0 = OFF
pico_enable_stdio_usb(led-with-timer-delay 1)
pico_enable_stdio_uart(led-with-for-delay 0)


#### led-blink-with-pwm ####
# Tell CMake where to find the executable source file
add_executable(led-blink-with-pwm
    led-blink-with-pwm.c 
    hal/pin-hal.c
    hal/timer-hal.c
    hal/pwm-hal.c
)   

# Vreate map/bin/hex/uf2 files
pico_add_extra_outputs(led-blink-with-pwm)

# Link to pico_stdlib
target_link_libraries(led-blink-with-pwm pico_stdlib)

# Serial interface 1 = ON, 0 = OFF
pico_enable_stdio_usb(led-blink-with-pwm 1)
pico_enable_stdio_uart(led-with-for-delay 0)



