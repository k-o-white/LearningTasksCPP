//
// Created by teena on 22.12.2022.
//

#pragma once
#include "Shape.h"

class Rectangle : virtual public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double width, double height);

    ~Rectangle() = default;

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual std::string type();
};

