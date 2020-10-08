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

class Scene {
public:
    Scene();
    //~Scene();
    ColorDbl rayTracer(Ray ray);
    Triangle triangleList[24];
    Tetrahedron tetrahedron;
    Sphere sphere;
    Light lightsource;

    void rayIntersection(Ray &r);
    bool isIntersected(Ray &r);

private:
    //Triangle triangleList[24];





};


#endif //RAYTRACER_SCENE_H
