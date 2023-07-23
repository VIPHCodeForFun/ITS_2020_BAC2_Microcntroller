cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(led-with-for-delay
led-with-for-delay.c
)

pico_enable_stdio_usb(led-with-for-delay 1)
pico_enable_stdio_uart(led-with-for-delay 1)

pico_add_extra_outputs(led-with-for-delay)
target_link_libraries(led-with-for-delay pico_stdlib)
