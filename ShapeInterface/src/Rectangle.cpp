//
// Created by teena on 22.12.2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::square()
{
    return this->width * this->height;
}

BoundingBoxDimensions Rectangle::dimensions()
{
    this->boundingBox.width = width;
    this->boundingBox.height = height;
    return boundingBox;
}

std::string Rectangle::type()
{
    return "Rectangle";
}
