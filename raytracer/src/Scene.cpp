//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include <iostream>

#include "../headers/Scene.h"

Scene::Scene() {

    //ROOF - white color
    triangleList[0] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[1] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,6.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[2] = Triangle(Vertex(5.0,0.0,5.0),Vertex(13.0,0.0,5.),Vertex(10.0,6.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[3] = Triangle(Vertex(5.0,0.0,5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[4] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,-6.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[5] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,-6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(255,255,255), LAMBERTIAN);

    // FLOOR
    triangleList[6] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);
   	triangleList[7] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);
   	triangleList[8] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[9] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[10] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);
    triangleList[11] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(255,255,255), LAMBERTIAN);

    // WALLS
    // blue color
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(0,0,255), LAMBERTIAN);
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(0.0,6.0,-5.0), ColorDbl(0,0,255), LAMBERTIAN);

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(10.0,6.0,5.0), ColorDbl(0,128,0), LAMBERTIAN);
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(10.0,6.0,-5.0), ColorDbl(0,128,0), LAMBERTIAN);

    // red
    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(128,0,0), LAMBERTIAN);
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(13.0,0.0,-5.0), ColorDbl(128,0,0), LAMBERTIAN);

    // Yellow color
    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(255, 255, 0), LAMBERTIAN);
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(255, 255, 0), LAMBERTIAN);

    // Purple color
    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(255, 0, 255), LAMBERTIAN);
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(255, 0, 255), LAMBERTIAN);

    // Light blue color
    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(0, 255, 255), LAMBERTIAN);
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(0, 255, 255), LAMBERTIAN);

    tetrahedron = Tetrahedron(ColorDbl(0,200,5), LAMBERTIAN);

    sphere = Sphere(1.5, Vertex(7,2,-2), ColorDbl(255,99,71), LAMBERTIAN);

    sphere2 = Sphere(1, Vertex(5,0,-3), ColorDbl(255,255,255), MIRROR);

    lightsource = Light();
}

bool Scene::isIntersected(Ray &r, float minDist, int depth) {

    if (depth > 5)
        return false;


    if (sphere2.rayIntersection(r,minDist))
        return true;

    if (tetrahedron.rayIntersection(r, minDist))
        return true;


    if (sphere.rayIntersection(r,minDist))
        return true;

    if(r.getRayType() != SHADOW) {


        for (int i = 0; i < 24; i++) {
            if (triangleList[i].rayIntersection(r, minDist))
                return true;
        }
    }
    return false;
}

void Scene::rayIntersection(Ray &r, int depth) {
   // r.setColor(ColorDbl(0.0f,0.0f,0.0f));
    if(depth > 5) return;

    float minDist = 1000.0f;

    tetrahedron.rayIntersection(r, minDist);
    sphere.rayIntersection(r,minDist);
    sphere2.rayIntersection(r,minDist);
    lightsource.rayIntersection(r, minDist);
    for (int i = 0; i < 24; i++) {
        triangleList[i].rayIntersection(r, minDist);
    }

    if(r.getRayType() != SHADOW) {
        switch(r.getMaterial()) {
            case MIRROR: {

                //float length_of = sqrt((r.getObjectNormal().x * r.getObjectNormal().x) + (r.getObjectNormal().y * r.getObjectNormal().y) + (r.getObjectNormal().z * r.getObjectNormal().z));
                //Direction gaga = Direction (r.getObjectNormal().x / length_of, r.getObjectNormal().y / length_of, r.getObjectNormal().z / length_of);

                //float length = sqrt((r.getDir().x * r.getDir().x) + (r.getDir().y * r.getDir().y) + (r.getDir().z * r.getDir().z));
                //Direction gago = Direction (r.getDir().x / length, r.getDir().y / length, r.getDir().z / length);


                    Direction reflected= glm::reflect(r.getDir(),r.getObjectNormal());
                    Ray reflectedRay(r.getEnd(), reflected,REFLECTION);

                    if(isIntersected(reflectedRay, minDist, depth)) {
                        r.setColor(reflectedRay.getColor());
                        std::cout << r.getColor().x;
                    }

                    break;

            }
            default: break;
        }
    }

    Vertex shadowStart = r.getEnd() + r.getObjectNormal() * 0.001f;

    Direction dir = lightsource.point - shadowStart;

    //dir = r.normalize(dir);

    float length_of_cross = sqrt((dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z));
    dir = Direction (dir.x / length_of_cross, dir.y / length_of_cross, dir.z / length_of_cross);

    Ray shadowRay = Ray(shadowStart, dir, SHADOW);

    if (isIntersected(shadowRay, minDist, depth)) {
        r.setColor(r.getColor() * 0.5f);
    }
}