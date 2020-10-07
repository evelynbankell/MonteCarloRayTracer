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
    Sphere(double _radius, Vertex _center, ColorDbl _color){
        radius = _radius;
        center = _center;
        color = _color;
    }

    const ColorDbl &getColor() const {
        return color;
    }

    bool rayIntersection(Ray &r, double &minDist) {

        const float EPSILON = 0.0000001;

        Vertex o, x1, x2, hit;
        Direction l;

        o = r.getStart();
        l = r.getDir();

        float a, b;
        double c, d, d1, d2, sqrt;

        a = 1;
        b = glm::dot(glm::dvec4(2.0*l,1), (o - center));
        c = glm::dot((o-center),(o-center)) - pow(radius,2);


         d = -(b/2.0);
         sqrt = glm::pow(d,2) - c;

        if(sqrt < EPSILON)
            return false;

        sqrt = glm::sqrt(sqrt);

        d1 = d + sqrt;
        d2 = d - sqrt;

        //  the line of the ray does not intersect the sphere (missed);
        if (d1 < EPSILON || d2 < EPSILON )
            return false;

        l = d1 * l;
        x1 = o + glm::dvec4(l,0);
        l = d2 * l;
        x2 = o + glm::dvec4(l,0);

        if(glm::length(x1) < glm::length(x2))
            hit = x1;
        else
            hit = x2;

        std::cout <<  hit.length() << " " << r.getStart().length() << std::endl;

        if(glm::length(hit) < minDist) {

            r.setEnd(hit);
            r.setColor(this->color);
            minDist = glm::length(r.getEnd() - r.getStart());
        }
        return true;
    }
private:
    double radius;
    Vertex center;
    ColorDbl color;
};
#endif //RAYTRACER_SPHERE_H