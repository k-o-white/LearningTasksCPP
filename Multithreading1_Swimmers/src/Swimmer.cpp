//
// Created by teena on 16.12.2022.
//
#include <iostream>
#include <thread>
#include <mutex>
#include "Swimmer.h"

std::mutex swimmer_status;

Swimmer::Swimmer(const std::string &name, const float &speed) : name(name), speed(speed) {}

std::string Swimmer::getName()
{
    return this->name;
}

double Swimmer::getSpeed() const
{
    return this->speed;
}

void Swimmer::setFinish()
{
    isFinished = true;
}

bool Swimmer::getFinish() const
{
    return isFinished;
}

void Swimmer::setTime(int &time)
{
    this->time = time;
}

int Swimmer::getTime() const
{
    return this->time;
}

void Swimmer::setCurrentDistance(double &dist)
{
    currentDistance = dist;
}

double Swimmer::getCurrentDistance() const
{
    return currentDistance;
}

bool compare(Swimmer* a, Swimmer* b)
{
    return (a->time < b->time);
}

void addSwimmers(std::vector <Swimmer*> &swimmers)
{
    const int swimmersCount = 6;
    for (int i = 0; i < swimmersCount; ++i)
    {
        std::string newName;
        float newSpeed;
        std::cout << "Input name of swimmer №" << i + 1 << ": ";
        std::cin >> newName;
        std::cout << "Input speed of swimmer №" << i + 1 << ": ";
        std::cin >> newSpeed;
        auto* newSwimmer = new Swimmer(newName, newSpeed);
        swimmers.push_back(newSwimmer);
    }
}


void displaySwimmerStatus(Swimmer* s, int totalDistance)
{
    int time = 0;
    while (!s->getFinish())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++time;

        swimmer_status.lock();
        s->setTime(time);
        double newCurDistance = s->getCurrentDistance() + s->getSpeed();
        s->setCurrentDistance(newCurDistance);
        if (s->getCurrentDistance() >= totalDistance)
            s->setFinish();

        std::cout << "Swimmer " << s->getName() << " ";
        if (!s->getFinish())
            std::cout << "swam " << s->getCurrentDistance() << " m." << std::endl;
        else
            std::cout << "is finished." << std::endl;
        swimmer_status.unlock();
    }
}

void displayResult(std::vector <Swimmer*> &swimmers)
{
    std::sort(swimmers.begin(), swimmers.end(), compare);

    for (int i = 0; i < swimmers.size(); ++i)
    {
        std::cout << i + 1 << " place: " << swimmers[i]->getName() << ";\n";
        std::cout << "Time: " << swimmers[i]->getTime() << " sec." << std::endl;
    }
}

void deleteSwimmers(std::vector <Swimmer*> &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        delete s[i];
        s[i] = nullptr;
    }
}