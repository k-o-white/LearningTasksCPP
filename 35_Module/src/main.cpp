#include <iostream>
#include "tasks.h"

int main()
{
    int input;
    std::cout << "Choose task (from 1 to 3) or 0 to exit: ";
    std::cin >> input;

    while (input != 0)
    {
        std::system("cls");
        switch (input)
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            default:
                std::cout << "Input is invalid." << std::endl;
        }

        std::cout << std::endl << "Choose task (from 1 to 3) or 0 to exit: ";
        std::cin >> input;
    }
    return 0;
}
