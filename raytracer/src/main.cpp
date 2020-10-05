
#include <iostream>

#include "../headers/Camera.h"


//This is a main function
int main() {

    Scene scene;
    Camera camera(1);
    camera.render(&scene);
    camera.createImage();

    return 0;
}
