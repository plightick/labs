#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <limits>
#include "List.hpp"
#include "ListAlgorithm.hpp"

template<typename T>
class Menu {
public:
    Menu() = default;
    void run();

private:
    List<T> list;

    void printMenu() const;
    void addElement();
    void printList() const;
    void findElement() const;
    void sortList();
    T readValue() const;
};

#include "MenuImpl.hpp"

#endif // MENU_HPP
