#include "../include/string_class.h"
#include "../include/string_exceptions.h"
#include <iostream>
#include <cstring>
#include "string_constructor_expection.h"

const int String::maxLength;

String::String() : data(nullptr), lengthNew(0) {}

String::String(const char* str) {
    if (str == nullptr) {
        lengthNew = 0;
        data = nullptr;
        return;
    }
    
    lengthNew = std::strlen(str);
    validateLength(lengthNew);
    allocateAndCopy(str, lengthNew);
}

String::String(const String& other) : lengthNew(other.lengthNew) {
    allocateAndCopy(other.data, lengthNew);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        lengthNew = other.lengthNew;
        allocateAndCopy(other.data, lengthNew);
    }
    return *this;
}

String::~String() {
    delete[] data;
}

String operator+(const String& lhs, const String& rhs) {
    int newLength = lhs.lengthNew + rhs.lengthNew;
    
    const_cast<String&>(lhs).validateLength(newLength);
    
    char* newData = new char[newLength + 1];
    newData[0] = '\0'; 
    
    if (lhs.data != nullptr) {
        std::strcpy(newData, lhs.data);
    }
    
    if (rhs.data != nullptr) {
        std::strcat(newData, rhs.data);
    }
    
    String result;
    result.lengthNew = newLength;
    result.data = newData;
    
    return result;
}

void String::print() const {
    if (data == nullptr || lengthNew == 0) {
        std::cout << "Строка пуста." << std::endl;
    } else {
        std::cout << "Строка: \"" << data << "\" (длина: " << lengthNew << ")" << std::endl;
    }
}

void String::validateLength(int length) const {
    if (length > maxLength) {
        throw stringConstructorException(maxLength, length);
    }
}

void String::allocateAndCopy(const char* str, int length) {
    if (str == nullptr || length == 0) {
        data = nullptr;
        return;
    }
    
    data = new char[length + 1];
    std::strcpy(data, str);
}