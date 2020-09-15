cmake_minimum_required(VERSION 3.15)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ./src/main.cpp ./headers/Camera.h ./src/Camera.cpp)

add_executable(raytracer ${SOURCE_FILES})

