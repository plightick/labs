#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../header/shapes.hpp"
#include <cmath>
#include <iostream>
#include <string>

class Triangle : public Shape {
public:
    Triangle(double a, double b) : side1_(a), side2_(b) {}

    double square() const override;
    double perimeter() const override;
    void parameters() const override;
    std::string name() const override;
    void draw() const override;

private:
    double side1_;
    double side2_;
    std::string shape_name_ = "Прямоугольный треугольник";
};

#endif
