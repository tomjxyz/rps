#include <iostream>
#include <random>
#include <cstdlib>
#include "../include/cpu.h"
Cpu::Cpu() {
    losses = 0;
    turn = 0;
    wins = std::vector{0,0};
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
            losses++;
            return true;
        }
        break;
    case 'p':
        if (choice == 's' || choice == 'p')
            return false;
        else {
            losses++;
            return true;
        }
        break;
    case 's':
        if (choice == 'r' || choice == 's')
            return false;
        else {
            losses++;
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
    int round = (turn+3)/3;
    if (turn % 3 == 0) {
        if (turn != 0) {
            if (losses > 1) {
                wins[0]++;
                std::cout << "\nWon Round!";
            } else {
                wins[1]++;
                std::cout << "\nLost Round";
            }
            losses = 0;
            std::cout << " \nScore: "    << wins[0]
                      << "\nCPU Score: " << wins[1] << "\n";
        }
        std::cout << "\nRound " << round << "\n";
    }
}
