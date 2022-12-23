//
// Created by teena on 22.12.2022.
//

#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

double Triangle::square()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

BoundingBoxDimensions Triangle::dimensions()
{
    BoundingBoxDimensions boundingBox;
    double p = (a + b + c) / 2;
    boundingBox.width = 2 * (a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c))));
    boundingBox.height = boundingBox.width;
    return boundingBox;
}

std::string Triangle::type()
{
    return "Triangle";
}
