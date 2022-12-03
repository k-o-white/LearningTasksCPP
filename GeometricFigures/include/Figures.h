//
// Created by teena on 03.12.2022.
//
#pragma once
#include <string>
#include <cmath>

const double pi = atan(1.0) * 4.0;

enum colors
{
    NONE = 0, RED, BLUE, GREEN
};

enum figures
{
    CIRCLE = 1, TRIANGLE, SQUARE, RECTANGLE
};

class Figure
{
private:
    std::string type;
    double centerX;
    double centerY;
    int color;
public:
    Figure(std::string type, double &centerX, double &centerY, int &color);

    std::string getType();

    double getX();

    double getY();

    std::string getColor() const;

    virtual double calculateArea();

    virtual double calcutateOutsideArea();
};

class Circle : public Figure
{
private:
    double radius;
public:
    Circle(std::string type, double &centerX, double &centerY, int &color, double &radius);

    double calculateArea() override;

    double calcutateOutsideArea() override;
};

class Triangle : public Figure
{
private:
    double side;
public:
    Triangle(std::string type, double &centerX, double &centerY, int &color, double &side);

    double calculateArea() override;

    double calcutateOutsideArea() override;
};

class Square : public Figure
{
private:
    double side;
public:
    Square(std::string type, double &centerX, double &centerY, int &color, double &side);

    double calculateArea() override;

    double calcutateOutsideArea() override;
};

class Rectangle : public Figure
{
private:
    double width;
    double height;
public:
    Rectangle(std::string type, double &centerX, double &centerY, int &color, double &width, double &height);

    double calculateArea() override;

    double calcutateOutsideArea() override;
};


void instruction();
void createFigure();