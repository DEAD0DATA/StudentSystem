cmake_minimum_required(VERSION 3.19)
project(StudentSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(StudentSystem src/main.c lib/cJSON.h lib/cJSON.c)