#ifndef TEACHER_COMMISSION_MEMBER_HPP
#define TEACHER_COMMISSION_MEMBER_HPP

#include "teacher.hpp"
#include "commission_member.hpp"
#include <string_view>
#include <span>

class TeacherCommissionMember : public Teacher, public CommissionMember {
private:
    std::string* commissionWorks = nullptr;
    int commissionWorkCount = 0;

public:
    TeacherCommissionMember();
    TeacherCommissionMember(const TeacherCommissionMember& other);
    TeacherCommissionMember& operator=(const TeacherCommissionMember& other);
    ~TeacherCommissionMember() override;

    void setCommissionWorks(std::span<const std::string> works);
    int getCommissionWorkCount() const;
    std::string getCommissionWork(int index) const;

    void print() const override;
};

#endif