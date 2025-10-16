#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

namespace {

double get_double() {
    double number;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        if (std::stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        std::cout << "Ошибка. Введите число: ";
    }
}

int get_int() {
    int number;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        if (std::stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        std::cout << "Ошибка. Введите число: ";
    }
}

void print_menu() {
    std::cout << "\nМеню фигур:\n"
              << "1 - Создать фигуру\n"
              << "2 - Площадь и периметр\n"
              << "3 - Параметры\n"
              << "4 - Визуализация\n"
              << "0 - Выход\n";
}

std::unique_ptr<Shape> create_circle() {
    std::cout << "Введите радиус: ";
    double r = get_double();
    return std::make_unique<Circle>(r);
}

std::unique_ptr<Shape> create_triangle() {
    std::cout << "Введите два катета: ";
    double a = get_double();
    double b = get_double();
    return std::make_unique<Triangle>(a, b);
}

std::unique_ptr<Shape> create_trapezoid() {
    std::cout << "Введите два основания и высоту: ";
    double a = get_double();
    double b = get_double();
    double h = get_double();
    return std::make_unique<Trapezoid>(a, b, h);
}

std::unique_ptr<Shape> create_figure() {
    std::cout << "Выберите фигуру:\n"
              << "1 - Круг\n"
              << "2 - Прямоугольный треугольник\n"
              << "3 - Равнобокая трапеция\n";

    int choice = get_int();

    switch (choice) {
        case 1:
            return create_circle();
        case 2:
            return create_triangle();
        case 3:
            return create_trapezoid();
        default:
            std::cout << "Неверный выбор.\n";
            return nullptr;
    }
}

void handle_create_figure(std::vector<std::unique_ptr<Shape>>& shapes) {
    if (auto shape = create_figure(); shape) {
        shapes.push_back(std::move(shape));
    }
}

void handle_show_area_perimeter(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) {
        std::cout << "Нет фигур.\n";
        return;
    }
    
    for (const auto& shape : shapes) {
        std::cout << shape->name()
                  << " — площадь: " << shape->square()
                  << ", периметр: " << shape->perimeter() << '\n';
    }
}

void handle_show_parameters(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) {
        std::cout << "Нет фигур.\n";
        return;
    }
    
    for (const auto& shape : shapes) {
        std::cout << shape->name() << ": ";
        shape->parameters();
    }
}

void handle_visualization(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) {
        std::cout << "Нет фигур для отображения.\n";
        return;
    }
    
    for (const auto& shape : shapes) {
        std::cout << "\nФигура: " << shape->name() << "\n";
        shape->draw();
    }
}

void process_menu_choice(int choice, std::vector<std::unique_ptr<Shape>>& shapes) {
    switch (choice) {
        case 1:
            handle_create_figure(shapes);
            break;
        case 2:
            handle_show_area_perimeter(shapes);
            break;
        case 3:
            handle_show_parameters(shapes);
            break;
        case 4:
            handle_visualization(shapes);
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный ввод.\n";
    }
}

} 

void menu() {
    std::vector<std::unique_ptr<Shape>> shapes;
    int choice;

    do {
        print_menu();
        choice = get_int();
        process_menu_choice(choice, shapes);
    } while (choice != 0);
}