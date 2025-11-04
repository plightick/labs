#include "../header/circle.hpp"
#include <iostream>
#include <cmath>
#include <numbers> 

double Circle::square() const {
    return std::numbers::pi * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2 * std::numbers::pi * radius_  ;
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