#include "person.hpp"
#include <iostream>
using namespace std;

Person::Person() : firstName(""), lastName(""), middleName(""), yearOfBirth(0) {}

Person::Person(const string& firstName, const string& lastName, const string& middleName, int yearOfBirth): firstName(firstName), lastName(lastName), middleName(middleName), yearOfBirth(yearOfBirth) {}

string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
string Person::getMiddleName() const { return middleName; }
int Person::getYearOfBirth() const { return yearOfBirth; }

void Person::setFirstName(const string& newFirstName) { firstName = newFirstName; }
void Person::setLastName(const string& newLastName) { lastName = newLastName; }
void Person::setMiddleName(const string& newMiddleName) { middleName = newMiddleName; }
void Person::setYearOfBirth(int newYearOfBirth) { yearOfBirth = newYearOfBirth; }

void Person::print() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", " << yearOfBirth << " г.р.\n";
}
