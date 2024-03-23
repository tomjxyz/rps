#include <iostream>
#include "../include/cpu.h"

int main() {
    Cpu pc{};
    for (int i = 0; i < 1000; i++){
        std::cout << pc.next();
    }
    std::cout << std::endl;

    return 0;
}
