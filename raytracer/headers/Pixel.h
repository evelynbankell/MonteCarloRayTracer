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
    Pixel(ColorDbl color, float intensity);
    ~Pixel() = default;

    void setColor(ColorDbl &color);
    ColorDbl color;

private:
    float intensity;

};


#endif //RAYTRACER_PIXEL_H
