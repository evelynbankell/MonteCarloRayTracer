//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include "../headers/Camera.h"
#include <random>


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
    std::uniform_real_distribution<float> distribution(0.0f,1.0f);
    std::random_device rd;
    std::default_random_engine generator(rd());

    float subPixelLength = pixelSize/float(subPixel);

    Vertex position;
    Vertex sub_position;

    for (int y = 0; y < 800; y++) {
        if (y % 10 == 0) std::cout << "\r" << (float)y*100.0f/float(800) << "%" << std::endl;
        for (int x = 0; x < 800; x++) {
            //std::cout << ((y*x)+800)/(800.f*800.f)*100 << "%" << std::endl;
            position = Vertex(0,  1 -x * pixelSize , 1 -y * pixelSize );
            ColorDbl sampledPixelColor = ColorDbl (0,0,0);

            //supersamplig
            for(int i = 0; i < subPixel; i++) {

                for(int j = 0; j < subPixel; j++) {
                    sub_position = position - Vertex(0,(j + distribution(generator))*subPixelLength,(i + distribution(generator))*subPixelLength);

                    Direction test;
                    test.x = sub_position.x - start.x;
                    test.y = sub_position.y - start.y;
                    test.z = sub_position.z - start.z;
                    float length_of_test = sqrt((test.x * test.x) + (test.y * test.y) + (test.z * test.z));
                    Direction testN = Direction (test.x / length_of_test, test.y / length_of_test, test.z / length_of_test);

                    Ray ray (start, testN, PRIMARY);
                    int depth = 0;
                    s.rayIntersection(ray, depth);
                    sampledPixelColor += ray.getColor();
                }
            }

            ColorDbl pixelColor = sampledPixelColor/((float)subPixel*(float)subPixel);

            screen[y][x].setColor(pixelColor);

            //std::cout << x << " " << screen[y][x].getColor().x << std::endl;
        }
    }
}

void Camera::createImage() {
        FILE* Output = fopen("Output.ppm", "wb");

        fprintf(Output, "P6\n%i %i 255\n", SCREEN_RESOLUTION, SCREEN_RESOLUTION);

        std::cout << "Write to Output.ppm" << std::endl;

        std:: cout << findMaxIntensity() << std::endl;
        double factor = 255/findMaxIntensity();
        std::cout << factor;

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