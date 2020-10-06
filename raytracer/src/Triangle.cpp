//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include <iostream>

#include "../headers/Triangle.h"
Triangle::Triangle() {
}

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2, ColorDbl color) : v0(v0), v1(v1), v2(v2), color(color), normal(glm::vec3(0.0,0.0,0.0)) {}
Triangle::~Triangle() {
}

// Calculate intersection between a ray and triangle with the Möller-Trumbore Algorithm
bool Triangle::rayIntersection(Ray &ray) {

    const float EPSILON = 0.0000001;

    Vertex start = ray.getStart();

    Direction edge1 = v1 - v0;
    Direction edge2 = v2 - v0;

    Direction T = start - v0;

    Direction P = glm::cross(ray.getDir(), edge2);
    Direction Q = glm::cross(T, edge1);

    double a = glm::dot(edge1, P);

    // ray is parallel to this triangle
    if (a > -EPSILON && a < EPSILON)
        return false;

    double f = 1.0 / a;

    double u = f * glm::dot(T, P);
    if (u < 0.0 || u > 1.0)
        return false;

    double v = f * glm::dot(ray.getDir(), Q);
    if (v < 0.0 || u+v > 1.0)
        return false;

    double t = f * glm::dot(Q, edge2);
    if (t > EPSILON) { // ray intersection
        //calculate out intersection point
        ray.setEnd(start + glm::dvec4(ray.getDir(),1) * t); // set new end position
        ray.setColor(this->color);
        return true;
    }
    else
        return false;
}

const ColorDbl &Triangle::getColor() const {
    return color;
}

const Direction &Triangle::getNormal() const {
    return normal;
}

void Triangle::setColor(const ColorDbl &color) {
    Triangle::color = color;
}

void Triangle::setNormal() {
    Direction d1 = Triangle::v1 - Triangle::v0;
    Direction d2 = Triangle::v2 - Triangle::v0;

    Direction cross = glm::cross(d1, d2);

    float length_of_cross = sqrt((cross.x * cross.x) + (cross.y * cross.y) + (cross.z * cross.z));
    Direction normal = Direction (cross.x / length_of_cross, cross.y / length_of_cross, cross.z / length_of_cross);
    Triangle::normal = normal;
    //Sometimes not working??
    //Triangle::normal = glm::normalize(glm::cross(d1, d2));
}
