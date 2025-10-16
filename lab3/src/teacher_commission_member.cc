#include "teacher_commission_member.hpp"
#include <iostream>
#include <span>
using namespace std;

TeacherCommissionMember::TeacherCommissionMember() = default;

TeacherCommissionMember::TeacherCommissionMember(const TeacherCommissionMember& other) 
    : Teacher(other), 
      CommissionMember(other),
      commissionWorkCount(other.commissionWorkCount) {
    
    if (commissionWorkCount > 0) {
        commissionWorks = new string[commissionWorkCount];
        for (int i = 0; i < commissionWorkCount; i++)
            commissionWorks[i] = other.commissionWorks[i];
    } else {
        commissionWorks = nullptr;
    }
}

TeacherCommissionMember& TeacherCommissionMember::operator=(const TeacherCommissionMember& other) {
    if (this == &other) return *this;
    
    Teacher::operator=(other);
    CommissionMember::operator=(other);

    delete[] commissionWorks;
    commissionWorkCount = other.commissionWorkCount;
    if (commissionWorkCount > 0) {
        commissionWorks = new string[commissionWorkCount];
        for (int i = 0; i < commissionWorkCount; i++)
            commissionWorks[i] = other.commissionWorks[i];
    } else {
        commissionWorks = nullptr;
    }
    return *this;
}

TeacherCommissionMember::~TeacherCommissionMember() { 
    delete[] commissionWorks; 
}

void TeacherCommissionMember::setCommissionWorks(span<const string> works) {
    delete[] commissionWorks;
    commissionWorkCount = works.size();
    if (commissionWorkCount > 0) {
        commissionWorks = new string[commissionWorkCount];
        for (int i = 0; i < commissionWorkCount; i++)
            commissionWorks[i] = works[i];
    } else {
        commissionWorks = nullptr;
    }
}

int TeacherCommissionMember::getCommissionWorkCount() const { 
    return commissionWorkCount; 
}

string TeacherCommissionMember::getCommissionWork(int index) const {
    return (index >= 0 && index < commissionWorkCount) ? commissionWorks[index] : "";
}

void TeacherCommissionMember::print() const {
    Teacher::print();
    CommissionMember::print();
    cout << "Работы в комиссии:\n";
    for (int i = 0; i < commissionWorkCount; i++)
        cout << " + " << commissionWorks[i] << endl;
}