
#include <iostream>

#include "../headers/Camera.h"


//This is a main function
int main() {


    Camera camera(1);
    Scene scene;
    camera.render(scene);
    camera.createImage();

    return 0;
}
