//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include "../headers/Ray.h"

Ray::Ray(const Vertex start_point, const Vertex end_point ) : start(start_point), end(end_point) {}

const Vertex Ray::getStart() const {
    return start;
}

const Vertex Ray::getEnd() const {
    return end;
}

void Ray::setEnd(const Vertex end) {
    Ray::end = end;
}

void Ray::setColor(const ColorDbl color) {
    Ray::color = color;
}

const ColorDbl Ray::getColor() const {
    return color;
}
