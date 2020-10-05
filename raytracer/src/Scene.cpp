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
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0), ColorDbl(255,0,0));
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(0.0,6.0,-5.0,1.0), ColorDbl(255,0,0));

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0), ColorDbl(0,128,0));
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(10.0,6.0,-5.0,1.0), ColorDbl(0,128,0));

    // Blue/navy color
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

}

Ray Scene::rayIntersection(Ray r) {
    bool is_hit = false;

    for (int i = 0; i < 24; i++) {
        if (triangleList[i].rayIntersection(&r)) {
            r.setColor(triangleList[i].getColor());
            //std::cout << r.getColor().x << " " << r.getColor().y << " " << r.getColor().z << std::endl;
            is_hit = true;
        }
    }
    return r;
}

// Determines which triangle is intersected by the ray
bool Scene::is_intersected(Ray ray) {



    if(tetrahedron.rayIntersection(ray)) {
        std::cout << "bra" << std::endl;
        ray.setColor(ColorDbl (255,255,0));
        return true;
    }

    rayIntersection(ray);

    std::cout << ray.getColor().x << " " << ray.getColor().y << " " << ray.getColor().z << std::endl;



    return false;
}

ColorDbl Scene::rayTracer(Ray ray) {

   // if(is_intersected(*ray)) {
    //    ColorDbl color = ColorDbl(0, 255, 0);
    //}

    //is_intersected(ray);
    ray = rayIntersection(ray);

    //ColorDbl color = ColorDbl(255, 0, 255);
    //ColorDbl color = ray.getColor();
    //std::cout << color.x << " " << color.y << " " << color.z << std::endl;
    std::cout << ray.getColor().x << " " << ray.getColor().y << " " << ray.getColor().z << std::endl;

    ColorDbl color = ray.getColor();

    return color;
}