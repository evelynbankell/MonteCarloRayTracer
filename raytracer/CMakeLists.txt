cmake_minimum_required(VERSION 3.15)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracer src/main.cpp src/Camera.cpp headers/Camera.h)