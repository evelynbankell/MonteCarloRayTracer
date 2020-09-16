#include <iostream>

#include "../headers/Camera.h"

//This is a main function
int main() {
    Camera n(35);
    std::cout << n.getNum() << " + " << glm::sqrt(2) << std::endl;


    return 0;
}
