//
// Created by Hannah Bergenroth on 2020-09-15.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H
#include "../glm/glm.hpp"


class Camera {
private:
    int num;
public:
    Camera(int n);
    int getNum();
    glm::vec3 position;
};

#endif //RAYTRACER_CAMERA_H
