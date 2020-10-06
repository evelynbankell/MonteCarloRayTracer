//
// Created by Evelyn Bankell on 2020-10-02.
//

#ifndef RAYTRACER_TETRAHEDRON_H
#define RAYTRACER_TETRAHEDRON_H

#include "Definitions.h"
#include "Triangle.h"

class Tetrahedron {
public:
    Tetrahedron() { };

    Tetrahedron(ColorDbl color){
        Vertex v0 = Vertex(6, -2, 0, 1.0); //top
        Vertex v1 = Vertex(5, -2, -4, 1.0); //right
        Vertex v2 = Vertex(7, -4.0, -4, 1.0); //left
        Vertex v3 = Vertex(7, 0.0, -4, 1.0); //up


        triangles[0] = Triangle(v0, v3, v2, color);
        triangles[1] = Triangle(v0, v1, v3, color);
        triangles[2] = Triangle(v1, v3, v2, color);
        triangles[3] = Triangle(v1, v2, v3, color);
    }

    Triangle triangles[4];

    void rayIntersection(Ray &r, double &minDist) {
        for (int i = 0; i < 4; i++) {

            triangles[i].rayIntersection(r, minDist);
        }
    }
};

#endif //RAYTRACER_TETRAHEDRON_H
