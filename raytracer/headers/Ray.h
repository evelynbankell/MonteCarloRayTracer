//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "Definitions.h"
#include "Triangle.h"

class Triangle;

class Ray {
public:
    Ray(const Vertex start_point, const Vertex end_point);
    //~Ray();

    const Vertex getEnd() const;
    const Vertex getStart() const;
    const ColorDbl getColor() const;

    void setEnd(const Vertex end);
    void setColor(const ColorDbl color);

private:
    Vertex start, end;
    Triangle *t;
    ColorDbl color;
};


#endif //RAYTRACER_RAY_H
