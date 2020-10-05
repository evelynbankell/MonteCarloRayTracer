//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include "../glm/glm.hpp"
#include "../headers/Ray.h"

Ray::Ray(Vertex start_point, Vertex end_point ) {
    end = end_point;
    start = start_point;
    //color = ColorDbl (255, 0, 0);
}


Ray::~Ray() {
}

Vertex Ray::getStart() {
    return start;
}

Vertex Ray::getEnd() {
    return end;
}

void Ray::setEnd(Vertex end) {
    Ray::end = end;
}

void Ray::setColor(ColorDbl color) {
    Ray::color = color;
}

ColorDbl Ray::getColor() {
    return color;
}
