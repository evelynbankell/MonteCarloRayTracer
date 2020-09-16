//
// Created by Hannah Bergenroth on 2020-09-16.
//

#include "../headers/Scene.h"

Scene::Scene() {

    //FLOOR
    triangleList[0] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0));
    triangleList[1] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0),Vertex(0.0,6.0,-5.0,1.0));
    triangleList[2] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,6.0,-5.0,1.0));
    triangleList[3] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0));
    triangleList[4] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0));
    triangleList[5] = Triangle(Vertex(5.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0),Vertex(13.0,0.0,-5.0,1.0));
    //ROOF
    triangleList[6] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0));
    triangleList[7] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0));
    triangleList[8] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0));
    triangleList[9] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0));
    triangleList[10] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0));
    triangleList[11] = Triangle(Vertex(5.0,0.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0));
    //WALLS
    triangleList[12] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(0.0,6.0,5.0,1.0));
    triangleList[13] = Triangle(Vertex(-3.0,0.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(0.0,6.0,-5.0,1.0));

    triangleList[14] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(0.0,6.0,5.0,1.0),Vertex(10.0,6.0,5.0,1.0));
    triangleList[15] = Triangle(Vertex(0.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(10.0,6.0,-5.0,1.0));

    triangleList[16] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(10.0,6.0,5.0,1.0),Vertex(13.0,0.0,5.0,1.0));
    triangleList[17] = Triangle(Vertex(10.0,6.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(13.0,0.0,-5.0,1.0));

    triangleList[18] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(-3.0,0.0,5.0,1.0));
    triangleList[19] = Triangle(Vertex(0.0,-6.0,-5.0,1.0),Vertex(-3.0,0.0,5.0,1.0),Vertex(-3.0,0.0,-5.0,1.0));

    triangleList[20] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,5.0,1.0));
    triangleList[21] = Triangle(Vertex(10.0,-6.0,-5.0,1.0),Vertex(0.0,-6.0,5.0,1.0),Vertex(0.0,-6.0,-5.0,1.0));

    triangleList[22] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(13.0,0.0,5.0,1.0),Vertex(10.0,-6.0,5.0,1.0));
    triangleList[23] = Triangle(Vertex(13.0,0.0,-5.0,1.0),Vertex(10.0,-6.0,5.0,1.0),Vertex(10.0,-6.0,-5.0,1.0));
}