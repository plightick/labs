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


#endif