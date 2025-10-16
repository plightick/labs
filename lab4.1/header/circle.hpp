#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../header/shapes.hpp"
#include <string>  

class Circle : public Shape {
public:
    explicit Circle(double r) : radius_(r) {}

    double square() const override;
    double perimeter() const override;
    void parameters() const override;
    std::string name() const override;
    void draw() const override;

private:
    double radius_;
    std::string shape_name_ = "Круг";
};

#endif