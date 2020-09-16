//
// Created by Hannah Bergenroth on 2020-09-16.
//

#ifndef RAYTRACER_DIRECTION_H
#define RAYTRACER_DIRECTION_H

#include "../glm/glm.hpp"


class Direction {
public:
    Direction(const glm::vec3 &direction);
    ~Direction();
private:
    glm::vec3 direction;
};


#endif //RAYTRACER_DIRECTION_H
