
#include "Flame.h"
#include <iostream>

int main() {

    try {
        FlameTest();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }


}