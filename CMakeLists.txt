cmake_minimum_required(VERSION 3.15)
project(printf_new C)

set(CMAKE_C_STANDARD 99)

add_executable(printf_new ft_printf.c check.c ft_printf.h func.c cmake-build-debug/ft_itoa.c)