#include "operations_person.hpp"
#include <iostream>
#include <limits>
using namespace std;

int checkInt() {
    int number;
    while (!(cin >> number)) {
        cout << "Ошибка. Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

void showMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Ввести человека\n";
    cout << "2. Ввести преподавателя\n";
    cout << "3. Ввести члена комиссии\n";
    cout << "4. Ввести преподавателя-члена комиссии\n";
    cout << "5. Вывести все данные\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт: ";
}

void inputPerson(Person*& person) {
    delete person;
    person = new Person();

    string firstName;
    string lastName;
    string middleName;
    int yearOfBirth;

    cout << "Имя: "; cin >> firstName;
    cout << "Фамилия: "; cin >> lastName;
    cout << "Отчество: "; cin >> middleName;
    cout << "Год рождения: "; yearOfBirth = checkInt();

    person->setFirstName(firstName);
    person->setLastName(lastName);
    person->setMiddleName(middleName);
    person->setYearOfBirth(yearOfBirth);
}
 
void inputTeacher(Teacher*& teacher) {
    delete teacher;
    teacher = new Teacher();

    string firstName;
    string lastName;
    string middleName;
    string position;
    string degree;
    string specialty;
    int yearOfBirth;
    int publicationCount;

    cout << "Имя: "; cin >> firstName;
    cout << "Фамилия: "; cin >> lastName;
    cout << "Отчество: "; cin >> middleName;
    cout << "Год рождения: "; yearOfBirth = checkInt();

    teacher->setFirstName(firstName);
    teacher->setLastName(lastName);
    teacher->setMiddleName(middleName);
    teacher->setYearOfBirth(yearOfBirth);

    cout << "Должность: "; cin >> position;
    cout << "Учёная степень: "; cin >> degree;
    cout << "Специальность: "; cin >> specialty;
    teacher->setPosition(position);
    teacher->setDegree(degree);
    teacher->setSpecialty(specialty);

    cout << "Количество публикаций: "; publicationCount = checkInt();
    string* publications = new string[publicationCount];
    for (int i = 0; i < publicationCount; i++) {
        cout << "Публикация " << (i+1) << ": "; cin >> publications[i];
    }
    teacher->setPublications(publications, publicationCount);
    delete[] publications;
}

void inputCommissionMember(CommissionMember*& member) {
    delete member;
    member = new CommissionMember();

    string firstName;
    string lastName;
    string middleName;
    string commissionName;
    string certificateNumber;
    int yearOfBirth;
    int appointmentYear;
    int autobiographyCount;

    cout << "Имя: "; cin >> firstName;
    cout << "Фамилия: "; cin >> lastName;
    cout << "Отчество: "; cin >> middleName;
    cout << "Год рождения: "; yearOfBirth = checkInt();
    member->setFirstName(firstName);
    member->setLastName(lastName);
    member->setMiddleName(middleName);
    member->setYearOfBirth(yearOfBirth);

    cout << "Название комиссии: "; cin >> commissionName;
    cout << "Год назначения: "; appointmentYear = checkInt();
    cout << "Номер свидетельства: "; cin >> certificateNumber;

    member->setCommissionName(commissionName);
    member->setAppointmentYear(appointmentYear);
    member->setCertificateNumber(certificateNumber);

    cout << "Количество записей автобиографии: "; autobiographyCount = checkInt();
    string* autobiography = new string[autobiographyCount];
    for (int i = 0; i < autobiographyCount; i++) {
        cout << "Запись " << (i+1) << ": "; cin >> autobiography[i];
    }
    member->setAutobiography(autobiography, autobiographyCount);
    delete[] autobiography;
}

void inputTeacherCommissionMember(TeacherCommissionMember*& tcm) {
    delete tcm;
    tcm = new TeacherCommissionMember();

    string firstName;
    string lastName;
    string middleName;
    string position;
    string degree;
    string specialty;
    int yearOfBirth;
    int publicationCount;

    cout << "Имя: "; cin >> firstName;
    cout << "Фамилия: "; cin >> lastName;
    cout << "Отчество: "; cin >> middleName;
    cout << "Год рождения: "; yearOfBirth = checkInt();
    tcm->setFirstName(firstName);
    tcm->setLastName(lastName);
    tcm->setMiddleName(middleName);
    tcm->setYearOfBirth(yearOfBirth);

    cout << "Должность: "; cin >> position;
    cout << "Учёная степень: "; cin >> degree;
    cout << "Специальность: "; cin >> specialty;
    tcm->setPosition(position);
    tcm->setDegree(degree);
    tcm->setSpecialty(specialty);

    cout << "Количество публикаций: "; publicationCount = checkInt();
    string* publications = new string[publicationCount];
    for (int i = 0; i < publicationCount; i++) {
        cout << "Публикация " << (i+1) << ": "; cin >> publications[i];
    }
    tcm->setPublications(publications, publicationCount);
    delete[] publications;

    string commissionName;
    string certificateNumber;
    int appointmentYear;
    int autobiographyCount;

    cout << "Название комиссии: "; cin >> commissionName;
    cout << "Год назначения: "; appointmentYear = checkInt();
    cout << "Номер свидетельства: "; cin >> certificateNumber;

    tcm->setCommissionName(commissionName);
    tcm->setAppointmentYear(appointmentYear);
    tcm->setCertificateNumber(certificateNumber);

    cout << "Количество записей автобиографии: "; autobiographyCount = checkInt();
    string* autobiography = new string[autobiographyCount];
    for (int i = 0; i < autobiographyCount; i++) {
        cout << "Запись " << (i+1) << ": "; cin >> autobiography[i];
    }
    tcm->setAutobiography(autobiography, autobiographyCount);
    delete[] autobiography;

    int commissionWorkCount;
    cout << "Количество работ в комиссии: "; commissionWorkCount = checkInt();
    string* works = new string[commissionWorkCount];
    for (int i = 0; i < commissionWorkCount; i++) {
        cout << "Работа " << (i+1) << ": "; cin >> works[i];
    }
    tcm->setCommissionWorks(works, commissionWorkCount);
    delete[] works;
}

void printObjects(const Person* person, const Teacher* teacher,
                  const CommissionMember* member,
                  const TeacherCommissionMember* tcm) {
    cout << "\n====== ДАННЫЕ ======\n";
    if (person) {
        cout << "--- Человек ---\n";
        person->print();
    }
    if (teacher) {
        cout << "--- Преподаватель ---\n";
        teacher->print();
    }
    if (member) {
        cout << "--- Член комиссии ---\n";
        member->print();
    }
    if (tcm) {
        cout << "--- Преподаватель-член комиссии ---\n";
        tcm->print();
    }
}


