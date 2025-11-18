#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <cstring>
#include <limits>

class User {
public:
    User() = default;
    User(const std::string* initials, int number) 
        : surname_(initials[0]), name_(initials[1]), middleName_(initials[2]), workerNumber_(number) {}

    void inputInFile(const std::string& fileName, const User& user) const;
    void enterUser(User& user, const std::string& fileName) const;

    static User** loadUsersFromFile(const std::string& fileName, int& userCount);
    static void freeUsers(User** users, int count);

    void display() const;

private:
    std::string surname_;
    std::string name_;
    std::string middleName_;
    int workerNumber_;

    static void resetUserData(std::string& surname, std::string& name, std::string& middleName, int& number);
    static void processDataLine(const std::string_view& line, size_t pos, std::string& surname, std::string& name, std::string& middleName, int& number);
};

#endif
