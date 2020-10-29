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

    Tetrahedron(ColorDbl _color, Material _material ){
        Vertex v0 = Vertex(7, -2, 2); //top
        Vertex v1 = Vertex(6, -2, -1); //front
        Vertex v2 = Vertex(7, -3.0, -1); //right
        Vertex v3 = Vertex(7, -1.0, -1); //left


        triangles[0] = Triangle(v3, v1, v2, _color, _material); // under
        triangles[1] = Triangle(v0, v3, v2, _color, _material); //behind
        triangles[2] = Triangle(v2, v1, v0, _color, _material); //right
        triangles[3] = Triangle(v3, v0, v1, _color, _material); //left
    }

    Triangle triangles[4];

    bool rayIntersection(Ray &r, float &minDist) {
        bool is_hit = false;
        for (int i = 0; i < 4; i++) {
            is_hit = triangles[i].rayIntersection(r, minDist);
        }

        return is_hit;
    }
};

#endif //RAYTRACER_TETRAHEDRON_H
