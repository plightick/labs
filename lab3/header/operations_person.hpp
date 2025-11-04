#ifndef OPERATIONS_PERSON_HPP
#define OPERATIONS_PERSON_HPP

#include "teacher_commission_member.hpp"
#include "commission_member.hpp"
#include "teacher.hpp"

int checkInt();
void showMenu();

void inputPerson(Person*& person);
void inputTeacher(Teacher*& teacher);
void inputCommissionMember(CommissionMember*& member);
void inputTeacherCommissionMember(TeacherCommissionMember*& tcm);

void printObjects(const Person* person, const Teacher* teacher, const CommissionMember* member,const TeacherCommissionMember* tcm);

#endif
