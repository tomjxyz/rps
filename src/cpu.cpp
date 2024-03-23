#include <iostream>
#include <random>
#include "../include/cpu.h"
Cpu::Cpu() {
    wins = 0;
    round = 1;
    opts = {'r','p','s'};

    std::random_device rd{};
    mt = std::mt19937(rd());
    three = std::uniform_int_distribution{0,2};

    choice = next();
}

char Cpu::next() {
    return opts[three(mt)];
}

bool Cpu::play(char userChoice) {
    return userChoice;

}
