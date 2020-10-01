//
// Created by Hannah Bergenroth on 2020-09-16.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Ray.h"
#include "Triangle.h"

class Scene {
public:
    Scene();
    //~Scene();
    bool is_intersected(Ray &ray);
    ColorDbl rayTracer(Ray *ray);

private:
    Triangle triangleList[24];


};


#endif //RAYTRACER_SCENE_H
