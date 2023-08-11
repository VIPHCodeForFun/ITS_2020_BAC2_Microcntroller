# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly

cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(main)

# Add the directory where your files are located
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(hal)
include_directories(define)
