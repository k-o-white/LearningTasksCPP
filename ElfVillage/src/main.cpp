#include <iostream>
#include "Branch.h"
#include "Village.h"

int main()
{
    Village* elfVillage = new Village();
    char answer = ' ';
    while (answer != 'n')
    {
        std::string input;
        std::cout << "Input name you are looking for: ";
        std::cin >> input;
        while (input == "None")
        {
            std::cout << "Name is invalid. Try again." << std::endl;
            std::cout << "Input name you are looking for: ";
            std::cin >> input;
        }

        elfVillage->findTree(input);

        answer = ' ';
        do {
            std::cout << "Continue? (y/n): ";
            std::cin >> answer;
        } while (answer != 'y' && answer != 'n');
    }
    delete elfVillage;
    elfVillage = nullptr;
    return 0;
}
