#include "commission_member.hpp"
#include <iostream>
#include <span>
using namespace std;

CommissionMember::CommissionMember() = default;

CommissionMember::CommissionMember(const CommissionMember& other) 
    : Person(other),
      commissionName(other.commissionName),
      appointmentYear(other.appointmentYear),
      certificateNumber(other.certificateNumber),
      autobiographyCount(other.autobiographyCount) {
    
    if (autobiographyCount > 0) {
        autobiographyEntries = new string[autobiographyCount];
        for (int i = 0; i < autobiographyCount; i++)
            autobiographyEntries[i] = other.autobiographyEntries[i];
    } else {
        autobiographyEntries = nullptr;
    }
}

CommissionMember& CommissionMember::operator=(const CommissionMember& other) {
    if (this == &other) return *this;

    Person::operator=(other);
    commissionName = other.commissionName;
    appointmentYear = other.appointmentYear;
    certificateNumber = other.certificateNumber;

    delete[] autobiographyEntries;
    autobiographyCount = other.autobiographyCount;
    if (autobiographyCount > 0) {
        autobiographyEntries = new string[autobiographyCount];
        for (int i = 0; i < autobiographyCount; i++)
            autobiographyEntries[i] = other.autobiographyEntries[i];
    } else {
        autobiographyEntries = nullptr;
    }

    return *this;
}

CommissionMember::~CommissionMember() { delete[] autobiographyEntries; }

void CommissionMember::setCommissionName(string_view name) { 
    commissionName = name; 
}

void CommissionMember::setAppointmentYear(int year) { 
    appointmentYear = year;
}

void CommissionMember::setCertificateNumber(string_view number) { 
    certificateNumber = number;
}

void CommissionMember::setAutobiography(span<const string> entries) {
    delete[] autobiographyEntries;
    autobiographyCount = entries.size();
    if (autobiographyCount > 0) {
        autobiographyEntries = new string[autobiographyCount];
        for (int i = 0; i < autobiographyCount; i++)
            autobiographyEntries[i] = entries[i];
    } else {
        autobiographyEntries = nullptr;
    }
}

string CommissionMember::getCommissionName() const { return commissionName; }
int CommissionMember::getAppointmentYear() const { return appointmentYear; }
string CommissionMember::getCertificateNumber() const { return certificateNumber; }
int CommissionMember::getAutobiographyCount() const { return autobiographyCount; }
string CommissionMember::getAutobiographyEntry(int index) const {
    return (index >= 0 && index < autobiographyCount) ? autobiographyEntries[index] : "";
}

void CommissionMember::print() const {
    Person::print();
    cout << "Комиссия: " << commissionName
         << "\nГод назначения: " << appointmentYear
         << "\nНомер удостоверения: " << certificateNumber
         << "\nАвтобиография:\n";
    for (int i = 0; i < autobiographyCount; i++)
        cout << " * " << autobiographyEntries[i] << endl;
}