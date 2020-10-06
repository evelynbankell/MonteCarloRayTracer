cmake_minimum_required(VERSION 3.15)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(raytracer
        src/main.cpp headers/Camera.h src/Camera.cpp src/Scene.cpp headers/Scene.h src/Triangle.cpp headers/Triangle.h headers/Definitions.h src/Ray.cpp headers/Ray.h src/Pixel.cpp headers/Pixel.h headers/Tetrahedron.h src/Light.cpp headers/Light.h headers/Sphere.h)

