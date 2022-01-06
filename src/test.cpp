
#include "pch.h"
#include "Flame.h"

int main() {

    try {
        FlameTest();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }


}