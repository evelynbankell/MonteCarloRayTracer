//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#include "../headers/Scene.h"

Scene::Scene() {

    //FLOOR - white color
    triangleList[0] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[1] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[2] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[3] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[4] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0), ColorDbl(255,255,255));
    triangleList[5] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0), ColorDbl(255,255,255));

    //ROOF - white color
    triangleList[6] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[7] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[8] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[9] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[10] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0), ColorDbl(255,255,255));
    triangleList[11] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0), ColorDbl(255,255,255));

    //WALLS
    // Red color
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0), ColorDbl(255,0,0));
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(0.0,6.0,-5.0,1.0), ColorDbl(255,0,0));

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0), ColorDbl(0,128,0));
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(10.0,6.0,-5.0,1.0), ColorDbl(0,128,0));

    // Blue/navy color
    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0), ColorDbl(0,0,128));
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(13.0,0.0,-5.0,1.0), ColorDbl(0,0,128));

    // Yellow color
    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0), ColorDbl(255, 255, 0));
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0), ColorDbl(255, 255, 0));

    // Purple color
    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0), ColorDbl(255, 0, 255));
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0), ColorDbl(255, 0, 255));

    // Light blue color
    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0), ColorDbl(0, 255, 255));
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0), ColorDbl(0, 255, 255));
}


// Determines which triangle is intersected by the ray
// Not sure if this is working ...
bool Scene::is_intersected(Ray &ray) {
    return true;
    //(*it)->Triangle::rayIntersection(&ray);

}

ColorDbl Scene::rayTracer(Ray *ray) {

    ColorDbl color = ColorDbl(0, 255, 255);

    return color;
}