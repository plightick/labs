#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <cstring>

class String {
private:
    char* data_;
    int length_;
    static const int MAX_LENGTH = 20;
    void validate_length(int length) const;
    void allocate_and_copy(const char* str, int length);
    
public:
    String();
    explicit String(const char* str);
    String(const String& other);
    String& operator=(const String& other);
    ~String(); 
    
    friend String operator+(const String& lhs, const String& rhs);
    
    const char* get_data() const { return data_; }
    int length() const { return length_; }
    bool empty() const { return length_ == 0; }
    void print() const;
};

#endif