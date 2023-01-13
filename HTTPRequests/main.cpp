#include <iostream>
#include <cpr/cpr.h>

enum requests
{
    EXIT = 0, GET, POST, PUT, DEL, PATCH
};

void displayResponse(int &request)
{
    cpr::Response response;
    switch (request)
    {
        case GET:
            response = cpr::Get(cpr::Url("http://httpbin.org/get"));
            break;
        case POST:
            response = cpr::Post(cpr::Url("http://httpbin.org/post"));
            break;
        case PUT:
            response = cpr::Put(cpr::Url("http://httpbin.org/put"));
            break;
        case DEL:
            response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            break;
        case PATCH:
            response = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            break;
    }
    std::cout << response.text << std::endl << std::endl;
}

void instruction()
{
    std::cout << "--------------" << std::endl;
    std::cout << "| 1 - GET    |" << std::endl;
    std::cout << "| 2 - POST   |" << std::endl;
    std::cout << "| 3 - PUT    |" << std::endl;
    std::cout << "| 4 - DELETE |" << std::endl;
    std::cout << "| 5 - PATCH  |" << std::endl;
    std::cout << "| 0 - EXIT   |" << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << std::endl;
}

int main()
{
    int input = -1;
    while (input != EXIT)
    {
        std::system("cls");
        instruction();
        std::cout << "Input number of request: ";
        std::cin >> input;

        if (input > EXIT && input <= PATCH)
            displayResponse(input);
        else if (input != EXIT)
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}
