#include "../include/string_class.h"
#include "../include/string_exceptions.h"
#include <iostream>
#include <cstring>

const int String::MAX_LENGTH;

String::String() : data_(nullptr), length_(0) {}

String::String(const char* str) {
    if (str == nullptr) {
        length_ = 0;
        data_ = nullptr;
        return;
    }
    
    length_ = std::strlen(str);
    validate_length(length_);
    allocate_and_copy(str, length_);
}

String::String(const String& other) : length_(other.length_) {
    allocate_and_copy(other.data_, length_);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data_;
        length_ = other.length_;
        allocate_and_copy(other.data_, length_);
    }
    return *this;
}

String::~String() {
    delete[] data_;
}

String operator+(const String& lhs, const String& rhs) {
    int new_length = lhs.length_ + rhs.length_;
    
    const_cast<String&>(lhs).validate_length(new_length);
    
    char* new_data = new char[new_length + 1];
    new_data[0] = '\0'; 
    
    if (lhs.data_ != nullptr) {
        std::strcpy(new_data, lhs.data_);
    }
    
    if (rhs.data_ != nullptr) {
        std::strcat(new_data, rhs.data_);
    }
    
    String result;
    result.length_ = new_length;
    result.data_ = new_data;
    
    return result;
}

void String::print() const {
    if (data_ == nullptr || length_ == 0) {
        std::cout << "Строка пуста." << std::endl;
    } else {
        std::cout << "Строка: \"" << data_ << "\" (длина: " << length_ << ")" << std::endl;
    }
}

void String::validate_length(int length) const {
    if (length > MAX_LENGTH) {
        throw String_constructor_exception(MAX_LENGTH, length);
    }
}

void String::allocate_and_copy(const char* str, int length) {
    if (str == nullptr || length == 0) {
        data_ = nullptr;
        return;
    }
    
    data_ = new char[length + 1];
    std::strcpy(data_, str);
}