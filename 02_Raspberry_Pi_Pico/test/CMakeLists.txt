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

# Tell CMake where to find the executable source file
add_executable(test # Projektname
    pinled.c     # Compilefiles
)   

# Vreate map/bin/hex/uf2 files
pico_add_extra_outputs(test) # Projektname

# link to pico_stdlib
target_link_libraries(test pico_stdlib)

pico_enable_stdio_usb(test 1)
# pico_enable_stdio_uart(test 1)



