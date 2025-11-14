#ifndef STRINGLENGTHEXCEPTIONS_H
#define STRINGLENGTHEXCEPTIONS_H

#include <string>
#include <stdexcept>
#include "string_exceptions.h"


class StringLengthNewException : public StringException {
public:
    explicit StringLengthNewException(const std::string& operation, int maxLength, int actualLength)
        : StringException("Ошибка в операции '" + operation + "': максимальная длина " + 
                          std::to_string(maxLength) + ", фактическая длина " + 
                          std::to_string(actualLength)) {}
};

#endif