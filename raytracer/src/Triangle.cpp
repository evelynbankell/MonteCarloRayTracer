//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include <iostream>

#include "../headers/Triangle.h"
Triangle::Triangle() {
}

Triangle::Triangle(Vertex _v0, Vertex _v1, Vertex _v2, ColorDbl _color, Material _material) : v0(_v0), v1(_v1), v2(_v2), color(_color), material(_material) {
    Direction d1 = v2 - v0;
    Direction d2 = v1 - v0;

    Direction cross = glm::cross(d1, d2);

    float length_of_cross = sqrt((cross.x * cross.x) + (cross.y * cross.y) + (cross.z * cross.z));
    setNormal(Direction (cross.x / length_of_cross, cross.y / length_of_cross, cross.z / length_of_cross));

}
Triangle::~Triangle() {
}

// Calculate intersection between a ray and triangle with the Möller-Trumbore Algorithm
bool Triangle::rayIntersection(Ray &ray, float &minDist) {

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

    float u = f * glm::dot(T, P);
    if (u < 0.0 || u > 1.0)
        return false;

    float v = f * glm::dot(ray.getDir(), Q);
    if (v < 0.0 || u+v > 1.0)
        return false;

    float t = f * glm::dot(Q, edge2);

    if (t > EPSILON) { // ray intersection
        if(glm::length(Vertex(ray.getStart() + ray.getDir() * t))< minDist) {
            //calculate out intersection point
            ray.setObjectNormal(getNormal());
            ray.setEnd(ray.getStart() + ray.getDir()*t + getNormal()*0.001f); // set new end position
            ray.setColor(getColor());
            minDist = glm::length(ray.getEnd()-ray.getStart());
            ray.setMaterial(getMaterial());
           // std::cout << ray.getColor().x << std::endl;

        }
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

void Triangle::setNormal(Direction _normal) {
    normal = _normal;
}

const Material Triangle::getMaterial() const {
    return material;
}
