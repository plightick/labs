#include "../header/user.h"
#include "../header/menu.h"
#include <fstream>
#include <sstream>

void User::inputInFile(const std::string& fileName, const User& user) const {
    std::ofstream file(fileName, std::ios::app);

    file << "Фамилия: " << user.surname_ << std::endl
         << "Имя: " << user.name_ << std::endl
         << "Отчество: " << user.middleName_ << std::endl
         << "Номер пользователя: " << user.workerNumber_ << std::endl
         << "==============================" << std::endl;

    file.close();
}

void User::resetUserData(std::string& surname, std::string& name, std::string& middleName, int& number) {
    surname.clear();
    name.clear();
    middleName.clear();
    number = 0;
}

void User::enterUser(User& user, const std::string& fileName) const {
    std::string tempLine;
    int number = 0;

    do {
        std::cout << "Введите фамилию: ";
        std::getline(std::cin, tempLine);
    } while (!isOnlyLetters(tempLine));
    user.surname_ = tempLine;

    do {
        std::cout << "Введите имя: ";
        std::getline(std::cin, tempLine);
    } while (!isOnlyLetters(tempLine));
    user.name_ = tempLine;

    do {
        std::cout << "Введите отчество: ";
        std::getline(std::cin, tempLine);
    } while (!isOnlyLetters(tempLine));
    user.middleName_ = tempLine;

    std::cout << "Введите номер: ";
    number = checkNumbers<int>();
    user.workerNumber_ = number;

    inputInFile(fileName, user);
}

void User::display() const {
    std::cout << "\nФамилия: " << surname_
              << ",\nИмя: " << name_
              << ",\nОтчество: " << middleName_
              << ",\nНомер: " << workerNumber_ << std::endl;
}

void User::processDataLine(const std::string_view& line, size_t pos, std::string& surname, std::string& name, std::string& middleName, int& number) {
    std::string_view key = line.substr(0, pos);
    std::string value(line.substr(pos + 2));

    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    if (key.find("Фамилия") != std::string::npos) {
        surname = value;
    } else if (key.find("Имя") != std::string::npos) {
        name = value;
    } else if (key.find("Отчество") != std::string::npos) {
        middleName = value;
    } else if (key.find("Номер") != std::string::npos && !value.empty()) {
        try {
            number = std::stoi(value);
        } catch (const std::invalid_argument&) {
            std::cout << "Ошибка: неверный формат числа '" << value << "'" << std::endl;
            number = 0;
        } catch (const std::out_of_range&) {
            std::cout << "Ошибка: число слишком большое '" << value << "'" << std::endl;
            number = 0;
        }
    }
}

User** User::loadUsersFromFile(const std::string& fileName, int& userCount) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        userCount = 0;
        return nullptr;
    }

    userCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("=") != std::string::npos) {
            userCount++;
        }
    }
    file.close();

    if (userCount == 0) {
        return nullptr;
    }

    auto users = new User*[userCount]();
    file.open(fileName);

    std::string surname;
    std::string name;
    std::string middleName;
    int number = 0;
    int currentUser = 0;

    while (std::getline(file, line) && currentUser < userCount) {
        size_t pos = line.find(": ");
        if (pos != std::string::npos) {
            processDataLine(line, pos, surname, name, middleName, number);
        } else if (line.find("=") != std::string::npos) {
            if (!surname.empty() && !name.empty()) {
                std::string initials[3] = {surname, name, middleName};
                users[currentUser++] = new User(initials, number);
            }
            resetUserData(surname, name, middleName, number);
        }
    }

    file.close();
    userCount = currentUser;

    if (userCount == 0) {
        delete[] users;
        return nullptr;
    }

    return users;
}
