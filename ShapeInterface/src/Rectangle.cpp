//
// Created by teena on 22.12.2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::square()
{
    return width * height;
}

BoundingBoxDimensions Rectangle::dimensions()
{
    BoundingBoxDimensions boundingBox;
    boundingBox.width = width;
    boundingBox.height = height;
    return boundingBox;
}

std::string Rectangle::type()
{
    return "Rectangle";
}
