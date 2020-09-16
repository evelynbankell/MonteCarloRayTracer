//
// Created by Hannah Bergenroth on 2020-09-16.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "Triangle.h"

class Scene {
public:
    Scene();
    ~Scene();
private:
    Triangle triangleList[24];
};


#endif //RAYTRACER_SCENE_H
