//
// Created by Evelyn Bankell on 2020-09-21.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "Definitions.h"
#include "Triangle.h"

class Ray {
public:
    Ray(const Vertex &start_point, const Vertex &end_point);
    ~Ray();

    const Vertex &getEnd() const;
    const Vertex &getStart() const;
    void setEnd(const Vertex &end);

    void setColor(const ColorDbl &color);

private:
    Vertex start, end;
    Triangle *t;
    ColorDbl color;
};


#endif //RAYTRACER_RAY_H
