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
    Triangle(Vertex _v0, Vertex _v1, Vertex _v2, ColorDbl _color, Material _material);
    ~Triangle();

    const Direction &getNormal() const;
    const ColorDbl &getColor() const;

    void setColor(const ColorDbl &color);
    void setNormal();
    void setNormal(Direction _normal);

    bool rayIntersection(Ray &ray, float &minDist);

    const Material getMaterial() const;

private:
    Vertex v0, v1, v2;
    ColorDbl color;
    Direction normal;
    Material material;
};


#endif //RAYTRACER_TRIANGLE_H
