//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include "../glm/glm.hpp"
#include "../headers/Ray.h"

Ray::Ray(Vertex _start, Direction _direction, RayType _rayType) {
    direction = _direction;
    start = _start;
    rayType = _rayType;
}


Ray::~Ray() {
}

Vertex Ray::getStart() {
    return start;
}

Vertex Ray::getEnd() {
    return end;
}

Direction Ray::getDir() {
    return direction;
}

void Ray::setObjectNormal(const Direction &normal) {
    objectNormal = normal;
}

const Direction &Ray::getObjectNormal() const {
    return objectNormal;
}


void Ray::setEnd(Vertex _end) {
    end = _end;
}

void Ray::setColor(ColorDbl _color) {
    color = _color;
}

ColorDbl Ray::getColor() {
    return color;
}

RayType Ray::getRayType() const {
    return rayType;
}

Direction Ray::normalize(Direction _direction) {
    float length_of_cross = sqrt((_direction.x * _direction.x) + (_direction.y * _direction.y) + (_direction.z * _direction.z));
    _direction = Direction (_direction.x / length_of_cross, _direction.y / length_of_cross, _direction.z / length_of_cross);
    return _direction;
}

Direction Ray::reflectRay() {
    float length_of_cross = sqrt((direction.x * direction.x) + (direction.y * direction.y) + (direction.z * direction.z));
     Direction _direction = Direction (direction.x / length_of_cross, direction.y / length_of_cross, direction.z / length_of_cross);

    float length_of_cross2 = sqrt((objectNormal.x * objectNormal.x) + (objectNormal.y * objectNormal.y) + (objectNormal.z * objectNormal.z));
    Direction _normal = Direction (objectNormal.x / length_of_cross2, objectNormal.y / length_of_cross2, objectNormal.z / length_of_cross2);

    return  _direction - 2.f * glm::dot(_direction, _normal) * _normal;
}

void Ray::setMaterial(Material _material) {
    material = _material;
}

Material Ray::getMaterial() {
    return material;
}
