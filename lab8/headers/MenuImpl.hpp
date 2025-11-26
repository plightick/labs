#ifndef MENUIMPL_HPP
#define MENUIMPL_HPP

#include "Menu.hpp"

template<typename T>
void Menu<T>::run() {
    int userChoice = -1;

    while (userChoice != 0) {
        printMenu();
        std::cin >> userChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод.\n";
            continue;
        }

        switch (userChoice) {
            case 1: addElement(); break;
            case 2: printList(); break;
            case 3: findElement(); break;
            case 4: sortList(); break;
            case 0: break;
            default: std::cout << "Нет такого пункта.\n";
        }
    }
}

template<typename T>
void Menu<T>::printMenu() const {
    std::cout << "\n--- Меню ---\n"
              << "1. Добавить элемент\n"
              << "2. Показать список\n"
              << "3. Найти элемент\n"
              << "4. Отсортировать список\n"
              << "0. Выход\n"
              << "Выберите пункт: ";
}

template<typename T>
void Menu<T>::addElement() {
    T value = readValue();
    list.pushBack(value);
    std::cout << "Добавлено.\n";
}

template<typename T>
void Menu<T>::printList() const {
    if (list.empty()) {
        std::cout << "Список пуст.\n";
        return;
    }

    std::cout << "Список: ";
    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

template<typename T>
void Menu<T>::findElement() const {
    if (list.empty()) {
        std::cout << "Список пуст.\n";
        return;
    }

    T value = readValue();
    auto result = ListAlgorithm<T>::find(list, value);

    if (result != list.end())
        std::cout << "Найдено: " << *result << "\n";
    else
        std::cout << "Не найдено.\n";
}

template<typename T>
void Menu<T>::sortList() {
    if (list.empty()) {
        std::cout << "Список пуст.\n";
        return;
    }

    ListAlgorithm<T>::sort(list);
    std::cout << "Список отсортирован.\n";
}

template<typename T>
T Menu<T>::readValue() const {
    T value;
    std::cout << "Введите значение: ";
    std::cin >> value;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Повторите: ";
        std::cin >> value;
    }
    return value;
}

#endif // MENUIMPL_HPP
