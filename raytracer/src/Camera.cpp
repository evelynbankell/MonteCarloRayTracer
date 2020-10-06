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
    //Vertex start;

    for(int i = 0; i < SCREEN_RESOLUTION; ++i)
        screen[i] = new Pixel[SCREEN_RESOLUTION];

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

void Camera::render(Scene s) {

    std::cout  << screen[0][0].getColor().x << std::endl;


    for (int y = 0; y < 800; y++) {
        for (int x = 0; x < 800; x++) {

            Vertex position = Vertex(0, 1 - x * pixelSize, 1 - y * pixelSize, 1);

            Direction test;
            test.x = position.x - start.x;
            test.y = position.y - start.y;
            test.z = position.z - start.z;
            float length_of_test = sqrt((test.x * test.x) + (test.y * test.y) + (test.z * test.z));
            Direction testN = Direction (test.x / length_of_test, test.y / length_of_test, test.z / length_of_test);


            std::cout << "x: " << test.x << " " << test.y <<  " " << test.z << std::endl;
            std::cout << testN.x << " " << testN.y <<  " " << testN.z << std::endl;
            Ray ray (start, testN);
            s.rayIntersection(ray);
            ColorDbl color = ray.getColor();
            screen[y][x].setColor(color);

            //std::cout << x << " " << screen[y][x].getColor().x << std::endl;
        }
    }
}

void Camera::createImage() {
        FILE* Output = fopen("Output1.ppm", "wb");

        fprintf(Output, "P6\n%i %i 255\n", SCREEN_RESOLUTION, SCREEN_RESOLUTION);

        std::cout << "Write to Output.ppm" << std::endl;

        double factor = 255.99/findMaxIntensity();

        for (int y = 0; y < SCREEN_RESOLUTION; y++) {
            for (int x = 0; x < SCREEN_RESOLUTION; x++) {

                fputc((int)(screen[y][x].getColor().x * factor), Output);
                fputc((int)(screen[y][x].getColor().y * factor), Output);
                fputc((int)(screen[y][x].getColor().z * factor), Output);
            }
        }

        std::cout << "done" << std::endl;
        fclose(Output);
}

double Camera::findMaxIntensity() {
    double iMax = 0.0;

    for (int y = 0; y < SCREEN_RESOLUTION; y++) {
        for (int x = 0; x < SCREEN_RESOLUTION; x++) {
            Pixel* p = &screen[y][x];
            if (p->getColor().x > iMax)
                iMax = p->getColor().x;
            if (p->getColor().y > iMax)
                iMax = p->getColor().y;
            if (p->getColor().z > iMax)
                iMax = p->getColor().z;
        }
    }
    return iMax;
}