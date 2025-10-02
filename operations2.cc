#include "operations2.hpp"
#include <limits>
#include <iostream>

using namespace std;
 
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

void showMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Ввести первую матрицу\n";
    cout << "2. Ввести вторую матрицу\n";
    cout << "3. Вывести матрицы\n";
    cout << "4. Перемножить матрицы\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт: ";
}
