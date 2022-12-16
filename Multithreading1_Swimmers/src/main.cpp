#include <vector>
#include <thread>
#include "Swimmer.h"

void clear()
{
#ifdef _WIN32
    std::system("cls");
#elif defined (__LINUX__)
    std::system("clear");
#endif
}

int main()
{
    const int totalDistance = 100;
    std::vector <Swimmer*> swimmers;
    addSwimmers(swimmers);

    clear();

    std::vector <std::thread> swims;
    for (int i = 0; i < swimmers.size(); ++i)
        swims.emplace_back(std::thread(displaySwimmerStatus, swimmers[i], totalDistance));

    for (auto& swim: swims)
        if (swim.joinable()) swim.join();

    displayResult(swimmers);
    deleteSwimmers(swimmers);
    return 0;
}
