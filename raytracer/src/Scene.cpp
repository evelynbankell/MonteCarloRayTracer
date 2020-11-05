//
// Created by Hannah Bergenroth & Evelyn Bankell
//
#include <iostream>
#include <random>
#include <cmath>

#include "../headers/Scene.h"

Scene::Scene() {

    //ROOF - white color
    triangleList[0] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[1] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,6.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[2] = Triangle(Vertex(5.0,0.0,5.0),Vertex(13.0,0.0,5.),Vertex(10.0,6.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[3] = Triangle(Vertex(5.0,0.0,5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[4] = Triangle(Vertex(5.0,0.0,5.0),Vertex(0.0,-6.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[5] = Triangle(Vertex(5.0,0.0,5.0),Vertex(10.0,-6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(1,1,1), LAMBERTIAN);

    // FLOOR
    triangleList[6] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);
   	triangleList[7] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);
   	triangleList[8] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[9] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[10] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);
    triangleList[11] = Triangle(Vertex(5.0,0.0,-5.0),Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(1,1,1), LAMBERTIAN);

    // WALLS
    // blue color
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(0.0,6.0,5.0), ColorDbl(0,0,0.8), LAMBERTIAN);
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(0.0,6.0,-5.0), ColorDbl(0,0,0.8), LAMBERTIAN);

    // Green color
    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(0.0,6.0,5.0),Vertex(10.0,6.0,5.0), ColorDbl(0,0.5,0), LAMBERTIAN);
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(10.0,6.0,-5.0), ColorDbl(0,0.5,0), LAMBERTIAN);

    // red
    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(10.0,6.0,5.0),Vertex(13.0,0.0,5.0), ColorDbl(0.5,0,0), LAMBERTIAN);
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(13.0,0.0,-5.0), ColorDbl(0.5,0,0), LAMBERTIAN);

    // Yellow color
    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(-3.0,0.0,5.0), ColorDbl(0.8, 0.8, 0), LAMBERTIAN);
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0),Vertex(-3.0,0.0,5.0),Vertex(-3.0,0.0,-5.0), ColorDbl(0.8, 0.8, 0), LAMBERTIAN);

    // Purple color
    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(0.0,-6.0,5.0), ColorDbl(0.8, 0, 0.8), LAMBERTIAN);
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0),Vertex(0.0,-6.0,5.0),Vertex(0.0,-6.0,-5.0), ColorDbl(0.8, 0, 0.8), LAMBERTIAN);

    // Light blue color
    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(13.0,0.0,5.0),Vertex(10.0,-6.0,5.0), ColorDbl(0, 0.8, 0.8), LAMBERTIAN);
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0),Vertex(10.0,-6.0,5.0),Vertex(10.0,-6.0,-5.0), ColorDbl(0, 0.8, 0.8), LAMBERTIAN);

    //Lamp
    //triangleList[24] = Triangle(Vertex(5.5,-1.5,4), Vertex(4.5,1.5,4), Vertex(5.5,-1.5,4), ColorDbl(0,0,0), LIGHT);
    //triangleList[25] = Triangle(Vertex(5.5,-1.5,4), Vertex(4.5,1.5,4), Vertex(5.5,1.5,4), ColorDbl(0,0,0) , LIGHT);

    tetrahedron = Tetrahedron(ColorDbl(0.5,0.5,0.5), LAMBERTIAN);

    sphere = Sphere(1.5, Vertex(7,2,-2), ColorDbl(0,0.3,0.2), LAMBERTIAN);

    sphere2 = Sphere(1, Vertex(5,0,-1), ColorDbl(0,0,0), MIRROR);

    sphere3 = Sphere(2, Vertex(4,4,-2), ColorDbl(0.8,0.2,0.2), LAMBERTIAN);

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
    if(depth > 5) return;

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
                //Normalize object normal
                float length_of = sqrt((r.getObjectNormal().x * r.getObjectNormal().x) + (r.getObjectNormal().y * r.getObjectNormal().y) + (r.getObjectNormal().z * r.getObjectNormal().z));
                Direction norm_normal = Direction (r.getObjectNormal().x / length_of, r.getObjectNormal().y / length_of, r.getObjectNormal().z / length_of);

                //Normalize ray direction
                float length = sqrt((r.getDir().x * r.getDir().x) + (r.getDir().y * r.getDir().y) + (r.getDir().z * r.getDir().z));
                Direction norm_dir = Direction (r.getDir().x / length, r.getDir().y / length, r.getDir().z / length);

                //Perfect reflection
                Direction reflected= glm::reflect(norm_dir, norm_normal);

                //Normalize reflected ray
                length = sqrt((reflected.x * reflected.x) + (reflected.y * reflected.y) + (reflected.z * reflected.z));
                Direction norm_ref = Direction (reflected.x / length, reflected.y / length, reflected.z / length);

                //Create reflected ray
                Ray reflectedRay(r.getEnd(), norm_ref,REFLECTION);

                //Cast reflected ray
                rayIntersection(reflectedRay,depth+1);
                //Get color of intersection
                r.setColor(reflectedRay.getColor());
                break;
            }
            case LAMBERTIAN : {
                ColorDbl direct = computeDirectLight(r, minDist);
                ColorDbl inDirect = computeIndirectLight(r, depth);
                r.setColor(direct + inDirect);
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

    //light normal
    Direction lightNormal = Direction (0.0f,0.0f,-1.0f);

    int M = 4;
    for(int i = 1; i <= M; i++){
        float vk;
        //parametrize point q on the area light
        float u = distribution(generator);
        float v = distribution(generator);

        Vertex q = Vertex(4.5+u,-0.5+ v,4.4f);

        Direction s_i = q - r.getEnd();

        float d_i = glm::length(s_i);

        float length_of_cross = sqrt((s_i.x * s_i.x) + (s_i.y * s_i.y) + (s_i.z * s_i.z));
        Direction rayDir = Direction (s_i.x / length_of_cross, s_i.y / length_of_cross, s_i.z / length_of_cross);

        float cos_alpha =  glm::max(0.f,glm::dot(-s_i,lightNormal));
        float cos_beta = glm::max(0.f, glm::dot(s_i,r.getObjectNormal()));

        //create shadow ray
        Ray shadowRay = Ray(r.getEnd(), rayDir, SHADOW);
        //cast shadow ray
        rayIntersection(shadowRay, 0);

        float shadowRayLength = glm::length(shadowRay.getEnd() - shadowRay.getStart());

        //check visibility
        if(shadowRayLength < d_i) {
            vk = 0;
        }
        else vk = 1.0f;

        sum += 0.9f * r.getColor()*vk*(cos_alpha*cos_beta/(d_i*d_i));
       // std::cout << sum.x << " " << sum.y << " " << sum.z << std::endl;
    }
    //surface A of light source
    float A = glm::length(glm::cross(v1-v0, v3-v0));


    return  (( sum * A/ float(M)));
}

ColorDbl Scene::computeIndirectLight(Ray &r, int  depth) {
    std::uniform_real_distribution<float> distribution(0.0f,1.0f);
    std::random_device rd;
    std::default_random_engine generator(rd());

    ColorDbl indirectLight(0,0,0);

    //Russian roulette
    float randomValue = distribution(generator);
    float maxIntensity = glm::max(glm::max(r.getColor().x, r.getColor().y),r.getColor().z);

    if(!(randomValue < maxIntensity)) {
        return indirectLight;
    }

    Direction I = r.getDir();
    Direction Z = r.getObjectNormal();

    //float length_of_cross = sqrt((I.x * I.x) + (I.y * I.y) + (I.z * I.z));
    //I = Direction (I.x / length_of_cross, I.y / length_of_cross, I.z / length_of_cross);

    //length_of_cross = sqrt((Z.x * Z.x) + (Z.y * Z.y) + (Z.z * Z.z));
    //Z = Direction (Z.x / length_of_cross, Z.y / length_of_cross, Z.z / length_of_cross);

    Direction I_ortho = I - glm::dot(I,Z)*Z;
    Direction X = I_ortho/glm::length(I_ortho);
    Direction Y = glm::cross(-X,Z);

    glm::mat4 a;
    a[0] = glm::vec4(X.x, Y.x, Z.x,0);
    a[1] = glm::vec4(X.y, Y.y, Z.y, 0);
    a[2] = glm::vec4(X.z, Y.z, Z.z, 0);
    a[3] = glm::vec4(0, 0, 0, 1);
    glm::mat4 b;
    b[0] = glm::vec4(1, 0, 0, 0);
    b[1] = glm::vec4(0, 1, 0, 0);
    b[2] = glm::vec4(0, 0, 1, 0);
    b[3] = glm::vec4(-r.getEnd().x, -r.getEnd().y, -r.getEnd().z, 1);
    glm::mat4 M = a * b;


        float f1 = distribution(generator);
        float f2 = distribution(generator);

    /*
    float azimuth = (2.f * M_PI ) * f1;
    float inclination = acos(sqrt(f2)); //glm::acos(1 - f2)//acos(sqrt(f2)))//1-2*f2;
    float x = sin(azimuth)*sin(inclination);
    float y = sin(azimuth)*cos(inclination);
    float z = sin(inclination);*/

    float sinTheta = glm::max(sqrt(1.0f - f1 * f1),0.f);
    float phi = 2.0f * M_PI * f2;
    float x = sinTheta * cosf(phi);
    float z = sinTheta * sinf(phi);

    Direction Nt,Nb;

    Direction N = r.getObjectNormal();

    if (std::fabs(N.x) > std::fabs(N.y))
        Nt = Direction(N.z, 0.0f, -N.x) / (float)sqrt(N.x * N.x + N.z * N.z);
    else
        Nt = Direction(0.0f, -N.z, N.y) / (float)sqrt(N.y * N.y + N.z * N.z);
    Nb = glm::cross(N, Nt);



        glm::vec4 v_W(x,f1,z,0);

        //Direction sample(x,f1,z);

        glm::vec4 v_I = M*v_W;
        Direction random_direction (v_I.x, v_I.y, v_I.z);

    /*Direction random_direction(
            sample.x * Nb.x + sample.y * r.getObjectNormal().x + sample.z * Nt.x,
            sample.x * Nb.y + sample.y * r.getObjectNormal().y + sample.z * Nt.y,
            sample.x * Nb.z + sample.y * r.getObjectNormal().z + sample.z * Nt.z);*/

        float length_of_cross = sqrt((random_direction.x * random_direction.x) + (random_direction.y * random_direction.y) + (random_direction.z * random_direction.z));
        Direction randomDirectionNormalize = Direction (random_direction.x / length_of_cross, random_direction.y / length_of_cross, random_direction.z / length_of_cross);

        Ray randomRay(r.getEnd(), randomDirectionNormalize, SECONDARY);

        rayIntersection(randomRay, depth + 1);
        if (randomRay.getColor().x > 1.0f)
            //std::cout << randomRay.getColor().x << std::endl;

        float d_i = glm::length(randomRay.getEnd()-r.getEnd());

    return 0.9f * randomRay.getColor() ;// Importance, M_PI is because of the importance sampling;
}

