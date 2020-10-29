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
        Vertex v0 = Vertex(8, -1, 3); //top
        Vertex v1 = Vertex(7, -1, -1); //right
        Vertex v2 = Vertex(8, -2.0, -1); //left
        Vertex v3 = Vertex(8, 0.0, -1); //up


        triangles[0] = Triangle(v0, v1, v2, _color, _material);
        triangles[1] = Triangle(v0, v3, v1, _color, _material);
        triangles[2] = Triangle(v0, v2, v3, _color, _material);
        triangles[3] = Triangle(v1, v3, v2, _color, _material);
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
