#include "operations_person.hpp"
#include "teacher_commission_member.hpp"
#include "commission_member.hpp"
#include "teacher.hpp"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Person* person = nullptr;
    Teacher* teacher = nullptr;
    CommissionMember* commissionMember = nullptr;
    TeacherCommissionMember* teacherCommissionMember = nullptr;

    bool running = true;
    while (running) {
        showMenu();
        int choice = checkInt();

        switch (choice) {
            case 1: inputPerson(person); break;
            case 2: inputTeacher(teacher); break;
            case 3: inputCommissionMember(commissionMember); break;
            case 4: inputTeacherCommissionMember(teacherCommissionMember); break;
            case 5: printObjects(person, teacher, commissionMember, teacherCommissionMember); break;
            case 0: running = false; break;
            default: cout << "Некорректный выбор.\n";
        }
    }

    delete person;
    delete teacher;
    delete commissionMember;
    delete teacherCommissionMember;

    cout << "Завершение программы.\n";
    return 0;
}
