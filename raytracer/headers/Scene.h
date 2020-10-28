//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Ray.h"
#include "Triangle.h"
#include "Definitions.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include "Light.h"
#include <cmath>

class Scene {
public:
    Scene();
    //~Scene();
    Triangle triangleList[24];
    Tetrahedron tetrahedron;
    Sphere sphere;
    Sphere sphere2;
    Light lightsource;

    void rayIntersection(Ray &r, int depth);
    bool isIntersected(Ray &r, float minDist, int depth);

private:
    //Triangle triangleList[24];





};


#endif //RAYTRACER_SCENE_H
