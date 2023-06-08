cmake_minimum_required(VERSION 3.24)
project(EDA2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(EDA2
        main.c
        main.h users.c menu.c)
