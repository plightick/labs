#ifndef STRINGEXCEPTIONS_H
#define STRINGEXCEPTIONS_H

#include <string>
#include <stdexcept>

class StringException : public std::exception {
private:
    std::string newMessage;
    
public:
    explicit StringException(const std::string& message) {
        newMessage = message;
    }
    
    const char* what() const noexcept override {
        return newMessage.c_str();
    }
};

class StringLengthNewException : public StringException {
public:
    explicit StringLengthNewException(const std::string& operation, int maxLength, int actualLength)
        : StringException("Ошибка в операции '" + operation + "': максимальная длина " + 
                          std::to_string(maxLength) + ", фактическая длина " + 
                          std::to_string(actualLength)) {}
};

class stringConstructorException : public StringLengthNewException {
public:
    stringConstructorException(int maxLength, int actualLength)
        : StringLengthNewException("конструктор", maxLength, actualLength) {}
};

class StringConcatenationException : public StringLengthNewException {
public:
    StringConcatenationException(int maxLength, int actualLength)
        : StringLengthNewException("конкатенация", maxLength, actualLength) {}
};

#endif