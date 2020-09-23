//
// Created by Hannah Bergenroth on 2020-09-16.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "../glm/glm.hpp"
#include "Definitions.h"
#include "Ray.h"

class Triangle {
public:
    Triangle();
    Triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2, ColorDbl color);
    ~Triangle();

    bool rayIntersection(Ray& ray);


private:
    Vertex v0, v1, v2;
    ColorDbl color;
    Direction normal;
};


#endif //RAYTRACER_TRIANGLE_H
