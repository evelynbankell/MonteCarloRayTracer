//
// Created by Evelyn Bankell on 2020-10-02.
//

#include "../headers/Light.h"

Light::Light() {
    color = ColorDbl (1, 1, 1);
    length = 1.0;

    point = Vertex (5, 0, 4.9);

    v0 = Vertex(4.5,-0.5,4.5);
    v1 = Vertex(5.5,-0.5,4.5);
    v2 = Vertex(4.5,0.5,4.5);
    v3 = Vertex(5.5,0.5,4.5);

    triangles[1] = Triangle(v1, v3, v0, color, LIGHT);
    triangles[0] = Triangle(v2, v0, v3, color, LIGHT);
}

void Light::rayIntersection(Ray &r, float &minDist) {
    for (int i = 0; i < 2; i++) {

        triangles[i].rayIntersection(r, minDist);
    }
}

const Vertex Light::getv0() const { return v0;}

const Vertex Light::getv1() const {return v1;}

const Vertex Light::getv2() const {return v2;}

const Vertex Light::getv3() const {return v3;}

const float Light::getL0() const {return L0;}

