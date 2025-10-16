#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <string_view>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int yearOfBirth;

public:
    Person();
    Person(std::string_view firstName, std::string_view lastName, std::string_view middleName, int yearOfBirth);
    virtual ~Person() = default;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMiddleName() const;
    int getYearOfBirth() const;

    void setFirstName(std::string_view firstName);
    void setLastName(std::string_view lastName);
    void setMiddleName(std::string_view middleName);
    void setYearOfBirth(int yearOfBirth);

    virtual void print() const;
};

#endif