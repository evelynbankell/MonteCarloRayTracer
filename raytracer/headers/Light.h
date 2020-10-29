//
// Created by Evelyn Bankell on 2020-10-02.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Definitions.h"
#include "Triangle.h"

class Light {
public:
    Light();

    void rayIntersection(Ray &ray, float &minDist);

    Vertex point;
    Direction getNormal(Vertex p) { return normal; };
    const Vertex getv0() const;
    const Vertex getv1() const;
    const Vertex getv2() const;
    const Vertex getv3() const;
    const float getL0() const;

private:
    double length;
    ColorDbl color;
    float L0 = 255;

    Direction normal;
    Vertex v0, v1, v2, v3;
    Triangle triangles[2];
    Material material;
};


#endif //RAYTRACER_LIGHT_H
