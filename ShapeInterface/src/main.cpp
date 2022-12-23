#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main()
{
    Circle c(4);
    Rectangle r(5, 4);
    Triangle t(3,4,5);
    Circle::printParams(&c);
    Rectangle::printParams(&r);
    Triangle::printParams(&t);
    return 0;
}
