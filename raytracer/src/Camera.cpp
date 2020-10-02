//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include "../headers/Camera.h"


Camera::Camera(int eye_perspective) {
    eye = eye_perspective;
    resolution = SCREEN_RESOLUTION * SCREEN_RESOLUTION;
    //Vertex start;

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

Camera::~Camera() {
}

void Camera::render(Scene* s) {
    for (int y = 0; y < SCREEN_RESOLUTION; y++) {
        for (int x = 0; x < SCREEN_RESOLUTION; x++) {
            Pixel p = screen[x + SCREEN_RESOLUTION * y];

            Vertex position = Vertex(0, 1 - (x * pixelSize), 1 - (y * pixelSize), 1);
            p.color = createPixel(s, position);

            std::cout << x << " " << 1 - (x * pixelSize) << std::endl;
        }
    }
}

ColorDbl Camera::createPixel(Scene* s, Vertex position) {
    ColorDbl color = ColorDbl(0, 255, 255);

    Ray ray = Ray(start, position);

    float length_of_position = sqrt((position.x * position.x) + (position.y * position.y) + (position.z * position.z));
    Vertex normP = Vertex(position.x / length_of_position, position.y / length_of_position, position.z / length_of_position, 1);

    float length_of_start = sqrt((start.x * start.x) + (start.y * start.y) + (start.z * start.z));
    Vertex normS = Vertex(start.x / length_of_start, start.y / length_of_start, start.z / length_of_start, 1);

    Vertex norm;
    norm.x = normP.x - normS.x;
    norm.y = normP.y - normS.y;
    norm.z = normP.z - normS.z;
    norm.w = 1;

    ray.setEnd(norm);
    color = s->rayTracer(&ray);

    return color;
}

void Camera::createImage() {
        FILE* Output = fopen("Output.png", "wb");

        fprintf(Output, "P6\n%i %i 255\n", SCREEN_RESOLUTION, SCREEN_RESOLUTION);

        std::cout << "Write to Output.ppm" << std::endl;

        double factor = 255.99/findMaxIntensity();

        for (int y = 0; y < SCREEN_RESOLUTION; y++) {
            for (int x = 0; x < SCREEN_RESOLUTION; x++) {

                fputc((int)(screen[x + SCREEN_RESOLUTION * y].color.x * factor), Output);
                fputc((int)(screen[x + SCREEN_RESOLUTION * y].color.y * factor), Output);
                fputc((int)(screen[x + SCREEN_RESOLUTION * y].color.z * factor), Output);
            }
        }

        std::cout << "done" << std::endl;
        fclose(Output);
}

double Camera::findMaxIntensity() {
    double iMax = 0.0;

    for (int y = 0; y < SCREEN_RESOLUTION; y++) {
        for (int x = 0; x < SCREEN_RESOLUTION; x++) {
            Pixel* p = &screen[x + SCREEN_RESOLUTION*y];
            if (p->color.x > iMax)
                iMax = p->color.x;
            if (p->color.y > iMax)
                iMax = p->color.y;
            if (p->color.z > iMax)
                iMax = p->color.z;
        }
    }
    return iMax;
}