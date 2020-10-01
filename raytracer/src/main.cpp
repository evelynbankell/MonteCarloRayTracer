#include <iostream>

#include "../headers/Camera.h"

//This is a main function
int main() {


    Camera cam(1);

    Scene scene;
    Pixel *screen;

    //cam.render(&scene);

    FILE* Output = fopen("Output.ppm", "wb");

    fprintf(Output, "P6\n%i %i 255\n", SCREEN_RESOLUTION, SCREEN_RESOLUTION);

    std::cout << "Write to Output.ppm" << std::endl;

    for (int i = 0; i < SCREEN_RESOLUTION; i++) {
        for (int j = 0; j < SCREEN_RESOLUTION; j++) {

            fputc((int)(screen[j + SCREEN_RESOLUTION * i].color.x), Output);
            fputc((int)(screen[j + SCREEN_RESOLUTION * i].color.y), Output);
            fputc((int)(screen[j + SCREEN_RESOLUTION * i].color.z), Output);

        }

    }
    fclose(Output);
    std::cout << "Done!!" << std::endl;

    return 0;
}
