#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

void printParams(Shape *shape)
{
    BoundingBoxDimensions bBox = shape->dimensions();
    std::cout << "Type: " << shape->type() << ";" << std::endl;
    std::cout << "Square: " << shape->square() << ";" << std::endl;
    std::cout << "Width: " << bBox.width << ";" << std::endl;
    std::cout << "Height: " << bBox.height << "." << std::endl;
    std::cout << std::endl;
}

int main()
{
    Circle c(4);
    Rectangle r(5, 4);
    Triangle t(3,4,5);
    printParams(&c);
    printParams(&r);
    printParams(&t);
    return 0;
}
