#include "teacher.hpp"
#include <iostream>
using namespace std;

Teacher::Teacher() : position(""), degree(""), specialty(""), publications(nullptr), publicationCount(0) {}

Teacher::Teacher(const Teacher& other) : Person(other) {
    position = other.position;
    degree = other.degree;
    specialty = other.specialty;
    publicationCount = other.publicationCount;

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

void Teacher::setPosition(const string& position) { this->position = position; }
void Teacher::setDegree(const string& degree) { this->degree = degree; }
void Teacher::setSpecialty(const string& specialty) { this->specialty = specialty; }

void Teacher::setPublications(string* publications, int publicationCount) {
    delete[] this->publications;
    this->publicationCount = publicationCount;
    this->publications = new string[publicationCount];
    for (int i = 0; i < publicationCount; i++)
        this->publications[i] = publications[i];
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
