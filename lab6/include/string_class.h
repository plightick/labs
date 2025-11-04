#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <cstring>

class String {
private:
    char* data;
    int lengthNew;
    static const int maxLength = 20;
    void validateLength(int length) const;
    void allocateAndCopy(const char* str, int length);
    
public:
    String();
    explicit String(const char* str);
    String(const String& other);
    String& operator=(const String& other);
    ~String(); 
    
    friend String operator+(const String& lhs, const String& rhs);
    
    const char* get_data() const { return data; }
    int length() const { return lengthNew; }
    bool empty() const { return lengthNew == 0; }
    void print() const;
};

#endif