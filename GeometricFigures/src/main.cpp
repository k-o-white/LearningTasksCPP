#include <iostream>
#include "Figures.h"

int main()
{
    std::cout << "------------ Geometric Figures ------------" << std::endl;
    char userAnswer;
    do {
        std::cout << "To start program, press Y, to exit press N." << std::endl;
        std::cin >> userAnswer;
    } while (userAnswer != 'Y' && userAnswer != 'N');

    while (userAnswer != 'N')
    {
        instruction();
        createFigure();
        do {
            std::cout << std::endl;
            std::cout << "To continue program, press Y, to exit press N." << std::endl;
            std::cin >> userAnswer;
        } while (userAnswer != 'Y' && userAnswer != 'N');
    }
    return 0;
}




