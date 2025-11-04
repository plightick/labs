#ifndef STRING_EXCEPTIONS_H
#define STRING_EXCEPTIONS_H

#include <string>
#include <stdexcept>

class String_exception : public std::exception {
private:
    std::string message_;
    
public:
    explicit String_exception(const std::string& message) {
        message_ = message;
    }
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

class String_length_exception : public String_exception {
public:
    explicit String_length_exception(const std::string& operation, int max_length, int actual_length)
        : String_exception("Ошибка в операции '" + operation + "': максимальная длина " + 
                          std::to_string(max_length) + ", фактическая длина " + 
                          std::to_string(actual_length)) {}
};

class String_constructor_exception : public String_length_exception {
public:
    String_constructor_exception(int max_length, int actual_length)
        : String_length_exception("конструктор", max_length, actual_length) {}
};

class String_concatenation_exception : public String_length_exception {
public:
    String_concatenation_exception(int max_length, int actual_length)
        : String_length_exception("конкатенация", max_length, actual_length) {}
};

#endif