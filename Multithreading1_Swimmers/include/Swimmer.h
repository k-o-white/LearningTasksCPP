//
// Created by teena on 16.12.2022.
//
#pragma once
#include <string>
#include <vector>

class Swimmer
{
private:
    std::string name = "unknown";
    double speed = 0;
    double currentDistance = 0;
    int time = 0;
    bool isFinished = false;
public:
    Swimmer(const std::string &name, const float &speed);

    std::string getName();

    double getSpeed() const;

    void setFinish();

    bool getFinish() const;

    void setTime(int &time);

    int getTime() const;

    void setCurrentDistance(double &dist);

    double getCurrentDistance() const;

    friend bool compare(Swimmer* a, Swimmer* b);
};

void addSwimmers(std::vector <Swimmer*> &swimmers);

void displaySwimmerStatus(Swimmer* s, int totalDistance);

void displayResult(std::vector <Swimmer*> &swimmers);

void deleteSwimmers(std::vector <Swimmer*> &s);
