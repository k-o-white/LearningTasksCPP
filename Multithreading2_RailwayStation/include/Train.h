//
// Created by teena on 16.12.2022.
//
#pragma once
#include <vector>

class Train
{
private:
    char name;
    int arrivalTime;
public:
    Train(const char &name, const int &arrivalTime);

    char getTrainName() const;

    int getArrivalTime() const;
};

void createTrains(std::vector <Train*> &t);

void deleteTrains(std::vector <Train*> &t);

void displayStationStatus(Train* t);