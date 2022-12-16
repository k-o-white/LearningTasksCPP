//
// Created by teena on 16.12.2022.
//
#include <iostream>
#include <thread>
#include <mutex>
#include "../include/Train.h"

std::mutex station_status;

Train::Train(const char &name, const int &arrivalTime) : name(name), arrivalTime(arrivalTime) {}

char Train::getTrainName() const
{
    return name;
}

int Train::getArrivalTime() const
{
    return arrivalTime;
}

void createTrains(std::vector <Train*> &t)
{
    enum trains {A = 65, B, C};
    for (int i = A; i < C + 1; ++i)
    {
        char trainName = (char)i;
        int arrivalTime;
        std::cout << "Input arrival time of train " << trainName << ": ";
        std::cin >> arrivalTime;
        auto* newTrain = new Train(trainName, arrivalTime);
        t.emplace_back(newTrain);
    }
}

void deleteTrains(std::vector <Train*> &t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        delete t[i];
        t[i] = nullptr;
    }
}

void displayStationStatus(Train* t)
{
    std::this_thread::sleep_for(std::chrono::seconds(t->getArrivalTime()));
    if (station_status.try_lock())
        station_status.unlock();
    else
        std::cout << "Train " << t->getTrainName() << " is waiting now." << std::endl;
    station_status.lock();
    std::cout << "Train " << t->getTrainName() << " arrived on train station." << std::endl;
    std::string cmd;
    do {
        std::cout << "To depart train " << t->getTrainName() << " enter \"depart\": ";
        std::cin >> cmd;
    } while (cmd != "depart");
    std::cout << "Train " << t->getTrainName() << " left station." << std::endl;
    station_status.unlock();
}
