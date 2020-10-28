//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../glm/glm.hpp"
#include "Definitions.h"
#include "Triangle.h"

class Triangle;

class Ray {
public:
    Ray(Vertex _start, Direction _direction, RayType _rayType);
    ~Ray();

    Vertex getEnd();
    Vertex getStart();
    ColorDbl getColor();
    Direction getDir();
    RayType getRayType() const;
    const Direction &getObjectNormal() const;
    Direction normalize(Direction _direction);
    void setMaterial(Material _material);
    Material getMaterial();

    void setObjectNormal(const Direction &normal);
    void setEnd(Vertex end);
    void setColor(ColorDbl color);

    Direction reflectRay();

private:
    Vertex start, end;
    Direction direction;
    Direction objectNormal;
    ColorDbl color;
    Material material;
    RayType rayType;
};


#endif //RAYTRACER_RAY_H
