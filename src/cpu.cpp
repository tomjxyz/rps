#include <iostream>
#include <random>
#include <cstdlib>
#include "../include/cpu.h"
Cpu::Cpu() {
    wins = 0;
    turn = 0;
    opts = {'r','p','s'};

    std::random_device rd{};
    mt = std::mt19937(rd());
    three = std::uniform_int_distribution{0,2};

    choice = next();
}

char Cpu::next() {
    choice = opts[three(mt)]; 
    return choice;
}

bool Cpu::play(char userChoice) {
    turn++;
    switch (userChoice)
    {
    case 'r':
        if (choice == 'r' || choice == 'p')
            return false;
        else {
            wins++;
            return true;
        }
        break;
    case 'p':
        if (choice == 's' || choice == 'p')
            return false;
        else {
            wins++;
            return true;
        }
        break;
    case 's':
        if (choice == 'r' || choice == 's')
            return false;
        else {
            wins++;
            return true;
        }
        break;
    default:
        std::cout << "Enter a valid choice (r p s)\n";
        return false;
        break;
    }

}
void Cpu::printRound() {
    if (turn % 3 == 0) {
        std::cout << "\nRound " << (turn+3)/3 << "\n";
    }
}
