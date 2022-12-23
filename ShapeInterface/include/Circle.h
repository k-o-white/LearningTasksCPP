//
// Created by teena on 22.12.2022.
//

#pragma once
#include <Shape.h>
#include <Circle.h>

class Circle : virtual public Shape
{
private:
    double radius;
public:
    Circle(double radius);

    ~Circle() = default;

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual std::string type();
};


