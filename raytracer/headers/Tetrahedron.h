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
        Vertex v0 = Vertex(1.0, 1.0, 1.0, 1.0); //top
        Vertex v1 = Vertex(0.0, 0.0, 0.0, 1.0);
        Vertex v2 = Vertex(2.0, 0.0, 0.0, 1.0);
        Vertex v3 = Vertex(1.0, 2.0, 0.0, 1.0);

        Triangle triangles[4];
        triangles[0] = Triangle(v0, v1, v2, color);
        triangles[1] = Triangle(v0, v2, v3, color);
        triangles[2] = Triangle(v0, v3, v1, color);
        triangles[3] = Triangle(v1, v3, v2, color);
    }

    Triangle triangles[4];

    bool rayIntersection(Ray r) {
        bool is_hit = false;

        for (int i = 0; i < 4; i++) {
            if (triangles[i].rayIntersection(&r)) {
                is_hit = true;
            }
        }
        return is_hit;
    }

private:
};

#endif //RAYTRACER_TETRAHEDRON_H
