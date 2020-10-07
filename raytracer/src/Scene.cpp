//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include <iostream>

#include "../headers/Scene.h"

Scene::Scene() {

    //ROOF - white color
    triangleList[0] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[1] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[2] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[3] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[4] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[5] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0), ColorDbl(255,255,255));

    // FLOOR
    triangleList[6] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0), ColorDbl(255,255,255));
   	triangleList[7] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0), ColorDbl(255,255,255));
   	triangleList[8] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[9] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[10] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[11] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0), ColorDbl(255,255,255));

    // WALLS
    // red color
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0), ColorDbl(0,0,255));
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(0.0,6.0,-5.0,1.0), ColorDbl(0,0,255));

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0), ColorDbl(0,128,0));
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(10.0,6.0,-5.0,1.0), ColorDbl(0,128,0));

    // red
    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0), ColorDbl(128,0,0));
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(13.0,0.0,-5.0,1.0), ColorDbl(128,0,0));

    // Yellow color
    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0), ColorDbl(255, 255, 0));
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0), ColorDbl(255, 255, 0));

    // Purple color
    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0), ColorDbl(255, 0, 255));
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0), ColorDbl(255, 0, 255));

    // Light blue color
    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0), ColorDbl(0, 255, 255));
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0), ColorDbl(0, 255, 255));

    tetrahedron = Tetrahedron(ColorDbl(0,0,0));

    sphere = Sphere(2.0, Vertex(11,0,0,1), ColorDbl(255,99,71));

    lightsource = Light();
}

void Scene::rayIntersection(Ray &r) {
    double minDist = 1000;

    tetrahedron.rayIntersection(r, minDist);

    sphere.rayIntersection(r,minDist);

    for (int i = 0; i < 24; i++) {
        triangleList[i].rayIntersection(r, minDist);
    }

    lightsource.rayIntersection(r, minDist);


}