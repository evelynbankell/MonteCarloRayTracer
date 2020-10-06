//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include "../headers/Pixel.h"


Pixel::Pixel() {
    color = ColorDbl (0,0,0);
}

void Pixel::setColor(ColorDbl _color) {
    color = _color;
}