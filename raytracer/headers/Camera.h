//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H
#include "../glm/glm.hpp"

#include "Definitions.h"
#include "Pixel.h"
#include "Scene.h"

const int SCREEN_RESOLUTION = 800;


class Camera {
public:
    Camera(int eye_perspective);
    //~Camera();

    Pixel* screen;
    void render(Scene *s);

private:
    const Vertex eye1 = Vertex(-2, 0, 0, 1);
    const Vertex eye2 = Vertex(-1, 0, 0, 1);

    int eye;
    int resolution;

    double pixelSize = 0.0025;

    Vertex start;
    ColorDbl createPixel(Pixel *p, Scene *s, Vertex position);

};

#endif //RAYTRACER_CAMERA_H
