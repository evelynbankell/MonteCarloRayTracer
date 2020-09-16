//
// Created by Hannah Bergenroth on 2020-09-16.
//

#include "../headers/Triangle.h"

Triangle::Triangle() {}
Triangle::Triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2) : v0(v0), v1(v1), v2(v2), normal(glm::vec3(0.0,0.0,0.0)) {}
