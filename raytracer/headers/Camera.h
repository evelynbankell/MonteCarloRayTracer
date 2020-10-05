//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H
#include "../glm/glm.hpp"

#include "Definitions.h"
#include "Pixel.h"
#include "Scene.h"

const int SCREEN_RESOLUTION = 500;


class Camera {
public:
    Camera(int eye_perspective);
    ~Camera();

    Pixel screen[SCREEN_RESOLUTION*SCREEN_RESOLUTION];
    void render(Scene* scene);
    void createImage();

    double pixelSize = 0.0025;

private:
    const Vertex eye1 = Vertex(-1, 0, 0, 1);
    const Vertex eye2 = Vertex(-1, 0, 0, 1);

    const Vertex c1 = Vertex(0, -1, 1, 1);
    const Vertex c2 = Vertex(0, 1, 1, 1);
    const Vertex c3 = Vertex(0, -1, -1, 1);
    const Vertex c4 = Vertex(0, 1, -1, 1);

    int eye;
    int resolution;

    Vertex start;

    ColorDbl createPixel(Scene* s, Vertex position);
    double findMaxIntensity();


};

#endif //RAYTRACER_CAMERA_H
