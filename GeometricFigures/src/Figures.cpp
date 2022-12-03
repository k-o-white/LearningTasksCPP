//
// Created by teena on 03.12.2022.
//
#include <iostream>
#include "Figures.h"

Figure::Figure(std::string type, double &centerX, double &centerY, int &color)
{
    this->type = type;
    this->centerX = centerX;
    this->centerY = centerY;
    this->color = color;
}

double Figure::getX()
{
    return centerX;
}

double Figure::getY()
{
    return centerY;
}


std::string Figure::getType()
{
    return this->type;
}

std::string Figure::getColor() const
{
    std::string result = "";
    switch (color)
    {
        case NONE:
            result = "None";
        case RED:
            result = "Red";
        case BLUE:
            result = "Blue";
        case GREEN:
            result = "Green";
    }
    return result;
}

double Figure::calculateArea()
{
    return 0;
}

double Figure::calcutateOutsideArea()
{
    return 0;
}

Circle::Circle(std::string type, double &centerX, double &centerY, int &color, double &radius) :
        Figure(type, centerX, centerY, color)
{
    this->radius = radius;
}

double Circle::calculateArea()
{
    return pi * pow(this->radius, 2);
}

double Circle::calcutateOutsideArea()
{
    return pow((2 * this->radius), 2);
}

Triangle::Triangle(std::string type, double &centerX, double &centerY, int &color, double &side) :
        Figure(type, centerX, centerY, color)
{
    this->side = side;
}

double Triangle::calculateArea()
{
    return this->side * this->side * sqrt(3.0) / 4.0;
}

double Triangle::calcutateOutsideArea()
{
    return pow(this->side, 2);
}

Square::Square(std::string type, double &centerX, double &centerY, int &color, double &side) :
        Figure(type, centerX, centerY, color)
{
    this->side = side;
}

double Square::calculateArea()
{
    return pow(this->side, 2);
}

double Square::calcutateOutsideArea()
{
    return calculateArea();
}

Rectangle::Rectangle(std::string type, double &centerX, double &centerY, int &color, double &width, double &height) :
        Figure(type, centerX, centerY, color)
{
    this->width = width;
    this->height = height;
}

double Rectangle::calculateArea()
{
    return this->width * this->height;
}

double Rectangle::calcutateOutsideArea()
{
    return calculateArea();
}

void instruction()
{
    std::cout << "--------------" << std::endl;
    std::cout << "1 - circle;" << std::endl;
    std::cout << "2 - triangle;" << std::endl;
    std::cout << "3 - square;" << std::endl;
    std::cout << "4 - rectangle." << std::endl;
    std::cout << "--------------" << std::endl;
}

void createFigure()
{
    int figureNum;
    std::cout << "Input number of figure: ";
    std::cin >> figureNum;

    double x, y;
    int color;
    std::cout << "Input coordinates of center (x, y): ";
    std::cin >> x >> y;
    std::cout << "Input color (0 - none, 1 - red, 2 - blue, 3 - green): ";
    std::cin >> color;

    Figure* myFigure = nullptr;
    switch (figureNum)
    {
        case CIRCLE:
            double radius;
            std::cout << "Input radius: ";
            std::cin >> radius;
            myFigure = new Circle("Circle", x, y, color, radius);
            break;
        case TRIANGLE:
            double triangleSide;
            std::cout << "Input side: ";
            std::cin >> triangleSide;
            myFigure = new Triangle("Triangle", x, y, color, triangleSide);
            break;
        case SQUARE:
            double squareSide;
            std::cout << "Input side: ";
            std::cin >> squareSide;
            myFigure = new Square("Square", x, y, color, squareSide);
            break;
        case RECTANGLE:
            double width, height;
            std::cout << "Input width and height: ";
            std::cin >> width >> height;
            myFigure = new Rectangle("Rectangle", x, y, color, width, height);
            break;
        default:
            std::cout << "Wrong number." << std::endl;
    }
    if (myFigure != nullptr)
    {
        std::cout << std::endl;
        std::cout << "Type: " << myFigure->getType() << ";" << std::endl;
        std::cout << "Coordinates of center: (" << myFigure->getX() << "; " << myFigure->getY() << ");" << std::endl;
        std::cout << "Color: " << myFigure->getColor() << ";" << std::endl;
        std::cout << "Figure area: " << myFigure->calculateArea() << ";" << std::endl;
        std::cout << "Outside area: " << myFigure->calcutateOutsideArea() << "." << std::endl;
        delete myFigure;
        myFigure = nullptr;
    }
}