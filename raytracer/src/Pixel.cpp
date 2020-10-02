//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include "../headers/Pixel.h"


Pixel::Pixel(ColorDbl color, float intensity ) : color(color), intensity(intensity) {}

Pixel::Pixel() {
    color = ColorDbl (0,255,255);
    intensity = 1;
}

void Pixel::setColor(ColorDbl &color) {
    Pixel::color = color;
}