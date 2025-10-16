#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <memory>
#include <vector>

namespace {

double get_double() {
    double number;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> number && ss.eof()) return number;
        std::cout << "Ошибка. Введите число: ";
    }
}

int get_int() {
    int number;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> number && ss.eof()) return number;
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

std::unique_ptr<Shape> create_figure() {
    std::cout << "Выберите фигуру:\n"
              << "1 - Круг\n"
              << "2 - Прямоугольный треугольник\n"
              << "3 - Равнобокая трапеция\n";

    int choice = get_int();

    switch (choice) {
        case 1: {
            std::cout << "Введите радиус: ";
            double r = get_double();
            return std::make_unique<Circle>(r);
        }
        case 2: {
            std::cout << "Введите два катета: ";
            double a = get_double();
            double b = get_double();
            return std::make_unique<Triangle>(a, b);
        }
        case 3: {
            std::cout << "Введите два основания и высоту: ";
            double a = get_double();
            double b = get_double();
            double h = get_double();
            return std::make_unique<Trapezoid>(a, b, h);
        }
        default:
            std::cout << "Неверный выбор.\n";
            return nullptr;
    }
}

} // namespace

void menu() {
    std::vector<std::unique_ptr<Shape>> shapes;
    int choice;

    do {
        print_menu();
        choice = get_int();

        switch (choice) {
            case 1: {
                auto shape = create_figure();
                if (shape) shapes.push_back(std::move(shape));
                break;
            }
            case 2:
                if (shapes.empty()) {
                    std::cout << "Нет фигур.\n";
                } else {
                    for (const auto& s : shapes) {
                        std::cout << s->name()
                                  << " — площадь: " << s->square()
                                  << ", периметр: " << s->perimeter() << '\n';
                    }
                }
                break;
            case 3:
                if (shapes.empty()) {
                    std::cout << "Нет фигур.\n";
                } else {
                    for (const auto& s : shapes) {
                        std::cout << s->name() << ": ";
                        s->parameters();
                    }
                }
                break;
            case 4:
                if (shapes.empty()) {
                    std::cout << "Нет фигур для отображения.\n";
                } else {
                    for (const auto& s : shapes) {
                        std::cout << "\nФигура: " << s->name() << "\n";
                        s->draw();
                    }
                }
                break;
            case 0:
                std::cout << "Выход...\n";
                break;
            default:
                std::cout << "Неверный ввод.\n";
        }

    } while (choice != 0);
}
