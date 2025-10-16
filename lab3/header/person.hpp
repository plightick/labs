#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int yearOfBirth;

public:
    Person();
    Person(const std::string& firstName, const std::string& lastName, const std::string& middleName, int yearOfBirth);
    virtual ~Person() = default;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMiddleName() const;
    int getYearOfBirth() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setMiddleName(const std::string& middleName);
    void setYearOfBirth(int yearOfBirth);

    virtual void print() const;
};

#endif
