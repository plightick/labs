#include "commission_member.hpp"
#include <iostream>
using namespace std;

CommissionMember::CommissionMember()
    : commissionName(""), appointmentYear(0), certificateNumber(""),
      autobiographyEntries(nullptr), autobiographyCount(0) {}

CommissionMember::CommissionMember(const CommissionMember& other) : Person(other) {
    commissionName = other.commissionName;
    appointmentYear = other.appointmentYear;
    certificateNumber = other.certificateNumber;
    autobiographyCount = other.autobiographyCount;

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

void CommissionMember::setCommissionName(const string& commissionName) { this->commissionName = commissionName; }
void CommissionMember::setAppointmentYear(int appointmentYear) { this->appointmentYear = appointmentYear; }
void CommissionMember::setCertificateNumber(const string& certificateNumber) { this->certificateNumber = certificateNumber; }
void CommissionMember::setAutobiography(string* entries, int count) {
    delete[] autobiographyEntries;
    autobiographyCount = count;
    autobiographyEntries = new string[count];
    for (int i = 0; i < count; i++)
        autobiographyEntries[i] = entries[i];
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
