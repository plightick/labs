#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "person.hpp"

class Teacher :public Person {
private:
    std::string position;
    std::string degree;
    std::string specialty;
    std::string* publications;
    int publicationCount;

public:
    Teacher();
    Teacher(const Teacher& other);
    Teacher& operator=(const Teacher& other);
    ~Teacher() override;

    void setPosition(const std::string& position);
    void setDegree(const std::string& degree);
    void setSpecialty(const std::string& specialty);
    void setPublications(std::string* publications, int publicationCount);

    std::string getPosition() const;
    std::string getDegree() const;
    std::string getSpecialty() const;
    int getPublicationCount() const;
    std::string getPublication(int index) const;

    void print() const override;
};

#endif
