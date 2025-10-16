#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double square() const = 0;
    virtual double perimeter() const = 0;
    virtual void parameters() const = 0;
    virtual std::string name() const = 0;
    virtual void draw() const = 0; 
};

#endif
