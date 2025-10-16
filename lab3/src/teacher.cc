#include "teacher.hpp"
#include <iostream>
#include <span>
using namespace std;

Teacher::Teacher() = default;

Teacher::Teacher(const Teacher& other) 
    : Person(other),
      position(other.position),
      degree(other.degree),
      specialty(other.specialty),
      publicationCount(other.publicationCount) {
    
    if (publicationCount > 0) {
        publications = new string[publicationCount];
        for (int i = 0; i < publicationCount; i++)
            publications[i] = other.publications[i];
    } else {
        publications = nullptr;
    }
}

Teacher& Teacher::operator=(const Teacher& other) {
    if (this == &other) return *this;

    Person::operator=(other);
    position = other.position;
    degree = other.degree;
    specialty = other.specialty;

    delete[] publications;
    publicationCount = other.publicationCount;
    if (publicationCount > 0) {
        publications = new string[publicationCount];
        for (int i = 0; i < publicationCount; i++)
            publications[i] = other.publications[i];
    } else {
        publications = nullptr;
    }

    return *this;
}

Teacher::~Teacher() { delete[] publications; }

void Teacher::setPosition(string_view pos) { position = pos; }
void Teacher::setDegree(string_view deg) { degree = deg; }
void Teacher::setSpecialty(string_view spec) { specialty = spec; }

void Teacher::setPublications(span<const string> pubs) {
    delete[] publications;
    publicationCount = pubs.size();
    if (publicationCount > 0) {
        publications = new string[publicationCount];
        for (int i = 0; i < publicationCount; i++)
            publications[i] = pubs[i];
    } else {
        publications = nullptr;
    }
}

string Teacher::getPosition() const { return position; }
string Teacher::getDegree() const { return degree; }
string Teacher::getSpecialty() const { return specialty; }
int Teacher::getPublicationCount() const { return publicationCount; }

string Teacher::getPublication(int index) const {
    return (index >= 0 && index < publicationCount) ? publications[index] : "";
}

void Teacher::print() const {
    Person::print();
    cout << "Должность: " << position << "\nУченая степень: " << degree
         << "\nСпециальность: " << specialty << "\nПубликации:\n";
    for (int i = 0; i < publicationCount; i++)
        cout << " - " << publications[i] << endl;
}