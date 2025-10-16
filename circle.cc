#include "circle.hpp"
#include <iostream>
#include <cmath>

constexpr double PI = 3.14159265358979323846;

double Circle::square() const {
    return PI * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2 * PI * radius_;
}

void Circle::parameters() const {
    std::cout << "Радиус: " << radius_ << "\n";
}

std::string Circle::name() const {
    return shape_name_;
}

void Circle::draw() const {
    std::cout << "    ***    \n";
    std::cout << " *       * \n";
    std::cout << "*         *\n";
    std::cout << " *       * \n";
    std::cout << "    ***    \n";
}
