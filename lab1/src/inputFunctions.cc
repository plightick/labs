#include "../headers/inputFunctions.hpp"
#include <limits>
#include <iostream>
 
int checkInt() {
    int number;
    while (true) {
        if (std::cin >> number) {
            if (std::cin.peek() == '\n' || std::cin.peek() == EOF) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return number;
            } else {
                std::cout << "Ошибка. Введите число: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Ошибка. Введите число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
