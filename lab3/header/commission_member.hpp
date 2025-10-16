#ifndef COMMISSION_MEMBER_HPP
#define COMMISSION_MEMBER_HPP

#include "person.hpp"
#include <string_view>
#include <span>

class CommissionMember : public Person {
private:
    std::string commissionName = "";
    int appointmentYear = 0;
    std::string certificateNumber = "";
    std::string* autobiographyEntries = nullptr;
    int autobiographyCount = 0;

public:
    CommissionMember();
    CommissionMember(const CommissionMember& other);
    CommissionMember& operator=(const CommissionMember& other);
    ~CommissionMember() override;

    void setCommissionName(std::string_view commissionName);
    void setAppointmentYear(int year);  
    void setCertificateNumber(std::string_view number);  
    void setAutobiography(std::span<const std::string> entries);  

    std::string getCommissionName() const;
    int getAppointmentYear() const;
    std::string getCertificateNumber() const;
    int getAutobiographyCount() const;
    std::string getAutobiographyEntry(int index) const;

    void print() const override;
};

#endif