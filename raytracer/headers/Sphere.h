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

        double a, b;
        double c, d, d1, d2, sqrten;

        a = 1;
        b = 2.0f * glm::dot(glm::dvec4((l),1), (o - center));
        c = glm::dot((o-center),(o-center)) - glm::pow(radius,2);

         d = -(b/2.0);
         sqrten = glm::pow(d,2.0) - c;

        if(sqrten < EPSILON)
            return false;

        sqrten = glm::sqrt(sqrten);

        d1 = d + sqrten;
        d2 = d - sqrten;

        //  the line of the ray does not intersect the sphere (missed);
        if (d1 < EPSILON || d2 < EPSILON )
            return false;

        //l = d1 * l;
        x1 = o + glm::dvec4(d1*l.x, d1*l.y, d1*l.z,1);
        //l = d2 * l;
        x2 = o + glm::dvec4(d2*l.x,d2* l.y, d2*l.z,1);

        if (glm::length(x1) < glm::length(x2)) {
            if ((r.getEnd() - r.getStart()).length() > x1.length())
                return false;
            hit = x1;
        }
        else {
            if ((r.getEnd() - r.getStart()).length() > x2.length())
                return false;
            hit = x2;
        }

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