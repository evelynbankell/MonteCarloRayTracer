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

    void setIntensity(float _intensity);
    float getIntensity() const;


private:
    ColorDbl color;
    float intensity = 1.0;

};


#endif //RAYTRACER_PIXEL_H
