#include "../include/menu.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

template<typename T>
T checkNumbers() {
    T number;
    string input;
    
    while (true) {
        getline(cin, input);
        
        if (stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        cout << "Ошибка. Введите число: ";
    }
}

template int checkNumbers<int>();

void handInputString(String& str) {
    cout << "Ввод строки" << endl;
    cout << "Введите строку: ";
    
    string input;
    getline(cin, input);
    
    try {
        str = String(input.c_str()); 
        cout << "Строка сохранена." << endl;
        str.print();
    } catch (const StringException& error) {
        cout << "Ошибка: " << error.what() << endl;
    }
}

void printStringMenu() {
    cout << "\nМеню работы со строками\n"
         << "1 - Ввести первую строку\n"
         << "2 - Ввести вторую строку\n"
         << "3 - Показать строки\n"
         << "4 - Объединить строки (оператор +)\n"
         << "0 - Выход\n"
         << "Введите число от 0 до 4: ";
}

void showStrings(const String& str1, const String& str2) {
    cout << "Первая строка: ";
    str1.print();
    cout << "Вторая строка: ";
    str2.print();
}

void concatenateStrings(const String& str1, const String& str2) {
    cout << "Объединение строк:" << endl;
    str1.print();
    cout << " + " << endl;
    str2.print();
    cout << " = " << endl;
    
    try {
        String result = str1 + str2;
        result.print();
    } catch (const StringException& error) {
        cout << "Ошибка при объединении: " << error.what() << endl;
    }
}

void stringMenu() {
    int choice = 0;
    String str1, str2;

    do {
        system("clear");
        printStringMenu();
        choice = checkNumbers<int>();

        switch (choice) {
        case 1:
            system("clear");
            handInputString(str1);
            break;
        
        case 2:
            system("clear");
            handInputString(str2);
            break;
            
        case 3:
            system("clear");
            showStrings(str1, str2);
            break;
            
        case 4:
            system("clear");
            if (str1.empty() && str2.empty()) {
                cout << "Обе строки пусты. Сначала введите строки." << endl;
            } else {
                concatenateStrings(str1, str2);
            }
            break;
            
        case 0:
            system("clear");
            cout << "Выход..." << endl;
            break;
            
        default:
            cout << "Неверный пункт меню. Введите ещё раз.\n";
        }
        
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 0);
}