#ifndef TEACHER_COMMISSION_MEMBER_HPP
#define TEACHER_COMMISSION_MEMBER_HPP

#include "teacher.hpp"
#include "commission_member.hpp"

class TeacherCommissionMember : public Teacher, public CommissionMember {
private:
    std::string* commissionWorks;
    int commissionWorkCount;

public:
    TeacherCommissionMember();
    TeacherCommissionMember(const TeacherCommissionMember& other);
    TeacherCommissionMember& operator=(const TeacherCommissionMember& other);
    ~TeacherCommissionMember();

    void setCommissionWorks(std::string* works, int count);
    int getCommissionWorkCount() const;
    std::string getCommissionWork(int index) const;

    
    void print() const override;
};

#endif
