//
// Created by teena on 22.12.2022.
//

#include "Circle.h"

Circle::Circle(double radius) : radius(radius) {}

std::string Circle::type()
{
    return "Circle";
}

double Circle::square()
{
    return pi * pow(radius, 2);
}

BoundingBoxDimensions Circle::dimensions()
{
    this->boundingBox.height = radius * 2;
    this->boundingBox.width = radius * 2;
    return boundingBox;
}



