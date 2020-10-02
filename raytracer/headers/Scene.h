//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Ray.h"
#include "Triangle.h"
#include "Definitions.h"
#include "Tetrahedron.h"

class Scene {
public:
    Scene();
    //~Scene();
    bool is_intersected(Ray &ray);
    ColorDbl rayTracer(Ray *ray);
    Triangle triangleList[24];
    Tetrahedron tetrahedron;

private:
    //Triangle triangleList[24];



};


#endif //RAYTRACER_SCENE_H
