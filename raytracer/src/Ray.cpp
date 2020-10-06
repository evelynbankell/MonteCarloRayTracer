//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include "../glm/glm.hpp"
#include "../headers/Ray.h"

Ray::Ray(Vertex start_point, Direction dir ) {
    direction = dir;
    start = start_point;
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


void Ray::setEnd(Vertex _end) {
    end = _end;
}

void Ray::setColor(ColorDbl _color) {
    color = _color;
}

ColorDbl Ray::getColor() {
    return color;
}
