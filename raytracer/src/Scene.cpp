//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include <iostream>
#include <random>
#include <cmath>

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

    //Lamp
    //triangleList[24] = Triangle(Vertex(5.5,-1.5,4), Vertex(4.5,1.5,4), Vertex(5.5,-1.5,4), ColorDbl(0,0,0), LIGHT);
    //triangleList[25] = Triangle(Vertex(5.5,-1.5,4), Vertex(4.5,1.5,4), Vertex(5.5,1.5,4), ColorDbl(0,0,0) , LIGHT);

    tetrahedron = Tetrahedron(ColorDbl(255,255,200), LAMBERTIAN);

    sphere = Sphere(1.5, Vertex(7,2,-2), ColorDbl(255,99,71), LAMBERTIAN);

    sphere2 = Sphere(1, Vertex(5,0,-1), ColorDbl(0,0,0), MIRROR);

    sphere3 = Sphere(2, Vertex(4,4,-2), ColorDbl(0,99,71), LAMBERTIAN);

    lightsource = Light();
}

bool Scene::isIntersected(Ray &r, float minDist, int depth) {

   // if (depth > 5)
    //    return false;

    if (sphere3.rayIntersection(r,minDist))
        return true;

    if (sphere2.rayIntersection(r,minDist))
        return true;

    if (tetrahedron.rayIntersection(r, minDist))
        return true;

    for (int i = 0; i < 24; i++) {
        triangleList[i].rayIntersection(r, minDist);

    }

    if (sphere.rayIntersection(r,minDist))
        return true;

    return false;
}

void Scene::rayIntersection(Ray &r, int depth) {

    r.setColor(ColorDbl(0.0f,0.0f,0.0f));
    //if(depth > 5) return;

    float minDist = 1000.0f;

    tetrahedron.rayIntersection(r, minDist);
    sphere.rayIntersection(r,minDist);
    sphere2.rayIntersection(r,minDist);
    sphere3.rayIntersection(r,minDist);
    lightsource.rayIntersection(r, minDist);

    for (int i = 0; i < 24; i++) {
        triangleList[i].rayIntersection(r, minDist);
    }

    if(r.getRayType() != SHADOW) {
        switch(r.getMaterial()) {
            case MIRROR: {

                float length_of = sqrt((r.getObjectNormal().x * r.getObjectNormal().x) + (r.getObjectNormal().y * r.getObjectNormal().y) + (r.getObjectNormal().z * r.getObjectNormal().z));
                Direction norm_normal = Direction (r.getObjectNormal().x / length_of, r.getObjectNormal().y / length_of, r.getObjectNormal().z / length_of);

                float length = sqrt((r.getDir().x * r.getDir().x) + (r.getDir().y * r.getDir().y) + (r.getDir().z * r.getDir().z));
                Direction norm_dir = Direction (r.getDir().x / length, r.getDir().y / length, r.getDir().z / length);


                Direction reflected= glm::reflect(norm_dir, norm_normal);

                 length = sqrt((reflected.x * reflected.x) + (reflected.y * reflected.y) + (reflected.z * reflected.z));
                Direction norm_ref = Direction (reflected.x / length, reflected.y / length, reflected.z / length);

                    Ray reflectedRay(r.getEnd(), norm_ref,REFLECTION);

                    /*if(isIntersected(reflectedRay, minDist, depth)) {
                        r.setColor(reflectedRay.getColor()*0.9f);
                        std::cout << r.getColor().x;
                    }*/

                    rayIntersection(reflectedRay,0);
                    r.setColor(reflectedRay.getColor()*0.9f);



                    break;

            }
            case LIGHT: {

                break;
            }
            case LAMBERTIAN : {




                r.setColor(computeDirectLight(r, minDist));
                break;
            }
            default: break;
        }
    }


}

ColorDbl Scene::computeDirectLight(Ray &r, float &minDist) {
    float L0 = lightsource.getL0();

    float brdf = (0.8f / (float)M_PI);

    ColorDbl sum = ColorDbl(0.f,0.0f,0.0f);

    std::uniform_real_distribution<float> distribution(0.0f,1.0f);
    std::random_device rd;
    std::default_random_engine generator(rd());


    Vertex v0 = lightsource.getv0();
    Vertex v1 = lightsource.getv1();
    Vertex v2 = lightsource.getv2();
    Vertex v3 = lightsource.getv3();



    Direction lightNormal = Direction (0.0f,0.0f,-1.0f);

    int M = 5;
    for(int i = 0; i < M; i++){
        float vk;
        //parametrize point q on the area light
        float u = distribution(generator);
        float v = distribution(generator);


        //random point on light surface
        //Vertex q = Vertex(u*(v1-v0) + v*(v3-v0));
        //move to global coordinates
        //q += Vertex(4,-1.5,3.9f);
        //std::cout << q.x << " "<< q.y << " " << q.z << std::endl;

       Vertex q = Vertex(4.5+u,-0.5+ v,4.4f);
        //std::cout << q.x << " "<< q.y << " " << q.z << std::endl;

        Direction s_i = q - r.getEnd();

        //normalize s_i

        float d_i = glm::length(s_i);

        float length_of_cross = sqrt((s_i.x * s_i.x) + (s_i.y * s_i.y) + (s_i.z * s_i.z));
        Direction rayDir = Direction (s_i.x / length_of_cross, s_i.y / length_of_cross, s_i.z / length_of_cross);

        float cos_alpha =  glm::max(0.f,glm::dot(-rayDir,lightNormal));
        float cos_beta = glm::max(0.f, glm::dot(rayDir,r.getObjectNormal()));
        //float cos_alpha = glm::dot(-s_i,lightNormal);
        //float cos_beta = glm::dot(s_i,r.getObjectNormal());

        //shadow ray




        Ray shadowRay = Ray(r.getEnd(), rayDir, SHADOW);
        rayIntersection(shadowRay, 0);
        float shadowRayLength = glm::length(shadowRay.getEnd() - shadowRay.getStart());

        //if(isIntersected(shadowRay,minDist,0)){
        if(shadowRayLength < d_i) {
            vk = 0;
        }
        else vk = 1.0f;

        sum += brdf * r.getColor()*vk*(cos_alpha*cos_beta/(d_i*d_i));
    }
    //surface A of light source
    float A = glm::length(glm::cross(v1-v0, v3-v0));

    return  ((L0 * A * sum / float(M+1)));

}