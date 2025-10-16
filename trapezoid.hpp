#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "shapes.hpp"
#include <string>
#include <iostream>

class Trapezoid : public Shape {
public:
    Trapezoid(double a, double b, double h)
        : side1_(a), side2_(b), height_(h) {}

    double square() const override;
    double perimeter() const override;
    void parameters() const override;
    std::string name() const override;
    void draw() const override;

private:
    double side1_;
    double side2_;
    double height_;
    std::string shape_name_ = "Равнобокая трапеция";
};

#endif
