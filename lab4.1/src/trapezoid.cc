#include "../header/trapezoid.hpp"
#include <iostream>
#include <cmath>

double Trapezoid::square() const {
    return (side1_ + side2_) * height_ / 2.0;
}

double Trapezoid::perimeter() const {
    double leg = std::sqrt(std::pow((side1_ - side2_) / 2.0, 2) + height_ * height_);
    return side1_ + side2_ + 2 * leg;
}

void Trapezoid::parameters() const {
    std::cout << "Основания: " << side1_ << ", " << side2_
              << "; высота: " << height_ << "\n";
}

std::string Trapezoid::name() const {
    return shape_name_;
}

void Trapezoid::draw() const {
    std::cout << "  ******  \n";
    std::cout << " ******** \n";
    std::cout << "**********\n";
}
