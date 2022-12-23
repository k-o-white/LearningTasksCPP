//
// Created by teena on 22.12.2022.
//
#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a, double b, double c);

    ~Triangle() = default;

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual std::string type();
};

