//
// Created by teena on 22.12.2022.
//
#pragma once
#include <string>
#include <cmath>

const double pi = 4.0 * atan(1.0);

struct BoundingBoxDimensions
{
    double width = 0;
    double height = 0;
};

class Shape
{
protected:
    BoundingBoxDimensions boundingBox;
public:
    virtual double square() = 0;

    virtual BoundingBoxDimensions dimensions() = 0;

    virtual std::string type() = 0;

    static void printParams(Shape *shape);
};


