//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include <iostream>
#include "../headers/Camera.h"


Camera::Camera(int eye_perspective) {
    eye = eye_perspective;
    resolution = SCREEN_RESOLUTION * SCREEN_RESOLUTION;
    //Pixel *p = screen;

    if (eye == 1) {
        start = eye1;
    } else if (eye == 2) {
        start = eye2;
    }
    else {
        std::cout << "error";
        return;
    }
}

void Camera::render(Scene *s) {
    for (int y = 0; y < SCREEN_RESOLUTION; y++) {
        for (int x = 0; x < SCREEN_RESOLUTION; x++) {
            Pixel *p = &screen[x + SCREEN_RESOLUTION * y];
            Vertex position = Vertex(0, 1 - x * pixelSize, 1 - y * pixelSize, 1);
            p->color = createPixel(p, s, position);

        }
    }
}

ColorDbl Camera::createPixel(Pixel *p, Scene *s, Vertex position) {

    ColorDbl color;

    Ray ray = Ray(start, position);
    ray.setEnd(glm::normalize(position-start));

    color = s->rayTracer(&ray);

    return color;
}

