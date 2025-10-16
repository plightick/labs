#ifndef COMMISSION_MEMBER_HPP
#define COMMISSION_MEMBER_HPP

#include "person.hpp"
#include <string_view>

class CommissionMember : public Person {
private:
    std::string commissionName;
    int appointmentYear;
    std::string certificateNumber;
    std::string* autobiographyEntries;
    int autobiographyCount;

public:
    CommissionMember();
    CommissionMember(const CommissionMember& other);
    CommissionMember& operator=(const CommissionMember& other);
    ~CommissionMember();

    void setCommissionName(std::string_view commissionName);
    void setAppointmentYear(int appointmentYear);
    void setCertificateNumber(std::string_view certificateNumber);
    void setAutobiography(std::string* entries, int count);

    std::string getCommissionName() const;
    int getAppointmentYear() const;
    std::string getCertificateNumber() const;
    int getAutobiographyCount() const;
    std::string getAutobiographyEntry(int index) const;

    void print() const override;
};

#endif