//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include "../headers/Pixel.h"


Pixel::Pixel(const ColorDbl color, float intensity ) : color(color), intensity(intensity) {}

Pixel::Pixel() {
    color = ColorDbl (0,255,255);
}

void Pixel::setColor(const ColorDbl &color) {
    Pixel::color = color;
}