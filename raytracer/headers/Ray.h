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
    Ray(Vertex start_point, Direction dir);


    ~Ray();

    Vertex getEnd();
    Vertex getStart();
    ColorDbl getColor();
    Direction getDir();

    void setEnd(Vertex end);
    void setColor(ColorDbl color);

private:
    Vertex start, end;
    Direction direction;
    ColorDbl color;
};


#endif //RAYTRACER_RAY_H
