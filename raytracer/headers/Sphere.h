//
// Created by Hannah Bergenroth on 2020-10-06.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Definitions.h"
#include "Ray.h"
#include <math.h>


class Sphere {
public:
    Sphere(){};
    Sphere(float _radius, Vertex _center, ColorDbl _color){
        radius = _radius;
        center = _center;
        color = _color;
    }

    const ColorDbl &getColor() const {
        return color;
    }

    //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1) {
        float discr = b * b - 4 * a * c;
        if (discr < 0) return false;
        else if (discr == 0) x0 = x1 = - 0.5 * b / a;
        else {
            float q = (b > 0) ?
                      -0.5 * (b + sqrt(discr)) :
                      -0.5 * (b - sqrt(discr));
            x0 = q / a;
            x1 = c / q;
        }
        if (x0 > x1) std::swap(x0, x1);

        return true;
    }

    bool rayIntersection(Ray &r, float &minDist) {

        const float EPSILON = 0.0000000001;

        Vertex o, x1, x2, hit;
        Direction l;

        o = r.getStart();
        l = r.getDir();

        float a, b;
        float c, d, d1, d2;

        a = 1;
        b = 2.0f * glm::dot(l, (o - center));
        c = glm::dot((o-center),(o-center)) - glm::pow(radius,2);

        d = b * b - 4.0f * a * c;

        if(d < 0) {
            return false;
        }
        else if (d < EPSILON ){
            d1 = - (b / 2.0f);
            hit = o + d1 *l;
        }
        else {
            d1 = -(b/2.0f) + sqrt(pow((b/2.0f),2) - a*c);
            d2 = -(b/2.0f) - sqrt(pow((b/2.0f),2) - a*c);

            if(d2 > 0.0f) {
                hit = o + d2*l;
            }
            else if (d1 > 0.0f){
                hit = o + d1*l;
            }
            else return false;
        }

        if(glm::length(hit-r.getStart()) < minDist) {
            minDist = glm::length(hit-r.getStart());
            std::cout << "min: " << minDist << std::endl;

            Direction norm = hit - center;

            float length_of_cross = sqrt((norm.x * norm.x) + (norm.y * norm.y) + (norm.z * norm.z));
            Direction normal = Direction (norm.x / length_of_cross, norm.y / length_of_cross, norm.z / length_of_cross);

            r.setObjectNormal(normal);

            r.setColor(getColor());
            r.setEnd(hit);

        }

        return true;

    }

private:
    float radius;
    Vertex center;
    ColorDbl color;
};
#endif //RAYTRACER_SPHERE_H