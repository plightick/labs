#include "../header/triangle.hpp"
#include <iostream>
#include <cmath>

double Triangle::square() const {
    return (side1_ * side2_) / 2.0;
}

double Triangle::perimeter() const {
    return side1_ + side2_ + std::sqrt(side1_ * side1_ + side2_ * side2_);
}

void Triangle::parameters() const {
    std::cout << "Катеты: " << side1_ << ", " << side2_ << "\n";
}

std::string Triangle::name() const {
    return shape_name_;
}

void Triangle::draw() const {
    std::cout << "    *\n";
    std::cout << "   **\n";
    std::cout << "  ***\n";
    std::cout << " *****\n";
    std::cout << "*******\n";
}
