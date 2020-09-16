cmake_minimum_required(VERSION 3.15)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ./src/main.cpp ./headers/Camera.h ./src/Camera.cpp src/Scene.cpp headers/Scene.h src/Triangle.cpp headers/Triangle.h src/Vertex.cpp headers/Vertex.h src/Direction.cpp headers/Direction.h src/ColorDbl.cpp headers/ColorDbl.h)

add_executable(raytracer ${SOURCE_FILES})

