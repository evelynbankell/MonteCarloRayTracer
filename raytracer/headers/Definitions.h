//
// Created by Hannah Bergenroth & Evelyn Bankell
//

#ifndef RAYTRACER_DEFINITIONS_H
#define RAYTRACER_DEFINITIONS_H

#include "../glm/glm.hpp"

using Vertex = glm::vec3;
using Direction = glm::vec3;
using ColorDbl = glm::vec3;

enum Material {MIRROR, LAMBERTIAN, LIGHT};
enum RayType {SHADOW, REFLECTION, PRIMARY, SECONDARY};

#endif //RAYTRACER_DEFINITIONS_H