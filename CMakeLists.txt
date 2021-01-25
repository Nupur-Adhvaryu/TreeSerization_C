cmake_minimum_required(VERSION 3.16)
project(TreeSerialization C)

set(CMAKE_C_STANDARD 99)

add_executable(TreeSerialization main.c serializeDeserialize.h)