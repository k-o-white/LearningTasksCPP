//
// Created by teena on 22.12.2022.
//

#include "Shape.h"
#include <iostream>

void Shape::printParams(Shape *shape)
{
    BoundingBoxDimensions bBox = shape->dimensions();
    std::cout << "Type: " << shape->type() << ";" << std::endl;
    std::cout << "Square: " << shape->square() << ";" << std::endl;
    std::cout << "Width: " << bBox.width << ";" << std::endl;
    std::cout << "Height: " << bBox.height << "." << std::endl;
    std::cout << std::endl;
}
