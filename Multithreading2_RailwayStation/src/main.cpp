#include <iostream>
#include <vector>
#include <thread>
#include "Train.h"

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
    std::vector <Train*> trains;
    createTrains(trains);

    clear();

    std::vector <std::thread> trainThreads;
    for (int i = 0; i < trains.size(); ++i)
        trainThreads.emplace_back(std::thread(displayStationStatus, trains[i]));

    for (auto& tr: trainThreads)
        if (tr.joinable()) tr.join();

    deleteTrains(trains);
    return 0;
}
