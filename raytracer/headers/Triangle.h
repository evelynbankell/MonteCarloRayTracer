//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "../glm/glm.hpp"
#include "Definitions.h"
#include "Ray.h"

class Ray;

class Triangle {
public:
    Triangle();
    Triangle(Vertex v0, Vertex v1, Vertex v2, ColorDbl color);
    ~Triangle();

    const Direction &getNormal() const;
    const ColorDbl &getColor() const;

    void setColor(const ColorDbl &color);
    void setNormal();

    bool rayIntersection(Ray *ray);


private:
    Vertex v0, v1, v2;
    ColorDbl color;
    Direction normal;
};


#endif //RAYTRACER_TRIANGLE_H
