#ifndef STRINGCONCATENATIONEXCEPTIONS_H
#define STRINGCONCATENATIONEXCEPTIONS_H

#include <string>
#include <stdexcept>
#include "string_length_exception.h"

class StringConcatenationException : public StringLengthNewException {
public:
    StringConcatenationException(int maxLength, int actualLength)
        : StringLengthNewException("конкатенация", maxLength, actualLength) {}
};

#endif