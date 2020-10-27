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

    bool rayIntersection(Ray &r, double &minDist) {

        const float EPSILON = 0.0000000001;

        Vertex o, x1, x2, hit;
        Direction l;

        o = r.getStart();
        l = r.getDir();

        float a, b;
        float c, d, d1, d2, sqrten;

        a = 1;
        b = glm::dot(2.0*glm::dvec4(l.x, l.y, l.z,1), (o - center));
        c = glm::dot((o-center),(o-center)) - glm::pow(radius,2);

        if (!solveQuadratic(a, b, c, d1, d2)) return false;
        std::cout << d1 << " " << d2 << std::endl;

        if (d1 > d2) std::swap(d1, d2);

        if (d1 < EPSILON) {
            d1 = d2; // if t0 is negative, let's use t1 instead
            if (d1 < EPSILON) return false; // both t0 and t1 are negative
        }

        d = d1;

       /* d = -(b/2.0f);
         sqrten = glm::pow(d,2.0) - a*c;

        if(sqrten < EPSILON)
            return false;

        sqrten = glm::sqrt(sqrten);

        d1 = d + sqrten;
        d2 = d - sqrten;
*/


        //  the line of the ray does not intersect the sphere (missed);
        if (d < EPSILON)
            return false;


        //l = d1 * l;
        x1 = o + (double)d * glm::dvec4(l,1);
        //l = d2 * l;



        x2 = o + glm::dvec4((double)d*l.x,(double)d* l.y, (double)d*l.z,1);


        if (glm::length(x1) < glm::length(x2)) {
            hit = x1;
        }
        else {
            hit = x2;
        }



        if(glm::length(x2) < minDist) {

            std::cout << "min: " << minDist << std::endl;


            r.setColor(this->color);
            minDist = glm::length(r.getEnd()-r.getStart());
            r.setEnd(x2);
            return true;
        }

        return false;

    }
private:
    double radius;
    Vertex center;
    ColorDbl color;
};
#endif //RAYTRACER_SPHERE_H