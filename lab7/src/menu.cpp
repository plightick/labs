#include "../header/menu.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>

bool isCyrillicChar(unsigned char c1, unsigned char c2) {
    return (c1 == 0xD0 && c2 >= 0x80 && c2 <= 0xBF) || 
           (c1 == 0xD1 && c2 >= 0x80 && c2 <= 0x9F);
}

bool isOnlyLetters(const std::string& str) {
    if (str.empty()) {
        std::cout << "Строка не может быть пустой!\n";
        return false;
    }

    for (size_t i = 0; i < str.length();) {
        auto c = static_cast<unsigned char>(str[i]);
        if (c >= 0xC0) {
            if (i + 1 >= str.length()) {
                std::cout << "Некорректный UTF-8 символ\n";
                return false;
            }
            if (auto c2 = static_cast<unsigned char>(str[i + 1]); !isCyrillicChar(c, c2)) {
                std::cout << "Недопустимый символ: допускаются только русские буквы\n";
                return false;
            }
            i += 2;
        } else if (!isalpha(c) && c != ' ' && c != '-') {
            std::cout << "Недопустимый символ: '" << c << "'\n";
            return false;
        } else {
            i++;
        }
    }

    return true;
}

template<typename T>
T checkNumbers() {
    T number;
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (std::stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        std::cout << "Ошибка. Введите число: ";
    }
}

void printMenu() {
    std::cout << "1 - Введите пользователя" << std::endl
              << "2 - Посмотреть пользователей в файле" << std::endl
              << "0 - Выход" << std::endl;
}

void printFile(const std::string& fileName) {
    int userCount = 0;
    User** users = User::loadUsersFromFile(fileName, userCount);

    if (users == nullptr || userCount == 0) {
        std::cout << "Файл пуст или пользователи не найдены." << std::endl;
        return;
    }

    for (int i = 0; i < userCount; i++) {
        std::cout << i + 1 << ". ";
        users[i]->display();
    }
}

void menu() {
    User user;
    int choice = 0;
    std::string fileName = "users.txt";
    std::ofstream clearFile(fileName);
    clearFile.close();

    do {
        system("clear");
        printMenu();
        choice = checkNumbers<int>();

        switch (choice) {
            case 1:
                system("clear");
                user.enterUser(user, fileName);
                break;
            case 2:
                system("clear");
                printFile(fileName);
                break;
            case 0:
                system("clear");
                std::cout << "Выход..." << std::endl;
                break;
            default:
                std::cout << "Неверный пункт меню. Введите ещё раз.\n";
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 0);
}
