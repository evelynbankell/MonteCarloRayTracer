//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_PIXEL_H
#define RAYTRACER_PIXEL_H

#include "Definitions.h"
#include "Ray.h"

class Pixel {
public:
    Pixel();
    ~Pixel() = default;

    void setColor(ColorDbl color);
    ColorDbl getColor() { return color; }




private:
    ColorDbl color;
    float intensity;

};


#endif //RAYTRACER_PIXEL_H
