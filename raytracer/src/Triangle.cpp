//
// Created by Hannah Bergenroth on 2020-09-16.
//

#include "../headers/Triangle.h"

Triangle::Triangle() {}
Triangle::Triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2, ColorDbl color) : v0(v0), v1(v1), v2(v2), color(color), normal(glm::vec3(0.0,0.0,0.0)) {}


// Calculate intersection between a ray and triangle with the Möller-Trumbore Algorithm
bool Triangle::rayIntersection(Ray& ray) {

    const float EPSILON = 0.0000001;

    Vertex start = ray.getStart();
    Vertex end = ray.getEnd();

    Direction edge1 = v1 - v0;
    Direction edge2 = v2 - v0;

    Direction T = start - v0;
    Direction D = end - start;

    Direction P = glm::cross(D, edge2);
    Direction Q = glm::cross(T, edge1);

    float a = glm::dot(edge1, P);

    // ray is parallel to this triangle
    if (a > -EPSILON && a < EPSILON)
        return false;

    float f = 1.0 / a;

    float u = f * glm::dot(T, P);
    if (u < 0.0 || u > 1.0)
        return false;

    float v = f * glm::dot(D, Q);
    if (v < 0.0 || v > 1.0)
        return false;

    double t = f * glm::dot(Q, edge2);
    if (t > EPSILON) { // ray intersection
        //calculate out intersection point
        Vertex outIntersectionPoint = start + t * Vertex(D,0);
        ray.setEnd(outIntersectionPoint); // set new end position
        ray.setColor(this->color);
        return true;
    }
    else
        return false;
}
