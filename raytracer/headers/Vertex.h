//
// Created by Hannah Bergenroth on 2020-09-16.
//

#ifndef RAYTRACER_VERTEX_H
#define RAYTRACER_VERTEX_H
#include "../glm/glm.hpp"

class Vertex {
public:
    Vertex(const double &x, const double &y, const double &z);
    ~Vertex();
private:
    glm::vec3 cord;
    double w;
};

#endif //RAYTRACER_VERTEX_H
