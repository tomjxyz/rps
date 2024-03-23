#include <iostream>
#include <unistd.h>
#include <termio.h>
#include "../include/cpu.h"

int main() {
    Cpu pc{};
    char userChoice{};
    bool win{};

    // Turn off terminal buffering
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    std::cout << "--- Rock Paper Scissors ---\nPress CRTL+C to exit\n";
    while (true){
        std::cout << "Enter Move: ";
        userChoice = std::getchar();
        win = pc.play(userChoice);
        if (win)
            std::cout << "\nWin!\n";
        else
            std::cout << "\nLose\n";
        
        pc.next();
    }

    return 0;
}
