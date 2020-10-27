//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include <iostream>

#include "../headers/Scene.h"

Scene::Scene() {

    //ROOF - white color
    triangleList[0] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(255,255,255));
    triangleList[1] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,6.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(255,255,255));
    triangleList[2] = Triangle(Vertex(5.0,0.0,5.0),Vertex(13.0,0.0,5.),Vertex(10.0,6.0,5.0), ColorDbl(255,255,255));
    triangleList[3] = Triangle(Vertex(5.0,0.0,5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(255,255,255));
    triangleList[4] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,-6.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(255,255,255));
    triangleList[5] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,-6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(255,255,255));

    // FLOOR
    triangleList[6] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,-5.0), ColorDbl(255,255,255));
   	triangleList[7] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,-5.0), ColorDbl(255,255,255));
   	triangleList[8] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,-5.0), ColorDbl(255,255,255));
    triangleList[9] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(255,255,255));
    triangleList[10] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(255,255,255));
    triangleList[11] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(255,255,255));

    // WALLS
    // red color
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(0,0,255));
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(0.0,6.0,-5.0), ColorDbl(0,0,255));

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(10.0,6.0,5.0), ColorDbl(0,128,0));
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(10.0,6.0,-5.0), ColorDbl(0,128,0));

    // red
    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(128,0,0));
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(13.0,0.0,-5.0), ColorDbl(128,0,0));

    // Yellow color
    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(255, 255, 0));
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(255, 255, 0));

    // Purple color
    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(255, 0, 255));
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(255, 0, 255));

    // Light blue color
    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(0, 255, 255));
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(0, 255, 255));

    tetrahedron = Tetrahedron(ColorDbl(0,200,5));

    sphere = Sphere(1.5, Vertex(7,2,-2), ColorDbl(255,99,71));

    lightsource = Light();
}

bool Scene::isIntersected(Ray &r, float minDist, int depth) {

    if (depth > 5)
        return false;

    if (sphere.rayIntersection(r,minDist))
        return true;

    if (tetrahedron.rayIntersection(r, minDist))
        return true;

    for (int i = 0; i < 24; i++) {
       // if (triangleList[i].rayIntersection(r, minDist))
         //   return true;
    }


    return false;
}

void Scene::rayIntersection(Ray &r, int depth) {
    r.setColor(ColorDbl(0.0f,0.0f,0.0f));
    float minDist = 1000.0f;

    tetrahedron.rayIntersection(r, minDist);

    sphere.rayIntersection(r,minDist);

    for (int i = 0; i < 24; i++) {
        triangleList[i].rayIntersection(r, minDist);
    }

    lightsource.rayIntersection(r, minDist);

    Vertex shadowStart = r.getEnd() + r.getObjectNormal() * 0.001f;

    //Direction dir = glm::dvec3(-lightsource.point.x, lightsource.point.y, lightsource.point.z);
    Direction dir = lightsource.point - shadowStart;


    float length_of_cross = sqrt((dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z));
    dir = Direction (dir.x / length_of_cross, dir.y / length_of_cross, dir.z / length_of_cross);


    Ray shadowRay = Ray(shadowStart, dir);

    if (isIntersected(shadowRay, minDist, depth)) {
        r.setColor(r.getColor() * 0.5f);
       // std::cout << r.getColor().x << std::endl;
    }

   /* if ((glm::length(shadowRay.getEnd() - shadowStart) - (glm::length(lightsource.point - shadowStart)) < DBL_EPSILON)) {

    }
    */

}