#include "person.hpp"
#include <iostream>
using namespace std;

Person::Person() : firstName(""), lastName(""), middleName(""), yearOfBirth(0) {}

Person::Person(string_view firstName, string_view lastName, string_view middleName, int yearOfBirth): firstName(firstName), lastName(lastName), middleName(middleName), yearOfBirth(yearOfBirth) {}

string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
string Person::getMiddleName() const { return middleName; }
int Person::getYearOfBirth() const { return yearOfBirth; }

void Person::setFirstName(string_view newFirstName) { firstName = newFirstName; }
void Person::setLastName(string_view newLastName) { lastName = newLastName; }
void Person::setMiddleName(string_view newMiddleName) { middleName = newMiddleName; }
void Person::setYearOfBirth(int newYearOfBirth) { yearOfBirth = newYearOfBirth; }

void Person::print() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", " << yearOfBirth << " г.р.\n";
}