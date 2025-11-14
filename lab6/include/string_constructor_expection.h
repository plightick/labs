#ifndef STRINGCONSTRUCTOREXCEPTIONS_H
#define STRINGCONSTRUCTOREXCEPTIONS_H

#include <string>
#include <stdexcept>
#include "string_length_exception.h"

class stringConstructorException : public StringLengthNewException {
public:
    stringConstructorException(int maxLength, int actualLength)
        : StringLengthNewException("конструктор", maxLength, actualLength) {}
};

#endif