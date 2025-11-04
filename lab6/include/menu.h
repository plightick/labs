#ifndef STRING_MENU_H
#define STRING_MENU_H

#include "string_class.h"
#include "string_exceptions.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

template<typename T>
T check_numbers();

void hand_input_string(String& str);
void print_string_menu();
void show_strings(const String& str1, const String& str2);
void concatenate_strings(const String& str1, const String& str2);
void string_menu();

#endif