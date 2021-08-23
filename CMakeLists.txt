# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(GPIO-Interrupt C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(GPIO-Interrupt example.c)

pico_set_program_name(GPIO-Interrupt "GPIO-Interrupt")
pico_set_program_version(GPIO-Interrupt "0.1")

pico_enable_stdio_uart(GPIO-Interrupt 1)
pico_enable_stdio_usb(GPIO-Interrupt 0)

# Add the standard library to the build
target_link_libraries(GPIO-Interrupt pico_stdlib)

pico_add_extra_outputs(GPIO-Interrupt)
