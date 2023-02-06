#include <iostream>
#include "Registry.h"

enum actions {ADD = 1, REMOVE, PRINT, FIND, EXIT};

void instruction()
{
    std::cout << "Add    - 1" << std::endl;
    std::cout << "Remove - 2" << std::endl;
    std::cout << "Print  - 3" << std::endl;
    std::cout << "Find   - 4" << std::endl;
    std::cout << "Exit   - 5" << std::endl;
}

int main()
{
    Registry<int, std::string> reg;

    int cmd = 0;
    while (cmd != EXIT)
    {
        instruction();
        std::cout << "Input command: ";
        std::cin >> cmd;

        std::system("cls");
        switch (cmd)
        {
            case ADD:
                reg.add();
                break;
            case REMOVE:
                reg.remove();
                break;
            case PRINT:
                reg.print();
                break;
            case FIND:
                reg.find();
                break;
            case EXIT:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}
