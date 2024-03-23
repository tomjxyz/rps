#include <iostream>
#include <random>

class Cpu {

private:
    // Current choice (r,p,s)
    char choice;
    // Number of losses per round
    int losses;
    // Number of user vs cpu wins (user, cpu)
    std::vector<int> wins;
    // Current turn
    int turn;
    // Options for next
    std::vector<char> opts;
    //RNG
    std::mt19937 mt;
    // To get a list index from RNG
    std::uniform_int_distribution<int> three;

public:
    Cpu();

    // Pick next move
    char next();

    // Compare current choice and user choice and return wether user won or not
    bool play(char userChoice);

    // Prints round if new one has started.
    void printRound();
};
