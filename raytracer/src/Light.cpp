//
// Created by Evelyn Bankell on 2020-10-02.
//

#include "../headers/Light.h"

Light::Light() {
    color = ColorDbl (L0, L0, L0);
    length = 1.0;

    v0 = Vertex(-0.5,-0.5,2,1);
    v1 = Vertex(0.5,-0.5,2,1);
    v2 = Vertex(-0.5,0.5,2,1);
    v3 = Vertex(0.5,0.5,2,1);

    triangles[0] = Triangle(v0, v2, v1, color);
    triangles[1] = Triangle(v1, v2, v3, color);
}
