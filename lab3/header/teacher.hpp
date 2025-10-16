#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "person.hpp"
#include <string_view>
#include <span>

class Teacher : public Person {
private:
    std::string position = "";
    std::string degree = "";
    std::string specialty = "";
    std::string* publications = nullptr;
    int publicationCount = 0;

public:
    Teacher();
    Teacher(const Teacher& other);
    Teacher& operator=(const Teacher& other);
    ~Teacher() override;

    void setPosition(std::string_view pos);
    void setDegree(std::string_view deg);
    void setSpecialty(std::string_view spec);
    void setPublications(std::span<const std::string> pubs);

    std::string getPosition() const;
    std::string getDegree() const;
    std::string getSpecialty() const;
    int getPublicationCount() const;
    std::string getPublication(int index) const;

    void print() const override;
};

#endif